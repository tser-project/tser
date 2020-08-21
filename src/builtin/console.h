#pragma once

#include "tser.h"

using namespace std;

namespace tser {

class console {

  public:
  static void debug(int length, VariableType *types, ...);
  static void log(int length, VariableType *types, ...);
  static void info(int length, VariableType *types, ...);
  static void warn(int length, VariableType *types, ...);
  static void error(int length, VariableType *types, ...);

  // void _assert(bool, string);
  // void clear();
  // int  count();
  // void countReset();
};

}; // namespace tser
