%{
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

void handleFunctionCall();

ExprData handleInteger(int integer);

%}


%union {
    char *string;
    int integer;
    double decimal;
    int boolean;
    ExprData exprData;
};

%token INCLUDE MAIN BREAK CASE CONST CONTINUE DEFAULT IF ELSE ENUM RETURN STRUCT DO PRINTF SCANF FOR GOTO SIZEOF SWITCH TYPEDEF UNION WHILE FREE POINTER SLICE SOME REDUCE FILTER MAP SORT CLOSE_BRACKET OPEN_BRACKET CLOSE_PAREN OPEN_PAREN BLOCK_CLOSE BLOCK_OPEN ADD SUB MUL DIV BITWISE_AND BITWISE_OR BITWISE_NOT MOD LEFT_SHIFT RIGHT_SHIFT LT GT LE GE EQ NE BITWISE_XOR LOGICAL_AND LOGICAL_OR LOGICAL_NOT COLON SEMI_COLON ASSIGN COMMA INVALID UMINUS

%token DECIMAL STRING DOT

%token <string> IDENTIFIER
%token <integer> INTEGER
%token <boolean> TRUE FALSE

%type <integer> constvector
%type <boolean> boolean
%type <string> attr
%type <exprData> expr term const exprvector

%start program

%left COMMA
%right ASSIGN
%right COLON
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
%right LOGICAL_NOT SIZEOF BITWISE_NOT
%left OPEN_PAREN CLOSE_PAREN OPEN_BRACKET CLOSE_BRACKET POINTER

%nonassoc IFX
%nonassoc ELSE
%nonassoc UNARY

%%

program: stmts {  }
    ;

stmts: stmts stmt                   {  }
    |                               {  }
    ;

stmt: conditional               {  }
    | repetition                {  }
    | func                      {  }
    | var SEMI_COLON            {  }
    | commands                  {  }
    | expr SEMI_COLON           {  }
    | BLOCK_OPEN stmts BLOCK_CLOSE {  }

conditional: IF OPEN_PAREN condexpr CLOSE_PAREN stmt %prec IFX { handleIfAfterStmt(); handleIfAfterElse(); }
    | IF OPEN_PAREN condexpr CLOSE_PAREN stmt ELSE { handleIfAfterStmt(); } stmt { handleIfAfterElse(); }
    /* | SWITCH OPEN_PAREN expr CLOSE_PAREN BLOCK_OPEN caselist BLOCK_CLOSE {  } */
    ;

condexpr: expr                  { handleIfAfterExpr($1); }
    ;

/* caselist: caselist CASE term COLON stmts    {  }
    | caselist DEFAULT COLON stmts          {  }
    |                                       {  }
    ; */

repetition: WHILE {handleRepEntry();} OPEN_PAREN repexpr CLOSE_PAREN {handleRepStmt();} stmt {handleRepGotoEntry();handleRepExit();}

    | FOR OPEN_PAREN optexpr {handleRepEntry();} SEMI_COLON repexpr SEMI_COLON {handleRepUpdate();} optexpr CLOSE_PAREN {handleRepGotoEntry();handleRepStmt();} stmt {handleRepGotoUpdate();handleRepExit();}

    | DO {handleRepEntry();handleRepStmt();} stmt WHILE OPEN_PAREN repexpr CLOSE_PAREN SEMI_COLON {handleRepExit();}
    ;

repexpr: expr { handleRepAfterExpr($1); }
    ;

var: IDENTIFIER IDENTIFIER constvector { handleVarDeclaration($1, $2, $3); }
    ;

func: IDENTIFIER IDENTIFIER {} OPEN_PAREN opttypelist CLOSE_PAREN BLOCK_OPEN stmts BLOCK_CLOSE {}
    ;

typelist: typelist COMMA var {}
    | var {}
    ;

termlist: termlist COMMA term {}
    | term {  }
    ;

opttypelist: typelist   {  }
    |                   {  }
    ;

opttermlist: termlist   {  }
    |                   {  }
    ;

commands: 
    RETURN optexpr SEMI_COLON {}
    | BREAK SEMI_COLON {}
    | CONTINUE SEMI_COLON {}
    | TYPEDEF IDENTIFIER IDENTIFIER SEMI_COLON {}
    | INCLUDE STRING SEMI_COLON {}
    | STRUCT IDENTIFIER BLOCK_OPEN varlist BLOCK_CLOSE { }
    | ENUM IDENTIFIER BLOCK_OPEN idlist BLOCK_CLOSE { }
    ;

