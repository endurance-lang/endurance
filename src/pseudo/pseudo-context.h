#ifndef PSEUDOCONTEXT_H
#define PSEUDOCONTEXT_H

#include "../symbol-table/symbolTable.h"
#include "inst-stack.h"

typedef struct pseudoContext PseudoContext;

struct pseudoContext
{
    SymbolTable* symbolTable;
    FILE* fileName;
    //LabelStack *if_else, *if_exit, *rep_entry, *rep_exit, *for_stmt, *for_update;
};


PseudoContext *pseudo_ContextNew(FILE* filename,SymbolTable* st);
int pseudoCodeGenAssign(PseudoContext *context, char* var, int reg2);
int pseudoCodeGenInteger(PseudoContext *context, int num);
int pseudoCodeGenBinaryOperator(PseudoContext *context, int op, int reg1, int reg2);
int  pseudoCodeGenUnaryOperator(PseudoContext *context, int op, int reg1);
int pseudoCodeGenVariable(PseudoContext *context,char* var);
void pseudoSaveRegisters(PseudoContext *context);
void pseudoCodeExpr(PseudoContext *context, int reg);
void pseudoCodeElse(PseudoContext *context);
void pseudoCodeExit(PseudoContext *context);
void pseudoCodeRepEntry(PseudoContext *context);
void pseudoCodeRepExpr(PseudoContext *context, int reg);
void pseudoCodeRepExit(PseudoContext *context);
void pseudoCodeForStmtUpdate(PseudoContext *context);
void pseudoCodeForEntryStmt(PseudoContext *context);
void pseudoCodeForUpdateExit(PseudoContext *context);


#endif