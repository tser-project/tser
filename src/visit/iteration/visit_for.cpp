#include "antlr4-runtime.h"
#include "common/error/error.h"
#include "grammar/TypeScriptParser.h"
#include "support/Any.h"
#include "tree/ParseTree.h"
#include "visit/visit.h"
#include "llvm/ADT/APSInt.h"
#include "llvm/IR/DerivedTypes.h"
#include "llvm/IR/Instruction.h"
#include <string>

using namespace tser;
using namespace std;
using namespace antlr4;
using namespace llvm;
using namespace antlr4::tree;

antlrcpp::Any ModuleVisitor::visitForStatement(TypeScriptParser::ForStatementContext *ctx) {

  if (IsPrecheckStep()) {
    auto parent_scope = GetScope(ctx->parent);
    auto scope        = new BlockScope(ctx, BlockType::For, parent_scope);

    SetNewScope(ctx, scope);

    visitChildren(ctx);
    return defaultResult();
  }
  auto scope = (BlockScope *)GetScope(ctx);

  auto  func_value = (Function *)GetWrapFunctionScope(ctx)->GetFunctionVariableValue()->value;
  auto &block_list = func_value->getBasicBlockList();

  /// visit initialization
  visitForInitialization(ctx->forInitialization());

  /// thunk block, merge to this when end
  BasicBlock *ThunkBB = BasicBlock::Create(GetLLVMContext(), "");
  /// content block, must have this
  BasicBlock *ContentBB = BasicBlock::Create(GetLLVMContext(), "");

  BasicBlock *ConditionBB       = nullptr;
  BasicBlock *FinalExpressionBB = nullptr;

  bool has_condition        = !!ctx->forCondition();
  bool has_final_expression = !!ctx->expressionSequence();

  /// init condition block
  if (has_condition) {
    ConditionBB = BasicBlock::Create(GetLLVMContext(), "");
    scope->SetConditionBlock(ConditionBB);
  } else {
    ConditionBB = ContentBB;
  }

  /// init final expression
  if (has_final_expression) {
    FinalExpressionBB = BasicBlock::Create(GetLLVMContext(), "");
  } else {
    FinalExpressionBB = ConditionBB;
  }

  /// save to scope
  scope->SetMergeBlock(ThunkBB);
  scope->SetContinueJumpBlock(FinalExpressionBB);

  /// visit condition
  if (has_condition) {
    builder->CreateBr(ConditionBB);
    block_list.push_back(ConditionBB);

    builder->SetInsertPoint(ConditionBB);
    auto condition_node = move(visitForCondition(ctx->forCondition()).as<unique_ptr<NodeValue>>());
    scope->NodeValueInitLlvmValueInfo(builder, condition_node.get());
    auto condition_value = scope->LoadToRegister(builder, condition_node->GetLlvmValueInfo());
    builder->CreateCondBr(condition_value, ContentBB, ThunkBB);
  } else {
    builder->CreateBr(ContentBB);
  }

  /// visit content block
  block_list.push_back(ContentBB);
  builder->SetInsertPoint(ContentBB);
  if (ctx->statement()) {
    visitStatement(ctx->statement());
  }
  if (!scope->HasJumpedOut()) {
    builder->CreateBr(FinalExpressionBB);
  }

  /// visit final expression
  if (has_final_expression) {
    block_list.push_back(FinalExpressionBB);
    builder->SetInsertPoint(FinalExpressionBB);
    visit(ctx->expressionSequence());
    builder->CreateBr(ConditionBB);
  }

  block_list.push_back(ThunkBB);
  builder->SetInsertPoint(ThunkBB);

  return defaultResult();
}

antlrcpp::Any ModuleVisitor::visitForInitialization(TypeScriptParser::ForInitializationContext *ctx) {
  return visitChildren(ctx);
}

antlrcpp::Any ModuleVisitor::visitForCondition(TypeScriptParser::ForConditionContext *ctx) {
  return visitChildren(ctx);
}
