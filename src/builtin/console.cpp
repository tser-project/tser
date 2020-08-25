#include "builtin/console.h"
#include "tser.h"
#include "utils.h"
#include "visit/class/class.h"
#include <sstream>
#include <string>

using namespace std;
using namespace tser;

string float_to_string(double v) {
  ostringstream oss;
  oss << v;
  return oss.str();
}

string ArgsToString(int length, VariableType *types, va_list args) {
  string result = "";
  void * ptr    = nullptr;
  for (int i = 0; i < length; i++) {
    switch (*types) {
      case VariableType::Boolean:
        result.append(va_arg(args, int) == 1 ? "true" : "false"); // no bool type
        break;
      case VariableType::Int32:
        result.append(to_string(va_arg(args, int)));
        break;
      case VariableType::Int64:
        result.append(to_string(va_arg(args, int64_t)));
        break;
      case VariableType::Float:
        result.append(float_to_string(va_arg(args, float))); // must be float, ignore clang's warning
        break;
      case VariableType::Double:
        result.append(float_to_string(va_arg(args, double)));
        break;
      case VariableType::String:
        result.append(va_arg(args, char *));
        break;
      case VariableType::Reference:
        ptr = va_arg(args, void *);
        result.append(ptr ? "[Reference Type]" : "null");
        break;
      default:
        result.append("unknow");
        break;
    }
    types++;
  }
  return result;
}

void console::debug(int length, VariableType *types, ...) {
  va_list args;
  va_start(args, types);
  string result = ArgsToString(length, types, args);
  va_end(args);
  clog << result << endl;
}

void console::log(int length, VariableType *types, ...) {
  va_list args;
  va_start(args, types);
  string result = ArgsToString(length, types, args);
  va_end(args);
  clog << result << endl;
}

void console::info(int length, VariableType *types, ...) {
  va_list args;
  va_start(args, types);
  string result = ArgsToString(length, types, args);
  va_end(args);
  cout << result << endl;
}

void console::warn(int length, VariableType *types, ...) {
  va_list args;
  va_start(args, types);
  string result = ArgsToString(length, types, args);
  va_end(args);
  cout << result << endl;
}

void console::error(int length, VariableType *types, ...) {
  va_list args;
  va_start(args, types);
  string result = ArgsToString(length, types, args);
  va_end(args);
  cerr << result << endl;
}
