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

extern int yylex();
extern void yyerror(const char*);

#define YYSTYPE YYSTYPE

typedef struct {
    int number;
    double decimal;
    char* string;
} YYSTYPE;

void executeProgram();


#line 90 "y.tab.c"

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
#line 114 "translate.y"

    int number;
    double decimal;
    char* string;

#line 332 "y.tab.c"

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
#define YYLAST   886

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  93
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  31
/* YYNRULES -- Number of rules.  */
#define YYNRULES  128
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  234

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
      85,    86,    87,    88,    89,    90,    91,    92
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   122,   122,   126,   127,   128,   129,   130,   131,   132,
     135,   139,   142,   145,   150,   151,   152,   155,   158,   161,
     166,   169,   174,   175,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   191,   194,   199,   200,   203,
     204,   207,   208,   211,   212,   215,   218,   221,   224,   227,
     230,   233,   236,   239,   242,   245,   248,   253,   254,   257,
     258,   261,   262,   265,   266,   269,   272,   275,   278,   281,
     284,   287,   292,   293,   294,   295,   296,   297,   298,   299,
     300,   301,   302,   305,   306,   307,   308,   309,   310,   311,
     312,   313,   314,   315,   318,   319,   320,   321,   322,   323,
     326,   327,   330,   333,   336,   339,   342,   345,   350,   353,
     356,   361,   364,   369,   370,   373,   374,   375,   376,   377,
     378,   379,   380,   383,   384,   385,   386,   387,   388
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
  "INTEGER", "DECIMAL", "STRING", "IDENTIFIER", "COMMENTS", "$accept",
  "program", "stmt", "block", "conditional", "caselist", "repetition",
  "var", "pointer", "funcid", "func", "typelist", "termlist",
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
     345,   346,   347
};
# endif

