#include "scope/scope.h"
#include "common/error/error.h"
#include "utils.h"
#include "llvm/IR/Constant.h"
#include <list>

using namespace std;
using namespace tser;

/// Scope
ModuleScope *Scope::GetModuleScope() {
  if (module_scope) {
    return module_scope;
  }
  Scope *scope = this;
  while (!scope->IsModule()) {
    scope = scope->GetParentScope();
  }
  module_scope = (ModuleScope *)scope;
  return module_scope;
}

VariableValue *Scope::CheckVariable(string key) {

  if (self_variables.count(key) > 0) {
    return self_variables[ key ];
  }

  VariableValue *var_value = nullptr;
  if (GetParentScope()) {
    var_value = GetParentScope()->CheckVariable(key);
    if (!var_value) {
      /// Maybe ReferenceInfo
      return nullptr;
    }
  }
  return var_value;
}

void Scope::DefineVariable(string key, VariableValue *value) {
  self_variables[ key ] = value;
}

VariableValue *Scope::GetVariableValue(string key) {
  Scope *scope = this;
  while (scope) {
    if (scope->self_variables.count(key) > 0) {
      return scope->self_variables[ key ];
    }
    scope = scope->parent_scope;
  }
  throw VariableNotFoundException(key);
}

/// @return { X* } : return value is pointer type
Value *Scope::StoreLlvmValue(ModuleVisitor *visitor, string key, LlvmValueInfo *init_value) {
  auto        var_value     = GetVariableValue(key);
  auto        var_llvm_type = VariableTypeToLLVMType(visitor->builder->getContext(), var_value->type);
  AllocaInst *value         = visitor->builder->CreateAlloca(var_llvm_type);
  var_value->value          = value;
  if (init_value) {
    visitor->builder->CreateStore(init_value->value, value, false);
  }
  return var_value->value;
}

Value *Scope::LoadToRegister(IRBuilder<> *builder, LlvmValueInfo *llvm_value_info) {
  if (llvm_value_info->type->type == VariableType::Null) {
    return nullptr;
  }
  if (!llvm_value_info->ValueIsPointer()) {
    return llvm_value_info->value;
  }
  switch (llvm_value_info->type->type) {
    case VariableType::String:
    default:
      return builder->CreateLoad(llvm_value_info->value);
  }
}

ConstantInt *Scope::LoadToRegisterAsConstantInt(IRBuilder<> *builder, LlvmValueInfo *llvm_value_info) {
  GlobalVariable *string_value = nullptr;
  switch (llvm_value_info->type->type) {
    case VariableType::String:
    case VariableType::Boolean:
    case VariableType::Int32:
    case VariableType::Int64:
    case VariableType::Float:
    case VariableType::Double:
    default:
      return (ConstantInt *)LoadToRegister(builder, llvm_value_info);
  }
}

void Scope::NodeValueInitLlvmValueInfo(IRBuilder<> *builder, NodeValue *node_value) {
  if (node_value->IsString()) {
    /// support load "this"
    auto value_info = LoadAsLlvmValueInfo(builder, node_value->GetStringValue());
    node_value->SetLlvmValueInfo(value_info);
  }
}

Scope *Scope::FindTagetScope(string key) {
  if (self_variables.count(key) > 0) {
    return this;
  }
  if (parent_scope) {
    return parent_scope->FindTagetScope(key);
  } else {
    throw VariableNotFoundException(key);
  }
}

Scope::~Scope() {
  for (auto const &item : self_variables) {
    delete item.second;
  }
  parent_scope = nullptr;
}

// get parent function scope, if none, return nullptr
FunctionScope *Scope::GetParentFunctionScope() {
  Scope *temp_scope = GetParentScope();
  while (temp_scope && !temp_scope->IsFunction()) {
    temp_scope = temp_scope->GetParentScope();
  }
  if (temp_scope) {
    return (FunctionScope *)temp_scope;
  }
  return nullptr;
}

// wrap function scope, if current is function scope, return direct
FunctionScope *Scope::GetWrapFunctionScope() {
  Scope *target = this;
  while (target && !target->IsFunction()) {
    target = target->parent_scope;
  }
  if (target) {
    return (FunctionScope *)target;
  }
  return nullptr;
}

BlockScope *Scope::GetWrapBlockScope() {
  Scope *     target      = this;
  BlockScope *block_scope = nullptr;
  while (target) {
    if (target->IsBlock()) {
      return (BlockScope *)target;
    }
    target = target->parent_scope;
  }
  return nullptr;
}

