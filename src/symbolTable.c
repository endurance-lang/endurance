#include "symbolTable.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

typedef struct symbolnode SymbolNode;
typedef struct list List;

struct symboltablepriv {
    List *head;
};

struct symbolnode {
    Symbol *sym;
    SymbolNode *prox;
};

struct list {
    SymbolNode* headNode;
    List* prox;
};

/*
    Private
*/

void insertSymbol(SymbolNode** head, Symbol *sym) {
    SymbolNode *new = (SymbolNode *) malloc(sizeof(SymbolNode));
    new->sym = sym;
    new->prox = *head;
    *head = new;
}

void insertSymbolList(List **head) {
    List *new = (List *) malloc(sizeof(List));
    new->headNode = NULL;
    new->prox = *head;
    *head = new;
}

Symbol* findSymbol(char *id, SymbolNode* sym){
    while(sym != NULL){
        if(strcmp(sym->sym->id, id) == 0){
            return sym->sym;
        }
        sym = sym->prox;
    }
    return NULL;
}

void deleteSymbolList(SymbolNode *head){
    while(head != NULL){
        SymbolNode* aux = head;
        head = head->prox;
        symbolDelete(aux->sym);
        free(aux);
    }
}

void showSymbolList(SymbolNode *head){
    SymbolNode* aux = head;
    while(aux != NULL){
        printf("%s ", aux->sym->id);
        // printf("",aux->sym->address);
        // printf("",aux->sym->type);
        aux = aux->prox;
    }
    printf("\n");
}


/*
    Public
*/

SymbolTable *symbolTableNew(void) {
    SymbolTable *new = (SymbolTable *) malloc(sizeof(SymbolTable));
    new->size = 0;
    new->priv = (SymbolTablePriv *) malloc(sizeof(SymbolTablePriv));
    new->priv->head = NULL;
    return new;
}

void symbolTableCreateBlock(SymbolTable *st){
    insertSymbolList(&st->priv->head);
}

void symbolTableDeleteBlock(SymbolTable *st){
    if(!st->priv->head) return;
    deleteSymbolList(st->priv->head->headNode);
    List *aux = st->priv->head;
    st->priv->head = st->priv->head->prox;
    free(aux);
}

void symbolTableInsert(SymbolTable *st, Symbol *sym) {
    if(!st->priv->head) return;
    if(findSymbol(sym->id, st->priv->head->headNode)) return;
    insertSymbol(&st->priv->head->headNode, sym);
}

Symbol *symbolTableFind(SymbolTable *st, char *id){
    List *aux = st->priv->head;
    while(aux != NULL) {
        Symbol *search = findSymbol(id, aux->headNode);
        if(search) return search;
        aux = aux->prox;
    }
    return NULL;
}

void symbolTableDelete(SymbolTable *st){
    while(st->priv->head != NULL) {
        List *aux = st->priv->head;
        st->priv->head = st->priv->head->prox;
        deleteSymbolList(aux->headNode);
        free(aux);
    }
    free(st->priv);
    free(st);
}

void symbolTableShow(SymbolTable *st){
    List *aux = st->priv->head;
    while(aux != NULL) {
        showSymbolList(aux->headNode);
        aux = aux->prox;
    }
    printf("--- \n");
}