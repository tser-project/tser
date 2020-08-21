
// Generated from TypeScriptParser.g4 by ANTLR 4.8

#pragma once


#include "antlr4-runtime.h"
#include "TypeScriptParser.h"



/**
 * This class defines an abstract visitor for a parse tree
 * produced by TypeScriptParser.
 */
class  TypeScriptParserVisitor : public antlr4::tree::AbstractParseTreeVisitor {
public:

  /**
   * Visit parse trees produced by TypeScriptParser.
   */
    virtual antlrcpp::Any visitProgram(TypeScriptParser::ProgramContext *context) = 0;

    virtual antlrcpp::Any visitStatementList(TypeScriptParser::StatementListContext *context) = 0;

    virtual antlrcpp::Any visitStatement(TypeScriptParser::StatementContext *context) = 0;

    virtual antlrcpp::Any visitTypeSign(TypeScriptParser::TypeSignContext *context) = 0;

    virtual antlrcpp::Any visitPrimaryType(TypeScriptParser::PrimaryTypeContext *context) = 0;

    virtual antlrcpp::Any visitPredefinedType(TypeScriptParser::PredefinedTypeContext *context) = 0;

    virtual antlrcpp::Any visitTypeReference(TypeScriptParser::TypeReferenceContext *context) = 0;

    virtual antlrcpp::Any visitAccessControl(TypeScriptParser::AccessControlContext *context) = 0;

    virtual antlrcpp::Any visitClassControl(TypeScriptParser::ClassControlContext *context) = 0;

    virtual antlrcpp::Any visitPropertyControl(TypeScriptParser::PropertyControlContext *context) = 0;

    virtual antlrcpp::Any visitFunctionControl(TypeScriptParser::FunctionControlContext *context) = 0;

    virtual antlrcpp::Any visitBlock(TypeScriptParser::BlockContext *context) = 0;

    virtual antlrcpp::Any visitImportStatement(TypeScriptParser::ImportStatementContext *context) = 0;

    virtual antlrcpp::Any visitImportFromBlock(TypeScriptParser::ImportFromBlockContext *context) = 0;

    virtual antlrcpp::Any visitModuleItems(TypeScriptParser::ModuleItemsContext *context) = 0;

    virtual antlrcpp::Any visitImportDefault(TypeScriptParser::ImportDefaultContext *context) = 0;

    virtual antlrcpp::Any visitImportNamespace(TypeScriptParser::ImportNamespaceContext *context) = 0;

    virtual antlrcpp::Any visitImportFrom(TypeScriptParser::ImportFromContext *context) = 0;

    virtual antlrcpp::Any visitAliasName(TypeScriptParser::AliasNameContext *context) = 0;

    virtual antlrcpp::Any visitExportDeclaration(TypeScriptParser::ExportDeclarationContext *context) = 0;

    virtual antlrcpp::Any visitExportDefaultDeclaration(TypeScriptParser::ExportDefaultDeclarationContext *context) = 0;

    virtual antlrcpp::Any visitExportFromBlock(TypeScriptParser::ExportFromBlockContext *context) = 0;

    virtual antlrcpp::Any visitDeclaration(TypeScriptParser::DeclarationContext *context) = 0;

    virtual antlrcpp::Any visitVariableStatement(TypeScriptParser::VariableStatementContext *context) = 0;

    virtual antlrcpp::Any visitVariableDeclarationList(TypeScriptParser::VariableDeclarationListContext *context) = 0;

    virtual antlrcpp::Any visitVariableDeclaration(TypeScriptParser::VariableDeclarationContext *context) = 0;

    virtual antlrcpp::Any visitEmptyStatement(TypeScriptParser::EmptyStatementContext *context) = 0;

    virtual antlrcpp::Any visitExpressionStatement(TypeScriptParser::ExpressionStatementContext *context) = 0;

    virtual antlrcpp::Any visitIfStatement(TypeScriptParser::IfStatementContext *context) = 0;

    virtual antlrcpp::Any visitDoStatement(TypeScriptParser::DoStatementContext *context) = 0;

    virtual antlrcpp::Any visitWhileStatement(TypeScriptParser::WhileStatementContext *context) = 0;

    virtual antlrcpp::Any visitForStatement(TypeScriptParser::ForStatementContext *context) = 0;

    virtual antlrcpp::Any visitForInStatement(TypeScriptParser::ForInStatementContext *context) = 0;

    virtual antlrcpp::Any visitForOfStatement(TypeScriptParser::ForOfStatementContext *context) = 0;

