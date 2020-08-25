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

antlrcpp::Any ModuleVisitor::visitBreakStatement(TypeScriptParser::BreakStatementContext *ctx) {

  if (IsPrecheckStep()) {
    return defaultResult();
  }
  auto scope      = GetScope(ctx);
  auto loop_scope = scope->GetWrapLoopBlockScope();

  if (loop_scope) {
    builder->CreateBr(loop_scope->GetMergeBlock());
    if (scope->IsBlock()) {
      BlockScope *block_scope = (BlockScope *)scope;
      block_scope->SetHasJumpedOut(true, ctx);
    }
  }

  return defaultResult();
}

antlrcpp::Any ModuleVisitor::visitContinueStatement(TypeScriptParser::ContinueStatementContext *ctx) {
  if (IsPrecheckStep()) {
    return defaultResult();
  }

  auto scope      = GetScope(ctx);
  auto loop_scope = scope->GetWrapLoopBlockScope();

  if (loop_scope) {
    if (loop_scope->GetContinueJumpBlock()) {
      builder->CreateBr(loop_scope->GetContinueJumpBlock());
    }

    /// 'continue' only jump out `if` scope, don't jump out `for`, `while`
    if (scope->IsBlock() && scope != loop_scope) {
      BlockScope *block_scope = (BlockScope *)scope;
      block_scope->SetHasJumpedOut(true, ctx);
    }
  }

  return defaultResult();
}
