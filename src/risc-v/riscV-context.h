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
    LabelStack *if_else, *if_exit;
    LabelStack *rep_entry, *rep_exit, *rep_stmt, *rep_update;
};


RiscVContext *riscV_ContextNew(FILE* filename,SymbolTable* st);
// void getReg();
char* getLabel();
int riscVCodeGenAssign(RiscVContext *context, char* var, int reg2);
int riscVCodeGenInteger(RiscVContext *context, int num);
int riscVCodeGenBinaryOperator(RiscVContext *context, int op, int reg1, int reg2);
int  riscVCodeGenUnaryOperator(RiscVContext *context, int op, int reg1);
int riscVCodeGenVariable(RiscVContext *context,char* var);
void riscVSaveRegisters(RiscVContext *context);
void riscVCodeIfAfterExpr(RiscVContext *context, int reg);
void riscVCodeIfAfterStmt(RiscVContext *context);
void riscVCodeIfAfterElse(RiscVContext *context);
void riscVCodeRepEntry(RiscVContext *context);
void riscVCodeRepAfterExpr(RiscVContext *context, int reg);
void riscVCodeRepExit(RiscVContext *context);
void riscVCodeRepUpdate(RiscVContext *context);
void riscVCodeRepStmt(RiscVContext *context);
void riscVCodeRepGotoEntry(RiscVContext *context);
void riscVCodeRepGotoUpdate(RiscVContext *context);
void riscVCodeExitProgram(RiscVContext *context);

#endif
