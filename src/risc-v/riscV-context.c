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
    new->if_else = new->if_exit = new->rep_entry = new->rep_exit = new->rep_stmt, new->rep_update = NULL;
    
    FILE *base = fopen("src/risc-v/riscv-base.s", "r");
    if(!base) exit(1);
    char c;
    while((c = fgetc(base)) != EOF) fprintf(filename, "%c", c);
    fclose(base);

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
        fprintf(context->fileName, "addi x%d, x0, %d\n", tempReg, sym->data.variable.address);
        fprintf(context->fileName, "sw x%d, 0(x%d)\n", regToFree, tempReg);

        rManagerFreeRegVar(context->rm, regToFree);
        
        if(!rManagerHasSpaceVar(context->rm)) {
            printf("riscV-context.c emit -> codeGenAssign error\n");
            exit(0);
        }

        regdes = rManagerAddVar(context->rm, var);
    }

    fprintf(context->fileName,"add x%d, x%d, x0\n", regdes, reg2);
    return regdes;
}

int riscVCodeGenInteger(RiscVContext *context, int num){
    int regdes = rManagerGetRegTemp(context->rm);
    fprintf(context->fileName,"addi x%d, x0, %d\n",regdes,num);
    return regdes;
}

//Code for binary operations
int  riscVCodeGenBinaryOperator(RiscVContext *context, int op, int reg1, int reg2){
    int regdes = rManagerGetRegTemp(context->rm);
    fprintf(context->fileName, "# handle operation %d\n", op);
    switch (op)
    {
    case ADD:
        fprintf(context->fileName,"add x%d, x%d, x%d\n",regdes,reg1,reg2);
        break;
    case SUB:
        fprintf(context->fileName,"sub x%d, x%d, x%d\n",regdes,reg1,reg2);
        break;
    case MUL:
        fprintf(context->fileName,"mul x%d, x%d, x%d\n",regdes,reg1,reg2);
        break;
    case DIV:
        fprintf(context->fileName,"div x%d, x%d, x%d\n",regdes,reg1,reg2);
        break;
    case LEFT_SHIFT:
        fprintf(context->fileName, "sll x%d, x%d, x%d\n",regdes,reg1,reg2);
        break;
    case RIGHT_SHIFT:
        fprintf(context->fileName, "srl x%d, x%d, x%d\n",regdes,reg1,reg2);
        break;
    case LOGICAL_AND:
        fprintf(context->fileName, "and x%d, x%d, x%d\n",regdes,reg1,reg2);
        break;
    case LOGICAL_OR:
        fprintf(context->fileName, "or x%d, x%d, x%d\n",regdes,reg1,reg2);
        break;
    case EQ: {
        fprintf(context->fileName, "xor x%d, x%d, x%d\n", regdes, reg1, reg2);
        fprintf(context->fileName, "seqz x%d, x%d\n", regdes, regdes);
        break;
    }
    case NE: {
        fprintf(context->fileName, "xor x%d, x%d, x%d\n", regdes, reg1, reg2);
        fprintf(context->fileName, "snez x%d, x%d\n", regdes, regdes);
        break;
    }
    case LT: {
        fprintf(context->fileName, "slt x%d, x%d, x%d\n", regdes, reg1, reg2);
        break;
    }

    case GT: {
        fprintf(context->fileName, "slt x%d, x%d, x%d\n", regdes, reg2, reg1);
        break;
    }
    
    case LE: {
        fprintf(context->fileName, "slt x%d, x%d, x%d\n", regdes, reg2, reg1);
        fprintf(context->fileName, "seqz x%d, x%d\n", regdes, regdes);
        break;
    }
    case GE: {
        fprintf(context->fileName, "slt x%d, x%d, x%d\n", regdes, reg1, reg2);
        fprintf(context->fileName, "seqz x%d, x%d\n", regdes, regdes);
        break;
    }
    default:
        printf("riscV-context.h  emit -> Impossivel fazer %d no risc-V\n",op);
        exit(0);
        break;
    }
    return regdes;
}
int  riscVCodeGenUnaryOperator(RiscVContext *context, int op, int reg1){
    int regdes = rManagerGetRegTemp(context->rm);
    switch (op)
    {
    case LOGICAL_NOT:
        fprintf(context->fileName,"xori x%d, x%d, -1\n", regdes, reg1);
        break;
    case SUB:
        fprintf(context->fileName,"sub x%d, x0, x%d\n",regdes,reg1);
        break;
    default:
        printf("riscV-context.h  emit -> Impossivel fazer %d no risc-V\n",op);
        exit(0);
        break;
    }
    return regdes;
}
//Code for Variables
int riscVCodeGenVariable(RiscVContext *context, char *var){
    int regdes = -4;
    if(rManagerHasVar(context->rm, var)) return rManagerGetRegVar(context->rm, var);
    else if(rManagerHasSpaceVar(context->rm)) regdes = rManagerAddVar(context->rm, var);
    else {
        char *toFree = rManagerVarToFreeSpace(context->rm);
        int regToFree = rManagerGetRegVar(context->rm, toFree);
        Symbol *sym =  symbolTableFind(context->symbolTable, toFree);

        int tempReg = rManagerGetRegTemp(context->rm);
        fprintf(context->fileName, "addi x%d, x0, %d\n", tempReg, sym->data.variable.address);
        fprintf(context->fileName, "sw x%d, 0(x%d)\n", regToFree, tempReg);

        rManagerFreeRegVar(context->rm, regToFree);
        
        if(!rManagerHasSpaceVar(context->rm)) {
            printf("riscV-context.c emit -> Deu ruim paizao\n");
            exit(0);
        }

        regdes = rManagerAddVar(context->rm, var);
    }


    int tempReg = rManagerGetRegTemp(context->rm);
    Symbol *sym =  symbolTableFind(context->symbolTable, var);
    fprintf(context->fileName, "addi x%d, x0, %d\n", tempReg, sym->data.variable.address);
    fprintf(context->fileName, "lw x%d, 0(x%d)\n", regdes, tempReg);

    return regdes;
}


