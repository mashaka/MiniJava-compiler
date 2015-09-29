%{
    #include <stdio.h>
    int line_count = 0;
    int pos_in_line = 0;

    void change_line() {
    	line_count++;
    	pos_in_line = 0;
    }

    void update_location(int len) {
    	printf("%d:%d-%d ", line_count, pos_in_line, pos_in_line+len-1);
    	pos_in_line += len;
    }
%}

%option noyywrap

%%

\/\*.*\*\/     			/* comment */
[ ]						{ 	
							pos_in_line++;
							printf(" "); }
[\t]                 	{ 	
							pos_in_line++;
							printf("\t"); }
[\n]					{ 
							change_line();
							printf("\n");
							change_line();
						}

"boolean"				{ 	
							update_location(yyleng);
							printf("BOOLEAN ");
						}
"break"					{ 	
							update_location(yyleng);
							printf("BREAK ");
						}               
"case"					{ 	
							update_location(yyleng);
							printf("CASE ");
						}                
"class"					{ 	
							update_location(yyleng);
							printf("CLASS ");
						}
"continue"				{ 	
							update_location(yyleng);
							printf("CONTINUE ");
						}
"else"					{ 	
							update_location(yyleng);
							printf("ELSE ");
						}
"extends"				{ 	
							update_location(yyleng);
							printf("EXTENDS ");
						}
"float"					{ 	
							update_location(yyleng);
							printf("FLOAT ");
						}
"default"				{ 	
							update_location(yyleng);
							printf("DEFAULT ");
						}
"int"					{ 	
							update_location(yyleng);
							printf("INT ");
						}
"new"					{ 	
							update_location(yyleng);
							printf("NEW ");
						}
"if"					{ 	
							update_location(yyleng);
							printf("IF ");
						}
"public"				{ 	
							update_location(yyleng);
							printf("PUBLIC ");
						}
"switch"				{ 	
							update_location(yyleng);
							printf("SWITCH ");
						}
"return"				{ 	
							update_location(yyleng);
							printf("RETURN ");
						}
"static"				{ 	
							update_location(yyleng);
							printf("STATIC ");
						}
"while"					{ 	
							update_location(yyleng);
							printf("WHILE ");
						}
"this"					{ 	
							update_location(yyleng);
							printf("THIS ");
						}
"null"					{ 	
							update_location(yyleng);
							printf("NULL LITERAL ");
						}
")"						{ 	
							update_location(yyleng);
							printf("LPAREN ");
						}
"("						{ 	
							update_location(yyleng);
							printf("RPAREN ");
						}
"{"						{ 	
							update_location(yyleng);
							printf("LBRACE ");
						}
"}"						{ 	
							update_location(yyleng);
							printf("RBRACE ");
						}
"["						{ 	
							update_location(yyleng);
							printf("LBRACK ");
						}
"]"						{ 	
							update_location(yyleng);
							printf("RBRACK ");
						}
";"						{ 	
							update_location(yyleng);
							printf("SEMICOLON ");
						}
","						{ 	
							update_location(yyleng);
							printf("COMMA ");
						}
"."						{ 	
							update_location(yyleng);
							printf("DOT ");
						}
"="						{ 	
							update_location(yyleng);
							printf("EQ ");
						}
"<"						{ 	
							update_location(yyleng);
							printf("LT ");
						}
">"						{ 	
							update_location(yyleng);
							printf("GT ");
						}
"<="					{ 	
							update_location(yyleng);
							printf("LET ");
						}
">="					{ 	
							update_location(yyleng);
							printf("GET ");
						}
"!"						{ 	
							update_location(yyleng);
							printf("NOT ");
						}
":"						{ 	
							update_location(yyleng);
							printf("COLON ");
						}
"&&"					{ 	
							update_location(yyleng);
							printf("ANDAND ");
						}
"||"					{ 	
							update_location(yyleng);
							printf("OROR ");
						}
"+"						{ 	
							update_location(yyleng);
							printf("PLUS ");
						}
"-"						{ 	
							update_location(yyleng);
							printf("MINUS ");
						}
"*"						{ 	
							update_location(yyleng);
							printf("MULT ");
						}
"/"						{ 	
							update_location(yyleng);
							printf("DIV ");
						}
"&"						{ 	
							update_location(yyleng);
							printf("AND ");
						}
"|"						{ 	
							update_location(yyleng);
							printf("OR ");
						}
[_a-zA-Z]+[_a-zA-Z0-9]* { 	
							update_location(yyleng);
							printf("ID(%s) ", yytext);
						}
[1-9]+[0-9]*			{ 	
							update_location(yyleng);
							printf("INT(%s)", yytext); }
.                       { 	fprintf(stderr, "Unknown token: %s\n", yytext); exit(EXIT_FAILURE); }

%%
