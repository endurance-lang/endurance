%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../symbol-table/symbolTable.h"
#include "../utils/print-source-code.h"
#include "../risc-v/riscV-context.h"
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

int nextAddress = 0;

void blockOpen();
void blockClose();

// void handleStruct();
void handleVar(char *type, char *id, int size);
ExprData handleAttr(char *id);
void handleOperation(int opcode, ...);
ExprData handleBinaryExpr(int opcode, ExprData e1, ExprData e2);
ExprData handleAssignExpr(char *id, ExprData e);
void reportAndExit(const char *s, ...);

char *mergeStrPointers(char *a, char *b);

void handleCondExpr(ExprData e);
void handleCondElse();
void handleCondExit();

struct label_stack {
    char *label;
    struct label_stack *next;
};

// void addLabel(struct label_stack **lst, char *label) {
//     struct label_stack *new = (struct label_stack *) malloc(sizeof(struct label_stack));
//     new->label = label;
//     new->next = *lst;
//     *lst = new;
// }

// char *useLabel(struct label_stack **lst) {
//     char *label = (*lst)->label;
//     struct label_stack *aux;
//     *lst = (*lst)->next;
//     free(aux);
//     return label;
// }

// struct label_stack *stack = NULL;

char *currentLabelExit;
char *currentLabelElse;

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

conditional: IF OPEN_PAREN condexpr CLOSE_PAREN stmt %prec IFX { handleCondElse(); handleCondExit(); }
    | IF OPEN_PAREN condexpr CLOSE_PAREN stmt ELSE { handleCondElse();  } stmt { handleCondExit(); }
    | SWITCH OPEN_PAREN condexpr CLOSE_PAREN BLOCK_OPEN caselist BLOCK_CLOSE {  }
    ;

condexpr: expr                  { handleCondExpr($1); }
    ;

caselist: caselist CASE term COLON stmts    {  }
    | caselist DEFAULT COLON stmts          {  }
    |                                       {  }
    ;

repetition: WHILE OPEN_PAREN expr CLOSE_PAREN stmt {}
    | FOR OPEN_PAREN optexpr SEMI_COLON optexpr SEMI_COLON optexpr CLOSE_PAREN stmt {}
    | DO stmt WHILE OPEN_PAREN expr CLOSE_PAREN SEMI_COLON {}
    ;

var: IDENTIFIER IDENTIFIER constvector { handleVar($1, $2, $3); }
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
    |                               { }
    ;                           

expr: expr ADD expr { $$ = handleBinaryExpr(ADD, $1, $3); }
    | expr SUB expr { $$ = handleBinaryExpr(SUB, $1, $3); }
    | expr MUL expr { /* geraTemp1, geraTemp2, chama codeGen(t1, op, t2) */ }
    | expr DIV expr { /* geraTemp1, geraTemp2, chama codeGen(t1, op, t2) */ }
    | expr MOD expr { /* geraTemp1, geraTemp2, chama codeGen(t1, op, t2) */ }
    | expr BITWISE_AND expr     { /* geraTemp1, geraTemp2, chama codeGen(t1, op, t2) */ }
    | expr BITWISE_OR expr      { /* geraTemp1, geraTemp2, chama codeGen(t1, op, t2) */ }
    | expr BITWISE_NOT expr     { /* geraTemp1, geraTemp2, chama codeGen(t1, op, t2) */ }
    | expr BITWISE_XOR expr     { /* geraTemp1, geraTemp2, chama codeGen(t1, op, t2) */ }
    | expr LEFT_SHIFT expr      { $$ = handleBinaryExpr(LEFT_SHIFT, $1, $3); }
    | expr RIGHT_SHIFT expr     { $$ = handleBinaryExpr(RIGHT_SHIFT, $1, $3); }
    | expr EQ expr { /* geraTemp1, geraTemp2, chama codeGen(t1, op, t2) */ }
    | expr NE expr { /* geraTemp1, geraTemp2, chama codeGen(t1, op, t2) */ }
    | expr LT expr { /* geraTemp1, geraTemp2, chama codeGen(t1, op, t2) */ }
    | expr GT expr { /* geraTemp1, geraTemp2, chama codeGen(t1, op, t2) */ }
    | expr LE expr { /* geraTemp1, geraTemp2, chama codeGen(t1, op, t2) */ }
    | expr GE expr { /* geraTemp1, geraTemp2, chama codeGen(t1, op, t2) */ }
    | expr LOGICAL_AND expr         { $$ = handleBinaryExpr(LOGICAL_AND, $1, $3); }
    | expr LOGICAL_OR expr          { $$ = handleBinaryExpr(LOGICAL_OR, $1, $3); }
    | OPEN_PAREN expr CLOSE_PAREN   { $$ = $2; }
    | LOGICAL_NOT expr %prec UNARY  { /* geraTemp1, chama codeGen(op, t1) */ }
    | SUB expr %prec UNARY          {  }
    | term                          { $$ = $1; }
    | attr ASSIGN expr              { $$ = handleAssignExpr($1, $3); }
    | SIZEOF IDENTIFIER             { /* return symbol table size of identifier */ }
    ;


