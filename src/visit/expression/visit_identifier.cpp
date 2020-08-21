#include "antlr4-runtime.h"
#include "common/error/error.h"
#include "grammar/TypeScriptParser.h"
#include "support/Any.h"
#include "tree/ParseTree.h"
#include "visit/visit.h"
#include "llvm/ADT/APSInt.h"
#include "llvm/IR/DerivedTypes.h"
#include "llvm/IR/Instruction.h"
#include <string>

using namespace tser;
using namespace std;
using namespace antlr4;
using namespace llvm;
using namespace antlr4::tree;

antlrcpp::Any ModuleVisitor::visitIdentifierExpression(TypeScriptParser::IdentifierExpressionContext *ctx) {
  DebugPrintln("[visitIdentifierExpression] IsPreCheck: %d ; text: %s", IsPrecheckStep(), ctx->getText().data());

  string key = ctx->Identifier()->getText();
  if (IsPrecheckStep()) {
    GetScope(ctx)->CheckVariable(key);
  }
  auto value = make_unique<NodeValue>(key);
  return value;
}