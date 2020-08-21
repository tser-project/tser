
// Generated from TypeScriptParser.g4 by ANTLR 4.8

#pragma once


#include "antlr4-runtime.h"
#include "TypeScriptParserListener.h"


/**
 * This class provides an empty implementation of TypeScriptParserListener,
 * which can be extended to create a listener which only needs to handle a subset
 * of the available methods.
 */
class  TypeScriptParserBaseListener : public TypeScriptParserListener {
public:

  virtual void enterProgram(TypeScriptParser::ProgramContext * /*ctx*/) override { }
  virtual void exitProgram(TypeScriptParser::ProgramContext * /*ctx*/) override { }

  virtual void enterStatementList(TypeScriptParser::StatementListContext * /*ctx*/) override { }
  virtual void exitStatementList(TypeScriptParser::StatementListContext * /*ctx*/) override { }

  virtual void enterStatement(TypeScriptParser::StatementContext * /*ctx*/) override { }
  virtual void exitStatement(TypeScriptParser::StatementContext * /*ctx*/) override { }

  virtual void enterTypeSign(TypeScriptParser::TypeSignContext * /*ctx*/) override { }
  virtual void exitTypeSign(TypeScriptParser::TypeSignContext * /*ctx*/) override { }

  virtual void enterPrimaryType(TypeScriptParser::PrimaryTypeContext * /*ctx*/) override { }
  virtual void exitPrimaryType(TypeScriptParser::PrimaryTypeContext * /*ctx*/) override { }

  virtual void enterPredefinedType(TypeScriptParser::PredefinedTypeContext * /*ctx*/) override { }
  virtual void exitPredefinedType(TypeScriptParser::PredefinedTypeContext * /*ctx*/) override { }

  virtual void enterTypeReference(TypeScriptParser::TypeReferenceContext * /*ctx*/) override { }
  virtual void exitTypeReference(TypeScriptParser::TypeReferenceContext * /*ctx*/) override { }

  virtual void enterAccessControl(TypeScriptParser::AccessControlContext * /*ctx*/) override { }
  virtual void exitAccessControl(TypeScriptParser::AccessControlContext * /*ctx*/) override { }

  virtual void enterClassControl(TypeScriptParser::ClassControlContext * /*ctx*/) override { }
  virtual void exitClassControl(TypeScriptParser::ClassControlContext * /*ctx*/) override { }

  virtual void enterPropertyControl(TypeScriptParser::PropertyControlContext * /*ctx*/) override { }
  virtual void exitPropertyControl(TypeScriptParser::PropertyControlContext * /*ctx*/) override { }

  virtual void enterFunctionControl(TypeScriptParser::FunctionControlContext * /*ctx*/) override { }
  virtual void exitFunctionControl(TypeScriptParser::FunctionControlContext * /*ctx*/) override { }

  virtual void enterBlock(TypeScriptParser::BlockContext * /*ctx*/) override { }
  virtual void exitBlock(TypeScriptParser::BlockContext * /*ctx*/) override { }

  virtual void enterImportStatement(TypeScriptParser::ImportStatementContext * /*ctx*/) override { }
  virtual void exitImportStatement(TypeScriptParser::ImportStatementContext * /*ctx*/) override { }

  virtual void enterImportFromBlock(TypeScriptParser::ImportFromBlockContext * /*ctx*/) override { }
  virtual void exitImportFromBlock(TypeScriptParser::ImportFromBlockContext * /*ctx*/) override { }

  virtual void enterModuleItems(TypeScriptParser::ModuleItemsContext * /*ctx*/) override { }
  virtual void exitModuleItems(TypeScriptParser::ModuleItemsContext * /*ctx*/) override { }

  virtual void enterImportDefault(TypeScriptParser::ImportDefaultContext * /*ctx*/) override { }
  virtual void exitImportDefault(TypeScriptParser::ImportDefaultContext * /*ctx*/) override { }

  virtual void enterImportNamespace(TypeScriptParser::ImportNamespaceContext * /*ctx*/) override { }
  virtual void exitImportNamespace(TypeScriptParser::ImportNamespaceContext * /*ctx*/) override { }

