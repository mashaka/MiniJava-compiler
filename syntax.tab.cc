/* A Bison parser, made by GNU Bison 3.0.2.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.0.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 1 "syntax.yy" /* yacc.c:339  */
 
    int yylex(void);
    void yyerror(const char *);
    #include <stdio.h>
    #include "AcceptVisitor.hpp"
    extern FILE * yyin;
    Goal* root;

#line 75 "syntax.tab.cc" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "syntax.tab.hh".  */
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
#line 10 "syntax.yy" /* yacc.c:355  */

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

#line 187 "syntax.tab.cc" /* yacc.c:355  */
};
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_SYNTAX_TAB_HH_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 202 "syntax.tab.cc" /* yacc.c:358  */

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif


#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  5
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   259

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  54
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  15
/* YYNRULES -- Number of rules.  */
#define YYNRULES  48
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  149

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   308

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    68,    68,    74,    78,    79,    83,    84,    88,    92,
      93,    97,    98,   102,   103,   107,   108,   112,   113,   114,
     115,   119,   120,   121,   122,   123,   124,   128,   129,   133,
     134,   135,   136,   137,   138,   139,   140,   141,   142,   143,
     144,   145,   146,   147,   148,   149,   150,   154,   155
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "T_BOOLEAN", "T_BREAK", "T_CASE",
  "T_CLASS", "T_CONTINUE", "T_ELSE", "T_EXTENDS", "T_DEFAULT", "T_INT",
  "T_NEW", "T_IF", "T_PUBLIC", "T_SWITCH", "T_RETURN", "T_STATIC",
  "T_WHILE", "T_THIS", "T_NULL_LITERAL", "T_LENGTH", "T_TRUE", "T_FALSE",
  "T_MAIN", "T_LPAREN", "T_RPAREN", "T_LBRACE", "T_RBRACE", "T_LBRACK",
  "T_RBRACK", "T_SEMICOLON", "T_COMMA", "T_DOT", "T_EQ", "T_LT", "T_GT",
  "T_LET", "T_GET", "T_NOT", "T_COLON", "T_ANDAND", "T_OROR", "T_PLUS",
  "T_MINUS", "T_MULT", "T_DIV", "T_AND", "T_OR", "T_VOID", "T_NULL",
  "T_PRINT", "T_ID", "T_NUM", "$accept", "GoalNode", "MainClassNode",
  "ClassDeclarationNode", "ClassDeclarationListNode", "VarDeclarationNode",
  "VarDeclarationListNode", "MethodDeclarationNode",
  "MethodDeclarationListNode", "CommaTypeIdentifierListNode", "TypeNode",
  "StatementNode", "StatementListNode", "ExpressionNode",
  "CommaExpressionListNode", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308
};
# endif

