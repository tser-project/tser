#include "utils.h"
#include "antlr4-runtime.h"
#include "common/error/error.h"
#include "support/Any.h"
#include "tree/ParseTree.h"
#include "visit/visit.h"
#include "llvm/ADT/APSInt.h"
#include "llvm/IR/DerivedTypes.h"
#include "llvm/IR/Function.h"
#include "llvm/IR/IRBuilder.h"
#include "llvm/IR/LLVMContext.h"
#include "llvm/IR/Value.h"
#include <stdint.h>

using namespace std;
using namespace antlr4;
using namespace llvm;
using namespace antlr4::tree;
using namespace tser;

BinaryOperModel *tser::DealBinaryParams(Scope *scope, ModuleVisitor *visitor, ParseTree *left, ParseTree *right) {

  auto left_node  = move(visitor->visit(left).as<unique_ptr<NodeValue>>());
  auto right_node = move(visitor->visit(right).as<unique_ptr<NodeValue>>());
  return DealBinaryParams(scope, visitor, left_node.get(), right_node.get());
}

BinaryOperModel *tser::DealBinaryParams(Scope *scope, ModuleVisitor *visitor, NodeValue *left_node,
                                        NodeValue *right_node) {

  scope->NodeValueInitLlvmValueInfo(visitor->builder, left_node);
  scope->NodeValueInitLlvmValueInfo(visitor->builder, right_node);

  // 获取二者上层的类型
  auto upper_type = GetUpperType(left_node->GetLlvmValueInfo()->type, right_node->GetLlvmValueInfo()->type);

  LlvmValueInfo *           left_value_info  = left_node->GetLlvmValueInfo();
  LlvmValueInfo *           right_value_info = right_node->GetLlvmValueInfo();
  unique_ptr<LlvmValueInfo> temp_left;
  unique_ptr<LlvmValueInfo> temp_right;

  if (IsSameType(upper_type, left_node->GetLlvmValueInfo()->type)) {
    /// convert right_node
    right_value_info = TypeCastToTarget(scope, visitor->builder, upper_type, right_node->GetLlvmValueInfo());
    temp_right       = unique_ptr<LlvmValueInfo>(right_value_info);
  } else {
    /// convert left_node
    left_value_info = TypeCastToTarget(scope, visitor->builder, upper_type, left_node->GetLlvmValueInfo());
    temp_left       = unique_ptr<LlvmValueInfo>(left_value_info);
  }

  auto left_value  = scope->LoadToRegister(visitor->builder, left_value_info);
  auto right_value = scope->LoadToRegister(visitor->builder, right_value_info);

  auto binary_model = new BinaryOperModel(upper_type->clone(), left_value, right_value);

  if (upper_type->type == VariableType::Float || upper_type->type == VariableType::Double) {
    binary_model->SetHasFloat(true);
  }

  return binary_model;
}
LlvmValueInfo *tser::DealBinaryOper(Scope *scope, ModuleVisitor *visitor, BinaryOperType oper_type, ParseTree *left,
                                    ParseTree *right, bool is_self_assign) {
  auto left_node  = move(visitor->visit(left).as<unique_ptr<NodeValue>>());
  auto right_node = move(visitor->visit(right).as<unique_ptr<NodeValue>>());

  return DealBinaryOper(scope, visitor, oper_type, left_node.get(), right_node.get(), is_self_assign);
}

