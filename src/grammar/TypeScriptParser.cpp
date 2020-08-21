
// Generated from TypeScriptParser.g4 by ANTLR 4.8


#include "TypeScriptParserListener.h"
#include "TypeScriptParserVisitor.h"

#include "TypeScriptParser.h"


using namespace antlrcpp;
using namespace antlr4;

TypeScriptParser::TypeScriptParser(TokenStream *input) : Parser(input) {
  _interpreter = new atn::ParserATNSimulator(this, _atn, _decisionToDFA, _sharedContextCache);
}

TypeScriptParser::~TypeScriptParser() {
  delete _interpreter;
}

std::string TypeScriptParser::getGrammarFileName() const {
  return "TypeScriptParser.g4";
}

const std::vector<std::string>& TypeScriptParser::getRuleNames() const {
  return _ruleNames;
}

dfa::Vocabulary& TypeScriptParser::getVocabulary() const {
  return _vocabulary;
}


//----------------- ProgramContext ------------------------------------------------------------------

TypeScriptParser::ProgramContext::ProgramContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* TypeScriptParser::ProgramContext::EOF() {
  return getToken(TypeScriptParser::EOF, 0);
}

tree::TerminalNode* TypeScriptParser::ProgramContext::HashBangLine() {
  return getToken(TypeScriptParser::HashBangLine, 0);
}

TypeScriptParser::StatementListContext* TypeScriptParser::ProgramContext::statementList() {
  return getRuleContext<TypeScriptParser::StatementListContext>(0);
}


size_t TypeScriptParser::ProgramContext::getRuleIndex() const {
  return TypeScriptParser::RuleProgram;
}

void TypeScriptParser::ProgramContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TypeScriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterProgram(this);
}

void TypeScriptParser::ProgramContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TypeScriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitProgram(this);
}


antlrcpp::Any TypeScriptParser::ProgramContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TypeScriptParserVisitor*>(visitor))
    return parserVisitor->visitProgram(this);
  else
    return visitor->visitChildren(this);
}

TypeScriptParser::ProgramContext* TypeScriptParser::program() {
  ProgramContext *_localctx = _tracker.createInstance<ProgramContext>(_ctx, getState());
  enterRule(_localctx, 0, TypeScriptParser::RuleProgram);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(157);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == TypeScriptParser::HashBangLine) {
      setState(156);
      match(TypeScriptParser::HashBangLine);
    }
    setState(160);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << TypeScriptParser::RegularExpressionLiteral)
      | (1ULL << TypeScriptParser::OpenBracket)
      | (1ULL << TypeScriptParser::OpenParen)
      | (1ULL << TypeScriptParser::OpenBrace)
      | (1ULL << TypeScriptParser::SemiColon)
      | (1ULL << TypeScriptParser::PlusPlus)
      | (1ULL << TypeScriptParser::MinusMinus)
      | (1ULL << TypeScriptParser::Plus)
      | (1ULL << TypeScriptParser::Minus)
      | (1ULL << TypeScriptParser::BitNot)
      | (1ULL << TypeScriptParser::Not)
      | (1ULL << TypeScriptParser::NullLiteral)
      | (1ULL << TypeScriptParser::BooleanLiteral)
      | (1ULL << TypeScriptParser::DecimalLiteral))) != 0) || ((((_la - 71) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 71)) & ((1ULL << (TypeScriptParser::HexIntegerLiteral - 71))
      | (1ULL << (TypeScriptParser::OctalIntegerLiteral - 71))
      | (1ULL << (TypeScriptParser::OctalIntegerLiteral2 - 71))
      | (1ULL << (TypeScriptParser::BinaryIntegerLiteral - 71))
      | (1ULL << (TypeScriptParser::BigHexIntegerLiteral - 71))
      | (1ULL << (TypeScriptParser::BigOctalIntegerLiteral - 71))
      | (1ULL << (TypeScriptParser::BigBinaryIntegerLiteral - 71))
      | (1ULL << (TypeScriptParser::BigDecimalIntegerLiteral - 71))
      | (1ULL << (TypeScriptParser::Break - 71))
      | (1ULL << (TypeScriptParser::Do - 71))
      | (1ULL << (TypeScriptParser::Typeof - 71))
      | (1ULL << (TypeScriptParser::New - 71))
      | (1ULL << (TypeScriptParser::Var - 71))
      | (1ULL << (TypeScriptParser::Return - 71))
      | (1ULL << (TypeScriptParser::Void - 71))
      | (1ULL << (TypeScriptParser::Continue - 71))
      | (1ULL << (TypeScriptParser::For - 71))
      | (1ULL << (TypeScriptParser::Switch - 71))
      | (1ULL << (TypeScriptParser::While - 71))
      | (1ULL << (TypeScriptParser::Debugger - 71))
      | (1ULL << (TypeScriptParser::Function - 71))
      | (1ULL << (TypeScriptParser::This - 71))
      | (1ULL << (TypeScriptParser::With - 71))
      | (1ULL << (TypeScriptParser::If - 71))
      | (1ULL << (TypeScriptParser::Throw - 71))
      | (1ULL << (TypeScriptParser::Delete - 71))
      | (1ULL << (TypeScriptParser::Try - 71))
      | (1ULL << (TypeScriptParser::Class - 71))
      | (1ULL << (TypeScriptParser::Super - 71))
      | (1ULL << (TypeScriptParser::Const - 71))
      | (1ULL << (TypeScriptParser::Export - 71))
      | (1ULL << (TypeScriptParser::Import - 71))
      | (1ULL << (TypeScriptParser::Async - 71))
      | (1ULL << (TypeScriptParser::Await - 71))
      | (1ULL << (TypeScriptParser::Let - 71))
      | (1ULL << (TypeScriptParser::Static - 71))
      | (1ULL << (TypeScriptParser::Final - 71))
      | (1ULL << (TypeScriptParser::Yield - 71))
      | (1ULL << (TypeScriptParser::Identifier - 71))
      | (1ULL << (TypeScriptParser::StringLiteral - 71))
      | (1ULL << (TypeScriptParser::TemplateStringLiteral - 71)))) != 0)) {
      setState(159);
      statementList();
    }
    setState(162);
    match(TypeScriptParser::EOF);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- StatementListContext ------------------------------------------------------------------

TypeScriptParser::StatementListContext::StatementListContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<TypeScriptParser::StatementContext *> TypeScriptParser::StatementListContext::statement() {
  return getRuleContexts<TypeScriptParser::StatementContext>();
}

TypeScriptParser::StatementContext* TypeScriptParser::StatementListContext::statement(size_t i) {
  return getRuleContext<TypeScriptParser::StatementContext>(i);
}


size_t TypeScriptParser::StatementListContext::getRuleIndex() const {
  return TypeScriptParser::RuleStatementList;
}

void TypeScriptParser::StatementListContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TypeScriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterStatementList(this);
}

void TypeScriptParser::StatementListContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TypeScriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitStatementList(this);
}


antlrcpp::Any TypeScriptParser::StatementListContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TypeScriptParserVisitor*>(visitor))
    return parserVisitor->visitStatementList(this);
  else
    return visitor->visitChildren(this);
}

TypeScriptParser::StatementListContext* TypeScriptParser::statementList() {
  StatementListContext *_localctx = _tracker.createInstance<StatementListContext>(_ctx, getState());
  enterRule(_localctx, 2, TypeScriptParser::RuleStatementList);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(165); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(164);
      statement();
      setState(167); 
      _errHandler->sync(this);
      _la = _input->LA(1);
    } while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << TypeScriptParser::RegularExpressionLiteral)
      | (1ULL << TypeScriptParser::OpenBracket)
      | (1ULL << TypeScriptParser::OpenParen)
      | (1ULL << TypeScriptParser::OpenBrace)
      | (1ULL << TypeScriptParser::SemiColon)
      | (1ULL << TypeScriptParser::PlusPlus)
      | (1ULL << TypeScriptParser::MinusMinus)
      | (1ULL << TypeScriptParser::Plus)
      | (1ULL << TypeScriptParser::Minus)
      | (1ULL << TypeScriptParser::BitNot)
      | (1ULL << TypeScriptParser::Not)
      | (1ULL << TypeScriptParser::NullLiteral)
      | (1ULL << TypeScriptParser::BooleanLiteral)
      | (1ULL << TypeScriptParser::DecimalLiteral))) != 0) || ((((_la - 71) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 71)) & ((1ULL << (TypeScriptParser::HexIntegerLiteral - 71))
      | (1ULL << (TypeScriptParser::OctalIntegerLiteral - 71))
      | (1ULL << (TypeScriptParser::OctalIntegerLiteral2 - 71))
      | (1ULL << (TypeScriptParser::BinaryIntegerLiteral - 71))
      | (1ULL << (TypeScriptParser::BigHexIntegerLiteral - 71))
      | (1ULL << (TypeScriptParser::BigOctalIntegerLiteral - 71))
      | (1ULL << (TypeScriptParser::BigBinaryIntegerLiteral - 71))
      | (1ULL << (TypeScriptParser::BigDecimalIntegerLiteral - 71))
      | (1ULL << (TypeScriptParser::Break - 71))
      | (1ULL << (TypeScriptParser::Do - 71))
      | (1ULL << (TypeScriptParser::Typeof - 71))
      | (1ULL << (TypeScriptParser::New - 71))
      | (1ULL << (TypeScriptParser::Var - 71))
      | (1ULL << (TypeScriptParser::Return - 71))
      | (1ULL << (TypeScriptParser::Void - 71))
      | (1ULL << (TypeScriptParser::Continue - 71))
      | (1ULL << (TypeScriptParser::For - 71))
      | (1ULL << (TypeScriptParser::Switch - 71))
      | (1ULL << (TypeScriptParser::While - 71))
      | (1ULL << (TypeScriptParser::Debugger - 71))
      | (1ULL << (TypeScriptParser::Function - 71))
      | (1ULL << (TypeScriptParser::This - 71))
      | (1ULL << (TypeScriptParser::With - 71))
      | (1ULL << (TypeScriptParser::If - 71))
      | (1ULL << (TypeScriptParser::Throw - 71))
      | (1ULL << (TypeScriptParser::Delete - 71))
      | (1ULL << (TypeScriptParser::Try - 71))
      | (1ULL << (TypeScriptParser::Class - 71))
      | (1ULL << (TypeScriptParser::Super - 71))
      | (1ULL << (TypeScriptParser::Const - 71))
      | (1ULL << (TypeScriptParser::Export - 71))
      | (1ULL << (TypeScriptParser::Import - 71))
      | (1ULL << (TypeScriptParser::Async - 71))
      | (1ULL << (TypeScriptParser::Await - 71))
      | (1ULL << (TypeScriptParser::Let - 71))
      | (1ULL << (TypeScriptParser::Static - 71))
      | (1ULL << (TypeScriptParser::Final - 71))
      | (1ULL << (TypeScriptParser::Yield - 71))
      | (1ULL << (TypeScriptParser::Identifier - 71))
      | (1ULL << (TypeScriptParser::StringLiteral - 71))
      | (1ULL << (TypeScriptParser::TemplateStringLiteral - 71)))) != 0));
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- StatementContext ------------------------------------------------------------------

TypeScriptParser::StatementContext::StatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

TypeScriptParser::BlockContext* TypeScriptParser::StatementContext::block() {
  return getRuleContext<TypeScriptParser::BlockContext>(0);
}

TypeScriptParser::VariableStatementContext* TypeScriptParser::StatementContext::variableStatement() {
  return getRuleContext<TypeScriptParser::VariableStatementContext>(0);
}

TypeScriptParser::ImportStatementContext* TypeScriptParser::StatementContext::importStatement() {
  return getRuleContext<TypeScriptParser::ImportStatementContext>(0);
}

TypeScriptParser::ExportStatementContext* TypeScriptParser::StatementContext::exportStatement() {
  return getRuleContext<TypeScriptParser::ExportStatementContext>(0);
}

TypeScriptParser::EmptyStatementContext* TypeScriptParser::StatementContext::emptyStatement() {
  return getRuleContext<TypeScriptParser::EmptyStatementContext>(0);
}

TypeScriptParser::ClassDeclarationContext* TypeScriptParser::StatementContext::classDeclaration() {
  return getRuleContext<TypeScriptParser::ClassDeclarationContext>(0);
}

TypeScriptParser::ExpressionStatementContext* TypeScriptParser::StatementContext::expressionStatement() {
  return getRuleContext<TypeScriptParser::ExpressionStatementContext>(0);
}

TypeScriptParser::IfStatementContext* TypeScriptParser::StatementContext::ifStatement() {
  return getRuleContext<TypeScriptParser::IfStatementContext>(0);
}

TypeScriptParser::IterationStatementContext* TypeScriptParser::StatementContext::iterationStatement() {
  return getRuleContext<TypeScriptParser::IterationStatementContext>(0);
}

TypeScriptParser::ContinueStatementContext* TypeScriptParser::StatementContext::continueStatement() {
  return getRuleContext<TypeScriptParser::ContinueStatementContext>(0);
}

TypeScriptParser::BreakStatementContext* TypeScriptParser::StatementContext::breakStatement() {
  return getRuleContext<TypeScriptParser::BreakStatementContext>(0);
}

TypeScriptParser::ReturnStatementContext* TypeScriptParser::StatementContext::returnStatement() {
  return getRuleContext<TypeScriptParser::ReturnStatementContext>(0);
}

TypeScriptParser::YieldStatementContext* TypeScriptParser::StatementContext::yieldStatement() {
  return getRuleContext<TypeScriptParser::YieldStatementContext>(0);
}

TypeScriptParser::WithStatementContext* TypeScriptParser::StatementContext::withStatement() {
  return getRuleContext<TypeScriptParser::WithStatementContext>(0);
}

TypeScriptParser::LabelledStatementContext* TypeScriptParser::StatementContext::labelledStatement() {
  return getRuleContext<TypeScriptParser::LabelledStatementContext>(0);
}

TypeScriptParser::SwitchStatementContext* TypeScriptParser::StatementContext::switchStatement() {
  return getRuleContext<TypeScriptParser::SwitchStatementContext>(0);
}

TypeScriptParser::ThrowStatementContext* TypeScriptParser::StatementContext::throwStatement() {
  return getRuleContext<TypeScriptParser::ThrowStatementContext>(0);
}

TypeScriptParser::TryStatementContext* TypeScriptParser::StatementContext::tryStatement() {
  return getRuleContext<TypeScriptParser::TryStatementContext>(0);
}

TypeScriptParser::DebuggerStatementContext* TypeScriptParser::StatementContext::debuggerStatement() {
  return getRuleContext<TypeScriptParser::DebuggerStatementContext>(0);
}

TypeScriptParser::FunctionDeclarationContext* TypeScriptParser::StatementContext::functionDeclaration() {
  return getRuleContext<TypeScriptParser::FunctionDeclarationContext>(0);
}


size_t TypeScriptParser::StatementContext::getRuleIndex() const {
  return TypeScriptParser::RuleStatement;
}

void TypeScriptParser::StatementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TypeScriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterStatement(this);
}

void TypeScriptParser::StatementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TypeScriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitStatement(this);
}


antlrcpp::Any TypeScriptParser::StatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TypeScriptParserVisitor*>(visitor))
    return parserVisitor->visitStatement(this);
  else
    return visitor->visitChildren(this);
}

TypeScriptParser::StatementContext* TypeScriptParser::statement() {
  StatementContext *_localctx = _tracker.createInstance<StatementContext>(_ctx, getState());
  enterRule(_localctx, 4, TypeScriptParser::RuleStatement);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(189);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 3, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(169);
      block();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(170);
      variableStatement();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(171);
      importStatement();
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(172);
      exportStatement();
      break;
    }

    case 5: {
      enterOuterAlt(_localctx, 5);
      setState(173);
      emptyStatement();
      break;
    }

    case 6: {
      enterOuterAlt(_localctx, 6);
      setState(174);
      classDeclaration();
      break;
    }

    case 7: {
      enterOuterAlt(_localctx, 7);
      setState(175);
      expressionStatement();
      break;
    }

    case 8: {
      enterOuterAlt(_localctx, 8);
      setState(176);
      ifStatement();
      break;
    }

    case 9: {
      enterOuterAlt(_localctx, 9);
      setState(177);
      iterationStatement();
      break;
    }

    case 10: {
      enterOuterAlt(_localctx, 10);
      setState(178);
      continueStatement();
      break;
    }

    case 11: {
      enterOuterAlt(_localctx, 11);
      setState(179);
      breakStatement();
      break;
    }

    case 12: {
      enterOuterAlt(_localctx, 12);
      setState(180);
      returnStatement();
      break;
    }

    case 13: {
      enterOuterAlt(_localctx, 13);
      setState(181);
      yieldStatement();
      break;
    }

    case 14: {
      enterOuterAlt(_localctx, 14);
      setState(182);
      withStatement();
      break;
    }

    case 15: {
      enterOuterAlt(_localctx, 15);
      setState(183);
      labelledStatement();
      break;
    }

    case 16: {
      enterOuterAlt(_localctx, 16);
      setState(184);
      switchStatement();
      break;
    }

    case 17: {
      enterOuterAlt(_localctx, 17);
      setState(185);
      throwStatement();
      break;
    }

    case 18: {
      enterOuterAlt(_localctx, 18);
      setState(186);
      tryStatement();
      break;
    }

    case 19: {
      enterOuterAlt(_localctx, 19);
      setState(187);
      debuggerStatement();
      break;
    }

    case 20: {
      enterOuterAlt(_localctx, 20);
      setState(188);
      functionDeclaration();
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- TypeSignContext ------------------------------------------------------------------

TypeScriptParser::TypeSignContext::TypeSignContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* TypeScriptParser::TypeSignContext::Colon() {
  return getToken(TypeScriptParser::Colon, 0);
}

TypeScriptParser::PrimaryTypeContext* TypeScriptParser::TypeSignContext::primaryType() {
  return getRuleContext<TypeScriptParser::PrimaryTypeContext>(0);
}


size_t TypeScriptParser::TypeSignContext::getRuleIndex() const {
  return TypeScriptParser::RuleTypeSign;
}

void TypeScriptParser::TypeSignContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TypeScriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterTypeSign(this);
}

void TypeScriptParser::TypeSignContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TypeScriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitTypeSign(this);
}


antlrcpp::Any TypeScriptParser::TypeSignContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TypeScriptParserVisitor*>(visitor))
    return parserVisitor->visitTypeSign(this);
  else
    return visitor->visitChildren(this);
}

TypeScriptParser::TypeSignContext* TypeScriptParser::typeSign() {
  TypeSignContext *_localctx = _tracker.createInstance<TypeSignContext>(_ctx, getState());
  enterRule(_localctx, 6, TypeScriptParser::RuleTypeSign);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(191);
    match(TypeScriptParser::Colon);
    setState(192);
    primaryType();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- PrimaryTypeContext ------------------------------------------------------------------

TypeScriptParser::PrimaryTypeContext::PrimaryTypeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

TypeScriptParser::PredefinedTypeContext* TypeScriptParser::PrimaryTypeContext::predefinedType() {
  return getRuleContext<TypeScriptParser::PredefinedTypeContext>(0);
}

TypeScriptParser::TypeReferenceContext* TypeScriptParser::PrimaryTypeContext::typeReference() {
  return getRuleContext<TypeScriptParser::TypeReferenceContext>(0);
}


size_t TypeScriptParser::PrimaryTypeContext::getRuleIndex() const {
  return TypeScriptParser::RulePrimaryType;
}

void TypeScriptParser::PrimaryTypeContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TypeScriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterPrimaryType(this);
}

void TypeScriptParser::PrimaryTypeContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TypeScriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitPrimaryType(this);
}


antlrcpp::Any TypeScriptParser::PrimaryTypeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TypeScriptParserVisitor*>(visitor))
    return parserVisitor->visitPrimaryType(this);
  else
    return visitor->visitChildren(this);
}

TypeScriptParser::PrimaryTypeContext* TypeScriptParser::primaryType() {
  PrimaryTypeContext *_localctx = _tracker.createInstance<PrimaryTypeContext>(_ctx, getState());
  enterRule(_localctx, 8, TypeScriptParser::RulePrimaryType);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(196);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case TypeScriptParser::AnyType:
      case TypeScriptParser::Int32Type:
      case TypeScriptParser::Int64Type:
      case TypeScriptParser::FloatType:
      case TypeScriptParser::DoubleType:
      case TypeScriptParser::NumberType:
      case TypeScriptParser::BooleanType:
      case TypeScriptParser::StringType:
      case TypeScriptParser::VoidType: {
        enterOuterAlt(_localctx, 1);
        setState(194);
        predefinedType();
        break;
      }

      case TypeScriptParser::Identifier: {
        enterOuterAlt(_localctx, 2);
        setState(195);
        typeReference();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- PredefinedTypeContext ------------------------------------------------------------------

TypeScriptParser::PredefinedTypeContext::PredefinedTypeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* TypeScriptParser::PredefinedTypeContext::AnyType() {
  return getToken(TypeScriptParser::AnyType, 0);
}

tree::TerminalNode* TypeScriptParser::PredefinedTypeContext::Int32Type() {
  return getToken(TypeScriptParser::Int32Type, 0);
}

tree::TerminalNode* TypeScriptParser::PredefinedTypeContext::Int64Type() {
  return getToken(TypeScriptParser::Int64Type, 0);
}

tree::TerminalNode* TypeScriptParser::PredefinedTypeContext::FloatType() {
  return getToken(TypeScriptParser::FloatType, 0);
}

tree::TerminalNode* TypeScriptParser::PredefinedTypeContext::DoubleType() {
  return getToken(TypeScriptParser::DoubleType, 0);
}

tree::TerminalNode* TypeScriptParser::PredefinedTypeContext::NumberType() {
  return getToken(TypeScriptParser::NumberType, 0);
}

tree::TerminalNode* TypeScriptParser::PredefinedTypeContext::BooleanType() {
  return getToken(TypeScriptParser::BooleanType, 0);
}

tree::TerminalNode* TypeScriptParser::PredefinedTypeContext::StringType() {
  return getToken(TypeScriptParser::StringType, 0);
}

tree::TerminalNode* TypeScriptParser::PredefinedTypeContext::VoidType() {
  return getToken(TypeScriptParser::VoidType, 0);
}


size_t TypeScriptParser::PredefinedTypeContext::getRuleIndex() const {
  return TypeScriptParser::RulePredefinedType;
}

void TypeScriptParser::PredefinedTypeContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TypeScriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterPredefinedType(this);
}

void TypeScriptParser::PredefinedTypeContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TypeScriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitPredefinedType(this);
}


antlrcpp::Any TypeScriptParser::PredefinedTypeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TypeScriptParserVisitor*>(visitor))
    return parserVisitor->visitPredefinedType(this);
  else
    return visitor->visitChildren(this);
}

TypeScriptParser::PredefinedTypeContext* TypeScriptParser::predefinedType() {
  PredefinedTypeContext *_localctx = _tracker.createInstance<PredefinedTypeContext>(_ctx, getState());
  enterRule(_localctx, 10, TypeScriptParser::RulePredefinedType);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(198);
    _la = _input->LA(1);
    if (!(((((_la - 62) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 62)) & ((1ULL << (TypeScriptParser::AnyType - 62))
      | (1ULL << (TypeScriptParser::Int32Type - 62))
      | (1ULL << (TypeScriptParser::Int64Type - 62))
      | (1ULL << (TypeScriptParser::FloatType - 62))
      | (1ULL << (TypeScriptParser::DoubleType - 62))
      | (1ULL << (TypeScriptParser::NumberType - 62))
      | (1ULL << (TypeScriptParser::BooleanType - 62))
      | (1ULL << (TypeScriptParser::StringType - 62))
      | (1ULL << (TypeScriptParser::VoidType - 62)))) != 0))) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- TypeReferenceContext ------------------------------------------------------------------

TypeScriptParser::TypeReferenceContext::TypeReferenceContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* TypeScriptParser::TypeReferenceContext::Identifier() {
  return getToken(TypeScriptParser::Identifier, 0);
}


size_t TypeScriptParser::TypeReferenceContext::getRuleIndex() const {
  return TypeScriptParser::RuleTypeReference;
}

void TypeScriptParser::TypeReferenceContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TypeScriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterTypeReference(this);
}

void TypeScriptParser::TypeReferenceContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TypeScriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitTypeReference(this);
}


antlrcpp::Any TypeScriptParser::TypeReferenceContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TypeScriptParserVisitor*>(visitor))
    return parserVisitor->visitTypeReference(this);
  else
    return visitor->visitChildren(this);
}

TypeScriptParser::TypeReferenceContext* TypeScriptParser::typeReference() {
  TypeReferenceContext *_localctx = _tracker.createInstance<TypeReferenceContext>(_ctx, getState());
  enterRule(_localctx, 12, TypeScriptParser::RuleTypeReference);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(200);
    match(TypeScriptParser::Identifier);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- AccessControlContext ------------------------------------------------------------------

TypeScriptParser::AccessControlContext::AccessControlContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* TypeScriptParser::AccessControlContext::Private() {
  return getToken(TypeScriptParser::Private, 0);
}

tree::TerminalNode* TypeScriptParser::AccessControlContext::Protected() {
  return getToken(TypeScriptParser::Protected, 0);
}

tree::TerminalNode* TypeScriptParser::AccessControlContext::Public() {
  return getToken(TypeScriptParser::Public, 0);
}


size_t TypeScriptParser::AccessControlContext::getRuleIndex() const {
  return TypeScriptParser::RuleAccessControl;
}

void TypeScriptParser::AccessControlContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TypeScriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAccessControl(this);
}

void TypeScriptParser::AccessControlContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TypeScriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAccessControl(this);
}


antlrcpp::Any TypeScriptParser::AccessControlContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TypeScriptParserVisitor*>(visitor))
    return parserVisitor->visitAccessControl(this);
  else
    return visitor->visitChildren(this);
}

TypeScriptParser::AccessControlContext* TypeScriptParser::accessControl() {
  AccessControlContext *_localctx = _tracker.createInstance<AccessControlContext>(_ctx, getState());
  enterRule(_localctx, 14, TypeScriptParser::RuleAccessControl);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(202);
    _la = _input->LA(1);
    if (!(((((_la - 120) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 120)) & ((1ULL << (TypeScriptParser::Private - 120))
      | (1ULL << (TypeScriptParser::Public - 120))
      | (1ULL << (TypeScriptParser::Protected - 120)))) != 0))) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ClassControlContext ------------------------------------------------------------------

TypeScriptParser::ClassControlContext::ClassControlContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* TypeScriptParser::ClassControlContext::Static() {
  return getToken(TypeScriptParser::Static, 0);
}

tree::TerminalNode* TypeScriptParser::ClassControlContext::Final() {
  return getToken(TypeScriptParser::Final, 0);
}


size_t TypeScriptParser::ClassControlContext::getRuleIndex() const {
  return TypeScriptParser::RuleClassControl;
}

void TypeScriptParser::ClassControlContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TypeScriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterClassControl(this);
}

void TypeScriptParser::ClassControlContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TypeScriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitClassControl(this);
}


antlrcpp::Any TypeScriptParser::ClassControlContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TypeScriptParserVisitor*>(visitor))
    return parserVisitor->visitClassControl(this);
  else
    return visitor->visitChildren(this);
}

TypeScriptParser::ClassControlContext* TypeScriptParser::classControl() {
  ClassControlContext *_localctx = _tracker.createInstance<ClassControlContext>(_ctx, getState());
  enterRule(_localctx, 16, TypeScriptParser::RuleClassControl);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(204);
    _la = _input->LA(1);
    if (!(_la == TypeScriptParser::Static

    || _la == TypeScriptParser::Final)) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- PropertyControlContext ------------------------------------------------------------------

TypeScriptParser::PropertyControlContext::PropertyControlContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* TypeScriptParser::PropertyControlContext::Static() {
  return getToken(TypeScriptParser::Static, 0);
}

tree::TerminalNode* TypeScriptParser::PropertyControlContext::Readonly() {
  return getToken(TypeScriptParser::Readonly, 0);
}


size_t TypeScriptParser::PropertyControlContext::getRuleIndex() const {
  return TypeScriptParser::RulePropertyControl;
}

void TypeScriptParser::PropertyControlContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TypeScriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterPropertyControl(this);
}

void TypeScriptParser::PropertyControlContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TypeScriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitPropertyControl(this);
}


antlrcpp::Any TypeScriptParser::PropertyControlContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TypeScriptParserVisitor*>(visitor))
    return parserVisitor->visitPropertyControl(this);
  else
    return visitor->visitChildren(this);
}

TypeScriptParser::PropertyControlContext* TypeScriptParser::propertyControl() {
  PropertyControlContext *_localctx = _tracker.createInstance<PropertyControlContext>(_ctx, getState());
  enterRule(_localctx, 18, TypeScriptParser::RulePropertyControl);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(206);
    _la = _input->LA(1);
    if (!(_la == TypeScriptParser::Readonly

    || _la == TypeScriptParser::Static)) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FunctionControlContext ------------------------------------------------------------------

TypeScriptParser::FunctionControlContext::FunctionControlContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* TypeScriptParser::FunctionControlContext::Static() {
  return getToken(TypeScriptParser::Static, 0);
}

tree::TerminalNode* TypeScriptParser::FunctionControlContext::Final() {
  return getToken(TypeScriptParser::Final, 0);
}

tree::TerminalNode* TypeScriptParser::FunctionControlContext::Identifier() {
  return getToken(TypeScriptParser::Identifier, 0);
}


size_t TypeScriptParser::FunctionControlContext::getRuleIndex() const {
  return TypeScriptParser::RuleFunctionControl;
}

void TypeScriptParser::FunctionControlContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TypeScriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFunctionControl(this);
}

void TypeScriptParser::FunctionControlContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TypeScriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFunctionControl(this);
}


antlrcpp::Any TypeScriptParser::FunctionControlContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TypeScriptParserVisitor*>(visitor))
    return parserVisitor->visitFunctionControl(this);
  else
    return visitor->visitChildren(this);
}

TypeScriptParser::FunctionControlContext* TypeScriptParser::functionControl() {
  FunctionControlContext *_localctx = _tracker.createInstance<FunctionControlContext>(_ctx, getState());
  enterRule(_localctx, 20, TypeScriptParser::RuleFunctionControl);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(208);
    _la = _input->LA(1);
    if (!(((((_la - 125) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 125)) & ((1ULL << (TypeScriptParser::Static - 125))
      | (1ULL << (TypeScriptParser::Final - 125))
      | (1ULL << (TypeScriptParser::Identifier - 125)))) != 0))) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- BlockContext ------------------------------------------------------------------

TypeScriptParser::BlockContext::BlockContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* TypeScriptParser::BlockContext::OpenBrace() {
  return getToken(TypeScriptParser::OpenBrace, 0);
}

tree::TerminalNode* TypeScriptParser::BlockContext::CloseBrace() {
  return getToken(TypeScriptParser::CloseBrace, 0);
}

TypeScriptParser::StatementListContext* TypeScriptParser::BlockContext::statementList() {
  return getRuleContext<TypeScriptParser::StatementListContext>(0);
}


size_t TypeScriptParser::BlockContext::getRuleIndex() const {
  return TypeScriptParser::RuleBlock;
}

void TypeScriptParser::BlockContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TypeScriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterBlock(this);
}

void TypeScriptParser::BlockContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TypeScriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitBlock(this);
}


antlrcpp::Any TypeScriptParser::BlockContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TypeScriptParserVisitor*>(visitor))
    return parserVisitor->visitBlock(this);
  else
    return visitor->visitChildren(this);
}

TypeScriptParser::BlockContext* TypeScriptParser::block() {
  BlockContext *_localctx = _tracker.createInstance<BlockContext>(_ctx, getState());
  enterRule(_localctx, 22, TypeScriptParser::RuleBlock);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(210);
    match(TypeScriptParser::OpenBrace);
    setState(212);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << TypeScriptParser::RegularExpressionLiteral)
      | (1ULL << TypeScriptParser::OpenBracket)
      | (1ULL << TypeScriptParser::OpenParen)
      | (1ULL << TypeScriptParser::OpenBrace)
      | (1ULL << TypeScriptParser::SemiColon)
      | (1ULL << TypeScriptParser::PlusPlus)
      | (1ULL << TypeScriptParser::MinusMinus)
      | (1ULL << TypeScriptParser::Plus)
      | (1ULL << TypeScriptParser::Minus)
      | (1ULL << TypeScriptParser::BitNot)
      | (1ULL << TypeScriptParser::Not)
      | (1ULL << TypeScriptParser::NullLiteral)
      | (1ULL << TypeScriptParser::BooleanLiteral)
      | (1ULL << TypeScriptParser::DecimalLiteral))) != 0) || ((((_la - 71) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 71)) & ((1ULL << (TypeScriptParser::HexIntegerLiteral - 71))
      | (1ULL << (TypeScriptParser::OctalIntegerLiteral - 71))
      | (1ULL << (TypeScriptParser::OctalIntegerLiteral2 - 71))
      | (1ULL << (TypeScriptParser::BinaryIntegerLiteral - 71))
      | (1ULL << (TypeScriptParser::BigHexIntegerLiteral - 71))
      | (1ULL << (TypeScriptParser::BigOctalIntegerLiteral - 71))
      | (1ULL << (TypeScriptParser::BigBinaryIntegerLiteral - 71))
      | (1ULL << (TypeScriptParser::BigDecimalIntegerLiteral - 71))
      | (1ULL << (TypeScriptParser::Break - 71))
      | (1ULL << (TypeScriptParser::Do - 71))
      | (1ULL << (TypeScriptParser::Typeof - 71))
      | (1ULL << (TypeScriptParser::New - 71))
      | (1ULL << (TypeScriptParser::Var - 71))
      | (1ULL << (TypeScriptParser::Return - 71))
      | (1ULL << (TypeScriptParser::Void - 71))
      | (1ULL << (TypeScriptParser::Continue - 71))
      | (1ULL << (TypeScriptParser::For - 71))
      | (1ULL << (TypeScriptParser::Switch - 71))
      | (1ULL << (TypeScriptParser::While - 71))
      | (1ULL << (TypeScriptParser::Debugger - 71))
      | (1ULL << (TypeScriptParser::Function - 71))
      | (1ULL << (TypeScriptParser::This - 71))
      | (1ULL << (TypeScriptParser::With - 71))
      | (1ULL << (TypeScriptParser::If - 71))
      | (1ULL << (TypeScriptParser::Throw - 71))
      | (1ULL << (TypeScriptParser::Delete - 71))
      | (1ULL << (TypeScriptParser::Try - 71))
      | (1ULL << (TypeScriptParser::Class - 71))
      | (1ULL << (TypeScriptParser::Super - 71))
      | (1ULL << (TypeScriptParser::Const - 71))
      | (1ULL << (TypeScriptParser::Export - 71))
      | (1ULL << (TypeScriptParser::Import - 71))
      | (1ULL << (TypeScriptParser::Async - 71))
      | (1ULL << (TypeScriptParser::Await - 71))
      | (1ULL << (TypeScriptParser::Let - 71))
      | (1ULL << (TypeScriptParser::Static - 71))
      | (1ULL << (TypeScriptParser::Final - 71))
      | (1ULL << (TypeScriptParser::Yield - 71))
      | (1ULL << (TypeScriptParser::Identifier - 71))
      | (1ULL << (TypeScriptParser::StringLiteral - 71))
      | (1ULL << (TypeScriptParser::TemplateStringLiteral - 71)))) != 0)) {
      setState(211);
      statementList();
    }
    setState(214);
    match(TypeScriptParser::CloseBrace);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ImportStatementContext ------------------------------------------------------------------

TypeScriptParser::ImportStatementContext::ImportStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* TypeScriptParser::ImportStatementContext::Import() {
  return getToken(TypeScriptParser::Import, 0);
}

TypeScriptParser::ImportFromBlockContext* TypeScriptParser::ImportStatementContext::importFromBlock() {
  return getRuleContext<TypeScriptParser::ImportFromBlockContext>(0);
}


size_t TypeScriptParser::ImportStatementContext::getRuleIndex() const {
  return TypeScriptParser::RuleImportStatement;
}

void TypeScriptParser::ImportStatementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TypeScriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterImportStatement(this);
}

void TypeScriptParser::ImportStatementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TypeScriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitImportStatement(this);
}


antlrcpp::Any TypeScriptParser::ImportStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TypeScriptParserVisitor*>(visitor))
    return parserVisitor->visitImportStatement(this);
  else
    return visitor->visitChildren(this);
}

TypeScriptParser::ImportStatementContext* TypeScriptParser::importStatement() {
  ImportStatementContext *_localctx = _tracker.createInstance<ImportStatementContext>(_ctx, getState());
  enterRule(_localctx, 24, TypeScriptParser::RuleImportStatement);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(216);
    match(TypeScriptParser::Import);
    setState(217);
    importFromBlock();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ImportFromBlockContext ------------------------------------------------------------------

TypeScriptParser::ImportFromBlockContext::ImportFromBlockContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

TypeScriptParser::ImportFromContext* TypeScriptParser::ImportFromBlockContext::importFrom() {
  return getRuleContext<TypeScriptParser::ImportFromContext>(0);
}

TypeScriptParser::EosContext* TypeScriptParser::ImportFromBlockContext::eos() {
  return getRuleContext<TypeScriptParser::EosContext>(0);
}

TypeScriptParser::ImportNamespaceContext* TypeScriptParser::ImportFromBlockContext::importNamespace() {
  return getRuleContext<TypeScriptParser::ImportNamespaceContext>(0);
}

TypeScriptParser::ModuleItemsContext* TypeScriptParser::ImportFromBlockContext::moduleItems() {
  return getRuleContext<TypeScriptParser::ModuleItemsContext>(0);
}

TypeScriptParser::ImportDefaultContext* TypeScriptParser::ImportFromBlockContext::importDefault() {
  return getRuleContext<TypeScriptParser::ImportDefaultContext>(0);
}

tree::TerminalNode* TypeScriptParser::ImportFromBlockContext::StringLiteral() {
  return getToken(TypeScriptParser::StringLiteral, 0);
}


size_t TypeScriptParser::ImportFromBlockContext::getRuleIndex() const {
  return TypeScriptParser::RuleImportFromBlock;
}

void TypeScriptParser::ImportFromBlockContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TypeScriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterImportFromBlock(this);
}

void TypeScriptParser::ImportFromBlockContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TypeScriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitImportFromBlock(this);
}


antlrcpp::Any TypeScriptParser::ImportFromBlockContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TypeScriptParserVisitor*>(visitor))
    return parserVisitor->visitImportFromBlock(this);
  else
    return visitor->visitChildren(this);
}

TypeScriptParser::ImportFromBlockContext* TypeScriptParser::importFromBlock() {
  ImportFromBlockContext *_localctx = _tracker.createInstance<ImportFromBlockContext>(_ctx, getState());
  enterRule(_localctx, 26, TypeScriptParser::RuleImportFromBlock);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(231);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case TypeScriptParser::OpenBrace:
      case TypeScriptParser::Multiply:
      case TypeScriptParser::NullLiteral:
      case TypeScriptParser::BooleanLiteral:
      case TypeScriptParser::Break:
      case TypeScriptParser::Do:
      case TypeScriptParser::Instanceof:
      case TypeScriptParser::Typeof:
      case TypeScriptParser::Case:
      case TypeScriptParser::Else:
      case TypeScriptParser::New:
      case TypeScriptParser::Var:
      case TypeScriptParser::Catch:
      case TypeScriptParser::Finally:
      case TypeScriptParser::Return:
      case TypeScriptParser::Void:
      case TypeScriptParser::Continue:
      case TypeScriptParser::For:
      case TypeScriptParser::Switch:
      case TypeScriptParser::While:
      case TypeScriptParser::Debugger:
      case TypeScriptParser::Function:
      case TypeScriptParser::This:
      case TypeScriptParser::With:
      case TypeScriptParser::Default:
      case TypeScriptParser::If:
      case TypeScriptParser::Throw:
      case TypeScriptParser::Delete:
      case TypeScriptParser::In:
      case TypeScriptParser::Try:
      case TypeScriptParser::As:
      case TypeScriptParser::From:
      case TypeScriptParser::Class:
      case TypeScriptParser::Enum:
      case TypeScriptParser::Extends:
      case TypeScriptParser::Super:
      case TypeScriptParser::Const:
      case TypeScriptParser::Export:
      case TypeScriptParser::Import:
      case TypeScriptParser::Async:
      case TypeScriptParser::Await:
      case TypeScriptParser::Implements:
      case TypeScriptParser::Let:
      case TypeScriptParser::Private:
      case TypeScriptParser::Public:
      case TypeScriptParser::Interface:
      case TypeScriptParser::Package:
      case TypeScriptParser::Protected:
      case TypeScriptParser::Static:
      case TypeScriptParser::Yield:
      case TypeScriptParser::Identifier: {
        enterOuterAlt(_localctx, 1);
        setState(220);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == TypeScriptParser::NullLiteral

        || _la == TypeScriptParser::BooleanLiteral || ((((_la - 80) & ~ 0x3fULL) == 0) &&
          ((1ULL << (_la - 80)) & ((1ULL << (TypeScriptParser::Break - 80))
          | (1ULL << (TypeScriptParser::Do - 80))
          | (1ULL << (TypeScriptParser::Instanceof - 80))
          | (1ULL << (TypeScriptParser::Typeof - 80))
          | (1ULL << (TypeScriptParser::Case - 80))
          | (1ULL << (TypeScriptParser::Else - 80))
          | (1ULL << (TypeScriptParser::New - 80))
          | (1ULL << (TypeScriptParser::Var - 80))
          | (1ULL << (TypeScriptParser::Catch - 80))
          | (1ULL << (TypeScriptParser::Finally - 80))
          | (1ULL << (TypeScriptParser::Return - 80))
          | (1ULL << (TypeScriptParser::Void - 80))
          | (1ULL << (TypeScriptParser::Continue - 80))
          | (1ULL << (TypeScriptParser::For - 80))
          | (1ULL << (TypeScriptParser::Switch - 80))
          | (1ULL << (TypeScriptParser::While - 80))
          | (1ULL << (TypeScriptParser::Debugger - 80))
          | (1ULL << (TypeScriptParser::Function - 80))
          | (1ULL << (TypeScriptParser::This - 80))
          | (1ULL << (TypeScriptParser::With - 80))
          | (1ULL << (TypeScriptParser::Default - 80))
          | (1ULL << (TypeScriptParser::If - 80))
          | (1ULL << (TypeScriptParser::Throw - 80))
          | (1ULL << (TypeScriptParser::Delete - 80))
          | (1ULL << (TypeScriptParser::In - 80))
          | (1ULL << (TypeScriptParser::Try - 80))
          | (1ULL << (TypeScriptParser::As - 80))
          | (1ULL << (TypeScriptParser::From - 80))
          | (1ULL << (TypeScriptParser::Class - 80))
          | (1ULL << (TypeScriptParser::Enum - 80))
          | (1ULL << (TypeScriptParser::Extends - 80))
          | (1ULL << (TypeScriptParser::Super - 80))
          | (1ULL << (TypeScriptParser::Const - 80))
          | (1ULL << (TypeScriptParser::Export - 80))
          | (1ULL << (TypeScriptParser::Import - 80))
          | (1ULL << (TypeScriptParser::Async - 80))
          | (1ULL << (TypeScriptParser::Await - 80))
          | (1ULL << (TypeScriptParser::Implements - 80))
          | (1ULL << (TypeScriptParser::Let - 80))
          | (1ULL << (TypeScriptParser::Private - 80))
          | (1ULL << (TypeScriptParser::Public - 80))
          | (1ULL << (TypeScriptParser::Interface - 80))
          | (1ULL << (TypeScriptParser::Package - 80))
          | (1ULL << (TypeScriptParser::Protected - 80))
          | (1ULL << (TypeScriptParser::Static - 80))
          | (1ULL << (TypeScriptParser::Yield - 80))
          | (1ULL << (TypeScriptParser::Identifier - 80)))) != 0)) {
          setState(219);
          importDefault();
        }
        setState(224);
        _errHandler->sync(this);
        switch (_input->LA(1)) {
          case TypeScriptParser::Multiply: {
            setState(222);
            importNamespace();
            break;
          }

          case TypeScriptParser::OpenBrace: {
            setState(223);
            moduleItems();
            break;
          }

        default:
          throw NoViableAltException(this);
        }
        setState(226);
        importFrom();
        setState(227);
        eos();
        break;
      }

      case TypeScriptParser::StringLiteral: {
        enterOuterAlt(_localctx, 2);
        setState(229);
        match(TypeScriptParser::StringLiteral);
        setState(230);
        eos();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ModuleItemsContext ------------------------------------------------------------------

TypeScriptParser::ModuleItemsContext::ModuleItemsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* TypeScriptParser::ModuleItemsContext::OpenBrace() {
  return getToken(TypeScriptParser::OpenBrace, 0);
}

tree::TerminalNode* TypeScriptParser::ModuleItemsContext::CloseBrace() {
  return getToken(TypeScriptParser::CloseBrace, 0);
}

std::vector<TypeScriptParser::AliasNameContext *> TypeScriptParser::ModuleItemsContext::aliasName() {
  return getRuleContexts<TypeScriptParser::AliasNameContext>();
}

TypeScriptParser::AliasNameContext* TypeScriptParser::ModuleItemsContext::aliasName(size_t i) {
  return getRuleContext<TypeScriptParser::AliasNameContext>(i);
}

std::vector<tree::TerminalNode *> TypeScriptParser::ModuleItemsContext::Comma() {
  return getTokens(TypeScriptParser::Comma);
}

tree::TerminalNode* TypeScriptParser::ModuleItemsContext::Comma(size_t i) {
  return getToken(TypeScriptParser::Comma, i);
}


size_t TypeScriptParser::ModuleItemsContext::getRuleIndex() const {
  return TypeScriptParser::RuleModuleItems;
}

void TypeScriptParser::ModuleItemsContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TypeScriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterModuleItems(this);
}

void TypeScriptParser::ModuleItemsContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TypeScriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitModuleItems(this);
}


antlrcpp::Any TypeScriptParser::ModuleItemsContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TypeScriptParserVisitor*>(visitor))
    return parserVisitor->visitModuleItems(this);
  else
    return visitor->visitChildren(this);
}

TypeScriptParser::ModuleItemsContext* TypeScriptParser::moduleItems() {
  ModuleItemsContext *_localctx = _tracker.createInstance<ModuleItemsContext>(_ctx, getState());
  enterRule(_localctx, 28, TypeScriptParser::RuleModuleItems);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(233);
    match(TypeScriptParser::OpenBrace);
    setState(239);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 9, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(234);
        aliasName();
        setState(235);
        match(TypeScriptParser::Comma); 
      }
      setState(241);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 9, _ctx);
    }
    setState(246);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == TypeScriptParser::NullLiteral

    || _la == TypeScriptParser::BooleanLiteral || ((((_la - 80) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 80)) & ((1ULL << (TypeScriptParser::Break - 80))
      | (1ULL << (TypeScriptParser::Do - 80))
      | (1ULL << (TypeScriptParser::Instanceof - 80))
      | (1ULL << (TypeScriptParser::Typeof - 80))
      | (1ULL << (TypeScriptParser::Case - 80))
      | (1ULL << (TypeScriptParser::Else - 80))
      | (1ULL << (TypeScriptParser::New - 80))
      | (1ULL << (TypeScriptParser::Var - 80))
      | (1ULL << (TypeScriptParser::Catch - 80))
      | (1ULL << (TypeScriptParser::Finally - 80))
      | (1ULL << (TypeScriptParser::Return - 80))
      | (1ULL << (TypeScriptParser::Void - 80))
      | (1ULL << (TypeScriptParser::Continue - 80))
      | (1ULL << (TypeScriptParser::For - 80))
      | (1ULL << (TypeScriptParser::Switch - 80))
      | (1ULL << (TypeScriptParser::While - 80))
      | (1ULL << (TypeScriptParser::Debugger - 80))
      | (1ULL << (TypeScriptParser::Function - 80))
      | (1ULL << (TypeScriptParser::This - 80))
      | (1ULL << (TypeScriptParser::With - 80))
      | (1ULL << (TypeScriptParser::Default - 80))
      | (1ULL << (TypeScriptParser::If - 80))
      | (1ULL << (TypeScriptParser::Throw - 80))
      | (1ULL << (TypeScriptParser::Delete - 80))
      | (1ULL << (TypeScriptParser::In - 80))
      | (1ULL << (TypeScriptParser::Try - 80))
      | (1ULL << (TypeScriptParser::As - 80))
      | (1ULL << (TypeScriptParser::From - 80))
      | (1ULL << (TypeScriptParser::Class - 80))
      | (1ULL << (TypeScriptParser::Enum - 80))
      | (1ULL << (TypeScriptParser::Extends - 80))
      | (1ULL << (TypeScriptParser::Super - 80))
      | (1ULL << (TypeScriptParser::Const - 80))
      | (1ULL << (TypeScriptParser::Export - 80))
      | (1ULL << (TypeScriptParser::Import - 80))
      | (1ULL << (TypeScriptParser::Async - 80))
      | (1ULL << (TypeScriptParser::Await - 80))
      | (1ULL << (TypeScriptParser::Implements - 80))
      | (1ULL << (TypeScriptParser::Let - 80))
      | (1ULL << (TypeScriptParser::Private - 80))
      | (1ULL << (TypeScriptParser::Public - 80))
      | (1ULL << (TypeScriptParser::Interface - 80))
      | (1ULL << (TypeScriptParser::Package - 80))
      | (1ULL << (TypeScriptParser::Protected - 80))
      | (1ULL << (TypeScriptParser::Static - 80))
      | (1ULL << (TypeScriptParser::Yield - 80))
      | (1ULL << (TypeScriptParser::Identifier - 80)))) != 0)) {
      setState(242);
      aliasName();
      setState(244);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == TypeScriptParser::Comma) {
        setState(243);
        match(TypeScriptParser::Comma);
      }
    }
    setState(248);
    match(TypeScriptParser::CloseBrace);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ImportDefaultContext ------------------------------------------------------------------

TypeScriptParser::ImportDefaultContext::ImportDefaultContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

TypeScriptParser::AliasNameContext* TypeScriptParser::ImportDefaultContext::aliasName() {
  return getRuleContext<TypeScriptParser::AliasNameContext>(0);
}

tree::TerminalNode* TypeScriptParser::ImportDefaultContext::Comma() {
  return getToken(TypeScriptParser::Comma, 0);
}


size_t TypeScriptParser::ImportDefaultContext::getRuleIndex() const {
  return TypeScriptParser::RuleImportDefault;
}

void TypeScriptParser::ImportDefaultContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TypeScriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterImportDefault(this);
}

void TypeScriptParser::ImportDefaultContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TypeScriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitImportDefault(this);
}


antlrcpp::Any TypeScriptParser::ImportDefaultContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TypeScriptParserVisitor*>(visitor))
    return parserVisitor->visitImportDefault(this);
  else
    return visitor->visitChildren(this);
}

TypeScriptParser::ImportDefaultContext* TypeScriptParser::importDefault() {
  ImportDefaultContext *_localctx = _tracker.createInstance<ImportDefaultContext>(_ctx, getState());
  enterRule(_localctx, 30, TypeScriptParser::RuleImportDefault);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(250);
    aliasName();
    setState(251);
    match(TypeScriptParser::Comma);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ImportNamespaceContext ------------------------------------------------------------------

TypeScriptParser::ImportNamespaceContext::ImportNamespaceContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* TypeScriptParser::ImportNamespaceContext::Multiply() {
  return getToken(TypeScriptParser::Multiply, 0);
}

tree::TerminalNode* TypeScriptParser::ImportNamespaceContext::As() {
  return getToken(TypeScriptParser::As, 0);
}

TypeScriptParser::IdentifierNameContext* TypeScriptParser::ImportNamespaceContext::identifierName() {
  return getRuleContext<TypeScriptParser::IdentifierNameContext>(0);
}


size_t TypeScriptParser::ImportNamespaceContext::getRuleIndex() const {
  return TypeScriptParser::RuleImportNamespace;
}

void TypeScriptParser::ImportNamespaceContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TypeScriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterImportNamespace(this);
}

void TypeScriptParser::ImportNamespaceContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TypeScriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitImportNamespace(this);
}


antlrcpp::Any TypeScriptParser::ImportNamespaceContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TypeScriptParserVisitor*>(visitor))
    return parserVisitor->visitImportNamespace(this);
  else
    return visitor->visitChildren(this);
}

TypeScriptParser::ImportNamespaceContext* TypeScriptParser::importNamespace() {
  ImportNamespaceContext *_localctx = _tracker.createInstance<ImportNamespaceContext>(_ctx, getState());
  enterRule(_localctx, 32, TypeScriptParser::RuleImportNamespace);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(253);
    match(TypeScriptParser::Multiply);
    setState(256);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == TypeScriptParser::As) {
      setState(254);
      match(TypeScriptParser::As);
      setState(255);
      identifierName();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ImportFromContext ------------------------------------------------------------------

TypeScriptParser::ImportFromContext::ImportFromContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* TypeScriptParser::ImportFromContext::From() {
  return getToken(TypeScriptParser::From, 0);
}

tree::TerminalNode* TypeScriptParser::ImportFromContext::StringLiteral() {
  return getToken(TypeScriptParser::StringLiteral, 0);
}


size_t TypeScriptParser::ImportFromContext::getRuleIndex() const {
  return TypeScriptParser::RuleImportFrom;
}

void TypeScriptParser::ImportFromContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TypeScriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterImportFrom(this);
}

void TypeScriptParser::ImportFromContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TypeScriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitImportFrom(this);
}


antlrcpp::Any TypeScriptParser::ImportFromContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TypeScriptParserVisitor*>(visitor))
    return parserVisitor->visitImportFrom(this);
  else
    return visitor->visitChildren(this);
}

TypeScriptParser::ImportFromContext* TypeScriptParser::importFrom() {
  ImportFromContext *_localctx = _tracker.createInstance<ImportFromContext>(_ctx, getState());
  enterRule(_localctx, 34, TypeScriptParser::RuleImportFrom);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(258);
    match(TypeScriptParser::From);
    setState(259);
    match(TypeScriptParser::StringLiteral);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- AliasNameContext ------------------------------------------------------------------

TypeScriptParser::AliasNameContext::AliasNameContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<TypeScriptParser::IdentifierNameContext *> TypeScriptParser::AliasNameContext::identifierName() {
  return getRuleContexts<TypeScriptParser::IdentifierNameContext>();
}

TypeScriptParser::IdentifierNameContext* TypeScriptParser::AliasNameContext::identifierName(size_t i) {
  return getRuleContext<TypeScriptParser::IdentifierNameContext>(i);
}

tree::TerminalNode* TypeScriptParser::AliasNameContext::As() {
  return getToken(TypeScriptParser::As, 0);
}


size_t TypeScriptParser::AliasNameContext::getRuleIndex() const {
  return TypeScriptParser::RuleAliasName;
}

void TypeScriptParser::AliasNameContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TypeScriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAliasName(this);
}

void TypeScriptParser::AliasNameContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TypeScriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAliasName(this);
}


antlrcpp::Any TypeScriptParser::AliasNameContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TypeScriptParserVisitor*>(visitor))
    return parserVisitor->visitAliasName(this);
  else
    return visitor->visitChildren(this);
}

TypeScriptParser::AliasNameContext* TypeScriptParser::aliasName() {
  AliasNameContext *_localctx = _tracker.createInstance<AliasNameContext>(_ctx, getState());
  enterRule(_localctx, 36, TypeScriptParser::RuleAliasName);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(261);
    identifierName();
    setState(264);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == TypeScriptParser::As) {
      setState(262);
      match(TypeScriptParser::As);
      setState(263);
      identifierName();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ExportStatementContext ------------------------------------------------------------------

TypeScriptParser::ExportStatementContext::ExportStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t TypeScriptParser::ExportStatementContext::getRuleIndex() const {
  return TypeScriptParser::RuleExportStatement;
}

void TypeScriptParser::ExportStatementContext::copyFrom(ExportStatementContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- ExportDefaultDeclarationContext ------------------------------------------------------------------

tree::TerminalNode* TypeScriptParser::ExportDefaultDeclarationContext::Export() {
  return getToken(TypeScriptParser::Export, 0);
}

tree::TerminalNode* TypeScriptParser::ExportDefaultDeclarationContext::Default() {
  return getToken(TypeScriptParser::Default, 0);
}

TypeScriptParser::SingleExpressionContext* TypeScriptParser::ExportDefaultDeclarationContext::singleExpression() {
  return getRuleContext<TypeScriptParser::SingleExpressionContext>(0);
}

TypeScriptParser::EosContext* TypeScriptParser::ExportDefaultDeclarationContext::eos() {
  return getRuleContext<TypeScriptParser::EosContext>(0);
}

TypeScriptParser::ExportDefaultDeclarationContext::ExportDefaultDeclarationContext(ExportStatementContext *ctx) { copyFrom(ctx); }

void TypeScriptParser::ExportDefaultDeclarationContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TypeScriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterExportDefaultDeclaration(this);
}
void TypeScriptParser::ExportDefaultDeclarationContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TypeScriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitExportDefaultDeclaration(this);
}

antlrcpp::Any TypeScriptParser::ExportDefaultDeclarationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TypeScriptParserVisitor*>(visitor))
    return parserVisitor->visitExportDefaultDeclaration(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ExportDeclarationContext ------------------------------------------------------------------

tree::TerminalNode* TypeScriptParser::ExportDeclarationContext::Export() {
  return getToken(TypeScriptParser::Export, 0);
}

TypeScriptParser::EosContext* TypeScriptParser::ExportDeclarationContext::eos() {
  return getRuleContext<TypeScriptParser::EosContext>(0);
}

TypeScriptParser::ExportFromBlockContext* TypeScriptParser::ExportDeclarationContext::exportFromBlock() {
  return getRuleContext<TypeScriptParser::ExportFromBlockContext>(0);
}

TypeScriptParser::DeclarationContext* TypeScriptParser::ExportDeclarationContext::declaration() {
  return getRuleContext<TypeScriptParser::DeclarationContext>(0);
}

TypeScriptParser::ExportDeclarationContext::ExportDeclarationContext(ExportStatementContext *ctx) { copyFrom(ctx); }

void TypeScriptParser::ExportDeclarationContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TypeScriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterExportDeclaration(this);
}
void TypeScriptParser::ExportDeclarationContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TypeScriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitExportDeclaration(this);
}

antlrcpp::Any TypeScriptParser::ExportDeclarationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TypeScriptParserVisitor*>(visitor))
    return parserVisitor->visitExportDeclaration(this);
  else
    return visitor->visitChildren(this);
}
TypeScriptParser::ExportStatementContext* TypeScriptParser::exportStatement() {
  ExportStatementContext *_localctx = _tracker.createInstance<ExportStatementContext>(_ctx, getState());
  enterRule(_localctx, 38, TypeScriptParser::RuleExportStatement);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(278);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 15, _ctx)) {
    case 1: {
      _localctx = dynamic_cast<ExportStatementContext *>(_tracker.createInstance<TypeScriptParser::ExportDeclarationContext>(_localctx));
      enterOuterAlt(_localctx, 1);
      setState(266);
      match(TypeScriptParser::Export);
      setState(269);
      _errHandler->sync(this);
      switch (_input->LA(1)) {
        case TypeScriptParser::OpenBrace:
        case TypeScriptParser::Multiply: {
          setState(267);
          exportFromBlock();
          break;
        }

        case TypeScriptParser::Var:
        case TypeScriptParser::Function:
        case TypeScriptParser::Class:
        case TypeScriptParser::Const:
        case TypeScriptParser::Async:
        case TypeScriptParser::Let:
        case TypeScriptParser::Static:
        case TypeScriptParser::Final: {
          setState(268);
          declaration();
          break;
        }

      default:
        throw NoViableAltException(this);
      }
      setState(271);
      eos();
      break;
    }

    case 2: {
      _localctx = dynamic_cast<ExportStatementContext *>(_tracker.createInstance<TypeScriptParser::ExportDefaultDeclarationContext>(_localctx));
      enterOuterAlt(_localctx, 2);
      setState(273);
      match(TypeScriptParser::Export);
      setState(274);
      match(TypeScriptParser::Default);
      setState(275);
      singleExpression(0);
      setState(276);
      eos();
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ExportFromBlockContext ------------------------------------------------------------------

TypeScriptParser::ExportFromBlockContext::ExportFromBlockContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

TypeScriptParser::ImportNamespaceContext* TypeScriptParser::ExportFromBlockContext::importNamespace() {
  return getRuleContext<TypeScriptParser::ImportNamespaceContext>(0);
}

TypeScriptParser::ImportFromContext* TypeScriptParser::ExportFromBlockContext::importFrom() {
  return getRuleContext<TypeScriptParser::ImportFromContext>(0);
}

TypeScriptParser::EosContext* TypeScriptParser::ExportFromBlockContext::eos() {
  return getRuleContext<TypeScriptParser::EosContext>(0);
}

TypeScriptParser::ModuleItemsContext* TypeScriptParser::ExportFromBlockContext::moduleItems() {
  return getRuleContext<TypeScriptParser::ModuleItemsContext>(0);
}


size_t TypeScriptParser::ExportFromBlockContext::getRuleIndex() const {
  return TypeScriptParser::RuleExportFromBlock;
}

void TypeScriptParser::ExportFromBlockContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TypeScriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterExportFromBlock(this);
}

void TypeScriptParser::ExportFromBlockContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TypeScriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitExportFromBlock(this);
}


antlrcpp::Any TypeScriptParser::ExportFromBlockContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TypeScriptParserVisitor*>(visitor))
    return parserVisitor->visitExportFromBlock(this);
  else
    return visitor->visitChildren(this);
}

TypeScriptParser::ExportFromBlockContext* TypeScriptParser::exportFromBlock() {
  ExportFromBlockContext *_localctx = _tracker.createInstance<ExportFromBlockContext>(_ctx, getState());
  enterRule(_localctx, 40, TypeScriptParser::RuleExportFromBlock);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(290);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case TypeScriptParser::Multiply: {
        enterOuterAlt(_localctx, 1);
        setState(280);
        importNamespace();
        setState(281);
        importFrom();
        setState(282);
        eos();
        break;
      }

      case TypeScriptParser::OpenBrace: {
        enterOuterAlt(_localctx, 2);
        setState(284);
        moduleItems();
        setState(286);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == TypeScriptParser::From) {
          setState(285);
          importFrom();
        }
        setState(288);
        eos();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- DeclarationContext ------------------------------------------------------------------

TypeScriptParser::DeclarationContext::DeclarationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

TypeScriptParser::VariableStatementContext* TypeScriptParser::DeclarationContext::variableStatement() {
  return getRuleContext<TypeScriptParser::VariableStatementContext>(0);
}

TypeScriptParser::ClassDeclarationContext* TypeScriptParser::DeclarationContext::classDeclaration() {
  return getRuleContext<TypeScriptParser::ClassDeclarationContext>(0);
}

TypeScriptParser::FunctionDeclarationContext* TypeScriptParser::DeclarationContext::functionDeclaration() {
  return getRuleContext<TypeScriptParser::FunctionDeclarationContext>(0);
}


size_t TypeScriptParser::DeclarationContext::getRuleIndex() const {
  return TypeScriptParser::RuleDeclaration;
}

void TypeScriptParser::DeclarationContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TypeScriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterDeclaration(this);
}

void TypeScriptParser::DeclarationContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TypeScriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitDeclaration(this);
}


antlrcpp::Any TypeScriptParser::DeclarationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TypeScriptParserVisitor*>(visitor))
    return parserVisitor->visitDeclaration(this);
  else
    return visitor->visitChildren(this);
}

TypeScriptParser::DeclarationContext* TypeScriptParser::declaration() {
  DeclarationContext *_localctx = _tracker.createInstance<DeclarationContext>(_ctx, getState());
  enterRule(_localctx, 42, TypeScriptParser::RuleDeclaration);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(295);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case TypeScriptParser::Var:
      case TypeScriptParser::Const:
      case TypeScriptParser::Let: {
        enterOuterAlt(_localctx, 1);
        setState(292);
        variableStatement();
        break;
      }

      case TypeScriptParser::Class:
      case TypeScriptParser::Static:
      case TypeScriptParser::Final: {
        enterOuterAlt(_localctx, 2);
        setState(293);
        classDeclaration();
        break;
      }

      case TypeScriptParser::Function:
      case TypeScriptParser::Async: {
        enterOuterAlt(_localctx, 3);
        setState(294);
        functionDeclaration();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- VariableStatementContext ------------------------------------------------------------------

TypeScriptParser::VariableStatementContext::VariableStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

TypeScriptParser::VarModifierContext* TypeScriptParser::VariableStatementContext::varModifier() {
  return getRuleContext<TypeScriptParser::VarModifierContext>(0);
}

TypeScriptParser::VariableDeclarationListContext* TypeScriptParser::VariableStatementContext::variableDeclarationList() {
  return getRuleContext<TypeScriptParser::VariableDeclarationListContext>(0);
}

TypeScriptParser::EosContext* TypeScriptParser::VariableStatementContext::eos() {
  return getRuleContext<TypeScriptParser::EosContext>(0);
}


size_t TypeScriptParser::VariableStatementContext::getRuleIndex() const {
  return TypeScriptParser::RuleVariableStatement;
}

void TypeScriptParser::VariableStatementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TypeScriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterVariableStatement(this);
}

void TypeScriptParser::VariableStatementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TypeScriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitVariableStatement(this);
}


antlrcpp::Any TypeScriptParser::VariableStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TypeScriptParserVisitor*>(visitor))
    return parserVisitor->visitVariableStatement(this);
  else
    return visitor->visitChildren(this);
}

TypeScriptParser::VariableStatementContext* TypeScriptParser::variableStatement() {
  VariableStatementContext *_localctx = _tracker.createInstance<VariableStatementContext>(_ctx, getState());
  enterRule(_localctx, 44, TypeScriptParser::RuleVariableStatement);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(297);
    varModifier();
    setState(298);
    variableDeclarationList();
    setState(299);
    eos();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- VariableDeclarationListContext ------------------------------------------------------------------

TypeScriptParser::VariableDeclarationListContext::VariableDeclarationListContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<TypeScriptParser::VariableDeclarationContext *> TypeScriptParser::VariableDeclarationListContext::variableDeclaration() {
  return getRuleContexts<TypeScriptParser::VariableDeclarationContext>();
}

TypeScriptParser::VariableDeclarationContext* TypeScriptParser::VariableDeclarationListContext::variableDeclaration(size_t i) {
  return getRuleContext<TypeScriptParser::VariableDeclarationContext>(i);
}

std::vector<tree::TerminalNode *> TypeScriptParser::VariableDeclarationListContext::Comma() {
  return getTokens(TypeScriptParser::Comma);
}

tree::TerminalNode* TypeScriptParser::VariableDeclarationListContext::Comma(size_t i) {
  return getToken(TypeScriptParser::Comma, i);
}


size_t TypeScriptParser::VariableDeclarationListContext::getRuleIndex() const {
  return TypeScriptParser::RuleVariableDeclarationList;
}

void TypeScriptParser::VariableDeclarationListContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TypeScriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterVariableDeclarationList(this);
}

void TypeScriptParser::VariableDeclarationListContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TypeScriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitVariableDeclarationList(this);
}


antlrcpp::Any TypeScriptParser::VariableDeclarationListContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TypeScriptParserVisitor*>(visitor))
    return parserVisitor->visitVariableDeclarationList(this);
  else
    return visitor->visitChildren(this);
}

TypeScriptParser::VariableDeclarationListContext* TypeScriptParser::variableDeclarationList() {
  VariableDeclarationListContext *_localctx = _tracker.createInstance<VariableDeclarationListContext>(_ctx, getState());
  enterRule(_localctx, 46, TypeScriptParser::RuleVariableDeclarationList);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(301);
    variableDeclaration();
    setState(306);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == TypeScriptParser::Comma) {
      setState(302);
      match(TypeScriptParser::Comma);
      setState(303);
      variableDeclaration();
      setState(308);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- VariableDeclarationContext ------------------------------------------------------------------

TypeScriptParser::VariableDeclarationContext::VariableDeclarationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

TypeScriptParser::AssignableContext* TypeScriptParser::VariableDeclarationContext::assignable() {
  return getRuleContext<TypeScriptParser::AssignableContext>(0);
}

TypeScriptParser::TypeSignContext* TypeScriptParser::VariableDeclarationContext::typeSign() {
  return getRuleContext<TypeScriptParser::TypeSignContext>(0);
}

tree::TerminalNode* TypeScriptParser::VariableDeclarationContext::Assign() {
  return getToken(TypeScriptParser::Assign, 0);
}

TypeScriptParser::SingleExpressionContext* TypeScriptParser::VariableDeclarationContext::singleExpression() {
  return getRuleContext<TypeScriptParser::SingleExpressionContext>(0);
}


size_t TypeScriptParser::VariableDeclarationContext::getRuleIndex() const {
  return TypeScriptParser::RuleVariableDeclaration;
}

void TypeScriptParser::VariableDeclarationContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TypeScriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterVariableDeclaration(this);
}

void TypeScriptParser::VariableDeclarationContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TypeScriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitVariableDeclaration(this);
}


antlrcpp::Any TypeScriptParser::VariableDeclarationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TypeScriptParserVisitor*>(visitor))
    return parserVisitor->visitVariableDeclaration(this);
  else
    return visitor->visitChildren(this);
}

TypeScriptParser::VariableDeclarationContext* TypeScriptParser::variableDeclaration() {
  VariableDeclarationContext *_localctx = _tracker.createInstance<VariableDeclarationContext>(_ctx, getState());
  enterRule(_localctx, 48, TypeScriptParser::RuleVariableDeclaration);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(309);
    assignable();
    setState(311);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == TypeScriptParser::Colon) {
      setState(310);
      typeSign();
    }
    setState(315);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == TypeScriptParser::Assign) {
      setState(313);
      match(TypeScriptParser::Assign);
      setState(314);
      singleExpression(0);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- EmptyStatementContext ------------------------------------------------------------------

TypeScriptParser::EmptyStatementContext::EmptyStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* TypeScriptParser::EmptyStatementContext::SemiColon() {
  return getToken(TypeScriptParser::SemiColon, 0);
}


size_t TypeScriptParser::EmptyStatementContext::getRuleIndex() const {
  return TypeScriptParser::RuleEmptyStatement;
}

void TypeScriptParser::EmptyStatementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TypeScriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterEmptyStatement(this);
}

void TypeScriptParser::EmptyStatementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TypeScriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitEmptyStatement(this);
}


antlrcpp::Any TypeScriptParser::EmptyStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TypeScriptParserVisitor*>(visitor))
    return parserVisitor->visitEmptyStatement(this);
  else
    return visitor->visitChildren(this);
}

TypeScriptParser::EmptyStatementContext* TypeScriptParser::emptyStatement() {
  EmptyStatementContext *_localctx = _tracker.createInstance<EmptyStatementContext>(_ctx, getState());
  enterRule(_localctx, 50, TypeScriptParser::RuleEmptyStatement);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(317);
    match(TypeScriptParser::SemiColon);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ExpressionStatementContext ------------------------------------------------------------------

TypeScriptParser::ExpressionStatementContext::ExpressionStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

TypeScriptParser::ExpressionSequenceContext* TypeScriptParser::ExpressionStatementContext::expressionSequence() {
  return getRuleContext<TypeScriptParser::ExpressionSequenceContext>(0);
}

TypeScriptParser::EosContext* TypeScriptParser::ExpressionStatementContext::eos() {
  return getRuleContext<TypeScriptParser::EosContext>(0);
}


size_t TypeScriptParser::ExpressionStatementContext::getRuleIndex() const {
  return TypeScriptParser::RuleExpressionStatement;
}

void TypeScriptParser::ExpressionStatementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TypeScriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterExpressionStatement(this);
}

void TypeScriptParser::ExpressionStatementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TypeScriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitExpressionStatement(this);
}


antlrcpp::Any TypeScriptParser::ExpressionStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TypeScriptParserVisitor*>(visitor))
    return parserVisitor->visitExpressionStatement(this);
  else
    return visitor->visitChildren(this);
}

TypeScriptParser::ExpressionStatementContext* TypeScriptParser::expressionStatement() {
  ExpressionStatementContext *_localctx = _tracker.createInstance<ExpressionStatementContext>(_ctx, getState());
  enterRule(_localctx, 52, TypeScriptParser::RuleExpressionStatement);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(319);
    expressionSequence();
    setState(320);
    eos();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- IfStatementContext ------------------------------------------------------------------

TypeScriptParser::IfStatementContext::IfStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* TypeScriptParser::IfStatementContext::If() {
  return getToken(TypeScriptParser::If, 0);
}

tree::TerminalNode* TypeScriptParser::IfStatementContext::OpenParen() {
  return getToken(TypeScriptParser::OpenParen, 0);
}

TypeScriptParser::ExpressionSequenceContext* TypeScriptParser::IfStatementContext::expressionSequence() {
  return getRuleContext<TypeScriptParser::ExpressionSequenceContext>(0);
}

tree::TerminalNode* TypeScriptParser::IfStatementContext::CloseParen() {
  return getToken(TypeScriptParser::CloseParen, 0);
}

std::vector<TypeScriptParser::StatementContext *> TypeScriptParser::IfStatementContext::statement() {
  return getRuleContexts<TypeScriptParser::StatementContext>();
}

TypeScriptParser::StatementContext* TypeScriptParser::IfStatementContext::statement(size_t i) {
  return getRuleContext<TypeScriptParser::StatementContext>(i);
}

tree::TerminalNode* TypeScriptParser::IfStatementContext::Else() {
  return getToken(TypeScriptParser::Else, 0);
}


size_t TypeScriptParser::IfStatementContext::getRuleIndex() const {
  return TypeScriptParser::RuleIfStatement;
}

void TypeScriptParser::IfStatementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TypeScriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterIfStatement(this);
}

void TypeScriptParser::IfStatementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TypeScriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitIfStatement(this);
}


antlrcpp::Any TypeScriptParser::IfStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TypeScriptParserVisitor*>(visitor))
    return parserVisitor->visitIfStatement(this);
  else
    return visitor->visitChildren(this);
}

TypeScriptParser::IfStatementContext* TypeScriptParser::ifStatement() {
  IfStatementContext *_localctx = _tracker.createInstance<IfStatementContext>(_ctx, getState());
  enterRule(_localctx, 54, TypeScriptParser::RuleIfStatement);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(322);
    match(TypeScriptParser::If);
    setState(323);
    match(TypeScriptParser::OpenParen);
    setState(324);
    expressionSequence();
    setState(325);
    match(TypeScriptParser::CloseParen);
    setState(326);
    statement();
    setState(329);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 22, _ctx)) {
    case 1: {
      setState(327);
      match(TypeScriptParser::Else);
      setState(328);
      statement();
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- IterationStatementContext ------------------------------------------------------------------

TypeScriptParser::IterationStatementContext::IterationStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t TypeScriptParser::IterationStatementContext::getRuleIndex() const {
  return TypeScriptParser::RuleIterationStatement;
}

void TypeScriptParser::IterationStatementContext::copyFrom(IterationStatementContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- DoStatementContext ------------------------------------------------------------------

tree::TerminalNode* TypeScriptParser::DoStatementContext::Do() {
  return getToken(TypeScriptParser::Do, 0);
}

TypeScriptParser::StatementContext* TypeScriptParser::DoStatementContext::statement() {
  return getRuleContext<TypeScriptParser::StatementContext>(0);
}

tree::TerminalNode* TypeScriptParser::DoStatementContext::While() {
  return getToken(TypeScriptParser::While, 0);
}

tree::TerminalNode* TypeScriptParser::DoStatementContext::OpenParen() {
  return getToken(TypeScriptParser::OpenParen, 0);
}

TypeScriptParser::ExpressionSequenceContext* TypeScriptParser::DoStatementContext::expressionSequence() {
  return getRuleContext<TypeScriptParser::ExpressionSequenceContext>(0);
}

tree::TerminalNode* TypeScriptParser::DoStatementContext::CloseParen() {
  return getToken(TypeScriptParser::CloseParen, 0);
}

TypeScriptParser::EosContext* TypeScriptParser::DoStatementContext::eos() {
  return getRuleContext<TypeScriptParser::EosContext>(0);
}

TypeScriptParser::DoStatementContext::DoStatementContext(IterationStatementContext *ctx) { copyFrom(ctx); }

void TypeScriptParser::DoStatementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TypeScriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterDoStatement(this);
}
void TypeScriptParser::DoStatementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TypeScriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitDoStatement(this);
}

antlrcpp::Any TypeScriptParser::DoStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TypeScriptParserVisitor*>(visitor))
    return parserVisitor->visitDoStatement(this);
  else
    return visitor->visitChildren(this);
}
//----------------- WhileStatementContext ------------------------------------------------------------------

tree::TerminalNode* TypeScriptParser::WhileStatementContext::While() {
  return getToken(TypeScriptParser::While, 0);
}

tree::TerminalNode* TypeScriptParser::WhileStatementContext::OpenParen() {
  return getToken(TypeScriptParser::OpenParen, 0);
}

TypeScriptParser::ExpressionSequenceContext* TypeScriptParser::WhileStatementContext::expressionSequence() {
  return getRuleContext<TypeScriptParser::ExpressionSequenceContext>(0);
}

tree::TerminalNode* TypeScriptParser::WhileStatementContext::CloseParen() {
  return getToken(TypeScriptParser::CloseParen, 0);
}

TypeScriptParser::StatementContext* TypeScriptParser::WhileStatementContext::statement() {
  return getRuleContext<TypeScriptParser::StatementContext>(0);
}

TypeScriptParser::WhileStatementContext::WhileStatementContext(IterationStatementContext *ctx) { copyFrom(ctx); }

void TypeScriptParser::WhileStatementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TypeScriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterWhileStatement(this);
}
void TypeScriptParser::WhileStatementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TypeScriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitWhileStatement(this);
}

antlrcpp::Any TypeScriptParser::WhileStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TypeScriptParserVisitor*>(visitor))
    return parserVisitor->visitWhileStatement(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ForStatementContext ------------------------------------------------------------------

tree::TerminalNode* TypeScriptParser::ForStatementContext::For() {
  return getToken(TypeScriptParser::For, 0);
}

tree::TerminalNode* TypeScriptParser::ForStatementContext::OpenParen() {
  return getToken(TypeScriptParser::OpenParen, 0);
}

TypeScriptParser::ForInitializationContext* TypeScriptParser::ForStatementContext::forInitialization() {
  return getRuleContext<TypeScriptParser::ForInitializationContext>(0);
}

tree::TerminalNode* TypeScriptParser::ForStatementContext::SemiColon() {
  return getToken(TypeScriptParser::SemiColon, 0);
}

tree::TerminalNode* TypeScriptParser::ForStatementContext::CloseParen() {
  return getToken(TypeScriptParser::CloseParen, 0);
}

TypeScriptParser::StatementContext* TypeScriptParser::ForStatementContext::statement() {
  return getRuleContext<TypeScriptParser::StatementContext>(0);
}

TypeScriptParser::ForConditionContext* TypeScriptParser::ForStatementContext::forCondition() {
  return getRuleContext<TypeScriptParser::ForConditionContext>(0);
}

TypeScriptParser::ExpressionSequenceContext* TypeScriptParser::ForStatementContext::expressionSequence() {
  return getRuleContext<TypeScriptParser::ExpressionSequenceContext>(0);
}

TypeScriptParser::ForStatementContext::ForStatementContext(IterationStatementContext *ctx) { copyFrom(ctx); }

void TypeScriptParser::ForStatementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TypeScriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterForStatement(this);
}
void TypeScriptParser::ForStatementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TypeScriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitForStatement(this);
}

antlrcpp::Any TypeScriptParser::ForStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TypeScriptParserVisitor*>(visitor))
    return parserVisitor->visitForStatement(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ForInStatementContext ------------------------------------------------------------------

tree::TerminalNode* TypeScriptParser::ForInStatementContext::For() {
  return getToken(TypeScriptParser::For, 0);
}

tree::TerminalNode* TypeScriptParser::ForInStatementContext::OpenParen() {
  return getToken(TypeScriptParser::OpenParen, 0);
}

tree::TerminalNode* TypeScriptParser::ForInStatementContext::In() {
  return getToken(TypeScriptParser::In, 0);
}

TypeScriptParser::ExpressionSequenceContext* TypeScriptParser::ForInStatementContext::expressionSequence() {
  return getRuleContext<TypeScriptParser::ExpressionSequenceContext>(0);
}

tree::TerminalNode* TypeScriptParser::ForInStatementContext::CloseParen() {
  return getToken(TypeScriptParser::CloseParen, 0);
}

TypeScriptParser::StatementContext* TypeScriptParser::ForInStatementContext::statement() {
  return getRuleContext<TypeScriptParser::StatementContext>(0);
}

TypeScriptParser::SingleExpressionContext* TypeScriptParser::ForInStatementContext::singleExpression() {
  return getRuleContext<TypeScriptParser::SingleExpressionContext>(0);
}

TypeScriptParser::VariableStatementContext* TypeScriptParser::ForInStatementContext::variableStatement() {
  return getRuleContext<TypeScriptParser::VariableStatementContext>(0);
}

TypeScriptParser::ForInStatementContext::ForInStatementContext(IterationStatementContext *ctx) { copyFrom(ctx); }

void TypeScriptParser::ForInStatementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TypeScriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterForInStatement(this);
}
void TypeScriptParser::ForInStatementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TypeScriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitForInStatement(this);
}

antlrcpp::Any TypeScriptParser::ForInStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TypeScriptParserVisitor*>(visitor))
    return parserVisitor->visitForInStatement(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ForOfStatementContext ------------------------------------------------------------------

tree::TerminalNode* TypeScriptParser::ForOfStatementContext::For() {
  return getToken(TypeScriptParser::For, 0);
}

tree::TerminalNode* TypeScriptParser::ForOfStatementContext::OpenParen() {
  return getToken(TypeScriptParser::OpenParen, 0);
}

tree::TerminalNode* TypeScriptParser::ForOfStatementContext::Of() {
  return getToken(TypeScriptParser::Of, 0);
}

tree::TerminalNode* TypeScriptParser::ForOfStatementContext::Identifier() {
  return getToken(TypeScriptParser::Identifier, 0);
}

TypeScriptParser::ExpressionSequenceContext* TypeScriptParser::ForOfStatementContext::expressionSequence() {
  return getRuleContext<TypeScriptParser::ExpressionSequenceContext>(0);
}

tree::TerminalNode* TypeScriptParser::ForOfStatementContext::CloseParen() {
  return getToken(TypeScriptParser::CloseParen, 0);
}

TypeScriptParser::StatementContext* TypeScriptParser::ForOfStatementContext::statement() {
  return getRuleContext<TypeScriptParser::StatementContext>(0);
}

TypeScriptParser::SingleExpressionContext* TypeScriptParser::ForOfStatementContext::singleExpression() {
  return getRuleContext<TypeScriptParser::SingleExpressionContext>(0);
}

TypeScriptParser::VariableStatementContext* TypeScriptParser::ForOfStatementContext::variableStatement() {
  return getRuleContext<TypeScriptParser::VariableStatementContext>(0);
}

tree::TerminalNode* TypeScriptParser::ForOfStatementContext::Await() {
  return getToken(TypeScriptParser::Await, 0);
}

TypeScriptParser::ForOfStatementContext::ForOfStatementContext(IterationStatementContext *ctx) { copyFrom(ctx); }

void TypeScriptParser::ForOfStatementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TypeScriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterForOfStatement(this);
}
void TypeScriptParser::ForOfStatementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TypeScriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitForOfStatement(this);
}

antlrcpp::Any TypeScriptParser::ForOfStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TypeScriptParserVisitor*>(visitor))
    return parserVisitor->visitForOfStatement(this);
  else
    return visitor->visitChildren(this);
}
TypeScriptParser::IterationStatementContext* TypeScriptParser::iterationStatement() {
  IterationStatementContext *_localctx = _tracker.createInstance<IterationStatementContext>(_ctx, getState());
  enterRule(_localctx, 56, TypeScriptParser::RuleIterationStatement);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(384);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 28, _ctx)) {
    case 1: {
      _localctx = dynamic_cast<IterationStatementContext *>(_tracker.createInstance<TypeScriptParser::DoStatementContext>(_localctx));
      enterOuterAlt(_localctx, 1);
      setState(331);
      match(TypeScriptParser::Do);
      setState(332);
      statement();
      setState(333);
      match(TypeScriptParser::While);
      setState(334);
      match(TypeScriptParser::OpenParen);
      setState(335);
      expressionSequence();
      setState(336);
      match(TypeScriptParser::CloseParen);
      setState(337);
      eos();
      break;
    }

    case 2: {
      _localctx = dynamic_cast<IterationStatementContext *>(_tracker.createInstance<TypeScriptParser::WhileStatementContext>(_localctx));
      enterOuterAlt(_localctx, 2);
      setState(339);
      match(TypeScriptParser::While);
      setState(340);
      match(TypeScriptParser::OpenParen);
      setState(341);
      expressionSequence();
      setState(342);
      match(TypeScriptParser::CloseParen);
      setState(343);
      statement();
      break;
    }

    case 3: {
      _localctx = dynamic_cast<IterationStatementContext *>(_tracker.createInstance<TypeScriptParser::ForStatementContext>(_localctx));
      enterOuterAlt(_localctx, 3);
      setState(345);
      match(TypeScriptParser::For);
      setState(346);
      match(TypeScriptParser::OpenParen);
      setState(347);
      forInitialization();
      setState(349);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & ((1ULL << TypeScriptParser::RegularExpressionLiteral)
        | (1ULL << TypeScriptParser::OpenBracket)
        | (1ULL << TypeScriptParser::OpenParen)
        | (1ULL << TypeScriptParser::OpenBrace)
        | (1ULL << TypeScriptParser::PlusPlus)
        | (1ULL << TypeScriptParser::MinusMinus)
        | (1ULL << TypeScriptParser::Plus)
        | (1ULL << TypeScriptParser::Minus)
        | (1ULL << TypeScriptParser::BitNot)
        | (1ULL << TypeScriptParser::Not)
        | (1ULL << TypeScriptParser::NullLiteral)
        | (1ULL << TypeScriptParser::BooleanLiteral)
        | (1ULL << TypeScriptParser::DecimalLiteral))) != 0) || ((((_la - 71) & ~ 0x3fULL) == 0) &&
        ((1ULL << (_la - 71)) & ((1ULL << (TypeScriptParser::HexIntegerLiteral - 71))
        | (1ULL << (TypeScriptParser::OctalIntegerLiteral - 71))
        | (1ULL << (TypeScriptParser::OctalIntegerLiteral2 - 71))
        | (1ULL << (TypeScriptParser::BinaryIntegerLiteral - 71))
        | (1ULL << (TypeScriptParser::BigHexIntegerLiteral - 71))
        | (1ULL << (TypeScriptParser::BigOctalIntegerLiteral - 71))
        | (1ULL << (TypeScriptParser::BigBinaryIntegerLiteral - 71))
        | (1ULL << (TypeScriptParser::BigDecimalIntegerLiteral - 71))
        | (1ULL << (TypeScriptParser::Typeof - 71))
        | (1ULL << (TypeScriptParser::New - 71))
        | (1ULL << (TypeScriptParser::Void - 71))
        | (1ULL << (TypeScriptParser::Function - 71))
        | (1ULL << (TypeScriptParser::This - 71))
        | (1ULL << (TypeScriptParser::Delete - 71))
        | (1ULL << (TypeScriptParser::Class - 71))
        | (1ULL << (TypeScriptParser::Super - 71))
        | (1ULL << (TypeScriptParser::Import - 71))
        | (1ULL << (TypeScriptParser::Async - 71))
        | (1ULL << (TypeScriptParser::Await - 71))
        | (1ULL << (TypeScriptParser::Yield - 71))
        | (1ULL << (TypeScriptParser::Identifier - 71))
        | (1ULL << (TypeScriptParser::StringLiteral - 71))
        | (1ULL << (TypeScriptParser::TemplateStringLiteral - 71)))) != 0)) {
        setState(348);
        forCondition();
      }
      setState(351);
      match(TypeScriptParser::SemiColon);
      setState(353);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & ((1ULL << TypeScriptParser::RegularExpressionLiteral)
        | (1ULL << TypeScriptParser::OpenBracket)
        | (1ULL << TypeScriptParser::OpenParen)
        | (1ULL << TypeScriptParser::OpenBrace)
        | (1ULL << TypeScriptParser::PlusPlus)
        | (1ULL << TypeScriptParser::MinusMinus)
        | (1ULL << TypeScriptParser::Plus)
        | (1ULL << TypeScriptParser::Minus)
        | (1ULL << TypeScriptParser::BitNot)
        | (1ULL << TypeScriptParser::Not)
        | (1ULL << TypeScriptParser::NullLiteral)
        | (1ULL << TypeScriptParser::BooleanLiteral)
        | (1ULL << TypeScriptParser::DecimalLiteral))) != 0) || ((((_la - 71) & ~ 0x3fULL) == 0) &&
        ((1ULL << (_la - 71)) & ((1ULL << (TypeScriptParser::HexIntegerLiteral - 71))
        | (1ULL << (TypeScriptParser::OctalIntegerLiteral - 71))
        | (1ULL << (TypeScriptParser::OctalIntegerLiteral2 - 71))
        | (1ULL << (TypeScriptParser::BinaryIntegerLiteral - 71))
        | (1ULL << (TypeScriptParser::BigHexIntegerLiteral - 71))
        | (1ULL << (TypeScriptParser::BigOctalIntegerLiteral - 71))
        | (1ULL << (TypeScriptParser::BigBinaryIntegerLiteral - 71))
        | (1ULL << (TypeScriptParser::BigDecimalIntegerLiteral - 71))
        | (1ULL << (TypeScriptParser::Typeof - 71))
        | (1ULL << (TypeScriptParser::New - 71))
        | (1ULL << (TypeScriptParser::Void - 71))
        | (1ULL << (TypeScriptParser::Function - 71))
        | (1ULL << (TypeScriptParser::This - 71))
        | (1ULL << (TypeScriptParser::Delete - 71))
        | (1ULL << (TypeScriptParser::Class - 71))
        | (1ULL << (TypeScriptParser::Super - 71))
        | (1ULL << (TypeScriptParser::Import - 71))
        | (1ULL << (TypeScriptParser::Async - 71))
        | (1ULL << (TypeScriptParser::Await - 71))
        | (1ULL << (TypeScriptParser::Yield - 71))
        | (1ULL << (TypeScriptParser::Identifier - 71))
        | (1ULL << (TypeScriptParser::StringLiteral - 71))
        | (1ULL << (TypeScriptParser::TemplateStringLiteral - 71)))) != 0)) {
        setState(352);
        expressionSequence();
      }
      setState(355);
      match(TypeScriptParser::CloseParen);
      setState(356);
      statement();
      break;
    }

    case 4: {
      _localctx = dynamic_cast<IterationStatementContext *>(_tracker.createInstance<TypeScriptParser::ForInStatementContext>(_localctx));
      enterOuterAlt(_localctx, 4);
      setState(358);
      match(TypeScriptParser::For);
      setState(359);
      match(TypeScriptParser::OpenParen);
      setState(362);
      _errHandler->sync(this);
      switch (_input->LA(1)) {
        case TypeScriptParser::RegularExpressionLiteral:
        case TypeScriptParser::OpenBracket:
        case TypeScriptParser::OpenParen:
        case TypeScriptParser::OpenBrace:
        case TypeScriptParser::PlusPlus:
        case TypeScriptParser::MinusMinus:
        case TypeScriptParser::Plus:
        case TypeScriptParser::Minus:
        case TypeScriptParser::BitNot:
        case TypeScriptParser::Not:
        case TypeScriptParser::NullLiteral:
        case TypeScriptParser::BooleanLiteral:
        case TypeScriptParser::DecimalLiteral:
        case TypeScriptParser::HexIntegerLiteral:
        case TypeScriptParser::OctalIntegerLiteral:
        case TypeScriptParser::OctalIntegerLiteral2:
        case TypeScriptParser::BinaryIntegerLiteral:
        case TypeScriptParser::BigHexIntegerLiteral:
        case TypeScriptParser::BigOctalIntegerLiteral:
        case TypeScriptParser::BigBinaryIntegerLiteral:
        case TypeScriptParser::BigDecimalIntegerLiteral:
        case TypeScriptParser::Typeof:
        case TypeScriptParser::New:
        case TypeScriptParser::Void:
        case TypeScriptParser::Function:
        case TypeScriptParser::This:
        case TypeScriptParser::Delete:
        case TypeScriptParser::Class:
        case TypeScriptParser::Super:
        case TypeScriptParser::Import:
        case TypeScriptParser::Async:
        case TypeScriptParser::Await:
        case TypeScriptParser::Yield:
        case TypeScriptParser::Identifier:
        case TypeScriptParser::StringLiteral:
        case TypeScriptParser::TemplateStringLiteral: {
          setState(360);
          singleExpression(0);
          break;
        }

        case TypeScriptParser::Var:
        case TypeScriptParser::Const:
        case TypeScriptParser::Let: {
          setState(361);
          variableStatement();
          break;
        }

      default:
        throw NoViableAltException(this);
      }
      setState(364);
      match(TypeScriptParser::In);
      setState(365);
      expressionSequence();
      setState(366);
      match(TypeScriptParser::CloseParen);
      setState(367);
      statement();
      break;
    }

    case 5: {
      _localctx = dynamic_cast<IterationStatementContext *>(_tracker.createInstance<TypeScriptParser::ForOfStatementContext>(_localctx));
      enterOuterAlt(_localctx, 5);
      setState(369);
      match(TypeScriptParser::For);
      setState(371);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == TypeScriptParser::Await) {
        setState(370);
        match(TypeScriptParser::Await);
      }
      setState(373);
      match(TypeScriptParser::OpenParen);
      setState(376);
      _errHandler->sync(this);
      switch (_input->LA(1)) {
        case TypeScriptParser::RegularExpressionLiteral:
        case TypeScriptParser::OpenBracket:
        case TypeScriptParser::OpenParen:
        case TypeScriptParser::OpenBrace:
        case TypeScriptParser::PlusPlus:
        case TypeScriptParser::MinusMinus:
        case TypeScriptParser::Plus:
        case TypeScriptParser::Minus:
        case TypeScriptParser::BitNot:
        case TypeScriptParser::Not:
        case TypeScriptParser::NullLiteral:
        case TypeScriptParser::BooleanLiteral:
        case TypeScriptParser::DecimalLiteral:
        case TypeScriptParser::HexIntegerLiteral:
        case TypeScriptParser::OctalIntegerLiteral:
        case TypeScriptParser::OctalIntegerLiteral2:
        case TypeScriptParser::BinaryIntegerLiteral:
        case TypeScriptParser::BigHexIntegerLiteral:
        case TypeScriptParser::BigOctalIntegerLiteral:
        case TypeScriptParser::BigBinaryIntegerLiteral:
        case TypeScriptParser::BigDecimalIntegerLiteral:
        case TypeScriptParser::Typeof:
        case TypeScriptParser::New:
        case TypeScriptParser::Void:
        case TypeScriptParser::Function:
        case TypeScriptParser::This:
        case TypeScriptParser::Delete:
        case TypeScriptParser::Class:
        case TypeScriptParser::Super:
        case TypeScriptParser::Import:
        case TypeScriptParser::Async:
        case TypeScriptParser::Await:
        case TypeScriptParser::Yield:
        case TypeScriptParser::Identifier:
        case TypeScriptParser::StringLiteral:
        case TypeScriptParser::TemplateStringLiteral: {
          setState(374);
          singleExpression(0);
          break;
        }

        case TypeScriptParser::Var:
        case TypeScriptParser::Const:
        case TypeScriptParser::Let: {
          setState(375);
          variableStatement();
          break;
        }

      default:
        throw NoViableAltException(this);
      }
      setState(378);
      match(TypeScriptParser::Of);
      setState(379);
      match(TypeScriptParser::Identifier);
      setState(380);
      expressionSequence();
      setState(381);
      match(TypeScriptParser::CloseParen);
      setState(382);
      statement();
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ForInitializationContext ------------------------------------------------------------------

TypeScriptParser::ForInitializationContext::ForInitializationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* TypeScriptParser::ForInitializationContext::SemiColon() {
  return getToken(TypeScriptParser::SemiColon, 0);
}

TypeScriptParser::ExpressionSequenceContext* TypeScriptParser::ForInitializationContext::expressionSequence() {
  return getRuleContext<TypeScriptParser::ExpressionSequenceContext>(0);
}

TypeScriptParser::VariableStatementContext* TypeScriptParser::ForInitializationContext::variableStatement() {
  return getRuleContext<TypeScriptParser::VariableStatementContext>(0);
}


size_t TypeScriptParser::ForInitializationContext::getRuleIndex() const {
  return TypeScriptParser::RuleForInitialization;
}

void TypeScriptParser::ForInitializationContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TypeScriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterForInitialization(this);
}

void TypeScriptParser::ForInitializationContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TypeScriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitForInitialization(this);
}


antlrcpp::Any TypeScriptParser::ForInitializationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TypeScriptParserVisitor*>(visitor))
    return parserVisitor->visitForInitialization(this);
  else
    return visitor->visitChildren(this);
}

TypeScriptParser::ForInitializationContext* TypeScriptParser::forInitialization() {
  ForInitializationContext *_localctx = _tracker.createInstance<ForInitializationContext>(_ctx, getState());
  enterRule(_localctx, 58, TypeScriptParser::RuleForInitialization);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(391);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case TypeScriptParser::RegularExpressionLiteral:
      case TypeScriptParser::OpenBracket:
      case TypeScriptParser::OpenParen:
      case TypeScriptParser::OpenBrace:
      case TypeScriptParser::SemiColon:
      case TypeScriptParser::PlusPlus:
      case TypeScriptParser::MinusMinus:
      case TypeScriptParser::Plus:
      case TypeScriptParser::Minus:
      case TypeScriptParser::BitNot:
      case TypeScriptParser::Not:
      case TypeScriptParser::NullLiteral:
      case TypeScriptParser::BooleanLiteral:
      case TypeScriptParser::DecimalLiteral:
      case TypeScriptParser::HexIntegerLiteral:
      case TypeScriptParser::OctalIntegerLiteral:
      case TypeScriptParser::OctalIntegerLiteral2:
      case TypeScriptParser::BinaryIntegerLiteral:
      case TypeScriptParser::BigHexIntegerLiteral:
      case TypeScriptParser::BigOctalIntegerLiteral:
      case TypeScriptParser::BigBinaryIntegerLiteral:
      case TypeScriptParser::BigDecimalIntegerLiteral:
      case TypeScriptParser::Typeof:
      case TypeScriptParser::New:
      case TypeScriptParser::Void:
      case TypeScriptParser::Function:
      case TypeScriptParser::This:
      case TypeScriptParser::Delete:
      case TypeScriptParser::Class:
      case TypeScriptParser::Super:
      case TypeScriptParser::Import:
      case TypeScriptParser::Async:
      case TypeScriptParser::Await:
      case TypeScriptParser::Yield:
      case TypeScriptParser::Identifier:
      case TypeScriptParser::StringLiteral:
      case TypeScriptParser::TemplateStringLiteral: {
        enterOuterAlt(_localctx, 1);
        setState(387);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if ((((_la & ~ 0x3fULL) == 0) &&
          ((1ULL << _la) & ((1ULL << TypeScriptParser::RegularExpressionLiteral)
          | (1ULL << TypeScriptParser::OpenBracket)
          | (1ULL << TypeScriptParser::OpenParen)
          | (1ULL << TypeScriptParser::OpenBrace)
          | (1ULL << TypeScriptParser::PlusPlus)
          | (1ULL << TypeScriptParser::MinusMinus)
          | (1ULL << TypeScriptParser::Plus)
          | (1ULL << TypeScriptParser::Minus)
          | (1ULL << TypeScriptParser::BitNot)
          | (1ULL << TypeScriptParser::Not)
          | (1ULL << TypeScriptParser::NullLiteral)
          | (1ULL << TypeScriptParser::BooleanLiteral)
          | (1ULL << TypeScriptParser::DecimalLiteral))) != 0) || ((((_la - 71) & ~ 0x3fULL) == 0) &&
          ((1ULL << (_la - 71)) & ((1ULL << (TypeScriptParser::HexIntegerLiteral - 71))
          | (1ULL << (TypeScriptParser::OctalIntegerLiteral - 71))
          | (1ULL << (TypeScriptParser::OctalIntegerLiteral2 - 71))
          | (1ULL << (TypeScriptParser::BinaryIntegerLiteral - 71))
          | (1ULL << (TypeScriptParser::BigHexIntegerLiteral - 71))
          | (1ULL << (TypeScriptParser::BigOctalIntegerLiteral - 71))
          | (1ULL << (TypeScriptParser::BigBinaryIntegerLiteral - 71))
          | (1ULL << (TypeScriptParser::BigDecimalIntegerLiteral - 71))
          | (1ULL << (TypeScriptParser::Typeof - 71))
          | (1ULL << (TypeScriptParser::New - 71))
          | (1ULL << (TypeScriptParser::Void - 71))
          | (1ULL << (TypeScriptParser::Function - 71))
          | (1ULL << (TypeScriptParser::This - 71))
          | (1ULL << (TypeScriptParser::Delete - 71))
          | (1ULL << (TypeScriptParser::Class - 71))
          | (1ULL << (TypeScriptParser::Super - 71))
          | (1ULL << (TypeScriptParser::Import - 71))
          | (1ULL << (TypeScriptParser::Async - 71))
          | (1ULL << (TypeScriptParser::Await - 71))
          | (1ULL << (TypeScriptParser::Yield - 71))
          | (1ULL << (TypeScriptParser::Identifier - 71))
          | (1ULL << (TypeScriptParser::StringLiteral - 71))
          | (1ULL << (TypeScriptParser::TemplateStringLiteral - 71)))) != 0)) {
          setState(386);
          expressionSequence();
        }
        setState(389);
        match(TypeScriptParser::SemiColon);
        break;
      }

      case TypeScriptParser::Var:
      case TypeScriptParser::Const:
      case TypeScriptParser::Let: {
        enterOuterAlt(_localctx, 2);
        setState(390);
        variableStatement();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ForConditionContext ------------------------------------------------------------------

TypeScriptParser::ForConditionContext::ForConditionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

TypeScriptParser::ExpressionSequenceContext* TypeScriptParser::ForConditionContext::expressionSequence() {
  return getRuleContext<TypeScriptParser::ExpressionSequenceContext>(0);
}


size_t TypeScriptParser::ForConditionContext::getRuleIndex() const {
  return TypeScriptParser::RuleForCondition;
}

void TypeScriptParser::ForConditionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TypeScriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterForCondition(this);
}

void TypeScriptParser::ForConditionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TypeScriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitForCondition(this);
}


antlrcpp::Any TypeScriptParser::ForConditionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TypeScriptParserVisitor*>(visitor))
    return parserVisitor->visitForCondition(this);
  else
    return visitor->visitChildren(this);
}

TypeScriptParser::ForConditionContext* TypeScriptParser::forCondition() {
  ForConditionContext *_localctx = _tracker.createInstance<ForConditionContext>(_ctx, getState());
  enterRule(_localctx, 60, TypeScriptParser::RuleForCondition);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(393);
    expressionSequence();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- VarModifierContext ------------------------------------------------------------------

TypeScriptParser::VarModifierContext::VarModifierContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* TypeScriptParser::VarModifierContext::Var() {
  return getToken(TypeScriptParser::Var, 0);
}

tree::TerminalNode* TypeScriptParser::VarModifierContext::Let() {
  return getToken(TypeScriptParser::Let, 0);
}

tree::TerminalNode* TypeScriptParser::VarModifierContext::Const() {
  return getToken(TypeScriptParser::Const, 0);
}


size_t TypeScriptParser::VarModifierContext::getRuleIndex() const {
  return TypeScriptParser::RuleVarModifier;
}

void TypeScriptParser::VarModifierContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TypeScriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterVarModifier(this);
}

void TypeScriptParser::VarModifierContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TypeScriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitVarModifier(this);
}


antlrcpp::Any TypeScriptParser::VarModifierContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TypeScriptParserVisitor*>(visitor))
    return parserVisitor->visitVarModifier(this);
  else
    return visitor->visitChildren(this);
}

TypeScriptParser::VarModifierContext* TypeScriptParser::varModifier() {
  VarModifierContext *_localctx = _tracker.createInstance<VarModifierContext>(_ctx, getState());
  enterRule(_localctx, 62, TypeScriptParser::RuleVarModifier);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(395);
    _la = _input->LA(1);
    if (!(((((_la - 87) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 87)) & ((1ULL << (TypeScriptParser::Var - 87))
      | (1ULL << (TypeScriptParser::Const - 87))
      | (1ULL << (TypeScriptParser::Let - 87)))) != 0))) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ContinueStatementContext ------------------------------------------------------------------

TypeScriptParser::ContinueStatementContext::ContinueStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* TypeScriptParser::ContinueStatementContext::Continue() {
  return getToken(TypeScriptParser::Continue, 0);
}

TypeScriptParser::EosContext* TypeScriptParser::ContinueStatementContext::eos() {
  return getRuleContext<TypeScriptParser::EosContext>(0);
}

tree::TerminalNode* TypeScriptParser::ContinueStatementContext::Identifier() {
  return getToken(TypeScriptParser::Identifier, 0);
}


size_t TypeScriptParser::ContinueStatementContext::getRuleIndex() const {
  return TypeScriptParser::RuleContinueStatement;
}

void TypeScriptParser::ContinueStatementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TypeScriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterContinueStatement(this);
}

void TypeScriptParser::ContinueStatementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TypeScriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitContinueStatement(this);
}


antlrcpp::Any TypeScriptParser::ContinueStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TypeScriptParserVisitor*>(visitor))
    return parserVisitor->visitContinueStatement(this);
  else
    return visitor->visitChildren(this);
}

TypeScriptParser::ContinueStatementContext* TypeScriptParser::continueStatement() {
  ContinueStatementContext *_localctx = _tracker.createInstance<ContinueStatementContext>(_ctx, getState());
  enterRule(_localctx, 64, TypeScriptParser::RuleContinueStatement);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(397);
    match(TypeScriptParser::Continue);
    setState(399);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == TypeScriptParser::Identifier) {
      setState(398);
      match(TypeScriptParser::Identifier);
    }
    setState(401);
    eos();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- BreakStatementContext ------------------------------------------------------------------

TypeScriptParser::BreakStatementContext::BreakStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* TypeScriptParser::BreakStatementContext::Break() {
  return getToken(TypeScriptParser::Break, 0);
}

TypeScriptParser::EosContext* TypeScriptParser::BreakStatementContext::eos() {
  return getRuleContext<TypeScriptParser::EosContext>(0);
}

tree::TerminalNode* TypeScriptParser::BreakStatementContext::Identifier() {
  return getToken(TypeScriptParser::Identifier, 0);
}


size_t TypeScriptParser::BreakStatementContext::getRuleIndex() const {
  return TypeScriptParser::RuleBreakStatement;
}

void TypeScriptParser::BreakStatementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TypeScriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterBreakStatement(this);
}

void TypeScriptParser::BreakStatementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TypeScriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitBreakStatement(this);
}


antlrcpp::Any TypeScriptParser::BreakStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TypeScriptParserVisitor*>(visitor))
    return parserVisitor->visitBreakStatement(this);
  else
    return visitor->visitChildren(this);
}

TypeScriptParser::BreakStatementContext* TypeScriptParser::breakStatement() {
  BreakStatementContext *_localctx = _tracker.createInstance<BreakStatementContext>(_ctx, getState());
  enterRule(_localctx, 66, TypeScriptParser::RuleBreakStatement);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(403);
    match(TypeScriptParser::Break);
    setState(405);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == TypeScriptParser::Identifier) {
      setState(404);
      match(TypeScriptParser::Identifier);
    }
    setState(407);
    eos();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ReturnStatementContext ------------------------------------------------------------------

TypeScriptParser::ReturnStatementContext::ReturnStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* TypeScriptParser::ReturnStatementContext::Return() {
  return getToken(TypeScriptParser::Return, 0);
}

TypeScriptParser::EosContext* TypeScriptParser::ReturnStatementContext::eos() {
  return getRuleContext<TypeScriptParser::EosContext>(0);
}

TypeScriptParser::ExpressionSequenceContext* TypeScriptParser::ReturnStatementContext::expressionSequence() {
  return getRuleContext<TypeScriptParser::ExpressionSequenceContext>(0);
}


size_t TypeScriptParser::ReturnStatementContext::getRuleIndex() const {
  return TypeScriptParser::RuleReturnStatement;
}

void TypeScriptParser::ReturnStatementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TypeScriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterReturnStatement(this);
}

void TypeScriptParser::ReturnStatementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TypeScriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitReturnStatement(this);
}


antlrcpp::Any TypeScriptParser::ReturnStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TypeScriptParserVisitor*>(visitor))
    return parserVisitor->visitReturnStatement(this);
  else
    return visitor->visitChildren(this);
}

TypeScriptParser::ReturnStatementContext* TypeScriptParser::returnStatement() {
  ReturnStatementContext *_localctx = _tracker.createInstance<ReturnStatementContext>(_ctx, getState());
  enterRule(_localctx, 68, TypeScriptParser::RuleReturnStatement);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(409);
    match(TypeScriptParser::Return);
    setState(411);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << TypeScriptParser::RegularExpressionLiteral)
      | (1ULL << TypeScriptParser::OpenBracket)
      | (1ULL << TypeScriptParser::OpenParen)
      | (1ULL << TypeScriptParser::OpenBrace)
      | (1ULL << TypeScriptParser::PlusPlus)
      | (1ULL << TypeScriptParser::MinusMinus)
      | (1ULL << TypeScriptParser::Plus)
      | (1ULL << TypeScriptParser::Minus)
      | (1ULL << TypeScriptParser::BitNot)
      | (1ULL << TypeScriptParser::Not)
      | (1ULL << TypeScriptParser::NullLiteral)
      | (1ULL << TypeScriptParser::BooleanLiteral)
      | (1ULL << TypeScriptParser::DecimalLiteral))) != 0) || ((((_la - 71) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 71)) & ((1ULL << (TypeScriptParser::HexIntegerLiteral - 71))
      | (1ULL << (TypeScriptParser::OctalIntegerLiteral - 71))
      | (1ULL << (TypeScriptParser::OctalIntegerLiteral2 - 71))
      | (1ULL << (TypeScriptParser::BinaryIntegerLiteral - 71))
      | (1ULL << (TypeScriptParser::BigHexIntegerLiteral - 71))
      | (1ULL << (TypeScriptParser::BigOctalIntegerLiteral - 71))
      | (1ULL << (TypeScriptParser::BigBinaryIntegerLiteral - 71))
      | (1ULL << (TypeScriptParser::BigDecimalIntegerLiteral - 71))
      | (1ULL << (TypeScriptParser::Typeof - 71))
      | (1ULL << (TypeScriptParser::New - 71))
      | (1ULL << (TypeScriptParser::Void - 71))
      | (1ULL << (TypeScriptParser::Function - 71))
      | (1ULL << (TypeScriptParser::This - 71))
      | (1ULL << (TypeScriptParser::Delete - 71))
      | (1ULL << (TypeScriptParser::Class - 71))
      | (1ULL << (TypeScriptParser::Super - 71))
      | (1ULL << (TypeScriptParser::Import - 71))
      | (1ULL << (TypeScriptParser::Async - 71))
      | (1ULL << (TypeScriptParser::Await - 71))
      | (1ULL << (TypeScriptParser::Yield - 71))
      | (1ULL << (TypeScriptParser::Identifier - 71))
      | (1ULL << (TypeScriptParser::StringLiteral - 71))
      | (1ULL << (TypeScriptParser::TemplateStringLiteral - 71)))) != 0)) {
      setState(410);
      expressionSequence();
    }
    setState(413);
    eos();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- YieldStatementContext ------------------------------------------------------------------

TypeScriptParser::YieldStatementContext::YieldStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* TypeScriptParser::YieldStatementContext::Yield() {
  return getToken(TypeScriptParser::Yield, 0);
}

TypeScriptParser::EosContext* TypeScriptParser::YieldStatementContext::eos() {
  return getRuleContext<TypeScriptParser::EosContext>(0);
}

TypeScriptParser::ExpressionSequenceContext* TypeScriptParser::YieldStatementContext::expressionSequence() {
  return getRuleContext<TypeScriptParser::ExpressionSequenceContext>(0);
}


size_t TypeScriptParser::YieldStatementContext::getRuleIndex() const {
  return TypeScriptParser::RuleYieldStatement;
}

void TypeScriptParser::YieldStatementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TypeScriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterYieldStatement(this);
}

void TypeScriptParser::YieldStatementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TypeScriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitYieldStatement(this);
}


antlrcpp::Any TypeScriptParser::YieldStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TypeScriptParserVisitor*>(visitor))
    return parserVisitor->visitYieldStatement(this);
  else
    return visitor->visitChildren(this);
}

TypeScriptParser::YieldStatementContext* TypeScriptParser::yieldStatement() {
  YieldStatementContext *_localctx = _tracker.createInstance<YieldStatementContext>(_ctx, getState());
  enterRule(_localctx, 70, TypeScriptParser::RuleYieldStatement);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(415);
    match(TypeScriptParser::Yield);
    setState(417);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << TypeScriptParser::RegularExpressionLiteral)
      | (1ULL << TypeScriptParser::OpenBracket)
      | (1ULL << TypeScriptParser::OpenParen)
      | (1ULL << TypeScriptParser::OpenBrace)
      | (1ULL << TypeScriptParser::PlusPlus)
      | (1ULL << TypeScriptParser::MinusMinus)
      | (1ULL << TypeScriptParser::Plus)
      | (1ULL << TypeScriptParser::Minus)
      | (1ULL << TypeScriptParser::BitNot)
      | (1ULL << TypeScriptParser::Not)
      | (1ULL << TypeScriptParser::NullLiteral)
      | (1ULL << TypeScriptParser::BooleanLiteral)
      | (1ULL << TypeScriptParser::DecimalLiteral))) != 0) || ((((_la - 71) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 71)) & ((1ULL << (TypeScriptParser::HexIntegerLiteral - 71))
      | (1ULL << (TypeScriptParser::OctalIntegerLiteral - 71))
      | (1ULL << (TypeScriptParser::OctalIntegerLiteral2 - 71))
      | (1ULL << (TypeScriptParser::BinaryIntegerLiteral - 71))
      | (1ULL << (TypeScriptParser::BigHexIntegerLiteral - 71))
      | (1ULL << (TypeScriptParser::BigOctalIntegerLiteral - 71))
      | (1ULL << (TypeScriptParser::BigBinaryIntegerLiteral - 71))
      | (1ULL << (TypeScriptParser::BigDecimalIntegerLiteral - 71))
      | (1ULL << (TypeScriptParser::Typeof - 71))
      | (1ULL << (TypeScriptParser::New - 71))
      | (1ULL << (TypeScriptParser::Void - 71))
      | (1ULL << (TypeScriptParser::Function - 71))
      | (1ULL << (TypeScriptParser::This - 71))
      | (1ULL << (TypeScriptParser::Delete - 71))
      | (1ULL << (TypeScriptParser::Class - 71))
      | (1ULL << (TypeScriptParser::Super - 71))
      | (1ULL << (TypeScriptParser::Import - 71))
      | (1ULL << (TypeScriptParser::Async - 71))
      | (1ULL << (TypeScriptParser::Await - 71))
      | (1ULL << (TypeScriptParser::Yield - 71))
      | (1ULL << (TypeScriptParser::Identifier - 71))
      | (1ULL << (TypeScriptParser::StringLiteral - 71))
      | (1ULL << (TypeScriptParser::TemplateStringLiteral - 71)))) != 0)) {
      setState(416);
      expressionSequence();
    }
    setState(419);
    eos();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- WithStatementContext ------------------------------------------------------------------

TypeScriptParser::WithStatementContext::WithStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* TypeScriptParser::WithStatementContext::With() {
  return getToken(TypeScriptParser::With, 0);
}

tree::TerminalNode* TypeScriptParser::WithStatementContext::OpenParen() {
  return getToken(TypeScriptParser::OpenParen, 0);
}

TypeScriptParser::ExpressionSequenceContext* TypeScriptParser::WithStatementContext::expressionSequence() {
  return getRuleContext<TypeScriptParser::ExpressionSequenceContext>(0);
}

tree::TerminalNode* TypeScriptParser::WithStatementContext::CloseParen() {
  return getToken(TypeScriptParser::CloseParen, 0);
}

TypeScriptParser::StatementContext* TypeScriptParser::WithStatementContext::statement() {
  return getRuleContext<TypeScriptParser::StatementContext>(0);
}


size_t TypeScriptParser::WithStatementContext::getRuleIndex() const {
  return TypeScriptParser::RuleWithStatement;
}

void TypeScriptParser::WithStatementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TypeScriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterWithStatement(this);
}

void TypeScriptParser::WithStatementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TypeScriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitWithStatement(this);
}


antlrcpp::Any TypeScriptParser::WithStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TypeScriptParserVisitor*>(visitor))
    return parserVisitor->visitWithStatement(this);
  else
    return visitor->visitChildren(this);
}

TypeScriptParser::WithStatementContext* TypeScriptParser::withStatement() {
  WithStatementContext *_localctx = _tracker.createInstance<WithStatementContext>(_ctx, getState());
  enterRule(_localctx, 72, TypeScriptParser::RuleWithStatement);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(421);
    match(TypeScriptParser::With);
    setState(422);
    match(TypeScriptParser::OpenParen);
    setState(423);
    expressionSequence();
    setState(424);
    match(TypeScriptParser::CloseParen);
    setState(425);
    statement();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- SwitchStatementContext ------------------------------------------------------------------

TypeScriptParser::SwitchStatementContext::SwitchStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* TypeScriptParser::SwitchStatementContext::Switch() {
  return getToken(TypeScriptParser::Switch, 0);
}

tree::TerminalNode* TypeScriptParser::SwitchStatementContext::OpenParen() {
  return getToken(TypeScriptParser::OpenParen, 0);
}

TypeScriptParser::ExpressionSequenceContext* TypeScriptParser::SwitchStatementContext::expressionSequence() {
  return getRuleContext<TypeScriptParser::ExpressionSequenceContext>(0);
}

tree::TerminalNode* TypeScriptParser::SwitchStatementContext::CloseParen() {
  return getToken(TypeScriptParser::CloseParen, 0);
}

TypeScriptParser::CaseBlockContext* TypeScriptParser::SwitchStatementContext::caseBlock() {
  return getRuleContext<TypeScriptParser::CaseBlockContext>(0);
}


size_t TypeScriptParser::SwitchStatementContext::getRuleIndex() const {
  return TypeScriptParser::RuleSwitchStatement;
}

void TypeScriptParser::SwitchStatementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TypeScriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSwitchStatement(this);
}

void TypeScriptParser::SwitchStatementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TypeScriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSwitchStatement(this);
}


antlrcpp::Any TypeScriptParser::SwitchStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TypeScriptParserVisitor*>(visitor))
    return parserVisitor->visitSwitchStatement(this);
  else
    return visitor->visitChildren(this);
}

TypeScriptParser::SwitchStatementContext* TypeScriptParser::switchStatement() {
  SwitchStatementContext *_localctx = _tracker.createInstance<SwitchStatementContext>(_ctx, getState());
  enterRule(_localctx, 74, TypeScriptParser::RuleSwitchStatement);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(427);
    match(TypeScriptParser::Switch);
    setState(428);
    match(TypeScriptParser::OpenParen);
    setState(429);
    expressionSequence();
    setState(430);
    match(TypeScriptParser::CloseParen);
    setState(431);
    caseBlock();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- CaseBlockContext ------------------------------------------------------------------

TypeScriptParser::CaseBlockContext::CaseBlockContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* TypeScriptParser::CaseBlockContext::OpenBrace() {
  return getToken(TypeScriptParser::OpenBrace, 0);
}

tree::TerminalNode* TypeScriptParser::CaseBlockContext::CloseBrace() {
  return getToken(TypeScriptParser::CloseBrace, 0);
}

std::vector<TypeScriptParser::CaseClauseContext *> TypeScriptParser::CaseBlockContext::caseClause() {
  return getRuleContexts<TypeScriptParser::CaseClauseContext>();
}

TypeScriptParser::CaseClauseContext* TypeScriptParser::CaseBlockContext::caseClause(size_t i) {
  return getRuleContext<TypeScriptParser::CaseClauseContext>(i);
}


size_t TypeScriptParser::CaseBlockContext::getRuleIndex() const {
  return TypeScriptParser::RuleCaseBlock;
}

void TypeScriptParser::CaseBlockContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TypeScriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterCaseBlock(this);
}

void TypeScriptParser::CaseBlockContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TypeScriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitCaseBlock(this);
}


antlrcpp::Any TypeScriptParser::CaseBlockContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TypeScriptParserVisitor*>(visitor))
    return parserVisitor->visitCaseBlock(this);
  else
    return visitor->visitChildren(this);
}

TypeScriptParser::CaseBlockContext* TypeScriptParser::caseBlock() {
  CaseBlockContext *_localctx = _tracker.createInstance<CaseBlockContext>(_ctx, getState());
  enterRule(_localctx, 76, TypeScriptParser::RuleCaseBlock);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(433);
    match(TypeScriptParser::OpenBrace);
    setState(437);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == TypeScriptParser::Case

    || _la == TypeScriptParser::Default) {
      setState(434);
      caseClause();
      setState(439);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(440);
    match(TypeScriptParser::CloseBrace);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- CaseClauseContext ------------------------------------------------------------------

TypeScriptParser::CaseClauseContext::CaseClauseContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t TypeScriptParser::CaseClauseContext::getRuleIndex() const {
  return TypeScriptParser::RuleCaseClause;
}

void TypeScriptParser::CaseClauseContext::copyFrom(CaseClauseContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- SwitchCaseClauseContext ------------------------------------------------------------------

tree::TerminalNode* TypeScriptParser::SwitchCaseClauseContext::Case() {
  return getToken(TypeScriptParser::Case, 0);
}

TypeScriptParser::ExpressionSequenceContext* TypeScriptParser::SwitchCaseClauseContext::expressionSequence() {
  return getRuleContext<TypeScriptParser::ExpressionSequenceContext>(0);
}

tree::TerminalNode* TypeScriptParser::SwitchCaseClauseContext::Colon() {
  return getToken(TypeScriptParser::Colon, 0);
}

TypeScriptParser::StatementListContext* TypeScriptParser::SwitchCaseClauseContext::statementList() {
  return getRuleContext<TypeScriptParser::StatementListContext>(0);
}

TypeScriptParser::SwitchCaseClauseContext::SwitchCaseClauseContext(CaseClauseContext *ctx) { copyFrom(ctx); }

void TypeScriptParser::SwitchCaseClauseContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TypeScriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSwitchCaseClause(this);
}
void TypeScriptParser::SwitchCaseClauseContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TypeScriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSwitchCaseClause(this);
}

antlrcpp::Any TypeScriptParser::SwitchCaseClauseContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TypeScriptParserVisitor*>(visitor))
    return parserVisitor->visitSwitchCaseClause(this);
  else
    return visitor->visitChildren(this);
}
//----------------- SwitchDefaultClauseContext ------------------------------------------------------------------

tree::TerminalNode* TypeScriptParser::SwitchDefaultClauseContext::Default() {
  return getToken(TypeScriptParser::Default, 0);
}

tree::TerminalNode* TypeScriptParser::SwitchDefaultClauseContext::Colon() {
  return getToken(TypeScriptParser::Colon, 0);
}

TypeScriptParser::StatementListContext* TypeScriptParser::SwitchDefaultClauseContext::statementList() {
  return getRuleContext<TypeScriptParser::StatementListContext>(0);
}

TypeScriptParser::SwitchDefaultClauseContext::SwitchDefaultClauseContext(CaseClauseContext *ctx) { copyFrom(ctx); }

void TypeScriptParser::SwitchDefaultClauseContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TypeScriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSwitchDefaultClause(this);
}
void TypeScriptParser::SwitchDefaultClauseContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TypeScriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSwitchDefaultClause(this);
}

antlrcpp::Any TypeScriptParser::SwitchDefaultClauseContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TypeScriptParserVisitor*>(visitor))
    return parserVisitor->visitSwitchDefaultClause(this);
  else
    return visitor->visitChildren(this);
}
TypeScriptParser::CaseClauseContext* TypeScriptParser::caseClause() {
  CaseClauseContext *_localctx = _tracker.createInstance<CaseClauseContext>(_ctx, getState());
  enterRule(_localctx, 78, TypeScriptParser::RuleCaseClause);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(453);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case TypeScriptParser::Default: {
        _localctx = dynamic_cast<CaseClauseContext *>(_tracker.createInstance<TypeScriptParser::SwitchDefaultClauseContext>(_localctx));
        enterOuterAlt(_localctx, 1);
        setState(442);
        match(TypeScriptParser::Default);
        setState(443);
        match(TypeScriptParser::Colon);
        setState(445);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if ((((_la & ~ 0x3fULL) == 0) &&
          ((1ULL << _la) & ((1ULL << TypeScriptParser::RegularExpressionLiteral)
          | (1ULL << TypeScriptParser::OpenBracket)
          | (1ULL << TypeScriptParser::OpenParen)
          | (1ULL << TypeScriptParser::OpenBrace)
          | (1ULL << TypeScriptParser::SemiColon)
          | (1ULL << TypeScriptParser::PlusPlus)
          | (1ULL << TypeScriptParser::MinusMinus)
          | (1ULL << TypeScriptParser::Plus)
          | (1ULL << TypeScriptParser::Minus)
          | (1ULL << TypeScriptParser::BitNot)
          | (1ULL << TypeScriptParser::Not)
          | (1ULL << TypeScriptParser::NullLiteral)
          | (1ULL << TypeScriptParser::BooleanLiteral)
          | (1ULL << TypeScriptParser::DecimalLiteral))) != 0) || ((((_la - 71) & ~ 0x3fULL) == 0) &&
          ((1ULL << (_la - 71)) & ((1ULL << (TypeScriptParser::HexIntegerLiteral - 71))
          | (1ULL << (TypeScriptParser::OctalIntegerLiteral - 71))
          | (1ULL << (TypeScriptParser::OctalIntegerLiteral2 - 71))
          | (1ULL << (TypeScriptParser::BinaryIntegerLiteral - 71))
          | (1ULL << (TypeScriptParser::BigHexIntegerLiteral - 71))
          | (1ULL << (TypeScriptParser::BigOctalIntegerLiteral - 71))
          | (1ULL << (TypeScriptParser::BigBinaryIntegerLiteral - 71))
          | (1ULL << (TypeScriptParser::BigDecimalIntegerLiteral - 71))
          | (1ULL << (TypeScriptParser::Break - 71))
          | (1ULL << (TypeScriptParser::Do - 71))
          | (1ULL << (TypeScriptParser::Typeof - 71))
          | (1ULL << (TypeScriptParser::New - 71))
          | (1ULL << (TypeScriptParser::Var - 71))
          | (1ULL << (TypeScriptParser::Return - 71))
          | (1ULL << (TypeScriptParser::Void - 71))
          | (1ULL << (TypeScriptParser::Continue - 71))
          | (1ULL << (TypeScriptParser::For - 71))
          | (1ULL << (TypeScriptParser::Switch - 71))
          | (1ULL << (TypeScriptParser::While - 71))
          | (1ULL << (TypeScriptParser::Debugger - 71))
          | (1ULL << (TypeScriptParser::Function - 71))
          | (1ULL << (TypeScriptParser::This - 71))
          | (1ULL << (TypeScriptParser::With - 71))
          | (1ULL << (TypeScriptParser::If - 71))
          | (1ULL << (TypeScriptParser::Throw - 71))
          | (1ULL << (TypeScriptParser::Delete - 71))
          | (1ULL << (TypeScriptParser::Try - 71))
          | (1ULL << (TypeScriptParser::Class - 71))
          | (1ULL << (TypeScriptParser::Super - 71))
          | (1ULL << (TypeScriptParser::Const - 71))
          | (1ULL << (TypeScriptParser::Export - 71))
          | (1ULL << (TypeScriptParser::Import - 71))
          | (1ULL << (TypeScriptParser::Async - 71))
          | (1ULL << (TypeScriptParser::Await - 71))
          | (1ULL << (TypeScriptParser::Let - 71))
          | (1ULL << (TypeScriptParser::Static - 71))
          | (1ULL << (TypeScriptParser::Final - 71))
          | (1ULL << (TypeScriptParser::Yield - 71))
          | (1ULL << (TypeScriptParser::Identifier - 71))
          | (1ULL << (TypeScriptParser::StringLiteral - 71))
          | (1ULL << (TypeScriptParser::TemplateStringLiteral - 71)))) != 0)) {
          setState(444);
          statementList();
        }
        break;
      }

      case TypeScriptParser::Case: {
        _localctx = dynamic_cast<CaseClauseContext *>(_tracker.createInstance<TypeScriptParser::SwitchCaseClauseContext>(_localctx));
        enterOuterAlt(_localctx, 2);
        setState(447);
        match(TypeScriptParser::Case);
        setState(448);
        expressionSequence();
        setState(449);
        match(TypeScriptParser::Colon);
        setState(451);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if ((((_la & ~ 0x3fULL) == 0) &&
          ((1ULL << _la) & ((1ULL << TypeScriptParser::RegularExpressionLiteral)
          | (1ULL << TypeScriptParser::OpenBracket)
          | (1ULL << TypeScriptParser::OpenParen)
          | (1ULL << TypeScriptParser::OpenBrace)
          | (1ULL << TypeScriptParser::SemiColon)
          | (1ULL << TypeScriptParser::PlusPlus)
          | (1ULL << TypeScriptParser::MinusMinus)
          | (1ULL << TypeScriptParser::Plus)
          | (1ULL << TypeScriptParser::Minus)
          | (1ULL << TypeScriptParser::BitNot)
          | (1ULL << TypeScriptParser::Not)
          | (1ULL << TypeScriptParser::NullLiteral)
          | (1ULL << TypeScriptParser::BooleanLiteral)
          | (1ULL << TypeScriptParser::DecimalLiteral))) != 0) || ((((_la - 71) & ~ 0x3fULL) == 0) &&
          ((1ULL << (_la - 71)) & ((1ULL << (TypeScriptParser::HexIntegerLiteral - 71))
          | (1ULL << (TypeScriptParser::OctalIntegerLiteral - 71))
          | (1ULL << (TypeScriptParser::OctalIntegerLiteral2 - 71))
          | (1ULL << (TypeScriptParser::BinaryIntegerLiteral - 71))
          | (1ULL << (TypeScriptParser::BigHexIntegerLiteral - 71))
          | (1ULL << (TypeScriptParser::BigOctalIntegerLiteral - 71))
          | (1ULL << (TypeScriptParser::BigBinaryIntegerLiteral - 71))
          | (1ULL << (TypeScriptParser::BigDecimalIntegerLiteral - 71))
          | (1ULL << (TypeScriptParser::Break - 71))
          | (1ULL << (TypeScriptParser::Do - 71))
          | (1ULL << (TypeScriptParser::Typeof - 71))
          | (1ULL << (TypeScriptParser::New - 71))
          | (1ULL << (TypeScriptParser::Var - 71))
          | (1ULL << (TypeScriptParser::Return - 71))
          | (1ULL << (TypeScriptParser::Void - 71))
          | (1ULL << (TypeScriptParser::Continue - 71))
          | (1ULL << (TypeScriptParser::For - 71))
          | (1ULL << (TypeScriptParser::Switch - 71))
          | (1ULL << (TypeScriptParser::While - 71))
          | (1ULL << (TypeScriptParser::Debugger - 71))
          | (1ULL << (TypeScriptParser::Function - 71))
          | (1ULL << (TypeScriptParser::This - 71))
          | (1ULL << (TypeScriptParser::With - 71))
          | (1ULL << (TypeScriptParser::If - 71))
          | (1ULL << (TypeScriptParser::Throw - 71))
          | (1ULL << (TypeScriptParser::Delete - 71))
          | (1ULL << (TypeScriptParser::Try - 71))
          | (1ULL << (TypeScriptParser::Class - 71))
          | (1ULL << (TypeScriptParser::Super - 71))
          | (1ULL << (TypeScriptParser::Const - 71))
          | (1ULL << (TypeScriptParser::Export - 71))
          | (1ULL << (TypeScriptParser::Import - 71))
          | (1ULL << (TypeScriptParser::Async - 71))
          | (1ULL << (TypeScriptParser::Await - 71))
          | (1ULL << (TypeScriptParser::Let - 71))
          | (1ULL << (TypeScriptParser::Static - 71))
          | (1ULL << (TypeScriptParser::Final - 71))
          | (1ULL << (TypeScriptParser::Yield - 71))
          | (1ULL << (TypeScriptParser::Identifier - 71))
          | (1ULL << (TypeScriptParser::StringLiteral - 71))
          | (1ULL << (TypeScriptParser::TemplateStringLiteral - 71)))) != 0)) {
          setState(450);
          statementList();
        }
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- LabelledStatementContext ------------------------------------------------------------------

TypeScriptParser::LabelledStatementContext::LabelledStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* TypeScriptParser::LabelledStatementContext::Identifier() {
  return getToken(TypeScriptParser::Identifier, 0);
}

tree::TerminalNode* TypeScriptParser::LabelledStatementContext::Colon() {
  return getToken(TypeScriptParser::Colon, 0);
}

TypeScriptParser::StatementContext* TypeScriptParser::LabelledStatementContext::statement() {
  return getRuleContext<TypeScriptParser::StatementContext>(0);
}


size_t TypeScriptParser::LabelledStatementContext::getRuleIndex() const {
  return TypeScriptParser::RuleLabelledStatement;
}

void TypeScriptParser::LabelledStatementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TypeScriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterLabelledStatement(this);
}

void TypeScriptParser::LabelledStatementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TypeScriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitLabelledStatement(this);
}


antlrcpp::Any TypeScriptParser::LabelledStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TypeScriptParserVisitor*>(visitor))
    return parserVisitor->visitLabelledStatement(this);
  else
    return visitor->visitChildren(this);
}

TypeScriptParser::LabelledStatementContext* TypeScriptParser::labelledStatement() {
  LabelledStatementContext *_localctx = _tracker.createInstance<LabelledStatementContext>(_ctx, getState());
  enterRule(_localctx, 80, TypeScriptParser::RuleLabelledStatement);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(455);
    match(TypeScriptParser::Identifier);
    setState(456);
    match(TypeScriptParser::Colon);
    setState(457);
    statement();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ThrowStatementContext ------------------------------------------------------------------

TypeScriptParser::ThrowStatementContext::ThrowStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* TypeScriptParser::ThrowStatementContext::Throw() {
  return getToken(TypeScriptParser::Throw, 0);
}

TypeScriptParser::ExpressionSequenceContext* TypeScriptParser::ThrowStatementContext::expressionSequence() {
  return getRuleContext<TypeScriptParser::ExpressionSequenceContext>(0);
}

TypeScriptParser::EosContext* TypeScriptParser::ThrowStatementContext::eos() {
  return getRuleContext<TypeScriptParser::EosContext>(0);
}


size_t TypeScriptParser::ThrowStatementContext::getRuleIndex() const {
  return TypeScriptParser::RuleThrowStatement;
}

void TypeScriptParser::ThrowStatementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TypeScriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterThrowStatement(this);
}

void TypeScriptParser::ThrowStatementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TypeScriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitThrowStatement(this);
}


antlrcpp::Any TypeScriptParser::ThrowStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TypeScriptParserVisitor*>(visitor))
    return parserVisitor->visitThrowStatement(this);
  else
    return visitor->visitChildren(this);
}

TypeScriptParser::ThrowStatementContext* TypeScriptParser::throwStatement() {
  ThrowStatementContext *_localctx = _tracker.createInstance<ThrowStatementContext>(_ctx, getState());
  enterRule(_localctx, 82, TypeScriptParser::RuleThrowStatement);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(459);
    match(TypeScriptParser::Throw);
    setState(460);
    expressionSequence();
    setState(461);
    eos();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- TryStatementContext ------------------------------------------------------------------

TypeScriptParser::TryStatementContext::TryStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* TypeScriptParser::TryStatementContext::Try() {
  return getToken(TypeScriptParser::Try, 0);
}

TypeScriptParser::BlockContext* TypeScriptParser::TryStatementContext::block() {
  return getRuleContext<TypeScriptParser::BlockContext>(0);
}

TypeScriptParser::CatchProductionContext* TypeScriptParser::TryStatementContext::catchProduction() {
  return getRuleContext<TypeScriptParser::CatchProductionContext>(0);
}

TypeScriptParser::FinallyProductionContext* TypeScriptParser::TryStatementContext::finallyProduction() {
  return getRuleContext<TypeScriptParser::FinallyProductionContext>(0);
}


size_t TypeScriptParser::TryStatementContext::getRuleIndex() const {
  return TypeScriptParser::RuleTryStatement;
}

void TypeScriptParser::TryStatementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TypeScriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterTryStatement(this);
}

void TypeScriptParser::TryStatementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TypeScriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitTryStatement(this);
}


antlrcpp::Any TypeScriptParser::TryStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TypeScriptParserVisitor*>(visitor))
    return parserVisitor->visitTryStatement(this);
  else
    return visitor->visitChildren(this);
}

TypeScriptParser::TryStatementContext* TypeScriptParser::tryStatement() {
  TryStatementContext *_localctx = _tracker.createInstance<TryStatementContext>(_ctx, getState());
  enterRule(_localctx, 84, TypeScriptParser::RuleTryStatement);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(463);
    match(TypeScriptParser::Try);
    setState(464);
    block();
    setState(470);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case TypeScriptParser::Catch: {
        setState(465);
        catchProduction();
        setState(467);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == TypeScriptParser::Finally) {
          setState(466);
          finallyProduction();
        }
        break;
      }

      case TypeScriptParser::Finally: {
        setState(469);
        finallyProduction();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- CatchProductionContext ------------------------------------------------------------------

TypeScriptParser::CatchProductionContext::CatchProductionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* TypeScriptParser::CatchProductionContext::Catch() {
  return getToken(TypeScriptParser::Catch, 0);
}

TypeScriptParser::BlockContext* TypeScriptParser::CatchProductionContext::block() {
  return getRuleContext<TypeScriptParser::BlockContext>(0);
}

tree::TerminalNode* TypeScriptParser::CatchProductionContext::OpenParen() {
  return getToken(TypeScriptParser::OpenParen, 0);
}

tree::TerminalNode* TypeScriptParser::CatchProductionContext::CloseParen() {
  return getToken(TypeScriptParser::CloseParen, 0);
}

TypeScriptParser::AssignableContext* TypeScriptParser::CatchProductionContext::assignable() {
  return getRuleContext<TypeScriptParser::AssignableContext>(0);
}


size_t TypeScriptParser::CatchProductionContext::getRuleIndex() const {
  return TypeScriptParser::RuleCatchProduction;
}

void TypeScriptParser::CatchProductionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TypeScriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterCatchProduction(this);
}

void TypeScriptParser::CatchProductionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TypeScriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitCatchProduction(this);
}


antlrcpp::Any TypeScriptParser::CatchProductionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TypeScriptParserVisitor*>(visitor))
    return parserVisitor->visitCatchProduction(this);
  else
    return visitor->visitChildren(this);
}

TypeScriptParser::CatchProductionContext* TypeScriptParser::catchProduction() {
  CatchProductionContext *_localctx = _tracker.createInstance<CatchProductionContext>(_ctx, getState());
  enterRule(_localctx, 86, TypeScriptParser::RuleCatchProduction);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(472);
    match(TypeScriptParser::Catch);
    setState(478);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == TypeScriptParser::OpenParen) {
      setState(473);
      match(TypeScriptParser::OpenParen);
      setState(475);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == TypeScriptParser::OpenBracket

      || _la == TypeScriptParser::OpenBrace || _la == TypeScriptParser::Identifier) {
        setState(474);
        assignable();
      }
      setState(477);
      match(TypeScriptParser::CloseParen);
    }
    setState(480);
    block();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FinallyProductionContext ------------------------------------------------------------------

TypeScriptParser::FinallyProductionContext::FinallyProductionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* TypeScriptParser::FinallyProductionContext::Finally() {
  return getToken(TypeScriptParser::Finally, 0);
}

TypeScriptParser::BlockContext* TypeScriptParser::FinallyProductionContext::block() {
  return getRuleContext<TypeScriptParser::BlockContext>(0);
}


size_t TypeScriptParser::FinallyProductionContext::getRuleIndex() const {
  return TypeScriptParser::RuleFinallyProduction;
}

void TypeScriptParser::FinallyProductionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TypeScriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFinallyProduction(this);
}

void TypeScriptParser::FinallyProductionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TypeScriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFinallyProduction(this);
}


antlrcpp::Any TypeScriptParser::FinallyProductionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TypeScriptParserVisitor*>(visitor))
    return parserVisitor->visitFinallyProduction(this);
  else
    return visitor->visitChildren(this);
}

TypeScriptParser::FinallyProductionContext* TypeScriptParser::finallyProduction() {
  FinallyProductionContext *_localctx = _tracker.createInstance<FinallyProductionContext>(_ctx, getState());
  enterRule(_localctx, 88, TypeScriptParser::RuleFinallyProduction);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(482);
    match(TypeScriptParser::Finally);
    setState(483);
    block();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- DebuggerStatementContext ------------------------------------------------------------------

TypeScriptParser::DebuggerStatementContext::DebuggerStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* TypeScriptParser::DebuggerStatementContext::Debugger() {
  return getToken(TypeScriptParser::Debugger, 0);
}

TypeScriptParser::EosContext* TypeScriptParser::DebuggerStatementContext::eos() {
  return getRuleContext<TypeScriptParser::EosContext>(0);
}


size_t TypeScriptParser::DebuggerStatementContext::getRuleIndex() const {
  return TypeScriptParser::RuleDebuggerStatement;
}

void TypeScriptParser::DebuggerStatementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TypeScriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterDebuggerStatement(this);
}

void TypeScriptParser::DebuggerStatementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TypeScriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitDebuggerStatement(this);
}


antlrcpp::Any TypeScriptParser::DebuggerStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TypeScriptParserVisitor*>(visitor))
    return parserVisitor->visitDebuggerStatement(this);
  else
    return visitor->visitChildren(this);
}

TypeScriptParser::DebuggerStatementContext* TypeScriptParser::debuggerStatement() {
  DebuggerStatementContext *_localctx = _tracker.createInstance<DebuggerStatementContext>(_ctx, getState());
  enterRule(_localctx, 90, TypeScriptParser::RuleDebuggerStatement);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(485);
    match(TypeScriptParser::Debugger);
    setState(486);
    eos();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FunctionDeclarationContext ------------------------------------------------------------------

TypeScriptParser::FunctionDeclarationContext::FunctionDeclarationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* TypeScriptParser::FunctionDeclarationContext::Function() {
  return getToken(TypeScriptParser::Function, 0);
}

tree::TerminalNode* TypeScriptParser::FunctionDeclarationContext::Identifier() {
  return getToken(TypeScriptParser::Identifier, 0);
}

tree::TerminalNode* TypeScriptParser::FunctionDeclarationContext::OpenParen() {
  return getToken(TypeScriptParser::OpenParen, 0);
}

tree::TerminalNode* TypeScriptParser::FunctionDeclarationContext::CloseParen() {
  return getToken(TypeScriptParser::CloseParen, 0);
}

tree::TerminalNode* TypeScriptParser::FunctionDeclarationContext::OpenBrace() {
  return getToken(TypeScriptParser::OpenBrace, 0);
}

TypeScriptParser::FunctionBodyContext* TypeScriptParser::FunctionDeclarationContext::functionBody() {
  return getRuleContext<TypeScriptParser::FunctionBodyContext>(0);
}

tree::TerminalNode* TypeScriptParser::FunctionDeclarationContext::CloseBrace() {
  return getToken(TypeScriptParser::CloseBrace, 0);
}

tree::TerminalNode* TypeScriptParser::FunctionDeclarationContext::Async() {
  return getToken(TypeScriptParser::Async, 0);
}

tree::TerminalNode* TypeScriptParser::FunctionDeclarationContext::Multiply() {
  return getToken(TypeScriptParser::Multiply, 0);
}

TypeScriptParser::FormalParameterListContext* TypeScriptParser::FunctionDeclarationContext::formalParameterList() {
  return getRuleContext<TypeScriptParser::FormalParameterListContext>(0);
}

TypeScriptParser::TypeSignContext* TypeScriptParser::FunctionDeclarationContext::typeSign() {
  return getRuleContext<TypeScriptParser::TypeSignContext>(0);
}


size_t TypeScriptParser::FunctionDeclarationContext::getRuleIndex() const {
  return TypeScriptParser::RuleFunctionDeclaration;
}

void TypeScriptParser::FunctionDeclarationContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TypeScriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFunctionDeclaration(this);
}

void TypeScriptParser::FunctionDeclarationContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TypeScriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFunctionDeclaration(this);
}


antlrcpp::Any TypeScriptParser::FunctionDeclarationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TypeScriptParserVisitor*>(visitor))
    return parserVisitor->visitFunctionDeclaration(this);
  else
    return visitor->visitChildren(this);
}

TypeScriptParser::FunctionDeclarationContext* TypeScriptParser::functionDeclaration() {
  FunctionDeclarationContext *_localctx = _tracker.createInstance<FunctionDeclarationContext>(_ctx, getState());
  enterRule(_localctx, 92, TypeScriptParser::RuleFunctionDeclaration);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(489);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == TypeScriptParser::Async) {
      setState(488);
      match(TypeScriptParser::Async);
    }
    setState(491);
    match(TypeScriptParser::Function);
    setState(493);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == TypeScriptParser::Multiply) {
      setState(492);
      match(TypeScriptParser::Multiply);
    }
    setState(495);
    match(TypeScriptParser::Identifier);
    setState(496);
    match(TypeScriptParser::OpenParen);
    setState(498);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << TypeScriptParser::OpenBracket)
      | (1ULL << TypeScriptParser::OpenBrace)
      | (1ULL << TypeScriptParser::Ellipsis))) != 0) || _la == TypeScriptParser::Identifier) {
      setState(497);
      formalParameterList();
    }
    setState(500);
    match(TypeScriptParser::CloseParen);
    setState(502);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == TypeScriptParser::Colon) {
      setState(501);
      typeSign();
    }
    setState(504);
    match(TypeScriptParser::OpenBrace);
    setState(505);
    functionBody();
    setState(506);
    match(TypeScriptParser::CloseBrace);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ClassDeclarationContext ------------------------------------------------------------------

TypeScriptParser::ClassDeclarationContext::ClassDeclarationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* TypeScriptParser::ClassDeclarationContext::Class() {
  return getToken(TypeScriptParser::Class, 0);
}

tree::TerminalNode* TypeScriptParser::ClassDeclarationContext::Identifier() {
  return getToken(TypeScriptParser::Identifier, 0);
}

TypeScriptParser::ClassTailContext* TypeScriptParser::ClassDeclarationContext::classTail() {
  return getRuleContext<TypeScriptParser::ClassTailContext>(0);
}

std::vector<TypeScriptParser::ClassControlContext *> TypeScriptParser::ClassDeclarationContext::classControl() {
  return getRuleContexts<TypeScriptParser::ClassControlContext>();
}

TypeScriptParser::ClassControlContext* TypeScriptParser::ClassDeclarationContext::classControl(size_t i) {
  return getRuleContext<TypeScriptParser::ClassControlContext>(i);
}


size_t TypeScriptParser::ClassDeclarationContext::getRuleIndex() const {
  return TypeScriptParser::RuleClassDeclaration;
}

void TypeScriptParser::ClassDeclarationContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TypeScriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterClassDeclaration(this);
}

void TypeScriptParser::ClassDeclarationContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TypeScriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitClassDeclaration(this);
}


antlrcpp::Any TypeScriptParser::ClassDeclarationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TypeScriptParserVisitor*>(visitor))
    return parserVisitor->visitClassDeclaration(this);
  else
    return visitor->visitChildren(this);
}

TypeScriptParser::ClassDeclarationContext* TypeScriptParser::classDeclaration() {
  ClassDeclarationContext *_localctx = _tracker.createInstance<ClassDeclarationContext>(_ctx, getState());
  enterRule(_localctx, 94, TypeScriptParser::RuleClassDeclaration);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(511);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == TypeScriptParser::Static

    || _la == TypeScriptParser::Final) {
      setState(508);
      classControl();
      setState(513);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(514);
    match(TypeScriptParser::Class);
    setState(515);
    match(TypeScriptParser::Identifier);
    setState(516);
    classTail();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ClassTailContext ------------------------------------------------------------------

TypeScriptParser::ClassTailContext::ClassTailContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* TypeScriptParser::ClassTailContext::OpenBrace() {
  return getToken(TypeScriptParser::OpenBrace, 0);
}

tree::TerminalNode* TypeScriptParser::ClassTailContext::CloseBrace() {
  return getToken(TypeScriptParser::CloseBrace, 0);
}

tree::TerminalNode* TypeScriptParser::ClassTailContext::Extends() {
  return getToken(TypeScriptParser::Extends, 0);
}

TypeScriptParser::SingleExpressionContext* TypeScriptParser::ClassTailContext::singleExpression() {
  return getRuleContext<TypeScriptParser::SingleExpressionContext>(0);
}

std::vector<TypeScriptParser::ClassElementContext *> TypeScriptParser::ClassTailContext::classElement() {
  return getRuleContexts<TypeScriptParser::ClassElementContext>();
}

TypeScriptParser::ClassElementContext* TypeScriptParser::ClassTailContext::classElement(size_t i) {
  return getRuleContext<TypeScriptParser::ClassElementContext>(i);
}


size_t TypeScriptParser::ClassTailContext::getRuleIndex() const {
  return TypeScriptParser::RuleClassTail;
}

void TypeScriptParser::ClassTailContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TypeScriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterClassTail(this);
}

void TypeScriptParser::ClassTailContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TypeScriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitClassTail(this);
}


antlrcpp::Any TypeScriptParser::ClassTailContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TypeScriptParserVisitor*>(visitor))
    return parserVisitor->visitClassTail(this);
  else
    return visitor->visitChildren(this);
}

TypeScriptParser::ClassTailContext* TypeScriptParser::classTail() {
  ClassTailContext *_localctx = _tracker.createInstance<ClassTailContext>(_ctx, getState());
  enterRule(_localctx, 96, TypeScriptParser::RuleClassTail);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(520);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == TypeScriptParser::Extends) {
      setState(518);
      match(TypeScriptParser::Extends);
      setState(519);
      singleExpression(0);
    }
    setState(522);
    match(TypeScriptParser::OpenBrace);
    setState(526);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << TypeScriptParser::OpenBracket)
      | (1ULL << TypeScriptParser::SemiColon)
      | (1ULL << TypeScriptParser::NullLiteral)
      | (1ULL << TypeScriptParser::BooleanLiteral)
      | (1ULL << TypeScriptParser::DecimalLiteral))) != 0) || ((((_la - 71) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 71)) & ((1ULL << (TypeScriptParser::HexIntegerLiteral - 71))
      | (1ULL << (TypeScriptParser::OctalIntegerLiteral - 71))
      | (1ULL << (TypeScriptParser::OctalIntegerLiteral2 - 71))
      | (1ULL << (TypeScriptParser::BinaryIntegerLiteral - 71))
      | (1ULL << (TypeScriptParser::Readonly - 71))
      | (1ULL << (TypeScriptParser::Break - 71))
      | (1ULL << (TypeScriptParser::Do - 71))
      | (1ULL << (TypeScriptParser::Instanceof - 71))
      | (1ULL << (TypeScriptParser::Typeof - 71))
      | (1ULL << (TypeScriptParser::Case - 71))
      | (1ULL << (TypeScriptParser::Else - 71))
      | (1ULL << (TypeScriptParser::New - 71))
      | (1ULL << (TypeScriptParser::Var - 71))
      | (1ULL << (TypeScriptParser::Catch - 71))
      | (1ULL << (TypeScriptParser::Finally - 71))
      | (1ULL << (TypeScriptParser::Return - 71))
      | (1ULL << (TypeScriptParser::Void - 71))
      | (1ULL << (TypeScriptParser::Continue - 71))
      | (1ULL << (TypeScriptParser::For - 71))
      | (1ULL << (TypeScriptParser::Switch - 71))
      | (1ULL << (TypeScriptParser::While - 71))
      | (1ULL << (TypeScriptParser::Debugger - 71))
      | (1ULL << (TypeScriptParser::Function - 71))
      | (1ULL << (TypeScriptParser::This - 71))
      | (1ULL << (TypeScriptParser::With - 71))
      | (1ULL << (TypeScriptParser::Default - 71))
      | (1ULL << (TypeScriptParser::If - 71))
      | (1ULL << (TypeScriptParser::Throw - 71))
      | (1ULL << (TypeScriptParser::Delete - 71))
      | (1ULL << (TypeScriptParser::In - 71))
      | (1ULL << (TypeScriptParser::Try - 71))
      | (1ULL << (TypeScriptParser::As - 71))
      | (1ULL << (TypeScriptParser::From - 71))
      | (1ULL << (TypeScriptParser::Class - 71))
      | (1ULL << (TypeScriptParser::Constructor - 71))
      | (1ULL << (TypeScriptParser::Enum - 71))
      | (1ULL << (TypeScriptParser::Extends - 71))
      | (1ULL << (TypeScriptParser::Super - 71))
      | (1ULL << (TypeScriptParser::Const - 71))
      | (1ULL << (TypeScriptParser::Export - 71))
      | (1ULL << (TypeScriptParser::Import - 71))
      | (1ULL << (TypeScriptParser::Async - 71))
      | (1ULL << (TypeScriptParser::Await - 71))
      | (1ULL << (TypeScriptParser::Implements - 71))
      | (1ULL << (TypeScriptParser::Let - 71))
      | (1ULL << (TypeScriptParser::Private - 71))
      | (1ULL << (TypeScriptParser::Public - 71))
      | (1ULL << (TypeScriptParser::Interface - 71))
      | (1ULL << (TypeScriptParser::Package - 71))
      | (1ULL << (TypeScriptParser::Protected - 71))
      | (1ULL << (TypeScriptParser::Static - 71))
      | (1ULL << (TypeScriptParser::Final - 71))
      | (1ULL << (TypeScriptParser::Yield - 71))
      | (1ULL << (TypeScriptParser::Get - 71))
      | (1ULL << (TypeScriptParser::Set - 71))
      | (1ULL << (TypeScriptParser::Identifier - 71))
      | (1ULL << (TypeScriptParser::StringLiteral - 71)))) != 0)) {
      setState(523);
      classElement();
      setState(528);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(529);
    match(TypeScriptParser::CloseBrace);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ClassElementContext ------------------------------------------------------------------

TypeScriptParser::ClassElementContext::ClassElementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t TypeScriptParser::ClassElementContext::getRuleIndex() const {
  return TypeScriptParser::RuleClassElement;
}

void TypeScriptParser::ClassElementContext::copyFrom(ClassElementContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- SetterMethodDefinitionContext ------------------------------------------------------------------

TypeScriptParser::SetterContext* TypeScriptParser::SetterMethodDefinitionContext::setter() {
  return getRuleContext<TypeScriptParser::SetterContext>(0);
}

tree::TerminalNode* TypeScriptParser::SetterMethodDefinitionContext::OpenParen() {
  return getToken(TypeScriptParser::OpenParen, 0);
}

tree::TerminalNode* TypeScriptParser::SetterMethodDefinitionContext::CloseParen() {
  return getToken(TypeScriptParser::CloseParen, 0);
}

tree::TerminalNode* TypeScriptParser::SetterMethodDefinitionContext::OpenBrace() {
  return getToken(TypeScriptParser::OpenBrace, 0);
}

TypeScriptParser::FunctionBodyContext* TypeScriptParser::SetterMethodDefinitionContext::functionBody() {
  return getRuleContext<TypeScriptParser::FunctionBodyContext>(0);
}

tree::TerminalNode* TypeScriptParser::SetterMethodDefinitionContext::CloseBrace() {
  return getToken(TypeScriptParser::CloseBrace, 0);
}

TypeScriptParser::AccessControlContext* TypeScriptParser::SetterMethodDefinitionContext::accessControl() {
  return getRuleContext<TypeScriptParser::AccessControlContext>(0);
}

std::vector<TypeScriptParser::FunctionControlContext *> TypeScriptParser::SetterMethodDefinitionContext::functionControl() {
  return getRuleContexts<TypeScriptParser::FunctionControlContext>();
}

TypeScriptParser::FunctionControlContext* TypeScriptParser::SetterMethodDefinitionContext::functionControl(size_t i) {
  return getRuleContext<TypeScriptParser::FunctionControlContext>(i);
}

TypeScriptParser::FormalParameterListContext* TypeScriptParser::SetterMethodDefinitionContext::formalParameterList() {
  return getRuleContext<TypeScriptParser::FormalParameterListContext>(0);
}

TypeScriptParser::SetterMethodDefinitionContext::SetterMethodDefinitionContext(ClassElementContext *ctx) { copyFrom(ctx); }

void TypeScriptParser::SetterMethodDefinitionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TypeScriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSetterMethodDefinition(this);
}
void TypeScriptParser::SetterMethodDefinitionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TypeScriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSetterMethodDefinition(this);
}

antlrcpp::Any TypeScriptParser::SetterMethodDefinitionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TypeScriptParserVisitor*>(visitor))
    return parserVisitor->visitSetterMethodDefinition(this);
  else
    return visitor->visitChildren(this);
}
//----------------- GetterMethodDefinitionContext ------------------------------------------------------------------

TypeScriptParser::GetterContext* TypeScriptParser::GetterMethodDefinitionContext::getter() {
  return getRuleContext<TypeScriptParser::GetterContext>(0);
}

tree::TerminalNode* TypeScriptParser::GetterMethodDefinitionContext::OpenParen() {
  return getToken(TypeScriptParser::OpenParen, 0);
}

tree::TerminalNode* TypeScriptParser::GetterMethodDefinitionContext::CloseParen() {
  return getToken(TypeScriptParser::CloseParen, 0);
}

tree::TerminalNode* TypeScriptParser::GetterMethodDefinitionContext::OpenBrace() {
  return getToken(TypeScriptParser::OpenBrace, 0);
}

TypeScriptParser::FunctionBodyContext* TypeScriptParser::GetterMethodDefinitionContext::functionBody() {
  return getRuleContext<TypeScriptParser::FunctionBodyContext>(0);
}

tree::TerminalNode* TypeScriptParser::GetterMethodDefinitionContext::CloseBrace() {
  return getToken(TypeScriptParser::CloseBrace, 0);
}

TypeScriptParser::AccessControlContext* TypeScriptParser::GetterMethodDefinitionContext::accessControl() {
  return getRuleContext<TypeScriptParser::AccessControlContext>(0);
}

std::vector<TypeScriptParser::FunctionControlContext *> TypeScriptParser::GetterMethodDefinitionContext::functionControl() {
  return getRuleContexts<TypeScriptParser::FunctionControlContext>();
}

TypeScriptParser::FunctionControlContext* TypeScriptParser::GetterMethodDefinitionContext::functionControl(size_t i) {
  return getRuleContext<TypeScriptParser::FunctionControlContext>(i);
}

TypeScriptParser::TypeSignContext* TypeScriptParser::GetterMethodDefinitionContext::typeSign() {
  return getRuleContext<TypeScriptParser::TypeSignContext>(0);
}

TypeScriptParser::GetterMethodDefinitionContext::GetterMethodDefinitionContext(ClassElementContext *ctx) { copyFrom(ctx); }

void TypeScriptParser::GetterMethodDefinitionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TypeScriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterGetterMethodDefinition(this);
}
void TypeScriptParser::GetterMethodDefinitionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TypeScriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitGetterMethodDefinition(this);
}

antlrcpp::Any TypeScriptParser::GetterMethodDefinitionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TypeScriptParserVisitor*>(visitor))
    return parserVisitor->visitGetterMethodDefinition(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ConstructorDefinitionContext ------------------------------------------------------------------

tree::TerminalNode* TypeScriptParser::ConstructorDefinitionContext::Constructor() {
  return getToken(TypeScriptParser::Constructor, 0);
}

tree::TerminalNode* TypeScriptParser::ConstructorDefinitionContext::OpenParen() {
  return getToken(TypeScriptParser::OpenParen, 0);
}

tree::TerminalNode* TypeScriptParser::ConstructorDefinitionContext::CloseParen() {
  return getToken(TypeScriptParser::CloseParen, 0);
}

tree::TerminalNode* TypeScriptParser::ConstructorDefinitionContext::OpenBrace() {
  return getToken(TypeScriptParser::OpenBrace, 0);
}

TypeScriptParser::FunctionBodyContext* TypeScriptParser::ConstructorDefinitionContext::functionBody() {
  return getRuleContext<TypeScriptParser::FunctionBodyContext>(0);
}

tree::TerminalNode* TypeScriptParser::ConstructorDefinitionContext::CloseBrace() {
  return getToken(TypeScriptParser::CloseBrace, 0);
}

TypeScriptParser::AccessControlContext* TypeScriptParser::ConstructorDefinitionContext::accessControl() {
  return getRuleContext<TypeScriptParser::AccessControlContext>(0);
}

tree::TerminalNode* TypeScriptParser::ConstructorDefinitionContext::Async() {
  return getToken(TypeScriptParser::Async, 0);
}

TypeScriptParser::FormalParameterListContext* TypeScriptParser::ConstructorDefinitionContext::formalParameterList() {
  return getRuleContext<TypeScriptParser::FormalParameterListContext>(0);
}

TypeScriptParser::ConstructorDefinitionContext::ConstructorDefinitionContext(ClassElementContext *ctx) { copyFrom(ctx); }

void TypeScriptParser::ConstructorDefinitionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TypeScriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterConstructorDefinition(this);
}
void TypeScriptParser::ConstructorDefinitionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TypeScriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitConstructorDefinition(this);
}

antlrcpp::Any TypeScriptParser::ConstructorDefinitionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TypeScriptParserVisitor*>(visitor))
    return parserVisitor->visitConstructorDefinition(this);
  else
    return visitor->visitChildren(this);
}
//----------------- NormalMethodDefinitionContext ------------------------------------------------------------------

TypeScriptParser::PropertyNameContext* TypeScriptParser::NormalMethodDefinitionContext::propertyName() {
  return getRuleContext<TypeScriptParser::PropertyNameContext>(0);
}

tree::TerminalNode* TypeScriptParser::NormalMethodDefinitionContext::OpenParen() {
  return getToken(TypeScriptParser::OpenParen, 0);
}

tree::TerminalNode* TypeScriptParser::NormalMethodDefinitionContext::CloseParen() {
  return getToken(TypeScriptParser::CloseParen, 0);
}

tree::TerminalNode* TypeScriptParser::NormalMethodDefinitionContext::OpenBrace() {
  return getToken(TypeScriptParser::OpenBrace, 0);
}

TypeScriptParser::FunctionBodyContext* TypeScriptParser::NormalMethodDefinitionContext::functionBody() {
  return getRuleContext<TypeScriptParser::FunctionBodyContext>(0);
}

tree::TerminalNode* TypeScriptParser::NormalMethodDefinitionContext::CloseBrace() {
  return getToken(TypeScriptParser::CloseBrace, 0);
}

TypeScriptParser::AccessControlContext* TypeScriptParser::NormalMethodDefinitionContext::accessControl() {
  return getRuleContext<TypeScriptParser::AccessControlContext>(0);
}

std::vector<TypeScriptParser::FunctionControlContext *> TypeScriptParser::NormalMethodDefinitionContext::functionControl() {
  return getRuleContexts<TypeScriptParser::FunctionControlContext>();
}

TypeScriptParser::FunctionControlContext* TypeScriptParser::NormalMethodDefinitionContext::functionControl(size_t i) {
  return getRuleContext<TypeScriptParser::FunctionControlContext>(i);
}

tree::TerminalNode* TypeScriptParser::NormalMethodDefinitionContext::Async() {
  return getToken(TypeScriptParser::Async, 0);
}

TypeScriptParser::FormalParameterListContext* TypeScriptParser::NormalMethodDefinitionContext::formalParameterList() {
  return getRuleContext<TypeScriptParser::FormalParameterListContext>(0);
}

TypeScriptParser::TypeSignContext* TypeScriptParser::NormalMethodDefinitionContext::typeSign() {
  return getRuleContext<TypeScriptParser::TypeSignContext>(0);
}

TypeScriptParser::NormalMethodDefinitionContext::NormalMethodDefinitionContext(ClassElementContext *ctx) { copyFrom(ctx); }

void TypeScriptParser::NormalMethodDefinitionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TypeScriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterNormalMethodDefinition(this);
}
void TypeScriptParser::NormalMethodDefinitionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TypeScriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitNormalMethodDefinition(this);
}

antlrcpp::Any TypeScriptParser::NormalMethodDefinitionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TypeScriptParserVisitor*>(visitor))
    return parserVisitor->visitNormalMethodDefinition(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ClassEmptyStatementContext ------------------------------------------------------------------

TypeScriptParser::EmptyStatementContext* TypeScriptParser::ClassEmptyStatementContext::emptyStatement() {
  return getRuleContext<TypeScriptParser::EmptyStatementContext>(0);
}

TypeScriptParser::ClassEmptyStatementContext::ClassEmptyStatementContext(ClassElementContext *ctx) { copyFrom(ctx); }

void TypeScriptParser::ClassEmptyStatementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TypeScriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterClassEmptyStatement(this);
}
void TypeScriptParser::ClassEmptyStatementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TypeScriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitClassEmptyStatement(this);
}

antlrcpp::Any TypeScriptParser::ClassEmptyStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TypeScriptParserVisitor*>(visitor))
    return parserVisitor->visitClassEmptyStatement(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ClassPropertyDefinitionContext ------------------------------------------------------------------

TypeScriptParser::PropertyNameContext* TypeScriptParser::ClassPropertyDefinitionContext::propertyName() {
  return getRuleContext<TypeScriptParser::PropertyNameContext>(0);
}

TypeScriptParser::AccessControlContext* TypeScriptParser::ClassPropertyDefinitionContext::accessControl() {
  return getRuleContext<TypeScriptParser::AccessControlContext>(0);
}

std::vector<TypeScriptParser::PropertyControlContext *> TypeScriptParser::ClassPropertyDefinitionContext::propertyControl() {
  return getRuleContexts<TypeScriptParser::PropertyControlContext>();
}

TypeScriptParser::PropertyControlContext* TypeScriptParser::ClassPropertyDefinitionContext::propertyControl(size_t i) {
  return getRuleContext<TypeScriptParser::PropertyControlContext>(i);
}

TypeScriptParser::TypeSignContext* TypeScriptParser::ClassPropertyDefinitionContext::typeSign() {
  return getRuleContext<TypeScriptParser::TypeSignContext>(0);
}

tree::TerminalNode* TypeScriptParser::ClassPropertyDefinitionContext::Assign() {
  return getToken(TypeScriptParser::Assign, 0);
}

TypeScriptParser::SingleExpressionContext* TypeScriptParser::ClassPropertyDefinitionContext::singleExpression() {
  return getRuleContext<TypeScriptParser::SingleExpressionContext>(0);
}

TypeScriptParser::ClassPropertyDefinitionContext::ClassPropertyDefinitionContext(ClassElementContext *ctx) { copyFrom(ctx); }

void TypeScriptParser::ClassPropertyDefinitionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TypeScriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterClassPropertyDefinition(this);
}
void TypeScriptParser::ClassPropertyDefinitionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TypeScriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitClassPropertyDefinition(this);
}

antlrcpp::Any TypeScriptParser::ClassPropertyDefinitionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TypeScriptParserVisitor*>(visitor))
    return parserVisitor->visitClassPropertyDefinition(this);
  else
    return visitor->visitChildren(this);
}
TypeScriptParser::ClassElementContext* TypeScriptParser::classElement() {
  ClassElementContext *_localctx = _tracker.createInstance<ClassElementContext>(_ctx, getState());
  enterRule(_localctx, 98, TypeScriptParser::RuleClassElement);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    size_t alt;
    setState(628);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 68, _ctx)) {
    case 1: {
      _localctx = dynamic_cast<ClassElementContext *>(_tracker.createInstance<TypeScriptParser::ConstructorDefinitionContext>(_localctx));
      enterOuterAlt(_localctx, 1);
      setState(532);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (((((_la - 120) & ~ 0x3fULL) == 0) &&
        ((1ULL << (_la - 120)) & ((1ULL << (TypeScriptParser::Private - 120))
        | (1ULL << (TypeScriptParser::Public - 120))
        | (1ULL << (TypeScriptParser::Protected - 120)))) != 0)) {
        setState(531);
        accessControl();
      }
      setState(535);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == TypeScriptParser::Async) {
        setState(534);
        match(TypeScriptParser::Async);
      }
      setState(537);
      match(TypeScriptParser::Constructor);
      setState(538);
      match(TypeScriptParser::OpenParen);
      setState(540);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & ((1ULL << TypeScriptParser::OpenBracket)
        | (1ULL << TypeScriptParser::OpenBrace)
        | (1ULL << TypeScriptParser::Ellipsis))) != 0) || _la == TypeScriptParser::Identifier) {
        setState(539);
        formalParameterList();
      }
      setState(542);
      match(TypeScriptParser::CloseParen);
      setState(543);
      match(TypeScriptParser::OpenBrace);
      setState(544);
      functionBody();
      setState(545);
      match(TypeScriptParser::CloseBrace);
      break;
    }

    case 2: {
      _localctx = dynamic_cast<ClassElementContext *>(_tracker.createInstance<TypeScriptParser::NormalMethodDefinitionContext>(_localctx));
      enterOuterAlt(_localctx, 2);
      setState(548);
      _errHandler->sync(this);

      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 53, _ctx)) {
      case 1: {
        setState(547);
        accessControl();
        break;
      }

      }
      setState(553);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 54, _ctx);
      while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
        if (alt == 1) {
          setState(550);
          functionControl(); 
        }
        setState(555);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 54, _ctx);
      }
      setState(557);
      _errHandler->sync(this);

      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 55, _ctx)) {
      case 1: {
        setState(556);
        match(TypeScriptParser::Async);
        break;
      }

      }
      setState(559);
      propertyName();
      setState(560);
      match(TypeScriptParser::OpenParen);
      setState(562);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & ((1ULL << TypeScriptParser::OpenBracket)
        | (1ULL << TypeScriptParser::OpenBrace)
        | (1ULL << TypeScriptParser::Ellipsis))) != 0) || _la == TypeScriptParser::Identifier) {
        setState(561);
        formalParameterList();
      }
      setState(564);
      match(TypeScriptParser::CloseParen);
      setState(566);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == TypeScriptParser::Colon) {
        setState(565);
        typeSign();
      }
      setState(568);
      match(TypeScriptParser::OpenBrace);
      setState(569);
      functionBody();
      setState(570);
      match(TypeScriptParser::CloseBrace);
      break;
    }

    case 3: {
      _localctx = dynamic_cast<ClassElementContext *>(_tracker.createInstance<TypeScriptParser::GetterMethodDefinitionContext>(_localctx));
      enterOuterAlt(_localctx, 3);
      setState(573);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (((((_la - 120) & ~ 0x3fULL) == 0) &&
        ((1ULL << (_la - 120)) & ((1ULL << (TypeScriptParser::Private - 120))
        | (1ULL << (TypeScriptParser::Public - 120))
        | (1ULL << (TypeScriptParser::Protected - 120)))) != 0)) {
        setState(572);
        accessControl();
      }
      setState(578);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (((((_la - 125) & ~ 0x3fULL) == 0) &&
        ((1ULL << (_la - 125)) & ((1ULL << (TypeScriptParser::Static - 125))
        | (1ULL << (TypeScriptParser::Final - 125))
        | (1ULL << (TypeScriptParser::Identifier - 125)))) != 0)) {
        setState(575);
        functionControl();
        setState(580);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(581);
      getter();
      setState(582);
      match(TypeScriptParser::OpenParen);
      setState(583);
      match(TypeScriptParser::CloseParen);
      setState(585);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == TypeScriptParser::Colon) {
        setState(584);
        typeSign();
      }
      setState(587);
      match(TypeScriptParser::OpenBrace);
      setState(588);
      functionBody();
      setState(589);
      match(TypeScriptParser::CloseBrace);
      break;
    }

    case 4: {
      _localctx = dynamic_cast<ClassElementContext *>(_tracker.createInstance<TypeScriptParser::SetterMethodDefinitionContext>(_localctx));
      enterOuterAlt(_localctx, 4);
      setState(592);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (((((_la - 120) & ~ 0x3fULL) == 0) &&
        ((1ULL << (_la - 120)) & ((1ULL << (TypeScriptParser::Private - 120))
        | (1ULL << (TypeScriptParser::Public - 120))
        | (1ULL << (TypeScriptParser::Protected - 120)))) != 0)) {
        setState(591);
        accessControl();
      }
      setState(597);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (((((_la - 125) & ~ 0x3fULL) == 0) &&
        ((1ULL << (_la - 125)) & ((1ULL << (TypeScriptParser::Static - 125))
        | (1ULL << (TypeScriptParser::Final - 125))
        | (1ULL << (TypeScriptParser::Identifier - 125)))) != 0)) {
        setState(594);
        functionControl();
        setState(599);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(600);
      setter();
      setState(601);
      match(TypeScriptParser::OpenParen);
      setState(603);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & ((1ULL << TypeScriptParser::OpenBracket)
        | (1ULL << TypeScriptParser::OpenBrace)
        | (1ULL << TypeScriptParser::Ellipsis))) != 0) || _la == TypeScriptParser::Identifier) {
        setState(602);
        formalParameterList();
      }
      setState(605);
      match(TypeScriptParser::CloseParen);
      setState(606);
      match(TypeScriptParser::OpenBrace);
      setState(607);
      functionBody();
      setState(608);
      match(TypeScriptParser::CloseBrace);
      break;
    }

    case 5: {
      _localctx = dynamic_cast<ClassElementContext *>(_tracker.createInstance<TypeScriptParser::ClassPropertyDefinitionContext>(_localctx));
      enterOuterAlt(_localctx, 5);
      setState(611);
      _errHandler->sync(this);

      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 64, _ctx)) {
      case 1: {
        setState(610);
        accessControl();
        break;
      }

      }
      setState(616);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 65, _ctx);
      while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
        if (alt == 1) {
          setState(613);
          propertyControl(); 
        }
        setState(618);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 65, _ctx);
      }
      setState(619);
      propertyName();
      setState(621);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == TypeScriptParser::Colon) {
        setState(620);
        typeSign();
      }
      setState(625);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == TypeScriptParser::Assign) {
        setState(623);
        match(TypeScriptParser::Assign);
        setState(624);
        singleExpression(0);
      }
      break;
    }

    case 6: {
      _localctx = dynamic_cast<ClassElementContext *>(_tracker.createInstance<TypeScriptParser::ClassEmptyStatementContext>(_localctx));
      enterOuterAlt(_localctx, 6);
      setState(627);
      emptyStatement();
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FormalParameterListContext ------------------------------------------------------------------

TypeScriptParser::FormalParameterListContext::FormalParameterListContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<TypeScriptParser::FormalParameterArgContext *> TypeScriptParser::FormalParameterListContext::formalParameterArg() {
  return getRuleContexts<TypeScriptParser::FormalParameterArgContext>();
}

TypeScriptParser::FormalParameterArgContext* TypeScriptParser::FormalParameterListContext::formalParameterArg(size_t i) {
  return getRuleContext<TypeScriptParser::FormalParameterArgContext>(i);
}

std::vector<tree::TerminalNode *> TypeScriptParser::FormalParameterListContext::Comma() {
  return getTokens(TypeScriptParser::Comma);
}

tree::TerminalNode* TypeScriptParser::FormalParameterListContext::Comma(size_t i) {
  return getToken(TypeScriptParser::Comma, i);
}

TypeScriptParser::LastFormalParameterArgContext* TypeScriptParser::FormalParameterListContext::lastFormalParameterArg() {
  return getRuleContext<TypeScriptParser::LastFormalParameterArgContext>(0);
}


size_t TypeScriptParser::FormalParameterListContext::getRuleIndex() const {
  return TypeScriptParser::RuleFormalParameterList;
}

void TypeScriptParser::FormalParameterListContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TypeScriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFormalParameterList(this);
}

void TypeScriptParser::FormalParameterListContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TypeScriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFormalParameterList(this);
}


antlrcpp::Any TypeScriptParser::FormalParameterListContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TypeScriptParserVisitor*>(visitor))
    return parserVisitor->visitFormalParameterList(this);
  else
    return visitor->visitChildren(this);
}

TypeScriptParser::FormalParameterListContext* TypeScriptParser::formalParameterList() {
  FormalParameterListContext *_localctx = _tracker.createInstance<FormalParameterListContext>(_ctx, getState());
  enterRule(_localctx, 100, TypeScriptParser::RuleFormalParameterList);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    size_t alt;
    setState(643);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case TypeScriptParser::OpenBracket:
      case TypeScriptParser::OpenBrace:
      case TypeScriptParser::Identifier: {
        enterOuterAlt(_localctx, 1);
        setState(630);
        formalParameterArg();
        setState(635);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 69, _ctx);
        while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
          if (alt == 1) {
            setState(631);
            match(TypeScriptParser::Comma);
            setState(632);
            formalParameterArg(); 
          }
          setState(637);
          _errHandler->sync(this);
          alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 69, _ctx);
        }
        setState(640);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == TypeScriptParser::Comma) {
          setState(638);
          match(TypeScriptParser::Comma);
          setState(639);
          lastFormalParameterArg();
        }
        break;
      }

      case TypeScriptParser::Ellipsis: {
        enterOuterAlt(_localctx, 2);
        setState(642);
        lastFormalParameterArg();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FormalParameterArgContext ------------------------------------------------------------------

TypeScriptParser::FormalParameterArgContext::FormalParameterArgContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

TypeScriptParser::AssignableContext* TypeScriptParser::FormalParameterArgContext::assignable() {
  return getRuleContext<TypeScriptParser::AssignableContext>(0);
}

TypeScriptParser::TypeSignContext* TypeScriptParser::FormalParameterArgContext::typeSign() {
  return getRuleContext<TypeScriptParser::TypeSignContext>(0);
}

tree::TerminalNode* TypeScriptParser::FormalParameterArgContext::Assign() {
  return getToken(TypeScriptParser::Assign, 0);
}

TypeScriptParser::SingleExpressionContext* TypeScriptParser::FormalParameterArgContext::singleExpression() {
  return getRuleContext<TypeScriptParser::SingleExpressionContext>(0);
}


size_t TypeScriptParser::FormalParameterArgContext::getRuleIndex() const {
  return TypeScriptParser::RuleFormalParameterArg;
}

void TypeScriptParser::FormalParameterArgContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TypeScriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFormalParameterArg(this);
}

void TypeScriptParser::FormalParameterArgContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TypeScriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFormalParameterArg(this);
}


antlrcpp::Any TypeScriptParser::FormalParameterArgContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TypeScriptParserVisitor*>(visitor))
    return parserVisitor->visitFormalParameterArg(this);
  else
    return visitor->visitChildren(this);
}

TypeScriptParser::FormalParameterArgContext* TypeScriptParser::formalParameterArg() {
  FormalParameterArgContext *_localctx = _tracker.createInstance<FormalParameterArgContext>(_ctx, getState());
  enterRule(_localctx, 102, TypeScriptParser::RuleFormalParameterArg);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(645);
    assignable();
    setState(647);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == TypeScriptParser::Colon) {
      setState(646);
      typeSign();
    }
    setState(651);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == TypeScriptParser::Assign) {
      setState(649);
      match(TypeScriptParser::Assign);
      setState(650);
      singleExpression(0);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- LastFormalParameterArgContext ------------------------------------------------------------------

TypeScriptParser::LastFormalParameterArgContext::LastFormalParameterArgContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* TypeScriptParser::LastFormalParameterArgContext::Ellipsis() {
  return getToken(TypeScriptParser::Ellipsis, 0);
}

TypeScriptParser::SingleExpressionContext* TypeScriptParser::LastFormalParameterArgContext::singleExpression() {
  return getRuleContext<TypeScriptParser::SingleExpressionContext>(0);
}


size_t TypeScriptParser::LastFormalParameterArgContext::getRuleIndex() const {
  return TypeScriptParser::RuleLastFormalParameterArg;
}

void TypeScriptParser::LastFormalParameterArgContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TypeScriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterLastFormalParameterArg(this);
}

void TypeScriptParser::LastFormalParameterArgContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TypeScriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitLastFormalParameterArg(this);
}


antlrcpp::Any TypeScriptParser::LastFormalParameterArgContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TypeScriptParserVisitor*>(visitor))
    return parserVisitor->visitLastFormalParameterArg(this);
  else
    return visitor->visitChildren(this);
}

TypeScriptParser::LastFormalParameterArgContext* TypeScriptParser::lastFormalParameterArg() {
  LastFormalParameterArgContext *_localctx = _tracker.createInstance<LastFormalParameterArgContext>(_ctx, getState());
  enterRule(_localctx, 104, TypeScriptParser::RuleLastFormalParameterArg);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(653);
    match(TypeScriptParser::Ellipsis);
    setState(654);
    singleExpression(0);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FunctionBodyContext ------------------------------------------------------------------

TypeScriptParser::FunctionBodyContext::FunctionBodyContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

TypeScriptParser::StatementListContext* TypeScriptParser::FunctionBodyContext::statementList() {
  return getRuleContext<TypeScriptParser::StatementListContext>(0);
}


size_t TypeScriptParser::FunctionBodyContext::getRuleIndex() const {
  return TypeScriptParser::RuleFunctionBody;
}

void TypeScriptParser::FunctionBodyContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TypeScriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFunctionBody(this);
}

void TypeScriptParser::FunctionBodyContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TypeScriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFunctionBody(this);
}


antlrcpp::Any TypeScriptParser::FunctionBodyContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TypeScriptParserVisitor*>(visitor))
    return parserVisitor->visitFunctionBody(this);
  else
    return visitor->visitChildren(this);
}

TypeScriptParser::FunctionBodyContext* TypeScriptParser::functionBody() {
  FunctionBodyContext *_localctx = _tracker.createInstance<FunctionBodyContext>(_ctx, getState());
  enterRule(_localctx, 106, TypeScriptParser::RuleFunctionBody);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(657);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << TypeScriptParser::RegularExpressionLiteral)
      | (1ULL << TypeScriptParser::OpenBracket)
      | (1ULL << TypeScriptParser::OpenParen)
      | (1ULL << TypeScriptParser::OpenBrace)
      | (1ULL << TypeScriptParser::SemiColon)
      | (1ULL << TypeScriptParser::PlusPlus)
      | (1ULL << TypeScriptParser::MinusMinus)
      | (1ULL << TypeScriptParser::Plus)
      | (1ULL << TypeScriptParser::Minus)
      | (1ULL << TypeScriptParser::BitNot)
      | (1ULL << TypeScriptParser::Not)
      | (1ULL << TypeScriptParser::NullLiteral)
      | (1ULL << TypeScriptParser::BooleanLiteral)
      | (1ULL << TypeScriptParser::DecimalLiteral))) != 0) || ((((_la - 71) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 71)) & ((1ULL << (TypeScriptParser::HexIntegerLiteral - 71))
      | (1ULL << (TypeScriptParser::OctalIntegerLiteral - 71))
      | (1ULL << (TypeScriptParser::OctalIntegerLiteral2 - 71))
      | (1ULL << (TypeScriptParser::BinaryIntegerLiteral - 71))
      | (1ULL << (TypeScriptParser::BigHexIntegerLiteral - 71))
      | (1ULL << (TypeScriptParser::BigOctalIntegerLiteral - 71))
      | (1ULL << (TypeScriptParser::BigBinaryIntegerLiteral - 71))
      | (1ULL << (TypeScriptParser::BigDecimalIntegerLiteral - 71))
      | (1ULL << (TypeScriptParser::Break - 71))
      | (1ULL << (TypeScriptParser::Do - 71))
      | (1ULL << (TypeScriptParser::Typeof - 71))
      | (1ULL << (TypeScriptParser::New - 71))
      | (1ULL << (TypeScriptParser::Var - 71))
      | (1ULL << (TypeScriptParser::Return - 71))
      | (1ULL << (TypeScriptParser::Void - 71))
      | (1ULL << (TypeScriptParser::Continue - 71))
      | (1ULL << (TypeScriptParser::For - 71))
      | (1ULL << (TypeScriptParser::Switch - 71))
      | (1ULL << (TypeScriptParser::While - 71))
      | (1ULL << (TypeScriptParser::Debugger - 71))
      | (1ULL << (TypeScriptParser::Function - 71))
      | (1ULL << (TypeScriptParser::This - 71))
      | (1ULL << (TypeScriptParser::With - 71))
      | (1ULL << (TypeScriptParser::If - 71))
      | (1ULL << (TypeScriptParser::Throw - 71))
      | (1ULL << (TypeScriptParser::Delete - 71))
      | (1ULL << (TypeScriptParser::Try - 71))
      | (1ULL << (TypeScriptParser::Class - 71))
      | (1ULL << (TypeScriptParser::Super - 71))
      | (1ULL << (TypeScriptParser::Const - 71))
      | (1ULL << (TypeScriptParser::Export - 71))
      | (1ULL << (TypeScriptParser::Import - 71))
      | (1ULL << (TypeScriptParser::Async - 71))
      | (1ULL << (TypeScriptParser::Await - 71))
      | (1ULL << (TypeScriptParser::Let - 71))
      | (1ULL << (TypeScriptParser::Static - 71))
      | (1ULL << (TypeScriptParser::Final - 71))
      | (1ULL << (TypeScriptParser::Yield - 71))
      | (1ULL << (TypeScriptParser::Identifier - 71))
      | (1ULL << (TypeScriptParser::StringLiteral - 71))
      | (1ULL << (TypeScriptParser::TemplateStringLiteral - 71)))) != 0)) {
      setState(656);
      statementList();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ArrayLiteralContext ------------------------------------------------------------------

TypeScriptParser::ArrayLiteralContext::ArrayLiteralContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* TypeScriptParser::ArrayLiteralContext::OpenBracket() {
  return getToken(TypeScriptParser::OpenBracket, 0);
}

TypeScriptParser::ElementListContext* TypeScriptParser::ArrayLiteralContext::elementList() {
  return getRuleContext<TypeScriptParser::ElementListContext>(0);
}

tree::TerminalNode* TypeScriptParser::ArrayLiteralContext::CloseBracket() {
  return getToken(TypeScriptParser::CloseBracket, 0);
}


size_t TypeScriptParser::ArrayLiteralContext::getRuleIndex() const {
  return TypeScriptParser::RuleArrayLiteral;
}

void TypeScriptParser::ArrayLiteralContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TypeScriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterArrayLiteral(this);
}

void TypeScriptParser::ArrayLiteralContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TypeScriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitArrayLiteral(this);
}


antlrcpp::Any TypeScriptParser::ArrayLiteralContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TypeScriptParserVisitor*>(visitor))
    return parserVisitor->visitArrayLiteral(this);
  else
    return visitor->visitChildren(this);
}

TypeScriptParser::ArrayLiteralContext* TypeScriptParser::arrayLiteral() {
  ArrayLiteralContext *_localctx = _tracker.createInstance<ArrayLiteralContext>(_ctx, getState());
  enterRule(_localctx, 108, TypeScriptParser::RuleArrayLiteral);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(659);
    match(TypeScriptParser::OpenBracket);
    setState(660);
    elementList();
    setState(661);
    match(TypeScriptParser::CloseBracket);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ElementListContext ------------------------------------------------------------------

TypeScriptParser::ElementListContext::ElementListContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<tree::TerminalNode *> TypeScriptParser::ElementListContext::Comma() {
  return getTokens(TypeScriptParser::Comma);
}

tree::TerminalNode* TypeScriptParser::ElementListContext::Comma(size_t i) {
  return getToken(TypeScriptParser::Comma, i);
}

std::vector<TypeScriptParser::ArrayElementContext *> TypeScriptParser::ElementListContext::arrayElement() {
  return getRuleContexts<TypeScriptParser::ArrayElementContext>();
}

TypeScriptParser::ArrayElementContext* TypeScriptParser::ElementListContext::arrayElement(size_t i) {
  return getRuleContext<TypeScriptParser::ArrayElementContext>(i);
}


size_t TypeScriptParser::ElementListContext::getRuleIndex() const {
  return TypeScriptParser::RuleElementList;
}

void TypeScriptParser::ElementListContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TypeScriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterElementList(this);
}

void TypeScriptParser::ElementListContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TypeScriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitElementList(this);
}


antlrcpp::Any TypeScriptParser::ElementListContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TypeScriptParserVisitor*>(visitor))
    return parserVisitor->visitElementList(this);
  else
    return visitor->visitChildren(this);
}

TypeScriptParser::ElementListContext* TypeScriptParser::elementList() {
  ElementListContext *_localctx = _tracker.createInstance<ElementListContext>(_ctx, getState());
  enterRule(_localctx, 110, TypeScriptParser::RuleElementList);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(666);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 75, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(663);
        match(TypeScriptParser::Comma); 
      }
      setState(668);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 75, _ctx);
    }
    setState(670);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << TypeScriptParser::RegularExpressionLiteral)
      | (1ULL << TypeScriptParser::OpenBracket)
      | (1ULL << TypeScriptParser::OpenParen)
      | (1ULL << TypeScriptParser::OpenBrace)
      | (1ULL << TypeScriptParser::Ellipsis)
      | (1ULL << TypeScriptParser::PlusPlus)
      | (1ULL << TypeScriptParser::MinusMinus)
      | (1ULL << TypeScriptParser::Plus)
      | (1ULL << TypeScriptParser::Minus)
      | (1ULL << TypeScriptParser::BitNot)
      | (1ULL << TypeScriptParser::Not)
      | (1ULL << TypeScriptParser::NullLiteral)
      | (1ULL << TypeScriptParser::BooleanLiteral)
      | (1ULL << TypeScriptParser::DecimalLiteral))) != 0) || ((((_la - 71) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 71)) & ((1ULL << (TypeScriptParser::HexIntegerLiteral - 71))
      | (1ULL << (TypeScriptParser::OctalIntegerLiteral - 71))
      | (1ULL << (TypeScriptParser::OctalIntegerLiteral2 - 71))
      | (1ULL << (TypeScriptParser::BinaryIntegerLiteral - 71))
      | (1ULL << (TypeScriptParser::BigHexIntegerLiteral - 71))
      | (1ULL << (TypeScriptParser::BigOctalIntegerLiteral - 71))
      | (1ULL << (TypeScriptParser::BigBinaryIntegerLiteral - 71))
      | (1ULL << (TypeScriptParser::BigDecimalIntegerLiteral - 71))
      | (1ULL << (TypeScriptParser::Typeof - 71))
      | (1ULL << (TypeScriptParser::New - 71))
      | (1ULL << (TypeScriptParser::Void - 71))
      | (1ULL << (TypeScriptParser::Function - 71))
      | (1ULL << (TypeScriptParser::This - 71))
      | (1ULL << (TypeScriptParser::Delete - 71))
      | (1ULL << (TypeScriptParser::Class - 71))
      | (1ULL << (TypeScriptParser::Super - 71))
      | (1ULL << (TypeScriptParser::Import - 71))
      | (1ULL << (TypeScriptParser::Async - 71))
      | (1ULL << (TypeScriptParser::Await - 71))
      | (1ULL << (TypeScriptParser::Yield - 71))
      | (1ULL << (TypeScriptParser::Identifier - 71))
      | (1ULL << (TypeScriptParser::StringLiteral - 71))
      | (1ULL << (TypeScriptParser::TemplateStringLiteral - 71)))) != 0)) {
      setState(669);
      arrayElement();
    }
    setState(680);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 78, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(673); 
        _errHandler->sync(this);
        _la = _input->LA(1);
        do {
          setState(672);
          match(TypeScriptParser::Comma);
          setState(675); 
          _errHandler->sync(this);
          _la = _input->LA(1);
        } while (_la == TypeScriptParser::Comma);
        setState(677);
        arrayElement(); 
      }
      setState(682);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 78, _ctx);
    }
    setState(686);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == TypeScriptParser::Comma) {
      setState(683);
      match(TypeScriptParser::Comma);
      setState(688);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ArrayElementContext ------------------------------------------------------------------

TypeScriptParser::ArrayElementContext::ArrayElementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

TypeScriptParser::SingleExpressionContext* TypeScriptParser::ArrayElementContext::singleExpression() {
  return getRuleContext<TypeScriptParser::SingleExpressionContext>(0);
}

tree::TerminalNode* TypeScriptParser::ArrayElementContext::Ellipsis() {
  return getToken(TypeScriptParser::Ellipsis, 0);
}


size_t TypeScriptParser::ArrayElementContext::getRuleIndex() const {
  return TypeScriptParser::RuleArrayElement;
}

void TypeScriptParser::ArrayElementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TypeScriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterArrayElement(this);
}

void TypeScriptParser::ArrayElementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TypeScriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitArrayElement(this);
}


antlrcpp::Any TypeScriptParser::ArrayElementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TypeScriptParserVisitor*>(visitor))
    return parserVisitor->visitArrayElement(this);
  else
    return visitor->visitChildren(this);
}

TypeScriptParser::ArrayElementContext* TypeScriptParser::arrayElement() {
  ArrayElementContext *_localctx = _tracker.createInstance<ArrayElementContext>(_ctx, getState());
  enterRule(_localctx, 112, TypeScriptParser::RuleArrayElement);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(690);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == TypeScriptParser::Ellipsis) {
      setState(689);
      match(TypeScriptParser::Ellipsis);
    }
    setState(692);
    singleExpression(0);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ObjectLiteralContext ------------------------------------------------------------------

TypeScriptParser::ObjectLiteralContext::ObjectLiteralContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* TypeScriptParser::ObjectLiteralContext::OpenBrace() {
  return getToken(TypeScriptParser::OpenBrace, 0);
}

tree::TerminalNode* TypeScriptParser::ObjectLiteralContext::CloseBrace() {
  return getToken(TypeScriptParser::CloseBrace, 0);
}

std::vector<TypeScriptParser::PropertyAssignmentContext *> TypeScriptParser::ObjectLiteralContext::propertyAssignment() {
  return getRuleContexts<TypeScriptParser::PropertyAssignmentContext>();
}

TypeScriptParser::PropertyAssignmentContext* TypeScriptParser::ObjectLiteralContext::propertyAssignment(size_t i) {
  return getRuleContext<TypeScriptParser::PropertyAssignmentContext>(i);
}

std::vector<tree::TerminalNode *> TypeScriptParser::ObjectLiteralContext::Comma() {
  return getTokens(TypeScriptParser::Comma);
}

tree::TerminalNode* TypeScriptParser::ObjectLiteralContext::Comma(size_t i) {
  return getToken(TypeScriptParser::Comma, i);
}


size_t TypeScriptParser::ObjectLiteralContext::getRuleIndex() const {
  return TypeScriptParser::RuleObjectLiteral;
}

void TypeScriptParser::ObjectLiteralContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TypeScriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterObjectLiteral(this);
}

void TypeScriptParser::ObjectLiteralContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TypeScriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitObjectLiteral(this);
}


antlrcpp::Any TypeScriptParser::ObjectLiteralContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TypeScriptParserVisitor*>(visitor))
    return parserVisitor->visitObjectLiteral(this);
  else
    return visitor->visitChildren(this);
}

TypeScriptParser::ObjectLiteralContext* TypeScriptParser::objectLiteral() {
  ObjectLiteralContext *_localctx = _tracker.createInstance<ObjectLiteralContext>(_ctx, getState());
  enterRule(_localctx, 114, TypeScriptParser::RuleObjectLiteral);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(694);
    match(TypeScriptParser::OpenBrace);
    setState(703);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << TypeScriptParser::RegularExpressionLiteral)
      | (1ULL << TypeScriptParser::OpenBracket)
      | (1ULL << TypeScriptParser::OpenParen)
      | (1ULL << TypeScriptParser::OpenBrace)
      | (1ULL << TypeScriptParser::Ellipsis)
      | (1ULL << TypeScriptParser::PlusPlus)
      | (1ULL << TypeScriptParser::MinusMinus)
      | (1ULL << TypeScriptParser::Plus)
      | (1ULL << TypeScriptParser::Minus)
      | (1ULL << TypeScriptParser::BitNot)
      | (1ULL << TypeScriptParser::Not)
      | (1ULL << TypeScriptParser::Multiply)
      | (1ULL << TypeScriptParser::NullLiteral)
      | (1ULL << TypeScriptParser::BooleanLiteral)
      | (1ULL << TypeScriptParser::DecimalLiteral))) != 0) || ((((_la - 71) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 71)) & ((1ULL << (TypeScriptParser::HexIntegerLiteral - 71))
      | (1ULL << (TypeScriptParser::OctalIntegerLiteral - 71))
      | (1ULL << (TypeScriptParser::OctalIntegerLiteral2 - 71))
      | (1ULL << (TypeScriptParser::BinaryIntegerLiteral - 71))
      | (1ULL << (TypeScriptParser::BigHexIntegerLiteral - 71))
      | (1ULL << (TypeScriptParser::BigOctalIntegerLiteral - 71))
      | (1ULL << (TypeScriptParser::BigBinaryIntegerLiteral - 71))
      | (1ULL << (TypeScriptParser::BigDecimalIntegerLiteral - 71))
      | (1ULL << (TypeScriptParser::Break - 71))
      | (1ULL << (TypeScriptParser::Do - 71))
      | (1ULL << (TypeScriptParser::Instanceof - 71))
      | (1ULL << (TypeScriptParser::Typeof - 71))
      | (1ULL << (TypeScriptParser::Case - 71))
      | (1ULL << (TypeScriptParser::Else - 71))
      | (1ULL << (TypeScriptParser::New - 71))
      | (1ULL << (TypeScriptParser::Var - 71))
      | (1ULL << (TypeScriptParser::Catch - 71))
      | (1ULL << (TypeScriptParser::Finally - 71))
      | (1ULL << (TypeScriptParser::Return - 71))
      | (1ULL << (TypeScriptParser::Void - 71))
      | (1ULL << (TypeScriptParser::Continue - 71))
      | (1ULL << (TypeScriptParser::For - 71))
      | (1ULL << (TypeScriptParser::Switch - 71))
      | (1ULL << (TypeScriptParser::While - 71))
      | (1ULL << (TypeScriptParser::Debugger - 71))
      | (1ULL << (TypeScriptParser::Function - 71))
      | (1ULL << (TypeScriptParser::This - 71))
      | (1ULL << (TypeScriptParser::With - 71))
      | (1ULL << (TypeScriptParser::Default - 71))
      | (1ULL << (TypeScriptParser::If - 71))
      | (1ULL << (TypeScriptParser::Throw - 71))
      | (1ULL << (TypeScriptParser::Delete - 71))
      | (1ULL << (TypeScriptParser::In - 71))
      | (1ULL << (TypeScriptParser::Try - 71))
      | (1ULL << (TypeScriptParser::As - 71))
      | (1ULL << (TypeScriptParser::From - 71))
      | (1ULL << (TypeScriptParser::Class - 71))
      | (1ULL << (TypeScriptParser::Enum - 71))
      | (1ULL << (TypeScriptParser::Extends - 71))
      | (1ULL << (TypeScriptParser::Super - 71))
      | (1ULL << (TypeScriptParser::Const - 71))
      | (1ULL << (TypeScriptParser::Export - 71))
      | (1ULL << (TypeScriptParser::Import - 71))
      | (1ULL << (TypeScriptParser::Async - 71))
      | (1ULL << (TypeScriptParser::Await - 71))
      | (1ULL << (TypeScriptParser::Implements - 71))
      | (1ULL << (TypeScriptParser::Let - 71))
      | (1ULL << (TypeScriptParser::Private - 71))
      | (1ULL << (TypeScriptParser::Public - 71))
      | (1ULL << (TypeScriptParser::Interface - 71))
      | (1ULL << (TypeScriptParser::Package - 71))
      | (1ULL << (TypeScriptParser::Protected - 71))
      | (1ULL << (TypeScriptParser::Static - 71))
      | (1ULL << (TypeScriptParser::Yield - 71))
      | (1ULL << (TypeScriptParser::Get - 71))
      | (1ULL << (TypeScriptParser::Set - 71))
      | (1ULL << (TypeScriptParser::Identifier - 71))
      | (1ULL << (TypeScriptParser::StringLiteral - 71))
      | (1ULL << (TypeScriptParser::TemplateStringLiteral - 71)))) != 0)) {
      setState(695);
      propertyAssignment();
      setState(700);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 81, _ctx);
      while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
        if (alt == 1) {
          setState(696);
          match(TypeScriptParser::Comma);
          setState(697);
          propertyAssignment(); 
        }
        setState(702);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 81, _ctx);
      }
    }
    setState(706);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == TypeScriptParser::Comma) {
      setState(705);
      match(TypeScriptParser::Comma);
    }
    setState(708);
    match(TypeScriptParser::CloseBrace);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- PropertyAssignmentContext ------------------------------------------------------------------

TypeScriptParser::PropertyAssignmentContext::PropertyAssignmentContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t TypeScriptParser::PropertyAssignmentContext::getRuleIndex() const {
  return TypeScriptParser::RulePropertyAssignment;
}

void TypeScriptParser::PropertyAssignmentContext::copyFrom(PropertyAssignmentContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- PropertyExpressionAssignmentContext ------------------------------------------------------------------

TypeScriptParser::PropertyNameContext* TypeScriptParser::PropertyExpressionAssignmentContext::propertyName() {
  return getRuleContext<TypeScriptParser::PropertyNameContext>(0);
}

tree::TerminalNode* TypeScriptParser::PropertyExpressionAssignmentContext::Colon() {
  return getToken(TypeScriptParser::Colon, 0);
}

TypeScriptParser::SingleExpressionContext* TypeScriptParser::PropertyExpressionAssignmentContext::singleExpression() {
  return getRuleContext<TypeScriptParser::SingleExpressionContext>(0);
}

TypeScriptParser::TypeSignContext* TypeScriptParser::PropertyExpressionAssignmentContext::typeSign() {
  return getRuleContext<TypeScriptParser::TypeSignContext>(0);
}

TypeScriptParser::PropertyExpressionAssignmentContext::PropertyExpressionAssignmentContext(PropertyAssignmentContext *ctx) { copyFrom(ctx); }

void TypeScriptParser::PropertyExpressionAssignmentContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TypeScriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterPropertyExpressionAssignment(this);
}
void TypeScriptParser::PropertyExpressionAssignmentContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TypeScriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitPropertyExpressionAssignment(this);
}

antlrcpp::Any TypeScriptParser::PropertyExpressionAssignmentContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TypeScriptParserVisitor*>(visitor))
    return parserVisitor->visitPropertyExpressionAssignment(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ComputedPropertyExpressionAssignmentContext ------------------------------------------------------------------

tree::TerminalNode* TypeScriptParser::ComputedPropertyExpressionAssignmentContext::OpenBracket() {
  return getToken(TypeScriptParser::OpenBracket, 0);
}

std::vector<TypeScriptParser::SingleExpressionContext *> TypeScriptParser::ComputedPropertyExpressionAssignmentContext::singleExpression() {
  return getRuleContexts<TypeScriptParser::SingleExpressionContext>();
}

TypeScriptParser::SingleExpressionContext* TypeScriptParser::ComputedPropertyExpressionAssignmentContext::singleExpression(size_t i) {
  return getRuleContext<TypeScriptParser::SingleExpressionContext>(i);
}

tree::TerminalNode* TypeScriptParser::ComputedPropertyExpressionAssignmentContext::CloseBracket() {
  return getToken(TypeScriptParser::CloseBracket, 0);
}

tree::TerminalNode* TypeScriptParser::ComputedPropertyExpressionAssignmentContext::Colon() {
  return getToken(TypeScriptParser::Colon, 0);
}

TypeScriptParser::ComputedPropertyExpressionAssignmentContext::ComputedPropertyExpressionAssignmentContext(PropertyAssignmentContext *ctx) { copyFrom(ctx); }

void TypeScriptParser::ComputedPropertyExpressionAssignmentContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TypeScriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterComputedPropertyExpressionAssignment(this);
}
void TypeScriptParser::ComputedPropertyExpressionAssignmentContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TypeScriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitComputedPropertyExpressionAssignment(this);
}

antlrcpp::Any TypeScriptParser::ComputedPropertyExpressionAssignmentContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TypeScriptParserVisitor*>(visitor))
    return parserVisitor->visitComputedPropertyExpressionAssignment(this);
  else
    return visitor->visitChildren(this);
}
//----------------- PropertyShorthandContext ------------------------------------------------------------------

TypeScriptParser::SingleExpressionContext* TypeScriptParser::PropertyShorthandContext::singleExpression() {
  return getRuleContext<TypeScriptParser::SingleExpressionContext>(0);
}

tree::TerminalNode* TypeScriptParser::PropertyShorthandContext::Ellipsis() {
  return getToken(TypeScriptParser::Ellipsis, 0);
}

TypeScriptParser::PropertyShorthandContext::PropertyShorthandContext(PropertyAssignmentContext *ctx) { copyFrom(ctx); }

void TypeScriptParser::PropertyShorthandContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TypeScriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterPropertyShorthand(this);
}
void TypeScriptParser::PropertyShorthandContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TypeScriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitPropertyShorthand(this);
}

antlrcpp::Any TypeScriptParser::PropertyShorthandContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TypeScriptParserVisitor*>(visitor))
    return parserVisitor->visitPropertyShorthand(this);
  else
    return visitor->visitChildren(this);
}
//----------------- PropertySetterContext ------------------------------------------------------------------

TypeScriptParser::SetterContext* TypeScriptParser::PropertySetterContext::setter() {
  return getRuleContext<TypeScriptParser::SetterContext>(0);
}

tree::TerminalNode* TypeScriptParser::PropertySetterContext::OpenParen() {
  return getToken(TypeScriptParser::OpenParen, 0);
}

TypeScriptParser::FormalParameterArgContext* TypeScriptParser::PropertySetterContext::formalParameterArg() {
  return getRuleContext<TypeScriptParser::FormalParameterArgContext>(0);
}

tree::TerminalNode* TypeScriptParser::PropertySetterContext::CloseParen() {
  return getToken(TypeScriptParser::CloseParen, 0);
}

tree::TerminalNode* TypeScriptParser::PropertySetterContext::OpenBrace() {
  return getToken(TypeScriptParser::OpenBrace, 0);
}

TypeScriptParser::FunctionBodyContext* TypeScriptParser::PropertySetterContext::functionBody() {
  return getRuleContext<TypeScriptParser::FunctionBodyContext>(0);
}

tree::TerminalNode* TypeScriptParser::PropertySetterContext::CloseBrace() {
  return getToken(TypeScriptParser::CloseBrace, 0);
}

TypeScriptParser::PropertySetterContext::PropertySetterContext(PropertyAssignmentContext *ctx) { copyFrom(ctx); }

void TypeScriptParser::PropertySetterContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TypeScriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterPropertySetter(this);
}
void TypeScriptParser::PropertySetterContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TypeScriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitPropertySetter(this);
}

antlrcpp::Any TypeScriptParser::PropertySetterContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TypeScriptParserVisitor*>(visitor))
    return parserVisitor->visitPropertySetter(this);
  else
    return visitor->visitChildren(this);
}
//----------------- PropertyGetterContext ------------------------------------------------------------------

TypeScriptParser::GetterContext* TypeScriptParser::PropertyGetterContext::getter() {
  return getRuleContext<TypeScriptParser::GetterContext>(0);
}

tree::TerminalNode* TypeScriptParser::PropertyGetterContext::OpenParen() {
  return getToken(TypeScriptParser::OpenParen, 0);
}

tree::TerminalNode* TypeScriptParser::PropertyGetterContext::CloseParen() {
  return getToken(TypeScriptParser::CloseParen, 0);
}

tree::TerminalNode* TypeScriptParser::PropertyGetterContext::OpenBrace() {
  return getToken(TypeScriptParser::OpenBrace, 0);
}

TypeScriptParser::FunctionBodyContext* TypeScriptParser::PropertyGetterContext::functionBody() {
  return getRuleContext<TypeScriptParser::FunctionBodyContext>(0);
}

tree::TerminalNode* TypeScriptParser::PropertyGetterContext::CloseBrace() {
  return getToken(TypeScriptParser::CloseBrace, 0);
}

TypeScriptParser::PropertyGetterContext::PropertyGetterContext(PropertyAssignmentContext *ctx) { copyFrom(ctx); }

void TypeScriptParser::PropertyGetterContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TypeScriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterPropertyGetter(this);
}
void TypeScriptParser::PropertyGetterContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TypeScriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitPropertyGetter(this);
}

antlrcpp::Any TypeScriptParser::PropertyGetterContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TypeScriptParserVisitor*>(visitor))
    return parserVisitor->visitPropertyGetter(this);
  else
    return visitor->visitChildren(this);
}
//----------------- FunctionPropertyContext ------------------------------------------------------------------

TypeScriptParser::PropertyNameContext* TypeScriptParser::FunctionPropertyContext::propertyName() {
  return getRuleContext<TypeScriptParser::PropertyNameContext>(0);
}

tree::TerminalNode* TypeScriptParser::FunctionPropertyContext::OpenParen() {
  return getToken(TypeScriptParser::OpenParen, 0);
}

tree::TerminalNode* TypeScriptParser::FunctionPropertyContext::CloseParen() {
  return getToken(TypeScriptParser::CloseParen, 0);
}

tree::TerminalNode* TypeScriptParser::FunctionPropertyContext::OpenBrace() {
  return getToken(TypeScriptParser::OpenBrace, 0);
}

TypeScriptParser::FunctionBodyContext* TypeScriptParser::FunctionPropertyContext::functionBody() {
  return getRuleContext<TypeScriptParser::FunctionBodyContext>(0);
}

tree::TerminalNode* TypeScriptParser::FunctionPropertyContext::CloseBrace() {
  return getToken(TypeScriptParser::CloseBrace, 0);
}

tree::TerminalNode* TypeScriptParser::FunctionPropertyContext::Async() {
  return getToken(TypeScriptParser::Async, 0);
}

tree::TerminalNode* TypeScriptParser::FunctionPropertyContext::Multiply() {
  return getToken(TypeScriptParser::Multiply, 0);
}

TypeScriptParser::TypeSignContext* TypeScriptParser::FunctionPropertyContext::typeSign() {
  return getRuleContext<TypeScriptParser::TypeSignContext>(0);
}

TypeScriptParser::FormalParameterListContext* TypeScriptParser::FunctionPropertyContext::formalParameterList() {
  return getRuleContext<TypeScriptParser::FormalParameterListContext>(0);
}

TypeScriptParser::FunctionPropertyContext::FunctionPropertyContext(PropertyAssignmentContext *ctx) { copyFrom(ctx); }

void TypeScriptParser::FunctionPropertyContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TypeScriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFunctionProperty(this);
}
void TypeScriptParser::FunctionPropertyContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TypeScriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFunctionProperty(this);
}

antlrcpp::Any TypeScriptParser::FunctionPropertyContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TypeScriptParserVisitor*>(visitor))
    return parserVisitor->visitFunctionProperty(this);
  else
    return visitor->visitChildren(this);
}
TypeScriptParser::PropertyAssignmentContext* TypeScriptParser::propertyAssignment() {
  PropertyAssignmentContext *_localctx = _tracker.createInstance<PropertyAssignmentContext>(_ctx, getState());
  enterRule(_localctx, 116, TypeScriptParser::RulePropertyAssignment);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(761);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 90, _ctx)) {
    case 1: {
      _localctx = dynamic_cast<PropertyAssignmentContext *>(_tracker.createInstance<TypeScriptParser::PropertyExpressionAssignmentContext>(_localctx));
      enterOuterAlt(_localctx, 1);
      setState(710);
      propertyName();
      setState(712);
      _errHandler->sync(this);

      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 84, _ctx)) {
      case 1: {
        setState(711);
        typeSign();
        break;
      }

      }
      setState(714);
      match(TypeScriptParser::Colon);
      setState(715);
      singleExpression(0);
      break;
    }

    case 2: {
      _localctx = dynamic_cast<PropertyAssignmentContext *>(_tracker.createInstance<TypeScriptParser::ComputedPropertyExpressionAssignmentContext>(_localctx));
      enterOuterAlt(_localctx, 2);
      setState(717);
      match(TypeScriptParser::OpenBracket);
      setState(718);
      singleExpression(0);
      setState(719);
      match(TypeScriptParser::CloseBracket);
      setState(720);
      match(TypeScriptParser::Colon);
      setState(721);
      singleExpression(0);
      break;
    }

    case 3: {
      _localctx = dynamic_cast<PropertyAssignmentContext *>(_tracker.createInstance<TypeScriptParser::FunctionPropertyContext>(_localctx));
      enterOuterAlt(_localctx, 3);
      setState(724);
      _errHandler->sync(this);

      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 85, _ctx)) {
      case 1: {
        setState(723);
        match(TypeScriptParser::Async);
        break;
      }

      }
      setState(727);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == TypeScriptParser::Multiply) {
        setState(726);
        match(TypeScriptParser::Multiply);
      }
      setState(729);
      propertyName();
      setState(731);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == TypeScriptParser::Colon) {
        setState(730);
        typeSign();
      }
      setState(733);
      match(TypeScriptParser::OpenParen);
      setState(735);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & ((1ULL << TypeScriptParser::OpenBracket)
        | (1ULL << TypeScriptParser::OpenBrace)
        | (1ULL << TypeScriptParser::Ellipsis))) != 0) || _la == TypeScriptParser::Identifier) {
        setState(734);
        formalParameterList();
      }
      setState(737);
      match(TypeScriptParser::CloseParen);
      setState(738);
      match(TypeScriptParser::OpenBrace);
      setState(739);
      functionBody();
      setState(740);
      match(TypeScriptParser::CloseBrace);
      break;
    }

    case 4: {
      _localctx = dynamic_cast<PropertyAssignmentContext *>(_tracker.createInstance<TypeScriptParser::PropertyGetterContext>(_localctx));
      enterOuterAlt(_localctx, 4);
      setState(742);
      getter();
      setState(743);
      match(TypeScriptParser::OpenParen);
      setState(744);
      match(TypeScriptParser::CloseParen);
      setState(745);
      match(TypeScriptParser::OpenBrace);
      setState(746);
      functionBody();
      setState(747);
      match(TypeScriptParser::CloseBrace);
      break;
    }

    case 5: {
      _localctx = dynamic_cast<PropertyAssignmentContext *>(_tracker.createInstance<TypeScriptParser::PropertySetterContext>(_localctx));
      enterOuterAlt(_localctx, 5);
      setState(749);
      setter();
      setState(750);
      match(TypeScriptParser::OpenParen);
      setState(751);
      formalParameterArg();
      setState(752);
      match(TypeScriptParser::CloseParen);
      setState(753);
      match(TypeScriptParser::OpenBrace);
      setState(754);
      functionBody();
      setState(755);
      match(TypeScriptParser::CloseBrace);
      break;
    }

    case 6: {
      _localctx = dynamic_cast<PropertyAssignmentContext *>(_tracker.createInstance<TypeScriptParser::PropertyShorthandContext>(_localctx));
      enterOuterAlt(_localctx, 6);
      setState(758);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == TypeScriptParser::Ellipsis) {
        setState(757);
        match(TypeScriptParser::Ellipsis);
      }
      setState(760);
      singleExpression(0);
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- PropertyNameContext ------------------------------------------------------------------

TypeScriptParser::PropertyNameContext::PropertyNameContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

TypeScriptParser::IdentifierNameContext* TypeScriptParser::PropertyNameContext::identifierName() {
  return getRuleContext<TypeScriptParser::IdentifierNameContext>(0);
}

tree::TerminalNode* TypeScriptParser::PropertyNameContext::StringLiteral() {
  return getToken(TypeScriptParser::StringLiteral, 0);
}

TypeScriptParser::NumericLiteralContext* TypeScriptParser::PropertyNameContext::numericLiteral() {
  return getRuleContext<TypeScriptParser::NumericLiteralContext>(0);
}

tree::TerminalNode* TypeScriptParser::PropertyNameContext::OpenBracket() {
  return getToken(TypeScriptParser::OpenBracket, 0);
}

TypeScriptParser::SingleExpressionContext* TypeScriptParser::PropertyNameContext::singleExpression() {
  return getRuleContext<TypeScriptParser::SingleExpressionContext>(0);
}

tree::TerminalNode* TypeScriptParser::PropertyNameContext::CloseBracket() {
  return getToken(TypeScriptParser::CloseBracket, 0);
}


size_t TypeScriptParser::PropertyNameContext::getRuleIndex() const {
  return TypeScriptParser::RulePropertyName;
}

void TypeScriptParser::PropertyNameContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TypeScriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterPropertyName(this);
}

void TypeScriptParser::PropertyNameContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TypeScriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitPropertyName(this);
}


antlrcpp::Any TypeScriptParser::PropertyNameContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TypeScriptParserVisitor*>(visitor))
    return parserVisitor->visitPropertyName(this);
  else
    return visitor->visitChildren(this);
}

TypeScriptParser::PropertyNameContext* TypeScriptParser::propertyName() {
  PropertyNameContext *_localctx = _tracker.createInstance<PropertyNameContext>(_ctx, getState());
  enterRule(_localctx, 118, TypeScriptParser::RulePropertyName);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(770);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case TypeScriptParser::NullLiteral:
      case TypeScriptParser::BooleanLiteral:
      case TypeScriptParser::Break:
      case TypeScriptParser::Do:
      case TypeScriptParser::Instanceof:
      case TypeScriptParser::Typeof:
      case TypeScriptParser::Case:
      case TypeScriptParser::Else:
      case TypeScriptParser::New:
      case TypeScriptParser::Var:
      case TypeScriptParser::Catch:
      case TypeScriptParser::Finally:
      case TypeScriptParser::Return:
      case TypeScriptParser::Void:
      case TypeScriptParser::Continue:
      case TypeScriptParser::For:
      case TypeScriptParser::Switch:
      case TypeScriptParser::While:
      case TypeScriptParser::Debugger:
      case TypeScriptParser::Function:
      case TypeScriptParser::This:
      case TypeScriptParser::With:
      case TypeScriptParser::Default:
      case TypeScriptParser::If:
      case TypeScriptParser::Throw:
      case TypeScriptParser::Delete:
      case TypeScriptParser::In:
      case TypeScriptParser::Try:
      case TypeScriptParser::As:
      case TypeScriptParser::From:
      case TypeScriptParser::Class:
      case TypeScriptParser::Enum:
      case TypeScriptParser::Extends:
      case TypeScriptParser::Super:
      case TypeScriptParser::Const:
      case TypeScriptParser::Export:
      case TypeScriptParser::Import:
      case TypeScriptParser::Async:
      case TypeScriptParser::Await:
      case TypeScriptParser::Implements:
      case TypeScriptParser::Let:
      case TypeScriptParser::Private:
      case TypeScriptParser::Public:
      case TypeScriptParser::Interface:
      case TypeScriptParser::Package:
      case TypeScriptParser::Protected:
      case TypeScriptParser::Static:
      case TypeScriptParser::Yield:
      case TypeScriptParser::Identifier: {
        enterOuterAlt(_localctx, 1);
        setState(763);
        identifierName();
        break;
      }

      case TypeScriptParser::StringLiteral: {
        enterOuterAlt(_localctx, 2);
        setState(764);
        match(TypeScriptParser::StringLiteral);
        break;
      }

      case TypeScriptParser::DecimalLiteral:
      case TypeScriptParser::HexIntegerLiteral:
      case TypeScriptParser::OctalIntegerLiteral:
      case TypeScriptParser::OctalIntegerLiteral2:
      case TypeScriptParser::BinaryIntegerLiteral: {
        enterOuterAlt(_localctx, 3);
        setState(765);
        numericLiteral();
        break;
      }

      case TypeScriptParser::OpenBracket: {
        enterOuterAlt(_localctx, 4);
        setState(766);
        match(TypeScriptParser::OpenBracket);
        setState(767);
        singleExpression(0);
        setState(768);
        match(TypeScriptParser::CloseBracket);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ArgumentsContext ------------------------------------------------------------------

TypeScriptParser::ArgumentsContext::ArgumentsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* TypeScriptParser::ArgumentsContext::OpenParen() {
  return getToken(TypeScriptParser::OpenParen, 0);
}

tree::TerminalNode* TypeScriptParser::ArgumentsContext::CloseParen() {
  return getToken(TypeScriptParser::CloseParen, 0);
}

std::vector<TypeScriptParser::ArgumentContext *> TypeScriptParser::ArgumentsContext::argument() {
  return getRuleContexts<TypeScriptParser::ArgumentContext>();
}

TypeScriptParser::ArgumentContext* TypeScriptParser::ArgumentsContext::argument(size_t i) {
  return getRuleContext<TypeScriptParser::ArgumentContext>(i);
}

std::vector<tree::TerminalNode *> TypeScriptParser::ArgumentsContext::Comma() {
  return getTokens(TypeScriptParser::Comma);
}

tree::TerminalNode* TypeScriptParser::ArgumentsContext::Comma(size_t i) {
  return getToken(TypeScriptParser::Comma, i);
}


size_t TypeScriptParser::ArgumentsContext::getRuleIndex() const {
  return TypeScriptParser::RuleArguments;
}

void TypeScriptParser::ArgumentsContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TypeScriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterArguments(this);
}

void TypeScriptParser::ArgumentsContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TypeScriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitArguments(this);
}


antlrcpp::Any TypeScriptParser::ArgumentsContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TypeScriptParserVisitor*>(visitor))
    return parserVisitor->visitArguments(this);
  else
    return visitor->visitChildren(this);
}

TypeScriptParser::ArgumentsContext* TypeScriptParser::arguments() {
  ArgumentsContext *_localctx = _tracker.createInstance<ArgumentsContext>(_ctx, getState());
  enterRule(_localctx, 120, TypeScriptParser::RuleArguments);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(772);
    match(TypeScriptParser::OpenParen);
    setState(784);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << TypeScriptParser::RegularExpressionLiteral)
      | (1ULL << TypeScriptParser::OpenBracket)
      | (1ULL << TypeScriptParser::OpenParen)
      | (1ULL << TypeScriptParser::OpenBrace)
      | (1ULL << TypeScriptParser::Ellipsis)
      | (1ULL << TypeScriptParser::PlusPlus)
      | (1ULL << TypeScriptParser::MinusMinus)
      | (1ULL << TypeScriptParser::Plus)
      | (1ULL << TypeScriptParser::Minus)
      | (1ULL << TypeScriptParser::BitNot)
      | (1ULL << TypeScriptParser::Not)
      | (1ULL << TypeScriptParser::NullLiteral)
      | (1ULL << TypeScriptParser::BooleanLiteral)
      | (1ULL << TypeScriptParser::DecimalLiteral))) != 0) || ((((_la - 71) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 71)) & ((1ULL << (TypeScriptParser::HexIntegerLiteral - 71))
      | (1ULL << (TypeScriptParser::OctalIntegerLiteral - 71))
      | (1ULL << (TypeScriptParser::OctalIntegerLiteral2 - 71))
      | (1ULL << (TypeScriptParser::BinaryIntegerLiteral - 71))
      | (1ULL << (TypeScriptParser::BigHexIntegerLiteral - 71))
      | (1ULL << (TypeScriptParser::BigOctalIntegerLiteral - 71))
      | (1ULL << (TypeScriptParser::BigBinaryIntegerLiteral - 71))
      | (1ULL << (TypeScriptParser::BigDecimalIntegerLiteral - 71))
      | (1ULL << (TypeScriptParser::Typeof - 71))
      | (1ULL << (TypeScriptParser::New - 71))
      | (1ULL << (TypeScriptParser::Void - 71))
      | (1ULL << (TypeScriptParser::Function - 71))
      | (1ULL << (TypeScriptParser::This - 71))
      | (1ULL << (TypeScriptParser::Delete - 71))
      | (1ULL << (TypeScriptParser::Class - 71))
      | (1ULL << (TypeScriptParser::Super - 71))
      | (1ULL << (TypeScriptParser::Import - 71))
      | (1ULL << (TypeScriptParser::Async - 71))
      | (1ULL << (TypeScriptParser::Await - 71))
      | (1ULL << (TypeScriptParser::Yield - 71))
      | (1ULL << (TypeScriptParser::Identifier - 71))
      | (1ULL << (TypeScriptParser::StringLiteral - 71))
      | (1ULL << (TypeScriptParser::TemplateStringLiteral - 71)))) != 0)) {
      setState(773);
      argument();
      setState(778);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 92, _ctx);
      while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
        if (alt == 1) {
          setState(774);
          match(TypeScriptParser::Comma);
          setState(775);
          argument(); 
        }
        setState(780);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 92, _ctx);
      }
      setState(782);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == TypeScriptParser::Comma) {
        setState(781);
        match(TypeScriptParser::Comma);
      }
    }
    setState(786);
    match(TypeScriptParser::CloseParen);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ArgumentContext ------------------------------------------------------------------

TypeScriptParser::ArgumentContext::ArgumentContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

TypeScriptParser::SingleExpressionContext* TypeScriptParser::ArgumentContext::singleExpression() {
  return getRuleContext<TypeScriptParser::SingleExpressionContext>(0);
}

tree::TerminalNode* TypeScriptParser::ArgumentContext::Identifier() {
  return getToken(TypeScriptParser::Identifier, 0);
}

tree::TerminalNode* TypeScriptParser::ArgumentContext::Ellipsis() {
  return getToken(TypeScriptParser::Ellipsis, 0);
}


size_t TypeScriptParser::ArgumentContext::getRuleIndex() const {
  return TypeScriptParser::RuleArgument;
}

void TypeScriptParser::ArgumentContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TypeScriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterArgument(this);
}

void TypeScriptParser::ArgumentContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TypeScriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitArgument(this);
}


antlrcpp::Any TypeScriptParser::ArgumentContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TypeScriptParserVisitor*>(visitor))
    return parserVisitor->visitArgument(this);
  else
    return visitor->visitChildren(this);
}

TypeScriptParser::ArgumentContext* TypeScriptParser::argument() {
  ArgumentContext *_localctx = _tracker.createInstance<ArgumentContext>(_ctx, getState());
  enterRule(_localctx, 122, TypeScriptParser::RuleArgument);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(789);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == TypeScriptParser::Ellipsis) {
      setState(788);
      match(TypeScriptParser::Ellipsis);
    }
    setState(793);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 96, _ctx)) {
    case 1: {
      setState(791);
      singleExpression(0);
      break;
    }

    case 2: {
      setState(792);
      match(TypeScriptParser::Identifier);
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ExpressionSequenceContext ------------------------------------------------------------------

TypeScriptParser::ExpressionSequenceContext::ExpressionSequenceContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<TypeScriptParser::SingleExpressionContext *> TypeScriptParser::ExpressionSequenceContext::singleExpression() {
  return getRuleContexts<TypeScriptParser::SingleExpressionContext>();
}

TypeScriptParser::SingleExpressionContext* TypeScriptParser::ExpressionSequenceContext::singleExpression(size_t i) {
  return getRuleContext<TypeScriptParser::SingleExpressionContext>(i);
}

std::vector<tree::TerminalNode *> TypeScriptParser::ExpressionSequenceContext::Comma() {
  return getTokens(TypeScriptParser::Comma);
}

tree::TerminalNode* TypeScriptParser::ExpressionSequenceContext::Comma(size_t i) {
  return getToken(TypeScriptParser::Comma, i);
}


size_t TypeScriptParser::ExpressionSequenceContext::getRuleIndex() const {
  return TypeScriptParser::RuleExpressionSequence;
}

void TypeScriptParser::ExpressionSequenceContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TypeScriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterExpressionSequence(this);
}

void TypeScriptParser::ExpressionSequenceContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TypeScriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitExpressionSequence(this);
}


antlrcpp::Any TypeScriptParser::ExpressionSequenceContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TypeScriptParserVisitor*>(visitor))
    return parserVisitor->visitExpressionSequence(this);
  else
    return visitor->visitChildren(this);
}

TypeScriptParser::ExpressionSequenceContext* TypeScriptParser::expressionSequence() {
  ExpressionSequenceContext *_localctx = _tracker.createInstance<ExpressionSequenceContext>(_ctx, getState());
  enterRule(_localctx, 124, TypeScriptParser::RuleExpressionSequence);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(795);
    singleExpression(0);
    setState(800);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == TypeScriptParser::Comma) {
      setState(796);
      match(TypeScriptParser::Comma);
      setState(797);
      singleExpression(0);
      setState(802);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- SingleExpressionContext ------------------------------------------------------------------

TypeScriptParser::SingleExpressionContext::SingleExpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t TypeScriptParser::SingleExpressionContext::getRuleIndex() const {
  return TypeScriptParser::RuleSingleExpression;
}

void TypeScriptParser::SingleExpressionContext::copyFrom(SingleExpressionContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- TemplateStringExpressionContext ------------------------------------------------------------------

TypeScriptParser::SingleExpressionContext* TypeScriptParser::TemplateStringExpressionContext::singleExpression() {
  return getRuleContext<TypeScriptParser::SingleExpressionContext>(0);
}

tree::TerminalNode* TypeScriptParser::TemplateStringExpressionContext::TemplateStringLiteral() {
  return getToken(TypeScriptParser::TemplateStringLiteral, 0);
}

TypeScriptParser::TemplateStringExpressionContext::TemplateStringExpressionContext(SingleExpressionContext *ctx) { copyFrom(ctx); }

void TypeScriptParser::TemplateStringExpressionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TypeScriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterTemplateStringExpression(this);
}
void TypeScriptParser::TemplateStringExpressionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TypeScriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitTemplateStringExpression(this);
}

antlrcpp::Any TypeScriptParser::TemplateStringExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TypeScriptParserVisitor*>(visitor))
    return parserVisitor->visitTemplateStringExpression(this);
  else
    return visitor->visitChildren(this);
}
//----------------- TernaryExpressionContext ------------------------------------------------------------------

std::vector<TypeScriptParser::SingleExpressionContext *> TypeScriptParser::TernaryExpressionContext::singleExpression() {
  return getRuleContexts<TypeScriptParser::SingleExpressionContext>();
}

TypeScriptParser::SingleExpressionContext* TypeScriptParser::TernaryExpressionContext::singleExpression(size_t i) {
  return getRuleContext<TypeScriptParser::SingleExpressionContext>(i);
}

tree::TerminalNode* TypeScriptParser::TernaryExpressionContext::QuestionMark() {
  return getToken(TypeScriptParser::QuestionMark, 0);
}

tree::TerminalNode* TypeScriptParser::TernaryExpressionContext::Colon() {
  return getToken(TypeScriptParser::Colon, 0);
}

TypeScriptParser::TernaryExpressionContext::TernaryExpressionContext(SingleExpressionContext *ctx) { copyFrom(ctx); }

void TypeScriptParser::TernaryExpressionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TypeScriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterTernaryExpression(this);
}
void TypeScriptParser::TernaryExpressionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TypeScriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitTernaryExpression(this);
}

antlrcpp::Any TypeScriptParser::TernaryExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TypeScriptParserVisitor*>(visitor))
    return parserVisitor->visitTernaryExpression(this);
  else
    return visitor->visitChildren(this);
}
//----------------- LogicalAndExpressionContext ------------------------------------------------------------------

std::vector<TypeScriptParser::SingleExpressionContext *> TypeScriptParser::LogicalAndExpressionContext::singleExpression() {
  return getRuleContexts<TypeScriptParser::SingleExpressionContext>();
}

TypeScriptParser::SingleExpressionContext* TypeScriptParser::LogicalAndExpressionContext::singleExpression(size_t i) {
  return getRuleContext<TypeScriptParser::SingleExpressionContext>(i);
}

tree::TerminalNode* TypeScriptParser::LogicalAndExpressionContext::And() {
  return getToken(TypeScriptParser::And, 0);
}

TypeScriptParser::LogicalAndExpressionContext::LogicalAndExpressionContext(SingleExpressionContext *ctx) { copyFrom(ctx); }

void TypeScriptParser::LogicalAndExpressionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TypeScriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterLogicalAndExpression(this);
}
void TypeScriptParser::LogicalAndExpressionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TypeScriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitLogicalAndExpression(this);
}

antlrcpp::Any TypeScriptParser::LogicalAndExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TypeScriptParserVisitor*>(visitor))
    return parserVisitor->visitLogicalAndExpression(this);
  else
    return visitor->visitChildren(this);
}
//----------------- PowerExpressionContext ------------------------------------------------------------------

std::vector<TypeScriptParser::SingleExpressionContext *> TypeScriptParser::PowerExpressionContext::singleExpression() {
  return getRuleContexts<TypeScriptParser::SingleExpressionContext>();
}

TypeScriptParser::SingleExpressionContext* TypeScriptParser::PowerExpressionContext::singleExpression(size_t i) {
  return getRuleContext<TypeScriptParser::SingleExpressionContext>(i);
}

tree::TerminalNode* TypeScriptParser::PowerExpressionContext::Power() {
  return getToken(TypeScriptParser::Power, 0);
}

TypeScriptParser::PowerExpressionContext::PowerExpressionContext(SingleExpressionContext *ctx) { copyFrom(ctx); }

void TypeScriptParser::PowerExpressionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TypeScriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterPowerExpression(this);
}
void TypeScriptParser::PowerExpressionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TypeScriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitPowerExpression(this);
}

antlrcpp::Any TypeScriptParser::PowerExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TypeScriptParserVisitor*>(visitor))
    return parserVisitor->visitPowerExpression(this);
  else
    return visitor->visitChildren(this);
}
//----------------- PreIncrementExpressionContext ------------------------------------------------------------------

tree::TerminalNode* TypeScriptParser::PreIncrementExpressionContext::PlusPlus() {
  return getToken(TypeScriptParser::PlusPlus, 0);
}

TypeScriptParser::SingleExpressionContext* TypeScriptParser::PreIncrementExpressionContext::singleExpression() {
  return getRuleContext<TypeScriptParser::SingleExpressionContext>(0);
}

TypeScriptParser::PreIncrementExpressionContext::PreIncrementExpressionContext(SingleExpressionContext *ctx) { copyFrom(ctx); }

void TypeScriptParser::PreIncrementExpressionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TypeScriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterPreIncrementExpression(this);
}
void TypeScriptParser::PreIncrementExpressionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TypeScriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitPreIncrementExpression(this);
}

antlrcpp::Any TypeScriptParser::PreIncrementExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TypeScriptParserVisitor*>(visitor))
    return parserVisitor->visitPreIncrementExpression(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ObjectLiteralExpressionContext ------------------------------------------------------------------

TypeScriptParser::ObjectLiteralContext* TypeScriptParser::ObjectLiteralExpressionContext::objectLiteral() {
  return getRuleContext<TypeScriptParser::ObjectLiteralContext>(0);
}

TypeScriptParser::ObjectLiteralExpressionContext::ObjectLiteralExpressionContext(SingleExpressionContext *ctx) { copyFrom(ctx); }

void TypeScriptParser::ObjectLiteralExpressionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TypeScriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterObjectLiteralExpression(this);
}
void TypeScriptParser::ObjectLiteralExpressionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TypeScriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitObjectLiteralExpression(this);
}

antlrcpp::Any TypeScriptParser::ObjectLiteralExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TypeScriptParserVisitor*>(visitor))
    return parserVisitor->visitObjectLiteralExpression(this);
  else
    return visitor->visitChildren(this);
}
//----------------- MetaExpressionContext ------------------------------------------------------------------

tree::TerminalNode* TypeScriptParser::MetaExpressionContext::New() {
  return getToken(TypeScriptParser::New, 0);
}

tree::TerminalNode* TypeScriptParser::MetaExpressionContext::Dot() {
  return getToken(TypeScriptParser::Dot, 0);
}

tree::TerminalNode* TypeScriptParser::MetaExpressionContext::Identifier() {
  return getToken(TypeScriptParser::Identifier, 0);
}

TypeScriptParser::MetaExpressionContext::MetaExpressionContext(SingleExpressionContext *ctx) { copyFrom(ctx); }

void TypeScriptParser::MetaExpressionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TypeScriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterMetaExpression(this);
}
void TypeScriptParser::MetaExpressionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TypeScriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitMetaExpression(this);
}

antlrcpp::Any TypeScriptParser::MetaExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TypeScriptParserVisitor*>(visitor))
    return parserVisitor->visitMetaExpression(this);
  else
    return visitor->visitChildren(this);
}
//----------------- InExpressionContext ------------------------------------------------------------------

std::vector<TypeScriptParser::SingleExpressionContext *> TypeScriptParser::InExpressionContext::singleExpression() {
  return getRuleContexts<TypeScriptParser::SingleExpressionContext>();
}

TypeScriptParser::SingleExpressionContext* TypeScriptParser::InExpressionContext::singleExpression(size_t i) {
  return getRuleContext<TypeScriptParser::SingleExpressionContext>(i);
}

tree::TerminalNode* TypeScriptParser::InExpressionContext::In() {
  return getToken(TypeScriptParser::In, 0);
}

TypeScriptParser::InExpressionContext::InExpressionContext(SingleExpressionContext *ctx) { copyFrom(ctx); }

void TypeScriptParser::InExpressionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TypeScriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterInExpression(this);
}
void TypeScriptParser::InExpressionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TypeScriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitInExpression(this);
}

antlrcpp::Any TypeScriptParser::InExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TypeScriptParserVisitor*>(visitor))
    return parserVisitor->visitInExpression(this);
  else
    return visitor->visitChildren(this);
}
//----------------- LogicalOrExpressionContext ------------------------------------------------------------------

std::vector<TypeScriptParser::SingleExpressionContext *> TypeScriptParser::LogicalOrExpressionContext::singleExpression() {
  return getRuleContexts<TypeScriptParser::SingleExpressionContext>();
}

TypeScriptParser::SingleExpressionContext* TypeScriptParser::LogicalOrExpressionContext::singleExpression(size_t i) {
  return getRuleContext<TypeScriptParser::SingleExpressionContext>(i);
}

tree::TerminalNode* TypeScriptParser::LogicalOrExpressionContext::Or() {
  return getToken(TypeScriptParser::Or, 0);
}

TypeScriptParser::LogicalOrExpressionContext::LogicalOrExpressionContext(SingleExpressionContext *ctx) { copyFrom(ctx); }

void TypeScriptParser::LogicalOrExpressionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TypeScriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterLogicalOrExpression(this);
}
void TypeScriptParser::LogicalOrExpressionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TypeScriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitLogicalOrExpression(this);
}

antlrcpp::Any TypeScriptParser::LogicalOrExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TypeScriptParserVisitor*>(visitor))
    return parserVisitor->visitLogicalOrExpression(this);
  else
    return visitor->visitChildren(this);
}
//----------------- NotExpressionContext ------------------------------------------------------------------

tree::TerminalNode* TypeScriptParser::NotExpressionContext::Not() {
  return getToken(TypeScriptParser::Not, 0);
}

TypeScriptParser::SingleExpressionContext* TypeScriptParser::NotExpressionContext::singleExpression() {
  return getRuleContext<TypeScriptParser::SingleExpressionContext>(0);
}

TypeScriptParser::NotExpressionContext::NotExpressionContext(SingleExpressionContext *ctx) { copyFrom(ctx); }

void TypeScriptParser::NotExpressionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TypeScriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterNotExpression(this);
}
void TypeScriptParser::NotExpressionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TypeScriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitNotExpression(this);
}

antlrcpp::Any TypeScriptParser::NotExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TypeScriptParserVisitor*>(visitor))
    return parserVisitor->visitNotExpression(this);
  else
    return visitor->visitChildren(this);
}
//----------------- PreDecreaseExpressionContext ------------------------------------------------------------------

tree::TerminalNode* TypeScriptParser::PreDecreaseExpressionContext::MinusMinus() {
  return getToken(TypeScriptParser::MinusMinus, 0);
}

TypeScriptParser::SingleExpressionContext* TypeScriptParser::PreDecreaseExpressionContext::singleExpression() {
  return getRuleContext<TypeScriptParser::SingleExpressionContext>(0);
}

TypeScriptParser::PreDecreaseExpressionContext::PreDecreaseExpressionContext(SingleExpressionContext *ctx) { copyFrom(ctx); }

void TypeScriptParser::PreDecreaseExpressionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TypeScriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterPreDecreaseExpression(this);
}
void TypeScriptParser::PreDecreaseExpressionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TypeScriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitPreDecreaseExpression(this);
}

antlrcpp::Any TypeScriptParser::PreDecreaseExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TypeScriptParserVisitor*>(visitor))
    return parserVisitor->visitPreDecreaseExpression(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ArgumentsExpressionContext ------------------------------------------------------------------

TypeScriptParser::SingleExpressionContext* TypeScriptParser::ArgumentsExpressionContext::singleExpression() {
  return getRuleContext<TypeScriptParser::SingleExpressionContext>(0);
}

TypeScriptParser::ArgumentsContext* TypeScriptParser::ArgumentsExpressionContext::arguments() {
  return getRuleContext<TypeScriptParser::ArgumentsContext>(0);
}

TypeScriptParser::ArgumentsExpressionContext::ArgumentsExpressionContext(SingleExpressionContext *ctx) { copyFrom(ctx); }

void TypeScriptParser::ArgumentsExpressionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TypeScriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterArgumentsExpression(this);
}
void TypeScriptParser::ArgumentsExpressionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TypeScriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitArgumentsExpression(this);
}

antlrcpp::Any TypeScriptParser::ArgumentsExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TypeScriptParserVisitor*>(visitor))
    return parserVisitor->visitArgumentsExpression(this);
  else
    return visitor->visitChildren(this);
}
//----------------- AwaitExpressionContext ------------------------------------------------------------------

tree::TerminalNode* TypeScriptParser::AwaitExpressionContext::Await() {
  return getToken(TypeScriptParser::Await, 0);
}

TypeScriptParser::SingleExpressionContext* TypeScriptParser::AwaitExpressionContext::singleExpression() {
  return getRuleContext<TypeScriptParser::SingleExpressionContext>(0);
}

TypeScriptParser::AwaitExpressionContext::AwaitExpressionContext(SingleExpressionContext *ctx) { copyFrom(ctx); }

void TypeScriptParser::AwaitExpressionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TypeScriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAwaitExpression(this);
}
void TypeScriptParser::AwaitExpressionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TypeScriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAwaitExpression(this);
}

antlrcpp::Any TypeScriptParser::AwaitExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TypeScriptParserVisitor*>(visitor))
    return parserVisitor->visitAwaitExpression(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ThisExpressionContext ------------------------------------------------------------------

tree::TerminalNode* TypeScriptParser::ThisExpressionContext::This() {
  return getToken(TypeScriptParser::This, 0);
}

TypeScriptParser::ThisExpressionContext::ThisExpressionContext(SingleExpressionContext *ctx) { copyFrom(ctx); }

void TypeScriptParser::ThisExpressionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TypeScriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterThisExpression(this);
}
void TypeScriptParser::ThisExpressionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TypeScriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitThisExpression(this);
}

antlrcpp::Any TypeScriptParser::ThisExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TypeScriptParserVisitor*>(visitor))
    return parserVisitor->visitThisExpression(this);
  else
    return visitor->visitChildren(this);
}
//----------------- FunctionExpressionContext ------------------------------------------------------------------

TypeScriptParser::AnoymousFunctionContext* TypeScriptParser::FunctionExpressionContext::anoymousFunction() {
  return getRuleContext<TypeScriptParser::AnoymousFunctionContext>(0);
}

TypeScriptParser::FunctionExpressionContext::FunctionExpressionContext(SingleExpressionContext *ctx) { copyFrom(ctx); }

void TypeScriptParser::FunctionExpressionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TypeScriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFunctionExpression(this);
}
void TypeScriptParser::FunctionExpressionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TypeScriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFunctionExpression(this);
}

antlrcpp::Any TypeScriptParser::FunctionExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TypeScriptParserVisitor*>(visitor))
    return parserVisitor->visitFunctionExpression(this);
  else
    return visitor->visitChildren(this);
}
//----------------- UnaryMinusExpressionContext ------------------------------------------------------------------

tree::TerminalNode* TypeScriptParser::UnaryMinusExpressionContext::Minus() {
  return getToken(TypeScriptParser::Minus, 0);
}

TypeScriptParser::SingleExpressionContext* TypeScriptParser::UnaryMinusExpressionContext::singleExpression() {
  return getRuleContext<TypeScriptParser::SingleExpressionContext>(0);
}

TypeScriptParser::UnaryMinusExpressionContext::UnaryMinusExpressionContext(SingleExpressionContext *ctx) { copyFrom(ctx); }

void TypeScriptParser::UnaryMinusExpressionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TypeScriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterUnaryMinusExpression(this);
}
void TypeScriptParser::UnaryMinusExpressionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TypeScriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitUnaryMinusExpression(this);
}

antlrcpp::Any TypeScriptParser::UnaryMinusExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TypeScriptParserVisitor*>(visitor))
    return parserVisitor->visitUnaryMinusExpression(this);
  else
    return visitor->visitChildren(this);
}
//----------------- AssignmentExpressionContext ------------------------------------------------------------------

std::vector<TypeScriptParser::SingleExpressionContext *> TypeScriptParser::AssignmentExpressionContext::singleExpression() {
  return getRuleContexts<TypeScriptParser::SingleExpressionContext>();
}

TypeScriptParser::SingleExpressionContext* TypeScriptParser::AssignmentExpressionContext::singleExpression(size_t i) {
  return getRuleContext<TypeScriptParser::SingleExpressionContext>(i);
}

tree::TerminalNode* TypeScriptParser::AssignmentExpressionContext::Assign() {
  return getToken(TypeScriptParser::Assign, 0);
}

TypeScriptParser::AssignmentExpressionContext::AssignmentExpressionContext(SingleExpressionContext *ctx) { copyFrom(ctx); }

void TypeScriptParser::AssignmentExpressionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TypeScriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAssignmentExpression(this);
}
void TypeScriptParser::AssignmentExpressionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TypeScriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAssignmentExpression(this);
}

antlrcpp::Any TypeScriptParser::AssignmentExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TypeScriptParserVisitor*>(visitor))
    return parserVisitor->visitAssignmentExpression(this);
  else
    return visitor->visitChildren(this);
}
//----------------- PostDecreaseExpressionContext ------------------------------------------------------------------

TypeScriptParser::SingleExpressionContext* TypeScriptParser::PostDecreaseExpressionContext::singleExpression() {
  return getRuleContext<TypeScriptParser::SingleExpressionContext>(0);
}

tree::TerminalNode* TypeScriptParser::PostDecreaseExpressionContext::MinusMinus() {
  return getToken(TypeScriptParser::MinusMinus, 0);
}

TypeScriptParser::PostDecreaseExpressionContext::PostDecreaseExpressionContext(SingleExpressionContext *ctx) { copyFrom(ctx); }

void TypeScriptParser::PostDecreaseExpressionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TypeScriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterPostDecreaseExpression(this);
}
void TypeScriptParser::PostDecreaseExpressionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TypeScriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitPostDecreaseExpression(this);
}

antlrcpp::Any TypeScriptParser::PostDecreaseExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TypeScriptParserVisitor*>(visitor))
    return parserVisitor->visitPostDecreaseExpression(this);
  else
    return visitor->visitChildren(this);
}
//----------------- TypeofExpressionContext ------------------------------------------------------------------

tree::TerminalNode* TypeScriptParser::TypeofExpressionContext::Typeof() {
  return getToken(TypeScriptParser::Typeof, 0);
}

TypeScriptParser::SingleExpressionContext* TypeScriptParser::TypeofExpressionContext::singleExpression() {
  return getRuleContext<TypeScriptParser::SingleExpressionContext>(0);
}

TypeScriptParser::TypeofExpressionContext::TypeofExpressionContext(SingleExpressionContext *ctx) { copyFrom(ctx); }

void TypeScriptParser::TypeofExpressionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TypeScriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterTypeofExpression(this);
}
void TypeScriptParser::TypeofExpressionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TypeScriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitTypeofExpression(this);
}

antlrcpp::Any TypeScriptParser::TypeofExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TypeScriptParserVisitor*>(visitor))
    return parserVisitor->visitTypeofExpression(this);
  else
    return visitor->visitChildren(this);
}
//----------------- InstanceofExpressionContext ------------------------------------------------------------------

std::vector<TypeScriptParser::SingleExpressionContext *> TypeScriptParser::InstanceofExpressionContext::singleExpression() {
  return getRuleContexts<TypeScriptParser::SingleExpressionContext>();
}

TypeScriptParser::SingleExpressionContext* TypeScriptParser::InstanceofExpressionContext::singleExpression(size_t i) {
  return getRuleContext<TypeScriptParser::SingleExpressionContext>(i);
}

tree::TerminalNode* TypeScriptParser::InstanceofExpressionContext::Instanceof() {
  return getToken(TypeScriptParser::Instanceof, 0);
}

TypeScriptParser::InstanceofExpressionContext::InstanceofExpressionContext(SingleExpressionContext *ctx) { copyFrom(ctx); }

void TypeScriptParser::InstanceofExpressionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TypeScriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterInstanceofExpression(this);
}
void TypeScriptParser::InstanceofExpressionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TypeScriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitInstanceofExpression(this);
}

antlrcpp::Any TypeScriptParser::InstanceofExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TypeScriptParserVisitor*>(visitor))
    return parserVisitor->visitInstanceofExpression(this);
  else
    return visitor->visitChildren(this);
}
//----------------- UnaryPlusExpressionContext ------------------------------------------------------------------

tree::TerminalNode* TypeScriptParser::UnaryPlusExpressionContext::Plus() {
  return getToken(TypeScriptParser::Plus, 0);
}

TypeScriptParser::SingleExpressionContext* TypeScriptParser::UnaryPlusExpressionContext::singleExpression() {
  return getRuleContext<TypeScriptParser::SingleExpressionContext>(0);
}

TypeScriptParser::UnaryPlusExpressionContext::UnaryPlusExpressionContext(SingleExpressionContext *ctx) { copyFrom(ctx); }

void TypeScriptParser::UnaryPlusExpressionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TypeScriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterUnaryPlusExpression(this);
}
void TypeScriptParser::UnaryPlusExpressionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TypeScriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitUnaryPlusExpression(this);
}

antlrcpp::Any TypeScriptParser::UnaryPlusExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TypeScriptParserVisitor*>(visitor))
    return parserVisitor->visitUnaryPlusExpression(this);
  else
    return visitor->visitChildren(this);
}
//----------------- DeleteExpressionContext ------------------------------------------------------------------

tree::TerminalNode* TypeScriptParser::DeleteExpressionContext::Delete() {
  return getToken(TypeScriptParser::Delete, 0);
}

TypeScriptParser::SingleExpressionContext* TypeScriptParser::DeleteExpressionContext::singleExpression() {
  return getRuleContext<TypeScriptParser::SingleExpressionContext>(0);
}

TypeScriptParser::DeleteExpressionContext::DeleteExpressionContext(SingleExpressionContext *ctx) { copyFrom(ctx); }

void TypeScriptParser::DeleteExpressionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TypeScriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterDeleteExpression(this);
}
void TypeScriptParser::DeleteExpressionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TypeScriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitDeleteExpression(this);
}

antlrcpp::Any TypeScriptParser::DeleteExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TypeScriptParserVisitor*>(visitor))
    return parserVisitor->visitDeleteExpression(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ImportExpressionContext ------------------------------------------------------------------

tree::TerminalNode* TypeScriptParser::ImportExpressionContext::Import() {
  return getToken(TypeScriptParser::Import, 0);
}

tree::TerminalNode* TypeScriptParser::ImportExpressionContext::OpenParen() {
  return getToken(TypeScriptParser::OpenParen, 0);
}

TypeScriptParser::SingleExpressionContext* TypeScriptParser::ImportExpressionContext::singleExpression() {
  return getRuleContext<TypeScriptParser::SingleExpressionContext>(0);
}

tree::TerminalNode* TypeScriptParser::ImportExpressionContext::CloseParen() {
  return getToken(TypeScriptParser::CloseParen, 0);
}

TypeScriptParser::ImportExpressionContext::ImportExpressionContext(SingleExpressionContext *ctx) { copyFrom(ctx); }

void TypeScriptParser::ImportExpressionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TypeScriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterImportExpression(this);
}
void TypeScriptParser::ImportExpressionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TypeScriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitImportExpression(this);
}

antlrcpp::Any TypeScriptParser::ImportExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TypeScriptParserVisitor*>(visitor))
    return parserVisitor->visitImportExpression(this);
  else
    return visitor->visitChildren(this);
}
//----------------- EqualityExpressionContext ------------------------------------------------------------------

std::vector<TypeScriptParser::SingleExpressionContext *> TypeScriptParser::EqualityExpressionContext::singleExpression() {
  return getRuleContexts<TypeScriptParser::SingleExpressionContext>();
}

TypeScriptParser::SingleExpressionContext* TypeScriptParser::EqualityExpressionContext::singleExpression(size_t i) {
  return getRuleContext<TypeScriptParser::SingleExpressionContext>(i);
}

tree::TerminalNode* TypeScriptParser::EqualityExpressionContext::Equals_() {
  return getToken(TypeScriptParser::Equals_, 0);
}

tree::TerminalNode* TypeScriptParser::EqualityExpressionContext::NotEquals() {
  return getToken(TypeScriptParser::NotEquals, 0);
}

tree::TerminalNode* TypeScriptParser::EqualityExpressionContext::IdentityEquals() {
  return getToken(TypeScriptParser::IdentityEquals, 0);
}

tree::TerminalNode* TypeScriptParser::EqualityExpressionContext::IdentityNotEquals() {
  return getToken(TypeScriptParser::IdentityNotEquals, 0);
}

TypeScriptParser::EqualityExpressionContext::EqualityExpressionContext(SingleExpressionContext *ctx) { copyFrom(ctx); }

void TypeScriptParser::EqualityExpressionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TypeScriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterEqualityExpression(this);
}
void TypeScriptParser::EqualityExpressionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TypeScriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitEqualityExpression(this);
}

antlrcpp::Any TypeScriptParser::EqualityExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TypeScriptParserVisitor*>(visitor))
    return parserVisitor->visitEqualityExpression(this);
  else
    return visitor->visitChildren(this);
}
//----------------- BitXOrExpressionContext ------------------------------------------------------------------

std::vector<TypeScriptParser::SingleExpressionContext *> TypeScriptParser::BitXOrExpressionContext::singleExpression() {
  return getRuleContexts<TypeScriptParser::SingleExpressionContext>();
}

TypeScriptParser::SingleExpressionContext* TypeScriptParser::BitXOrExpressionContext::singleExpression(size_t i) {
  return getRuleContext<TypeScriptParser::SingleExpressionContext>(i);
}

tree::TerminalNode* TypeScriptParser::BitXOrExpressionContext::BitXOr() {
  return getToken(TypeScriptParser::BitXOr, 0);
}

TypeScriptParser::BitXOrExpressionContext::BitXOrExpressionContext(SingleExpressionContext *ctx) { copyFrom(ctx); }

void TypeScriptParser::BitXOrExpressionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TypeScriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterBitXOrExpression(this);
}
void TypeScriptParser::BitXOrExpressionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TypeScriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitBitXOrExpression(this);
}

antlrcpp::Any TypeScriptParser::BitXOrExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TypeScriptParserVisitor*>(visitor))
    return parserVisitor->visitBitXOrExpression(this);
  else
    return visitor->visitChildren(this);
}
//----------------- SuperExpressionContext ------------------------------------------------------------------

tree::TerminalNode* TypeScriptParser::SuperExpressionContext::Super() {
  return getToken(TypeScriptParser::Super, 0);
}

TypeScriptParser::SuperExpressionContext::SuperExpressionContext(SingleExpressionContext *ctx) { copyFrom(ctx); }

void TypeScriptParser::SuperExpressionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TypeScriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSuperExpression(this);
}
void TypeScriptParser::SuperExpressionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TypeScriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSuperExpression(this);
}

antlrcpp::Any TypeScriptParser::SuperExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TypeScriptParserVisitor*>(visitor))
    return parserVisitor->visitSuperExpression(this);
  else
    return visitor->visitChildren(this);
}
//----------------- MultiplicativeExpressionContext ------------------------------------------------------------------

std::vector<TypeScriptParser::SingleExpressionContext *> TypeScriptParser::MultiplicativeExpressionContext::singleExpression() {
  return getRuleContexts<TypeScriptParser::SingleExpressionContext>();
}

TypeScriptParser::SingleExpressionContext* TypeScriptParser::MultiplicativeExpressionContext::singleExpression(size_t i) {
  return getRuleContext<TypeScriptParser::SingleExpressionContext>(i);
}

tree::TerminalNode* TypeScriptParser::MultiplicativeExpressionContext::Multiply() {
  return getToken(TypeScriptParser::Multiply, 0);
}

tree::TerminalNode* TypeScriptParser::MultiplicativeExpressionContext::Divide() {
  return getToken(TypeScriptParser::Divide, 0);
}

tree::TerminalNode* TypeScriptParser::MultiplicativeExpressionContext::Modulus() {
  return getToken(TypeScriptParser::Modulus, 0);
}

TypeScriptParser::MultiplicativeExpressionContext::MultiplicativeExpressionContext(SingleExpressionContext *ctx) { copyFrom(ctx); }

void TypeScriptParser::MultiplicativeExpressionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TypeScriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterMultiplicativeExpression(this);
}
void TypeScriptParser::MultiplicativeExpressionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TypeScriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitMultiplicativeExpression(this);
}

antlrcpp::Any TypeScriptParser::MultiplicativeExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TypeScriptParserVisitor*>(visitor))
    return parserVisitor->visitMultiplicativeExpression(this);
  else
    return visitor->visitChildren(this);
}
//----------------- BitShiftExpressionContext ------------------------------------------------------------------

std::vector<TypeScriptParser::SingleExpressionContext *> TypeScriptParser::BitShiftExpressionContext::singleExpression() {
  return getRuleContexts<TypeScriptParser::SingleExpressionContext>();
}

TypeScriptParser::SingleExpressionContext* TypeScriptParser::BitShiftExpressionContext::singleExpression(size_t i) {
  return getRuleContext<TypeScriptParser::SingleExpressionContext>(i);
}

tree::TerminalNode* TypeScriptParser::BitShiftExpressionContext::LeftShiftArithmetic() {
  return getToken(TypeScriptParser::LeftShiftArithmetic, 0);
}

tree::TerminalNode* TypeScriptParser::BitShiftExpressionContext::RightShiftArithmetic() {
  return getToken(TypeScriptParser::RightShiftArithmetic, 0);
}

tree::TerminalNode* TypeScriptParser::BitShiftExpressionContext::RightShiftLogical() {
  return getToken(TypeScriptParser::RightShiftLogical, 0);
}

TypeScriptParser::BitShiftExpressionContext::BitShiftExpressionContext(SingleExpressionContext *ctx) { copyFrom(ctx); }

void TypeScriptParser::BitShiftExpressionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TypeScriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterBitShiftExpression(this);
}
void TypeScriptParser::BitShiftExpressionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TypeScriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitBitShiftExpression(this);
}

antlrcpp::Any TypeScriptParser::BitShiftExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TypeScriptParserVisitor*>(visitor))
    return parserVisitor->visitBitShiftExpression(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ParenthesizedExpressionContext ------------------------------------------------------------------

tree::TerminalNode* TypeScriptParser::ParenthesizedExpressionContext::OpenParen() {
  return getToken(TypeScriptParser::OpenParen, 0);
}

TypeScriptParser::ExpressionSequenceContext* TypeScriptParser::ParenthesizedExpressionContext::expressionSequence() {
  return getRuleContext<TypeScriptParser::ExpressionSequenceContext>(0);
}

tree::TerminalNode* TypeScriptParser::ParenthesizedExpressionContext::CloseParen() {
  return getToken(TypeScriptParser::CloseParen, 0);
}

TypeScriptParser::ParenthesizedExpressionContext::ParenthesizedExpressionContext(SingleExpressionContext *ctx) { copyFrom(ctx); }

void TypeScriptParser::ParenthesizedExpressionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TypeScriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterParenthesizedExpression(this);
}
void TypeScriptParser::ParenthesizedExpressionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TypeScriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitParenthesizedExpression(this);
}

antlrcpp::Any TypeScriptParser::ParenthesizedExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TypeScriptParserVisitor*>(visitor))
    return parserVisitor->visitParenthesizedExpression(this);
  else
    return visitor->visitChildren(this);
}
//----------------- AdditiveExpressionContext ------------------------------------------------------------------

std::vector<TypeScriptParser::SingleExpressionContext *> TypeScriptParser::AdditiveExpressionContext::singleExpression() {
  return getRuleContexts<TypeScriptParser::SingleExpressionContext>();
}

TypeScriptParser::SingleExpressionContext* TypeScriptParser::AdditiveExpressionContext::singleExpression(size_t i) {
  return getRuleContext<TypeScriptParser::SingleExpressionContext>(i);
}

tree::TerminalNode* TypeScriptParser::AdditiveExpressionContext::Plus() {
  return getToken(TypeScriptParser::Plus, 0);
}

tree::TerminalNode* TypeScriptParser::AdditiveExpressionContext::Minus() {
  return getToken(TypeScriptParser::Minus, 0);
}

TypeScriptParser::AdditiveExpressionContext::AdditiveExpressionContext(SingleExpressionContext *ctx) { copyFrom(ctx); }

void TypeScriptParser::AdditiveExpressionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TypeScriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAdditiveExpression(this);
}
void TypeScriptParser::AdditiveExpressionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TypeScriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAdditiveExpression(this);
}

antlrcpp::Any TypeScriptParser::AdditiveExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TypeScriptParserVisitor*>(visitor))
    return parserVisitor->visitAdditiveExpression(this);
  else
    return visitor->visitChildren(this);
}
//----------------- RelationalExpressionContext ------------------------------------------------------------------

std::vector<TypeScriptParser::SingleExpressionContext *> TypeScriptParser::RelationalExpressionContext::singleExpression() {
  return getRuleContexts<TypeScriptParser::SingleExpressionContext>();
}

TypeScriptParser::SingleExpressionContext* TypeScriptParser::RelationalExpressionContext::singleExpression(size_t i) {
  return getRuleContext<TypeScriptParser::SingleExpressionContext>(i);
}

tree::TerminalNode* TypeScriptParser::RelationalExpressionContext::LessThan() {
  return getToken(TypeScriptParser::LessThan, 0);
}

tree::TerminalNode* TypeScriptParser::RelationalExpressionContext::MoreThan() {
  return getToken(TypeScriptParser::MoreThan, 0);
}

tree::TerminalNode* TypeScriptParser::RelationalExpressionContext::LessThanEquals() {
  return getToken(TypeScriptParser::LessThanEquals, 0);
}

tree::TerminalNode* TypeScriptParser::RelationalExpressionContext::GreaterThanEquals() {
  return getToken(TypeScriptParser::GreaterThanEquals, 0);
}

TypeScriptParser::RelationalExpressionContext::RelationalExpressionContext(SingleExpressionContext *ctx) { copyFrom(ctx); }

void TypeScriptParser::RelationalExpressionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TypeScriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterRelationalExpression(this);
}
void TypeScriptParser::RelationalExpressionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TypeScriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitRelationalExpression(this);
}

antlrcpp::Any TypeScriptParser::RelationalExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TypeScriptParserVisitor*>(visitor))
    return parserVisitor->visitRelationalExpression(this);
  else
    return visitor->visitChildren(this);
}
//----------------- PostIncrementExpressionContext ------------------------------------------------------------------

TypeScriptParser::SingleExpressionContext* TypeScriptParser::PostIncrementExpressionContext::singleExpression() {
  return getRuleContext<TypeScriptParser::SingleExpressionContext>(0);
}

tree::TerminalNode* TypeScriptParser::PostIncrementExpressionContext::PlusPlus() {
  return getToken(TypeScriptParser::PlusPlus, 0);
}

TypeScriptParser::PostIncrementExpressionContext::PostIncrementExpressionContext(SingleExpressionContext *ctx) { copyFrom(ctx); }

void TypeScriptParser::PostIncrementExpressionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TypeScriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterPostIncrementExpression(this);
}
void TypeScriptParser::PostIncrementExpressionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TypeScriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitPostIncrementExpression(this);
}

antlrcpp::Any TypeScriptParser::PostIncrementExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TypeScriptParserVisitor*>(visitor))
    return parserVisitor->visitPostIncrementExpression(this);
  else
    return visitor->visitChildren(this);
}
//----------------- YieldExpressionContext ------------------------------------------------------------------

TypeScriptParser::YieldStatementContext* TypeScriptParser::YieldExpressionContext::yieldStatement() {
  return getRuleContext<TypeScriptParser::YieldStatementContext>(0);
}

TypeScriptParser::YieldExpressionContext::YieldExpressionContext(SingleExpressionContext *ctx) { copyFrom(ctx); }

void TypeScriptParser::YieldExpressionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TypeScriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterYieldExpression(this);
}
void TypeScriptParser::YieldExpressionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TypeScriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitYieldExpression(this);
}

antlrcpp::Any TypeScriptParser::YieldExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TypeScriptParserVisitor*>(visitor))
    return parserVisitor->visitYieldExpression(this);
  else
    return visitor->visitChildren(this);
}
//----------------- BitNotExpressionContext ------------------------------------------------------------------

tree::TerminalNode* TypeScriptParser::BitNotExpressionContext::BitNot() {
  return getToken(TypeScriptParser::BitNot, 0);
}

TypeScriptParser::SingleExpressionContext* TypeScriptParser::BitNotExpressionContext::singleExpression() {
  return getRuleContext<TypeScriptParser::SingleExpressionContext>(0);
}

TypeScriptParser::BitNotExpressionContext::BitNotExpressionContext(SingleExpressionContext *ctx) { copyFrom(ctx); }

void TypeScriptParser::BitNotExpressionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TypeScriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterBitNotExpression(this);
}
void TypeScriptParser::BitNotExpressionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TypeScriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitBitNotExpression(this);
}

antlrcpp::Any TypeScriptParser::BitNotExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TypeScriptParserVisitor*>(visitor))
    return parserVisitor->visitBitNotExpression(this);
  else
    return visitor->visitChildren(this);
}
//----------------- NewExpressionContext ------------------------------------------------------------------

tree::TerminalNode* TypeScriptParser::NewExpressionContext::New() {
  return getToken(TypeScriptParser::New, 0);
}

TypeScriptParser::SingleExpressionContext* TypeScriptParser::NewExpressionContext::singleExpression() {
  return getRuleContext<TypeScriptParser::SingleExpressionContext>(0);
}

TypeScriptParser::ArgumentsContext* TypeScriptParser::NewExpressionContext::arguments() {
  return getRuleContext<TypeScriptParser::ArgumentsContext>(0);
}

TypeScriptParser::NewExpressionContext::NewExpressionContext(SingleExpressionContext *ctx) { copyFrom(ctx); }

void TypeScriptParser::NewExpressionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TypeScriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterNewExpression(this);
}
void TypeScriptParser::NewExpressionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TypeScriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitNewExpression(this);
}

antlrcpp::Any TypeScriptParser::NewExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TypeScriptParserVisitor*>(visitor))
    return parserVisitor->visitNewExpression(this);
  else
    return visitor->visitChildren(this);
}
//----------------- LiteralExpressionContext ------------------------------------------------------------------

TypeScriptParser::LiteralContext* TypeScriptParser::LiteralExpressionContext::literal() {
  return getRuleContext<TypeScriptParser::LiteralContext>(0);
}

TypeScriptParser::LiteralExpressionContext::LiteralExpressionContext(SingleExpressionContext *ctx) { copyFrom(ctx); }

void TypeScriptParser::LiteralExpressionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TypeScriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterLiteralExpression(this);
}
void TypeScriptParser::LiteralExpressionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TypeScriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitLiteralExpression(this);
}

antlrcpp::Any TypeScriptParser::LiteralExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TypeScriptParserVisitor*>(visitor))
    return parserVisitor->visitLiteralExpression(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ArrayLiteralExpressionContext ------------------------------------------------------------------

TypeScriptParser::ArrayLiteralContext* TypeScriptParser::ArrayLiteralExpressionContext::arrayLiteral() {
  return getRuleContext<TypeScriptParser::ArrayLiteralContext>(0);
}

TypeScriptParser::ArrayLiteralExpressionContext::ArrayLiteralExpressionContext(SingleExpressionContext *ctx) { copyFrom(ctx); }

void TypeScriptParser::ArrayLiteralExpressionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TypeScriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterArrayLiteralExpression(this);
}
void TypeScriptParser::ArrayLiteralExpressionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TypeScriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitArrayLiteralExpression(this);
}

antlrcpp::Any TypeScriptParser::ArrayLiteralExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TypeScriptParserVisitor*>(visitor))
    return parserVisitor->visitArrayLiteralExpression(this);
  else
    return visitor->visitChildren(this);
}
//----------------- MemberDotExpressionContext ------------------------------------------------------------------

TypeScriptParser::SingleExpressionContext* TypeScriptParser::MemberDotExpressionContext::singleExpression() {
  return getRuleContext<TypeScriptParser::SingleExpressionContext>(0);
}

tree::TerminalNode* TypeScriptParser::MemberDotExpressionContext::Dot() {
  return getToken(TypeScriptParser::Dot, 0);
}

TypeScriptParser::IdentifierNameContext* TypeScriptParser::MemberDotExpressionContext::identifierName() {
  return getRuleContext<TypeScriptParser::IdentifierNameContext>(0);
}

tree::TerminalNode* TypeScriptParser::MemberDotExpressionContext::QuestionMark() {
  return getToken(TypeScriptParser::QuestionMark, 0);
}

tree::TerminalNode* TypeScriptParser::MemberDotExpressionContext::Hashtag() {
  return getToken(TypeScriptParser::Hashtag, 0);
}

TypeScriptParser::MemberDotExpressionContext::MemberDotExpressionContext(SingleExpressionContext *ctx) { copyFrom(ctx); }

void TypeScriptParser::MemberDotExpressionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TypeScriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterMemberDotExpression(this);
}
void TypeScriptParser::MemberDotExpressionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TypeScriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitMemberDotExpression(this);
}

antlrcpp::Any TypeScriptParser::MemberDotExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TypeScriptParserVisitor*>(visitor))
    return parserVisitor->visitMemberDotExpression(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ClassExpressionContext ------------------------------------------------------------------

tree::TerminalNode* TypeScriptParser::ClassExpressionContext::Class() {
  return getToken(TypeScriptParser::Class, 0);
}

TypeScriptParser::ClassTailContext* TypeScriptParser::ClassExpressionContext::classTail() {
  return getRuleContext<TypeScriptParser::ClassTailContext>(0);
}

tree::TerminalNode* TypeScriptParser::ClassExpressionContext::Identifier() {
  return getToken(TypeScriptParser::Identifier, 0);
}

TypeScriptParser::ClassExpressionContext::ClassExpressionContext(SingleExpressionContext *ctx) { copyFrom(ctx); }

void TypeScriptParser::ClassExpressionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TypeScriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterClassExpression(this);
}
void TypeScriptParser::ClassExpressionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TypeScriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitClassExpression(this);
}

antlrcpp::Any TypeScriptParser::ClassExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TypeScriptParserVisitor*>(visitor))
    return parserVisitor->visitClassExpression(this);
  else
    return visitor->visitChildren(this);
}
//----------------- MemberIndexExpressionContext ------------------------------------------------------------------

TypeScriptParser::SingleExpressionContext* TypeScriptParser::MemberIndexExpressionContext::singleExpression() {
  return getRuleContext<TypeScriptParser::SingleExpressionContext>(0);
}

tree::TerminalNode* TypeScriptParser::MemberIndexExpressionContext::OpenBracket() {
  return getToken(TypeScriptParser::OpenBracket, 0);
}

TypeScriptParser::ExpressionSequenceContext* TypeScriptParser::MemberIndexExpressionContext::expressionSequence() {
  return getRuleContext<TypeScriptParser::ExpressionSequenceContext>(0);
}

tree::TerminalNode* TypeScriptParser::MemberIndexExpressionContext::CloseBracket() {
  return getToken(TypeScriptParser::CloseBracket, 0);
}

TypeScriptParser::MemberIndexExpressionContext::MemberIndexExpressionContext(SingleExpressionContext *ctx) { copyFrom(ctx); }

void TypeScriptParser::MemberIndexExpressionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TypeScriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterMemberIndexExpression(this);
}
void TypeScriptParser::MemberIndexExpressionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TypeScriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitMemberIndexExpression(this);
}

antlrcpp::Any TypeScriptParser::MemberIndexExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TypeScriptParserVisitor*>(visitor))
    return parserVisitor->visitMemberIndexExpression(this);
  else
    return visitor->visitChildren(this);
}
//----------------- IdentifierExpressionContext ------------------------------------------------------------------

tree::TerminalNode* TypeScriptParser::IdentifierExpressionContext::Identifier() {
  return getToken(TypeScriptParser::Identifier, 0);
}

TypeScriptParser::IdentifierExpressionContext::IdentifierExpressionContext(SingleExpressionContext *ctx) { copyFrom(ctx); }

void TypeScriptParser::IdentifierExpressionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TypeScriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterIdentifierExpression(this);
}
void TypeScriptParser::IdentifierExpressionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TypeScriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitIdentifierExpression(this);
}

antlrcpp::Any TypeScriptParser::IdentifierExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TypeScriptParserVisitor*>(visitor))
    return parserVisitor->visitIdentifierExpression(this);
  else
    return visitor->visitChildren(this);
}
//----------------- BitAndExpressionContext ------------------------------------------------------------------

std::vector<TypeScriptParser::SingleExpressionContext *> TypeScriptParser::BitAndExpressionContext::singleExpression() {
  return getRuleContexts<TypeScriptParser::SingleExpressionContext>();
}

TypeScriptParser::SingleExpressionContext* TypeScriptParser::BitAndExpressionContext::singleExpression(size_t i) {
  return getRuleContext<TypeScriptParser::SingleExpressionContext>(i);
}

tree::TerminalNode* TypeScriptParser::BitAndExpressionContext::BitAnd() {
  return getToken(TypeScriptParser::BitAnd, 0);
}

TypeScriptParser::BitAndExpressionContext::BitAndExpressionContext(SingleExpressionContext *ctx) { copyFrom(ctx); }

void TypeScriptParser::BitAndExpressionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TypeScriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterBitAndExpression(this);
}
void TypeScriptParser::BitAndExpressionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TypeScriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitBitAndExpression(this);
}

antlrcpp::Any TypeScriptParser::BitAndExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TypeScriptParserVisitor*>(visitor))
    return parserVisitor->visitBitAndExpression(this);
  else
    return visitor->visitChildren(this);
}
//----------------- BitOrExpressionContext ------------------------------------------------------------------

std::vector<TypeScriptParser::SingleExpressionContext *> TypeScriptParser::BitOrExpressionContext::singleExpression() {
  return getRuleContexts<TypeScriptParser::SingleExpressionContext>();
}

TypeScriptParser::SingleExpressionContext* TypeScriptParser::BitOrExpressionContext::singleExpression(size_t i) {
  return getRuleContext<TypeScriptParser::SingleExpressionContext>(i);
}

tree::TerminalNode* TypeScriptParser::BitOrExpressionContext::BitOr() {
  return getToken(TypeScriptParser::BitOr, 0);
}

TypeScriptParser::BitOrExpressionContext::BitOrExpressionContext(SingleExpressionContext *ctx) { copyFrom(ctx); }

void TypeScriptParser::BitOrExpressionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TypeScriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterBitOrExpression(this);
}
void TypeScriptParser::BitOrExpressionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TypeScriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitBitOrExpression(this);
}

antlrcpp::Any TypeScriptParser::BitOrExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TypeScriptParserVisitor*>(visitor))
    return parserVisitor->visitBitOrExpression(this);
  else
    return visitor->visitChildren(this);
}
//----------------- AssignmentOperatorExpressionContext ------------------------------------------------------------------

std::vector<TypeScriptParser::SingleExpressionContext *> TypeScriptParser::AssignmentOperatorExpressionContext::singleExpression() {
  return getRuleContexts<TypeScriptParser::SingleExpressionContext>();
}

TypeScriptParser::SingleExpressionContext* TypeScriptParser::AssignmentOperatorExpressionContext::singleExpression(size_t i) {
  return getRuleContext<TypeScriptParser::SingleExpressionContext>(i);
}

TypeScriptParser::AssignmentOperatorContext* TypeScriptParser::AssignmentOperatorExpressionContext::assignmentOperator() {
  return getRuleContext<TypeScriptParser::AssignmentOperatorContext>(0);
}

TypeScriptParser::AssignmentOperatorExpressionContext::AssignmentOperatorExpressionContext(SingleExpressionContext *ctx) { copyFrom(ctx); }

void TypeScriptParser::AssignmentOperatorExpressionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TypeScriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAssignmentOperatorExpression(this);
}
void TypeScriptParser::AssignmentOperatorExpressionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TypeScriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAssignmentOperatorExpression(this);
}

antlrcpp::Any TypeScriptParser::AssignmentOperatorExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TypeScriptParserVisitor*>(visitor))
    return parserVisitor->visitAssignmentOperatorExpression(this);
  else
    return visitor->visitChildren(this);
}
//----------------- VoidExpressionContext ------------------------------------------------------------------

tree::TerminalNode* TypeScriptParser::VoidExpressionContext::Void() {
  return getToken(TypeScriptParser::Void, 0);
}

TypeScriptParser::SingleExpressionContext* TypeScriptParser::VoidExpressionContext::singleExpression() {
  return getRuleContext<TypeScriptParser::SingleExpressionContext>(0);
}

TypeScriptParser::VoidExpressionContext::VoidExpressionContext(SingleExpressionContext *ctx) { copyFrom(ctx); }

void TypeScriptParser::VoidExpressionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TypeScriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterVoidExpression(this);
}
void TypeScriptParser::VoidExpressionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TypeScriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitVoidExpression(this);
}

antlrcpp::Any TypeScriptParser::VoidExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TypeScriptParserVisitor*>(visitor))
    return parserVisitor->visitVoidExpression(this);
  else
    return visitor->visitChildren(this);
}
//----------------- CoalesceExpressionContext ------------------------------------------------------------------

std::vector<TypeScriptParser::SingleExpressionContext *> TypeScriptParser::CoalesceExpressionContext::singleExpression() {
  return getRuleContexts<TypeScriptParser::SingleExpressionContext>();
}

TypeScriptParser::SingleExpressionContext* TypeScriptParser::CoalesceExpressionContext::singleExpression(size_t i) {
  return getRuleContext<TypeScriptParser::SingleExpressionContext>(i);
}

tree::TerminalNode* TypeScriptParser::CoalesceExpressionContext::NullCoalesce() {
  return getToken(TypeScriptParser::NullCoalesce, 0);
}

TypeScriptParser::CoalesceExpressionContext::CoalesceExpressionContext(SingleExpressionContext *ctx) { copyFrom(ctx); }

void TypeScriptParser::CoalesceExpressionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TypeScriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterCoalesceExpression(this);
}
void TypeScriptParser::CoalesceExpressionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TypeScriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitCoalesceExpression(this);
}

antlrcpp::Any TypeScriptParser::CoalesceExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TypeScriptParserVisitor*>(visitor))
    return parserVisitor->visitCoalesceExpression(this);
  else
    return visitor->visitChildren(this);
}

TypeScriptParser::SingleExpressionContext* TypeScriptParser::singleExpression() {
   return singleExpression(0);
}

TypeScriptParser::SingleExpressionContext* TypeScriptParser::singleExpression(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  TypeScriptParser::SingleExpressionContext *_localctx = _tracker.createInstance<SingleExpressionContext>(_ctx, parentState);
  TypeScriptParser::SingleExpressionContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 126;
  enterRecursionRule(_localctx, 126, TypeScriptParser::RuleSingleExpression, precedence);

    size_t _la = 0;

  auto onExit = finally([=] {
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(853);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 99, _ctx)) {
    case 1: {
      _localctx = _tracker.createInstance<FunctionExpressionContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;

      setState(804);
      anoymousFunction();
      break;
    }

    case 2: {
      _localctx = _tracker.createInstance<ClassExpressionContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(805);
      match(TypeScriptParser::Class);
      setState(807);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == TypeScriptParser::Identifier) {
        setState(806);
        match(TypeScriptParser::Identifier);
      }
      setState(809);
      classTail();
      break;
    }

    case 3: {
      _localctx = _tracker.createInstance<NewExpressionContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(810);
      match(TypeScriptParser::New);
      setState(811);
      singleExpression(0);
      setState(812);
      arguments();
      break;
    }

    case 4: {
      _localctx = _tracker.createInstance<MetaExpressionContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(814);
      match(TypeScriptParser::New);
      setState(815);
      match(TypeScriptParser::Dot);
      setState(816);
      match(TypeScriptParser::Identifier);
      break;
    }

    case 5: {
      _localctx = _tracker.createInstance<DeleteExpressionContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(817);
      match(TypeScriptParser::Delete);
      setState(818);
      singleExpression(37);
      break;
    }

    case 6: {
      _localctx = _tracker.createInstance<VoidExpressionContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(819);
      match(TypeScriptParser::Void);
      setState(820);
      singleExpression(36);
      break;
    }

    case 7: {
      _localctx = _tracker.createInstance<TypeofExpressionContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(821);
      match(TypeScriptParser::Typeof);
      setState(822);
      singleExpression(35);
      break;
    }

    case 8: {
      _localctx = _tracker.createInstance<PreIncrementExpressionContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(823);
      match(TypeScriptParser::PlusPlus);
      setState(824);
      singleExpression(34);
      break;
    }

    case 9: {
      _localctx = _tracker.createInstance<PreDecreaseExpressionContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(825);
      match(TypeScriptParser::MinusMinus);
      setState(826);
      singleExpression(33);
      break;
    }

    case 10: {
      _localctx = _tracker.createInstance<UnaryPlusExpressionContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(827);
      match(TypeScriptParser::Plus);
      setState(828);
      singleExpression(32);
      break;
    }

    case 11: {
      _localctx = _tracker.createInstance<UnaryMinusExpressionContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(829);
      match(TypeScriptParser::Minus);
      setState(830);
      singleExpression(31);
      break;
    }

    case 12: {
      _localctx = _tracker.createInstance<BitNotExpressionContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(831);
      match(TypeScriptParser::BitNot);
      setState(832);
      singleExpression(30);
      break;
    }

    case 13: {
      _localctx = _tracker.createInstance<NotExpressionContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(833);
      match(TypeScriptParser::Not);
      setState(834);
      singleExpression(29);
      break;
    }

    case 14: {
      _localctx = _tracker.createInstance<AwaitExpressionContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(835);
      match(TypeScriptParser::Await);
      setState(836);
      singleExpression(28);
      break;
    }

    case 15: {
      _localctx = _tracker.createInstance<ImportExpressionContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(837);
      match(TypeScriptParser::Import);
      setState(838);
      match(TypeScriptParser::OpenParen);
      setState(839);
      singleExpression(0);
      setState(840);
      match(TypeScriptParser::CloseParen);
      break;
    }

    case 16: {
      _localctx = _tracker.createInstance<YieldExpressionContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(842);
      yieldStatement();
      break;
    }

    case 17: {
      _localctx = _tracker.createInstance<ThisExpressionContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(843);
      match(TypeScriptParser::This);
      break;
    }

    case 18: {
      _localctx = _tracker.createInstance<IdentifierExpressionContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(844);
      match(TypeScriptParser::Identifier);
      break;
    }

    case 19: {
      _localctx = _tracker.createInstance<SuperExpressionContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(845);
      match(TypeScriptParser::Super);
      break;
    }

    case 20: {
      _localctx = _tracker.createInstance<LiteralExpressionContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(846);
      literal();
      break;
    }

    case 21: {
      _localctx = _tracker.createInstance<ArrayLiteralExpressionContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(847);
      arrayLiteral();
      break;
    }

    case 22: {
      _localctx = _tracker.createInstance<ObjectLiteralExpressionContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(848);
      objectLiteral();
      break;
    }

    case 23: {
      _localctx = _tracker.createInstance<ParenthesizedExpressionContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(849);
      match(TypeScriptParser::OpenParen);
      setState(850);
      expressionSequence();
      setState(851);
      match(TypeScriptParser::CloseParen);
      break;
    }

    }
    _ctx->stop = _input->LT(-1);
    setState(934);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 103, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(932);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 102, _ctx)) {
        case 1: {
          auto newContext = _tracker.createInstance<PowerExpressionContext>(_tracker.createInstance<SingleExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleSingleExpression);
          setState(855);

          if (!(precpred(_ctx, 27))) throw FailedPredicateException(this, "precpred(_ctx, 27)");
          setState(856);
          match(TypeScriptParser::Power);
          setState(857);
          singleExpression(27);
          break;
        }

        case 2: {
          auto newContext = _tracker.createInstance<MultiplicativeExpressionContext>(_tracker.createInstance<SingleExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleSingleExpression);
          setState(858);

          if (!(precpred(_ctx, 26))) throw FailedPredicateException(this, "precpred(_ctx, 26)");
          setState(859);
          _la = _input->LA(1);
          if (!((((_la & ~ 0x3fULL) == 0) &&
            ((1ULL << _la) & ((1ULL << TypeScriptParser::Multiply)
            | (1ULL << TypeScriptParser::Divide)
            | (1ULL << TypeScriptParser::Modulus))) != 0))) {
          _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(860);
          singleExpression(27);
          break;
        }

        case 3: {
          auto newContext = _tracker.createInstance<AdditiveExpressionContext>(_tracker.createInstance<SingleExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleSingleExpression);
          setState(861);

          if (!(precpred(_ctx, 25))) throw FailedPredicateException(this, "precpred(_ctx, 25)");
          setState(862);
          _la = _input->LA(1);
          if (!(_la == TypeScriptParser::Plus

          || _la == TypeScriptParser::Minus)) {
          _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(863);
          singleExpression(26);
          break;
        }

        case 4: {
          auto newContext = _tracker.createInstance<CoalesceExpressionContext>(_tracker.createInstance<SingleExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleSingleExpression);
          setState(864);

          if (!(precpred(_ctx, 24))) throw FailedPredicateException(this, "precpred(_ctx, 24)");
          setState(865);
          match(TypeScriptParser::NullCoalesce);
          setState(866);
          singleExpression(25);
          break;
        }

        case 5: {
          auto newContext = _tracker.createInstance<BitShiftExpressionContext>(_tracker.createInstance<SingleExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleSingleExpression);
          setState(867);

          if (!(precpred(_ctx, 23))) throw FailedPredicateException(this, "precpred(_ctx, 23)");
          setState(868);
          _la = _input->LA(1);
          if (!((((_la & ~ 0x3fULL) == 0) &&
            ((1ULL << _la) & ((1ULL << TypeScriptParser::RightShiftArithmetic)
            | (1ULL << TypeScriptParser::LeftShiftArithmetic)
            | (1ULL << TypeScriptParser::RightShiftLogical))) != 0))) {
          _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(869);
          singleExpression(24);
          break;
        }

        case 6: {
          auto newContext = _tracker.createInstance<RelationalExpressionContext>(_tracker.createInstance<SingleExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleSingleExpression);
          setState(870);

          if (!(precpred(_ctx, 22))) throw FailedPredicateException(this, "precpred(_ctx, 22)");
          setState(871);
          _la = _input->LA(1);
          if (!((((_la & ~ 0x3fULL) == 0) &&
            ((1ULL << _la) & ((1ULL << TypeScriptParser::LessThan)
            | (1ULL << TypeScriptParser::MoreThan)
            | (1ULL << TypeScriptParser::LessThanEquals)
            | (1ULL << TypeScriptParser::GreaterThanEquals))) != 0))) {
          _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(872);
          singleExpression(23);
          break;
        }

        case 7: {
          auto newContext = _tracker.createInstance<InstanceofExpressionContext>(_tracker.createInstance<SingleExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleSingleExpression);
          setState(873);

          if (!(precpred(_ctx, 21))) throw FailedPredicateException(this, "precpred(_ctx, 21)");
          setState(874);
          match(TypeScriptParser::Instanceof);
          setState(875);
          singleExpression(22);
          break;
        }

        case 8: {
          auto newContext = _tracker.createInstance<InExpressionContext>(_tracker.createInstance<SingleExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleSingleExpression);
          setState(876);

          if (!(precpred(_ctx, 20))) throw FailedPredicateException(this, "precpred(_ctx, 20)");
          setState(877);
          match(TypeScriptParser::In);
          setState(878);
          singleExpression(21);
          break;
        }

        case 9: {
          auto newContext = _tracker.createInstance<EqualityExpressionContext>(_tracker.createInstance<SingleExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleSingleExpression);
          setState(879);

          if (!(precpred(_ctx, 19))) throw FailedPredicateException(this, "precpred(_ctx, 19)");
          setState(880);
          _la = _input->LA(1);
          if (!((((_la & ~ 0x3fULL) == 0) &&
            ((1ULL << _la) & ((1ULL << TypeScriptParser::Equals_)
            | (1ULL << TypeScriptParser::NotEquals)
            | (1ULL << TypeScriptParser::IdentityEquals)
            | (1ULL << TypeScriptParser::IdentityNotEquals))) != 0))) {
          _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(881);
          singleExpression(20);
          break;
        }

        case 10: {
          auto newContext = _tracker.createInstance<BitAndExpressionContext>(_tracker.createInstance<SingleExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleSingleExpression);
          setState(882);

          if (!(precpred(_ctx, 18))) throw FailedPredicateException(this, "precpred(_ctx, 18)");
          setState(883);
          match(TypeScriptParser::BitAnd);
          setState(884);
          singleExpression(19);
          break;
        }

        case 11: {
          auto newContext = _tracker.createInstance<BitXOrExpressionContext>(_tracker.createInstance<SingleExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleSingleExpression);
          setState(885);

          if (!(precpred(_ctx, 17))) throw FailedPredicateException(this, "precpred(_ctx, 17)");
          setState(886);
          match(TypeScriptParser::BitXOr);
          setState(887);
          singleExpression(18);
          break;
        }

        case 12: {
          auto newContext = _tracker.createInstance<BitOrExpressionContext>(_tracker.createInstance<SingleExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleSingleExpression);
          setState(888);

          if (!(precpred(_ctx, 16))) throw FailedPredicateException(this, "precpred(_ctx, 16)");
          setState(889);
          match(TypeScriptParser::BitOr);
          setState(890);
          singleExpression(17);
          break;
        }

        case 13: {
          auto newContext = _tracker.createInstance<LogicalAndExpressionContext>(_tracker.createInstance<SingleExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleSingleExpression);
          setState(891);

          if (!(precpred(_ctx, 15))) throw FailedPredicateException(this, "precpred(_ctx, 15)");
          setState(892);
          match(TypeScriptParser::And);
          setState(893);
          singleExpression(16);
          break;
        }

        case 14: {
          auto newContext = _tracker.createInstance<LogicalOrExpressionContext>(_tracker.createInstance<SingleExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleSingleExpression);
          setState(894);

          if (!(precpred(_ctx, 14))) throw FailedPredicateException(this, "precpred(_ctx, 14)");
          setState(895);
          match(TypeScriptParser::Or);
          setState(896);
          singleExpression(15);
          break;
        }

        case 15: {
          auto newContext = _tracker.createInstance<TernaryExpressionContext>(_tracker.createInstance<SingleExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleSingleExpression);
          setState(897);

          if (!(precpred(_ctx, 13))) throw FailedPredicateException(this, "precpred(_ctx, 13)");
          setState(898);
          match(TypeScriptParser::QuestionMark);
          setState(899);
          singleExpression(0);
          setState(900);
          match(TypeScriptParser::Colon);
          setState(901);
          singleExpression(14);
          break;
        }

        case 16: {
          auto newContext = _tracker.createInstance<AssignmentExpressionContext>(_tracker.createInstance<SingleExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleSingleExpression);
          setState(903);

          if (!(precpred(_ctx, 12))) throw FailedPredicateException(this, "precpred(_ctx, 12)");
          setState(904);
          match(TypeScriptParser::Assign);
          setState(905);
          singleExpression(12);
          break;
        }

        case 17: {
          auto newContext = _tracker.createInstance<AssignmentOperatorExpressionContext>(_tracker.createInstance<SingleExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleSingleExpression);
          setState(906);

          if (!(precpred(_ctx, 11))) throw FailedPredicateException(this, "precpred(_ctx, 11)");
          setState(907);
          assignmentOperator();
          setState(908);
          singleExpression(11);
          break;
        }

        case 18: {
          auto newContext = _tracker.createInstance<MemberIndexExpressionContext>(_tracker.createInstance<SingleExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleSingleExpression);
          setState(910);

          if (!(precpred(_ctx, 44))) throw FailedPredicateException(this, "precpred(_ctx, 44)");
          setState(911);
          match(TypeScriptParser::OpenBracket);
          setState(912);
          expressionSequence();
          setState(913);
          match(TypeScriptParser::CloseBracket);
          break;
        }

        case 19: {
          auto newContext = _tracker.createInstance<MemberDotExpressionContext>(_tracker.createInstance<SingleExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleSingleExpression);
          setState(915);

          if (!(precpred(_ctx, 43))) throw FailedPredicateException(this, "precpred(_ctx, 43)");
          setState(917);
          _errHandler->sync(this);

          _la = _input->LA(1);
          if (_la == TypeScriptParser::QuestionMark) {
            setState(916);
            match(TypeScriptParser::QuestionMark);
          }
          setState(919);
          match(TypeScriptParser::Dot);
          setState(921);
          _errHandler->sync(this);

          _la = _input->LA(1);
          if (_la == TypeScriptParser::Hashtag) {
            setState(920);
            match(TypeScriptParser::Hashtag);
          }
          setState(923);
          identifierName();
          break;
        }

        case 20: {
          auto newContext = _tracker.createInstance<ArgumentsExpressionContext>(_tracker.createInstance<SingleExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleSingleExpression);
          setState(924);

          if (!(precpred(_ctx, 40))) throw FailedPredicateException(this, "precpred(_ctx, 40)");
          setState(925);
          arguments();
          break;
        }

        case 21: {
          auto newContext = _tracker.createInstance<PostIncrementExpressionContext>(_tracker.createInstance<SingleExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleSingleExpression);
          setState(926);

          if (!(precpred(_ctx, 39))) throw FailedPredicateException(this, "precpred(_ctx, 39)");
          setState(927);
          match(TypeScriptParser::PlusPlus);
          break;
        }

        case 22: {
          auto newContext = _tracker.createInstance<PostDecreaseExpressionContext>(_tracker.createInstance<SingleExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleSingleExpression);
          setState(928);

          if (!(precpred(_ctx, 38))) throw FailedPredicateException(this, "precpred(_ctx, 38)");
          setState(929);
          match(TypeScriptParser::MinusMinus);
          break;
        }

        case 23: {
          auto newContext = _tracker.createInstance<TemplateStringExpressionContext>(_tracker.createInstance<SingleExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleSingleExpression);
          setState(930);

          if (!(precpred(_ctx, 9))) throw FailedPredicateException(this, "precpred(_ctx, 9)");
          setState(931);
          match(TypeScriptParser::TemplateStringLiteral);
          break;
        }

        } 
      }
      setState(936);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 103, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- AssignableContext ------------------------------------------------------------------

TypeScriptParser::AssignableContext::AssignableContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* TypeScriptParser::AssignableContext::Identifier() {
  return getToken(TypeScriptParser::Identifier, 0);
}

TypeScriptParser::ArrayLiteralContext* TypeScriptParser::AssignableContext::arrayLiteral() {
  return getRuleContext<TypeScriptParser::ArrayLiteralContext>(0);
}

TypeScriptParser::ObjectLiteralContext* TypeScriptParser::AssignableContext::objectLiteral() {
  return getRuleContext<TypeScriptParser::ObjectLiteralContext>(0);
}


size_t TypeScriptParser::AssignableContext::getRuleIndex() const {
  return TypeScriptParser::RuleAssignable;
}

void TypeScriptParser::AssignableContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TypeScriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAssignable(this);
}

void TypeScriptParser::AssignableContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TypeScriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAssignable(this);
}


antlrcpp::Any TypeScriptParser::AssignableContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TypeScriptParserVisitor*>(visitor))
    return parserVisitor->visitAssignable(this);
  else
    return visitor->visitChildren(this);
}

TypeScriptParser::AssignableContext* TypeScriptParser::assignable() {
  AssignableContext *_localctx = _tracker.createInstance<AssignableContext>(_ctx, getState());
  enterRule(_localctx, 128, TypeScriptParser::RuleAssignable);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(940);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case TypeScriptParser::Identifier: {
        enterOuterAlt(_localctx, 1);
        setState(937);
        match(TypeScriptParser::Identifier);
        break;
      }

      case TypeScriptParser::OpenBracket: {
        enterOuterAlt(_localctx, 2);
        setState(938);
        arrayLiteral();
        break;
      }

      case TypeScriptParser::OpenBrace: {
        enterOuterAlt(_localctx, 3);
        setState(939);
        objectLiteral();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- AnoymousFunctionContext ------------------------------------------------------------------

TypeScriptParser::AnoymousFunctionContext::AnoymousFunctionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t TypeScriptParser::AnoymousFunctionContext::getRuleIndex() const {
  return TypeScriptParser::RuleAnoymousFunction;
}

void TypeScriptParser::AnoymousFunctionContext::copyFrom(AnoymousFunctionContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- AnoymousFunctionDeclContext ------------------------------------------------------------------

tree::TerminalNode* TypeScriptParser::AnoymousFunctionDeclContext::Function() {
  return getToken(TypeScriptParser::Function, 0);
}

tree::TerminalNode* TypeScriptParser::AnoymousFunctionDeclContext::OpenParen() {
  return getToken(TypeScriptParser::OpenParen, 0);
}

tree::TerminalNode* TypeScriptParser::AnoymousFunctionDeclContext::CloseParen() {
  return getToken(TypeScriptParser::CloseParen, 0);
}

tree::TerminalNode* TypeScriptParser::AnoymousFunctionDeclContext::OpenBrace() {
  return getToken(TypeScriptParser::OpenBrace, 0);
}

TypeScriptParser::FunctionBodyContext* TypeScriptParser::AnoymousFunctionDeclContext::functionBody() {
  return getRuleContext<TypeScriptParser::FunctionBodyContext>(0);
}

tree::TerminalNode* TypeScriptParser::AnoymousFunctionDeclContext::CloseBrace() {
  return getToken(TypeScriptParser::CloseBrace, 0);
}

tree::TerminalNode* TypeScriptParser::AnoymousFunctionDeclContext::Async() {
  return getToken(TypeScriptParser::Async, 0);
}

tree::TerminalNode* TypeScriptParser::AnoymousFunctionDeclContext::Multiply() {
  return getToken(TypeScriptParser::Multiply, 0);
}

TypeScriptParser::FormalParameterListContext* TypeScriptParser::AnoymousFunctionDeclContext::formalParameterList() {
  return getRuleContext<TypeScriptParser::FormalParameterListContext>(0);
}

TypeScriptParser::AnoymousFunctionDeclContext::AnoymousFunctionDeclContext(AnoymousFunctionContext *ctx) { copyFrom(ctx); }

void TypeScriptParser::AnoymousFunctionDeclContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TypeScriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAnoymousFunctionDecl(this);
}
void TypeScriptParser::AnoymousFunctionDeclContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TypeScriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAnoymousFunctionDecl(this);
}

antlrcpp::Any TypeScriptParser::AnoymousFunctionDeclContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TypeScriptParserVisitor*>(visitor))
    return parserVisitor->visitAnoymousFunctionDecl(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ArrowFunctionContext ------------------------------------------------------------------

TypeScriptParser::ArrowFunctionParametersContext* TypeScriptParser::ArrowFunctionContext::arrowFunctionParameters() {
  return getRuleContext<TypeScriptParser::ArrowFunctionParametersContext>(0);
}

tree::TerminalNode* TypeScriptParser::ArrowFunctionContext::ARROW() {
  return getToken(TypeScriptParser::ARROW, 0);
}

TypeScriptParser::ArrowFunctionBodyContext* TypeScriptParser::ArrowFunctionContext::arrowFunctionBody() {
  return getRuleContext<TypeScriptParser::ArrowFunctionBodyContext>(0);
}

tree::TerminalNode* TypeScriptParser::ArrowFunctionContext::Async() {
  return getToken(TypeScriptParser::Async, 0);
}

TypeScriptParser::ArrowFunctionContext::ArrowFunctionContext(AnoymousFunctionContext *ctx) { copyFrom(ctx); }

void TypeScriptParser::ArrowFunctionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TypeScriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterArrowFunction(this);
}
void TypeScriptParser::ArrowFunctionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TypeScriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitArrowFunction(this);
}

antlrcpp::Any TypeScriptParser::ArrowFunctionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TypeScriptParserVisitor*>(visitor))
    return parserVisitor->visitArrowFunction(this);
  else
    return visitor->visitChildren(this);
}
//----------------- FunctionDeclContext ------------------------------------------------------------------

TypeScriptParser::FunctionDeclarationContext* TypeScriptParser::FunctionDeclContext::functionDeclaration() {
  return getRuleContext<TypeScriptParser::FunctionDeclarationContext>(0);
}

TypeScriptParser::FunctionDeclContext::FunctionDeclContext(AnoymousFunctionContext *ctx) { copyFrom(ctx); }

void TypeScriptParser::FunctionDeclContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TypeScriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFunctionDecl(this);
}
void TypeScriptParser::FunctionDeclContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TypeScriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFunctionDecl(this);
}

antlrcpp::Any TypeScriptParser::FunctionDeclContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TypeScriptParserVisitor*>(visitor))
    return parserVisitor->visitFunctionDecl(this);
  else
    return visitor->visitChildren(this);
}
TypeScriptParser::AnoymousFunctionContext* TypeScriptParser::anoymousFunction() {
  AnoymousFunctionContext *_localctx = _tracker.createInstance<AnoymousFunctionContext>(_ctx, getState());
  enterRule(_localctx, 130, TypeScriptParser::RuleAnoymousFunction);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(966);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 109, _ctx)) {
    case 1: {
      _localctx = dynamic_cast<AnoymousFunctionContext *>(_tracker.createInstance<TypeScriptParser::FunctionDeclContext>(_localctx));
      enterOuterAlt(_localctx, 1);
      setState(942);
      functionDeclaration();
      break;
    }

    case 2: {
      _localctx = dynamic_cast<AnoymousFunctionContext *>(_tracker.createInstance<TypeScriptParser::AnoymousFunctionDeclContext>(_localctx));
      enterOuterAlt(_localctx, 2);
      setState(944);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == TypeScriptParser::Async) {
        setState(943);
        match(TypeScriptParser::Async);
      }
      setState(946);
      match(TypeScriptParser::Function);
      setState(948);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == TypeScriptParser::Multiply) {
        setState(947);
        match(TypeScriptParser::Multiply);
      }
      setState(950);
      match(TypeScriptParser::OpenParen);
      setState(952);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & ((1ULL << TypeScriptParser::OpenBracket)
        | (1ULL << TypeScriptParser::OpenBrace)
        | (1ULL << TypeScriptParser::Ellipsis))) != 0) || _la == TypeScriptParser::Identifier) {
        setState(951);
        formalParameterList();
      }
      setState(954);
      match(TypeScriptParser::CloseParen);
      setState(955);
      match(TypeScriptParser::OpenBrace);
      setState(956);
      functionBody();
      setState(957);
      match(TypeScriptParser::CloseBrace);
      break;
    }

    case 3: {
      _localctx = dynamic_cast<AnoymousFunctionContext *>(_tracker.createInstance<TypeScriptParser::ArrowFunctionContext>(_localctx));
      enterOuterAlt(_localctx, 3);
      setState(960);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == TypeScriptParser::Async) {
        setState(959);
        match(TypeScriptParser::Async);
      }
      setState(962);
      arrowFunctionParameters();
      setState(963);
      match(TypeScriptParser::ARROW);
      setState(964);
      arrowFunctionBody();
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ArrowFunctionParametersContext ------------------------------------------------------------------

TypeScriptParser::ArrowFunctionParametersContext::ArrowFunctionParametersContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* TypeScriptParser::ArrowFunctionParametersContext::Identifier() {
  return getToken(TypeScriptParser::Identifier, 0);
}

tree::TerminalNode* TypeScriptParser::ArrowFunctionParametersContext::OpenParen() {
  return getToken(TypeScriptParser::OpenParen, 0);
}

tree::TerminalNode* TypeScriptParser::ArrowFunctionParametersContext::CloseParen() {
  return getToken(TypeScriptParser::CloseParen, 0);
}

TypeScriptParser::FormalParameterListContext* TypeScriptParser::ArrowFunctionParametersContext::formalParameterList() {
  return getRuleContext<TypeScriptParser::FormalParameterListContext>(0);
}


size_t TypeScriptParser::ArrowFunctionParametersContext::getRuleIndex() const {
  return TypeScriptParser::RuleArrowFunctionParameters;
}

void TypeScriptParser::ArrowFunctionParametersContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TypeScriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterArrowFunctionParameters(this);
}

void TypeScriptParser::ArrowFunctionParametersContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TypeScriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitArrowFunctionParameters(this);
}


antlrcpp::Any TypeScriptParser::ArrowFunctionParametersContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TypeScriptParserVisitor*>(visitor))
    return parserVisitor->visitArrowFunctionParameters(this);
  else
    return visitor->visitChildren(this);
}

TypeScriptParser::ArrowFunctionParametersContext* TypeScriptParser::arrowFunctionParameters() {
  ArrowFunctionParametersContext *_localctx = _tracker.createInstance<ArrowFunctionParametersContext>(_ctx, getState());
  enterRule(_localctx, 132, TypeScriptParser::RuleArrowFunctionParameters);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(974);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case TypeScriptParser::Identifier: {
        enterOuterAlt(_localctx, 1);
        setState(968);
        match(TypeScriptParser::Identifier);
        break;
      }

      case TypeScriptParser::OpenParen: {
        enterOuterAlt(_localctx, 2);
        setState(969);
        match(TypeScriptParser::OpenParen);
        setState(971);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if ((((_la & ~ 0x3fULL) == 0) &&
          ((1ULL << _la) & ((1ULL << TypeScriptParser::OpenBracket)
          | (1ULL << TypeScriptParser::OpenBrace)
          | (1ULL << TypeScriptParser::Ellipsis))) != 0) || _la == TypeScriptParser::Identifier) {
          setState(970);
          formalParameterList();
        }
        setState(973);
        match(TypeScriptParser::CloseParen);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ArrowFunctionBodyContext ------------------------------------------------------------------

TypeScriptParser::ArrowFunctionBodyContext::ArrowFunctionBodyContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

TypeScriptParser::SingleExpressionContext* TypeScriptParser::ArrowFunctionBodyContext::singleExpression() {
  return getRuleContext<TypeScriptParser::SingleExpressionContext>(0);
}

tree::TerminalNode* TypeScriptParser::ArrowFunctionBodyContext::OpenBrace() {
  return getToken(TypeScriptParser::OpenBrace, 0);
}

TypeScriptParser::FunctionBodyContext* TypeScriptParser::ArrowFunctionBodyContext::functionBody() {
  return getRuleContext<TypeScriptParser::FunctionBodyContext>(0);
}

tree::TerminalNode* TypeScriptParser::ArrowFunctionBodyContext::CloseBrace() {
  return getToken(TypeScriptParser::CloseBrace, 0);
}


size_t TypeScriptParser::ArrowFunctionBodyContext::getRuleIndex() const {
  return TypeScriptParser::RuleArrowFunctionBody;
}

void TypeScriptParser::ArrowFunctionBodyContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TypeScriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterArrowFunctionBody(this);
}

void TypeScriptParser::ArrowFunctionBodyContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TypeScriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitArrowFunctionBody(this);
}


antlrcpp::Any TypeScriptParser::ArrowFunctionBodyContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TypeScriptParserVisitor*>(visitor))
    return parserVisitor->visitArrowFunctionBody(this);
  else
    return visitor->visitChildren(this);
}

TypeScriptParser::ArrowFunctionBodyContext* TypeScriptParser::arrowFunctionBody() {
  ArrowFunctionBodyContext *_localctx = _tracker.createInstance<ArrowFunctionBodyContext>(_ctx, getState());
  enterRule(_localctx, 134, TypeScriptParser::RuleArrowFunctionBody);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(981);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 112, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(976);
      singleExpression(0);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(977);
      match(TypeScriptParser::OpenBrace);
      setState(978);
      functionBody();
      setState(979);
      match(TypeScriptParser::CloseBrace);
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- AssignmentOperatorContext ------------------------------------------------------------------

TypeScriptParser::AssignmentOperatorContext::AssignmentOperatorContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* TypeScriptParser::AssignmentOperatorContext::MultiplyAssign() {
  return getToken(TypeScriptParser::MultiplyAssign, 0);
}

tree::TerminalNode* TypeScriptParser::AssignmentOperatorContext::DivideAssign() {
  return getToken(TypeScriptParser::DivideAssign, 0);
}

tree::TerminalNode* TypeScriptParser::AssignmentOperatorContext::ModulusAssign() {
  return getToken(TypeScriptParser::ModulusAssign, 0);
}

tree::TerminalNode* TypeScriptParser::AssignmentOperatorContext::PlusAssign() {
  return getToken(TypeScriptParser::PlusAssign, 0);
}

tree::TerminalNode* TypeScriptParser::AssignmentOperatorContext::MinusAssign() {
  return getToken(TypeScriptParser::MinusAssign, 0);
}

tree::TerminalNode* TypeScriptParser::AssignmentOperatorContext::LeftShiftArithmeticAssign() {
  return getToken(TypeScriptParser::LeftShiftArithmeticAssign, 0);
}

tree::TerminalNode* TypeScriptParser::AssignmentOperatorContext::RightShiftArithmeticAssign() {
  return getToken(TypeScriptParser::RightShiftArithmeticAssign, 0);
}

tree::TerminalNode* TypeScriptParser::AssignmentOperatorContext::RightShiftLogicalAssign() {
  return getToken(TypeScriptParser::RightShiftLogicalAssign, 0);
}

tree::TerminalNode* TypeScriptParser::AssignmentOperatorContext::BitAndAssign() {
  return getToken(TypeScriptParser::BitAndAssign, 0);
}

tree::TerminalNode* TypeScriptParser::AssignmentOperatorContext::BitXorAssign() {
  return getToken(TypeScriptParser::BitXorAssign, 0);
}

tree::TerminalNode* TypeScriptParser::AssignmentOperatorContext::BitOrAssign() {
  return getToken(TypeScriptParser::BitOrAssign, 0);
}

tree::TerminalNode* TypeScriptParser::AssignmentOperatorContext::PowerAssign() {
  return getToken(TypeScriptParser::PowerAssign, 0);
}


size_t TypeScriptParser::AssignmentOperatorContext::getRuleIndex() const {
  return TypeScriptParser::RuleAssignmentOperator;
}

void TypeScriptParser::AssignmentOperatorContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TypeScriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAssignmentOperator(this);
}

void TypeScriptParser::AssignmentOperatorContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TypeScriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAssignmentOperator(this);
}


antlrcpp::Any TypeScriptParser::AssignmentOperatorContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TypeScriptParserVisitor*>(visitor))
    return parserVisitor->visitAssignmentOperator(this);
  else
    return visitor->visitChildren(this);
}

TypeScriptParser::AssignmentOperatorContext* TypeScriptParser::assignmentOperator() {
  AssignmentOperatorContext *_localctx = _tracker.createInstance<AssignmentOperatorContext>(_ctx, getState());
  enterRule(_localctx, 136, TypeScriptParser::RuleAssignmentOperator);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(983);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << TypeScriptParser::MultiplyAssign)
      | (1ULL << TypeScriptParser::DivideAssign)
      | (1ULL << TypeScriptParser::ModulusAssign)
      | (1ULL << TypeScriptParser::PlusAssign)
      | (1ULL << TypeScriptParser::MinusAssign)
      | (1ULL << TypeScriptParser::LeftShiftArithmeticAssign)
      | (1ULL << TypeScriptParser::RightShiftArithmeticAssign)
      | (1ULL << TypeScriptParser::RightShiftLogicalAssign)
      | (1ULL << TypeScriptParser::BitAndAssign)
      | (1ULL << TypeScriptParser::BitXorAssign)
      | (1ULL << TypeScriptParser::BitOrAssign)
      | (1ULL << TypeScriptParser::PowerAssign))) != 0))) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- LiteralContext ------------------------------------------------------------------

TypeScriptParser::LiteralContext::LiteralContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* TypeScriptParser::LiteralContext::NullLiteral() {
  return getToken(TypeScriptParser::NullLiteral, 0);
}

tree::TerminalNode* TypeScriptParser::LiteralContext::BooleanLiteral() {
  return getToken(TypeScriptParser::BooleanLiteral, 0);
}

tree::TerminalNode* TypeScriptParser::LiteralContext::StringLiteral() {
  return getToken(TypeScriptParser::StringLiteral, 0);
}

tree::TerminalNode* TypeScriptParser::LiteralContext::TemplateStringLiteral() {
  return getToken(TypeScriptParser::TemplateStringLiteral, 0);
}

tree::TerminalNode* TypeScriptParser::LiteralContext::RegularExpressionLiteral() {
  return getToken(TypeScriptParser::RegularExpressionLiteral, 0);
}

TypeScriptParser::NumericLiteralContext* TypeScriptParser::LiteralContext::numericLiteral() {
  return getRuleContext<TypeScriptParser::NumericLiteralContext>(0);
}

TypeScriptParser::BigintLiteralContext* TypeScriptParser::LiteralContext::bigintLiteral() {
  return getRuleContext<TypeScriptParser::BigintLiteralContext>(0);
}


size_t TypeScriptParser::LiteralContext::getRuleIndex() const {
  return TypeScriptParser::RuleLiteral;
}

void TypeScriptParser::LiteralContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TypeScriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterLiteral(this);
}

void TypeScriptParser::LiteralContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TypeScriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitLiteral(this);
}


antlrcpp::Any TypeScriptParser::LiteralContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TypeScriptParserVisitor*>(visitor))
    return parserVisitor->visitLiteral(this);
  else
    return visitor->visitChildren(this);
}

TypeScriptParser::LiteralContext* TypeScriptParser::literal() {
  LiteralContext *_localctx = _tracker.createInstance<LiteralContext>(_ctx, getState());
  enterRule(_localctx, 138, TypeScriptParser::RuleLiteral);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(992);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case TypeScriptParser::NullLiteral: {
        enterOuterAlt(_localctx, 1);
        setState(985);
        match(TypeScriptParser::NullLiteral);
        break;
      }

      case TypeScriptParser::BooleanLiteral: {
        enterOuterAlt(_localctx, 2);
        setState(986);
        match(TypeScriptParser::BooleanLiteral);
        break;
      }

      case TypeScriptParser::StringLiteral: {
        enterOuterAlt(_localctx, 3);
        setState(987);
        match(TypeScriptParser::StringLiteral);
        break;
      }

      case TypeScriptParser::TemplateStringLiteral: {
        enterOuterAlt(_localctx, 4);
        setState(988);
        match(TypeScriptParser::TemplateStringLiteral);
        break;
      }

      case TypeScriptParser::RegularExpressionLiteral: {
        enterOuterAlt(_localctx, 5);
        setState(989);
        match(TypeScriptParser::RegularExpressionLiteral);
        break;
      }

      case TypeScriptParser::DecimalLiteral:
      case TypeScriptParser::HexIntegerLiteral:
      case TypeScriptParser::OctalIntegerLiteral:
      case TypeScriptParser::OctalIntegerLiteral2:
      case TypeScriptParser::BinaryIntegerLiteral: {
        enterOuterAlt(_localctx, 6);
        setState(990);
        numericLiteral();
        break;
      }

      case TypeScriptParser::BigHexIntegerLiteral:
      case TypeScriptParser::BigOctalIntegerLiteral:
      case TypeScriptParser::BigBinaryIntegerLiteral:
      case TypeScriptParser::BigDecimalIntegerLiteral: {
        enterOuterAlt(_localctx, 7);
        setState(991);
        bigintLiteral();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- NumericLiteralContext ------------------------------------------------------------------

TypeScriptParser::NumericLiteralContext::NumericLiteralContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* TypeScriptParser::NumericLiteralContext::DecimalLiteral() {
  return getToken(TypeScriptParser::DecimalLiteral, 0);
}

tree::TerminalNode* TypeScriptParser::NumericLiteralContext::HexIntegerLiteral() {
  return getToken(TypeScriptParser::HexIntegerLiteral, 0);
}

tree::TerminalNode* TypeScriptParser::NumericLiteralContext::OctalIntegerLiteral() {
  return getToken(TypeScriptParser::OctalIntegerLiteral, 0);
}

tree::TerminalNode* TypeScriptParser::NumericLiteralContext::OctalIntegerLiteral2() {
  return getToken(TypeScriptParser::OctalIntegerLiteral2, 0);
}

tree::TerminalNode* TypeScriptParser::NumericLiteralContext::BinaryIntegerLiteral() {
  return getToken(TypeScriptParser::BinaryIntegerLiteral, 0);
}


size_t TypeScriptParser::NumericLiteralContext::getRuleIndex() const {
  return TypeScriptParser::RuleNumericLiteral;
}

void TypeScriptParser::NumericLiteralContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TypeScriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterNumericLiteral(this);
}

void TypeScriptParser::NumericLiteralContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TypeScriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitNumericLiteral(this);
}


antlrcpp::Any TypeScriptParser::NumericLiteralContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TypeScriptParserVisitor*>(visitor))
    return parserVisitor->visitNumericLiteral(this);
  else
    return visitor->visitChildren(this);
}

TypeScriptParser::NumericLiteralContext* TypeScriptParser::numericLiteral() {
  NumericLiteralContext *_localctx = _tracker.createInstance<NumericLiteralContext>(_ctx, getState());
  enterRule(_localctx, 140, TypeScriptParser::RuleNumericLiteral);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(994);
    _la = _input->LA(1);
    if (!(((((_la - 61) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 61)) & ((1ULL << (TypeScriptParser::DecimalLiteral - 61))
      | (1ULL << (TypeScriptParser::HexIntegerLiteral - 61))
      | (1ULL << (TypeScriptParser::OctalIntegerLiteral - 61))
      | (1ULL << (TypeScriptParser::OctalIntegerLiteral2 - 61))
      | (1ULL << (TypeScriptParser::BinaryIntegerLiteral - 61)))) != 0))) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- BigintLiteralContext ------------------------------------------------------------------

TypeScriptParser::BigintLiteralContext::BigintLiteralContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* TypeScriptParser::BigintLiteralContext::BigDecimalIntegerLiteral() {
  return getToken(TypeScriptParser::BigDecimalIntegerLiteral, 0);
}

tree::TerminalNode* TypeScriptParser::BigintLiteralContext::BigHexIntegerLiteral() {
  return getToken(TypeScriptParser::BigHexIntegerLiteral, 0);
}

tree::TerminalNode* TypeScriptParser::BigintLiteralContext::BigOctalIntegerLiteral() {
  return getToken(TypeScriptParser::BigOctalIntegerLiteral, 0);
}

tree::TerminalNode* TypeScriptParser::BigintLiteralContext::BigBinaryIntegerLiteral() {
  return getToken(TypeScriptParser::BigBinaryIntegerLiteral, 0);
}


size_t TypeScriptParser::BigintLiteralContext::getRuleIndex() const {
  return TypeScriptParser::RuleBigintLiteral;
}

void TypeScriptParser::BigintLiteralContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TypeScriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterBigintLiteral(this);
}

void TypeScriptParser::BigintLiteralContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TypeScriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitBigintLiteral(this);
}


antlrcpp::Any TypeScriptParser::BigintLiteralContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TypeScriptParserVisitor*>(visitor))
    return parserVisitor->visitBigintLiteral(this);
  else
    return visitor->visitChildren(this);
}

TypeScriptParser::BigintLiteralContext* TypeScriptParser::bigintLiteral() {
  BigintLiteralContext *_localctx = _tracker.createInstance<BigintLiteralContext>(_ctx, getState());
  enterRule(_localctx, 142, TypeScriptParser::RuleBigintLiteral);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(996);
    _la = _input->LA(1);
    if (!(((((_la - 75) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 75)) & ((1ULL << (TypeScriptParser::BigHexIntegerLiteral - 75))
      | (1ULL << (TypeScriptParser::BigOctalIntegerLiteral - 75))
      | (1ULL << (TypeScriptParser::BigBinaryIntegerLiteral - 75))
      | (1ULL << (TypeScriptParser::BigDecimalIntegerLiteral - 75)))) != 0))) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- IdentifierNameContext ------------------------------------------------------------------

TypeScriptParser::IdentifierNameContext::IdentifierNameContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* TypeScriptParser::IdentifierNameContext::Identifier() {
  return getToken(TypeScriptParser::Identifier, 0);
}

TypeScriptParser::ReservedWordContext* TypeScriptParser::IdentifierNameContext::reservedWord() {
  return getRuleContext<TypeScriptParser::ReservedWordContext>(0);
}


size_t TypeScriptParser::IdentifierNameContext::getRuleIndex() const {
  return TypeScriptParser::RuleIdentifierName;
}

void TypeScriptParser::IdentifierNameContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TypeScriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterIdentifierName(this);
}

void TypeScriptParser::IdentifierNameContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TypeScriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitIdentifierName(this);
}


antlrcpp::Any TypeScriptParser::IdentifierNameContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TypeScriptParserVisitor*>(visitor))
    return parserVisitor->visitIdentifierName(this);
  else
    return visitor->visitChildren(this);
}

TypeScriptParser::IdentifierNameContext* TypeScriptParser::identifierName() {
  IdentifierNameContext *_localctx = _tracker.createInstance<IdentifierNameContext>(_ctx, getState());
  enterRule(_localctx, 144, TypeScriptParser::RuleIdentifierName);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(1000);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case TypeScriptParser::Identifier: {
        enterOuterAlt(_localctx, 1);
        setState(998);
        match(TypeScriptParser::Identifier);
        break;
      }

      case TypeScriptParser::NullLiteral:
      case TypeScriptParser::BooleanLiteral:
      case TypeScriptParser::Break:
      case TypeScriptParser::Do:
      case TypeScriptParser::Instanceof:
      case TypeScriptParser::Typeof:
      case TypeScriptParser::Case:
      case TypeScriptParser::Else:
      case TypeScriptParser::New:
      case TypeScriptParser::Var:
      case TypeScriptParser::Catch:
      case TypeScriptParser::Finally:
      case TypeScriptParser::Return:
      case TypeScriptParser::Void:
      case TypeScriptParser::Continue:
      case TypeScriptParser::For:
      case TypeScriptParser::Switch:
      case TypeScriptParser::While:
      case TypeScriptParser::Debugger:
      case TypeScriptParser::Function:
      case TypeScriptParser::This:
      case TypeScriptParser::With:
      case TypeScriptParser::Default:
      case TypeScriptParser::If:
      case TypeScriptParser::Throw:
      case TypeScriptParser::Delete:
      case TypeScriptParser::In:
      case TypeScriptParser::Try:
      case TypeScriptParser::As:
      case TypeScriptParser::From:
      case TypeScriptParser::Class:
      case TypeScriptParser::Enum:
      case TypeScriptParser::Extends:
      case TypeScriptParser::Super:
      case TypeScriptParser::Const:
      case TypeScriptParser::Export:
      case TypeScriptParser::Import:
      case TypeScriptParser::Async:
      case TypeScriptParser::Await:
      case TypeScriptParser::Implements:
      case TypeScriptParser::Let:
      case TypeScriptParser::Private:
      case TypeScriptParser::Public:
      case TypeScriptParser::Interface:
      case TypeScriptParser::Package:
      case TypeScriptParser::Protected:
      case TypeScriptParser::Static:
      case TypeScriptParser::Yield: {
        enterOuterAlt(_localctx, 2);
        setState(999);
        reservedWord();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ReservedWordContext ------------------------------------------------------------------

TypeScriptParser::ReservedWordContext::ReservedWordContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

TypeScriptParser::KeywordContext* TypeScriptParser::ReservedWordContext::keyword() {
  return getRuleContext<TypeScriptParser::KeywordContext>(0);
}

tree::TerminalNode* TypeScriptParser::ReservedWordContext::NullLiteral() {
  return getToken(TypeScriptParser::NullLiteral, 0);
}

tree::TerminalNode* TypeScriptParser::ReservedWordContext::BooleanLiteral() {
  return getToken(TypeScriptParser::BooleanLiteral, 0);
}


size_t TypeScriptParser::ReservedWordContext::getRuleIndex() const {
  return TypeScriptParser::RuleReservedWord;
}

void TypeScriptParser::ReservedWordContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TypeScriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterReservedWord(this);
}

void TypeScriptParser::ReservedWordContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TypeScriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitReservedWord(this);
}


antlrcpp::Any TypeScriptParser::ReservedWordContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TypeScriptParserVisitor*>(visitor))
    return parserVisitor->visitReservedWord(this);
  else
    return visitor->visitChildren(this);
}

TypeScriptParser::ReservedWordContext* TypeScriptParser::reservedWord() {
  ReservedWordContext *_localctx = _tracker.createInstance<ReservedWordContext>(_ctx, getState());
  enterRule(_localctx, 146, TypeScriptParser::RuleReservedWord);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(1005);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case TypeScriptParser::Break:
      case TypeScriptParser::Do:
      case TypeScriptParser::Instanceof:
      case TypeScriptParser::Typeof:
      case TypeScriptParser::Case:
      case TypeScriptParser::Else:
      case TypeScriptParser::New:
      case TypeScriptParser::Var:
      case TypeScriptParser::Catch:
      case TypeScriptParser::Finally:
      case TypeScriptParser::Return:
      case TypeScriptParser::Void:
      case TypeScriptParser::Continue:
      case TypeScriptParser::For:
      case TypeScriptParser::Switch:
      case TypeScriptParser::While:
      case TypeScriptParser::Debugger:
      case TypeScriptParser::Function:
      case TypeScriptParser::This:
      case TypeScriptParser::With:
      case TypeScriptParser::Default:
      case TypeScriptParser::If:
      case TypeScriptParser::Throw:
      case TypeScriptParser::Delete:
      case TypeScriptParser::In:
      case TypeScriptParser::Try:
      case TypeScriptParser::As:
      case TypeScriptParser::From:
      case TypeScriptParser::Class:
      case TypeScriptParser::Enum:
      case TypeScriptParser::Extends:
      case TypeScriptParser::Super:
      case TypeScriptParser::Const:
      case TypeScriptParser::Export:
      case TypeScriptParser::Import:
      case TypeScriptParser::Async:
      case TypeScriptParser::Await:
      case TypeScriptParser::Implements:
      case TypeScriptParser::Let:
      case TypeScriptParser::Private:
      case TypeScriptParser::Public:
      case TypeScriptParser::Interface:
      case TypeScriptParser::Package:
      case TypeScriptParser::Protected:
      case TypeScriptParser::Static:
      case TypeScriptParser::Yield: {
        enterOuterAlt(_localctx, 1);
        setState(1002);
        keyword();
        break;
      }

      case TypeScriptParser::NullLiteral: {
        enterOuterAlt(_localctx, 2);
        setState(1003);
        match(TypeScriptParser::NullLiteral);
        break;
      }

      case TypeScriptParser::BooleanLiteral: {
        enterOuterAlt(_localctx, 3);
        setState(1004);
        match(TypeScriptParser::BooleanLiteral);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- KeywordContext ------------------------------------------------------------------

TypeScriptParser::KeywordContext::KeywordContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* TypeScriptParser::KeywordContext::Break() {
  return getToken(TypeScriptParser::Break, 0);
}

tree::TerminalNode* TypeScriptParser::KeywordContext::Do() {
  return getToken(TypeScriptParser::Do, 0);
}

tree::TerminalNode* TypeScriptParser::KeywordContext::Instanceof() {
  return getToken(TypeScriptParser::Instanceof, 0);
}

tree::TerminalNode* TypeScriptParser::KeywordContext::Typeof() {
  return getToken(TypeScriptParser::Typeof, 0);
}

tree::TerminalNode* TypeScriptParser::KeywordContext::Case() {
  return getToken(TypeScriptParser::Case, 0);
}

tree::TerminalNode* TypeScriptParser::KeywordContext::Else() {
  return getToken(TypeScriptParser::Else, 0);
}

tree::TerminalNode* TypeScriptParser::KeywordContext::New() {
  return getToken(TypeScriptParser::New, 0);
}

tree::TerminalNode* TypeScriptParser::KeywordContext::Var() {
  return getToken(TypeScriptParser::Var, 0);
}

tree::TerminalNode* TypeScriptParser::KeywordContext::Catch() {
  return getToken(TypeScriptParser::Catch, 0);
}

tree::TerminalNode* TypeScriptParser::KeywordContext::Finally() {
  return getToken(TypeScriptParser::Finally, 0);
}

tree::TerminalNode* TypeScriptParser::KeywordContext::Return() {
  return getToken(TypeScriptParser::Return, 0);
}

tree::TerminalNode* TypeScriptParser::KeywordContext::Void() {
  return getToken(TypeScriptParser::Void, 0);
}

tree::TerminalNode* TypeScriptParser::KeywordContext::Continue() {
  return getToken(TypeScriptParser::Continue, 0);
}

tree::TerminalNode* TypeScriptParser::KeywordContext::For() {
  return getToken(TypeScriptParser::For, 0);
}

tree::TerminalNode* TypeScriptParser::KeywordContext::Switch() {
  return getToken(TypeScriptParser::Switch, 0);
}

tree::TerminalNode* TypeScriptParser::KeywordContext::While() {
  return getToken(TypeScriptParser::While, 0);
}

tree::TerminalNode* TypeScriptParser::KeywordContext::Debugger() {
  return getToken(TypeScriptParser::Debugger, 0);
}

tree::TerminalNode* TypeScriptParser::KeywordContext::Function() {
  return getToken(TypeScriptParser::Function, 0);
}

tree::TerminalNode* TypeScriptParser::KeywordContext::This() {
  return getToken(TypeScriptParser::This, 0);
}

tree::TerminalNode* TypeScriptParser::KeywordContext::With() {
  return getToken(TypeScriptParser::With, 0);
}

tree::TerminalNode* TypeScriptParser::KeywordContext::Default() {
  return getToken(TypeScriptParser::Default, 0);
}

tree::TerminalNode* TypeScriptParser::KeywordContext::If() {
  return getToken(TypeScriptParser::If, 0);
}

tree::TerminalNode* TypeScriptParser::KeywordContext::Throw() {
  return getToken(TypeScriptParser::Throw, 0);
}

tree::TerminalNode* TypeScriptParser::KeywordContext::Delete() {
  return getToken(TypeScriptParser::Delete, 0);
}

tree::TerminalNode* TypeScriptParser::KeywordContext::In() {
  return getToken(TypeScriptParser::In, 0);
}

tree::TerminalNode* TypeScriptParser::KeywordContext::Try() {
  return getToken(TypeScriptParser::Try, 0);
}

tree::TerminalNode* TypeScriptParser::KeywordContext::Class() {
  return getToken(TypeScriptParser::Class, 0);
}

tree::TerminalNode* TypeScriptParser::KeywordContext::Enum() {
  return getToken(TypeScriptParser::Enum, 0);
}

tree::TerminalNode* TypeScriptParser::KeywordContext::Extends() {
  return getToken(TypeScriptParser::Extends, 0);
}

tree::TerminalNode* TypeScriptParser::KeywordContext::Super() {
  return getToken(TypeScriptParser::Super, 0);
}

tree::TerminalNode* TypeScriptParser::KeywordContext::Const() {
  return getToken(TypeScriptParser::Const, 0);
}

tree::TerminalNode* TypeScriptParser::KeywordContext::Export() {
  return getToken(TypeScriptParser::Export, 0);
}

tree::TerminalNode* TypeScriptParser::KeywordContext::Import() {
  return getToken(TypeScriptParser::Import, 0);
}

tree::TerminalNode* TypeScriptParser::KeywordContext::Implements() {
  return getToken(TypeScriptParser::Implements, 0);
}

tree::TerminalNode* TypeScriptParser::KeywordContext::Let() {
  return getToken(TypeScriptParser::Let, 0);
}

tree::TerminalNode* TypeScriptParser::KeywordContext::Private() {
  return getToken(TypeScriptParser::Private, 0);
}

tree::TerminalNode* TypeScriptParser::KeywordContext::Public() {
  return getToken(TypeScriptParser::Public, 0);
}

tree::TerminalNode* TypeScriptParser::KeywordContext::Interface() {
  return getToken(TypeScriptParser::Interface, 0);
}

tree::TerminalNode* TypeScriptParser::KeywordContext::Package() {
  return getToken(TypeScriptParser::Package, 0);
}

tree::TerminalNode* TypeScriptParser::KeywordContext::Protected() {
  return getToken(TypeScriptParser::Protected, 0);
}

tree::TerminalNode* TypeScriptParser::KeywordContext::Static() {
  return getToken(TypeScriptParser::Static, 0);
}

tree::TerminalNode* TypeScriptParser::KeywordContext::Yield() {
  return getToken(TypeScriptParser::Yield, 0);
}

tree::TerminalNode* TypeScriptParser::KeywordContext::Async() {
  return getToken(TypeScriptParser::Async, 0);
}

tree::TerminalNode* TypeScriptParser::KeywordContext::Await() {
  return getToken(TypeScriptParser::Await, 0);
}

tree::TerminalNode* TypeScriptParser::KeywordContext::From() {
  return getToken(TypeScriptParser::From, 0);
}

tree::TerminalNode* TypeScriptParser::KeywordContext::As() {
  return getToken(TypeScriptParser::As, 0);
}


size_t TypeScriptParser::KeywordContext::getRuleIndex() const {
  return TypeScriptParser::RuleKeyword;
}

void TypeScriptParser::KeywordContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TypeScriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterKeyword(this);
}

void TypeScriptParser::KeywordContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TypeScriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitKeyword(this);
}


antlrcpp::Any TypeScriptParser::KeywordContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TypeScriptParserVisitor*>(visitor))
    return parserVisitor->visitKeyword(this);
  else
    return visitor->visitChildren(this);
}

TypeScriptParser::KeywordContext* TypeScriptParser::keyword() {
  KeywordContext *_localctx = _tracker.createInstance<KeywordContext>(_ctx, getState());
  enterRule(_localctx, 148, TypeScriptParser::RuleKeyword);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1007);
    _la = _input->LA(1);
    if (!(((((_la - 80) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 80)) & ((1ULL << (TypeScriptParser::Break - 80))
      | (1ULL << (TypeScriptParser::Do - 80))
      | (1ULL << (TypeScriptParser::Instanceof - 80))
      | (1ULL << (TypeScriptParser::Typeof - 80))
      | (1ULL << (TypeScriptParser::Case - 80))
      | (1ULL << (TypeScriptParser::Else - 80))
      | (1ULL << (TypeScriptParser::New - 80))
      | (1ULL << (TypeScriptParser::Var - 80))
      | (1ULL << (TypeScriptParser::Catch - 80))
      | (1ULL << (TypeScriptParser::Finally - 80))
      | (1ULL << (TypeScriptParser::Return - 80))
      | (1ULL << (TypeScriptParser::Void - 80))
      | (1ULL << (TypeScriptParser::Continue - 80))
      | (1ULL << (TypeScriptParser::For - 80))
      | (1ULL << (TypeScriptParser::Switch - 80))
      | (1ULL << (TypeScriptParser::While - 80))
      | (1ULL << (TypeScriptParser::Debugger - 80))
      | (1ULL << (TypeScriptParser::Function - 80))
      | (1ULL << (TypeScriptParser::This - 80))
      | (1ULL << (TypeScriptParser::With - 80))
      | (1ULL << (TypeScriptParser::Default - 80))
      | (1ULL << (TypeScriptParser::If - 80))
      | (1ULL << (TypeScriptParser::Throw - 80))
      | (1ULL << (TypeScriptParser::Delete - 80))
      | (1ULL << (TypeScriptParser::In - 80))
      | (1ULL << (TypeScriptParser::Try - 80))
      | (1ULL << (TypeScriptParser::As - 80))
      | (1ULL << (TypeScriptParser::From - 80))
      | (1ULL << (TypeScriptParser::Class - 80))
      | (1ULL << (TypeScriptParser::Enum - 80))
      | (1ULL << (TypeScriptParser::Extends - 80))
      | (1ULL << (TypeScriptParser::Super - 80))
      | (1ULL << (TypeScriptParser::Const - 80))
      | (1ULL << (TypeScriptParser::Export - 80))
      | (1ULL << (TypeScriptParser::Import - 80))
      | (1ULL << (TypeScriptParser::Async - 80))
      | (1ULL << (TypeScriptParser::Await - 80))
      | (1ULL << (TypeScriptParser::Implements - 80))
      | (1ULL << (TypeScriptParser::Let - 80))
      | (1ULL << (TypeScriptParser::Private - 80))
      | (1ULL << (TypeScriptParser::Public - 80))
      | (1ULL << (TypeScriptParser::Interface - 80))
      | (1ULL << (TypeScriptParser::Package - 80))
      | (1ULL << (TypeScriptParser::Protected - 80))
      | (1ULL << (TypeScriptParser::Static - 80))
      | (1ULL << (TypeScriptParser::Yield - 80)))) != 0))) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- GetterContext ------------------------------------------------------------------

TypeScriptParser::GetterContext::GetterContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* TypeScriptParser::GetterContext::Get() {
  return getToken(TypeScriptParser::Get, 0);
}

TypeScriptParser::PropertyNameContext* TypeScriptParser::GetterContext::propertyName() {
  return getRuleContext<TypeScriptParser::PropertyNameContext>(0);
}


size_t TypeScriptParser::GetterContext::getRuleIndex() const {
  return TypeScriptParser::RuleGetter;
}

void TypeScriptParser::GetterContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TypeScriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterGetter(this);
}

void TypeScriptParser::GetterContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TypeScriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitGetter(this);
}


antlrcpp::Any TypeScriptParser::GetterContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TypeScriptParserVisitor*>(visitor))
    return parserVisitor->visitGetter(this);
  else
    return visitor->visitChildren(this);
}

TypeScriptParser::GetterContext* TypeScriptParser::getter() {
  GetterContext *_localctx = _tracker.createInstance<GetterContext>(_ctx, getState());
  enterRule(_localctx, 150, TypeScriptParser::RuleGetter);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1009);
    match(TypeScriptParser::Get);
    setState(1010);
    propertyName();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- SetterContext ------------------------------------------------------------------

TypeScriptParser::SetterContext::SetterContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* TypeScriptParser::SetterContext::Set() {
  return getToken(TypeScriptParser::Set, 0);
}

TypeScriptParser::PropertyNameContext* TypeScriptParser::SetterContext::propertyName() {
  return getRuleContext<TypeScriptParser::PropertyNameContext>(0);
}


size_t TypeScriptParser::SetterContext::getRuleIndex() const {
  return TypeScriptParser::RuleSetter;
}

void TypeScriptParser::SetterContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TypeScriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSetter(this);
}

void TypeScriptParser::SetterContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TypeScriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSetter(this);
}


antlrcpp::Any TypeScriptParser::SetterContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TypeScriptParserVisitor*>(visitor))
    return parserVisitor->visitSetter(this);
  else
    return visitor->visitChildren(this);
}

TypeScriptParser::SetterContext* TypeScriptParser::setter() {
  SetterContext *_localctx = _tracker.createInstance<SetterContext>(_ctx, getState());
  enterRule(_localctx, 152, TypeScriptParser::RuleSetter);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1012);
    match(TypeScriptParser::Set);
    setState(1013);
    propertyName();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- EosContext ------------------------------------------------------------------

TypeScriptParser::EosContext::EosContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* TypeScriptParser::EosContext::SemiColon() {
  return getToken(TypeScriptParser::SemiColon, 0);
}

tree::TerminalNode* TypeScriptParser::EosContext::EOF() {
  return getToken(TypeScriptParser::EOF, 0);
}


size_t TypeScriptParser::EosContext::getRuleIndex() const {
  return TypeScriptParser::RuleEos;
}

void TypeScriptParser::EosContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TypeScriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterEos(this);
}

void TypeScriptParser::EosContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TypeScriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitEos(this);
}


antlrcpp::Any TypeScriptParser::EosContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TypeScriptParserVisitor*>(visitor))
    return parserVisitor->visitEos(this);
  else
    return visitor->visitChildren(this);
}

TypeScriptParser::EosContext* TypeScriptParser::eos() {
  EosContext *_localctx = _tracker.createInstance<EosContext>(_ctx, getState());
  enterRule(_localctx, 154, TypeScriptParser::RuleEos);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1015);
    _la = _input->LA(1);
    if (!(_la == TypeScriptParser::EOF

    || _la == TypeScriptParser::SemiColon)) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

bool TypeScriptParser::sempred(RuleContext *context, size_t ruleIndex, size_t predicateIndex) {
  switch (ruleIndex) {
    case 63: return singleExpressionSempred(dynamic_cast<SingleExpressionContext *>(context), predicateIndex);

  default:
    break;
  }
  return true;
}

bool TypeScriptParser::singleExpressionSempred(SingleExpressionContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 0: return precpred(_ctx, 27);
    case 1: return precpred(_ctx, 26);
    case 2: return precpred(_ctx, 25);
    case 3: return precpred(_ctx, 24);
    case 4: return precpred(_ctx, 23);
    case 5: return precpred(_ctx, 22);
    case 6: return precpred(_ctx, 21);
    case 7: return precpred(_ctx, 20);
    case 8: return precpred(_ctx, 19);
    case 9: return precpred(_ctx, 18);
    case 10: return precpred(_ctx, 17);
    case 11: return precpred(_ctx, 16);
    case 12: return precpred(_ctx, 15);
    case 13: return precpred(_ctx, 14);
    case 14: return precpred(_ctx, 13);
    case 15: return precpred(_ctx, 12);
    case 16: return precpred(_ctx, 11);
    case 17: return precpred(_ctx, 44);
    case 18: return precpred(_ctx, 43);
    case 19: return precpred(_ctx, 40);
    case 20: return precpred(_ctx, 39);
    case 21: return precpred(_ctx, 38);
    case 22: return precpred(_ctx, 9);

  default:
    break;
  }
  return true;
}

// Static vars and initialization.
std::vector<dfa::DFA> TypeScriptParser::_decisionToDFA;
atn::PredictionContextCache TypeScriptParser::_sharedContextCache;

// We own the ATN which in turn owns the ATN states.
atn::ATN TypeScriptParser::_atn;
std::vector<uint16_t> TypeScriptParser::_serializedATN;

std::vector<std::string> TypeScriptParser::_ruleNames = {
  "program", "statementList", "statement", "typeSign", "primaryType", "predefinedType", 
  "typeReference", "accessControl", "classControl", "propertyControl", "functionControl", 
  "block", "importStatement", "importFromBlock", "moduleItems", "importDefault", 
  "importNamespace", "importFrom", "aliasName", "exportStatement", "exportFromBlock", 
  "declaration", "variableStatement", "variableDeclarationList", "variableDeclaration", 
  "emptyStatement", "expressionStatement", "ifStatement", "iterationStatement", 
  "forInitialization", "forCondition", "varModifier", "continueStatement", 
  "breakStatement", "returnStatement", "yieldStatement", "withStatement", 
  "switchStatement", "caseBlock", "caseClause", "labelledStatement", "throwStatement", 
  "tryStatement", "catchProduction", "finallyProduction", "debuggerStatement", 
  "functionDeclaration", "classDeclaration", "classTail", "classElement", 
  "formalParameterList", "formalParameterArg", "lastFormalParameterArg", 
  "functionBody", "arrayLiteral", "elementList", "arrayElement", "objectLiteral", 
  "propertyAssignment", "propertyName", "arguments", "argument", "expressionSequence", 
  "singleExpression", "assignable", "anoymousFunction", "arrowFunctionParameters", 
  "arrowFunctionBody", "assignmentOperator", "literal", "numericLiteral", 
  "bigintLiteral", "identifierName", "reservedWord", "keyword", "getter", 
  "setter", "eos"
};

std::vector<std::string> TypeScriptParser::_literalNames = {
  "", "", "", "", "", "'['", "']'", "'('", "')'", "'{'", "'}'", "';'", "','", 
  "'='", "'?'", "':'", "'...'", "'.'", "'++'", "'--'", "'+'", "'-'", "'~'", 
  "'!'", "'*'", "'/'", "'%'", "'**'", "'??'", "'#'", "'>>'", "'<<'", "'>>>'", 
  "'<'", "'>'", "'<='", "'>='", "'=='", "'!='", "'==='", "'!=='", "'&'", 
  "'^'", "'|'", "'&&'", "'||'", "'*='", "'/='", "'%='", "'+='", "'-='", 
  "'<<='", "'>>='", "'>>>='", "'&='", "'^='", "'|='", "'**='", "'=>'", "", 
  "", "", "'any'", "'int32'", "'int64'", "'float'", "'double'", "'number'", 
  "'boolean'", "'string'", "", "", "", "", "", "", "", "", "", "'readonly'", 
  "'break'", "'do'", "'instanceof'", "'typeof'", "'case'", "'else'", "'new'", 
  "'var'", "'catch'", "'finally'", "'return'", "'void'", "'continue'", "'for'", 
  "'switch'", "'while'", "'debugger'", "'function'", "'this'", "'with'", 
  "'default'", "'if'", "'throw'", "'delete'", "'in'", "'try'", "'as'", "'from'", 
  "'class'", "'constructor'", "'enum'", "'extends'", "'super'", "'const'", 
  "'export'", "'import'", "'async'", "'await'", "'implements'", "'let'", 
  "'private'", "'public'", "'interface'", "'package'", "'protected'", "'static'", 
  "'final'", "'yield'", "'get'", "'set'", "'of'"
};

std::vector<std::string> TypeScriptParser::_symbolicNames = {
  "", "HashBangLine", "MultiLineComment", "SingleLineComment", "RegularExpressionLiteral", 
  "OpenBracket", "CloseBracket", "OpenParen", "CloseParen", "OpenBrace", 
  "CloseBrace", "SemiColon", "Comma", "Assign", "QuestionMark", "Colon", 
  "Ellipsis", "Dot", "PlusPlus", "MinusMinus", "Plus", "Minus", "BitNot", 
  "Not", "Multiply", "Divide", "Modulus", "Power", "NullCoalesce", "Hashtag", 
  "RightShiftArithmetic", "LeftShiftArithmetic", "RightShiftLogical", "LessThan", 
  "MoreThan", "LessThanEquals", "GreaterThanEquals", "Equals_", "NotEquals", 
  "IdentityEquals", "IdentityNotEquals", "BitAnd", "BitXOr", "BitOr", "And", 
  "Or", "MultiplyAssign", "DivideAssign", "ModulusAssign", "PlusAssign", 
  "MinusAssign", "LeftShiftArithmeticAssign", "RightShiftArithmeticAssign", 
  "RightShiftLogicalAssign", "BitAndAssign", "BitXorAssign", "BitOrAssign", 
  "PowerAssign", "ARROW", "NullLiteral", "BooleanLiteral", "DecimalLiteral", 
  "AnyType", "Int32Type", "Int64Type", "FloatType", "DoubleType", "NumberType", 
  "BooleanType", "StringType", "VoidType", "HexIntegerLiteral", "OctalIntegerLiteral", 
  "OctalIntegerLiteral2", "BinaryIntegerLiteral", "BigHexIntegerLiteral", 
  "BigOctalIntegerLiteral", "BigBinaryIntegerLiteral", "BigDecimalIntegerLiteral", 
  "Readonly", "Break", "Do", "Instanceof", "Typeof", "Case", "Else", "New", 
  "Var", "Catch", "Finally", "Return", "Void", "Continue", "For", "Switch", 
  "While", "Debugger", "Function", "This", "With", "Default", "If", "Throw", 
  "Delete", "In", "Try", "As", "From", "Class", "Constructor", "Enum", "Extends", 
  "Super", "Const", "Export", "Import", "Async", "Await", "Implements", 
  "Let", "Private", "Public", "Interface", "Package", "Protected", "Static", 
  "Final", "Yield", "Get", "Set", "Of", "Identifier", "StringLiteral", "TemplateStringLiteral", 
  "WhiteSpaces", "LineTerminator", "HtmlComment", "CDataComment", "UnexpectedCharacter"
};

dfa::Vocabulary TypeScriptParser::_vocabulary(_literalNames, _symbolicNames);

std::vector<std::string> TypeScriptParser::_tokenNames;

TypeScriptParser::Initializer::Initializer() {
	for (size_t i = 0; i < _symbolicNames.size(); ++i) {
		std::string name = _vocabulary.getLiteralName(i);
		if (name.empty()) {
			name = _vocabulary.getSymbolicName(i);
		}

		if (name.empty()) {
			_tokenNames.push_back("<INVALID>");
		} else {
      _tokenNames.push_back(name);
    }
	}

  _serializedATN = {
    0x3, 0x608b, 0xa72a, 0x8133, 0xb9ed, 0x417c, 0x3be7, 0x7786, 0x5964, 
    0x3, 0x8c, 0x3fc, 0x4, 0x2, 0x9, 0x2, 0x4, 0x3, 0x9, 0x3, 0x4, 0x4, 
    0x9, 0x4, 0x4, 0x5, 0x9, 0x5, 0x4, 0x6, 0x9, 0x6, 0x4, 0x7, 0x9, 0x7, 
    0x4, 0x8, 0x9, 0x8, 0x4, 0x9, 0x9, 0x9, 0x4, 0xa, 0x9, 0xa, 0x4, 0xb, 
    0x9, 0xb, 0x4, 0xc, 0x9, 0xc, 0x4, 0xd, 0x9, 0xd, 0x4, 0xe, 0x9, 0xe, 
    0x4, 0xf, 0x9, 0xf, 0x4, 0x10, 0x9, 0x10, 0x4, 0x11, 0x9, 0x11, 0x4, 
    0x12, 0x9, 0x12, 0x4, 0x13, 0x9, 0x13, 0x4, 0x14, 0x9, 0x14, 0x4, 0x15, 
    0x9, 0x15, 0x4, 0x16, 0x9, 0x16, 0x4, 0x17, 0x9, 0x17, 0x4, 0x18, 0x9, 
    0x18, 0x4, 0x19, 0x9, 0x19, 0x4, 0x1a, 0x9, 0x1a, 0x4, 0x1b, 0x9, 0x1b, 
    0x4, 0x1c, 0x9, 0x1c, 0x4, 0x1d, 0x9, 0x1d, 0x4, 0x1e, 0x9, 0x1e, 0x4, 
    0x1f, 0x9, 0x1f, 0x4, 0x20, 0x9, 0x20, 0x4, 0x21, 0x9, 0x21, 0x4, 0x22, 
    0x9, 0x22, 0x4, 0x23, 0x9, 0x23, 0x4, 0x24, 0x9, 0x24, 0x4, 0x25, 0x9, 
    0x25, 0x4, 0x26, 0x9, 0x26, 0x4, 0x27, 0x9, 0x27, 0x4, 0x28, 0x9, 0x28, 
    0x4, 0x29, 0x9, 0x29, 0x4, 0x2a, 0x9, 0x2a, 0x4, 0x2b, 0x9, 0x2b, 0x4, 
    0x2c, 0x9, 0x2c, 0x4, 0x2d, 0x9, 0x2d, 0x4, 0x2e, 0x9, 0x2e, 0x4, 0x2f, 
    0x9, 0x2f, 0x4, 0x30, 0x9, 0x30, 0x4, 0x31, 0x9, 0x31, 0x4, 0x32, 0x9, 
    0x32, 0x4, 0x33, 0x9, 0x33, 0x4, 0x34, 0x9, 0x34, 0x4, 0x35, 0x9, 0x35, 
    0x4, 0x36, 0x9, 0x36, 0x4, 0x37, 0x9, 0x37, 0x4, 0x38, 0x9, 0x38, 0x4, 
    0x39, 0x9, 0x39, 0x4, 0x3a, 0x9, 0x3a, 0x4, 0x3b, 0x9, 0x3b, 0x4, 0x3c, 
    0x9, 0x3c, 0x4, 0x3d, 0x9, 0x3d, 0x4, 0x3e, 0x9, 0x3e, 0x4, 0x3f, 0x9, 
    0x3f, 0x4, 0x40, 0x9, 0x40, 0x4, 0x41, 0x9, 0x41, 0x4, 0x42, 0x9, 0x42, 
    0x4, 0x43, 0x9, 0x43, 0x4, 0x44, 0x9, 0x44, 0x4, 0x45, 0x9, 0x45, 0x4, 
    0x46, 0x9, 0x46, 0x4, 0x47, 0x9, 0x47, 0x4, 0x48, 0x9, 0x48, 0x4, 0x49, 
    0x9, 0x49, 0x4, 0x4a, 0x9, 0x4a, 0x4, 0x4b, 0x9, 0x4b, 0x4, 0x4c, 0x9, 
    0x4c, 0x4, 0x4d, 0x9, 0x4d, 0x4, 0x4e, 0x9, 0x4e, 0x4, 0x4f, 0x9, 0x4f, 
    0x3, 0x2, 0x5, 0x2, 0xa0, 0xa, 0x2, 0x3, 0x2, 0x5, 0x2, 0xa3, 0xa, 0x2, 
    0x3, 0x2, 0x3, 0x2, 0x3, 0x3, 0x6, 0x3, 0xa8, 0xa, 0x3, 0xd, 0x3, 0xe, 
    0x3, 0xa9, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 
    0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 
    0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 
    0x5, 0x4, 0xc0, 0xa, 0x4, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x6, 0x3, 
    0x6, 0x5, 0x6, 0xc7, 0xa, 0x6, 0x3, 0x7, 0x3, 0x7, 0x3, 0x8, 0x3, 0x8, 
    0x3, 0x9, 0x3, 0x9, 0x3, 0xa, 0x3, 0xa, 0x3, 0xb, 0x3, 0xb, 0x3, 0xc, 
    0x3, 0xc, 0x3, 0xd, 0x3, 0xd, 0x5, 0xd, 0xd7, 0xa, 0xd, 0x3, 0xd, 0x3, 
    0xd, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xf, 0x5, 0xf, 0xdf, 0xa, 0xf, 
    0x3, 0xf, 0x3, 0xf, 0x5, 0xf, 0xe3, 0xa, 0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 
    0xf, 0x3, 0xf, 0x3, 0xf, 0x5, 0xf, 0xea, 0xa, 0xf, 0x3, 0x10, 0x3, 0x10, 
    0x3, 0x10, 0x3, 0x10, 0x7, 0x10, 0xf0, 0xa, 0x10, 0xc, 0x10, 0xe, 0x10, 
    0xf3, 0xb, 0x10, 0x3, 0x10, 0x3, 0x10, 0x5, 0x10, 0xf7, 0xa, 0x10, 0x5, 
    0x10, 0xf9, 0xa, 0x10, 0x3, 0x10, 0x3, 0x10, 0x3, 0x11, 0x3, 0x11, 0x3, 
    0x11, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x5, 0x12, 0x103, 0xa, 0x12, 
    0x3, 0x13, 0x3, 0x13, 0x3, 0x13, 0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 0x5, 
    0x14, 0x10b, 0xa, 0x14, 0x3, 0x15, 0x3, 0x15, 0x3, 0x15, 0x5, 0x15, 
    0x110, 0xa, 0x15, 0x3, 0x15, 0x3, 0x15, 0x3, 0x15, 0x3, 0x15, 0x3, 0x15, 
    0x3, 0x15, 0x3, 0x15, 0x5, 0x15, 0x119, 0xa, 0x15, 0x3, 0x16, 0x3, 0x16, 
    0x3, 0x16, 0x3, 0x16, 0x3, 0x16, 0x3, 0x16, 0x5, 0x16, 0x121, 0xa, 0x16, 
    0x3, 0x16, 0x3, 0x16, 0x5, 0x16, 0x125, 0xa, 0x16, 0x3, 0x17, 0x3, 0x17, 
    0x3, 0x17, 0x5, 0x17, 0x12a, 0xa, 0x17, 0x3, 0x18, 0x3, 0x18, 0x3, 0x18, 
    0x3, 0x18, 0x3, 0x19, 0x3, 0x19, 0x3, 0x19, 0x7, 0x19, 0x133, 0xa, 0x19, 
    0xc, 0x19, 0xe, 0x19, 0x136, 0xb, 0x19, 0x3, 0x1a, 0x3, 0x1a, 0x5, 0x1a, 
    0x13a, 0xa, 0x1a, 0x3, 0x1a, 0x3, 0x1a, 0x5, 0x1a, 0x13e, 0xa, 0x1a, 
    0x3, 0x1b, 0x3, 0x1b, 0x3, 0x1c, 0x3, 0x1c, 0x3, 0x1c, 0x3, 0x1d, 0x3, 
    0x1d, 0x3, 0x1d, 0x3, 0x1d, 0x3, 0x1d, 0x3, 0x1d, 0x3, 0x1d, 0x5, 0x1d, 
    0x14c, 0xa, 0x1d, 0x3, 0x1e, 0x3, 0x1e, 0x3, 0x1e, 0x3, 0x1e, 0x3, 0x1e, 
    0x3, 0x1e, 0x3, 0x1e, 0x3, 0x1e, 0x3, 0x1e, 0x3, 0x1e, 0x3, 0x1e, 0x3, 
    0x1e, 0x3, 0x1e, 0x3, 0x1e, 0x3, 0x1e, 0x3, 0x1e, 0x3, 0x1e, 0x3, 0x1e, 
    0x5, 0x1e, 0x160, 0xa, 0x1e, 0x3, 0x1e, 0x3, 0x1e, 0x5, 0x1e, 0x164, 
    0xa, 0x1e, 0x3, 0x1e, 0x3, 0x1e, 0x3, 0x1e, 0x3, 0x1e, 0x3, 0x1e, 0x3, 
    0x1e, 0x3, 0x1e, 0x5, 0x1e, 0x16d, 0xa, 0x1e, 0x3, 0x1e, 0x3, 0x1e, 
    0x3, 0x1e, 0x3, 0x1e, 0x3, 0x1e, 0x3, 0x1e, 0x3, 0x1e, 0x5, 0x1e, 0x176, 
    0xa, 0x1e, 0x3, 0x1e, 0x3, 0x1e, 0x3, 0x1e, 0x5, 0x1e, 0x17b, 0xa, 0x1e, 
    0x3, 0x1e, 0x3, 0x1e, 0x3, 0x1e, 0x3, 0x1e, 0x3, 0x1e, 0x3, 0x1e, 0x5, 
    0x1e, 0x183, 0xa, 0x1e, 0x3, 0x1f, 0x5, 0x1f, 0x186, 0xa, 0x1f, 0x3, 
    0x1f, 0x3, 0x1f, 0x5, 0x1f, 0x18a, 0xa, 0x1f, 0x3, 0x20, 0x3, 0x20, 
    0x3, 0x21, 0x3, 0x21, 0x3, 0x22, 0x3, 0x22, 0x5, 0x22, 0x192, 0xa, 0x22, 
    0x3, 0x22, 0x3, 0x22, 0x3, 0x23, 0x3, 0x23, 0x5, 0x23, 0x198, 0xa, 0x23, 
    0x3, 0x23, 0x3, 0x23, 0x3, 0x24, 0x3, 0x24, 0x5, 0x24, 0x19e, 0xa, 0x24, 
    0x3, 0x24, 0x3, 0x24, 0x3, 0x25, 0x3, 0x25, 0x5, 0x25, 0x1a4, 0xa, 0x25, 
    0x3, 0x25, 0x3, 0x25, 0x3, 0x26, 0x3, 0x26, 0x3, 0x26, 0x3, 0x26, 0x3, 
    0x26, 0x3, 0x26, 0x3, 0x27, 0x3, 0x27, 0x3, 0x27, 0x3, 0x27, 0x3, 0x27, 
    0x3, 0x27, 0x3, 0x28, 0x3, 0x28, 0x7, 0x28, 0x1b6, 0xa, 0x28, 0xc, 0x28, 
    0xe, 0x28, 0x1b9, 0xb, 0x28, 0x3, 0x28, 0x3, 0x28, 0x3, 0x29, 0x3, 0x29, 
    0x3, 0x29, 0x5, 0x29, 0x1c0, 0xa, 0x29, 0x3, 0x29, 0x3, 0x29, 0x3, 0x29, 
    0x3, 0x29, 0x5, 0x29, 0x1c6, 0xa, 0x29, 0x5, 0x29, 0x1c8, 0xa, 0x29, 
    0x3, 0x2a, 0x3, 0x2a, 0x3, 0x2a, 0x3, 0x2a, 0x3, 0x2b, 0x3, 0x2b, 0x3, 
    0x2b, 0x3, 0x2b, 0x3, 0x2c, 0x3, 0x2c, 0x3, 0x2c, 0x3, 0x2c, 0x5, 0x2c, 
    0x1d6, 0xa, 0x2c, 0x3, 0x2c, 0x5, 0x2c, 0x1d9, 0xa, 0x2c, 0x3, 0x2d, 
    0x3, 0x2d, 0x3, 0x2d, 0x5, 0x2d, 0x1de, 0xa, 0x2d, 0x3, 0x2d, 0x5, 0x2d, 
    0x1e1, 0xa, 0x2d, 0x3, 0x2d, 0x3, 0x2d, 0x3, 0x2e, 0x3, 0x2e, 0x3, 0x2e, 
    0x3, 0x2f, 0x3, 0x2f, 0x3, 0x2f, 0x3, 0x30, 0x5, 0x30, 0x1ec, 0xa, 0x30, 
    0x3, 0x30, 0x3, 0x30, 0x5, 0x30, 0x1f0, 0xa, 0x30, 0x3, 0x30, 0x3, 0x30, 
    0x3, 0x30, 0x5, 0x30, 0x1f5, 0xa, 0x30, 0x3, 0x30, 0x3, 0x30, 0x5, 0x30, 
    0x1f9, 0xa, 0x30, 0x3, 0x30, 0x3, 0x30, 0x3, 0x30, 0x3, 0x30, 0x3, 0x31, 
    0x7, 0x31, 0x200, 0xa, 0x31, 0xc, 0x31, 0xe, 0x31, 0x203, 0xb, 0x31, 
    0x3, 0x31, 0x3, 0x31, 0x3, 0x31, 0x3, 0x31, 0x3, 0x32, 0x3, 0x32, 0x5, 
    0x32, 0x20b, 0xa, 0x32, 0x3, 0x32, 0x3, 0x32, 0x7, 0x32, 0x20f, 0xa, 
    0x32, 0xc, 0x32, 0xe, 0x32, 0x212, 0xb, 0x32, 0x3, 0x32, 0x3, 0x32, 
    0x3, 0x33, 0x5, 0x33, 0x217, 0xa, 0x33, 0x3, 0x33, 0x5, 0x33, 0x21a, 
    0xa, 0x33, 0x3, 0x33, 0x3, 0x33, 0x3, 0x33, 0x5, 0x33, 0x21f, 0xa, 0x33, 
    0x3, 0x33, 0x3, 0x33, 0x3, 0x33, 0x3, 0x33, 0x3, 0x33, 0x3, 0x33, 0x5, 
    0x33, 0x227, 0xa, 0x33, 0x3, 0x33, 0x7, 0x33, 0x22a, 0xa, 0x33, 0xc, 
    0x33, 0xe, 0x33, 0x22d, 0xb, 0x33, 0x3, 0x33, 0x5, 0x33, 0x230, 0xa, 
    0x33, 0x3, 0x33, 0x3, 0x33, 0x3, 0x33, 0x5, 0x33, 0x235, 0xa, 0x33, 
    0x3, 0x33, 0x3, 0x33, 0x5, 0x33, 0x239, 0xa, 0x33, 0x3, 0x33, 0x3, 0x33, 
    0x3, 0x33, 0x3, 0x33, 0x3, 0x33, 0x5, 0x33, 0x240, 0xa, 0x33, 0x3, 0x33, 
    0x7, 0x33, 0x243, 0xa, 0x33, 0xc, 0x33, 0xe, 0x33, 0x246, 0xb, 0x33, 
    0x3, 0x33, 0x3, 0x33, 0x3, 0x33, 0x3, 0x33, 0x5, 0x33, 0x24c, 0xa, 0x33, 
    0x3, 0x33, 0x3, 0x33, 0x3, 0x33, 0x3, 0x33, 0x3, 0x33, 0x5, 0x33, 0x253, 
    0xa, 0x33, 0x3, 0x33, 0x7, 0x33, 0x256, 0xa, 0x33, 0xc, 0x33, 0xe, 0x33, 
    0x259, 0xb, 0x33, 0x3, 0x33, 0x3, 0x33, 0x3, 0x33, 0x5, 0x33, 0x25e, 
    0xa, 0x33, 0x3, 0x33, 0x3, 0x33, 0x3, 0x33, 0x3, 0x33, 0x3, 0x33, 0x3, 
    0x33, 0x5, 0x33, 0x266, 0xa, 0x33, 0x3, 0x33, 0x7, 0x33, 0x269, 0xa, 
    0x33, 0xc, 0x33, 0xe, 0x33, 0x26c, 0xb, 0x33, 0x3, 0x33, 0x3, 0x33, 
    0x5, 0x33, 0x270, 0xa, 0x33, 0x3, 0x33, 0x3, 0x33, 0x5, 0x33, 0x274, 
    0xa, 0x33, 0x3, 0x33, 0x5, 0x33, 0x277, 0xa, 0x33, 0x3, 0x34, 0x3, 0x34, 
    0x3, 0x34, 0x7, 0x34, 0x27c, 0xa, 0x34, 0xc, 0x34, 0xe, 0x34, 0x27f, 
    0xb, 0x34, 0x3, 0x34, 0x3, 0x34, 0x5, 0x34, 0x283, 0xa, 0x34, 0x3, 0x34, 
    0x5, 0x34, 0x286, 0xa, 0x34, 0x3, 0x35, 0x3, 0x35, 0x5, 0x35, 0x28a, 
    0xa, 0x35, 0x3, 0x35, 0x3, 0x35, 0x5, 0x35, 0x28e, 0xa, 0x35, 0x3, 0x36, 
    0x3, 0x36, 0x3, 0x36, 0x3, 0x37, 0x5, 0x37, 0x294, 0xa, 0x37, 0x3, 0x38, 
    0x3, 0x38, 0x3, 0x38, 0x3, 0x38, 0x3, 0x39, 0x7, 0x39, 0x29b, 0xa, 0x39, 
    0xc, 0x39, 0xe, 0x39, 0x29e, 0xb, 0x39, 0x3, 0x39, 0x5, 0x39, 0x2a1, 
    0xa, 0x39, 0x3, 0x39, 0x6, 0x39, 0x2a4, 0xa, 0x39, 0xd, 0x39, 0xe, 0x39, 
    0x2a5, 0x3, 0x39, 0x7, 0x39, 0x2a9, 0xa, 0x39, 0xc, 0x39, 0xe, 0x39, 
    0x2ac, 0xb, 0x39, 0x3, 0x39, 0x7, 0x39, 0x2af, 0xa, 0x39, 0xc, 0x39, 
    0xe, 0x39, 0x2b2, 0xb, 0x39, 0x3, 0x3a, 0x5, 0x3a, 0x2b5, 0xa, 0x3a, 
    0x3, 0x3a, 0x3, 0x3a, 0x3, 0x3b, 0x3, 0x3b, 0x3, 0x3b, 0x3, 0x3b, 0x7, 
    0x3b, 0x2bd, 0xa, 0x3b, 0xc, 0x3b, 0xe, 0x3b, 0x2c0, 0xb, 0x3b, 0x5, 
    0x3b, 0x2c2, 0xa, 0x3b, 0x3, 0x3b, 0x5, 0x3b, 0x2c5, 0xa, 0x3b, 0x3, 
    0x3b, 0x3, 0x3b, 0x3, 0x3c, 0x3, 0x3c, 0x5, 0x3c, 0x2cb, 0xa, 0x3c, 
    0x3, 0x3c, 0x3, 0x3c, 0x3, 0x3c, 0x3, 0x3c, 0x3, 0x3c, 0x3, 0x3c, 0x3, 
    0x3c, 0x3, 0x3c, 0x3, 0x3c, 0x3, 0x3c, 0x5, 0x3c, 0x2d7, 0xa, 0x3c, 
    0x3, 0x3c, 0x5, 0x3c, 0x2da, 0xa, 0x3c, 0x3, 0x3c, 0x3, 0x3c, 0x5, 0x3c, 
    0x2de, 0xa, 0x3c, 0x3, 0x3c, 0x3, 0x3c, 0x5, 0x3c, 0x2e2, 0xa, 0x3c, 
    0x3, 0x3c, 0x3, 0x3c, 0x3, 0x3c, 0x3, 0x3c, 0x3, 0x3c, 0x3, 0x3c, 0x3, 
    0x3c, 0x3, 0x3c, 0x3, 0x3c, 0x3, 0x3c, 0x3, 0x3c, 0x3, 0x3c, 0x3, 0x3c, 
    0x3, 0x3c, 0x3, 0x3c, 0x3, 0x3c, 0x3, 0x3c, 0x3, 0x3c, 0x3, 0x3c, 0x3, 
    0x3c, 0x3, 0x3c, 0x5, 0x3c, 0x2f9, 0xa, 0x3c, 0x3, 0x3c, 0x5, 0x3c, 
    0x2fc, 0xa, 0x3c, 0x3, 0x3d, 0x3, 0x3d, 0x3, 0x3d, 0x3, 0x3d, 0x3, 0x3d, 
    0x3, 0x3d, 0x3, 0x3d, 0x5, 0x3d, 0x305, 0xa, 0x3d, 0x3, 0x3e, 0x3, 0x3e, 
    0x3, 0x3e, 0x3, 0x3e, 0x7, 0x3e, 0x30b, 0xa, 0x3e, 0xc, 0x3e, 0xe, 0x3e, 
    0x30e, 0xb, 0x3e, 0x3, 0x3e, 0x5, 0x3e, 0x311, 0xa, 0x3e, 0x5, 0x3e, 
    0x313, 0xa, 0x3e, 0x3, 0x3e, 0x3, 0x3e, 0x3, 0x3f, 0x5, 0x3f, 0x318, 
    0xa, 0x3f, 0x3, 0x3f, 0x3, 0x3f, 0x5, 0x3f, 0x31c, 0xa, 0x3f, 0x3, 0x40, 
    0x3, 0x40, 0x3, 0x40, 0x7, 0x40, 0x321, 0xa, 0x40, 0xc, 0x40, 0xe, 0x40, 
    0x324, 0xb, 0x40, 0x3, 0x41, 0x3, 0x41, 0x3, 0x41, 0x3, 0x41, 0x5, 0x41, 
    0x32a, 0xa, 0x41, 0x3, 0x41, 0x3, 0x41, 0x3, 0x41, 0x3, 0x41, 0x3, 0x41, 
    0x3, 0x41, 0x3, 0x41, 0x3, 0x41, 0x3, 0x41, 0x3, 0x41, 0x3, 0x41, 0x3, 
    0x41, 0x3, 0x41, 0x3, 0x41, 0x3, 0x41, 0x3, 0x41, 0x3, 0x41, 0x3, 0x41, 
    0x3, 0x41, 0x3, 0x41, 0x3, 0x41, 0x3, 0x41, 0x3, 0x41, 0x3, 0x41, 0x3, 
    0x41, 0x3, 0x41, 0x3, 0x41, 0x3, 0x41, 0x3, 0x41, 0x3, 0x41, 0x3, 0x41, 
    0x3, 0x41, 0x3, 0x41, 0x3, 0x41, 0x3, 0x41, 0x3, 0x41, 0x3, 0x41, 0x3, 
    0x41, 0x3, 0x41, 0x3, 0x41, 0x3, 0x41, 0x3, 0x41, 0x3, 0x41, 0x3, 0x41, 
    0x5, 0x41, 0x358, 0xa, 0x41, 0x3, 0x41, 0x3, 0x41, 0x3, 0x41, 0x3, 0x41, 
    0x3, 0x41, 0x3, 0x41, 0x3, 0x41, 0x3, 0x41, 0x3, 0x41, 0x3, 0x41, 0x3, 
    0x41, 0x3, 0x41, 0x3, 0x41, 0x3, 0x41, 0x3, 0x41, 0x3, 0x41, 0x3, 0x41, 
    0x3, 0x41, 0x3, 0x41, 0x3, 0x41, 0x3, 0x41, 0x3, 0x41, 0x3, 0x41, 0x3, 
    0x41, 0x3, 0x41, 0x3, 0x41, 0x3, 0x41, 0x3, 0x41, 0x3, 0x41, 0x3, 0x41, 
    0x3, 0x41, 0x3, 0x41, 0x3, 0x41, 0x3, 0x41, 0x3, 0x41, 0x3, 0x41, 0x3, 
    0x41, 0x3, 0x41, 0x3, 0x41, 0x3, 0x41, 0x3, 0x41, 0x3, 0x41, 0x3, 0x41, 
    0x3, 0x41, 0x3, 0x41, 0x3, 0x41, 0x3, 0x41, 0x3, 0x41, 0x3, 0x41, 0x3, 
    0x41, 0x3, 0x41, 0x3, 0x41, 0x3, 0x41, 0x3, 0x41, 0x3, 0x41, 0x3, 0x41, 
    0x3, 0x41, 0x3, 0x41, 0x3, 0x41, 0x3, 0x41, 0x3, 0x41, 0x3, 0x41, 0x5, 
    0x41, 0x398, 0xa, 0x41, 0x3, 0x41, 0x3, 0x41, 0x5, 0x41, 0x39c, 0xa, 
    0x41, 0x3, 0x41, 0x3, 0x41, 0x3, 0x41, 0x3, 0x41, 0x3, 0x41, 0x3, 0x41, 
    0x3, 0x41, 0x3, 0x41, 0x3, 0x41, 0x7, 0x41, 0x3a7, 0xa, 0x41, 0xc, 0x41, 
    0xe, 0x41, 0x3aa, 0xb, 0x41, 0x3, 0x42, 0x3, 0x42, 0x3, 0x42, 0x5, 0x42, 
    0x3af, 0xa, 0x42, 0x3, 0x43, 0x3, 0x43, 0x5, 0x43, 0x3b3, 0xa, 0x43, 
    0x3, 0x43, 0x3, 0x43, 0x5, 0x43, 0x3b7, 0xa, 0x43, 0x3, 0x43, 0x3, 0x43, 
    0x5, 0x43, 0x3bb, 0xa, 0x43, 0x3, 0x43, 0x3, 0x43, 0x3, 0x43, 0x3, 0x43, 
    0x3, 0x43, 0x3, 0x43, 0x5, 0x43, 0x3c3, 0xa, 0x43, 0x3, 0x43, 0x3, 0x43, 
    0x3, 0x43, 0x3, 0x43, 0x5, 0x43, 0x3c9, 0xa, 0x43, 0x3, 0x44, 0x3, 0x44, 
    0x3, 0x44, 0x5, 0x44, 0x3ce, 0xa, 0x44, 0x3, 0x44, 0x5, 0x44, 0x3d1, 
    0xa, 0x44, 0x3, 0x45, 0x3, 0x45, 0x3, 0x45, 0x3, 0x45, 0x3, 0x45, 0x5, 
    0x45, 0x3d8, 0xa, 0x45, 0x3, 0x46, 0x3, 0x46, 0x3, 0x47, 0x3, 0x47, 
    0x3, 0x47, 0x3, 0x47, 0x3, 0x47, 0x3, 0x47, 0x3, 0x47, 0x5, 0x47, 0x3e3, 
    0xa, 0x47, 0x3, 0x48, 0x3, 0x48, 0x3, 0x49, 0x3, 0x49, 0x3, 0x4a, 0x3, 
    0x4a, 0x5, 0x4a, 0x3eb, 0xa, 0x4a, 0x3, 0x4b, 0x3, 0x4b, 0x3, 0x4b, 
    0x5, 0x4b, 0x3f0, 0xa, 0x4b, 0x3, 0x4c, 0x3, 0x4c, 0x3, 0x4d, 0x3, 0x4d, 
    0x3, 0x4d, 0x3, 0x4e, 0x3, 0x4e, 0x3, 0x4e, 0x3, 0x4f, 0x3, 0x4f, 0x3, 
    0x4f, 0x2, 0x3, 0x80, 0x50, 0x2, 0x4, 0x6, 0x8, 0xa, 0xc, 0xe, 0x10, 
    0x12, 0x14, 0x16, 0x18, 0x1a, 0x1c, 0x1e, 0x20, 0x22, 0x24, 0x26, 0x28, 
    0x2a, 0x2c, 0x2e, 0x30, 0x32, 0x34, 0x36, 0x38, 0x3a, 0x3c, 0x3e, 0x40, 
    0x42, 0x44, 0x46, 0x48, 0x4a, 0x4c, 0x4e, 0x50, 0x52, 0x54, 0x56, 0x58, 
    0x5a, 0x5c, 0x5e, 0x60, 0x62, 0x64, 0x66, 0x68, 0x6a, 0x6c, 0x6e, 0x70, 
    0x72, 0x74, 0x76, 0x78, 0x7a, 0x7c, 0x7e, 0x80, 0x82, 0x84, 0x86, 0x88, 
    0x8a, 0x8c, 0x8e, 0x90, 0x92, 0x94, 0x96, 0x98, 0x9a, 0x9c, 0x2, 0x12, 
    0x3, 0x2, 0x40, 0x48, 0x4, 0x2, 0x7a, 0x7b, 0x7e, 0x7e, 0x3, 0x2, 0x7f, 
    0x80, 0x4, 0x2, 0x51, 0x51, 0x7f, 0x7f, 0x4, 0x2, 0x7f, 0x80, 0x85, 
    0x85, 0x5, 0x2, 0x59, 0x59, 0x73, 0x73, 0x79, 0x79, 0x3, 0x2, 0x1a, 
    0x1c, 0x3, 0x2, 0x16, 0x17, 0x3, 0x2, 0x20, 0x22, 0x3, 0x2, 0x23, 0x26, 
    0x3, 0x2, 0x27, 0x2a, 0x3, 0x2, 0x30, 0x3b, 0x4, 0x2, 0x3f, 0x3f, 0x49, 
    0x4c, 0x3, 0x2, 0x4d, 0x50, 0x5, 0x2, 0x52, 0x6e, 0x70, 0x7f, 0x81, 
    0x81, 0x3, 0x3, 0xd, 0xd, 0x2, 0x473, 0x2, 0x9f, 0x3, 0x2, 0x2, 0x2, 
    0x4, 0xa7, 0x3, 0x2, 0x2, 0x2, 0x6, 0xbf, 0x3, 0x2, 0x2, 0x2, 0x8, 0xc1, 
    0x3, 0x2, 0x2, 0x2, 0xa, 0xc6, 0x3, 0x2, 0x2, 0x2, 0xc, 0xc8, 0x3, 0x2, 
    0x2, 0x2, 0xe, 0xca, 0x3, 0x2, 0x2, 0x2, 0x10, 0xcc, 0x3, 0x2, 0x2, 
    0x2, 0x12, 0xce, 0x3, 0x2, 0x2, 0x2, 0x14, 0xd0, 0x3, 0x2, 0x2, 0x2, 
    0x16, 0xd2, 0x3, 0x2, 0x2, 0x2, 0x18, 0xd4, 0x3, 0x2, 0x2, 0x2, 0x1a, 
    0xda, 0x3, 0x2, 0x2, 0x2, 0x1c, 0xe9, 0x3, 0x2, 0x2, 0x2, 0x1e, 0xeb, 
    0x3, 0x2, 0x2, 0x2, 0x20, 0xfc, 0x3, 0x2, 0x2, 0x2, 0x22, 0xff, 0x3, 
    0x2, 0x2, 0x2, 0x24, 0x104, 0x3, 0x2, 0x2, 0x2, 0x26, 0x107, 0x3, 0x2, 
    0x2, 0x2, 0x28, 0x118, 0x3, 0x2, 0x2, 0x2, 0x2a, 0x124, 0x3, 0x2, 0x2, 
    0x2, 0x2c, 0x129, 0x3, 0x2, 0x2, 0x2, 0x2e, 0x12b, 0x3, 0x2, 0x2, 0x2, 
    0x30, 0x12f, 0x3, 0x2, 0x2, 0x2, 0x32, 0x137, 0x3, 0x2, 0x2, 0x2, 0x34, 
    0x13f, 0x3, 0x2, 0x2, 0x2, 0x36, 0x141, 0x3, 0x2, 0x2, 0x2, 0x38, 0x144, 
    0x3, 0x2, 0x2, 0x2, 0x3a, 0x182, 0x3, 0x2, 0x2, 0x2, 0x3c, 0x189, 0x3, 
    0x2, 0x2, 0x2, 0x3e, 0x18b, 0x3, 0x2, 0x2, 0x2, 0x40, 0x18d, 0x3, 0x2, 
    0x2, 0x2, 0x42, 0x18f, 0x3, 0x2, 0x2, 0x2, 0x44, 0x195, 0x3, 0x2, 0x2, 
    0x2, 0x46, 0x19b, 0x3, 0x2, 0x2, 0x2, 0x48, 0x1a1, 0x3, 0x2, 0x2, 0x2, 
    0x4a, 0x1a7, 0x3, 0x2, 0x2, 0x2, 0x4c, 0x1ad, 0x3, 0x2, 0x2, 0x2, 0x4e, 
    0x1b3, 0x3, 0x2, 0x2, 0x2, 0x50, 0x1c7, 0x3, 0x2, 0x2, 0x2, 0x52, 0x1c9, 
    0x3, 0x2, 0x2, 0x2, 0x54, 0x1cd, 0x3, 0x2, 0x2, 0x2, 0x56, 0x1d1, 0x3, 
    0x2, 0x2, 0x2, 0x58, 0x1da, 0x3, 0x2, 0x2, 0x2, 0x5a, 0x1e4, 0x3, 0x2, 
    0x2, 0x2, 0x5c, 0x1e7, 0x3, 0x2, 0x2, 0x2, 0x5e, 0x1eb, 0x3, 0x2, 0x2, 
    0x2, 0x60, 0x201, 0x3, 0x2, 0x2, 0x2, 0x62, 0x20a, 0x3, 0x2, 0x2, 0x2, 
    0x64, 0x276, 0x3, 0x2, 0x2, 0x2, 0x66, 0x285, 0x3, 0x2, 0x2, 0x2, 0x68, 
    0x287, 0x3, 0x2, 0x2, 0x2, 0x6a, 0x28f, 0x3, 0x2, 0x2, 0x2, 0x6c, 0x293, 
    0x3, 0x2, 0x2, 0x2, 0x6e, 0x295, 0x3, 0x2, 0x2, 0x2, 0x70, 0x29c, 0x3, 
    0x2, 0x2, 0x2, 0x72, 0x2b4, 0x3, 0x2, 0x2, 0x2, 0x74, 0x2b8, 0x3, 0x2, 
    0x2, 0x2, 0x76, 0x2fb, 0x3, 0x2, 0x2, 0x2, 0x78, 0x304, 0x3, 0x2, 0x2, 
    0x2, 0x7a, 0x306, 0x3, 0x2, 0x2, 0x2, 0x7c, 0x317, 0x3, 0x2, 0x2, 0x2, 
    0x7e, 0x31d, 0x3, 0x2, 0x2, 0x2, 0x80, 0x357, 0x3, 0x2, 0x2, 0x2, 0x82, 
    0x3ae, 0x3, 0x2, 0x2, 0x2, 0x84, 0x3c8, 0x3, 0x2, 0x2, 0x2, 0x86, 0x3d0, 
    0x3, 0x2, 0x2, 0x2, 0x88, 0x3d7, 0x3, 0x2, 0x2, 0x2, 0x8a, 0x3d9, 0x3, 
    0x2, 0x2, 0x2, 0x8c, 0x3e2, 0x3, 0x2, 0x2, 0x2, 0x8e, 0x3e4, 0x3, 0x2, 
    0x2, 0x2, 0x90, 0x3e6, 0x3, 0x2, 0x2, 0x2, 0x92, 0x3ea, 0x3, 0x2, 0x2, 
    0x2, 0x94, 0x3ef, 0x3, 0x2, 0x2, 0x2, 0x96, 0x3f1, 0x3, 0x2, 0x2, 0x2, 
    0x98, 0x3f3, 0x3, 0x2, 0x2, 0x2, 0x9a, 0x3f6, 0x3, 0x2, 0x2, 0x2, 0x9c, 
    0x3f9, 0x3, 0x2, 0x2, 0x2, 0x9e, 0xa0, 0x7, 0x3, 0x2, 0x2, 0x9f, 0x9e, 
    0x3, 0x2, 0x2, 0x2, 0x9f, 0xa0, 0x3, 0x2, 0x2, 0x2, 0xa0, 0xa2, 0x3, 
    0x2, 0x2, 0x2, 0xa1, 0xa3, 0x5, 0x4, 0x3, 0x2, 0xa2, 0xa1, 0x3, 0x2, 
    0x2, 0x2, 0xa2, 0xa3, 0x3, 0x2, 0x2, 0x2, 0xa3, 0xa4, 0x3, 0x2, 0x2, 
    0x2, 0xa4, 0xa5, 0x7, 0x2, 0x2, 0x3, 0xa5, 0x3, 0x3, 0x2, 0x2, 0x2, 
    0xa6, 0xa8, 0x5, 0x6, 0x4, 0x2, 0xa7, 0xa6, 0x3, 0x2, 0x2, 0x2, 0xa8, 
    0xa9, 0x3, 0x2, 0x2, 0x2, 0xa9, 0xa7, 0x3, 0x2, 0x2, 0x2, 0xa9, 0xaa, 
    0x3, 0x2, 0x2, 0x2, 0xaa, 0x5, 0x3, 0x2, 0x2, 0x2, 0xab, 0xc0, 0x5, 
    0x18, 0xd, 0x2, 0xac, 0xc0, 0x5, 0x2e, 0x18, 0x2, 0xad, 0xc0, 0x5, 0x1a, 
    0xe, 0x2, 0xae, 0xc0, 0x5, 0x28, 0x15, 0x2, 0xaf, 0xc0, 0x5, 0x34, 0x1b, 
    0x2, 0xb0, 0xc0, 0x5, 0x60, 0x31, 0x2, 0xb1, 0xc0, 0x5, 0x36, 0x1c, 
    0x2, 0xb2, 0xc0, 0x5, 0x38, 0x1d, 0x2, 0xb3, 0xc0, 0x5, 0x3a, 0x1e, 
    0x2, 0xb4, 0xc0, 0x5, 0x42, 0x22, 0x2, 0xb5, 0xc0, 0x5, 0x44, 0x23, 
    0x2, 0xb6, 0xc0, 0x5, 0x46, 0x24, 0x2, 0xb7, 0xc0, 0x5, 0x48, 0x25, 
    0x2, 0xb8, 0xc0, 0x5, 0x4a, 0x26, 0x2, 0xb9, 0xc0, 0x5, 0x52, 0x2a, 
    0x2, 0xba, 0xc0, 0x5, 0x4c, 0x27, 0x2, 0xbb, 0xc0, 0x5, 0x54, 0x2b, 
    0x2, 0xbc, 0xc0, 0x5, 0x56, 0x2c, 0x2, 0xbd, 0xc0, 0x5, 0x5c, 0x2f, 
    0x2, 0xbe, 0xc0, 0x5, 0x5e, 0x30, 0x2, 0xbf, 0xab, 0x3, 0x2, 0x2, 0x2, 
    0xbf, 0xac, 0x3, 0x2, 0x2, 0x2, 0xbf, 0xad, 0x3, 0x2, 0x2, 0x2, 0xbf, 
    0xae, 0x3, 0x2, 0x2, 0x2, 0xbf, 0xaf, 0x3, 0x2, 0x2, 0x2, 0xbf, 0xb0, 
    0x3, 0x2, 0x2, 0x2, 0xbf, 0xb1, 0x3, 0x2, 0x2, 0x2, 0xbf, 0xb2, 0x3, 
    0x2, 0x2, 0x2, 0xbf, 0xb3, 0x3, 0x2, 0x2, 0x2, 0xbf, 0xb4, 0x3, 0x2, 
    0x2, 0x2, 0xbf, 0xb5, 0x3, 0x2, 0x2, 0x2, 0xbf, 0xb6, 0x3, 0x2, 0x2, 
    0x2, 0xbf, 0xb7, 0x3, 0x2, 0x2, 0x2, 0xbf, 0xb8, 0x3, 0x2, 0x2, 0x2, 
    0xbf, 0xb9, 0x3, 0x2, 0x2, 0x2, 0xbf, 0xba, 0x3, 0x2, 0x2, 0x2, 0xbf, 
    0xbb, 0x3, 0x2, 0x2, 0x2, 0xbf, 0xbc, 0x3, 0x2, 0x2, 0x2, 0xbf, 0xbd, 
    0x3, 0x2, 0x2, 0x2, 0xbf, 0xbe, 0x3, 0x2, 0x2, 0x2, 0xc0, 0x7, 0x3, 
    0x2, 0x2, 0x2, 0xc1, 0xc2, 0x7, 0x11, 0x2, 0x2, 0xc2, 0xc3, 0x5, 0xa, 
    0x6, 0x2, 0xc3, 0x9, 0x3, 0x2, 0x2, 0x2, 0xc4, 0xc7, 0x5, 0xc, 0x7, 
    0x2, 0xc5, 0xc7, 0x5, 0xe, 0x8, 0x2, 0xc6, 0xc4, 0x3, 0x2, 0x2, 0x2, 
    0xc6, 0xc5, 0x3, 0x2, 0x2, 0x2, 0xc7, 0xb, 0x3, 0x2, 0x2, 0x2, 0xc8, 
    0xc9, 0x9, 0x2, 0x2, 0x2, 0xc9, 0xd, 0x3, 0x2, 0x2, 0x2, 0xca, 0xcb, 
    0x7, 0x85, 0x2, 0x2, 0xcb, 0xf, 0x3, 0x2, 0x2, 0x2, 0xcc, 0xcd, 0x9, 
    0x3, 0x2, 0x2, 0xcd, 0x11, 0x3, 0x2, 0x2, 0x2, 0xce, 0xcf, 0x9, 0x4, 
    0x2, 0x2, 0xcf, 0x13, 0x3, 0x2, 0x2, 0x2, 0xd0, 0xd1, 0x9, 0x5, 0x2, 
    0x2, 0xd1, 0x15, 0x3, 0x2, 0x2, 0x2, 0xd2, 0xd3, 0x9, 0x6, 0x2, 0x2, 
    0xd3, 0x17, 0x3, 0x2, 0x2, 0x2, 0xd4, 0xd6, 0x7, 0xb, 0x2, 0x2, 0xd5, 
    0xd7, 0x5, 0x4, 0x3, 0x2, 0xd6, 0xd5, 0x3, 0x2, 0x2, 0x2, 0xd6, 0xd7, 
    0x3, 0x2, 0x2, 0x2, 0xd7, 0xd8, 0x3, 0x2, 0x2, 0x2, 0xd8, 0xd9, 0x7, 
    0xc, 0x2, 0x2, 0xd9, 0x19, 0x3, 0x2, 0x2, 0x2, 0xda, 0xdb, 0x7, 0x75, 
    0x2, 0x2, 0xdb, 0xdc, 0x5, 0x1c, 0xf, 0x2, 0xdc, 0x1b, 0x3, 0x2, 0x2, 
    0x2, 0xdd, 0xdf, 0x5, 0x20, 0x11, 0x2, 0xde, 0xdd, 0x3, 0x2, 0x2, 0x2, 
    0xde, 0xdf, 0x3, 0x2, 0x2, 0x2, 0xdf, 0xe2, 0x3, 0x2, 0x2, 0x2, 0xe0, 
    0xe3, 0x5, 0x22, 0x12, 0x2, 0xe1, 0xe3, 0x5, 0x1e, 0x10, 0x2, 0xe2, 
    0xe0, 0x3, 0x2, 0x2, 0x2, 0xe2, 0xe1, 0x3, 0x2, 0x2, 0x2, 0xe3, 0xe4, 
    0x3, 0x2, 0x2, 0x2, 0xe4, 0xe5, 0x5, 0x24, 0x13, 0x2, 0xe5, 0xe6, 0x5, 
    0x9c, 0x4f, 0x2, 0xe6, 0xea, 0x3, 0x2, 0x2, 0x2, 0xe7, 0xe8, 0x7, 0x86, 
    0x2, 0x2, 0xe8, 0xea, 0x5, 0x9c, 0x4f, 0x2, 0xe9, 0xde, 0x3, 0x2, 0x2, 
    0x2, 0xe9, 0xe7, 0x3, 0x2, 0x2, 0x2, 0xea, 0x1d, 0x3, 0x2, 0x2, 0x2, 
    0xeb, 0xf1, 0x7, 0xb, 0x2, 0x2, 0xec, 0xed, 0x5, 0x26, 0x14, 0x2, 0xed, 
    0xee, 0x7, 0xe, 0x2, 0x2, 0xee, 0xf0, 0x3, 0x2, 0x2, 0x2, 0xef, 0xec, 
    0x3, 0x2, 0x2, 0x2, 0xf0, 0xf3, 0x3, 0x2, 0x2, 0x2, 0xf1, 0xef, 0x3, 
    0x2, 0x2, 0x2, 0xf1, 0xf2, 0x3, 0x2, 0x2, 0x2, 0xf2, 0xf8, 0x3, 0x2, 
    0x2, 0x2, 0xf3, 0xf1, 0x3, 0x2, 0x2, 0x2, 0xf4, 0xf6, 0x5, 0x26, 0x14, 
    0x2, 0xf5, 0xf7, 0x7, 0xe, 0x2, 0x2, 0xf6, 0xf5, 0x3, 0x2, 0x2, 0x2, 
    0xf6, 0xf7, 0x3, 0x2, 0x2, 0x2, 0xf7, 0xf9, 0x3, 0x2, 0x2, 0x2, 0xf8, 
    0xf4, 0x3, 0x2, 0x2, 0x2, 0xf8, 0xf9, 0x3, 0x2, 0x2, 0x2, 0xf9, 0xfa, 
    0x3, 0x2, 0x2, 0x2, 0xfa, 0xfb, 0x7, 0xc, 0x2, 0x2, 0xfb, 0x1f, 0x3, 
    0x2, 0x2, 0x2, 0xfc, 0xfd, 0x5, 0x26, 0x14, 0x2, 0xfd, 0xfe, 0x7, 0xe, 
    0x2, 0x2, 0xfe, 0x21, 0x3, 0x2, 0x2, 0x2, 0xff, 0x102, 0x7, 0x1a, 0x2, 
    0x2, 0x100, 0x101, 0x7, 0x6c, 0x2, 0x2, 0x101, 0x103, 0x5, 0x92, 0x4a, 
    0x2, 0x102, 0x100, 0x3, 0x2, 0x2, 0x2, 0x102, 0x103, 0x3, 0x2, 0x2, 
    0x2, 0x103, 0x23, 0x3, 0x2, 0x2, 0x2, 0x104, 0x105, 0x7, 0x6d, 0x2, 
    0x2, 0x105, 0x106, 0x7, 0x86, 0x2, 0x2, 0x106, 0x25, 0x3, 0x2, 0x2, 
    0x2, 0x107, 0x10a, 0x5, 0x92, 0x4a, 0x2, 0x108, 0x109, 0x7, 0x6c, 0x2, 
    0x2, 0x109, 0x10b, 0x5, 0x92, 0x4a, 0x2, 0x10a, 0x108, 0x3, 0x2, 0x2, 
    0x2, 0x10a, 0x10b, 0x3, 0x2, 0x2, 0x2, 0x10b, 0x27, 0x3, 0x2, 0x2, 0x2, 
    0x10c, 0x10f, 0x7, 0x74, 0x2, 0x2, 0x10d, 0x110, 0x5, 0x2a, 0x16, 0x2, 
    0x10e, 0x110, 0x5, 0x2c, 0x17, 0x2, 0x10f, 0x10d, 0x3, 0x2, 0x2, 0x2, 
    0x10f, 0x10e, 0x3, 0x2, 0x2, 0x2, 0x110, 0x111, 0x3, 0x2, 0x2, 0x2, 
    0x111, 0x112, 0x5, 0x9c, 0x4f, 0x2, 0x112, 0x119, 0x3, 0x2, 0x2, 0x2, 
    0x113, 0x114, 0x7, 0x74, 0x2, 0x2, 0x114, 0x115, 0x7, 0x66, 0x2, 0x2, 
    0x115, 0x116, 0x5, 0x80, 0x41, 0x2, 0x116, 0x117, 0x5, 0x9c, 0x4f, 0x2, 
    0x117, 0x119, 0x3, 0x2, 0x2, 0x2, 0x118, 0x10c, 0x3, 0x2, 0x2, 0x2, 
    0x118, 0x113, 0x3, 0x2, 0x2, 0x2, 0x119, 0x29, 0x3, 0x2, 0x2, 0x2, 0x11a, 
    0x11b, 0x5, 0x22, 0x12, 0x2, 0x11b, 0x11c, 0x5, 0x24, 0x13, 0x2, 0x11c, 
    0x11d, 0x5, 0x9c, 0x4f, 0x2, 0x11d, 0x125, 0x3, 0x2, 0x2, 0x2, 0x11e, 
    0x120, 0x5, 0x1e, 0x10, 0x2, 0x11f, 0x121, 0x5, 0x24, 0x13, 0x2, 0x120, 
    0x11f, 0x3, 0x2, 0x2, 0x2, 0x120, 0x121, 0x3, 0x2, 0x2, 0x2, 0x121, 
    0x122, 0x3, 0x2, 0x2, 0x2, 0x122, 0x123, 0x5, 0x9c, 0x4f, 0x2, 0x123, 
    0x125, 0x3, 0x2, 0x2, 0x2, 0x124, 0x11a, 0x3, 0x2, 0x2, 0x2, 0x124, 
    0x11e, 0x3, 0x2, 0x2, 0x2, 0x125, 0x2b, 0x3, 0x2, 0x2, 0x2, 0x126, 0x12a, 
    0x5, 0x2e, 0x18, 0x2, 0x127, 0x12a, 0x5, 0x60, 0x31, 0x2, 0x128, 0x12a, 
    0x5, 0x5e, 0x30, 0x2, 0x129, 0x126, 0x3, 0x2, 0x2, 0x2, 0x129, 0x127, 
    0x3, 0x2, 0x2, 0x2, 0x129, 0x128, 0x3, 0x2, 0x2, 0x2, 0x12a, 0x2d, 0x3, 
    0x2, 0x2, 0x2, 0x12b, 0x12c, 0x5, 0x40, 0x21, 0x2, 0x12c, 0x12d, 0x5, 
    0x30, 0x19, 0x2, 0x12d, 0x12e, 0x5, 0x9c, 0x4f, 0x2, 0x12e, 0x2f, 0x3, 
    0x2, 0x2, 0x2, 0x12f, 0x134, 0x5, 0x32, 0x1a, 0x2, 0x130, 0x131, 0x7, 
    0xe, 0x2, 0x2, 0x131, 0x133, 0x5, 0x32, 0x1a, 0x2, 0x132, 0x130, 0x3, 
    0x2, 0x2, 0x2, 0x133, 0x136, 0x3, 0x2, 0x2, 0x2, 0x134, 0x132, 0x3, 
    0x2, 0x2, 0x2, 0x134, 0x135, 0x3, 0x2, 0x2, 0x2, 0x135, 0x31, 0x3, 0x2, 
    0x2, 0x2, 0x136, 0x134, 0x3, 0x2, 0x2, 0x2, 0x137, 0x139, 0x5, 0x82, 
    0x42, 0x2, 0x138, 0x13a, 0x5, 0x8, 0x5, 0x2, 0x139, 0x138, 0x3, 0x2, 
    0x2, 0x2, 0x139, 0x13a, 0x3, 0x2, 0x2, 0x2, 0x13a, 0x13d, 0x3, 0x2, 
    0x2, 0x2, 0x13b, 0x13c, 0x7, 0xf, 0x2, 0x2, 0x13c, 0x13e, 0x5, 0x80, 
    0x41, 0x2, 0x13d, 0x13b, 0x3, 0x2, 0x2, 0x2, 0x13d, 0x13e, 0x3, 0x2, 
    0x2, 0x2, 0x13e, 0x33, 0x3, 0x2, 0x2, 0x2, 0x13f, 0x140, 0x7, 0xd, 0x2, 
    0x2, 0x140, 0x35, 0x3, 0x2, 0x2, 0x2, 0x141, 0x142, 0x5, 0x7e, 0x40, 
    0x2, 0x142, 0x143, 0x5, 0x9c, 0x4f, 0x2, 0x143, 0x37, 0x3, 0x2, 0x2, 
    0x2, 0x144, 0x145, 0x7, 0x67, 0x2, 0x2, 0x145, 0x146, 0x7, 0x9, 0x2, 
    0x2, 0x146, 0x147, 0x5, 0x7e, 0x40, 0x2, 0x147, 0x148, 0x7, 0xa, 0x2, 
    0x2, 0x148, 0x14b, 0x5, 0x6, 0x4, 0x2, 0x149, 0x14a, 0x7, 0x57, 0x2, 
    0x2, 0x14a, 0x14c, 0x5, 0x6, 0x4, 0x2, 0x14b, 0x149, 0x3, 0x2, 0x2, 
    0x2, 0x14b, 0x14c, 0x3, 0x2, 0x2, 0x2, 0x14c, 0x39, 0x3, 0x2, 0x2, 0x2, 
    0x14d, 0x14e, 0x7, 0x53, 0x2, 0x2, 0x14e, 0x14f, 0x5, 0x6, 0x4, 0x2, 
    0x14f, 0x150, 0x7, 0x61, 0x2, 0x2, 0x150, 0x151, 0x7, 0x9, 0x2, 0x2, 
    0x151, 0x152, 0x5, 0x7e, 0x40, 0x2, 0x152, 0x153, 0x7, 0xa, 0x2, 0x2, 
    0x153, 0x154, 0x5, 0x9c, 0x4f, 0x2, 0x154, 0x183, 0x3, 0x2, 0x2, 0x2, 
    0x155, 0x156, 0x7, 0x61, 0x2, 0x2, 0x156, 0x157, 0x7, 0x9, 0x2, 0x2, 
    0x157, 0x158, 0x5, 0x7e, 0x40, 0x2, 0x158, 0x159, 0x7, 0xa, 0x2, 0x2, 
    0x159, 0x15a, 0x5, 0x6, 0x4, 0x2, 0x15a, 0x183, 0x3, 0x2, 0x2, 0x2, 
    0x15b, 0x15c, 0x7, 0x5f, 0x2, 0x2, 0x15c, 0x15d, 0x7, 0x9, 0x2, 0x2, 
    0x15d, 0x15f, 0x5, 0x3c, 0x1f, 0x2, 0x15e, 0x160, 0x5, 0x3e, 0x20, 0x2, 
    0x15f, 0x15e, 0x3, 0x2, 0x2, 0x2, 0x15f, 0x160, 0x3, 0x2, 0x2, 0x2, 
    0x160, 0x161, 0x3, 0x2, 0x2, 0x2, 0x161, 0x163, 0x7, 0xd, 0x2, 0x2, 
    0x162, 0x164, 0x5, 0x7e, 0x40, 0x2, 0x163, 0x162, 0x3, 0x2, 0x2, 0x2, 
    0x163, 0x164, 0x3, 0x2, 0x2, 0x2, 0x164, 0x165, 0x3, 0x2, 0x2, 0x2, 
    0x165, 0x166, 0x7, 0xa, 0x2, 0x2, 0x166, 0x167, 0x5, 0x6, 0x4, 0x2, 
    0x167, 0x183, 0x3, 0x2, 0x2, 0x2, 0x168, 0x169, 0x7, 0x5f, 0x2, 0x2, 
    0x169, 0x16c, 0x7, 0x9, 0x2, 0x2, 0x16a, 0x16d, 0x5, 0x80, 0x41, 0x2, 
    0x16b, 0x16d, 0x5, 0x2e, 0x18, 0x2, 0x16c, 0x16a, 0x3, 0x2, 0x2, 0x2, 
    0x16c, 0x16b, 0x3, 0x2, 0x2, 0x2, 0x16d, 0x16e, 0x3, 0x2, 0x2, 0x2, 
    0x16e, 0x16f, 0x7, 0x6a, 0x2, 0x2, 0x16f, 0x170, 0x5, 0x7e, 0x40, 0x2, 
    0x170, 0x171, 0x7, 0xa, 0x2, 0x2, 0x171, 0x172, 0x5, 0x6, 0x4, 0x2, 
    0x172, 0x183, 0x3, 0x2, 0x2, 0x2, 0x173, 0x175, 0x7, 0x5f, 0x2, 0x2, 
    0x174, 0x176, 0x7, 0x77, 0x2, 0x2, 0x175, 0x174, 0x3, 0x2, 0x2, 0x2, 
    0x175, 0x176, 0x3, 0x2, 0x2, 0x2, 0x176, 0x177, 0x3, 0x2, 0x2, 0x2, 
    0x177, 0x17a, 0x7, 0x9, 0x2, 0x2, 0x178, 0x17b, 0x5, 0x80, 0x41, 0x2, 
    0x179, 0x17b, 0x5, 0x2e, 0x18, 0x2, 0x17a, 0x178, 0x3, 0x2, 0x2, 0x2, 
    0x17a, 0x179, 0x3, 0x2, 0x2, 0x2, 0x17b, 0x17c, 0x3, 0x2, 0x2, 0x2, 
    0x17c, 0x17d, 0x7, 0x84, 0x2, 0x2, 0x17d, 0x17e, 0x7, 0x85, 0x2, 0x2, 
    0x17e, 0x17f, 0x5, 0x7e, 0x40, 0x2, 0x17f, 0x180, 0x7, 0xa, 0x2, 0x2, 
    0x180, 0x181, 0x5, 0x6, 0x4, 0x2, 0x181, 0x183, 0x3, 0x2, 0x2, 0x2, 
    0x182, 0x14d, 0x3, 0x2, 0x2, 0x2, 0x182, 0x155, 0x3, 0x2, 0x2, 0x2, 
    0x182, 0x15b, 0x3, 0x2, 0x2, 0x2, 0x182, 0x168, 0x3, 0x2, 0x2, 0x2, 
    0x182, 0x173, 0x3, 0x2, 0x2, 0x2, 0x183, 0x3b, 0x3, 0x2, 0x2, 0x2, 0x184, 
    0x186, 0x5, 0x7e, 0x40, 0x2, 0x185, 0x184, 0x3, 0x2, 0x2, 0x2, 0x185, 
    0x186, 0x3, 0x2, 0x2, 0x2, 0x186, 0x187, 0x3, 0x2, 0x2, 0x2, 0x187, 
    0x18a, 0x7, 0xd, 0x2, 0x2, 0x188, 0x18a, 0x5, 0x2e, 0x18, 0x2, 0x189, 
    0x185, 0x3, 0x2, 0x2, 0x2, 0x189, 0x188, 0x3, 0x2, 0x2, 0x2, 0x18a, 
    0x3d, 0x3, 0x2, 0x2, 0x2, 0x18b, 0x18c, 0x5, 0x7e, 0x40, 0x2, 0x18c, 
    0x3f, 0x3, 0x2, 0x2, 0x2, 0x18d, 0x18e, 0x9, 0x7, 0x2, 0x2, 0x18e, 0x41, 
    0x3, 0x2, 0x2, 0x2, 0x18f, 0x191, 0x7, 0x5e, 0x2, 0x2, 0x190, 0x192, 
    0x7, 0x85, 0x2, 0x2, 0x191, 0x190, 0x3, 0x2, 0x2, 0x2, 0x191, 0x192, 
    0x3, 0x2, 0x2, 0x2, 0x192, 0x193, 0x3, 0x2, 0x2, 0x2, 0x193, 0x194, 
    0x5, 0x9c, 0x4f, 0x2, 0x194, 0x43, 0x3, 0x2, 0x2, 0x2, 0x195, 0x197, 
    0x7, 0x52, 0x2, 0x2, 0x196, 0x198, 0x7, 0x85, 0x2, 0x2, 0x197, 0x196, 
    0x3, 0x2, 0x2, 0x2, 0x197, 0x198, 0x3, 0x2, 0x2, 0x2, 0x198, 0x199, 
    0x3, 0x2, 0x2, 0x2, 0x199, 0x19a, 0x5, 0x9c, 0x4f, 0x2, 0x19a, 0x45, 
    0x3, 0x2, 0x2, 0x2, 0x19b, 0x19d, 0x7, 0x5c, 0x2, 0x2, 0x19c, 0x19e, 
    0x5, 0x7e, 0x40, 0x2, 0x19d, 0x19c, 0x3, 0x2, 0x2, 0x2, 0x19d, 0x19e, 
    0x3, 0x2, 0x2, 0x2, 0x19e, 0x19f, 0x3, 0x2, 0x2, 0x2, 0x19f, 0x1a0, 
    0x5, 0x9c, 0x4f, 0x2, 0x1a0, 0x47, 0x3, 0x2, 0x2, 0x2, 0x1a1, 0x1a3, 
    0x7, 0x81, 0x2, 0x2, 0x1a2, 0x1a4, 0x5, 0x7e, 0x40, 0x2, 0x1a3, 0x1a2, 
    0x3, 0x2, 0x2, 0x2, 0x1a3, 0x1a4, 0x3, 0x2, 0x2, 0x2, 0x1a4, 0x1a5, 
    0x3, 0x2, 0x2, 0x2, 0x1a5, 0x1a6, 0x5, 0x9c, 0x4f, 0x2, 0x1a6, 0x49, 
    0x3, 0x2, 0x2, 0x2, 0x1a7, 0x1a8, 0x7, 0x65, 0x2, 0x2, 0x1a8, 0x1a9, 
    0x7, 0x9, 0x2, 0x2, 0x1a9, 0x1aa, 0x5, 0x7e, 0x40, 0x2, 0x1aa, 0x1ab, 
    0x7, 0xa, 0x2, 0x2, 0x1ab, 0x1ac, 0x5, 0x6, 0x4, 0x2, 0x1ac, 0x4b, 0x3, 
    0x2, 0x2, 0x2, 0x1ad, 0x1ae, 0x7, 0x60, 0x2, 0x2, 0x1ae, 0x1af, 0x7, 
    0x9, 0x2, 0x2, 0x1af, 0x1b0, 0x5, 0x7e, 0x40, 0x2, 0x1b0, 0x1b1, 0x7, 
    0xa, 0x2, 0x2, 0x1b1, 0x1b2, 0x5, 0x4e, 0x28, 0x2, 0x1b2, 0x4d, 0x3, 
    0x2, 0x2, 0x2, 0x1b3, 0x1b7, 0x7, 0xb, 0x2, 0x2, 0x1b4, 0x1b6, 0x5, 
    0x50, 0x29, 0x2, 0x1b5, 0x1b4, 0x3, 0x2, 0x2, 0x2, 0x1b6, 0x1b9, 0x3, 
    0x2, 0x2, 0x2, 0x1b7, 0x1b5, 0x3, 0x2, 0x2, 0x2, 0x1b7, 0x1b8, 0x3, 
    0x2, 0x2, 0x2, 0x1b8, 0x1ba, 0x3, 0x2, 0x2, 0x2, 0x1b9, 0x1b7, 0x3, 
    0x2, 0x2, 0x2, 0x1ba, 0x1bb, 0x7, 0xc, 0x2, 0x2, 0x1bb, 0x4f, 0x3, 0x2, 
    0x2, 0x2, 0x1bc, 0x1bd, 0x7, 0x66, 0x2, 0x2, 0x1bd, 0x1bf, 0x7, 0x11, 
    0x2, 0x2, 0x1be, 0x1c0, 0x5, 0x4, 0x3, 0x2, 0x1bf, 0x1be, 0x3, 0x2, 
    0x2, 0x2, 0x1bf, 0x1c0, 0x3, 0x2, 0x2, 0x2, 0x1c0, 0x1c8, 0x3, 0x2, 
    0x2, 0x2, 0x1c1, 0x1c2, 0x7, 0x56, 0x2, 0x2, 0x1c2, 0x1c3, 0x5, 0x7e, 
    0x40, 0x2, 0x1c3, 0x1c5, 0x7, 0x11, 0x2, 0x2, 0x1c4, 0x1c6, 0x5, 0x4, 
    0x3, 0x2, 0x1c5, 0x1c4, 0x3, 0x2, 0x2, 0x2, 0x1c5, 0x1c6, 0x3, 0x2, 
    0x2, 0x2, 0x1c6, 0x1c8, 0x3, 0x2, 0x2, 0x2, 0x1c7, 0x1bc, 0x3, 0x2, 
    0x2, 0x2, 0x1c7, 0x1c1, 0x3, 0x2, 0x2, 0x2, 0x1c8, 0x51, 0x3, 0x2, 0x2, 
    0x2, 0x1c9, 0x1ca, 0x7, 0x85, 0x2, 0x2, 0x1ca, 0x1cb, 0x7, 0x11, 0x2, 
    0x2, 0x1cb, 0x1cc, 0x5, 0x6, 0x4, 0x2, 0x1cc, 0x53, 0x3, 0x2, 0x2, 0x2, 
    0x1cd, 0x1ce, 0x7, 0x68, 0x2, 0x2, 0x1ce, 0x1cf, 0x5, 0x7e, 0x40, 0x2, 
    0x1cf, 0x1d0, 0x5, 0x9c, 0x4f, 0x2, 0x1d0, 0x55, 0x3, 0x2, 0x2, 0x2, 
    0x1d1, 0x1d2, 0x7, 0x6b, 0x2, 0x2, 0x1d2, 0x1d8, 0x5, 0x18, 0xd, 0x2, 
    0x1d3, 0x1d5, 0x5, 0x58, 0x2d, 0x2, 0x1d4, 0x1d6, 0x5, 0x5a, 0x2e, 0x2, 
    0x1d5, 0x1d4, 0x3, 0x2, 0x2, 0x2, 0x1d5, 0x1d6, 0x3, 0x2, 0x2, 0x2, 
    0x1d6, 0x1d9, 0x3, 0x2, 0x2, 0x2, 0x1d7, 0x1d9, 0x5, 0x5a, 0x2e, 0x2, 
    0x1d8, 0x1d3, 0x3, 0x2, 0x2, 0x2, 0x1d8, 0x1d7, 0x3, 0x2, 0x2, 0x2, 
    0x1d9, 0x57, 0x3, 0x2, 0x2, 0x2, 0x1da, 0x1e0, 0x7, 0x5a, 0x2, 0x2, 
    0x1db, 0x1dd, 0x7, 0x9, 0x2, 0x2, 0x1dc, 0x1de, 0x5, 0x82, 0x42, 0x2, 
    0x1dd, 0x1dc, 0x3, 0x2, 0x2, 0x2, 0x1dd, 0x1de, 0x3, 0x2, 0x2, 0x2, 
    0x1de, 0x1df, 0x3, 0x2, 0x2, 0x2, 0x1df, 0x1e1, 0x7, 0xa, 0x2, 0x2, 
    0x1e0, 0x1db, 0x3, 0x2, 0x2, 0x2, 0x1e0, 0x1e1, 0x3, 0x2, 0x2, 0x2, 
    0x1e1, 0x1e2, 0x3, 0x2, 0x2, 0x2, 0x1e2, 0x1e3, 0x5, 0x18, 0xd, 0x2, 
    0x1e3, 0x59, 0x3, 0x2, 0x2, 0x2, 0x1e4, 0x1e5, 0x7, 0x5b, 0x2, 0x2, 
    0x1e5, 0x1e6, 0x5, 0x18, 0xd, 0x2, 0x1e6, 0x5b, 0x3, 0x2, 0x2, 0x2, 
    0x1e7, 0x1e8, 0x7, 0x62, 0x2, 0x2, 0x1e8, 0x1e9, 0x5, 0x9c, 0x4f, 0x2, 
    0x1e9, 0x5d, 0x3, 0x2, 0x2, 0x2, 0x1ea, 0x1ec, 0x7, 0x76, 0x2, 0x2, 
    0x1eb, 0x1ea, 0x3, 0x2, 0x2, 0x2, 0x1eb, 0x1ec, 0x3, 0x2, 0x2, 0x2, 
    0x1ec, 0x1ed, 0x3, 0x2, 0x2, 0x2, 0x1ed, 0x1ef, 0x7, 0x63, 0x2, 0x2, 
    0x1ee, 0x1f0, 0x7, 0x1a, 0x2, 0x2, 0x1ef, 0x1ee, 0x3, 0x2, 0x2, 0x2, 
    0x1ef, 0x1f0, 0x3, 0x2, 0x2, 0x2, 0x1f0, 0x1f1, 0x3, 0x2, 0x2, 0x2, 
    0x1f1, 0x1f2, 0x7, 0x85, 0x2, 0x2, 0x1f2, 0x1f4, 0x7, 0x9, 0x2, 0x2, 
    0x1f3, 0x1f5, 0x5, 0x66, 0x34, 0x2, 0x1f4, 0x1f3, 0x3, 0x2, 0x2, 0x2, 
    0x1f4, 0x1f5, 0x3, 0x2, 0x2, 0x2, 0x1f5, 0x1f6, 0x3, 0x2, 0x2, 0x2, 
    0x1f6, 0x1f8, 0x7, 0xa, 0x2, 0x2, 0x1f7, 0x1f9, 0x5, 0x8, 0x5, 0x2, 
    0x1f8, 0x1f7, 0x3, 0x2, 0x2, 0x2, 0x1f8, 0x1f9, 0x3, 0x2, 0x2, 0x2, 
    0x1f9, 0x1fa, 0x3, 0x2, 0x2, 0x2, 0x1fa, 0x1fb, 0x7, 0xb, 0x2, 0x2, 
    0x1fb, 0x1fc, 0x5, 0x6c, 0x37, 0x2, 0x1fc, 0x1fd, 0x7, 0xc, 0x2, 0x2, 
    0x1fd, 0x5f, 0x3, 0x2, 0x2, 0x2, 0x1fe, 0x200, 0x5, 0x12, 0xa, 0x2, 
    0x1ff, 0x1fe, 0x3, 0x2, 0x2, 0x2, 0x200, 0x203, 0x3, 0x2, 0x2, 0x2, 
    0x201, 0x1ff, 0x3, 0x2, 0x2, 0x2, 0x201, 0x202, 0x3, 0x2, 0x2, 0x2, 
    0x202, 0x204, 0x3, 0x2, 0x2, 0x2, 0x203, 0x201, 0x3, 0x2, 0x2, 0x2, 
    0x204, 0x205, 0x7, 0x6e, 0x2, 0x2, 0x205, 0x206, 0x7, 0x85, 0x2, 0x2, 
    0x206, 0x207, 0x5, 0x62, 0x32, 0x2, 0x207, 0x61, 0x3, 0x2, 0x2, 0x2, 
    0x208, 0x209, 0x7, 0x71, 0x2, 0x2, 0x209, 0x20b, 0x5, 0x80, 0x41, 0x2, 
    0x20a, 0x208, 0x3, 0x2, 0x2, 0x2, 0x20a, 0x20b, 0x3, 0x2, 0x2, 0x2, 
    0x20b, 0x20c, 0x3, 0x2, 0x2, 0x2, 0x20c, 0x210, 0x7, 0xb, 0x2, 0x2, 
    0x20d, 0x20f, 0x5, 0x64, 0x33, 0x2, 0x20e, 0x20d, 0x3, 0x2, 0x2, 0x2, 
    0x20f, 0x212, 0x3, 0x2, 0x2, 0x2, 0x210, 0x20e, 0x3, 0x2, 0x2, 0x2, 
    0x210, 0x211, 0x3, 0x2, 0x2, 0x2, 0x211, 0x213, 0x3, 0x2, 0x2, 0x2, 
    0x212, 0x210, 0x3, 0x2, 0x2, 0x2, 0x213, 0x214, 0x7, 0xc, 0x2, 0x2, 
    0x214, 0x63, 0x3, 0x2, 0x2, 0x2, 0x215, 0x217, 0x5, 0x10, 0x9, 0x2, 
    0x216, 0x215, 0x3, 0x2, 0x2, 0x2, 0x216, 0x217, 0x3, 0x2, 0x2, 0x2, 
    0x217, 0x219, 0x3, 0x2, 0x2, 0x2, 0x218, 0x21a, 0x7, 0x76, 0x2, 0x2, 
    0x219, 0x218, 0x3, 0x2, 0x2, 0x2, 0x219, 0x21a, 0x3, 0x2, 0x2, 0x2, 
    0x21a, 0x21b, 0x3, 0x2, 0x2, 0x2, 0x21b, 0x21c, 0x7, 0x6f, 0x2, 0x2, 
    0x21c, 0x21e, 0x7, 0x9, 0x2, 0x2, 0x21d, 0x21f, 0x5, 0x66, 0x34, 0x2, 
    0x21e, 0x21d, 0x3, 0x2, 0x2, 0x2, 0x21e, 0x21f, 0x3, 0x2, 0x2, 0x2, 
    0x21f, 0x220, 0x3, 0x2, 0x2, 0x2, 0x220, 0x221, 0x7, 0xa, 0x2, 0x2, 
    0x221, 0x222, 0x7, 0xb, 0x2, 0x2, 0x222, 0x223, 0x5, 0x6c, 0x37, 0x2, 
    0x223, 0x224, 0x7, 0xc, 0x2, 0x2, 0x224, 0x277, 0x3, 0x2, 0x2, 0x2, 
    0x225, 0x227, 0x5, 0x10, 0x9, 0x2, 0x226, 0x225, 0x3, 0x2, 0x2, 0x2, 
    0x226, 0x227, 0x3, 0x2, 0x2, 0x2, 0x227, 0x22b, 0x3, 0x2, 0x2, 0x2, 
    0x228, 0x22a, 0x5, 0x16, 0xc, 0x2, 0x229, 0x228, 0x3, 0x2, 0x2, 0x2, 
    0x22a, 0x22d, 0x3, 0x2, 0x2, 0x2, 0x22b, 0x229, 0x3, 0x2, 0x2, 0x2, 
    0x22b, 0x22c, 0x3, 0x2, 0x2, 0x2, 0x22c, 0x22f, 0x3, 0x2, 0x2, 0x2, 
    0x22d, 0x22b, 0x3, 0x2, 0x2, 0x2, 0x22e, 0x230, 0x7, 0x76, 0x2, 0x2, 
    0x22f, 0x22e, 0x3, 0x2, 0x2, 0x2, 0x22f, 0x230, 0x3, 0x2, 0x2, 0x2, 
    0x230, 0x231, 0x3, 0x2, 0x2, 0x2, 0x231, 0x232, 0x5, 0x78, 0x3d, 0x2, 
    0x232, 0x234, 0x7, 0x9, 0x2, 0x2, 0x233, 0x235, 0x5, 0x66, 0x34, 0x2, 
    0x234, 0x233, 0x3, 0x2, 0x2, 0x2, 0x234, 0x235, 0x3, 0x2, 0x2, 0x2, 
    0x235, 0x236, 0x3, 0x2, 0x2, 0x2, 0x236, 0x238, 0x7, 0xa, 0x2, 0x2, 
    0x237, 0x239, 0x5, 0x8, 0x5, 0x2, 0x238, 0x237, 0x3, 0x2, 0x2, 0x2, 
    0x238, 0x239, 0x3, 0x2, 0x2, 0x2, 0x239, 0x23a, 0x3, 0x2, 0x2, 0x2, 
    0x23a, 0x23b, 0x7, 0xb, 0x2, 0x2, 0x23b, 0x23c, 0x5, 0x6c, 0x37, 0x2, 
    0x23c, 0x23d, 0x7, 0xc, 0x2, 0x2, 0x23d, 0x277, 0x3, 0x2, 0x2, 0x2, 
    0x23e, 0x240, 0x5, 0x10, 0x9, 0x2, 0x23f, 0x23e, 0x3, 0x2, 0x2, 0x2, 
    0x23f, 0x240, 0x3, 0x2, 0x2, 0x2, 0x240, 0x244, 0x3, 0x2, 0x2, 0x2, 
    0x241, 0x243, 0x5, 0x16, 0xc, 0x2, 0x242, 0x241, 0x3, 0x2, 0x2, 0x2, 
    0x243, 0x246, 0x3, 0x2, 0x2, 0x2, 0x244, 0x242, 0x3, 0x2, 0x2, 0x2, 
    0x244, 0x245, 0x3, 0x2, 0x2, 0x2, 0x245, 0x247, 0x3, 0x2, 0x2, 0x2, 
    0x246, 0x244, 0x3, 0x2, 0x2, 0x2, 0x247, 0x248, 0x5, 0x98, 0x4d, 0x2, 
    0x248, 0x249, 0x7, 0x9, 0x2, 0x2, 0x249, 0x24b, 0x7, 0xa, 0x2, 0x2, 
    0x24a, 0x24c, 0x5, 0x8, 0x5, 0x2, 0x24b, 0x24a, 0x3, 0x2, 0x2, 0x2, 
    0x24b, 0x24c, 0x3, 0x2, 0x2, 0x2, 0x24c, 0x24d, 0x3, 0x2, 0x2, 0x2, 
    0x24d, 0x24e, 0x7, 0xb, 0x2, 0x2, 0x24e, 0x24f, 0x5, 0x6c, 0x37, 0x2, 
    0x24f, 0x250, 0x7, 0xc, 0x2, 0x2, 0x250, 0x277, 0x3, 0x2, 0x2, 0x2, 
    0x251, 0x253, 0x5, 0x10, 0x9, 0x2, 0x252, 0x251, 0x3, 0x2, 0x2, 0x2, 
    0x252, 0x253, 0x3, 0x2, 0x2, 0x2, 0x253, 0x257, 0x3, 0x2, 0x2, 0x2, 
    0x254, 0x256, 0x5, 0x16, 0xc, 0x2, 0x255, 0x254, 0x3, 0x2, 0x2, 0x2, 
    0x256, 0x259, 0x3, 0x2, 0x2, 0x2, 0x257, 0x255, 0x3, 0x2, 0x2, 0x2, 
    0x257, 0x258, 0x3, 0x2, 0x2, 0x2, 0x258, 0x25a, 0x3, 0x2, 0x2, 0x2, 
    0x259, 0x257, 0x3, 0x2, 0x2, 0x2, 0x25a, 0x25b, 0x5, 0x9a, 0x4e, 0x2, 
    0x25b, 0x25d, 0x7, 0x9, 0x2, 0x2, 0x25c, 0x25e, 0x5, 0x66, 0x34, 0x2, 
    0x25d, 0x25c, 0x3, 0x2, 0x2, 0x2, 0x25d, 0x25e, 0x3, 0x2, 0x2, 0x2, 
    0x25e, 0x25f, 0x3, 0x2, 0x2, 0x2, 0x25f, 0x260, 0x7, 0xa, 0x2, 0x2, 
    0x260, 0x261, 0x7, 0xb, 0x2, 0x2, 0x261, 0x262, 0x5, 0x6c, 0x37, 0x2, 
    0x262, 0x263, 0x7, 0xc, 0x2, 0x2, 0x263, 0x277, 0x3, 0x2, 0x2, 0x2, 
    0x264, 0x266, 0x5, 0x10, 0x9, 0x2, 0x265, 0x264, 0x3, 0x2, 0x2, 0x2, 
    0x265, 0x266, 0x3, 0x2, 0x2, 0x2, 0x266, 0x26a, 0x3, 0x2, 0x2, 0x2, 
    0x267, 0x269, 0x5, 0x14, 0xb, 0x2, 0x268, 0x267, 0x3, 0x2, 0x2, 0x2, 
    0x269, 0x26c, 0x3, 0x2, 0x2, 0x2, 0x26a, 0x268, 0x3, 0x2, 0x2, 0x2, 
    0x26a, 0x26b, 0x3, 0x2, 0x2, 0x2, 0x26b, 0x26d, 0x3, 0x2, 0x2, 0x2, 
    0x26c, 0x26a, 0x3, 0x2, 0x2, 0x2, 0x26d, 0x26f, 0x5, 0x78, 0x3d, 0x2, 
    0x26e, 0x270, 0x5, 0x8, 0x5, 0x2, 0x26f, 0x26e, 0x3, 0x2, 0x2, 0x2, 
    0x26f, 0x270, 0x3, 0x2, 0x2, 0x2, 0x270, 0x273, 0x3, 0x2, 0x2, 0x2, 
    0x271, 0x272, 0x7, 0xf, 0x2, 0x2, 0x272, 0x274, 0x5, 0x80, 0x41, 0x2, 
    0x273, 0x271, 0x3, 0x2, 0x2, 0x2, 0x273, 0x274, 0x3, 0x2, 0x2, 0x2, 
    0x274, 0x277, 0x3, 0x2, 0x2, 0x2, 0x275, 0x277, 0x5, 0x34, 0x1b, 0x2, 
    0x276, 0x216, 0x3, 0x2, 0x2, 0x2, 0x276, 0x226, 0x3, 0x2, 0x2, 0x2, 
    0x276, 0x23f, 0x3, 0x2, 0x2, 0x2, 0x276, 0x252, 0x3, 0x2, 0x2, 0x2, 
    0x276, 0x265, 0x3, 0x2, 0x2, 0x2, 0x276, 0x275, 0x3, 0x2, 0x2, 0x2, 
    0x277, 0x65, 0x3, 0x2, 0x2, 0x2, 0x278, 0x27d, 0x5, 0x68, 0x35, 0x2, 
    0x279, 0x27a, 0x7, 0xe, 0x2, 0x2, 0x27a, 0x27c, 0x5, 0x68, 0x35, 0x2, 
    0x27b, 0x279, 0x3, 0x2, 0x2, 0x2, 0x27c, 0x27f, 0x3, 0x2, 0x2, 0x2, 
    0x27d, 0x27b, 0x3, 0x2, 0x2, 0x2, 0x27d, 0x27e, 0x3, 0x2, 0x2, 0x2, 
    0x27e, 0x282, 0x3, 0x2, 0x2, 0x2, 0x27f, 0x27d, 0x3, 0x2, 0x2, 0x2, 
    0x280, 0x281, 0x7, 0xe, 0x2, 0x2, 0x281, 0x283, 0x5, 0x6a, 0x36, 0x2, 
    0x282, 0x280, 0x3, 0x2, 0x2, 0x2, 0x282, 0x283, 0x3, 0x2, 0x2, 0x2, 
    0x283, 0x286, 0x3, 0x2, 0x2, 0x2, 0x284, 0x286, 0x5, 0x6a, 0x36, 0x2, 
    0x285, 0x278, 0x3, 0x2, 0x2, 0x2, 0x285, 0x284, 0x3, 0x2, 0x2, 0x2, 
    0x286, 0x67, 0x3, 0x2, 0x2, 0x2, 0x287, 0x289, 0x5, 0x82, 0x42, 0x2, 
    0x288, 0x28a, 0x5, 0x8, 0x5, 0x2, 0x289, 0x288, 0x3, 0x2, 0x2, 0x2, 
    0x289, 0x28a, 0x3, 0x2, 0x2, 0x2, 0x28a, 0x28d, 0x3, 0x2, 0x2, 0x2, 
    0x28b, 0x28c, 0x7, 0xf, 0x2, 0x2, 0x28c, 0x28e, 0x5, 0x80, 0x41, 0x2, 
    0x28d, 0x28b, 0x3, 0x2, 0x2, 0x2, 0x28d, 0x28e, 0x3, 0x2, 0x2, 0x2, 
    0x28e, 0x69, 0x3, 0x2, 0x2, 0x2, 0x28f, 0x290, 0x7, 0x12, 0x2, 0x2, 
    0x290, 0x291, 0x5, 0x80, 0x41, 0x2, 0x291, 0x6b, 0x3, 0x2, 0x2, 0x2, 
    0x292, 0x294, 0x5, 0x4, 0x3, 0x2, 0x293, 0x292, 0x3, 0x2, 0x2, 0x2, 
    0x293, 0x294, 0x3, 0x2, 0x2, 0x2, 0x294, 0x6d, 0x3, 0x2, 0x2, 0x2, 0x295, 
    0x296, 0x7, 0x7, 0x2, 0x2, 0x296, 0x297, 0x5, 0x70, 0x39, 0x2, 0x297, 
    0x298, 0x7, 0x8, 0x2, 0x2, 0x298, 0x6f, 0x3, 0x2, 0x2, 0x2, 0x299, 0x29b, 
    0x7, 0xe, 0x2, 0x2, 0x29a, 0x299, 0x3, 0x2, 0x2, 0x2, 0x29b, 0x29e, 
    0x3, 0x2, 0x2, 0x2, 0x29c, 0x29a, 0x3, 0x2, 0x2, 0x2, 0x29c, 0x29d, 
    0x3, 0x2, 0x2, 0x2, 0x29d, 0x2a0, 0x3, 0x2, 0x2, 0x2, 0x29e, 0x29c, 
    0x3, 0x2, 0x2, 0x2, 0x29f, 0x2a1, 0x5, 0x72, 0x3a, 0x2, 0x2a0, 0x29f, 
    0x3, 0x2, 0x2, 0x2, 0x2a0, 0x2a1, 0x3, 0x2, 0x2, 0x2, 0x2a1, 0x2aa, 
    0x3, 0x2, 0x2, 0x2, 0x2a2, 0x2a4, 0x7, 0xe, 0x2, 0x2, 0x2a3, 0x2a2, 
    0x3, 0x2, 0x2, 0x2, 0x2a4, 0x2a5, 0x3, 0x2, 0x2, 0x2, 0x2a5, 0x2a3, 
    0x3, 0x2, 0x2, 0x2, 0x2a5, 0x2a6, 0x3, 0x2, 0x2, 0x2, 0x2a6, 0x2a7, 
    0x3, 0x2, 0x2, 0x2, 0x2a7, 0x2a9, 0x5, 0x72, 0x3a, 0x2, 0x2a8, 0x2a3, 
    0x3, 0x2, 0x2, 0x2, 0x2a9, 0x2ac, 0x3, 0x2, 0x2, 0x2, 0x2aa, 0x2a8, 
    0x3, 0x2, 0x2, 0x2, 0x2aa, 0x2ab, 0x3, 0x2, 0x2, 0x2, 0x2ab, 0x2b0, 
    0x3, 0x2, 0x2, 0x2, 0x2ac, 0x2aa, 0x3, 0x2, 0x2, 0x2, 0x2ad, 0x2af, 
    0x7, 0xe, 0x2, 0x2, 0x2ae, 0x2ad, 0x3, 0x2, 0x2, 0x2, 0x2af, 0x2b2, 
    0x3, 0x2, 0x2, 0x2, 0x2b0, 0x2ae, 0x3, 0x2, 0x2, 0x2, 0x2b0, 0x2b1, 
    0x3, 0x2, 0x2, 0x2, 0x2b1, 0x71, 0x3, 0x2, 0x2, 0x2, 0x2b2, 0x2b0, 0x3, 
    0x2, 0x2, 0x2, 0x2b3, 0x2b5, 0x7, 0x12, 0x2, 0x2, 0x2b4, 0x2b3, 0x3, 
    0x2, 0x2, 0x2, 0x2b4, 0x2b5, 0x3, 0x2, 0x2, 0x2, 0x2b5, 0x2b6, 0x3, 
    0x2, 0x2, 0x2, 0x2b6, 0x2b7, 0x5, 0x80, 0x41, 0x2, 0x2b7, 0x73, 0x3, 
    0x2, 0x2, 0x2, 0x2b8, 0x2c1, 0x7, 0xb, 0x2, 0x2, 0x2b9, 0x2be, 0x5, 
    0x76, 0x3c, 0x2, 0x2ba, 0x2bb, 0x7, 0xe, 0x2, 0x2, 0x2bb, 0x2bd, 0x5, 
    0x76, 0x3c, 0x2, 0x2bc, 0x2ba, 0x3, 0x2, 0x2, 0x2, 0x2bd, 0x2c0, 0x3, 
    0x2, 0x2, 0x2, 0x2be, 0x2bc, 0x3, 0x2, 0x2, 0x2, 0x2be, 0x2bf, 0x3, 
    0x2, 0x2, 0x2, 0x2bf, 0x2c2, 0x3, 0x2, 0x2, 0x2, 0x2c0, 0x2be, 0x3, 
    0x2, 0x2, 0x2, 0x2c1, 0x2b9, 0x3, 0x2, 0x2, 0x2, 0x2c1, 0x2c2, 0x3, 
    0x2, 0x2, 0x2, 0x2c2, 0x2c4, 0x3, 0x2, 0x2, 0x2, 0x2c3, 0x2c5, 0x7, 
    0xe, 0x2, 0x2, 0x2c4, 0x2c3, 0x3, 0x2, 0x2, 0x2, 0x2c4, 0x2c5, 0x3, 
    0x2, 0x2, 0x2, 0x2c5, 0x2c6, 0x3, 0x2, 0x2, 0x2, 0x2c6, 0x2c7, 0x7, 
    0xc, 0x2, 0x2, 0x2c7, 0x75, 0x3, 0x2, 0x2, 0x2, 0x2c8, 0x2ca, 0x5, 0x78, 
    0x3d, 0x2, 0x2c9, 0x2cb, 0x5, 0x8, 0x5, 0x2, 0x2ca, 0x2c9, 0x3, 0x2, 
    0x2, 0x2, 0x2ca, 0x2cb, 0x3, 0x2, 0x2, 0x2, 0x2cb, 0x2cc, 0x3, 0x2, 
    0x2, 0x2, 0x2cc, 0x2cd, 0x7, 0x11, 0x2, 0x2, 0x2cd, 0x2ce, 0x5, 0x80, 
    0x41, 0x2, 0x2ce, 0x2fc, 0x3, 0x2, 0x2, 0x2, 0x2cf, 0x2d0, 0x7, 0x7, 
    0x2, 0x2, 0x2d0, 0x2d1, 0x5, 0x80, 0x41, 0x2, 0x2d1, 0x2d2, 0x7, 0x8, 
    0x2, 0x2, 0x2d2, 0x2d3, 0x7, 0x11, 0x2, 0x2, 0x2d3, 0x2d4, 0x5, 0x80, 
    0x41, 0x2, 0x2d4, 0x2fc, 0x3, 0x2, 0x2, 0x2, 0x2d5, 0x2d7, 0x7, 0x76, 
    0x2, 0x2, 0x2d6, 0x2d5, 0x3, 0x2, 0x2, 0x2, 0x2d6, 0x2d7, 0x3, 0x2, 
    0x2, 0x2, 0x2d7, 0x2d9, 0x3, 0x2, 0x2, 0x2, 0x2d8, 0x2da, 0x7, 0x1a, 
    0x2, 0x2, 0x2d9, 0x2d8, 0x3, 0x2, 0x2, 0x2, 0x2d9, 0x2da, 0x3, 0x2, 
    0x2, 0x2, 0x2da, 0x2db, 0x3, 0x2, 0x2, 0x2, 0x2db, 0x2dd, 0x5, 0x78, 
    0x3d, 0x2, 0x2dc, 0x2de, 0x5, 0x8, 0x5, 0x2, 0x2dd, 0x2dc, 0x3, 0x2, 
    0x2, 0x2, 0x2dd, 0x2de, 0x3, 0x2, 0x2, 0x2, 0x2de, 0x2df, 0x3, 0x2, 
    0x2, 0x2, 0x2df, 0x2e1, 0x7, 0x9, 0x2, 0x2, 0x2e0, 0x2e2, 0x5, 0x66, 
    0x34, 0x2, 0x2e1, 0x2e0, 0x3, 0x2, 0x2, 0x2, 0x2e1, 0x2e2, 0x3, 0x2, 
    0x2, 0x2, 0x2e2, 0x2e3, 0x3, 0x2, 0x2, 0x2, 0x2e3, 0x2e4, 0x7, 0xa, 
    0x2, 0x2, 0x2e4, 0x2e5, 0x7, 0xb, 0x2, 0x2, 0x2e5, 0x2e6, 0x5, 0x6c, 
    0x37, 0x2, 0x2e6, 0x2e7, 0x7, 0xc, 0x2, 0x2, 0x2e7, 0x2fc, 0x3, 0x2, 
    0x2, 0x2, 0x2e8, 0x2e9, 0x5, 0x98, 0x4d, 0x2, 0x2e9, 0x2ea, 0x7, 0x9, 
    0x2, 0x2, 0x2ea, 0x2eb, 0x7, 0xa, 0x2, 0x2, 0x2eb, 0x2ec, 0x7, 0xb, 
    0x2, 0x2, 0x2ec, 0x2ed, 0x5, 0x6c, 0x37, 0x2, 0x2ed, 0x2ee, 0x7, 0xc, 
    0x2, 0x2, 0x2ee, 0x2fc, 0x3, 0x2, 0x2, 0x2, 0x2ef, 0x2f0, 0x5, 0x9a, 
    0x4e, 0x2, 0x2f0, 0x2f1, 0x7, 0x9, 0x2, 0x2, 0x2f1, 0x2f2, 0x5, 0x68, 
    0x35, 0x2, 0x2f2, 0x2f3, 0x7, 0xa, 0x2, 0x2, 0x2f3, 0x2f4, 0x7, 0xb, 
    0x2, 0x2, 0x2f4, 0x2f5, 0x5, 0x6c, 0x37, 0x2, 0x2f5, 0x2f6, 0x7, 0xc, 
    0x2, 0x2, 0x2f6, 0x2fc, 0x3, 0x2, 0x2, 0x2, 0x2f7, 0x2f9, 0x7, 0x12, 
    0x2, 0x2, 0x2f8, 0x2f7, 0x3, 0x2, 0x2, 0x2, 0x2f8, 0x2f9, 0x3, 0x2, 
    0x2, 0x2, 0x2f9, 0x2fa, 0x3, 0x2, 0x2, 0x2, 0x2fa, 0x2fc, 0x5, 0x80, 
    0x41, 0x2, 0x2fb, 0x2c8, 0x3, 0x2, 0x2, 0x2, 0x2fb, 0x2cf, 0x3, 0x2, 
    0x2, 0x2, 0x2fb, 0x2d6, 0x3, 0x2, 0x2, 0x2, 0x2fb, 0x2e8, 0x3, 0x2, 
    0x2, 0x2, 0x2fb, 0x2ef, 0x3, 0x2, 0x2, 0x2, 0x2fb, 0x2f8, 0x3, 0x2, 
    0x2, 0x2, 0x2fc, 0x77, 0x3, 0x2, 0x2, 0x2, 0x2fd, 0x305, 0x5, 0x92, 
    0x4a, 0x2, 0x2fe, 0x305, 0x7, 0x86, 0x2, 0x2, 0x2ff, 0x305, 0x5, 0x8e, 
    0x48, 0x2, 0x300, 0x301, 0x7, 0x7, 0x2, 0x2, 0x301, 0x302, 0x5, 0x80, 
    0x41, 0x2, 0x302, 0x303, 0x7, 0x8, 0x2, 0x2, 0x303, 0x305, 0x3, 0x2, 
    0x2, 0x2, 0x304, 0x2fd, 0x3, 0x2, 0x2, 0x2, 0x304, 0x2fe, 0x3, 0x2, 
    0x2, 0x2, 0x304, 0x2ff, 0x3, 0x2, 0x2, 0x2, 0x304, 0x300, 0x3, 0x2, 
    0x2, 0x2, 0x305, 0x79, 0x3, 0x2, 0x2, 0x2, 0x306, 0x312, 0x7, 0x9, 0x2, 
    0x2, 0x307, 0x30c, 0x5, 0x7c, 0x3f, 0x2, 0x308, 0x309, 0x7, 0xe, 0x2, 
    0x2, 0x309, 0x30b, 0x5, 0x7c, 0x3f, 0x2, 0x30a, 0x308, 0x3, 0x2, 0x2, 
    0x2, 0x30b, 0x30e, 0x3, 0x2, 0x2, 0x2, 0x30c, 0x30a, 0x3, 0x2, 0x2, 
    0x2, 0x30c, 0x30d, 0x3, 0x2, 0x2, 0x2, 0x30d, 0x310, 0x3, 0x2, 0x2, 
    0x2, 0x30e, 0x30c, 0x3, 0x2, 0x2, 0x2, 0x30f, 0x311, 0x7, 0xe, 0x2, 
    0x2, 0x310, 0x30f, 0x3, 0x2, 0x2, 0x2, 0x310, 0x311, 0x3, 0x2, 0x2, 
    0x2, 0x311, 0x313, 0x3, 0x2, 0x2, 0x2, 0x312, 0x307, 0x3, 0x2, 0x2, 
    0x2, 0x312, 0x313, 0x3, 0x2, 0x2, 0x2, 0x313, 0x314, 0x3, 0x2, 0x2, 
    0x2, 0x314, 0x315, 0x7, 0xa, 0x2, 0x2, 0x315, 0x7b, 0x3, 0x2, 0x2, 0x2, 
    0x316, 0x318, 0x7, 0x12, 0x2, 0x2, 0x317, 0x316, 0x3, 0x2, 0x2, 0x2, 
    0x317, 0x318, 0x3, 0x2, 0x2, 0x2, 0x318, 0x31b, 0x3, 0x2, 0x2, 0x2, 
    0x319, 0x31c, 0x5, 0x80, 0x41, 0x2, 0x31a, 0x31c, 0x7, 0x85, 0x2, 0x2, 
    0x31b, 0x319, 0x3, 0x2, 0x2, 0x2, 0x31b, 0x31a, 0x3, 0x2, 0x2, 0x2, 
    0x31c, 0x7d, 0x3, 0x2, 0x2, 0x2, 0x31d, 0x322, 0x5, 0x80, 0x41, 0x2, 
    0x31e, 0x31f, 0x7, 0xe, 0x2, 0x2, 0x31f, 0x321, 0x5, 0x80, 0x41, 0x2, 
    0x320, 0x31e, 0x3, 0x2, 0x2, 0x2, 0x321, 0x324, 0x3, 0x2, 0x2, 0x2, 
    0x322, 0x320, 0x3, 0x2, 0x2, 0x2, 0x322, 0x323, 0x3, 0x2, 0x2, 0x2, 
    0x323, 0x7f, 0x3, 0x2, 0x2, 0x2, 0x324, 0x322, 0x3, 0x2, 0x2, 0x2, 0x325, 
    0x326, 0x8, 0x41, 0x1, 0x2, 0x326, 0x358, 0x5, 0x84, 0x43, 0x2, 0x327, 
    0x329, 0x7, 0x6e, 0x2, 0x2, 0x328, 0x32a, 0x7, 0x85, 0x2, 0x2, 0x329, 
    0x328, 0x3, 0x2, 0x2, 0x2, 0x329, 0x32a, 0x3, 0x2, 0x2, 0x2, 0x32a, 
    0x32b, 0x3, 0x2, 0x2, 0x2, 0x32b, 0x358, 0x5, 0x62, 0x32, 0x2, 0x32c, 
    0x32d, 0x7, 0x58, 0x2, 0x2, 0x32d, 0x32e, 0x5, 0x80, 0x41, 0x2, 0x32e, 
    0x32f, 0x5, 0x7a, 0x3e, 0x2, 0x32f, 0x358, 0x3, 0x2, 0x2, 0x2, 0x330, 
    0x331, 0x7, 0x58, 0x2, 0x2, 0x331, 0x332, 0x7, 0x13, 0x2, 0x2, 0x332, 
    0x358, 0x7, 0x85, 0x2, 0x2, 0x333, 0x334, 0x7, 0x69, 0x2, 0x2, 0x334, 
    0x358, 0x5, 0x80, 0x41, 0x27, 0x335, 0x336, 0x7, 0x5d, 0x2, 0x2, 0x336, 
    0x358, 0x5, 0x80, 0x41, 0x26, 0x337, 0x338, 0x7, 0x55, 0x2, 0x2, 0x338, 
    0x358, 0x5, 0x80, 0x41, 0x25, 0x339, 0x33a, 0x7, 0x14, 0x2, 0x2, 0x33a, 
    0x358, 0x5, 0x80, 0x41, 0x24, 0x33b, 0x33c, 0x7, 0x15, 0x2, 0x2, 0x33c, 
    0x358, 0x5, 0x80, 0x41, 0x23, 0x33d, 0x33e, 0x7, 0x16, 0x2, 0x2, 0x33e, 
    0x358, 0x5, 0x80, 0x41, 0x22, 0x33f, 0x340, 0x7, 0x17, 0x2, 0x2, 0x340, 
    0x358, 0x5, 0x80, 0x41, 0x21, 0x341, 0x342, 0x7, 0x18, 0x2, 0x2, 0x342, 
    0x358, 0x5, 0x80, 0x41, 0x20, 0x343, 0x344, 0x7, 0x19, 0x2, 0x2, 0x344, 
    0x358, 0x5, 0x80, 0x41, 0x1f, 0x345, 0x346, 0x7, 0x77, 0x2, 0x2, 0x346, 
    0x358, 0x5, 0x80, 0x41, 0x1e, 0x347, 0x348, 0x7, 0x75, 0x2, 0x2, 0x348, 
    0x349, 0x7, 0x9, 0x2, 0x2, 0x349, 0x34a, 0x5, 0x80, 0x41, 0x2, 0x34a, 
    0x34b, 0x7, 0xa, 0x2, 0x2, 0x34b, 0x358, 0x3, 0x2, 0x2, 0x2, 0x34c, 
    0x358, 0x5, 0x48, 0x25, 0x2, 0x34d, 0x358, 0x7, 0x64, 0x2, 0x2, 0x34e, 
    0x358, 0x7, 0x85, 0x2, 0x2, 0x34f, 0x358, 0x7, 0x72, 0x2, 0x2, 0x350, 
    0x358, 0x5, 0x8c, 0x47, 0x2, 0x351, 0x358, 0x5, 0x6e, 0x38, 0x2, 0x352, 
    0x358, 0x5, 0x74, 0x3b, 0x2, 0x353, 0x354, 0x7, 0x9, 0x2, 0x2, 0x354, 
    0x355, 0x5, 0x7e, 0x40, 0x2, 0x355, 0x356, 0x7, 0xa, 0x2, 0x2, 0x356, 
    0x358, 0x3, 0x2, 0x2, 0x2, 0x357, 0x325, 0x3, 0x2, 0x2, 0x2, 0x357, 
    0x327, 0x3, 0x2, 0x2, 0x2, 0x357, 0x32c, 0x3, 0x2, 0x2, 0x2, 0x357, 
    0x330, 0x3, 0x2, 0x2, 0x2, 0x357, 0x333, 0x3, 0x2, 0x2, 0x2, 0x357, 
    0x335, 0x3, 0x2, 0x2, 0x2, 0x357, 0x337, 0x3, 0x2, 0x2, 0x2, 0x357, 
    0x339, 0x3, 0x2, 0x2, 0x2, 0x357, 0x33b, 0x3, 0x2, 0x2, 0x2, 0x357, 
    0x33d, 0x3, 0x2, 0x2, 0x2, 0x357, 0x33f, 0x3, 0x2, 0x2, 0x2, 0x357, 
    0x341, 0x3, 0x2, 0x2, 0x2, 0x357, 0x343, 0x3, 0x2, 0x2, 0x2, 0x357, 
    0x345, 0x3, 0x2, 0x2, 0x2, 0x357, 0x347, 0x3, 0x2, 0x2, 0x2, 0x357, 
    0x34c, 0x3, 0x2, 0x2, 0x2, 0x357, 0x34d, 0x3, 0x2, 0x2, 0x2, 0x357, 
    0x34e, 0x3, 0x2, 0x2, 0x2, 0x357, 0x34f, 0x3, 0x2, 0x2, 0x2, 0x357, 
    0x350, 0x3, 0x2, 0x2, 0x2, 0x357, 0x351, 0x3, 0x2, 0x2, 0x2, 0x357, 
    0x352, 0x3, 0x2, 0x2, 0x2, 0x357, 0x353, 0x3, 0x2, 0x2, 0x2, 0x358, 
    0x3a8, 0x3, 0x2, 0x2, 0x2, 0x359, 0x35a, 0xc, 0x1d, 0x2, 0x2, 0x35a, 
    0x35b, 0x7, 0x1d, 0x2, 0x2, 0x35b, 0x3a7, 0x5, 0x80, 0x41, 0x1d, 0x35c, 
    0x35d, 0xc, 0x1c, 0x2, 0x2, 0x35d, 0x35e, 0x9, 0x8, 0x2, 0x2, 0x35e, 
    0x3a7, 0x5, 0x80, 0x41, 0x1d, 0x35f, 0x360, 0xc, 0x1b, 0x2, 0x2, 0x360, 
    0x361, 0x9, 0x9, 0x2, 0x2, 0x361, 0x3a7, 0x5, 0x80, 0x41, 0x1c, 0x362, 
    0x363, 0xc, 0x1a, 0x2, 0x2, 0x363, 0x364, 0x7, 0x1e, 0x2, 0x2, 0x364, 
    0x3a7, 0x5, 0x80, 0x41, 0x1b, 0x365, 0x366, 0xc, 0x19, 0x2, 0x2, 0x366, 
    0x367, 0x9, 0xa, 0x2, 0x2, 0x367, 0x3a7, 0x5, 0x80, 0x41, 0x1a, 0x368, 
    0x369, 0xc, 0x18, 0x2, 0x2, 0x369, 0x36a, 0x9, 0xb, 0x2, 0x2, 0x36a, 
    0x3a7, 0x5, 0x80, 0x41, 0x19, 0x36b, 0x36c, 0xc, 0x17, 0x2, 0x2, 0x36c, 
    0x36d, 0x7, 0x54, 0x2, 0x2, 0x36d, 0x3a7, 0x5, 0x80, 0x41, 0x18, 0x36e, 
    0x36f, 0xc, 0x16, 0x2, 0x2, 0x36f, 0x370, 0x7, 0x6a, 0x2, 0x2, 0x370, 
    0x3a7, 0x5, 0x80, 0x41, 0x17, 0x371, 0x372, 0xc, 0x15, 0x2, 0x2, 0x372, 
    0x373, 0x9, 0xc, 0x2, 0x2, 0x373, 0x3a7, 0x5, 0x80, 0x41, 0x16, 0x374, 
    0x375, 0xc, 0x14, 0x2, 0x2, 0x375, 0x376, 0x7, 0x2b, 0x2, 0x2, 0x376, 
    0x3a7, 0x5, 0x80, 0x41, 0x15, 0x377, 0x378, 0xc, 0x13, 0x2, 0x2, 0x378, 
    0x379, 0x7, 0x2c, 0x2, 0x2, 0x379, 0x3a7, 0x5, 0x80, 0x41, 0x14, 0x37a, 
    0x37b, 0xc, 0x12, 0x2, 0x2, 0x37b, 0x37c, 0x7, 0x2d, 0x2, 0x2, 0x37c, 
    0x3a7, 0x5, 0x80, 0x41, 0x13, 0x37d, 0x37e, 0xc, 0x11, 0x2, 0x2, 0x37e, 
    0x37f, 0x7, 0x2e, 0x2, 0x2, 0x37f, 0x3a7, 0x5, 0x80, 0x41, 0x12, 0x380, 
    0x381, 0xc, 0x10, 0x2, 0x2, 0x381, 0x382, 0x7, 0x2f, 0x2, 0x2, 0x382, 
    0x3a7, 0x5, 0x80, 0x41, 0x11, 0x383, 0x384, 0xc, 0xf, 0x2, 0x2, 0x384, 
    0x385, 0x7, 0x10, 0x2, 0x2, 0x385, 0x386, 0x5, 0x80, 0x41, 0x2, 0x386, 
    0x387, 0x7, 0x11, 0x2, 0x2, 0x387, 0x388, 0x5, 0x80, 0x41, 0x10, 0x388, 
    0x3a7, 0x3, 0x2, 0x2, 0x2, 0x389, 0x38a, 0xc, 0xe, 0x2, 0x2, 0x38a, 
    0x38b, 0x7, 0xf, 0x2, 0x2, 0x38b, 0x3a7, 0x5, 0x80, 0x41, 0xe, 0x38c, 
    0x38d, 0xc, 0xd, 0x2, 0x2, 0x38d, 0x38e, 0x5, 0x8a, 0x46, 0x2, 0x38e, 
    0x38f, 0x5, 0x80, 0x41, 0xd, 0x38f, 0x3a7, 0x3, 0x2, 0x2, 0x2, 0x390, 
    0x391, 0xc, 0x2e, 0x2, 0x2, 0x391, 0x392, 0x7, 0x7, 0x2, 0x2, 0x392, 
    0x393, 0x5, 0x7e, 0x40, 0x2, 0x393, 0x394, 0x7, 0x8, 0x2, 0x2, 0x394, 
    0x3a7, 0x3, 0x2, 0x2, 0x2, 0x395, 0x397, 0xc, 0x2d, 0x2, 0x2, 0x396, 
    0x398, 0x7, 0x10, 0x2, 0x2, 0x397, 0x396, 0x3, 0x2, 0x2, 0x2, 0x397, 
    0x398, 0x3, 0x2, 0x2, 0x2, 0x398, 0x399, 0x3, 0x2, 0x2, 0x2, 0x399, 
    0x39b, 0x7, 0x13, 0x2, 0x2, 0x39a, 0x39c, 0x7, 0x1f, 0x2, 0x2, 0x39b, 
    0x39a, 0x3, 0x2, 0x2, 0x2, 0x39b, 0x39c, 0x3, 0x2, 0x2, 0x2, 0x39c, 
    0x39d, 0x3, 0x2, 0x2, 0x2, 0x39d, 0x3a7, 0x5, 0x92, 0x4a, 0x2, 0x39e, 
    0x39f, 0xc, 0x2a, 0x2, 0x2, 0x39f, 0x3a7, 0x5, 0x7a, 0x3e, 0x2, 0x3a0, 
    0x3a1, 0xc, 0x29, 0x2, 0x2, 0x3a1, 0x3a7, 0x7, 0x14, 0x2, 0x2, 0x3a2, 
    0x3a3, 0xc, 0x28, 0x2, 0x2, 0x3a3, 0x3a7, 0x7, 0x15, 0x2, 0x2, 0x3a4, 
    0x3a5, 0xc, 0xb, 0x2, 0x2, 0x3a5, 0x3a7, 0x7, 0x87, 0x2, 0x2, 0x3a6, 
    0x359, 0x3, 0x2, 0x2, 0x2, 0x3a6, 0x35c, 0x3, 0x2, 0x2, 0x2, 0x3a6, 
    0x35f, 0x3, 0x2, 0x2, 0x2, 0x3a6, 0x362, 0x3, 0x2, 0x2, 0x2, 0x3a6, 
    0x365, 0x3, 0x2, 0x2, 0x2, 0x3a6, 0x368, 0x3, 0x2, 0x2, 0x2, 0x3a6, 
    0x36b, 0x3, 0x2, 0x2, 0x2, 0x3a6, 0x36e, 0x3, 0x2, 0x2, 0x2, 0x3a6, 
    0x371, 0x3, 0x2, 0x2, 0x2, 0x3a6, 0x374, 0x3, 0x2, 0x2, 0x2, 0x3a6, 
    0x377, 0x3, 0x2, 0x2, 0x2, 0x3a6, 0x37a, 0x3, 0x2, 0x2, 0x2, 0x3a6, 
    0x37d, 0x3, 0x2, 0x2, 0x2, 0x3a6, 0x380, 0x3, 0x2, 0x2, 0x2, 0x3a6, 
    0x383, 0x3, 0x2, 0x2, 0x2, 0x3a6, 0x389, 0x3, 0x2, 0x2, 0x2, 0x3a6, 
    0x38c, 0x3, 0x2, 0x2, 0x2, 0x3a6, 0x390, 0x3, 0x2, 0x2, 0x2, 0x3a6, 
    0x395, 0x3, 0x2, 0x2, 0x2, 0x3a6, 0x39e, 0x3, 0x2, 0x2, 0x2, 0x3a6, 
    0x3a0, 0x3, 0x2, 0x2, 0x2, 0x3a6, 0x3a2, 0x3, 0x2, 0x2, 0x2, 0x3a6, 
    0x3a4, 0x3, 0x2, 0x2, 0x2, 0x3a7, 0x3aa, 0x3, 0x2, 0x2, 0x2, 0x3a8, 
    0x3a6, 0x3, 0x2, 0x2, 0x2, 0x3a8, 0x3a9, 0x3, 0x2, 0x2, 0x2, 0x3a9, 
    0x81, 0x3, 0x2, 0x2, 0x2, 0x3aa, 0x3a8, 0x3, 0x2, 0x2, 0x2, 0x3ab, 0x3af, 
    0x7, 0x85, 0x2, 0x2, 0x3ac, 0x3af, 0x5, 0x6e, 0x38, 0x2, 0x3ad, 0x3af, 
    0x5, 0x74, 0x3b, 0x2, 0x3ae, 0x3ab, 0x3, 0x2, 0x2, 0x2, 0x3ae, 0x3ac, 
    0x3, 0x2, 0x2, 0x2, 0x3ae, 0x3ad, 0x3, 0x2, 0x2, 0x2, 0x3af, 0x83, 0x3, 
    0x2, 0x2, 0x2, 0x3b0, 0x3c9, 0x5, 0x5e, 0x30, 0x2, 0x3b1, 0x3b3, 0x7, 
    0x76, 0x2, 0x2, 0x3b2, 0x3b1, 0x3, 0x2, 0x2, 0x2, 0x3b2, 0x3b3, 0x3, 
    0x2, 0x2, 0x2, 0x3b3, 0x3b4, 0x3, 0x2, 0x2, 0x2, 0x3b4, 0x3b6, 0x7, 
    0x63, 0x2, 0x2, 0x3b5, 0x3b7, 0x7, 0x1a, 0x2, 0x2, 0x3b6, 0x3b5, 0x3, 
    0x2, 0x2, 0x2, 0x3b6, 0x3b7, 0x3, 0x2, 0x2, 0x2, 0x3b7, 0x3b8, 0x3, 
    0x2, 0x2, 0x2, 0x3b8, 0x3ba, 0x7, 0x9, 0x2, 0x2, 0x3b9, 0x3bb, 0x5, 
    0x66, 0x34, 0x2, 0x3ba, 0x3b9, 0x3, 0x2, 0x2, 0x2, 0x3ba, 0x3bb, 0x3, 
    0x2, 0x2, 0x2, 0x3bb, 0x3bc, 0x3, 0x2, 0x2, 0x2, 0x3bc, 0x3bd, 0x7, 
    0xa, 0x2, 0x2, 0x3bd, 0x3be, 0x7, 0xb, 0x2, 0x2, 0x3be, 0x3bf, 0x5, 
    0x6c, 0x37, 0x2, 0x3bf, 0x3c0, 0x7, 0xc, 0x2, 0x2, 0x3c0, 0x3c9, 0x3, 
    0x2, 0x2, 0x2, 0x3c1, 0x3c3, 0x7, 0x76, 0x2, 0x2, 0x3c2, 0x3c1, 0x3, 
    0x2, 0x2, 0x2, 0x3c2, 0x3c3, 0x3, 0x2, 0x2, 0x2, 0x3c3, 0x3c4, 0x3, 
    0x2, 0x2, 0x2, 0x3c4, 0x3c5, 0x5, 0x86, 0x44, 0x2, 0x3c5, 0x3c6, 0x7, 
    0x3c, 0x2, 0x2, 0x3c6, 0x3c7, 0x5, 0x88, 0x45, 0x2, 0x3c7, 0x3c9, 0x3, 
    0x2, 0x2, 0x2, 0x3c8, 0x3b0, 0x3, 0x2, 0x2, 0x2, 0x3c8, 0x3b2, 0x3, 
    0x2, 0x2, 0x2, 0x3c8, 0x3c2, 0x3, 0x2, 0x2, 0x2, 0x3c9, 0x85, 0x3, 0x2, 
    0x2, 0x2, 0x3ca, 0x3d1, 0x7, 0x85, 0x2, 0x2, 0x3cb, 0x3cd, 0x7, 0x9, 
    0x2, 0x2, 0x3cc, 0x3ce, 0x5, 0x66, 0x34, 0x2, 0x3cd, 0x3cc, 0x3, 0x2, 
    0x2, 0x2, 0x3cd, 0x3ce, 0x3, 0x2, 0x2, 0x2, 0x3ce, 0x3cf, 0x3, 0x2, 
    0x2, 0x2, 0x3cf, 0x3d1, 0x7, 0xa, 0x2, 0x2, 0x3d0, 0x3ca, 0x3, 0x2, 
    0x2, 0x2, 0x3d0, 0x3cb, 0x3, 0x2, 0x2, 0x2, 0x3d1, 0x87, 0x3, 0x2, 0x2, 
    0x2, 0x3d2, 0x3d8, 0x5, 0x80, 0x41, 0x2, 0x3d3, 0x3d4, 0x7, 0xb, 0x2, 
    0x2, 0x3d4, 0x3d5, 0x5, 0x6c, 0x37, 0x2, 0x3d5, 0x3d6, 0x7, 0xc, 0x2, 
    0x2, 0x3d6, 0x3d8, 0x3, 0x2, 0x2, 0x2, 0x3d7, 0x3d2, 0x3, 0x2, 0x2, 
    0x2, 0x3d7, 0x3d3, 0x3, 0x2, 0x2, 0x2, 0x3d8, 0x89, 0x3, 0x2, 0x2, 0x2, 
    0x3d9, 0x3da, 0x9, 0xd, 0x2, 0x2, 0x3da, 0x8b, 0x3, 0x2, 0x2, 0x2, 0x3db, 
    0x3e3, 0x7, 0x3d, 0x2, 0x2, 0x3dc, 0x3e3, 0x7, 0x3e, 0x2, 0x2, 0x3dd, 
    0x3e3, 0x7, 0x86, 0x2, 0x2, 0x3de, 0x3e3, 0x7, 0x87, 0x2, 0x2, 0x3df, 
    0x3e3, 0x7, 0x6, 0x2, 0x2, 0x3e0, 0x3e3, 0x5, 0x8e, 0x48, 0x2, 0x3e1, 
    0x3e3, 0x5, 0x90, 0x49, 0x2, 0x3e2, 0x3db, 0x3, 0x2, 0x2, 0x2, 0x3e2, 
    0x3dc, 0x3, 0x2, 0x2, 0x2, 0x3e2, 0x3dd, 0x3, 0x2, 0x2, 0x2, 0x3e2, 
    0x3de, 0x3, 0x2, 0x2, 0x2, 0x3e2, 0x3df, 0x3, 0x2, 0x2, 0x2, 0x3e2, 
    0x3e0, 0x3, 0x2, 0x2, 0x2, 0x3e2, 0x3e1, 0x3, 0x2, 0x2, 0x2, 0x3e3, 
    0x8d, 0x3, 0x2, 0x2, 0x2, 0x3e4, 0x3e5, 0x9, 0xe, 0x2, 0x2, 0x3e5, 0x8f, 
    0x3, 0x2, 0x2, 0x2, 0x3e6, 0x3e7, 0x9, 0xf, 0x2, 0x2, 0x3e7, 0x91, 0x3, 
    0x2, 0x2, 0x2, 0x3e8, 0x3eb, 0x7, 0x85, 0x2, 0x2, 0x3e9, 0x3eb, 0x5, 
    0x94, 0x4b, 0x2, 0x3ea, 0x3e8, 0x3, 0x2, 0x2, 0x2, 0x3ea, 0x3e9, 0x3, 
    0x2, 0x2, 0x2, 0x3eb, 0x93, 0x3, 0x2, 0x2, 0x2, 0x3ec, 0x3f0, 0x5, 0x96, 
    0x4c, 0x2, 0x3ed, 0x3f0, 0x7, 0x3d, 0x2, 0x2, 0x3ee, 0x3f0, 0x7, 0x3e, 
    0x2, 0x2, 0x3ef, 0x3ec, 0x3, 0x2, 0x2, 0x2, 0x3ef, 0x3ed, 0x3, 0x2, 
    0x2, 0x2, 0x3ef, 0x3ee, 0x3, 0x2, 0x2, 0x2, 0x3f0, 0x95, 0x3, 0x2, 0x2, 
    0x2, 0x3f1, 0x3f2, 0x9, 0x10, 0x2, 0x2, 0x3f2, 0x97, 0x3, 0x2, 0x2, 
    0x2, 0x3f3, 0x3f4, 0x7, 0x82, 0x2, 0x2, 0x3f4, 0x3f5, 0x5, 0x78, 0x3d, 
    0x2, 0x3f5, 0x99, 0x3, 0x2, 0x2, 0x2, 0x3f6, 0x3f7, 0x7, 0x83, 0x2, 
    0x2, 0x3f7, 0x3f8, 0x5, 0x78, 0x3d, 0x2, 0x3f8, 0x9b, 0x3, 0x2, 0x2, 
    0x2, 0x3f9, 0x3fa, 0x9, 0x11, 0x2, 0x2, 0x3fa, 0x9d, 0x3, 0x2, 0x2, 
    0x2, 0x76, 0x9f, 0xa2, 0xa9, 0xbf, 0xc6, 0xd6, 0xde, 0xe2, 0xe9, 0xf1, 
    0xf6, 0xf8, 0x102, 0x10a, 0x10f, 0x118, 0x120, 0x124, 0x129, 0x134, 
    0x139, 0x13d, 0x14b, 0x15f, 0x163, 0x16c, 0x175, 0x17a, 0x182, 0x185, 
    0x189, 0x191, 0x197, 0x19d, 0x1a3, 0x1b7, 0x1bf, 0x1c5, 0x1c7, 0x1d5, 
    0x1d8, 0x1dd, 0x1e0, 0x1eb, 0x1ef, 0x1f4, 0x1f8, 0x201, 0x20a, 0x210, 
    0x216, 0x219, 0x21e, 0x226, 0x22b, 0x22f, 0x234, 0x238, 0x23f, 0x244, 
    0x24b, 0x252, 0x257, 0x25d, 0x265, 0x26a, 0x26f, 0x273, 0x276, 0x27d, 
    0x282, 0x285, 0x289, 0x28d, 0x293, 0x29c, 0x2a0, 0x2a5, 0x2aa, 0x2b0, 
    0x2b4, 0x2be, 0x2c1, 0x2c4, 0x2ca, 0x2d6, 0x2d9, 0x2dd, 0x2e1, 0x2f8, 
    0x2fb, 0x304, 0x30c, 0x310, 0x312, 0x317, 0x31b, 0x322, 0x329, 0x357, 
    0x397, 0x39b, 0x3a6, 0x3a8, 0x3ae, 0x3b2, 0x3b6, 0x3ba, 0x3c2, 0x3c8, 
    0x3cd, 0x3d0, 0x3d7, 0x3e2, 0x3ea, 0x3ef, 
  };

  atn::ATNDeserializer deserializer;
  _atn = deserializer.deserialize(_serializedATN);

  size_t count = _atn.getNumberOfDecisions();
  _decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    _decisionToDFA.emplace_back(_atn.getDecisionState(i), i);
  }
}

TypeScriptParser::Initializer TypeScriptParser::_init;
