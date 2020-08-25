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

/// visit expressionSequence
antlrcpp::Any ModuleVisitor::visitExpressionSequence(TypeScriptParser::ExpressionSequenceContext *ctx) {
  DebugPrintln("[visitExpressionSequence] IsPreCheck: %d ; text: %s", IsPrecheckStep(), ctx->getText().data());

  if (IsPrecheckStep()) {
    return visitChildren(ctx);
  }

  auto children = ctx->singleExpression();

  unique_ptr<NodeValue> result = nullptr;

  for (auto child : children) {
    result = move(visit(child).as<unique_ptr<NodeValue>>());
  }
  return result;
}

/// visit assignable
antlrcpp::Any ModuleVisitor::visitAssignable(TypeScriptParser::AssignableContext *ctx) {
  DebugPrintln("[visitAssignable] IsPreCheck: %d ; text: %s", IsPrecheckStep(), ctx->getText().data());
  return make_unique<NodeValue>(ctx->Identifier()->getText());
}

antlrcpp::Any ModuleVisitor::visitStatementList(TypeScriptParser::StatementListContext *ctx) {
  visitChildren(ctx);
  return defaultResult();
}

antlrcpp::Any ModuleVisitor::visitStatement(TypeScriptParser::StatementContext *ctx) {
  visitChildren(ctx);
  return defaultResult();
}

antlrcpp::Any ModuleVisitor::visitVarModifier(TypeScriptParser::VarModifierContext *ctx) {
  return visitChildren(ctx);
}

antlrcpp::Any ModuleVisitor::visitVariableDeclarationList(TypeScriptParser::VariableDeclarationListContext *ctx) {
  return visitChildren(ctx);
}

antlrcpp::Any ModuleVisitor::visitExpressionStatement(TypeScriptParser::ExpressionStatementContext *ctx) {
  return visitChildren(ctx);
}
antlrcpp::Any ModuleVisitor::visitGetter(TypeScriptParser::GetterContext *ctx) {
  return visitChildren(ctx);
}

antlrcpp::Any ModuleVisitor::visitSetter(TypeScriptParser::SetterContext *ctx) {
  return visitChildren(ctx);
}

antlrcpp::Any ModuleVisitor::visitEos(TypeScriptParser::EosContext *ctx) {
  return visitChildren(ctx);
}

antlrcpp::Any ModuleVisitor::visitIdentifierName(TypeScriptParser::IdentifierNameContext *ctx) {
  DebugPrintln("[visitIdentifierName] IsPreCheck: %d ; text: %s", IsPrecheckStep(), ctx->getText().data());
  return ctx->Identifier()->getText();
}

antlrcpp::Any ModuleVisitor::visitReservedWord(TypeScriptParser::ReservedWordContext *ctx) {
  return visitChildren(ctx);
}

antlrcpp::Any ModuleVisitor::visitKeyword(TypeScriptParser::KeywordContext *ctx) {
  return visitChildren(ctx);
}