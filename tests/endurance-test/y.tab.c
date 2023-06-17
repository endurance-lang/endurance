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
#line 1 "example.y"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../../src/symbolTable.h"

extern int yylex();
extern void yyerror(const char*);

void onExit();

SymbolTable *st;

void executeProgram();


#line 87 "y.tab.c"

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
#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
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
    COMMENTS = 347
  };
#endif
/* Tokens.  */
#define UNSIGNED 258
#define SIGNED 259
#define SHORT 260
#define LONG 261
#define INCLUDE 262
#define MAIN 263
#define BREAK 264
#define CASE 265
#define CONST 266
#define CONTINUE 267
#define DEFAULT 268
#define IF 269
#define ELSE 270
#define ENUM 271
#define RETURN 272
#define STRUCT 273
#define INT 274
#define FLOAT 275
#define DOUBLE 276
#define BOOL 277
#define TRUE 278
#define FALSE 279
#define CHAR 280
#define DO 281
#define PRINTF 282
#define SCANF 283
#define FOR 284
#define GOTO 285
#define SIZEOF 286
#define SWITCH 287
#define TYPEDEF 288
#define UNION 289
#define WHILE 290
#define FREE 291
#define POINTER 292
#define SLICE 293
#define SOME 294
#define REDUCE 295
#define FILTER 296
#define MAP 297
#define SORT 298
#define CLOSE_BRACKET 299
#define OPEN_BRACKET 300
#define CLOSE_PAREN 301
#define OPEN_PAREN 302
#define BLOCK_CLOSE 303
#define BLOCK_OPEN 304
#define DOT 305
#define INCREMENT 306
#define DECREMENT 307
#define ADD 308
#define SUB 309
#define MUL 310
#define DIV 311
#define BITWISE_AND 312
#define BITWISE_OR 313
#define BITWISE_NOT 314
#define MOD 315
#define LEFT_SHIFT 316
#define RIGHT_SHIFT 317
#define LT 318
#define GT 319
#define LE 320
#define GE 321
#define EQ 322
#define NE 323
#define BITWISE_XOR 324
#define LOGICAL_AND 325
#define LOGICAL_OR 326
#define LOGICAL_NOT 327
#define QUEST 328
#define COLON 329
#define SEMI_COLON 330
#define ASSIGN 331
#define ADD_ASSIGN 332
#define SUB_ASSIGN 333
#define MUL_ASSIGN 334
#define DIV_ASSIGN 335
#define MOD_ASSIGN 336
#define LEFT_SHIFT_ASSIGN 337
#define RIGHT_SHIFT_ASSIGN 338
#define BITWISE_AND_ASSIGN 339
#define BITWISE_OR_ASSIGN 340
#define BITWISE_XOR_ASSIGN 341
#define COMMA 342
#define INTEGER 343
#define DECIMAL 344
#define STRING 345
#define IDENTIFIER 346
#define COMMENTS 347

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 18 "example.y"

    int number;
    double decimal;
    char* string;
    Enumtypes typeValue;

#line 330 "y.tab.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */



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
#define YYLAST   846

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  97
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  37
/* YYNRULES -- Number of rules.  */
#define YYNRULES  134
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  248

