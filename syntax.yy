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

%%

Goal
	: MainClass ( ClassDeclaration )* { printf("**Goal**") }
	;

MainClass
	: T_CLASS Identifier T_LBRACE T_PUBLIC T_STATIC T_VOID "main" T_LPAREN T_STRING T_LBRACK T_RBRACK Identifier T_RPAREN T_LBRACE Statement T_RBRACE T_RBRACE { printf("**MainClass**") }
	;

ClassDeclaration
	: T_CLASS Identifier ( T_EXTENDS Identifier )? T_LBRACE ( VarDeclaration )* ( MethodDeclaration )* T_RBRACE { printf("**ClassDeclaration**") }
	;

VarDeclaration
	: Type Identifier ";" { printf("**VarDeclaration**") }
	;


%%