    virtual antlrcpp::Any visitForInitialization(TypeScriptParser::ForInitializationContext *context) = 0;

    virtual antlrcpp::Any visitForCondition(TypeScriptParser::ForConditionContext *context) = 0;

    virtual antlrcpp::Any visitVarModifier(TypeScriptParser::VarModifierContext *context) = 0;

    virtual antlrcpp::Any visitContinueStatement(TypeScriptParser::ContinueStatementContext *context) = 0;

    virtual antlrcpp::Any visitBreakStatement(TypeScriptParser::BreakStatementContext *context) = 0;

    virtual antlrcpp::Any visitReturnStatement(TypeScriptParser::ReturnStatementContext *context) = 0;

    virtual antlrcpp::Any visitYieldStatement(TypeScriptParser::YieldStatementContext *context) = 0;

    virtual antlrcpp::Any visitWithStatement(TypeScriptParser::WithStatementContext *context) = 0;

    virtual antlrcpp::Any visitSwitchStatement(TypeScriptParser::SwitchStatementContext *context) = 0;

    virtual antlrcpp::Any visitCaseBlock(TypeScriptParser::CaseBlockContext *context) = 0;

    virtual antlrcpp::Any visitSwitchDefaultClause(TypeScriptParser::SwitchDefaultClauseContext *context) = 0;

    virtual antlrcpp::Any visitSwitchCaseClause(TypeScriptParser::SwitchCaseClauseContext *context) = 0;

    virtual antlrcpp::Any visitLabelledStatement(TypeScriptParser::LabelledStatementContext *context) = 0;

    virtual antlrcpp::Any visitThrowStatement(TypeScriptParser::ThrowStatementContext *context) = 0;

    virtual antlrcpp::Any visitTryStatement(TypeScriptParser::TryStatementContext *context) = 0;

    virtual antlrcpp::Any visitCatchProduction(TypeScriptParser::CatchProductionContext *context) = 0;

    virtual antlrcpp::Any visitFinallyProduction(TypeScriptParser::FinallyProductionContext *context) = 0;

    virtual antlrcpp::Any visitDebuggerStatement(TypeScriptParser::DebuggerStatementContext *context) = 0;

    virtual antlrcpp::Any visitFunctionDeclaration(TypeScriptParser::FunctionDeclarationContext *context) = 0;

    virtual antlrcpp::Any visitClassDeclaration(TypeScriptParser::ClassDeclarationContext *context) = 0;

    virtual antlrcpp::Any visitClassTail(TypeScriptParser::ClassTailContext *context) = 0;

    virtual antlrcpp::Any visitConstructorDefinition(TypeScriptParser::ConstructorDefinitionContext *context) = 0;

    virtual antlrcpp::Any visitNormalMethodDefinition(TypeScriptParser::NormalMethodDefinitionContext *context) = 0;

    virtual antlrcpp::Any visitGetterMethodDefinition(TypeScriptParser::GetterMethodDefinitionContext *context) = 0;

    virtual antlrcpp::Any visitSetterMethodDefinition(TypeScriptParser::SetterMethodDefinitionContext *context) = 0;

    virtual antlrcpp::Any visitClassPropertyDefinition(TypeScriptParser::ClassPropertyDefinitionContext *context) = 0;

    virtual antlrcpp::Any visitClassEmptyStatement(TypeScriptParser::ClassEmptyStatementContext *context) = 0;

    virtual antlrcpp::Any visitFormalParameterList(TypeScriptParser::FormalParameterListContext *context) = 0;

    virtual antlrcpp::Any visitFormalParameterArg(TypeScriptParser::FormalParameterArgContext *context) = 0;

    virtual antlrcpp::Any visitLastFormalParameterArg(TypeScriptParser::LastFormalParameterArgContext *context) = 0;

    virtual antlrcpp::Any visitFunctionBody(TypeScriptParser::FunctionBodyContext *context) = 0;

    virtual antlrcpp::Any visitArrayLiteral(TypeScriptParser::ArrayLiteralContext *context) = 0;

    virtual antlrcpp::Any visitElementList(TypeScriptParser::ElementListContext *context) = 0;

    virtual antlrcpp::Any visitArrayElement(TypeScriptParser::ArrayElementContext *context) = 0;

    virtual antlrcpp::Any visitObjectLiteral(TypeScriptParser::ObjectLiteralContext *context) = 0;

    virtual antlrcpp::Any visitPropertyExpressionAssignment(TypeScriptParser::PropertyExpressionAssignmentContext *context) = 0;

