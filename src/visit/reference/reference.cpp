#include "visit/reference/reference.h"
#include "common/error/error.h"
#include "utils.h"
#include "visit/visit.h"

using namespace tser;
using namespace std;
using namespace llvm;

Value *ReferenceInfo::CreateInstance(ModuleVisitor *visitor) {
  /// call new to malloc memory
  auto     layout = visitor->module->getDataLayout().getStructLayout(GetReferenceStructType());
  uint64_t length = layout->getSizeInBytes();

  Function *newFunc      = visitor->GetIntrinsicFunctionManager()->GetIntrinsicFunction(IntrinsicFunctionID::Znwm);
  auto      length_value = ConstantInt::get(GetAutoBitType(visitor->GetLLVMContext(), OriginType::NewParam), length);
  CallInst *call_inst    = visitor->builder->CreateCall(newFunc, {length_value});

  Value *this_value = visitor->builder->CreateBitCast(call_inst, GetReferenceStructType()->getPointerTo());

  /// set memory to zero
  Value *zero_value = ConstantInt::get(Type::getInt8Ty(visitor->GetLLVMContext()), 0);
  visitor->builder->CreateMemSet(this_value, zero_value, layout->getSizeInBytes(), MaybeAlign(layout->getAlignment()));

  return this_value;
}

void ReferenceInfo::CallDefaultConstructor(ModuleVisitor *visitor, Value *this_value) {
  /// call default constructor
  Function *      func = (Function *)default_constructor->value;
  vector<Value *> args;
  args.push_back(this_value);
  visitor->builder->CreateCall(func, args);
}

void ReferenceInfo::CreateVariablesStructType(ModuleVisitor *visitor) {
  /// init property 'type'
  vector<Type *> class_struct_type_args;
  VariableValue *pro = nullptr;
  for (auto pro_name : property_queue) {
    pro        = properties[ pro_name ];
    Type *type = VariableTypeToLLVMType(visitor->GetLLVMContext(), pro->type);
    class_struct_type_args.push_back(type);
  }

  /// create main struct type
  reference_struct_type = StructType::create(visitor->GetLLVMContext(), class_struct_type_args, GetTypeName());
}

void ReferenceInfo::CreateDefaultConstructor(ModuleVisitor *visitor) {

  IRBuilder<> *builder = visitor->builder;

  /// Step 1: create function
  auto scope = new FunctionScope(nullptr, visitor->GetModuleScope(), GetDefaultConstroctorName());

  auto func_value_info = unique_ptr<LlvmValueInfo>(
      CreateFunction(GetTypeName(), scope, visitor, GetReferenceStructType(), nullptr, nullptr));

  auto value            = new ReferenceMethodValue(scope, new TypeSignInfo(VariableType::Function));
  value->access_control = AccessControl::Private;
  value->value          = func_value_info->value;
  value->scope          = scope;
  value->SetUsingThis(true);

  scope->SetFunctionVariableValue(value);
  default_constructor = value;

  /// Step 2: load this
  BasicBlock *oldBB = builder->GetInsertBlock();
  LoadReferenceMethodArgs(visitor, this, value, scope, nullptr);

  /// Load this to another variable
  Value *this_arg = scope->GetVariableValue("this")->value;
  Value *this_ptr = builder->CreateAlloca(GetReferenceStructType()->getPointerTo());
  builder->CreateStore(this_arg, this_ptr);
  Value *this_value = builder->CreateLoad(this_ptr);

  /// Step 3: save properties' value to this
  VariableValue *property_src_value = nullptr;
  Value *        target_value       = nullptr;
  var_index      index              = 0;
  Value *        zero_index         = ConstantInt::get(Type::getInt32Ty(visitor->GetLLVMContext()), 0);
  for (auto property : property_queue) {
    property_src_value = GetProperty(property);
    index              = property_queue_index[ property ];
    target_value       = builder->CreateInBoundsGEP(
        this_value, {GetConstantInt(visitor->GetLLVMContext()), GetConstantInt(visitor->GetLLVMContext(), index)});
    builder->CreateStore(property_src_value->value, target_value);
  }
  builder->CreateRetVoid();
  builder->SetInsertPoint(oldBB);
}

/// @param { %class.X * } this_pointer
Value *ReferenceInfo::LoadProperty(Value *this_pointer, IRBuilder<> *builder, string property) {
  auto property_src_value = GetProperty(property);
  auto index              = property_queue_index[ property ];
  auto target_value =
      builder->CreateInBoundsGEP(this_pointer, {ConstantInt::get(Type::getInt32Ty(builder->getContext()), 0),
                                                ConstantInt::get(Type::getInt32Ty(builder->getContext()), index)});
  return target_value;
}

/// @param { %class.X * } this_pointer
FunctionVariableValue *ReferenceInfo::LoadMethod(Value *this_pointer, IRBuilder<> *builder, string key) {
  return GetMethod(key);
}

bool ReferenceInfo::IsMethod(string key) {
  if (methods.count(key) > 0) {
    return true;
  }
  return false;
}
bool ReferenceInfo::IsProperty(string key) {
  if (properties.count(key) > 0) {
    return true;
  }
  return false;
}

void ReferenceInfo::CheckVariable(Scope *scope, string key) {
  if (IsMethod(key) || IsProperty(key)) {
    return;
  }
  auto module_scope = scope->GetModuleScope();
  module_scope->GetProcess()->LoadToModule(module_scope->GetModuleVisitor(), name, key);
  if (IsMethod(key) || IsProperty(key)) {
    return;
  }
  throw VariableNotFoundException(key);
}

void ReferenceInfo::DefineProperty(string key, ReferencePropertyValue *value) {
  if (properties.count(key) > 0) {
    return;
  }
  properties[ key ] = value;
  property_queue.push_back(key);
  property_queue_index[ key ] = property_queue.size() - 1;
}

void ReferenceInfo::DefineMethod(string key, FunctionVariableValue *value) {
  if (methods.count(key) > 0) {
    return;
  }
  methods[ key ] = value;
  method_queue.push_back(key);
}

FunctionVariableValue *ReferenceInfo::GetMethod(string key) {
  return methods[ key ];
}

ReferencePropertyValue *ReferenceInfo::GetProperty(string key) {
  return properties[ key ];
}

ReferenceInfo::~ReferenceInfo() {
  properties.empty();
  property_queue.empty();
  property_queue_index.empty();
  methods.empty();
  method_queue.empty();
}

ReferenceInfoManager::ReferenceInfoManager() {
  tree_reference_info = new ParseTreeProperty<ReferenceInfo *>();
}

ReferenceInfoManager::~ReferenceInfoManager() {
  RemoveAllReferenceInfo();
  delete tree_reference_info;
  tree_reference_info = nullptr;
}

void ReferenceInfoManager::RemoveAllReferenceInfo() {
  for (auto reference_info : reference_info_list) {
    delete reference_info;
  }
  reference_info_list.empty();
}

void ReferenceInfoManager::SetNewReferenceInfo(ParseTree *node, ReferenceInfo *reference_info) {
  reference_info_list.push_back(reference_info);
  tree_reference_info->put(node, reference_info);
}

ReferenceInfo *ReferenceInfoManager::GetReferenceInfo(ParseTree *node) {
  if (node == nullptr) {
    return nullptr;
  }
  ReferenceInfo *reference_info = tree_reference_info->get(node);
  if (reference_info == nullptr) {
    return GetReferenceInfo(node->parent);
  }
  return reference_info;
}
