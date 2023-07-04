/* A Bison parser, made by GNU Bison 3.5.1.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2020 Free Software Foundation,
   Inc.

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

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.5.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "translate.y"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../symbol-table/symbolTable.h"
#include "../utils/print-source-code.h"
#include "../risc-v/riscV-context.h"
#include "../pseudo/pseudo-context.h"
#include "types.h"
#include <stdarg.h>
#include <assert.h>

extern int yylex();
extern void yyerror(const char*);
extern FILE* yyin; // Declarar a variável global de entrada do analisador léxico
extern int line;

void onExit();
void onStart();
void executeProgram();

SymbolTable *st;
FILE *prod, *gen;

FILE *friscv;
RiscVContext *riscv;

FILE *fpseudo;
PseudoContext *pseudo;


int nextAddress = 0;

void blockOpen();
void blockClose();

// void handleStruct();
void handleVarDeclaration(char *type, char *id, int size);
ExprData handleAttr(char *id);
void handleOperation(int opcode, ...);
ExprData handleBinaryExpr(int opcode, ExprData e1, ExprData e2);
ExprData handleUnaryExpr(int opcode, ExprData e);
ExprData handleAssignExpr(char *id, ExprData e);
void reportAndExit(const char *s, ...);

char *mergeStrPointers(char *a, char *b);

void handleIfAfterExpr(ExprData e);
void handleIfAfterStmt();
void handleIfAfterElse();

void handleRepEntry();
void handleRepAfterExpr(ExprData e);
void handleRepUpdate();
void handleRepStmt();
void handleRepExit();

void handleRepGotoEntry();
void handleRepGotoUpdate();

ExprData handleFunctionCall(char *id, FuncParamList *params);

ExprData handleInteger(int integer);


#line 136 "translate.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
#ifndef YY_YY_TRANSLATE_TAB_H_INCLUDED
# define YY_YY_TRANSLATE_TAB_H_INCLUDED
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
    INCLUDE = 258,
    MAIN = 259,
    BREAK = 260,
    CASE = 261,
    CONST = 262,
    CONTINUE = 263,
    DEFAULT = 264,
    IF = 265,
    ELSE = 266,
    ENUM = 267,
    RETURN = 268,
    STRUCT = 269,
    DO = 270,
    PRINTF = 271,
    SCANF = 272,
    FOR = 273,
    GOTO = 274,
    SIZEOF = 275,
    SWITCH = 276,
    TYPEDEF = 277,
    UNION = 278,
    WHILE = 279,
    FREE = 280,
    POINTER = 281,
    SLICE = 282,
    SOME = 283,
    REDUCE = 284,
    FILTER = 285,
    MAP = 286,
    SORT = 287,
    CLOSE_BRACKET = 288,
    OPEN_BRACKET = 289,
    CLOSE_PAREN = 290,
    OPEN_PAREN = 291,
    BLOCK_CLOSE = 292,
    BLOCK_OPEN = 293,
    ADD = 294,
    SUB = 295,
    MUL = 296,
    DIV = 297,
    BITWISE_AND = 298,
    BITWISE_OR = 299,
    BITWISE_NOT = 300,
    MOD = 301,
    LEFT_SHIFT = 302,
    RIGHT_SHIFT = 303,
    LT = 304,
    GT = 305,
    LE = 306,
    GE = 307,
    EQ = 308,
    NE = 309,
    BITWISE_XOR = 310,
    LOGICAL_AND = 311,
    LOGICAL_OR = 312,
    LOGICAL_NOT = 313,
    COLON = 314,
    SEMI_COLON = 315,
    ASSIGN = 316,
    COMMA = 317,
    INVALID = 318,
    UMINUS = 319,
    DECIMAL = 320,
    STRING = 321,
    DOT = 322,
    IDENTIFIER = 323,
    INTEGER = 324,
    TRUE = 325,
    FALSE = 326,
    IFX = 327,
    UNARY = 328
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 68 "translate.y"

    char *string;
    int integer;
    double decimal;
    int boolean;
    ExprData exprData;
    FuncParamList *paramList;

#line 271 "translate.tab.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_TRANSLATE_TAB_H_INCLUDED  */



#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))

/* Stored state numbers (used for stacks). */
typedef yytype_uint8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

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

#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                            \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
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

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

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
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
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
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   444

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  74
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  33
/* YYNRULES -- Number of rules.  */
#define YYNRULES  89
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  175

