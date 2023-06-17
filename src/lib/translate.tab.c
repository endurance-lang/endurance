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
#include "../symbolTable.h"
#include "../print-source-code.h"

extern int yylex();
extern void yyerror(const char*);
extern FILE* yyin; // Declarar a variável global de entrada do analisador léxico
extern int line;

void onExit();
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
    IFX = 348,
    UNARY = 349
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

#line 249 "translate.tab.c"

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
#define YYLAST   665

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  95
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  34
/* YYNRULES -- Number of rules.  */
#define YYNRULES  129
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  227

#define YYUNDEFTOK  2
#define YYMAXUTOK   349


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
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   151,   151,   157,   160,   163,   166,   169,   172,   175,
     180,   180,   180,   184,   187,   190,   195,   196,   197,   200,
     203,   206,   211,   211,   214,   219,   222,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   240,   244,
     249,   252,   257,   260,   265,   266,   269,   270,   274,   277,
     280,   283,   286,   289,   292,   295,   298,   301,   304,   309,
     310,   313,   314,   317,   318,   321,   322,   325,   328,   331,
     334,   337,   340,   343,   348,   349,   350,   351,   352,   353,
     354,   355,   356,   357,   358,   361,   362,   363,   364,   365,
     366,   367,   368,   369,   370,   371,   374,   375,   376,   377,
     378,   379,   382,   383,   387,   390,   393,   396,   399,   402,
     407,   410,   413,   419,   422,   427,   430,   435,   436,   437,
     438,   439,   440,   441,   444,   445,   446,   447,   448,   449
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
  "INTEGER", "DECIMAL", "STRING", "IDENTIFIER", "COMMENTS", "IFX", "UNARY",
  "$accept", "program", "stmt", "block", "$@1", "$@2", "conditional",
  "caselist", "repetition", "var", "$@3", "pointer", "funcid", "func",
  "typelist", "termlist", "opttypelist", "opttermlist", "commands",
  "varlist", "idlist", "optexpr", "stmts", "expr", "assign", "op", "rel",
  "cond", "term", "attr", "boolean", "vector", "type", "modifier", YY_NULLPTR
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
     345,   346,   347,   348,   349
};
# endif