  virtual void enterImportFrom(TypeScriptParser::ImportFromContext * /*ctx*/) override { }
  virtual void exitImportFrom(TypeScriptParser::ImportFromContext * /*ctx*/) override { }

  virtual void enterAliasName(TypeScriptParser::AliasNameContext * /*ctx*/) override { }
  virtual void exitAliasName(TypeScriptParser::AliasNameContext * /*ctx*/) override { }

  virtual void enterExportDeclaration(TypeScriptParser::ExportDeclarationContext * /*ctx*/) override { }
  virtual void exitExportDeclaration(TypeScriptParser::ExportDeclarationContext * /*ctx*/) override { }

  virtual void enterExportDefaultDeclaration(TypeScriptParser::ExportDefaultDeclarationContext * /*ctx*/) override { }
  virtual void exitExportDefaultDeclaration(TypeScriptParser::ExportDefaultDeclarationContext * /*ctx*/) override { }

  virtual void enterExportFromBlock(TypeScriptParser::ExportFromBlockContext * /*ctx*/) override { }
  virtual void exitExportFromBlock(TypeScriptParser::ExportFromBlockContext * /*ctx*/) override { }

  virtual void enterDeclaration(TypeScriptParser::DeclarationContext * /*ctx*/) override { }
  virtual void exitDeclaration(TypeScriptParser::DeclarationContext * /*ctx*/) override { }

  virtual void enterVariableStatement(TypeScriptParser::VariableStatementContext * /*ctx*/) override { }
  virtual void exitVariableStatement(TypeScriptParser::VariableStatementContext * /*ctx*/) override { }

  virtual void enterVariableDeclarationList(TypeScriptParser::VariableDeclarationListContext * /*ctx*/) override { }
  virtual void exitVariableDeclarationList(TypeScriptParser::VariableDeclarationListContext * /*ctx*/) override { }

  virtual void enterVariableDeclaration(TypeScriptParser::VariableDeclarationContext * /*ctx*/) override { }
  virtual void exitVariableDeclaration(TypeScriptParser::VariableDeclarationContext * /*ctx*/) override { }

  virtual void enterEmptyStatement(TypeScriptParser::EmptyStatementContext * /*ctx*/) override { }
  virtual void exitEmptyStatement(TypeScriptParser::EmptyStatementContext * /*ctx*/) override { }

  virtual void enterExpressionStatement(TypeScriptParser::ExpressionStatementContext * /*ctx*/) override { }
  virtual void exitExpressionStatement(TypeScriptParser::ExpressionStatementContext * /*ctx*/) override { }

  virtual void enterIfStatement(TypeScriptParser::IfStatementContext * /*ctx*/) override { }
  virtual void exitIfStatement(TypeScriptParser::IfStatementContext * /*ctx*/) override { }

  virtual void enterDoStatement(TypeScriptParser::DoStatementContext * /*ctx*/) override { }
  virtual void exitDoStatement(TypeScriptParser::DoStatementContext * /*ctx*/) override { }

  virtual void enterWhileStatement(TypeScriptParser::WhileStatementContext * /*ctx*/) override { }
  virtual void exitWhileStatement(TypeScriptParser::WhileStatementContext * /*ctx*/) override { }

  virtual void enterForStatement(TypeScriptParser::ForStatementContext * /*ctx*/) override { }
  virtual void exitForStatement(TypeScriptParser::ForStatementContext * /*ctx*/) override { }

  virtual void enterForInStatement(TypeScriptParser::ForInStatementContext * /*ctx*/) override { }
  virtual void exitForInStatement(TypeScriptParser::ForInStatementContext * /*ctx*/) override { }

  virtual void enterForOfStatement(TypeScriptParser::ForOfStatementContext * /*ctx*/) override { }
  virtual void exitForOfStatement(TypeScriptParser::ForOfStatementContext * /*ctx*/) override { }

  virtual void enterForInitialization(TypeScriptParser::ForInitializationContext * /*ctx*/) override { }
  virtual void exitForInitialization(TypeScriptParser::ForInitializationContext * /*ctx*/) override { }

  virtual void enterForCondition(TypeScriptParser::ForConditionContext * /*ctx*/) override { }
  virtual void exitForCondition(TypeScriptParser::ForConditionContext * /*ctx*/) override { }

