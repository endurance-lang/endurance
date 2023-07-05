#ifndef INST_STACK_H
#define INST_STACK_H

/**
 * Estrutura que representa a pilha de instruções.
 */
typedef struct inst_stack InstructionStack;

struct inst_stack {
    int instr;               // Instrução
    InstructionStack *next;  // Próximo elemento da pilha
};

/**
 * Insere uma instrução no topo da pilha.
 *
 * @param stack - Ponteiro para o topo da pilha de instruções
 * @param instr - Instrução a ser inserida
 */
void instStackPush(InstructionStack **stack, int instr);

/**
 * Remove a instrução do topo da pilha.
 *
 * @param stack - Ponteiro para o topo da pilha de instruções
 */
void instStackPop(InstructionStack **stack);

#endif