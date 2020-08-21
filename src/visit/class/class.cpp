#include "visit/class/class.h"
#include "common/error/error.h"
#include "utils.h"
#include "visit/reference/reference.h"
#include "visit/visit.h"

using namespace std;
using namespace tser;
using namespace llvm;

void ClassInfo::InitVariables(ModuleVisitor *visitor, Scope *scope, Value *this_value) {
  IRBuilder<> *builder = visitor->builder;

  if (GetSuperClass()) {
    Value *parent_this = builder->CreateBitCast(this_value, GetSuperClass()->GetReferenceStructType()->getPointerTo());
    GetSuperClass()->InitVariables(visitor, scope, parent_this);
  }

  ReferencePropertyValue *property_src_value  = nullptr;
  Value *                 target_value        = nullptr;
  var_index               index               = 0;
  int                     property_root_index = GetPropertyStartIndex();
  Value *                 zero_index          = GetConstantInt(visitor->GetLLVMContext(), 0);
  for (auto property : property_queue) {
    property_src_value = GetProperty(property);
    Value *value       = nullptr;
    /// visit property node to save value to `this`
    if (property_src_value->GetTreeNode()) {
      auto node_value = move(visitor->visit(property_src_value->GetTreeNode()).as<unique_ptr<NodeValue>>());
      scope->NodeValueInitLlvmValueInfo(builder, node_value.get());
      value = node_value->GetLlvmValueInfo()->value;
    }
    if (!value) {
      continue;
    }
    index        = property_queue_index[ property ];
    target_value = builder->CreateInBoundsGEP(
        this_value,
        {zero_index, ConstantInt::get(Type::getInt32Ty(visitor->GetLLVMContext()), property_root_index + index)});
    builder->CreateStore(value, target_value);
  }
}

void ClassInfo::CreateDefaultConstructor(ModuleVisitor *visitor) {
  if (!HasMapTable()) {
    return ReferenceInfo::CreateDefaultConstructor(visitor);
  }

  IRBuilder<> *builder = visitor->builder;

  // Step 1: create function
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

  // Load this to a new writable variable
  Value *this_arg = scope->GetVariableValue("this")->value;
  Value *this_ptr = builder->CreateAlloca(GetReferenceStructType()->getPointerTo());
  builder->CreateStore(this_arg, this_ptr);
  Value *this_value = builder->CreateLoad(this_ptr);

  /// Step 3: save self properties' value to this
  InitVariables(visitor, scope, this_value);

  /// Step4: get root class
  Value *root_type_this_value               = this_value;
  Value *root_type_property_map_table_value = property_map_table_value;
  if (!IsRootMapClass()) {
    ClassInfo *root_class_info = GetRootClass();
    root_type_this_value =
        builder->CreateBitCast(this_value, root_class_info->GetReferenceStructType()->getPointerTo());
    root_type_property_map_table_value = builder->CreateBitCast(root_type_property_map_table_value,
                                                                root_class_info->property_map_table_value->getType());
  }

  /// Step5: replace property-map value to root address
  Value *zero_index             = GetConstantInt(visitor->GetLLVMContext(), 0);
  Value *property_map_table_ptr = builder->CreateInBoundsGEP(root_type_this_value, {zero_index, zero_index});
  builder->CreateStore(root_type_property_map_table_value, property_map_table_ptr);

  // Step6: replace method-map vlaue to root address
  if (method_map_table_value) {
    /// i8**
    Value *temp_value = builder->CreateInBoundsGEP(
        root_type_this_value, {zero_index, ConstantInt::get(Type::getInt32Ty(visitor->GetLLVMContext()), 1)});
    /// convert to map constant address: x.method**
    temp_value = builder->CreateBitCast(temp_value, method_map_table_value->getType()->getPointerTo());
    builder->CreateStore(method_map_table_value, temp_value);
  }

  builder->CreateRetVoid();
  builder->SetInsertPoint(oldBB);
}

/// @param { %class.X * } this_pointer
Value *ClassInfo::LoadProperty(Value *this_pointer, IRBuilder<> *builder, string key) {

  if (!HasMapTable()) {
    return ReferenceInfo::LoadProperty(this_pointer, builder, key);
  }

  if (property_map_table_index.count(key) == 0) {
    throw VariableNotFoundException(key);
  }

  // Step 1: load pointer of property-map-table
  Value *temp_value = builder->CreateBitCast(this_pointer, property_map_table_value->getType()->getPointerTo());
  temp_value = builder->CreateInBoundsGEP(temp_value, {ConstantInt::get(Type::getInt32Ty(builder->getContext()), 0)});
  temp_value = builder->CreateLoad(temp_value);

  Value *zore_index = ConstantInt::get(Type::getInt32Ty(builder->getContext()), 0);

  // Step 2: load offset value of target property
  auto map_table_index = property_map_table_index[ key ];
  temp_value           = builder->CreateInBoundsGEP(
      temp_value, {zore_index, ConstantInt::get(Type::getInt32Ty(builder->getContext()), map_table_index)});
  Value *offset = builder->CreateLoad(temp_value);

  // Step 3: load target value
  Type *type = VariableTypeToLLVMType(builder->getContext(), GetProperty(key)->type);
  temp_value = builder->CreateBitCast(this_pointer, Type::getInt8PtrTy(builder->getContext()));
  temp_value = builder->CreateInBoundsGEP(temp_value, {offset});
  temp_value = builder->CreateBitCast(temp_value, type->getPointerTo());

  return temp_value;
}