  virtual void enterVarModifier(TypeScriptParser::VarModifierContext * /*ctx*/) override { }
  virtual void exitVarModifier(TypeScriptParser::VarModifierContext * /*ctx*/) override { }

  virtual void enterContinueStatement(TypeScriptParser::ContinueStatementContext * /*ctx*/) override { }
  virtual void exitContinueStatement(TypeScriptParser::ContinueStatementContext * /*ctx*/) override { }

  virtual void enterBreakStatement(TypeScriptParser::BreakStatementContext * /*ctx*/) override { }
  virtual void exitBreakStatement(TypeScriptParser::BreakStatementContext * /*ctx*/) override { }

  virtual void enterReturnStatement(TypeScriptParser::ReturnStatementContext * /*ctx*/) override { }
  virtual void exitReturnStatement(TypeScriptParser::ReturnStatementContext * /*ctx*/) override { }

  virtual void enterYieldStatement(TypeScriptParser::YieldStatementContext * /*ctx*/) override { }
  virtual void exitYieldStatement(TypeScriptParser::YieldStatementContext * /*ctx*/) override { }

  virtual void enterWithStatement(TypeScriptParser::WithStatementContext * /*ctx*/) override { }
  virtual void exitWithStatement(TypeScriptParser::WithStatementContext * /*ctx*/) override { }

  virtual void enterSwitchStatement(TypeScriptParser::SwitchStatementContext * /*ctx*/) override { }
  virtual void exitSwitchStatement(TypeScriptParser::SwitchStatementContext * /*ctx*/) override { }

  virtual void enterCaseBlock(TypeScriptParser::CaseBlockContext * /*ctx*/) override { }
  virtual void exitCaseBlock(TypeScriptParser::CaseBlockContext * /*ctx*/) override { }

  virtual void enterSwitchDefaultClause(TypeScriptParser::SwitchDefaultClauseContext * /*ctx*/) override { }
  virtual void exitSwitchDefaultClause(TypeScriptParser::SwitchDefaultClauseContext * /*ctx*/) override { }

  virtual void enterSwitchCaseClause(TypeScriptParser::SwitchCaseClauseContext * /*ctx*/) override { }
  virtual void exitSwitchCaseClause(TypeScriptParser::SwitchCaseClauseContext * /*ctx*/) override { }

  virtual void enterLabelledStatement(TypeScriptParser::LabelledStatementContext * /*ctx*/) override { }
  virtual void exitLabelledStatement(TypeScriptParser::LabelledStatementContext * /*ctx*/) override { }

  virtual void enterThrowStatement(TypeScriptParser::ThrowStatementContext * /*ctx*/) override { }
  virtual void exitThrowStatement(TypeScriptParser::ThrowStatementContext * /*ctx*/) override { }

  virtual void enterTryStatement(TypeScriptParser::TryStatementContext * /*ctx*/) override { }
  virtual void exitTryStatement(TypeScriptParser::TryStatementContext * /*ctx*/) override { }

  virtual void enterCatchProduction(TypeScriptParser::CatchProductionContext * /*ctx*/) override { }
  virtual void exitCatchProduction(TypeScriptParser::CatchProductionContext * /*ctx*/) override { }

  virtual void enterFinallyProduction(TypeScriptParser::FinallyProductionContext * /*ctx*/) override { }
  virtual void exitFinallyProduction(TypeScriptParser::FinallyProductionContext * /*ctx*/) override { }

  virtual void enterDebuggerStatement(TypeScriptParser::DebuggerStatementContext * /*ctx*/) override { }
  virtual void exitDebuggerStatement(TypeScriptParser::DebuggerStatementContext * /*ctx*/) override { }

  virtual void enterFunctionDeclaration(TypeScriptParser::FunctionDeclarationContext * /*ctx*/) override { }
  virtual void exitFunctionDeclaration(TypeScriptParser::FunctionDeclarationContext * /*ctx*/) override { }

  virtual void enterClassDeclaration(TypeScriptParser::ClassDeclarationContext * /*ctx*/) override { }
  virtual void exitClassDeclaration(TypeScriptParser::ClassDeclarationContext * /*ctx*/) override { }

