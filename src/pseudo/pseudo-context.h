#ifndef PSEUDOCONTEXT_H
#define PSEUDOCONTEXT_H

#include "../symbol-table/symbolTable.h"
#include "inst-stack.h"

typedef struct pseudoContext PseudoContext;

struct pseudoContext
{
    SymbolTable* symbolTable;
    FILE* fileName;
    InstructionStack *ifs, *elses, *repentry, *repexit, *repstmt, *repupdate;
};


PseudoContext *pseudo_ContextNew(FILE* filename,SymbolTable* st);
int pseudoCodeGenAssign(PseudoContext *context, char* var, int reg2);
int pseudoCodeGenInteger(PseudoContext *context, int num);
int pseudoCodeGenBinaryOperator(PseudoContext *context, int op, int reg1, int reg2);
int  pseudoCodeGenUnaryOperator(PseudoContext *context, int op, int reg1);
int pseudoCodeGenVariable(PseudoContext *context,char* var);
void pseudoCodeIfAfterExpr(PseudoContext *context, int reg);
void pseudoCodeIfAfterStmt(PseudoContext *context);
void pseudoCodeIfAfterElse(PseudoContext *context);
void pseudoCodeRepEntry(PseudoContext *context);
void pseudoCodeRepAfterExpr(PseudoContext *context, int reg);
void pseudoCodeRepExit(PseudoContext *context);
void pseudoCodeRepUpdate(PseudoContext *context);
void pseudoCodeRepStmt(PseudoContext *context);
void pseudoCodeRepGotoEntry(PseudoContext *context);
void pseudoCodeRepGotoUpdate(PseudoContext *context);


#endif