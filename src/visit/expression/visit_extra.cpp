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

/// '()'
antlrcpp::Any ModuleVisitor::visitParenthesizedExpression(TypeScriptParser::ParenthesizedExpressionContext *ctx) {
  DebugPrintln("[visitParenthesizedExpression] IsPreCheck: %d ; text: %s", IsPrecheckStep(), ctx->getText().data());
  if (IsPrecheckStep()) {
    return visitExpressionSequence(ctx->expressionSequence());
  }
  return visitExpressionSequence(ctx->expressionSequence());
}

/// 'this'
antlrcpp::Any ModuleVisitor::visitThisExpression(TypeScriptParser::ThisExpressionContext *ctx) {
  return make_unique<NodeValue>("this");
}

/// literal
antlrcpp::Any ModuleVisitor::visitLiteralExpression(TypeScriptParser::LiteralExpressionContext *ctx) {
  if (IsPrecheckStep()) {
    return defaultResult();
  }
  return visitChildren(ctx);
}
