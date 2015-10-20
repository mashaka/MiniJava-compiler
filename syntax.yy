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

%left T_COMMA
%left T_DOT
%left T_COLON
%left T_EQ T_LT T_GT T_LET T_GET
%left T_OROR
%left T_ANDAND
%left T_PLUS T_MINUS
%left T_MULT T_DIV
%left T_OR
%left T_AND

%right T_NOT

%nonassoc T_LPAREN T_RPAREN
%nonassoc T_LBRACK T_RBRACK
%nonassoc T_IF T_ELSE
%nonassoc T_LBRACE T_RBRACE

%%

Goal
    : MainClass ClassDeclarationStar { printf("**Goal**"); }
    ;

MainClass
    : T_CLASS T_ID T_LBRACE T_PUBLIC T_STATIC T_VOID T_MAIN T_LPAREN T_STRING T_LBRACK T_RBRACK T_ID T_RPAREN T_LBRACE Statement T_RBRACE T_RBRACE { printf("**MainClass**"); }
    ;

ClassDeclaration
    : T_CLASS T_ID T_EXTENDS T_ID T_LBRACE VarDeclarationStar MethodDeclarationStar T_RBRACE { printf("**ClassDeclaration1**"); }
    | T_CLASS T_ID T_LBRACE VarDeclarationStar MethodDeclarationStar T_RBRACE                { printf("**ClassDeclaration2**"); }
    ;

ClassDeclarationStar
    : %empty                                { printf("**ClassDeclarationStar1**"); }
    | ClassDeclaration ClassDeclarationStar { printf("**ClassDeclarationStar2**"); }
    ;

MethodDeclarationStar
    : %empty                                    { printf("**MethodDeclarationStar1**"); }
    | MethodDeclaration MethodDeclarationStar   { printf("**MethodDeclarationStar2**"); }
    ;

VarDeclaration
    : Type T_ID T_SEMICOLON { printf("**VarDeclaration**"); }
    ;

VarDeclarationStar
    : %empty                            { printf("**VarDeclarationStar1**"); }
    | VarDeclarationStar VarDeclaration { printf("**VarDeclarationStar2**"); }
    ;

MethodDeclaration
    : T_PUBLIC Type T_ID T_LPAREN Type T_ID CommaTypeIdentifierStar T_RPAREN T_LBRACE VarDeclarationStar StatementStar T_RETURN Expression T_SEMICOLON T_RBRACE { printf("**MethodDeclaration1**"); }
    | T_PUBLIC Type T_ID T_LPAREN T_RPAREN T_LBRACE VarDeclarationStar StatementStar T_RETURN Expression T_SEMICOLON T_RBRACE                                   { printf("**MethodDeclaration2**"); }
    ;

CommaTypeIdentifierStar
    : %empty                        { printf("**CommaTypeIdentifierStar1**"); }
    | T_COMMA Type T_ID CommaTypeIdentifierStar   { printf("**CommaTypeIdentifierStar2**"); }
    ;

Type
    : T_INT T_LBRACK T_RBRACK { printf("**Type1**"); }
    | T_BOOLEAN               { printf("**Type2**"); }
    | T_INT                   { printf("**Type3**"); }
    | T_ID                    { printf("**Type4**"); }
    ;

Statement
    : T_LBRACE StatementStar T_RBRACE
    | T_IF T_LPAREN Expression T_RPAREN Statement T_ELSE Statement  { printf("**Statement1**"); }
    | T_WHILE T_LPAREN Expression T_RPAREN Statement                { printf("**Statement2**"); }
    | T_PRINT T_LPAREN Expression T_RPAREN T_SEMICOLON              { printf("**Statement3**"); }
    | T_ID T_EQ Expression T_SEMICOLON                              { printf("**Statement4**"); }
    | T_ID T_LBRACK Expression T_RBRACK T_EQ Expression T_SEMICOLON { printf("**Statement5**"); }
    ;

StatementStar
    : %empty                    { printf("**StatementStar1**"); }
    | Statement StatementStar   { printf("**StatementStar2**"); }
    ;

Expression
    : Expression T_ANDAND Expression                                         { printf("**Expression1**"); }
    | Expression T_LT Expression                                             { printf("**Expression2**"); }
    | Expression T_PLUS Expression                                           { printf("**Expression3**"); }
    | Expression T_MINUS Expression                                          { printf("**Expression4**"); }
    | Expression T_MULT Expression                                           { printf("**Expression5**"); }
    | Expression T_LBRACK Expression T_RBRACK                                { printf("**Expression6**"); }
    | Expression T_DOT T_LENGTH                                              { printf("**Expression7**"); }
    | Expression T_DOT T_ID T_LPAREN Expression CommaExpressionStar T_RPAREN { printf("**Expression8**"); }
    | Expression T_DOT T_ID T_LPAREN T_RPAREN                                { printf("**Expression9**"); }
    | T_INT                                                                  { printf("**Expression10**"); }
    | T_TRUE                                                                 { printf("**Expression11**"); }
    | T_FALSE                                                                { printf("**Expression12**"); }
    | T_ID                                                                   { printf("**Expression13**"); }
    | T_THIS                                                                 { printf("**Expression14**"); }
    | T_NEW T_INT T_LBRACK Expression T_RBRACK                               { printf("**Expression15**"); }
    | T_NEW T_ID T_LPAREN T_RPAREN                                           { printf("**Expression16**"); }
    | T_NOT Expression                                                       { printf("**Expression17**"); }
    | T_LPAREN Expression T_RPAREN                                           { printf("**Expression18**"); }
    ;

CommaExpressionStar
    : %empty                                    { printf("**CommaExpressionStar1**"); }
    | T_COMMA Expression CommaExpressionStar    { printf("**CommaExpressionStar2**"); }
    ;

%%