#define YYPACT_NINF (-141)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-46)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -141,    21,   181,  -141,  -141,  -141,  -141,  -141,   -57,  -141,
     -41,  -141,   -38,   -11,   -51,    33,   -27,  -141,  -141,   537,
    -141,  -141,    23,    -5,    31,    32,    12,    -3,    38,  -141,
    -141,  -141,  -141,  -141,  -141,  -141,    33,    33,  -141,  -141,
    -141,   -39,  -141,  -141,    10,  -141,  -141,  -141,    42,  -141,
    -141,    -7,   178,   179,  -141,    11,    62,  -141,  -141,  -141,
      33,    44,    48,    22,  -141,    47,    64,    33,    27,    12,
      33,    15,    16,    17,    60,    33,    65,  -141,  -141,   -23,
    -141,   574,  -141,  -141,  -141,  -141,  -141,  -141,  -141,  -141,
    -141,  -141,  -141,  -141,  -141,  -141,  -141,  -141,  -141,  -141,
    -141,  -141,    33,    33,    33,  -141,  -141,  -141,  -141,  -141,
    -141,  -141,  -141,  -141,  -141,  -141,    33,   -46,    48,    63,
    -141,  -141,  -141,  -141,  -141,    70,    26,  -141,  -141,    71,
      51,  -141,    73,    82,  -141,  -141,  -141,  -141,    84,  -141,
      41,    33,    41,   448,    46,    88,  -141,  -141,  -141,  -141,
    -141,  -141,   -46,  -141,    61,  -141,   157,   537,    50,    91,
     109,    33,    33,    67,    98,   -32,   148,   537,  -141,  -141,
     111,  -141,  -141,   574,  -141,  -141,   113,  -141,   -13,    69,
     119,    76,   154,    26,  -141,  -141,  -141,   -45,   124,    96,
    -141,  -141,  -141,  -141,  -141,  -141,  -141,  -141,  -141,    12,
      97,  -141,   537,  -141,  -141,   101,    33,    -6,    86,  -141,
    -141,   113,  -141,  -141,   132,   574,   105,  -141,  -141,   537,
     106,  -141,   113,  -141,  -141,   270,   359
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
      66,     0,   129,     1,   124,   125,   126,   127,     0,    28,
       0,   128,     0,     0,     0,    64,     0,   113,   114,   129,
      29,    30,     0,     0,     0,     0,   129,     0,     0,    37,
      31,    32,    33,    34,    35,    36,     0,     0,   104,   105,
     106,   116,    65,     9,     0,     3,     4,     6,     0,     5,
       7,     0,    71,   109,   107,     0,     0,    52,    49,    50,
       0,   123,   116,     0,    63,   122,     0,    64,     0,   129,
       0,     0,     0,     0,     0,     0,     0,    70,    57,   110,
      66,    47,     8,    85,    86,    87,    88,    90,    91,    92,
      89,    93,    94,    98,   100,    99,   101,    96,    97,    95,
     102,   103,     0,     0,     0,    74,    75,    76,    77,    78,
      79,    80,    81,    82,    83,    84,     0,     0,    22,     0,
     117,   119,   120,   121,   118,     0,     0,    48,    60,     0,
       0,    56,     0,     0,   123,   122,   116,    60,     0,    72,
       0,     0,     0,   129,    46,     0,    43,   109,    67,    68,
      69,    73,     0,   116,     0,   116,   129,   129,    62,     0,
     129,     0,    64,     0,     0,     0,   129,   129,   116,   112,
       0,   111,    11,     0,   108,    26,    25,    24,     0,    44,
       0,     0,    13,     0,    54,    53,    59,     0,     0,     0,
      58,    18,    51,    55,    19,   115,    12,    42,    23,   129,
      10,   116,   129,    61,    22,     0,    64,     0,     0,    39,
      38,    41,    14,    21,     0,     0,     0,    15,   116,   129,
       0,    66,    40,    20,    66,   129,   129
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -141,  -141,   -19,   -18,  -141,  -141,  -141,  -141,  -141,  -140,
    -141,    39,   146,  -141,  -141,  -141,  -141,  -141,  -141,    81,
      19,   -62,   -78,   -12,  -141,  -141,  -141,  -141,   -70,   -75,
    -141,  -124,   -25,  -141
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,    42,    43,    44,   196,    45,   207,    46,    47,
     155,   154,    48,    49,   179,   144,   180,   145,    50,   160,
     159,    63,     2,    51,   116,   102,   103,   104,    52,    53,
      54,    79,    55,    56
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      66,    73,   143,    64,   215,   130,   147,   216,   -27,   152,
     117,   146,   165,   141,   140,     4,     5,     6,     7,     9,
     186,     3,   141,    11,    76,    77,   186,   142,    71,   176,
      72,   178,   141,    57,    58,    78,    60,    59,    20,    21,
      61,     9,   217,   192,   132,   153,   204,    29,   125,    30,
      31,    32,    33,    34,    35,    64,    17,    18,   133,    80,
      20,    21,   198,   138,    65,   169,   117,   171,    82,    29,
      67,    30,    31,    32,    33,    34,    35,   211,    69,    70,
      36,   120,   121,   122,   123,    75,    68,   124,    74,    81,
     148,   149,   150,   126,   222,   -27,   128,   127,   147,   129,
     189,   131,   118,   197,   151,    37,   134,   135,   136,   137,
     156,   139,     4,     5,     6,     7,   157,   158,   161,   163,
      11,    38,    39,    40,    62,    71,   162,    72,   164,   170,
     167,   181,   168,   173,   174,   187,   177,   183,   182,   184,
     147,   187,   190,   225,   214,   220,   226,   191,   194,   188,
      64,     4,     5,     6,     7,   195,   199,   185,   141,    11,
       4,     5,     6,     7,    71,   200,    72,   201,    11,   202,
     205,   206,   209,    71,   208,    72,   213,   218,   219,   221,
     224,    -2,   210,   212,     4,     5,     6,     7,     8,     9,
      10,   175,    11,    12,    64,    13,   193,    14,    15,    16,
     223,   119,   203,   -45,    17,    18,     0,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,   166,    30,
      31,    32,    33,    34,    35,     0,     0,     0,    36,     0,
     -10,    83,    84,    85,    86,    87,    88,    89,    90,    91,
      92,    93,    94,    95,    96,    97,    98,    99,   100,   101,
       0,     0,     0,    37,     0,   105,   106,   107,   108,   109,
     110,   111,   112,   113,   114,   115,     0,     0,     0,    38,
      39,    40,    41,     4,     5,     6,     7,     8,     9,    10,
     -17,    11,    12,   -17,    13,     0,    14,    15,    16,     0,
       0,     0,     0,    17,    18,     0,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,     0,    30,    31,
      32,    33,    34,    35,     0,     0,     0,    36,   -17,   -10,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    37,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    38,    39,
      40,    41,     4,     5,     6,     7,     8,     9,    10,   -16,
      11,    12,   -16,    13,     0,    14,    15,    16,     0,     0,
       0,     0,    17,    18,     0,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,     0,    30,    31,    32,
      33,    34,    35,     0,     0,     0,    36,   -16,   -10,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    37,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    38,    39,    40,
      41,     4,     5,     6,     7,     8,     9,    10,     0,    11,
      12,     0,    13,     0,    14,    15,    16,     0,     0,     0,
       0,    17,    18,     0,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,     0,    30,    31,    32,    33,
      34,    35,     0,     0,     0,    36,   172,   -10,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      37,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    38,    39,    40,    41,
       4,     5,     6,     7,     8,     9,    10,     0,    11,    12,
       0,    13,     0,    14,    15,    16,     0,     0,     0,     0,
      17,    18,     0,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,     0,    30,    31,    32,    33,    34,
      35,     0,     9,     0,    36,     0,   -10,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    17,    18,     0,
       0,    20,    21,     0,     0,     0,     0,     0,     0,    37,
      29,     0,    30,    31,    32,    33,    34,    35,     0,     0,
       0,     0,     0,     0,     0,    38,    39,    40,    41,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    38,    39,    40,    62
};

