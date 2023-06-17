%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../../src/symbolTable.h"

extern int yylex();
extern void yyerror(const char*);

void onExit();
void executeProgram();

SymbolTable *st;
FILE *prod;

void blockOpen();
void blockClose();
void addId(char *id, Enumtypes type);

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


%type <typeValue> type 

%start program

%left COMMA
%right ASSIGN ADD_ASSIGN DIV_ASSIGN MOD_ASSIGN MUL_ASSIGN SUB_ASSIGN BITWISE_OR_ASSIGN LEFT_SHIFT_ASSIGN BITWISE_AND_ASSIGN BITWISE_XOR_ASSIGN RIGHT_SHIFT_ASSIGN
%right QUEST COLON
%left LOGICAL_OR
%left LOGICAL_AND
%left BITWISE_OR
%left BITWISE_XOR
%left BITWISE_AND
%left EQ NE
%left LT LE GE GT
%left LEFT_SHIFT RIGHT_SHIFT
%left ADD SUB
%left MUL DIV MOD
%right INCREMENT DECREMENT LOGICAL_NOT SIZEOF BITWISE_NOT
%left OPEN_PAREN CLOSE_PAREN OPEN_BRACKET CLOSE_BRACKET POINTER DOT

%nonassoc IFX
%nonassoc ELSE
%nonassoc UNARY

%%

program: stmts {
    fprintf(prod, "program -> stmts\n");
    executeProgram();
}
    ;

stmt: conditional {
        fprintf(prod, "stmt -> conditional\n");
}
    | repetition {
        fprintf(prod, "stmt -> repetition\n");
}
    | func {
        fprintf(prod, "stmt -> func\n");
}
    | var {
        fprintf(prod, "stmt -> var\n");
}
    | commands {
        fprintf(prod, "stmt -> commands\n");
}
    | expr SEMI_COLON {
        fprintf(prod, "stmt -> expr ;\n");
}
    | block {
        fprintf(prod, "stmt -> block\n");
    }
    ;

block: {blockOpen();} BLOCK_OPEN stmts BLOCK_CLOSE {blockClose();} {
        fprintf(prod, "block -> { stmts }\n");
}

conditional: IF OPEN_PAREN expr CLOSE_PAREN stmt %prec IFX {
    fprintf(prod, "conditional: IF ( expr ) stmt\n");
}
    | IF OPEN_PAREN expr CLOSE_PAREN stmt ELSE stmt {
    fprintf(prod, "conditional: IF ( expr ) stmt ELSE stmt\n");
}
    | SWITCH OPEN_PAREN expr CLOSE_PAREN BLOCK_OPEN caselist BLOCK_CLOSE {
    fprintf(prod, "conditional: SWITCH ( expr ) { caselist }\n");
}
    ;

caselist: caselist CASE term COLON stmts    { fprintf(prod, "caselist -> caselist CASE term : stmts\n"); }
    | caselist DEFAULT COLON stmts          { fprintf(prod, "caselist -> caselist DEFAULT term : stmts\n"); }
    |                                       { fprintf(prod, "caselist -> EPS\n"); }
    ;

repetition: WHILE OPEN_PAREN expr CLOSE_PAREN stmt {
    fprintf(prod, "repetition -> WHILE ( expr ) stmt\n");
}
    | FOR OPEN_PAREN optexpr SEMI_COLON optexpr SEMI_COLON optexpr CLOSE_PAREN stmt {
    fprintf(prod, "repetition -> FOR ( optexpr ; optexpr ; optexpr ) stmt\n");
}
    | DO stmt WHILE OPEN_PAREN expr CLOSE_PAREN SEMI_COLON {
    fprintf(prod, "repetition -> DO stmt WHILE ( expr ) ;\n");
}
    ;

var: type IDENTIFIER {addId($2, $1);} vector SEMI_COLON  {
    fprintf(prod, "var -> type ID vector ;\n");
}
    | type MUL pointer SEMI_COLON {
    fprintf(prod, "var -> type * pointer ;\n");
}
    ;

pointer: IDENTIFIER vector {
        fprintf(prod, "pointer -> ID vector\n");
    }
	| MUL pointer {
        fprintf(prod, "pointer -> * pointer\n");
    }
    ;

funcid: IDENTIFIER  { fprintf(prod, "funcid -> ID\n"); }
    | MAIN          { fprintf(prod, "funcid -> MAIN\n"); }
    | PRINTF        { fprintf(prod, "funcid -> PRINTF\n"); }
    | SCANF         { fprintf(prod, "funcid -> SCANF\n"); }
    | SLICE         { fprintf(prod, "funcid -> SLICE\n"); }
    | SOME          { fprintf(prod, "funcid -> SOME\n"); }
    | REDUCE        { fprintf(prod, "funcid -> REDUCE\n"); }
    | FILTER        { fprintf(prod, "funcid -> FILTER\n"); }
    | MAP           { fprintf(prod, "funcid -> MAP\n"); }
    | SORT          { fprintf(prod, "funcid -> SORT\n"); }
    | FREE          { fprintf(prod, "funcid -> FREE\n"); }
    ;

