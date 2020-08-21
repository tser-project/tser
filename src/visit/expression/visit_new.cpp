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

antlrcpp::Any ModuleVisitor::visitNewExpression(TypeScriptParser::NewExpressionContext *ctx) {
  DebugPrintln("[visitNewExpression] IsPreCheck: %d ; text: %s", IsPrecheckStep(), ctx->getText().data());

  FunctionScope *scope = GetWrapFunctionScope(ctx);

  if (IsPrecheckStep()) {
    return defaultResult();
  }

  auto reference_node = move(visit(ctx->singleExpression()).as<unique_ptr<NodeValue>>());
  if (reference_node->IsString()) {
    auto reference_info = GetModuleScope()->GetReferenceInfo(reference_node->GetStringValue());

    /// alloca memery for instance
    Value *this_value = reference_info->CreateInstance(this);

    /// call default constructor
    reference_info->CallDefaultConstructor(this, this_value);

    auto type = new TypeSignInfo(VariableType::Reference, reference_info);

    /// for heap value, address is treated as 'value' not 'pointer of value'
    auto return_value = make_unique<NodeValue>(new LlvmValueInfo(type, this_value, false));

    /// call custom constructor
    auto            custom_cons = reference_info->GetCustomConstructor();
    vector<Value *> arguments;
    arguments.push_back(this_value);

    auto real_arguments = move(visitArguments(ctx->arguments()).as<vector<unique_ptr<NodeValue>>>());

    if (real_arguments.size() > 0) {
      for (auto &temp_node_value : real_arguments) {
        scope->NodeValueInitLlvmValueInfo(builder, temp_node_value.get());
        arguments.push_back(scope->LoadToRegister(builder, temp_node_value->GetLlvmValueInfo()));
      }
    }

    reference_info->CallCustomConstructor(builder, this_value, arguments);

    return return_value;
  }
  return defaultResult();
}
