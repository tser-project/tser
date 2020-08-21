#include "ffi/link.h"
#include "grammar/TypeScriptLexer.h"
#include "grammar/TypeScriptParser.h"
#include "perf/pert_utils.h"
#include "tser.h"
#include "utils.h"
#include "visit/visit.h"
#include "llvm/ExecutionEngine/Orc/JITTargetMachineBuilder.h"
#include "llvm/ExecutionEngine/Orc/LLJIT.h"
#include "llvm/ExecutionEngine/Orc/ObjectLinkingLayer.h"
#include "llvm/ExecutionEngine/Orc/ThreadSafeModule.h"
#include "llvm/IR/LLVMContext.h"
#include "llvm/IR/Module.h"
#include "llvm/Support/InitLLVM.h"
#include "llvm/Support/TargetSelect.h"
#include <iostream>
#include <string>
#include <unistd.h>

using namespace tser;
using namespace std;
using namespace antlr4;
using namespace llvm;
using namespace llvm::orc;

int main(int argc, char *argv[], char *scope[]) {

  DebugPrintln("[Process] Tser started");

  InitLLVM X(argc, argv);
  InitializeNativeTarget();
  InitializeNativeTargetAsmPrinter();
  ThreadSafeContext context(std::make_unique<LLVMContext>());

  ExitOnError ExitOnErr;
  auto        JTMB = ExitOnErr(JITTargetMachineBuilder::detectHost());

  auto jit = ExitOnErr(LLJITBuilder()
                           .setJITTargetMachineBuilder(std::move(JTMB))
                           .setObjectLinkingLayerCreator([ & ](ExecutionSession &ES, const Triple &TT) {
                             auto ll =
                                 make_unique<ObjectLinkingLayer>(ES, make_unique<jitlink::InProcessMemoryManager>());
                             ll->setOverrideObjectFlagsWithResponsibilityFlags(true);
                             /// fix bug: asserts "Resolving symbol outside this
                             /// responsibility set"
                             /// https://stackoverflow.com/a/60609825/11354404
                             ll->setAutoClaimResponsibilityForObjectSymbols(true);
                             return move(ll);
                           })
                           .create());

  jit->getMainJITDylib().addGenerator(
      ExitOnErr(orc::DynamicLibrarySearchGenerator::GetForCurrentProcess(jit->getDataLayout().getGlobalPrefix())));

  /// add builtin file
  string builtin_file_path[] = {"lib", "builtin.o"};
  string builtin_file        = fsutils::GetPathStartFromProject(GetArrayLen(builtin_file_path), builtin_file_path);
  Error  err = jit->addObjectFile(ExitOnErr(errorOrToExpected(MemoryBuffer::getFileAsStream(builtin_file.data()))));
  if (err) {
    cerr << "[Error] Read tser's builtin file error" << endl;
    return 1;
  }

  auto process = make_unique<TserProcess>(new GlobalScope());
  DefineBuiltins(process.get());

  /// read input file
  string input_paths[] = {argv[ 1 ]};
  string input_path    = fsutils::GetPathStartFromCurrent(1, input_paths);
  auto   module = fsutils::ReadFile(process.get(), input_path.data(), *context.getContext(), jit->getDataLayout());

  if (!module) {
    return 1;
  }

#if (defined DEBUG) && (defined LLVM_BUILD_DEBUG)
  DebugPrintln("----module dump----");
  module->dump();
#endif

  ThreadSafeModule mod(move(module), context);
  err = jit->addIRModule(move(mod));
  if (err) {
    throw err;
  }

  string func_name_name   = "main";
  auto   func_main        = ExitOnErr(jit->lookup(func_name_name.data()));
  int (*func_main_addr)() = (int (*)())func_main.getAddress();
  int result              = func_main_addr();
  if (result != 0) {
    cerr << "[Error] Main function run error:" << result << endl;
    return 1;
  }

  return 0;
}