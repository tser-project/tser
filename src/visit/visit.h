#pragma once

#include "antlr4-runtime.h"
#include "ffi/intrinsic.h"
#include "grammar/TypeScriptParser.h"
#include "grammar/TypeScriptParserBaseVisitor.h"
#include "scope/scope.h"
#include "support/Any.h"
#include "tree/ParseTree.h"
#include "visit/reference/reference.h"
#include "llvm/IR/IRBuilder.h"
#include "llvm/IR/LLVMContext.h"
#include "llvm/IR/Module.h"

using namespace tser;
using namespace std;
using namespace antlr4::tree;
using namespace llvm;

namespace tser {
class ModuleVisitor : public TypeScriptParserBaseVisitor {
  public:
  ModuleVisitor(TserProcess *, Module *, ParseTree *);
  ~ModuleVisitor();

  private:
  TserProcess *process = nullptr;

  public:
  ParseTree *  parse_tree   = nullptr;
  Module *     module       = nullptr;
  IRBuilder<> *builder      = nullptr;
  ModuleScope *module_scope = nullptr;

  private:
  ScopeManager *            scope_manager              = nullptr;
  ReferenceInfoManager *    reference_info_manager     = nullptr;
  IntrinsicFunctionManager *intrinsic_function_manager = nullptr;

  private:
  CompileStep compile_step;

  public:
  void StartPrecheck();
  void StartBuildIR();

  public:
  LLVMContext &GetLLVMContext() {
    return module->getContext();
  }
  TserProcess *GetProcess() {
    return process;
  }
  GlobalScope *GetGlobalScope() {
    return process->GetGlobalScope();
  }
  void           SetNewScope(ParseTree *, Scope *);
  Scope *        GetScope(ParseTree *);
  FunctionScope *GetWrapFunctionScope(ParseTree *);
  void           SetModuleScope(ModuleScope *_module_scope) {
    module_scope = _module_scope;
  }
  ModuleScope *GetModuleScope() {
    return module_scope;
  }

  public:
  void           SetNewReferenceInfo(ParseTree *, ReferenceInfo *);
  ReferenceInfo *GetReferenceInfo(ParseTree *);

  public:
  IntrinsicFunctionManager *GetIntrinsicFunctionManager() {
    return intrinsic_function_manager;
  }

  public:
  bool        IsPrecheckStep();
  bool        IsBuildIRStep();
  CompileStep getCompileStep() {
    return this->compile_step;
  }
  void setCompileStep(CompileStep step) {
    this->compile_step = step;
  }

  // override antlr's definition, to support unique_ptr<T> return value.
  antlrcpp::Any visitChildren(ParseTree *node) {
    antlrcpp::Any result = defaultResult();
    size_t        n      = node->children.size();
    for (size_t i = 0; i < n; i++) {
      if (!shouldVisitNextChild(node, result)) {
        break;
      }

      antlrcpp::Any childResult = node->children[ i ]->accept(this);
      result                    = move(childResult);
    }

    return result;
  }

  public:
  antlrcpp::Any visitProgram(TypeScriptParser::ProgramContext *ctx);

  antlrcpp::Any visitStatementList(TypeScriptParser::StatementListContext *ctx);

  antlrcpp::Any visitStatement(TypeScriptParser::StatementContext *ctx);

  // antlrcpp::Any visitBlock(TypeScriptParser::BlockContext *ctx);

  // antlrcpp::Any visitImportStatement(TypeScriptParser::ImportStatementContext *ctx);

  // antlrcpp::Any visitImportFromBlock(TypeScriptParser::ImportFromBlockContext *ctx);

  // antlrcpp::Any visitModuleItems(TypeScriptParser::ModuleItemsContext *ctx);

  // antlrcpp::Any visitImportDefault(TypeScriptParser::ImportDefaultContext *ctx);

  // antlrcpp::Any visitImportNamespace(TypeScriptParser::ImportNamespaceContext *ctx);

  // antlrcpp::Any visitImportFrom(TypeScriptParser::ImportFromContext *ctx);

  // antlrcpp::Any visitAliasName(TypeScriptParser::AliasNameContext *ctx);

  // antlrcpp::Any visitExportDeclaration(TypeScriptParser::ExportDeclarationContext *ctx);

  // antlrcpp::Any
  //     visitExportDefaultDeclaration(TypeScriptParser::ExportDefaultDeclarationContext *ctx);

  // antlrcpp::Any visitExportFromBlock(TypeScriptParser::ExportFromBlockContext *ctx);

  // antlrcpp::Any visitDeclaration(TypeScriptParser::DeclarationContext *ctx);

  antlrcpp::Any visitVariableStatement(TypeScriptParser::VariableStatementContext *ctx);

