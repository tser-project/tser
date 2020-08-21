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

antlrcpp::Any ModuleVisitor::visitSwitchStatement(TypeScriptParser::SwitchStatementContext *ctx) {
  DebugPrintln("[visitSwitchStatement] IsPreCheck: %d", IsPrecheckStep());

  if (IsPrecheckStep()) {
    auto parent_scope = GetScope(ctx->parent);
    auto scope        = new SwitchBlockScope(ctx, parent_scope);
    SetNewScope(ctx, scope);
    return visitChildren(ctx);
  }
  auto           scope      = (SwitchBlockScope *)GetScope(ctx);
  FunctionScope *func_scope = scope->GetWrapFunctionScope();

  auto  func_value = (Function *)GetWrapFunctionScope(ctx)->GetFunctionVariableValue()->value;
  auto &block_list = func_value->getBasicBlockList();
  auto  OldBB      = builder->GetInsertBlock();

  map<int, BasicBlock *> ClauseCaseBBMap;
  int                    default_index = -1;
  auto                   case_contexts = ctx->caseBlock()->caseClause();

  /// Step 1: create default branch block and merge default block
  BasicBlock *DefaultBB = nullptr;
  for (auto &case_context : case_contexts) {
    if (dynamic_cast<TypeScriptParser::SwitchDefaultClauseContext *>(case_context)) {
      DefaultBB = BasicBlock::Create(GetLLVMContext(), "");
    }
  }

  BasicBlock *MergeBB = BasicBlock::Create(GetLLVMContext(), "");
  scope->SetTrunkBlock(MergeBB); // for return and break statement

  set<BasicBlock *> VisitedClauseCaseBBs; // used to avoid repeatedly visit of statementList of case block
  map<int, TypeScriptParser::ExpressionSequenceContext *> case_conditions;

  /// Step 2: visit cases reverse, for no statementList scenes
  for (int case_index = case_contexts.size() - 1; case_index >= 0; case_index--) {
    auto case_context = case_contexts.at(case_index);

    /// Step 1: mark if is default clause
    auto default_clause = dynamic_cast<TypeScriptParser::SwitchDefaultClauseContext *>(case_context);
    TypeScriptParser::SwitchCaseClauseContext *case_clause = nullptr; // normal case
    if (!default_clause) {
      case_clause = dynamic_cast<TypeScriptParser::SwitchCaseClauseContext *>(case_context);
    } else if (default_index == -1) {
      default_index = case_index;
    }

    /// Step 2: record statement_list
    auto statement_list = default_clause ? default_clause->statementList() : case_clause->statementList();

    /// Step 3: create or get case branch
    BasicBlock *CaseBB = nullptr;
    if (default_clause) {
      CaseBB = DefaultBB;
    } else if (statement_list) {
      CaseBB = BasicBlock::Create(GetLLVMContext(), "");
    } else {
      CaseBB = (case_index + 1 < case_contexts.size()) ? ClauseCaseBBMap[ case_index + 1 ] : nullptr;
    }
    if (!CaseBB) {
      throw SwitchCaseIllegalException("Last case cannot be empty");
    }
    ClauseCaseBBMap[ case_index ] = CaseBB;

    /// Step 4: init case by visit branch's statements (skip if multiple cases use one statementList)
    if (!VisitedClauseCaseBBs.insert(CaseBB).second) {
      continue;
    }
    builder->SetInsertPoint(CaseBB);
    visitStatementList(statement_list);

    if (!scope->CaseHasJumpedOut(case_context)) {
      if (case_index + 1 == case_contexts.size()) {
        builder->CreateBr(MergeBB);
      } else {
        builder->CreateBr(ClauseCaseBBMap[ case_index + 1 ]);
      }
    }

    /// Step 5: record conditions of case block, for used below (skip default case)
    if (case_clause) {
      case_conditions[ case_index ] = case_clause->expressionSequence();
    }
  }

  builder->SetInsertPoint(OldBB);
  auto condition_node = move(visit(ctx->expressionSequence()).as<unique_ptr<NodeValue>>());
  scope->NodeValueInitLlvmValueInfo(builder, condition_node.get());

  auto condition_value_type = condition_node->GetLlvmValueInfo()->type->type;
  bool IsConstantInt = condition_value_type == VariableType::Int32 || condition_value_type == VariableType::Int64 ||
                       condition_value_type == VariableType::Boolean;

  /// the condition value (if constant int, stay; if string or reference, use index of its' order)
  Value *condition_value = IsConstantInt ? scope->LoadToRegister(builder, condition_node->GetLlvmValueInfo()) : nullptr;

  /// Step3: visit conditions, and convert case value to ConstantInt* (use case index for case value)
  if (!IsConstantInt) {
    auto                   condition_value_ptr = builder->CreateAlloca(Type::getInt32Ty(GetLLVMContext()));
    map<int, BasicBlock *> ConWriteIndexBBMap; // save BasicBlocks of case's condition
    map<int, BasicBlock *> CondMergeBBMap;     // save merge block of each BasicBlock of case's condition

    for (int case_index = 0; case_index < ClauseCaseBBMap.size(); case_index++) {
      if (case_index == default_index) {
        continue;
      }
      auto case_condition_node = move(visit(case_conditions[ case_index ]).as<unique_ptr<NodeValue>>());

      /// Step 1: compare address of case value (for string and reference type)
      auto compare_result = unique_ptr<LlvmValueInfo>(
          DealBinaryOper(scope, this, BinaryOperType::Equals, condition_node.get(), case_condition_node.get()));

      auto ConWriteIndexBB             = BasicBlock::Create(GetLLVMContext(), "", func_value);
      auto ConMergeBB                  = BasicBlock::Create(GetLLVMContext(), "", func_value);
      ConWriteIndexBBMap[ case_index ] = ConWriteIndexBB;
      CondMergeBBMap[ case_index ]     = ConMergeBB;

      builder->CreateCondBr(compare_result->value, ConWriteIndexBB, ConMergeBB);

      /// Step 2: Write index of case to condition value
      builder->SetInsertPoint(ConWriteIndexBB);
      builder->CreateStore(GetConstantInt(GetLLVMContext(), case_index), condition_value_ptr);

      builder->CreateBr(ConMergeBB);
      builder->SetInsertPoint(ConMergeBB);
    }

    condition_value = builder->CreateLoad(condition_value_ptr);
  }

  /// Step 4 : create switch instruction
  auto switch_inst = builder->CreateSwitch(condition_value, DefaultBB ? DefaultBB : MergeBB);

  /// Step 5: insert blocks in order
  VisitedClauseCaseBBs.empty();
  for (int case_index = 0; case_index < ClauseCaseBBMap.size(); case_index++) {
    // for (auto case_item : ClauseCaseBBMap) {
    if (!VisitedClauseCaseBBs.insert(ClauseCaseBBMap[ case_index ]).second) {
      block_list.push_back(ClauseCaseBBMap[ case_index ]);
    }

    /// add to switch instruction (skip default case)
    if (case_index == default_index) {
      continue;
    }

    ConstantInt *case_condition_value = nullptr;

    if (IsConstantInt) {
      auto case_condition_node = move(visit(case_conditions[ case_index ]).as<unique_ptr<NodeValue>>());
      case_condition_value     = scope->LoadToRegisterAsConstantInt(builder, case_condition_node->GetLlvmValueInfo());
    } else {
      case_condition_value = GetConstantInt(GetLLVMContext(), case_index);
    }

    switch_inst->addCase(case_condition_value, ClauseCaseBBMap[ case_index ]);
  }

  block_list.push_back(MergeBB);
  builder->SetInsertPoint(MergeBB);

  return defaultResult();
}

antlrcpp::Any ModuleVisitor::visitCaseBlock(TypeScriptParser::CaseBlockContext *ctx) {
  return visitChildren(ctx);
}

antlrcpp::Any ModuleVisitor::visitSwitchDefaultClause(TypeScriptParser::SwitchDefaultClauseContext *ctx) {
  return visitChildren(ctx);
}

antlrcpp::Any ModuleVisitor::visitSwitchCaseClause(TypeScriptParser::SwitchCaseClauseContext *ctx) {
  return visitChildren(ctx);
}
