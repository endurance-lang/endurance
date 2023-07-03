#include "pseudo-context.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "../lib/types.h"
#include "../lib/translate.tab.h"



void pseudoCodeExpr(PseudoContext *context, int reg);
void pseudoCodeElse(PseudoContext *context);
void pseudoCodeExit(PseudoContext *context);
void pseudoCodeRepEntry(PseudoContext *context);
void pseudoCodeRepExpr(PseudoContext *context, int reg);
void pseudoCodeRepExit(PseudoContext *context);
void pseudoCodeForStmtUpdate(PseudoContext *context);
void pseudoCodeForEntryStmt(PseudoContext *context);

void pseudoCodeForUpdateExit(PseudoContext *context) {
    fprintf(context->fileName, "goto %d\n", context->for_update->instr);
    

    instStackPop(&context->rep_entry);
    instStackPop(&context->rep_exit);
    instStackPop(&context->for_stmt);
    instStackPop(&context->for_update);
}