LlvmValueInfo *tser::DealBinaryOper(Scope *scope, ModuleVisitor *visitor, BinaryOperType oper_type,
                                    NodeValue *left_node, NodeValue *right_node, bool is_self_assign) {

  auto binary_params = unique_ptr<BinaryOperModel>(DealBinaryParams(scope, visitor, left_node, right_node));
  bool has_float     = binary_params->HasFloat();
  auto left_value    = binary_params->left;
  auto right_value   = binary_params->right;

  auto builder = visitor->builder;

  Value *            value = nullptr;
  TypeSignInfo *     type  = nullptr;
  CmpInst::Predicate P;

  if (oper_type == BinaryOperType::Equals || oper_type == BinaryOperType::NotEquals ||
      oper_type == BinaryOperType::LessThan || oper_type == BinaryOperType::LessThanEquals ||
      oper_type == BinaryOperType::GreaterThan || oper_type == BinaryOperType::GreaterThanEquals) {

    /// for compare operators
    switch (oper_type) {
      case BinaryOperType::Equals:
        P = has_float ? CmpInst::Predicate::FCMP_OEQ : CmpInst::Predicate::ICMP_EQ;
        break;
      case BinaryOperType::NotEquals:
        P = has_float ? CmpInst::Predicate::FCMP_ONE : CmpInst::Predicate::ICMP_NE;
        break;
      case BinaryOperType::LessThan:
        P = has_float ? CmpInst::Predicate::FCMP_OLT : CmpInst::Predicate::ICMP_SLT;
        break;
      case BinaryOperType::LessThanEquals:
        P = has_float ? CmpInst::Predicate::FCMP_OLE : CmpInst::Predicate::ICMP_SLE;
        break;
      case BinaryOperType::GreaterThan:
        P = has_float ? CmpInst::Predicate::FCMP_OGT : CmpInst::Predicate::ICMP_SGT;
        break;
      case BinaryOperType::GreaterThanEquals:
        P = has_float ? CmpInst::Predicate::FCMP_OGE : CmpInst::Predicate::ICMP_SGE;
        break;
      default:
        break;
    }
    value =
        has_float ? builder->CreateFCmp(P, left_value, right_value) : builder->CreateICmp(P, left_value, right_value);
    type = new TypeSignInfo(VariableType::Boolean);
  } else {

    /// for math operators
    switch (oper_type) {
      case BinaryOperType::Plus:
        value = has_float ? builder->CreateFAdd(left_value, right_value) : builder->CreateAdd(left_value, right_value);
        break;
      case BinaryOperType::Minus:
        value = has_float ? builder->CreateFSub(left_value, right_value) : builder->CreateSub(left_value, right_value);
        break;
      case BinaryOperType::Multiply:
        value = has_float ? builder->CreateFMul(left_value, right_value) : builder->CreateMul(left_value, right_value);
        break;
      case BinaryOperType::Divide:
        value = has_float ? builder->CreateFDiv(left_value, right_value) : builder->CreateSDiv(left_value, right_value);
        break;
      case BinaryOperType::Modulus:
        value = builder->CreateSRem(left_value, right_value);
        break;
      default:
        throw CurrentNotSupportException("unknown");
        break;
    }
    type = binary_params->type->clone();
  }
  Value *return_value     = value;
  bool   value_is_pointer = false;
  if (is_self_assign) {
    builder->CreateStore(value, left_node->GetLlvmValueInfo()->value);
    return_value     = left_node->GetLlvmValueInfo()->value;
    value_is_pointer = true;
  }
  return new LlvmValueInfo(type, return_value, value_is_pointer);
}

bool tser::IsSameType(TypeSignInfo *type1, TypeSignInfo *type2) {
  /// Reference Type
  if (type1->type == VariableType::Reference || type2->type == VariableType::Reference) {
    if (type1->type != type2->type)
      return false;
    return type1->reference_info == type2->reference_info;
  }

  /// Function
  if (type1->type == VariableType::Function || type2->type == VariableType::Function) {
    return type1->type == type2->type;
  }

  /// Pre-defined Type
  return type1->type == type2->type;
}

TypeSignInfo *tser::GetUpperType(TypeSignInfo *type1, TypeSignInfo *type2) {
  if (IsSameType(type1, type2)) {
    return type1;
  }

  /// for 'null'
  if (type2->type == VariableType::Null) {
    return type1;
  }
  if (type1->type == VariableType::Null) {
    return type2;
  }

  if (type1->type < VariableType::Boolean || type1->type > VariableType::Double ||
      type2->type < VariableType::Boolean || type2->type > VariableType::Double) {
    throw TypeConvertException("Type cannot convert");
  }

  /// For: bool, int32, int64, float, double
  if (type1->type > type2->type) {
    return type1;
  }
  return type2;
}

