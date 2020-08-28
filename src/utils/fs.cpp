#include "grammar/TypeScriptLexer.h"
#include "grammar/TypeScriptParser.h"
#include "tser.h"
#include "utils.h"
#include "llvm/ExecutionEngine/Orc/ThreadSafeModule.h"
#include "llvm/IR/LLVMContext.h"
#include "llvm/IR/Module.h"
#include <boost/filesystem.hpp>
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
namespace fs = boost::filesystem;

/// get tser executeable file path
string GetTserExecutablePath() {
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

/// get tser executeable project path
string GetTserRootPath() {
  fs::path p(GetTserExecutablePath());
  return p.parent_path().parent_path().string();
}

/// get path in tser project
string tser::fsutils::GetPathInTser(int size, string paths[]) {

  auto project_path = fs::path(GetTserRootPath());
  for (int i = 0; i < size; i++) {
    if (paths[ i ] == "..") {
      project_path = project_path.parent_path();
    } else {
      project_path.append(paths[ i ]);
    }
  }
  return project_path.string();
}

/// get path from current path of terminal
string tser::fsutils::GetPathStartFromCurrent(int size, string paths[]) {

  auto current_path = fs::current_path();
  for (int i = 0; i < size; i++) {
    if (paths[ i ] == "..") {
      current_path = current_path.parent_path();
    } else {
      current_path.append(paths[ i ]);
    }
  }
  return current_path.string();
}

unique_ptr<Module> tser::fsutils::CreateModuleFromFile(TserProcess *process, char *file_path, LLVMContext &context,
                                                       const DataLayout &dataLayout) {

  DebugPrintln("file path: %s", file_path);

  string module_name = file_path;
  DebugPrintln("module name: %s", module_name.data());

  if (!fs::exists(file_path)) {
    cerr << "[Error] File not exist: " << file_path << endl;
    return nullptr;
  }

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

  auto module = make_unique<Module>(module_name, context);
  module->setDataLayout(dataLayout);
  module->setTargetTriple(sys::getDefaultTargetTriple());

  auto module_visitor = make_unique<ModuleVisitor>(process, module.get(), tree);
  module_visitor->StartPrecheck();
  module_visitor->StartBuildIR();

  ifs.close();
  return move(module);
}