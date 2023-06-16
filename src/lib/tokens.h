#ifndef TRANSLATE_TAB_H
#define TRANSLATE_TAB_H

/* Tokens */

typedef enum Token{
    UNKNOWN_TOKEN = -1,
    
}Token;

typedef enum IdType{
    UNKNOWN_ID_TYPE = -1,
    SHORT_ID_TYPE, 
    LONG_ID_TYPE, 
    INT_ID_TYPE, 
    FLOAT_ID_TYPE, 
    DOUBLE_ID_TYPE, 
    BOOL_ID_TYPE, 
    CHAR_ID_TYPE, 
    INTEGER_ID_TYPE, 
    DECIMAL_ID_TYPE, 
    STRING_ID_TYPE, 
}IdType;

typedef enum OperatorType{

}OperatorType;

#define UNSIGNED 258
#define SIGNED 259
// #define SHORT 260
// #define LONG 261
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
// #define INT 274
// #define FLOAT 275
// #define DOUBLE 276
// #define BOOL 277
#define TRUE 278
#define FALSE 279
// #define CHAR 280
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
// #define INTEGER 343
// #define DECIMAL 344
// #define STRING 345
#define IDENTIFIER 346
#define COMMENTS 347

#endif /* TRANSLATE_TAB_H */