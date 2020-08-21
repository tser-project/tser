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

VariableType GetNumericLiteralType(string text, ParseTree *node) {

  /// use default type directly
  string::size_type index = text.find(".");
  if (index != text.npos) {
    return VariableType::Double;
  }
  return VariableType::Int32;
}

antlrcpp::Any ModuleVisitor::visitLiteral(TypeScriptParser::LiteralContext *ctx) {
  DebugPrintln("[visitLiteral] IsPreCheck: %d ; text: %s", IsPrecheckStep(), ctx->getText().data());

  if (IsPrecheckStep()) {
    return visitChildren(ctx);
  }

  /// null
  if (ctx->NullLiteral()) {
    return make_unique<NodeValue>(new LlvmValueInfo(new TypeSignInfo(VariableType::Null), nullptr, false));
  }

  /// number
  if (ctx->numericLiteral() || ctx->bigintLiteral()) {
    return visitChildren(ctx);
  }

  /// boolean
  if (ctx->BooleanLiteral()) {
    bool result = ctx->BooleanLiteral()->getText() == "true";
    return make_unique<NodeValue>(
        new LlvmValueInfo(new TypeSignInfo(VariableType::Boolean),
                          ConstantInt::get(llvm::Type::getInt1Ty(GetLLVMContext()), result ? 1 : 0), false));
  }

  /// string
  if (ctx->StringLiteral()) {
    string str_value = ctx->StringLiteral()->getText();
    if (str_value.size() >= 2) {
      str_value = str_value.substr(1, str_value.size() - 2);
    }
    auto value = GetModuleScope()->LoadGlobalString(this, str_value);
    return make_unique<NodeValue>(new LlvmValueInfo(new TypeSignInfo(VariableType::String), value, false));
  }
  return visitChildren(ctx);
}

antlrcpp::Any ModuleVisitor::visitNumericLiteral(TypeScriptParser::NumericLiteralContext *ctx) {
  DebugPrintln("[visitNumericLiteral] IsPreCheck: %d ; text: %s", IsPrecheckStep(), ctx->getText().data());

  if (IsPrecheckStep()) {
    return defaultResult();
  }

  string       text  = ctx->getText();
  VariableType type  = GetNumericLiteralType(text, ctx);
  auto         value = new LlvmValueInfo(new TypeSignInfo(type), false);
  value->value       = GetConstantNumber(type, GetLLVMContext(), text);
  cout << "dump:" << endl;
  value->value->dump();

  return make_unique<NodeValue>(value);
}
