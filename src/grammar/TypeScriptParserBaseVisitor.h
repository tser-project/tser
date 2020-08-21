
// Generated from TypeScriptParser.g4 by ANTLR 4.8

#pragma once


#include "antlr4-runtime.h"
#include "TypeScriptParserVisitor.h"


/**
 * This class provides an empty implementation of TypeScriptParserVisitor, which can be
 * extended to create a visitor which only needs to handle a subset of the available methods.
 */
class  TypeScriptParserBaseVisitor : public TypeScriptParserVisitor {
public:

  virtual antlrcpp::Any visitProgram(TypeScriptParser::ProgramContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitStatementList(TypeScriptParser::StatementListContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitStatement(TypeScriptParser::StatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitTypeSign(TypeScriptParser::TypeSignContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitPrimaryType(TypeScriptParser::PrimaryTypeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitPredefinedType(TypeScriptParser::PredefinedTypeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitTypeReference(TypeScriptParser::TypeReferenceContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitAccessControl(TypeScriptParser::AccessControlContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitClassControl(TypeScriptParser::ClassControlContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitPropertyControl(TypeScriptParser::PropertyControlContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitFunctionControl(TypeScriptParser::FunctionControlContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitBlock(TypeScriptParser::BlockContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitImportStatement(TypeScriptParser::ImportStatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitImportFromBlock(TypeScriptParser::ImportFromBlockContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitModuleItems(TypeScriptParser::ModuleItemsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitImportDefault(TypeScriptParser::ImportDefaultContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitImportNamespace(TypeScriptParser::ImportNamespaceContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitImportFrom(TypeScriptParser::ImportFromContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitAliasName(TypeScriptParser::AliasNameContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitExportDeclaration(TypeScriptParser::ExportDeclarationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitExportDefaultDeclaration(TypeScriptParser::ExportDefaultDeclarationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitExportFromBlock(TypeScriptParser::ExportFromBlockContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitDeclaration(TypeScriptParser::DeclarationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitVariableStatement(TypeScriptParser::VariableStatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitVariableDeclarationList(TypeScriptParser::VariableDeclarationListContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitVariableDeclaration(TypeScriptParser::VariableDeclarationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitEmptyStatement(TypeScriptParser::EmptyStatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitExpressionStatement(TypeScriptParser::ExpressionStatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitIfStatement(TypeScriptParser::IfStatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitDoStatement(TypeScriptParser::DoStatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitWhileStatement(TypeScriptParser::WhileStatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitForStatement(TypeScriptParser::ForStatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitForInStatement(TypeScriptParser::ForInStatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitForOfStatement(TypeScriptParser::ForOfStatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitForInitialization(TypeScriptParser::ForInitializationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitForCondition(TypeScriptParser::ForConditionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitVarModifier(TypeScriptParser::VarModifierContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitContinueStatement(TypeScriptParser::ContinueStatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitBreakStatement(TypeScriptParser::BreakStatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitReturnStatement(TypeScriptParser::ReturnStatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitYieldStatement(TypeScriptParser::YieldStatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitWithStatement(TypeScriptParser::WithStatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitSwitchStatement(TypeScriptParser::SwitchStatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitCaseBlock(TypeScriptParser::CaseBlockContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitSwitchDefaultClause(TypeScriptParser::SwitchDefaultClauseContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitSwitchCaseClause(TypeScriptParser::SwitchCaseClauseContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitLabelledStatement(TypeScriptParser::LabelledStatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitThrowStatement(TypeScriptParser::ThrowStatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitTryStatement(TypeScriptParser::TryStatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitCatchProduction(TypeScriptParser::CatchProductionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitFinallyProduction(TypeScriptParser::FinallyProductionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitDebuggerStatement(TypeScriptParser::DebuggerStatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitFunctionDeclaration(TypeScriptParser::FunctionDeclarationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitClassDeclaration(TypeScriptParser::ClassDeclarationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitClassTail(TypeScriptParser::ClassTailContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitConstructorDefinition(TypeScriptParser::ConstructorDefinitionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitNormalMethodDefinition(TypeScriptParser::NormalMethodDefinitionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitGetterMethodDefinition(TypeScriptParser::GetterMethodDefinitionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitSetterMethodDefinition(TypeScriptParser::SetterMethodDefinitionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitClassPropertyDefinition(TypeScriptParser::ClassPropertyDefinitionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitClassEmptyStatement(TypeScriptParser::ClassEmptyStatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitFormalParameterList(TypeScriptParser::FormalParameterListContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitFormalParameterArg(TypeScriptParser::FormalParameterArgContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitLastFormalParameterArg(TypeScriptParser::LastFormalParameterArgContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitFunctionBody(TypeScriptParser::FunctionBodyContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitArrayLiteral(TypeScriptParser::ArrayLiteralContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitElementList(TypeScriptParser::ElementListContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitArrayElement(TypeScriptParser::ArrayElementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitObjectLiteral(TypeScriptParser::ObjectLiteralContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitPropertyExpressionAssignment(TypeScriptParser::PropertyExpressionAssignmentContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitComputedPropertyExpressionAssignment(TypeScriptParser::ComputedPropertyExpressionAssignmentContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitFunctionProperty(TypeScriptParser::FunctionPropertyContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitPropertyGetter(TypeScriptParser::PropertyGetterContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitPropertySetter(TypeScriptParser::PropertySetterContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitPropertyShorthand(TypeScriptParser::PropertyShorthandContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitPropertyName(TypeScriptParser::PropertyNameContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitArguments(TypeScriptParser::ArgumentsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitArgument(TypeScriptParser::ArgumentContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitExpressionSequence(TypeScriptParser::ExpressionSequenceContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitTemplateStringExpression(TypeScriptParser::TemplateStringExpressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitTernaryExpression(TypeScriptParser::TernaryExpressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitLogicalAndExpression(TypeScriptParser::LogicalAndExpressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitPowerExpression(TypeScriptParser::PowerExpressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitPreIncrementExpression(TypeScriptParser::PreIncrementExpressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitObjectLiteralExpression(TypeScriptParser::ObjectLiteralExpressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitMetaExpression(TypeScriptParser::MetaExpressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitInExpression(TypeScriptParser::InExpressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitLogicalOrExpression(TypeScriptParser::LogicalOrExpressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitNotExpression(TypeScriptParser::NotExpressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitPreDecreaseExpression(TypeScriptParser::PreDecreaseExpressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitArgumentsExpression(TypeScriptParser::ArgumentsExpressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitAwaitExpression(TypeScriptParser::AwaitExpressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitThisExpression(TypeScriptParser::ThisExpressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitFunctionExpression(TypeScriptParser::FunctionExpressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitUnaryMinusExpression(TypeScriptParser::UnaryMinusExpressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitAssignmentExpression(TypeScriptParser::AssignmentExpressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitPostDecreaseExpression(TypeScriptParser::PostDecreaseExpressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitTypeofExpression(TypeScriptParser::TypeofExpressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitInstanceofExpression(TypeScriptParser::InstanceofExpressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitUnaryPlusExpression(TypeScriptParser::UnaryPlusExpressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitDeleteExpression(TypeScriptParser::DeleteExpressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitImportExpression(TypeScriptParser::ImportExpressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitEqualityExpression(TypeScriptParser::EqualityExpressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitBitXOrExpression(TypeScriptParser::BitXOrExpressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitSuperExpression(TypeScriptParser::SuperExpressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitMultiplicativeExpression(TypeScriptParser::MultiplicativeExpressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitBitShiftExpression(TypeScriptParser::BitShiftExpressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitParenthesizedExpression(TypeScriptParser::ParenthesizedExpressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitAdditiveExpression(TypeScriptParser::AdditiveExpressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitRelationalExpression(TypeScriptParser::RelationalExpressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitPostIncrementExpression(TypeScriptParser::PostIncrementExpressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitYieldExpression(TypeScriptParser::YieldExpressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitBitNotExpression(TypeScriptParser::BitNotExpressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitNewExpression(TypeScriptParser::NewExpressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitLiteralExpression(TypeScriptParser::LiteralExpressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitArrayLiteralExpression(TypeScriptParser::ArrayLiteralExpressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitMemberDotExpression(TypeScriptParser::MemberDotExpressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitClassExpression(TypeScriptParser::ClassExpressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitMemberIndexExpression(TypeScriptParser::MemberIndexExpressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitIdentifierExpression(TypeScriptParser::IdentifierExpressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitBitAndExpression(TypeScriptParser::BitAndExpressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitBitOrExpression(TypeScriptParser::BitOrExpressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitAssignmentOperatorExpression(TypeScriptParser::AssignmentOperatorExpressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitVoidExpression(TypeScriptParser::VoidExpressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitCoalesceExpression(TypeScriptParser::CoalesceExpressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitAssignable(TypeScriptParser::AssignableContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitFunctionDecl(TypeScriptParser::FunctionDeclContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitAnoymousFunctionDecl(TypeScriptParser::AnoymousFunctionDeclContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitArrowFunction(TypeScriptParser::ArrowFunctionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitArrowFunctionParameters(TypeScriptParser::ArrowFunctionParametersContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitArrowFunctionBody(TypeScriptParser::ArrowFunctionBodyContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitAssignmentOperator(TypeScriptParser::AssignmentOperatorContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitLiteral(TypeScriptParser::LiteralContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitNumericLiteral(TypeScriptParser::NumericLiteralContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitBigintLiteral(TypeScriptParser::BigintLiteralContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitIdentifierName(TypeScriptParser::IdentifierNameContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitReservedWord(TypeScriptParser::ReservedWordContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitKeyword(TypeScriptParser::KeywordContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitGetter(TypeScriptParser::GetterContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitSetter(TypeScriptParser::SetterContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitEos(TypeScriptParser::EosContext *ctx) override {
    return visitChildren(ctx);
  }


};

