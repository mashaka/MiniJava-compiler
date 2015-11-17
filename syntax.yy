%{ 
    int yylex(void);
    void yyerror(const char *);
    #include <stdio.h>
    #include "interfaces.hpp"
// need to include classes.h file or smth like that
%}

%union{
    char* str;
    struct IGoal* iGoal;
    struct IMainClass* iMainClass;
    struct IClassDeclaration* iClassDeclaration;
    struct IClassDeclarationList* iClassDeclarationList;
    struct IVarDeclaration* iVarDeclaration;
    struct IVarDeclarationList* iVarDeclarationList;
    struct IMethodDeclaration* iMethodDeclaration;
    struct IMethodDeclarationList* iMethodDeclarationList;
    struct IType* iType;
    struct ICommaTypeIdentifierList* iCommaTypeIdentifierList;
    struct IStatement* iStatement;
    struct IStatementList* iStatementList;
    struct IExpression* iExpression;
    struct ICommaExpressionList* iCommaExpressionList;
}

%token T_BOOLEAN T_BREAK T_CASE T_CLASS T_CONTINUE T_ELSE T_EXTENDS T_DEFAULT T_INT T_NEW T_IF T_PUBLIC T_SWITCH T_RETURN T_STATIC T_WHILE T_THIS T_NULL_LITERAL T_LENGTH T_TRUE T_FALSE T_MAIN T_LPAREN T_RPAREN T_LBRACE T_RBRACE T_LBRACK T_RBRACK T_SEMICOLON T_COMMA T_DOT T_EQ T_LT T_GT T_LET T_GET T_NOT T_COLON T_ANDAND T_OROR T_PLUS T_MINUS T_MULT T_DIV T_AND T_OR T_STRING T_VOID T_NULL T_PRINT
%token <str> T_ID T_NUM


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

%type <iGoal> Goal
%type <iMainClass> MainClass
%type <iClassDeclaration> ClassDeclaration
%type <iClassDeclarationList> ClassDeclarationList
%type <iVarDeclaration> VarDeclaration
%type <iVarDeclarationList> VarDeclarationList
%type <iMethodDeclaration> MethodDeclaration
%type <iMethodDeclarationList> MethodDeclarationList
%type <iType> Type
%type <iCommaTypeIdentifierList> CommaTypeIdentifierList
%type <iStatement> Statement
%type <iStatementList> StatementList
%type <iExpression> Expression
%type <iCommaExpressionList> CommaExpressionList

%%

Goal
    : MainClass ClassDeclarationList { $$ = new Goal($1, $2); }
    ;

MainClass
    : T_CLASS T_ID T_LBRACE T_PUBLIC T_STATIC T_VOID T_MAIN T_LPAREN T_STRING T_LBRACK T_RBRACK T_ID T_RPAREN T_LBRACE Statement T_RBRACE T_RBRACE { $$ = new MainClass($2, $12, $15); }
    ;

ClassDeclaration
    : T_CLASS T_ID T_EXTENDS T_ID T_LBRACE VarDeclarationList MethodDeclarationList T_RBRACE { $$ = new ClassDeclaration1($2, $4, $6, $7); }
    | T_CLASS T_ID T_LBRACE VarDeclarationList MethodDeclarationList T_RBRACE                { $$ = new ClassDeclaration2($2, $4, $5);     }
    ;

ClassDeclarationList
    : %empty                                { $$ = 0;                                }
    | ClassDeclaration ClassDeclarationList { $$ = new ClassDeclarationList($1, $2); }
    ;

VarDeclaration
    : Type T_ID T_SEMICOLON { $$ = new VarDeclaration($1, $2); }
    ;

VarDeclarationList
    : %empty                            { $$ = 0;                              }
    | VarDeclarationList VarDeclaration { $$ = new VarDeclarationList($1, $2); }
    ;

MethodDeclaration
    : T_PUBLIC Type T_ID T_LPAREN Type T_ID CommaTypeIdentifierList T_RPAREN T_LBRACE VarDeclarationList StatementList T_RETURN Expression T_SEMICOLON T_RBRACE { $$ = new MethodDeclaration1($2, $3, $5, $6, $7, $10, $11, $13); }
    | T_PUBLIC Type T_ID T_LPAREN T_RPAREN T_LBRACE VarDeclarationList StatementList T_RETURN Expression T_SEMICOLON T_RBRACE                                   { $$ = new MethodDeclaration2($2, $3, $7, $8, $10);               }
    ;

