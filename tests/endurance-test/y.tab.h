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

#line 248 "y.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