  antlrcpp::Any visitVariableDeclarationList(TypeScriptParser::VariableDeclarationListContext *ctx);

  antlrcpp::Any visitVariableDeclaration(TypeScriptParser::VariableDeclarationContext *ctx);

  // antlrcpp::Any visitEmptyStatement(TypeScriptParser::EmptyStatementContext *ctx);

  antlrcpp::Any visitExpressionStatement(TypeScriptParser::ExpressionStatementContext *ctx);

  antlrcpp::Any visitIfStatement(TypeScriptParser::IfStatementContext *ctx);

  antlrcpp::Any visitDoStatement(TypeScriptParser::DoStatementContext *ctx);

  antlrcpp::Any visitWhileStatement(TypeScriptParser::WhileStatementContext *ctx);

  antlrcpp::Any visitForStatement(TypeScriptParser::ForStatementContext *ctx);

  antlrcpp::Any visitForInitialization(TypeScriptParser::ForInitializationContext *ctx);

  antlrcpp::Any visitForCondition(TypeScriptParser::ForConditionContext *ctx);

  // antlrcpp::Any visitForInStatement(TypeScriptParser::ForInStatementContext *ctx);

  // antlrcpp::Any visitForOfStatement(TypeScriptParser::ForOfStatementContext *ctx);

  antlrcpp::Any visitVarModifier(TypeScriptParser::VarModifierContext *ctx);

  antlrcpp::Any visitContinueStatement(TypeScriptParser::ContinueStatementContext *ctx);

  antlrcpp::Any visitBreakStatement(TypeScriptParser::BreakStatementContext *ctx);

  antlrcpp::Any visitReturnStatement(TypeScriptParser::ReturnStatementContext *ctx);

  // antlrcpp::Any visitYieldStatement(TypeScriptParser::YieldStatementContext *ctx);

  // antlrcpp::Any visitWithStatement(TypeScriptParser::WithStatementContext *ctx);

  antlrcpp::Any visitSwitchStatement(TypeScriptParser::SwitchStatementContext *context);

  antlrcpp::Any visitCaseBlock(TypeScriptParser::CaseBlockContext *context);

  antlrcpp::Any visitSwitchDefaultClause(TypeScriptParser::SwitchDefaultClauseContext *context);

  antlrcpp::Any visitSwitchCaseClause(TypeScriptParser::SwitchCaseClauseContext *context);

  // antlrcpp::Any visitLabelledStatement(TypeScriptParser::LabelledStatementContext *ctx);

  // antlrcpp::Any visitThrowStatement(TypeScriptParser::ThrowStatementContext *ctx);

  // antlrcpp::Any visitTryStatement(TypeScriptParser::TryStatementContext *ctx);

  // antlrcpp::Any visitCatchProduction(TypeScriptParser::CatchProductionContext *ctx);

  // antlrcpp::Any visitFinallyProduction(TypeScriptParser::FinallyProductionContext *ctx);

  // antlrcpp::Any visitDebuggerStatement(TypeScriptParser::DebuggerStatementContext *ctx);

  antlrcpp::Any visitFunctionDeclaration(TypeScriptParser::FunctionDeclarationContext *ctx);

  antlrcpp::Any visitFormalParameterList(TypeScriptParser::FormalParameterListContext *ctx);

  antlrcpp::Any visitFormalParameterArg(TypeScriptParser::FormalParameterArgContext *ctx);

  antlrcpp::Any visitFunctionBody(TypeScriptParser::FunctionBodyContext *ctx);

  /// class definition
  antlrcpp::Any visitClassDeclaration(TypeScriptParser::ClassDeclarationContext *ctx);

  antlrcpp::Any visitClassTail(TypeScriptParser::ClassTailContext *ctx);

  antlrcpp::Any visitConstructorDefinition(TypeScriptParser::ConstructorDefinitionContext *context);

  antlrcpp::Any visitClassPropertyDefinition(TypeScriptParser::ClassPropertyDefinitionContext *ctx);

  antlrcpp::Any visitPropertyName(TypeScriptParser::PropertyNameContext *ctx);

  antlrcpp::Any visitNormalMethodDefinition(TypeScriptParser::NormalMethodDefinitionContext *ctx);

  antlrcpp::Any visitGetterMethodDefinition(TypeScriptParser::GetterMethodDefinitionContext *ctx);

  antlrcpp::Any visitSetterMethodDefinition(TypeScriptParser::SetterMethodDefinitionContext *ctx);

  antlrcpp::Any visitAccessControl(TypeScriptParser::AccessControlContext *context);

  antlrcpp::Any visitTypeReference(TypeScriptParser::TypeReferenceContext *ctx);

  // antlrcpp::Any visitArrayLiteral(TypeScriptParser::ArrayLiteralContext *ctx);

