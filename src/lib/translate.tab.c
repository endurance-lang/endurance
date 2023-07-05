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

FILE *dot;
int nextLabel = 1;

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


#line 139 "translate.tab.c"

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
  YYSYMBOL_INCLUDE = 3,                    /* INCLUDE  */
  YYSYMBOL_MAIN = 4,                       /* MAIN  */
  YYSYMBOL_BREAK = 5,                      /* BREAK  */
  YYSYMBOL_CASE = 6,                       /* CASE  */
  YYSYMBOL_CONST = 7,                      /* CONST  */
  YYSYMBOL_CONTINUE = 8,                   /* CONTINUE  */
  YYSYMBOL_DEFAULT = 9,                    /* DEFAULT  */
  YYSYMBOL_IF = 10,                        /* IF  */
  YYSYMBOL_ELSE = 11,                      /* ELSE  */
  YYSYMBOL_ENUM = 12,                      /* ENUM  */
  YYSYMBOL_RETURN = 13,                    /* RETURN  */
  YYSYMBOL_STRUCT = 14,                    /* STRUCT  */
  YYSYMBOL_DO = 15,                        /* DO  */
  YYSYMBOL_PRINTF = 16,                    /* PRINTF  */
  YYSYMBOL_SCANF = 17,                     /* SCANF  */
  YYSYMBOL_FOR = 18,                       /* FOR  */
  YYSYMBOL_GOTO = 19,                      /* GOTO  */
  YYSYMBOL_SIZEOF = 20,                    /* SIZEOF  */
  YYSYMBOL_SWITCH = 21,                    /* SWITCH  */
  YYSYMBOL_TYPEDEF = 22,                   /* TYPEDEF  */
  YYSYMBOL_UNION = 23,                     /* UNION  */
  YYSYMBOL_WHILE = 24,                     /* WHILE  */
  YYSYMBOL_FREE = 25,                      /* FREE  */
  YYSYMBOL_POINTER = 26,                   /* POINTER  */
  YYSYMBOL_SLICE = 27,                     /* SLICE  */
  YYSYMBOL_SOME = 28,                      /* SOME  */
  YYSYMBOL_REDUCE = 29,                    /* REDUCE  */
  YYSYMBOL_FILTER = 30,                    /* FILTER  */
  YYSYMBOL_MAP = 31,                       /* MAP  */
  YYSYMBOL_SORT = 32,                      /* SORT  */
  YYSYMBOL_CLOSE_BRACKET = 33,             /* CLOSE_BRACKET  */
  YYSYMBOL_OPEN_BRACKET = 34,              /* OPEN_BRACKET  */
  YYSYMBOL_CLOSE_PAREN = 35,               /* CLOSE_PAREN  */
  YYSYMBOL_OPEN_PAREN = 36,                /* OPEN_PAREN  */
  YYSYMBOL_BLOCK_CLOSE = 37,               /* BLOCK_CLOSE  */
  YYSYMBOL_BLOCK_OPEN = 38,                /* BLOCK_OPEN  */
  YYSYMBOL_ADD = 39,                       /* ADD  */
  YYSYMBOL_SUB = 40,                       /* SUB  */
  YYSYMBOL_MUL = 41,                       /* MUL  */
  YYSYMBOL_DIV = 42,                       /* DIV  */
  YYSYMBOL_BITWISE_AND = 43,               /* BITWISE_AND  */
  YYSYMBOL_BITWISE_OR = 44,                /* BITWISE_OR  */
  YYSYMBOL_BITWISE_NOT = 45,               /* BITWISE_NOT  */
  YYSYMBOL_MOD = 46,                       /* MOD  */
  YYSYMBOL_LEFT_SHIFT = 47,                /* LEFT_SHIFT  */
  YYSYMBOL_RIGHT_SHIFT = 48,               /* RIGHT_SHIFT  */
  YYSYMBOL_LT = 49,                        /* LT  */
  YYSYMBOL_GT = 50,                        /* GT  */
  YYSYMBOL_LE = 51,                        /* LE  */
  YYSYMBOL_GE = 52,                        /* GE  */
  YYSYMBOL_EQ = 53,                        /* EQ  */
  YYSYMBOL_NE = 54,                        /* NE  */
  YYSYMBOL_BITWISE_XOR = 55,               /* BITWISE_XOR  */
  YYSYMBOL_LOGICAL_AND = 56,               /* LOGICAL_AND  */
  YYSYMBOL_LOGICAL_OR = 57,                /* LOGICAL_OR  */
  YYSYMBOL_LOGICAL_NOT = 58,               /* LOGICAL_NOT  */
  YYSYMBOL_COLON = 59,                     /* COLON  */
  YYSYMBOL_SEMI_COLON = 60,                /* SEMI_COLON  */
  YYSYMBOL_ASSIGN = 61,                    /* ASSIGN  */
  YYSYMBOL_COMMA = 62,                     /* COMMA  */
  YYSYMBOL_INVALID = 63,                   /* INVALID  */
  YYSYMBOL_UMINUS = 64,                    /* UMINUS  */
  YYSYMBOL_DOT = 65,                       /* DOT  */
  YYSYMBOL_DECIMAL = 66,                   /* DECIMAL  */
  YYSYMBOL_STRING = 67,                    /* STRING  */
  YYSYMBOL_IDENTIFIER = 68,                /* IDENTIFIER  */
  YYSYMBOL_INTEGER = 69,                   /* INTEGER  */
  YYSYMBOL_TRUE = 70,                      /* TRUE  */
  YYSYMBOL_FALSE = 71,                     /* FALSE  */
  YYSYMBOL_IFX = 72,                       /* IFX  */
  YYSYMBOL_UNARY = 73,                     /* UNARY  */
  YYSYMBOL_YYACCEPT = 74,                  /* $accept  */
  YYSYMBOL_program = 75,                   /* program  */
  YYSYMBOL_stmts = 76,                     /* stmts  */
  YYSYMBOL_stmt = 77,                      /* stmt  */
  YYSYMBOL_conditional = 78,               /* conditional  */
  YYSYMBOL_79_1 = 79,                      /* $@1  */
  YYSYMBOL_condexpr = 80,                  /* condexpr  */
  YYSYMBOL_repetition = 81,                /* repetition  */
  YYSYMBOL_82_2 = 82,                      /* $@2  */
  YYSYMBOL_83_3 = 83,                      /* $@3  */
  YYSYMBOL_84_4 = 84,                      /* $@4  */
  YYSYMBOL_85_5 = 85,                      /* $@5  */
  YYSYMBOL_86_6 = 86,                      /* $@6  */
  YYSYMBOL_repexpr = 87,                   /* repexpr  */
  YYSYMBOL_var = 88,                       /* var  */
  YYSYMBOL_func = 89,                      /* func  */
  YYSYMBOL_typelist = 90,                  /* typelist  */
  YYSYMBOL_exprlist = 91,                  /* exprlist  */
  YYSYMBOL_opttypelist = 92,               /* opttypelist  */
  YYSYMBOL_optexprlist = 93,               /* optexprlist  */
  YYSYMBOL_commands = 94,                  /* commands  */
  YYSYMBOL_varlist = 95,                   /* varlist  */
  YYSYMBOL_idlist = 96,                    /* idlist  */
  YYSYMBOL_optexpr = 97,                   /* optexpr  */
  YYSYMBOL_expr = 98,                      /* expr  */
  YYSYMBOL_term = 99,                      /* term  */
  YYSYMBOL_attr = 100,                     /* attr  */
  YYSYMBOL_const = 101,                    /* const  */
  YYSYMBOL_boolean = 102,                  /* boolean  */
  YYSYMBOL_exprvector = 103,               /* exprvector  */
  YYSYMBOL_constvector = 104               /* constvector  */
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
#define YYLAST   413

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  74
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  31
/* YYNRULES -- Number of rules.  */
#define YYNRULES  86
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  166

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   328


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
      65,    66,    67,    68,    69,    70,    71,    72,    73
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   117,   117,   124,   129,   138,   143,   148,   153,   159,
     164,   171,   188,   210,   210,   239,   254,   257,   254,   282,
     286,   290,   282,   328,   336,   355,   387,   399,   406,   421,
     432,   437,   446,   454,   466,   482,   496,   509,   523,   535,
     549,   565,   572,   581,   590,   599,   604,   613,   624,   635,
     646,   657,   665,   676,   687,   698,   709,   720,   731,   742,
     753,   765,   776,   787,   798,   809,   820,   833,   845,   856,
     865,   876,   880,   889,   904,   915,   926,   938,   948,   959,
     968,   977,   988,  1002,  1015,  1026,  1040
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
  "\"end of file\"", "error", "\"invalid token\"", "INCLUDE", "MAIN",
  "BREAK", "CASE", "CONST", "CONTINUE", "DEFAULT", "IF", "ELSE", "ENUM",
  "RETURN", "STRUCT", "DO", "PRINTF", "SCANF", "FOR", "GOTO", "SIZEOF",
  "SWITCH", "TYPEDEF", "UNION", "WHILE", "FREE", "POINTER", "SLICE",
  "SOME", "REDUCE", "FILTER", "MAP", "SORT", "CLOSE_BRACKET",
  "OPEN_BRACKET", "CLOSE_PAREN", "OPEN_PAREN", "BLOCK_CLOSE", "BLOCK_OPEN",
  "ADD", "SUB", "MUL", "DIV", "BITWISE_AND", "BITWISE_OR", "BITWISE_NOT",
  "MOD", "LEFT_SHIFT", "RIGHT_SHIFT", "LT", "GT", "LE", "GE", "EQ", "NE",
  "BITWISE_XOR", "LOGICAL_AND", "LOGICAL_OR", "LOGICAL_NOT", "COLON",
  "SEMI_COLON", "ASSIGN", "COMMA", "INVALID", "UMINUS", "DOT", "DECIMAL",
  "STRING", "IDENTIFIER", "INTEGER", "TRUE", "FALSE", "IFX", "UNARY",
  "$accept", "program", "stmts", "stmt", "conditional", "$@1", "condexpr",
  "repetition", "$@2", "$@3", "$@4", "$@5", "$@6", "repexpr", "var",
  "func", "typelist", "exprlist", "opttypelist", "optexprlist", "commands",
  "varlist", "idlist", "optexpr", "expr", "term", "attr", "const",
  "boolean", "exprvector", "constvector", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-118)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -118,    12,   155,  -118,   -52,   -42,   -36,   -11,   -51,   130,
     -37,    -4,   -35,   -34,  -118,   130,  -118,   130,   130,  -118,
    -118,   -20,  -118,  -118,  -118,  -118,  -118,  -118,   -18,  -118,
    -118,   236,  -118,   -22,  -118,  -118,   -17,  -118,  -118,   130,
      -1,   -29,     8,   258,     2,   130,  -118,     5,    38,   217,
      75,  -118,  -118,   130,   130,   -23,  -118,  -118,   130,   130,
     130,   130,   130,   130,   130,   130,   130,   130,   130,   130,
     130,   130,   130,   130,   130,   130,   130,  -118,     9,   130,
    -118,    46,   258,    14,  -118,  -118,  -118,    24,   130,  -118,
    -118,   194,    28,    51,   258,    22,    26,  -118,    30,    30,
      47,    47,   345,   312,    47,    47,    61,    61,   -19,   -19,
     -19,   -19,   361,   361,   329,   295,   277,    62,  -118,   258,
     155,    36,    67,   -27,    45,  -118,    73,   258,  -118,   130,
    -118,    76,    42,  -118,    52,    81,   107,    14,  -118,  -118,
      63,   130,  -118,   258,  -118,    88,    26,    87,  -118,  -118,
    -118,    71,   155,  -118,  -118,   155,  -118,  -118,   116,  -118,
     130,  -118,    92,  -118,   155,  -118
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       4,     0,     2,     1,     0,     0,     0,     0,     0,    46,
       0,     0,     0,     0,    16,     0,     4,     0,     0,    78,
      79,    84,    77,    81,    82,     3,     5,     6,     0,     7,
       9,     0,    69,    74,    72,    80,     0,    35,    36,     0,
       0,    84,     0,    45,     0,    46,    71,     0,     0,     0,
       0,    68,    67,     0,    33,    86,    75,     8,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    10,     0,     0,
      38,     0,    15,     0,    34,    42,    19,     0,     0,    66,
      11,     0,    32,     0,    29,     0,    31,    24,    47,    48,
      49,    50,    52,    53,    54,    51,    56,    57,    60,    61,
      62,    63,    58,    59,    55,    64,    65,    84,    76,    70,
       0,    44,     0,     0,     0,    37,     0,    23,    83,     0,
      73,     0,     0,    27,    30,     0,    12,     0,    40,    39,
       0,     0,    17,    28,    85,    86,     0,     0,    13,    43,
      41,     0,     0,    26,     4,     0,    20,    18,     0,    14,
      46,    25,     0,    21,     0,    22
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
    -118,  -118,   -15,  -117,  -118,  -118,  -118,  -118,  -118,  -118,
    -118,  -118,  -118,    -6,   -77,  -118,  -118,  -118,  -118,  -118,
    -118,  -118,     0,   -43,    -9,  -118,    69,  -118,  -118,  -118,
    -118
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     1,     2,    25,    26,   155,    81,    27,    48,   152,
     124,   160,   164,   126,    28,    29,   134,    92,   135,    93,
      30,   123,   122,    42,    31,    32,    33,    34,    35,    56,
      97
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      43,    50,    86,   136,    78,    53,    49,    54,    51,    52,
     139,    95,     3,    96,    53,    36,    54,    40,    37,   133,
      58,    59,    60,    61,    38,    39,    64,    65,    66,    67,
      82,    44,    45,    46,    47,   157,    43,    83,   159,    79,
      85,   132,    57,    80,    91,    94,   140,   165,    55,    98,
      99,   100,   101,   102,   103,   104,   105,   106,   107,   108,
     109,   110,   111,   112,   113,   114,   115,   116,    84,   153,
     119,    60,    61,    87,    88,    64,    65,   117,     4,   127,
       5,   120,   121,     6,   125,     7,   130,     8,     9,    10,
     129,   131,    64,    11,   132,    12,    53,    13,   137,    14,
      58,    59,    60,    61,   138,   141,    64,    65,   142,   144,
     145,    15,    90,    16,   146,    17,   147,   162,   148,     4,
     143,     5,    95,   150,     6,   154,     7,   163,     8,     9,
      10,   156,   127,    18,    11,   151,    12,   149,    13,   158,
      14,    19,    20,    21,    22,    23,    24,   118,     0,     0,
      12,    43,    15,   161,    16,     0,    17,     0,     4,     0,
       5,     0,     0,     6,     0,     7,    15,     8,     9,    10,
      17,     0,     0,    11,    18,    12,     0,    13,     0,    14,
       0,     0,    19,    20,    21,    22,    23,    24,    18,     0,
       0,    15,     0,    16,     0,    17,    19,    20,    41,    22,
      23,    24,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    18,     0,     0,     0,     0,     0,     0,
       0,    19,    20,    21,    22,    23,    24,   128,     0,     0,
       0,     0,     0,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    89,     0,     0,     0,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,    69,    70,    71,
      72,    73,    74,    75,    76,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    68,    69,    70,    71,    72,
      73,    74,    75,    76,     0,     0,    77,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    68,    69,    70,
      71,    72,    73,    74,    75,    76,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,    69,    70,    71,
      72,    73,    74,    75,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,    69,    70,    71,    72,    73,
      74,    58,    59,    60,    61,    62,     0,    64,    65,    66,
      67,    68,    69,    70,    71,    72,    73,    74,    58,    59,
      60,    61,    62,     0,    64,    65,    66,    67,    68,    69,
      70,    71,    72,    73,    58,    59,    60,    61,     0,     0,
      64,    65,    66,    67,    68,    69,    70,    71,    72,    73,
      58,    59,    60,    61,     0,     0,    64,    65,    66,    67,
      68,    69,    70,    71
};