  virtual void enterClassTail(TypeScriptParser::ClassTailContext * /*ctx*/) override { }
  virtual void exitClassTail(TypeScriptParser::ClassTailContext * /*ctx*/) override { }

  virtual void enterConstructorDefinition(TypeScriptParser::ConstructorDefinitionContext * /*ctx*/) override { }
  virtual void exitConstructorDefinition(TypeScriptParser::ConstructorDefinitionContext * /*ctx*/) override { }

  virtual void enterNormalMethodDefinition(TypeScriptParser::NormalMethodDefinitionContext * /*ctx*/) override { }
  virtual void exitNormalMethodDefinition(TypeScriptParser::NormalMethodDefinitionContext * /*ctx*/) override { }

  virtual void enterGetterMethodDefinition(TypeScriptParser::GetterMethodDefinitionContext * /*ctx*/) override { }
  virtual void exitGetterMethodDefinition(TypeScriptParser::GetterMethodDefinitionContext * /*ctx*/) override { }

  virtual void enterSetterMethodDefinition(TypeScriptParser::SetterMethodDefinitionContext * /*ctx*/) override { }
  virtual void exitSetterMethodDefinition(TypeScriptParser::SetterMethodDefinitionContext * /*ctx*/) override { }

  virtual void enterClassPropertyDefinition(TypeScriptParser::ClassPropertyDefinitionContext * /*ctx*/) override { }
  virtual void exitClassPropertyDefinition(TypeScriptParser::ClassPropertyDefinitionContext * /*ctx*/) override { }

  virtual void enterClassEmptyStatement(TypeScriptParser::ClassEmptyStatementContext * /*ctx*/) override { }
  virtual void exitClassEmptyStatement(TypeScriptParser::ClassEmptyStatementContext * /*ctx*/) override { }

  virtual void enterFormalParameterList(TypeScriptParser::FormalParameterListContext * /*ctx*/) override { }
  virtual void exitFormalParameterList(TypeScriptParser::FormalParameterListContext * /*ctx*/) override { }

  virtual void enterFormalParameterArg(TypeScriptParser::FormalParameterArgContext * /*ctx*/) override { }
  virtual void exitFormalParameterArg(TypeScriptParser::FormalParameterArgContext * /*ctx*/) override { }

  virtual void enterLastFormalParameterArg(TypeScriptParser::LastFormalParameterArgContext * /*ctx*/) override { }
  virtual void exitLastFormalParameterArg(TypeScriptParser::LastFormalParameterArgContext * /*ctx*/) override { }

  virtual void enterFunctionBody(TypeScriptParser::FunctionBodyContext * /*ctx*/) override { }
  virtual void exitFunctionBody(TypeScriptParser::FunctionBodyContext * /*ctx*/) override { }

  virtual void enterArrayLiteral(TypeScriptParser::ArrayLiteralContext * /*ctx*/) override { }
  virtual void exitArrayLiteral(TypeScriptParser::ArrayLiteralContext * /*ctx*/) override { }

  virtual void enterElementList(TypeScriptParser::ElementListContext * /*ctx*/) override { }
  virtual void exitElementList(TypeScriptParser::ElementListContext * /*ctx*/) override { }

  virtual void enterArrayElement(TypeScriptParser::ArrayElementContext * /*ctx*/) override { }
  virtual void exitArrayElement(TypeScriptParser::ArrayElementContext * /*ctx*/) override { }

  virtual void enterObjectLiteral(TypeScriptParser::ObjectLiteralContext * /*ctx*/) override { }
  virtual void exitObjectLiteral(TypeScriptParser::ObjectLiteralContext * /*ctx*/) override { }

  virtual void enterPropertyExpressionAssignment(TypeScriptParser::PropertyExpressionAssignmentContext * /*ctx*/) override { }
  virtual void exitPropertyExpressionAssignment(TypeScriptParser::PropertyExpressionAssignmentContext * /*ctx*/) override { }

  virtual void enterComputedPropertyExpressionAssignment(TypeScriptParser::ComputedPropertyExpressionAssignmentContext * /*ctx*/) override { }
  virtual void exitComputedPropertyExpressionAssignment(TypeScriptParser::ComputedPropertyExpressionAssignmentContext * /*ctx*/) override { }

