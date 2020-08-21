#include "ffi/intrinsic.h"
#include "tser.h"
#include "utils.h"

using namespace tser;
using namespace std;

Function *IntrinsicFunctionManager::GetIntrinsicFunction(IntrinsicFunctionID id) {
  if (function_cache.count(id) > 0) {
    return function_cache[ id ];
  }
  auto func = InsertIntrinsicFunction(id);
  if (func) {
    function_cache[ id ] = func;
    return function_cache[ id ];
  }
  assert(false);
  return nullptr;
}

Function *IntrinsicFunctionManager::InsertIntrinsicFunction(IntrinsicFunctionID id) {
  switch (id) {
    case IntrinsicFunctionID::Printf:
      return InsertPrintf();
    case IntrinsicFunctionID::Znwm:
      return InsertZnwm();
    case IntrinsicFunctionID::ZdlPv:
      return InsertZdlPv();
    default:
      return nullptr;
  }
}

Function *IntrinsicFunctionManager::InsertPrintf() {

  Type *         return_type = Type::getVoidTy(module->getContext());
  vector<Type *> arg_types;
  arg_types.push_back(Type::getInt8PtrTy(module->getContext()));

  /// support '...' type
  FunctionCallee callee = module->getOrInsertFunction("printf", FunctionType::get(return_type, arg_types, true));

  return (Function *)callee.getCallee();
}

Function *IntrinsicFunctionManager::InsertZnwm() {
  // declare noalias i8* @_Znwm(i64) #1
  vector<Type *> arg_types;
  arg_types.push_back(GetAutoBitType(module->getContext(), OriginType::NewParam));
  FunctionCallee callee = module->getOrInsertFunction(
      "_Znwm", FunctionType::get(Type::getInt8PtrTy(module->getContext()), arg_types, false));
  return (Function *)callee.getCallee();
}

Function *IntrinsicFunctionManager::InsertZdlPv() {
  // declare void @_ZdlPv(i8*) #3
  vector<Type *> arg_types;
  arg_types.push_back(Type::getInt8PtrTy(module->getContext()));
  FunctionCallee callee =
      module->getOrInsertFunction("_ZdlPv", FunctionType::get(Type::getVoidTy(module->getContext()), arg_types, false));
  return (Function *)callee.getCallee();
}