%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../../src/symbolTable.h"

extern int yylex();
extern void yyerror(const char*);

void onExit();

SymbolTable *st;

void executeProgram();

%}

%union {
    int number;
    double decimal;
    char* string;
    Enumtypes typeValue;
};

%token UNSIGNED 
%token SIGNED
%token SHORT
%token LONG
%token INCLUDE
%token MAIN
%token BREAK
%token CASE
%token CONST
%token CONTINUE
%token DEFAULT
%token IF
%token ELSE
%token ENUM
%token RETURN
%token STRUCT
%token INT
%token FLOAT
%token DOUBLE
%token BOOL
%token TRUE
%token FALSE
%token CHAR
%token DO
%token PRINTF
%token SCANF
%token FOR
%token GOTO
%token SIZEOF
%token SWITCH
%token TYPEDEF
%token UNION
%token WHILE
%token FREE
%token POINTER
%token SLICE
%token SOME
%token REDUCE
%token FILTER
%token MAP
%token SORT
%token CLOSE_BRACKET
%token OPEN_BRACKET
%token CLOSE_PAREN
%token OPEN_PAREN
%token BLOCK_CLOSE
%token BLOCK_OPEN
%token DOT
%token INCREMENT
%token DECREMENT
%token ADD
%token SUB
%token MUL
%token DIV
%token BITWISE_AND
%token BITWISE_OR
%token BITWISE_NOT
%token MOD
%token LEFT_SHIFT
%token RIGHT_SHIFT
%token LT
%token GT
%token LE
%token GE
%token EQ
%token NE
%token BITWISE_XOR
%token LOGICAL_AND
%token LOGICAL_OR
%token LOGICAL_NOT
%token QUEST
%token COLON
%token SEMI_COLON
%token ASSIGN
%token ADD_ASSIGN
%token SUB_ASSIGN
%token MUL_ASSIGN
%token DIV_ASSIGN
%token MOD_ASSIGN
%token LEFT_SHIFT_ASSIGN
%token RIGHT_SHIFT_ASSIGN
%token BITWISE_AND_ASSIGN
%token BITWISE_OR_ASSIGN
%token BITWISE_XOR_ASSIGN
%token COMMA
%token INTEGER
%token DECIMAL
%token STRING
%token <string> IDENTIFIER
%token COMMENTS


%left '+' '-'
%left '*' '/'

%type <typeValue> type 

%start program


%nonassoc IFX
%nonassoc ELSE

%left ADD SUB 
%left DIV MUL
%nonassoc UNARY

%%

program: 
    stmts {
    executeProgram();
}

stmt: 
    conditional
    | repetition
    | func
    | var
    | commands
    | expr SEMI_COLON
    |       { symbolTableCreateBlock(st); } 
      block
            { 
                symbolTableShow(st);
                symbolTableDeleteBlock(st);
            }
    ;

block: 
    BLOCK_OPEN stmts BLOCK_CLOSE {
    printf("Block statement\n");
}

conditional: IF OPEN_PAREN expr CLOSE_PAREN stmt %prec IFX {
    printf("If statement\n");
}
    | IF OPEN_PAREN expr CLOSE_PAREN stmt ELSE stmt {
    printf("If-else statement\n");
}
    | SWITCH OPEN_PAREN expr CLOSE_PAREN BLOCK_OPEN caselist BLOCK_CLOSE {
    printf("switch statement\n");
}
    ;

caselist: 
    caselist CASE term COLON stmts
    | caselist DEFAULT COLON stmts
    |
    ;

repetition: 
    WHILE OPEN_PAREN expr CLOSE_PAREN stmt {
    printf("While loop\n");
}
    | FOR OPEN_PAREN optexpr SEMI_COLON optexpr SEMI_COLON optexpr CLOSE_PAREN stmt {
    printf("For loop\n");
}
    | DO stmt WHILE OPEN_PAREN expr CLOSE_PAREN SEMI_COLON {
    printf("Do-while loop\n");
}
    ;

var: 
    type IDENTIFIER 
                                        { symbolTableInsert(st, symbolNew($2, $1, 1)); }
    vector SEMI_COLON 
    | type MUL pointer SEMI_COLON {
    printf("Pointer declaration\n");
}
    ;

pointer: 
    IDENTIFIER vector
	| MUL pointer
    ;

funcid: 
    IDENTIFIER
    | MAIN
    | PRINTF
    | SCANF
    | SLICE
    | SOME
    | REDUCE
    | FILTER
    | MAP
    | SORT
    | FREE
    ;

func: 
                                { symbolTableCreateBlock(st); }
    type funcid 
    OPEN_PAREN opttypelist CLOSE_PAREN BLOCK_OPEN stmts BLOCK_CLOSE 
                                { 
                                  symbolTableShow(st);
                                  symbolTableDeleteBlock(st); 
                                }
    | type funcid OPEN_PAREN opttypelist CLOSE_PAREN SEMI_COLON {
    printf("Function declaration\n");
}
    ;

typelist: 
    typelist COMMA type IDENTIFIER 
                                    {symbolTableInsert(st, symbolNew($4, $3, 1));}
    vector
    | type IDENTIFIER 
                                    {symbolTableInsert(st, symbolNew($2, $1, 1));}
    vector
    ;

