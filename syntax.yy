%{ 
    int yylex(void);
    void yyerror(const char *);
    #include <stdio.h>
    #include "AcceptVisitor.hpp"
    extern FILE * yyin;
    Goal* root;
%}

%union{
    char str[4096];
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

%token T_BOOLEAN T_BREAK T_CASE T_CLASS T_CONTINUE T_ELSE T_EXTENDS T_DEFAULT T_INT T_NEW T_IF T_PUBLIC T_SWITCH T_RETURN T_STATIC T_WHILE T_THIS T_NULL_LITERAL T_LENGTH T_TRUE T_FALSE T_MAIN T_LPAREN T_RPAREN T_LBRACE T_RBRACE T_LBRACK T_RBRACK T_SEMICOLON T_COMMA T_DOT T_EQ T_LT T_GT T_LET T_GET T_NOT T_COLON T_ANDAND T_OROR T_PLUS T_MINUS T_MULT T_DIV T_AND T_OR T_VOID T_NULL T_PRINT
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

%type <iGoal> GoalNode
%type <iMainClass> MainClassNode
%type <iClassDeclaration> ClassDeclarationNode
%type <iClassDeclarationList> ClassDeclarationListNode
%type <iVarDeclaration> VarDeclarationNode
%type <iVarDeclarationList> VarDeclarationListNode
%type <iMethodDeclaration> MethodDeclarationNode
%type <iMethodDeclarationList> MethodDeclarationListNode
%type <iType> TypeNode
%type <iCommaTypeIdentifierList> CommaTypeIdentifierListNode
%type <iStatement> StatementNode
%type <iStatementList> StatementListNode
%type <iExpression> ExpressionNode
%type <iCommaExpressionList> CommaExpressionListNode

%%

GoalNode
    : MainClassNode ClassDeclarationListNode { 
    root = new Goal($1, $2);
    $$ = root; }
    ;

MainClassNode
    : T_CLASS T_ID T_LBRACE T_PUBLIC T_STATIC T_VOID T_MAIN T_LPAREN T_ID T_LBRACK T_RBRACK T_ID T_RPAREN T_LBRACE StatementNode T_RBRACE T_RBRACE { $$ = new MainClass($2, $12, $15); }
    ;

ClassDeclarationNode
    : T_CLASS T_ID T_EXTENDS T_ID T_LBRACE VarDeclarationListNode MethodDeclarationListNode T_RBRACE { $$ = new ClassDeclaration1($2, $4, $6, $7); }
    | T_CLASS T_ID T_LBRACE VarDeclarationListNode MethodDeclarationListNode T_RBRACE                { $$ = new ClassDeclaration2($2, $4, $5);     }
    ;

ClassDeclarationListNode
    : %empty                                { $$ = 0;                                }
    | ClassDeclarationNode ClassDeclarationListNode { $$ = new ClassDeclarationList($1, $2); }
    ;

VarDeclarationNode
    : TypeNode T_ID T_SEMICOLON { $$ = new VarDeclaration($1, $2); }
    ;

VarDeclarationListNode
    : %empty                            { $$ = 0;                              }
    | VarDeclarationListNode VarDeclarationNode { $$ = new VarDeclarationList($1, $2); }
    ;

MethodDeclarationNode
    : T_PUBLIC TypeNode T_ID T_LPAREN TypeNode T_ID CommaTypeIdentifierListNode T_RPAREN T_LBRACE VarDeclarationListNode StatementListNode T_RETURN ExpressionNode T_SEMICOLON T_RBRACE { $$ = new MethodDeclaration1($2, $3, $5, $6, $7, $10, $11, $13); }
    | T_PUBLIC TypeNode T_ID T_LPAREN T_RPAREN T_LBRACE VarDeclarationListNode StatementListNode T_RETURN ExpressionNode T_SEMICOLON T_RBRACE                                   { $$ = new MethodDeclaration2($2, $3, $7, $8, $10);               }
    ;

MethodDeclarationListNode
    : %empty                                    { $$ = 0;                                 }
    | MethodDeclarationNode MethodDeclarationListNode   { $$ = new MethodDeclarationList($1, $2); }
    ;

CommaTypeIdentifierListNode
    : %empty                                      { $$ = 0;                                       }
    | T_COMMA TypeNode T_ID CommaTypeIdentifierListNode   { $$ = new CommaTypeIdentifierList($2, $3, $4); }
    ;

TypeNode
    : T_INT T_LBRACK T_RBRACK { $$ = new TypeIntArray();     }
    | T_BOOLEAN               { $$ = new TypeBoolean();      }
    | T_INT                   { $$ = new TypeInt();          }
    | T_ID                    { $$ = new TypeIdentifier($1); }
    ;

StatementNode
    : T_LBRACE StatementListNode T_RBRACE                               { $$ = new StatementListBraced($2);          }
    | T_IF T_LPAREN ExpressionNode T_RPAREN StatementNode T_ELSE StatementNode  { $$ = new StatementIf($3, $5, $7);          }
    | T_WHILE T_LPAREN ExpressionNode T_RPAREN StatementNode                { $$ = new StatementWhile($3, $5);           }
    | T_PRINT T_LPAREN ExpressionNode T_RPAREN T_SEMICOLON              { $$ = new StatementPrint($3);               }
    | T_ID T_EQ ExpressionNode T_SEMICOLON                              { $$ = new StatementIdentifier1($1, $3);     }
    | T_ID T_LBRACK ExpressionNode T_RBRACK T_EQ ExpressionNode T_SEMICOLON { $$ = new StatementIdentifier2($1, $3, $6); }
    ;

StatementListNode
    : %empty                    { $$ = 0;     }
    | StatementNode StatementListNode   { $$ = new StatementList($1, $2); }
    ;

ExpressionNode
    : ExpressionNode T_ANDAND ExpressionNode                                         { $$ = new ExpressionBinOp($1, B_ANDAND, $3); }
    | ExpressionNode T_LT ExpressionNode                                             { $$ = new ExpressionBinOp($1, B_LT,     $3); }
    | ExpressionNode T_PLUS ExpressionNode                                           { $$ = new ExpressionAriOp($1, A_PLUS,   $3); }
    | ExpressionNode T_MINUS ExpressionNode                                          { $$ = new ExpressionAriOp($1, A_MINUS,  $3); }
    | ExpressionNode T_MULT ExpressionNode                                           { $$ = new ExpressionAriOp($1, A_MULT,   $3); }
    | ExpressionNode T_LBRACK ExpressionNode T_RBRACK                                { $$ = new ExpressionBracks($1, $3);          }
    | ExpressionNode T_DOT T_LENGTH                                              { $$ = new ExpressionLength($1);              }
    | ExpressionNode T_DOT T_ID T_LPAREN ExpressionNode CommaExpressionListNode T_RPAREN { $$ = new ExpressionMethod($1, $3, $5, $6);  }
    | ExpressionNode T_DOT T_ID T_LPAREN T_RPAREN                                        { $$ = new ExpressionEmptyMethod($1, $3);     }
    | T_NUM                                                                              { $$ = new ExpressionNum($1);                 }
    | T_TRUE                                                                             { $$ = new ExpressionLogOp(L_TRUE);           }
    | T_FALSE                                                                            { $$ = new ExpressionLogOp(L_FALSE);          }
    | T_ID                                                                               { $$ = new ExpressionId($1);                  }
    | T_THIS                                                                             { $$ = new ExpressionThis();                  }
    | T_NEW T_INT T_LBRACK ExpressionNode T_RBRACK                               { $$ = new ExpressionNew($4);                 }
    | T_NEW T_ID T_LPAREN T_RPAREN                                           { $$ = new ExpressionEmptyNew($2);            }
    | T_NOT ExpressionNode                                                       { $$ = new ExpressionNot($2);                 }
    | T_LPAREN ExpressionNode T_RPAREN                                           { $$ = new ExpressionParens($2);              }
    ;

CommaExpressionListNode
    : %empty                                    { $$ = 0;                               }
    | T_COMMA ExpressionNode CommaExpressionListNode    { $$ = new CommaExpressionList($2, $3); }
    ;

%%