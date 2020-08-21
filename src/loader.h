#pragma once

#include "ffi/intrinsic.h"
#include "tser.h"
#include "visit/class/class.h"
#include <set>

using namespace std;

namespace tser {

enum class LoaderType {
  Class,
  Function,
  Variable,
};

class ReferencePackageConfig;
class ModuleVisitor;

class Loader {
  protected:
  TserProcess *process = nullptr;

  public:
  Loader(TserProcess *process)
      : process(process) {
  }

  public:
  /// if 'name' is function or property, var_key is empty.
  virtual void LoadToModule(ModuleVisitor *visitor, string name, string var_key = "") = 0;
  GlobalScope *GetGlobalScope();

  public:
  virtual ~Loader() {
    process = nullptr;
  }
};

class FunctionLoader : public Loader {

  public:
  using Loader::Loader;

  void LoadToModule(ModuleVisitor *visitor, string name, string var_key = "");
};

class ClassLoader : public Loader {
  public:
  using Loader::Loader;

  private:
  map<ModuleVisitor *, map<string, ClassInfo *>> load_cache;

  public:
  void       LoadToModule(ModuleVisitor *visitor, string name, string var_key = "");
  ClassInfo *LoadClassInfo(ModuleVisitor *visitor, string name);
};

class LoaderManager {
  private:
  TserProcess *process = nullptr;
  // map<ModuleVisitor *, set<string>> load_cache;
  ClassLoader *   class_loader    = nullptr;
  FunctionLoader *function_loader = nullptr;

  public:
  LoaderManager(TserProcess *process)
      : process(process) {
    class_loader    = new ClassLoader(process);
    function_loader = new FunctionLoader(process);
  }
  ~LoaderManager();

  public:
  virtual void LoadToModule(LoaderType type, ModuleVisitor *visitor, string name, string var_key = "");
};

} // namespace tser