BlockScope *Scope::GetWrapLoopBlockScope(string name) {
  Scope *     target      = this;
  BlockScope *block_scope = nullptr;
  while (target) {
    if (target->IsBlock()) {
      block_scope = (BlockScope *)target;
      if (block_scope->IsLoop()) {
        if (name == "") {
          return block_scope;
        } else if (block_scope->GetBlockLoopName() == name) {
          return block_scope;
        }
      }
    }
    target = target->parent_scope;
  }
  return nullptr;
}

/// FunctionScope
VariableValue *FunctionScope::CheckVariable(string key) {

  if (key == "this") {
    GetFunctionVariableValue()->SetUsingThis(true);
    return nullptr;
  }

  if (parent_variable_cache.count(key) > 0) {
    return parent_variable_cache[ key ];
  }

  VariableValue *var_value = Scope::CheckVariable(key);

  if (!var_value || var_value->type->type == VariableType::Function) {
    return var_value;
  }

  if (var_value->scope->IsModule() || var_value->scope->GetWrapFunctionScope() == GetWrapFunctionScope()) {
    /// in same function, or target is module scope, do nothing
    return var_value;
  }

  /// clone value, because llvm value will be redefined in header of this function
  var_value = var_value->clone();

  FunctionScope *parent_func_scope = GetParentFunctionScope();
  parent_variable_cache[ key ]     = var_value;
  parent_variables_queue.push_back(key);
  parent_variables_queue_index[ key ] = parent_variables_queue.size() - 1;
  return var_value;
}

LlvmValueInfo *FunctionScope::LoadAsLlvmValueInfo(IRBuilder<> *builder, string key) {
  if (self_variables.count(key) > 0) {
    return new LlvmValueInfo(self_variables[ key ]);
  }
  if (parent_variables_queue_index.count(key) > 0) {
    Value *ptr = builder->CreateConstInBoundsGEP2_32(parent_variables_struct_type, parent_variables_struct_value, 0,
                                                     parent_variables_queue_index[ key ]);
    ptr        = builder->CreateLoad(ptr);
    return new LlvmValueInfo(parent_variable_cache[ key ]->type->clone(), ptr, true);
  }
  return GetModuleScope()->LoadAsLlvmValueInfo(builder, key);
}

void FunctionScope::CreateParentVariablesStructType(LLVMContext &context) {
  if (parent_variables_queue.size() == 0) {
    return;
  }
  vector<Type *> parent_variables_type;
  for (auto key : parent_variables_queue) {
    parent_variables_type.push_back(
        VariableTypeToLLVMType(context, parent_variable_cache[ key ]->type)->getPointerTo());
  }
  parent_variables_struct_type = StructType::create(context, parent_variables_type, "struct");
}
Value *FunctionScope::PackParentVariablesToStructValue(IRBuilder<> *builder) {
  if (parent_variables_queue.size() == 0) {
    return nullptr;
  }
  Scope *wrap_scope = GetParentScope();
  // pack parent variables as first argument
  Value *   parent_variables_value = builder->CreateAlloca(parent_variables_struct_type);
  var_index index                  = 0;
  for (string variable : parent_variables_queue) {
    Value *ptr = builder->CreateConstInBoundsGEP2_32(parent_variables_struct_type, parent_variables_value, 0, index);
    auto   temp_value = unique_ptr<LlvmValueInfo>(wrap_scope->LoadAsLlvmValueInfo(builder, variable));
    builder->CreateStore(temp_value->value, ptr);
    parent_variable_cache[ variable ]->value = temp_value->value;
    index++;
  }
  return parent_variables_value;
}

/// ModuleScope
VariableValue *ModuleScope::CheckVariable(string key) {
  if (self_variables.count(key) > 0) {
    return self_variables[ key ];
  }
  if (GetReferenceInfo(key)) {
    return nullptr;
  }

  /// check global scope and load auto if exists
  auto var_value = Scope::CheckVariable(key);
  if (!var_value) {
    GetProcess()->LoadToModule(GetModuleVisitor(), key);
  }

  /// check again after loaded
  if (self_variables.count(key) > 0) {
    return self_variables[ key ];
  }

  if (GetReferenceInfo(key)) {
    return nullptr;
  }

  throw VariableNotFoundException(key);
}

