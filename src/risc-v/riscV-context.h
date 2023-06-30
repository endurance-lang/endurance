#ifndef RISCVCONTEXT_H
#define RISCVCONTEXT_H

#include <stdlib.h>
#include "../symbol-table/symbolTable.h"
#include "register-manager.h"

typedef struct riscVcontext RiscVContext;

struct riscVcontext
{
    SymbolTable* symbolTable;
    FILE* fileName;
    RManager* rm;
};


RiscVContext *riscV_ContextNew(FILE* filename,SymbolTable* st);
// void getReg();
char* getLabel();
void codeGenAssign(RiscVContext *context, char* var, int reg2);
int codeGenInteger(RiscVContext *context, int num);
void codeGenBinaryOperator(RiscVContext *context, int op, int reg1, int reg2);
int codeGenVariable(RiscVContext *context,char* var);

#endif
