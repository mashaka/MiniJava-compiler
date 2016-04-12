/* A Bison parser, made by GNU Bison 3.0.2.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2013 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

#ifndef YY_YY_SYNTAX_TAB_HH_INCLUDED
# define YY_YY_SYNTAX_TAB_HH_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    T_BOOLEAN = 258,
    T_BREAK = 259,
    T_CASE = 260,
    T_CLASS = 261,
    T_CONTINUE = 262,
    T_ELSE = 263,
    T_EXTENDS = 264,
    T_DEFAULT = 265,
    T_INT = 266,
    T_NEW = 267,
    T_IF = 268,
    T_PUBLIC = 269,
    T_SWITCH = 270,
    T_RETURN = 271,
    T_STATIC = 272,
    T_WHILE = 273,
    T_THIS = 274,
    T_NULL_LITERAL = 275,
    T_LENGTH = 276,
    T_TRUE = 277,
    T_FALSE = 278,
    T_MAIN = 279,
    T_LPAREN = 280,
    T_RPAREN = 281,
    T_LBRACE = 282,
    T_RBRACE = 283,
    T_LBRACK = 284,
    T_RBRACK = 285,
    T_SEMICOLON = 286,
    T_COMMA = 287,
    T_DOT = 288,
    T_EQ = 289,
    T_LT = 290,
    T_GT = 291,
    T_LET = 292,
    T_GET = 293,
    T_NOT = 294,
    T_COLON = 295,
    T_ANDAND = 296,
    T_OROR = 297,
    T_PLUS = 298,
    T_MINUS = 299,
    T_MULT = 300,
    T_DIV = 301,
    T_AND = 302,
    T_OR = 303,
    T_VOID = 304,
    T_NULL = 305,
    T_PRINT = 306,
    T_ID = 307,
    T_NUM = 308
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE YYSTYPE;
union YYSTYPE
{
#line 10 "syntax.yy" /* yacc.c:1909  */

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

#line 126 "syntax.tab.hh" /* yacc.c:1909  */
};
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_SYNTAX_TAB_HH_INCLUDED  */