#define YYPACT_NINF -66

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-66)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
       3,   -44,    18,    14,    -6,   -66,   -17,    14,   -66,    33,
      16,   -66,    27,     5,   -66,    12,    44,     8,    50,   -66,
     -66,    47,    21,   -66,   -66,    68,    63,    35,    70,     8,
      66,    41,   -66,   -66,    77,    57,    71,   -66,    87,   -66,
      85,   -66,    20,    94,    95,    76,    79,   -66,   102,   103,
      -1,    21,   113,   118,   119,   122,    15,   123,    24,    15,
     133,    99,   128,    15,    67,    67,    24,   135,    67,    67,
      67,   -66,    67,   102,   -66,   136,     2,   -66,   -66,   -66,
      67,    67,   -66,   -66,    72,    92,   -66,    97,   124,   141,
     146,   -66,    -1,   138,   127,   148,   117,   142,    15,    67,
      -7,    67,    67,    67,    67,    67,    15,   147,   149,   -66,
     152,   172,   -66,    67,   168,   -66,   189,   163,   -66,   176,
      59,   214,    23,    23,   142,   -66,   -66,    67,   -66,    67,
     170,   -66,    15,   -66,    58,   187,   192,   -66,   -66,   -66,
     209,   -66,   167,    67,   183,   -66,   209,   -66,   -66
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     6,     0,     1,     0,     6,     2,     0,
       0,     7,     0,     0,     9,     0,     0,    13,     0,     9,
      18,    19,     0,    20,    10,    13,     0,     0,     0,    13,
       0,     0,    14,     5,     0,     0,     0,    17,     0,     8,
       0,     4,     0,     0,     0,     0,     0,     9,    15,     0,
      27,     0,     0,     0,     0,     0,    27,     0,    20,    27,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    28,     0,    15,     9,     0,     0,    42,    39,    40,
       0,     0,    41,    38,     0,     0,    21,     0,     0,     0,
       0,    16,    27,     0,     0,     0,     0,    45,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    25,
       0,     0,     3,     0,     0,    46,     0,     0,    35,     0,
      30,    29,    31,    32,    33,    23,    24,     0,    12,     0,
       0,    44,     0,    34,     0,     0,     0,    43,    22,    37,
      47,    26,     0,     0,     0,    11,    47,    36,    48
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -66,   -66,   -66,   -66,   195,   -66,   -18,   -66,    30,   137,
      43,   -57,   -29,   -65,    73
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,     7,     8,    24,    17,    25,    26,    52,
      27,    59,    60,    84,   144
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      85,    29,    20,    87,    88,    89,    75,    90,     4,     1,
      21,    20,    54,    94,   118,    96,    97,    55,     5,    21,
       6,     9,    22,    20,    20,    13,    56,    67,    54,    50,
      71,    21,    21,    55,   117,    10,   120,   121,   122,   123,
     124,   116,    56,    14,    15,   119,    44,    12,   130,   125,
      57,    58,    99,    69,    95,    32,    92,    16,    70,    36,
      23,    18,   135,   111,   136,    31,    57,    66,   105,   140,
      76,    19,    23,    23,    28,   138,    30,    77,   146,    76,
      78,    79,    22,    80,   139,    45,    77,    34,    99,    78,
      79,    33,    80,    38,    61,    35,    37,    81,    98,    41,
     102,    99,   103,   104,   105,   100,    81,   101,    39,    40,
      82,    83,    42,   102,    43,   103,   104,   105,   106,    82,
      83,    99,    47,   107,    46,   100,    99,   101,    48,    53,
     100,    49,   101,   102,    51,   103,   104,   105,   102,    62,
     103,   104,   105,   115,    64,    63,    99,    65,    68,    72,
     100,    73,   101,    99,   108,    74,   113,   100,   102,   101,
     103,   104,   105,    86,    93,   102,   112,   103,   104,   105,
      99,    99,   109,   114,   100,    99,   101,   110,   126,   100,
     128,   101,   102,   127,   103,   104,   105,   102,   129,   103,
     104,   105,    99,   133,   131,   145,   100,   132,   101,    99,
     137,   134,    11,   100,   102,   101,   103,   104,   105,   147,
      91,   102,     0,   103,   104,   105,    99,     0,   141,   148,
     100,    99,   101,   142,     0,   100,     0,   101,   102,     0,
     103,   104,   105,   102,     0,   103,   104,   105,    99,     0,
       0,   143,   100,    99,   101,     0,     0,     0,     0,     0,
     102,     0,   103,   104,   105,     0,     0,   103,   104,   105
};

