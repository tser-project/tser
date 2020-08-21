#pragma once

#include "grammar/TypeScriptLexer.h"
#include "grammar/TypeScriptParser.h"
#include "tser.h"
#include "llvm/IR/Constant.h"
#include "llvm/IR/DerivedTypes.h"
#include "llvm/IR/Function.h"
#include "llvm/IR/IRBuilder.h"
#include "llvm/IR/Instruction.h"
#include "llvm/IR/LLVMContext.h"
#include "llvm/IR/Value.h"
#include <list>
#include <map>
#include <string>

using namespace std;
using namespace antlr4;
using namespace antlr4::tree;
using namespace llvm;

namespace tser {

class Scope;
class FunctionScope;
class ModuleScope;
class BlockScope;
class ModuleVisitor;

enum class ScopeType {
  // Expression, // delay
  Block,
  Function,
  // File,   // not support
  Module,
  Global,
};

// The scope of runtime
class Scope {
  public:
  Scope(ParseTree *node, ScopeType type, Scope *parent_scope)
      : node(node)
      , type(type)
      , parent_scope(parent_scope){};
  virtual ~Scope();

  private:
  ParseTree *  node         = nullptr;
  Scope *      parent_scope = nullptr;
  ModuleScope *module_scope = nullptr;

  // Variables of scope
  public:
  const ScopeType              type;
  map<string, VariableValue *> self_variables; // self scope variables, includes arguments of function

  public:
  ParseTree *GetTreeNode() {
    return node;
  }
  ModuleScope *GetModuleScope();
  Scope *      GetParentScope() {
    return parent_scope;
  }
  virtual Scope *        FindTagetScope(string key);
  virtual FunctionScope *GetParentFunctionScope();
  virtual FunctionScope *GetWrapFunctionScope();
  virtual BlockScope *   GetWrapLoopBlockScope(string name = "");

  public:
  virtual VariableValue *CheckVariable(string key);
  virtual void           DefineVariable(string key, VariableValue *value);
  virtual VariableValue *GetVariableValue(string key);

  public:
  virtual Value *        StoreLlvmValue(ModuleVisitor *, string key, LlvmValueInfo *);
  virtual Value *        LoadToRegister(IRBuilder<> *builder, LlvmValueInfo *llvm_value_info);
  virtual ConstantInt *  LoadToRegisterAsConstantInt(IRBuilder<> *builder, LlvmValueInfo *llvm_value_info);
  virtual void           NodeValueInitLlvmValueInfo(IRBuilder<> *builder, NodeValue *nodeValue);
  virtual LlvmValueInfo *LoadAsLlvmValueInfo(IRBuilder<> *builder, string key) = 0;

  public:
  virtual bool IsModule() {
    return type == ScopeType::Module;
  };
  virtual bool IsFunction() {
    return type == ScopeType::Function || type == ScopeType::Module;
  };
  virtual bool IsBlock() {
    return type == ScopeType::Block;
  };
  virtual bool IsClassMethod() {
    return false;
  };
};

class FunctionScope : public Scope {

  private:                                    // for basic
  string                 name           = ""; // correspond function name
  FunctionVariableValue *func_var_value = nullptr;

  private:                                             // for scope chain
  vector<string>               parent_variables_queue; // use to pack `struct` of parent variables
  map<string, var_index>       parent_variables_queue_index;
  map<string, VariableValue *> parent_variable_cache;
  llvm::StructType *           parent_variables_struct_type  = nullptr;
  llvm::Value *                parent_variables_struct_value = nullptr;

  private:                                  // for return statement
  bool        has_branch           = false; // function has branch(if switch for while...)
  bool        has_return_statement = false;
  bool        is_multi_return      = false;
  BasicBlock *return_block         = nullptr;

  public:
  FunctionScope(ParseTree *node, Scope *scope, string name)
      : name(name)
      , Scope(node, ScopeType::Function, scope) {
  }
  FunctionScope(ParseTree *node, ScopeType type, string name) // for ModuleScope
      : name(name)
      , Scope(node, type, nullptr) {
  }

  public:
  virtual VariableValue *CheckVariable(string key);
  virtual LlvmValueInfo *LoadAsLlvmValueInfo(IRBuilder<> *builder, string key);

  public:
  virtual void   CreateParentVariablesStructType(LLVMContext &context);
  virtual Value *PackParentVariablesToStructValue(IRBuilder<> *builder);

  public:
  void SetFunctionVariableValue(FunctionVariableValue *func_var_value) {
    this->func_var_value = func_var_value;
  }
  FunctionVariableValue *GetFunctionVariableValue() {
    return func_var_value;
  }
  void SetReturnBlock(BasicBlock *return_block) {
    this->return_block = return_block;
  }
  BasicBlock *GetReturnBlock() {
    return return_block;
  }

  public:
  string GetName() {
    return name;
  }
  bool HasParentVariablesQueue() {
    return parent_variables_queue.size() > 0;
  }
  StructType *GetParentVariablesStructType() {
    return parent_variables_struct_type;
  }
  void SetParentVariablesStructValue(Value *value) {
    parent_variables_struct_value = value;
  }
  Value *GetParentVariablesStructValue(Value *value) {
    return parent_variables_struct_value;
  }
  void SetHasBranch(bool has_branch) {
    this->has_branch = has_branch;
  }
  bool HasBranch() {
    return this->has_branch;
  }