    virtual antlrcpp::Any visitComputedPropertyExpressionAssignment(TypeScriptParser::ComputedPropertyExpressionAssignmentContext *context) = 0;

    virtual antlrcpp::Any visitFunctionProperty(TypeScriptParser::FunctionPropertyContext *context) = 0;

    virtual antlrcpp::Any visitPropertyGetter(TypeScriptParser::PropertyGetterContext *context) = 0;

    virtual antlrcpp::Any visitPropertySetter(TypeScriptParser::PropertySetterContext *context) = 0;

    virtual antlrcpp::Any visitPropertyShorthand(TypeScriptParser::PropertyShorthandContext *context) = 0;

    virtual antlrcpp::Any visitPropertyName(TypeScriptParser::PropertyNameContext *context) = 0;

    virtual antlrcpp::Any visitArguments(TypeScriptParser::ArgumentsContext *context) = 0;

    virtual antlrcpp::Any visitArgument(TypeScriptParser::ArgumentContext *context) = 0;

    virtual antlrcpp::Any visitExpressionSequence(TypeScriptParser::ExpressionSequenceContext *context) = 0;

    virtual antlrcpp::Any visitTemplateStringExpression(TypeScriptParser::TemplateStringExpressionContext *context) = 0;

    virtual antlrcpp::Any visitTernaryExpression(TypeScriptParser::TernaryExpressionContext *context) = 0;

    virtual antlrcpp::Any visitLogicalAndExpression(TypeScriptParser::LogicalAndExpressionContext *context) = 0;

    virtual antlrcpp::Any visitPowerExpression(TypeScriptParser::PowerExpressionContext *context) = 0;

    virtual antlrcpp::Any visitPreIncrementExpression(TypeScriptParser::PreIncrementExpressionContext *context) = 0;

    virtual antlrcpp::Any visitObjectLiteralExpression(TypeScriptParser::ObjectLiteralExpressionContext *context) = 0;

    virtual antlrcpp::Any visitMetaExpression(TypeScriptParser::MetaExpressionContext *context) = 0;

    virtual antlrcpp::Any visitInExpression(TypeScriptParser::InExpressionContext *context) = 0;

    virtual antlrcpp::Any visitLogicalOrExpression(TypeScriptParser::LogicalOrExpressionContext *context) = 0;

    virtual antlrcpp::Any visitNotExpression(TypeScriptParser::NotExpressionContext *context) = 0;

    virtual antlrcpp::Any visitPreDecreaseExpression(TypeScriptParser::PreDecreaseExpressionContext *context) = 0;

    virtual antlrcpp::Any visitArgumentsExpression(TypeScriptParser::ArgumentsExpressionContext *context) = 0;

    virtual antlrcpp::Any visitAwaitExpression(TypeScriptParser::AwaitExpressionContext *context) = 0;

    virtual antlrcpp::Any visitThisExpression(TypeScriptParser::ThisExpressionContext *context) = 0;

    virtual antlrcpp::Any visitFunctionExpression(TypeScriptParser::FunctionExpressionContext *context) = 0;

    virtual antlrcpp::Any visitUnaryMinusExpression(TypeScriptParser::UnaryMinusExpressionContext *context) = 0;

    virtual antlrcpp::Any visitAssignmentExpression(TypeScriptParser::AssignmentExpressionContext *context) = 0;

    virtual antlrcpp::Any visitPostDecreaseExpression(TypeScriptParser::PostDecreaseExpressionContext *context) = 0;

    virtual antlrcpp::Any visitTypeofExpression(TypeScriptParser::TypeofExpressionContext *context) = 0;

    virtual antlrcpp::Any visitInstanceofExpression(TypeScriptParser::InstanceofExpressionContext *context) = 0;

    virtual antlrcpp::Any visitUnaryPlusExpression(TypeScriptParser::UnaryPlusExpressionContext *context) = 0;

    virtual antlrcpp::Any visitDeleteExpression(TypeScriptParser::DeleteExpressionContext *context) = 0;

    virtual antlrcpp::Any visitImportExpression(TypeScriptParser::ImportExpressionContext *context) = 0;

    virtual antlrcpp::Any visitEqualityExpression(TypeScriptParser::EqualityExpressionContext *context) = 0;

    virtual antlrcpp::Any visitBitXOrExpression(TypeScriptParser::BitXOrExpressionContext *context) = 0;

    virtual antlrcpp::Any visitSuperExpression(TypeScriptParser::SuperExpressionContext *context) = 0;

