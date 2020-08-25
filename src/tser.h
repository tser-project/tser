#pragma once

#include "config.h"
#include "llvm/IR/Value.h"
#include <map>
#include <set>
#include <string>

#define TSER_HAS___FORCEINLINE 1

#define TSER_HAS_ATTRIBUTE_ALWAYS_INLINE (__has_attribute(always_inline))

#if !defined(DEBUG) && TSER_HAS_ATTRIBUTE_ALWAYS_INLINE
#define TSER_INLINE inline __attribute__((always_inline))
#elif !defined(DEBUG) && TSER_HAS___FORCEINLINE
#define TSER_INLINE __forceinline
#else
#define TSER_INLINE inline
#endif

/// If target is not current machine, manual assignment TSER_TARGET_BITS
#define TSER_TARGET_BITS (8 * (int)sizeof(int *))
// #define TSER_TARGET_BITS 32

#ifdef DEBUG
static void DebugPrintln(const char *format, ...) {
  va_list argPtr;
  int     count;
  va_start(argPtr, format);
  fflush(stdout);
  std::string fm = format;
  count          = vfprintf(stderr, (fm + "\n").data(), argPtr);
  va_end(argPtr);
}
#else
static TSER_INLINE void DebugPrintln(const char *format, ...) {
}
#endif

/// size of file path's size
#define FILE_PATH_SIZE 512

using namespace std;
using namespace llvm;

namespace tser {

/// variable index; may change to 'unsigned short'
typedef unsigned int var_index;

/**
 * The step of compile
 *    : Precheck -> BuildIR -> RunningEntry
 */
enum class CompileStep {
  Precheck,     // variable improvment
  BuildIR,      // build ir of llvm
  RunningEntry, // run at entry
};

// c++ origin type
enum class OriginType {
  Long,
  Int64t, // long long
  NewParam,
  MemSet, // memset.i64/i32
};

// All type decelaration of variables
enum class VariableType : int {
  /// Boolean -> Double, must in current order, for automatic type transformation
  Boolean,
  Int32,
  Int64,
  Float,
  Double,
  String,
  Enum,
  Function,  // function
  Reference, // reference type
  Null,
  Any,
  Void,
  None, // unknown
};

class ReferenceInfo; // use for 'TypeSignInfo'
class Scope;

class TypeName {
  public:
  string spacename = "";
  string name      = "";

  public:
  TypeName(string spacename, string name)
      : spacename(spacename)
      , name(name) {
  }
};

// visit result of type sign nodes
class TypeSignInfo {
  public:
  VariableType   type;
  ReferenceInfo *reference_info  = nullptr;
  bool           is_pointer_type = false;
  TypeName *     name            = nullptr;

  public:
  TypeSignInfo(VariableType type, bool is_pointer_type = false)
      : type(type)
      , is_pointer_type(is_pointer_type) {
  }
  TypeSignInfo(VariableType type, ReferenceInfo *reference_info, bool is_pointer_type = false)
      : type(type)
      , is_pointer_type(is_pointer_type)
      , reference_info(reference_info) {
  }
  TypeSignInfo(VariableType type, TypeName *name, bool is_pointer_type = false)
      : type(type)
      , name(name)
      , is_pointer_type(is_pointer_type) {
  }
  ~TypeSignInfo() {
    reference_info = nullptr;
    if (name) {
      delete name;
    }
  }

  public:
  bool IsPointerType() {
    return is_pointer_type;
  }
  TypeSignInfo *clone() {
    return new TypeSignInfo(type, reference_info);
  }
  ReferenceInfo *GetReferenceInfo() {
    return reference_info;
  }
};

class VariableValue;
class FunctionVariableValue;
class ReferenceInfo;
class LlvmValueInfo;

class FunctionValueWrapper {
  private:
  LlvmValueInfo *this_value = nullptr;
  void *         scope      = nullptr;

  public:
  FunctionValueWrapper(LlvmValueInfo *this_value)
      : this_value(this_value) {
  }
  ~FunctionValueWrapper();

  public:
  void SetThis(LlvmValueInfo *this_value) {
    this->this_value = this_value;
  }
  LlvmValueInfo *GetThis() {
    return this->this_value;
  }
};

// Pack llvm value info, usually used for temply
class LlvmValueInfo {

  public:
  TypeSignInfo *type  = nullptr;
  Value *       value = nullptr;

  private:
  FunctionVariableValue *function_var      = nullptr;
  FunctionValueWrapper * function_wrapper  = nullptr;
  bool                   is_reference_info = false;
  bool                   value_is_pointer  = true; // class.X* is not pointer type (for it's normal-use type)

  public:
  LlvmValueInfo(TypeSignInfo *type, Value *value, bool value_is_pointer = true);
  LlvmValueInfo(TypeSignInfo *type, bool value_is_pointer = true);
  LlvmValueInfo(VariableValue *var_value, bool is_function_var = false);

  public:
  LlvmValueInfo *        clone();
  FunctionVariableValue *GetFunctionVariableValue() {
    return function_var;
  }
  void SetFunctionValueWrapper(FunctionValueWrapper *function_wrapper) {
    this->function_wrapper = function_wrapper;
  }
  FunctionValueWrapper *GetFunctionValueWrapper() {
    return function_wrapper;
  }
  void SetIsReferenceInfo(bool is_reference_info) {
    this->is_reference_info = is_reference_info;
  }
  bool IsReferenceInfo() {
    return is_reference_info;
  }
  bool ValueIsPointer() {
    return value_is_pointer;
  }
  void SetValueIsPointer(bool value_is_pointer) {
    this->value_is_pointer = value_is_pointer;
  }
  void ResetType(TypeSignInfo *type) {
    if (this->type) {
      delete this->type;
    }
    this->type = type;
  }

