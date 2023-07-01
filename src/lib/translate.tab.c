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

int nextAddress = 0;

void blockOpen();
void blockClose();

// void handleStruct();
void handleVar(char *type, char *id, int size);
ExprData handleAttr(char *id);
void handleOperation(int opcode, ...);
ExprData handleBinaryExpr(int opcode, ExprData e1, ExprData e2);
ExprData handleAssignExpr(char *id, ExprData e);
void reportAndExit(const char *s, ...);

char *mergeStrPointers(char *a, char *b);

void handleCondExpr(ExprData e);
void handleCondElse();
void handleCondExit();

void handleRepEntry();
void handleRepExpr(ExprData e);
void handleRepExit();


#line 121 "translate.tab.c"

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
#line 53 "translate.y"

    char *string;
    int integer;
    double decimal;
    int boolean;
    ExprData exprData;

#line 255 "translate.tab.c"

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
#define YYLAST   488

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  74
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  29
/* YYNRULES -- Number of rules.  */
#define YYNRULES  88
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  185

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
       0,    98,    98,   101,   102,   105,   106,   107,   108,   109,
     110,   111,   113,   114,   114,   115,   118,   121,   122,   123,
     126,   127,   128,   131,   131,   134,   137,   137,   140,   141,
     144,   145,   148,   149,   152,   153,   157,   158,   159,   160,
     161,   162,   163,   166,   167,   170,   171,   174,   175,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   191,   192,   193,   194,   195,   196,   197,   198,
     199,   200,   201,   202,   206,   207,   208,   211,   212,   215,
     216,   217,   218,   220,   221,   225,   226,   230,   231
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
  "program", "stmts", "stmt", "conditional", "$@1", "condexpr", "caselist",
  "repetition", "repexpr", "$@2", "var", "func", "$@3", "typelist",
  "termlist", "opttypelist", "opttermlist", "commands", "varlist",
  "idlist", "optexpr", "expr", "term", "attr", "const", "boolean",
  "exprvector", "constvector", YY_NULLPTR
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

