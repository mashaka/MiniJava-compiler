%{ 
    int yylex(void);
    void yyerror(const char *);
    #include <stdio.h>
    #include "interfaces.hpp"
// need to include classes.h file or smth like that
%}

%union{
    char* str;
    IAbstract* node;
}

%token T_BOOLEAN
%token T_BREAK
%token T_CASE
%token T_CLASS
%token T_CONTINUE
%token T_ELSE
%token T_EXTENDS
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
%token <str> T_ID
%token T_PRINT
%token <str> T_NUM

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

%type <node> Goal, MainClass, ClassDeclaration, ClassDeclarationStar, VarDeclaration, VarDeclarationStar, MethodDeclaration, MethodDeclarationStar, CommaTypeIdentifierStar, Type, Statement, StatementStar, Expression, CommaExpressionStar

%%

Goal
    : MainClass ClassDeclarationStar { $$ = new Goal(dynamic_cast<>($1), dynamic_cast<>($2)); }
    ;

MainClass
    : T_CLASS T_ID T_LBRACE T_PUBLIC T_STATIC T_VOID T_MAIN T_LPAREN T_STRING T_LBRACK T_RBRACK T_ID T_RPAREN T_LBRACE Statement T_RBRACE T_RBRACE { $$ = new MainClass(dynamic_cast<>($2), dynamic_cast<>($12), dynamic_cast<>($15)); }
    ;

ClassDeclaration
    : T_CLASS T_ID T_EXTENDS T_ID T_LBRACE VarDeclarationStar MethodDeclarationStar T_RBRACE { $$ = new ClassDeclaration1(dynamic_cast<>($2), dynamic_cast<>($4), dynamic_cast<>($6), dynamic_cast<>($7)); }
    | T_CLASS T_ID T_LBRACE VarDeclarationStar MethodDeclarationStar T_RBRACE                { $$ = new ClassDeclaration2(dynamic_cast<>($2), dynamic_cast<>($4), dynamic_cast<>($5));     }
    ;

ClassDeclarationStar
    : %empty                                { $$ = new ClassDeclarationStar1();       }
    | ClassDeclaration ClassDeclarationStar { $$ = new ClassDeclarationStar2(dynamic_cast<>($1), dynamic_cast<>($2)); }
    ;

VarDeclaration
    : Type T_ID T_SEMICOLON { $$ = new VarDeclaration(dynamic_cast<>($1), dynamic_cast<>($2)); }
    ;

VarDeclarationStar
    : %empty                            { $$ = new VarDeclarationStar1();       }
    | VarDeclarationStar VarDeclaration { $$ = new VarDeclarationStar2(dynamic_cast<>($1), dynamic_cast<>($2)); }
    ;

MethodDeclaration
    : T_PUBLIC Type T_ID T_LPAREN Type T_ID CommaTypeIdentifierStar T_RPAREN T_LBRACE VarDeclarationStar StatementStar T_RETURN Expression T_SEMICOLON T_RBRACE { $$ = new MethodDeclaration1(dynamic_cast<>($2), dynamic_cast<>($3), dynamic_cast<>($5), dynamic_cast<>($6), dynamic_cast<>($7), dynamic_cast<>($10), dynamic_cast<>($11), dynamic_cast<>($13)); }
    | T_PUBLIC Type T_ID T_LPAREN T_RPAREN T_LBRACE VarDeclarationStar StatementStar T_RETURN Expression T_SEMICOLON T_RBRACE                                   { $$ = new MethodDeclaration2(dynamic_cast<>($2), dynamic_cast<>($3), dynamic_cast<>($7), dynamic_cast<>($8), dynamic_cast<>($10));               }
    ;

MethodDeclarationStar
    : %empty                                    { $$ = new MethodDeclarationStar1();       }
    | MethodDeclaration MethodDeclarationStar   { $$ = new MethodDeclarationStar2(dynamic_cast<>($1), dynamic_cast<>($2)); }
    ;

CommaTypeIdentifierStar
    : %empty                                      { $$ = new CommaTypeIdentifierStar1();           }
    | T_COMMA Type T_ID CommaTypeIdentifierStar   { $$ = new CommaTypeIdentifierStar2(dynamic_cast<>($2), dynamic_cast<>($3), dynamic_cast<>($4)); }
    ;

