#include "antlr4-runtime.h"
#include "common/error/error.h"
#include "grammar/TypeScriptParser.h"
#include "support/Any.h"
#include "tree/ParseTree.h"
#include "visit/visit.h"
#include "llvm/IR/IRBuilder.h"
#include "llvm/IR/Instruction.h"
#include "llvm/IR/LLVMContext.h"

using namespace tser;
using namespace std;
using namespace antlr4;
using namespace antlr4::tree;
using namespace llvm;

ModuleVisitor::ModuleVisitor(TserProcess *process, Module *module, ParseTree *tree)
    : process(process)
    , module(module)
    , parse_tree(tree) {
  this->builder                    = new IRBuilder<>(module->getContext());
  this->scope_manager              = new ScopeManager();
  this->reference_info_manager     = new ReferenceInfoManager();
  this->intrinsic_function_manager = new IntrinsicFunctionManager(this->module);
}

bool ModuleVisitor::IsPrecheckStep() {
  return this->compile_step == CompileStep::Precheck;
}

bool ModuleVisitor::IsBuildIRStep() {
  return this->compile_step == CompileStep::BuildIR;
}

void ModuleVisitor::StartPrecheck() {
  this->setCompileStep(CompileStep::Precheck);
  this->visit(parse_tree);
}

void ModuleVisitor::StartBuildIR() {
  this->setCompileStep(CompileStep::BuildIR);
  this->visit(parse_tree);
}

void ModuleVisitor::SetNewScope(ParseTree *node, Scope *scope) {
  scope_manager->SetNewScope(node, scope);
}

Scope *ModuleVisitor::GetScope(ParseTree *node) {
  return scope_manager->GetScope(node);
}
FunctionScope *ModuleVisitor::GetWrapFunctionScope(ParseTree *node) {
  return GetScope(node)->GetWrapFunctionScope();
}
void ModuleVisitor::SetNewReferenceInfo(ParseTree *node, ReferenceInfo *reference_info) {
  reference_info_manager->SetNewReferenceInfo(node, reference_info);
}

ReferenceInfo *ModuleVisitor::GetReferenceInfo(ParseTree *node) {
  return reference_info_manager->GetReferenceInfo(node);
}

ModuleVisitor::~ModuleVisitor() {
  this->process    = nullptr;
  this->parse_tree = nullptr;
  delete this->builder;
  delete this->scope_manager;
  delete this->reference_info_manager;
  delete this->intrinsic_function_manager;
  this->builder                    = nullptr;
  this->scope_manager              = nullptr;
  this->reference_info_manager     = nullptr;
  this->intrinsic_function_manager = nullptr;
  this->module                     = nullptr;
}