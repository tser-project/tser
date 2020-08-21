
// Generated from TypeScriptParser.g4 by ANTLR 4.8

#pragma once


#include "antlr4-runtime.h"
#include "TypeScriptParser.h"


/**
 * This interface defines an abstract listener for a parse tree produced by TypeScriptParser.
 */
class  TypeScriptParserListener : public antlr4::tree::ParseTreeListener {
public:

  virtual void enterProgram(TypeScriptParser::ProgramContext *ctx) = 0;
  virtual void exitProgram(TypeScriptParser::ProgramContext *ctx) = 0;

  virtual void enterStatementList(TypeScriptParser::StatementListContext *ctx) = 0;
  virtual void exitStatementList(TypeScriptParser::StatementListContext *ctx) = 0;

  virtual void enterStatement(TypeScriptParser::StatementContext *ctx) = 0;
  virtual void exitStatement(TypeScriptParser::StatementContext *ctx) = 0;

  virtual void enterTypeSign(TypeScriptParser::TypeSignContext *ctx) = 0;
  virtual void exitTypeSign(TypeScriptParser::TypeSignContext *ctx) = 0;

  virtual void enterPrimaryType(TypeScriptParser::PrimaryTypeContext *ctx) = 0;
  virtual void exitPrimaryType(TypeScriptParser::PrimaryTypeContext *ctx) = 0;

  virtual void enterPredefinedType(TypeScriptParser::PredefinedTypeContext *ctx) = 0;
  virtual void exitPredefinedType(TypeScriptParser::PredefinedTypeContext *ctx) = 0;

  virtual void enterTypeReference(TypeScriptParser::TypeReferenceContext *ctx) = 0;
  virtual void exitTypeReference(TypeScriptParser::TypeReferenceContext *ctx) = 0;

  virtual void enterAccessControl(TypeScriptParser::AccessControlContext *ctx) = 0;
  virtual void exitAccessControl(TypeScriptParser::AccessControlContext *ctx) = 0;

  virtual void enterClassControl(TypeScriptParser::ClassControlContext *ctx) = 0;
  virtual void exitClassControl(TypeScriptParser::ClassControlContext *ctx) = 0;

  virtual void enterPropertyControl(TypeScriptParser::PropertyControlContext *ctx) = 0;
  virtual void exitPropertyControl(TypeScriptParser::PropertyControlContext *ctx) = 0;

  virtual void enterFunctionControl(TypeScriptParser::FunctionControlContext *ctx) = 0;
  virtual void exitFunctionControl(TypeScriptParser::FunctionControlContext *ctx) = 0;

  virtual void enterBlock(TypeScriptParser::BlockContext *ctx) = 0;
  virtual void exitBlock(TypeScriptParser::BlockContext *ctx) = 0;

  virtual void enterImportStatement(TypeScriptParser::ImportStatementContext *ctx) = 0;
  virtual void exitImportStatement(TypeScriptParser::ImportStatementContext *ctx) = 0;

  virtual void enterImportFromBlock(TypeScriptParser::ImportFromBlockContext *ctx) = 0;
  virtual void exitImportFromBlock(TypeScriptParser::ImportFromBlockContext *ctx) = 0;

  virtual void enterModuleItems(TypeScriptParser::ModuleItemsContext *ctx) = 0;
  virtual void exitModuleItems(TypeScriptParser::ModuleItemsContext *ctx) = 0;

  virtual void enterImportDefault(TypeScriptParser::ImportDefaultContext *ctx) = 0;
  virtual void exitImportDefault(TypeScriptParser::ImportDefaultContext *ctx) = 0;

  virtual void enterImportNamespace(TypeScriptParser::ImportNamespaceContext *ctx) = 0;
  virtual void exitImportNamespace(TypeScriptParser::ImportNamespaceContext *ctx) = 0;

