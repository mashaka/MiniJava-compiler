%{

	#include "syntax.tab.hh"
    #include <stdio.h>

	void yyerror (char const *s) {
		fprintf (stderr, "%s\n", s);
	}

    int line_count = 0;
    int pos_in_line = 0;

    void change_line() {
    	line_count++;
    	pos_in_line = 0;
    }

    void update_location(int len) {
    	// printf("%d:%d-%d ", line_count, pos_in_line, pos_in_line+len-1);
    	pos_in_line += len;
    }
%}

%option noyywrap

%%

\/\*.*\*\/     			/* comment */
[ ]						{ 	
							pos_in_line++;
							// printf(" ");
						}
[\t]                 	{ 	
							pos_in_line++;
							// printf("\t");
						}
[\n]					{ 
							change_line();
							// printf("\n");
							change_line();
						}

"boolean"				{
							update_location(yyleng);
							// printf("BOOLEAN");
							return T_BOOLEAN;
						}
"break"					{
							update_location(yyleng);
							// printf("BREAK");
							return T_BREAK;
						}
"case"					{
							update_location(yyleng);
							// printf("CASE");
							return T_CASE;
						}
"class"					{
							update_location(yyleng);
							// printf("CLASS");
							return T_CLASS;
						}
"continue"				{
							update_location(yyleng);
							// printf("CONTINUE");
							return T_CONTINUE;
						}
"else"					{
							update_location(yyleng);
							// printf("ELSE");
							return T_ELSE;
						}
"extends"				{
							update_location(yyleng);
							// printf("EXTENDS");
							return T_EXTENDS;
						}
"default"				{
							update_location(yyleng);
							// printf("DEFAULT");
							return T_DEFAULT;
						}
"int"					{
							update_location(yyleng);
							// printf("INT");
							return T_INT;
						}
"new"					{
							update_location(yyleng);
							// printf("NEW");
							return T_NEW;
						}
"if"					{
							update_location(yyleng);
							// printf("IF");
							return T_IF;
						}
"public"				{
							update_location(yyleng);
							// printf("PUBLIC");
							return T_PUBLIC;
						}
"switch"				{
							update_location(yyleng);
							// printf("SWITCH");
							return T_SWITCH;
						}
"return"				{
							update_location(yyleng);
							// printf("RETURN");
							return T_RETURN;
						}
"static"				{
							update_location(yyleng);
							// printf("STATIC");
							return T_STATIC;
						}
"while"					{
							update_location(yyleng);
							// printf("WHILE");
							return T_WHILE;
						}
"void"					{
							update_location(yyleng);
							// printf("VOID");
							return T_VOID;
						}
"this"					{
							update_location(yyleng);
							// printf("THIS");
							return T_THIS;
						}
"null"					{
							update_location(yyleng);
							// printf("NULL LITERAL");
							return T_NULL;
						}
"length"				{
							update_location(yyleng);
							// printf("LENGTH");
							return T_LENGTH;
						}
"true"					{
							update_location(yyleng);
							// printf("TRUE");
							return T_TRUE;
						}
"false"					{
							update_location(yyleng);
							// printf("FALSE");
							return T_FALSE;
						}
"main"					{
							update_location(yyleng);
							// printf("MAIN");
							return T_MAIN;
						}
"("						{
							update_location(yyleng);
							// printf("LPAREN");
							return T_LPAREN;
						}
")"						{
							update_location(yyleng);
							// printf("RPAREN");
							return T_RPAREN;
						}
"{"						{
							update_location(yyleng);
							// printf("LBRACE");
							return T_LBRACE;
						}
"}"						{
							update_location(yyleng);
							// printf("RBRACE");
							return T_RBRACE;
						}
"["						{
							update_location(yyleng);
							// printf("LBRACK");
							return T_LBRACK;
						}
"]"						{
							update_location(yyleng);
							// printf("RBRACK");
							return T_RBRACK;
						}
";"						{
							update_location(yyleng);
							// printf("SEMICOLON");
							return T_SEMICOLON;
						}
","						{
							update_location(yyleng);
							// printf("COMMA");
							return T_COMMA;
						}
"."						{
							update_location(yyleng);
							// printf("DOT");
							return T_DOT;
						}
"="						{
							update_location(yyleng);
							// printf("EQ");
							return T_EQ;
						}
"<"						{
							update_location(yyleng);
							// printf("LT");
							return T_LT;
						}
">"						{
							update_location(yyleng);
							// printf("GT");
							return T_GT;
						}
"<="					{
							update_location(yyleng);
							// printf("LET");
							return T_LET;
						}
">="					{
							update_location(yyleng);
							// printf("GET");
							return T_GET;
						}
"!"						{
							update_location(yyleng);
							// printf("NOT");
							return T_NOT;
						}
":"						{
							update_location(yyleng);
							// printf("COLON");
							return T_COLON;
						}
"&&"					{
							update_location(yyleng);
							// printf("ANDAND");
							return T_ANDAND;
						}
"||"					{
							update_location(yyleng);
							// printf("OROR");
							return T_OROR;
						}
"+"						{
							update_location(yyleng);
							// printf("PLUS");
							return T_PLUS;
						}
"-"						{
							update_location(yyleng);
							// printf("MINUS");
							return T_MINUS;
						}
"*"						{
							update_location(yyleng);
							// printf("MULT");
							return T_MULT;
						}
"/"						{
							update_location(yyleng);
							// printf("DIV");
							return T_DIV;
						}
"&"						{
							update_location(yyleng);
							// printf("AND");
							return T_AND;
						}
"|"						{
							update_location(yyleng);
							// printf("OR");
							return T_OR;
						}
"System.out.println"	{
							update_location(yyleng);
							// printf("PRINT");
							return T_PRINT;
						}

[_a-zA-Z]+[_a-zA-Z0-9]* {
							update_location(yyleng);
							strcpy(yylval.str, yytext);
							// printf("ID(%s)", yytext);
							return T_ID;
						}
[1-9]+[0-9]*			{
							update_location(yyleng);
							strcpy(yylval.str, yytext);
							// printf("NUM(%s)", yytext); 
							return T_NUM;
						}
.                       { 	fprintf(stderr, "Unknown token: %s\n", yytext); exit(EXIT_FAILURE); }

%%