#define YYUNDEFTOK  2
#define YYMAXUTOK   328


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
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
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,   115,   115,   118,   119,   122,   123,   124,   125,   126,
     127,   128,   130,   131,   131,   135,   143,   143,   143,   145,
     145,   145,   145,   147,   147,   150,   153,   156,   156,   159,
     160,   163,   164,   167,   168,   171,   172,   176,   177,   178,
     179,   180,   181,   182,   185,   186,   189,   190,   193,   194,
     197,   198,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   225,   226,   227,   230,   231,
     234,   235,   236,   237,   239,   240,   244,   245,   249,   250
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "INCLUDE", "MAIN", "BREAK", "CASE",
  "CONST", "CONTINUE", "DEFAULT", "IF", "ELSE", "ENUM", "RETURN", "STRUCT",
  "DO", "PRINTF", "SCANF", "FOR", "GOTO", "SIZEOF", "SWITCH", "TYPEDEF",
  "UNION", "WHILE", "FREE", "POINTER", "SLICE", "SOME", "REDUCE", "FILTER",
  "MAP", "SORT", "CLOSE_BRACKET", "OPEN_BRACKET", "CLOSE_PAREN",
  "OPEN_PAREN", "BLOCK_CLOSE", "BLOCK_OPEN", "ADD", "SUB", "MUL", "DIV",
  "BITWISE_AND", "BITWISE_OR", "BITWISE_NOT", "MOD", "LEFT_SHIFT",
  "RIGHT_SHIFT", "LT", "GT", "LE", "GE", "EQ", "NE", "BITWISE_XOR",
  "LOGICAL_AND", "LOGICAL_OR", "LOGICAL_NOT", "COLON", "SEMI_COLON",
  "ASSIGN", "COMMA", "INVALID", "UMINUS", "DECIMAL", "STRING", "DOT",
  "IDENTIFIER", "INTEGER", "TRUE", "FALSE", "IFX", "UNARY", "$accept",
  "program", "stmts", "stmt", "conditional", "$@1", "condexpr",
  "repetition", "$@2", "$@3", "$@4", "$@5", "$@6", "$@7", "repexpr", "var",
  "func", "$@8", "typelist", "exprlist", "opttypelist", "optexprlist",
  "commands", "varlist", "idlist", "optexpr", "expr", "term", "attr",
  "const", "boolean", "exprvector", "constvector", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_int16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,   322,   323,   324,
     325,   326,   327,   328
};
# endif

#define YYPACT_NINF (-115)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-90)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -115,     8,   191,  -115,   -51,   -39,   -27,     1,   -29,   205,
     -26,  -115,     5,   -25,   -19,  -115,   205,  -115,   205,   205,
    -115,  -115,   -23,  -115,  -115,  -115,  -115,  -115,  -115,   -12,
    -115,  -115,   281,  -115,   -21,  -115,  -115,   -10,  -115,  -115,
     205,    32,   -20,    11,   303,    40,   191,   205,  -115,    15,
      37,   262,    82,  -115,  -115,   205,   205,   -28,  -115,  -115,
     205,   205,   205,   205,   205,   205,   205,   205,   205,   205,
     205,   205,   205,   205,   205,   205,   205,   205,   205,  -115,
      16,   205,  -115,    51,   303,    20,  -115,  -115,    65,  -115,
      31,   205,  -115,  -115,   239,    36,    58,   303,    30,    67,
    -115,    66,    66,    56,    56,   390,   357,    56,    56,    35,
      35,    91,    91,    91,    91,   -22,   -22,   374,   340,   322,
      71,  -115,   303,   191,    47,    73,   -34,    78,    55,  -115,
      86,   303,  -115,   205,  -115,    84,    59,   112,    20,  -115,
    -115,    60,    81,   205,   205,  -115,   303,  -115,  -115,    64,
     107,  -115,  -115,   109,  -115,   110,    94,   191,    59,   106,
     191,    96,  -115,  -115,  -115,  -115,  -115,  -115,   205,   152,
     111,  -115,  -115,   191,  -115
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       4,     0,     2,     1,     0,     0,     0,     0,     0,    49,
       0,    23,     0,     0,     0,    16,     0,     4,     0,     0,
      81,    82,    87,    80,    84,    85,     3,     5,     6,     0,
       7,     9,     0,    72,    77,    75,    83,     0,    38,    39,
       0,     0,    87,     0,    48,     0,     0,    49,    74,     0,
       0,     0,     0,    71,    70,     0,    36,    27,    78,     8,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    10,
       0,     0,    41,     0,    15,     0,    37,    45,     0,    19,
       0,     0,    69,    11,     0,    35,     0,    32,     0,     0,
      26,    50,    51,    52,    53,    55,    56,    57,    54,    59,
      60,    63,    64,    65,    66,    61,    62,    58,    67,    68,
      87,    79,    73,     0,    47,     0,     0,     0,     0,    40,
       0,    25,    86,     0,    76,     0,    34,    12,     0,    43,
      42,     0,     0,     0,     0,    17,    31,    88,    30,    33,
       0,    13,    46,    89,    44,     0,     0,     0,     0,     0,
       0,     0,    20,    18,    29,     4,    14,    24,    49,     0,
       0,    28,    21,     0,    22
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
    -115,  -115,   -16,   -44,  -115,  -115,  -115,  -115,  -115,  -115,
    -115,  -115,  -115,  -115,  -108,  -114,  -115,  -115,  -115,  -115,
    -115,  -115,  -115,  -115,    23,   -43,    -9,  -115,    83,  -115,
    -115,  -115,  -115
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,     2,    26,    27,   160,    83,    28,    50,   157,
     128,   168,   173,    46,   130,    29,    30,    99,   149,    95,
     150,    96,    31,   126,   125,    43,    32,    33,    34,    35,
      36,    58,   100
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      44,    52,    88,   140,    89,    80,    98,    51,     3,    53,
      54,    55,   142,    56,    55,    37,    56,    60,    61,    62,
      63,    38,   148,    66,    67,    68,    69,    70,    71,    72,
      73,    84,   -89,    39,   141,   155,   156,    40,    44,    41,
      81,    47,    45,    48,   164,    57,    94,    97,    59,    49,
      82,   101,   102,   103,   104,   105,   106,   107,   108,   109,
     110,   111,   112,   113,   114,   115,   116,   117,   118,   119,
      85,    86,   122,    91,    60,    61,    62,    63,    87,   137,
      66,    67,   131,    90,   120,     4,   123,     5,   124,   127,
       6,   129,     7,   134,     8,     9,    10,    11,   133,   135,
      12,    66,    13,   136,    14,    55,    15,    62,    63,   138,
     139,    66,    67,   163,   143,   144,   166,   147,    16,    93,
      17,   145,    18,   151,   146,   170,   158,   141,   153,   174,
      60,    61,    62,    63,   131,   131,    66,    67,    68,    69,
      19,   154,   159,    98,   165,   161,   172,    20,    21,   169,
      22,    23,    24,    25,   162,     4,   167,     5,     0,    44,
       6,   152,     7,   121,     8,     9,    10,    11,     0,     0,
      12,     0,    13,     0,    14,     0,    15,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    16,   171,
      17,     0,    18,     0,     4,     0,     5,     0,     0,     6,
       0,     7,     0,     8,     9,    10,    11,     0,     0,    12,
      19,    13,     0,    14,     0,    15,     0,    20,    21,     0,
      22,    23,    24,    25,     0,    13,     0,    16,     0,    17,
       0,    18,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    16,     0,     0,     0,    18,     0,     0,     0,    19,
       0,     0,     0,     0,     0,     0,    20,    21,     0,    22,
      23,    24,    25,    19,     0,     0,     0,     0,     0,     0,
      20,    21,   132,    42,    23,    24,    25,     0,    60,    61,
      62,    63,    64,    65,    66,    67,    68,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    92,     0,     0,
       0,    60,    61,    62,    63,    64,    65,    66,    67,    68,
      69,    70,    71,    72,    73,    74,    75,    76,    77,    78,
      60,    61,    62,    63,    64,    65,    66,    67,    68,    69,
      70,    71,    72,    73,    74,    75,    76,    77,    78,     0,
       0,    79,    60,    61,    62,    63,    64,    65,    66,    67,
      68,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    60,    61,    62,    63,    64,    65,    66,    67,    68,
      69,    70,    71,    72,    73,    74,    75,    76,    77,    60,
      61,    62,    63,    64,    65,    66,    67,    68,    69,    70,
      71,    72,    73,    74,    75,    76,    60,    61,    62,    63,
      64,     0,    66,    67,    68,    69,    70,    71,    72,    73,
      74,    75,    76,    60,    61,    62,    63,    64,     0,    66,
      67,    68,    69,    70,    71,    72,    73,    74,    75,    60,
      61,    62,    63,     0,     0,    66,    67,    68,    69,    70,
      71,    72,    73,    74,    75
};