  virtual void enterImportFrom(TypeScriptParser::ImportFromContext *ctx) = 0;
  virtual void exitImportFrom(TypeScriptParser::ImportFromContext *ctx) = 0;

  virtual void enterAliasName(TypeScriptParser::AliasNameContext *ctx) = 0;
  virtual void exitAliasName(TypeScriptParser::AliasNameContext *ctx) = 0;

  virtual void enterExportDeclaration(TypeScriptParser::ExportDeclarationContext *ctx) = 0;
  virtual void exitExportDeclaration(TypeScriptParser::ExportDeclarationContext *ctx) = 0;

  virtual void enterExportDefaultDeclaration(TypeScriptParser::ExportDefaultDeclarationContext *ctx) = 0;
  virtual void exitExportDefaultDeclaration(TypeScriptParser::ExportDefaultDeclarationContext *ctx) = 0;

  virtual void enterExportFromBlock(TypeScriptParser::ExportFromBlockContext *ctx) = 0;
  virtual void exitExportFromBlock(TypeScriptParser::ExportFromBlockContext *ctx) = 0;

  virtual void enterDeclaration(TypeScriptParser::DeclarationContext *ctx) = 0;
  virtual void exitDeclaration(TypeScriptParser::DeclarationContext *ctx) = 0;

  virtual void enterVariableStatement(TypeScriptParser::VariableStatementContext *ctx) = 0;
  virtual void exitVariableStatement(TypeScriptParser::VariableStatementContext *ctx) = 0;

  virtual void enterVariableDeclarationList(TypeScriptParser::VariableDeclarationListContext *ctx) = 0;
  virtual void exitVariableDeclarationList(TypeScriptParser::VariableDeclarationListContext *ctx) = 0;

  virtual void enterVariableDeclaration(TypeScriptParser::VariableDeclarationContext *ctx) = 0;
  virtual void exitVariableDeclaration(TypeScriptParser::VariableDeclarationContext *ctx) = 0;

  virtual void enterEmptyStatement(TypeScriptParser::EmptyStatementContext *ctx) = 0;
  virtual void exitEmptyStatement(TypeScriptParser::EmptyStatementContext *ctx) = 0;

  virtual void enterExpressionStatement(TypeScriptParser::ExpressionStatementContext *ctx) = 0;
  virtual void exitExpressionStatement(TypeScriptParser::ExpressionStatementContext *ctx) = 0;

  virtual void enterIfStatement(TypeScriptParser::IfStatementContext *ctx) = 0;
  virtual void exitIfStatement(TypeScriptParser::IfStatementContext *ctx) = 0;

  virtual void enterDoStatement(TypeScriptParser::DoStatementContext *ctx) = 0;
  virtual void exitDoStatement(TypeScriptParser::DoStatementContext *ctx) = 0;

  virtual void enterWhileStatement(TypeScriptParser::WhileStatementContext *ctx) = 0;
  virtual void exitWhileStatement(TypeScriptParser::WhileStatementContext *ctx) = 0;

  virtual void enterForStatement(TypeScriptParser::ForStatementContext *ctx) = 0;
  virtual void exitForStatement(TypeScriptParser::ForStatementContext *ctx) = 0;

  virtual void enterForInStatement(TypeScriptParser::ForInStatementContext *ctx) = 0;
  virtual void exitForInStatement(TypeScriptParser::ForInStatementContext *ctx) = 0;

  virtual void enterForOfStatement(TypeScriptParser::ForOfStatementContext *ctx) = 0;
  virtual void exitForOfStatement(TypeScriptParser::ForOfStatementContext *ctx) = 0;

  virtual void enterForInitialization(TypeScriptParser::ForInitializationContext *ctx) = 0;
  virtual void exitForInitialization(TypeScriptParser::ForInitializationContext *ctx) = 0;

  virtual void enterForCondition(TypeScriptParser::ForConditionContext *ctx) = 0;
  virtual void exitForCondition(TypeScriptParser::ForConditionContext *ctx) = 0;

