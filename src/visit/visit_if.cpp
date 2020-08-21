#include "antlr4-runtime.h"
#include "common/error/error.h"
#include "grammar/TypeScriptParser.h"
#include "support/Any.h"
#include "tree/ParseTree.h"
#include "visit/visit.h"
#include "llvm/ADT/APSInt.h"
#include "llvm/IR/DerivedTypes.h"
#include "llvm/IR/Instruction.h"

using namespace tser;
using namespace std;
using namespace antlr4;
using namespace llvm;
using namespace antlr4::tree;

antlrcpp::Any ModuleVisitor::visitIfStatement(TypeScriptParser::IfStatementContext *ctx) {

  bool has_else          = !!ctx->statement(1);
  bool else_is_pure_else = has_else && !ctx->statement(1)->ifStatement();

  if (IsPrecheckStep()) {
    Scope *        parent_scope   = GetScope(ctx->parent);
    FunctionScope *function_scope = parent_scope->GetWrapFunctionScope();
    auto           if_scope       = new BlockScope(ctx, BlockType::If, parent_scope);
    SetNewScope(ctx->statement(0), if_scope);

    if (else_is_pure_else) {
      /// create else scope
      auto pure_else_scope = new BlockScope(ctx, BlockType::If, parent_scope);
      SetNewScope(ctx->statement(1), pure_else_scope);
    }

    function_scope->SetHasBranch(true);
    return visitChildren(ctx);
  }
  Scope *        parent_scope   = GetScope(ctx->parent);
  BlockScope *   if_scope       = (BlockScope *)GetScope(ctx->statement(0));
  FunctionScope *function_scope = if_scope->GetWrapFunctionScope();

  auto condition = move(visitExpressionSequence(ctx->expressionSequence()).as<unique_ptr<NodeValue>>());

  parent_scope->NodeValueInitLlvmValueInfo(builder, condition.get());
  auto condition_value = parent_scope->LoadToRegister(builder, condition->GetLlvmValueInfo());

  auto func_value = (Function *)function_scope->GetFunctionVariableValue()->value;

  BasicBlock *ThenBB  = BasicBlock::Create(GetLLVMContext(), "", func_value);
  BasicBlock *ElseBB  = has_else ? BasicBlock::Create(GetLLVMContext(), "", func_value) : nullptr;
  BasicBlock *MergeBB = BasicBlock::Create(GetLLVMContext(), "");

  builder->CreateCondBr(condition_value, ThenBB, has_else ? ElseBB : MergeBB);

  // if statement scope
  builder->SetInsertPoint(ThenBB);
  if_scope->SetTrunkBlock(MergeBB);
  visitStatement(ctx->statement(0));
  if (!if_scope->HasJumpedOut()) {
    builder->CreateBr(MergeBB);
  }

  if (has_else) {
    // else scope
    builder->SetInsertPoint(ElseBB);
    BlockScope *pure_else_scope = nullptr;
    if (else_is_pure_else) {
      pure_else_scope = (BlockScope *)GetScope(ctx->statement(1));
      pure_else_scope->SetTrunkBlock(MergeBB);
    }
    visitStatement(ctx->statement(1));
    if (!pure_else_scope || !pure_else_scope->HasJumpedOut()) {
      builder->CreateBr(MergeBB);
    }
  }

  func_value->getBasicBlockList().push_back(MergeBB);
  builder->SetInsertPoint(MergeBB);

  return defaultResult();
}
