%{
    #include <stdio.h>
%}

%option noyywrap

%%

"{"(\\.|[^"}"])*"}"     /* comment */
[ \t\n]                 /* whitespace */

"program"               { printf("program"); }
"begin"                 { printf("begin"  ); }
"end"                   { printf("end"    ); }
"var"                   { printf("var"    ); }
"integer"               { printf("integer"); }

"if"                    { printf("if"     ); }
"then"                  { printf("then"   ); }
"else"                  { printf("else"   ); }
"while"                 { printf("while"  ); }
"do"                    { printf("do"     ); }

"not"                   { printf("not"    ); }
"or"                    { printf("or"     ); }
"and"                   { printf("and"    ); }

"write"                 { printf("write"  ); }

";"                     { printf(";"      ); }
":"                     { printf(":"      ); }
":="                    { printf(":="     ); }
"+"                     { printf("+"      ); }
"-"                     { printf("-"      ); }
"*"                     { printf("*"      ); }
"/"                     { printf("/"      ); }
"div"                   { printf("div"    ); }
"mod"                   { printf("mod"    ); }
"("                     { printf("("      ); }
")"                     { printf(")"      ); }
"="                     { printf("="      ); }
"<>"                    { printf("<>"     ); }
">"                     { printf(">"      ); }
">="                    { printf(">="     ); }
"<"                     { printf("<"      ); }
"<="                    { printf("<="     ); }
"."                     { printf("."      ); }
","                     { printf(","      ); }

.                       { fprintf(stderr, "Unknown token: %s\n", yytext); exit(EXIT_FAILURE); }

%%