  virtual void enterFunctionProperty(TypeScriptParser::FunctionPropertyContext * /*ctx*/) override { }
  virtual void exitFunctionProperty(TypeScriptParser::FunctionPropertyContext * /*ctx*/) override { }

  virtual void enterPropertyGetter(TypeScriptParser::PropertyGetterContext * /*ctx*/) override { }
  virtual void exitPropertyGetter(TypeScriptParser::PropertyGetterContext * /*ctx*/) override { }

  virtual void enterPropertySetter(TypeScriptParser::PropertySetterContext * /*ctx*/) override { }
  virtual void exitPropertySetter(TypeScriptParser::PropertySetterContext * /*ctx*/) override { }

  virtual void enterPropertyShorthand(TypeScriptParser::PropertyShorthandContext * /*ctx*/) override { }
  virtual void exitPropertyShorthand(TypeScriptParser::PropertyShorthandContext * /*ctx*/) override { }

  virtual void enterPropertyName(TypeScriptParser::PropertyNameContext * /*ctx*/) override { }
  virtual void exitPropertyName(TypeScriptParser::PropertyNameContext * /*ctx*/) override { }

  virtual void enterArguments(TypeScriptParser::ArgumentsContext * /*ctx*/) override { }
  virtual void exitArguments(TypeScriptParser::ArgumentsContext * /*ctx*/) override { }

  virtual void enterArgument(TypeScriptParser::ArgumentContext * /*ctx*/) override { }
  virtual void exitArgument(TypeScriptParser::ArgumentContext * /*ctx*/) override { }

  virtual void enterExpressionSequence(TypeScriptParser::ExpressionSequenceContext * /*ctx*/) override { }
  virtual void exitExpressionSequence(TypeScriptParser::ExpressionSequenceContext * /*ctx*/) override { }

  virtual void enterTemplateStringExpression(TypeScriptParser::TemplateStringExpressionContext * /*ctx*/) override { }
  virtual void exitTemplateStringExpression(TypeScriptParser::TemplateStringExpressionContext * /*ctx*/) override { }

  virtual void enterTernaryExpression(TypeScriptParser::TernaryExpressionContext * /*ctx*/) override { }
  virtual void exitTernaryExpression(TypeScriptParser::TernaryExpressionContext * /*ctx*/) override { }

  virtual void enterLogicalAndExpression(TypeScriptParser::LogicalAndExpressionContext * /*ctx*/) override { }
  virtual void exitLogicalAndExpression(TypeScriptParser::LogicalAndExpressionContext * /*ctx*/) override { }

  virtual void enterPowerExpression(TypeScriptParser::PowerExpressionContext * /*ctx*/) override { }
  virtual void exitPowerExpression(TypeScriptParser::PowerExpressionContext * /*ctx*/) override { }

  virtual void enterPreIncrementExpression(TypeScriptParser::PreIncrementExpressionContext * /*ctx*/) override { }
  virtual void exitPreIncrementExpression(TypeScriptParser::PreIncrementExpressionContext * /*ctx*/) override { }

  virtual void enterObjectLiteralExpression(TypeScriptParser::ObjectLiteralExpressionContext * /*ctx*/) override { }
  virtual void exitObjectLiteralExpression(TypeScriptParser::ObjectLiteralExpressionContext * /*ctx*/) override { }

  virtual void enterMetaExpression(TypeScriptParser::MetaExpressionContext * /*ctx*/) override { }
  virtual void exitMetaExpression(TypeScriptParser::MetaExpressionContext * /*ctx*/) override { }

  virtual void enterInExpression(TypeScriptParser::InExpressionContext * /*ctx*/) override { }
  virtual void exitInExpression(TypeScriptParser::InExpressionContext * /*ctx*/) override { }

  virtual void enterLogicalOrExpression(TypeScriptParser::LogicalOrExpressionContext * /*ctx*/) override { }
  virtual void exitLogicalOrExpression(TypeScriptParser::LogicalOrExpressionContext * /*ctx*/) override { }

  virtual void enterNotExpression(TypeScriptParser::NotExpressionContext * /*ctx*/) override { }
  virtual void exitNotExpression(TypeScriptParser::NotExpressionContext * /*ctx*/) override { }