func: type funcid OPEN_PAREN opttypelist CLOSE_PAREN block {
    fprintf(prod, "func -> type funcid ( opttypelist ) { stmts }\n");
    
}
    | type funcid OPEN_PAREN opttypelist CLOSE_PAREN SEMI_COLON {
    fprintf(prod, "func -> type funcid ( opttypelist ) ;\n");
}
    ;

typelist: typelist COMMA type IDENTIFIER vector {
    fprintf(prod, "typelist -> typelist , type ID\n");
}
    | type IDENTIFIER vector {
        fprintf(prod, "typelist -> type ID vector\n");
    }
    ;

termlist: termlist COMMA term {
    fprintf(prod, "termlist -> termlist , term\n");
}
    | term {
        fprintf(prod, "termlist -> term\n");
    }
    ;

opttypelist: typelist   { fprintf(prod, "opttypelist -> typelist\n"); }
    |                   { fprintf(prod, "opttypelist -> EPS\n"); }
    ;

opttermlist: termlist   { fprintf(prod, "opttermlist -> termlist\n"); }
    |                   { fprintf(prod, "opttermlist -> EPS"); }
    ;

commands: 
    RETURN optexpr SEMI_COLON {
    fprintf(prod, "commands -> RETURN optexpr ;\n");
}
    | BREAK SEMI_COLON {
    fprintf(prod, "commands -> BREAK ;\n");
}
    | CONTINUE SEMI_COLON {
    fprintf(prod, "commands -> continue ;\n");
}
    | TYPEDEF type IDENTIFIER vector SEMI_COLON {
    fprintf(prod, "commands -> TYPEDEF type ID vector ;\n");
}
    | INCLUDE STRING {
    fprintf(prod, "commands -> INCLUDE STRING\n");
}
    | STRUCT IDENTIFIER BLOCK_OPEN varlist BLOCK_CLOSE {
    fprintf(prod, "commands -> STRUCT ID ( varlist )\n");
}
    | ENUM IDENTIFIER BLOCK_OPEN idlist BLOCK_CLOSE {
    fprintf(prod, "commands -> ENUM ID ( idlist )\n");
}
    | UNION IDENTIFIER BLOCK_OPEN varlist BLOCK_CLOSE {
    fprintf(prod, "commands -> UNION ID ( varlist )\n");
}
    | GOTO IDENTIFIER COLON {
    fprintf(prod, "commands -> GOTO ID :\n");
}
    | IDENTIFIER COLON {
    fprintf(prod, "commands -> IDENTIFIER :\n");
}
    | SIZEOF OPEN_PAREN type CLOSE_PAREN SEMI_COLON {
    fprintf(prod, "commands -> SIZEOF ( type ) ;\n");
}   
    ;

varlist: varlist var            { fprintf(prod, "varlist -> varlist var\n"); }
    |                           { fprintf(prod, "varlist -> EPS\n"); }
    ;

idlist: IDENTIFIER COMMA idlist { fprintf(prod, "idlist -> ID , idlist\n"); }
    | IDENTIFIER                { fprintf(prod, "idlist -> ID\n"); }
    ;

optexpr: expr                       { fprintf(prod, "optexpr -> expr\n"); }
    |                               { fprintf(prod, "optexpr -> EPS\n"); }
    ;                           

stmts: stmts stmt                   { fprintf(prod, "stmts -> stmts stmt\n"); }
    |                               { fprintf(prod, "stmts -> EPS\n"); }
    ;

expr: term op expr { 
    fprintf(prod, "expr -> expr op term\n"); 
}                                 
    | term rel expr { 
    fprintf(prod, "expr -> expr rel term\n"); 
}                                 
    | term cond expr { 
    fprintf(prod, "expr -> expr cond term\n"); 
}                         
    | LOGICAL_NOT expr %prec UNARY { 
    fprintf(prod, "expr -> ! expr\n"); 
}                                                  
    | term { 
    fprintf(prod, "expr -> term\n"); 
}                         
    | OPEN_PAREN expr CLOSE_PAREN { 
    fprintf(prod, "expr -> ( expr )\n"); 
}         
    | attr assign expr { 
    fprintf(prod, "expr -> attr assign expr\n"); 
}                
    ;

