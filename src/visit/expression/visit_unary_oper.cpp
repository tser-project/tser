#include "antlr4-runtime.h"
#include "common/error/error.h"
#include "grammar/TypeScriptParser.h"
#include "support/Any.h"
#include "tree/ParseTree.h"
#include "utils.h"
#include "visit/visit.h"
#include "llvm/ADT/APSInt.h"
#include "llvm/IR/DerivedTypes.h"
#include "llvm/IR/Instruction.h"

using namespace tser;
using namespace std;
using namespace antlr4;
using namespace llvm;
using namespace antlr4::tree;

/// operator '!'
antlrcpp::Any ModuleVisitor::visitNotExpression(TypeScriptParser::NotExpressionContext *ctx) {
  if (IsPrecheckStep()) {
    return visitChildren(ctx);
  }

  auto scope = GetScope(ctx);

  auto node_value = move(visit(ctx->singleExpression()).as<unique_ptr<NodeValue>>());
  scope->NodeValueInitLlvmValueInfo(builder, node_value.get());

  auto value_info = node_value->GetLlvmValueInfo();
  auto value      = scope->LoadToRegister(builder, value_info);

  Value *return_value = nullptr;
  Value *temp_value   = nullptr;
  switch (value_info->type->type) {
    case VariableType::Boolean:
      return_value = builder->CreateXor(value, ConstantInt::get(Type::getInt1Ty(GetLLVMContext()), 1));
      break;
    case VariableType::Int32:
      temp_value   = builder->CreateICmpNE(value, ConstantInt::get(Type::getInt32Ty(GetLLVMContext()), 0));
      return_value = builder->CreateXor(temp_value, ConstantInt::get(Type::getInt1Ty(GetLLVMContext()), 1));
      break;
    case VariableType::Int64:
      temp_value   = builder->CreateICmpNE(value, ConstantInt::get(Type::getInt64Ty(GetLLVMContext()), 0));
      return_value = builder->CreateXor(temp_value, ConstantInt::get(Type::getInt1Ty(GetLLVMContext()), 1));
      break;
    case VariableType::Float:
      temp_value   = builder->CreateFCmpUNE(value, ConstantFP::get(Type::getFloatTy(GetLLVMContext()), 0));
      return_value = builder->CreateXor(temp_value, ConstantInt::get(Type::getInt1Ty(GetLLVMContext()), 1));
      break;
    case VariableType::Double:
      temp_value   = builder->CreateFCmpUNE(value, ConstantFP::get(Type::getDoubleTy(GetLLVMContext()), 0));
      return_value = builder->CreateXor(temp_value, ConstantInt::get(Type::getInt1Ty(GetLLVMContext()), 1));
      break;
    case VariableType::String:
      temp_value   = GetModuleScope()->LoadGlobalString(this, "");
      temp_value   = builder->CreateICmpNE(value, temp_value);
      return_value = builder->CreateXor(temp_value, ConstantInt::get(Type::getInt1Ty(GetLLVMContext()), 1));
      break;
    case VariableType::Reference:
      temp_value = builder->CreateICmpNE(
          value, ConstantPointerNull::get((PointerType *)VariableTypeToLLVMType(GetLLVMContext(), value_info->type)));
      return_value = builder->CreateXor(temp_value, ConstantInt::get(Type::getInt1Ty(GetLLVMContext()), 1));
      break;
    case VariableType::Null:
      return ConstantInt::get(Type::getInt1Ty(GetLLVMContext()), 1);
    default:
      throw CurrentNotSupportException("operator '!' for current type");
  }
  return make_unique<NodeValue>(new LlvmValueInfo(new TypeSignInfo(VariableType::Boolean), return_value, false));
}

/// deal for '++', '--'
unique_ptr<NodeValue> DealDoubleBinaryExpression(ModuleVisitor *visitor, Scope *scope, ParseTree *expression_node,
                                                 bool is_plus, bool is_pre) {
  auto node_value = move(visitor->visit(expression_node).as<unique_ptr<NodeValue>>());
  scope->NodeValueInitLlvmValueInfo(visitor->builder, node_value.get());

  auto value_info = node_value->GetLlvmValueInfo();

  auto value = scope->LoadToRegister(visitor->builder, value_info);

  auto type = value_info->type->clone();

  Value *new_value =
      visitor->builder->CreateAdd(value, GetConstantNumber(type->type, visitor->GetLLVMContext(), is_plus ? 1 : -1));
  visitor->builder->CreateStore(new_value, value_info->value);

  if (is_pre) {
    return make_unique<NodeValue>(new LlvmValueInfo(type, new_value, false));
  } else {
    return make_unique<NodeValue>(new LlvmValueInfo(type, value, false));
  }
}

/// '++x'
antlrcpp::Any ModuleVisitor::visitPreIncrementExpression(TypeScriptParser::PreIncrementExpressionContext *ctx) {

  if (IsPrecheckStep()) {
    return visitChildren(ctx);
  }

  return DealDoubleBinaryExpression(this, GetScope(ctx), ctx->singleExpression(), true, true);
}

/// 'x++'
antlrcpp::Any ModuleVisitor::visitPostIncrementExpression(TypeScriptParser::PostIncrementExpressionContext *ctx) {
  if (IsPrecheckStep()) {
    return visitChildren(ctx);
  }

  return DealDoubleBinaryExpression(this, GetScope(ctx), ctx->singleExpression(), true, false);
}

/// '--x'
antlrcpp::Any ModuleVisitor::visitPreDecreaseExpression(TypeScriptParser::PreDecreaseExpressionContext *ctx) {

  if (IsPrecheckStep()) {
    return visitChildren(ctx);
  }

  return DealDoubleBinaryExpression(this, GetScope(ctx), ctx->singleExpression(), false, true);
}

/// 'x--'
antlrcpp::Any ModuleVisitor::visitPostDecreaseExpression(TypeScriptParser::PostDecreaseExpressionContext *ctx) {

  if (IsPrecheckStep()) {
    return visitChildren(ctx);
  }

  return DealDoubleBinaryExpression(this, GetScope(ctx), ctx->singleExpression(), false, false);
}