LlvmValueInfo *tser::TypeCastToTarget(Scope *scope, IRBuilder<> *builder, TypeSignInfo *target_type,
                                      LlvmValueInfo *current_value_info) {
  /// same type, return directly
  if (IsSameType(target_type, current_value_info->type)) {
    return current_value_info->clone();
  }

  /// null value
  if (current_value_info->type->type == VariableType::Null) {
    return new LlvmValueInfo(target_type->clone(), GetDefaultValue(builder->getContext(), target_type), false);
  }

  auto result   = new LlvmValueInfo(target_type->clone(), current_value_info->ValueIsPointer());
  result->value = nullptr;

  /// Reference Type
  if (target_type->type == VariableType::Reference) {
    result->value =
        builder->CreateBitCast(current_value_info->value, VariableTypeToLLVMType(builder->getContext(), target_type));
    return result;
  }
  /// No need to convert type
  if (target_type->type == VariableType::String || target_type->type == VariableType::Function ||
      target_type->type == VariableType::Any || target_type->type == VariableType::None) {
    result->value = current_value_info->value;
    return result;
  }

  /// Deal with Number and Boolean
  auto  current_type     = current_value_info->type->type;
  bool  need_up          = target_type->type > current_value_info->type->type;
  Type *target_llvm_type = VariableTypeToLLVMType(builder->getContext(), target_type);

  result->SetValueIsPointer(false);
  Value *temp_value = scope->LoadToRegister(builder, current_value_info);

  /// int32 <-> int64
  if ((target_type->type == VariableType::Int32 || target_type->type == VariableType::Int64) &&
      (current_value_info->type->type == VariableType::Int32 ||
       current_value_info->type->type == VariableType::Int64)) {
    if (need_up) {
      result->value = builder->CreateSExt(temp_value, target_llvm_type);
    } else {
      result->value = builder->CreateTrunc(temp_value, target_llvm_type);
    }
    return result;
  }

  /// float <-> double
  if ((target_type->type == VariableType::Float || target_type->type == VariableType::Double) &&
      (current_value_info->type->type == VariableType::Float ||
       current_value_info->type->type == VariableType::Double)) {
    if (need_up) {
      result->value = builder->CreateFPExt(temp_value, target_llvm_type);
    } else {
      result->value = builder->CreateFPTrunc(temp_value, target_llvm_type);
    }
    return result;
  }

  /// float, double -> int32, int64
  if (target_type->type == VariableType::Int32 || target_type->type == VariableType::Int64) {
    if (current_type == VariableType::Float || current_type == VariableType::Double) {
      result->value = builder->CreateFPToSI(temp_value, target_llvm_type);
    } else if (current_type == VariableType::Boolean) {
      result->value = builder->CreateZExt(temp_value, target_llvm_type);
    }
  } else if (target_type->type == VariableType::Float || target_type->type == VariableType::Double) {
    /// int32, int64 -> float, double
    if (current_type == VariableType::Int32 || current_type == VariableType::Int64) {
      result->value = builder->CreateSIToFP(temp_value, target_llvm_type);
    } else if (current_type == VariableType::Boolean) {
      result->value = builder->CreateUIToFP(temp_value, target_llvm_type);
    }
  } else if (target_type->type == VariableType::Boolean) {
    if (current_type == VariableType::Int32 || current_type == VariableType::Int64) {
      /// int32, int64 -> bool
      result->value = builder->CreateICmp(CmpInst::Predicate::ICMP_NE, temp_value,
                                          GetDefaultValue(builder->getContext(), current_value_info->type));
    } else if (current_type == VariableType::Float || current_type == VariableType::Double) {
      /// float, double -> bool
      result->value = builder->CreateFCmp(CmpInst::Predicate::FCMP_UNE, temp_value,
                                          GetDefaultValue(builder->getContext(), current_value_info->type));
    }
  }
  if (!result->value) {
    delete result;
    throw TypeConvertException("Type cannot convert");
  }
  return result;
}

