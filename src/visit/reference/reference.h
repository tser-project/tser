#pragma once

#include "scope/scope.h"
#include "tser.h"
#include <map>
#include <string>

namespace tser {
enum class ReferenceType {
  Class,
  Object,
  TypeDefine,
  Enum,
};

enum AccessControl {
  Public,
  Protected,
  Private,
};

class ReferenceInfo;

class ReferencePropertyValue : public tser::VariableValue {
  public:
  using VariableValue::VariableValue;

  private:
  ParseTree *tree_node = nullptr;

  private:
  AccessControl access_control;
  bool          is_static = false;
  bool          is_final  = false;

  public:
  ReferencePropertyValue *cloneWithoutValue() {
    auto obj   = new ReferencePropertyValue(scope, type->clone());
    obj->scope = this->scope;
    obj->SetIsStatic(this->IsStatic());
    obj->SetIsFinal(this->IsFinal());
    obj->SetIsConst(this->IsConst());
    return obj;
  }

  public:
  bool IsStatic() {
    return this->is_static;
  }
  void SetIsStatic(bool is_static) {
    this->is_static = is_static;
  }
  bool IsFinal() {
    return this->is_final;
  }
  void SetIsFinal(bool is_final) {
    this->is_final = is_final;
  }
  AccessControl GetAccessControl() {
    return access_control;
  }
  void SetAccessControl(AccessControl access_control) {
    this->access_control = access_control;
  }
  ParseTree *GetTreeNode() {
    return tree_node;
  }
  void SetTreeNode(ParseTree *node) {
    this->tree_node = node;
  }
};

class ReferenceMethodValue : public FunctionVariableValue {
  public:
  using FunctionVariableValue::FunctionVariableValue;

  private:
  ReferenceInfo *reference_info = nullptr;

  private:
  AccessControl access_control;
  bool          is_static = false;
  bool          is_final  = false;
  bool          is_async  = false;

  public:
  ReferenceMethodValue *cloneWithoutValue() {
    auto obj   = new ReferenceMethodValue(scope, type->clone());
    obj->scope = this->scope;
    obj->SetIsStatic(this->IsStatic());
    obj->SetIsFinal(this->IsFinal());
    obj->SetIsAsync(this->IsAsync());
    obj->SetReferenceInfo(this->GetReferenceInfo());
    obj->SetIsConst(this->IsConst());
    obj->SetUsingThis(this->UsingThis());
    obj->SetReturnValue(
        new LlvmValueInfo(this->GetReturnValue()->type->clone(), this->GetReturnValue()->ValueIsPointer()));
    return obj;
  }

  public:
  ReferenceInfo *GetReferenceInfo() {
    return reference_info;
  }
  void SetReferenceInfo(ReferenceInfo *reference_info) {
    this->reference_info = reference_info;
  }
  bool IsStatic() {
    return this->is_static;
  }
  void SetIsStatic(bool is_static) {
    this->is_static = is_static;
  }
  bool IsFinal() {
    return this->is_final;
  }
  void SetIsFinal(bool is_final) {
    this->is_final = is_final;
  }
  bool IsAsync() {
    return this->is_async;
  }
  void SetIsAsync(bool is_async) {
    this->is_async = is_async;
  }
  AccessControl GetAccessControl() {
    return access_control;
  }
  void SetAccessControl(AccessControl access_control) {
    this->access_control = access_control;
  }
};

class ModuleVisitor;

class ReferenceInfo {
  public:
  ReferenceType type;

  protected:
  string       name;
  const string DEFAULT_CONSTRUCTOR_KEY = "constructor.default";

  public:
  ReferenceInfo(ReferenceType type, string name)
      : type(type)
      , name(name) {
  }
  virtual ~ReferenceInfo();

  protected:
  map<string, ReferencePropertyValue *> properties;
  vector<string>                        property_queue; // no parent's properties, no static properties
  map<string, var_index>                property_queue_index;

  protected:
  map<string, ReferenceMethodValue *> methods;
  vector<string>                      method_queue;

  public:
  virtual void                    CheckVariable(Scope *scope, string key);
  virtual void                    DefineProperty(string key, ReferencePropertyValue *);
  virtual void                    DefineMethod(string key, ReferenceMethodValue *);
  virtual bool                    IsMethod(string key);
  virtual bool                    IsProperty(string key);
  virtual ReferenceMethodValue *  GetMethod(string key);
  virtual ReferencePropertyValue *GetProperty(string key);

  public:
  virtual ReferencePropertyValue *LoadProperty(Value *this_value, IRBuilder<> *builder, string key);
  virtual ReferenceMethodValue *  LoadMethod(Value *this_pointer, IRBuilder<> *builder, string key);

  protected:
  StructType *reference_struct_type = nullptr;

  public:
  virtual void CreateVariablesStructType(ModuleVisitor *visitor) = 0;
  StructType * GetReferenceStructType() {
    return reference_struct_type;
  }

  protected:
  FunctionVariableValue *default_constructor = nullptr;

  public:
  virtual void   InitStaticProperties(ModuleVisitor *){};
  virtual Value *CreateInstance(ModuleVisitor *visitor);
  virtual void   CreateDefaultConstructor(ModuleVisitor *visitor);
  virtual void   CallDefaultConstructor(ModuleVisitor *visitor, Value *this_value);

  public:
  virtual void CallCustomConstructor(IRBuilder<> *builder, Value *this_value, vector<Value *> arguments) = 0;
  virtual void SetCustomConstructor(FunctionVariableValue *custom_constructor)                           = 0;
  virtual FunctionVariableValue *GetCustomConstructor()                                                  = 0;
  string                         GetDefaultConstroctorName() {
    return DEFAULT_CONSTRUCTOR_KEY;
  }

  public:
  virtual var_index GetPropertyStartIndex() {
    return 0;
  }

  public:
  virtual string ToString() {
    return "[Reference: " + name + "]";
  };

  public:
  string GetTypeName() {
    switch (type) {
      case ReferenceType::Class:
        return "class." + name;
      case ReferenceType::Object:
        return "object." + name;
      case ReferenceType::TypeDefine:
        return "typedef." + name;
      default:
        return "";
    }
  }
};

class ReferenceInfoManager {
  private:
  ParseTreeProperty<ReferenceInfo *> *tree_reference_info = nullptr;
  list<ReferenceInfo *>               reference_info_list;

  public:
  ReferenceInfoManager();
  ~ReferenceInfoManager();

  public:
  void           SetNewReferenceInfo(ParseTree *node, ReferenceInfo *reference_info);
  ReferenceInfo *GetReferenceInfo(ParseTree *node);

  private:
  void RemoveAllReferenceInfo();
};

} // namespace tser