  virtual void enterVarModifier(TypeScriptParser::VarModifierContext *ctx) = 0;
  virtual void exitVarModifier(TypeScriptParser::VarModifierContext *ctx) = 0;

  virtual void enterContinueStatement(TypeScriptParser::ContinueStatementContext *ctx) = 0;
  virtual void exitContinueStatement(TypeScriptParser::ContinueStatementContext *ctx) = 0;

  virtual void enterBreakStatement(TypeScriptParser::BreakStatementContext *ctx) = 0;
  virtual void exitBreakStatement(TypeScriptParser::BreakStatementContext *ctx) = 0;

  virtual void enterReturnStatement(TypeScriptParser::ReturnStatementContext *ctx) = 0;
  virtual void exitReturnStatement(TypeScriptParser::ReturnStatementContext *ctx) = 0;

  virtual void enterYieldStatement(TypeScriptParser::YieldStatementContext *ctx) = 0;
  virtual void exitYieldStatement(TypeScriptParser::YieldStatementContext *ctx) = 0;

  virtual void enterWithStatement(TypeScriptParser::WithStatementContext *ctx) = 0;
  virtual void exitWithStatement(TypeScriptParser::WithStatementContext *ctx) = 0;

  virtual void enterSwitchStatement(TypeScriptParser::SwitchStatementContext *ctx) = 0;
  virtual void exitSwitchStatement(TypeScriptParser::SwitchStatementContext *ctx) = 0;

  virtual void enterCaseBlock(TypeScriptParser::CaseBlockContext *ctx) = 0;
  virtual void exitCaseBlock(TypeScriptParser::CaseBlockContext *ctx) = 0;

  virtual void enterSwitchDefaultClause(TypeScriptParser::SwitchDefaultClauseContext *ctx) = 0;
  virtual void exitSwitchDefaultClause(TypeScriptParser::SwitchDefaultClauseContext *ctx) = 0;

  virtual void enterSwitchCaseClause(TypeScriptParser::SwitchCaseClauseContext *ctx) = 0;
  virtual void exitSwitchCaseClause(TypeScriptParser::SwitchCaseClauseContext *ctx) = 0;

  virtual void enterLabelledStatement(TypeScriptParser::LabelledStatementContext *ctx) = 0;
  virtual void exitLabelledStatement(TypeScriptParser::LabelledStatementContext *ctx) = 0;

  virtual void enterThrowStatement(TypeScriptParser::ThrowStatementContext *ctx) = 0;
  virtual void exitThrowStatement(TypeScriptParser::ThrowStatementContext *ctx) = 0;

  virtual void enterTryStatement(TypeScriptParser::TryStatementContext *ctx) = 0;
  virtual void exitTryStatement(TypeScriptParser::TryStatementContext *ctx) = 0;

  virtual void enterCatchProduction(TypeScriptParser::CatchProductionContext *ctx) = 0;
  virtual void exitCatchProduction(TypeScriptParser::CatchProductionContext *ctx) = 0;

  virtual void enterFinallyProduction(TypeScriptParser::FinallyProductionContext *ctx) = 0;
  virtual void exitFinallyProduction(TypeScriptParser::FinallyProductionContext *ctx) = 0;

  virtual void enterDebuggerStatement(TypeScriptParser::DebuggerStatementContext *ctx) = 0;
  virtual void exitDebuggerStatement(TypeScriptParser::DebuggerStatementContext *ctx) = 0;

  virtual void enterFunctionDeclaration(TypeScriptParser::FunctionDeclarationContext *ctx) = 0;
  virtual void exitFunctionDeclaration(TypeScriptParser::FunctionDeclarationContext *ctx) = 0;

  virtual void enterClassDeclaration(TypeScriptParser::ClassDeclarationContext *ctx) = 0;
  virtual void exitClassDeclaration(TypeScriptParser::ClassDeclarationContext *ctx) = 0;

