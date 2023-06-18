/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
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
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

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
void executeProgram();

SymbolTable *st;
FILE *prod;

void blockOpen();
void blockClose();
void addId(char *id, Enumtypes type);



#line 96 "translate.tab.c"

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

#include "translate.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_UNSIGNED = 3,                   /* UNSIGNED  */
  YYSYMBOL_SIGNED = 4,                     /* SIGNED  */
  YYSYMBOL_SHORT = 5,                      /* SHORT  */
  YYSYMBOL_LONG = 6,                       /* LONG  */
  YYSYMBOL_INCLUDE = 7,                    /* INCLUDE  */
  YYSYMBOL_MAIN = 8,                       /* MAIN  */
  YYSYMBOL_BREAK = 9,                      /* BREAK  */
  YYSYMBOL_CASE = 10,                      /* CASE  */
  YYSYMBOL_CONST = 11,                     /* CONST  */
  YYSYMBOL_CONTINUE = 12,                  /* CONTINUE  */
  YYSYMBOL_DEFAULT = 13,                   /* DEFAULT  */
  YYSYMBOL_IF = 14,                        /* IF  */
  YYSYMBOL_ELSE = 15,                      /* ELSE  */
  YYSYMBOL_ENUM = 16,                      /* ENUM  */
  YYSYMBOL_RETURN = 17,                    /* RETURN  */
  YYSYMBOL_STRUCT = 18,                    /* STRUCT  */
  YYSYMBOL_INT = 19,                       /* INT  */
  YYSYMBOL_FLOAT = 20,                     /* FLOAT  */
  YYSYMBOL_DOUBLE = 21,                    /* DOUBLE  */
  YYSYMBOL_BOOL = 22,                      /* BOOL  */
  YYSYMBOL_TRUE = 23,                      /* TRUE  */
  YYSYMBOL_FALSE = 24,                     /* FALSE  */
  YYSYMBOL_CHAR = 25,                      /* CHAR  */
  YYSYMBOL_DO = 26,                        /* DO  */
  YYSYMBOL_PRINTF = 27,                    /* PRINTF  */
  YYSYMBOL_SCANF = 28,                     /* SCANF  */
  YYSYMBOL_FOR = 29,                       /* FOR  */
  YYSYMBOL_GOTO = 30,                      /* GOTO  */
  YYSYMBOL_SIZEOF = 31,                    /* SIZEOF  */
  YYSYMBOL_SWITCH = 32,                    /* SWITCH  */
  YYSYMBOL_TYPEDEF = 33,                   /* TYPEDEF  */
  YYSYMBOL_UNION = 34,                     /* UNION  */
  YYSYMBOL_WHILE = 35,                     /* WHILE  */
  YYSYMBOL_FREE = 36,                      /* FREE  */
  YYSYMBOL_POINTER = 37,                   /* POINTER  */
  YYSYMBOL_SLICE = 38,                     /* SLICE  */
  YYSYMBOL_SOME = 39,                      /* SOME  */
  YYSYMBOL_REDUCE = 40,                    /* REDUCE  */
  YYSYMBOL_FILTER = 41,                    /* FILTER  */
  YYSYMBOL_MAP = 42,                       /* MAP  */
  YYSYMBOL_SORT = 43,                      /* SORT  */
  YYSYMBOL_CLOSE_BRACKET = 44,             /* CLOSE_BRACKET  */
  YYSYMBOL_OPEN_BRACKET = 45,              /* OPEN_BRACKET  */
  YYSYMBOL_CLOSE_PAREN = 46,               /* CLOSE_PAREN  */
  YYSYMBOL_OPEN_PAREN = 47,                /* OPEN_PAREN  */
  YYSYMBOL_BLOCK_CLOSE = 48,               /* BLOCK_CLOSE  */
  YYSYMBOL_BLOCK_OPEN = 49,                /* BLOCK_OPEN  */
  YYSYMBOL_DOT = 50,                       /* DOT  */
  YYSYMBOL_INCREMENT = 51,                 /* INCREMENT  */
  YYSYMBOL_DECREMENT = 52,                 /* DECREMENT  */
  YYSYMBOL_ADD = 53,                       /* ADD  */
  YYSYMBOL_SUB = 54,                       /* SUB  */
  YYSYMBOL_MUL = 55,                       /* MUL  */
  YYSYMBOL_DIV = 56,                       /* DIV  */
  YYSYMBOL_BITWISE_AND = 57,               /* BITWISE_AND  */
  YYSYMBOL_BITWISE_OR = 58,                /* BITWISE_OR  */
  YYSYMBOL_BITWISE_NOT = 59,               /* BITWISE_NOT  */
  YYSYMBOL_MOD = 60,                       /* MOD  */
  YYSYMBOL_LEFT_SHIFT = 61,                /* LEFT_SHIFT  */
  YYSYMBOL_RIGHT_SHIFT = 62,               /* RIGHT_SHIFT  */
  YYSYMBOL_LT = 63,                        /* LT  */
  YYSYMBOL_GT = 64,                        /* GT  */
  YYSYMBOL_LE = 65,                        /* LE  */
  YYSYMBOL_GE = 66,                        /* GE  */
  YYSYMBOL_EQ = 67,                        /* EQ  */
  YYSYMBOL_NE = 68,                        /* NE  */
  YYSYMBOL_BITWISE_XOR = 69,               /* BITWISE_XOR  */
  YYSYMBOL_LOGICAL_AND = 70,               /* LOGICAL_AND  */
  YYSYMBOL_LOGICAL_OR = 71,                /* LOGICAL_OR  */
  YYSYMBOL_LOGICAL_NOT = 72,               /* LOGICAL_NOT  */
  YYSYMBOL_QUEST = 73,                     /* QUEST  */
  YYSYMBOL_COLON = 74,                     /* COLON  */
  YYSYMBOL_SEMI_COLON = 75,                /* SEMI_COLON  */
  YYSYMBOL_ASSIGN = 76,                    /* ASSIGN  */
  YYSYMBOL_ADD_ASSIGN = 77,                /* ADD_ASSIGN  */
  YYSYMBOL_SUB_ASSIGN = 78,                /* SUB_ASSIGN  */
  YYSYMBOL_MUL_ASSIGN = 79,                /* MUL_ASSIGN  */
  YYSYMBOL_DIV_ASSIGN = 80,                /* DIV_ASSIGN  */
  YYSYMBOL_MOD_ASSIGN = 81,                /* MOD_ASSIGN  */
  YYSYMBOL_LEFT_SHIFT_ASSIGN = 82,         /* LEFT_SHIFT_ASSIGN  */
  YYSYMBOL_RIGHT_SHIFT_ASSIGN = 83,        /* RIGHT_SHIFT_ASSIGN  */
  YYSYMBOL_BITWISE_AND_ASSIGN = 84,        /* BITWISE_AND_ASSIGN  */
  YYSYMBOL_BITWISE_OR_ASSIGN = 85,         /* BITWISE_OR_ASSIGN  */
  YYSYMBOL_BITWISE_XOR_ASSIGN = 86,        /* BITWISE_XOR_ASSIGN  */
  YYSYMBOL_COMMA = 87,                     /* COMMA  */
  YYSYMBOL_INTEGER = 88,                   /* INTEGER  */
  YYSYMBOL_DECIMAL = 89,                   /* DECIMAL  */
  YYSYMBOL_STRING = 90,                    /* STRING  */
  YYSYMBOL_IDENTIFIER = 91,                /* IDENTIFIER  */
  YYSYMBOL_COMMENTS = 92,                  /* COMMENTS  */
  YYSYMBOL_IFX = 93,                       /* IFX  */
  YYSYMBOL_UNARY = 94,                     /* UNARY  */
  YYSYMBOL_YYACCEPT = 95,                  /* $accept  */
  YYSYMBOL_program = 96,                   /* program  */
  YYSYMBOL_stmt = 97,                      /* stmt  */
  YYSYMBOL_block = 98,                     /* block  */
  YYSYMBOL_99_1 = 99,                      /* $@1  */
  YYSYMBOL_100_2 = 100,                    /* $@2  */
  YYSYMBOL_conditional = 101,              /* conditional  */
  YYSYMBOL_caselist = 102,                 /* caselist  */
  YYSYMBOL_repetition = 103,               /* repetition  */
  YYSYMBOL_var = 104,                      /* var  */
  YYSYMBOL_105_3 = 105,                    /* $@3  */
  YYSYMBOL_pointer = 106,                  /* pointer  */
  YYSYMBOL_funcid = 107,                   /* funcid  */
  YYSYMBOL_func = 108,                     /* func  */
  YYSYMBOL_typelist = 109,                 /* typelist  */
  YYSYMBOL_termlist = 110,                 /* termlist  */
  YYSYMBOL_opttypelist = 111,              /* opttypelist  */
  YYSYMBOL_opttermlist = 112,              /* opttermlist  */
  YYSYMBOL_commands = 113,                 /* commands  */
  YYSYMBOL_varlist = 114,                  /* varlist  */
  YYSYMBOL_idlist = 115,                   /* idlist  */
  YYSYMBOL_optexpr = 116,                  /* optexpr  */
  YYSYMBOL_stmts = 117,                    /* stmts  */
  YYSYMBOL_expr = 118,                     /* expr  */
  YYSYMBOL_assign = 119,                   /* assign  */
  YYSYMBOL_op = 120,                       /* op  */
  YYSYMBOL_rel = 121,                      /* rel  */
  YYSYMBOL_cond = 122,                     /* cond  */
  YYSYMBOL_term = 123,                     /* term  */
  YYSYMBOL_attr = 124,                     /* attr  */
  YYSYMBOL_boolean = 125,                  /* boolean  */
  YYSYMBOL_vector = 126,                   /* vector  */
  YYSYMBOL_type = 127,                     /* type  */
  YYSYMBOL_modifier = 128                  /* modifier  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




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

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
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
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
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

#if !defined yyoverflow

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
#endif /* !defined yyoverflow */

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

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   349


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

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

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "UNSIGNED", "SIGNED",
  "SHORT", "LONG", "INCLUDE", "MAIN", "BREAK", "CASE", "CONST", "CONTINUE",
  "DEFAULT", "IF", "ELSE", "ENUM", "RETURN", "STRUCT", "INT", "FLOAT",
  "DOUBLE", "BOOL", "TRUE", "FALSE", "CHAR", "DO", "PRINTF", "SCANF",
  "FOR", "GOTO", "SIZEOF", "SWITCH", "TYPEDEF", "UNION", "WHILE", "FREE",
  "POINTER", "SLICE", "SOME", "REDUCE", "FILTER", "MAP", "SORT",
  "CLOSE_BRACKET", "OPEN_BRACKET", "CLOSE_PAREN", "OPEN_PAREN",
  "BLOCK_CLOSE", "BLOCK_OPEN", "DOT", "INCREMENT", "DECREMENT", "ADD",
  "SUB", "MUL", "DIV", "BITWISE_AND", "BITWISE_OR", "BITWISE_NOT", "MOD",
  "LEFT_SHIFT", "RIGHT_SHIFT", "LT", "GT", "LE", "GE", "EQ", "NE",
  "BITWISE_XOR", "LOGICAL_AND", "LOGICAL_OR", "LOGICAL_NOT", "QUEST",
  "COLON", "SEMI_COLON", "ASSIGN", "ADD_ASSIGN", "SUB_ASSIGN",
  "MUL_ASSIGN", "DIV_ASSIGN", "MOD_ASSIGN", "LEFT_SHIFT_ASSIGN",
  "RIGHT_SHIFT_ASSIGN", "BITWISE_AND_ASSIGN", "BITWISE_OR_ASSIGN",
  "BITWISE_XOR_ASSIGN", "COMMA", "INTEGER", "DECIMAL", "STRING",
  "IDENTIFIER", "COMMENTS", "IFX", "UNARY", "$accept", "program", "stmt",
  "block", "$@1", "$@2", "conditional", "caselist", "repetition", "var",
  "$@3", "pointer", "funcid", "func", "typelist", "termlist",
  "opttypelist", "opttermlist", "commands", "varlist", "idlist", "optexpr",
  "stmts", "expr", "assign", "op", "rel", "cond", "term", "attr",
  "boolean", "vector", "type", "modifier", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

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
static const yytype_uint8 yydefgoto[] =
{
       0,     1,    42,    43,    44,   196,    45,   207,    46,    47,
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

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
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

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
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

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
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


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


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

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


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




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
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
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
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
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
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






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
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
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

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
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
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
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
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

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
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
  case 2: /* program: stmts  */
#line 151 "translate.y"
               {
    fprintf(prod, "program -> stmts\n");
    executeProgram();
}
#line 1468 "translate.tab.c"
    break;

  case 3: /* stmt: conditional  */
#line 157 "translate.y"
                  {
        fprintf(prod, "stmt -> conditional\n");
}
#line 1476 "translate.tab.c"
    break;

  case 4: /* stmt: repetition  */
#line 160 "translate.y"
                 {
        fprintf(prod, "stmt -> repetition\n");
}
#line 1484 "translate.tab.c"
    break;

  case 5: /* stmt: func  */
#line 163 "translate.y"
           {
        fprintf(prod, "stmt -> func\n");
}
#line 1492 "translate.tab.c"
    break;

  case 6: /* stmt: var  */
#line 166 "translate.y"
          {
        fprintf(prod, "stmt -> var\n");
}
#line 1500 "translate.tab.c"
    break;

  case 7: /* stmt: commands  */
#line 169 "translate.y"
               {
        fprintf(prod, "stmt -> commands\n");
}
#line 1508 "translate.tab.c"
    break;

  case 8: /* stmt: expr SEMI_COLON  */
#line 172 "translate.y"
                      {
        fprintf(prod, "stmt -> expr ;\n");
}
#line 1516 "translate.tab.c"
    break;

  case 9: /* stmt: block  */
#line 175 "translate.y"
            {
        fprintf(prod, "stmt -> block\n");
    }
#line 1524 "translate.tab.c"
    break;

  case 10: /* $@1: %empty  */
#line 180 "translate.y"
       {blockOpen();}
#line 1530 "translate.tab.c"
    break;

  case 11: /* $@2: %empty  */
#line 180 "translate.y"
                                                   {blockClose();}
#line 1536 "translate.tab.c"
    break;

  case 12: /* block: $@1 BLOCK_OPEN stmts BLOCK_CLOSE $@2  */
#line 180 "translate.y"
                                                                   {
        fprintf(prod, "block -> { stmts }\n");
}
#line 1544 "translate.tab.c"
    break;

  case 13: /* conditional: IF OPEN_PAREN expr CLOSE_PAREN stmt  */
#line 184 "translate.y"
                                                           {
    fprintf(prod, "conditional: IF ( expr ) stmt\n");
}
#line 1552 "translate.tab.c"
    break;

  case 14: /* conditional: IF OPEN_PAREN expr CLOSE_PAREN stmt ELSE stmt  */
#line 187 "translate.y"
                                                    {
    fprintf(prod, "conditional: IF ( expr ) stmt ELSE stmt\n");
}
#line 1560 "translate.tab.c"
    break;

  case 15: /* conditional: SWITCH OPEN_PAREN expr CLOSE_PAREN BLOCK_OPEN caselist BLOCK_CLOSE  */
#line 190 "translate.y"
                                                                         {
    fprintf(prod, "conditional: SWITCH ( expr ) { caselist }\n");
}
#line 1568 "translate.tab.c"
    break;

  case 16: /* caselist: caselist CASE term COLON stmts  */
#line 195 "translate.y"
                                            { fprintf(prod, "caselist -> caselist CASE term : stmts\n"); }
#line 1574 "translate.tab.c"
    break;

  case 17: /* caselist: caselist DEFAULT COLON stmts  */
#line 196 "translate.y"
                                            { fprintf(prod, "caselist -> caselist DEFAULT term : stmts\n"); }
#line 1580 "translate.tab.c"
    break;

  case 18: /* caselist: %empty  */
#line 197 "translate.y"
                                            { fprintf(prod, "caselist -> EPS\n"); }
#line 1586 "translate.tab.c"
    break;

  case 19: /* repetition: WHILE OPEN_PAREN expr CLOSE_PAREN stmt  */
#line 200 "translate.y"
                                                   {
    fprintf(prod, "repetition -> WHILE ( expr ) stmt\n");
}
#line 1594 "translate.tab.c"
    break;

  case 20: /* repetition: FOR OPEN_PAREN optexpr SEMI_COLON optexpr SEMI_COLON optexpr CLOSE_PAREN stmt  */
#line 203 "translate.y"
                                                                                    {
    fprintf(prod, "repetition -> FOR ( optexpr ; optexpr ; optexpr ) stmt\n");
}
#line 1602 "translate.tab.c"
    break;

  case 21: /* repetition: DO stmt WHILE OPEN_PAREN expr CLOSE_PAREN SEMI_COLON  */
#line 206 "translate.y"
                                                           {
    fprintf(prod, "repetition -> DO stmt WHILE ( expr ) ;\n");
}
#line 1610 "translate.tab.c"
    break;

  case 22: /* $@3: %empty  */
#line 211 "translate.y"
                     {addId((yyvsp[0].string), (yyvsp[-1].typeValue));}
#line 1616 "translate.tab.c"
    break;

  case 23: /* var: type IDENTIFIER $@3 vector SEMI_COLON  */
#line 211 "translate.y"
                                                         {
    fprintf(prod, "var -> type ID vector ;\n");
}
#line 1624 "translate.tab.c"
    break;

  case 24: /* var: type MUL pointer SEMI_COLON  */
#line 214 "translate.y"
                                  {
    fprintf(prod, "var -> type * pointer ;\n");
}
#line 1632 "translate.tab.c"
    break;

  case 25: /* pointer: IDENTIFIER vector  */
#line 219 "translate.y"
                           {
        fprintf(prod, "pointer -> ID vector\n");
    }
#line 1640 "translate.tab.c"
    break;

  case 26: /* pointer: MUL pointer  */
#line 222 "translate.y"
                      {
        fprintf(prod, "pointer -> * pointer\n");
    }
#line 1648 "translate.tab.c"
    break;

  case 27: /* funcid: IDENTIFIER  */
#line 227 "translate.y"
                    { fprintf(prod, "funcid -> ID\n"); }
#line 1654 "translate.tab.c"
    break;

  case 28: /* funcid: MAIN  */
#line 228 "translate.y"
                    { fprintf(prod, "funcid -> MAIN\n"); }
#line 1660 "translate.tab.c"
    break;

  case 29: /* funcid: PRINTF  */
#line 229 "translate.y"
                    { fprintf(prod, "funcid -> PRINTF\n"); }
#line 1666 "translate.tab.c"
    break;

  case 30: /* funcid: SCANF  */
#line 230 "translate.y"
                    { fprintf(prod, "funcid -> SCANF\n"); }
#line 1672 "translate.tab.c"
    break;

  case 31: /* funcid: SLICE  */
#line 231 "translate.y"
                    { fprintf(prod, "funcid -> SLICE\n"); }
#line 1678 "translate.tab.c"
    break;

  case 32: /* funcid: SOME  */
#line 232 "translate.y"
                    { fprintf(prod, "funcid -> SOME\n"); }
#line 1684 "translate.tab.c"
    break;

  case 33: /* funcid: REDUCE  */
#line 233 "translate.y"
                    { fprintf(prod, "funcid -> REDUCE\n"); }
#line 1690 "translate.tab.c"
    break;

  case 34: /* funcid: FILTER  */
#line 234 "translate.y"
                    { fprintf(prod, "funcid -> FILTER\n"); }
#line 1696 "translate.tab.c"
    break;

  case 35: /* funcid: MAP  */
#line 235 "translate.y"
                    { fprintf(prod, "funcid -> MAP\n"); }
#line 1702 "translate.tab.c"
    break;

  case 36: /* funcid: SORT  */
#line 236 "translate.y"
                    { fprintf(prod, "funcid -> SORT\n"); }
#line 1708 "translate.tab.c"
    break;

  case 37: /* funcid: FREE  */
#line 237 "translate.y"
                    { fprintf(prod, "funcid -> FREE\n"); }
#line 1714 "translate.tab.c"
    break;

  case 38: /* func: type funcid OPEN_PAREN opttypelist CLOSE_PAREN block  */
#line 240 "translate.y"
                                                           {
    fprintf(prod, "func -> type funcid ( opttypelist ) { stmts }\n");
    
}
#line 1723 "translate.tab.c"
    break;

  case 39: /* func: type funcid OPEN_PAREN opttypelist CLOSE_PAREN SEMI_COLON  */
#line 244 "translate.y"
                                                                {
    fprintf(prod, "func -> type funcid ( opttypelist ) ;\n");
}
#line 1731 "translate.tab.c"
    break;

  case 40: /* typelist: typelist COMMA type IDENTIFIER vector  */
#line 249 "translate.y"
                                                {
    fprintf(prod, "typelist -> typelist , type ID\n");
}
#line 1739 "translate.tab.c"
    break;

  case 41: /* typelist: type IDENTIFIER vector  */
#line 252 "translate.y"
                             {
        fprintf(prod, "typelist -> type ID vector\n");
    }
#line 1747 "translate.tab.c"
    break;

  case 42: /* termlist: termlist COMMA term  */
#line 257 "translate.y"
                              {
    fprintf(prod, "termlist -> termlist , term\n");
}
#line 1755 "translate.tab.c"
    break;

  case 43: /* termlist: term  */
#line 260 "translate.y"
           {
        fprintf(prod, "termlist -> term\n");
    }
#line 1763 "translate.tab.c"
    break;

  case 44: /* opttypelist: typelist  */
#line 265 "translate.y"
                        { fprintf(prod, "opttypelist -> typelist\n"); }
#line 1769 "translate.tab.c"
    break;

  case 45: /* opttypelist: %empty  */
#line 266 "translate.y"
                        { fprintf(prod, "opttypelist -> EPS\n"); }
#line 1775 "translate.tab.c"
    break;

  case 46: /* opttermlist: termlist  */
#line 269 "translate.y"
                        { fprintf(prod, "opttermlist -> termlist\n"); }
#line 1781 "translate.tab.c"
    break;

  case 47: /* opttermlist: %empty  */
#line 270 "translate.y"
                        { fprintf(prod, "opttermlist -> EPS"); }
#line 1787 "translate.tab.c"
    break;

  case 48: /* commands: RETURN optexpr SEMI_COLON  */
#line 274 "translate.y"
                              {
    fprintf(prod, "commands -> RETURN optexpr ;\n");
}
#line 1795 "translate.tab.c"
    break;

  case 49: /* commands: BREAK SEMI_COLON  */
#line 277 "translate.y"
                       {
    fprintf(prod, "commands -> BREAK ;\n");
}
#line 1803 "translate.tab.c"
    break;

  case 50: /* commands: CONTINUE SEMI_COLON  */
#line 280 "translate.y"
                          {
    fprintf(prod, "commands -> continue ;\n");
}
#line 1811 "translate.tab.c"
    break;

  case 51: /* commands: TYPEDEF type IDENTIFIER vector SEMI_COLON  */
#line 283 "translate.y"
                                                {
    fprintf(prod, "commands -> TYPEDEF type ID vector ;\n");
}
#line 1819 "translate.tab.c"
    break;

  case 52: /* commands: INCLUDE STRING  */
#line 286 "translate.y"
                     {
    fprintf(prod, "commands -> INCLUDE STRING\n");
}
#line 1827 "translate.tab.c"
    break;

  case 53: /* commands: STRUCT IDENTIFIER BLOCK_OPEN varlist BLOCK_CLOSE  */
#line 289 "translate.y"
                                                       {
    fprintf(prod, "commands -> STRUCT ID ( varlist )\n");
}
#line 1835 "translate.tab.c"
    break;

  case 54: /* commands: ENUM IDENTIFIER BLOCK_OPEN idlist BLOCK_CLOSE  */
#line 292 "translate.y"
                                                    {
    fprintf(prod, "commands -> ENUM ID ( idlist )\n");
}
#line 1843 "translate.tab.c"
    break;

  case 55: /* commands: UNION IDENTIFIER BLOCK_OPEN varlist BLOCK_CLOSE  */
#line 295 "translate.y"
                                                      {
    fprintf(prod, "commands -> UNION ID ( varlist )\n");
}
#line 1851 "translate.tab.c"
    break;

  case 56: /* commands: GOTO IDENTIFIER COLON  */
#line 298 "translate.y"
                            {
    fprintf(prod, "commands -> GOTO ID :\n");
}
#line 1859 "translate.tab.c"
    break;

  case 57: /* commands: IDENTIFIER COLON  */
#line 301 "translate.y"
                       {
    fprintf(prod, "commands -> IDENTIFIER :\n");
}
#line 1867 "translate.tab.c"
    break;

  case 58: /* commands: SIZEOF OPEN_PAREN type CLOSE_PAREN SEMI_COLON  */
#line 304 "translate.y"
                                                    {
    fprintf(prod, "commands -> SIZEOF ( type ) ;\n");
}
#line 1875 "translate.tab.c"
    break;

  case 59: /* varlist: varlist var  */
#line 309 "translate.y"
                                { fprintf(prod, "varlist -> varlist var\n"); }
#line 1881 "translate.tab.c"
    break;

  case 60: /* varlist: %empty  */
#line 310 "translate.y"
                                { fprintf(prod, "varlist -> EPS\n"); }
#line 1887 "translate.tab.c"
    break;

  case 61: /* idlist: IDENTIFIER COMMA idlist  */
#line 313 "translate.y"
                                { fprintf(prod, "idlist -> ID , idlist\n"); }
#line 1893 "translate.tab.c"
    break;

  case 62: /* idlist: IDENTIFIER  */
#line 314 "translate.y"
                                { fprintf(prod, "idlist -> ID\n"); }
#line 1899 "translate.tab.c"
    break;

  case 63: /* optexpr: expr  */
#line 317 "translate.y"
                                    { fprintf(prod, "optexpr -> expr\n"); }
#line 1905 "translate.tab.c"
    break;

  case 64: /* optexpr: %empty  */
#line 318 "translate.y"
                                    { fprintf(prod, "optexpr -> EPS\n"); }
#line 1911 "translate.tab.c"
    break;

  case 65: /* stmts: stmts stmt  */
#line 321 "translate.y"
                                    { fprintf(prod, "stmts -> stmts stmt\n"); }
#line 1917 "translate.tab.c"
    break;

  case 66: /* stmts: %empty  */
#line 322 "translate.y"
                                    { fprintf(prod, "stmts -> EPS\n"); }
#line 1923 "translate.tab.c"
    break;

  case 67: /* expr: term op expr  */
#line 325 "translate.y"
                   { 
    fprintf(prod, "expr -> expr op term\n"); 
}
#line 1931 "translate.tab.c"
    break;

  case 68: /* expr: term rel expr  */
#line 328 "translate.y"
                    { 
    fprintf(prod, "expr -> expr rel term\n"); 
}
#line 1939 "translate.tab.c"
    break;

  case 69: /* expr: term cond expr  */
#line 331 "translate.y"
                     { 
    fprintf(prod, "expr -> expr cond term\n"); 
}
#line 1947 "translate.tab.c"
    break;

  case 70: /* expr: LOGICAL_NOT expr  */
#line 334 "translate.y"
                                   { 
    fprintf(prod, "expr -> ! expr\n"); 
}
#line 1955 "translate.tab.c"
    break;

  case 71: /* expr: term  */
#line 337 "translate.y"
           { 
    fprintf(prod, "expr -> term\n"); 
}
#line 1963 "translate.tab.c"
    break;

  case 72: /* expr: OPEN_PAREN expr CLOSE_PAREN  */
#line 340 "translate.y"
                                  { 
    fprintf(prod, "expr -> ( expr )\n"); 
}
#line 1971 "translate.tab.c"
    break;

  case 73: /* expr: attr assign expr  */
#line 343 "translate.y"
                       { 
    fprintf(prod, "expr -> attr assign expr\n"); 
}
#line 1979 "translate.tab.c"
    break;

  case 74: /* assign: ASSIGN  */
#line 348 "translate.y"
                                { fprintf(prod, "assign -> =\n"); }
#line 1985 "translate.tab.c"
    break;

  case 75: /* assign: ADD_ASSIGN  */
#line 349 "translate.y"
                                { fprintf(prod, "assign -> +=\n"); }
#line 1991 "translate.tab.c"
    break;

  case 76: /* assign: SUB_ASSIGN  */
#line 350 "translate.y"
                                { fprintf(prod, "assign -> -=\n"); }
#line 1997 "translate.tab.c"
    break;

  case 77: /* assign: MUL_ASSIGN  */
#line 351 "translate.y"
                                { fprintf(prod, "assign -> *=\n"); }
#line 2003 "translate.tab.c"
    break;

  case 78: /* assign: DIV_ASSIGN  */
#line 352 "translate.y"
                                { fprintf(prod, "assign -> /=\n"); }
#line 2009 "translate.tab.c"
    break;

  case 79: /* assign: MOD_ASSIGN  */
#line 353 "translate.y"
                                { fprintf(prod, "assign -> %%=\n"); }
#line 2015 "translate.tab.c"
    break;

  case 80: /* assign: LEFT_SHIFT_ASSIGN  */
#line 354 "translate.y"
                                { fprintf(prod, "assign -> <<=\n"); }
#line 2021 "translate.tab.c"
    break;

  case 81: /* assign: RIGHT_SHIFT_ASSIGN  */
#line 355 "translate.y"
                                { fprintf(prod, "assign -> >>=\n"); }
#line 2027 "translate.tab.c"
    break;

  case 82: /* assign: BITWISE_AND_ASSIGN  */
#line 356 "translate.y"
                                { fprintf(prod, "assign -> &=\n"); }
#line 2033 "translate.tab.c"
    break;

  case 83: /* assign: BITWISE_OR_ASSIGN  */
#line 357 "translate.y"
                                { fprintf(prod, "assign -> |=\n"); }
#line 2039 "translate.tab.c"
    break;

  case 84: /* assign: BITWISE_XOR_ASSIGN  */
#line 358 "translate.y"
                                { fprintf(prod, "assign -> ^=\n"); }
#line 2045 "translate.tab.c"
    break;

  case 85: /* op: ADD  */
#line 361 "translate.y"
                                { fprintf(prod, "op -> +\n"); }
#line 2051 "translate.tab.c"
    break;

  case 86: /* op: SUB  */
#line 362 "translate.y"
                                { fprintf(prod, "op -> -\n"); }
#line 2057 "translate.tab.c"
    break;

  case 87: /* op: MUL  */
#line 363 "translate.y"
                                { fprintf(prod, "op -> *\n"); }
#line 2063 "translate.tab.c"
    break;

  case 88: /* op: DIV  */
#line 364 "translate.y"
                                { fprintf(prod, "op -> /\n"); }
#line 2069 "translate.tab.c"
    break;

  case 89: /* op: MOD  */
#line 365 "translate.y"
                                { fprintf(prod, "op -> %%\n"); }
#line 2075 "translate.tab.c"
    break;

  case 90: /* op: BITWISE_AND  */
#line 366 "translate.y"
                                { fprintf(prod, "op -> &\n"); }
#line 2081 "translate.tab.c"
    break;

  case 91: /* op: BITWISE_OR  */
#line 367 "translate.y"
                                { fprintf(prod, "op -> |\n"); }
#line 2087 "translate.tab.c"
    break;

  case 92: /* op: BITWISE_NOT  */
#line 368 "translate.y"
                                { fprintf(prod, "op -> ~\n"); }
#line 2093 "translate.tab.c"
    break;

  case 93: /* op: LEFT_SHIFT  */
#line 369 "translate.y"
                                { fprintf(prod, "op -> <<\n"); }
#line 2099 "translate.tab.c"
    break;

  case 94: /* op: RIGHT_SHIFT  */
#line 370 "translate.y"
                                { fprintf(prod, "op -> >>\n"); }
#line 2105 "translate.tab.c"
    break;

  case 95: /* op: BITWISE_XOR  */
#line 371 "translate.y"
                                { fprintf(prod, "op -> ^\n"); }
#line 2111 "translate.tab.c"
    break;

  case 96: /* rel: EQ  */
#line 374 "translate.y"
                                { fprintf(prod, "rel -> ==\n"); }
#line 2117 "translate.tab.c"
    break;

  case 97: /* rel: NE  */
#line 375 "translate.y"
                                { fprintf(prod, "rel -> !=\n"); }
#line 2123 "translate.tab.c"
    break;

  case 98: /* rel: LT  */
#line 376 "translate.y"
                                { fprintf(prod, "rel -> <\n"); }
#line 2129 "translate.tab.c"
    break;

  case 99: /* rel: LE  */
#line 377 "translate.y"
                                { fprintf(prod, "rel -> <=\n"); }
#line 2135 "translate.tab.c"
    break;

  case 100: /* rel: GT  */
#line 378 "translate.y"
                                { fprintf(prod, "rel -> >\n"); }
#line 2141 "translate.tab.c"
    break;

  case 101: /* rel: GE  */
#line 379 "translate.y"
                                { fprintf(prod, "rel -> >=\n"); }
#line 2147 "translate.tab.c"
    break;

  case 102: /* cond: LOGICAL_AND  */
#line 382 "translate.y"
                                { fprintf(prod, "cond -> &&\n"); }
#line 2153 "translate.tab.c"
    break;

  case 103: /* cond: LOGICAL_OR  */
#line 383 "translate.y"
                                { fprintf(prod, "cond -> ||\n"); }
#line 2159 "translate.tab.c"
    break;

  case 104: /* term: INTEGER  */
#line 387 "translate.y"
            {
    fprintf(prod, "term -> INTEGER\n");
}
#line 2167 "translate.tab.c"
    break;

  case 105: /* term: DECIMAL  */
#line 390 "translate.y"
              {
    fprintf(prod, "term -> DECIMAL\n");
}
#line 2175 "translate.tab.c"
    break;

  case 106: /* term: STRING  */
#line 393 "translate.y"
             {
    fprintf(prod, "term -> STRING\n");
}
#line 2183 "translate.tab.c"
    break;

  case 107: /* term: boolean  */
#line 396 "translate.y"
              {
    fprintf(prod, "term -> boolean\n");
}
#line 2191 "translate.tab.c"
    break;

  case 108: /* term: funcid OPEN_PAREN opttermlist CLOSE_PAREN  */
#line 399 "translate.y"
                                                {
    fprintf(prod, "term -> funcid ( opttermlist )\n");
}
#line 2199 "translate.tab.c"
    break;

  case 109: /* term: attr  */
#line 402 "translate.y"
           {
    fprintf(prod, "term -> attr\n");
}
#line 2207 "translate.tab.c"
    break;

  case 110: /* attr: IDENTIFIER vector  */
#line 407 "translate.y"
                        {
    fprintf(prod, "attr -> ID vector\n");
}
#line 2215 "translate.tab.c"
    break;

  case 111: /* attr: IDENTIFIER vector DOT attr  */
#line 410 "translate.y"
                                 {
    fprintf(prod, "attr -> ID vector . attr\n");
}
#line 2223 "translate.tab.c"
    break;

  case 112: /* attr: IDENTIFIER vector POINTER attr  */
#line 413 "translate.y"
                                     {
    fprintf(prod, "attr -> ID vector POINTER attr\n");
}
#line 2231 "translate.tab.c"
    break;

  case 113: /* boolean: TRUE  */
#line 419 "translate.y"
         {
    fprintf(prod, "boolean -> TRUE\n");
}
#line 2239 "translate.tab.c"
    break;

  case 114: /* boolean: FALSE  */
#line 422 "translate.y"
            {
    fprintf(prod, "boolean -> FALSE\n");
}
#line 2247 "translate.tab.c"
    break;

  case 115: /* vector: vector OPEN_BRACKET expr CLOSE_BRACKET  */
#line 427 "translate.y"
                                               {
    fprintf(prod, "vector -> vector [ expr ]");
}
#line 2255 "translate.tab.c"
    break;

  case 116: /* vector: %empty  */
#line 430 "translate.y"
                {
        fprintf(prod, "vector -> EPS\n");
    }
#line 2263 "translate.tab.c"
    break;

  case 117: /* type: modifier INT  */
#line 435 "translate.y"
                                { fprintf(prod, "type -> INT\n"); (yyval.typeValue) = type_int; }
#line 2269 "translate.tab.c"
    break;

  case 118: /* type: modifier CHAR  */
#line 436 "translate.y"
                                { fprintf(prod, "type -> CHAR\n"); (yyval.typeValue) = type_char; }
#line 2275 "translate.tab.c"
    break;

  case 119: /* type: modifier FLOAT  */
#line 437 "translate.y"
                                { fprintf(prod, "type -> FLOAT\n"); (yyval.typeValue) = type_float; }
#line 2281 "translate.tab.c"
    break;

  case 120: /* type: modifier DOUBLE  */
#line 438 "translate.y"
                                { fprintf(prod, "type -> DOUBLE\n"); (yyval.typeValue) = type_double; }
#line 2287 "translate.tab.c"
    break;

  case 121: /* type: modifier BOOL  */
#line 439 "translate.y"
                                { fprintf(prod, "type -> BOOL\n"); (yyval.typeValue) = type_bool; }
#line 2293 "translate.tab.c"
    break;

  case 122: /* type: STRUCT IDENTIFIER  */
#line 440 "translate.y"
                                { fprintf(prod, "type -> STRUCT ID\n"); (yyval.typeValue) = type_struct; }
#line 2299 "translate.tab.c"
    break;

  case 123: /* type: ENUM IDENTIFIER  */
#line 441 "translate.y"
                                { fprintf(prod, "type -> ENUM ID\n"); (yyval.typeValue) = type_enum; }
#line 2305 "translate.tab.c"
    break;

  case 124: /* modifier: UNSIGNED  */
#line 444 "translate.y"
                                { fprintf(prod, "modifier -> UNSIGNED\n"); }
#line 2311 "translate.tab.c"
    break;

  case 125: /* modifier: SIGNED  */
#line 445 "translate.y"
                                { fprintf(prod, "modifier -> SIGNED\n"); }
#line 2317 "translate.tab.c"
    break;

  case 126: /* modifier: SHORT  */
#line 446 "translate.y"
                                { fprintf(prod, "modifier -> SHORT\n"); }
#line 2323 "translate.tab.c"
    break;

  case 127: /* modifier: LONG  */
#line 447 "translate.y"
                                { fprintf(prod, "modifier -> LONG\n"); }
#line 2329 "translate.tab.c"
    break;

  case 128: /* modifier: CONST  */
#line 448 "translate.y"
                                { fprintf(prod, "modifier -> CONST\n"); }
#line 2335 "translate.tab.c"
    break;

  case 129: /* modifier: %empty  */
#line 449 "translate.y"
                                { fprintf(prod, "modifier -> EPS\n"); }
#line 2341 "translate.tab.c"
    break;


#line 2345 "translate.tab.c"

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
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

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
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
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
  ++yynerrs;

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

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
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
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
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
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
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
