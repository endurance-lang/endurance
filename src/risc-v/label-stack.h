#ifndef LABELSTACK_H
#define LABELSTACK_H

/**
 * Estrutura que representa a pilha de rótulos.
 */
typedef struct labelStack LabelStack;

struct labelStack {
    char *label;             // Rótulo
    struct labelStack *next; // Próximo elemento da pilha
};

/**
 * Insere um rótulo no topo da pilha.
 *
 * @param lst - Ponteiro para o topo da pilha de rótulos
 * @param label - Rótulo a ser inserido
 */
void labelStackPush(LabelStack **lst, char *label);

/**
 * Remove o rótulo do topo da pilha.
 *
 * @param lst - Ponteiro para o topo da pilha de rótulos
 */
void labelStackPop(LabelStack **lst);

#endif