/// global value set rules:
/// 1. save directly if is Constant of basic type
/// 2. save nullptr if is ReferenceInfo
/// 3. save real value to ReferenceInfo' value after created
///
/// @param init_value: cannot be nullptr
/// @return { X* } : return value is pointer type
Value *ModuleScope::StoreLlvmValue(ModuleVisitor *visitor, string key, LlvmValueInfo *init_value) {
  return CreateGlobalLlvmValue(visitor, key, GetVariableValue(key), init_value);
}

LlvmValueInfo *ModuleScope::LoadAsLlvmValueInfo(IRBuilder<> *builder, string key) {
  if (self_variables.count(key) > 0) {
    return new LlvmValueInfo(self_variables[ key ]);
  }
  auto ref_info = GetReferenceInfo(key);
  if (ref_info) {
    auto value_info = new LlvmValueInfo(new TypeSignInfo(VariableType::Reference, ref_info));
    value_info->SetIsReferenceInfo(true);
    return value_info;
  }
  throw VariableNotFoundException(key);
}

void ModuleScope::CheckReferenceInfo(string name) {
  if (reference_infos.count(name) == 0) {
    throw ReferenceInfoNotFoundException(name);
  }
}

void ModuleScope::DefineReferenceInfo(string name, ReferenceInfo *reference_info) {
  reference_infos[ name ] = reference_info;
}
ReferenceInfo *ModuleScope::GetReferenceInfo(string name) {
  return reference_infos[ name ];
}

Value *ModuleScope::LoadGlobalString(ModuleVisitor *visitor, string key, bool create_if_null) {
  if (global_string.count(key) == 0) {
    if (!create_if_null) {
      return nullptr;
    }

    auto global_value    = visitor->builder->CreateGlobalString(key, key);
    global_string[ key ] = global_value;
  }

  auto zero = GetConstantInt(visitor->GetLLVMContext(), 0);
  return visitor->builder->CreateInBoundsGEP(global_string[ key ], {zero, zero});
}

/// BlockScope
VariableValue *BlockScope::CheckVariable(string key) {

  if (self_variables.count(key) > 0) {
    return self_variables[ key ];
  }

  return GetParentScope()->CheckVariable(key);
}

LlvmValueInfo *BlockScope::LoadAsLlvmValueInfo(IRBuilder<> *builder, string key) {
  if (self_variables.count(key) > 0) {
    return new LlvmValueInfo(self_variables[ key ]);
  }
  return GetParentScope()->LoadAsLlvmValueInfo(builder, key);
}

/// SwitchBlockScope
void SwitchBlockScope::SetHasJumpedOut(bool has_jumped_out, ParseTree *node) {
  BlockScope::SetHasJumpedOut(has_jumped_out, node);

  auto break_node = dynamic_cast<TypeScriptParser::BreakStatementContext *>(node);
  if (!dynamic_cast<TypeScriptParser::BreakStatementContext *>(node) &&
      !dynamic_cast<TypeScriptParser::ReturnStatementContext *>(node)) {
    /// skip if not break or return statement
    return;
  }

  /// mark case block has jumped out
  ParseTree *parent_node = break_node->parent;
  // stop loop until current scope node
  while (parent_node && parent_node != GetTreeNode()) {
    auto parent_case_node = dynamic_cast<TypeScriptParser::CaseClauseContext *>(parent_node);
    if (parent_case_node) {
      case_has_jumped_out[ parent_case_node ] = true;
      break;
    } else {
      parent_node = parent_node->parent;
    }
  }
}

/// ScopeManager
ScopeManager::ScopeManager() {
  tree_scope = new ParseTreeProperty<Scope *>();
}
ScopeManager::~ScopeManager() {
  RemoveAllScopes();
  delete tree_scope;
  tree_scope = nullptr;
}
Scope *ScopeManager::GetScope(ParseTree *node) {
  if (node == nullptr) {
    return nullptr;
  }
  Scope *scope = tree_scope->get(node);
  if (scope == nullptr) {
    return GetScope(node->parent);
  }
  return scope;
}
void ScopeManager::SetNewScope(ParseTree *node, Scope *scope) {
  scope_list.push_back(scope);
  tree_scope->put(node, scope);
}

void ScopeManager::RemoveAllScopes() {
  list<Scope *>::iterator it = scope_list.begin();
  while (it != scope_list.end()) {
    delete *it;
    it++;
  }
  scope_list.empty();
}
