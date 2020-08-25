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

/// TODO: performance optimization (like c++)
LlvmValueInfo *DealLogicalOperator(ModuleVisitor *visitor, Scope *scope, FunctionScope *func_scope,
                                   ParseTree *left_tree, ParseTree *right_tree, bool is_and_not_or) {

  auto  func_value = (Function *)func_scope->GetFunctionVariableValue()->value;
  auto &block_list = func_value->getBasicBlockList();

  BasicBlock *RightBB = BasicBlock::Create(visitor->GetLLVMContext(), "");
  BasicBlock *MergeBB = BasicBlock::Create(visitor->GetLLVMContext(), "");

  /// visit left
  auto left_node = move(visitor->visit(left_tree).as<unique_ptr<NodeValue>>());
  scope->NodeValueInitLlvmValueInfo(visitor->builder, left_node.get());
  auto left_value = scope->LoadToRegister(visitor->builder, left_node->GetLlvmValueInfo());
  if (is_and_not_or) {
    /// '&&'
    visitor->builder->CreateCondBr(left_value, RightBB, MergeBB);
  } else {
    /// '||'
    visitor->builder->CreateCondBr(left_value, MergeBB, RightBB);
  }
  /// must after visited left
  BasicBlock *EntryBB = visitor->builder->GetInsertBlock();

  /// visit right
  block_list.push_back(RightBB);
  visitor->builder->SetInsertPoint(RightBB);
  auto right_node = move(visitor->visit(right_tree).as<unique_ptr<NodeValue>>());
  scope->NodeValueInitLlvmValueInfo(visitor->builder, right_node.get());
  auto right_value = scope->LoadToRegister(visitor->builder, right_node->GetLlvmValueInfo());
  visitor->builder->CreateBr(MergeBB);

  /// must after visited right
  auto &RightValueBB = block_list.back();

  /// merge value
  block_list.push_back(MergeBB);
  visitor->builder->SetInsertPoint(MergeBB);
  auto phi = visitor->builder->CreatePHI(Type::getInt1Ty(visitor->GetLLVMContext()), 2);
  if (is_and_not_or) {
    /// '&&'
    phi->addIncoming(GetConstantNumber(VariableType::Boolean, visitor->GetLLVMContext(), 0), EntryBB);
  } else {
    /// '||'
    phi->addIncoming(GetConstantNumber(VariableType::Boolean, visitor->GetLLVMContext(), 1), EntryBB);
  }
  phi->addIncoming(right_value, &RightValueBB);

  return new LlvmValueInfo(new TypeSignInfo(VariableType::Boolean), phi, false);
}

/// '&&'
antlrcpp::Any ModuleVisitor::visitLogicalAndExpression(TypeScriptParser::LogicalAndExpressionContext *ctx) {
  DebugPrintln("[visitLogicalAndExpression] IsPreCheck: %d ; text: %s", IsPrecheckStep(), ctx->getText().data());
  if (IsPrecheckStep()) {
    return visitChildren(ctx);
  }

  Scope *scope      = GetScope(ctx);
  auto   func_scope = GetWrapFunctionScope(ctx);

  auto return_value =
      DealLogicalOperator(this, scope, func_scope, ctx->singleExpression(0), ctx->singleExpression(1), true);

  return make_unique<NodeValue>(return_value);
}

antlrcpp::Any ModuleVisitor::visitLogicalOrExpression(TypeScriptParser::LogicalOrExpressionContext *ctx) {
  DebugPrintln("[visitLogicalOrExpression] IsPreCheck: %d ; text: %s", IsPrecheckStep(), ctx->getText().data());
  if (IsPrecheckStep()) {
    return visitChildren(ctx);
  }

  Scope *scope      = GetScope(ctx);
  auto   func_scope = GetWrapFunctionScope(ctx);

  auto return_value =
      DealLogicalOperator(this, scope, func_scope, ctx->singleExpression(0), ctx->singleExpression(1), false);

  return make_unique<NodeValue>(return_value);
}