#include "grammar/TypeScriptLexer.h"
#include "grammar/TypeScriptParser.h"
#include "tser.h"
#include "utils.h"
#include "llvm/ExecutionEngine/Orc/ThreadSafeModule.h"
#include "llvm/IR/LLVMContext.h"
#include "llvm/IR/Module.h"
#include <filesystem>
#include <iostream>
#include <string>
// fs include
#ifdef TSER_TARGET_MAC
#include <mach-o/dyld.h>
#else
#include <unistd.h>
#endif

#define FILE_PATH_SIZE 512

using namespace tser;
using namespace std;
using namespace antlr4;
using namespace llvm;
using namespace llvm::orc;
using namespace filesystem;

string GetExecutablePath() {
  char path[ FILE_PATH_SIZE ];
#ifdef TSER_TARGET_MAC
  unsigned _size = FILE_PATH_SIZE;
  _NSGetExecutablePath(path, &_size);
  path[ FILE_PATH_SIZE - 1 ] = '\0';
#else
  int count = readlink("/proc/self/exe", path, FILE_PATH_SIZE);
  if (count < 0 || count >= FILE_PATH_SIZE) {
    cerr << "[Error] Get executable path" << endl;
    return "";
  }
  path[ count ] = '\0';
#endif
  return path;
}

string tser::fsutils::GetPathStartFromProject(int size, string paths[]) {

  auto project_path = filesystem::canonical(GetExecutablePath()).parent_path().parent_path();
  for (int i = 0; i < size; i++) {
    if (paths[ i ] == "..") {
      project_path = project_path.parent_path();
    } else {
      project_path.append(paths[ i ]);
    }
  }
  return project_path;
}

string tser::fsutils::GetPathStartFromCurrent(int size, string paths[]) {

  auto current_path = filesystem::current_path();
  for (int i = 0; i < size; i++) {
    if (paths[ i ] == "..") {
      current_path = current_path.parent_path();
    } else {
      current_path.append(paths[ i ]);
    }
  }
  return current_path;
}

unique_ptr<Module> tser::fsutils::ReadFile(TserProcess *process, char *file_path, LLVMContext &context,
                                           const DataLayout &dataLayout) {

  DebugPrintln("file path: %s", file_path);

  ifstream ifs;
  ifs.open(file_path);

  if (!ifs) {
    string msg = "[Error] Read file error:" + (string)file_path;
    cerr << msg << endl;
    return nullptr;
  }

  ANTLRInputStream in(ifs);

  TypeScriptLexer   lexer(&in);
  CommonTokenStream tokens(&lexer);
  tokens.fill();

  TypeScriptParser parser(&tokens);

  tree::ParseTree *tree = parser.program();

  auto module = make_unique<Module>(file_path, context);
  module->setDataLayout(dataLayout);
  module->setTargetTriple(sys::getDefaultTargetTriple());

  auto module_visitor = make_unique<ModuleVisitor>(process, module.get(), tree);
  module_visitor->StartPrecheck();
  module_visitor->StartBuildIR();

  ifs.close();
  return move(module);
}