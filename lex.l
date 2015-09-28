%{
    #include <stdio.h>
%}

%option noyywrap

%%

"{"(\\.|[^"}"])*"}"     /* comment */
[ \t\n]                 /* whitespace */

"boolean"				{ printf("BOOLEAN");}
"break"					{ printf("BREAK");}               
"case"					{ printf("CASE");}                
"class"					{ printf("CLASS");}
"continue"				{ printf("CONTINUE");}
"else"					{ printf("ELSE");}
"extends"				{ printf("EXTENDS");}
"float"					{ printf("FLOAT");}
"default"				{ printf("DEFAULT");}
"int"					{ printf("INT");}
"new"					{ printf("NEW");}
"if"					{ printf("IF");}
"public"				{ printf("PUBLIC");}
"switch"				{ printf("SWITCH");}
"return"				{ printf("RETURN");}
"static"				{ printf("STATIC");}
"while"					{ printf("WHILE");}
"this"					{ printf("THIS");}
"null"					{ printf("NULL LITERAL");}
")"						{ printf("LPAREN");}
"("						{ printf("RPAREN");}
"{"						{ printf("LBRACE");}
"}"						{ printf("RBRACE");}
"["						{ printf("LBRACK");}
"]"						{ printf("RBRACK");}
";"						{ printf("SEMICOLON");}
","						{ printf("COMMA");}
"."						{ printf("DOT");}
"="						{ printf("EQ");}
"<"						{ printf("LT");}
"!"						{ printf("NOT");}
":"						{ printf("COLON");}
"&&"					{ printf("ANDAND");}
"||"					{ printf("OROR");}
"+"						{ printf("PLUS");}
"-"						{ printf("MINUS");}
"*"						{ printf("MULT");}
"/"						{ printf("DIV");}
"&"						{ printf("AND");}
"|"						{ printf("OR");}

.                       { fprintf(stderr, "Unknown token: %s\n", yytext); exit(EXIT_FAILURE); }

%%
