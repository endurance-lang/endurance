/* A Bison parser, made by GNU Bison 3.5.1.  */

/* Bison interface for Yacc-like parsers in C

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

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

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
#line 24 "translate.y"

    int number;
    double decimal;
    char* string;
    Enumtypes typeValue;

#line 159 "translate.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_TRANSLATE_TAB_H_INCLUDED  */