#define YYPACT_NINF (-122)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-89)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -122,    17,   208,  -122,   -48,   -38,   -37,    -4,   -44,   222,
     -43,   208,    -1,   -30,     3,   -26,    12,   222,  -122,   222,
     222,  -122,  -122,   -27,  -122,  -122,  -122,  -122,  -122,  -122,
     -29,  -122,  -122,   301,  -122,   -21,  -122,  -122,    19,  -122,
    -122,   222,    11,   -23,    22,   323,    46,    62,   222,  -122,
     222,    42,  -122,   259,   130,  -122,  -122,   222,   -15,   -14,
    -122,  -122,   222,   222,   222,   222,   222,   222,   222,   222,
     222,   222,   222,   222,   222,   222,   222,   222,   222,   222,
     222,  -122,    43,   222,  -122,    77,   323,    45,  -122,  -122,
      51,    55,    81,    59,    86,   222,  -122,  -122,    52,    60,
      88,  -122,    98,    57,    93,  -122,    35,    35,    85,    85,
     410,   377,    85,    85,   -12,   -12,   440,   440,   440,   440,
     426,   426,   394,   360,   342,    97,  -122,   323,   208,    70,
      99,   -31,   222,   222,    96,  -122,   208,   323,  -122,   -15,
    -122,   104,    71,   135,    45,  -122,  -122,    73,    87,   282,
      89,  -122,  -122,  -122,  -122,  -122,    91,   120,  -122,  -122,
     125,  -122,   100,   222,    10,    71,   124,   208,  -122,   128,
     -15,   110,  -122,  -122,  -122,  -122,   208,   112,  -122,   169,
    -122,  -122,   208,  -122,   208
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       4,     0,     2,     1,     0,     0,     0,     0,     0,    48,
       0,     0,     0,     0,     0,     0,     0,     0,     4,     0,
       0,    80,    81,    86,    79,    83,    84,     3,     5,     6,
       0,     7,     9,     0,    71,    76,    74,    82,     0,    37,
      38,     0,     0,    86,     0,    47,     0,     0,    48,    73,
       0,     0,    23,     0,     0,    70,    69,     0,    35,    26,
      77,     8,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    10,     0,     0,    40,     0,    16,     0,    36,    44,
       0,     0,     0,     0,     0,     0,    68,    11,     0,    34,
       0,    31,    76,     0,     0,    25,    49,    50,    51,    52,
      54,    55,    56,    53,    58,    59,    62,    63,    64,    65,
      60,    61,    57,    66,    67,    86,    78,    72,     0,    46,
       0,     0,     0,    48,     0,    39,     0,    24,    85,     0,
      75,     0,    33,    12,     0,    42,    41,     0,     0,     0,
       0,    19,    20,    30,    87,    29,    32,     0,    13,    45,
      88,    43,     0,    48,     0,     0,     0,     0,    22,     0,
       0,     0,    15,    28,     4,    14,     0,     0,     4,     0,
      21,     4,    18,    27,    17
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
    -122,  -122,   -17,   -11,  -122,  -122,   123,  -122,  -122,  -122,
    -122,  -121,  -122,  -122,  -122,  -122,  -122,  -122,  -122,  -122,
      31,   -45,    -5,   -50,   -56,  -122,  -122,  -122,  -122
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,     2,    27,    28,   167,    85,   164,    29,    94,
      95,    30,    31,   104,   156,    99,   157,   100,    32,   131,
     130,    44,    33,    34,    35,    36,    37,    60,   105
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      47,    54,   102,    91,    45,    82,   146,    57,   101,    58,
     148,    57,    53,    58,    55,    56,   170,     3,    38,   171,
     103,   155,    39,    40,    42,    46,   126,    62,    63,    64,
      65,    61,    41,    68,    69,    48,    86,   147,    49,    50,
      83,    59,    51,    45,   173,    86,   -88,   172,    52,    87,
      21,    22,    98,    43,    24,    25,    26,   106,   107,   108,
     109,   110,   111,   112,   113,   114,   115,   116,   117,   118,
     119,   120,   121,   122,   123,   124,    64,    65,   127,    84,
      68,    69,    88,   102,    89,   138,    90,   132,   150,   153,
     137,    62,    63,    64,    65,    66,    67,    68,    69,    70,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    80,
      93,   125,   128,   129,   102,   133,   134,   143,   169,   135,
     177,   136,   139,   140,    82,   152,   141,   149,    45,   142,
      68,    57,   144,     4,   151,     5,   145,   154,     6,   147,
       7,   160,     8,     9,    10,    11,   158,   161,    12,   163,
      13,    14,    15,   165,    16,   166,   175,   179,    45,   103,
     168,   182,   174,   176,   184,   180,    17,    97,    18,   178,
      19,   181,     4,    92,     5,   159,     0,     6,     0,     7,
       0,     8,     9,    10,    11,     0,     0,    12,    20,    13,
      14,    15,     0,    16,     0,    21,    22,     0,    23,    24,
      25,    26,     0,     0,     0,    17,   183,    18,     0,    19,
       0,     4,     0,     5,     0,     0,     6,     0,     7,     0,
       8,     9,    10,    11,     0,     0,    12,    20,    13,    14,
      15,     0,    16,     0,    21,    22,     0,    23,    24,    25,
      26,     0,    13,     0,    17,     0,    18,     0,    19,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    17,     0,
       0,     0,    19,     0,     0,     0,    20,     0,     0,     0,
       0,     0,     0,    21,    22,     0,    23,    24,    25,    26,
      20,     0,     0,     0,     0,     0,     0,    21,    22,     0,
      43,    24,    25,    26,    96,     0,     0,     0,    62,    63,
      64,    65,    66,    67,    68,    69,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    80,   162,     0,     0,
       0,    62,    63,    64,    65,    66,    67,    68,    69,    70,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    80,
      62,    63,    64,    65,    66,    67,    68,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,     0,
       0,    81,    62,    63,    64,    65,    66,    67,    68,    69,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    62,    63,    64,    65,    66,    67,    68,    69,    70,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    62,
      63,    64,    65,    66,    67,    68,    69,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    62,    63,    64,    65,
      66,     0,    68,    69,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    62,    63,    64,    65,    66,     0,    68,
      69,    70,    71,    72,    73,    74,    75,    76,    77,    62,
      63,    64,    65,     0,     0,    68,    69,    70,    71,    72,
      73,    74,    75,    76,    77,    62,    63,    64,    65,     0,
       0,    68,    69,    70,    71,    72,    73,    74,    75,    62,
      63,    64,    65,     0,     0,    68,    69,    70,    71
};