static const yytype_int16 yycheck[] =
{
       9,    16,    45,   120,    26,    34,    15,    36,    17,    18,
      37,    34,     0,    36,    34,    67,    36,    68,    60,    96,
      39,    40,    41,    42,    60,    36,    45,    46,    47,    48,
      39,    68,    36,    68,    68,   152,    45,    38,   155,    61,
      38,    68,    60,    60,    53,    54,   123,   164,    68,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    68,
      69,    70,    71,    72,    73,    74,    75,    76,    60,   146,
      79,    41,    42,    68,    36,    45,    46,    68,     3,    88,
       5,    35,    68,     8,    60,    10,    35,    12,    13,    14,
      62,    69,    45,    18,    68,    20,    34,    22,    62,    24,
      39,    40,    41,    42,    37,    60,    45,    46,    35,    33,
      68,    36,    37,    38,    62,    40,    35,   160,    11,     3,
     129,     5,    34,    60,     8,    38,    10,    35,    12,    13,
      14,    60,   141,    58,    18,   141,    20,   137,    22,   154,
      24,    66,    67,    68,    69,    70,    71,    78,    -1,    -1,
      20,   160,    36,    37,    38,    -1,    40,    -1,     3,    -1,
       5,    -1,    -1,     8,    -1,    10,    36,    12,    13,    14,
      40,    -1,    -1,    18,    58,    20,    -1,    22,    -1,    24,
      -1,    -1,    66,    67,    68,    69,    70,    71,    58,    -1,
      -1,    36,    -1,    38,    -1,    40,    66,    67,    68,    69,
      70,    71,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    58,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    66,    67,    68,    69,    70,    71,    33,    -1,    -1,
      -1,    -1,    -1,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    35,    -1,    -1,    -1,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    -1,    -1,    60,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    39,    40,    41,    42,    43,    -1,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    39,    40,
      41,    42,    43,    -1,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    39,    40,    41,    42,    -1,    -1,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      39,    40,    41,    42,    -1,    -1,    45,    46,    47,    48,
      49,    50,    51,    52
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    75,    76,     0,     3,     5,     8,    10,    12,    13,
      14,    18,    20,    22,    24,    36,    38,    40,    58,    66,
      67,    68,    69,    70,    71,    77,    78,    81,    88,    89,
      94,    98,    99,   100,   101,   102,    67,    60,    60,    36,
      68,    68,    97,    98,    68,    36,    68,    68,    82,    98,
      76,    98,    98,    34,    36,    68,   103,    60,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    60,    26,    61,
      60,    80,    98,    38,    60,    38,    97,    68,    36,    35,
      37,    98,    91,    93,    98,    34,    36,   104,    98,    98,
      98,    98,    98,    98,    98,    98,    98,    98,    98,    98,
      98,    98,    98,    98,    98,    98,    98,    68,   100,    98,
      35,    68,    96,    95,    84,    60,    87,    98,    33,    62,
      35,    69,    68,    88,    90,    92,    77,    62,    37,    37,
      88,    60,    35,    98,    33,    68,    62,    35,    11,    96,
      60,    87,    83,    88,    38,    79,    60,    77,    76,    77,
      85,    37,    97,    35,    86,    77
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    74,    75,    76,    76,    77,    77,    77,    77,    77,
      77,    77,    78,    79,    78,    80,    82,    83,    81,    84,
      85,    86,    81,    87,    88,    89,    90,    90,    91,    91,
      92,    92,    93,    93,    94,    94,    94,    94,    94,    94,
      94,    95,    95,    96,    96,    97,    97,    98,    98,    98,
      98,    98,    98,    98,    98,    98,    98,    98,    98,    98,
      98,    98,    98,    98,    98,    98,    98,    98,    98,    98,
      98,    98,    99,    99,    99,   100,   100,   101,   101,   101,
     101,   102,   102,   103,   103,   104,   104
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     0,     1,     1,     1,     2,     1,
       2,     3,     5,     0,     8,     1,     0,     0,     7,     0,
       0,     0,    12,     1,     3,     8,     3,     1,     3,     1,
       1,     0,     1,     0,     3,     2,     2,     4,     3,     5,
       5,     3,     0,     3,     1,     1,     0,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     2,     2,     1,
       3,     2,     1,     4,     1,     2,     3,     1,     1,     1,
       1,     1,     1,     3,     0,     3,     0
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
#line 117 "translate.y"
                                    { 
                                        (yyval.data).node_id = nextLabel++; 
                                        fprintf(dot, "n%d [label=\"program\"]\n", (yyval.data).node_id); 
                                        fprintf(dot, "n%d -- n%d\n", (yyval.data).node_id, (yyvsp[0].data).node_id); 
                                    }
#line 1401 "translate.tab.c"
    break;

  case 3: /* stmts: stmts stmt  */
#line 124 "translate.y"
                                    { 
                                        (yyval.data).node_id = nextLabel++; 
                                        fprintf(dot, "n%d [label=\"stmts\"]\n", (yyval.data).node_id);
                                        fprintf(dot, "n%d -- {n%d n%d}\n", (yyval.data).node_id, (yyvsp[-1].data).node_id, (yyvsp[0].data).node_id); 
                                    }
#line 1411 "translate.tab.c"
    break;

  case 4: /* stmts: %empty  */
#line 129 "translate.y"
                                    { 
                                        (yyval.data).node_id = nextLabel++; 
                                        int eps = nextLabel++; 
                                        fprintf(dot, "n%d [label=\"stmts\"]\n", (yyval.data).node_id);
                                        fprintf(dot, "n%d [label=\"&#x03B5;\"]\n",eps); 
                                        fprintf(dot, "n%d -- n%d\n", (yyval.data).node_id, eps); 
                                    }
#line 1423 "translate.tab.c"
    break;

  case 5: /* stmt: conditional  */
#line 138 "translate.y"
                                { 
                                    (yyval.data).node_id = nextLabel++; 
                                    fprintf(dot, "n%d [label=\"stmt\"]\n", (yyval.data).node_id); 
                                    fprintf(dot, "n%d -- n%d\n", (yyval.data).node_id, (yyvsp[0].data).node_id);
                                }
#line 1433 "translate.tab.c"
    break;

  case 6: /* stmt: repetition  */
#line 143 "translate.y"
                                { 
                                    (yyval.data).node_id = nextLabel++; 
                                    fprintf(dot, "n%d [label=\"stmt\"]\n", (yyval.data).node_id); 
                                    fprintf(dot, "n%d -- n%d\n", (yyval.data).node_id, (yyvsp[0].data).node_id);
                                }
#line 1443 "translate.tab.c"
    break;

  case 7: /* stmt: func  */
#line 148 "translate.y"
                                { 
                                    (yyval.data).node_id = nextLabel++; 
                                    fprintf(dot, "n%d [label=\"stmt\"]\n", (yyval.data).node_id); 
                                    fprintf(dot, "n%d -- n%d\n", (yyval.data).node_id, (yyvsp[0].data).node_id);
                                }
#line 1453 "translate.tab.c"
    break;

  case 8: /* stmt: var SEMI_COLON  */
#line 153 "translate.y"
                                { 
                                    (yyval.data).node_id = nextLabel++; 
                                    int semicolon = nextLabel++; 
                                    fprintf(dot, "n%d [label=\"stmt\"]\n", (yyval.data).node_id);  
                                    fprintf(dot, "n%d [label=\";\"]\n", semicolon); 
                                    fprintf(dot, "n%d -- {n%d n%d}\n", (yyval.data).node_id, (yyvsp[-1].data).node_id, semicolon); }
#line 1464 "translate.tab.c"
    break;

  case 9: /* stmt: commands  */
#line 159 "translate.y"
                                { 
                                    (yyval.data).node_id = nextLabel++; 
                                    fprintf(dot, "n%d [label=\"stmt\"]\n", (yyval.data).node_id); 
                                    fprintf(dot, "n%d -- n%d\n", (yyval.data).node_id, (yyvsp[0].data).node_id);
                                }
#line 1474 "translate.tab.c"
    break;

  case 10: /* stmt: expr SEMI_COLON  */
#line 164 "translate.y"
                                { 
                                    (yyval.data).node_id = nextLabel++; 
                                    int semicolon = nextLabel++; 
                                    fprintf(dot, "n%d [label=\"stmt\"]\n", (yyval.data).node_id);  
                                    fprintf(dot, "n%d [label=\";\"]\n", semicolon); 
                                    fprintf(dot, "n%d -- {n%d n%d}\n", (yyval.data).node_id, (yyvsp[-1].data).node_id, semicolon);
                                }
#line 1486 "translate.tab.c"
    break;

  case 11: /* stmt: BLOCK_OPEN stmts BLOCK_CLOSE  */
#line 171 "translate.y"
                                        { 
                                            int block_open = nextLabel++;
                                            (yyval.data).node_id = nextLabel++;
                                            int block_close = nextLabel++;
                                               
                                            fprintf(dot, "n%d [label=\"&#9875;\"]\n", block_open);
                                            fprintf(dot, "n%d [label=\"stmt\"]\n", (yyval.data).node_id);
                                            fprintf(dot, "n%d [label=\"&#9875;;\"]\n", block_close);
                                            
                                            fprintf(dot, "{ rank=same; n%d n%d n%d; }\n", block_open, (yyvsp[-1].data).node_id, block_close);
                                            
                                            fprintf(dot, "n%d -- n%d\n", (yyval.data).node_id, block_open);
                                            fprintf(dot, "n%d -- n%d\n", (yyval.data).node_id, (yyvsp[-1].data).node_id);
                                            fprintf(dot, "n%d -- n%d\n", (yyval.data).node_id, block_close);

                                        }
#line 1507 "translate.tab.c"
    break;

  case 12: /* conditional: IF OPEN_PAREN condexpr CLOSE_PAREN stmt  */
#line 188 "translate.y"
                                                               {
                                                                    handleIfAfterStmt(); 
                                                                    handleIfAfterElse();

                                                                    (yyval.data).node_id = nextLabel++;
                                                                    int if_cond = nextLabel++; 
                                                                    int open_paren = nextLabel++;
                                                                    int close_paren = nextLabel++;
                                                                    
                                                                    fprintf(dot, "n%d [label=\"conditional\"]\n", (yyval.data).node_id);
                                                                    fprintf(dot, "n%d [label=\"IF\"]\n", if_cond);  
                                                                    fprintf(dot, "n%d [label=\"(\"]\n", open_paren);  
                                                                    fprintf(dot, "n%d [label=\")\"]\n", close_paren);   

                                                                    fprintf(dot, "{ rank=same; n%d n%d n%d n%d n%d; }\n", if_cond, open_paren, (yyvsp[-2].data).node_id, close_paren, (yyvsp[0].data).node_id);
                                                                    
                                                                    fprintf(dot, "n%d -- n%d\n", (yyval.data).node_id, if_cond);
                                                                    fprintf(dot, "n%d -- n%d\n", (yyval.data).node_id, open_paren);
                                                                    fprintf(dot, "n%d -- n%d\n", (yyval.data).node_id, (yyvsp[-2].data).node_id);
                                                                    fprintf(dot, "n%d -- n%d\n", (yyval.data).node_id, close_paren);
                                                                    fprintf(dot, "n%d -- n%d\n", (yyval.data).node_id, (yyvsp[0].data).node_id);
                                                                }
#line 1534 "translate.tab.c"
    break;

  case 13: /* $@1: %empty  */
#line 210 "translate.y"
                                                   { 
                                                        handleIfAfterStmt();
                                                   }
#line 1542 "translate.tab.c"
    break;

  case 14: /* conditional: IF OPEN_PAREN condexpr CLOSE_PAREN stmt ELSE $@1 stmt  */
#line 212 "translate.y"
                                                          { 
                                                        handleIfAfterElse(); 
                                                        (yyval.data).node_id = nextLabel++;
                                                        int if_cond = nextLabel++; 
                                                        int open_paren = nextLabel++;
                                                        int close_paren = nextLabel++;
                                                        int else_cond = nextLabel++;
                                                        
                                                        fprintf(dot, "n%d [label=\"conditional\"]\n", (yyval.data).node_id);
                                                        fprintf(dot, "n%d [label=\"IF\"]\n", if_cond);  
                                                        fprintf(dot, "n%d [label=\"(\"]\n", open_paren);  
                                                        fprintf(dot, "n%d [label=\")\"]\n", close_paren);   
                                                        fprintf(dot, "n%d [label=\"ELSE\"]\n", else_cond);   

                                                        fprintf(dot, "{ rank=same; n%d n%d n%d n%d n%d n%d n%d; }\n", if_cond, open_paren, (yyvsp[-5].data).node_id, close_paren, (yyvsp[-3].data).node_id, else_cond, (yyvsp[0].data).node_id);
                                                        
                                                        fprintf(dot, "n%d -- n%d\n", (yyval.data).node_id, if_cond);
                                                        fprintf(dot, "n%d -- n%d\n", (yyval.data).node_id, open_paren);
                                                        fprintf(dot, "n%d -- n%d\n", (yyval.data).node_id, (yyvsp[-5].data).node_id);
                                                        fprintf(dot, "n%d -- n%d\n", (yyval.data).node_id, close_paren);
                                                        fprintf(dot, "n%d -- n%d\n", (yyval.data).node_id, (yyvsp[-3].data).node_id);
                                                        fprintf(dot, "n%d -- n%d\n", (yyval.data).node_id, else_cond);
                                                        fprintf(dot, "n%d -- n%d\n", (yyval.data).node_id, (yyvsp[0].data).node_id);
                                                   }
#line 1571 "translate.tab.c"
    break;

  case 15: /* condexpr: expr  */
#line 239 "translate.y"
                                { 
                                    handleIfAfterExpr((yyvsp[0].data).data.exprData); 

                                    (yyval.data).node_id = nextLabel++; 
                                    fprintf(dot, "n%d [label=\"condexpr\"]\n", (yyval.data).node_id); 
                                    fprintf(dot, "n%d -- n%d\n", (yyval.data).node_id, (yyvsp[0].data).node_id);

                                }
#line 1584 "translate.tab.c"
    break;

  case 16: /* $@2: %empty  */
#line 254 "translate.y"
                    {
                        handleRepEntry();
                    }
#line 1592 "translate.tab.c"
    break;

  case 17: /* $@3: %empty  */
#line 257 "translate.y"
                                                    {
                        handleRepStmt();
                    }
#line 1600 "translate.tab.c"
    break;

  case 18: /* repetition: WHILE $@2 OPEN_PAREN repexpr CLOSE_PAREN $@3 stmt  */
#line 259 "translate.y"
                           {
                        handleRepGotoEntry();
                        handleRepExit();

                        (yyval.data).node_id = nextLabel++;
                        int while_loop = nextLabel++;
                        int open_paren = nextLabel++;
                        int close_paren = nextLabel++;

                        fprintf(dot, "n%d [label=\"WHILE\"]\n", while_loop); 
                        fprintf(dot, "n%d [label=\"(\"]\n", open_paren);
                        fprintf(dot, "n%d [label=\"repetition\"]\n", (yyval.data).node_id); 
                        fprintf(dot, "n%d [label=\")\"]\n", close_paren);
                        
                        fprintf(dot, "{ rank=same; n%d n%d n%d n%d n%d; }\n", while_loop, open_paren, (yyvsp[-3].data).node_id ,close_paren,(yyvsp[0].data).node_id);

                        fprintf(dot, "n%d -- n%d\n", (yyval.data).node_id, while_loop);
                        fprintf(dot, "n%d -- n%d\n", (yyval.data).node_id, open_paren);
                        fprintf(dot, "n%d -- n%d\n", (yyval.data).node_id, (yyvsp[-3].data).node_id);
                        fprintf(dot, "n%d -- n%d\n", (yyval.data).node_id, close_paren);
                        fprintf(dot, "n%d -- n%d\n", (yyval.data).node_id, (yyvsp[0].data).node_id);
                    }
#line 1627 "translate.tab.c"
    break;

  case 19: /* $@4: %empty  */
#line 282 "translate.y"
                                {
                                    handleRepEntry();
                                }
#line 1635 "translate.tab.c"
    break;

  case 20: /* $@5: %empty  */
#line 286 "translate.y"
                                {
                                    handleRepUpdate();
                                }
#line 1643 "translate.tab.c"
    break;

  case 21: /* $@6: %empty  */
#line 290 "translate.y"
                                {
                                    handleRepGotoEntry();
                                    handleRepStmt();
                                }
#line 1652 "translate.tab.c"
    break;

  case 22: /* repetition: FOR OPEN_PAREN optexpr $@4 SEMI_COLON repexpr SEMI_COLON $@5 optexpr CLOSE_PAREN $@6 stmt  */
#line 294 "translate.y"
                                     {
                                    handleRepGotoUpdate();
                                    handleRepExit();

                                    (yyval.data).node_id = nextLabel++;
                                    int for_loop = nextLabel++;
                                    int open_paren = nextLabel++;
                                    int semicolon_1 = nextLabel++;
                                    int semicolon_2 = nextLabel++;
                                    int close_paren = nextLabel++;

                                    fprintf(dot, "n%d [label=\"repetition\"]\n", (yyval.data).node_id);
                                    fprintf(dot, "n%d [label=\"FOR\"]\n", for_loop);
                                    fprintf(dot, "n%d [label=\"(\"]\n", open_paren);
                                    fprintf(dot, "n%d [label=\";\"]\n", semicolon_1);
                                    fprintf(dot, "n%d [label=\";\"]\n", semicolon_2);
                                    fprintf(dot, "n%d [label=\")\"]\n", close_paren);

                                    fprintf(dot, "{ rank=same; n%d n%d n%d n%d n%d n%d n%d n%d n%d; }\n", for_loop, open_paren, (yyvsp[-9].data).node_id, semicolon_1, (yyvsp[-6].data).node_id, semicolon_2, (yyvsp[-3].data).node_id, close_paren, (yyvsp[0].data).node_id);
                                    
                                    fprintf(dot, "n%d -- n%d\n", (yyval.data).node_id, for_loop);
                                    fprintf(dot, "n%d -- n%d\n", (yyval.data).node_id, open_paren);
                                    fprintf(dot, "n%d -- n%d\n", (yyval.data).node_id, (yyvsp[-9].data).node_id);
                                    fprintf(dot, "n%d -- n%d\n", (yyval.data).node_id, semicolon_1);
                                    fprintf(dot, "n%d -- n%d\n", (yyval.data).node_id, (yyvsp[-6].data).node_id);
                                    fprintf(dot, "n%d -- n%d\n", (yyval.data).node_id, semicolon_2);
                                    fprintf(dot, "n%d -- n%d\n", (yyval.data).node_id, (yyvsp[-3].data).node_id);
                                    fprintf(dot, "n%d -- n%d\n", (yyval.data).node_id, close_paren);
                                    fprintf(dot, "n%d -- n%d\n", (yyval.data).node_id, (yyvsp[0].data).node_id);
                                }
#line 1687 "translate.tab.c"
    break;

  case 23: /* repexpr: expr  */
#line 328 "translate.y"
                { 
                    handleRepAfterExpr((yyvsp[0].data).data.exprData);
                    (yyval.data).node_id = nextLabel++; 
                    fprintf(dot, "n%d [label=\"repexpr\"]\n", (yyval.data).node_id); 
                    fprintf(dot, "n%d -- n%d\n", (yyval.data).node_id, (yyvsp[0].data).node_id);
                }
#line 1698 "translate.tab.c"
    break;

  case 24: /* var: IDENTIFIER IDENTIFIER constvector  */
#line 336 "translate.y"
                                        { 
                                            handleVarDeclaration((yyvsp[-2].data).data.string, (yyvsp[-1].data).data.string, (yyvsp[0].data).data.integer);

                                            (yyval.data).node_id = nextLabel++;
                                            int identifier_1 = nextLabel++;
                                            int identifier_2 = nextLabel++;

                                            fprintf(dot, "n%d [label=\"var\"]\n", (yyval.data).node_id);
                                            fprintf(dot, "n%d [label=\"%s\"]\n", identifier_1, (yyvsp[-2].data).data.string);
                                            fprintf(dot, "n%d [label=\"%s\"]\n", identifier_2, (yyvsp[-1].data).data.string);

                                            fprintf(dot, "{ rank=same; n%d n%d n%d; }\n", identifier_1, identifier_2, (yyvsp[0].data).node_id);

                                            fprintf(dot, "n%d -- n%d\n", (yyval.data).node_id, identifier_1);
                                            fprintf(dot, "n%d -- n%d\n", (yyval.data).node_id, identifier_2);
                                            fprintf(dot, "n%d -- n%d\n", (yyval.data).node_id, (yyvsp[0].data).node_id);
                                        }
#line 1720 "translate.tab.c"
    break;

  case 25: /* func: IDENTIFIER IDENTIFIER OPEN_PAREN opttypelist CLOSE_PAREN BLOCK_OPEN stmts BLOCK_CLOSE  */
#line 356 "translate.y"
                                        {
                                            (yyval.data).node_id = nextLabel++;
                                            int identifier_1 = nextLabel++;
                                            int identifier_2 = nextLabel++;
                                            int open_paren = nextLabel++;
                                            int close_paren = nextLabel++;
                                            int block_open = nextLabel++;
                                            int block_close = nextLabel++;

                                            fprintf(dot, "n%d [label=\"func\"]\n", (yyval.data).node_id);
                                            fprintf(dot, "n%d [label=\"%s\"]\n", identifier_1, (yyvsp[-7].data).data.string);
                                            fprintf(dot, "n%d [label=\"%s\"]\n", identifier_2, (yyvsp[-6].data).data.string);
                                            fprintf(dot, "n%d [label=\"(\"]\n", open_paren);
                                            fprintf(dot, "n%d [label=\")\"]\n", close_paren);
                                            fprintf(dot, "n%d [label=\"&#9875;\"]\n", block_open);
                                            fprintf(dot, "n%d [label=\"&#9875;;\"]\n", block_close);

                                            fprintf(dot, "{ rank=same; n%d n%d n%d n%d n%d n%d n%d n%d ; }\n", identifier_1, identifier_2, open_paren, (yyvsp[-4].data).node_id, close_paren, block_open, (yyvsp[-1].data).node_id, block_close);

                                            fprintf(dot, "n%d -- n%d\n", (yyval.data).node_id, identifier_1);
                                            fprintf(dot, "n%d -- n%d\n", (yyval.data).node_id, identifier_2);
                                            fprintf(dot, "n%d -- n%d\n", (yyval.data).node_id, open_paren);
                                            fprintf(dot, "n%d -- n%d\n", (yyval.data).node_id, (yyvsp[-4].data).node_id);
                                            fprintf(dot, "n%d -- n%d\n", (yyval.data).node_id, close_paren);
                                            fprintf(dot, "n%d -- n%d\n", (yyval.data).node_id, block_open);
                                            fprintf(dot, "n%d -- n%d\n", (yyval.data).node_id, (yyvsp[-1].data).node_id);
                                            fprintf(dot, "n%d -- n%d\n", (yyval.data).node_id, block_close);

                                        }
#line 1754 "translate.tab.c"
    break;

  case 26: /* typelist: typelist COMMA var  */
#line 387 "translate.y"
                             {
                                (yyval.data).node_id = nextLabel++; 
                                int comma = nextLabel++;
                                fprintf(dot, "n%d [label=\"typelist\"]\n", (yyval.data).node_id);
                                fprintf(dot, "n%d [label=\",\"]\n", comma); 

                                fprintf(dot, "{ rank=same; n%d n%d n%d;}\n", (yyvsp[-2].data).node_id, comma, (yyvsp[0].data).node_id);

                                fprintf(dot, "n%d -- n%d\n", (yyval.data).node_id, (yyvsp[-2].data).node_id);
                                fprintf(dot, "n%d -- n%d\n", (yyval.data).node_id, comma);
                                fprintf(dot, "n%d -- n%d\n", (yyval.data).node_id, (yyvsp[0].data).node_id);
                             }
#line 1771 "translate.tab.c"
    break;

  case 27: /* typelist: var  */
#line 399 "translate.y"
          {
            (yyval.data).node_id = nextLabel++; 
            fprintf(dot, "n%d [label=\"typelist\"]\n", (yyval.data).node_id); 
            fprintf(dot, "n%d -- n%d\n", (yyval.data).node_id, (yyvsp[0].data).node_id); 
          }
#line 1781 "translate.tab.c"
    break;

  case 28: /* exprlist: exprlist COMMA expr  */
#line 406 "translate.y"
                                { 
                                    functAddParam(&(yyvsp[-2].data).data.paramList, (yyvsp[0].data).data.exprData.reg, (yyvsp[0].data).data.exprData.returnType);
                                    
                                    (yyval.data).node_id = nextLabel++;
                                    int comma = nextLabel++;

                                    fprintf(dot, "n%d [label=\",\"]\n", comma);
                                    fprintf(dot, "n%d [label=\"exprlist\"]\n", (yyval.data).node_id);

                                    fprintf(dot, "{ rank=same; n%d n%d n%d; }\n", (yyvsp[-2].data).node_id, comma, (yyvsp[0].data).node_id);

                                    fprintf(dot, "n%d -- n%d\n", (yyval.data).node_id, (yyvsp[-2].data).node_id);
                                    fprintf(dot, "n%d -- n%d\n", (yyval.data).node_id, comma);
                                    fprintf(dot, "n%d -- n%d\n", (yyval.data).node_id, (yyvsp[0].data).node_id);
                                }
#line 1801 "translate.tab.c"
    break;

  case 29: /* exprlist: expr  */
#line 421 "translate.y"
            { 
                (yyval.data).data.paramList = NULL; 
                functAddParam(&(yyval.data).data.paramList, (yyvsp[0].data).data.exprData.reg, (yyvsp[0].data).data.exprData.returnType); 

                (yyval.data).node_id = nextLabel++;
                fprintf(dot, "n%d [label=\"exprlist\"]\n", (yyval.data).node_id);
                fprintf(dot, "n%d -- n%d\n", (yyval.data).node_id, (yyvsp[0].data).node_id);
                
            }
#line 1815 "translate.tab.c"
    break;

  case 30: /* opttypelist: typelist  */
#line 432 "translate.y"
                        { 
                            (yyval.data).node_id = nextLabel++;
                            fprintf(dot, "n%d [label=\"opttypelist\"]\n", (yyval.data).node_id);
                            fprintf(dot, "n%d -- n%d\n", (yyval.data).node_id, (yyvsp[0].data).node_id); 
                        }
#line 1825 "translate.tab.c"
    break;

  case 31: /* opttypelist: %empty  */
#line 437 "translate.y"
                        {
                            (yyval.data).node_id = nextLabel++; 
                            int eps = nextLabel++; 
                            fprintf(dot, "n%d [label=\"opttypelist\"]\n", (yyval.data).node_id);
                            fprintf(dot, "n%d [label=\"&#x03B5;\"]\n",eps); 
                            fprintf(dot, "n%d -- n%d\n", (yyval.data).node_id, eps);
                        }
#line 1837 "translate.tab.c"
    break;

  case 32: /* optexprlist: exprlist  */
#line 446 "translate.y"
                        { 
                            (yyval.data).data.paramList = (yyvsp[0].data).data.paramList; 
                            
                            (yyval.data).node_id = nextLabel++;
                            fprintf(dot, "n%d [label=\"optexprlist\"]\n", (yyval.data).node_id);
                            fprintf(dot, "n%d -- n%d\n", (yyval.data).node_id, (yyvsp[0].data).node_id);
                            
                        }
#line 1850 "translate.tab.c"
    break;

  case 33: /* optexprlist: %empty  */
#line 454 "translate.y"
                        { 
                            (yyval.data).data.paramList = NULL; 
                            
                            (yyval.data).node_id = nextLabel++; 
                            int eps = nextLabel++; 
                            fprintf(dot, "n%d [label=\"optexprlist\"]\n", (yyval.data).node_id);
                            fprintf(dot, "n%d [label=\"&#x03B5;\"]\n",eps); 
                            fprintf(dot, "n%d -- n%d\n", (yyval.data).node_id, eps); 
                        }
#line 1864 "translate.tab.c"
    break;

  case 34: /* commands: RETURN optexpr SEMI_COLON  */
#line 466 "translate.y"
                              {
                                int return_ = nextLabel++;
                                (yyval.data).node_id = nextLabel++;
                                int semicolon = nextLabel++;
                                
                                fprintf(dot, "n%d [label=\"commands\"]\n", (yyval.data).node_id);
                                fprintf(dot, "n%d [label=\"RETURN\"]\n", return_);
                                fprintf(dot, "n%d [label=\";\"]\n", semicolon);
                                fprintf(dot, "n%d [label=\"commands\"]\n", (yyval.data).node_id);

                                fprintf(dot, "{ rank=same; n%d n%d n%d; }\n", return_, (yyvsp[-1].data).node_id, semicolon);

                                fprintf(dot, "n%d -- n%d\n", (yyval.data).node_id, return_);
                                fprintf(dot, "n%d -- n%d\n", (yyval.data).node_id, (yyvsp[-1].data).node_id);
                                fprintf(dot, "n%d -- n%d\n", (yyval.data).node_id, semicolon);
                                }
#line 1885 "translate.tab.c"
    break;

  case 35: /* commands: BREAK SEMI_COLON  */
#line 482 "translate.y"
                       {
                                int break_ = nextLabel++;
                                int semicolon = nextLabel++;
                                (yyval.data).node_id = nextLabel++;

                                fprintf(dot, "n%d [label=\"BREAK\"]\n", break_);
                                fprintf(dot, "n%d [label=\";\"]\n", semicolon);
                                fprintf(dot, "n%d [label=\"commands\"]\n", (yyval.data).node_id);

                                fprintf(dot, "{ rank=same; n%d n%d n%d; }\n", break_, semicolon, (yyval.data).node_id);
                                
                                fprintf(dot, "n%d -- {n%d n%d}\n", (yyval.data).node_id, break_, semicolon);
                                
                        }
#line 1904 "translate.tab.c"
    break;

  case 36: /* commands: CONTINUE SEMI_COLON  */
#line 496 "translate.y"
                          {
                                int continue_ = nextLabel++;
                                int semicolon = nextLabel++;
                                (yyval.data).node_id = nextLabel++;

                                fprintf(dot, "n%d [label=\"CONTINUE\"]\n", continue_);
                                fprintf(dot, "n%d [label=\";\"]\n", semicolon);
                                fprintf(dot, "n%d [label=\"commands\"]\n", (yyval.data).node_id);

                                fprintf(dot, "{ rank=same; n%d n%d n%d; }\n", continue_, semicolon, (yyval.data).node_id);
                                
                                fprintf(dot, "n%d -- {n%d n%d}\n", (yyval.data).node_id, continue_, semicolon);
                          }
#line 1922 "translate.tab.c"
    break;

  case 37: /* commands: TYPEDEF IDENTIFIER IDENTIFIER SEMI_COLON  */
#line 509 "translate.y"
                                               {
                                                    int typedef_ = nextLabel++;
                                                    int identifier_1 = nextLabel++;
                                                    int identifier_2 = nextLabel++;
                                                    int semicolon = nextLabel++;
                                                    (yyval.data).node_id = nextLabel++;

                                                    fprintf(dot, "n%d [label=\"TYPEDEF\"]\n", typedef_);
                                                    fprintf(dot, "n%d [label=\"ID1\"]\n", identifier_1);
                                                    fprintf(dot, "n%d [label=\"ID2\"]\n", identifier_2);
                                                    fprintf(dot, "n%d [label=\";\"]\n", semicolon);
                                                    fprintf(dot, "n%d [label=\"commands\"]\n", (yyval.data).node_id);
                                                    fprintf(dot, "n%d -- {n%d n%d n%d n%d}\n", (yyval.data).node_id, typedef_, identifier_1, identifier_2, semicolon);
                                               }
#line 1941 "translate.tab.c"
    break;

  case 38: /* commands: INCLUDE STRING SEMI_COLON  */
#line 523 "translate.y"
                                {
                                    int include_ = nextLabel++;
                                    int string_ = nextLabel++;
                                    int semicolon = nextLabel++;
                                    (yyval.data).node_id = nextLabel++;

                                    fprintf(dot, "n%d [label=\"INCLUDE\"]\n", include_);
                                    fprintf(dot, "n%d [label=\"%s\"]\n", string_,(yyvsp[-1].data).data.string);
                                    fprintf(dot, "n%d [label=\";\"]\n", semicolon);
                                    fprintf(dot, "n%d [label=\"commands\"]\n", (yyval.data).node_id);
                                    fprintf(dot, "n%d -- {n%d n%d n%d}\n", (yyval.data).node_id, include_, string_, semicolon);
                                }
#line 1958 "translate.tab.c"
    break;

  case 39: /* commands: STRUCT IDENTIFIER BLOCK_OPEN varlist BLOCK_CLOSE  */
#line 535 "translate.y"
                                                       { 
                                                        int struct_ = nextLabel++;
                                                        int identifier = nextLabel++;
                                                        int block_open = nextLabel++;
                                                        (yyval.data).node_id = nextLabel++;
                                                        int block_close = nextLabel++;

                                                        fprintf(dot, "n%d [label=\"STRUCT\"]\n", struct_);
                                                        fprintf(dot, "n%d [label=\"ID\"]\n", identifier);
                                                        fprintf(dot, "n%d [label=\"&#9875;\"]\n", block_open);
                                                        fprintf(dot, "n%d [label=\"commands\"]\n", (yyval.data).node_id);
                                                        fprintf(dot, "n%d [label=\"&#9875;;\"]\n", block_close);
                                                        fprintf(dot, "n%d -- {n%d n%d n%d n%d n%d}\n", (yyval.data).node_id, struct_, identifier, block_open, (yyvsp[-1].data).node_id, block_close);
                                                       }
#line 1977 "translate.tab.c"
    break;

  case 40: /* commands: ENUM IDENTIFIER BLOCK_OPEN idlist BLOCK_CLOSE  */
#line 549 "translate.y"
                                                    { 
                                                        int enum_ = nextLabel++;
                                                        int identifier = nextLabel++;
                                                        int block_open = nextLabel++;
                                                        (yyval.data).node_id = nextLabel++;
                                                        int block_close = nextLabel++;

                                                        fprintf(dot, "n%d [label=\"ENUM\"]\n", enum_);
                                                        fprintf(dot, "n%d [label=\"ID\"]\n", identifier);
                                                        fprintf(dot, "n%d [label=\"&#9875;\"]\n", block_open);
                                                        fprintf(dot, "n%d [label=\"commands\"]\n", (yyval.data).node_id);
                                                        fprintf(dot, "n%d [label=\"&#9875;;\"]\n", block_close);
                                                        fprintf(dot, "n%d -- {n%d n%d n%d n%d n%d}\n", (yyval.data).node_id, enum_, identifier, block_open, (yyvsp[-1].data).node_id, block_close);
                                                    }
#line 1996 "translate.tab.c"
    break;

  case 41: /* varlist: varlist var SEMI_COLON  */
#line 565 "translate.y"
                                    { 
                                        (yyval.data).node_id = nextLabel++;
                                        int semicolon = nextLabel++;
                                        fprintf(dot, "n%d [label=\"varlist\"]\n", (yyval.data).node_id);
                                        fprintf(dot, "n%d [label=\";\"]\n", semicolon);
                                        fprintf(dot, "n%d -- {n%d n%d n%d}\n", (yyval.data).node_id, (yyvsp[-2].data).node_id, (yyvsp[-1].data).node_id, semicolon);
                                    }
#line 2008 "translate.tab.c"
    break;

  case 42: /* varlist: %empty  */
#line 572 "translate.y"
                                    {
                                        (yyval.data).node_id = nextLabel++; 
                                        int eps = nextLabel++; 
                                        fprintf(dot, "n%d [label=\"varlist\"]\n", (yyval.data).node_id);
                                        fprintf(dot, "n%d [label=\"&#x03B5;\"]\n",eps); 
                                        fprintf(dot, "n%d -- n%d\n", (yyval.data).node_id, eps); 
                                    }
#line 2020 "translate.tab.c"
    break;

  case 43: /* idlist: IDENTIFIER COMMA idlist  */
#line 581 "translate.y"
                                    { 
                                        int identifier = nextLabel++;
                                        int comma = nextLabel++;
                                        (yyval.data).node_id = nextLabel++;
                                        fprintf(dot, "n%d [label=\"ID\"]\n", identifier);
                                        fprintf(dot, "n%d [label=\",\"]\n", comma);
                                        fprintf(dot, "n%d [label=\"idlist\"]\n", (yyval.data).node_id);
                                        fprintf(dot, "n%d -- {n%d n%d n%d}\n", (yyval.data).node_id, identifier, comma, (yyvsp[0].data).node_id);
                                    }
#line 2034 "translate.tab.c"
    break;

  case 44: /* idlist: IDENTIFIER  */
#line 590 "translate.y"
                                    { 
                                        int identifier = nextLabel++;
                                        (yyval.data).node_id = nextLabel++;
                                        fprintf(dot, "n%d [label=\"ID\"]\n", identifier);
                                        fprintf(dot, "n%d [label=\"idlist\"]\n", (yyval.data).node_id);
                                        fprintf(dot, "n%d -- n%d\n", (yyval.data).node_id, identifier);
                                    }
#line 2046 "translate.tab.c"
    break;

  case 45: /* optexpr: expr  */
#line 599 "translate.y"
                                    { 
                                        (yyval.data).node_id = nextLabel++;
                                        fprintf(dot, "n%d [label=\"optexpr\"]\n", (yyval.data).node_id);
                                        fprintf(dot, "n%d -- n%d\n", (yyval.data).node_id, (yyvsp[0].data).node_id);
                                    }
#line 2056 "translate.tab.c"
    break;

  case 46: /* optexpr: %empty  */
#line 604 "translate.y"
                                    { 
                                        (yyval.data).node_id = nextLabel++; 
                                        int eps = nextLabel++; 
                                        fprintf(dot, "n%d [label=\"optexpr\"]\n", (yyval.data).node_id);
                                        fprintf(dot, "n%d [label=\"&#x03B5;\"]\n",eps); 
                                        fprintf(dot, "n%d -- n%d\n", (yyval.data).node_id, eps);
                                    }
#line 2068 "translate.tab.c"
    break;

  case 47: /* expr: expr ADD expr  */
#line 613 "translate.y"
                    { 
                        (yyval.data).data.exprData = handleBinaryExpr(ADD, (yyvsp[-2].data).data.exprData, (yyvsp[0].data).data.exprData);

                        (yyval.data).node_id = nextLabel++;
                        int add = nextLabel++;

                        fprintf(dot, "n%d [label=\"expr\"]\n", (yyval.data).node_id);
                        fprintf(dot, "n%d [label=\"+\"]\n", add);
                        fprintf(dot, "n%d -- {n%d n%d n%d}\n", (yyval.data).node_id, (yyvsp[-2].data).node_id, add, (yyvsp[0].data).node_id);

                    }
#line 2084 "translate.tab.c"
    break;

  case 48: /* expr: expr SUB expr  */
#line 624 "translate.y"
                    { 
                        (yyval.data).data.exprData = handleBinaryExpr(SUB, (yyvsp[-2].data).data.exprData, (yyvsp[0].data).data.exprData); 

                        (yyval.data).node_id = nextLabel++;
                        int sub = nextLabel++;

                        fprintf(dot, "n%d [label=\"expr\"]\n", (yyval.data).node_id);
                        fprintf(dot, "n%d [label=\"-\"]\n", sub);
                        fprintf(dot, "n%d -- {n%d n%d n%d}\n", (yyval.data).node_id, (yyvsp[-2].data).node_id, sub, (yyvsp[0].data).node_id);

                    }
#line 2100 "translate.tab.c"
    break;

  case 49: /* expr: expr MUL expr  */
#line 635 "translate.y"
                    { 
                        (yyval.data).data.exprData = handleBinaryExpr(MUL, (yyvsp[-2].data).data.exprData, (yyvsp[0].data).data.exprData); 

                        (yyval.data).node_id = nextLabel++;
                        int mul = nextLabel++;

                        fprintf(dot, "n%d [label=\"expr\"]\n", (yyval.data).node_id);
                        fprintf(dot, "n%d [label=\"*\"]\n", mul);
                        fprintf(dot, "n%d -- {n%d n%d n%d}\n", (yyval.data).node_id, (yyvsp[-2].data).node_id, mul, (yyvsp[0].data).node_id);

                    }
#line 2116 "translate.tab.c"
    break;

  case 50: /* expr: expr DIV expr  */
#line 646 "translate.y"
                    { 
                        (yyval.data).data.exprData = handleBinaryExpr(DIV, (yyvsp[-2].data).data.exprData, (yyvsp[0].data).data.exprData);
                        
                        (yyval.data).node_id = nextLabel++;
                        int div = nextLabel++;

                        fprintf(dot, "n%d [label=\"expr\"]\n", (yyval.data).node_id);
                        fprintf(dot, "n%d [label=\"/\"]\n", div);
                        fprintf(dot, "n%d -- {n%d n%d n%d}\n", (yyval.data).node_id, (yyvsp[-2].data).node_id, div, (yyvsp[0].data).node_id);
                        
                    }
#line 2132 "translate.tab.c"
    break;

  case 51: /* expr: expr MOD expr  */
#line 657 "translate.y"
                    { /* geraTemp1, geraTemp2, chama codeGen(t1, op, t2) */ 
                        (yyval.data).node_id = nextLabel++;
                        int mod = nextLabel++;

                        fprintf(dot, "n%d [label=\"expr\"]\n", (yyval.data).node_id);
                        fprintf(dot, "n%d [label=\"%%\"]\n", mod);
                        fprintf(dot, "n%d -- {n%d n%d n%d}\n", (yyval.data).node_id, (yyvsp[-2].data).node_id, mod, (yyvsp[0].data).node_id);
                    }
#line 2145 "translate.tab.c"
    break;

  case 52: /* expr: expr BITWISE_AND expr  */
#line 665 "translate.y"
                                { 
                                    (yyval.data).data.exprData = handleBinaryExpr(BITWISE_AND, (yyvsp[-2].data).data.exprData, (yyvsp[0].data).data.exprData); 

                                    (yyval.data).node_id = nextLabel++;
                                    int and = nextLabel++;

                                    fprintf(dot, "n%d [label=\"expr\"]\n", (yyval.data).node_id);
                                    fprintf(dot, "n%d [label=\"&\"]\n", and);
                                    fprintf(dot, "n%d -- {n%d n%d n%d}\n", (yyval.data).node_id, (yyvsp[-2].data).node_id, and, (yyvsp[0].data).node_id);

                                }
#line 2161 "translate.tab.c"
    break;

  case 53: /* expr: expr BITWISE_OR expr  */
#line 676 "translate.y"
                                { 
                                    (yyval.data).data.exprData = handleBinaryExpr(BITWISE_OR, (yyvsp[-2].data).data.exprData, (yyvsp[0].data).data.exprData); 

                                    (yyval.data).node_id = nextLabel++;
                                    int or = nextLabel++;

                                    fprintf(dot, "n%d [label=\"expr\"]\n", (yyval.data).node_id);
                                    fprintf(dot, "n%d [label=\"|\"]\n", or);
                                    fprintf(dot, "n%d -- {n%d n%d n%d}\n", (yyval.data).node_id, (yyvsp[-2].data).node_id, or, (yyvsp[0].data).node_id);

                                }
#line 2177 "translate.tab.c"
    break;

  case 54: /* expr: expr BITWISE_NOT expr  */
#line 687 "translate.y"
                                { 
                                    (yyval.data).data.exprData = handleBinaryExpr(BITWISE_NOT, (yyvsp[-2].data).data.exprData, (yyvsp[0].data).data.exprData); 

                                    (yyval.data).node_id = nextLabel++;
                                    int not = nextLabel++;

                                    fprintf(dot, "n%d [label=\"expr\"]\n", (yyval.data).node_id);
                                    fprintf(dot, "n%d [label=\"~\"]\n", not);
                                    fprintf(dot, "n%d -- {n%d n%d n%d}\n", (yyval.data).node_id, (yyvsp[-2].data).node_id, not, (yyvsp[0].data).node_id);
                                    
                                }
#line 2193 "translate.tab.c"
    break;

  case 55: /* expr: expr BITWISE_XOR expr  */
#line 698 "translate.y"
                                { 
                                    (yyval.data).data.exprData = handleBinaryExpr(BITWISE_XOR, (yyvsp[-2].data).data.exprData, (yyvsp[0].data).data.exprData); 
                                    
                                    (yyval.data).node_id = nextLabel++;
                                    int xor = nextLabel++;

                                    fprintf(dot, "n%d [label=\"expr\"]\n", (yyval.data).node_id);
                                    fprintf(dot, "n%d [label=\"^\"]\n", xor);
                                    fprintf(dot, "n%d -- {n%d n%d n%d}\n", (yyval.data).node_id, (yyvsp[-2].data).node_id, xor, (yyvsp[0].data).node_id);
                                    
                                }
#line 2209 "translate.tab.c"
    break;

  case 56: /* expr: expr LEFT_SHIFT expr  */
#line 709 "translate.y"
                                { 
                                    (yyval.data).data.exprData = handleBinaryExpr(LEFT_SHIFT, (yyvsp[-2].data).data.exprData, (yyvsp[0].data).data.exprData); 

                                    (yyval.data).node_id = nextLabel++;
                                    int lshift = nextLabel++;

                                    fprintf(dot, "n%d [label=\"expr\"]\n", (yyval.data).node_id);
                                    fprintf(dot, "n%d [label=\"<<\"]\n", lshift);
                                    fprintf(dot, "n%d -- {n%d n%d n%d}\n", (yyval.data).node_id, (yyvsp[-2].data).node_id, lshift, (yyvsp[0].data).node_id);

                                }
#line 2225 "translate.tab.c"
    break;

  case 57: /* expr: expr RIGHT_SHIFT expr  */
#line 720 "translate.y"
                                { 
                                    (yyval.data).data.exprData = handleBinaryExpr(RIGHT_SHIFT, (yyvsp[-2].data).data.exprData, (yyvsp[0].data).data.exprData); 

                                    (yyval.data).node_id = nextLabel++;
                                    int rshift = nextLabel++;

                                    fprintf(dot, "n%d [label=\"expr\"]\n", (yyval.data).node_id);
                                    fprintf(dot, "n%d [label=\">>\"]\n", rshift);
                                    fprintf(dot, "n%d -- {n%d n%d n%d}\n", (yyval.data).node_id, (yyvsp[-2].data).node_id, rshift, (yyvsp[0].data).node_id);

                                }
#line 2241 "translate.tab.c"
    break;

  case 58: /* expr: expr EQ expr  */
#line 731 "translate.y"
                    { 
                        (yyval.data).data.exprData = handleBinaryExpr(EQ, (yyvsp[-2].data).data.exprData, (yyvsp[0].data).data.exprData); 

                        (yyval.data).node_id = nextLabel++;
                        int eq = nextLabel++;

                        fprintf(dot, "n%d [label=\"expr\"]\n", (yyval.data).node_id);
                        fprintf(dot, "n%d [label=\"==\"]\n", eq);
                        fprintf(dot, "n%d -- {n%d n%d n%d}\n", (yyval.data).node_id, (yyvsp[-2].data).node_id, eq, (yyvsp[0].data).node_id);

                    }
#line 2257 "translate.tab.c"
    break;

  case 59: /* expr: expr NE expr  */
#line 742 "translate.y"
                    { 
                        (yyval.data).data.exprData = handleBinaryExpr(NE, (yyvsp[-2].data).data.exprData, (yyvsp[0].data).data.exprData); 

                        (yyval.data).node_id = nextLabel++;
                        int ne = nextLabel++;

                        fprintf(dot, "n%d [label=\"expr\"]\n", (yyval.data).node_id);
                        fprintf(dot, "n%d [label=\"!=\"]\n", ne);
                        fprintf(dot, "n%d -- {n%d n%d n%d}\n", (yyval.data).node_id, (yyvsp[-2].data).node_id, ne, (yyvsp[0].data).node_id);
                        
                    }
#line 2273 "translate.tab.c"
    break;

  case 60: /* expr: expr LT expr  */
#line 753 "translate.y"
                    { 
                        (yyval.data).data.exprData = handleBinaryExpr(LT, (yyvsp[-2].data).data.exprData, (yyvsp[0].data).data.exprData); 

                        (yyval.data).node_id = nextLabel++;
                        int lt = nextLabel++;

                        fprintf(dot, "n%d [label=\"expr\"]\n", (yyval.data).node_id);
                        fprintf(dot, "n%d [label=\"<\"]\n", lt);
                        fprintf(dot, "n%d -- {n%d n%d n%d}\n", (yyval.data).node_id, (yyvsp[-2].data).node_id, lt, (yyvsp[0].data).node_id);
        

                    }
#line 2290 "translate.tab.c"
    break;

  case 61: /* expr: expr GT expr  */
#line 765 "translate.y"
                    { 
                        (yyval.data).data.exprData = handleBinaryExpr(GT, (yyvsp[-2].data).data.exprData, (yyvsp[0].data).data.exprData); 

                        (yyval.data).node_id = nextLabel++;
                        int gt = nextLabel++;
                        
                        fprintf(dot, "n%d [label=\"expr\"]\n", (yyval.data).node_id);
                        fprintf(dot, "n%d [label=\">\"]\n", gt);
                        fprintf(dot, "n%d -- {n%d n%d n%d}\n", (yyval.data).node_id, (yyvsp[-2].data).node_id, gt, (yyvsp[0].data).node_id);

                    }
#line 2306 "translate.tab.c"
    break;

  case 62: /* expr: expr LE expr  */
#line 776 "translate.y"
                    { 
                        (yyval.data).data.exprData = handleBinaryExpr(LE, (yyvsp[-2].data).data.exprData, (yyvsp[0].data).data.exprData); 
                        
                        (yyval.data).node_id = nextLabel++;
                        int le = nextLabel++;
                        
                        fprintf(dot, "n%d [label=\"expr\"]\n", (yyval.data).node_id);
                        fprintf(dot, "n%d [label=\"<=\"]\n", le);
                        fprintf(dot, "n%d -- {n%d n%d n%d}\n", (yyval.data).node_id, (yyvsp[-2].data).node_id, le, (yyvsp[0].data).node_id);
                        
                    }
#line 2322 "translate.tab.c"
    break;

  case 63: /* expr: expr GE expr  */
#line 787 "translate.y"
                    { 
                        (yyval.data).data.exprData = handleBinaryExpr(GE, (yyvsp[-2].data).data.exprData, (yyvsp[0].data).data.exprData); 
                        
                        (yyval.data).node_id = nextLabel++;
                        int ge = nextLabel++;
                        
                        fprintf(dot, "n%d [label=\"expr\"]\n", (yyval.data).node_id);
                        fprintf(dot, "n%d [label=\">=\"]\n", ge);
                        fprintf(dot, "n%d -- {n%d n%d n%d}\n", (yyval.data).node_id, (yyvsp[-2].data).node_id, ge, (yyvsp[0].data).node_id);

                    }
#line 2338 "translate.tab.c"
    break;

  case 64: /* expr: expr LOGICAL_AND expr  */
#line 798 "translate.y"
                                    { 
                                        (yyval.data).data.exprData = handleBinaryExpr(LOGICAL_AND, (yyvsp[-2].data).data.exprData, (yyvsp[0].data).data.exprData); 

                                        (yyval.data).node_id = nextLabel++;
                                        int and = nextLabel++;
                                        
                                        fprintf(dot, "n%d [label=\"expr\"]\n", (yyval.data).node_id);
                                        fprintf(dot, "n%d [label=\"&&\"]\n", and);
                                        fprintf(dot, "n%d -- {n%d n%d n%d}\n", (yyval.data).node_id, (yyvsp[-2].data).node_id, and, (yyvsp[0].data).node_id);

                                    }
#line 2354 "translate.tab.c"
    break;

  case 65: /* expr: expr LOGICAL_OR expr  */
#line 809 "translate.y"
                                    { 
                                        (yyval.data).data.exprData = handleBinaryExpr(LOGICAL_OR, (yyvsp[-2].data).data.exprData, (yyvsp[0].data).data.exprData); 

                                        (yyval.data).node_id = nextLabel++;
                                        int or = nextLabel++;

                                        fprintf(dot, "n%d [label=\"expr\"]\n", (yyval.data).node_id);
                                        fprintf(dot, "n%d [label=\"||\"]\n", or);
                                        fprintf(dot, "n%d -- {n%d n%d n%d}\n", (yyval.data).node_id, (yyvsp[-2].data).node_id, or, (yyvsp[0].data).node_id);
                                        
                                    }
#line 2370 "translate.tab.c"
    break;

  case 66: /* expr: OPEN_PAREN expr CLOSE_PAREN  */
#line 820 "translate.y"
                                    { 
                                        (yyval.data).data.exprData = (yyvsp[-1].data).data.exprData; 

                                        (yyval.data).node_id = nextLabel++;
                                        int paren = nextLabel++;
                                        int close_paren = nextLabel++;

                                        fprintf(dot, "n%d [label=\"(\"]\n", paren);
                                        fprintf(dot, "n%d [label=\"expr\"]\n", (yyval.data).node_id);
                                        fprintf(dot, "n%d [label=\")\"]\n", close_paren);
                                        fprintf(dot, "n%d -- {n%d n%d n%d}\n", (yyval.data).node_id, paren, (yyvsp[-1].data).node_id, close_paren);

                                    }
#line 2388 "translate.tab.c"
    break;

  case 67: /* expr: LOGICAL_NOT expr  */
#line 833 "translate.y"
                                    { 
                                        (yyval.data).data.exprData = handleUnaryExpr(LOGICAL_NOT, (yyvsp[0].data).data.exprData); 

                                        int not = nextLabel++;
                                        (yyval.data).node_id = nextLabel++;
                                        int unary = nextLabel++;
                                        fprintf(dot, "n%d [label=\"!\"]\n", not);
                                        fprintf(dot, "n%d [label=\"expr\"]\n", (yyval.data).node_id);
                                        fprintf(dot, "n%d [label=\"UNARY\"]\n", unary);
                                        fprintf(dot, "n%d -- {n%d n%d n%d}\n", (yyval.data).node_id, not, (yyvsp[0].data).node_id, unary);
                                        
                                    }
#line 2405 "translate.tab.c"
    break;

  case 68: /* expr: SUB expr  */
#line 845 "translate.y"
                                    { 
                                        (yyval.data).data.exprData = handleUnaryExpr(SUB, (yyvsp[0].data).data.exprData); 
                                        
                                        (yyval.data).node_id = nextLabel++;
                                        int sub = nextLabel++;
                                        
                                        fprintf(dot, "n%d [label=\"-\"]\n", sub);
                                        fprintf(dot, "n%d [label=\"expr\"]\n", (yyval.data).node_id);
                                        fprintf(dot, "n%d -- {n%d n%d}\n", (yyval.data).node_id, sub, (yyvsp[0].data).node_id);
                                        
                                    }
#line 2421 "translate.tab.c"
    break;

  case 69: /* expr: term  */
#line 856 "translate.y"
                                    { 
                                        (yyval.data).data.exprData = (yyvsp[0].data).data.exprData; 

                                        (yyval.data).node_id = nextLabel++;
                                        
                                        fprintf(dot, "n%d [label=\"term\"]\n", (yyval.data).node_id);
                                        fprintf(dot, "n%d -- n%d\n", (yyval.data).node_id, (yyvsp[0].data).node_id);
                                        
                                    }
#line 2435 "translate.tab.c"
    break;

  case 70: /* expr: attr ASSIGN expr  */
#line 865 "translate.y"
                                    { 
                                        (yyval.data).data.exprData = handleAssignExpr((yyvsp[-2].data).data.string, (yyvsp[0].data).data.exprData); 

                                        (yyval.data).node_id = nextLabel++;
                                        int assign_ = nextLabel++;

                                        fprintf(dot, "n%d [label=\"=\"]\n", assign_);
                                        fprintf(dot, "n%d [label=\"attr\"]\n", (yyval.data).node_id);
                                        fprintf(dot, "n%d -- {n%d n%d n%d}\n", (yyval.data).node_id, (yyvsp[-2].data).node_id, assign_, (yyvsp[0].data).node_id);

                                    }
#line 2451 "translate.tab.c"
    break;

  case 71: /* expr: SIZEOF IDENTIFIER  */
#line 876 "translate.y"
                                    { /* return symbol table size of identifier */ }
#line 2457 "translate.tab.c"
    break;

  case 72: /* term: const  */
#line 880 "translate.y"
            { 
                (yyval.data).data.exprData = (yyvsp[0].data).data.exprData; 

                (yyval.data).node_id = nextLabel++;
                
                fprintf(dot, "n%d [label=\"const\"]\n", (yyval.data).node_id);
                fprintf(dot, "n%d -- n%d\n", (yyval.data).node_id, (yyvsp[0].data).node_id);
                
            }
#line 2471 "translate.tab.c"
    break;

  case 73: /* term: IDENTIFIER OPEN_PAREN optexprlist CLOSE_PAREN  */
#line 889 "translate.y"
                                                    { 
                                                        (yyval.data).data.exprData = handleFunctionCall((yyvsp[-3].data).data.string, (yyvsp[-1].data).data.paramList); 

                                                        int identifier = nextLabel++;
                                                        int open_paren = nextLabel++;
                                                        (yyval.data).node_id = nextLabel++;
                                                        int close_paren = nextLabel++;

                                                        fprintf(dot, "n%d [label=\"%s\"]\n", identifier, (yyvsp[-3].data).data.string);
                                                        fprintf(dot, "n%d [label=\"(\"]\n", open_paren);
                                                        fprintf(dot, "n%d [label=\"const\"]\n", (yyval.data).node_id);
                                                        fprintf(dot, "n%d [label=\")\"]\n", close_paren);
                                                        fprintf(dot, "n%d -- {n%d n%d n%d n%d}\n", (yyval.data).node_id, identifier, open_paren, (yyvsp[-3].data).node_id, close_paren);

                                                    }
#line 2491 "translate.tab.c"
    break;

  case 74: /* term: attr  */
#line 904 "translate.y"
            { 
                (yyval.data).data.exprData = handleAttr((yyvsp[0].data).data.string); 
                
                (yyval.data).node_id = nextLabel++;

                fprintf(dot, "n%d [label=\"attr\"]\n", (yyval.data).node_id);
                fprintf(dot, "n%d -- n%d\n", (yyval.data).node_id, (yyvsp[0].data).node_id);

            }
#line 2505 "translate.tab.c"
    break;

  case 75: /* attr: IDENTIFIER exprvector  */
#line 915 "translate.y"
                                { 
                                    (yyval.data).data.string = (yyvsp[-1].data).data.string; 

                                    int exprvector = nextLabel++;
                                    (yyval.data).node_id = nextLabel++;

                                    fprintf(dot, "n%d [label=\"%s\"]\n", (yyval.data).node_id, (yyvsp[-1].data).data.string);
                                    fprintf(dot, "n%d [label=\"attr\"]\n", exprvector);
                                    fprintf(dot, "n%d -- {n%d n%d}\n", (yyval.data).node_id, exprvector, (yyvsp[0].data).node_id);

                                }
#line 2521 "translate.tab.c"
    break;

  case 76: /* attr: attr POINTER attr  */
#line 926 "translate.y"
                                { 
                                    (yyval.data).data.string = mergeStrPointers((yyvsp[-2].data).data.string, (yyvsp[0].data).data.string); 

                                    int pointer = nextLabel++;
                                    (yyval.data).node_id = nextLabel++;

                                    fprintf(dot, "n%d [label=\"attr\"]\n", (yyval.data).node_id);
                                    fprintf(dot, "n%d [label=\"*\"]\n", pointer);
                                    fprintf(dot, "n%d -- {n%d n%d n%d}\n", (yyval.data).node_id, (yyvsp[-2].data).node_id, pointer, (yyvsp[0].data).node_id);
                                }
#line 2536 "translate.tab.c"
    break;

  case 77: /* const: INTEGER  */
#line 938 "translate.y"
                        { 
                            (yyval.data).data.exprData = handleInteger((yyvsp[0].data).data.integer); 

                            int integer = nextLabel++;
                            (yyval.data).node_id = nextLabel++;

                            fprintf(dot, "n%d [label=\"%d\"]\n", integer, (yyvsp[0].data).data.integer);
                            fprintf(dot, "n%d [label=\"const\"]\n", (yyval.data).node_id);
                            fprintf(dot, "n%d -- n%d\n", (yyval.data).node_id, integer);
                        }
#line 2551 "translate.tab.c"
    break;

  case 78: /* const: DECIMAL  */
#line 948 "translate.y"
                        { 
                            (yyval.data).data.exprData.returnType = strdup("ship"); 
                            (yyval.data).data.exprData.reg = 0;  

                            int decimal = nextLabel++;
                            (yyval.data).node_id = nextLabel++;

                            fprintf(dot, "n%d [label=\"%lf\"]\n", decimal, (yyvsp[0].data).data.decimal);
                            fprintf(dot, "n%d [label=\"const\"]\n", (yyval.data).node_id);
                            fprintf(dot, "n%d -- n%d\n", (yyval.data).node_id, decimal);   
                        }
#line 2567 "translate.tab.c"
    break;

  case 79: /* const: STRING  */
#line 959 "translate.y"
                        { 
                            /* chama codeGen() e retorna o Temporary */
                            int string = nextLabel++;
                            (yyval.data).node_id = nextLabel++;

                            fprintf(dot, "n%d [label=\"%s\"]\n", string, (yyvsp[0].data).data.string);
                            fprintf(dot, "n%d [label=\"const\"]\n", (yyval.data).node_id);
                            fprintf(dot, "n%d -- n%d\n", (yyval.data).node_id, string);
                        }
#line 2581 "translate.tab.c"
    break;

  case 80: /* const: boolean  */
#line 968 "translate.y"
                        {
                            /* chama codeGen() e retorna o Temporary */
                            (yyval.data).node_id = nextLabel++;
                            
                            fprintf(dot, "n%d [label=\"const\"]\n", (yyval.data).node_id);
                            fprintf(dot, "n%d -- n%d\n", (yyval.data).node_id, (yyvsp[0].data).node_id);
                            
                        }
#line 2594 "translate.tab.c"
    break;

  case 81: /* boolean: TRUE  */
#line 977 "translate.y"
                                { 
                                    (yyval.data).data.boolean = (yyvsp[0].data).data.boolean; 

                                    (yyval.data).node_id = nextLabel++;
                                    int true = nextLabel++;

                                    fprintf(dot, "n%d [label=\"true\"]\n", true);
                                    fprintf(dot, "n%d [label=\"boolean\"]\n", (yyval.data).node_id);
                                    fprintf(dot, "n%d -- n%d\n", (yyval.data).node_id, true);

                                }
#line 2610 "translate.tab.c"
    break;

  case 82: /* boolean: FALSE  */
#line 988 "translate.y"
                                { 
                                    (yyval.data).data.boolean = (yyvsp[0].data).data.boolean; 

                                    (yyval.data).node_id = nextLabel++;
                                    int false = nextLabel++;

                                    fprintf(dot, "n%d [label=\"false\"]\n", false);
                                    fprintf(dot, "n%d [label=\"boolean\"]\n", (yyval.data).node_id);
                                    fprintf(dot, "n%d -- n%d\n", (yyval.data).node_id, false);

                                }
#line 2626 "translate.tab.c"
    break;

  case 83: /* exprvector: OPEN_BRACKET expr CLOSE_BRACKET  */
#line 1002 "translate.y"
                                    { 
                                        (yyval.data).data.exprData = (yyvsp[-1].data).data.exprData;

                                        int open_bracket = nextLabel++;
                                        (yyval.data).node_id = nextLabel++;
                                        int close_bracket = nextLabel++;

                                        fprintf(dot, "n%d [label=\"{\"]\n", open_bracket);
                                        fprintf(dot, "n%d [label=\"exprvector\"]\n", (yyval.data).node_id);
                                        fprintf(dot, "n%d [label=\"}\"]\n", close_bracket);
                                        fprintf(dot, "n%d -- {n%d n%d n%d}\n", (yyval.data).node_id, open_bracket, (yyvsp[-1].data).node_id, close_bracket);   

                                    }
#line 2644 "translate.tab.c"
    break;

  case 84: /* exprvector: %empty  */
#line 1015 "translate.y"
                                    {  

                                        (yyval.data).node_id = nextLabel++; 
                                        int eps = nextLabel++; 
                                        fprintf(dot, "n%d [label=\"exprvector\"]\n", (yyval.data).node_id);
                                        fprintf(dot, "n%d [label=\"&#x03B5;\"]\n",eps); 
                                        fprintf(dot, "n%d -- n%d\n", (yyval.data).node_id, eps); 
                                    }
#line 2657 "translate.tab.c"
    break;

  case 85: /* constvector: OPEN_BRACKET INTEGER CLOSE_BRACKET  */
#line 1026 "translate.y"
                                        { 
                                            (yyval.data).data.integer = (yyvsp[-1].data).data.integer; 

                                            int open_bracket = nextLabel++;
                                            int integer = nextLabel++;
                                            (yyval.data).node_id = nextLabel++; 
                                            int close_bracket = nextLabel++;
                                            
                                            fprintf(dot, "n%d [label=\"{\"]\n", open_bracket);
                                            fprintf(dot, "n%d [label=\"constvector\"]\n", (yyval.data).node_id);
                                            fprintf(dot, "n%d [label=\"}\"]\n", close_bracket);
                                            fprintf(dot, "n%d -- {n%d n%d n%d}\n", (yyval.data).node_id, open_bracket, integer, close_bracket);
                                            
                                        }
#line 2676 "translate.tab.c"
    break;

  case 86: /* constvector: %empty  */
#line 1040 "translate.y"
                                    { 
                                        (yyval.data).data.integer = 1;
                                        
                                        (yyval.data).node_id = nextLabel++; 
                                        int eps = nextLabel++; 
                                        fprintf(dot, "n%d [label=\"constvector\"]\n", (yyval.data).node_id);
                                        fprintf(dot, "n%d [label=\"&#x03B5;\"]\n",eps); 
                                        fprintf(dot, "n%d -- n%d\n", (yyval.data).node_id, eps); 
                                    }
#line 2690 "translate.tab.c"
    break;


#line 2694 "translate.tab.c"

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

#line 1051 "translate.y"


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
    pseudoCodeIfAfterExpr(pseudo,e.temp);
}