    virtual antlrcpp::Any visitMultiplicativeExpression(TypeScriptParser::MultiplicativeExpressionContext *context) = 0;

    virtual antlrcpp::Any visitBitShiftExpression(TypeScriptParser::BitShiftExpressionContext *context) = 0;

    virtual antlrcpp::Any visitParenthesizedExpression(TypeScriptParser::ParenthesizedExpressionContext *context) = 0;

    virtual antlrcpp::Any visitAdditiveExpression(TypeScriptParser::AdditiveExpressionContext *context) = 0;

    virtual antlrcpp::Any visitRelationalExpression(TypeScriptParser::RelationalExpressionContext *context) = 0;

    virtual antlrcpp::Any visitPostIncrementExpression(TypeScriptParser::PostIncrementExpressionContext *context) = 0;

    virtual antlrcpp::Any visitYieldExpression(TypeScriptParser::YieldExpressionContext *context) = 0;

    virtual antlrcpp::Any visitBitNotExpression(TypeScriptParser::BitNotExpressionContext *context) = 0;

    virtual antlrcpp::Any visitNewExpression(TypeScriptParser::NewExpressionContext *context) = 0;

    virtual antlrcpp::Any visitLiteralExpression(TypeScriptParser::LiteralExpressionContext *context) = 0;

    virtual antlrcpp::Any visitArrayLiteralExpression(TypeScriptParser::ArrayLiteralExpressionContext *context) = 0;

    virtual antlrcpp::Any visitMemberDotExpression(TypeScriptParser::MemberDotExpressionContext *context) = 0;

    virtual antlrcpp::Any visitClassExpression(TypeScriptParser::ClassExpressionContext *context) = 0;

    virtual antlrcpp::Any visitMemberIndexExpression(TypeScriptParser::MemberIndexExpressionContext *context) = 0;

    virtual antlrcpp::Any visitIdentifierExpression(TypeScriptParser::IdentifierExpressionContext *context) = 0;

    virtual antlrcpp::Any visitBitAndExpression(TypeScriptParser::BitAndExpressionContext *context) = 0;

    virtual antlrcpp::Any visitBitOrExpression(TypeScriptParser::BitOrExpressionContext *context) = 0;

    virtual antlrcpp::Any visitAssignmentOperatorExpression(TypeScriptParser::AssignmentOperatorExpressionContext *context) = 0;

    virtual antlrcpp::Any visitVoidExpression(TypeScriptParser::VoidExpressionContext *context) = 0;

    virtual antlrcpp::Any visitCoalesceExpression(TypeScriptParser::CoalesceExpressionContext *context) = 0;

    virtual antlrcpp::Any visitAssignable(TypeScriptParser::AssignableContext *context) = 0;

    virtual antlrcpp::Any visitFunctionDecl(TypeScriptParser::FunctionDeclContext *context) = 0;

    virtual antlrcpp::Any visitAnoymousFunctionDecl(TypeScriptParser::AnoymousFunctionDeclContext *context) = 0;

    virtual antlrcpp::Any visitArrowFunction(TypeScriptParser::ArrowFunctionContext *context) = 0;

    virtual antlrcpp::Any visitArrowFunctionParameters(TypeScriptParser::ArrowFunctionParametersContext *context) = 0;

    virtual antlrcpp::Any visitArrowFunctionBody(TypeScriptParser::ArrowFunctionBodyContext *context) = 0;

    virtual antlrcpp::Any visitAssignmentOperator(TypeScriptParser::AssignmentOperatorContext *context) = 0;

    virtual antlrcpp::Any visitLiteral(TypeScriptParser::LiteralContext *context) = 0;

    virtual antlrcpp::Any visitNumericLiteral(TypeScriptParser::NumericLiteralContext *context) = 0;

    virtual antlrcpp::Any visitBigintLiteral(TypeScriptParser::BigintLiteralContext *context) = 0;

    virtual antlrcpp::Any visitIdentifierName(TypeScriptParser::IdentifierNameContext *context) = 0;

    virtual antlrcpp::Any visitReservedWord(TypeScriptParser::ReservedWordContext *context) = 0;

    virtual antlrcpp::Any visitKeyword(TypeScriptParser::KeywordContext *context) = 0;

    virtual antlrcpp::Any visitGetter(TypeScriptParser::GetterContext *context) = 0;

    virtual antlrcpp::Any visitSetter(TypeScriptParser::SetterContext *context) = 0;

    virtual antlrcpp::Any visitEos(TypeScriptParser::EosContext *context) = 0;


};