  virtual void enterPreDecreaseExpression(TypeScriptParser::PreDecreaseExpressionContext * /*ctx*/) override { }
  virtual void exitPreDecreaseExpression(TypeScriptParser::PreDecreaseExpressionContext * /*ctx*/) override { }

  virtual void enterArgumentsExpression(TypeScriptParser::ArgumentsExpressionContext * /*ctx*/) override { }
  virtual void exitArgumentsExpression(TypeScriptParser::ArgumentsExpressionContext * /*ctx*/) override { }

  virtual void enterAwaitExpression(TypeScriptParser::AwaitExpressionContext * /*ctx*/) override { }
  virtual void exitAwaitExpression(TypeScriptParser::AwaitExpressionContext * /*ctx*/) override { }

  virtual void enterThisExpression(TypeScriptParser::ThisExpressionContext * /*ctx*/) override { }
  virtual void exitThisExpression(TypeScriptParser::ThisExpressionContext * /*ctx*/) override { }

  virtual void enterFunctionExpression(TypeScriptParser::FunctionExpressionContext * /*ctx*/) override { }
  virtual void exitFunctionExpression(TypeScriptParser::FunctionExpressionContext * /*ctx*/) override { }

  virtual void enterUnaryMinusExpression(TypeScriptParser::UnaryMinusExpressionContext * /*ctx*/) override { }
  virtual void exitUnaryMinusExpression(TypeScriptParser::UnaryMinusExpressionContext * /*ctx*/) override { }

  virtual void enterAssignmentExpression(TypeScriptParser::AssignmentExpressionContext * /*ctx*/) override { }
  virtual void exitAssignmentExpression(TypeScriptParser::AssignmentExpressionContext * /*ctx*/) override { }

  virtual void enterPostDecreaseExpression(TypeScriptParser::PostDecreaseExpressionContext * /*ctx*/) override { }
  virtual void exitPostDecreaseExpression(TypeScriptParser::PostDecreaseExpressionContext * /*ctx*/) override { }

  virtual void enterTypeofExpression(TypeScriptParser::TypeofExpressionContext * /*ctx*/) override { }
  virtual void exitTypeofExpression(TypeScriptParser::TypeofExpressionContext * /*ctx*/) override { }

  virtual void enterInstanceofExpression(TypeScriptParser::InstanceofExpressionContext * /*ctx*/) override { }
  virtual void exitInstanceofExpression(TypeScriptParser::InstanceofExpressionContext * /*ctx*/) override { }

  virtual void enterUnaryPlusExpression(TypeScriptParser::UnaryPlusExpressionContext * /*ctx*/) override { }
  virtual void exitUnaryPlusExpression(TypeScriptParser::UnaryPlusExpressionContext * /*ctx*/) override { }

  virtual void enterDeleteExpression(TypeScriptParser::DeleteExpressionContext * /*ctx*/) override { }
  virtual void exitDeleteExpression(TypeScriptParser::DeleteExpressionContext * /*ctx*/) override { }

  virtual void enterImportExpression(TypeScriptParser::ImportExpressionContext * /*ctx*/) override { }
  virtual void exitImportExpression(TypeScriptParser::ImportExpressionContext * /*ctx*/) override { }

  virtual void enterEqualityExpression(TypeScriptParser::EqualityExpressionContext * /*ctx*/) override { }
  virtual void exitEqualityExpression(TypeScriptParser::EqualityExpressionContext * /*ctx*/) override { }

  virtual void enterBitXOrExpression(TypeScriptParser::BitXOrExpressionContext * /*ctx*/) override { }
  virtual void exitBitXOrExpression(TypeScriptParser::BitXOrExpressionContext * /*ctx*/) override { }

  virtual void enterSuperExpression(TypeScriptParser::SuperExpressionContext * /*ctx*/) override { }
  virtual void exitSuperExpression(TypeScriptParser::SuperExpressionContext * /*ctx*/) override { }

  virtual void enterMultiplicativeExpression(TypeScriptParser::MultiplicativeExpressionContext * /*ctx*/) override { }
  virtual void exitMultiplicativeExpression(TypeScriptParser::MultiplicativeExpressionContext * /*ctx*/) override { }