term: const { $$ = $1; }
    | IDENTIFIER OPEN_PAREN opttermlist CLOSE_PAREN { /* cria a funcao e fala o temp */ }
    | attr { $$ = handleAttr($1); }
    ;

attr: IDENTIFIER exprvector     { $$ = $1; }
    | attr POINTER attr         { $$ = mergeStrPointers($1, $3); }
    ;

const: INTEGER          { $$.returnType = strdup("jib"); $$.reg = riscVCodeGenInteger(riscv, $1); }
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
void handleVar(char *type, char *id, int size) {
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

    return ret;
}

ExprData handleAssignExpr(char *id, ExprData e) {
    Symbol *sym = symbolTableFind(st, id);

    if(strcmp(sym->data.variable.type, e.returnType)) reportAndExit("Impossivel atribuir um valor do tipo \"%s\" para uma variavel do tipo \"%s\".", e.returnType, sym->data.variable.type);

    ExprData ret;
    ret.returnType = e.returnType;
    ret.reg = riscVCodeGenAssign(riscv, id, e.reg);
}

void handleCondExpr(ExprData e) {
    currentLabelElse = getLabel();
    currentLabelExit = getLabel();
    fprintf(friscv, "BEQ x0, x%d, %s\n", e.reg, currentLabelElse);
    /* saddLabel(&stack, label); */
}

void handleCondElse() {
    fprintf(friscv, "BEQ x0, x0, %s\n", currentLabelExit);
    fprintf(friscv, "%s:\n", currentLabelElse);
}

void handleCondExit() {
    fprintf(friscv, "%s:\n", currentLabelExit);
}

/* void handleOperation(int opcode, ...) {
    va_list args;
    va_start(args, opcode);

    switch(opcode) {
    case ASSIGN: {
        STNIdentifier *left = STN_IDENTIFIER(va_arg(args, SyntaxTreeNode*));
        STNOperation *right = STN_OPERATION(va_arg(args, SyntaxTreeNode*));

        Symbol *sym_id = symbolTableFind(st, left->id);
        if(!sym_id) reportAndExit("Variável \"%s\" nao declarada\n", left->id);
        if(sym_id->type != SymbolTypeVariable) reportAndExit("\"%s\" nao e uma variavel\n", left->id);
        STNReturnExec r = stnExecute(STN(right));
        if(strcmp(sym_id->datatype, r.type)) 
            reportAndExit("Impossivel assinalar um valor do tipo \"%s\" para uma variavel do tipo \"%s\"\n", r.type, sym_id->datatype);
        fprintf(gen, "addi Rd, R%d, 0\n", r.temp);
        break;
    }
    default: reportAndExit("Invalid Operation\n");
    };

    va_end(args);
} */

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

    friscv = fopen("./build/riscv.asm", "w");
    riscv = riscV_ContextNew(friscv, st);



    symbolTableCreateBlock(st);
    
    // jib a;
    // symbol {a, variavel, jib, 4, 0}
    
    
    symbolTableInsert(st, symbolTypeNew("jib", 4));
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