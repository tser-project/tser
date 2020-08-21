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

antlrcpp::Any ModuleVisitor::visitDoStatement(TypeScriptParser::DoStatementContext *ctx) {

  if (IsPrecheckStep()) {
    auto parent_scope = GetScope(ctx->parent);
    auto scope        = new BlockScope(ctx, BlockType::Do, parent_scope);

    SetNewScope(ctx, scope);

    visitChildren(ctx);
    return defaultResult();
  }

  auto scope = (BlockScope *)GetScope(ctx);

  auto  func_value = (Function *)GetWrapFunctionScope(ctx)->GetFunctionVariableValue()->value;
  auto &block_list = func_value->getBasicBlockList();

  BasicBlock *StatementBB = BasicBlock::Create(GetLLVMContext(), "", func_value);
  BasicBlock *ConditionBB = BasicBlock::Create(GetLLVMContext(), "");
  BasicBlock *MergeBB     = BasicBlock::Create(GetLLVMContext(), "");

  scope->SetTrunkBlock(MergeBB);

  builder->CreateBr(StatementBB);
  builder->SetInsertPoint(StatementBB);
  visitStatement(ctx->statement());

  if (!scope->HasJumpedOut()) {
    builder->CreateBr(ConditionBB);
  }

  block_list.push_back(ConditionBB);
  builder->SetInsertPoint(ConditionBB);
  auto condition = move(visitExpressionSequence(ctx->expressionSequence()).as<unique_ptr<NodeValue>>());
  scope->NodeValueInitLlvmValueInfo(builder, condition.get());
  auto condition_value = scope->LoadToRegister(builder, condition->GetLlvmValueInfo());
  builder->CreateCondBr(condition_value, StatementBB, MergeBB);

  block_list.push_back(MergeBB);
  builder->SetInsertPoint(MergeBB);

  return defaultResult();
}

antlrcpp::Any ModuleVisitor::visitWhileStatement(TypeScriptParser::WhileStatementContext *ctx) {

  if (IsPrecheckStep()) {
    auto parent_scope = GetScope(ctx->parent);
    auto scope        = new BlockScope(ctx, BlockType::While, parent_scope);

    SetNewScope(ctx, scope);

    visitChildren(ctx);
    return defaultResult();
  }

  auto scope = (BlockScope *)GetScope(ctx);

  auto  func_value = (Function *)GetWrapFunctionScope(ctx)->GetFunctionVariableValue()->value;
  auto &block_list = func_value->getBasicBlockList();

  BasicBlock *ConditionBB = BasicBlock::Create(GetLLVMContext(), "", func_value);
  BasicBlock *StatementBB = BasicBlock::Create(GetLLVMContext(), "");
  BasicBlock *MergeBB     = BasicBlock::Create(GetLLVMContext(), "");

  scope->SetTrunkBlock(MergeBB);

  builder->CreateBr(ConditionBB);
  builder->SetInsertPoint(ConditionBB);
  auto condition = move(visitExpressionSequence(ctx->expressionSequence()).as<unique_ptr<NodeValue>>());
  scope->NodeValueInitLlvmValueInfo(builder, condition.get());
  auto condition_value = scope->LoadToRegister(builder, condition->GetLlvmValueInfo());
  builder->CreateCondBr(condition_value, StatementBB, MergeBB);

  block_list.push_back(StatementBB);
  builder->SetInsertPoint(StatementBB);
  visitStatement(ctx->statement());

  if (!scope->HasJumpedOut()) {
    builder->CreateBr(ConditionBB);
  }

  block_list.push_back(MergeBB);
  builder->SetInsertPoint(MergeBB);

  return defaultResult();
}