Type *tser::VariableTypeToLLVMType(LLVMContext &context, TypeSignInfo *type_info) {
  switch (type_info->type) {
    case VariableType::Boolean:
      return Type::getInt1Ty(context);
    case VariableType::Int32:
    case VariableType::Enum:
      return Type::getInt32Ty(context);
    case VariableType::Int64:
      return Type::getInt64Ty(context);
    case VariableType::Float:
      return Type::getFloatTy(context);
    case VariableType::Double:
      return Type::getDoubleTy(context);
    case VariableType::String:
      return Type::getInt8PtrTy(context);
    case VariableType::Reference:
      return type_info->reference_info->GetReferenceStructType()->getPointerTo();
    case VariableType::Void:
      return Type::getVoidTy(context);
    case VariableType::None:
    default:
      assert(false);
      return nullptr;
  }
}

Type *tser::GetAutoBitType(LLVMContext &context, OriginType type) {
  switch (type) {
    case OriginType::Int64t:
      return Type::getInt64Ty(context);
    case OriginType::Long:
      return TSER_TARGET_BITS == 64 ? Type::getInt64Ty(context) : Type::getInt32Ty(context);
    case OriginType::NewParam:
    case OriginType::MemSet:
      return TSER_TARGET_BITS == 64 ? Type::getInt64Ty(context) : Type::getInt32Ty(context);
    default:
      return nullptr;
  }
}

bool tser::TypeIsNone(TypeSignInfo *type) {
  if (type->type == VariableType::None) {
    return true;
  }
  return false;
}

/// memory alignment
MaybeAlign tser::GetMaybeAlign(TypeSignInfo *type) {
  return GetMaybeAlign(type->type);
}
MaybeAlign tser::GetMaybeAlign(VariableType type) {
  switch (type) {
    case VariableType::Boolean:
      return MaybeAlign(sizeof(bool));
    case VariableType::Int32:
    case VariableType::Enum:
      return MaybeAlign(sizeof(int));
    case VariableType::Int64:
      return MaybeAlign(sizeof(int64_t));
    case VariableType::Float:
      return MaybeAlign(sizeof(float));
    case VariableType::Double:
      return MaybeAlign(sizeof(double));
    case VariableType::String:
    case VariableType::Reference:
      return MaybeAlign(sizeof(void *));
    case VariableType::Void:
    case VariableType::None:
    default:
      assert(false);
      return MaybeAlign(0);
  }
}

Constant *tser::GetDefaultValue(LLVMContext &context, TypeSignInfo *type) {
  switch (type->type) {
    case VariableType::Boolean:
      return ConstantInt::get(llvm::Type::getInt1Ty(context), 0);
    case VariableType::Int32:
      return ConstantInt::get(llvm::Type::getInt32Ty(context), 0);
    case VariableType::Int64:
      return ConstantInt::get(llvm::Type::getInt64Ty(context), 0);
    case VariableType::Float:
      return ConstantFP::get(llvm::Type::getFloatTy(context), 0);
    case VariableType::Double:
      return ConstantFP::get(llvm::Type::getDoubleTy(context), 0);
    case VariableType::String:
    case VariableType::Reference:
      return ConstantPointerNull::get((PointerType *)VariableTypeToLLVMType(context, type));
    case VariableType::Void:
    default:
      return nullptr;
  }
}

/// utils for function
LlvmValueInfo *tser::CreateFunction(string class_name, FunctionScope *scope, ModuleVisitor *visitor,
                                    StructType *                                  parent_or_this_struct_type,
                                    TypeScriptParser::FormalParameterListContext *formalParameterList,
                                    TypeScriptParser::TypeSignContext *           return_type_sign) {

  vector<string> func_arg_names = visitor->visitFormalParameterList(formalParameterList);
  VariableValue *arg_value;

  vector<Type *> func_args_type;
  if (parent_or_this_struct_type) {
    func_args_type.push_back(parent_or_this_struct_type->getPointerTo());
  }

  for (string arg_name : func_arg_names) {
    arg_value = scope->GetVariableValue(arg_name);
    func_args_type.push_back(VariableTypeToLLVMType(visitor->GetLLVMContext(), arg_value->type));
  }

  auto return_type = (TypeSignInfo *)visitor->visitTypeSign(return_type_sign);

  /// function does not support type inference currently
  if (return_type->type == VariableType::None) {
    delete return_type;
    return_type = new TypeSignInfo(VariableType::Void);
  }
  Type *return_llvm_type = VariableTypeToLLVMType(visitor->GetLLVMContext(), return_type);

  /// create function
  FunctionType *  func_type   = FunctionType::get(return_llvm_type, func_args_type, false);
  string          module_name = GenerateGlobalFunctionName(scope, visitor->module->getName(), class_name);
  llvm::Function *func = Function::Create(func_type, GlobalValue::ExternalLinkage, module_name, *visitor->module);
  return new LlvmValueInfo(return_type, func);
}