  public:
  ~LlvmValueInfo();
};

// Record varible value and type
class VariableValue {
  public:
  Scope *       scope = nullptr; /// src scope
  TypeSignInfo *type  = nullptr;
  Value *       value = nullptr;

  private:
  bool value_is_pointer = true;
  bool is_const         = false;

  public:
  VariableValue(Scope *scope, TypeSignInfo *type)
      : scope(scope)
      , type(type) {
  }
  VariableValue(Scope *scope, TypeSignInfo *type, Value *value, bool value_is_pointer = true)
      : scope(scope)
      , type(type)
      , value(value)
      , value_is_pointer(value_is_pointer) {
  }
  virtual ~VariableValue();

  public:
  bool IsConst() {
    return this->is_const;
  }
  void SetIsConst(bool is_const) {
    this->is_const = is_const;
  }
  bool ValueIsPointer() {
    return value_is_pointer;
  }
  void SetValueIsPointer(bool value_is_pointer) {
    this->value_is_pointer = value_is_pointer;
  }
  void ResetType(TypeSignInfo *type) {
    if (this->type) {
      delete this->type;
    }
    this->type = type;
  }
  VariableValue *clone();
};

class FunctionScope;

class FunctionVariableValue : public VariableValue {
  public:
  using VariableValue::VariableValue;

  FunctionVariableValue(Scope *scope)
      : VariableValue(scope, new TypeSignInfo(VariableType::Function)) {
  }

  private:
  bool using_this = false;
  // If `auto_add_var_args`=true, compiler will auto add `length`, `VariableType*` parameter before variadic arguments,
  // to recogenize length and types of params. Usually used for builtin functions
  bool auto_add_var_args = false;

  private:
  LlvmValueInfo *return_value = nullptr;

  public:
  virtual ~FunctionVariableValue();

  public:
  bool UsingThis() {
    return using_this;
  }
  void SetUsingThis(bool using_this) {
    this->using_this = using_this;
  }
  void SetReturnValue(LlvmValueInfo *return_value) {
    this->return_value = return_value;
  }
  void           SetReturnType(TypeSignInfo *return_type);
  LlvmValueInfo *GetReturnValue() {
    return this->return_value;
  }
  void SetAutoAddVarArgs(bool auto_add_var_args) {
    this->auto_add_var_args = auto_add_var_args;
  }
  bool AutoAddVarArgs() {
    return auto_add_var_args;
  }

  public:
  FunctionScope *scope = nullptr; // function scope;
};

// value type of visit tree
enum class NodeValueType {
  LlvmValueInfo, // llvm value
  // VariableValue, // variable
  String, // string
};

// value of visit tree
class NodeValue {
  private:
  NodeValueType  value_type;
  string         string_value = "";
  LlvmValueInfo *value_info   = nullptr;

  public:
  NodeValue(LlvmValueInfo *value_info)
      : value_type(NodeValueType::LlvmValueInfo)
      , value_info(value_info) {
    // for heap value, address is treated as 'value' not 'pointer of value'
  }
  NodeValue(string value)
      : value_type(NodeValueType::String) {
    string_value = value;
  }
  ~NodeValue() {
    string_value = "";
    if (IsLlvmValueInfo()) {
      delete value_info;
    }
    value_info = nullptr;
  }

  public:
  LlvmValueInfo *GetLlvmValueInfo() {
    return value_info;
  }
  void SetLlvmValueInfo(LlvmValueInfo *value_info) {
    this->value_info = value_info;
    value_type       = NodeValueType::LlvmValueInfo;
  }
  string GetStringValue() {
    return string_value;
  }

  public:
  virtual string ToString();

  public:
  bool IsString() {
    return value_type == NodeValueType::String;
  }
  bool IsLlvmValueInfo() {
    return value_type == NodeValueType::LlvmValueInfo;
  }
};

class ReferencePackageConfig;
class ModuleVisitor;

class GlobalVariableLoader {
  private:
  map<ModuleVisitor *, set<string>> load_cache;

  public:
  GlobalVariableLoader() {
  }
  ~GlobalVariableLoader() {
  }

  void LoadToModule(ModuleVisitor *visitor, string name);
};

class LinkFunctionConfig;

/// GlobalScope
class GlobalScope {

  private:
  map<string, ReferencePackageConfig *> classes;
  map<string, LinkFunctionConfig *>     functions;

  public:
  GlobalScope() {
  }
  ~GlobalScope();

  public:
  virtual void                    DefineReferenceInfo(ReferencePackageConfig *);
  virtual ReferencePackageConfig *GetReferenceInfo(string key);
  virtual void                    DefineFunction(LinkFunctionConfig *);
  virtual LinkFunctionConfig *    GetFunction(string key);
};

class LoaderManager;

/// process
class TserProcess {
  private:
  GlobalScope *  global_scope = nullptr;
  LoaderManager *loader_manager;

  public:
  TserProcess(GlobalScope *global_scope);
  ~TserProcess();

  public:
  GlobalScope *GetGlobalScope() {
    return global_scope;
  }

  public:
  void LoadToModule(ModuleVisitor *visitor, string name, string var_key = "");
};

/// Used for binary operation
class BinaryOperModel {
  public:
  TypeSignInfo *type  = nullptr;
  Value *       left  = nullptr;
  Value *       right = nullptr;

  private:
  bool has_float = false; // Has float value

  public:
  BinaryOperModel(TypeSignInfo *type, Value *left, Value *right)
      : type(type)
      , left(left)
      , right(right) {
  }
  ~BinaryOperModel() {
    /// don't delete type, will be used
  }

  public:
  void SetHasFloat(bool has_float) {
    this->has_float = has_float;
  }
  bool HasFloat() {
    return has_float;
  }
};
}; // namespace tser
