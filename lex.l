%{
    #include <stdio.h>
%}

%option noyywrap

%%

\/\*.*\*\/     			/* comment */
[ ]						{ printf(" "); }
[\t]                 	{ printf("\t"); }
[\n]					{ printf("\n"); }

"boolean"				{ printf("BOOLEAN ");}
"break"					{ printf("BREAK ");}               
"case"					{ printf("CASE ");}                
"class"					{ printf("CLASS ");}
"continue"				{ printf("CONTINUE ");}
"else"					{ printf("ELSE ");}
"extends"				{ printf("EXTENDS ");}
"float"					{ printf("FLOAT ");}
"default"				{ printf("DEFAULT ");}
"int"					{ printf("INT ");}
"new"					{ printf("NEW ");}
"if"					{ printf("IF ");}
"public"				{ printf("PUBLIC ");}
"switch"				{ printf("SWITCH ");}
"return"				{ printf("RETURN ");}
"static"				{ printf("STATIC ");}
"while"					{ printf("WHILE ");}
"this"					{ printf("THIS ");}
"null"					{ printf("NULL LITERAL ");}
")"						{ printf("LPAREN ");}
"("						{ printf("RPAREN ");}
"{"						{ printf("LBRACE ");}
"}"						{ printf("RBRACE ");}
"["						{ printf("LBRACK ");}
"]"						{ printf("RBRACK ");}
";"						{ printf("SEMICOLON ");}
","						{ printf("COMMA ");}
"."						{ printf("DOT ");}
"="						{ printf("EQ ");}
"<"						{ printf("LT ");}
"!"						{ printf("NOT ");}
":"						{ printf("COLON ");}
"&&"					{ printf("ANDAND ");}
"||"					{ printf("OROR ");}
"+"						{ printf("PLUS ");}
"-"						{ printf("MINUS ");}
"*"						{ printf("MULT ");}
"/"						{ printf("DIV ");}
"&"						{ printf("AND ");}
"|"						{ printf("OR ");}
[_a-zA-Z]+[_a-zA-Z0-9]* { printf("ID(%s) ", yytext);}
[1-9]+[0-9]*			{ printf("INT(%s) ", yytext); }
.                       { fprintf(stderr, "Unknown token: %s\n", yytext); exit(EXIT_FAILURE); }

%%