static const yytype_int16 yycheck[] =
{
      19,    26,    80,    15,    10,    67,    81,    13,    47,    55,
      55,    81,   136,    45,    37,     3,     4,     5,     6,     8,
     160,     0,    45,    11,    36,    37,   166,    50,    16,   153,
      18,   155,    45,    90,    75,    74,    47,    75,    27,    28,
      91,     8,    48,    75,    69,    91,    91,    36,    60,    38,
      39,    40,    41,    42,    43,    67,    23,    24,    70,    49,
      27,    28,    75,    75,    91,   140,    55,   142,    75,    36,
      47,    38,    39,    40,    41,    42,    43,   201,    47,    47,
      47,    19,    20,    21,    22,    47,    91,    25,    91,    47,
     102,   103,   104,    49,   218,    47,    49,    75,   173,    35,
     162,    74,    91,   173,   116,    72,    91,    91,    91,    49,
      47,    46,     3,     4,     5,     6,    46,    91,    47,    46,
      11,    88,    89,    90,    91,    16,    75,    18,    46,   141,
      46,   156,    91,    87,    46,   160,    75,    87,   157,    48,
     215,   166,    75,   221,   206,   215,   224,    49,   167,   161,
     162,     3,     4,     5,     6,    44,    87,    48,    45,    11,
       3,     4,     5,     6,    16,    46,    18,    91,    11,    15,
      46,    75,    75,    16,   199,    18,    75,    91,    46,    74,
      74,     0,   200,   202,     3,     4,     5,     6,     7,     8,
       9,   152,    11,    12,   206,    14,    48,    16,    17,    18,
     219,    55,   183,    46,    23,    24,    -1,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,   137,    38,
      39,    40,    41,    42,    43,    -1,    -1,    -1,    47,    -1,
      49,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,    69,    70,    71,
      -1,    -1,    -1,    72,    -1,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    -1,    -1,    -1,    88,
      89,    90,    91,     3,     4,     5,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    -1,    16,    17,    18,    -1,
      -1,    -1,    -1,    23,    24,    -1,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    -1,    38,    39,
      40,    41,    42,    43,    -1,    -1,    -1,    47,    48,    49,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    72,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    88,    89,
      90,    91,     3,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    -1,    16,    17,    18,    -1,    -1,
      -1,    -1,    23,    24,    -1,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    -1,    38,    39,    40,
      41,    42,    43,    -1,    -1,    -1,    47,    48,    49,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    72,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    88,    89,    90,
      91,     3,     4,     5,     6,     7,     8,     9,    -1,    11,
      12,    -1,    14,    -1,    16,    17,    18,    -1,    -1,    -1,
      -1,    23,    24,    -1,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    -1,    38,    39,    40,    41,
      42,    43,    -1,    -1,    -1,    47,    48,    49,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      72,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    88,    89,    90,    91,
       3,     4,     5,     6,     7,     8,     9,    -1,    11,    12,
      -1,    14,    -1,    16,    17,    18,    -1,    -1,    -1,    -1,
      23,    24,    -1,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    -1,    38,    39,    40,    41,    42,
      43,    -1,     8,    -1,    47,    -1,    49,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    23,    24,    -1,
      -1,    27,    28,    -1,    -1,    -1,    -1,    -1,    -1,    72,
      36,    -1,    38,    39,    40,    41,    42,    43,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    88,    89,    90,    91,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    88,    89,    90,    91
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    96,   117,     0,     3,     4,     5,     6,     7,     8,
       9,    11,    12,    14,    16,    17,    18,    23,    24,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      38,    39,    40,    41,    42,    43,    47,    72,    88,    89,
      90,    91,    97,    98,    99,   101,   103,   104,   107,   108,
     113,   118,   123,   124,   125,   127,   128,    90,    75,    75,
      47,    91,    91,   116,   118,    91,    97,    47,    91,    47,
      47,    16,    18,   127,    91,    47,   118,   118,    74,   126,
      49,    47,    75,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    68,    69,
      70,    71,   120,   121,   122,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,   119,    55,    91,   107,
      19,    20,    21,    22,    25,   118,    49,    75,    49,    35,
     116,    74,   127,   118,    91,    91,    91,    49,   118,    46,
      37,    45,    50,   117,   110,   112,   123,   124,   118,   118,
     118,   118,    55,    91,   106,   105,    47,    46,    91,   115,
     114,    47,    75,    46,    46,   126,   114,    46,    91,   124,
     118,   124,    48,    87,    46,   106,   126,    75,   126,   109,
     111,   127,    97,    87,    48,    48,   104,   127,   118,   116,
      75,    49,    75,    48,    97,    44,   100,   123,    75,    87,
      46,    91,    15,   115,    91,    46,    75,   102,   127,    75,
      98,   126,    97,    75,   116,    10,    13,    48,    91,    46,
     123,    74,   126,    97,    74,   117,   117
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    95,    96,    97,    97,    97,    97,    97,    97,    97,
      99,   100,    98,   101,   101,   101,   102,   102,   102,   103,
     103,   103,   105,   104,   104,   106,   106,   107,   107,   107,
     107,   107,   107,   107,   107,   107,   107,   107,   108,   108,
     109,   109,   110,   110,   111,   111,   112,   112,   113,   113,
     113,   113,   113,   113,   113,   113,   113,   113,   113,   114,
     114,   115,   115,   116,   116,   117,   117,   118,   118,   118,
     118,   118,   118,   118,   119,   119,   119,   119,   119,   119,
     119,   119,   119,   119,   119,   120,   120,   120,   120,   120,
     120,   120,   120,   120,   120,   120,   121,   121,   121,   121,
     121,   121,   122,   122,   123,   123,   123,   123,   123,   123,
     124,   124,   124,   125,   125,   126,   126,   127,   127,   127,
     127,   127,   127,   127,   128,   128,   128,   128,   128,   128
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     1,     1,     1,     1,     1,     2,     1,
       0,     0,     5,     5,     7,     7,     5,     4,     0,     5,
       9,     7,     0,     5,     4,     2,     2,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     6,     6,
       5,     3,     3,     1,     1,     0,     1,     0,     3,     2,
       2,     5,     2,     5,     5,     5,     3,     2,     5,     2,
       0,     3,     1,     1,     0,     2,     0,     3,     3,     3,
       2,     1,     3,     3,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     4,     1,
       2,     4,     4,     1,     1,     4,     0,     2,     2,     2,
       2,     2,     2,     2,     1,     1,     1,     1,     1,     0
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
#line 151 "translate.y"
               {
    fprintf(prod, "program -> stmts\n");
    executeProgram();
}
#line 1690 "translate.tab.c"
    break;

  case 3:
#line 157 "translate.y"
                  {
        fprintf(prod, "stmt -> conditional\n");
}
#line 1698 "translate.tab.c"
    break;

  case 4:
#line 160 "translate.y"
                 {
        fprintf(prod, "stmt -> repetition\n");
}
#line 1706 "translate.tab.c"
    break;

  case 5:
#line 163 "translate.y"
           {
        fprintf(prod, "stmt -> func\n");
}
#line 1714 "translate.tab.c"
    break;

  case 6:
#line 166 "translate.y"
          {
        fprintf(prod, "stmt -> var\n");
}
#line 1722 "translate.tab.c"
    break;

  case 7:
#line 169 "translate.y"
               {
        fprintf(prod, "stmt -> commands\n");
}
#line 1730 "translate.tab.c"
    break;

  case 8:
#line 172 "translate.y"
                      {
        fprintf(prod, "stmt -> expr ;\n");
}
#line 1738 "translate.tab.c"
    break;

  case 9:
#line 175 "translate.y"
            {
        fprintf(prod, "stmt -> block\n");
    }
#line 1746 "translate.tab.c"
    break;

  case 10:
#line 180 "translate.y"
       {blockOpen();}
#line 1752 "translate.tab.c"
    break;

  case 11:
#line 180 "translate.y"
                                                   {blockClose();}
#line 1758 "translate.tab.c"
    break;

  case 12:
#line 180 "translate.y"
                                                                   {
        fprintf(prod, "block -> { stmts }\n");
}
#line 1766 "translate.tab.c"
    break;

  case 13:
#line 184 "translate.y"
                                                           {
    fprintf(prod, "conditional: IF ( expr ) stmt\n");
}
#line 1774 "translate.tab.c"
    break;

  case 14:
#line 187 "translate.y"
                                                    {
    fprintf(prod, "conditional: IF ( expr ) stmt ELSE stmt\n");
}
#line 1782 "translate.tab.c"
    break;

  case 15:
#line 190 "translate.y"
                                                                         {
    fprintf(prod, "conditional: SWITCH ( expr ) { caselist }\n");
}
#line 1790 "translate.tab.c"
    break;

  case 16:
#line 195 "translate.y"
                                            { fprintf(prod, "caselist -> caselist CASE term : stmts\n"); }
#line 1796 "translate.tab.c"
    break;

  case 17:
#line 196 "translate.y"
                                            { fprintf(prod, "caselist -> caselist DEFAULT term : stmts\n"); }
#line 1802 "translate.tab.c"
    break;

  case 18:
#line 197 "translate.y"
                                            { fprintf(prod, "caselist -> EPS\n"); }
#line 1808 "translate.tab.c"
    break;

  case 19:
#line 200 "translate.y"
                                                   {
    fprintf(prod, "repetition -> WHILE ( expr ) stmt\n");
}
#line 1816 "translate.tab.c"
    break;

  case 20:
#line 203 "translate.y"
                                                                                    {
    fprintf(prod, "repetition -> FOR ( optexpr ; optexpr ; optexpr ) stmt\n");
}
#line 1824 "translate.tab.c"
    break;

  case 21:
#line 206 "translate.y"
                                                           {
    fprintf(prod, "repetition -> DO stmt WHILE ( expr ) ;\n");
}
#line 1832 "translate.tab.c"
    break;

  case 22:
#line 211 "translate.y"
                     {addId((yyvsp[0].string), (yyvsp[-1].typeValue));}
#line 1838 "translate.tab.c"
    break;

  case 23:
#line 211 "translate.y"
                                                         {
    fprintf(prod, "var -> type ID vector ;\n");
}
#line 1846 "translate.tab.c"
    break;

  case 24:
#line 214 "translate.y"
                                  {
    fprintf(prod, "var -> type * pointer ;\n");
}
#line 1854 "translate.tab.c"
    break;

  case 25:
#line 219 "translate.y"
                           {
        fprintf(prod, "pointer -> ID vector\n");
    }
#line 1862 "translate.tab.c"
    break;

  case 26:
#line 222 "translate.y"
                      {
        fprintf(prod, "pointer -> * pointer\n");
    }
#line 1870 "translate.tab.c"
    break;

  case 27:
#line 227 "translate.y"
                    { fprintf(prod, "funcid -> ID\n"); }
#line 1876 "translate.tab.c"
    break;

  case 28:
#line 228 "translate.y"
                    { fprintf(prod, "funcid -> MAIN\n"); }
#line 1882 "translate.tab.c"
    break;

  case 29:
#line 229 "translate.y"
                    { fprintf(prod, "funcid -> PRINTF\n"); }
#line 1888 "translate.tab.c"
    break;

  case 30:
#line 230 "translate.y"
                    { fprintf(prod, "funcid -> SCANF\n"); }
#line 1894 "translate.tab.c"
    break;

  case 31:
#line 231 "translate.y"
                    { fprintf(prod, "funcid -> SLICE\n"); }
#line 1900 "translate.tab.c"
    break;

  case 32:
#line 232 "translate.y"
                    { fprintf(prod, "funcid -> SOME\n"); }
#line 1906 "translate.tab.c"
    break;

  case 33:
#line 233 "translate.y"
                    { fprintf(prod, "funcid -> REDUCE\n"); }
#line 1912 "translate.tab.c"
    break;

  case 34:
#line 234 "translate.y"
                    { fprintf(prod, "funcid -> FILTER\n"); }
#line 1918 "translate.tab.c"
    break;

  case 35:
#line 235 "translate.y"
                    { fprintf(prod, "funcid -> MAP\n"); }
#line 1924 "translate.tab.c"
    break;

  case 36:
#line 236 "translate.y"
                    { fprintf(prod, "funcid -> SORT\n"); }
#line 1930 "translate.tab.c"
    break;

  case 37:
#line 237 "translate.y"
                    { fprintf(prod, "funcid -> FREE\n"); }
#line 1936 "translate.tab.c"
    break;

  case 38:
#line 240 "translate.y"
                                                           {
    fprintf(prod, "func -> type funcid ( opttypelist ) { stmts }\n");
    
}
#line 1945 "translate.tab.c"
    break;

  case 39:
#line 244 "translate.y"
                                                                {
    fprintf(prod, "func -> type funcid ( opttypelist ) ;\n");
}
#line 1953 "translate.tab.c"
    break;

  case 40:
#line 249 "translate.y"
                                                {
    fprintf(prod, "typelist -> typelist , type ID\n");
}
#line 1961 "translate.tab.c"
    break;

  case 41:
#line 252 "translate.y"
                             {
        fprintf(prod, "typelist -> type ID vector\n");
    }
#line 1969 "translate.tab.c"
    break;

  case 42:
#line 257 "translate.y"
                              {
    fprintf(prod, "termlist -> termlist , term\n");
}
#line 1977 "translate.tab.c"
    break;

  case 43:
#line 260 "translate.y"
           {
        fprintf(prod, "termlist -> term\n");
    }
#line 1985 "translate.tab.c"
    break;

  case 44:
#line 265 "translate.y"
                        { fprintf(prod, "opttypelist -> typelist\n"); }
#line 1991 "translate.tab.c"
    break;

  case 45:
#line 266 "translate.y"
                        { fprintf(prod, "opttypelist -> EPS\n"); }
#line 1997 "translate.tab.c"
    break;

  case 46:
#line 269 "translate.y"
                        { fprintf(prod, "opttermlist -> termlist\n"); }
#line 2003 "translate.tab.c"
    break;

  case 47:
#line 270 "translate.y"
                        { fprintf(prod, "opttermlist -> EPS"); }
#line 2009 "translate.tab.c"
    break;

  case 48:
#line 274 "translate.y"
                              {
    fprintf(prod, "commands -> RETURN optexpr ;\n");
}
#line 2017 "translate.tab.c"
    break;

  case 49:
#line 277 "translate.y"
                       {
    fprintf(prod, "commands -> BREAK ;\n");
}
#line 2025 "translate.tab.c"
    break;

  case 50:
#line 280 "translate.y"
                          {
    fprintf(prod, "commands -> continue ;\n");
}
#line 2033 "translate.tab.c"
    break;

  case 51:
#line 283 "translate.y"
                                                {
    fprintf(prod, "commands -> TYPEDEF type ID vector ;\n");
}
#line 2041 "translate.tab.c"
    break;

  case 52:
#line 286 "translate.y"
                     {
    fprintf(prod, "commands -> INCLUDE STRING\n");
}
#line 2049 "translate.tab.c"
    break;

  case 53:
#line 289 "translate.y"
                                                       {
    fprintf(prod, "commands -> STRUCT ID ( varlist )\n");
}
#line 2057 "translate.tab.c"
    break;

  case 54:
#line 292 "translate.y"
                                                    {
    fprintf(prod, "commands -> ENUM ID ( idlist )\n");
}
#line 2065 "translate.tab.c"
    break;

  case 55:
#line 295 "translate.y"
                                                      {
    fprintf(prod, "commands -> UNION ID ( varlist )\n");
}
#line 2073 "translate.tab.c"
    break;

  case 56:
#line 298 "translate.y"
                            {
    fprintf(prod, "commands -> GOTO ID :\n");
}
#line 2081 "translate.tab.c"
    break;

  case 57:
#line 301 "translate.y"
                       {
    fprintf(prod, "commands -> IDENTIFIER :\n");
}
#line 2089 "translate.tab.c"
    break;

  case 58:
#line 304 "translate.y"
                                                    {
    fprintf(prod, "commands -> SIZEOF ( type ) ;\n");
}
#line 2097 "translate.tab.c"
    break;

  case 59:
#line 309 "translate.y"
                                { fprintf(prod, "varlist -> varlist var\n"); }
#line 2103 "translate.tab.c"
    break;

  case 60:
#line 310 "translate.y"
                                { fprintf(prod, "varlist -> EPS\n"); }
#line 2109 "translate.tab.c"
    break;

  case 61:
#line 313 "translate.y"
                                { fprintf(prod, "idlist -> ID , idlist\n"); }
#line 2115 "translate.tab.c"
    break;

  case 62:
#line 314 "translate.y"
                                { fprintf(prod, "idlist -> ID\n"); }
#line 2121 "translate.tab.c"
    break;

  case 63:
#line 317 "translate.y"
                                    { fprintf(prod, "optexpr -> expr\n"); }
#line 2127 "translate.tab.c"
    break;

  case 64:
#line 318 "translate.y"
                                    { fprintf(prod, "optexpr -> EPS\n"); }
#line 2133 "translate.tab.c"
    break;

  case 65:
#line 321 "translate.y"
                                    { fprintf(prod, "stmts -> stmts stmt\n"); }
#line 2139 "translate.tab.c"
    break;

  case 66:
#line 322 "translate.y"
                                    { fprintf(prod, "stmts -> EPS\n"); }
#line 2145 "translate.tab.c"
    break;

  case 67:
#line 325 "translate.y"
                   { 
    fprintf(prod, "expr -> expr op term\n"); 
}
#line 2153 "translate.tab.c"
    break;

  case 68:
#line 328 "translate.y"
                    { 
    fprintf(prod, "expr -> expr rel term\n"); 
}
#line 2161 "translate.tab.c"
    break;

  case 69:
#line 331 "translate.y"
                     { 
    fprintf(prod, "expr -> expr cond term\n"); 
}
#line 2169 "translate.tab.c"
    break;

  case 70:
#line 334 "translate.y"
                                   { 
    fprintf(prod, "expr -> ! expr\n"); 
}
#line 2177 "translate.tab.c"
    break;

  case 71:
#line 337 "translate.y"
           { 
    fprintf(prod, "expr -> term\n"); 
}
#line 2185 "translate.tab.c"
    break;

  case 72:
#line 340 "translate.y"
                                  { 
    fprintf(prod, "expr -> ( expr )\n"); 
}
#line 2193 "translate.tab.c"
    break;

  case 73:
#line 343 "translate.y"
                       { 
    fprintf(prod, "expr -> attr assign expr\n"); 
}
#line 2201 "translate.tab.c"
    break;

  case 74:
#line 348 "translate.y"
                                { fprintf(prod, "assign -> =\n"); }
#line 2207 "translate.tab.c"
    break;

  case 75:
#line 349 "translate.y"
                                { fprintf(prod, "assign -> +=\n"); }
#line 2213 "translate.tab.c"
    break;

  case 76:
#line 350 "translate.y"
                                { fprintf(prod, "assign -> -=\n"); }
#line 2219 "translate.tab.c"
    break;

  case 77:
#line 351 "translate.y"
                                { fprintf(prod, "assign -> *=\n"); }
#line 2225 "translate.tab.c"
    break;

  case 78:
#line 352 "translate.y"
                                { fprintf(prod, "assign -> /=\n"); }
#line 2231 "translate.tab.c"
    break;

  case 79:
#line 353 "translate.y"
                                { fprintf(prod, "assign -> %%=\n"); }
#line 2237 "translate.tab.c"
    break;

  case 80:
#line 354 "translate.y"
                                { fprintf(prod, "assign -> <<=\n"); }
#line 2243 "translate.tab.c"
    break;

  case 81:
#line 355 "translate.y"
                                { fprintf(prod, "assign -> >>=\n"); }
#line 2249 "translate.tab.c"
    break;

  case 82:
#line 356 "translate.y"
                                { fprintf(prod, "assign -> &=\n"); }
#line 2255 "translate.tab.c"
    break;

  case 83:
#line 357 "translate.y"
                                { fprintf(prod, "assign -> |=\n"); }
#line 2261 "translate.tab.c"
    break;

  case 84:
#line 358 "translate.y"
                                { fprintf(prod, "assign -> ^=\n"); }
#line 2267 "translate.tab.c"
    break;

  case 85:
#line 361 "translate.y"
                                { fprintf(prod, "op -> +\n"); }
#line 2273 "translate.tab.c"
    break;

  case 86:
#line 362 "translate.y"
                                { fprintf(prod, "op -> -\n"); }
#line 2279 "translate.tab.c"
    break;

  case 87:
#line 363 "translate.y"
                                { fprintf(prod, "op -> *\n"); }
#line 2285 "translate.tab.c"
    break;

  case 88:
#line 364 "translate.y"
                                { fprintf(prod, "op -> /\n"); }
#line 2291 "translate.tab.c"
    break;

  case 89:
#line 365 "translate.y"
                                { fprintf(prod, "op -> %%\n"); }
#line 2297 "translate.tab.c"
    break;

  case 90:
#line 366 "translate.y"
                                { fprintf(prod, "op -> &\n"); }
#line 2303 "translate.tab.c"
    break;

  case 91:
#line 367 "translate.y"
                                { fprintf(prod, "op -> |\n"); }
#line 2309 "translate.tab.c"
    break;

  case 92:
#line 368 "translate.y"
                                { fprintf(prod, "op -> ~\n"); }
#line 2315 "translate.tab.c"
    break;

  case 93:
#line 369 "translate.y"
                                { fprintf(prod, "op -> <<\n"); }
#line 2321 "translate.tab.c"
    break;

  case 94:
#line 370 "translate.y"
                                { fprintf(prod, "op -> >>\n"); }
#line 2327 "translate.tab.c"
    break;

  case 95:
#line 371 "translate.y"
                                { fprintf(prod, "op -> ^\n"); }
#line 2333 "translate.tab.c"
    break;

  case 96:
#line 374 "translate.y"
                                { fprintf(prod, "rel -> ==\n"); }
#line 2339 "translate.tab.c"
    break;

  case 97:
#line 375 "translate.y"
                                { fprintf(prod, "rel -> !=\n"); }
#line 2345 "translate.tab.c"
    break;

  case 98:
#line 376 "translate.y"
                                { fprintf(prod, "rel -> <\n"); }
#line 2351 "translate.tab.c"
    break;

  case 99:
#line 377 "translate.y"
                                { fprintf(prod, "rel -> <=\n"); }
#line 2357 "translate.tab.c"
    break;

  case 100:
#line 378 "translate.y"
                                { fprintf(prod, "rel -> >\n"); }
#line 2363 "translate.tab.c"
    break;

  case 101:
#line 379 "translate.y"
                                { fprintf(prod, "rel -> >=\n"); }
#line 2369 "translate.tab.c"
    break;

  case 102:
#line 382 "translate.y"
                                { fprintf(prod, "cond -> &&\n"); }
#line 2375 "translate.tab.c"
    break;

  case 103:
#line 383 "translate.y"
                                { fprintf(prod, "cond -> ||\n"); }
#line 2381 "translate.tab.c"
    break;

  case 104:
#line 387 "translate.y"
            {
    fprintf(prod, "term -> INTEGER\n");
}
#line 2389 "translate.tab.c"
    break;

  case 105:
#line 390 "translate.y"
              {
    fprintf(prod, "term -> DECIMAL\n");
}
#line 2397 "translate.tab.c"
    break;

  case 106:
#line 393 "translate.y"
             {
    fprintf(prod, "term -> STRING\n");
}
#line 2405 "translate.tab.c"
    break;

  case 107:
#line 396 "translate.y"
              {
    fprintf(prod, "term -> boolean\n");
}
#line 2413 "translate.tab.c"
    break;

  case 108:
#line 399 "translate.y"
                                                {
    fprintf(prod, "term -> funcid ( opttermlist )\n");
}
#line 2421 "translate.tab.c"
    break;

  case 109:
#line 402 "translate.y"
           {
    fprintf(prod, "term -> attr\n");
}
#line 2429 "translate.tab.c"
    break;

  case 110:
#line 407 "translate.y"
                        {
    fprintf(prod, "attr -> ID vector\n");
}
#line 2437 "translate.tab.c"
    break;

  case 111:
#line 410 "translate.y"
                                 {
    fprintf(prod, "attr -> ID vector . attr\n");
}
#line 2445 "translate.tab.c"
    break;

  case 112:
#line 413 "translate.y"
                                     {
    fprintf(prod, "attr -> ID vector POINTER attr\n");
}
#line 2453 "translate.tab.c"
    break;

  case 113:
#line 419 "translate.y"
         {
    fprintf(prod, "boolean -> TRUE\n");
}
#line 2461 "translate.tab.c"
    break;

  case 114:
#line 422 "translate.y"
            {
    fprintf(prod, "boolean -> FALSE\n");
}
#line 2469 "translate.tab.c"
    break;

  case 115:
#line 427 "translate.y"
                                               {
    fprintf(prod, "vector -> vector [ expr ]");
}
#line 2477 "translate.tab.c"
    break;

  case 116:
#line 430 "translate.y"
                {
        fprintf(prod, "vector -> EPS\n");
    }
#line 2485 "translate.tab.c"
    break;

  case 117:
#line 435 "translate.y"
                                { fprintf(prod, "type -> INT\n"); (yyval.typeValue) = type_int; }
#line 2491 "translate.tab.c"
    break;

  case 118:
#line 436 "translate.y"
                                { fprintf(prod, "type -> CHAR\n"); (yyval.typeValue) = type_char; }
#line 2497 "translate.tab.c"
    break;

  case 119:
#line 437 "translate.y"
                                { fprintf(prod, "type -> FLOAT\n"); (yyval.typeValue) = type_float; }
#line 2503 "translate.tab.c"
    break;

  case 120:
#line 438 "translate.y"
                                { fprintf(prod, "type -> DOUBLE\n"); (yyval.typeValue) = type_double; }
#line 2509 "translate.tab.c"
    break;

  case 121:
#line 439 "translate.y"
                                { fprintf(prod, "type -> BOOL\n"); (yyval.typeValue) = type_bool; }
#line 2515 "translate.tab.c"
    break;

  case 122:
#line 440 "translate.y"
                                { fprintf(prod, "type -> STRUCT ID\n"); (yyval.typeValue) = type_struct; }
#line 2521 "translate.tab.c"
    break;

  case 123:
#line 441 "translate.y"
                                { fprintf(prod, "type -> ENUM ID\n"); (yyval.typeValue) = type_enum; }
#line 2527 "translate.tab.c"
    break;

  case 124:
#line 444 "translate.y"
                                { fprintf(prod, "modifier -> UNSIGNED\n"); }
#line 2533 "translate.tab.c"
    break;

  case 125:
#line 445 "translate.y"
                                { fprintf(prod, "modifier -> SIGNED\n"); }
#line 2539 "translate.tab.c"
    break;

  case 126:
#line 446 "translate.y"
                                { fprintf(prod, "modifier -> SHORT\n"); }
#line 2545 "translate.tab.c"
    break;

  case 127:
#line 447 "translate.y"
                                { fprintf(prod, "modifier -> LONG\n"); }
#line 2551 "translate.tab.c"
    break;

  case 128:
#line 448 "translate.y"
                                { fprintf(prod, "modifier -> CONST\n"); }
#line 2557 "translate.tab.c"
    break;

  case 129:
#line 449 "translate.y"
                                { fprintf(prod, "modifier -> EPS\n"); }
#line 2563 "translate.tab.c"
    break;


#line 2567 "translate.tab.c"

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
#line 452 "translate.y"


void blockOpen() {
    symbolTableCreateBlock(st);
}

void blockClose() {
    symbolTableShow(st, stdout);
    symbolTableDeleteBlock(st);
}

void addId(char *id, Enumtypes type) {
    symbolTableInsert(st, symbolNew(id, type, 1));
}

void onExit() {
    fclose(prod);
    symbolTableDelete(st);
}

void executeProgram() {
    printf("Programa sintaticamente correto\n");
}

void yyerror(const char *s) {
    printf("Erro próximo a linha %d: %s\n", line, s);
}

int main(void) {
    char sourceCode[1000000];
    size_t bytesRead = fread(sourceCode, sizeof(char), sizeof(sourceCode) - 1, stdin);
    sourceCode[bytesRead] = '\0';

    printSourceCodeWithLineNumbers(sourceCode);

    yyin = fmemopen(sourceCode, bytesRead, "r");
    
    prod = fopen("producoes.output", "w");
    st = symbolTableNew();
    symbolTableCreateBlock(st);
    yyparse();
    onExit();
    return 0;
}
