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

extern int yylex();
extern void yyerror(const char*);
extern FILE* yyin; // Declarar a variável global de entrada do analisador léxico
extern int line;

void onExit();
void onStart();
void executeProgram();

SymbolTable *st;
FILE *prod;

void blockOpen();
void blockClose();
void addId(char *id, Enumtypes type);


#line 95 "translate.tab.c"

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
    UNSIGNED = 258,
    SIGNED = 259,
    SHORT = 260,
    LONG = 261,
    INCLUDE = 262,
    MAIN = 263,
    BREAK = 264,
    CASE = 265,
    CONST = 266,
    CONTINUE = 267,
    DEFAULT = 268,
    IF = 269,
    ELSE = 270,
    ENUM = 271,
    RETURN = 272,
    STRUCT = 273,
    INT = 274,
    FLOAT = 275,
    DOUBLE = 276,
    BOOL = 277,
    TRUE = 278,
    FALSE = 279,
    CHAR = 280,
    DO = 281,
    PRINTF = 282,
    SCANF = 283,
    FOR = 284,
    GOTO = 285,
    SIZEOF = 286,
    SWITCH = 287,
    TYPEDEF = 288,
    UNION = 289,
    WHILE = 290,
    FREE = 291,
    POINTER = 292,
    SLICE = 293,
    SOME = 294,
    REDUCE = 295,
    FILTER = 296,
    MAP = 297,
    SORT = 298,
    CLOSE_BRACKET = 299,
    OPEN_BRACKET = 300,
    CLOSE_PAREN = 301,
    OPEN_PAREN = 302,
    BLOCK_CLOSE = 303,
    BLOCK_OPEN = 304,
    DOT = 305,
    INCREMENT = 306,
    DECREMENT = 307,
    ADD = 308,
    SUB = 309,
    MUL = 310,
    DIV = 311,
    BITWISE_AND = 312,
    BITWISE_OR = 313,
    BITWISE_NOT = 314,
    MOD = 315,
    LEFT_SHIFT = 316,
    RIGHT_SHIFT = 317,
    LT = 318,
    GT = 319,
    LE = 320,
    GE = 321,
    EQ = 322,
    NE = 323,
    BITWISE_XOR = 324,
    LOGICAL_AND = 325,
    LOGICAL_OR = 326,
    LOGICAL_NOT = 327,
    QUEST = 328,
    COLON = 329,
    SEMI_COLON = 330,
    ASSIGN = 331,
    ADD_ASSIGN = 332,
    SUB_ASSIGN = 333,
    MUL_ASSIGN = 334,
    DIV_ASSIGN = 335,
    MOD_ASSIGN = 336,
    LEFT_SHIFT_ASSIGN = 337,
    RIGHT_SHIFT_ASSIGN = 338,
    BITWISE_AND_ASSIGN = 339,
    BITWISE_OR_ASSIGN = 340,
    BITWISE_XOR_ASSIGN = 341,
    COMMA = 342,
    INTEGER = 343,
    DECIMAL = 344,
    STRING = 345,
    IDENTIFIER = 346,
    COMMENTS = 347,
    INVALID = 348,
    IFX = 349,
    UNARY = 350
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 26 "translate.y"

    int number;
    double decimal;
    char* string;
    Enumtypes typeValue;

#line 250 "translate.tab.c"

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
#define YYLAST   733

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  96
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  38
/* YYNRULES -- Number of rules.  */
#define YYNRULES  132
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  232

#define YYUNDEFTOK  2
#define YYMAXUTOK   350


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
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   153,   153,   159,   162,   165,   168,   171,   174,   177,
     177,   177,   181,   184,   187,   192,   193,   194,   197,   200,
     203,   208,   208,   211,   211,   216,   220,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   239,   239,
     239,   244,   244,   247,   247,   252,   255,   260,   261,   264,
     265,   269,   272,   275,   278,   281,   284,   287,   290,   293,
     296,   299,   304,   305,   308,   309,   312,   313,   316,   317,
     320,   323,   326,   329,   332,   335,   338,   343,   344,   345,
     346,   347,   348,   349,   350,   351,   352,   353,   356,   357,
     358,   359,   360,   361,   362,   363,   364,   365,   366,   369,
     370,   371,   372,   373,   374,   377,   378,   382,   385,   388,
     391,   394,   404,   409,   419,   422,   428,   431,   436,   439,
     444,   445,   446,   447,   448,   449,   450,   453,   454,   455,
     456,   457,   458
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "UNSIGNED", "SIGNED", "SHORT", "LONG",
  "INCLUDE", "MAIN", "BREAK", "CASE", "CONST", "CONTINUE", "DEFAULT", "IF",
  "ELSE", "ENUM", "RETURN", "STRUCT", "INT", "FLOAT", "DOUBLE", "BOOL",
  "TRUE", "FALSE", "CHAR", "DO", "PRINTF", "SCANF", "FOR", "GOTO",
  "SIZEOF", "SWITCH", "TYPEDEF", "UNION", "WHILE", "FREE", "POINTER",
  "SLICE", "SOME", "REDUCE", "FILTER", "MAP", "SORT", "CLOSE_BRACKET",
  "OPEN_BRACKET", "CLOSE_PAREN", "OPEN_PAREN", "BLOCK_CLOSE", "BLOCK_OPEN",
  "DOT", "INCREMENT", "DECREMENT", "ADD", "SUB", "MUL", "DIV",
  "BITWISE_AND", "BITWISE_OR", "BITWISE_NOT", "MOD", "LEFT_SHIFT",
  "RIGHT_SHIFT", "LT", "GT", "LE", "GE", "EQ", "NE", "BITWISE_XOR",
  "LOGICAL_AND", "LOGICAL_OR", "LOGICAL_NOT", "QUEST", "COLON",
  "SEMI_COLON", "ASSIGN", "ADD_ASSIGN", "SUB_ASSIGN", "MUL_ASSIGN",
  "DIV_ASSIGN", "MOD_ASSIGN", "LEFT_SHIFT_ASSIGN", "RIGHT_SHIFT_ASSIGN",
  "BITWISE_AND_ASSIGN", "BITWISE_OR_ASSIGN", "BITWISE_XOR_ASSIGN", "COMMA",
  "INTEGER", "DECIMAL", "STRING", "IDENTIFIER", "COMMENTS", "INVALID",
  "IFX", "UNARY", "$accept", "program", "stmt", "$@1", "$@2",
  "conditional", "caselist", "repetition", "var", "$@3", "$@4", "pointer",
  "funcid", "func", "$@5", "$@6", "typelist", "$@7", "$@8", "termlist",
  "opttypelist", "opttermlist", "commands", "varlist", "idlist", "optexpr",
  "stmts", "expr", "assign", "op", "rel", "cond", "term", "attr",
  "boolean", "vector", "type", "modifier", YY_NULLPTR
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
     325,   326,   327,   328,   329,   330,   331,   332,   333,   334,
     335,   336,   337,   338,   339,   340,   341,   342,   343,   344,
     345,   346,   347,   348,   349,   350
};
# endif