static const yytype_int16 yycheck[] =
{
       9,    17,    46,    37,    47,    26,    34,    16,     0,    18,
      19,    34,   126,    36,    34,    66,    36,    39,    40,    41,
      42,    60,   136,    45,    46,    47,    48,    49,    50,    51,
      52,    40,    60,    60,    68,   143,   144,    36,    47,    68,
      61,    36,    68,    68,   158,    68,    55,    56,    60,    68,
      60,    60,    61,    62,    63,    64,    65,    66,    67,    68,
      69,    70,    71,    72,    73,    74,    75,    76,    77,    78,
      38,    60,    81,    36,    39,    40,    41,    42,    38,   123,
      45,    46,    91,    68,    68,     3,    35,     5,    68,    24,
       8,    60,    10,    35,    12,    13,    14,    15,    62,    69,
      18,    45,    20,    36,    22,    34,    24,    41,    42,    62,
      37,    45,    46,   157,    36,    60,   160,    33,    36,    37,
      38,    35,    40,    11,   133,   168,    62,    68,    68,   173,
      39,    40,    41,    42,   143,   144,    45,    46,    47,    48,
      58,    60,    35,    34,    38,    35,    35,    65,    66,   165,
      68,    69,    70,    71,    60,     3,    60,     5,    -1,   168,
       8,   138,    10,    80,    12,    13,    14,    15,    -1,    -1,
      18,    -1,    20,    -1,    22,    -1,    24,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    36,    37,
      38,    -1,    40,    -1,     3,    -1,     5,    -1,    -1,     8,
      -1,    10,    -1,    12,    13,    14,    15,    -1,    -1,    18,
      58,    20,    -1,    22,    -1,    24,    -1,    65,    66,    -1,
      68,    69,    70,    71,    -1,    20,    -1,    36,    -1,    38,
      -1,    40,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    36,    -1,    -1,    -1,    40,    -1,    -1,    -1,    58,
      -1,    -1,    -1,    -1,    -1,    -1,    65,    66,    -1,    68,
      69,    70,    71,    58,    -1,    -1,    -1,    -1,    -1,    -1,
      65,    66,    33,    68,    69,    70,    71,    -1,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    35,    -1,    -1,
      -1,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    -1,
      -1,    60,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    39,    40,    41,    42,
      43,    -1,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    39,    40,    41,    42,    43,    -1,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    39,
      40,    41,    42,    -1,    -1,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    75,    76,     0,     3,     5,     8,    10,    12,    13,
      14,    15,    18,    20,    22,    24,    36,    38,    40,    58,
      65,    66,    68,    69,    70,    71,    77,    78,    81,    89,
      90,    96,   100,   101,   102,   103,   104,    66,    60,    60,
      36,    68,    68,    99,   100,    68,    87,    36,    68,    68,
      82,   100,    76,   100,   100,    34,    36,    68,   105,    60,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    60,
      26,    61,    60,    80,   100,    38,    60,    38,    77,    99,
      68,    36,    35,    37,   100,    93,    95,   100,    34,    91,
     106,   100,   100,   100,   100,   100,   100,   100,   100,   100,
     100,   100,   100,   100,   100,   100,   100,   100,   100,   100,
      68,   102,   100,    35,    68,    98,    97,    24,    84,    60,
      88,   100,    33,    62,    35,    69,    36,    77,    62,    37,
      37,    68,    89,    36,    60,    35,   100,    33,    89,    92,
      94,    11,    98,    68,    60,    88,    88,    83,    62,    35,
      79,    35,    60,    77,    89,    38,    77,    60,    85,    76,
      99,    37,    35,    86,    77
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    74,    75,    76,    76,    77,    77,    77,    77,    77,
      77,    77,    78,    79,    78,    80,    82,    83,    81,    84,
      85,    86,    81,    87,    81,    88,    89,    91,    90,    92,
      92,    93,    93,    94,    94,    95,    95,    96,    96,    96,
      96,    96,    96,    96,    97,    97,    98,    98,    99,    99,
     100,   100,   100,   100,   100,   100,   100,   100,   100,   100,
     100,   100,   100,   100,   100,   100,   100,   100,   100,   100,
     100,   100,   100,   100,   100,   101,   101,   101,   102,   102,
     103,   103,   103,   103,   104,   104,   105,   105,   106,   106
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     0,     1,     1,     1,     2,     1,
       2,     3,     5,     0,     8,     1,     0,     0,     7,     0,
       0,     0,    12,     0,     8,     1,     3,     0,     9,     3,
       1,     3,     1,     1,     0,     1,     0,     3,     2,     2,
       4,     3,     5,     5,     3,     0,     3,     1,     1,     0,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       2,     2,     1,     3,     2,     1,     4,     1,     2,     3,
       1,     1,     1,     1,     1,     1,     3,     0,     3,     0
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
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


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YYUSE (yyoutput);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yytype], *yyvaluep);
# endif
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyo, yytype, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[+yyssp[yyi + 1 - yynrhs]],
                       &yyvsp[(yyi + 1) - (yynrhs)]
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
#   define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
#  else
/* Return the length of YYSTR.  */
static YYPTRDIFF_T
yystrlen (const char *yystr)
{
  YYPTRDIFF_T yylen;
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
static YYPTRDIFF_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYPTRDIFF_T yyn = 0;
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
            else
              goto append;

          append:
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

  if (yyres)
    return yystpcpy (yyres, yystr) - yyres;
  else
    return yystrlen (yystr);
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
yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
                yy_state_t *yyssp, int yytoken)
{
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat: reported tokens (one for the "unexpected",
     one per "expected"). */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Actual size of YYARG. */
  int yycount = 0;
  /* Cumulated lengths of YYARG.  */
  YYPTRDIFF_T yysize = 0;

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
      int yyn = yypact[+*yyssp];
      YYPTRDIFF_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
      yysize = yysize0;
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
                  YYPTRDIFF_T yysize1
                    = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
                    yysize = yysize1;
                  else
                    return 2;
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
    default: /* Avoid compiler warnings. */
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    /* Don't count the "%s"s in the final size, but reserve room for
       the terminator.  */
    YYPTRDIFF_T yysize1 = yysize + (yystrlen (yyformat) - 2 * yycount) + 1;
    if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
      yysize = yysize1;
    else
      return 2;
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
          ++yyp;
          ++yyformat;
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
    yy_state_fast_t yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss;
    yy_state_t *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYPTRDIFF_T yystacksize;

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
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;
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
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    goto yyexhaustedlab;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
# undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */

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
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
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
| yyreduce -- do a reduction.  |
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
#line 115 "translate.y"
               {  }
#line 1630 "translate.tab.c"
    break;

  case 3:
#line 118 "translate.y"
                                    {  }
#line 1636 "translate.tab.c"
    break;

  case 4:
#line 119 "translate.y"
                                    {  }
#line 1642 "translate.tab.c"
    break;

  case 5:
#line 122 "translate.y"
                                {  }
#line 1648 "translate.tab.c"
    break;

  case 6:
#line 123 "translate.y"
                                {  }
#line 1654 "translate.tab.c"
    break;

  case 7:
#line 124 "translate.y"
                                {  }
#line 1660 "translate.tab.c"
    break;

  case 8:
#line 125 "translate.y"
                                {  }
#line 1666 "translate.tab.c"
    break;

  case 9:
#line 126 "translate.y"
                                {  }
#line 1672 "translate.tab.c"
    break;

  case 10:
#line 127 "translate.y"
                                {  }
#line 1678 "translate.tab.c"
    break;

  case 11:
#line 128 "translate.y"
                                   {  }
#line 1684 "translate.tab.c"
    break;

  case 12:
#line 130 "translate.y"
                                                               { handleIfAfterStmt(); handleIfAfterElse(); }
#line 1690 "translate.tab.c"
    break;

  case 13:
#line 131 "translate.y"
                                                   { handleIfAfterStmt(); }
#line 1696 "translate.tab.c"
    break;

  case 14:
#line 131 "translate.y"
                                                                                 { handleIfAfterElse(); }
#line 1702 "translate.tab.c"
    break;

  case 15:
#line 135 "translate.y"
                                { handleIfAfterExpr((yyvsp[0].exprData)); }
#line 1708 "translate.tab.c"
    break;

  case 16:
#line 143 "translate.y"
                  {handleRepEntry();}
#line 1714 "translate.tab.c"
    break;

  case 17:
#line 143 "translate.y"
                                                                     {handleRepStmt();}
#line 1720 "translate.tab.c"
    break;

  case 18:
#line 143 "translate.y"
                                                                                             {handleRepGotoEntry();handleRepExit();}
#line 1726 "translate.tab.c"
    break;

  case 19:
#line 145 "translate.y"
                             {handleRepEntry();}
#line 1732 "translate.tab.c"
    break;

  case 20:
#line 145 "translate.y"
                                                                               {handleRepUpdate();}
#line 1738 "translate.tab.c"
    break;

  case 21:
#line 145 "translate.y"
                                                                                                                        {handleRepGotoEntry();handleRepStmt();}
#line 1744 "translate.tab.c"
    break;

  case 22:
#line 145 "translate.y"
                                                                                                                                                                     {handleRepGotoUpdate();handleRepExit();}
#line 1750 "translate.tab.c"
    break;

  case 23:
#line 147 "translate.y"
         {handleRepEntry();handleRepStmt();}
#line 1756 "translate.tab.c"
    break;

  case 24:
#line 147 "translate.y"
                                                                                                  {handleRepExit();}
#line 1762 "translate.tab.c"
    break;

  case 25:
#line 150 "translate.y"
              { handleRepAfterExpr((yyvsp[0].exprData)); }
#line 1768 "translate.tab.c"
    break;

  case 26:
#line 153 "translate.y"
                                       { handleVarDeclaration((yyvsp[-2].string), (yyvsp[-1].string), (yyvsp[0].integer)); }
#line 1774 "translate.tab.c"
    break;

  case 27:
#line 156 "translate.y"
                            {}
#line 1780 "translate.tab.c"
    break;

  case 28:
#line 156 "translate.y"
                                                                                               {}
#line 1786 "translate.tab.c"
    break;

  case 29:
#line 159 "translate.y"
                             {}
#line 1792 "translate.tab.c"
    break;

  case 30:
#line 160 "translate.y"
          {}
#line 1798 "translate.tab.c"
    break;

  case 31:
#line 163 "translate.y"
                              { functAddParam(&(yyvsp[-2].paramList), (yyvsp[0].exprData).reg, (yyvsp[0].exprData).returnType); }
#line 1804 "translate.tab.c"
    break;

  case 32:
#line 164 "translate.y"
           { (yyval.paramList) = NULL; functAddParam(&(yyval.paramList), (yyvsp[0].exprData).reg, (yyvsp[0].exprData).returnType); }
#line 1810 "translate.tab.c"
    break;

  case 33:
#line 167 "translate.y"
                        {  }
#line 1816 "translate.tab.c"
    break;

  case 34:
#line 168 "translate.y"
                        {  }
#line 1822 "translate.tab.c"
    break;

  case 35:
#line 171 "translate.y"
                        { (yyval.paramList) = (yyvsp[0].paramList); }
#line 1828 "translate.tab.c"
    break;

  case 36:
#line 172 "translate.y"
                        { (yyval.paramList) = NULL; }
#line 1834 "translate.tab.c"
    break;

  case 37:
#line 176 "translate.y"
                              {}
#line 1840 "translate.tab.c"
    break;

  case 38:
#line 177 "translate.y"
                       {}
#line 1846 "translate.tab.c"
    break;

  case 39:
#line 178 "translate.y"
                          {}
#line 1852 "translate.tab.c"
    break;

  case 40:
#line 179 "translate.y"
                                               {}
#line 1858 "translate.tab.c"
    break;

  case 41:
#line 180 "translate.y"
                                {}
#line 1864 "translate.tab.c"
    break;

  case 42:
#line 181 "translate.y"
                                                       { }
#line 1870 "translate.tab.c"
    break;

  case 43:
#line 182 "translate.y"
                                                    { }
#line 1876 "translate.tab.c"
    break;

  case 44:
#line 185 "translate.y"
                                    {  }
#line 1882 "translate.tab.c"
    break;

  case 45:
#line 186 "translate.y"
                                    {  }
#line 1888 "translate.tab.c"
    break;

  case 46:
#line 189 "translate.y"
                                    {  }
#line 1894 "translate.tab.c"
    break;

  case 47:
#line 190 "translate.y"
                                    {  }
#line 1900 "translate.tab.c"
    break;

  case 48:
#line 193 "translate.y"
                                    {  }
#line 1906 "translate.tab.c"
    break;

  case 49:
#line 194 "translate.y"
                                    {  }
#line 1912 "translate.tab.c"
    break;

  case 50:
#line 197 "translate.y"
                    { (yyval.exprData) = handleBinaryExpr(ADD, (yyvsp[-2].exprData), (yyvsp[0].exprData)); }
#line 1918 "translate.tab.c"
    break;

  case 51:
#line 198 "translate.y"
                    { (yyval.exprData) = handleBinaryExpr(SUB, (yyvsp[-2].exprData), (yyvsp[0].exprData)); }
#line 1924 "translate.tab.c"
    break;

  case 52:
#line 199 "translate.y"
                    { (yyval.exprData) = handleBinaryExpr(MUL, (yyvsp[-2].exprData), (yyvsp[0].exprData)); }
#line 1930 "translate.tab.c"
    break;

  case 53:
#line 200 "translate.y"
                    { (yyval.exprData) = handleBinaryExpr(DIV, (yyvsp[-2].exprData), (yyvsp[0].exprData)); }
#line 1936 "translate.tab.c"
    break;

  case 54:
#line 201 "translate.y"
                    { /* geraTemp1, geraTemp2, chama codeGen(t1, op, t2) */ }
#line 1942 "translate.tab.c"
    break;

  case 55:
#line 202 "translate.y"
                                { (yyval.exprData) = handleBinaryExpr(BITWISE_AND, (yyvsp[-2].exprData), (yyvsp[0].exprData)); }
#line 1948 "translate.tab.c"
    break;

  case 56:
#line 203 "translate.y"
                                { (yyval.exprData) = handleBinaryExpr(BITWISE_OR, (yyvsp[-2].exprData), (yyvsp[0].exprData)); }
#line 1954 "translate.tab.c"
    break;

  case 57:
#line 204 "translate.y"
                                { (yyval.exprData) = handleBinaryExpr(BITWISE_NOT, (yyvsp[-2].exprData), (yyvsp[0].exprData)); }
#line 1960 "translate.tab.c"
    break;

  case 58:
#line 205 "translate.y"
                                { (yyval.exprData) = handleBinaryExpr(BITWISE_XOR, (yyvsp[-2].exprData), (yyvsp[0].exprData)); }
#line 1966 "translate.tab.c"
    break;

  case 59:
#line 206 "translate.y"
                                { (yyval.exprData) = handleBinaryExpr(LEFT_SHIFT, (yyvsp[-2].exprData), (yyvsp[0].exprData)); }
#line 1972 "translate.tab.c"
    break;

  case 60:
#line 207 "translate.y"
                                { (yyval.exprData) = handleBinaryExpr(RIGHT_SHIFT, (yyvsp[-2].exprData), (yyvsp[0].exprData)); }
#line 1978 "translate.tab.c"
    break;

  case 61:
#line 208 "translate.y"
                   { (yyval.exprData) = handleBinaryExpr(EQ, (yyvsp[-2].exprData), (yyvsp[0].exprData)); }
#line 1984 "translate.tab.c"
    break;

  case 62:
#line 209 "translate.y"
                   { (yyval.exprData) = handleBinaryExpr(NE, (yyvsp[-2].exprData), (yyvsp[0].exprData)); }
#line 1990 "translate.tab.c"
    break;

  case 63:
#line 210 "translate.y"
                   { (yyval.exprData) = handleBinaryExpr(LT, (yyvsp[-2].exprData), (yyvsp[0].exprData)); }
#line 1996 "translate.tab.c"
    break;

  case 64:
#line 211 "translate.y"
                   { (yyval.exprData) = handleBinaryExpr(GT, (yyvsp[-2].exprData), (yyvsp[0].exprData)); }
#line 2002 "translate.tab.c"
    break;

  case 65:
#line 212 "translate.y"
                   { (yyval.exprData) = handleBinaryExpr(LE, (yyvsp[-2].exprData), (yyvsp[0].exprData)); }
#line 2008 "translate.tab.c"
    break;

  case 66:
#line 213 "translate.y"
                   { (yyval.exprData) = handleBinaryExpr(GE, (yyvsp[-2].exprData), (yyvsp[0].exprData)); }
#line 2014 "translate.tab.c"
    break;

  case 67:
#line 214 "translate.y"
                                    { (yyval.exprData) = handleBinaryExpr(LOGICAL_AND, (yyvsp[-2].exprData), (yyvsp[0].exprData)); }
#line 2020 "translate.tab.c"
    break;

  case 68:
#line 215 "translate.y"
                                    { (yyval.exprData) = handleBinaryExpr(LOGICAL_OR, (yyvsp[-2].exprData), (yyvsp[0].exprData)); }
#line 2026 "translate.tab.c"
    break;

  case 69:
#line 216 "translate.y"
                                    { (yyval.exprData) = (yyvsp[-1].exprData); }
#line 2032 "translate.tab.c"
    break;

  case 70:
#line 217 "translate.y"
                                    { (yyval.exprData) = handleUnaryExpr(LOGICAL_NOT, (yyvsp[0].exprData)); }
#line 2038 "translate.tab.c"
    break;

  case 71:
#line 218 "translate.y"
                                    { (yyval.exprData) = handleUnaryExpr(SUB, (yyvsp[0].exprData)); }
#line 2044 "translate.tab.c"
    break;

  case 72:
#line 219 "translate.y"
                                    { (yyval.exprData) = (yyvsp[0].exprData); }
#line 2050 "translate.tab.c"
    break;

  case 73:
#line 220 "translate.y"
                                    { (yyval.exprData) = handleAssignExpr((yyvsp[-2].string), (yyvsp[0].exprData)); }
#line 2056 "translate.tab.c"
    break;

  case 74:
#line 221 "translate.y"
                                    { /* return symbol table size of identifier */ }
#line 2062 "translate.tab.c"
    break;

  case 75:
#line 225 "translate.y"
            { (yyval.exprData) = (yyvsp[0].exprData); }
#line 2068 "translate.tab.c"
    break;

  case 76:
#line 226 "translate.y"
                                                    { (yyval.exprData) = handleFunctionCall((yyvsp[-3].string), (yyvsp[-1].paramList)); }
#line 2074 "translate.tab.c"
    break;

  case 77:
#line 227 "translate.y"
           { (yyval.exprData) = handleAttr((yyvsp[0].string)); }
#line 2080 "translate.tab.c"
    break;

  case 78:
#line 230 "translate.y"
                                { (yyval.string) = (yyvsp[-1].string); }
#line 2086 "translate.tab.c"
    break;

  case 79:
#line 231 "translate.y"
                                { (yyval.string) = mergeStrPointers((yyvsp[-2].string), (yyvsp[0].string)); }
#line 2092 "translate.tab.c"
    break;

  case 80:
#line 234 "translate.y"
                        { (yyval.exprData) = handleInteger((yyvsp[0].integer)); }
#line 2098 "translate.tab.c"
    break;

  case 81:
#line 235 "translate.y"
                        { (yyval.exprData).returnType = strdup("ship"); (yyval.exprData).reg = 0;  }
#line 2104 "translate.tab.c"
    break;

  case 82:
#line 236 "translate.y"
                        { /* chama codeGen() e retorna o Temporary */  }
#line 2110 "translate.tab.c"
    break;

  case 83:
#line 237 "translate.y"
                        { /* chama codeGen() e retorna o Temporary */  }
#line 2116 "translate.tab.c"
    break;

  case 84:
#line 239 "translate.y"
                                { (yyval.boolean) = (yyvsp[0].boolean); }
#line 2122 "translate.tab.c"
    break;

  case 85:
#line 240 "translate.y"
                                { (yyval.boolean) = (yyvsp[0].boolean); }
#line 2128 "translate.tab.c"
    break;

  case 86:
#line 244 "translate.y"
                                    { (yyval.exprData) = (yyvsp[-1].exprData); }
#line 2134 "translate.tab.c"
    break;

  case 87:
#line 245 "translate.y"
                                    {  }
#line 2140 "translate.tab.c"
    break;

  case 88:
#line 249 "translate.y"
                                       { (yyval.integer) = (yyvsp[-1].integer); }
#line 2146 "translate.tab.c"
    break;

  case 89:
#line 250 "translate.y"
                                    { (yyval.integer) = 1; }
#line 2152 "translate.tab.c"
    break;


#line 2156 "translate.tab.c"

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
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

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
            yymsg = YY_CAST (char *, YYSTACK_ALLOC (YY_CAST (YYSIZE_T, yymsg_alloc)));
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
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;

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


/*-----------------------------------------------------.
| yyreturn -- parsing is finished, return the result.  |
`-----------------------------------------------------*/
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
                  yystos[+*yyssp], yyvsp);
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
#line 253 "translate.y"


