#include "antlr4-runtime.h"
#include "common/error/error.h"
#include "grammar/TypeScriptParser.h"
#include "support/Any.h"
#include "tree/ParseTree.h"
#include "utils.h"
#include "visit/visit.h"
#include "llvm/ADT/APSInt.h"
#include "llvm/IR/DerivedTypes.h"
#include "llvm/IR/Instruction.h"

using namespace tser;
using namespace std;
using namespace antlr4;
using namespace llvm;
using namespace antlr4::tree;

antlrcpp::Any ModuleVisitor::visitClassDeclaration(TypeScriptParser::ClassDeclarationContext *ctx) {
  DebugPrintln("[visitClassDeclaration] IsPreCheck: %d ; text: %s", IsPrecheckStep(),
               ctx->Identifier()->getText().data());

  if (IsPrecheckStep()) {
    string class_name = ctx->Identifier()->getText();
    auto   class_info = new ClassInfo(class_name);

    class_info->is_static = ClassIsStatic(ctx->classControl());
    class_info->is_final  = ClassIsFinal(ctx->classControl());

    auto class_tail = ctx->classTail();

    /// set super class
    if (class_tail->Extends()) {
      auto super_class_node = move(visit(class_tail->singleExpression()).as<unique_ptr<NodeValue>>());
      if (super_class_node->IsString()) {

        auto super_class_info = (ClassInfo *)GetModuleScope()->GetReferenceInfo(super_class_node->GetStringValue());
        class_info->SetSuperClass(super_class_info);
      }
    }

    /// mark if has map table
    if (class_info->is_final || class_info->is_static) {
      if (class_info->GetSuperClass()) {
        class_info->SetHasMapTable(class_info->GetSuperClass()->HasMapTable());
      } else {
        class_info->SetHasMapTable(false);
      }
    }

    SetNewReferenceInfo(ctx, class_info);

    GetModuleScope()->DefineReferenceInfo(class_name, class_info);
    visitClassTail(class_tail);
    return defaultResult();
  }
  visitChildren(ctx);
  return defaultResult();
}

antlrcpp::Any ModuleVisitor::visitClassTail(TypeScriptParser::ClassTailContext *ctx) {

  auto class_info = (ClassInfo *)GetReferenceInfo(ctx);

  vector<TypeScriptParser::ClassElementContext *>           elements = ctx->classElement();
  vector<TypeScriptParser::ClassElementContext *>::iterator it       = elements.begin();

  if (IsPrecheckStep()) {

    /// Step 1: visit properties first (should skip static property)
    while (it != elements.end()) {
      if (dynamic_cast<TypeScriptParser::ClassPropertyDefinitionContext *>(*it)) {
        visit(*it);
      }
      it++;
    }

    /// Step 2: visit getter
    it = elements.begin();
    while (it != elements.end()) {
      if (dynamic_cast<TypeScriptParser::GetterMethodDefinitionContext *>(*it)) {
        visit(*it);
      }
      it++;
    }

    /// Step 3: visit setter
    it = elements.begin();
    while (it != elements.end()) {
      if (dynamic_cast<TypeScriptParser::SetterMethodDefinitionContext *>(*it)) {
        visit(*it);
      }
      it++;
    }

    /// Step 4: create class struct type
    class_info->CreateVariablesStructType(this);

    // Step 5: visit normal methods
    it = elements.begin();
    while (it != elements.end()) {
      if (dynamic_cast<TypeScriptParser::NormalMethodDefinitionContext *>(*it)) {
        visit(*it);
      }
      it++;
    }

    /// Step 6: create class struct type
    class_info->CreateMethodsMapTable(this);

    /// Step 7: precheck custom contructor
    it = elements.begin();
    while (it != elements.end()) {
      if (dynamic_cast<TypeScriptParser::ConstructorDefinitionContext *>(*it)) {
        visit(*it);
      }
      it++;
    }

    return defaultResult();
  }

  /// Step 1: visit body again, to init properties and methods, and create custom contructor
  visitChildren(ctx);

  /// Step 2: create default constructor
  class_info->CreateDefaultConstructor(this);

  return defaultResult();
}

/// ConstructorDefinitionContext
antlrcpp::Any ModuleVisitor::visitConstructorDefinition(TypeScriptParser::ConstructorDefinitionContext *ctx) {

  auto class_info = (ClassInfo *)GetReferenceInfo(ctx);

  if (IsPrecheckStep()) {
    auto scope            = new FunctionScope(ctx, GetModuleScope(), class_info->GetCustomConstroctorName());
    auto value            = new ReferenceMethodValue(scope, new TypeSignInfo(VariableType::Function));
    value->access_control = AccessControl::Public;
    value->scope          = scope;
    value->SetUsingThis(true);

    auto func_value_info = unique_ptr<LlvmValueInfo>(CreateFunction(class_info->GetTypeName(), scope, this,
                                                                    class_info->GetReferenceStructType(),
                                                                    ctx->formalParameterList(), nullptr));
    value->value         = func_value_info->value;

    class_info->SetCustomConstructor(value);
    scope->SetFunctionVariableValue(value);

    SetNewScope(ctx, scope);

    BasicBlock *oldBB = builder->GetInsertBlock();
    LoadReferenceMethodArgs(this, class_info, value, scope, ctx->formalParameterList());
    visitFunctionBody(ctx->functionBody());
    builder->SetInsertPoint(oldBB);
    return defaultResult();
  }

  auto scope = (FunctionScope *)GetScope(ctx);

  BasicBlock *oldBB = builder->GetInsertBlock();

  auto custom_con = class_info->GetCustomConstructor();
  builder->SetInsertPoint(&((Function *)(custom_con->value))->getEntryBlock());

  visitFunctionBody(ctx->functionBody());

  builder->SetInsertPoint(oldBB);

  return defaultResult();
}