#define YYUNDEFTOK  2
#define YYMAXUTOK   347


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
       2,     2,    95,    93,     2,    94,     2,    96,     2,     2,
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
      85,    86,    87,    88,    89,    90,    91,    92
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   128,   128,   133,   134,   135,   136,   137,   138,   139,
     139,   148,   153,   156,   159,   165,   166,   167,   171,   174,
     177,   184,   183,   186,   192,   193,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   211,   211,   218,
     225,   224,   228,   227,   233,   234,   238,   239,   243,   244,
     248,   251,   254,   258,   257,   262,   265,   268,   271,   274,
     277,   280,   283,   289,   290,   294,   295,   299,   300,   304,
     305,   309,   312,   315,   318,   321,   324,   327,   330,   336,
     337,   338,   339,   340,   341,   342,   343,   344,   345,   346,
     350,   351,   352,   353,   354,   355,   356,   357,   358,   359,
     360,   364,   365,   366,   367,   368,   369,   373,   374,   378,
     381,   384,   387,   390,   393,   399,   402,   405,   411,   414,
     420,   421,   425,   426,   427,   428,   429,   430,   431,   435,
     436,   437,   438,   439,   440
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
  "INTEGER", "DECIMAL", "STRING", "IDENTIFIER", "COMMENTS", "'+'", "'-'",
  "'*'", "'/'", "$accept", "program", "stmt", "$@1", "block",
  "conditional", "caselist", "repetition", "var", "$@2", "pointer",
  "funcid", "func", "$@3", "typelist", "$@4", "$@5", "termlist",
  "opttypelist", "opttermlist", "commands", "$@6", "varlist", "idlist",
  "optexpr", "stmts", "expr", "assign", "op", "rel", "cond", "term",
  "attr", "boolean", "vector", "type", "modifier", YY_NULLPTR
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
     345,   346,   347,    43,    45,    42,    47
};
# endif