/**
 * Handle variable creation.
 *
 * @param _type     - Node Type
 * @param _id       - Variable Id
 * @param _sz       - How many copys of the type this variable stores
 *
 * @return Nothing
 */
void handleVarDeclaration(char *type, char *id, int size) {
    Symbol *sym_type = symbolTableFind(st, type);
    if(!sym_type || sym_type->symbolType != SymbolTypeType) {
        reportAndExit("\"%s\" nao e um tipo de dados.", type);
    }

    Symbol *sym_id = symbolTableFindInBlock(st, id);
    if(sym_id) {
        reportAndExit("Redeclaracao do identificador \"%s\"", id);
    }

    int allocSize = sym_type->data.type.bytes * size;

    symbolTableInsert(st, symbolVariableNew(id, type, nextAddress, allocSize));
    nextAddress += allocSize;

    printf("variable %s of type %s with %d bytes added.\n", id, type, allocSize);
}

ExprData handleAttr(char *id) {
    Symbol *sym_id = symbolTableFind(st, id);
    if(!sym_id) {
        reportAndExit("\"%s\" nao eh uma variavel declarada.", id);
    }
    if(sym_id->symbolType != SymbolTypeVariable) {
        reportAndExit("\"%s\" nao eh um valor modificavel.", id);
    }
    
    ExprData ret;
    ret.returnType = sym_id->data.variable.type;
    ret.reg = riscVCodeGenVariable(riscv, id);
    ret.temp = pseudoCodeGenVariable(pseudo, id);
    return ret;
}

