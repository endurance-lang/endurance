#include "riscV-context.h"
#include "register-manager.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "../lib/translate.tab.h"

static int newlabel = 1;

RiscVContext *riscV_ContextNew(FILE* filename, SymbolTable* st){
    RiscVContext* new = (RiscVContext *) malloc(sizeof(RiscVContext));
    new->fileName = filename;
    new->symbolTable = st;
    new->rm = rManagerCreate();
    return new;
}

// void getReg();
// char* getLabel(){
//     char *label;
//     strcpy(label,"label");
//     //strcat(label,(char*)(newlabel));
//     newlabel++;
//     return label;
// }


void codeGenAssign(RiscVContext *context, char* var, int reg2){
    int regdes = rManagerGetRegVar(context->rm,var);
    fprintf(context->fileName,"ADD x%d, x%d, x0\n",regdes, reg2);
}
int codeGenInteger(RiscVContext *context, int num){
    int regdes = rManagerGetRegTemp(context->rm);
    fprintf(context->fileName,"ADDi x%d, x0, %d\n",regdes,num);
    return regdes;
}
void codeGenBinaryOperator(RiscVContext *context, int op, int reg1, int reg2){
    int regdes = rManagerGetRegTemp(context->rm);
    switch (op)
    {
    case ADD:
        fprintf(context->fileName,"ADD x%d, x%d, x%d\n",regdes,reg1,reg2);
        break;
    case SUB:
        fprintf(context->fileName,"SUB x%d, x%d, x%d\n",regdes,reg1,reg2);
        break;
    case LEFT_SHIFT:
        fprintf(context->fileName, "SLL x%d, x%d, x%d\n",regdes,reg1,reg2);
        break;
    case RIGHT_SHIFT:
        fprintf(context->fileName, "SRL x%d, x%d, x%d\n",regdes,reg1,reg2);
        break;
    case LOGICAL_AND:
        fprintf(context->fileName, "AND x%d, x%d, x%d\n",regdes,reg1,reg2);
        break;
    case LOGICAL_OR:
        fprintf(context->fileName, "OR x%d, x%d, x%d\n",regdes,reg1,reg2);
        break;
    default:
        printf("riscV-context.h  emit -> Impossivel fazer %d no risc-V",op);
        exit(0);
        break;
    }
}
int codeGenVariable(RiscVContext *context,char* var){
    
    // pegar a var na tabela de simbolos (S) em C
    Symbol *S = symbolTableFind(context->symbolTable, var);
    // // pegar a posição da memoria da var (S.address) em C
    // // colocar esse endereço em um temp (T = S.address) no riscV
    int regtemp = rManagerGetRegTemp(context->rm);
    fprintf(context->fileName,"ADDi x%d, x0, %d\n",regtemp, S->address);
    // // pegar um reg pra variavel (R)
    int regdes = rManagerGetRegVar(context->rm, var);
    // // load em R o valor em 0(T) "lw R, 0(T)"
    fprintf(context->fileName,"LW x%d, 0(x%d)\n",regdes,regtemp);
    return 0;
}