/// @param { %class.X * } this_pointer
FunctionVariableValue *ClassInfo::LoadMethod(Value *this_pointer, IRBuilder<> *builder, string key) {

  if (!HasMapTable() || !MethodIsInheritAble(key)) {
    return ReferenceInfo::LoadMethod(this_pointer, builder, key);
  }

  if (method_map_table_index.count(key) == 0) {
    throw FunctionNotFoundException(key, true);
  }

  // Step 1: load pointer of property-map-table
  Value *temp_value = builder->CreateBitCast(this_pointer, method_map_table_value->getType()->getPointerTo());
  temp_value = builder->CreateInBoundsGEP(temp_value, {ConstantInt::get(Type::getInt32Ty(builder->getContext()), 1)});
  temp_value = builder->CreateLoad(temp_value);

  Value *zore_index = ConstantInt::get(Type::getInt32Ty(builder->getContext()), 0);

  // Step 2: get index value of target method
  auto  map_table_index = method_map_table_index[ key ];
  Type *type            = method_map_table_types_cache[ map_table_index ];
  temp_value            = builder->CreateInBoundsGEP(
      temp_value, {zore_index, ConstantInt::get(Type::getInt32Ty(builder->getContext()), map_table_index)});

  // Step 3: bit cast to target value
  temp_value = builder->CreateLoad(temp_value);

  auto old_var_value = GetMethod(key);
  auto var_value     = old_var_value->cloneWithoutValue();
  var_value->value   = temp_value;

  return var_value;
}

void ClassInfo::CreateVariablesStructType(ModuleVisitor *visitor) {

  if (!HasMapTable()) {
    return ReferenceInfo::CreateVariablesStructType(visitor);
  }

  /// RootClass     : { 'pointer of property map', 'pointer of method map', property1, property2 }
  /// Not RootClass : { 'root class', property1, property2 }
  vector<Type *> class_struct_type_args;

  /// if super class has this property, only update it's offset;
  map<string, var_index> *super_property_map_table_index = nullptr;
  if (!IsRootMapClass()) {

    /// copy from closest parent class
    property_map_table_types_cache       = GetSuperClass()->property_map_table_types_cache;
    property_map_table_index             = GetSuperClass()->property_map_table_index;
    property_map_table_value_queue_cache = GetSuperClass()->property_map_table_value_queue_cache;
    super_property_map_table_index       = &(GetSuperClass()->property_map_table_index);
  }

  /// init property 'type'
  ReferencePropertyValue *pro = nullptr;
  for (auto pro_name : property_queue) {
    pro        = (ReferencePropertyValue *)properties[ pro_name ];
    Type *type = VariableTypeToLLVMType(visitor->GetLLVMContext(), pro->type);
    // TODO: read tser::var_index size to llvm-type
    if (!super_property_map_table_index || super_property_map_table_index->count(pro_name) == 0) {
      property_map_table_types_cache.push_back(GetOffsetType(visitor->GetLLVMContext()));
      property_map_table_index[ pro_name ] = property_map_table_types_cache.size() - 1;
    }
    class_struct_type_args.push_back(type);
  }

  string      property_map_table_name = GetTypeName() + ".property";
  StructType *property_map_table_struct_type =
      StructType::create(visitor->GetLLVMContext(), property_map_table_types_cache, property_map_table_name);

  /// add map-table's type or parent-class's type to current class
  if (IsRootMapClass()) {
    class_struct_type_args.insert(class_struct_type_args.begin(), Type::getInt8PtrTy(visitor->GetLLVMContext()));
    class_struct_type_args.insert(class_struct_type_args.begin(), property_map_table_struct_type->getPointerTo());
  } else {
    class_struct_type_args.insert(class_struct_type_args.begin(), super_class->reference_struct_type);
  }

  /// create main struct type
  reference_struct_type = StructType::create(visitor->GetLLVMContext(), class_struct_type_args, GetTypeName());

  int property_root_index = GetPropertyStartIndex();

  /// create constant: property map-table
  for (auto pro_name : property_queue) {
    auto offset = visitor->module->getDataLayout()
                      .getStructLayout(reference_struct_type)
                      ->getElementOffset(property_root_index + property_queue_index[ pro_name ]);
    Constant *offset_value = ConstantInt::get(GetOffsetType(visitor->GetLLVMContext()), offset);
    if (!super_property_map_table_index || super_property_map_table_index->count(pro_name) == 0) {
      property_map_table_value_queue_cache.push_back(offset_value);
    } else {
      property_map_table_value_queue_cache[ super_property_map_table_index->at(pro_name) ] = offset_value;
    }
  }

  property_map_table_value =
      new GlobalVariable(*visitor->module, property_map_table_struct_type, true, GlobalValue::LinkOnceODRLinkage,
                         ConstantStruct::get(property_map_table_struct_type, property_map_table_value_queue_cache),
                         property_map_table_name);
}