  public:
  void SetHasReturnStatement(bool has) {
    has_return_statement = has;
  }
  bool HasReturnStatement() {
    return has_return_statement;
  }
  void SetIsMultiReturn(bool is_multi_return) {
    this->is_multi_return = is_multi_return;
  }
  bool IsMultiReturn() {
    return this->is_multi_return;
  }
};

class ClassMethodScope : public FunctionScope {
  public:
  virtual bool IsClassMethod() {
    return true;
  };
};

class ModuleScope : public FunctionScope {

  private:
  TserProcess *                 process = nullptr;
  ModuleVisitor *               visitor = nullptr;
  map<string, GlobalVariable *> global_string;

  public:
  ModuleScope()
      : FunctionScope(nullptr, ScopeType::Module, "main") {
  }
  ModuleScope(ScopeType type)
      : FunctionScope(nullptr, type, "") {
  }

  public:
  virtual VariableValue *CheckVariable(string key);
  virtual Value *        StoreLlvmValue(ModuleVisitor *, string key, LlvmValueInfo *);
  virtual LlvmValueInfo *LoadAsLlvmValueInfo(IRBuilder<> *builder, string key);

  private:
  map<string, ReferenceInfo *> reference_infos;

  public:
  virtual void           CheckReferenceInfo(string name);
  virtual void           DefineReferenceInfo(string name, ReferenceInfo *);
  virtual ReferenceInfo *GetReferenceInfo(string name);

  public:
  void SetModuleVisitor(ModuleVisitor *visitor) {
    this->visitor = visitor;
  }
  ModuleVisitor *GetModuleVisitor() {
    return visitor;
  }
  void SetProcess(TserProcess *process) {
    this->process = process;
  }
  TserProcess *GetProcess() {
    return process;
  }
  GlobalScope *GetGlobalScope() {
    return this->process->GetGlobalScope();
  }
  Value *LoadGlobalString(ModuleVisitor *visitor, string key, bool create_if_null = true);
};

enum class BlockType {
  If,
  For,
  While,
  Do,
  Switch,
};

class BlockScope : public Scope {
  protected:
  string    loop_name = "";
  BlockType block_type;
  bool      has_jumped_out = false; // if has jumped out to other branch

  private:
  /// for: break continue statement in (`for` `while`)
  BasicBlock *trunk_block         = nullptr; // always be merge branch, which to jump to when finished
  BasicBlock *condition_block     = nullptr;
  BasicBlock *continue_jump_block = nullptr;

  public:
  BlockScope(ParseTree *node, BlockType block_type, Scope *parent_scope)
      : block_type(block_type)
      , Scope(node, ScopeType::Block, parent_scope) {
  }
  BlockScope(ParseTree *node, BlockType block_type, Scope *parent_scope, string loop_name)
      : block_type(block_type)
      , loop_name(loop_name)
      , Scope(node, ScopeType::Block, parent_scope) {
  }

  public:
  virtual void SetHasJumpedOut(bool has_jumped_out, ParseTree *node) {
    this->has_jumped_out = has_jumped_out;
  }
  bool HasJumpedOut() {
    return has_jumped_out;
  }
  void SetTrunkBlock(BasicBlock *trunk_block) {
    this->trunk_block = trunk_block;
  }
  BasicBlock *GetTrunkBlock() {
    return trunk_block;
  }
  void SetConditionBlock(BasicBlock *condition_block) {
    this->condition_block = condition_block;
  }
  BasicBlock *GetConditionBlock() {
    return condition_block;
  }
  void SetContinueJumpBlock(BasicBlock *continue_jump_block) {
    this->continue_jump_block = continue_jump_block;
  }
  BasicBlock *GetContinueJumpBlock() {
    return continue_jump_block;
  }

  public:
  bool IsLoop() {
    return block_type == BlockType::For || block_type == BlockType::While || block_type == BlockType::Do ||
           block_type == BlockType::Switch;
  }
  string GetBlockLoopName() {
    return loop_name;
  }

  public:
  virtual VariableValue *CheckVariable(string key);
  virtual LlvmValueInfo *LoadAsLlvmValueInfo(IRBuilder<> *builder, string key);
};

/// SwitchBlockScope
class SwitchBlockScope : public BlockScope {

  public:
  SwitchBlockScope(ParseTree *node, Scope *parent_scope)
      : BlockScope(node, BlockType::Switch, parent_scope) {
  }
  SwitchBlockScope(ParseTree *node, Scope *parent_scope, string loop_name)
      : BlockScope(node, BlockType::Switch, parent_scope, loop_name) {
  }

  private:
  map<TypeScriptParser::CaseClauseContext *, bool> case_has_jumped_out;

  public:
  void SetHasJumpedOut(bool has_jumped_out, ParseTree *node);
  bool HasJumpedOut() {
    return has_jumped_out;
  }
  bool CaseHasJumpedOut(TypeScriptParser::CaseClauseContext *node) {
    if (case_has_jumped_out.count(node) == 0) {
      return false;
    }
    return case_has_jumped_out[ node ];
  }
};

/**
 * The scope manager, connect `ParseTree` and `Scope`
 * Each module will have one instance of EvnManager
 */
class ScopeManager {

  public:
  ParseTreeProperty<Scope *> *tree_scope = nullptr;

  private:
  list<Scope *> scope_list;

  public:
  ScopeManager();
  ~ScopeManager();

  public:
  Scope *GetScope(ParseTree *node);
  void   SetNewScope(ParseTree *node, Scope *scope);
  void   RemoveAllScopes();
};

} // namespace tser