/// ClassPropertyDefinitionContext
antlrcpp::Any ModuleVisitor::visitClassPropertyDefinition(TypeScriptParser::ClassPropertyDefinitionContext *ctx) {
  DebugPrintln("[visitClassPropertyDefinition] IsPreCheck: %d ; text: %s", IsPrecheckStep(), ctx->getText().data());

  string property_name = visitPropertyName(ctx->propertyName());
  auto   ref_info      = GetReferenceInfo(ctx);
  Scope *scope         = GetScope(ctx);

  if (IsPrecheckStep()) {

    TypeSignInfo *type_sign = visitTypeSign(ctx->typeSign());

    auto value = new ReferencePropertyValue(scope, type_sign);
    if (ctx->accessControl()) {
      value->access_control = visitAccessControl(ctx->accessControl());
    }
    value->is_static = PropertyIsStatic(ctx->propertyControl());

    if (ctx->singleExpression()) {
      // don't set value
      value->SetTreeNode(ctx->singleExpression());
      visit(ctx->singleExpression());
    }
    ref_info->DefineProperty(property_name, value);
    return defaultResult();
  }
  /// init when call default construction
  return defaultResult();
}

/// NormalMethodDefinitionContext
antlrcpp::Any ModuleVisitor::visitNormalMethodDefinition(TypeScriptParser::NormalMethodDefinitionContext *ctx) {

  DebugPrintln("[visitNormalMethodDefinition] IsPreCheck: %d ; text: %s", IsPrecheckStep(),
               ctx->propertyName()->getText().data());

  auto   class_info  = (ClassInfo *)GetReferenceInfo(ctx);
  string method_name = visit(ctx->propertyName());

  if (IsPrecheckStep()) {
    auto scope = new FunctionScope(ctx, GetModuleScope(), method_name);
    SetNewScope(ctx, scope);

    // store function definition to ir, and don't visit body, or other function' call inside it will
    // cann't find target.

    auto value            = new ReferenceMethodValue(scope, new TypeSignInfo(VariableType::Function));
    value->access_control = visitAccessControl(ctx->accessControl());
    value->is_async       = !!ctx->Async();
    value->scope          = scope;
    value->is_static      = FunctionIsStatic(ctx->functionControl());
    value->is_final       = FunctionIsFinal(ctx->functionControl());
    value->SetUsingThis(!value->is_static);

    auto func_value_info = unique_ptr<LlvmValueInfo>(CreateFunction(
        class_info->GetTypeName(), scope, this, value->UsingThis() ? class_info->GetReferenceStructType() : nullptr,
        ctx->formalParameterList(), ctx->typeSign()));

    value->value = func_value_info->value;

    value->SetReturnValue(new LlvmValueInfo(func_value_info->type->clone(), nullptr));

    scope->SetFunctionVariableValue(value);
    class_info->DefineMethod(method_name, value);

    BasicBlock *oldBB = builder->GetInsertBlock();
    LoadReferenceMethodArgs(this, class_info, value, GetScope(ctx), ctx->formalParameterList());
    visitFunctionBody(ctx->functionBody());
    builder->SetInsertPoint(oldBB);

    return defaultResult();
  }
  auto value = (ReferenceMethodValue *)class_info->GetMethod(method_name);

  BasicBlock *oldBB = builder->GetInsertBlock();
  builder->SetInsertPoint(&((Function *)(value->value))->getEntryBlock());

  visitFunctionBody(ctx->functionBody());

  builder->SetInsertPoint(oldBB);

  return defaultResult();
}

antlrcpp::Any ModuleVisitor::visitPropertyName(TypeScriptParser::PropertyNameContext *ctx) {
  DebugPrintln("[visitPropertyName] IsPreCheck: %d ; text: %s", IsPrecheckStep(), ctx->getText().data());
  return visitChildren(ctx);
}

antlrcpp::Any ModuleVisitor::visitGetterMethodDefinition(TypeScriptParser::GetterMethodDefinitionContext *ctx) {
  return visitChildren(ctx);
}

antlrcpp::Any ModuleVisitor::visitSetterMethodDefinition(TypeScriptParser::SetterMethodDefinitionContext *ctx) {
  return visitChildren(ctx);
}

antlrcpp::Any ModuleVisitor::visitAccessControl(TypeScriptParser::AccessControlContext *ctx) {

  if (!ctx) {
    return AccessControl::Public;
  }

  if (ctx->Private()) {
    return AccessControl::Private;
  }
  if (ctx->Protected()) {
    return AccessControl::Protected;
  }
  // default also return Public
  return AccessControl::Public;
}