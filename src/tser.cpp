#include "tser.h"
#include "antlr4-runtime.h"
#include "common/error/error.h"
#include "ffi/link.h"
#include "grammar/TypeScriptParser.h"
#include "loader.h"
#include "llvm/IR/DerivedTypes.h"
#include "llvm/IR/Function.h"
#include "llvm/IR/Value.h"

using namespace tser;
using namespace std;
using namespace antlr4;
using namespace antlr4::tree;
using namespace llvm;

/// FunctionValueWrapper
FunctionValueWrapper::~FunctionValueWrapper() {
  if (this_value) {
    delete this_value;
    this_value = nullptr;
  }
}

/// LlvmValueInfo
LlvmValueInfo::LlvmValueInfo(TypeSignInfo *type, Value *value, bool value_is_pointer)
    : type(type)
    , value(value)
    , value_is_pointer(value_is_pointer){};

LlvmValueInfo::LlvmValueInfo(TypeSignInfo *type, bool value_is_pointer)
    : type(type)
    , value_is_pointer(value_is_pointer){};

LlvmValueInfo::LlvmValueInfo(VariableValue *var_value, bool is_function_var) {
  this->type             = var_value->type->clone();
  this->value            = var_value->value;
  this->value_is_pointer = var_value->ValueIsPointer();
  if (is_function_var) {
    this->function_var = (FunctionVariableValue *)var_value;
  }
}

LlvmValueInfo *LlvmValueInfo::clone() {
  return new LlvmValueInfo(this->type->clone(), this->value, this->value_is_pointer);
}

LlvmValueInfo::~LlvmValueInfo() {
  delete type;
  type = nullptr;
  if (function_wrapper) {
    delete function_wrapper;
    function_wrapper = nullptr;
  }
}

/// VariableValue
VariableValue::~VariableValue() {
  if (type) {
    delete type;
    type = nullptr;
  }
  value = nullptr; // deleted by llvm;
  scope = nullptr;
}
VariableValue *VariableValue::clone() {
  return new VariableValue(this->scope, this->type->clone(), this->value);
}

/// FunctionVariableValue

void FunctionVariableValue::SetReturnType(TypeSignInfo *return_type) {
  this->return_value = new LlvmValueInfo(return_type);
}

FunctionVariableValue::~FunctionVariableValue() {
  if (return_value) {
    delete return_value;
    return_value = nullptr;
  }
}

/// NodeValue
string NodeValue::ToString() {
  string s = "[NodeValue] type:";
  s.append("; value: ");
  s.append(IsString() ? string_value : "[Pointer Value]");
  return s;
}

/// GlobalVariableLoader
void GlobalVariableLoader::LoadToModule(ModuleVisitor *visitor, string name) {
  if (load_cache.count(visitor) > 0 && load_cache[ visitor ].count(name) > 0) {
    return;
  }
}

/// GlobalScope
void GlobalScope::DefineReferenceInfo(ReferencePackageConfig *reference_package) {
  classes[ reference_package->GetName() ] = reference_package;
}
ReferencePackageConfig *GlobalScope::GetReferenceInfo(string key) {
  return classes[ key ];
}
void GlobalScope::DefineFunction(LinkFunctionConfig *func_config) {
  functions[ func_config->GetName() ] = func_config;
}
LinkFunctionConfig *GlobalScope::GetFunction(string key) {
  return functions[ key ];
}
GlobalScope::~GlobalScope() {
  for (auto &item : classes) {
    delete item.second;
  }
}

/// TserProcess
TserProcess::TserProcess(GlobalScope *global_scope) {
  this->global_scope = global_scope;
  loader_manager     = new LoaderManager(this);
}

void TserProcess::LoadToModule(ModuleVisitor *visitor, string name, string var_key) {
  if (global_scope->GetReferenceInfo(name)) {
    loader_manager->LoadToModule(LoaderType::Class, visitor, name, var_key);
    return;
  }
  if (global_scope->GetFunction(name)) {
    loader_manager->LoadToModule(LoaderType::Function, visitor, name, var_key);
    return;
  }
  throw ReferenceInfoNotFoundException(name + ":" + var_key);
}

TserProcess::~TserProcess() {
  delete global_scope;
  delete loader_manager;
}