assign: ASSIGN                  { fprintf(prod, "assign -> =\n"); }
    | ADD_ASSIGN                { fprintf(prod, "assign -> +=\n"); }
    | SUB_ASSIGN                { fprintf(prod, "assign -> -=\n"); }
    | MUL_ASSIGN                { fprintf(prod, "assign -> *=\n"); }
    | DIV_ASSIGN                { fprintf(prod, "assign -> /=\n"); }
    | MOD_ASSIGN                { fprintf(prod, "assign -> %%=\n"); }
    | LEFT_SHIFT_ASSIGN         { fprintf(prod, "assign -> <<=\n"); }
    | RIGHT_SHIFT_ASSIGN        { fprintf(prod, "assign -> >>=\n"); }
    | BITWISE_AND_ASSIGN        { fprintf(prod, "assign -> &=\n"); }
    | BITWISE_OR_ASSIGN         { fprintf(prod, "assign -> |=\n"); }
    | BITWISE_XOR_ASSIGN        { fprintf(prod, "assign -> ^=\n"); }
    ;

op: ADD                         { fprintf(prod, "op -> +\n"); }
    | SUB                       { fprintf(prod, "op -> -\n"); }
    | MUL                       { fprintf(prod, "op -> *\n"); }
    | DIV                       { fprintf(prod, "op -> /\n"); }
    | MOD                       { fprintf(prod, "op -> %%\n"); }
    | BITWISE_AND               { fprintf(prod, "op -> &\n"); }
    | BITWISE_OR                { fprintf(prod, "op -> |\n"); }
    | BITWISE_NOT               { fprintf(prod, "op -> ~\n"); }
    | LEFT_SHIFT                { fprintf(prod, "op -> <<\n"); }
    | RIGHT_SHIFT               { fprintf(prod, "op -> >>\n"); }
    | BITWISE_XOR               { fprintf(prod, "op -> ^\n"); }
    ;

rel: EQ                         { fprintf(prod, "rel -> ==\n"); }
    | NE                        { fprintf(prod, "rel -> !=\n"); }
    | LT                        { fprintf(prod, "rel -> <\n"); }
    | LE                        { fprintf(prod, "rel -> <=\n"); }
    | GT                        { fprintf(prod, "rel -> >\n"); }
    | GE                        { fprintf(prod, "rel -> >=\n"); }
    ;

cond: LOGICAL_AND               { fprintf(prod, "cond -> &&\n"); }
    | LOGICAL_OR                { fprintf(prod, "cond -> ||\n"); }
    ;

term: 
    INTEGER {
    fprintf(prod, "term -> INTEGER\n");
}
    | DECIMAL {
    fprintf(prod, "term -> DECIMAL\n");
}
    | STRING {
    fprintf(prod, "term -> STRING\n");
}
    | boolean {
    fprintf(prod, "term -> boolean\n");
}
    | funcid OPEN_PAREN opttermlist CLOSE_PAREN {
    fprintf(prod, "term -> funcid ( opttermlist )\n");
}
    | attr {
    fprintf(prod, "term -> attr\n");
}
    ;

attr: IDENTIFIER vector {
    fprintf(prod, "attr -> ID vector\n");
}
    | IDENTIFIER vector DOT attr {
    fprintf(prod, "attr -> ID vector . attr\n");
}
    | IDENTIFIER vector POINTER attr {
    fprintf(prod, "attr -> ID vector POINTER attr\n");
}
    ;

boolean: 
    TRUE {
    fprintf(prod, "boolean -> TRUE\n");
}
    | FALSE {
    fprintf(prod, "boolean -> FALSE\n");
}
    ;

vector: vector OPEN_BRACKET expr CLOSE_BRACKET {
    fprintf(prod, "vector -> vector [ expr ]");
}
    |           {
        fprintf(prod, "vector -> EPS\n");
    }
    ;

type: modifier INT              { fprintf(prod, "type -> INT\n"); $$ = type_int; }
    | modifier CHAR             { fprintf(prod, "type -> CHAR\n"); $$ = type_char; }
    | modifier FLOAT            { fprintf(prod, "type -> FLOAT\n"); $$ = type_float; }
    | modifier DOUBLE           { fprintf(prod, "type -> DOUBLE\n"); $$ = type_double; }
    | modifier BOOL             { fprintf(prod, "type -> BOOL\n"); $$ = type_bool; }
    | STRUCT IDENTIFIER         { fprintf(prod, "type -> STRUCT ID\n"); $$ = type_struct; }
    | ENUM IDENTIFIER           { fprintf(prod, "type -> ENUM ID\n"); $$ = type_enum; }
    ;

modifier: UNSIGNED              { fprintf(prod, "modifier -> UNSIGNED\n"); }
    | SIGNED                    { fprintf(prod, "modifier -> SIGNED\n"); }
    | SHORT                     { fprintf(prod, "modifier -> SHORT\n"); }
    | LONG                      { fprintf(prod, "modifier -> LONG\n"); }
    | CONST                     { fprintf(prod, "modifier -> CONST\n"); }
    |                           { fprintf(prod, "modifier -> EPS\n"); }
    ;   

%%

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

int main(void) {
    prod = fopen("producoes.output", "w");
    st = symbolTableNew();
    symbolTableCreateBlock(st);
    yyparse();
    onExit();
    return 0;
}