termlist: 
    termlist COMMA term
    | term
    ;

opttypelist: 
    typelist
    |
    ;

opttermlist: 
    termlist
    |
    ;

commands: 
    RETURN optexpr SEMI_COLON {
    printf("Return statement\n");
}
    | BREAK SEMI_COLON {
    printf("Break statement\n");
}
    | CONTINUE SEMI_COLON {
    printf("Continue statement\n");
}
    | TYPEDEF type IDENTIFIER 
                                    {symbolTableInsert(st, symbolNew($3, type_types, 1));}
    vector SEMI_COLON {
    printf("Typedef declaration\n");
}
    | INCLUDE STRING {
    printf("Include directive\n");
}
    | STRUCT IDENTIFIER BLOCK_OPEN varlist BLOCK_CLOSE SEMI_COLON {
    printf("Struct definition\n");
}
    | ENUM IDENTIFIER BLOCK_OPEN idlist BLOCK_CLOSE SEMI_COLON {
    printf("Enum definition\n");
}
    | UNION IDENTIFIER BLOCK_OPEN varlist BLOCK_CLOSE SEMI_COLON {
    printf("Union definition\n");
}
    | GOTO IDENTIFIER COLON {
    printf("Goto definition\n");
}
    | IDENTIFIER COLON {
    printf("Label definition\n");
}
    | SIZEOF OPEN_PAREN type CLOSE_PAREN SEMI_COLON {
    printf("Sizeof definition\n");
}
    | SIZEOF OPEN_PAREN IDENTIFIER CLOSE_PAREN SEMI_COLON {
    printf("Sizeof definition\n");
}
    ;

varlist: 
    varlist var
    |                   {printf("empty varlist\n");}
    ;

idlist: 
    IDENTIFIER COMMA idlist
    | IDENTIFIER
    ;

optexpr: 
    expr                        {  }
    |                           
    ;                           

stmts:                          
    stmts stmt                  {  }
    |
    ;

expr: 
    attr assign expr {
    printf("Assignment expression\n");
}                               
    | expr op term {            
    printf("Binary operation expression\n");
}                               
    | expr rel term {
    printf("Relational operation expression\n");
}                               
    | expr cond term {
    printf("Conditional operation expression\n");
}
    | LOGICAL_NOT expr %prec UNARY {
    printf("Logical NOT expression\n");
}                               
    | expr QUEST stmt COLON stmt {
    printf("Ternary conditional expression\n");
}                               
    | term {                    
    printf("Term expression\n");
}           
    | OPEN_PAREN expr CLOSE_PAREN{
        printf("Expression\n");
    }                    
    ;

assign: 
    ASSIGN
    | ADD_ASSIGN
    | SUB_ASSIGN
    | MUL_ASSIGN
    | DIV_ASSIGN
    | MOD_ASSIGN
    | LEFT_SHIFT_ASSIGN
    | RIGHT_SHIFT_ASSIGN
    | BITWISE_AND_ASSIGN
    | BITWISE_OR_ASSIGN
    | BITWISE_XOR_ASSIGN
    ;

op: 
    ADD
    | SUB
    | MUL
    | DIV
    | MOD
    | BITWISE_AND
    | BITWISE_OR
    | BITWISE_NOT
    | LEFT_SHIFT
    | RIGHT_SHIFT
    | BITWISE_XOR
    ;

rel: 
    EQ
    | NE
    | LT
    | LE
    | GT
    | GE
    ;

cond: 
    LOGICAL_AND
    | LOGICAL_OR
    ;

term: 
    INTEGER {
    printf("Integer term\n");
}
    | DECIMAL {
    printf("Decimal term\n");
}
    | STRING {
    printf("String term\n");
}
    | boolean {
    printf("boolean term\n");
}
    | funcid OPEN_PAREN opttermlist CLOSE_PAREN {
    printf("Function call term 2\n");
}
    | attr {
    printf("term -> attr\n");
}
    ;

attr: 
    IDENTIFIER vector {
    printf("Identifier attr 1\n");
}
    | IDENTIFIER vector DOT attr {
    printf("Nested identifier attr\n");
}
    | IDENTIFIER vector POINTER attr {
    printf("Dereferenced identifier attr\n");
}
    ;

boolean: 
    TRUE {
    printf("True boolean term\n");
}
    | FALSE {
    printf("False boolean term\n");
}
    ;

vector: 
    vector OPEN_BRACKET expr CLOSE_BRACKET
    |
    ;

type: 
    modifier INT                { $$ = type_int; }
    | modifier CHAR             { $$ = type_char; }
    | modifier FLOAT            { $$ = type_float; }
    | modifier DOUBLE           { $$ = type_double; }
    | modifier BOOL             { $$ = type_bool; }
    | STRUCT IDENTIFIER         { $$ = type_struct; }
    | ENUM IDENTIFIER           { $$ = type_enum; }
    ;

modifier: 
    UNSIGNED
    | SIGNED
    | SHORT
    | LONG
    | CONST
    |
    ;

%%

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