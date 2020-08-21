#pragma once

#include "llvm/IR/DerivedTypes.h"
#include "llvm/IR/Function.h"
#include "llvm/IR/Module.h"
#include <map>
#include <string>

using namespace llvm;
using namespace std;

namespace tser {

enum class IntrinsicFunctionID {
  Printf,
  Znwm,
  ZdlPv,
};

// Each module need to have one instance of IntrinsicFunctionManager
class IntrinsicFunctionManager {
  private:
  map<IntrinsicFunctionID, Function *> function_cache;
  Module *                             module = nullptr;

  public:
  IntrinsicFunctionManager(Module *module)
      : module(module) {
  }
  ~IntrinsicFunctionManager() {
    function_cache.empty();
    module = nullptr;
  }

  public:
  Function *GetIntrinsicFunction(IntrinsicFunctionID id);

  private:
  Function *InsertIntrinsicFunction(IntrinsicFunctionID id);
  Function *InsertPrintf();
  Function *InsertZnwm();
  Function *InsertZdlPv();
};
} // namespace tser