Type
    : T_INT T_LBRACK T_RBRACK { $$ = new TypeIntArray();     }
    | T_BOOLEAN               { $$ = new TypeBoolean();      }
    | T_INT                   { $$ = new TypeInt();          }
    | T_ID                    { $$ = new TypeIdentifier(dynamic_cast<>($1)); }
    ;

Statement
    : T_LBRACE StatementStar T_RBRACE                               { $$ = new StatementStarBraced(dynamic_cast<>($2));          }
    | T_IF T_LPAREN Expression T_RPAREN Statement T_ELSE Statement  { $$ = new StatementIf(dynamic_cast<>($3), dynamic_cast<>($5), dynamic_cast<>($7));          }
    | T_WHILE T_LPAREN Expression T_RPAREN Statement                { $$ = new StatementWhile(dynamic_cast<>($3), dynamic_cast<>($5));           }
    | T_PRINT T_LPAREN Expression T_RPAREN T_SEMICOLON              { $$ = new StatementPrint(dynamic_cast<>($3));               }
    | T_ID T_EQ Expression T_SEMICOLON                              { $$ = new StatementIdentifier1(dynamic_cast<>($1), dynamic_cast<>($3));     }
    | T_ID T_LBRACK Expression T_RBRACK T_EQ Expression T_SEMICOLON { $$ = new StatementIdentifier2(dynamic_cast<>($1), dynamic_cast<>($3), dynamic_cast<>($6)); }
    ;

StatementStar
    : %empty                    { $$ = new StatementStar1();       }
    | Statement StatementStar   { $$ = new StatementStar2(dynamic_cast<>($1), dynamic_cast<>($2)); }
    ;

Expression
    : Expression T_ANDAND Expression                                         { $$ = new ExpressionAndAnd(dynamic_cast<>($1), dynamic_cast<>($3));         }
    | Expression T_LT Expression                                             { $$ = new ExpressionLessThen(dynamic_cast<>($1), dynamic_cast<>($3));       }
    | Expression T_PLUS Expression                                           { $$ = new ExpressionPlus(dynamic_cast<>($1), dynamic_cast<>($3));           }
    | Expression T_MINUS Expression                                          { $$ = new ExpressionMinus(dynamic_cast<>($1), dynamic_cast<>($3));          }
    | Expression T_MULT Expression                                           { $$ = new ExpressionMult(dynamic_cast<>($1), dynamic_cast<>($3));           }
    | Expression T_LBRACK Expression T_RBRACK                                { $$ = new ExpressionBracks(dynamic_cast<>($1), dynamic_cast<>($3));         }
    | Expression T_DOT T_LENGTH                                              { $$ = new ExpressionLength(dynamic_cast<>($1));             }
    | Expression T_DOT T_ID T_LPAREN Expression CommaExpressionStar T_RPAREN { $$ = new ExpressionMethod(dynamic_cast<>($1), dynamic_cast<>($3), dynamic_cast<>($5), dynamic_cast<>($6)); }
    | Expression T_DOT T_ID T_LPAREN T_RPAREN                                { $$ = new ExpressionEmptyMethod(dynamic_cast<>($1), dynamic_cast<>($3));    }
    | T_NUM                                                                  { $$ = new ExpressionNum(dynamic_cast<>($1));                }
    | T_TRUE                                                                 { $$ = new ExpressionTrue();                 }
    | T_FALSE                                                                { $$ = new ExpressionFalse();                }
    | T_ID                                                                   { $$ = new ExpressionId(dynamic_cast<>($1));                 }
    | T_THIS                                                                 { $$ = new ExpressionThis();                 }
    | T_NEW T_INT T_LBRACK Expression T_RBRACK                               { $$ = new ExpressionNew(dynamic_cast<>($4));                }
    | T_NEW T_ID T_LPAREN T_RPAREN                                           { $$ = new ExpressionEmptyNew(dynamic_cast<>($2));           }
    | T_NOT Expression                                                       { $$ = new ExpressionNot(dynamic_cast<>($2));                }
    | T_LPAREN Expression T_RPAREN                                           { $$ = new ExpressionParens(dynamic_cast<>($2));             }
    ;

CommaExpressionStar
    : %empty                                    { $$ = new CommaExpressionStar1();       }
    | T_COMMA Expression CommaExpressionStar    { $$ = new CommaExpressionStar2(dynamic_cast<>($2), dynamic_cast<>($3)); }
    ;

%%