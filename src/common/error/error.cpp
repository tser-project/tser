#include "common/error/error.h"
#include <exception>
#include <string>

using namespace std;
using namespace tser;

const char *VariableNotFoundException::what() const throw() {
  return ("Variable [" + name + "] is not defined").data();
}

const char *FunctionNotFoundException::what() const throw() {
  std::string ss = (is_class_method ? "Method" : "Function");
  ss.append(" [").append(name).append("] is not defined"); // + ;
  return ss.data();
}

const char *ReferenceInfoNotFoundException::what() const throw() {
  return ("Reference Type [" + name + "] is not defined").data();
}

const char *TypeNotMatchException::what() const throw() {
  return ("Type not match: [" + name + "]").data();
}

const char *ValueNotMatchException::what() const throw() {
  return ("Value not match: [" + name + "]").data();
}

const char *SwitchCaseIllegalException::what() const throw() {
  return ("Switch case value is illegal: " + message + "").data();
}

const char *TypeConvertException::what() const throw() {
  return message.data();
}

const char *CurrentNotSupportException::what() const throw() {
  return ("Not supported [" + name + "] currently").data();
}

const char *TargetScopeNotFoundException::what() const throw() {
  return ("Target scope [" + (name == "" ? "anonymous" : name) + "] not found").data();
}