LlvmValueInfo *tser::CreateBuiltinFunction(string class_name, string function_name, ModuleVisitor *visitor,
                                           StructType *this_struct_type, vector<TypeSignInfo *> arg_types,
                                           TypeSignInfo *return_type, bool is_var_arg) {

  // vector<string> func_arg_names = visitor->visitFormalParameterList(formalParameterList);
  VariableValue *arg_value;

  vector<Type *> func_args_type;
  if (this_struct_type) {
    func_args_type.push_back(this_struct_type->getPointerTo());
  }

  for (auto arg_type : arg_types) {
    auto type = VariableTypeToLLVMType(visitor->GetLLVMContext(), arg_type);
    func_args_type.push_back(arg_type->IsPointerType() ? type->getPointerTo() : type);
  }

  Type *return_llvm_type = VariableTypeToLLVMType(visitor->GetLLVMContext(), return_type);

  /// create function
  FunctionType *  func_type         = FunctionType::get(return_llvm_type, func_args_type, is_var_arg);
  string          compile_func_name = GetBuiltinFunctionName("tser", class_name, function_name, arg_types, is_var_arg);
  llvm::Function *func = Function::Create(func_type, GlobalValue::ExternalLinkage, compile_func_name, *visitor->module);
  return new LlvmValueInfo(return_type->clone(), func);
}

void tser::LoadFunctionArgs(ModuleVisitor *visitor, FunctionScope *scope, llvm::Function *func,
                            TypeScriptParser::FormalParameterListContext *formalParameterList) {

  BasicBlock *main_block = BasicBlock::Create(visitor->GetLLVMContext(), "", func);

  visitor->builder->SetInsertPoint(main_block);

  unsigned actual_arg_index   = 0;
  bool     parent_arg_checked = false;

  vector<string> func_arg_names = visitor->visitFormalParameterList(formalParameterList);
  string         arg_name       = "";
  VariableValue *saved_value    = nullptr;
  for (auto &arg : func->args()) {
    if (scope->HasParentVariablesQueue() && !parent_arg_checked) {
      scope->SetParentVariablesStructValue(&arg);
      parent_arg_checked = true;
      continue;
    }
    arg_name = func_arg_names[ actual_arg_index ];
    arg.setName(arg_name);

    saved_value = scope->GetVariableValue(arg_name);

    AllocaInst *value =
        visitor->builder->CreateAlloca(VariableTypeToLLVMType(visitor->GetLLVMContext(), saved_value->type));
    // value->setAlignment(GetMaybeAlign(saved_value->type));
    visitor->builder->CreateStore(&arg, value);
    saved_value->value = value;

    actual_arg_index++;
  }
}

void tser::AutoAddVarArgs(ModuleVisitor *visitor, vector<Value *> &all_arguments,
                          vector<unique_ptr<NodeValue>> &real_arguments) {
  auto       builder         = visitor->builder;
  auto       args_size       = real_arguments.size();
  Type *     item_type       = IntegerType::getInt32Ty(visitor->GetLLVMContext());
  ArrayType *item_array_type = ArrayType::get(item_type, args_size);

  auto array_pointer = visitor->builder->CreateAlloca(item_array_type);

  int  index = 0;
  auto zero  = GetConstantInt(visitor->GetLLVMContext(), 0);
  for (auto &temp_node_value : real_arguments) {
    auto ptr   = builder->CreateInBoundsGEP(array_pointer, {zero, GetConstantInt(visitor->GetLLVMContext(), index++)});
    auto value = ConstantInt::get(Type::getInt32Ty(visitor->GetLLVMContext()),
                                  static_cast<int>(temp_node_value->GetLlvmValueInfo()->type->type));

    builder->CreateStore(value, ptr);
  };

  Value *arg_value       = visitor->builder->CreateInBoundsGEP(array_pointer, {zero, zero});
  auto   art_start_index = all_arguments.size() - real_arguments.size();

  all_arguments.insert(all_arguments.begin() + art_start_index, arg_value);
  all_arguments.insert(all_arguments.begin() + art_start_index, GetConstantInt(visitor->GetLLVMContext(), args_size));
}