  virtual void enterClassTail(TypeScriptParser::ClassTailContext *ctx) = 0;
  virtual void exitClassTail(TypeScriptParser::ClassTailContext *ctx) = 0;

  virtual void enterConstructorDefinition(TypeScriptParser::ConstructorDefinitionContext *ctx) = 0;
  virtual void exitConstructorDefinition(TypeScriptParser::ConstructorDefinitionContext *ctx) = 0;

  virtual void enterNormalMethodDefinition(TypeScriptParser::NormalMethodDefinitionContext *ctx) = 0;
  virtual void exitNormalMethodDefinition(TypeScriptParser::NormalMethodDefinitionContext *ctx) = 0;

  virtual void enterGetterMethodDefinition(TypeScriptParser::GetterMethodDefinitionContext *ctx) = 0;
  virtual void exitGetterMethodDefinition(TypeScriptParser::GetterMethodDefinitionContext *ctx) = 0;

  virtual void enterSetterMethodDefinition(TypeScriptParser::SetterMethodDefinitionContext *ctx) = 0;
  virtual void exitSetterMethodDefinition(TypeScriptParser::SetterMethodDefinitionContext *ctx) = 0;

  virtual void enterClassPropertyDefinition(TypeScriptParser::ClassPropertyDefinitionContext *ctx) = 0;
  virtual void exitClassPropertyDefinition(TypeScriptParser::ClassPropertyDefinitionContext *ctx) = 0;

  virtual void enterClassEmptyStatement(TypeScriptParser::ClassEmptyStatementContext *ctx) = 0;
  virtual void exitClassEmptyStatement(TypeScriptParser::ClassEmptyStatementContext *ctx) = 0;

  virtual void enterFormalParameterList(TypeScriptParser::FormalParameterListContext *ctx) = 0;
  virtual void exitFormalParameterList(TypeScriptParser::FormalParameterListContext *ctx) = 0;

  virtual void enterFormalParameterArg(TypeScriptParser::FormalParameterArgContext *ctx) = 0;
  virtual void exitFormalParameterArg(TypeScriptParser::FormalParameterArgContext *ctx) = 0;

  virtual void enterLastFormalParameterArg(TypeScriptParser::LastFormalParameterArgContext *ctx) = 0;
  virtual void exitLastFormalParameterArg(TypeScriptParser::LastFormalParameterArgContext *ctx) = 0;

  virtual void enterFunctionBody(TypeScriptParser::FunctionBodyContext *ctx) = 0;
  virtual void exitFunctionBody(TypeScriptParser::FunctionBodyContext *ctx) = 0;

  virtual void enterArrayLiteral(TypeScriptParser::ArrayLiteralContext *ctx) = 0;
  virtual void exitArrayLiteral(TypeScriptParser::ArrayLiteralContext *ctx) = 0;

  virtual void enterElementList(TypeScriptParser::ElementListContext *ctx) = 0;
  virtual void exitElementList(TypeScriptParser::ElementListContext *ctx) = 0;

  virtual void enterArrayElement(TypeScriptParser::ArrayElementContext *ctx) = 0;
  virtual void exitArrayElement(TypeScriptParser::ArrayElementContext *ctx) = 0;

  virtual void enterObjectLiteral(TypeScriptParser::ObjectLiteralContext *ctx) = 0;
  virtual void exitObjectLiteral(TypeScriptParser::ObjectLiteralContext *ctx) = 0;

  virtual void enterPropertyExpressionAssignment(TypeScriptParser::PropertyExpressionAssignmentContext *ctx) = 0;
  virtual void exitPropertyExpressionAssignment(TypeScriptParser::PropertyExpressionAssignmentContext *ctx) = 0;

  virtual void enterComputedPropertyExpressionAssignment(TypeScriptParser::ComputedPropertyExpressionAssignmentContext *ctx) = 0;
  virtual void exitComputedPropertyExpressionAssignment(TypeScriptParser::ComputedPropertyExpressionAssignmentContext *ctx) = 0;