#define YYPACT_NINF (-147)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-123)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -147,    10,   204,  -147,  -147,  -147,  -147,  -147,   -74,  -147,
     -57,  -147,   -56,   -27,   -70,   686,   -65,  -147,  -147,   649,
    -147,  -147,   -16,   -61,    -9,    -6,   150,   -58,     1,  -147,
    -147,  -147,  -147,  -147,  -147,  -147,  -147,   686,  -147,  -147,
    -147,   725,  -147,  -147,  -147,  -147,  -147,     2,  -147,  -147,
     790,  -147,   186,  -147,   751,    37,  -147,  -147,  -147,   686,
       4,     3,   -21,   813,    11,    28,   686,   -10,   170,   686,
     -26,   -24,  -147,   -22,    30,   686,   471,   813,  -147,   -13,
     707,  -147,  -147,  -147,  -147,  -147,  -147,  -147,  -147,  -147,
    -147,  -147,  -147,  -147,  -147,  -147,  -147,  -147,  -147,  -147,
     649,  -147,   707,   707,   707,  -147,  -147,  -147,  -147,  -147,
    -147,  -147,  -147,  -147,  -147,  -147,   686,   -51,     3,    33,
    -147,  -147,  -147,  -147,  -147,   291,    -7,  -147,  -147,    39,
      13,  -147,    44,    46,   380,  -147,  -147,  -147,  -147,   469,
    -147,     6,   686,     6,     7,    47,  -147,  -147,    21,  -147,
    -147,  -147,   813,   -51,  -147,    23,   -31,    67,   649,    14,
      55,    71,   686,   686,    29,    32,    56,   -28,   111,   649,
    -147,  -147,   764,  -147,   707,  -147,   649,  -147,    63,  -147,
    -147,    22,    64,    27,    97,    -7,    45,    48,  -147,   -48,
     558,    49,  -147,  -147,  -147,  -147,    50,  -147,  -147,  -147,
    -147,   150,   -36,  -147,   649,  -147,  -147,  -147,  -147,    51,
     686,    -2,  -147,    40,  -147,  -147,    63,  -147,  -147,    75,
     707,    58,  -147,  -147,   560,   649,    59,  -147,    63,  -147,
    -147,  -147,   293,   382
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
      64,     0,   128,     1,   123,   124,   125,   126,     0,    25,
       0,   127,     0,     0,     0,    62,     0,   111,   112,   128,
      26,    27,     0,     0,     0,     0,   128,     0,     0,    34,
      28,    29,    30,    31,    32,    33,    64,     0,   102,   103,
     104,   114,    63,     9,     3,     4,     6,     0,     5,     7,
       0,    71,   107,   105,     0,     0,    49,    46,    47,     0,
     121,   114,     0,    61,   120,     0,    62,     0,   128,     0,
       0,     0,   122,     0,     0,     0,   128,    69,    54,   108,
      44,    83,    84,    85,    86,    88,    89,    90,    87,    91,
      92,    96,    98,    97,    99,    94,    95,    93,   100,   101,
     128,     8,     0,     0,     0,    72,    73,    74,    75,    76,
      77,    78,    79,    80,    81,    82,     0,     0,   114,     0,
     115,   117,   118,   119,   116,     0,     0,    45,    58,     0,
       0,    53,     0,     0,     0,   121,   120,   114,    58,     0,
      10,     0,     0,     0,    43,     0,    40,   107,     0,    66,
      67,    68,    65,     0,   114,     0,     0,   128,   128,    60,
       0,   128,     0,    62,     0,     0,     0,     0,   128,   128,
     114,   110,     0,   109,     0,   106,   128,    23,    22,    21,
      20,    41,     0,     0,    11,     0,     0,     0,    57,     0,
       0,     0,    56,    55,    16,    48,     0,    17,   113,    39,
      70,   128,     0,   114,   128,    59,    51,    50,   114,     0,
      62,     0,    52,     0,    64,    36,    38,    12,    19,     0,
       0,     0,    13,   114,   128,   128,     0,    64,    37,    35,
      18,    64,   128,   128
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -147,  -147,   -19,  -147,  -147,  -147,  -147,  -146,   -23,    80,
    -147,  -147,  -147,  -147,  -147,  -147,    -3,   -49,   -63,   -34,
     -14,  -147,  -147,  -147,  -147,   -68,   -75,  -147,  -112,   -17,
    -147
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,    42,    43,    44,   211,    45,    46,   155,    47,
      48,   181,   144,   182,   145,    49,   161,   160,    62,     2,
      50,   116,   102,   103,   104,    51,    52,    53,    79,    54,
      55
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      65,    63,    76,   130,   153,   147,   156,   117,   220,    73,
       3,   221,   146,   214,   142,   188,    56,   142,    57,    58,
      59,    60,   188,    77,   141,   167,    64,   147,   147,   147,
      67,    66,   142,    74,   149,   150,   151,   143,    68,   215,
     154,    69,   178,   208,   180,   125,   222,   195,    75,    80,
     -24,   133,    63,   126,   127,   134,   120,   121,   122,   123,
     128,   139,   124,   129,   131,   135,   171,   136,   173,   137,
       4,     5,     6,     7,     4,     5,     6,     7,    11,   138,
     157,   148,    11,    70,   159,    71,   162,    70,   163,    71,
     164,   216,   165,   175,   174,   176,   156,   170,   179,   147,
     191,   185,   152,   186,   192,   194,   199,   193,   142,   201,
     202,   228,   204,   -42,     4,     5,     6,     7,   203,   187,
     206,   225,    11,   207,   210,   212,   218,    70,   172,    71,
     177,   223,   227,   231,   119,   168,   205,     0,     0,   184,
     183,     0,     0,     0,   189,   147,     0,   219,   190,    63,
     197,   189,   226,     4,     5,     6,     7,   200,    72,   196,
       0,    11,    72,     0,     0,     0,    70,     0,    71,     0,
       0,     0,     0,     4,     5,     6,     7,     0,     0,     0,
     224,    11,     0,     0,   213,   217,    70,     0,    71,     0,
       0,     0,     0,   232,     0,     0,    63,   233,     0,     0,
       0,     0,    72,     0,    -2,     0,   230,     4,     5,     6,
       7,     8,     9,    10,     0,    11,    12,     0,    13,     0,
      14,    15,    16,     0,     0,     0,     0,    17,    18,     0,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    72,    30,    31,    32,    33,    34,    35,     0,     0,
       0,     0,     0,    36,     0,     0,     0,     0,     0,     0,
       0,   132,   105,   106,   107,   108,   109,   110,   111,   112,
     113,   114,   115,     0,     0,     0,    37,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    38,    39,    40,    41,     4,     5,     6,     7,
       8,     9,    10,   -15,    11,    12,   -15,    13,     0,    14,
      15,    16,     0,     0,     0,     0,    17,    18,     0,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
       0,    30,    31,    32,    33,    34,    35,   158,     0,     0,
       0,   -15,    36,     0,    81,    82,    83,    84,    85,    86,
      87,    88,    89,    90,    91,    92,    93,    94,    95,    96,
      97,    98,    99,     0,   100,    37,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    38,    39,    40,    41,     4,     5,     6,     7,     8,
       9,    10,   -14,    11,    12,   -14,    13,     0,    14,    15,
      16,     0,     0,     0,     0,    17,    18,     0,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,     0,
      30,    31,    32,    33,    34,    35,   166,     0,     0,     0,
     -14,    36,     0,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    91,    92,    93,    94,    95,    96,    97,
      98,    99,     0,   100,    37,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      38,    39,    40,    41,     4,     5,     6,     7,     8,     9,
      10,     0,    11,    12,     0,    13,     0,    14,    15,    16,
       0,     0,     0,     0,    17,    18,     0,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,     0,    30,
      31,    32,    33,    34,    35,   169,     0,     0,     0,   140,
      36,     0,    81,    82,    83,    84,    85,    86,    87,    88,
      89,    90,    91,    92,    93,    94,    95,    96,    97,    98,
      99,     0,   100,    37,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    38,
      39,    40,    41,     4,     5,     6,     7,     8,     9,    10,
       0,    11,    12,     0,    13,     0,    14,    15,    16,     0,
       0,     0,     0,    17,    18,     0,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,     0,    30,    31,
      32,    33,    34,    35,   209,     0,     0,     0,   229,    36,
       0,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    93,    94,    95,    96,    97,    98,    99,
       0,   100,    37,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    38,    39,
      40,    41,     4,     5,     6,     7,     8,     9,    10,     0,
      11,    12,     0,    13,     0,    14,    15,    16,     0,     0,
       0,     0,    17,    18,     0,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,     0,    30,    31,    32,
      33,    34,    35,     0,     9,     0,     0,     0,    36,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    17,
      18,     0,     0,    20,    21,     9,     0,     0,     0,     0,
       0,    37,    29,     0,    30,    31,    32,    33,    34,    35,
      17,    18,     0,  -122,    20,    21,     0,    38,    39,    40,
      41,     0,     0,    29,     0,    30,    31,    32,    33,    34,
      35,     0,  -122,  -122,     0,     0,     0,     0,    37,     9,
       0,  -122,     0,  -122,  -122,  -122,  -122,  -122,  -122,     0,
       0,     0,   -24,     0,    38,    39,    40,    61,    20,    21,
       0,     0,     0,     0,     0,     0,     0,    29,     0,    30,
      31,    32,    33,    34,    35,    38,    39,    40,    61,    78,
       0,     0,     0,     0,     0,     0,   117,     0,   198,     0,
       0,     0,     0,     0,     0,     0,  -122,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    91,    92,    93,
      94,    95,    96,    97,    98,    99,     0,   100,     0,     0,
       0,     0,   118,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    91,    92,    93,    94,    95,    96,    97,
      98,    99,     0,   100,     0,   101,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,     0,   100
};

