parser grammar TypeScriptParser;

options {
    tokenVocab=TypeScriptLexer;
}

program
    : HashBangLine? statementList? EOF
    ;

statementList
    : statement+
    ;

statement
    : block
    | variableStatement
    | importStatement
    | exportStatement
    | emptyStatement
    | classDeclaration
    | expressionStatement
    | ifStatement
    | iterationStatement
    | continueStatement
    | breakStatement
    | returnStatement
    | yieldStatement
    | withStatement
    | labelledStatement
    | switchStatement
    | throwStatement
    | tryStatement
    | debuggerStatement
    | functionDeclaration
    ;


/// TypeScript addon - start
typeSign
    : Colon primaryType
    ;

primaryType
    : predefinedType
    | typeReference
    ;

// predefined types
predefinedType
    : AnyType
    | Int32Type
    | Int64Type
    | FloatType
    | DoubleType
    | NumberType
    | BooleanType
    | StringType
    | VoidType
    ;

// user defined types
typeReference
    : Identifier
    ;

accessControl
    : Private
    | Protected
    | Public
    ;

classControl
    : Static
    | Final
    ;

propertyControl
    : Static
    | Readonly
    ;

functionControl
    : Static
    | Final
    | Identifier
    ;

/// TypeScript addon - end

block
    : '{' statementList? '}'
    ;

importStatement
    : Import importFromBlock
    ;

importFromBlock
    : importDefault? (importNamespace | moduleItems) importFrom eos
    | StringLiteral eos
    ;

moduleItems
    : '{' (aliasName ',')* (aliasName ','?)? '}'
    ;

importDefault
    : aliasName ','
    ;

importNamespace
    : '*' (As identifierName)?
    ;

importFrom
    : From StringLiteral
    ;

aliasName
    : identifierName (As identifierName )?
    ;

exportStatement
    : Export (exportFromBlock | declaration) eos    # ExportDeclaration
    | Export Default singleExpression eos           # ExportDefaultDeclaration
    ;

exportFromBlock
    : importNamespace importFrom eos
    | moduleItems importFrom? eos
    ;

declaration
    : variableStatement
    | classDeclaration
    | functionDeclaration
    ;

variableStatement
    : varModifier variableDeclarationList eos
    ;

variableDeclarationList
    : variableDeclaration (',' variableDeclaration)*
    ;

variableDeclaration
    : assignable typeSign? ('=' singleExpression)? // ECMAScript 6: Array & Object Matching
    ;

emptyStatement
    : SemiColon
    ;

expressionStatement
    : expressionSequence eos
    ;

ifStatement
    : If '(' expressionSequence ')' statement (Else statement)?
    ;

iterationStatement
    : Do statement While '(' expressionSequence ')' eos                                                        # DoStatement
    | While '(' expressionSequence ')' statement                                                               # WhileStatement
    | For '(' forInitialization forCondition? ';' expressionSequence? ')' statement                            # ForStatement
    | For '(' (singleExpression | variableStatement) In expressionSequence ')' statement                       # ForInStatement
    // strange, 'of' is an identifier. and this.p("of") not work in sometime.
    | For Await? '(' (singleExpression | variableStatement) Of Identifier expressionSequence ')' statement     # ForOfStatement
    ;
    
forInitialization
  : expressionSequence? ';'
  | variableStatement
  ;

forCondition
  : expressionSequence
  ;

varModifier  // let, const - ECMAScript 6
    : Var
    | Let
    | Const
    ;

continueStatement
    : Continue Identifier? eos
    ;

breakStatement
    : Break Identifier? eos
    ;

returnStatement
    : Return expressionSequence? eos
    ;

yieldStatement
    : Yield expressionSequence? eos
    ;

withStatement
    : With '(' expressionSequence ')' statement
    ;

switchStatement
    : Switch '(' expressionSequence ')' caseBlock
    ;

caseBlock
    : '{' caseClause* '}'
    ;

caseClause
    : Default ':' statementList?                    # SwitchDefaultClause
    | Case expressionSequence ':' statementList?    # SwitchCaseClause
    ;

labelledStatement
    : Identifier ':' statement
    ;

throwStatement
    : Throw expressionSequence eos
    ;

