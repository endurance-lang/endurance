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
    new->ifs = new->elses = new->repentry = new->repexit = new->repstmt = new->repupdate = NULL;
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

//100 ifFalse expression goto 103
//101stmt-if
//102 goto SAIDA
//103 stmt-else
//104
void pseudoCodeIfAfterExpr(PseudoContext *context, int reg){
    int instr = numinstr++;
    fprintf(context->fileName,"%d: ifFalse t%d goto ",instr,reg);
    instStackPush(&context->ifs,ftell(context->fileName));
    fprintf(context->fileName,"     ");
}
void pseudoCodeIfAfterStmt(PseudoContext *context){
    int instr = numinstr++;
    fprintf(context->fileName,"%d: goto ",instr);
    instStackPush(&context->elses,ftell(context->fileName));
    fprintf(context->fileName,"     ");
    int postemp = ftell(context->fileName);
    int backpos = context->ifs->instr;
    instStackPop(&context->ifs);
    fseek(context->fileName,backpos,SEEK_SET);
    fprintf(context->fileName,"%4d\n",numinstr);
    fseek(context->fileName,postemp,SEEK_SET);
}
void pseudoCodeIfAfterElse(PseudoContext *context){
    int pos = ftell(context->fileName);
    fseek(context->fileName,context->elses->instr,SEEK_SET);
    instStackPop(&context->elses);
    fprintf(context->fileName,"%4d\n",numinstr);
    fseek(context->fileName,pos,SEEK_SET);
}
//99 calc expression
//100 ifFalse expression goto 103
//101 stmt
//102 goto 99
//103
void pseudoCodeRepEntry(PseudoContext *context){
    instStackPush(&context->repentry,numinstr);
}
void pseudoCodeRepAfterExpr(PseudoContext *context, int reg){
    int instr = numinstr++;
    fprintf(context->fileName,"%d: ifFalse t%d goto ", instr,reg);
    instStackPush(&context->repexit,ftell(context->fileName));
    fprintf(context->fileName,"     ");
    fprintf(context->fileName,"%d: goto ",numinstr++);
    int pos = ftell(context->fileName);
    instStackPush(&context->repstmt,pos);
    fprintf(context->fileName,"     ");
}
void pseudoCodeRepStmt(PseudoContext *context){
    fseek(context->fileName,context->repstmt->instr,SEEK_SET);
    instStackPop(&context->repstmt);
    fprintf(context->fileName,"%4d\n",numinstr);
    fseek(context->fileName,0,SEEK_END);
}
void pseudoCodeRepGotoEntry(PseudoContext *context){
    fprintf(context->fileName,"%d: goto %4d\n",numinstr++,context->repentry->instr);
    instStackPop(&context->repentry);
}
void pseudoCodeRepExit(PseudoContext *context){
    fseek(context->fileName,context->repexit->instr,SEEK_SET);
    fprintf(context->fileName,"%4d\n",numinstr);
    instStackPop(&context->repexit);
    fseek(context->fileName,0,SEEK_END);
}
void pseudoCodeRepUpdate(PseudoContext *context){
    instStackPush(&context->repupdate,numinstr);
}
void pseudoCodeRepGotoUpdate(PseudoContext *context){
    fprintf(context->fileName,"%d: goto %4d\n",numinstr++,context->repupdate->instr);
    instStackPop(&context->repupdate);
}

