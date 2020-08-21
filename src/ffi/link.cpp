#include "ffi/link.h"

using namespace tser;

/// LinkFunctionConfig
LinkFunctionConfig::~LinkFunctionConfig() {
  if (return_type) {
    delete return_type;
  }
  for (auto &arg : arguments) {
    delete arg;
  }
}

/// ReferenceMethodConfig
ReferenceMethodConfig::~ReferenceMethodConfig() {
  delete return_type;
  for (auto &arg : arguments) {
    delete arg;
  }
}

/// ReferencePackageConfig
ReferencePackageConfig::~ReferencePackageConfig() {
  delete ref_info;
  for (auto &item : methods) {
    delete item.second;
  }
  for (auto &item : properties) {
    delete item.second;
  }
}

/// console
void tser::DefineConsole(TserProcess *process) {

  /// console
  auto console_info = new ReferenceInfoConfig();
  console_info->SetIsFinal(true);
  console_info->SetHasMapTable(false);

  map<string, ReferenceMethodConfig *> methods;

  /// console. debug log info warn error
  auto   log_methods_length = 5;
  string log_methods[]      = {"debug", "log", "info", "warn", "error"};

  for (int index = 0; index < log_methods_length; index++) {
    vector<TypeSignInfo *> log_arguments;
    log_arguments.push_back(new TypeSignInfo(VariableType::Int32));
    log_arguments.push_back(new TypeSignInfo(VariableType::Enum, new TypeName("tser", "VariableType"), true));
    auto method =
        new ReferenceMethodConfig(log_methods[ index ], new TypeSignInfo(VariableType::Void), log_arguments, true);
    method->SetAutoAddVarArgs(true);
    method->SetIsStatic(true);

    methods[ log_methods[ index ] ] = method;
  }

  /// console package
  auto console = new ReferencePackageConfig("console", console_info, methods);

  process->GetGlobalScope()->DefineReferenceInfo(console);
}

/// Date
void tser::DefineDate(TserProcess *process) {
  /// console
  auto date_info = new ReferenceInfoConfig();
  date_info->SetIsFinal(true);
  date_info->SetHasMapTable(false);

  map<string, ReferenceMethodConfig *> methods;
  auto now_method = new ReferenceMethodConfig("now", new TypeSignInfo(VariableType::Int64));
  now_method->SetIsStatic(true);
  methods[ "now" ] = now_method;

  /// Date package
  auto date = new ReferencePackageConfig("Date", date_info, methods);

  process->GetGlobalScope()->DefineReferenceInfo(date);
}

void tser::DefineBuiltins(TserProcess *process) {

  /// define console
  DefineConsole(process);

  /// define Date
  DefineDate(process);

  /// defint printf
  auto printf = new LinkFunctionConfig("printf", IntrinsicFunctionID::Printf, new TypeSignInfo(VariableType::Void));
  process->GetGlobalScope()->DefineFunction(printf);
}
