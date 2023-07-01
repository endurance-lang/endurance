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
#line 74 "translate.y"

    char *string;
    int integer;
    double decimal;
    int boolean;
    ExprData exprData;

#line 139 "translate.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_TRANSLATE_TAB_H_INCLUDED  */