static const yytype_int16 yycheck[] =
{
      19,    15,    36,    66,    55,    80,   118,    55,    10,    26,
       0,    13,    80,    49,    45,   161,    90,    45,    75,    75,
      47,    91,   168,    37,    37,   137,    91,   102,   103,   104,
      91,    47,    45,    91,   102,   103,   104,    50,    47,    75,
      91,    47,   154,    91,    75,    59,    48,    75,    47,    47,
      47,    68,    66,    49,    75,    69,    19,    20,    21,    22,
      49,    75,    25,    35,    74,    91,   141,    91,   143,    91,
       3,     4,     5,     6,     3,     4,     5,     6,    11,    49,
      47,   100,    11,    16,    91,    18,    47,    16,    75,    18,
      46,   203,    46,    46,    87,    74,   208,    91,    75,   174,
     163,    87,   116,    48,    75,    49,   174,    75,    45,    87,
      46,   223,    15,    46,     3,     4,     5,     6,    91,    48,
      75,    46,    11,    75,    75,    75,    75,    16,   142,    18,
     153,    91,    74,    74,    54,   138,   185,    -1,    -1,   158,
     157,    -1,    -1,    -1,   161,   220,    -1,   210,   162,   163,
     169,   168,   220,     3,     4,     5,     6,   176,    91,    48,
      -1,    11,    91,    -1,    -1,    -1,    16,    -1,    18,    -1,
      -1,    -1,    -1,     3,     4,     5,     6,    -1,    -1,    -1,
     214,    11,    -1,    -1,   201,   204,    16,    -1,    18,    -1,
      -1,    -1,    -1,   227,    -1,    -1,   210,   231,    -1,    -1,
      -1,    -1,    91,    -1,     0,    -1,   225,     3,     4,     5,
       6,     7,     8,     9,    -1,    11,    12,    -1,    14,    -1,
      16,    17,    18,    -1,    -1,    -1,    -1,    23,    24,    -1,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    91,    38,    39,    40,    41,    42,    43,    -1,    -1,
      -1,    -1,    -1,    49,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    91,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    -1,    -1,    -1,    72,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    88,    89,    90,    91,     3,     4,     5,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    -1,    16,
      17,    18,    -1,    -1,    -1,    -1,    23,    24,    -1,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      -1,    38,    39,    40,    41,    42,    43,    46,    -1,    -1,
      -1,    48,    49,    -1,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    68,
      69,    70,    71,    -1,    73,    72,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    88,    89,    90,    91,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    -1,    16,    17,
      18,    -1,    -1,    -1,    -1,    23,    24,    -1,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    -1,
      38,    39,    40,    41,    42,    43,    46,    -1,    -1,    -1,
      48,    49,    -1,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    68,    69,
      70,    71,    -1,    73,    72,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      88,    89,    90,    91,     3,     4,     5,     6,     7,     8,
       9,    -1,    11,    12,    -1,    14,    -1,    16,    17,    18,
      -1,    -1,    -1,    -1,    23,    24,    -1,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    -1,    38,
      39,    40,    41,    42,    43,    46,    -1,    -1,    -1,    48,
      49,    -1,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    68,    69,    70,
      71,    -1,    73,    72,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    88,
      89,    90,    91,     3,     4,     5,     6,     7,     8,     9,
      -1,    11,    12,    -1,    14,    -1,    16,    17,    18,    -1,
      -1,    -1,    -1,    23,    24,    -1,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    -1,    38,    39,
      40,    41,    42,    43,    46,    -1,    -1,    -1,    48,    49,
      -1,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,    69,    70,    71,
      -1,    73,    72,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    88,    89,
      90,    91,     3,     4,     5,     6,     7,     8,     9,    -1,
      11,    12,    -1,    14,    -1,    16,    17,    18,    -1,    -1,
      -1,    -1,    23,    24,    -1,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    -1,    38,    39,    40,
      41,    42,    43,    -1,     8,    -1,    -1,    -1,    49,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    23,
      24,    -1,    -1,    27,    28,     8,    -1,    -1,    -1,    -1,
      -1,    72,    36,    -1,    38,    39,    40,    41,    42,    43,
      23,    24,    -1,     8,    27,    28,    -1,    88,    89,    90,
      91,    -1,    -1,    36,    -1,    38,    39,    40,    41,    42,
      43,    -1,    27,    28,    -1,    -1,    -1,    -1,    72,     8,
      -1,    36,    -1,    38,    39,    40,    41,    42,    43,    -1,
      -1,    -1,    47,    -1,    88,    89,    90,    91,    27,    28,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    36,    -1,    38,
      39,    40,    41,    42,    43,    88,    89,    90,    91,    74,
      -1,    -1,    -1,    -1,    -1,    -1,    55,    -1,    44,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    91,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    68,    69,    70,    71,    -1,    73,    -1,    -1,
      -1,    -1,    91,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    68,    69,
      70,    71,    -1,    73,    -1,    75,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    68,    69,    70,    71,    -1,    73
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    94,   112,     0,     3,     4,     5,     6,     7,     8,
       9,    11,    12,    14,    16,    17,    18,    23,    24,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      38,    39,    40,    41,    42,    43,    49,    72,    88,    89,
      90,    91,    95,    96,    97,    99,   100,   102,   103,   108,
     113,   118,   119,   120,   122,   123,    90,    75,    75,    47,
      91,    91,   111,   113,    91,    95,    47,    91,    47,    47,
      16,    18,    91,   122,    91,    47,   112,   113,    74,   121,
      47,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,    69,    70,    71,
      73,    75,   115,   116,   117,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,   114,    55,    91,   102,
      19,    20,    21,    22,    25,   113,    49,    75,    49,    35,
     111,    74,    91,   122,   113,    91,    91,    91,    49,   113,
      48,    37,    45,    50,   105,   107,   118,   119,    95,   118,
     118,   118,   113,    55,    91,   101,   121,    47,    46,    91,
     110,   109,    47,    75,    46,    46,    46,   121,   109,    46,
      91,   119,   113,   119,    87,    46,    74,   101,   121,    75,
      75,   104,   106,   122,    95,    87,    48,    48,   100,   122,
     113,   111,    75,    75,    49,    75,    48,    95,    44,   118,
      95,    87,    46,    91,    15,   110,    75,    75,    91,    46,
      75,    98,    75,   122,    49,    75,   121,    95,    75,   111,
      10,    13,    48,    91,   112,    46,   118,    74,   121,    48,
      95,    74,   112,   112
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    93,    94,    95,    95,    95,    95,    95,    95,    95,
      96,    97,    97,    97,    98,    98,    98,    99,    99,    99,
     100,   100,   101,   101,   102,   102,   102,   102,   102,   102,
     102,   102,   102,   102,   102,   103,   103,   104,   104,   105,
     105,   106,   106,   107,   107,   108,   108,   108,   108,   108,
     108,   108,   108,   108,   108,   108,   108,   109,   109,   110,
     110,   111,   111,   112,   112,   113,   113,   113,   113,   113,
     113,   113,   114,   114,   114,   114,   114,   114,   114,   114,
     114,   114,   114,   115,   115,   115,   115,   115,   115,   115,
     115,   115,   115,   115,   116,   116,   116,   116,   116,   116,
     117,   117,   118,   118,   118,   118,   118,   118,   119,   119,
     119,   120,   120,   121,   121,   122,   122,   122,   122,   122,
     122,   122,   122,   123,   123,   123,   123,   123,   123
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     1,     1,     1,     1,     1,     2,     1,
       3,     5,     7,     7,     5,     4,     0,     5,     9,     7,
       4,     4,     2,     2,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     8,     6,     5,     3,     3,
       1,     1,     0,     1,     0,     3,     2,     2,     5,     2,
       6,     6,     6,     3,     2,     5,     5,     2,     0,     3,
       1,     1,     0,     2,     0,     3,     3,     3,     3,     2,
       5,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     4,     1,     2,     4,
       4,     1,     1,     4,     0,     2,     2,     2,     2,     2,
       2,     2,     1,     1,     1,     1,     1,     1,     0
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
#line 122 "translate.y"
               {
    executeProgram();
}
#line 1819 "y.tab.c"
    break;

  case 10:
#line 135 "translate.y"
                                    {
    printf("Block statement\n");
}
#line 1827 "y.tab.c"
    break;

  case 11:
#line 139 "translate.y"
                                                 {
    printf("If statement\n");
}
#line 1835 "y.tab.c"
    break;

  case 12:
#line 142 "translate.y"
                                                    {
    printf("If-else statement\n");
}
#line 1843 "y.tab.c"
    break;

  case 13:
#line 145 "translate.y"
                                                                         {
    printf("Switch statement\n");
}
#line 1851 "y.tab.c"
    break;

  case 17:
#line 155 "translate.y"
                                                   {
    printf("While loop\n");
}
#line 1859 "y.tab.c"
    break;

  case 18:
#line 158 "translate.y"
                                                                                    {
    printf("For loop\n");
}
#line 1867 "y.tab.c"
    break;

  case 19:
#line 161 "translate.y"
                                                           {
    printf("Do-while loop\n");
}
#line 1875 "y.tab.c"
    break;

  case 20:
#line 166 "translate.y"
                                       {
    printf("Variable declaration\n");
}
#line 1883 "y.tab.c"
    break;

  case 21:
#line 169 "translate.y"
                                  {
    printf("Pointer declaration\n");
}
#line 1891 "y.tab.c"
    break;

  case 35:
#line 191 "translate.y"
                                                                                  {
    printf("Function definition\n");
}
#line 1899 "y.tab.c"
    break;

  case 36:
#line 194 "translate.y"
                                                                {
    printf("Function declaration\n");
}
#line 1907 "y.tab.c"
    break;

  case 45:
#line 215 "translate.y"
                                    {
    printf("Return statement\n");
}
#line 1915 "y.tab.c"
    break;

  case 46:
#line 218 "translate.y"
                       {
    printf("Break statement\n");
}
#line 1923 "y.tab.c"
    break;

  case 47:
#line 221 "translate.y"
                          {
    printf("Continue statement\n");
}
#line 1931 "y.tab.c"
    break;

  case 48:
#line 224 "translate.y"
                                                {
    printf("Typedef declaration\n");
}
#line 1939 "y.tab.c"
    break;

  case 49:
#line 227 "translate.y"
                     {
    printf("Include directive\n");
}
#line 1947 "y.tab.c"
    break;

  case 50:
#line 230 "translate.y"
                                                                  {
    printf("Struct definition\n");
}
#line 1955 "y.tab.c"
    break;

  case 51:
#line 233 "translate.y"
                                                               {
    printf("Enum definition\n");
}
#line 1963 "y.tab.c"
    break;

  case 52:
#line 236 "translate.y"
                                                                 {
    printf("Union definition\n");
}
#line 1971 "y.tab.c"
    break;

  case 53:
#line 239 "translate.y"
                            {
    printf("Goto definition\n");
}
#line 1979 "y.tab.c"
    break;

  case 54:
#line 242 "translate.y"
                       {
    printf("Label definition\n");
}
#line 1987 "y.tab.c"
    break;

  case 55:
#line 245 "translate.y"
                                                    {
    printf("Sizeof definition\n");
}
#line 1995 "y.tab.c"
    break;

  case 56:
#line 248 "translate.y"
                                                          {
    printf("Sizeof definition\n");
}
#line 2003 "y.tab.c"
    break;

  case 58:
#line 254 "translate.y"
                        {printf("empty varlist\n");}
#line 2009 "y.tab.c"
    break;

  case 65:
#line 269 "translate.y"
                       {
    printf("Assignment expression\n");
}
#line 2017 "y.tab.c"
    break;

  case 66:
#line 272 "translate.y"
                   {
    printf("Binary operation expression\n");
}
#line 2025 "y.tab.c"
    break;

  case 67:
#line 275 "translate.y"
                    {
    printf("Relational operation expression\n");
}
#line 2033 "y.tab.c"
    break;

  case 68:
#line 278 "translate.y"
                     {
    printf("Conditional operation expression\n");
}
#line 2041 "y.tab.c"
    break;

  case 69:
#line 281 "translate.y"
                       {
    printf("Logical NOT expression\n");
}
#line 2049 "y.tab.c"
    break;

  case 70:
#line 284 "translate.y"
                                 {
    printf("Ternary conditional expression\n");
}
#line 2057 "y.tab.c"
    break;

  case 71:
#line 287 "translate.y"
           {
    printf("Term expression\n");
}
#line 2065 "y.tab.c"
    break;

  case 102:
#line 330 "translate.y"
              {
    printf("Integer term\n");
}
#line 2073 "y.tab.c"
    break;

  case 103:
#line 333 "translate.y"
              {
    printf("Decimal term\n");
}
#line 2081 "y.tab.c"
    break;

  case 104:
#line 336 "translate.y"
             {
    printf("String term\n");
}
#line 2089 "y.tab.c"
    break;

  case 105:
#line 339 "translate.y"
              {
    printf("boolean term\n");
}
#line 2097 "y.tab.c"
    break;

  case 106:
#line 342 "translate.y"
                                                {
    printf("Function call term 2\n");
}
#line 2105 "y.tab.c"
    break;

  case 107:
#line 345 "translate.y"
           {
    printf("term -> attr\n");
}
#line 2113 "y.tab.c"
    break;

  case 108:
#line 350 "translate.y"
                        {
    printf("Identifier attr 1\n");
}
#line 2121 "y.tab.c"
    break;

  case 109:
#line 353 "translate.y"
                                 {
    printf("Nested identifier attr\n");
}
#line 2129 "y.tab.c"
    break;

  case 110:
#line 356 "translate.y"
                                     {
    printf("Dereferenced identifier attr\n");
}
#line 2137 "y.tab.c"
    break;

  case 111:
#line 361 "translate.y"
              {
    printf("True boolean term\n");
}
#line 2145 "y.tab.c"
    break;

  case 112:
#line 364 "translate.y"
            {
    printf("False boolean term\n");
}
#line 2153 "y.tab.c"
    break;


#line 2157 "y.tab.c"

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
#line 391 "translate.y"


void executeProgram() {
    printf("Program execution started\n");
}

int main(void) {
    yyparse();
    return 0;
}