#define YYPACT_NINF (-143)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-48)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -143,    38,   193,  -143,  -143,  -143,  -143,  -143,   -51,  -143,
     -34,  -143,   -32,     2,   -41,    36,   -36,  -143,  -143,   638,
    -143,  -143,    11,   -26,    15,    20,   170,   -22,    23,  -143,
    -143,  -143,  -143,  -143,  -143,  -143,    36,    36,  -143,  -143,
    -143,   -17,  -143,    22,  -143,  -143,  -143,    26,  -143,   170,
    -143,   750,  -143,   168,  -143,    73,    67,  -143,  -143,  -143,
      36,    31,    35,    16,   773,    41,    58,    36,    21,     3,
      36,     5,     6,     7,    55,    36,   458,   773,  -143,   -13,
    -143,  -143,    94,   235,  -143,  -143,  -143,  -143,  -143,  -143,
    -143,  -143,  -143,  -143,  -143,  -143,  -143,  -143,  -143,  -143,
    -143,  -143,  -143,   638,  -143,    94,    94,    94,  -143,  -143,
    -143,  -143,  -143,  -143,  -143,  -143,  -143,  -143,  -143,    36,
     -40,    35,    59,  -143,  -143,  -143,  -143,  -143,   547,    28,
    -143,  -143,    76,    45,  -143,    83,    92,   636,  -143,  -143,
    -143,  -143,   703,  -143,    49,    36,    49,   460,    54,    96,
    -143,  -143,  -143,    97,    72,  -143,  -143,  -143,   773,   -40,
    -143,    74,  -143,   346,   638,    60,   100,   342,    36,    36,
      77,    86,   102,  -143,   422,   638,  -143,  -143,   677,  -143,
    -143,    94,  -143,   346,   638,  -143,   118,  -143,   -33,    80,
     122,    78,   155,    28,   103,   104,  -143,   -39,   729,   105,
    -143,  -143,  -143,   -28,   114,  -143,  -143,  -143,   125,  -143,
    -143,   170,   115,  -143,   638,  -143,  -143,  -143,  -143,   116,
      36,     0,  -143,  -143,   123,   101,  -143,  -143,  -143,  -143,
     131,    94,   120,  -143,  -143,  -143,   118,   638,   129,  -143,
     549,  -143,  -143,  -143,   282,  -143,   118,   371
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
      70,     0,    37,     1,   129,   130,   131,   132,     0,    27,
       0,   133,     0,     0,     0,    68,     0,   118,   119,    37,
      28,    29,     0,     0,     0,     0,   134,     0,     0,    36,
      30,    31,    32,    33,    34,    35,     0,     0,   109,   110,
     111,   121,    69,     0,     3,     4,     6,     0,     5,   134,
       7,     0,    77,   114,   112,     0,     0,    55,    51,    52,
       0,   128,   121,     0,    67,   127,     0,    68,     0,   134,
       0,     0,     0,     0,     0,     0,     0,    75,    60,   115,
      70,    10,    49,     0,    90,    91,    92,    93,    95,    96,
      97,    94,    98,    99,   103,   105,   104,   106,   101,   102,
     100,   107,   108,    37,     8,     0,     0,     0,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,     0,
       0,    21,     0,   122,   124,   125,   126,   123,     0,     0,
      50,    64,     0,     0,    59,     0,     0,     0,   128,   127,
      53,    64,     0,    78,     0,     0,     0,    37,    48,     0,
      45,   114,    26,     0,     0,    72,    73,    74,    71,     0,
     121,     0,   121,   134,    37,    66,     0,   134,     0,    68,
       0,     0,     0,   121,   134,    37,   121,   117,     0,   116,
      11,     0,   113,   134,    37,    25,    24,    23,     0,    46,
       0,     0,    12,     0,     0,     0,    63,     0,     0,     0,
      62,    61,    17,     0,     0,    18,   120,    44,     0,    76,
      22,   134,     0,    42,    37,    65,    57,    56,    21,     0,
      68,     0,    54,    58,     0,     0,    39,   121,    13,    20,
       0,     0,     0,    14,    70,    40,    43,    37,     0,    70,
      37,   121,    19,    70,    37,    38,    41,    37
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -143,  -143,   -19,  -143,  -143,  -143,  -143,  -143,  -134,  -143,
      53,   -29,  -143,  -143,  -143,  -143,  -143,  -143,    25,  -143,
    -143,  -143,    89,    44,   -62,   -77,   -14,  -143,  -143,  -143,
    -143,   -71,   -78,  -143,  -142,   -24,  -143
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,    42,    43,    81,    44,   221,    45,    46,   162,
     161,    47,    48,    49,   189,   241,   227,   148,   190,   149,
      50,   173,   167,   166,    63,     2,    51,   119,   105,   106,
     107,    52,    53,    54,    79,    55,    56
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      66,    64,    73,   147,   151,   133,     4,     5,     6,     7,
     231,   150,   145,   232,    11,   159,   120,   145,   186,    71,
     188,    72,    76,    77,   144,    83,   122,   151,   151,   151,
     -26,   203,   145,   196,   155,   156,   157,   146,     3,    57,
     196,    58,   210,    59,     9,   136,   128,   222,   233,    60,
      61,   160,   218,    64,   153,    65,   137,    78,    67,    17,
      18,   142,    69,    20,    21,    68,   177,    70,   179,    74,
      75,    80,    29,    82,    30,    31,    32,    33,    34,    35,
     129,     9,   -26,    36,   154,   236,   123,   124,   125,   126,
     131,   130,   127,   132,   135,   134,   138,   139,   140,   246,
      20,    21,     9,   151,   141,   158,   163,   199,    37,    29,
     207,    30,    31,    32,    33,    34,    35,    17,    18,   165,
     169,    20,    21,   168,    38,    39,    40,    62,   120,   170,
      29,   178,    30,    31,    32,    33,    34,    35,   171,   191,
     176,   181,   182,   197,   183,   192,   184,   193,   194,   187,
     197,   202,   200,   151,   198,    64,   205,   240,   230,   191,
     238,   201,   244,   145,   121,   209,   247,   211,   212,   213,
     214,   224,   234,     4,     5,     6,     7,   237,   216,   217,
     220,    11,    38,    39,    40,    62,    71,   225,    72,   223,
     226,   229,   235,    -2,   239,   228,     4,     5,     6,     7,
       8,     9,    10,   243,    11,    12,    64,    13,   208,    14,
      15,    16,   185,     0,     0,     0,    17,    18,   242,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
     174,    30,    31,    32,    33,    34,    35,   215,     0,     0,
      36,     0,    -9,     9,   108,   109,   110,   111,   112,   113,
     114,   115,   116,   117,   118,     0,     0,     0,     0,     0,
       0,     0,    20,    21,     0,    37,     0,     0,     0,     0,
       0,    29,     0,    30,    31,    32,    33,    34,    35,     0,
       0,    38,    39,    40,    41,     4,     5,     6,     7,     8,
       9,    10,   -16,    11,    12,   -16,    13,     0,    14,    15,
      16,     0,     0,     0,     0,    17,    18,     0,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,     0,
      30,    31,    32,    33,    34,    35,   152,     0,     0,    36,
     -16,    -9,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     4,     5,     6,     7,     4,
       5,     6,     7,    11,    37,     0,     0,    11,    71,     0,
      72,     0,    71,     0,    72,     0,     0,     0,     0,     0,
      38,    39,    40,    41,     4,     5,     6,     7,     8,     9,
      10,   -15,    11,    12,   -15,    13,     0,    14,    15,    16,
     195,     0,   -47,     0,    17,    18,     0,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,     0,    30,
      31,    32,    33,    34,    35,     0,     0,     0,    36,   -15,
      -9,     0,     0,     0,     0,     4,     5,     6,     7,     0,
       0,     0,     0,    11,     0,     0,     0,     0,    71,     0,
      72,     0,     0,    37,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    38,
      39,    40,    41,     4,     5,     6,     7,     8,     9,    10,
     204,    11,    12,     0,    13,     0,    14,    15,    16,     0,
       0,     0,     0,    17,    18,     0,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,     0,    30,    31,
      32,    33,    34,    35,   143,     0,     0,    36,   180,    -9,
       0,    84,    85,    86,    87,    88,    89,    90,    91,    92,
      93,    94,    95,    96,    97,    98,    99,   100,   101,   102,
       0,   103,    37,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    38,    39,
      40,    41,     4,     5,     6,     7,     8,     9,    10,     0,
      11,    12,     0,    13,     0,    14,    15,    16,     0,     0,
       0,     0,    17,    18,     0,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,     0,    30,    31,    32,
      33,    34,    35,   164,     0,     0,    36,   245,    -9,     0,
      84,    85,    86,    87,    88,    89,    90,    91,    92,    93,
      94,    95,    96,    97,    98,    99,   100,   101,   102,     0,
     103,    37,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    38,    39,    40,
      41,     4,     5,     6,     7,     8,     9,    10,     0,    11,
      12,     0,    13,     0,    14,    15,    16,     0,     0,     0,
       0,    17,    18,     0,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,     0,    30,    31,    32,    33,
      34,    35,   172,     0,     0,    36,     0,    -9,     0,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   102,     0,   103,
      37,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   206,     0,     0,     0,     0,    38,    39,    40,    41,
      84,    85,    86,    87,    88,    89,    90,    91,    92,    93,
      94,    95,    96,    97,    98,    99,   100,   101,   102,   175,
     103,     0,     0,     0,     0,     0,    84,    85,    86,    87,
      88,    89,    90,    91,    92,    93,    94,    95,    96,    97,
      98,    99,   100,   101,   102,   219,   103,     0,     0,     0,
       0,     0,    84,    85,    86,    87,    88,    89,    90,    91,
      92,    93,    94,    95,    96,    97,    98,    99,   100,   101,
     102,     0,   103,    84,    85,    86,    87,    88,    89,    90,
      91,    92,    93,    94,    95,    96,    97,    98,    99,   100,
     101,   102,     0,   103,     0,   104,    84,    85,    86,    87,
      88,    89,    90,    91,    92,    93,    94,    95,    96,    97,
      98,    99,   100,   101,   102,     0,   103
};

