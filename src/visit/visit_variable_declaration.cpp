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

antlrcpp::Any ModuleVisitor::visitVariableDeclaration(TypeScriptParser::VariableDeclarationContext *ctx) {
  DebugPrintln("[visitVariableDeclaration] IsPreCheck: %d ; text: %s", IsPrecheckStep(), ctx->getText().data());

  auto   left_node = move(visitAssignable(ctx->assignable()).as<unique_ptr<NodeValue>>());
  Scope *scope     = GetScope(ctx);

  if (IsPrecheckStep()) {

    TypeSignInfo *type_sign = visitTypeSign(ctx->typeSign());

    auto var_value = new VariableValue(scope, type_sign);

    scope->DefineVariable(left_node->GetStringValue(), var_value);
    if (ctx->singleExpression()) {
      visit(ctx->singleExpression());
    }
    return defaultResult();
  }

  auto var_value = scope->GetVariableValue(left_node->GetStringValue());

  if (ctx->singleExpression()) {
    auto right_node = move(visit(ctx->singleExpression()).as<unique_ptr<NodeValue>>());
    scope->NodeValueInitLlvmValueInfo(builder, right_node.get());

    cout << "dump-2:" << endl;
    right_node->GetLlvmValueInfo()->value->dump();

    right_node->GetLlvmValueInfo()->value = scope->LoadToRegister(builder, right_node->GetLlvmValueInfo());
    right_node->GetLlvmValueInfo()->SetValueIsPointer(false);

    /// type inference
    if (TypeIsNone(var_value->type)) {
      var_value->ResetType(right_node->GetLlvmValueInfo()->type->clone());
    }

    auto new_value =
        unique_ptr<LlvmValueInfo>(TypeCastToTarget(scope, builder, var_value->type, right_node->GetLlvmValueInfo()));

    cout << "dump-3:" << endl;
    new_value->value->dump();

    scope->StoreLlvmValue(this, left_node->GetStringValue(), new_value.get());

    return defaultResult();

  } else {
    auto right_value = make_unique<LlvmValueInfo>(var_value->type->clone(), nullptr, false);
    scope->StoreLlvmValue(this, left_node->GetStringValue(), right_value.get());
    return defaultResult();
  }
}

antlrcpp::Any ModuleVisitor::visitAssignmentExpression(TypeScriptParser::AssignmentExpressionContext *ctx) {
  DebugPrintln("[visitAssignmentExpression] IsPreCheck: %d ; text: %s", IsPrecheckStep(), ctx->getText().data());

  if (IsPrecheckStep()) {
    return visitChildren(ctx);
  }
  Scope *scope      = GetScope(ctx);
  auto   left_node  = move(visit(ctx->singleExpression(0)).as<unique_ptr<NodeValue>>());
  auto   right_node = move(visit(ctx->singleExpression(1)).as<unique_ptr<NodeValue>>());

  scope->NodeValueInitLlvmValueInfo(builder, left_node.get());
  scope->NodeValueInitLlvmValueInfo(builder, right_node.get());

  right_node->GetLlvmValueInfo()->value = scope->LoadToRegister(builder, right_node->GetLlvmValueInfo());
  right_node->GetLlvmValueInfo()->SetValueIsPointer(false);

  if (TypeIsNone(left_node->GetLlvmValueInfo()->type)) {
    left_node->GetLlvmValueInfo()->ResetType(right_node->GetLlvmValueInfo()->type->clone());
  }

  auto new_value =
      TypeCastToTarget(scope, builder, left_node->GetLlvmValueInfo()->type, right_node->GetLlvmValueInfo());

  builder->CreateStore(new_value->value, left_node->GetLlvmValueInfo()->value);

  return make_unique<NodeValue>(left_node->GetLlvmValueInfo()->clone());
}