//code for IF-ELSE
void riscVCodeIfAfterExpr(RiscVContext *context, int reg){
    char* currentLabelElse = getLabel();
    char* currentLabelExit = getLabel();
    labelStackPush(&context->if_else,currentLabelElse);
    labelStackPush(&context->if_exit,currentLabelExit);
    fprintf(context->fileName, "beq x0, x%d, %s\n", reg, currentLabelElse);
}

void riscVCodeIfAfterStmt(RiscVContext *context){
    fprintf(context->fileName, "beq x0, x0, %s\n", context->if_exit->label);
    fprintf(context->fileName, "%s:\n", context->if_else->label);
}

void riscVCodeIfAfterElse(RiscVContext *context){
    fprintf(context->fileName, "%s:\n", context->if_exit->label);
    labelStackPop(&context->if_exit);
    labelStackPop(&context->if_else);
}

//Code for repetition
void riscVCodeRepEntry(RiscVContext *context){
    char *lbl_entry = getLabel();
    char *lbl_exit = getLabel();
    char *lbl_stmt = getLabel();
    char *lbl_update = getLabel();
    labelStackPush(&context->rep_entry, lbl_entry);
    labelStackPush(&context->rep_exit, lbl_exit);
    labelStackPush(&context->rep_stmt, lbl_stmt);
    labelStackPush(&context->rep_update, lbl_update);
    fprintf(context->fileName, "%s:\n", lbl_entry);
}

void riscVCodeRepAfterExpr(RiscVContext *context, int reg){
    fprintf(context->fileName, "beq x0, x%d, %s\n", reg, context->rep_exit->label);
    fprintf(context->fileName, "j %s\n", context->rep_stmt->label);
}

void riscVCodeRepExit(RiscVContext *context){
    fprintf(context->fileName, "%s:\n", context->rep_exit->label);
    labelStackPop(&context->rep_entry);
    labelStackPop(&context->rep_exit);
    labelStackPop(&context->rep_stmt);
    labelStackPop(&context->rep_update);
}

void riscVCodeRepUpdate(RiscVContext *context){
    fprintf(context->fileName, "%s:\n", context->rep_update->label);
}

void riscVCodeRepStmt(RiscVContext *context){
    fprintf(context->fileName, "%s:\n", context->rep_stmt->label);
}

void riscVCodeRepGotoEntry(RiscVContext *context) {
    fprintf(context->fileName, "j %s\n", context->rep_entry->label);
}

void riscVCodeRepGotoUpdate(RiscVContext *context) {
    fprintf(context->fileName, "j %s\n", context->rep_update->label);
}

//only store all registers
void riscVSaveRegisters(RiscVContext *context) {
    for(int i=0;i<32;i++){
        char *varToFree = rManagerGetVar(context->rm,i);
        if (varToFree != NULL){
            int tempReg = rManagerGetRegTemp(context->rm);
            // printf("Here"); fflush(stdout);
            Symbol *sym = symbolTableFind(context->symbolTable, varToFree);
            if(!sym) continue;
            fprintf(context->fileName, "addi x%d, x0, %d\n", tempReg, sym->data.variable.address);
            fprintf(context->fileName, "sw x%d, 0(x%d)\n", i, tempReg);

            rManagerFreeRegVar(context->rm,i);
        }
    }
    
    //free all reg
    rManagerFreeAllRegisters(context->rm);
}

void riscVCodeExitProgram(RiscVContext *context) {
    fprintf(context->fileName, "j programExit\n");
}