MethodDeclarationList
    : %empty                                    { $$ = 0;                                 }
    | MethodDeclaration MethodDeclarationList   { $$ = new MethodDeclarationList($1, $2); }
    ;

CommaTypeIdentifierList
    : %empty                                      { $$ = 0;                                       }
    | T_COMMA Type T_ID CommaTypeIdentifierList   { $$ = new CommaTypeIdentifierList($2, $3, $4); }
    ;

Type
    : T_INT T_LBRACK T_RBRACK { $$ = new TypeIntArray();     }
    | T_BOOLEAN               { $$ = new TypeBoolean();      }
    | T_INT                   { $$ = new TypeInt();          }
    | T_ID                    { $$ = new TypeIdentifier($1); }
    ;

Statement
    : T_LBRACE StatementList T_RBRACE                               { $$ = new StatementListBraced($2);          }
    | T_IF T_LPAREN Expression T_RPAREN Statement T_ELSE Statement  { $$ = new StatementIf($3, $5, $7);          }
    | T_WHILE T_LPAREN Expression T_RPAREN Statement                { $$ = new StatementWhile($3, $5);           }
    | T_PRINT T_LPAREN Expression T_RPAREN T_SEMICOLON              { $$ = new StatementPrint($3);               }
    | T_ID T_EQ Expression T_SEMICOLON                              { $$ = new StatementIdentifier1($1, $3);     }
    | T_ID T_LBRACK Expression T_RBRACK T_EQ Expression T_SEMICOLON { $$ = new StatementIdentifier2($1, $3, $6); }
    ;

StatementList
    : %empty                    { $$ = new 0;       }
    | Statement StatementList   { $$ = new StatementList($1, $2); }
    ;

Expression
    : Expression T_ANDAND Expression                                         { $$ = new ExpressionBinOp($1, B_ANDAND, $3); }
    | Expression T_LT Expression                                             { $$ = new ExpressionBinOp($1, B_LT,     $3); }
    | Expression T_PLUS Expression                                           { $$ = new ExpressionAriOp($1, A_PLUS,   $3); }
    | Expression T_MINUS Expression                                          { $$ = new ExpressionAriOp($1, A_MINUS,  $3); }
    | Expression T_MULT Expression                                           { $$ = new ExpressionAriOp($1, A_MULT,   $3); }
    | Expression T_LBRACK Expression T_RBRACK                                { $$ = new ExpressionBracks($1, $3);          }
    | Expression T_DOT T_LENGTH                                              { $$ = new ExpressionLength($1);              }
    | Expression T_DOT T_ID T_LPAREN Expression CommaExpressionList T_RPAREN { $$ = new ExpressionMethod($1, $3, $5, $6);  }
    | Expression T_DOT T_ID T_LPAREN T_RPAREN                                { $$ = new ExpressionEmptyMethod($1, $3);     }
    | T_NUM                                                                  { $$ = new ExpressionNum($1);                 }
    | T_TRUE                                                                 { $$ = new ExpressionLogOp(L_TRUE);           }
    | T_FALSE                                                                { $$ = new ExpressionLogOp(L_FALSE);          }
    | T_ID                                                                   { $$ = new ExpressionId($1);                  }
    | T_THIS                                                                 { $$ = new ExpressionThis();                  }
    | T_NEW T_INT T_LBRACK Expression T_RBRACK                               { $$ = new ExpressionNew($4);                 }
    | T_NEW T_ID T_LPAREN T_RPAREN                                           { $$ = new ExpressionEmptyNew($2);            }
    | T_NOT Expression                                                       { $$ = new ExpressionNot($2);                 }
    | T_LPAREN Expression T_RPAREN                                           { $$ = new ExpressionParens($2);              }
    ;

CommaExpressionList
    : %empty                                    { $$ = 0;                               }
    | T_COMMA Expression CommaExpressionList    { $$ = new CommaExpressionList($2, $3); }
    ;

%%