  virtual void enterFunctionProperty(TypeScriptParser::FunctionPropertyContext *ctx) = 0;
  virtual void exitFunctionProperty(TypeScriptParser::FunctionPropertyContext *ctx) = 0;

  virtual void enterPropertyGetter(TypeScriptParser::PropertyGetterContext *ctx) = 0;
  virtual void exitPropertyGetter(TypeScriptParser::PropertyGetterContext *ctx) = 0;

  virtual void enterPropertySetter(TypeScriptParser::PropertySetterContext *ctx) = 0;
  virtual void exitPropertySetter(TypeScriptParser::PropertySetterContext *ctx) = 0;

  virtual void enterPropertyShorthand(TypeScriptParser::PropertyShorthandContext *ctx) = 0;
  virtual void exitPropertyShorthand(TypeScriptParser::PropertyShorthandContext *ctx) = 0;

  virtual void enterPropertyName(TypeScriptParser::PropertyNameContext *ctx) = 0;
  virtual void exitPropertyName(TypeScriptParser::PropertyNameContext *ctx) = 0;

  virtual void enterArguments(TypeScriptParser::ArgumentsContext *ctx) = 0;
  virtual void exitArguments(TypeScriptParser::ArgumentsContext *ctx) = 0;

  virtual void enterArgument(TypeScriptParser::ArgumentContext *ctx) = 0;
  virtual void exitArgument(TypeScriptParser::ArgumentContext *ctx) = 0;

  virtual void enterExpressionSequence(TypeScriptParser::ExpressionSequenceContext *ctx) = 0;
  virtual void exitExpressionSequence(TypeScriptParser::ExpressionSequenceContext *ctx) = 0;

  virtual void enterTemplateStringExpression(TypeScriptParser::TemplateStringExpressionContext *ctx) = 0;
  virtual void exitTemplateStringExpression(TypeScriptParser::TemplateStringExpressionContext *ctx) = 0;

  virtual void enterTernaryExpression(TypeScriptParser::TernaryExpressionContext *ctx) = 0;
  virtual void exitTernaryExpression(TypeScriptParser::TernaryExpressionContext *ctx) = 0;

  virtual void enterLogicalAndExpression(TypeScriptParser::LogicalAndExpressionContext *ctx) = 0;
  virtual void exitLogicalAndExpression(TypeScriptParser::LogicalAndExpressionContext *ctx) = 0;

  virtual void enterPowerExpression(TypeScriptParser::PowerExpressionContext *ctx) = 0;
  virtual void exitPowerExpression(TypeScriptParser::PowerExpressionContext *ctx) = 0;

  virtual void enterPreIncrementExpression(TypeScriptParser::PreIncrementExpressionContext *ctx) = 0;
  virtual void exitPreIncrementExpression(TypeScriptParser::PreIncrementExpressionContext *ctx) = 0;

  virtual void enterObjectLiteralExpression(TypeScriptParser::ObjectLiteralExpressionContext *ctx) = 0;
  virtual void exitObjectLiteralExpression(TypeScriptParser::ObjectLiteralExpressionContext *ctx) = 0;

  virtual void enterMetaExpression(TypeScriptParser::MetaExpressionContext *ctx) = 0;
  virtual void exitMetaExpression(TypeScriptParser::MetaExpressionContext *ctx) = 0;

  virtual void enterInExpression(TypeScriptParser::InExpressionContext *ctx) = 0;
  virtual void exitInExpression(TypeScriptParser::InExpressionContext *ctx) = 0;

  virtual void enterLogicalOrExpression(TypeScriptParser::LogicalOrExpressionContext *ctx) = 0;
  virtual void exitLogicalOrExpression(TypeScriptParser::LogicalOrExpressionContext *ctx) = 0;

  virtual void enterNotExpression(TypeScriptParser::NotExpressionContext *ctx) = 0;
  virtual void exitNotExpression(TypeScriptParser::NotExpressionContext *ctx) = 0;