// union function name
string tser::GenerateGlobalFunctionName(FunctionScope *current_scope, string module_name, string class_name) {
  string name = module_name + ".";
  if (class_name != "") {
    name.append(class_name).append(".");
  }
  if (!current_scope->IsModule()) {
    FunctionScope *temp_scope = current_scope->GetWrapFunctionScope();
    list<string>   scope_names;
    while (temp_scope) {
      if (!temp_scope->IsModule()) {
        scope_names.push_front(temp_scope->GetName());
      }
      temp_scope = temp_scope->GetParentFunctionScope();
    }
    int index = scope_names.size();
    for (string scope_name : scope_names) {
      name.append(scope_name);
      if (--index > 0) {
        name.append(".");
      }
    }
  } else {
    name.append(current_scope->GetName());
  }
  return name;
}

/// Same rules as clang++ compiler
string tser::GetBuiltinFunctionName(string spacename, string class_name, string function_name,
                                    vector<TypeSignInfo *> arguments_type, bool is_var_arg) {
  string name = "_ZN";
  if (spacename != "") {
    name.append(to_string(spacename.size())).append(spacename);
  }
  name.append(to_string(class_name.size())).append(class_name);
  name.append(to_string(function_name.size())).append(function_name);
  name.append("E");
  if (arguments_type.size() == 0) {
    name.append("v");
  }
  for (auto arg_type : arguments_type) {
    if (arg_type->IsPointerType()) {
      name.append("P");
    }
    switch (arg_type->type) {
      case VariableType::Boolean:
        name.append("b");
        break;
      case VariableType::Int32:
        name.append("i");
        break;
      case VariableType::Int64:
        name.append("x");
        break;
      case VariableType::Float:
        name.append("f");
        break;
      case VariableType::Double:
        name.append("d");
        break;
      case VariableType::String:
        name.append("NSt3__112basic_stringIcNS0_11char_traitsIcEENS0_9allocatorIcEEEE");
        break;
      case VariableType::Enum:
        if (arg_type->name->spacename != "") {
          if (arg_type->name->spacename == spacename) {
            name.append("NS_");
          } else {
            name.append("N").append(to_string(arg_type->name->spacename.size())).append(arg_type->name->spacename);
          }
        }
        name.append(to_string(arg_type->name->name.size())).append(arg_type->name->name);
        name.append("E");
        break;
      default:
        break;
    }
  }
  if (is_var_arg) {
    name.append("z");
  }
  return name;
}

/// utils for reference
void tser::LoadReferenceMethodArgs(ModuleVisitor *visitor, ReferenceInfo *class_info, FunctionVariableValue *value,
                                   Scope *scope, TypeScriptParser::FormalParameterListContext *formalParameterList) {

  auto func_value = (Function *)value->value;

  BasicBlock *main_block = BasicBlock::Create(visitor->GetLLVMContext(), "", func_value);

  visitor->builder->SetInsertPoint(main_block);

  unsigned actual_arg_index = 0;
  bool     this_arg_checked = false;

  vector<string> func_arg_names = visitor->visitFormalParameterList(formalParameterList);

  string         arg_name    = "";
  VariableValue *saved_value = nullptr;
  for (auto &arg : func_value->args()) {
    if (value->UsingThis() && !this_arg_checked) {
      auto this_value =
          new VariableValue(scope, new TypeSignInfo(VariableType::Reference, class_info), (Value *)(&arg), false);
      scope->DefineVariable("this", this_value);
      arg.setName("this");
      this_arg_checked = true;
      continue;
    }
    arg_name = func_arg_names[ actual_arg_index ];
    arg.setName(arg_name);

    saved_value = scope->GetVariableValue(arg_name);

    Value *v = visitor->builder->CreateAlloca(VariableTypeToLLVMType(visitor->GetLLVMContext(), saved_value->type));
    visitor->builder->CreateStore(&arg, v);
    saved_value->value = v;

    actual_arg_index++;
  }
}