varlist: varlist var SEMI_COLON     {  }
    |                               {  }
    ;

idlist: IDENTIFIER COMMA idlist     {  }
    | IDENTIFIER                    {  }
    ;

optexpr: expr                       {  }
    |                               {  }
    ;                           

expr: expr ADD expr { $$ = handleBinaryExpr(ADD, $1, $3); }
    | expr SUB expr { $$ = handleBinaryExpr(SUB, $1, $3); }
    | expr MUL expr { $$ = handleBinaryExpr(MUL, $1, $3); }
    | expr DIV expr { $$ = handleBinaryExpr(DIV, $1, $3); }
    | expr MOD expr { /* geraTemp1, geraTemp2, chama codeGen(t1, op, t2) */ }
    | expr BITWISE_AND expr     { $$ = handleBinaryExpr(BITWISE_AND, $1, $3); }
    | expr BITWISE_OR expr      { $$ = handleBinaryExpr(BITWISE_OR, $1, $3); }
    | expr BITWISE_NOT expr     { $$ = handleBinaryExpr(BITWISE_NOT, $1, $3); }
    | expr BITWISE_XOR expr     { $$ = handleBinaryExpr(BITWISE_XOR, $1, $3); }
    | expr LEFT_SHIFT expr      { $$ = handleBinaryExpr(LEFT_SHIFT, $1, $3); }
    | expr RIGHT_SHIFT expr     { $$ = handleBinaryExpr(RIGHT_SHIFT, $1, $3); }
    | expr EQ expr { $$ = handleBinaryExpr(EQ, $1, $3); }
    | expr NE expr { $$ = handleBinaryExpr(NE, $1, $3); }
    | expr LT expr { $$ = handleBinaryExpr(LT, $1, $3); }
    | expr GT expr { $$ = handleBinaryExpr(GT, $1, $3); }
    | expr LE expr { $$ = handleBinaryExpr(LE, $1, $3); }
    | expr GE expr { $$ = handleBinaryExpr(GE, $1, $3); }
    | expr LOGICAL_AND expr         { $$ = handleBinaryExpr(LOGICAL_AND, $1, $3); }
    | expr LOGICAL_OR expr          { $$ = handleBinaryExpr(LOGICAL_OR, $1, $3); }
    | OPEN_PAREN expr CLOSE_PAREN   { $$ = $2; }
    | LOGICAL_NOT expr %prec UNARY  { $$ = handleUnaryExpr(LOGICAL_NOT, $2); }
    | SUB expr %prec UNARY          { $$ = handleUnaryExpr(SUB, $2); }
    | term                          { $$ = $1; }
    | attr ASSIGN expr              { $$ = handleAssignExpr($1, $3); }
    | SIZEOF IDENTIFIER             { /* return symbol table size of identifier */ }
    ;


term: const { $$ = $1; }
    | IDENTIFIER OPEN_PAREN opttermlist CLOSE_PAREN { handleFunctionCall($1); }
    | attr { $$ = handleAttr($1); }
    ;

attr: IDENTIFIER exprvector     { $$ = $1; }
    | attr POINTER attr         { $$ = mergeStrPointers($1, $3); }
    ;

const: INTEGER          { $$ = handleInteger($1); }
    | DECIMAL           { $$.returnType = strdup("ship"); $$.reg = 0;  }
    | STRING            { /* chama codeGen() e retorna o Temporary */  }
    | boolean           { /* chama codeGen() e retorna o Temporary */  }

boolean: TRUE                   { $$ = $1; }
    | FALSE                     { $$ = $1; }
    ;

exprvector:
    OPEN_BRACKET expr CLOSE_BRACKET { $$ = $2; }
    | /* EPS */                     {  }
    ;

constvector: 
    OPEN_BRACKET INTEGER CLOSE_BRACKET { $$ = $2; }
    | /* EPS */                     { $$ = 1; }
    ; 

%%

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
}

void handleFunctionCall(char *func) {
    if(!strcmp(func, "parrot")) {
        fprintf(friscv, "li a0, 1\n");
        fprintf(friscv, "li a1, 42\n");
        fprintf(friscv, "ecall\n");
        return;
    }
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

    fclose(gen);
    fclose(prod);
    fclose(friscv);
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


    symbolTableCreateBlock(st);
    
    // jib a;
    // symbol {a, variavel, jib, 4, 0}
    
    
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