  virtual void enterPreDecreaseExpression(TypeScriptParser::PreDecreaseExpressionContext *ctx) = 0;
  virtual void exitPreDecreaseExpression(TypeScriptParser::PreDecreaseExpressionContext *ctx) = 0;

  virtual void enterArgumentsExpression(TypeScriptParser::ArgumentsExpressionContext *ctx) = 0;
  virtual void exitArgumentsExpression(TypeScriptParser::ArgumentsExpressionContext *ctx) = 0;

  virtual void enterAwaitExpression(TypeScriptParser::AwaitExpressionContext *ctx) = 0;
  virtual void exitAwaitExpression(TypeScriptParser::AwaitExpressionContext *ctx) = 0;

  virtual void enterThisExpression(TypeScriptParser::ThisExpressionContext *ctx) = 0;
  virtual void exitThisExpression(TypeScriptParser::ThisExpressionContext *ctx) = 0;

  virtual void enterFunctionExpression(TypeScriptParser::FunctionExpressionContext *ctx) = 0;
  virtual void exitFunctionExpression(TypeScriptParser::FunctionExpressionContext *ctx) = 0;

  virtual void enterUnaryMinusExpression(TypeScriptParser::UnaryMinusExpressionContext *ctx) = 0;
  virtual void exitUnaryMinusExpression(TypeScriptParser::UnaryMinusExpressionContext *ctx) = 0;

  virtual void enterAssignmentExpression(TypeScriptParser::AssignmentExpressionContext *ctx) = 0;
  virtual void exitAssignmentExpression(TypeScriptParser::AssignmentExpressionContext *ctx) = 0;

  virtual void enterPostDecreaseExpression(TypeScriptParser::PostDecreaseExpressionContext *ctx) = 0;
  virtual void exitPostDecreaseExpression(TypeScriptParser::PostDecreaseExpressionContext *ctx) = 0;

  virtual void enterTypeofExpression(TypeScriptParser::TypeofExpressionContext *ctx) = 0;
  virtual void exitTypeofExpression(TypeScriptParser::TypeofExpressionContext *ctx) = 0;

  virtual void enterInstanceofExpression(TypeScriptParser::InstanceofExpressionContext *ctx) = 0;
  virtual void exitInstanceofExpression(TypeScriptParser::InstanceofExpressionContext *ctx) = 0;

  virtual void enterUnaryPlusExpression(TypeScriptParser::UnaryPlusExpressionContext *ctx) = 0;
  virtual void exitUnaryPlusExpression(TypeScriptParser::UnaryPlusExpressionContext *ctx) = 0;

  virtual void enterDeleteExpression(TypeScriptParser::DeleteExpressionContext *ctx) = 0;
  virtual void exitDeleteExpression(TypeScriptParser::DeleteExpressionContext *ctx) = 0;

  virtual void enterImportExpression(TypeScriptParser::ImportExpressionContext *ctx) = 0;
  virtual void exitImportExpression(TypeScriptParser::ImportExpressionContext *ctx) = 0;

  virtual void enterEqualityExpression(TypeScriptParser::EqualityExpressionContext *ctx) = 0;
  virtual void exitEqualityExpression(TypeScriptParser::EqualityExpressionContext *ctx) = 0;

  virtual void enterBitXOrExpression(TypeScriptParser::BitXOrExpressionContext *ctx) = 0;
  virtual void exitBitXOrExpression(TypeScriptParser::BitXOrExpressionContext *ctx) = 0;

  virtual void enterSuperExpression(TypeScriptParser::SuperExpressionContext *ctx) = 0;
  virtual void exitSuperExpression(TypeScriptParser::SuperExpressionContext *ctx) = 0;

  virtual void enterMultiplicativeExpression(TypeScriptParser::MultiplicativeExpressionContext *ctx) = 0;
  virtual void exitMultiplicativeExpression(TypeScriptParser::MultiplicativeExpressionContext *ctx) = 0;

