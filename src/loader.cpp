#include "loader.h"
#include "common/error/error.h"
#include "ffi/link.h"
#include "tser.h"
#include "utils.h"
#include "visit/class/class.h"
#include "visit/reference/reference.h"
#include "visit/visit.h"
#include <string>

using namespace tser;
using namespace std;

/// FunctionLoader
void FunctionLoader::LoadToModule(ModuleVisitor *visitor, string name, string _) {
  auto func_config = GetGlobalScope()->GetFunction(name);

  auto scope = visitor->GetModuleScope();
  if (func_config->IsIntrinsic()) {
    auto func = visitor->GetIntrinsicFunctionManager()->GetIntrinsicFunction(func_config->GetIntrinsicFunctionID());
    auto func_var_value   = new FunctionVariableValue(scope);
    func_var_value->value = func;
    func_var_value->SetReturnType(func_config->GetReturnType()->clone());
    scope->DefineVariable(name, func_var_value);
    return;
  }
  throw FunctionNotFoundException(name);
}

/// ClassLoader

/// Load class and it's method or property to module
/// Only support static method now.
void ClassLoader::LoadToModule(ModuleVisitor *visitor, string name, string var_key) {
  auto class_info = LoadClassInfo(visitor, name);
  if (var_key == "" || class_info->IsMethod(var_key) || class_info->IsProperty(var_key)) {
    return;
  }
  auto ref_pack_info = GetGlobalScope()->GetReferenceInfo(name);
  auto method_config = ref_pack_info->GetMethodConfig(var_key);
  if (!method_config) {
    throw FunctionNotFoundException(var_key);
  }

  auto module_scope = visitor->GetModuleScope();
  auto method_var   = new ReferenceMethodValue(module_scope);
  method_var->SetAutoAddVarArgs(method_config->AutoAddVarArgs());
  method_var->SetUsingThis(method_config->UsingThis());
  method_var->SetIsStatic(method_config->IsStatic());
  method_var->SetIsFinal(method_config->IsFinal());
  method_var->SetIsConst(method_config->IsConst());
  method_var->SetIsAsync(method_config->IsAsync());
  method_var->SetReturnValue(new LlvmValueInfo(method_config->GetReturnType()->clone()));
  method_var->SetAccessControl(AccessControl::Public);

  auto func_value_info =
      unique_ptr<LlvmValueInfo>(CreateBuiltinFunction(name, var_key, visitor, nullptr, method_config->GetArguments(),
                                                      method_config->GetReturnType(), method_config->IsVarArg()));

  method_var->value = func_value_info->value;

  class_info->DefineMethod(var_key, method_var);
}

ClassInfo *ClassLoader::LoadClassInfo(ModuleVisitor *visitor, string name) {
  if (load_cache.count(visitor) == 0) {
    map<string, ClassInfo *> values;
    load_cache[ visitor ] = values;
  }
  if (load_cache[ visitor ].count(name) > 0) {
    return load_cache[ visitor ][ name ];
  }
  auto ref_pack_info = GetGlobalScope()->GetReferenceInfo(name);
  auto module_scope  = visitor->GetModuleScope();
  auto class_info    = (ClassInfo *)module_scope->GetReferenceInfo(name);
  if (!class_info) {
    class_info            = new ClassInfo(name);
    class_info->is_static = ref_pack_info->GetReferenceInfoConfig()->IsStatic();
    class_info->is_final  = ref_pack_info->GetReferenceInfoConfig()->IsFinal();
    class_info->SetHasMapTable(ref_pack_info->GetReferenceInfoConfig()->HasMapTable());
    module_scope->DefineReferenceInfo(name, class_info);
  }
  load_cache[ visitor ][ name ] = class_info;
  return class_info;
}

GlobalScope *Loader::GetGlobalScope() {
  return process->GetGlobalScope();
}

/// LoaderManager
void LoaderManager::LoadToModule(LoaderType type, ModuleVisitor *visitor, string name, string var_key) {
  switch (type) {
    case LoaderType::Class:
      class_loader->LoadToModule(visitor, name, var_key);
      break;
    case LoaderType::Function:
      function_loader->LoadToModule(visitor, name);
      break;
    default:
      return;
  }
}

LoaderManager::~LoaderManager() {
  delete class_loader;
}