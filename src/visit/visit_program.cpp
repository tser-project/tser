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

antlrcpp::Any ModuleVisitor::visitProgram(TypeScriptParser::ProgramContext *ctx) {
  if (IsPrecheckStep()) {
    auto scope = new ModuleScope();
    scope->SetProcess(GetProcess());
    scope->SetModuleVisitor(this);

    SetModuleScope(scope);
    scope_manager->SetNewScope(ctx, scope);

    scope->SetFunctionVariableValue(new FunctionVariableValue(scope, new TypeSignInfo(VariableType::Function)));
    return visitChildren(ctx);
  }

  ModuleScope *scope = GetModuleScope();

  vector<Type *>  func_type_args(0);
  FunctionType *  main_func_type = FunctionType::get(Type::getInt32Ty(GetLLVMContext()), func_type_args, false);
  llvm::Function *main_func      = Function::Create(main_func_type, GlobalValue::ExternalLinkage, "main", *module);

  auto func_var_value   = scope->GetFunctionVariableValue();
  func_var_value->value = main_func;

  BasicBlock *mainBB = BasicBlock::Create(GetLLVMContext(), "", main_func);

  builder->SetInsertPoint(mainBB);

  visitChildren(ctx);

  /// return 0 in 'main' function, if succeed.
  Value *successReturn = GetConstantNumber(VariableType::Int32, GetLLVMContext(), 0);
  builder->CreateRet(successReturn);

  return defaultResult();
}