  virtual void enterBitShiftExpression(TypeScriptParser::BitShiftExpressionContext *ctx) = 0;
  virtual void exitBitShiftExpression(TypeScriptParser::BitShiftExpressionContext *ctx) = 0;

  virtual void enterParenthesizedExpression(TypeScriptParser::ParenthesizedExpressionContext *ctx) = 0;
  virtual void exitParenthesizedExpression(TypeScriptParser::ParenthesizedExpressionContext *ctx) = 0;

  virtual void enterAdditiveExpression(TypeScriptParser::AdditiveExpressionContext *ctx) = 0;
  virtual void exitAdditiveExpression(TypeScriptParser::AdditiveExpressionContext *ctx) = 0;

  virtual void enterRelationalExpression(TypeScriptParser::RelationalExpressionContext *ctx) = 0;
  virtual void exitRelationalExpression(TypeScriptParser::RelationalExpressionContext *ctx) = 0;

  virtual void enterPostIncrementExpression(TypeScriptParser::PostIncrementExpressionContext *ctx) = 0;
  virtual void exitPostIncrementExpression(TypeScriptParser::PostIncrementExpressionContext *ctx) = 0;

  virtual void enterYieldExpression(TypeScriptParser::YieldExpressionContext *ctx) = 0;
  virtual void exitYieldExpression(TypeScriptParser::YieldExpressionContext *ctx) = 0;

  virtual void enterBitNotExpression(TypeScriptParser::BitNotExpressionContext *ctx) = 0;
  virtual void exitBitNotExpression(TypeScriptParser::BitNotExpressionContext *ctx) = 0;

  virtual void enterNewExpression(TypeScriptParser::NewExpressionContext *ctx) = 0;
  virtual void exitNewExpression(TypeScriptParser::NewExpressionContext *ctx) = 0;

  virtual void enterLiteralExpression(TypeScriptParser::LiteralExpressionContext *ctx) = 0;
  virtual void exitLiteralExpression(TypeScriptParser::LiteralExpressionContext *ctx) = 0;

  virtual void enterArrayLiteralExpression(TypeScriptParser::ArrayLiteralExpressionContext *ctx) = 0;
  virtual void exitArrayLiteralExpression(TypeScriptParser::ArrayLiteralExpressionContext *ctx) = 0;

  virtual void enterMemberDotExpression(TypeScriptParser::MemberDotExpressionContext *ctx) = 0;
  virtual void exitMemberDotExpression(TypeScriptParser::MemberDotExpressionContext *ctx) = 0;

  virtual void enterClassExpression(TypeScriptParser::ClassExpressionContext *ctx) = 0;
  virtual void exitClassExpression(TypeScriptParser::ClassExpressionContext *ctx) = 0;

  virtual void enterMemberIndexExpression(TypeScriptParser::MemberIndexExpressionContext *ctx) = 0;
  virtual void exitMemberIndexExpression(TypeScriptParser::MemberIndexExpressionContext *ctx) = 0;

  virtual void enterIdentifierExpression(TypeScriptParser::IdentifierExpressionContext *ctx) = 0;
  virtual void exitIdentifierExpression(TypeScriptParser::IdentifierExpressionContext *ctx) = 0;

  virtual void enterBitAndExpression(TypeScriptParser::BitAndExpressionContext *ctx) = 0;
  virtual void exitBitAndExpression(TypeScriptParser::BitAndExpressionContext *ctx) = 0;

  virtual void enterBitOrExpression(TypeScriptParser::BitOrExpressionContext *ctx) = 0;
  virtual void exitBitOrExpression(TypeScriptParser::BitOrExpressionContext *ctx) = 0;

  virtual void enterAssignmentOperatorExpression(TypeScriptParser::AssignmentOperatorExpressionContext *ctx) = 0;
  virtual void exitAssignmentOperatorExpression(TypeScriptParser::AssignmentOperatorExpressionContext *ctx) = 0;

