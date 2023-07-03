#ifndef INST_STACK_H
#define INST_STACK_H

typedef struct inst_stack InstructionStack;

struct inst_stack {
    int instr;
    InstructionStack *next;
};

void instStackPush(InstructionStack **stack, int instr);
void instStackPop(InstructionStack **stack);

#endif