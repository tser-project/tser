#pragma once

#include "antlr4-runtime.h"
#include "grammar/TypeScriptParser.h"
#include "scope/scope.h"
#include "support/Any.h"
#include "tree/ParseTree.h"
#include "visit/class/class.h"
#include "visit/visit.h"
#include "llvm/IR/DerivedTypes.h"
#include "llvm/IR/Function.h"

using namespace tser;
using namespace std;

namespace tser {
/// get array length
template <class T> int GetArrayLen(T &array) {
  return (sizeof(array) / sizeof(array[ 0 ]));
}
}; // namespace tser

/// util functions
namespace tser {

enum class BinaryOperType {
  Unknown,
  Equals,
  NotEquals,
  LessThan,
  LessThanEquals,
  GreaterThan,
  GreaterThanEquals,
  Plus,
  Minus,
  Multiply,
  Divide,
  Modulus,
};

/// deal common part of binary oper: get left and right value, type convert, and so on
BinaryOperModel *DealBinaryParams(Scope *scope, ModuleVisitor *visitor, ParseTree *left, ParseTree *right);
BinaryOperModel *DealBinaryParams(Scope *scope, ModuleVisitor *visitor, NodeValue *left_node, NodeValue *right_node);
LlvmValueInfo *  DealBinaryOper(Scope *scope, ModuleVisitor *visitor, BinaryOperType oper_type, ParseTree *left,
                                ParseTree *right, bool is_self_assign = false);
LlvmValueInfo *  DealBinaryOper(Scope *scope, ModuleVisitor *visitor, BinaryOperType oper_type, NodeValue *left_node,
                                NodeValue *right_node, bool is_self_assign = false);

/// compare two type, including reference type comparation
bool IsSameType(TypeSignInfo *type1, TypeSignInfo *type2);

/// order: bool -> int32 -> int64 -> float -> double
TypeSignInfo * GetUpperType(TypeSignInfo *type1, TypeSignInfo *type2);
LlvmValueInfo *TypeCastToTarget(Scope *scope, IRBuilder<> *builder, TypeSignInfo *target_type,
                                LlvmValueInfo *current_value_info);

/// Get Default LLVM Value of target type
Constant *GetDefaultValue(LLVMContext &context, TypeSignInfo *type);

/// get constant of target type
Constant *   GetConstantNumber(VariableType type, LLVMContext &context, int64_t value);
Constant *   GetConstantNumber(VariableType type, LLVMContext &context, string value);
ConstantInt *GetConstantInt(LLVMContext &context, int value = 0);

/// change type to LLVM Type
Type *VariableTypeToLLVMType(LLVMContext &context, TypeSignInfo *);

/// auto bit type according to target and use case
Type *GetAutoBitType(LLVMContext &context, OriginType type);

/// if type is none
bool TypeIsNone(TypeSignInfo *);

/// memory alignment
MaybeAlign GetMaybeAlign(TypeSignInfo *);
MaybeAlign GetMaybeAlign(VariableType);

}; // namespace tser

namespace tser {
/// create function
LlvmValueInfo *CreateFunction(string class_name, FunctionScope *current_scope, ModuleVisitor *visitor,
                              StructType *                                  parent_or_this_struct_type,
                              TypeScriptParser::FormalParameterListContext *formalParameterList,
                              TypeScriptParser::TypeSignContext *           return_type_sign);

LlvmValueInfo *CreateBuiltinFunction(string class_name, string function_name, ModuleVisitor *visitor,
                                     StructType *this_struct_type, vector<TypeSignInfo *> arg_types,
                                     TypeSignInfo *return_type, bool is_var_arg);
/// generate global funciton name
string GenerateGlobalFunctionName(FunctionScope *current_scope, string module_name, string class_name);

/// get builtin function name, use c++ standart
string GetBuiltinFunctionName(string spacename, string class_name, string function_name,
                              vector<TypeSignInfo *> arguments_type, bool is_var_arg = false);

/// load function args to scope
void LoadFunctionArgs(ModuleVisitor *visitor, FunctionScope *scope, llvm::Function *func,
                      TypeScriptParser::FormalParameterListContext *formalParameterList);

void AutoAddVarArgs(ModuleVisitor *visitor, vector<Value *> &all_arguments,
                    vector<unique_ptr<NodeValue>> &real_arguments);

/// check if current return statement is last statement of function
bool IsFunctionLastReturnStatement(TypeScriptParser::ReturnStatementContext *ctx);
} // namespace tser

namespace tser {
bool ClassIsStatic(vector<TypeScriptParser::ClassControlContext *>);
bool ClassIsFinal(vector<TypeScriptParser::ClassControlContext *>);
bool PropertyIsStatic(vector<TypeScriptParser::PropertyControlContext *>);
bool PropertyIsReadonly(vector<TypeScriptParser::PropertyControlContext *>);
bool FunctionIsStatic(vector<TypeScriptParser::FunctionControlContext *>);
bool FunctionIsFinal(vector<TypeScriptParser::FunctionControlContext *>);
}; // namespace tser

namespace tser {

class ReferenceInfo;

void LoadReferenceMethodArgs(ModuleVisitor *visitor, ReferenceInfo *class_info, FunctionVariableValue *value,
                             Scope *scope, TypeScriptParser::FormalParameterListContext *formalParameterList);
}; // namespace tser

namespace tser {
namespace fsutils {
string GetPathStartFromProject(int size, string paths[]);
string GetPathStartFromCurrent(int size, string paths[]);

unique_ptr<Module> ReadFile(TserProcess *process, char *file_path, LLVMContext &context, const DataLayout &dataLayout);
} // namespace fsutils
}; // namespace tser