  virtual void enterVoidExpression(TypeScriptParser::VoidExpressionContext *ctx) = 0;
  virtual void exitVoidExpression(TypeScriptParser::VoidExpressionContext *ctx) = 0;

  virtual void enterCoalesceExpression(TypeScriptParser::CoalesceExpressionContext *ctx) = 0;
  virtual void exitCoalesceExpression(TypeScriptParser::CoalesceExpressionContext *ctx) = 0;

  virtual void enterAssignable(TypeScriptParser::AssignableContext *ctx) = 0;
  virtual void exitAssignable(TypeScriptParser::AssignableContext *ctx) = 0;

  virtual void enterFunctionDecl(TypeScriptParser::FunctionDeclContext *ctx) = 0;
  virtual void exitFunctionDecl(TypeScriptParser::FunctionDeclContext *ctx) = 0;

  virtual void enterAnoymousFunctionDecl(TypeScriptParser::AnoymousFunctionDeclContext *ctx) = 0;
  virtual void exitAnoymousFunctionDecl(TypeScriptParser::AnoymousFunctionDeclContext *ctx) = 0;

  virtual void enterArrowFunction(TypeScriptParser::ArrowFunctionContext *ctx) = 0;
  virtual void exitArrowFunction(TypeScriptParser::ArrowFunctionContext *ctx) = 0;

  virtual void enterArrowFunctionParameters(TypeScriptParser::ArrowFunctionParametersContext *ctx) = 0;
  virtual void exitArrowFunctionParameters(TypeScriptParser::ArrowFunctionParametersContext *ctx) = 0;

  virtual void enterArrowFunctionBody(TypeScriptParser::ArrowFunctionBodyContext *ctx) = 0;
  virtual void exitArrowFunctionBody(TypeScriptParser::ArrowFunctionBodyContext *ctx) = 0;

  virtual void enterAssignmentOperator(TypeScriptParser::AssignmentOperatorContext *ctx) = 0;
  virtual void exitAssignmentOperator(TypeScriptParser::AssignmentOperatorContext *ctx) = 0;

  virtual void enterLiteral(TypeScriptParser::LiteralContext *ctx) = 0;
  virtual void exitLiteral(TypeScriptParser::LiteralContext *ctx) = 0;

  virtual void enterNumericLiteral(TypeScriptParser::NumericLiteralContext *ctx) = 0;
  virtual void exitNumericLiteral(TypeScriptParser::NumericLiteralContext *ctx) = 0;

  virtual void enterBigintLiteral(TypeScriptParser::BigintLiteralContext *ctx) = 0;
  virtual void exitBigintLiteral(TypeScriptParser::BigintLiteralContext *ctx) = 0;

  virtual void enterIdentifierName(TypeScriptParser::IdentifierNameContext *ctx) = 0;
  virtual void exitIdentifierName(TypeScriptParser::IdentifierNameContext *ctx) = 0;

  virtual void enterReservedWord(TypeScriptParser::ReservedWordContext *ctx) = 0;
  virtual void exitReservedWord(TypeScriptParser::ReservedWordContext *ctx) = 0;

  virtual void enterKeyword(TypeScriptParser::KeywordContext *ctx) = 0;
  virtual void exitKeyword(TypeScriptParser::KeywordContext *ctx) = 0;

  virtual void enterGetter(TypeScriptParser::GetterContext *ctx) = 0;
  virtual void exitGetter(TypeScriptParser::GetterContext *ctx) = 0;

  virtual void enterSetter(TypeScriptParser::SetterContext *ctx) = 0;
  virtual void exitSetter(TypeScriptParser::SetterContext *ctx) = 0;

  virtual void enterEos(TypeScriptParser::EosContext *ctx) = 0;
  virtual void exitEos(TypeScriptParser::EosContext *ctx) = 0;


};

