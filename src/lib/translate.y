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

FILE *dot;
int nextLabel = 0;


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

%}

%union {
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
};

%token INCLUDE MAIN BREAK CASE CONST CONTINUE DEFAULT IF ELSE ENUM RETURN STRUCT DO PRINTF SCANF FOR GOTO SIZEOF SWITCH TYPEDEF UNION WHILE FREE POINTER SLICE SOME REDUCE FILTER MAP SORT CLOSE_BRACKET OPEN_BRACKET CLOSE_PAREN OPEN_PAREN BLOCK_CLOSE BLOCK_OPEN ADD SUB MUL DIV BITWISE_AND BITWISE_OR BITWISE_NOT MOD LEFT_SHIFT RIGHT_SHIFT LT GT LE GE EQ NE BITWISE_XOR LOGICAL_AND LOGICAL_OR LOGICAL_NOT COLON SEMI_COLON ASSIGN COMMA INVALID UMINUS

%token DECIMAL STRING DOT

%token <data> IDENTIFIER
%token <data> INTEGER
%token <data> TRUE FALSE

%type <data> constvector boolean attr expr term const exprvector exprlist optexprlist program stmts stmt conditional condexpr repetition repexpr var func typelist opttypelist commands varlist idlist optexpr

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

program: stmts { $$.node_id = nextLabel++; fprintf(dot, "n%d [label=\"program\"]\n", $$.node_id); fprintf(dot, "n%d -- n%d\n", $$.node_id, $1.node_id); }
    ;

stmts: stmts stmt                   { 
                                        $$.node_id = nextLabel++; 
                                        fprintf(dot, "n%d [label=\"stmts\"]\n", $$.node_id);
                                        fprintf(dot, "n%d -- {n%d n%d}\n", $$.node_id, $1.node_id, $2.node_id); 
                                    }
    | /* EPS */                     { 
                                        $$.node_id = nextLabel++; 
                                        int eps = nextLabel++; 
                                        fprintf(dot, "n%d [label=\"stmts\"]\n", $$.node_id);
                                        fprintf(dot, "n%d [label=\"&#x03B5;\"]\n",eps); 
                                        fprintf(dot, "n%d -- n%d\n", $$.node_id, eps); 
                                    }
    ;

stmt: conditional               { 
                                    $$.node_id = nextLabel++; 
                                    fprintf(dot, "n%d [label=\"stmt\"]\n", $$.node_id); 
                                    fprintf(dot, "n%d -- n%d\n", $$.node_id, $1.node_id);
                                }
    | repetition                { 
                                    $$.node_id = nextLabel++; 
                                    fprintf(dot, "n%d [label=\"stmt\"]\n", $$.node_id); 
                                    fprintf(dot, "n%d -- n%d\n", $$.node_id, $1.node_id);
                                }
    | func                      { 
                                    $$.node_id = nextLabel++; 
                                    fprintf(dot, "n%d [label=\"stmt\"]\n", $$.node_id); 
                                    fprintf(dot, "n%d -- n%d\n", $$.node_id, $1.node_id);
                                }
    | var SEMI_COLON            { 
                                    $$.node_id = nextLabel++; 
                                    int semicolon = nextLabel++; 
                                    fprintf(dot, "n%d [label=\"stmt\"]\n", $$.node_id);  
                                    fprintf(dot, "n%d [label=\";\"]\n", semicolon); 
                                    fprintf(dot, "n%d -- {n%d n%d}\n", $$.node_id, $1.node_id, semicolon); }
    | commands                  {  }
    | expr SEMI_COLON           {  }
    | BLOCK_OPEN stmts BLOCK_CLOSE {  }

conditional: IF OPEN_PAREN condexpr CLOSE_PAREN stmt %prec IFX { handleIfAfterStmt(); handleIfAfterElse(); }
    | IF OPEN_PAREN condexpr CLOSE_PAREN stmt ELSE { handleIfAfterStmt(); } stmt { handleIfAfterElse(); }
    /* | SWITCH OPEN_PAREN expr CLOSE_PAREN BLOCK_OPEN caselist BLOCK_CLOSE {  } */
    ;

condexpr: expr                  { handleIfAfterExpr($1.data.exprData); }
    ;

/* caselist: caselist CASE term COLON stmts    {  }
    | caselist DEFAULT COLON stmts          {  }
    |                                       {  }
    ; */

repetition: WHILE {handleRepEntry();} OPEN_PAREN repexpr CLOSE_PAREN {handleRepStmt();} stmt {handleRepGotoEntry();handleRepExit();}

    | FOR OPEN_PAREN optexpr {handleRepEntry();} SEMI_COLON repexpr SEMI_COLON {handleRepUpdate();} optexpr CLOSE_PAREN {handleRepGotoEntry();handleRepStmt();} stmt {handleRepGotoUpdate();handleRepExit();}

    /* | DO {handleRepEntry();handleRepStmt();} stmt WHILE OPEN_PAREN repexpr CLOSE_PAREN SEMI_COLON {handleRepExit();} */
    ;

repexpr: expr { handleRepAfterExpr($1.data.exprData); }
    ;

var: IDENTIFIER IDENTIFIER constvector { handleVarDeclaration($1.data.string, $2.data.string, $3.data.integer); }
    ;

func: IDENTIFIER IDENTIFIER {} OPEN_PAREN opttypelist CLOSE_PAREN BLOCK_OPEN stmts BLOCK_CLOSE {}
    ;

