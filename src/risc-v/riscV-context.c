#include "riscV-context.h"
#include "register-manager.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "../lib/types.h"
#include "../lib/translate.tab.h"

static int newlabel = 1;

RiscVContext *riscV_ContextNew(FILE* filename, SymbolTable* st){
    RiscVContext* new = (RiscVContext *) malloc(sizeof(RiscVContext));
    new->fileName = filename;
    new->symbolTable = st;
    new->rm = rManagerCreate();
    new->if_else = new->if_exit = new->rep_entry = new->rep_exit = new->for_stmt, new->for_update = NULL;
    return new;
}

//return the next label
char* getLabel() {
    char *label = (char*) malloc(100 * sizeof(char));
    sprintf(label,"label_%d", newlabel++);
    return label;
}

//code for assign
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

//Code for binary operations
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

//Code for Variables
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


//code for IF-ELSE
void riscVCodeExpr(RiscVContext *context, int reg){
    char* currentLabelElse = getLabel();
    char* currentLabelExit = getLabel();
    pushLabel(&context->if_else,currentLabelElse);
    pushLabel(&context->if_exit,currentLabelExit);
    fprintf(context->fileName, "BEQ x0, x%d, %s\n", reg, currentLabelElse);
}

void riscVCodeElse(RiscVContext *context){
    fprintf(context->fileName, "BEQ x0, x0, %s\n", context->if_exit->label);
    fprintf(context->fileName, "%s:\n", context->if_else->label);
}

void riscVCodeExit(RiscVContext *context){
    fprintf(context->fileName, "%s:\n", context->if_exit->label);
    popLabel(&context->if_exit);
    popLabel(&context->if_else);
}

//Code for repetition
void riscVCodeRepEntry(RiscVContext *context){
    
    char *lbl_entry = getLabel();
    char *lbl_exit = getLabel();
    pushLabel(&context->rep_entry, lbl_entry);
    pushLabel(&context->rep_exit, lbl_exit);
    fprintf(context->fileName, "%s:\n", lbl_entry);
    
}

void riscVCodeRepExpr(RiscVContext *context, int reg){
    fprintf(context->fileName, "BEQ x0, x%d, %s\n", reg, context->rep_exit->label);
}

void riscVCodeRepExit(RiscVContext *context){
    fprintf(context->fileName, "BEQ x0, x0, %s\n", context->rep_entry->label);
    fprintf(context->fileName, "%s:\n", context->rep_exit->label);
    popLabel(&context->rep_entry);
    popLabel(&context->rep_exit);
}


//Code for FOR
void riscVCodeForStmtUpdate(RiscVContext *context){
    char *lbl_stmt = getLabel();
    char *lbl_update = getLabel();
    pushLabel(&context->for_stmt, lbl_stmt);
    pushLabel(&context->for_update, lbl_update);
    fprintf(context->fileName, "BEQ x0, x0, %s\n", lbl_stmt);
    fprintf(context->fileName, "%s:\n", lbl_update);
}

void riscVCodeForEntryStmt(RiscVContext *context){
    fprintf(context->fileName, "BEQ x0, x0, %s\n", context->rep_entry->label);
    fprintf(context->fileName, "%s:\n", context->for_stmt->label);
}

void riscVCodeForUpdateExit(RiscVContext *context){
    fprintf(context->fileName, "BEQ x0, x0, %s\n", context->for_update->label);
    fprintf(context->fileName, "%s:\n", context->rep_exit->label);
    popLabel(&context->rep_entry);
    popLabel(&context->rep_exit);
    popLabel(&context->for_stmt);
    popLabel(&context->for_update);
}

//only store all registers
void riscVSaveRegisters(RiscVContext *context) {
    for(int i=0;i<32;i++){
        char *varToFree = rManagerGetVar(context->rm,i);
        if (varToFree != NULL){
            int tempReg = rManagerGetRegTemp(context->rm);
            Symbol *sym =  symbolTableFind(context->symbolTable, varToFree);
            fprintf(context->fileName, "ADDi x%d, x0, %d\n", tempReg, sym->data.variable.address);
            fprintf(context->fileName, "SW x%d, 0(x%d)\n", i, tempReg);

            rManagerFreeRegVar(context->rm,i);
        }
    }
    
    //free all reg
    rManagerFreeAllRegisters(context->rm);
}