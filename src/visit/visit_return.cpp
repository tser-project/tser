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

antlrcpp::Any ModuleVisitor::visitReturnStatement(TypeScriptParser::ReturnStatementContext *ctx) {
  DebugPrintln("[visitReturnStatement] IsPreCheck: %d ; text: %s", IsPrecheckStep(), ctx->getText().data());

  Scope *        scope      = GetScope(ctx);
  FunctionScope *func_scope = scope->GetWrapFunctionScope();
  if (IsPrecheckStep()) {
    func_scope->SetHasReturnStatement(true);
    if (!func_scope->IsMultiReturn()) {
      if (!IsFunctionLastReturnStatement(ctx)) {
        func_scope->SetIsMultiReturn(true);
      }
    }

    return visitChildren(ctx);
  }

  auto node_value = move(visitExpressionSequence(ctx->expressionSequence()).as<unique_ptr<NodeValue>>());

  /// Get return value
  auto return_info = func_scope->GetFunctionVariableValue()->GetReturnValue();
  scope->NodeValueInitLlvmValueInfo(builder, node_value.get());

  /// cast to return type
  auto return_value_info =
      unique_ptr<LlvmValueInfo>(TypeCastToTarget(scope, builder, return_info->type, node_value->GetLlvmValueInfo()));

  auto return_value = scope->LoadToRegister(builder, return_value_info.get());

  /// only one return statement: return directly.
  if (!func_scope->HasBranch() || !func_scope->IsMultiReturn()) {
    builder->CreateRet(return_value);

    return defaultResult();
  }

  /// multi return statement: save to return pointer, then switch to return block
  builder->CreateStore(return_value, return_info->value);
  builder->CreateBr(func_scope->GetReturnBlock());

  if (scope->IsBlock()) {
    auto block_scope = (BlockScope *)scope;
    block_scope->SetHasJumpedOut(true, ctx);
  }

  return defaultResult();
}