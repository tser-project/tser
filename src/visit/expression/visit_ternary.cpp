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

/// A? B:C
antlrcpp::Any ModuleVisitor::visitTernaryExpression(TypeScriptParser::TernaryExpressionContext *ctx) {
  DebugPrintln("[visitTernaryExpression] IsPreCheck: %d ; text: %s", IsPrecheckStep(), ctx->getText().data());

  Scope *scope = GetScope(ctx);

  if (IsPrecheckStep()) {
    return visitChildren(ctx);
  }
  auto condition = move(visit(ctx->singleExpression(0)).as<unique_ptr<NodeValue>>());

  auto binary_model = unique_ptr<BinaryOperModel>(
      DealBinaryParams(GetScope(ctx), this, ctx->singleExpression(1), ctx->singleExpression(2)));

  scope->NodeValueInitLlvmValueInfo(builder, condition.get());
  auto condition_value = scope->LoadToRegister(builder, condition->GetLlvmValueInfo());

  Value *value = builder->CreateSelect(condition_value, binary_model->left, binary_model->right);
  return make_unique<NodeValue>(new LlvmValueInfo(binary_model->type->clone(), value, false));
}
