#ifndef RISCVCONTEXT_H
#define RISCVCONTEXT_H

#include <stdlib.h>
#include "../symbol-table/symbolTable.h"
#include "register-manager.h"
#include "label-stack.h"

typedef struct riscVcontext RiscVContext;

struct riscVcontext
{
    SymbolTable* symbolTable;
    FILE* fileName;
    RManager* rm;
    LabelStack *if_else, *if_exit, *rep_entry, *rep_exit, *for_stmt, *for_update;
};


RiscVContext *riscV_ContextNew(FILE* filename,SymbolTable* st);
// void getReg();
char* getLabel();
int riscVCodeGenAssign(RiscVContext *context, char* var, int reg2);
int riscVCodeGenInteger(RiscVContext *context, int num);
int riscVCodeGenBinaryOperator(RiscVContext *context, int op, int reg1, int reg2);
int riscVCodeGenVariable(RiscVContext *context,char* var);
void riscVSaveRegisters(RiscVContext *context);
void riscVCodeExpr(RiscVContext *context, int reg);
void riscVCodeElse(RiscVContext *context);
void riscVCodeExit(RiscVContext *context);

#endif