static const yytype_int16 yycheck[] =
{
      11,    18,    58,    48,     9,    26,    37,    34,    58,    36,
     131,    34,    17,    36,    19,    20,     6,     0,    66,     9,
      34,   142,    60,    60,    68,    68,    82,    39,    40,    41,
      42,    60,    36,    45,    46,    36,    41,    68,    68,    36,
      61,    68,    68,    48,   165,    50,    60,    37,    36,    38,
      65,    66,    57,    68,    69,    70,    71,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    41,    42,    83,    60,
      45,    46,    60,   139,    38,    33,    24,    36,   133,   139,
      95,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      68,    68,    35,    68,   170,    60,    35,   128,   163,    60,
     170,    35,    62,    35,    26,   136,    69,   132,   133,    36,
      45,    34,    62,     3,    38,     5,    37,    33,     8,    68,
      10,    68,    12,    13,    14,    15,    11,    60,    18,    60,
      20,    21,    22,    62,    24,    35,   167,   174,   163,    34,
      60,   178,    38,    35,   181,   176,    36,    37,    38,    59,
      40,    59,     3,    50,     5,   144,    -1,     8,    -1,    10,
      -1,    12,    13,    14,    15,    -1,    -1,    18,    58,    20,
      21,    22,    -1,    24,    -1,    65,    66,    -1,    68,    69,
      70,    71,    -1,    -1,    -1,    36,    37,    38,    -1,    40,
      -1,     3,    -1,     5,    -1,    -1,     8,    -1,    10,    -1,
      12,    13,    14,    15,    -1,    -1,    18,    58,    20,    21,
      22,    -1,    24,    -1,    65,    66,    -1,    68,    69,    70,
      71,    -1,    20,    -1,    36,    -1,    38,    -1,    40,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    36,    -1,
      -1,    -1,    40,    -1,    -1,    -1,    58,    -1,    -1,    -1,
      -1,    -1,    -1,    65,    66,    -1,    68,    69,    70,    71,
      58,    -1,    -1,    -1,    -1,    -1,    -1,    65,    66,    -1,
      68,    69,    70,    71,    35,    -1,    -1,    -1,    39,    40,
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
      50,    51,    52,    53,    54,    39,    40,    41,    42,    -1,
      -1,    45,    46,    47,    48,    49,    50,    51,    52,    39,
      40,    41,    42,    -1,    -1,    45,    46,    47,    48
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    75,    76,     0,     3,     5,     8,    10,    12,    13,
      14,    15,    18,    20,    21,    22,    24,    36,    38,    40,
      58,    65,    66,    68,    69,    70,    71,    77,    78,    82,
      85,    86,    92,    96,    97,    98,    99,   100,    66,    60,
      60,    36,    68,    68,    95,    96,    68,    77,    36,    68,
      36,    68,    36,    96,    76,    96,    96,    34,    36,    68,
     101,    60,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    60,    26,    61,    60,    80,    96,    38,    60,    38,
      24,    95,    80,    68,    83,    84,    35,    37,    96,    89,
      91,    97,    98,    34,    87,   102,    96,    96,    96,    96,
      96,    96,    96,    96,    96,    96,    96,    96,    96,    96,
      96,    96,    96,    96,    96,    68,    98,    96,    35,    68,
      94,    93,    36,    60,    35,    60,    35,    96,    33,    62,
      35,    69,    36,    77,    62,    37,    37,    68,    85,    96,
      95,    38,    77,    97,    33,    85,    88,    90,    11,    94,
      68,    60,    35,    60,    81,    62,    35,    79,    60,    95,
       6,     9,    37,    85,    38,    77,    35,    97,    59,    76,
      77,    59,    76,    37,    76
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    74,    75,    76,    76,    77,    77,    77,    77,    77,
      77,    77,    78,    79,    78,    78,    80,    81,    81,    81,
      82,    82,    82,    84,    83,    85,    87,    86,    88,    88,
      89,    89,    90,    90,    91,    91,    92,    92,    92,    92,
      92,    92,    92,    93,    93,    94,    94,    95,    95,    96,
      96,    96,    96,    96,    96,    96,    96,    96,    96,    96,
      96,    96,    96,    96,    96,    96,    96,    96,    96,    96,
      96,    96,    96,    96,    97,    97,    97,    98,    98,    99,
      99,    99,    99,   100,   100,   101,   101,   102,   102
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     0,     1,     1,     1,     2,     1,
       2,     3,     5,     0,     8,     7,     1,     5,     4,     0,
       5,     9,     7,     0,     2,     3,     0,     9,     3,     1,
       3,     1,     1,     0,     1,     0,     3,     2,     2,     4,
       3,     5,     5,     3,     0,     3,     1,     1,     0,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     2,
       2,     1,     3,     2,     1,     4,     1,     2,     3,     1,
       1,     1,     1,     1,     1,     3,     0,     3,     0
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
#line 98 "translate.y"
               {  }
#line 1623 "translate.tab.c"
    break;

  case 3:
#line 101 "translate.y"
                                    {  }
#line 1629 "translate.tab.c"
    break;

  case 4:
#line 102 "translate.y"
                                    {  }
#line 1635 "translate.tab.c"
    break;

  case 5:
#line 105 "translate.y"
                                {  }
#line 1641 "translate.tab.c"
    break;

  case 6:
#line 106 "translate.y"
                                {  }
#line 1647 "translate.tab.c"
    break;

  case 7:
#line 107 "translate.y"
                                {  }
#line 1653 "translate.tab.c"
    break;

  case 8:
#line 108 "translate.y"
                                {  }
#line 1659 "translate.tab.c"
    break;

  case 9:
#line 109 "translate.y"
                                {  }
#line 1665 "translate.tab.c"
    break;

  case 10:
#line 110 "translate.y"
                                {  }
#line 1671 "translate.tab.c"
    break;

  case 11:
#line 111 "translate.y"
                                   {  }
#line 1677 "translate.tab.c"
    break;

  case 12:
#line 113 "translate.y"
                                                               { handleCondElse(); handleCondExit(); }
#line 1683 "translate.tab.c"
    break;

  case 13:
#line 114 "translate.y"
                                                   { handleCondElse();  }
#line 1689 "translate.tab.c"
    break;

  case 14:
#line 114 "translate.y"
                                                                               { handleCondExit(); }
#line 1695 "translate.tab.c"
    break;

  case 15:
#line 115 "translate.y"
                                                                             {  }
#line 1701 "translate.tab.c"
    break;

  case 16:
#line 118 "translate.y"
                                { handleCondExpr((yyvsp[0].exprData)); }
#line 1707 "translate.tab.c"
    break;

  case 17:
#line 121 "translate.y"
                                            {  }
#line 1713 "translate.tab.c"
    break;

  case 18:
#line 122 "translate.y"
                                            {  }
#line 1719 "translate.tab.c"
    break;

  case 19:
#line 123 "translate.y"
                                            {  }
#line 1725 "translate.tab.c"
    break;

  case 20:
#line 126 "translate.y"
                                                      {}
#line 1731 "translate.tab.c"
    break;

  case 21:
#line 127 "translate.y"
                                                                                    {}
#line 1737 "translate.tab.c"
    break;

  case 22:
#line 128 "translate.y"
                                                           {}
#line 1743 "translate.tab.c"
    break;

  case 23:
#line 131 "translate.y"
         { handleRepEntry(); }
#line 1749 "translate.tab.c"
    break;

  case 24:
#line 131 "translate.y"
                                    { handleRepExpr((yyvsp[0].exprData)); }
#line 1755 "translate.tab.c"
    break;

  case 25:
#line 134 "translate.y"
                                       { handleVar((yyvsp[-2].string), (yyvsp[-1].string), (yyvsp[0].integer)); }
#line 1761 "translate.tab.c"
    break;

  case 26:
#line 137 "translate.y"
                            {}
#line 1767 "translate.tab.c"
    break;

  case 27:
#line 137 "translate.y"
                                                                                               {}
#line 1773 "translate.tab.c"
    break;

  case 28:
#line 140 "translate.y"
                             {}
#line 1779 "translate.tab.c"
    break;

  case 29:
#line 141 "translate.y"
          {}
#line 1785 "translate.tab.c"
    break;

  case 30:
#line 144 "translate.y"
                              {}
#line 1791 "translate.tab.c"
    break;

  case 31:
#line 145 "translate.y"
           {  }
#line 1797 "translate.tab.c"
    break;

  case 32:
#line 148 "translate.y"
                        {  }
#line 1803 "translate.tab.c"
    break;

  case 33:
#line 149 "translate.y"
                        {  }
#line 1809 "translate.tab.c"
    break;

  case 34:
#line 152 "translate.y"
                        {  }
#line 1815 "translate.tab.c"
    break;

  case 35:
#line 153 "translate.y"
                        {  }
#line 1821 "translate.tab.c"
    break;

  case 36:
#line 157 "translate.y"
                              {}
#line 1827 "translate.tab.c"
    break;

  case 37:
#line 158 "translate.y"
                       {}
#line 1833 "translate.tab.c"
    break;

  case 38:
#line 159 "translate.y"
                          {}
#line 1839 "translate.tab.c"
    break;

  case 39:
#line 160 "translate.y"
                                               {}
#line 1845 "translate.tab.c"
    break;

  case 40:
#line 161 "translate.y"
                                {}
#line 1851 "translate.tab.c"
    break;

  case 41:
#line 162 "translate.y"
                                                       { }
#line 1857 "translate.tab.c"
    break;

  case 42:
#line 163 "translate.y"
                                                    { }
#line 1863 "translate.tab.c"
    break;

  case 43:
#line 166 "translate.y"
                                    {  }
#line 1869 "translate.tab.c"
    break;

  case 44:
#line 167 "translate.y"
                                    {  }
#line 1875 "translate.tab.c"
    break;

  case 45:
#line 170 "translate.y"
                                    {  }
#line 1881 "translate.tab.c"
    break;

  case 46:
#line 171 "translate.y"
                                    {  }
#line 1887 "translate.tab.c"
    break;

  case 47:
#line 174 "translate.y"
                                    {  }
#line 1893 "translate.tab.c"
    break;

  case 48:
#line 175 "translate.y"
                                    { }
#line 1899 "translate.tab.c"
    break;

  case 49:
#line 178 "translate.y"
                    { (yyval.exprData) = handleBinaryExpr(ADD, (yyvsp[-2].exprData), (yyvsp[0].exprData)); }
#line 1905 "translate.tab.c"
    break;

  case 50:
#line 179 "translate.y"
                    { (yyval.exprData) = handleBinaryExpr(SUB, (yyvsp[-2].exprData), (yyvsp[0].exprData)); }
#line 1911 "translate.tab.c"
    break;

  case 51:
#line 180 "translate.y"
                    { /* geraTemp1, geraTemp2, chama codeGen(t1, op, t2) */ }
#line 1917 "translate.tab.c"
    break;

  case 52:
#line 181 "translate.y"
                    { /* geraTemp1, geraTemp2, chama codeGen(t1, op, t2) */ }
#line 1923 "translate.tab.c"
    break;

  case 53:
#line 182 "translate.y"
                    { /* geraTemp1, geraTemp2, chama codeGen(t1, op, t2) */ }
#line 1929 "translate.tab.c"
    break;

  case 54:
#line 183 "translate.y"
                                { /* geraTemp1, geraTemp2, chama codeGen(t1, op, t2) */ }
#line 1935 "translate.tab.c"
    break;

  case 55:
#line 184 "translate.y"
                                { /* geraTemp1, geraTemp2, chama codeGen(t1, op, t2) */ }
#line 1941 "translate.tab.c"
    break;

  case 56:
#line 185 "translate.y"
                                { /* geraTemp1, geraTemp2, chama codeGen(t1, op, t2) */ }
#line 1947 "translate.tab.c"
    break;

  case 57:
#line 186 "translate.y"
                                { /* geraTemp1, geraTemp2, chama codeGen(t1, op, t2) */ }
#line 1953 "translate.tab.c"
    break;

  case 58:
#line 187 "translate.y"
                                { (yyval.exprData) = handleBinaryExpr(LEFT_SHIFT, (yyvsp[-2].exprData), (yyvsp[0].exprData)); }
#line 1959 "translate.tab.c"
    break;

  case 59:
#line 188 "translate.y"
                                { (yyval.exprData) = handleBinaryExpr(RIGHT_SHIFT, (yyvsp[-2].exprData), (yyvsp[0].exprData)); }
#line 1965 "translate.tab.c"
    break;

  case 60:
#line 189 "translate.y"
                   { /* geraTemp1, geraTemp2, chama codeGen(t1, op, t2) */ }
#line 1971 "translate.tab.c"
    break;

  case 61:
#line 190 "translate.y"
                   { /* geraTemp1, geraTemp2, chama codeGen(t1, op, t2) */ }
#line 1977 "translate.tab.c"
    break;

  case 62:
#line 191 "translate.y"
                   { /* geraTemp1, geraTemp2, chama codeGen(t1, op, t2) */ }
#line 1983 "translate.tab.c"
    break;

  case 63:
#line 192 "translate.y"
                   { /* geraTemp1, geraTemp2, chama codeGen(t1, op, t2) */ }
#line 1989 "translate.tab.c"
    break;

  case 64:
#line 193 "translate.y"
                   { /* geraTemp1, geraTemp2, chama codeGen(t1, op, t2) */ }
#line 1995 "translate.tab.c"
    break;

  case 65:
#line 194 "translate.y"
                   { /* geraTemp1, geraTemp2, chama codeGen(t1, op, t2) */ }
#line 2001 "translate.tab.c"
    break;

  case 66:
#line 195 "translate.y"
                                    { (yyval.exprData) = handleBinaryExpr(LOGICAL_AND, (yyvsp[-2].exprData), (yyvsp[0].exprData)); }
#line 2007 "translate.tab.c"
    break;

  case 67:
#line 196 "translate.y"
                                    { (yyval.exprData) = handleBinaryExpr(LOGICAL_OR, (yyvsp[-2].exprData), (yyvsp[0].exprData)); }
#line 2013 "translate.tab.c"
    break;

  case 68:
#line 197 "translate.y"
                                    { (yyval.exprData) = (yyvsp[-1].exprData); }
#line 2019 "translate.tab.c"
    break;

  case 69:
#line 198 "translate.y"
                                    { /* geraTemp1, chama codeGen(op, t1) */ }
#line 2025 "translate.tab.c"
    break;

  case 70:
#line 199 "translate.y"
                                    {  }
#line 2031 "translate.tab.c"
    break;

  case 71:
#line 200 "translate.y"
                                    { (yyval.exprData) = (yyvsp[0].exprData); }
#line 2037 "translate.tab.c"
    break;

  case 72:
#line 201 "translate.y"
                                    { (yyval.exprData) = handleAssignExpr((yyvsp[-2].string), (yyvsp[0].exprData)); }
#line 2043 "translate.tab.c"
    break;

  case 73:
#line 202 "translate.y"
                                    { /* return symbol table size of identifier */ }
#line 2049 "translate.tab.c"
    break;

  case 74:
#line 206 "translate.y"
            { (yyval.exprData) = (yyvsp[0].exprData); }
#line 2055 "translate.tab.c"
    break;

  case 75:
#line 207 "translate.y"
                                                    { /* cria a funcao e fala o temp */ }
#line 2061 "translate.tab.c"
    break;

  case 76:
#line 208 "translate.y"
           { (yyval.exprData) = handleAttr((yyvsp[0].string)); }
#line 2067 "translate.tab.c"
    break;

  case 77:
#line 211 "translate.y"
                                { (yyval.string) = (yyvsp[-1].string); }
#line 2073 "translate.tab.c"
    break;

  case 78:
#line 212 "translate.y"
                                { (yyval.string) = mergeStrPointers((yyvsp[-2].string), (yyvsp[0].string)); }
#line 2079 "translate.tab.c"
    break;

  case 79:
#line 215 "translate.y"
                        { (yyval.exprData).returnType = strdup("jib"); (yyval.exprData).reg = riscVCodeGenInteger(riscv, (yyvsp[0].integer)); }
#line 2085 "translate.tab.c"
    break;

  case 80:
#line 216 "translate.y"
                        { (yyval.exprData).returnType = strdup("ship"); (yyval.exprData).reg = 0;  }
#line 2091 "translate.tab.c"
    break;

  case 81:
#line 217 "translate.y"
                        { /* chama codeGen() e retorna o Temporary */  }
#line 2097 "translate.tab.c"
    break;

  case 82:
#line 218 "translate.y"
                        { /* chama codeGen() e retorna o Temporary */  }
#line 2103 "translate.tab.c"
    break;

  case 83:
#line 220 "translate.y"
                                { (yyval.boolean) = (yyvsp[0].boolean); }
#line 2109 "translate.tab.c"
    break;

  case 84:
#line 221 "translate.y"
                                { (yyval.boolean) = (yyvsp[0].boolean); }
#line 2115 "translate.tab.c"
    break;

  case 85:
#line 225 "translate.y"
                                    { (yyval.exprData) = (yyvsp[-1].exprData); }
#line 2121 "translate.tab.c"
    break;

  case 86:
#line 226 "translate.y"
                                    {  }
#line 2127 "translate.tab.c"
    break;

  case 87:
#line 230 "translate.y"
                                       { (yyval.integer) = (yyvsp[-1].integer); }
#line 2133 "translate.tab.c"
    break;

  case 88:
#line 231 "translate.y"
                                    { (yyval.integer) = 1; }
#line 2139 "translate.tab.c"
    break;


#line 2143 "translate.tab.c"

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
#line 234 "translate.y"


/**
 * Handle variable creation.
 *
 * @param _type     - Node Type
 * @param _id       - Variable Id
 * @param _sz       - How many copys of the type this variable stores
 *
 * @return Nothing
 */
void handleVar(char *type, char *id, int size) {
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

    return ret;
}

ExprData handleAssignExpr(char *id, ExprData e) {
    Symbol *sym = symbolTableFind(st, id);

    if(strcmp(sym->data.variable.type, e.returnType)) reportAndExit("Impossivel atribuir um valor do tipo \"%s\" para uma variavel do tipo \"%s\".", e.returnType, sym->data.variable.type);

    ExprData ret;
    ret.returnType = e.returnType;
    ret.reg = riscVCodeGenAssign(riscv, id, e.reg);
}

void handleCondExpr(ExprData e) {
    riscVCodeExpr(riscv,e.reg);
}

void handleCondElse() {
    riscVCodeElse(riscv);
}

void handleCondExit() {
    riscVCodeExit(riscv);
}

void handleRepEntry() {

}

void handleRepExpr(ExprData e) {

}

void handleRepExit() {

}

/* void handleOperation(int opcode, ...) {
    va_list args;
    va_start(args, opcode);

    switch(opcode) {
    case ASSIGN: {
        STNIdentifier *left = STN_IDENTIFIER(va_arg(args, SyntaxTreeNode*));
        STNOperation *right = STN_OPERATION(va_arg(args, SyntaxTreeNode*));

        Symbol *sym_id = symbolTableFind(st, left->id);
        if(!sym_id) reportAndExit("Variável \"%s\" nao declarada\n", left->id);
        if(sym_id->type != SymbolTypeVariable) reportAndExit("\"%s\" nao e uma variavel\n", left->id);
        STNReturnExec r = stnExecute(STN(right));
        if(strcmp(sym_id->datatype, r.type)) 
            reportAndExit("Impossivel assinalar um valor do tipo \"%s\" para uma variavel do tipo \"%s\"\n", r.type, sym_id->datatype);
        fprintf(gen, "addi Rd, R%d, 0\n", r.temp);
        break;
    }
    default: reportAndExit("Invalid Operation\n");
    };

    va_end(args);
} */

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

    friscv = fopen("./build/riscv.asm", "w");
    riscv = riscV_ContextNew(friscv, st);



    symbolTableCreateBlock(st);
    
    // jib a;
    // symbol {a, variavel, jib, 4, 0}
    
    
    symbolTableInsert(st, symbolTypeNew("jib", 4));
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
