#pragma once

#include "scope/scope.h"
#include "tser.h"
#include "utils.h"
#include "visit/reference/reference.h"
#include "llvm/IR/GlobalVariable.h"
#include <map>
#include <string>

using namespace tser;
using namespace std;
using namespace antlr4::tree;

namespace tser {

class ModuleVisitor;

class ClassInfo : public ReferenceInfo {
  private:
  const string CONSTRUCTOR_KEY = "constructor";

  public:
  ClassInfo(string name)
      : ReferenceInfo(ReferenceType::Class, name) {
  }
  ~ClassInfo();

  public:
  bool is_static = false;
  bool is_final  = false;

  private:
  ClassInfo *            super_class        = nullptr;
  FunctionVariableValue *custom_constructor = nullptr;

  private:
  bool has_map_table = true; // has property and method map-table

  /// map-table, used for 'extends' and 'polymorphism'
  protected:
  // map-table' values and types must contains parent's properties
  map<string, var_index> property_map_table_index;             // property's index in map-table
  vector<Type *>         property_map_table_types_cache;       // property's types in map-table
  GlobalVariable *       property_map_table_value = nullptr;   // the final value of properties' map-table
  vector<Constant *>     property_map_table_value_queue_cache; // map-table properties offset values

  protected:
  map<string, var_index> method_map_table_index;
  vector<Type *>         method_map_table_types_cache;
  GlobalVariable *       method_map_table_value = nullptr;
  vector<Constant *>     method_map_table_value_queue_cache;

  public:
  ReferenceMethodValue *  GetMethod(string key);
  ReferencePropertyValue *GetProperty(string key);

  public:
  ReferencePropertyValue *LoadProperty(Value *this_value, IRBuilder<> *builder, string key);
  ReferenceMethodValue *  LoadMethod(Value *this_pointer, IRBuilder<> *builder, string key);

  protected:
  virtual void InitVariables(ModuleVisitor *, Scope *, Value *this_value);

  public:
  virtual void InitStaticProperties(ModuleVisitor *);
  virtual void CreateDefaultConstructor(ModuleVisitor *visitor);
  virtual void CallCustomConstructor(IRBuilder<> *builder, Value *this_value, vector<Value *> arguments);
  virtual void SetCustomConstructor(FunctionVariableValue *custom_constructor) {
    this->custom_constructor = custom_constructor;
  }
  virtual FunctionVariableValue *GetCustomConstructor();
  string                         GetCustomConstroctorName() {
    return CONSTRUCTOR_KEY + ".1";
  }

  public:
  virtual void CreateVariablesStructType(ModuleVisitor *visitor);
  virtual void CreateMethodsMapTable(ModuleVisitor *visitor);

  public:
  bool       MethodIsInheritAble(string key);
  bool       PropertyIsInheritAble(string key);
  bool       PropertyIsStatic(string key);
  ClassInfo *GetRootClass();
  void       SetSuperClass(ClassInfo *super_class_info) {
    super_class = super_class_info;
  }
  ClassInfo *GetSuperClass() {
    return super_class;
  };
  bool HasMapTable() {
    return has_map_table;
  }
  void SetHasMapTable(bool has_map_table) {
    this->has_map_table = has_map_table;
  }
  // is root class which has properties and
  bool IsRootMapClass() {
    return !super_class;
  };
  virtual var_index GetPropertyStartIndex() {
    return IsRootMapClass() ? 2 : 1;
  }

  public:
  virtual string ToString() {
    return "[Class: " + name + "]";
  };
  Type *GetOffsetType(LLVMContext &context);
};

} // namespace tser