#define YYPACT_NINF (-147)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-49)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -147,    14,   197,  -147,  -147,  -147,  -147,  -147,   -75,  -147,
     -58,  -147,   -44,   -15,   -33,    71,   -30,  -147,  -147,   642,
    -147,  -147,    29,   -27,    30,    31,   180,    -7,    38,  -147,
    -147,  -147,  -147,  -147,  -147,  -147,    71,    71,  -147,  -147,
    -147,   -31,  -147,    39,  -147,  -147,  -147,    40,  -147,  -147,
      18,   283,   171,  -147,    10,    61,  -147,  -147,  -147,    71,
      48,    58,    33,  -147,    57,    80,    71,    42,   180,    71,
      26,    28,    34,    75,    71,    81,  -147,  -147,   -11,  -147,
      32,  -147,  -147,  -147,  -147,  -147,  -147,  -147,  -147,  -147,
    -147,  -147,  -147,  -147,  -147,  -147,  -147,  -147,  -147,  -147,
    -147,    71,    71,    71,  -147,  -147,  -147,  -147,  -147,  -147,
    -147,  -147,  -147,  -147,  -147,    71,   -46,    58,  -147,  -147,
    -147,  -147,  -147,  -147,    83,    35,  -147,  -147,    84,    55,
    -147,    86,    87,  -147,  -147,  -147,  -147,    88,  -147,    45,
      71,    45,   464,    51,    99,  -147,  -147,  -147,  -147,  -147,
    -147,   -46,  -147,  -147,  -147,   103,   642,    65,   105,   162,
      71,    71,    82,   106,   -39,   257,   642,  -147,  -147,   112,
    -147,  -147,    32,  -147,  -147,   113,    89,   -34,    17,   148,
      35,  -147,  -147,  -147,   -25,   123,    95,  -147,  -147,  -147,
    -147,  -147,  -147,  -147,  -147,  -147,  -147,    85,   125,    96,
     642,  -147,  -147,   100,    71,    -6,   180,   127,  -147,  -147,
    -147,   128,    32,   114,  -147,    98,  -147,  -147,   642,   116,
    -147,  -147,   553,   113,  -147,  -147,   286,  -147,  -147,   375,
     113,  -147
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
      69,     0,   132,     1,   127,   128,   129,   130,     0,    28,
       0,   131,     0,     0,     0,    67,     0,   116,   117,   132,
      29,    30,     0,     0,     0,     0,   132,     0,     0,    37,
      31,    32,    33,    34,    35,    36,     0,     0,   107,   108,
     109,   119,    68,     0,     3,     4,     6,     0,     5,     7,
       0,    74,   112,   110,     0,     0,    55,    52,    53,     0,
     126,   119,     0,    66,   125,     0,    67,     0,   132,     0,
       0,     0,     0,     0,     0,     0,    73,    60,   113,    69,
      50,     8,    88,    89,    90,    91,    93,    94,    95,    92,
      96,    97,   101,   103,   102,   104,    99,   100,    98,   105,
     106,     0,     0,     0,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,     0,     0,    21,    38,   120,
     122,   123,   124,   121,     0,     0,    51,    63,     0,     0,
      59,     0,     0,   126,   125,   119,    63,     0,    75,     0,
       0,     0,   132,    49,     0,    46,   112,    70,    71,    72,
      76,     0,   119,    23,   119,     0,   132,    65,     0,   132,
       0,    67,     0,     0,     0,   132,   132,   119,   115,     0,
     114,    10,     0,   111,    26,    25,     0,     0,   132,    12,
       0,    57,    56,    62,     0,     0,     0,    61,    17,    54,
      58,    18,   118,    11,    45,    24,    22,    47,     0,     0,
     132,    64,    21,     0,    67,     0,   132,     0,    43,    13,
      20,     0,     0,     0,    14,     0,    69,   119,   132,     0,
      69,    41,   132,    44,    19,    69,   132,   119,    39,   132,
      42,    40
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -147,  -147,   -19,  -147,  -147,  -147,  -147,  -147,  -146,  -147,
    -147,    43,   139,  -147,  -147,  -147,  -147,  -147,  -147,  -147,
    -147,  -147,  -147,    41,    -1,   -65,   -74,   -12,  -147,  -147,
    -147,  -147,   -68,   -72,  -147,  -125,   -24,  -147
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,    42,    43,   193,    44,   205,    45,    46,   154,
     176,   153,    47,    48,   155,   231,   197,   227,   217,   143,
     198,   144,    49,   159,   158,    62,     2,    50,   115,   101,
     102,   103,    51,    52,    53,    78,    54,    55
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      65,   129,    72,    63,   212,   142,   140,   213,   146,   151,
     164,   140,   145,   183,     3,    56,   -27,    57,     9,   183,
       4,     5,     6,     7,    75,    76,   139,   175,    11,   177,
     116,    58,    59,    70,   140,    71,   189,    20,    21,   141,
       9,   196,   214,    77,   131,   152,    29,   124,    30,    31,
      32,    33,    34,    35,    63,    17,    18,   132,    60,    20,
      21,    64,   137,   -48,    67,   116,   202,   168,    29,   170,
      30,    31,    32,    33,    34,    35,    66,    68,    69,     9,
     119,   120,   121,   122,    73,    74,   123,    80,    79,   147,
     148,   149,   223,    81,    17,    18,   186,   125,    20,    21,
     146,   117,   230,   150,   194,   -27,   127,    29,   126,    30,
      31,    32,    33,    34,    35,   128,   130,   133,    36,   134,
      38,    39,    40,    61,   136,   135,   157,   138,   169,   156,
     161,   160,   162,   163,   166,   184,   167,   179,   172,   211,
     146,   184,   222,    37,   219,   173,   226,   191,   185,    63,
     178,   229,   180,   181,   199,   188,   192,   187,   140,    38,
      39,    40,    61,   200,   195,     4,     5,     6,     7,   203,
     204,   207,   206,    11,   218,   210,   216,   165,    70,   201,
      71,   209,   215,     4,     5,     6,     7,   208,   220,   221,
     225,    11,    63,   118,   174,     0,    70,    -2,    71,   224,
       4,     5,     6,     7,     8,     9,    10,     0,    11,    12,
     182,    13,     0,    14,    15,    16,     0,     0,     0,     0,
      17,    18,     0,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,     0,    30,    31,    32,    33,    34,
      35,     0,     0,     0,    36,     0,    -9,   104,   105,   106,
     107,   108,   109,   110,   111,   112,   113,   114,     0,     0,
       4,     5,     6,     7,     0,     0,     0,     0,    11,    37,
       0,     0,     0,    70,     0,    71,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    38,    39,    40,    41,     4,
       5,     6,     7,     8,     9,    10,   -16,    11,    12,   -16,
      13,     0,    14,    15,    16,   190,     0,     0,     0,    17,
      18,     0,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,     0,    30,    31,    32,    33,    34,    35,
       0,     0,     0,    36,   -16,    -9,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,    92,    93,    94,    95,
      96,    97,    98,    99,   100,     0,     0,     0,    37,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    38,    39,    40,    41,     4,     5,
       6,     7,     8,     9,    10,   -15,    11,    12,   -15,    13,
       0,    14,    15,    16,     0,     0,     0,     0,    17,    18,
       0,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,     0,    30,    31,    32,    33,    34,    35,     0,
       0,     0,    36,   -15,    -9,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    37,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    38,    39,    40,    41,     4,     5,     6,
       7,     8,     9,    10,     0,    11,    12,     0,    13,     0,
      14,    15,    16,     0,     0,     0,     0,    17,    18,     0,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,     0,    30,    31,    32,    33,    34,    35,     0,     0,
       0,    36,   171,    -9,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    37,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    38,    39,    40,    41,     4,     5,     6,     7,
       8,     9,    10,     0,    11,    12,     0,    13,     0,    14,
      15,    16,     0,     0,     0,     0,    17,    18,     0,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
       0,    30,    31,    32,    33,    34,    35,     0,     0,     0,
      36,   228,    -9,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    37,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    38,    39,    40,    41,     4,     5,     6,     7,     8,
       9,    10,     0,    11,    12,     0,    13,     0,    14,    15,
      16,     0,     0,     0,     0,    17,    18,     0,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,     0,
      30,    31,    32,    33,    34,    35,     0,     0,     0,    36,
       0,    -9,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    37,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      38,    39,    40,    41
};

