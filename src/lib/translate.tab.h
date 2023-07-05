/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison interface for Yacc-like parsers in C

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_TRANSLATE_TAB_H_INCLUDED
# define YY_YY_TRANSLATE_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    INCLUDE = 258,                 /* INCLUDE  */
    MAIN = 259,                    /* MAIN  */
    BREAK = 260,                   /* BREAK  */
    CASE = 261,                    /* CASE  */
    CONST = 262,                   /* CONST  */
    CONTINUE = 263,                /* CONTINUE  */
    DEFAULT = 264,                 /* DEFAULT  */
    IF = 265,                      /* IF  */
    ELSE = 266,                    /* ELSE  */
    ENUM = 267,                    /* ENUM  */
    RETURN = 268,                  /* RETURN  */
    STRUCT = 269,                  /* STRUCT  */
    DO = 270,                      /* DO  */
    PRINTF = 271,                  /* PRINTF  */
    SCANF = 272,                   /* SCANF  */
    FOR = 273,                     /* FOR  */
    GOTO = 274,                    /* GOTO  */
    SIZEOF = 275,                  /* SIZEOF  */
    SWITCH = 276,                  /* SWITCH  */
    TYPEDEF = 277,                 /* TYPEDEF  */
    UNION = 278,                   /* UNION  */
    WHILE = 279,                   /* WHILE  */
    FREE = 280,                    /* FREE  */
    POINTER = 281,                 /* POINTER  */
    SLICE = 282,                   /* SLICE  */
    SOME = 283,                    /* SOME  */
    REDUCE = 284,                  /* REDUCE  */
    FILTER = 285,                  /* FILTER  */
    MAP = 286,                     /* MAP  */
    SORT = 287,                    /* SORT  */
    CLOSE_BRACKET = 288,           /* CLOSE_BRACKET  */
    OPEN_BRACKET = 289,            /* OPEN_BRACKET  */
    CLOSE_PAREN = 290,             /* CLOSE_PAREN  */
    OPEN_PAREN = 291,              /* OPEN_PAREN  */
    BLOCK_CLOSE = 292,             /* BLOCK_CLOSE  */
    BLOCK_OPEN = 293,              /* BLOCK_OPEN  */
    ADD = 294,                     /* ADD  */
    SUB = 295,                     /* SUB  */
    MUL = 296,                     /* MUL  */
    DIV = 297,                     /* DIV  */
    BITWISE_AND = 298,             /* BITWISE_AND  */
    BITWISE_OR = 299,              /* BITWISE_OR  */
    BITWISE_NOT = 300,             /* BITWISE_NOT  */
    MOD = 301,                     /* MOD  */
    LEFT_SHIFT = 302,              /* LEFT_SHIFT  */
    RIGHT_SHIFT = 303,             /* RIGHT_SHIFT  */
    LT = 304,                      /* LT  */
    GT = 305,                      /* GT  */
    LE = 306,                      /* LE  */
    GE = 307,                      /* GE  */
    EQ = 308,                      /* EQ  */
    NE = 309,                      /* NE  */
    BITWISE_XOR = 310,             /* BITWISE_XOR  */
    LOGICAL_AND = 311,             /* LOGICAL_AND  */
    LOGICAL_OR = 312,              /* LOGICAL_OR  */
    LOGICAL_NOT = 313,             /* LOGICAL_NOT  */
    COLON = 314,                   /* COLON  */
    SEMI_COLON = 315,              /* SEMI_COLON  */
    ASSIGN = 316,                  /* ASSIGN  */
    COMMA = 317,                   /* COMMA  */
    INVALID = 318,                 /* INVALID  */
    UMINUS = 319,                  /* UMINUS  */
    DOT = 320,                     /* DOT  */
    DECIMAL = 321,                 /* DECIMAL  */
    STRING = 322,                  /* STRING  */
    IDENTIFIER = 323,              /* IDENTIFIER  */
    INTEGER = 324,                 /* INTEGER  */
    TRUE = 325,                    /* TRUE  */
    FALSE = 326,                   /* FALSE  */
    IFX = 327,                     /* IFX  */
    UNARY = 328                    /* UNARY  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 69 "translate.y"

    struct {
        union {
            char *string;
            int integer;
            double decimal;
            int boolean;
            ExprData exprData;
            FuncParamList *paramList;
        } data;
        int node_id;
    } data;

#line 151 "translate.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_TRANSLATE_TAB_H_INCLUDED  */
