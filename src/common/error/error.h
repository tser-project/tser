#pragma once

#include <exception>
#include <string>

using namespace std;

namespace tser {

class VariableNotFoundException : public exception {

  private:
  string name = "";

  public:
  VariableNotFoundException(string name)
      : name(name){};

  public:
  const char *what() const throw();
};

class FunctionNotFoundException : public exception {

  private:
  string name            = "";
  bool   is_class_method = false;

  public:
  FunctionNotFoundException(string name)
      : name(name){};
  FunctionNotFoundException(string name, bool is_class_method)
      : name(name)
      , is_class_method(is_class_method){};

  public:
  const char *what() const throw();
};

class ReferenceInfoNotFoundException : public exception {

  private:
  string name = "";

  public:
  ReferenceInfoNotFoundException(string name)
      : name(name){};

  public:
  const char *what() const throw();
};

class TypeNotMatchException : public exception {

  private:
  string name = "";

  public:
  TypeNotMatchException(string name)
      : name(name){};

  public:
  const char *what() const throw();
};

class ValueNotMatchException : public exception {

  private:
  string name = "";

  public:
  ValueNotMatchException(string name)
      : name(name){};

  public:
  const char *what() const throw();
};

class SwitchCaseIllegalException : public exception {

  private:
  string message = "";

  public:
  SwitchCaseIllegalException(string message)
      : message(message){};

  public:
  const char *what() const throw();
};

class TypeConvertException : public exception {

  private:
  string message = "";

  public:
  TypeConvertException(string message)
      : message(message){};

  public:
  const char *what() const throw();
};

class CurrentNotSupportException : public exception {

  private:
  string name = "";

  public:
  CurrentNotSupportException(string name)
      : name(name){};

  public:
  const char *what() const throw();
};

enum class ScopeType;

class TargetScopeNotFoundException : public exception {

  private:
  ScopeType scope_type;
  string    name = "";

  public:
  TargetScopeNotFoundException(ScopeType scope_type, string name)
      : scope_type(scope_type)
      , name(name){};

  public:
  const char *what() const throw();
};

}; // namespace tser
