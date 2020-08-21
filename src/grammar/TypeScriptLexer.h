
// Generated from TypeScriptLexer.g4 by ANTLR 4.8

#pragma once


#include "antlr4-runtime.h"




class  TypeScriptLexer : public antlr4::Lexer {
public:
  enum {
    HashBangLine = 1, MultiLineComment = 2, SingleLineComment = 3, RegularExpressionLiteral = 4, 
    OpenBracket = 5, CloseBracket = 6, OpenParen = 7, CloseParen = 8, OpenBrace = 9, 
    CloseBrace = 10, SemiColon = 11, Comma = 12, Assign = 13, QuestionMark = 14, 
    Colon = 15, Ellipsis = 16, Dot = 17, PlusPlus = 18, MinusMinus = 19, 
    Plus = 20, Minus = 21, BitNot = 22, Not = 23, Multiply = 24, Divide = 25, 
    Modulus = 26, Power = 27, NullCoalesce = 28, Hashtag = 29, RightShiftArithmetic = 30, 
    LeftShiftArithmetic = 31, RightShiftLogical = 32, LessThan = 33, MoreThan = 34, 
    LessThanEquals = 35, GreaterThanEquals = 36, Equals_ = 37, NotEquals = 38, 
    IdentityEquals = 39, IdentityNotEquals = 40, BitAnd = 41, BitXOr = 42, 
    BitOr = 43, And = 44, Or = 45, MultiplyAssign = 46, DivideAssign = 47, 
    ModulusAssign = 48, PlusAssign = 49, MinusAssign = 50, LeftShiftArithmeticAssign = 51, 
    RightShiftArithmeticAssign = 52, RightShiftLogicalAssign = 53, BitAndAssign = 54, 
    BitXorAssign = 55, BitOrAssign = 56, PowerAssign = 57, ARROW = 58, NullLiteral = 59, 
    BooleanLiteral = 60, DecimalLiteral = 61, AnyType = 62, Int32Type = 63, 
    Int64Type = 64, FloatType = 65, DoubleType = 66, NumberType = 67, BooleanType = 68, 
    StringType = 69, VoidType = 70, HexIntegerLiteral = 71, OctalIntegerLiteral = 72, 
    OctalIntegerLiteral2 = 73, BinaryIntegerLiteral = 74, BigHexIntegerLiteral = 75, 
    BigOctalIntegerLiteral = 76, BigBinaryIntegerLiteral = 77, BigDecimalIntegerLiteral = 78, 
    Readonly = 79, Break = 80, Do = 81, Instanceof = 82, Typeof = 83, Case = 84, 
    Else = 85, New = 86, Var = 87, Catch = 88, Finally = 89, Return = 90, 
    Void = 91, Continue = 92, For = 93, Switch = 94, While = 95, Debugger = 96, 
    Function = 97, This = 98, With = 99, Default = 100, If = 101, Throw = 102, 
    Delete = 103, In = 104, Try = 105, As = 106, From = 107, Class = 108, 
    Constructor = 109, Enum = 110, Extends = 111, Super = 112, Const = 113, 
    Export = 114, Import = 115, Async = 116, Await = 117, Implements = 118, 
    Let = 119, Private = 120, Public = 121, Interface = 122, Package = 123, 
    Protected = 124, Static = 125, Final = 126, Yield = 127, Get = 128, 
    Set = 129, Of = 130, Identifier = 131, StringLiteral = 132, TemplateStringLiteral = 133, 
    WhiteSpaces = 134, LineTerminator = 135, HtmlComment = 136, CDataComment = 137, 
    UnexpectedCharacter = 138
  };

  enum {
    ERROR = 2
  };

  TypeScriptLexer(antlr4::CharStream *input);
  ~TypeScriptLexer();

  virtual std::string getGrammarFileName() const override;
  virtual const std::vector<std::string>& getRuleNames() const override;

  virtual const std::vector<std::string>& getChannelNames() const override;
  virtual const std::vector<std::string>& getModeNames() const override;
  virtual const std::vector<std::string>& getTokenNames() const override; // deprecated, use vocabulary instead
  virtual antlr4::dfa::Vocabulary& getVocabulary() const override;

  virtual const std::vector<uint16_t> getSerializedATN() const override;
  virtual const antlr4::atn::ATN& getATN() const override;

private:
  static std::vector<antlr4::dfa::DFA> _decisionToDFA;
  static antlr4::atn::PredictionContextCache _sharedContextCache;
  static std::vector<std::string> _ruleNames;
  static std::vector<std::string> _tokenNames;
  static std::vector<std::string> _channelNames;
  static std::vector<std::string> _modeNames;

  static std::vector<std::string> _literalNames;
  static std::vector<std::string> _symbolicNames;
  static antlr4::dfa::Vocabulary _vocabulary;
  static antlr4::atn::ATN _atn;
  static std::vector<uint16_t> _serializedATN;


  // Individual action functions triggered by action() above.

  // Individual semantic predicate functions triggered by sempred() above.

  struct Initializer {
    Initializer();
  };
  static Initializer _init;
};