  // antlrcpp::Any visitElementList(TypeScriptParser::ElementListContext *ctx);

  // antlrcpp::Any visitArrayElement(TypeScriptParser::ArrayElementContext *ctx);

  // antlrcpp::Any visitObjectLiteral(TypeScriptParser::ObjectLiteralContext *ctx);

  // antlrcpp::Any
  //     visitPropertyExpressionAssignment(TypeScriptParser::PropertyExpressionAssignmentContext
  //     *ctx);

  // antlrcpp::Any visitComputedPropertyExpressionAssignment(
  //     TypeScriptParser::ComputedPropertyExpressionAssignmentContext *ctx);

  // antlrcpp::Any visitFunctionProperty(TypeScriptParser::FunctionPropertyContext *ctx);

  // antlrcpp::Any visitPropertyGetter(TypeScriptParser::PropertyGetterContext *ctx);

  // antlrcpp::Any visitPropertySetter(TypeScriptParser::PropertySetterContext *ctx);

  // antlrcpp::Any visitPropertyShorthand(TypeScriptParser::PropertyShorthandContext *ctx);

  antlrcpp::Any visitArguments(TypeScriptParser::ArgumentsContext *ctx);

  antlrcpp::Any visitArgument(TypeScriptParser::ArgumentContext *ctx);

  antlrcpp::Any visitExpressionSequence(TypeScriptParser::ExpressionSequenceContext *ctx);

  // antlrcpp::Any
  //     visitTemplateStringExpression(TypeScriptParser::TemplateStringExpressionContext *ctx);

  antlrcpp::Any visitTernaryExpression(TypeScriptParser::TernaryExpressionContext *ctx);

  antlrcpp::Any visitLogicalAndExpression(TypeScriptParser::LogicalAndExpressionContext *ctx);

  antlrcpp::Any visitLogicalOrExpression(TypeScriptParser::LogicalOrExpressionContext *ctx);

  // antlrcpp::Any visitPowerExpression(TypeScriptParser::PowerExpressionContext *ctx);

  // antlrcpp::Any visitObjectLiteralExpression(TypeScriptParser::ObjectLiteralExpressionContext *ctx);

  // antlrcpp::Any visitMetaExpression(TypeScriptParser::MetaExpressionContext *ctx);

  // antlrcpp::Any visitInExpression(TypeScriptParser::InExpressionContext *ctx);

  antlrcpp::Any visitNotExpression(TypeScriptParser::NotExpressionContext *ctx);

  antlrcpp::Any visitPreIncrementExpression(TypeScriptParser::PreIncrementExpressionContext *ctx);

  antlrcpp::Any visitPreDecreaseExpression(TypeScriptParser::PreDecreaseExpressionContext *ctx);

  antlrcpp::Any visitPostIncrementExpression(TypeScriptParser::PostIncrementExpressionContext *ctx);

  antlrcpp::Any visitPostDecreaseExpression(TypeScriptParser::PostDecreaseExpressionContext *ctx);

  antlrcpp::Any visitArgumentsExpression(TypeScriptParser::ArgumentsExpressionContext *ctx);

  // antlrcpp::Any visitAwaitExpression(TypeScriptParser::AwaitExpressionContext *ctx);

  antlrcpp::Any visitThisExpression(TypeScriptParser::ThisExpressionContext *ctx);

  // antlrcpp::Any visitFunctionExpression(TypeScriptParser::FunctionExpressionContext *ctx);

  // antlrcpp::Any visitUnaryMinusExpression(TypeScriptParser::UnaryMinusExpressionContext *ctx);

  antlrcpp::Any visitAssignmentExpression(TypeScriptParser::AssignmentExpressionContext *ctx);

  // antlrcpp::Any visitTypeofExpression(TypeScriptParser::TypeofExpressionContext *ctx);

  // antlrcpp::Any visitInstanceofExpression(TypeScriptParser::InstanceofExpressionContext *ctx);

  // antlrcpp::Any visitUnaryPlusExpression(TypeScriptParser::UnaryPlusExpressionContext *ctx);

  // antlrcpp::Any visitDeleteExpression(TypeScriptParser::DeleteExpressionContext *ctx);

  // antlrcpp::Any visitImportExpression(TypeScriptParser::ImportExpressionContext *ctx);

  antlrcpp::Any visitEqualityExpression(TypeScriptParser::EqualityExpressionContext *ctx);

  // antlrcpp::Any visitBitXOrExpression(TypeScriptParser::BitXOrExpressionContext *ctx);

  // antlrcpp::Any visitSuperExpression(TypeScriptParser::SuperExpressionContext *ctx);

  antlrcpp::Any visitMultiplicativeExpression(TypeScriptParser::MultiplicativeExpressionContext *ctx);