  virtual void enterBitShiftExpression(TypeScriptParser::BitShiftExpressionContext * /*ctx*/) override { }
  virtual void exitBitShiftExpression(TypeScriptParser::BitShiftExpressionContext * /*ctx*/) override { }

  virtual void enterParenthesizedExpression(TypeScriptParser::ParenthesizedExpressionContext * /*ctx*/) override { }
  virtual void exitParenthesizedExpression(TypeScriptParser::ParenthesizedExpressionContext * /*ctx*/) override { }

  virtual void enterAdditiveExpression(TypeScriptParser::AdditiveExpressionContext * /*ctx*/) override { }
  virtual void exitAdditiveExpression(TypeScriptParser::AdditiveExpressionContext * /*ctx*/) override { }

  virtual void enterRelationalExpression(TypeScriptParser::RelationalExpressionContext * /*ctx*/) override { }
  virtual void exitRelationalExpression(TypeScriptParser::RelationalExpressionContext * /*ctx*/) override { }

  virtual void enterPostIncrementExpression(TypeScriptParser::PostIncrementExpressionContext * /*ctx*/) override { }
  virtual void exitPostIncrementExpression(TypeScriptParser::PostIncrementExpressionContext * /*ctx*/) override { }

  virtual void enterYieldExpression(TypeScriptParser::YieldExpressionContext * /*ctx*/) override { }
  virtual void exitYieldExpression(TypeScriptParser::YieldExpressionContext * /*ctx*/) override { }

  virtual void enterBitNotExpression(TypeScriptParser::BitNotExpressionContext * /*ctx*/) override { }
  virtual void exitBitNotExpression(TypeScriptParser::BitNotExpressionContext * /*ctx*/) override { }

  virtual void enterNewExpression(TypeScriptParser::NewExpressionContext * /*ctx*/) override { }
  virtual void exitNewExpression(TypeScriptParser::NewExpressionContext * /*ctx*/) override { }

  virtual void enterLiteralExpression(TypeScriptParser::LiteralExpressionContext * /*ctx*/) override { }
  virtual void exitLiteralExpression(TypeScriptParser::LiteralExpressionContext * /*ctx*/) override { }

  virtual void enterArrayLiteralExpression(TypeScriptParser::ArrayLiteralExpressionContext * /*ctx*/) override { }
  virtual void exitArrayLiteralExpression(TypeScriptParser::ArrayLiteralExpressionContext * /*ctx*/) override { }

  virtual void enterMemberDotExpression(TypeScriptParser::MemberDotExpressionContext * /*ctx*/) override { }
  virtual void exitMemberDotExpression(TypeScriptParser::MemberDotExpressionContext * /*ctx*/) override { }

  virtual void enterClassExpression(TypeScriptParser::ClassExpressionContext * /*ctx*/) override { }
  virtual void exitClassExpression(TypeScriptParser::ClassExpressionContext * /*ctx*/) override { }

  virtual void enterMemberIndexExpression(TypeScriptParser::MemberIndexExpressionContext * /*ctx*/) override { }
  virtual void exitMemberIndexExpression(TypeScriptParser::MemberIndexExpressionContext * /*ctx*/) override { }

  virtual void enterIdentifierExpression(TypeScriptParser::IdentifierExpressionContext * /*ctx*/) override { }
  virtual void exitIdentifierExpression(TypeScriptParser::IdentifierExpressionContext * /*ctx*/) override { }

  virtual void enterBitAndExpression(TypeScriptParser::BitAndExpressionContext * /*ctx*/) override { }
  virtual void exitBitAndExpression(TypeScriptParser::BitAndExpressionContext * /*ctx*/) override { }

  virtual void enterBitOrExpression(TypeScriptParser::BitOrExpressionContext * /*ctx*/) override { }
  virtual void exitBitOrExpression(TypeScriptParser::BitOrExpressionContext * /*ctx*/) override { }

  virtual void enterAssignmentOperatorExpression(TypeScriptParser::AssignmentOperatorExpressionContext * /*ctx*/) override { }
  virtual void exitAssignmentOperatorExpression(TypeScriptParser::AssignmentOperatorExpressionContext * /*ctx*/) override { }