tryStatement
    : Try block (catchProduction finallyProduction? | finallyProduction)
    ;

catchProduction
    : Catch ('(' assignable? ')')? block
    ;

finallyProduction
    : Finally block
    ;

debuggerStatement
    : Debugger eos
    ;

functionDeclaration
    : Async? Function '*'? Identifier '(' formalParameterList? ')' typeSign? '{' functionBody '}'
    ;

classDeclaration
    : classControl* Class Identifier classTail
    ;

classTail
    : (Extends singleExpression)? '{' classElement* '}'
    ;

classElement
    : accessControl? Async? 'constructor' '(' formalParameterList? ')' '{' functionBody '}'                              # ConstructorDefinition
    | accessControl? functionControl* Async? propertyName '(' formalParameterList? ')' typeSign? '{' functionBody '}'    # NormalMethodDefinition
    | accessControl? functionControl* getter '(' ')' typeSign? '{' functionBody '}'                                      # GetterMethodDefinition
    | accessControl? functionControl* setter '(' formalParameterList? ')' '{' functionBody '}'                           # SetterMethodDefinition
    | accessControl? propertyControl* propertyName typeSign? ('=' singleExpression)?                                     # ClassPropertyDefinition
    | emptyStatement                                                                                                     # ClassEmptyStatement
    ;

formalParameterList
    : formalParameterArg (',' formalParameterArg)* (',' lastFormalParameterArg)?
    | lastFormalParameterArg
    ;

formalParameterArg
    : assignable typeSign? ('=' singleExpression)?      // ECMAScript 6: Initialization
    ;

lastFormalParameterArg                        // ECMAScript 6: Rest Parameter
    : Ellipsis singleExpression
    ;

functionBody
    : statementList?
    ;

arrayLiteral
    : ('[' elementList ']')
    ;

elementList
    : ','* arrayElement? (','+ arrayElement)* ','* // Yes, everything is optional
    ;

arrayElement
    : Ellipsis? singleExpression
    ;

objectLiteral
    : '{' (propertyAssignment (',' propertyAssignment)*)? ','? '}'
    ;

propertyAssignment
    : propertyName typeSign? ':' singleExpression                                             # PropertyExpressionAssignment
    | '[' singleExpression ']' ':' singleExpression                                           # ComputedPropertyExpressionAssignment
    | Async? '*'? propertyName typeSign? '(' formalParameterList?  ')'  '{' functionBody '}'  # FunctionProperty
    | getter '(' ')' '{' functionBody '}'                                                     # PropertyGetter
    | setter '(' formalParameterArg ')' '{' functionBody '}'                                  # PropertySetter
    | Ellipsis? singleExpression                                                              # PropertyShorthand
    ;

propertyName
    : identifierName
    | StringLiteral
    | numericLiteral
    | '[' singleExpression ']'
    ;

arguments
    : '('(argument (',' argument)* ','?)?')'
    ;

argument
    : Ellipsis? (singleExpression | Identifier)
    ;

expressionSequence
    : singleExpression (',' singleExpression)*
    ;

