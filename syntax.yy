%{  
    int yylex(void);
    void yyerror(const char *);
    #include <stdio.h>
// need to include classes.h file or smth like that
%}

%union{
    // need to create buffers or vars for temp data
}

%token T_BOOLEAN 
%token T_BREAK 
%token T_CASE 
%token T_CLASS 
%token T_CONTINUE 
%token T_ELSE 
%token T_EXTENDS 
%token T_FLOAT 
%token T_DEFAULT 
%token T_INT 
%token T_NEW 
%token T_IF 
%token T_PUBLIC 
%token T_SWITCH 
%token T_RETURN 
%token T_STATIC 
%token T_WHILE 
%token T_THIS 
%token T_NULL_LITERAL 
%token T_LENGTH 
%token T_TRUE 
%token T_FALSE
%token T_MAIN
%token T_LPAREN 
%token T_RPAREN 
%token T_LBRACE 
%token T_RBRACE 
%token T_LBRACK 
%token T_RBRACK 
%token T_SEMICOLON 
%token T_COMMA 
%token T_DOT 
%token T_EQ 
%token T_LT 
%token T_GT 
%token T_LET 
%token T_GET 
%token T_NOT 
%token T_COLON 
%token T_ANDAND 
%token T_OROR 
%token T_PLUS 
%token T_MINUS 
%token T_MULT 
%token T_DIV 
%token T_AND 
%token T_OR
%token T_STRING
%token T_VOID
%token T_NULL
%token T_ID
%token T_PRINT

%%

Goal
    : MainClass ClassDeclarationStar { printf("**Goal**") }
    ;

MainClass
    : T_CLASS Identifier T_LBRACE T_PUBLIC T_STATIC T_VOID T_MAIN T_LPAREN T_STRING T_LBRACK T_RBRACK Identifier T_RPAREN T_LBRACE Statement T_RBRACE T_RBRACE { printf("**MainClass**") }
    ;

ClassDeclaration
    : T_CLASS Identifier T_EXTENDS Identifier T_LBRACE VarDeclarationStar MethodDeclarationStar T_RBRACE { printf("**ClassDeclaration1**") }
    | T_CLASS Identifier T_LBRACE VarDeclarationStar MethodDeclarationStar T_RBRACE                      { printf("**ClassDeclaration2**") }
    ;

ClassDeclarationStar
    :                          { printf("**ClassDeclarationStar1**") }
    | ClassDeclarationStarFake { printf("**ClassDeclarationStar2**") }
    ;

ClassDeclarationStarFake
    : ClassDeclaration                        { printf("**ClassDeclarationStarFake1**") }
    | ClassDeclarationStarFake VarDeclaration { printf("**ClassDeclarationStarFake2**") }
    ;

MethodDeclarationStar
    :                           { printf("**MethodDeclarationStar1**") }
    | MethodDeclarationStarFake { printf("**MethodDeclarationStar2**") }
    ;

MethodDeclarationStarFake
    : MethodDeclaration                           { printf("**MethodDeclarationStarFake1**") }
    | MethodDeclarationStarFake MethodDeclaration { printf("**MethodDeclarationStarFake2**") }
    ;

VarDeclaration
    : Type Identifier T_SEMICOLON { printf("**VarDeclaration**") }
    ;

VarDeclarationStar
    :                           { printf("**VarDeclarationStar1**") }
    | VarDeclarationStarFake    { printf("**VarDeclarationStar2**") }
    ;

VarDeclarationStarFake
    : VarDeclaration                        { printf("**VarDeclarationStarFake1**") }
    | VarDeclarationStarFake VarDeclaration { printf("**VarDeclarationStarFake2**") }
    ;

MethodDeclaration
    : T_PUBLIC Type Identifier T_LPAREN Type Identifier CommaTypeIdentifierStar T_RPAREN T_LBRACE VarDeclarationStar StatementStar T_RETURN Expression T_SEMICOLON T_RBRACE    { printf("**MethodDeclaration1**") }
    | T_PUBLIC Type Identifier T_LPAREN T_RPAREN T_LBRACE VarDeclarationStar StatementStar T_RETURN Expression T_SEMICOLON T_RBRACE                                                 { printf("**MethodDeclaration2**") }
    ;