typelist: typelist COMMA var {}
    | var {}
    ;

exprlist: exprlist COMMA expr { functAddParam(&$1.data.paramList, $3.data.exprData.reg, $3.data.exprData.returnType); }
    | expr { $$.data.paramList = NULL; functAddParam(&$$.data.paramList, $1.data.exprData.reg, $1.data.exprData.returnType); }
    ;

opttypelist: typelist   {  }
    |                   {  }
    ;

optexprlist: exprlist   { $$.data.paramList = $1.data.paramList; }
    |                   { $$.data.paramList = NULL; }
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

expr: expr ADD expr { $$.data.exprData = handleBinaryExpr(ADD, $1.data.exprData, $3.data.exprData); }
    | expr SUB expr { $$.data.exprData = handleBinaryExpr(SUB, $1.data.exprData, $3.data.exprData); }
    | expr MUL expr { $$.data.exprData = handleBinaryExpr(MUL, $1.data.exprData, $3.data.exprData); }
    | expr DIV expr { $$.data.exprData = handleBinaryExpr(DIV, $1.data.exprData, $3.data.exprData); }
    | expr MOD expr { /* geraTemp1, geraTemp2, chama codeGen(t1, op, t2) */ }
    | expr BITWISE_AND expr     { $$.data.exprData = handleBinaryExpr(BITWISE_AND, $1.data.exprData, $3.data.exprData); }
    | expr BITWISE_OR expr      { $$.data.exprData = handleBinaryExpr(BITWISE_OR, $1.data.exprData, $3.data.exprData); }
    | expr BITWISE_NOT expr     { $$.data.exprData = handleBinaryExpr(BITWISE_NOT, $1.data.exprData, $3.data.exprData); }
    | expr BITWISE_XOR expr     { $$.data.exprData = handleBinaryExpr(BITWISE_XOR, $1.data.exprData, $3.data.exprData); }
    | expr LEFT_SHIFT expr      { $$.data.exprData = handleBinaryExpr(LEFT_SHIFT, $1.data.exprData, $3.data.exprData); }
    | expr RIGHT_SHIFT expr     { $$.data.exprData = handleBinaryExpr(RIGHT_SHIFT, $1.data.exprData, $3.data.exprData); }
    | expr EQ expr { $$.data.exprData = handleBinaryExpr(EQ, $1.data.exprData, $3.data.exprData); }
    | expr NE expr { $$.data.exprData = handleBinaryExpr(NE, $1.data.exprData, $3.data.exprData); }
    | expr LT expr { $$.data.exprData = handleBinaryExpr(LT, $1.data.exprData, $3.data.exprData); }
    | expr GT expr { $$.data.exprData = handleBinaryExpr(GT, $1.data.exprData, $3.data.exprData); }
    | expr LE expr { $$.data.exprData = handleBinaryExpr(LE, $1.data.exprData, $3.data.exprData); }
    | expr GE expr { $$.data.exprData = handleBinaryExpr(GE, $1.data.exprData, $3.data.exprData); }
    | expr LOGICAL_AND expr         { $$.data.exprData = handleBinaryExpr(LOGICAL_AND, $1.data.exprData, $3.data.exprData); }
    | expr LOGICAL_OR expr          { $$.data.exprData = handleBinaryExpr(LOGICAL_OR, $1.data.exprData, $3.data.exprData); }
    | OPEN_PAREN expr CLOSE_PAREN   { $$.data.exprData = $2.data.exprData; }
    | LOGICAL_NOT expr %prec UNARY  { $$.data.exprData = handleUnaryExpr(LOGICAL_NOT, $2.data.exprData); }
    | SUB expr %prec UNARY          { $$.data.exprData = handleUnaryExpr(SUB, $2.data.exprData); }
    | term                          { $$.data.exprData = $1.data.exprData; }
    | attr ASSIGN expr              { $$.data.exprData = handleAssignExpr($1.data.string, $3.data.exprData); }
    | SIZEOF IDENTIFIER             { /* return symbol table size of identifier */ }
    ;


term: const { $$.data.exprData = $1.data.exprData; }
    | IDENTIFIER OPEN_PAREN optexprlist CLOSE_PAREN { $$.data.exprData = handleFunctionCall($1.data.string, $3.data.paramList); }
    | attr { $$.data.exprData = handleAttr($1.data.string); }
    ;

attr: IDENTIFIER exprvector     { $$.data.string = $1.data.string; }
    | attr POINTER attr         { $$.data.string = mergeStrPointers($1.data.string, $3.data.string); }
    ;

const: INTEGER          { $$.data.exprData = handleInteger($1.data.integer); }
    | DECIMAL           { $$.data.exprData.returnType = strdup("ship"); $$.data.exprData.reg = 0;  }
    | STRING            { /* chama codeGen() e retorna o Temporary */  }
    | boolean           { /* chama codeGen() e retorna o Temporary */  }

boolean: TRUE                   { $$.data.boolean = $1.data.boolean; }
    | FALSE                     { $$.data.boolean = $1.data.boolean; }
    ;

exprvector:
    OPEN_BRACKET expr CLOSE_BRACKET { $$.data.exprData = $2.data.exprData; }
    | /* EPS */                     {  }
    ;

constvector: 
    OPEN_BRACKET INTEGER CLOSE_BRACKET { $$.data.integer = $2.data.integer; }
    | /* EPS */                     { $$.data.integer = 1; }
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