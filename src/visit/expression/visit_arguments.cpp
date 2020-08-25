#include "antlr4-runtime.h"
#include "common/error/error.h"
#include "grammar/TypeScriptParser.h"
#include "support/Any.h"
#include "tree/ParseTree.h"
#include "tser.h"
#include "utils.h"
#include "visit/visit.h"
#include "llvm/ADT/APSInt.h"
#include "llvm/IR/DerivedTypes.h"
#include "llvm/IR/Function.h"
#include "llvm/IR/Instruction.h"

using namespace tser;
using namespace std;
using namespace antlr4;
using namespace llvm;
using namespace antlr4::tree;

antlrcpp::Any ModuleVisitor::visitArgumentsExpression(TypeScriptParser::ArgumentsExpressionContext *ctx) {
  DebugPrintln("[visitArgumentsExpression] IsPreCheck: %d ; text: %s", IsPrecheckStep(), ctx->getText().data());
  Scope *scope = GetScope(ctx);

  FunctionVariableValue *func_var_value = nullptr;

  auto func_node = move(visit(ctx->singleExpression()).as<unique_ptr<NodeValue>>());
  if (func_node->IsString()) {
    func_var_value = (FunctionVariableValue *)scope->GetVariableValue(func_node->GetStringValue());
  } else if (func_node->IsLlvmValueInfo()) {
    func_var_value = func_node->GetLlvmValueInfo()->GetFunctionVariableValue();
  }

  if (IsPrecheckStep()) {
    visitArguments(ctx->arguments());
    if (func_var_value->GetReturnValue()) {
      return make_unique<NodeValue>(new LlvmValueInfo(func_var_value->GetReturnValue()->type->clone(), nullptr, false));
    } else {
      return defaultResult();
    }
  }

  // aruguments of function
  vector<Value *> all_arguments;

  /// pack parent variables argument
  bool added_parent_variables_value = false;
  if (func_var_value->scope) { // builtin functions has no scope
    Value *parent_variables_value = func_var_value->scope->PackParentVariablesToStructValue(builder);
    if (parent_variables_value) {
      all_arguments.push_back(parent_variables_value);
      added_parent_variables_value = true;
    }
  }
  if (!added_parent_variables_value && func_var_value->UsingThis()) {
    auto func_wrapper = func_node->GetLlvmValueInfo()->GetFunctionValueWrapper();
    if (func_wrapper && func_wrapper->GetThis()) {

      Value *this_value = nullptr;
      if (func_wrapper->GetThis()->ValueIsPointer()) {
        this_value = builder->CreateLoad(func_wrapper->GetThis()->value);
      } else {
        this_value = func_wrapper->GetThis()->value;
      }
      all_arguments.push_back(this_value);
    }
  }

  auto real_arguments = move(visitArguments(ctx->arguments()).as<vector<unique_ptr<NodeValue>>>());

  if (real_arguments.size() > 0) {
    for (auto &temp_node_value : real_arguments) {
      all_arguments.push_back(temp_node_value->GetLlvmValueInfo()->value);
    }
  }
  llvm::Function *func_value = (llvm::Function *)(func_var_value->value);

  Value *result_value = nullptr;

  if (all_arguments.size() > 0) {
    if (func_var_value->AutoAddVarArgs()) {
      AutoAddVarArgs(this, all_arguments, real_arguments);
    }

    result_value = builder->CreateCall(func_value, all_arguments);
  } else {
    result_value = builder->CreateCall(func_value);
  }

  return make_unique<NodeValue>(
      new LlvmValueInfo(func_var_value->GetReturnValue()->type->clone(), result_value, false));
}
