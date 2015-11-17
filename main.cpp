#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <iostream>
#include "interfaces.hpp"
#include "visitor.cpp"

extern FILE* yyin;
extern Goal* root;

// extern int yyparse(void);
// extern "C" int yyparse (void);

extern int yylex(void);
extern int yyparse(void);

// int yylex();
// extern void yyerror(string s);

using namespace std;

string get_str(int number) {
    char buf[256];
    sprintf(buf, "%d", number);
    return string(buf);
}

int main(int argc, char **argv)
{
    FILE *handle;
    if (argc != 2) {
            cerr << "Usage: " << argv[0] << " program\n";
            exit(1);
    }
    if (!(handle = fopen(argv[1], "r"))) {
            cerr << "Error: cannot open file\n";
            exit(1);
    }

    yyin = handle;
    // yylex();
    
    yyparse();

    Interpreter print_visitor;
    root->accept(&print_visitor);
}

// void yyerror(string s)
// {
//         cerr << "Parser error: " << s << "\n";
//         exit(1);
// }