Constant *tser::GetConstantNumber(VariableType type, LLVMContext &context, int64_t value) {
  switch (type) {
    case VariableType::Int32:
      return ConstantInt::get(Type::getInt32Ty(context), value);
      break;
    case VariableType::Int64:
      return ConstantInt::get(Type::getInt64Ty(context), value);
      break;
    case VariableType::Float:
      return ConstantFP::get(Type::getFloatTy(context), (float)value);
      break;
    case VariableType::Double:
      return ConstantFP::get(Type ::getDoubleTy(context), (double)(value));
      break;
    default:
      break;
  }
  return nullptr;
}

Constant *tser::GetConstantNumber(VariableType type, LLVMContext &context, string value) {
  switch (type) {
    case VariableType::Int32:
      return ConstantInt::get(Type::getInt32Ty(context), APInt(32, value, 10));
      break;
    case VariableType::Int64:
      return ConstantInt::get(Type::getInt64Ty(context), APInt(64, value, 10));
      break;
    case VariableType::Float:
      return ConstantFP::get(Type::getFloatTy(context), APFloat(stof(value)));
      break;
    case VariableType::Double:
      return ConstantFP::get(Type ::getDoubleTy(context), APFloat(stod(value)));
      break;
    default:
      break;
  }
  return nullptr;
}

ConstantInt *tser::GetConstantInt(LLVMContext &context, int value) {
  return ConstantInt::get(Type::getInt32Ty(context), value);
}

bool tser::IsFunctionLastReturnStatement(TypeScriptParser::ReturnStatementContext *ctx) {
  auto statement_list = (TypeScriptParser::StatementListContext *)ctx->parent->parent; // ctx->parent must be statement
  if (!statement_list || !statement_list->parent ||
      !dynamic_cast<TypeScriptParser::FunctionBodyContext *>(statement_list->parent)) {
    return false;
  }
  return statement_list->statement(statement_list->children.size() - 1)->returnStatement() == ctx;
}

bool tser::ClassIsStatic(vector<TypeScriptParser::ClassControlContext *> class_controls) {
  if (class_controls.size() == 0) {
    return false;
  }
  for (auto &con : class_controls) {
    if (con->Static()) {
      return true;
    }
  }
  return false;
}

bool tser::ClassIsFinal(vector<TypeScriptParser::ClassControlContext *> class_controls) {
  if (class_controls.size() == 0) {
    return false;
  }
  for (auto &con : class_controls) {
    if (con->Final()) {
      return true;
    }
  }
  return false;
}

bool tser::PropertyIsStatic(vector<TypeScriptParser::PropertyControlContext *> property_controls) {
  if (property_controls.size() == 0) {
    return false;
  }
  for (auto &con : property_controls) {
    if (con->Static()) {
      return true;
    }
  }
  return false;
}

bool tser::PropertyIsReadonly(vector<TypeScriptParser::PropertyControlContext *> property_controls) {
  if (property_controls.size() == 0) {
    return false;
  }
  for (auto &con : property_controls) {
    if (con->Readonly()) {
      return true;
    }
  }
  return false;
}

bool tser::FunctionIsStatic(vector<TypeScriptParser::FunctionControlContext *> function_controls) {
  if (function_controls.size() == 0) {
    return false;
  }
  for (auto &con : function_controls) {
    if (con->Static()) {
      return true;
    }
  }
  return false;
}

bool tser::FunctionIsFinal(vector<TypeScriptParser::FunctionControlContext *> function_controls) {
  if (function_controls.size() == 0) {
    return false;
  }
  for (auto &con : function_controls) {
    if (con->Final()) {
      return true;
    }
  }
  return false;
}