CommaTypeIdentifierStar
    :                               { printf("**CommaTypeIdentifierStar1**") }
    | CommaTypeIdentifierStarFake   { printf("**CommaTypeIdentifierStar2**") }
    ;

CommaTypeIdentifierStarFake
    : T_COMMA Type Identifier                               { printf("**CommaTypeIdentifierStarFake1**") }
    | CommaTypeIdentifierStarFake T_COMMA Type Identifier   { printf("**CommaTypeIdentifierStarFake2**") }
    ;

Type
    : T_INT T_LBRACK T_RBRACK   { printf("**Type1**") }
    | T_BOOLEAN                 { printf("**Type2**") }
    | T_INT                     { printf("**Type3**") }
    | Identifier                { printf("**Type4**") }
    ;

Statement
    : T_LBRACE StatementStar T_RBRACE
    | T_IF T_LPAREN Expression T_RPAREN Statement T_ELSE Statement          { printf("**Statement1**") }
    | T_WHILE T_LPAREN Expression T_RPAREN Statement                        { printf("**Statement2**") }
    | T_PRINT T_LPAREN Expression T_LPAREN T_SEMICOLON                      { printf("**Statement3**") }
    | Identifier T_EQ Expression T_SEMICOLON                                { printf("**Statement4**") }
    | Identifier T_LBRACK Expression T_RBRACK T_EQ Expression T_SEMICOLON   { printf("**Statement5**") }
    ;

StatementStar
    :                   { printf("**StatementStar1**") }
    | StatementStarFake { printf("**StatementStar2**") }
    ;

StatementStarFake
    : Statement                     { printf("**StatementStarFake1**") }
    | StatementStarFake Statement   { printf("**StatementStarFake2**") }
    ;

Expression
    : Expression T_ANDAND Expression                                               { printf("**Statement1**") }
    | Expression T_LT Expression                                                   { printf("**Statement2**") }
    | Expression T_PLUS Expression                                                 { printf("**Statement3**") }
    | Expression T_MINUS Expression                                                { printf("**Statement4**") }
    | Expression T_MULT Expression                                                 { printf("**Statement5**") }
    | Expression T_LBRACK Expression T_RBRACK                                      { printf("**Statement6**") }
    | Expression T_DOT T_LENGTH                                                    { printf("**Statement7**") }
    | Expression T_DOT Identifier T_LPAREN Expression CommaExpressionStar T_RPAREN { printf("**Statement8**") }
    | Expression T_DOT Identifier T_LPAREN T_RPAREN                                { printf("**Statement9**") }
    | T_INT                                                                        { printf("**Statement10**") }
    | T_TRUE                                                                       { printf("**Statement11**") }
    | T_FALSE                                                                      { printf("**Statement12**") }
    | Identifier                                                                   { printf("**Statement13**") }
    | T_THIS                                                                       { printf("**Statement14**") }
    | T_NEW T_INT T_LBRACK Expression T_RBRACK                                     { printf("**Statement15**") }
    | T_NEW Identifier T_LPAREN T_RPAREN                                           { printf("**Statement16**") }
    | T_NOT Expression                                                             { printf("**Statement17**") }
    | T_LPAREN Expression T_RPAREN                                                 { printf("**Statement18**") }
    ;

CommaExpressionStar
    :                           { printf("**CommaExpressionStar1**") }
    | CommaExpressionStarFake   { printf("**CommaExpressionStar2**") }
    ;

CommaExpressionStarFake
    : T_COMMA Expression                            { printf("**CommaExpressionStarFake1**") }
    | CommaExpressionStarFake T_COMMA Expression    { printf("**CommaExpressionStarFake2**") }
    ;

Identifier
    : T_ID { printf("**Identifier**") }
    ;

%%