static const yytype_int16 yycheck[] =
{
      19,    66,    26,    15,    10,    79,    45,    13,    80,    55,
     135,    45,    80,   159,     0,    90,    47,    75,     8,   165,
       3,     4,     5,     6,    36,    37,    37,   152,    11,   154,
      55,    75,    47,    16,    45,    18,    75,    27,    28,    50,
       8,    75,    48,    74,    68,    91,    36,    59,    38,    39,
      40,    41,    42,    43,    66,    23,    24,    69,    91,    27,
      28,    91,    74,    46,    91,    55,    91,   139,    36,   141,
      38,    39,    40,    41,    42,    43,    47,    47,    47,     8,
      19,    20,    21,    22,    91,    47,    25,    47,    49,   101,
     102,   103,   217,    75,    23,    24,   161,    49,    27,    28,
     172,    91,   227,   115,   172,    47,    49,    36,    75,    38,
      39,    40,    41,    42,    43,    35,    74,    91,    47,    91,
      88,    89,    90,    91,    49,    91,    91,    46,   140,    46,
      75,    47,    46,    46,    46,   159,    91,   156,    87,   204,
     212,   165,   216,    72,   212,    46,   220,   166,   160,   161,
      47,   225,    87,    48,   178,    49,    44,    75,    45,    88,
      89,    90,    91,    15,    75,     3,     4,     5,     6,    46,
      75,    46,    87,    11,    46,    75,    49,   136,    16,   180,
      18,   200,   206,     3,     4,     5,     6,    91,    74,    91,
      74,    11,   204,    54,   151,    -1,    16,     0,    18,   218,
       3,     4,     5,     6,     7,     8,     9,    -1,    11,    12,
      48,    14,    -1,    16,    17,    18,    -1,    -1,    -1,    -1,
      23,    24,    -1,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    -1,    38,    39,    40,    41,    42,
      43,    -1,    -1,    -1,    47,    -1,    49,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    -1,    -1,
       3,     4,     5,     6,    -1,    -1,    -1,    -1,    11,    72,
      -1,    -1,    -1,    16,    -1,    18,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    88,    89,    90,    91,     3,
       4,     5,     6,     7,     8,     9,    10,    11,    12,    13,
      14,    -1,    16,    17,    18,    48,    -1,    -1,    -1,    23,
      24,    -1,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    -1,    38,    39,    40,    41,    42,    43,
      -1,    -1,    -1,    47,    48,    49,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    68,    69,    70,    71,    -1,    -1,    -1,    72,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    88,    89,    90,    91,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      -1,    16,    17,    18,    -1,    -1,    -1,    -1,    23,    24,
      -1,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    -1,    38,    39,    40,    41,    42,    43,    -1,
      -1,    -1,    47,    48,    49,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    72,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    88,    89,    90,    91,     3,     4,     5,
       6,     7,     8,     9,    -1,    11,    12,    -1,    14,    -1,
      16,    17,    18,    -1,    -1,    -1,    -1,    23,    24,    -1,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    -1,    38,    39,    40,    41,    42,    43,    -1,    -1,
      -1,    47,    48,    49,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    72,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    88,    89,    90,    91,     3,     4,     5,     6,
       7,     8,     9,    -1,    11,    12,    -1,    14,    -1,    16,
      17,    18,    -1,    -1,    -1,    -1,    23,    24,    -1,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      -1,    38,    39,    40,    41,    42,    43,    -1,    -1,    -1,
      47,    48,    49,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    72,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    88,    89,    90,    91,     3,     4,     5,     6,     7,
       8,     9,    -1,    11,    12,    -1,    14,    -1,    16,    17,
      18,    -1,    -1,    -1,    -1,    23,    24,    -1,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    -1,
      38,    39,    40,    41,    42,    43,    -1,    -1,    -1,    47,
      -1,    49,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    72,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      88,    89,    90,    91
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    97,   122,     0,     3,     4,     5,     6,     7,     8,
       9,    11,    12,    14,    16,    17,    18,    23,    24,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      38,    39,    40,    41,    42,    43,    47,    72,    88,    89,
      90,    91,    98,    99,   101,   103,   104,   108,   109,   118,
     123,   128,   129,   130,   132,   133,    90,    75,    75,    47,
      91,    91,   121,   123,    91,    98,    47,    91,    47,    47,
      16,    18,   132,    91,    47,   123,   123,    74,   131,    49,
      47,    75,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    68,    69,    70,
      71,   125,   126,   127,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,   124,    55,    91,   108,    19,
      20,    21,    22,    25,   123,    49,    75,    49,    35,   121,
      74,   132,   123,    91,    91,    91,    49,   123,    46,    37,
      45,    50,   122,   115,   117,   128,   129,   123,   123,   123,
     123,    55,    91,   107,   105,   110,    46,    91,   120,   119,
      47,    75,    46,    46,   131,   119,    46,    91,   129,   123,
     129,    48,    87,    46,   107,   131,   106,   131,    47,    98,
      87,    48,    48,   104,   132,   123,   121,    75,    49,    75,
      48,    98,    44,   100,   128,    75,    75,   112,   116,   132,
      15,   120,    91,    46,    75,   102,    87,    46,    91,    98,
      75,   121,    10,    13,    48,   132,    49,   114,    46,   128,
      74,    91,   122,   131,    98,    74,   122,   113,    48,   122,
     131,   111
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    96,    97,    98,    98,    98,    98,    98,    98,    99,
     100,    98,   101,   101,   101,   102,   102,   102,   103,   103,
     103,   105,   104,   106,   104,   107,   107,   108,   108,   108,
     108,   108,   108,   108,   108,   108,   108,   108,   110,   111,
     109,   113,   112,   114,   112,   115,   115,   116,   116,   117,
     117,   118,   118,   118,   118,   118,   118,   118,   118,   118,
     118,   118,   119,   119,   120,   120,   121,   121,   122,   122,
     123,   123,   123,   123,   123,   123,   123,   124,   124,   124,
     124,   124,   124,   124,   124,   124,   124,   124,   125,   125,
     125,   125,   125,   125,   125,   125,   125,   125,   125,   126,
     126,   126,   126,   126,   126,   127,   127,   128,   128,   128,
     128,   128,   128,   129,   129,   129,   130,   130,   131,   131,
     132,   132,   132,   132,   132,   132,   132,   133,   133,   133,
     133,   133,   133
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     1,     1,     1,     1,     1,     2,     0,
       0,     5,     5,     7,     7,     5,     4,     0,     5,     9,
       7,     0,     5,     0,     5,     2,     2,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     0,     0,
      10,     0,     6,     0,     4,     3,     1,     1,     0,     1,
       0,     3,     2,     2,     5,     2,     5,     5,     5,     3,
       2,     5,     2,     0,     3,     1,     1,     0,     2,     0,
       3,     3,     3,     2,     1,     3,     3,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     4,     1,     2,     4,     4,     1,     1,     4,     0,
       2,     2,     2,     2,     2,     2,     2,     1,     1,     1,
       1,     1,     0
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
#line 153 "translate.y"
               {
    fprintf(prod, "program -> stmts\n");
    executeProgram();
}
#line 1713 "translate.tab.c"
    break;

  case 3:
#line 159 "translate.y"
                  {
        fprintf(prod, "stmt -> conditional\n");
}
#line 1721 "translate.tab.c"
    break;

  case 4:
#line 162 "translate.y"
                 {
        fprintf(prod, "stmt -> repetition\n");
}
#line 1729 "translate.tab.c"
    break;

  case 5:
#line 165 "translate.y"
           {
        fprintf(prod, "stmt -> func\n");
}
#line 1737 "translate.tab.c"
    break;

  case 6:
#line 168 "translate.y"
          {
        fprintf(prod, "stmt -> var\n");
}
#line 1745 "translate.tab.c"
    break;

  case 7:
#line 171 "translate.y"
               {
        fprintf(prod, "stmt -> commands\n");
}
#line 1753 "translate.tab.c"
    break;

  case 8:
#line 174 "translate.y"
                      {
        fprintf(prod, "stmt -> expr ;\n");
}
#line 1761 "translate.tab.c"
    break;

  case 9:
#line 177 "translate.y"
      {blockOpen();}
#line 1767 "translate.tab.c"
    break;

  case 10:
#line 177 "translate.y"
                                                  {blockClose();}
#line 1773 "translate.tab.c"
    break;

  case 11:
#line 177 "translate.y"
                                                                  {
        fprintf(prod, "stmts -> { stmts }\n");
}
#line 1781 "translate.tab.c"
    break;

  case 12:
#line 181 "translate.y"
                                                           {
    fprintf(prod, "conditional: IF ( expr ) stmt\n");
}
#line 1789 "translate.tab.c"
    break;

  case 13:
#line 184 "translate.y"
                                                    {
    fprintf(prod, "conditional: IF ( expr ) stmt ELSE stmt\n");
}
#line 1797 "translate.tab.c"
    break;

  case 14:
#line 187 "translate.y"
                                                                         {
    fprintf(prod, "conditional: SWITCH ( expr ) { caselist }\n");
}
#line 1805 "translate.tab.c"
    break;

  case 15:
#line 192 "translate.y"
                                            { fprintf(prod, "caselist -> caselist CASE term : stmts\n"); }
#line 1811 "translate.tab.c"
    break;

  case 16:
#line 193 "translate.y"
                                            { fprintf(prod, "caselist -> caselist DEFAULT term : stmts\n"); }
#line 1817 "translate.tab.c"
    break;

  case 17:
#line 194 "translate.y"
                                            { fprintf(prod, "caselist -> EPS\n"); }
#line 1823 "translate.tab.c"
    break;

  case 18:
#line 197 "translate.y"
                                                   {
    fprintf(prod, "repetition -> WHILE ( expr ) stmt\n");
}
#line 1831 "translate.tab.c"
    break;

  case 19:
#line 200 "translate.y"
                                                                                    {
    fprintf(prod, "repetition -> FOR ( optexpr ; optexpr ; optexpr ) stmt\n");
}
#line 1839 "translate.tab.c"
    break;

  case 20:
#line 203 "translate.y"
                                                           {
    fprintf(prod, "repetition -> DO stmt WHILE ( expr ) ;\n");
}
#line 1847 "translate.tab.c"
    break;

  case 21:
#line 208 "translate.y"
                     {addId((yyvsp[0].string), (yyvsp[-1].typeValue));}
#line 1853 "translate.tab.c"
    break;

  case 22:
#line 208 "translate.y"
                                                         {
    fprintf(prod, "var -> type ID vector ;\n");
}
#line 1861 "translate.tab.c"
    break;

  case 23:
#line 211 "translate.y"
                       {addId((yyvsp[0].string), (yyvsp[-2].typeValue));}
#line 1867 "translate.tab.c"
    break;

  case 24:
#line 211 "translate.y"
                                                   {
    fprintf(prod, "var -> type * pointer ;\n");
}
#line 1875 "translate.tab.c"
    break;

  case 25:
#line 216 "translate.y"
                           {
        fprintf(prod, "pointer -> ID vector\n");
        (yyval.string) = (yyvsp[-1].string);
    }
#line 1884 "translate.tab.c"
    break;

  case 26:
#line 220 "translate.y"
                      {
        fprintf(prod, "pointer -> * pointer\n");
        (yyval.string) = (yyvsp[0].string);
    }
#line 1893 "translate.tab.c"
    break;

  case 27:
#line 226 "translate.y"
                    { (yyval.string) = (yyvsp[0].string); fprintf(prod, "funcid -> ID\n"); }
#line 1899 "translate.tab.c"
    break;

  case 28:
#line 227 "translate.y"
                    { (yyval.string) = (yyvsp[0].string); fprintf(prod, "funcid -> MAIN\n"); }
#line 1905 "translate.tab.c"
    break;

  case 29:
#line 228 "translate.y"
                    { (yyval.string) = (yyvsp[0].string); fprintf(prod, "funcid -> PRINTF\n"); }
#line 1911 "translate.tab.c"
    break;

  case 30:
#line 229 "translate.y"
                    { (yyval.string) = (yyvsp[0].string); fprintf(prod, "funcid -> SCANF\n"); }
#line 1917 "translate.tab.c"
    break;

  case 31:
#line 230 "translate.y"
                    { (yyval.string) = (yyvsp[0].string); fprintf(prod, "funcid -> SLICE\n"); }
#line 1923 "translate.tab.c"
    break;

  case 32:
#line 231 "translate.y"
                    { (yyval.string) = (yyvsp[0].string); fprintf(prod, "funcid -> SOME\n"); }
#line 1929 "translate.tab.c"
    break;

  case 33:
#line 232 "translate.y"
                    { (yyval.string) = (yyvsp[0].string); fprintf(prod, "funcid -> REDUCE\n"); }
#line 1935 "translate.tab.c"
    break;

  case 34:
#line 233 "translate.y"
                    { (yyval.string) = (yyvsp[0].string); fprintf(prod, "funcid -> FILTER\n"); }
#line 1941 "translate.tab.c"
    break;

  case 35:
#line 234 "translate.y"
                    { (yyval.string) = (yyvsp[0].string); fprintf(prod, "funcid -> MAP\n"); }
#line 1947 "translate.tab.c"
    break;

  case 36:
#line 235 "translate.y"
                    { (yyval.string) = (yyvsp[0].string); fprintf(prod, "funcid -> SORT\n"); }
#line 1953 "translate.tab.c"
    break;

  case 37:
#line 236 "translate.y"
                    { (yyval.string) = (yyvsp[0].string); fprintf(prod, "funcid -> FREE\n"); }
#line 1959 "translate.tab.c"
    break;

  case 38:
#line 239 "translate.y"
                  {addId((yyvsp[0].string), type_func); blockOpen();}
#line 1965 "translate.tab.c"
    break;

  case 39:
#line 239 "translate.y"
                                                                                                                       {blockClose();}
#line 1971 "translate.tab.c"
    break;

  case 40:
#line 239 "translate.y"
                                                                                                                                       {
    fprintf(prod, "func -> type funcid ( opttypelist ) { stmts }\n");
}
#line 1979 "translate.tab.c"
    break;

  case 41:
#line 244 "translate.y"
                                         {addId((yyvsp[0].string), (yyvsp[-1].typeValue));}
#line 1985 "translate.tab.c"
    break;

  case 42:
#line 244 "translate.y"
                                                                 {
    fprintf(prod, "typelist -> typelist , type ID\n");
}
#line 1993 "translate.tab.c"
    break;

  case 43:
#line 247 "translate.y"
                      {addId((yyvsp[0].string), (yyvsp[-1].typeValue));}
#line 1999 "translate.tab.c"
    break;

  case 44:
#line 247 "translate.y"
                                              {
        fprintf(prod, "typelist -> type ID vector\n");
    }
#line 2007 "translate.tab.c"
    break;

  case 45:
#line 252 "translate.y"
                              {
    fprintf(prod, "termlist -> termlist , term\n");
}
#line 2015 "translate.tab.c"
    break;

  case 46:
#line 255 "translate.y"
           {
        fprintf(prod, "termlist -> term\n");
    }
#line 2023 "translate.tab.c"
    break;

  case 47:
#line 260 "translate.y"
                        { fprintf(prod, "opttypelist -> typelist\n"); }
#line 2029 "translate.tab.c"
    break;

  case 48:
#line 261 "translate.y"
                        { fprintf(prod, "opttypelist -> EPS\n"); }
#line 2035 "translate.tab.c"
    break;

  case 49:
#line 264 "translate.y"
                        { fprintf(prod, "opttermlist -> termlist\n"); }
#line 2041 "translate.tab.c"
    break;

  case 50:
#line 265 "translate.y"
                        { fprintf(prod, "opttermlist -> EPS"); }
#line 2047 "translate.tab.c"
    break;

  case 51:
#line 269 "translate.y"
                              {
    fprintf(prod, "commands -> RETURN optexpr ;\n");
}
#line 2055 "translate.tab.c"
    break;

  case 52:
#line 272 "translate.y"
                       {
    fprintf(prod, "commands -> BREAK ;\n");
}
#line 2063 "translate.tab.c"
    break;

  case 53:
#line 275 "translate.y"
                          {
    fprintf(prod, "commands -> continue ;\n");
}
#line 2071 "translate.tab.c"
    break;

  case 54:
#line 278 "translate.y"
                                                {
    fprintf(prod, "commands -> TYPEDEF type ID vector ;\n");
}
#line 2079 "translate.tab.c"
    break;

  case 55:
#line 281 "translate.y"
                     {
    fprintf(prod, "commands -> INCLUDE STRING\n");
}
#line 2087 "translate.tab.c"
    break;

  case 56:
#line 284 "translate.y"
                                                       {
    fprintf(prod, "commands -> STRUCT ID ( varlist )\n");
}
#line 2095 "translate.tab.c"
    break;

  case 57:
#line 287 "translate.y"
                                                    {
    fprintf(prod, "commands -> ENUM ID ( idlist )\n");
}
#line 2103 "translate.tab.c"
    break;

  case 58:
#line 290 "translate.y"
                                                      {
    fprintf(prod, "commands -> UNION ID ( varlist )\n");
}
#line 2111 "translate.tab.c"
    break;

  case 59:
#line 293 "translate.y"
                            {
    fprintf(prod, "commands -> GOTO ID :\n");
}
#line 2119 "translate.tab.c"
    break;

  case 60:
#line 296 "translate.y"
                       {
    fprintf(prod, "commands -> IDENTIFIER :\n");
}
#line 2127 "translate.tab.c"
    break;

  case 61:
#line 299 "translate.y"
                                                    {
    fprintf(prod, "commands -> SIZEOF ( type ) ;\n");
}
#line 2135 "translate.tab.c"
    break;

  case 62:
#line 304 "translate.y"
                                { fprintf(prod, "varlist -> varlist var\n"); }
#line 2141 "translate.tab.c"
    break;

  case 63:
#line 305 "translate.y"
                                { fprintf(prod, "varlist -> EPS\n"); }
#line 2147 "translate.tab.c"
    break;

  case 64:
#line 308 "translate.y"
                                { fprintf(prod, "idlist -> ID , idlist\n"); }
#line 2153 "translate.tab.c"
    break;

  case 65:
#line 309 "translate.y"
                                { fprintf(prod, "idlist -> ID\n"); }
#line 2159 "translate.tab.c"
    break;

  case 66:
#line 312 "translate.y"
                                    { fprintf(prod, "optexpr -> expr\n"); }
#line 2165 "translate.tab.c"
    break;

  case 67:
#line 313 "translate.y"
                                    { fprintf(prod, "optexpr -> EPS\n"); }
#line 2171 "translate.tab.c"
    break;

  case 68:
#line 316 "translate.y"
                                    { fprintf(prod, "stmts -> stmts stmt\n"); }
#line 2177 "translate.tab.c"
    break;

  case 69:
#line 317 "translate.y"
                                    { fprintf(prod, "stmts -> EPS\n"); }
#line 2183 "translate.tab.c"
    break;

  case 70:
#line 320 "translate.y"
                   { 
    fprintf(prod, "expr -> expr op term\n"); 
}
#line 2191 "translate.tab.c"
    break;

  case 71:
#line 323 "translate.y"
                    { 
    fprintf(prod, "expr -> expr rel term\n"); 
}
#line 2199 "translate.tab.c"
    break;

  case 72:
#line 326 "translate.y"
                     { 
    fprintf(prod, "expr -> expr cond term\n"); 
}
#line 2207 "translate.tab.c"
    break;

  case 73:
#line 329 "translate.y"
                                   { 
    fprintf(prod, "expr -> ! expr\n"); 
}
#line 2215 "translate.tab.c"
    break;

  case 74:
#line 332 "translate.y"
           { 
    fprintf(prod, "expr -> term\n"); 
}
#line 2223 "translate.tab.c"
    break;

  case 75:
#line 335 "translate.y"
                                  { 
    fprintf(prod, "expr -> ( expr )\n"); 
}
#line 2231 "translate.tab.c"
    break;

  case 76:
#line 338 "translate.y"
                       { 
    fprintf(prod, "expr -> attr assign expr\n"); 
}
#line 2239 "translate.tab.c"
    break;

  case 77:
#line 343 "translate.y"
                                { fprintf(prod, "assign -> =\n"); }
#line 2245 "translate.tab.c"
    break;

  case 78:
#line 344 "translate.y"
                                { fprintf(prod, "assign -> +=\n"); }
#line 2251 "translate.tab.c"
    break;

  case 79:
#line 345 "translate.y"
                                { fprintf(prod, "assign -> -=\n"); }
#line 2257 "translate.tab.c"
    break;

  case 80:
#line 346 "translate.y"
                                { fprintf(prod, "assign -> *=\n"); }
#line 2263 "translate.tab.c"
    break;

  case 81:
#line 347 "translate.y"
                                { fprintf(prod, "assign -> /=\n"); }
#line 2269 "translate.tab.c"
    break;

  case 82:
#line 348 "translate.y"
                                { fprintf(prod, "assign -> %%=\n"); }
#line 2275 "translate.tab.c"
    break;

  case 83:
#line 349 "translate.y"
                                { fprintf(prod, "assign -> <<=\n"); }
#line 2281 "translate.tab.c"
    break;

  case 84:
#line 350 "translate.y"
                                { fprintf(prod, "assign -> >>=\n"); }
#line 2287 "translate.tab.c"
    break;

  case 85:
#line 351 "translate.y"
                                { fprintf(prod, "assign -> &=\n"); }
#line 2293 "translate.tab.c"
    break;

  case 86:
#line 352 "translate.y"
                                { fprintf(prod, "assign -> |=\n"); }
#line 2299 "translate.tab.c"
    break;

  case 87:
#line 353 "translate.y"
                                { fprintf(prod, "assign -> ^=\n"); }
#line 2305 "translate.tab.c"
    break;

  case 88:
#line 356 "translate.y"
                                { fprintf(prod, "op -> +\n"); }
#line 2311 "translate.tab.c"
    break;

  case 89:
#line 357 "translate.y"
                                { fprintf(prod, "op -> -\n"); }
#line 2317 "translate.tab.c"
    break;

  case 90:
#line 358 "translate.y"
                                { fprintf(prod, "op -> *\n"); }
#line 2323 "translate.tab.c"
    break;

  case 91:
#line 359 "translate.y"
                                { fprintf(prod, "op -> /\n"); }
#line 2329 "translate.tab.c"
    break;

  case 92:
#line 360 "translate.y"
                                { fprintf(prod, "op -> %%\n"); }
#line 2335 "translate.tab.c"
    break;

  case 93:
#line 361 "translate.y"
                                { fprintf(prod, "op -> &\n"); }
#line 2341 "translate.tab.c"
    break;

  case 94:
#line 362 "translate.y"
                                { fprintf(prod, "op -> |\n"); }
#line 2347 "translate.tab.c"
    break;

  case 95:
#line 363 "translate.y"
                                { fprintf(prod, "op -> ~\n"); }
#line 2353 "translate.tab.c"
    break;

  case 96:
#line 364 "translate.y"
                                { fprintf(prod, "op -> <<\n"); }
#line 2359 "translate.tab.c"
    break;

  case 97:
#line 365 "translate.y"
                                { fprintf(prod, "op -> >>\n"); }
#line 2365 "translate.tab.c"
    break;

  case 98:
#line 366 "translate.y"
                                { fprintf(prod, "op -> ^\n"); }
#line 2371 "translate.tab.c"
    break;

  case 99:
#line 369 "translate.y"
                                { fprintf(prod, "rel -> ==\n"); }
#line 2377 "translate.tab.c"
    break;

  case 100:
#line 370 "translate.y"
                                { fprintf(prod, "rel -> !=\n"); }
#line 2383 "translate.tab.c"
    break;

  case 101:
#line 371 "translate.y"
                                { fprintf(prod, "rel -> <\n"); }
#line 2389 "translate.tab.c"
    break;

  case 102:
#line 372 "translate.y"
                                { fprintf(prod, "rel -> <=\n"); }
#line 2395 "translate.tab.c"
    break;

  case 103:
#line 373 "translate.y"
                                { fprintf(prod, "rel -> >\n"); }
#line 2401 "translate.tab.c"
    break;

  case 104:
#line 374 "translate.y"
                                { fprintf(prod, "rel -> >=\n"); }
#line 2407 "translate.tab.c"
    break;

  case 105:
#line 377 "translate.y"
                                { fprintf(prod, "cond -> &&\n"); }
#line 2413 "translate.tab.c"
    break;

  case 106:
#line 378 "translate.y"
                                { fprintf(prod, "cond -> ||\n"); }
#line 2419 "translate.tab.c"
    break;

  case 107:
#line 382 "translate.y"
            {
    fprintf(prod, "term -> INTEGER\n");
}
#line 2427 "translate.tab.c"
    break;

  case 108:
#line 385 "translate.y"
              {
    fprintf(prod, "term -> DECIMAL\n");
}
#line 2435 "translate.tab.c"
    break;

  case 109:
#line 388 "translate.y"
             {
    fprintf(prod, "term -> STRING\n");
}
#line 2443 "translate.tab.c"
    break;

  case 110:
#line 391 "translate.y"
              {
    fprintf(prod, "term -> boolean\n");
}
#line 2451 "translate.tab.c"
    break;

  case 111:
#line 394 "translate.y"
                                                {
    fprintf(prod, "term -> funcid ( opttermlist )\n");
    if(!symbolTableFind(st, (yyvsp[-3].string))) {
        char msg[100];
        sprintf(msg, "Funcao nao declarada \"%s\"", (yyvsp[-3].string));
        yyerror(msg);
        onExit();
        exit(0);
    }
}
#line 2466 "translate.tab.c"
    break;

  case 112:
#line 404 "translate.y"
           {
    fprintf(prod, "term -> attr\n");
}
#line 2474 "translate.tab.c"
    break;

  case 113:
#line 409 "translate.y"
                        {
    fprintf(prod, "attr -> ID vector\n");
    if(!symbolTableFind(st, (yyvsp[-1].string))) {
        char msg[100];
        sprintf(msg, "Identificador nao declarado \"%s\"", (yyvsp[-1].string));
        yyerror(msg);
        onExit();
        exit(0);
    }
}
#line 2489 "translate.tab.c"
    break;

  case 114:
#line 419 "translate.y"
                                 {
    fprintf(prod, "attr -> ID vector . attr\n");
}
#line 2497 "translate.tab.c"
    break;

  case 115:
#line 422 "translate.y"
                                     {
    fprintf(prod, "attr -> ID vector POINTER attr\n");
}
#line 2505 "translate.tab.c"
    break;

  case 116:
#line 428 "translate.y"
         {
    fprintf(prod, "boolean -> TRUE\n");
}
#line 2513 "translate.tab.c"
    break;

  case 117:
#line 431 "translate.y"
            {
    fprintf(prod, "boolean -> FALSE\n");
}
#line 2521 "translate.tab.c"
    break;

  case 118:
#line 436 "translate.y"
                                               {
    fprintf(prod, "vector -> vector [ expr ]");
}
#line 2529 "translate.tab.c"
    break;

  case 119:
#line 439 "translate.y"
                {
        fprintf(prod, "vector -> EPS\n");
    }
#line 2537 "translate.tab.c"
    break;

  case 120:
#line 444 "translate.y"
                                { fprintf(prod, "type -> INT\n"); (yyval.typeValue) = type_int; }
#line 2543 "translate.tab.c"
    break;

  case 121:
#line 445 "translate.y"
                                { fprintf(prod, "type -> CHAR\n"); (yyval.typeValue) = type_char; }
#line 2549 "translate.tab.c"
    break;

  case 122:
#line 446 "translate.y"
                                { fprintf(prod, "type -> FLOAT\n"); (yyval.typeValue) = type_float; }
#line 2555 "translate.tab.c"
    break;

  case 123:
#line 447 "translate.y"
                                { fprintf(prod, "type -> DOUBLE\n"); (yyval.typeValue) = type_double; }
#line 2561 "translate.tab.c"
    break;

  case 124:
#line 448 "translate.y"
                                { fprintf(prod, "type -> BOOL\n"); (yyval.typeValue) = type_bool; }
#line 2567 "translate.tab.c"
    break;

  case 125:
#line 449 "translate.y"
                                { fprintf(prod, "type -> STRUCT ID\n"); (yyval.typeValue) = type_struct; }
#line 2573 "translate.tab.c"
    break;

  case 126:
#line 450 "translate.y"
                                { fprintf(prod, "type -> ENUM ID\n"); (yyval.typeValue) = type_enum; }
#line 2579 "translate.tab.c"
    break;

  case 127:
#line 453 "translate.y"
                                { fprintf(prod, "modifier -> UNSIGNED\n"); }
#line 2585 "translate.tab.c"
    break;

  case 128:
#line 454 "translate.y"
                                { fprintf(prod, "modifier -> SIGNED\n"); }
#line 2591 "translate.tab.c"
    break;

  case 129:
#line 455 "translate.y"
                                { fprintf(prod, "modifier -> SHORT\n"); }
#line 2597 "translate.tab.c"
    break;

  case 130:
#line 456 "translate.y"
                                { fprintf(prod, "modifier -> LONG\n"); }
#line 2603 "translate.tab.c"
    break;

  case 131:
#line 457 "translate.y"
                                { fprintf(prod, "modifier -> CONST\n"); }
#line 2609 "translate.tab.c"
    break;

  case 132:
#line 458 "translate.y"
                                { fprintf(prod, "modifier -> EPS\n"); }
#line 2615 "translate.tab.c"
    break;


#line 2619 "translate.tab.c"

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
#line 461 "translate.y"


void blockOpen() {
    symbolTableCreateBlock(st);
}

void blockClose() {
    symbolTableShow(st, stdout);
    symbolTableDeleteBlock(st);
}

void addId(char *id, Enumtypes type) {
    if(symbolTableFindInBlock(st, id)) {
        char msg[100];
        sprintf(msg, "Redeclaração do identificador \"%s\"", id);
        yyerror(msg);
        onExit();
        exit(0);
    }
    symbolTableInsert(st, symbolNew(id, type, 1));
}

void onExit() {
    fclose(prod);
    symbolTableDelete(st);
}

void onStart() {
    char sourceCode[1000000];
    size_t bytesRead = fread(sourceCode, sizeof(char), sizeof(sourceCode) - 1, stdin);
    sourceCode[bytesRead] = '\0';

    printSourceCodeWithLineNumbers(sourceCode);

    yyin = fmemopen(sourceCode, bytesRead, "r");
    
    prod = fopen("./build/producoes.output", "w");
    st = symbolTableNew();
    symbolTableCreateBlock(st);

    symbolTableInsert(st, symbolNew("parrot", type_func, 1));
    // symbolTableInsert(st, symbolNew("plunder", type_func, 1));
    // symbolTableInsert(st, symbolNew("swab", type_func, 1));
    // symbolTableInsert(st, symbolNew("gully", type_func, 1));
    // symbolTableInsert(st, symbolNew("hoard", type_func, 1));
    // symbolTableInsert(st, symbolNew("booty", type_func, 1));
    // symbolTableInsert(st, symbolNew("net", type_func, 1));
    // symbolTableInsert(st, symbolNew("chart", type_func, 1));
    // symbolTableInsert(st, symbolNew("plunderhaul", type_func, 1));
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
