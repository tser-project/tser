#include "antlr4-runtime.h"
#include "common/error/error.h"
#include "grammar/TypeScriptParser.h"
#include "support/Any.h"
#include "tree/ParseTree.h"
#include "visit/visit.h"
#include "llvm/ADT/APSInt.h"
#include "llvm/IR/DerivedTypes.h"
#include "llvm/IR/Instruction.h"
#include <assert.h>

using namespace tser;
using namespace std;
using namespace antlr4;
using namespace llvm;
using namespace antlr4::tree;

antlrcpp::Any ModuleVisitor::visitTypeSign(TypeScriptParser::TypeSignContext *ctx) {
  if (!ctx) {
    return new TypeSignInfo(VariableType::None);
  }
  return visitChildren(ctx);
}

antlrcpp::Any ModuleVisitor::visitPrimaryType(TypeScriptParser::PrimaryTypeContext *ctx) {
  return visitChildren(ctx);
}

antlrcpp::Any ModuleVisitor::visitPredefinedType(TypeScriptParser::PredefinedTypeContext *ctx) {
  DebugPrintln("[visitPredefinedType] IsPreCheck: %d ; text: %s", IsPrecheckStep(), ctx->getText().data());

  VariableType type;
  if (ctx->BooleanType()) {
    type = VariableType::Boolean;
  } else if (ctx->Int32Type()) {
    type = VariableType::Int32;
  } else if (ctx->Int64Type()) {
    type = VariableType::Int64;
  } else if (ctx->FloatType()) {
    type = VariableType::Float;
  } else if (ctx->DoubleType()) {
    type = VariableType::Double;
  } else if (ctx->NumberType()) {
    /// number treated as int32
    type = VariableType::Int32;
  } else if (ctx->StringType()) {
    type = VariableType::String;
  } else if (ctx->VoidType()) {
    type = VariableType::Void;
  } else {
    type = VariableType::Any;
  }
  return new TypeSignInfo(type);
}

antlrcpp::Any ModuleVisitor::visitTypeReference(TypeScriptParser::TypeReferenceContext *ctx) {
  DebugPrintln("[visitTypeReference] IsPreCheck: %d ; text: %s", IsPrecheckStep(), ctx->getText().data());

  string type_name  = ctx->Identifier()->getText();
  auto   class_info = GetModuleScope()->GetReferenceInfo(type_name);
  return new TypeSignInfo(VariableType::Reference, class_info);
}
