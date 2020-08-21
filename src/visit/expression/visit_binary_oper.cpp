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

/// '<', '>', '<=', '>='
antlrcpp::Any ModuleVisitor::visitRelationalExpression(TypeScriptParser::RelationalExpressionContext *ctx) {

  if (IsPrecheckStep()) {
    return visitChildren(ctx);
  }

  BinaryOperType oper_type;

  if (ctx->LessThan()) {
    oper_type = BinaryOperType::LessThan;
  } else if (ctx->LessThanEquals()) {
    oper_type = BinaryOperType::LessThanEquals;
  } else if (ctx->MoreThan()) {
    oper_type = BinaryOperType::GreaterThan;
  } else if (ctx->GreaterThanEquals()) {
    oper_type = BinaryOperType::GreaterThanEquals;
  }

  auto binary_result =
      DealBinaryOper(GetScope(ctx), this, oper_type, ctx->singleExpression(0), ctx->singleExpression(1));

  return make_unique<NodeValue>(binary_result);
}

/// '==', '!=', '===', '!=='
antlrcpp::Any ModuleVisitor::visitEqualityExpression(TypeScriptParser::EqualityExpressionContext *ctx) {
  if (IsPrecheckStep()) {
    return visitChildren(ctx);
  }
  BinaryOperType oper_type;
  if (ctx->Equals_() || ctx->IdentityEquals()) {
    oper_type = BinaryOperType::Equals;
  } else if (ctx->NotEquals() || ctx->IdentityNotEquals()) {
    oper_type = BinaryOperType::NotEquals;
  }

  auto binary_result =
      DealBinaryOper(GetScope(ctx), this, oper_type, ctx->singleExpression(0), ctx->singleExpression(1));

  return make_unique<NodeValue>(binary_result);
}

/// '*' | '/' | '%'
antlrcpp::Any ModuleVisitor::visitMultiplicativeExpression(TypeScriptParser::MultiplicativeExpressionContext *ctx) {

  if (IsPrecheckStep()) {
    return visitChildren(ctx);
  }

  BinaryOperType oper_type;

  if (ctx->Multiply()) { // '*'
    oper_type = BinaryOperType::Multiply;
  } else if (ctx->Divide()) { // '/'
    oper_type = BinaryOperType::Divide;
  } else if (ctx->Modulus()) { // '%'
    oper_type = BinaryOperType::Modulus;
  }

  auto binary_result =
      DealBinaryOper(GetScope(ctx), this, oper_type, ctx->singleExpression(0), ctx->singleExpression(1));

  return make_unique<NodeValue>(binary_result);
}

/// '+' | '-'
antlrcpp::Any ModuleVisitor::visitAdditiveExpression(TypeScriptParser::AdditiveExpressionContext *ctx) {
  if (IsPrecheckStep()) {
    return visitChildren(ctx);
  }

  BinaryOperType oper_type;
  if (ctx->Plus()) {
    oper_type = BinaryOperType::Plus;
  } else if (ctx->Minus()) {
    oper_type = BinaryOperType::Minus;
  }
  auto binary_result =
      DealBinaryOper(GetScope(ctx), this, oper_type, ctx->singleExpression(0), ctx->singleExpression(1));

  return make_unique<NodeValue>(binary_result);
}

/// '*=', '/=', '%=', '+=', '-='
antlrcpp::Any
    ModuleVisitor::visitAssignmentOperatorExpression(TypeScriptParser::AssignmentOperatorExpressionContext *ctx) {
  if (IsPrecheckStep()) {
    return visitChildren(ctx);
  }

  auto oper = ctx->assignmentOperator();

  BinaryOperType oper_type;
  if (oper->MultiplyAssign()) {
    /// '*='
    oper_type = BinaryOperType::Multiply;
  } else if (oper->DivideAssign()) {
    /// '/='
    oper_type = BinaryOperType::Divide;
  } else if (oper->ModulusAssign()) {
    /// '%='
    oper_type = BinaryOperType::Modulus;
  } else if (oper->PlusAssign()) {
    /// '+='
    oper_type = BinaryOperType::Plus;
  } else if (oper->MinusAssign()) {
    /// '-='
    oper_type = BinaryOperType::Minus;
  }
  auto binary_result =
      DealBinaryOper(GetScope(ctx), this, oper_type, ctx->singleExpression(0), ctx->singleExpression(1), true);
  return make_unique<NodeValue>(binary_result);
}