  antlrcpp::Any visitAdditiveExpression(TypeScriptParser::AdditiveExpressionContext *ctx);

  antlrcpp::Any visitIdentifierExpression(TypeScriptParser::IdentifierExpressionContext *ctx);

  // antlrcpp::Any visitBitShiftExpression(TypeScriptParser::BitShiftExpressionContext *ctx);

  antlrcpp::Any visitParenthesizedExpression(TypeScriptParser::ParenthesizedExpressionContext *ctx);

  antlrcpp::Any visitRelationalExpression(TypeScriptParser::RelationalExpressionContext *ctx);

  // antlrcpp::Any visitYieldExpression(TypeScriptParser::YieldExpressionContext *ctx);

  // antlrcpp::Any visitBitNotExpression(TypeScriptParser::BitNotExpressionContext *ctx);

  antlrcpp::Any visitNewExpression(TypeScriptParser::NewExpressionContext *ctx);

  antlrcpp::Any visitLiteralExpression(TypeScriptParser::LiteralExpressionContext *ctx);

  // antlrcpp::Any visitArrayLiteralExpression(TypeScriptParser::ArrayLiteralExpressionContext
  // *ctx);

  antlrcpp::Any visitMemberDotExpression(TypeScriptParser::MemberDotExpressionContext *ctx);

  // antlrcpp::Any visitClassExpression(TypeScriptParser::ClassExpressionContext *ctx);

  // antlrcpp::Any visitMemberIndexExpression(TypeScriptParser::MemberIndexExpressionContext *ctx);

  // antlrcpp::Any visitIdentifierExpression(TypeScriptParser::IdentifierExpressionContext *ctx);

  // antlrcpp::Any visitBitAndExpression(TypeScriptParser::BitAndExpressionContext *ctx);

  // antlrcpp::Any visitBitOrExpression(TypeScriptParser::BitOrExpressionContext *ctx);

  antlrcpp::Any visitAssignmentOperatorExpression(TypeScriptParser::AssignmentOperatorExpressionContext *ctx);

  // antlrcpp::Any visitVoidExpression(TypeScriptParser::VoidExpressionContext *ctx);

  // antlrcpp::Any visitCoalesceExpression(TypeScriptParser::CoalesceExpressionContext *ctx);

  antlrcpp::Any visitAssignable(TypeScriptParser::AssignableContext *ctx);

  // antlrcpp::Any visitFunctionDecl(TypeScriptParser::FunctionDeclContext *ctx);

  // antlrcpp::Any visitAnoymousFunctionDecl(TypeScriptParser::AnoymousFunctionDeclContext *ctx);

  // antlrcpp::Any visitArrowFunction(TypeScriptParser::ArrowFunctionContext *ctx);

  // antlrcpp::Any visitArrowFunctionParameters(TypeScriptParser::ArrowFunctionParametersContext
  // *ctx);

  // antlrcpp::Any visitArrowFunctionBody(TypeScriptParser::ArrowFunctionBodyContext *ctx);

  // antlrcpp::Any visitAssignmentOperator(TypeScriptParser::AssignmentOperatorContext *ctx);

  antlrcpp::Any visitTypeSign(TypeScriptParser::TypeSignContext *ctx);

  antlrcpp::Any visitPrimaryType(TypeScriptParser::PrimaryTypeContext *ctx);

  antlrcpp::Any visitPredefinedType(TypeScriptParser::PredefinedTypeContext *ctx);

  antlrcpp::Any visitLiteral(TypeScriptParser::LiteralContext *ctx);

  antlrcpp::Any visitNumericLiteral(TypeScriptParser::NumericLiteralContext *ctx);

  // antlrcpp::Any visitBigintLiteral(TypeScriptParser::BigintLiteralContext *ctx);

  antlrcpp::Any visitIdentifierName(TypeScriptParser::IdentifierNameContext *ctx);

  antlrcpp::Any visitReservedWord(TypeScriptParser::ReservedWordContext *ctx);

  antlrcpp::Any visitKeyword(TypeScriptParser::KeywordContext *ctx);

  antlrcpp::Any visitGetter(TypeScriptParser::GetterContext *ctx);

  antlrcpp::Any visitSetter(TypeScriptParser::SetterContext *ctx);

  antlrcpp::Any visitEos(TypeScriptParser::EosContext *ctx);

  // antlrcpp::Any visitSingleExpression(TypeScriptParser::SingleExpressionContext *ctx);

  // antlrcpp::Any visit(ParseTree *tree) = 0;

  // antlrcpp::Any visitChildren(ParseTree *node) = 0;

  // antlrcpp::Any visitTerminal(TerminalNode *node) = 0;

  // antlrcpp::Any visitErrorNode(ErrorNode *node) = 0;
};
}; // namespace tser