char *mergeStrPointers(char *a, char *b) {
    if(!a || !b) return NULL;
    int la = strlen(a);
    int lb = strlen(b);
    char *cat = (char*) malloc((la + lb + 2) * sizeof(char)); // size(a) + '.' + size(b) + '\0'
    cat[0] = '\0'; // make sure that this is a empty string
    strcat(cat, a);
    strcat(cat, ".");
    strcat(cat, b);
    return cat;
}

ExprData handleBinaryExpr(int opcode, ExprData e1, ExprData e2) {
    if(strcmp(e1.returnType, e2.returnType))
        reportAndExit("Impossivel fazer a operação entre tipos \"%s\" e \"%s\".", e1.returnType, e2.returnType);
    
    ExprData ret;
    ret.returnType = e1.returnType;

    ret.reg = riscVCodeGenBinaryOperator(riscv, opcode, e1.reg, e2.reg);
    ret.temp = pseudoCodeGenBinaryOperator(pseudo,opcode,e1.temp, e2.temp);

    return ret;
}

ExprData handleUnaryExpr(int opcode, ExprData e) {
    ExprData ret;
    ret.returnType = e.returnType;
    ret.reg = riscVCodeGenUnaryOperator(riscv, opcode, e.reg);
    ret.temp = pseudoCodeGenUnaryOperator(pseudo, opcode, e.temp);
    return ret;
}

