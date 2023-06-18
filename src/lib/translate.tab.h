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
    UNSIGNED = 258,                /* UNSIGNED  */
    SIGNED = 259,                  /* SIGNED  */
    SHORT = 260,                   /* SHORT  */
    LONG = 261,                    /* LONG  */
    INCLUDE = 262,                 /* INCLUDE  */
    MAIN = 263,                    /* MAIN  */
    BREAK = 264,                   /* BREAK  */
    CASE = 265,                    /* CASE  */
    CONST = 266,                   /* CONST  */
    CONTINUE = 267,                /* CONTINUE  */
    DEFAULT = 268,                 /* DEFAULT  */
    IF = 269,                      /* IF  */
    ELSE = 270,                    /* ELSE  */
    ENUM = 271,                    /* ENUM  */
    RETURN = 272,                  /* RETURN  */
    STRUCT = 273,                  /* STRUCT  */
    INT = 274,                     /* INT  */
    FLOAT = 275,                   /* FLOAT  */
    DOUBLE = 276,                  /* DOUBLE  */
    BOOL = 277,                    /* BOOL  */
    TRUE = 278,                    /* TRUE  */
    FALSE = 279,                   /* FALSE  */
    CHAR = 280,                    /* CHAR  */
    DO = 281,                      /* DO  */
    PRINTF = 282,                  /* PRINTF  */
    SCANF = 283,                   /* SCANF  */
    FOR = 284,                     /* FOR  */
    GOTO = 285,                    /* GOTO  */
    SIZEOF = 286,                  /* SIZEOF  */
    SWITCH = 287,                  /* SWITCH  */
    TYPEDEF = 288,                 /* TYPEDEF  */
    UNION = 289,                   /* UNION  */
    WHILE = 290,                   /* WHILE  */
    FREE = 291,                    /* FREE  */
    POINTER = 292,                 /* POINTER  */
    SLICE = 293,                   /* SLICE  */
    SOME = 294,                    /* SOME  */
    REDUCE = 295,                  /* REDUCE  */
    FILTER = 296,                  /* FILTER  */
    MAP = 297,                     /* MAP  */
    SORT = 298,                    /* SORT  */
    CLOSE_BRACKET = 299,           /* CLOSE_BRACKET  */
    OPEN_BRACKET = 300,            /* OPEN_BRACKET  */
    CLOSE_PAREN = 301,             /* CLOSE_PAREN  */
    OPEN_PAREN = 302,              /* OPEN_PAREN  */
    BLOCK_CLOSE = 303,             /* BLOCK_CLOSE  */
    BLOCK_OPEN = 304,              /* BLOCK_OPEN  */
    DOT = 305,                     /* DOT  */
    INCREMENT = 306,               /* INCREMENT  */
    DECREMENT = 307,               /* DECREMENT  */
    ADD = 308,                     /* ADD  */
    SUB = 309,                     /* SUB  */
    MUL = 310,                     /* MUL  */
    DIV = 311,                     /* DIV  */
    BITWISE_AND = 312,             /* BITWISE_AND  */
    BITWISE_OR = 313,              /* BITWISE_OR  */
    BITWISE_NOT = 314,             /* BITWISE_NOT  */
    MOD = 315,                     /* MOD  */
    LEFT_SHIFT = 316,              /* LEFT_SHIFT  */
    RIGHT_SHIFT = 317,             /* RIGHT_SHIFT  */
    LT = 318,                      /* LT  */
    GT = 319,                      /* GT  */
    LE = 320,                      /* LE  */
    GE = 321,                      /* GE  */
    EQ = 322,                      /* EQ  */
    NE = 323,                      /* NE  */
    BITWISE_XOR = 324,             /* BITWISE_XOR  */
    LOGICAL_AND = 325,             /* LOGICAL_AND  */
    LOGICAL_OR = 326,              /* LOGICAL_OR  */
    LOGICAL_NOT = 327,             /* LOGICAL_NOT  */
    QUEST = 328,                   /* QUEST  */
    COLON = 329,                   /* COLON  */
    SEMI_COLON = 330,              /* SEMI_COLON  */
    ASSIGN = 331,                  /* ASSIGN  */
    ADD_ASSIGN = 332,              /* ADD_ASSIGN  */
    SUB_ASSIGN = 333,              /* SUB_ASSIGN  */
    MUL_ASSIGN = 334,              /* MUL_ASSIGN  */
    DIV_ASSIGN = 335,              /* DIV_ASSIGN  */
    MOD_ASSIGN = 336,              /* MOD_ASSIGN  */
    LEFT_SHIFT_ASSIGN = 337,       /* LEFT_SHIFT_ASSIGN  */
    RIGHT_SHIFT_ASSIGN = 338,      /* RIGHT_SHIFT_ASSIGN  */
    BITWISE_AND_ASSIGN = 339,      /* BITWISE_AND_ASSIGN  */
    BITWISE_OR_ASSIGN = 340,       /* BITWISE_OR_ASSIGN  */
    BITWISE_XOR_ASSIGN = 341,      /* BITWISE_XOR_ASSIGN  */
    COMMA = 342,                   /* COMMA  */
    INTEGER = 343,                 /* INTEGER  */
    DECIMAL = 344,                 /* DECIMAL  */
    STRING = 345,                  /* STRING  */
    IDENTIFIER = 346,              /* IDENTIFIER  */
    COMMENTS = 347,                /* COMMENTS  */
    IFX = 348,                     /* IFX  */
    UNARY = 349                    /* UNARY  */
  };
  typedef enum yytokentype yytoken_kind_t;
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

#line 165 "translate.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_TRANSLATE_TAB_H_INCLUDED  */
