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


int riscVCodeGenAssign(RiscVContext *context, char* var, int reg2){
    int regdes;
    if(rManagerHasVar(context->rm, var)) regdes = rManagerGetRegVar(context->rm, var);
    else if(rManagerHasSpaceVar(context->rm)) regdes = rManagerAddVar(context->rm, var);
    else {
        char *toFree = rManagerVarToFreeSpace(context->rm);
        int regToFree = rManagerGetRegVar(context->rm, toFree);
        Symbol *sym =  symbolTableFind(context->symbolTable, toFree);

        int tempReg = rManagerGetRegTemp(context->rm);
        fprintf(context->fileName, "ADDi x%d, x0, %d\n", tempReg, sym->data.variable.address);
        fprintf(context->fileName, "SW x%d, 0(x%d)\n", regToFree, tempReg);

        rManagerFreeRegVar(context->rm, regToFree);
        
        if(!rManagerHasSpaceVar(context->rm)) {
            printf("riscV-context.c emit -> codeGenAssign error\n");
            exit(0);
        }

        regdes = rManagerAddVar(context->rm, var);
    }

    fprintf(context->fileName,"ADD x%d, x%d, x0\n", regdes, reg2);
    return regdes;
}

int riscVCodeGenInteger(RiscVContext *context, int num){
    int regdes = rManagerGetRegTemp(context->rm);
    fprintf(context->fileName,"ADDi x%d, x0, %d\n",regdes,num);
    return regdes;
}

int  riscVCodeGenBinaryOperator(RiscVContext *context, int op, int reg1, int reg2){
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
    return regdes;
}

int riscVCodeGenVariable(RiscVContext *context, char *var){
    int regdes = -4;
    if(rManagerHasVar(context->rm, var)) {
        // printf(".%s. ta dentro ???? \n", var);
        return rManagerGetRegVar(context->rm, var);
    }
    else if(rManagerHasSpaceVar(context->rm)) {
        regdes = rManagerAddVar(context->rm, var);
        // printf("add .%s. on reg %d\n", var, regdes);
    }
    else {
        char *toFree = rManagerVarToFreeSpace(context->rm);
        int regToFree = rManagerGetRegVar(context->rm, toFree);
        Symbol *sym =  symbolTableFind(context->symbolTable, toFree);

        int tempReg = rManagerGetRegTemp(context->rm);
        fprintf(context->fileName, "ADDi x%d, x0, %d\n", tempReg, sym->data.variable.address);
        fprintf(context->fileName, "SW x%d, 0(x%d)\n", regToFree, tempReg);

        rManagerFreeRegVar(context->rm, regToFree);
        
        if(!rManagerHasSpaceVar(context->rm)) {
            printf("riscV-context.c emit -> Deu ruim paizao\n");
            exit(0);
        }

        regdes = rManagerAddVar(context->rm, var);
    }


    int tempReg = rManagerGetRegTemp(context->rm);
    Symbol *sym =  symbolTableFind(context->symbolTable, var);
    fprintf(context->fileName, "ADDi x%d, x0, %d\n", tempReg, sym->data.variable.address);
    fprintf(context->fileName, "LW x%d, 0(x%d)\n", regdes, tempReg);

    return regdes;
}