ExprData handleAssignExpr(char *id, ExprData e) {
    Symbol *sym = symbolTableFind(st, id);

    if(!sym) reportAndExit("Identificador \"%s\" nao declarado.", id);

    if(strcmp(sym->data.variable.type, e.returnType)) reportAndExit("Impossivel atribuir um valor do tipo \"%s\" para uma variavel do tipo \"%s\".", e.returnType, sym->data.variable.type);

    ExprData ret;
    ret.returnType = e.returnType;
    ret.reg = riscVCodeGenAssign(riscv, id, e.reg);
    ret.temp = pseudoCodeGenAssign(pseudo,id,e.temp);
    return ret;
}

/* IF - ELSE */
void handleIfAfterExpr(ExprData e) {
    riscVCodeIfAfterExpr(riscv,e.reg);
}

void handleIfAfterStmt() {
    riscVCodeIfAfterStmt(riscv);
}

void handleIfAfterElse() {
    riscVCodeIfAfterElse(riscv);
}

/* WHILE - FOR - DO WHILE */
void handleRepEntry() {
    riscVCodeRepEntry(riscv);
}

void handleRepAfterExpr(ExprData e) {
    riscVCodeRepAfterExpr(riscv, e.reg);
}

void handleRepExit() {
    riscVCodeRepExit(riscv);
}