static const yytype_int16 yycheck[] =
{
      19,    15,    26,    80,    82,    67,     3,     4,     5,     6,
      10,    82,    45,    13,    11,    55,    55,    45,   160,    16,
     162,    18,    36,    37,    37,    49,    55,   105,   106,   107,
      47,   173,    45,   167,   105,   106,   107,    50,     0,    90,
     174,    75,    75,    75,     8,    69,    60,    75,    48,    47,
      91,    91,    91,    67,    83,    91,    70,    74,    47,    23,
      24,    75,    47,    27,    28,    91,   144,    47,   146,    91,
      47,    49,    36,    47,    38,    39,    40,    41,    42,    43,
      49,     8,    47,    47,   103,   227,    19,    20,    21,    22,
      49,    75,    25,    35,    91,    74,    91,    91,    91,   241,
      27,    28,     8,   181,    49,   119,    47,   169,    72,    36,
     181,    38,    39,    40,    41,    42,    43,    23,    24,    91,
      75,    27,    28,    47,    88,    89,    90,    91,    55,    46,
      36,   145,    38,    39,    40,    41,    42,    43,    46,   163,
      91,    87,    46,   167,    47,   164,    74,    87,    48,    75,
     174,    49,    75,   231,   168,   169,   175,   234,   220,   183,
     231,    75,   239,    45,    91,   184,   243,    87,    46,    91,
      15,    46,    49,     3,     4,     5,     6,    46,    75,    75,
      75,    11,    88,    89,    90,    91,    16,   211,    18,    75,
      75,    75,    91,     0,    74,   214,     3,     4,     5,     6,
       7,     8,     9,    74,    11,    12,   220,    14,   183,    16,
      17,    18,   159,    -1,    -1,    -1,    23,    24,   237,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
     141,    38,    39,    40,    41,    42,    43,   193,    -1,    -1,
      47,    -1,    49,     8,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    27,    28,    -1,    72,    -1,    -1,    -1,    -1,
      -1,    36,    -1,    38,    39,    40,    41,    42,    43,    -1,
      -1,    88,    89,    90,    91,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    -1,    16,    17,
      18,    -1,    -1,    -1,    -1,    23,    24,    -1,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    -1,
      38,    39,    40,    41,    42,    43,    91,    -1,    -1,    47,
      48,    49,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,     3,     4,     5,     6,     3,
       4,     5,     6,    11,    72,    -1,    -1,    11,    16,    -1,
      18,    -1,    16,    -1,    18,    -1,    -1,    -1,    -1,    -1,
      88,    89,    90,    91,     3,     4,     5,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    -1,    16,    17,    18,
      48,    -1,    46,    -1,    23,    24,    -1,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    -1,    38,
      39,    40,    41,    42,    43,    -1,    -1,    -1,    47,    48,
      49,    -1,    -1,    -1,    -1,     3,     4,     5,     6,    -1,
      -1,    -1,    -1,    11,    -1,    -1,    -1,    -1,    16,    -1,
      18,    -1,    -1,    72,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    88,
      89,    90,    91,     3,     4,     5,     6,     7,     8,     9,
      48,    11,    12,    -1,    14,    -1,    16,    17,    18,    -1,
      -1,    -1,    -1,    23,    24,    -1,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    -1,    38,    39,
      40,    41,    42,    43,    46,    -1,    -1,    47,    48,    49,
      -1,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,    69,    70,    71,
      -1,    73,    72,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    88,    89,
      90,    91,     3,     4,     5,     6,     7,     8,     9,    -1,
      11,    12,    -1,    14,    -1,    16,    17,    18,    -1,    -1,
      -1,    -1,    23,    24,    -1,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    -1,    38,    39,    40,
      41,    42,    43,    46,    -1,    -1,    47,    48,    49,    -1,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    68,    69,    70,    71,    -1,
      73,    72,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    88,    89,    90,
      91,     3,     4,     5,     6,     7,     8,     9,    -1,    11,
      12,    -1,    14,    -1,    16,    17,    18,    -1,    -1,    -1,
      -1,    23,    24,    -1,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    -1,    38,    39,    40,    41,
      42,    43,    46,    -1,    -1,    47,    -1,    49,    -1,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,    69,    70,    71,    -1,    73,
      72,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    44,    -1,    -1,    -1,    -1,    88,    89,    90,    91,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    68,    69,    70,    71,    46,
      73,    -1,    -1,    -1,    -1,    -1,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    68,    69,    70,    71,    46,    73,    -1,    -1,    -1,
      -1,    -1,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    68,    69,    70,
      71,    -1,    73,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    68,    69,
      70,    71,    -1,    73,    -1,    75,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    68,    69,    70,    71,    -1,    73
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    98,   122,     0,     3,     4,     5,     6,     7,     8,
       9,    11,    12,    14,    16,    17,    18,    23,    24,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      38,    39,    40,    41,    42,    43,    47,    72,    88,    89,
      90,    91,    99,   100,   102,   104,   105,   108,   109,   110,
     117,   123,   128,   129,   130,   132,   133,    90,    75,    75,
      47,    91,    91,   121,   123,    91,    99,    47,    91,    47,
      47,    16,    18,   132,    91,    47,   123,   123,    74,   131,
      49,   101,    47,   132,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    68,
      69,    70,    71,    73,    75,   125,   126,   127,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,   124,
      55,    91,   108,    19,    20,    21,    22,    25,   123,    49,
      75,    49,    35,   121,    74,    91,   132,   123,    91,    91,
      91,    49,   123,    46,    37,    45,    50,   122,   114,   116,
     128,   129,    91,   108,    99,   128,   128,   128,   123,    55,
      91,   107,   106,    47,    46,    91,   120,   119,    47,    75,
      46,    46,    46,   118,   119,    46,    91,   129,   123,   129,
      48,    87,    46,    47,    74,   107,   131,    75,   131,   111,
     115,   132,    99,    87,    48,    48,   105,   132,   123,   121,
      75,    75,    49,   131,    48,    99,    44,   128,   115,    99,
      75,    87,    46,    91,    15,   120,    75,    75,    91,    46,
      75,   103,    75,    75,    46,   132,    75,   113,    99,    75,
     121,    10,    13,    48,    49,    91,   131,    46,   128,    74,
     122,   112,    99,    74,   122,    48,   131,   122
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    97,    98,    99,    99,    99,    99,    99,    99,   100,
      99,   101,   102,   102,   102,   103,   103,   103,   104,   104,
     104,   106,   105,   105,   107,   107,   108,   108,   108,   108,
     108,   108,   108,   108,   108,   108,   108,   110,   109,   109,
     112,   111,   113,   111,   114,   114,   115,   115,   116,   116,
     117,   117,   117,   118,   117,   117,   117,   117,   117,   117,
     117,   117,   117,   119,   119,   120,   120,   121,   121,   122,
     122,   123,   123,   123,   123,   123,   123,   123,   123,   124,
     124,   124,   124,   124,   124,   124,   124,   124,   124,   124,
     125,   125,   125,   125,   125,   125,   125,   125,   125,   125,
     125,   126,   126,   126,   126,   126,   126,   127,   127,   128,
     128,   128,   128,   128,   128,   129,   129,   129,   130,   130,
     131,   131,   132,   132,   132,   132,   132,   132,   132,   133,
     133,   133,   133,   133,   133
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     1,     1,     1,     1,     1,     2,     0,
       2,     3,     5,     7,     7,     5,     4,     0,     5,     9,
       7,     0,     5,     4,     2,     2,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     0,     9,     6,
       0,     6,     0,     4,     3,     1,     1,     0,     1,     0,
       3,     2,     2,     0,     6,     2,     6,     6,     6,     3,
       2,     5,     5,     2,     0,     3,     1,     1,     0,     2,
       0,     3,     3,     3,     3,     2,     5,     1,     3,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     4,     1,     2,     4,     4,     1,     1,
       4,     0,     2,     2,     2,     2,     2,     2,     2,     1,
       1,     1,     1,     1,     0
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
#line 128 "example.y"
          {
    executeProgram();
}
#line 1816 "y.tab.c"
    break;

  case 9:
#line 139 "example.y"
            { symbolTableCreateBlock(st); }
#line 1822 "y.tab.c"
    break;

  case 10:
#line 141 "example.y"
            { 
                symbolTableShow(st);
                symbolTableDeleteBlock(st);
            }
#line 1831 "y.tab.c"
    break;

  case 11:
#line 148 "example.y"
                                 {
    printf("Block statement\n");
}
#line 1839 "y.tab.c"
    break;

  case 12:
#line 153 "example.y"
                                        {
    printf("If statement\n");
}
#line 1847 "y.tab.c"
    break;

  case 13:
#line 156 "example.y"
                                                    {
    printf("If-else statement\n");
}
#line 1855 "y.tab.c"
    break;

  case 14:
#line 159 "example.y"
                                                                         {
    printf("switch statement\n");
}
#line 1863 "y.tab.c"
    break;

  case 18:
#line 171 "example.y"
                                           {
    printf("While loop\n");
}
#line 1871 "y.tab.c"
    break;

  case 19:
#line 174 "example.y"
                                                                                    {
    printf("For loop\n");
}
#line 1879 "y.tab.c"
    break;

  case 20:
#line 177 "example.y"
                                                           {
    printf("Do-while loop\n");
}
#line 1887 "y.tab.c"
    break;

  case 21:
#line 184 "example.y"
                                        { symbolTableInsert(st, symbolNew((yyvsp[0].string), (yyvsp[-1].typeValue), 1)); }
#line 1893 "y.tab.c"
    break;

  case 23:
#line 186 "example.y"
                                  {
    printf("Pointer declaration\n");
}
#line 1901 "y.tab.c"
    break;

  case 37:
#line 211 "example.y"
                                { symbolTableCreateBlock(st); }
#line 1907 "y.tab.c"
    break;

  case 38:
#line 214 "example.y"
                                { 
                                  symbolTableShow(st);
                                  symbolTableDeleteBlock(st); 
                                }
#line 1916 "y.tab.c"
    break;

  case 39:
#line 218 "example.y"
                                                                {
    printf("Function declaration\n");
}
#line 1924 "y.tab.c"
    break;

  case 40:
#line 225 "example.y"
                                    {symbolTableInsert(st, symbolNew((yyvsp[0].string), (yyvsp[-1].typeValue), 1));}
#line 1930 "y.tab.c"
    break;

  case 42:
#line 228 "example.y"
                                    {symbolTableInsert(st, symbolNew((yyvsp[0].string), (yyvsp[-1].typeValue), 1));}
#line 1936 "y.tab.c"
    break;

  case 50:
#line 248 "example.y"
                              {
    printf("Return statement\n");
}
#line 1944 "y.tab.c"
    break;

  case 51:
#line 251 "example.y"
                       {
    printf("Break statement\n");
}
#line 1952 "y.tab.c"
    break;

  case 52:
#line 254 "example.y"
                          {
    printf("Continue statement\n");
}
#line 1960 "y.tab.c"
    break;

  case 53:
#line 258 "example.y"
                                    {symbolTableInsert(st, symbolNew((yyvsp[0].string), type_types, 1));}
#line 1966 "y.tab.c"
    break;

  case 54:
#line 259 "example.y"
                      {
    printf("Typedef declaration\n");
}
#line 1974 "y.tab.c"
    break;

  case 55:
#line 262 "example.y"
                     {
    printf("Include directive\n");
}
#line 1982 "y.tab.c"
    break;

  case 56:
#line 265 "example.y"
                                                                  {
    printf("Struct definition\n");
}
#line 1990 "y.tab.c"
    break;

  case 57:
#line 268 "example.y"
                                                               {
    printf("Enum definition\n");
}
#line 1998 "y.tab.c"
    break;

  case 58:
#line 271 "example.y"
                                                                 {
    printf("Union definition\n");
}
#line 2006 "y.tab.c"
    break;

  case 59:
#line 274 "example.y"
                            {
    printf("Goto definition\n");
}
#line 2014 "y.tab.c"
    break;

  case 60:
#line 277 "example.y"
                       {
    printf("Label definition\n");
}
#line 2022 "y.tab.c"
    break;

  case 61:
#line 280 "example.y"
                                                    {
    printf("Sizeof definition\n");
}
#line 2030 "y.tab.c"
    break;

  case 62:
#line 283 "example.y"
                                                          {
    printf("Sizeof definition\n");
}
#line 2038 "y.tab.c"
    break;

  case 64:
#line 290 "example.y"
                        {printf("empty varlist\n");}
#line 2044 "y.tab.c"
    break;

  case 67:
#line 299 "example.y"
                                {  }
#line 2050 "y.tab.c"
    break;

  case 69:
#line 304 "example.y"
                                {  }
#line 2056 "y.tab.c"
    break;

  case 71:
#line 309 "example.y"
                     {
    printf("Assignment expression\n");
}
#line 2064 "y.tab.c"
    break;

  case 72:
#line 312 "example.y"
                   {            
    printf("Binary operation expression\n");
}
#line 2072 "y.tab.c"
    break;

  case 73:
#line 315 "example.y"
                    {
    printf("Relational operation expression\n");
}
#line 2080 "y.tab.c"
    break;

  case 74:
#line 318 "example.y"
                     {
    printf("Conditional operation expression\n");
}
#line 2088 "y.tab.c"
    break;

  case 75:
#line 321 "example.y"
                       {
    printf("Logical NOT expression\n");
}
#line 2096 "y.tab.c"
    break;

  case 76:
#line 324 "example.y"
                                 {
    printf("Ternary conditional expression\n");
}
#line 2104 "y.tab.c"
    break;

  case 77:
#line 327 "example.y"
           {                    
    printf("Term expression\n");
}
#line 2112 "y.tab.c"
    break;

  case 78:
#line 330 "example.y"
                                 {
        printf("Expression\n");
    }
#line 2120 "y.tab.c"
    break;

  case 109:
#line 378 "example.y"
            {
    printf("Integer term\n");
}
#line 2128 "y.tab.c"
    break;

  case 110:
#line 381 "example.y"
              {
    printf("Decimal term\n");
}
#line 2136 "y.tab.c"
    break;

  case 111:
#line 384 "example.y"
             {
    printf("String term\n");
}
#line 2144 "y.tab.c"
    break;

  case 112:
#line 387 "example.y"
              {
    printf("boolean term\n");
}
#line 2152 "y.tab.c"
    break;

  case 113:
#line 390 "example.y"
                                                {
    printf("Function call term 2\n");
}
#line 2160 "y.tab.c"
    break;

  case 114:
#line 393 "example.y"
           {
    printf("term -> attr\n");
}
#line 2168 "y.tab.c"
    break;

  case 115:
#line 399 "example.y"
                      {
    printf("Identifier attr 1\n");
}
#line 2176 "y.tab.c"
    break;

  case 116:
#line 402 "example.y"
                                 {
    printf("Nested identifier attr\n");
}
#line 2184 "y.tab.c"
    break;

  case 117:
#line 405 "example.y"
                                     {
    printf("Dereferenced identifier attr\n");
}
#line 2192 "y.tab.c"
    break;

  case 118:
#line 411 "example.y"
         {
    printf("True boolean term\n");
}
#line 2200 "y.tab.c"
    break;

  case 119:
#line 414 "example.y"
            {
    printf("False boolean term\n");
}
#line 2208 "y.tab.c"
    break;

  case 122:
#line 425 "example.y"
                                { (yyval.typeValue) = type_int; }
#line 2214 "y.tab.c"
    break;

  case 123:
#line 426 "example.y"
                                { (yyval.typeValue) = type_char; }
#line 2220 "y.tab.c"
    break;

  case 124:
#line 427 "example.y"
                                { (yyval.typeValue) = type_float; }
#line 2226 "y.tab.c"
    break;

  case 125:
#line 428 "example.y"
                                { (yyval.typeValue) = type_double; }
#line 2232 "y.tab.c"
    break;

  case 126:
#line 429 "example.y"
                                { (yyval.typeValue) = type_bool; }
#line 2238 "y.tab.c"
    break;

  case 127:
#line 430 "example.y"
                                { (yyval.typeValue) = type_struct; }
#line 2244 "y.tab.c"
    break;

  case 128:
#line 431 "example.y"
                                { (yyval.typeValue) = type_enum; }
#line 2250 "y.tab.c"
    break;


#line 2254 "y.tab.c"

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
#line 443 "example.y"


void onExit() {
    symbolTableDelete(st);
}

void executeProgram() {
    printf("Program execution started\n");
}

int main(void) {
    st = symbolTableNew();
    symbolTableCreateBlock(st);
    yyparse();
    symbolTableShow(st);
    symbolTableDeleteBlock(st);
    onExit();
    return 0;
}