void handleIfAfterStmt() {
    riscVCodeIfAfterStmt(riscv);
    pseudoCodeIfAfterStmt(pseudo);
}

void handleIfAfterElse() {
    riscVCodeIfAfterElse(riscv);
    pseudoCodeIfAfterElse(pseudo);
}

/* WHILE - FOR - DO WHILE */
void handleRepEntry() {
    riscVCodeRepEntry(riscv);
    pseudoCodeRepEntry(pseudo);
}

void handleRepAfterExpr(ExprData e) {
    riscVCodeRepAfterExpr(riscv, e.reg);
    pseudoCodeRepAfterExpr(pseudo, e.temp);
}

void handleRepExit() {
    riscVCodeRepExit(riscv);
    pseudoCodeRepExit(pseudo);
}

void handleRepUpdate() {
    riscVCodeRepUpdate(riscv);
    pseudoCodeRepUpdate(pseudo);
}

void handleRepStmt() {
    riscVCodeRepStmt(riscv);
    pseudoCodeRepStmt(pseudo);
}

void handleRepGotoEntry() {
    riscVCodeRepGotoEntry(riscv);
    pseudoCodeRepGotoEntry(pseudo);
}

void handleRepGotoUpdate() {
    riscVCodeRepGotoUpdate(riscv);
    pseudoCodeRepGotoUpdate(pseudo);
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

    fprintf(dot,"}\n");

    fclose(gen);
    fclose(prod);
    fclose(friscv);
    fclose(dot);
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


    dot = fopen("./output/tree.dot", "w");
    fprintf(dot, "strict graph {\n");
    fprintf(dot, "node [ordering=out]\n");

    symbolTableCreateBlock(st);
    
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