void handleRepUpdate() {
    riscVCodeRepUpdate(riscv);
}

void handleRepStmt() {
    riscVCodeRepStmt(riscv);
}

void handleRepGotoEntry() {
    riscVCodeRepGotoEntry(riscv);
}

void handleRepGotoUpdate() {
    riscVCodeRepGotoUpdate(riscv);
}

ExprData handleFunctionCall(char *id, FuncParamList *params) {
    ExprData ret;
    ret.reg = 0;
    ret.temp = 0;

    if(!strcmp(id, "parrot")) {
        if(functParamListSize(&params) != 1) {
            reportAndExit("parrot requer 1 parametro.");
        }

        FuncParam p = functGetParam(&params, 0);

        fprintf(friscv, "mv a1, x%d\n", p.reg);
        fprintf(friscv, "jal x1, printf\n");
        ret.returnType = strdup("void");
        return ret;
    }

    if(!strcmp(id, "plunder")) {
        if(functParamListSize(&params) != 0) {
            reportAndExit("plunder nao aceita parametros.");
        }

        fprintf(friscv, "jal x1, scanf\n");
        ret.reg = 11;
        ret.returnType = strdup("jib");
        return ret;
    }

    return ret;
}
ExprData handleInteger(int integer){
    ExprData ret;
    ret.returnType = strdup("jib"); 
    ret.reg = riscVCodeGenInteger(riscv, integer);
    ret.temp = pseudoCodeGenInteger(pseudo, integer);
    return ret;
}

