#ifndef SYMBOL_TABLE_H
#define SYMBOL_TABLE_H

#include <stdio.h>
#include "symbol.h"

typedef struct symboltable SymbolTable;
typedef struct symboltablepriv SymbolTablePriv;

struct symboltable {
    SymbolTablePriv *priv;
    int size;
};

SymbolTable *symbolTableNew(void);
void symbolTableCreateBlock(SymbolTable *st);
void symbolTableDeleteBlock(SymbolTable *st);
void symbolTableInsert(SymbolTable *st, Symbol *sym);
Symbol*  symbolTableFind(SymbolTable *st, char *id);
Symbol *symbolTableFindInBlock(SymbolTable *st, char *id);
void symbolTableDelete(SymbolTable *st);
void symbolTableShow(SymbolTable *st,FILE* f);

#endif