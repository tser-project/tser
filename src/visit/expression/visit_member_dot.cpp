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

antlrcpp::Any ModuleVisitor::visitMemberDotExpression(TypeScriptParser::MemberDotExpressionContext *ctx) {
  DebugPrintln("[visitMemberDotExpression] IsPreCheck: %d ; text: %s", IsPrecheckStep(), ctx->getText().data());

  Scope *scope     = GetScope(ctx);
  auto   left_node = move(visit(ctx->singleExpression()).as<unique_ptr<NodeValue>>());

  string right_id = visitIdentifierName(ctx->identifierName());

  if (IsPrecheckStep()) {

    if (left_node->IsString()) {
      scope->CheckVariable(left_node->GetStringValue());
    }

    VariableValue *right_value = nullptr;
    /// support "this" verify
    scope->NodeValueInitLlvmValueInfo(builder, left_node.get());

    auto left_value_info = left_node->GetLlvmValueInfo();
    if (left_value_info->type->type != VariableType::Reference) {
      throw TypeNotMatchException("only support ReferenceInfo");
    }
    auto ref_info = left_value_info->type->reference_info;
    ref_info->CheckVariable(scope, right_id);

    if (ref_info->IsProperty(right_id)) {
      right_value = ref_info->GetProperty(right_id);
      return make_unique<NodeValue>(new LlvmValueInfo(right_value));
    } else if (ref_info->IsMethod(right_id)) {
      right_value = ref_info->GetMethod(right_id);
      return make_unique<NodeValue>(new LlvmValueInfo(right_value, true));
    }
    throw VariableNotFoundException(right_id);
  }

  /// Need run 'NodeValueInitLlvmValueInfo' again
  scope->NodeValueInitLlvmValueInfo(builder, left_node.get());
  auto           left_value_info = left_node->GetLlvmValueInfo();
  ReferenceInfo *reference_info  = left_value_info->type->GetReferenceInfo();

  if (left_value_info->IsReferenceInfo()) {
    /// for static method and property
    if (reference_info->IsMethod(right_id)) {
      auto func_var_value = reference_info->LoadMethod(nullptr, builder, right_id);

      return make_unique<NodeValue>(new LlvmValueInfo(func_var_value, true));
    } else if (reference_info->IsProperty(right_id)) {
      auto prop_var_value = reference_info->LoadProperty(nullptr, builder, right_id);
      return make_unique<NodeValue>(new LlvmValueInfo(prop_var_value));
    }
  }

  if (left_value_info->type->type == VariableType::Reference) {
    Value *this_pointer    = scope->LoadToRegister(builder, left_value_info);
    left_value_info->value = this_pointer;
    left_value_info->SetValueIsPointer(false);
    if (reference_info->IsMethod(right_id)) {
      auto func_var_value = reference_info->LoadMethod(this_pointer, builder, right_id);
      auto result_info    = new LlvmValueInfo(func_var_value, true);
      /// Get matched this
      if (func_var_value->UsingThis()) {
        auto target_type     = make_unique<TypeSignInfo>(VariableType::Reference, func_var_value->GetReferenceInfo());
        auto this_value_info = TypeCastToTarget(scope, builder, target_type.get(), left_value_info);
        result_info->SetFunctionValueWrapper(new FunctionValueWrapper(this_value_info));
      }
      return make_unique<NodeValue>(result_info);

    } else if (reference_info->IsProperty(right_id)) {
      auto value_info   = reference_info->GetProperty(right_id);
      auto return_value = reference_info->LoadProperty(this_pointer, builder, right_id);
      return make_unique<NodeValue>(new LlvmValueInfo(return_value));
    }
  }

  return defaultResult();
}