  virtual void enterVoidExpression(TypeScriptParser::VoidExpressionContext * /*ctx*/) override { }
  virtual void exitVoidExpression(TypeScriptParser::VoidExpressionContext * /*ctx*/) override { }

  virtual void enterCoalesceExpression(TypeScriptParser::CoalesceExpressionContext * /*ctx*/) override { }
  virtual void exitCoalesceExpression(TypeScriptParser::CoalesceExpressionContext * /*ctx*/) override { }

  virtual void enterAssignable(TypeScriptParser::AssignableContext * /*ctx*/) override { }
  virtual void exitAssignable(TypeScriptParser::AssignableContext * /*ctx*/) override { }

  virtual void enterFunctionDecl(TypeScriptParser::FunctionDeclContext * /*ctx*/) override { }
  virtual void exitFunctionDecl(TypeScriptParser::FunctionDeclContext * /*ctx*/) override { }

  virtual void enterAnoymousFunctionDecl(TypeScriptParser::AnoymousFunctionDeclContext * /*ctx*/) override { }
  virtual void exitAnoymousFunctionDecl(TypeScriptParser::AnoymousFunctionDeclContext * /*ctx*/) override { }

  virtual void enterArrowFunction(TypeScriptParser::ArrowFunctionContext * /*ctx*/) override { }
  virtual void exitArrowFunction(TypeScriptParser::ArrowFunctionContext * /*ctx*/) override { }

  virtual void enterArrowFunctionParameters(TypeScriptParser::ArrowFunctionParametersContext * /*ctx*/) override { }
  virtual void exitArrowFunctionParameters(TypeScriptParser::ArrowFunctionParametersContext * /*ctx*/) override { }

  virtual void enterArrowFunctionBody(TypeScriptParser::ArrowFunctionBodyContext * /*ctx*/) override { }
  virtual void exitArrowFunctionBody(TypeScriptParser::ArrowFunctionBodyContext * /*ctx*/) override { }

  virtual void enterAssignmentOperator(TypeScriptParser::AssignmentOperatorContext * /*ctx*/) override { }
  virtual void exitAssignmentOperator(TypeScriptParser::AssignmentOperatorContext * /*ctx*/) override { }

  virtual void enterLiteral(TypeScriptParser::LiteralContext * /*ctx*/) override { }
  virtual void exitLiteral(TypeScriptParser::LiteralContext * /*ctx*/) override { }

  virtual void enterNumericLiteral(TypeScriptParser::NumericLiteralContext * /*ctx*/) override { }
  virtual void exitNumericLiteral(TypeScriptParser::NumericLiteralContext * /*ctx*/) override { }

  virtual void enterBigintLiteral(TypeScriptParser::BigintLiteralContext * /*ctx*/) override { }
  virtual void exitBigintLiteral(TypeScriptParser::BigintLiteralContext * /*ctx*/) override { }

  virtual void enterIdentifierName(TypeScriptParser::IdentifierNameContext * /*ctx*/) override { }
  virtual void exitIdentifierName(TypeScriptParser::IdentifierNameContext * /*ctx*/) override { }

  virtual void enterReservedWord(TypeScriptParser::ReservedWordContext * /*ctx*/) override { }
  virtual void exitReservedWord(TypeScriptParser::ReservedWordContext * /*ctx*/) override { }

  virtual void enterKeyword(TypeScriptParser::KeywordContext * /*ctx*/) override { }
  virtual void exitKeyword(TypeScriptParser::KeywordContext * /*ctx*/) override { }

  virtual void enterGetter(TypeScriptParser::GetterContext * /*ctx*/) override { }
  virtual void exitGetter(TypeScriptParser::GetterContext * /*ctx*/) override { }

  virtual void enterSetter(TypeScriptParser::SetterContext * /*ctx*/) override { }
  virtual void exitSetter(TypeScriptParser::SetterContext * /*ctx*/) override { }

  virtual void enterEos(TypeScriptParser::EosContext * /*ctx*/) override { }
  virtual void exitEos(TypeScriptParser::EosContext * /*ctx*/) override { }


  virtual void enterEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void exitEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void visitTerminal(antlr4::tree::TerminalNode * /*node*/) override { }
  virtual void visitErrorNode(antlr4::tree::ErrorNode * /*node*/) override { }

};