void ClassInfo::CreateMethodsMapTable(ModuleVisitor *visitor) {

  if (!has_map_table) {
    return;
  }

  if (!IsRootMapClass()) {
    /// copy from closest parent class
    method_map_table_types_cache       = GetSuperClass()->method_map_table_types_cache;
    method_map_table_index             = GetSuperClass()->method_map_table_index;
    method_map_table_value_queue_cache = GetSuperClass()->method_map_table_value_queue_cache;
  }

  /// init method 'type' and 'value'
  ReferenceMethodValue *method = nullptr;
  for (auto method_name : method_queue) {
    if (!MethodIsInheritAble(method_name)) {
      continue;
    }
    method = (ReferenceMethodValue *)methods[ method_name ];
    if (method_map_table_index.count(method_name) == 0) {
      method_map_table_types_cache.push_back(((Function *)(method->value))->getFunctionType()->getPointerTo());
      method_map_table_index[ method_name ] = method_map_table_types_cache.size() - 1;
      method_map_table_value_queue_cache.push_back((Function *)(method->value));
    } else {
      method_map_table_value_queue_cache[ method_map_table_index[ method_name ] ] = (Function *)(method->value);
    }
  }

  string method_map_table_name = GetTypeName() + ".method";

  StructType *method_map_table_struct_type =
      StructType::create(visitor->GetLLVMContext(), method_map_table_types_cache, method_map_table_name);

  if (method_map_table_value_queue_cache.size() > 0) {
    Constant *_v           = ConstantStruct::get(method_map_table_struct_type, method_map_table_value_queue_cache);
    method_map_table_value = new GlobalVariable(*visitor->module, method_map_table_struct_type, true,
                                                GlobalValue::LinkOnceODRLinkage, _v, method_map_table_name);
  }
}

ReferenceMethodValue *ClassInfo::GetMethod(string key) {
  return (ReferenceMethodValue *)ReferenceInfo::GetMethod(key);
}
ReferencePropertyValue *ClassInfo::GetProperty(string key) {
  return (ReferencePropertyValue *)ReferenceInfo::GetProperty(key);
}

bool ClassInfo::MethodIsInheritAble(string key) {
  auto method = GetMethod(key);
  if (!method || method->is_static || method->is_final || method->access_control == AccessControl::Private) {
    return false;
  }
  return true;
}
bool ClassInfo::PropertyIsInheritAble(string key) {
  auto property = GetProperty(key);
  if (!property || property->is_static || property->is_final || property->access_control == AccessControl::Private) {
    return false;
  }
  return true;
}

bool ClassInfo::PropertyIsStatic(string key) {
  auto property = GetProperty(key);
  if (!property || !property->is_static) {
    return false;
  }
  return true;
}

ClassInfo *ClassInfo::GetRootClass() {
  ClassInfo *temp = this;
  while (temp->super_class) {
    temp = temp->super_class;
  }
  return temp;
}

void ClassInfo::CallCustomConstructor(IRBuilder<> *builder, Value *this_value, vector<Value *> arguments) {
  ClassInfo *            target_class_info = this;
  FunctionVariableValue *temp_value        = target_class_info->custom_constructor;
  while (!temp_value && target_class_info) {
    target_class_info = target_class_info->GetSuperClass();
    if (target_class_info) {
      temp_value = target_class_info->custom_constructor;
    }
  }
  if (!temp_value) {
    return;
  }

  if (target_class_info != this) {
    this_value     = builder->CreateBitCast(this_value, target_class_info->GetReferenceStructType()->getPointerTo());
    arguments[ 0 ] = this_value;
  }
  builder->CreateCall(temp_value->value, arguments);
}

FunctionVariableValue *ClassInfo::GetCustomConstructor() {
  if (custom_constructor) {
    return custom_constructor;
  }
  if (GetSuperClass()) {
    return GetSuperClass()->GetCustomConstructor();
  }
  return nullptr;
}

Type *ClassInfo::GetOffsetType(LLVMContext &context) {
  return GetAutoBitType(context, OriginType::Int64t);
}

ClassInfo::~ClassInfo() {
  super_class = nullptr;
  property_map_table_index.empty();
  property_map_table_types_cache.empty();
  property_map_table_value = nullptr;
  property_map_table_value_queue_cache.empty();
  method_map_table_index.empty();
  method_map_table_types_cache.empty();
  method_map_table_value = nullptr;
  method_map_table_value_queue_cache.empty();
}