singleExpression
    : anoymousFunction                                                      # FunctionExpression
    | Class Identifier? classTail                                           # ClassExpression
    | singleExpression '[' expressionSequence ']'                           # MemberIndexExpression
    | singleExpression '?'? '.' '#'? identifierName                         # MemberDotExpression
    | New singleExpression arguments                                        # NewExpression
    | New '.' Identifier                                                    # MetaExpression // new.target
    | singleExpression arguments                                            # ArgumentsExpression
    | singleExpression '++'                                                 # PostIncrementExpression
    | singleExpression '--'                                                 # PostDecreaseExpression
    | Delete singleExpression                                               # DeleteExpression
    | Void singleExpression                                                 # VoidExpression
    | Typeof singleExpression                                               # TypeofExpression
    | '++' singleExpression                                                 # PreIncrementExpression
    | '--' singleExpression                                                 # PreDecreaseExpression
    | '+' singleExpression                                                  # UnaryPlusExpression
    | '-' singleExpression                                                  # UnaryMinusExpression
    | '~' singleExpression                                                  # BitNotExpression
    | '!' singleExpression                                                  # NotExpression
    | Await singleExpression                                                # AwaitExpression
    | <assoc=right> singleExpression '**' singleExpression                  # PowerExpression
    | singleExpression ('*' | '/' | '%') singleExpression                   # MultiplicativeExpression
    | singleExpression ('+' | '-') singleExpression                         # AdditiveExpression
    | singleExpression '??' singleExpression                                # CoalesceExpression
    | singleExpression ('<<' | '>>' | '>>>') singleExpression               # BitShiftExpression
    | singleExpression ('<' | '>' | '<=' | '>=') singleExpression           # RelationalExpression
    | singleExpression Instanceof singleExpression                          # InstanceofExpression
    | singleExpression In singleExpression                                  # InExpression
    | singleExpression ('==' | '!=' | '===' | '!==') singleExpression       # EqualityExpression
    | singleExpression '&' singleExpression                                 # BitAndExpression
    | singleExpression '^' singleExpression                                 # BitXOrExpression
    | singleExpression '|' singleExpression                                 # BitOrExpression
    | singleExpression '&&' singleExpression                                # LogicalAndExpression
    | singleExpression '||' singleExpression                                # LogicalOrExpression
    | singleExpression '?' singleExpression ':' singleExpression            # TernaryExpression
    | <assoc=right> singleExpression '=' singleExpression                   # AssignmentExpression
    | <assoc=right> singleExpression assignmentOperator singleExpression    # AssignmentOperatorExpression
    | Import '(' singleExpression ')'                                       # ImportExpression
    | singleExpression TemplateStringLiteral                                # TemplateStringExpression
    | yieldStatement                                                        # YieldExpression // ECMAScript 6
    | This                                                                  # ThisExpression
    | Identifier                                                            # IdentifierExpression
    | Super                                                                 # SuperExpression
    | literal                                                               # LiteralExpression
    | arrayLiteral                                                          # ArrayLiteralExpression
    | objectLiteral                                                         # ObjectLiteralExpression
    | '(' expressionSequence ')'                                            # ParenthesizedExpression
    ;

assignable
    : Identifier
    | arrayLiteral
    | objectLiteral
    ;

anoymousFunction
    : functionDeclaration                                                       # FunctionDecl
    | Async? Function '*'? '(' formalParameterList? ')' '{' functionBody '}'    # AnoymousFunctionDecl
    | Async? arrowFunctionParameters '=>' arrowFunctionBody                     # ArrowFunction
    ;

arrowFunctionParameters
    : Identifier
    | '(' formalParameterList? ')'
    ;

arrowFunctionBody
    : singleExpression
    | '{' functionBody '}'
    ;

assignmentOperator
    : '*='
    | '/='
    | '%='
    | '+='
    | '-='
    | '<<='
    | '>>='
    | '>>>='
    | '&='
    | '^='
    | '|='
    | '**='
    ;

literal
    : NullLiteral
    | BooleanLiteral
    | StringLiteral
    | TemplateStringLiteral
    | RegularExpressionLiteral
    | numericLiteral
    | bigintLiteral
    ;

numericLiteral
    : DecimalLiteral
    | HexIntegerLiteral
    | OctalIntegerLiteral
    | OctalIntegerLiteral2
    | BinaryIntegerLiteral
    ;

bigintLiteral
    : BigDecimalIntegerLiteral
    | BigHexIntegerLiteral
    | BigOctalIntegerLiteral
    | BigBinaryIntegerLiteral
    ;

identifierName
    : Identifier
    | reservedWord
    ;

reservedWord
    : keyword
    | NullLiteral
    | BooleanLiteral
    ;

keyword
    : Break
    | Do
    | Instanceof
    | Typeof
    | Case
    | Else
    | New
    | Var
    | Catch
    | Finally
    | Return
    | Void
    | Continue
    | For
    | Switch
    | While
    | Debugger
    | Function
    | This
    | With
    | Default
    | If
    | Throw
    | Delete
    | In
    | Try

    | Class
    | Enum
    | Extends
    | Super
    | Const
    | Export
    | Import
    | Implements
    | Let
    | Private
    | Public
    | Interface
    | Package
    | Protected
    | Static
    | Yield
    | Async
    | Await
    | From
    | As
    ;

getter
    : Get propertyName
    ;

setter
    : Set propertyName
    ;

eos
    : SemiColon
    | EOF
    ;
