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

antlrcpp::Any ModuleVisitor::visitArguments(TypeScriptParser::ArgumentsContext *ctx) {
  DebugPrintln("[visitArguments] IsPreCheck: %d ; text: %s", IsPrecheckStep(), ctx->getText().data());

  if (IsPrecheckStep()) {
    return visitChildren(ctx);
  }
  vector<unique_ptr<NodeValue>>               arguments;
  vector<TypeScriptParser::ArgumentContext *> args = ctx->argument();
  for (TypeScriptParser::ArgumentContext *arg : args) {
    arguments.push_back(move(visitArgument(arg).as<unique_ptr<NodeValue>>()));
  }
  return arguments;
}

/// visit one argument
antlrcpp::Any ModuleVisitor::visitArgument(TypeScriptParser::ArgumentContext *ctx) {

  Scope *scope = GetScope(ctx);
  if (IsPrecheckStep()) {
    return visitChildren(ctx);
  }

  /// must load value right now, for keep arguments' run order
  auto result = move(visitChildren(ctx).as<unique_ptr<NodeValue>>());
  scope->NodeValueInitLlvmValueInfo(builder, result.get());
  result->GetLlvmValueInfo()->value = scope->LoadToRegister(builder, result->GetLlvmValueInfo());
  result->GetLlvmValueInfo()->SetValueIsPointer(false);
  return make_unique<NodeValue>(result->GetLlvmValueInfo()->clone());
}

antlrcpp::Any ModuleVisitor::visitFormalParameterList(TypeScriptParser::FormalParameterListContext *ctx) {

  vector<string> arg_names;
  if (!ctx) {
    return arg_names;
  }

  DebugPrintln("[visitFormalParameterList] IsPreCheck: %d ; text: %s", IsPrecheckStep(), ctx->getText().data());

  for (auto arg : ctx->formalParameterArg()) {
    arg_names.push_back(visitFormalParameterArg(arg));
  }

  if (ctx->lastFormalParameterArg()) {
  }
  return arg_names;
}

antlrcpp::Any ModuleVisitor::visitFormalParameterArg(TypeScriptParser::FormalParameterArgContext *ctx) {
  DebugPrintln("[visitFormalParameterArg] IsPreCheck: %d ; text: %s", IsPrecheckStep(), ctx->getText().data());

  string arg_name = ctx->assignable()->getText();

  Scope *scope = GetScope(ctx);
  if (IsPrecheckStep()) {
    TypeSignInfo *type_sign = visitTypeSign(ctx->typeSign());
    auto          var_value = new VariableValue(scope, type_sign);

    scope->DefineVariable(arg_name, var_value);
    scope->CheckVariable(arg_name);
  }
  return arg_name;
}