static const yytype_int16 yycheck[] =
{
      65,    19,     3,    68,    69,    70,    63,    72,    52,     6,
      11,     3,    13,    11,    21,    80,    81,    18,     0,    11,
       6,    27,    14,     3,     3,     9,    27,    56,    13,    47,
      59,    11,    11,    18,    99,    52,   101,   102,   103,   104,
     105,    98,    27,    27,    17,    52,    26,    14,   113,   106,
      51,    52,    29,    29,    52,    25,    74,    52,    34,    29,
      52,    49,   127,    92,   129,    22,    51,    52,    45,   134,
      12,    27,    52,    52,    24,   132,    29,    19,   143,    12,
      22,    23,    14,    25,    26,    42,    19,    52,    29,    22,
      23,    28,    25,    52,    51,    25,    30,    39,    26,    28,
      41,    29,    43,    44,    45,    33,    39,    35,    31,    52,
      52,    53,    25,    41,    29,    43,    44,    45,    26,    52,
      53,    29,    27,    26,    30,    33,    29,    35,    52,    26,
      33,    52,    35,    41,    32,    43,    44,    45,    41,    26,
      43,    44,    45,    26,    25,    27,    29,    25,    25,    16,
      33,    52,    35,    29,    30,    27,    29,    33,    41,    35,
      43,    44,    45,    28,    28,    41,    28,    43,    44,    45,
      29,    29,    31,    25,    33,    29,    35,    31,    31,    33,
      28,    35,    41,    34,    43,    44,    45,    41,    16,    43,
      44,    45,    29,    30,    26,    28,    33,     8,    35,    29,
      30,    25,     7,    33,    41,    35,    43,    44,    45,    26,
      73,    41,    -1,    43,    44,    45,    29,    -1,    31,   146,
      33,    29,    35,    31,    -1,    33,    -1,    35,    41,    -1,
      43,    44,    45,    41,    -1,    43,    44,    45,    29,    -1,
      -1,    32,    33,    29,    35,    -1,    -1,    -1,    -1,    -1,
      41,    -1,    43,    44,    45,    -1,    -1,    43,    44,    45
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     6,    55,    56,    52,     0,     6,    57,    58,    27,
      52,    58,    14,     9,    27,    17,    52,    60,    49,    27,
       3,    11,    14,    52,    59,    61,    62,    64,    24,    60,
      29,    64,    62,    28,    52,    25,    62,    30,    52,    31,
      52,    28,    25,    29,    26,    64,    30,    27,    52,    52,
      60,    32,    63,    26,    13,    18,    27,    51,    52,    65,
      66,    64,    26,    27,    25,    25,    52,    66,    25,    29,
      34,    66,    16,    52,    27,    65,    12,    19,    22,    23,
      25,    39,    52,    53,    67,    67,    28,    67,    67,    67,
      67,    63,    60,    28,    11,    52,    67,    67,    26,    29,
      33,    35,    41,    43,    44,    45,    26,    26,    30,    31,
      31,    66,    28,    29,    25,    26,    65,    67,    21,    52,
      67,    67,    67,    67,    67,    65,    31,    34,    28,    16,
      67,    26,     8,    30,    25,    67,    67,    30,    65,    26,
      67,    31,    31,    32,    68,    28,    67,    26,    68
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    54,    55,    56,    57,    57,    58,    58,    59,    60,
      60,    61,    61,    62,    62,    63,    63,    64,    64,    64,
      64,    65,    65,    65,    65,    65,    65,    66,    66,    67,
      67,    67,    67,    67,    67,    67,    67,    67,    67,    67,
      67,    67,    67,    67,    67,    67,    67,    68,    68
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     2,    17,     8,     6,     0,     2,     3,     0,
       2,    15,    12,     0,     2,     0,     4,     3,     1,     1,
       1,     3,     7,     5,     5,     4,     7,     0,     2,     3,
       3,     3,     3,     3,     4,     3,     7,     5,     1,     1,
       1,     1,     1,     5,     4,     2,     3,     0,     3
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
do                                                              \
  if (yychar == YYEMPTY)                                        \
    {                                                           \
      yychar = (Token);                                         \
      yylval = (Value);                                         \
      YYPOPSTACK (yylen);                                       \
      yystate = *yyssp;                                         \
      goto yybackup;                                            \
    }                                                           \
  else                                                          \
    {                                                           \
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;                                                  \
    }                                                           \
while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                                              );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            /* Fall through.  */
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        YYSTYPE *yyvs1 = yyvs;
        yytype_int16 *yyss1 = yyss;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yystacksize);

        yyss = yyss1;
        yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yytype_int16 *yyss1 = yyss;
        union yyalloc *yyptr =
          (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
#line 68 "syntax.yy" /* yacc.c:1646  */
    { 
    root = new Goal((yyvsp[-1].iMainClass), (yyvsp[0].iClassDeclarationList));
    (yyval.iGoal) = root; }
#line 1397 "syntax.tab.cc" /* yacc.c:1646  */
    break;

  case 3:
#line 74 "syntax.yy" /* yacc.c:1646  */
    { (yyval.iMainClass) = new MainClass((yyvsp[-15].str), (yyvsp[-5].str), (yyvsp[-2].iStatement)); }
#line 1403 "syntax.tab.cc" /* yacc.c:1646  */
    break;

  case 4:
#line 78 "syntax.yy" /* yacc.c:1646  */
    { (yyval.iClassDeclaration) = new ClassDeclaration1((yyvsp[-6].str), (yyvsp[-4].str), (yyvsp[-2].iVarDeclarationList), (yyvsp[-1].iMethodDeclarationList)); }
#line 1409 "syntax.tab.cc" /* yacc.c:1646  */
    break;

  case 5:
#line 79 "syntax.yy" /* yacc.c:1646  */
    { (yyval.iClassDeclaration) = new ClassDeclaration2((yyvsp[-4].str), (yyvsp[-2].iVarDeclarationList), (yyvsp[-1].iMethodDeclarationList));     }
#line 1415 "syntax.tab.cc" /* yacc.c:1646  */
    break;

  case 6:
#line 83 "syntax.yy" /* yacc.c:1646  */
    { (yyval.iClassDeclarationList) = 0;                                }
#line 1421 "syntax.tab.cc" /* yacc.c:1646  */
    break;

  case 7:
#line 84 "syntax.yy" /* yacc.c:1646  */
    { (yyval.iClassDeclarationList) = new ClassDeclarationList((yyvsp[-1].iClassDeclaration), (yyvsp[0].iClassDeclarationList)); }
#line 1427 "syntax.tab.cc" /* yacc.c:1646  */
    break;

  case 8:
#line 88 "syntax.yy" /* yacc.c:1646  */
    { (yyval.iVarDeclaration) = new VarDeclaration((yyvsp[-2].iType), (yyvsp[-1].str)); }
#line 1433 "syntax.tab.cc" /* yacc.c:1646  */
    break;

  case 9:
#line 92 "syntax.yy" /* yacc.c:1646  */
    { (yyval.iVarDeclarationList) = 0;                              }
#line 1439 "syntax.tab.cc" /* yacc.c:1646  */
    break;

  case 10:
#line 93 "syntax.yy" /* yacc.c:1646  */
    { (yyval.iVarDeclarationList) = new VarDeclarationList((yyvsp[-1].iVarDeclarationList), (yyvsp[0].iVarDeclaration)); }
#line 1445 "syntax.tab.cc" /* yacc.c:1646  */
    break;

  case 11:
#line 97 "syntax.yy" /* yacc.c:1646  */
    { (yyval.iMethodDeclaration) = new MethodDeclaration1((yyvsp[-13].iType), (yyvsp[-12].str), (yyvsp[-10].iType), (yyvsp[-9].str), (yyvsp[-8].iCommaTypeIdentifierList), (yyvsp[-5].iVarDeclarationList), (yyvsp[-4].iStatementList), (yyvsp[-2].iExpression)); }
#line 1451 "syntax.tab.cc" /* yacc.c:1646  */
    break;

  case 12:
#line 98 "syntax.yy" /* yacc.c:1646  */
    { (yyval.iMethodDeclaration) = new MethodDeclaration2((yyvsp[-10].iType), (yyvsp[-9].str), (yyvsp[-5].iVarDeclarationList), (yyvsp[-4].iStatementList), (yyvsp[-2].iExpression));               }
#line 1457 "syntax.tab.cc" /* yacc.c:1646  */
    break;

  case 13:
#line 102 "syntax.yy" /* yacc.c:1646  */
    { (yyval.iMethodDeclarationList) = 0;                                 }
#line 1463 "syntax.tab.cc" /* yacc.c:1646  */
    break;

  case 14:
#line 103 "syntax.yy" /* yacc.c:1646  */
    { (yyval.iMethodDeclarationList) = new MethodDeclarationList((yyvsp[-1].iMethodDeclaration), (yyvsp[0].iMethodDeclarationList)); }
#line 1469 "syntax.tab.cc" /* yacc.c:1646  */
    break;

  case 15:
#line 107 "syntax.yy" /* yacc.c:1646  */
    { (yyval.iCommaTypeIdentifierList) = 0;                                       }
#line 1475 "syntax.tab.cc" /* yacc.c:1646  */
    break;

  case 16:
#line 108 "syntax.yy" /* yacc.c:1646  */
    { (yyval.iCommaTypeIdentifierList) = new CommaTypeIdentifierList((yyvsp[-2].iType), (yyvsp[-1].str), (yyvsp[0].iCommaTypeIdentifierList)); }
#line 1481 "syntax.tab.cc" /* yacc.c:1646  */
    break;

  case 17:
#line 112 "syntax.yy" /* yacc.c:1646  */
    { (yyval.iType) = new TypeIntArray();     }
#line 1487 "syntax.tab.cc" /* yacc.c:1646  */
    break;

  case 18:
#line 113 "syntax.yy" /* yacc.c:1646  */
    { (yyval.iType) = new TypeBoolean();      }
#line 1493 "syntax.tab.cc" /* yacc.c:1646  */
    break;

  case 19:
#line 114 "syntax.yy" /* yacc.c:1646  */
    { (yyval.iType) = new TypeInt();          }
#line 1499 "syntax.tab.cc" /* yacc.c:1646  */
    break;

  case 20:
#line 115 "syntax.yy" /* yacc.c:1646  */
    { (yyval.iType) = new TypeIdentifier((yyvsp[0].str)); }
#line 1505 "syntax.tab.cc" /* yacc.c:1646  */
    break;

  case 21:
#line 119 "syntax.yy" /* yacc.c:1646  */
    { (yyval.iStatement) = new StatementListBraced((yyvsp[-1].iStatementList));          }
#line 1511 "syntax.tab.cc" /* yacc.c:1646  */
    break;

  case 22:
#line 120 "syntax.yy" /* yacc.c:1646  */
    { (yyval.iStatement) = new StatementIf((yyvsp[-4].iExpression), (yyvsp[-2].iStatement), (yyvsp[0].iStatement));          }
#line 1517 "syntax.tab.cc" /* yacc.c:1646  */
    break;

  case 23:
#line 121 "syntax.yy" /* yacc.c:1646  */
    { (yyval.iStatement) = new StatementWhile((yyvsp[-2].iExpression), (yyvsp[0].iStatement));           }
#line 1523 "syntax.tab.cc" /* yacc.c:1646  */
    break;

  case 24:
#line 122 "syntax.yy" /* yacc.c:1646  */
    { (yyval.iStatement) = new StatementPrint((yyvsp[-2].iExpression));               }
#line 1529 "syntax.tab.cc" /* yacc.c:1646  */
    break;

  case 25:
#line 123 "syntax.yy" /* yacc.c:1646  */
    { (yyval.iStatement) = new StatementIdentifier1((yyvsp[-3].str), (yyvsp[-1].iExpression));     }
#line 1535 "syntax.tab.cc" /* yacc.c:1646  */
    break;

  case 26:
#line 124 "syntax.yy" /* yacc.c:1646  */
    { (yyval.iStatement) = new StatementIdentifier2((yyvsp[-6].str), (yyvsp[-4].iExpression), (yyvsp[-1].iExpression)); }
#line 1541 "syntax.tab.cc" /* yacc.c:1646  */
    break;

  case 27:
#line 128 "syntax.yy" /* yacc.c:1646  */
    { (yyval.iStatementList) = 0;     }
#line 1547 "syntax.tab.cc" /* yacc.c:1646  */
    break;

  case 28:
#line 129 "syntax.yy" /* yacc.c:1646  */
    { (yyval.iStatementList) = new StatementList((yyvsp[-1].iStatement), (yyvsp[0].iStatementList)); }
#line 1553 "syntax.tab.cc" /* yacc.c:1646  */
    break;

  case 29:
#line 133 "syntax.yy" /* yacc.c:1646  */
    { (yyval.iExpression) = new ExpressionBinOp((yyvsp[-2].iExpression), B_ANDAND, (yyvsp[0].iExpression)); }
#line 1559 "syntax.tab.cc" /* yacc.c:1646  */
    break;

  case 30:
#line 134 "syntax.yy" /* yacc.c:1646  */
    { (yyval.iExpression) = new ExpressionBinOp((yyvsp[-2].iExpression), B_LT,     (yyvsp[0].iExpression)); }
#line 1565 "syntax.tab.cc" /* yacc.c:1646  */
    break;

  case 31:
#line 135 "syntax.yy" /* yacc.c:1646  */
    { (yyval.iExpression) = new ExpressionAriOp((yyvsp[-2].iExpression), A_PLUS,   (yyvsp[0].iExpression)); }
#line 1571 "syntax.tab.cc" /* yacc.c:1646  */
    break;

  case 32:
#line 136 "syntax.yy" /* yacc.c:1646  */
    { (yyval.iExpression) = new ExpressionAriOp((yyvsp[-2].iExpression), A_MINUS,  (yyvsp[0].iExpression)); }
#line 1577 "syntax.tab.cc" /* yacc.c:1646  */
    break;

  case 33:
#line 137 "syntax.yy" /* yacc.c:1646  */
    { (yyval.iExpression) = new ExpressionAriOp((yyvsp[-2].iExpression), A_MULT,   (yyvsp[0].iExpression)); }
#line 1583 "syntax.tab.cc" /* yacc.c:1646  */
    break;

  case 34:
#line 138 "syntax.yy" /* yacc.c:1646  */
    { (yyval.iExpression) = new ExpressionBracks((yyvsp[-3].iExpression), (yyvsp[-1].iExpression));          }
#line 1589 "syntax.tab.cc" /* yacc.c:1646  */
    break;

  case 35:
#line 139 "syntax.yy" /* yacc.c:1646  */
    { (yyval.iExpression) = new ExpressionLength((yyvsp[-2].iExpression));              }
#line 1595 "syntax.tab.cc" /* yacc.c:1646  */
    break;

  case 36:
#line 140 "syntax.yy" /* yacc.c:1646  */
    { (yyval.iExpression) = new ExpressionMethod((yyvsp[-6].iExpression), (yyvsp[-4].str), (yyvsp[-2].iExpression), (yyvsp[-1].iCommaExpressionList));  }
#line 1601 "syntax.tab.cc" /* yacc.c:1646  */
    break;

  case 37:
#line 141 "syntax.yy" /* yacc.c:1646  */
    { (yyval.iExpression) = new ExpressionEmptyMethod((yyvsp[-4].iExpression), (yyvsp[-2].str));     }
#line 1607 "syntax.tab.cc" /* yacc.c:1646  */
    break;

  case 38:
#line 142 "syntax.yy" /* yacc.c:1646  */
    { (yyval.iExpression) = new ExpressionNum((yyvsp[0].str));                 }
#line 1613 "syntax.tab.cc" /* yacc.c:1646  */
    break;

  case 39:
#line 143 "syntax.yy" /* yacc.c:1646  */
    { (yyval.iExpression) = new ExpressionLogOp(L_TRUE);           }
#line 1619 "syntax.tab.cc" /* yacc.c:1646  */
    break;

  case 40:
#line 144 "syntax.yy" /* yacc.c:1646  */
    { (yyval.iExpression) = new ExpressionLogOp(L_FALSE);          }
#line 1625 "syntax.tab.cc" /* yacc.c:1646  */
    break;

  case 41:
#line 145 "syntax.yy" /* yacc.c:1646  */
    { (yyval.iExpression) = new ExpressionId((yyvsp[0].str));                  }
#line 1631 "syntax.tab.cc" /* yacc.c:1646  */
    break;

  case 42:
#line 146 "syntax.yy" /* yacc.c:1646  */
    { (yyval.iExpression) = new ExpressionThis();                  }
#line 1637 "syntax.tab.cc" /* yacc.c:1646  */
    break;

  case 43:
#line 147 "syntax.yy" /* yacc.c:1646  */
    { (yyval.iExpression) = new ExpressionNew((yyvsp[-1].iExpression));                 }
#line 1643 "syntax.tab.cc" /* yacc.c:1646  */
    break;

  case 44:
#line 148 "syntax.yy" /* yacc.c:1646  */
    { (yyval.iExpression) = new ExpressionEmptyNew((yyvsp[-2].str));            }
#line 1649 "syntax.tab.cc" /* yacc.c:1646  */
    break;

  case 45:
#line 149 "syntax.yy" /* yacc.c:1646  */
    { (yyval.iExpression) = new ExpressionNot((yyvsp[0].iExpression));                 }
#line 1655 "syntax.tab.cc" /* yacc.c:1646  */
    break;

  case 46:
#line 150 "syntax.yy" /* yacc.c:1646  */
    { (yyval.iExpression) = new ExpressionParens((yyvsp[-1].iExpression));              }
#line 1661 "syntax.tab.cc" /* yacc.c:1646  */
    break;

  case 47:
#line 154 "syntax.yy" /* yacc.c:1646  */
    { (yyval.iCommaExpressionList) = 0;                               }
#line 1667 "syntax.tab.cc" /* yacc.c:1646  */
    break;

  case 48:
#line 155 "syntax.yy" /* yacc.c:1646  */
    { (yyval.iCommaExpressionList) = new CommaExpressionList((yyvsp[-1].iExpression), (yyvsp[0].iCommaExpressionList)); }
#line 1673 "syntax.tab.cc" /* yacc.c:1646  */
    break;


#line 1677 "syntax.tab.cc" /* yacc.c:1646  */
      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 158 "syntax.yy" /* yacc.c:1906  */
