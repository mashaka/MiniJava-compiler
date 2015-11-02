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
    : MainClass ClassDeclarationStar { Goal($1, $2); printf("**Goal**"); }
    ;

MainClass
    : T_CLASS T_ID T_LBRACE T_PUBLIC T_STATIC T_VOID T_MAIN T_LPAREN T_STRING T_LBRACK T_RBRACK T_ID T_RPAREN T_LBRACE Statement T_RBRACE T_RBRACE { MainClass($15); printf("**MainClass**"); }
    ;

ClassDeclaration
    : T_CLASS T_ID T_EXTENDS T_ID T_LBRACE VarDeclarationStar MethodDeclarationStar T_RBRACE { ClassDeclaration1($6, $7); printf("**ClassDeclaration1**"); }
    | T_CLASS T_ID T_LBRACE VarDeclarationStar MethodDeclarationStar T_RBRACE                { ClassDeclaration2($4, $5); printf("**ClassDeclaration2**"); }
    ;

ClassDeclarationStar
    : %empty                                { ClassDeclarationStar1();       printf("**ClassDeclarationStar1**"); }
    | ClassDeclaration ClassDeclarationStar { ClassDeclarationStar2($1, $2); printf("**ClassDeclarationStar2**"); }
    ;

VarDeclaration
    : Type T_ID T_SEMICOLON { VarDeclaration($1); printf("**VarDeclaration**"); }
    ;

VarDeclarationStar
    : %empty                            { VarDeclarationStar1();       printf("**VarDeclarationStar1**"); }
    | VarDeclarationStar VarDeclaration { VarDeclarationStar2($1, $2); printf("**VarDeclarationStar2**"); }
    ;

MethodDeclaration
    : T_PUBLIC Type T_ID T_LPAREN Type T_ID CommaTypeIdentifierStar T_RPAREN T_LBRACE VarDeclarationStar StatementStar T_RETURN Expression T_SEMICOLON T_RBRACE { MethodDeclaration1($2, $5, $7, $10, $11, $13); printf("**MethodDeclaration1**"); }
    | T_PUBLIC Type T_ID T_LPAREN T_RPAREN T_LBRACE VarDeclarationStar StatementStar T_RETURN Expression T_SEMICOLON T_RBRACE                                   { MethodDeclaration2($2, $7, $8, $10); printf("**MethodDeclaration2**"); }
    ;

MethodDeclarationStar
    : %empty                                    { MethodDeclarationStar1();       printf("**MethodDeclarationStar1**"); }
    | MethodDeclaration MethodDeclarationStar   { MethodDeclarationStar2($1, $2); printf("**MethodDeclarationStar2**"); }
    ;

CommaTypeIdentifierStar
    : %empty                                      { CommaTypeIdentifierStar1();       printf("**CommaTypeIdentifierStar1**"); }
    | T_COMMA Type T_ID CommaTypeIdentifierStar   { CommaTypeIdentifierStar2($2, $4); printf("**CommaTypeIdentifierStar2**"); }
    ;

Type
    : T_INT T_LBRACK T_RBRACK { TypeIntArray();   printf("**TypeIntArray**"); }
    | T_BOOLEAN               { TypeBoolean();    printf("**TypeBoolean**"); }
    | T_INT                   { TypeInt();        printf("**TypeInt**"); }
    | T_ID                    { TypeIdentifier(); printf("**TypeIdentifier**"); }
    ;

Statement
    : T_LBRACE StatementStar T_RBRACE                               { StatementStarBraced($2);      printf("**StatementStarBraced**"); }
    | T_IF T_LPAREN Expression T_RPAREN Statement T_ELSE Statement  { StatementIf($3, $5, $7);      printf("**StatementIf**"); }
    | T_WHILE T_LPAREN Expression T_RPAREN Statement                { StatementWhile($3, $5);       printf("**StatementWhile**"); }
    | T_PRINT T_LPAREN Expression T_RPAREN T_SEMICOLON              { StatementPrint($3);           printf("**StatementPrint**"); }
    | T_ID T_EQ Expression T_SEMICOLON                              { StatementIdentifier1($3);     printf("**StatementIdentifier1**"); }
    | T_ID T_LBRACK Expression T_RBRACK T_EQ Expression T_SEMICOLON { StatementIdentifier2($3, $6); printf("**StatementIdentifier2**"); }
    ;

StatementStar
    : %empty                    { StatementStar1();       printf("**StatementStar1**"); }
    | Statement StatementStar   { StatementStar2($1, $2); printf("**StatementStar2**"); }
    ;

Expression
    : Expression T_ANDAND Expression                                         { ExpressionAndAnd($1, $3);     printf("**ExpressionAndAnd**"); }
    | Expression T_LT Expression                                             { ExpressionLessThen($1, $3);   printf("**ExpressionLessThen**"); }
    | Expression T_PLUS Expression                                           { ExpressionPlus($1, $3);       printf("**ExpressionPlus**"); }
    | Expression T_MINUS Expression                                          { ExpressionMinus($1, $3);      printf("**ExpressionMinus**"); }
    | Expression T_MULT Expression                                           { ExpressionMult($1, $3);       printf("**ExpressionMult**"); }
    | Expression T_LBRACK Expression T_RBRACK                                { ExpressionBracks($1, $3);     printf("**ExpressionBracks**"); }
    | Expression T_DOT T_LENGTH                                              { ExpressionLength($1);         printf("**ExpressionLength**"); }
    | Expression T_DOT T_ID T_LPAREN Expression CommaExpressionStar T_RPAREN { ExpressionMethod($1, $5, $6); printf("**ExpressionMethod**"); }
    | Expression T_DOT T_ID T_LPAREN T_RPAREN                                { ExpressionEmptyMethod($1);    printf("**ExpressionEmptyMethod**"); }
    | T_INT                                                                  { ExpressionInt();              printf("**ExpressionInt**"); }
    | T_TRUE                                                                 { ExpressionTrue();             printf("**ExpressionTrue**"); }
    | T_FALSE                                                                { ExpressionFalse();            printf("**ExpressionFalse**"); }
    | T_ID                                                                   { ExpressionId();               printf("**ExpressionId**"); }
    | T_THIS                                                                 { ExpressionThis();             printf("**ExpressionThis**"); }
    | T_NEW T_INT T_LBRACK Expression T_RBRACK                               { ExpressionNew($4);            printf("**ExpressionNew**"); }
    | T_NEW T_ID T_LPAREN T_RPAREN                                           { ExpressionEmptyNew();         printf("**ExpressionEmptyNew**"); }
    | T_NOT Expression                                                       { ExpressionNot($2);            printf("**ExpressionNot**"); }
    | T_LPAREN Expression T_RPAREN                                           { ExpressionParens($2);         printf("**ExpressionParens**"); }
    ;

CommaExpressionStar
    : %empty                                    { CommaExpressionStar1();       printf("**CommaExpressionStar1**"); }
    | T_COMMA Expression CommaExpressionStar    { CommaExpressionStar2($1, $2); printf("**CommaExpressionStar2**"); }
    ;

%%