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

// Função auxiliar para retornar a string do tipo
const char* getTypeString(Enumtypes type) {
    switch (type) {
        case type_int:
            return "INT";
        case type_float:
            return "FLOAT";
        case type_double:
            return "DOUBLE";
        case type_char:
            return "CHAR";
        case type_bool:
            return "BOOL";
        case type_struct:
            return "STRUCT";
        case type_enum:
            return "ENUM";
        case type_types:
            return "TYPES";
        case type_func:
            return "FUNCTION";
            break;
        default:
            return "UNKNOWN";
    }
}


SymbolNode* getSymbolTableHead(SymbolTable* st) {
    return st->priv->head->headNode;
}



void showSymbolList(List* list,FILE* f) {
    fprintf(f,"===========================================================\n");
    fprintf(f,"| \033[38;5;196m%-15s\033[0m | \033[38;5;196m%-15s\033[0m | \033[38;5;196m%-19s\033[0m |\n", "ID", "Type", "Address");
    fprintf(f,"===========================================================\n");

    SymbolNode* aux = list->headNode;
    while (aux != NULL) {
        fprintf(f,"| \033[38;5;49m%-15s\033[0m | \033[38;5;208m%-15s\033[0m | \033[38;5;193m%-19p\033[0m |\n", aux->sym->id, getTypeString(aux->sym->type), aux->sym->address);
        aux = aux->prox;
    }

    fprintf(f,"===========================================================\n");
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
    if(!st->priv->head) return NULL;
    List *aux = st->priv->head;
    while(aux != NULL) {
        Symbol *search = findSymbol(id, aux->headNode);
        if(search) return search;
        aux = aux->prox;
    }
    return NULL;
}

Symbol *symbolTableFindInBlock(SymbolTable *st, char *id){
    if(!st->priv->head) return NULL;
    List *aux = st->priv->head;
    Symbol *search = findSymbol(id, aux->headNode);
    if(search) return search;
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

void symbolTableShow(SymbolTable *st, FILE* f) {
    List* list = st->priv->head;
    while (list != NULL) {
        showSymbolList(list,f);
        list = list->prox;
    }
    fprintf(f,"\n---\n\n");
}