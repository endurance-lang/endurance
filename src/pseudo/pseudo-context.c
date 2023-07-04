#include "pseudo-context.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "../lib/types.h"
#include "../lib/translate.tab.h"

static int newlabel = 1;
static int numinstr = 100;


PseudoContext *pseudo_ContextNew(FILE* filename,SymbolTable* st){
    PseudoContext *new = (PseudoContext *) malloc(sizeof(PseudoContext));
    new->fileName = filename;
    new->symbolTable = st;
    new->is = NULL;
    return new;
}


int pseudoCodeGenAssign(PseudoContext *context, char* var, int reg2){
    int instr = numinstr++;
    int tempdes = newlabel++;
    fprintf(context->fileName, "%d: %s = t%d\n",instr, var, reg2);
    instr = numinstr++;
    fprintf(context->fileName, "%d: t%d = %s\n",instr, tempdes, var);
    return tempdes;
}


int pseudoCodeGenInteger(PseudoContext *context, int num){
    int tempdes = newlabel++;
    int instr = numinstr++;
    fprintf(context->fileName,"%d: t%d = %d\n",instr, tempdes,num);
    return tempdes;
}

int pseudoCodeGenBinaryOperator(PseudoContext *context, int op, int reg1, int reg2){
    int tempdes = newlabel++;
    int instr = numinstr++;
    switch (op)
    {
    case ADD:
        fprintf(context->fileName,"%d: t%d = t%d + t%d\n",instr,tempdes,reg1,reg2);
        break;
    case SUB:
        fprintf(context->fileName,"%d: t%d = t%d - t%d\n",instr,tempdes,reg1,reg2);
        break;
    case MUL:
        fprintf(context->fileName,"%d: t%d = t%d * t%d\n",instr,tempdes,reg1,reg2);
        break;
    case DIV:
        fprintf(context->fileName,"%d: t%d = t%d / t%d\n",instr,tempdes,reg1,reg2);
        break;
    case BITWISE_AND:
        fprintf(context->fileName,"%d: t%d = t%d && t%d\n",instr,tempdes,reg1,reg2);
        break;
    case BITWISE_NOT:
        fprintf(context->fileName,"%d: t%d = t%d ~ t%d\n",instr,tempdes,reg1,reg2);
        break;
    case BITWISE_OR:
        fprintf(context->fileName,"%d: t%d = t%d || t%d\n",instr,tempdes,reg1,reg2);
        break;
    case BITWISE_XOR:
        fprintf(context->fileName,"%d: t%d = t%d ^ t%d\n",instr,tempdes,reg1,reg2);
        break;
    case LT:
        fprintf(context->fileName,"%d: t%d = t%d < t%d\n",instr,tempdes,reg1,reg2);
        break;
    case GT:
        fprintf(context->fileName,"%d: t%d = t%d > t%d\n",instr,tempdes,reg1,reg2);
        break;
    case LE:
        fprintf(context->fileName,"%d: t%d = t%d <= t%d\n",instr,tempdes,reg1,reg2);
        break;
    case GE:
        fprintf(context->fileName,"%d: t%d = t%d >= t%d\n", instr,tempdes,reg1,reg2);
        break;
    case EQ:
        fprintf(context->fileName,"%d: t%d = t%d == t%d\n", instr,tempdes,reg1,reg2);
        break;
    case NE:
        fprintf(context->fileName,"%d: t%d = t%d != t%d\n", instr,tempdes,reg1,reg2);
        break;
    default:
        printf("Unknow Operation %d\n", op);
        exit(0);
        break;
    }
    return tempdes;
}

int  pseudoCodeGenUnaryOperator(PseudoContext *context, int op, int reg1){
    int tempdes = newlabel++;
    int instr = numinstr++;
    switch (op)
    {
    case LOGICAL_NOT:
        fprintf(context->fileName,"%d: t%d = !t%d\n",instr, tempdes, reg1);
        break;
    case SUB:
        fprintf(context->fileName,"%d: t%d = -t%d\n",instr, tempdes,reg1);
        break;
    default:
        printf("riscV-context.h  emit -> Impossivel fazer %d no risc-V\n",op);
        exit(0);
        break;
    }
    return tempdes;
}


int pseudoCodeGenVariable(PseudoContext *context,char* var){
    int tempdes = newlabel++;
    int instr = numinstr++;
    fprintf(context->fileName,"%d: t%d = %s\n",instr,tempdes,var);
    return tempdes;
}


void pseudoCodeAfterElse(PseudoContext *context){
    // fprintf(context->fileName,"");
}
void pseudoCodeExit(PseudoContext *context);
void pseudoCodeRepEntry(PseudoContext *context);
void pseudoCodeRepExpr(PseudoContext *context, int reg);
void pseudoCodeRepExit(PseudoContext *context);
void pseudoCodeForStmtUpdate(PseudoContext *context);
void pseudoCodeForEntryStmt(PseudoContext *context);
void pseudoCodeForUpdateExit(PseudoContext *context);

