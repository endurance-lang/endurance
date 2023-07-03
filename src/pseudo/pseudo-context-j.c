#include "pseudo-context.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "../lib/types.h"
#include "../lib/translate.tab.h"

static int newlabel = 1;


PseudoContext *pseudo_ContextNew(FILE* filename,SymbolTable* st){
    PseudoContext *new = (PseudoContext *) malloc(sizeof(PseudoContext));
    new->fileName = filename;
    new->symbolTable = st;
    return new;
}


int pseudoCodeGenAssign(PseudoContext *context, char* var, int reg2){
    int tempdes = newlabel++;
    fprintf(context->fileName, "%s = t%d\n", var, tempdes);
    return tempdes;
}


int pseudoCodeGenInteger(PseudoContext *context, int num){
    int tempdes = newlabel++;
    fprintf(context->fileName,"t%d = %d",tempdes,num);
    return tempdes;
}

int pseudoCodeGenBinaryOperator(PseudoContext *context, int op, int reg1, int reg2){
    int tempdes = newlabel++;
    switch (op)
    {
    case ADD:
        fprintf(context->fileName,"t%d = t%d + t%d");
        break;
    case SUB:
        fprintf(context->fileName,"t%d = t%d - t%d");
        break;
    case MUL:
        fprintf(context->fileName,"t%d = t%d * t%d");
        break;
    case DIV:
        fprintf(context->fileName,"t%d = t%d / t%d");
        break;
    case BITWISE_AND:
        fprintf(context->fileName,"t%d = t%d && t%d");
        break;
    case BITWISE_NOT:
        fprintf(context->fileName,"t%d = t%d ~ t%d");
        break;
    case BITWISE_OR:
        fprintf(context->fileName,"t%d = t%d || t%d");
        break;
    case BITWISE_XOR:
        fprintf(context->fileName,"t%d = t%d ^ t%d");
        break;
    case LT:
        fprintf(context->fileName,"t%d = t%d < t%d");
        break;
    case GT:
        fprintf(context->fileName,"t%d = t%d > t%d");
        break;
    case LE:
        fprintf(context->fileName,"t%d = t%d <= t%d");
        break;
    case GE:
        fprintf(context->fileName,"t%d = t%d >= t%d");
        break;
    case EQ:
        fprintf(context->fileName,"t%d = t%d == t%d");
        break;
    case NE:
        fprintf(context->fileName,"t%d = t%d != t%d");
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
    switch (op)
    {
    case LOGICAL_NOT:
        fprintf(context->fileName,"t%d = !t%d\n", tempdes, reg1);
        break;
    case SUB:
        fprintf(context->fileName,"t%d = -t%d\n",tempdes,reg1);
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
    fprintf(context->fileName,"t%d = %s",tempdes,var);
    return tempdes;
}



