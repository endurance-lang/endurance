#include "inst-stack.h"
#include <stdlib.h>

void instStackPush(InstructionStack **stack, int instr)  {
    InstructionStack *new = (InstructionStack*) malloc(sizeof(InstructionStack));
    new->instr = instr;
    new->next = *stack;
    *stack = new;
}

void instStackPop(InstructionStack **stack) {
    InstructionStack *aux = *stack;
    *stack = (*stack)->next;
    free(aux);
}