void reportAndExit(const char *s, ...) {
    char msg[100];
    va_list args;
    va_start(args, s);
    vsnprintf(msg, sizeof(msg), s, args);
    va_end(args);
    yyerror(msg);
    onExit();
    exit(0);
}

void onExit() {
    riscVSaveRegisters(riscv);
    riscVCodeExitProgram(riscv);

    fclose(gen);
    fclose(prod);
    fclose(friscv);
    symbolTableDelete(st);
}

void onStart() {
    char sourceCode[1000000];
    size_t bytesRead = fread(sourceCode, sizeof(char), sizeof(sourceCode) - 1, stdin);
    sourceCode[bytesRead] = '\0';

    printSourceCodeWithLineNumbers(sourceCode);

    yyin = fmemopen(sourceCode, bytesRead, "r");
    
    prod = fopen("./build/producoes.output", "w");
    gen = fopen("./build/code.output", "w");

    st = symbolTableNew();

    friscv = fopen("./output/riscv.s", "w");
    riscv = riscV_ContextNew(friscv, st);

    fpseudo = fopen("./output/temp.txt","w");
    pseudo = pseudo_ContextNew(fpseudo,st);


    symbolTableCreateBlock(st);
    
    // jib a;
    // symbol {a, variavel, jib, 4, 0}
    
    
    symbolTableInsert(st, symbolTypeNew("jib", 4));
    symbolTableInsert(st, symbolTypeNew("void", 4));
    symbolTableInsert(st, symbolFunctionNew("parrot", "void"));
}

void executeProgram() {
    symbolTableShow(st, stdout);
    printf("Programa sintaticamente correto\n");
}

void yyerror(const char *s) {
    printf("Erro proximo a linha %d. %s\n", line, s);
}

int main(void) {
    onStart();
    yyparse();
    onExit();
    return 0;
}
