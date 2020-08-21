#pragma once

#include "ffi/intrinsic.h"
#include "scope/scope.h"
#include "tser.h"
#include "visit/reference/reference.h"
#include <string>

using namespace std;

namespace tser {

class LinkFunctionConfig {

  private:
  string name = "";
  // If `auto_add_var_args`=true, compiler will auto add `length`, `VariableType*` parameter before variadic arguments,
  // to recogenize length and types of params.
  bool                auto_add_var_args = false;
  bool                is_intrinsic      = false;
  IntrinsicFunctionID intrinsic_id;

  private:
  TypeSignInfo *         return_type = nullptr;
  vector<TypeSignInfo *> arguments;
  bool                   is_var_arg = false;

  public:
  LinkFunctionConfig(string name, TypeSignInfo *return_type, vector<TypeSignInfo *> arguments, bool is_var_arg = false)
      : name(name)
      , return_type(return_type)
      , arguments(arguments)
      , is_var_arg(is_var_arg) {
  }
  LinkFunctionConfig(string name, IntrinsicFunctionID intrinsic_id, TypeSignInfo *return_type)
      : name(name)
      , is_intrinsic(true)
      , intrinsic_id(intrinsic_id)
      , return_type(return_type) {
  }
  ~LinkFunctionConfig();

  public:
  void SetIsVarArg(bool is_var_arg) {
    this->is_var_arg = is_var_arg;
  }
  string GetName() {
    return name;
  }
  TypeSignInfo *GetReturnType() {
    return return_type;
  }
  vector<TypeSignInfo *> GetArguments() {
    return arguments;
  }
  bool IsVarArg() {
    return this->is_var_arg;
  }
  void SetAutoAddVarArgs(bool auto_add_var_args) {
    this->auto_add_var_args = auto_add_var_args;
  }
  bool AutoAddVarArgs() {
    return auto_add_var_args;
  }
  bool IsIntrinsic() {
    return is_intrinsic;
  }
  IntrinsicFunctionID GetIntrinsicFunctionID() {
    return intrinsic_id;
  }
};

class ReferenceInfoConfig {
  private:
  AccessControl access_control = AccessControl::Public;
  bool          is_static      = false;
  bool          is_final       = false;
  bool          has_map_table  = false;

  public:
  ReferenceInfoConfig() {
  }

  public:
  void SetIsFinal(bool is_final) {
    this->is_final = is_final;
  }
  void SetIsStatic(bool is_static) {
    this->is_static = is_static;
  }
  void SetHasMapTable(bool has_map_table) {
    this->has_map_table = has_map_table;
  }
  bool IsStatic() {
    return this->is_static;
  }
  bool IsFinal() {
    return this->is_final;
  }
  bool HasMapTable() {
    return has_map_table;
  }
};

class ReferenceMethodConfig {

  private:
  string        name           = "";
  AccessControl access_control = AccessControl::Public;
  bool          is_static      = false;
  bool          is_final       = false;
  bool          is_const       = false;
  bool          is_async       = false;
  bool          using_this     = false;
  // If `auto_add_var_args`=true, compiler will auto add `length`, `VariableType*` parameter before variadic arguments,
  // to recogenize length and types of params.
  bool auto_add_var_args = false;

  private:
  TypeSignInfo *         return_type = nullptr;
  vector<TypeSignInfo *> arguments;
  bool                   is_var_arg = false;

  public:
  ReferenceMethodConfig(string name, TypeSignInfo *return_type, vector<TypeSignInfo *> arguments,
                        bool is_var_arg = false)
      : name(name)
      , return_type(return_type)
      , arguments(arguments)
      , is_var_arg(is_var_arg) {
  }
  ReferenceMethodConfig(string name, TypeSignInfo *return_type, bool is_var_arg = false)
      : name(name)
      , return_type(return_type)
      , is_var_arg(is_var_arg) {
  }
  ~ReferenceMethodConfig();

  public:
  void SetIsStatic(bool is_static) {
    this->is_static = is_static;
  }
  void SetIsFinal(bool is_final) {
    this->is_final = is_final;
  }
  void SetIsConst(bool is_const) {
    this->is_const = is_const;
  }
  void SetIsAsync(bool is_async) {
    this->is_async = is_async;
  }
  void SetUsingThis(bool using_this) {
    this->using_this = using_this;
  }
  void SetIsVarArg(bool is_var_arg) {
    this->is_var_arg = is_var_arg;
  }
  string GetName() {
    return name;
  }
  bool IsStatic() {
    return this->is_static;
  }
  bool IsFinal() {
    return this->is_final;
  }
  bool IsConst() {
    return this->is_const;
  }
  bool IsAsync() {
    return this->is_async;
  }
  bool UsingThis() {
    return this->using_this;
  }
  TypeSignInfo *GetReturnType() {
    return return_type;
  }
  vector<TypeSignInfo *> GetArguments() {
    return arguments;
  }
  bool IsVarArg() {
    return this->is_var_arg;
  }
  void SetAutoAddVarArgs(bool auto_add_var_args) {
    this->auto_add_var_args = auto_add_var_args;
  }
  bool AutoAddVarArgs() {
    return auto_add_var_args;
  }
};

class ReferencePropertyConfig {};

class ReferencePackageConfig {
  private:
  string               name;
  ReferenceInfoConfig *ref_info;

  private:
  map<string, ReferenceMethodConfig *>   methods;
  map<string, ReferencePropertyConfig *> properties;

  public:
  ReferencePackageConfig(string name, ReferenceInfoConfig *ref_info, map<string, ReferenceMethodConfig *> methods,
                         map<string, ReferencePropertyConfig *> properties)
      : name(name)
      , ref_info(ref_info)
      , methods(methods)
      , properties(properties) {
  }
  ReferencePackageConfig(string name, ReferenceInfoConfig *ref_info, map<string, ReferenceMethodConfig *> methods)
      : name(name)
      , ref_info(ref_info)
      , methods(methods) {
  }
  ~ReferencePackageConfig();

  public:
  string GetName() {
    return name;
  }
  ReferenceInfoConfig *GetReferenceInfoConfig() {
    return ref_info;
  }

  public:
  ReferenceMethodConfig *GetMethodConfig(string key) {
    return methods[ key ];
  }
};

void DefineConsole(TserProcess *process);
void DefineDate(TserProcess *process);

void DefineBuiltins(TserProcess *process);

}; // namespace tser