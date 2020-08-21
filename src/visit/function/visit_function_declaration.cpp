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

antlrcpp::Any ModuleVisitor::visitFunctionDeclaration(TypeScriptParser::FunctionDeclarationContext *ctx) {

  string origin_func_name = ctx->Identifier()->getText();

  Scope *parent_scope = GetScope(ctx->parent);

  if (IsPrecheckStep()) {

    auto scope = new FunctionScope(ctx, parent_scope, origin_func_name);
    SetNewScope(ctx, scope);

    TypeSignInfo *type_sign = new TypeSignInfo(VariableType::Function);

    auto var_value   = new FunctionVariableValue(scope, type_sign);
    var_value->scope = scope;

    scope->SetFunctionVariableValue(var_value);
    parent_scope->DefineVariable(origin_func_name, var_value);
    return visitChildren(ctx);
  }

  FunctionScope *scope = GetWrapFunctionScope(ctx);
  scope->CreateParentVariablesStructType(GetLLVMContext());

  auto func_value_info = unique_ptr<LlvmValueInfo>(CreateFunction(
      "", scope, this, scope->GetParentVariablesStructType(), ctx->formalParameterList(), ctx->typeSign()));

  auto var_value   = (FunctionVariableValue *)parent_scope->GetVariableValue(origin_func_name);
  var_value->value = func_value_info->value;
  var_value->SetReturnValue(new LlvmValueInfo(func_value_info->type->clone(), nullptr));

  BasicBlock *oldBB = builder->GetInsertBlock();

  LoadFunctionArgs(this, scope, (Function *)func_value_info->value, ctx->formalParameterList());

  visitFunctionBody(ctx->functionBody());

  builder->SetInsertPoint(oldBB);
  return defaultResult();
}

antlrcpp::Any ModuleVisitor::visitFunctionBody(TypeScriptParser::FunctionBodyContext *ctx) {

  if (IsPrecheckStep()) {
    visitChildren(ctx);
    return defaultResult();
  }

  Scope *        scope      = GetScope(ctx);
  FunctionScope *func_scope = scope->GetWrapFunctionScope();

  /// create `return block` `return_value_pointer`
  if (func_scope->IsMultiReturn()) {
    auto   return_value_info = func_scope->GetFunctionVariableValue()->GetReturnValue();
    Value *return_pointer    = builder->CreateAlloca(VariableTypeToLLVMType(GetLLVMContext(), return_value_info->type));
    return_value_info->value = return_pointer;
    BasicBlock *ReturnBB     = BasicBlock::Create(GetLLVMContext(), "");
    func_scope->SetReturnBlock(ReturnBB);
  }

  visitChildren(ctx);

  if (!func_scope->HasReturnStatement()) {
    /// llvm function must have return statement
    builder->CreateRetVoid();
    return defaultResult();
  }

  if (func_scope->IsMultiReturn()) {
    auto func_value = (Function *)func_scope->GetFunctionVariableValue()->value;
    func_value->getBasicBlockList().push_back(func_scope->GetReturnBlock());
    builder->SetInsertPoint(func_scope->GetReturnBlock());

    builder->CreateRet(builder->CreateLoad(func_scope->GetFunctionVariableValue()->GetReturnValue()->value));
  }
  return defaultResult();
}