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

/**
 * Create a new symbol table.
 *
 * @return Pointer to the created symbol table
 */
SymbolTable *symbolTableNew(void);

/**
 * Create a new block in the symbol table.
 *
 * @param st - Pointer to the symbol table
 */
void symbolTableCreateBlock(SymbolTable *st);

/**
 * Delete the most recent block from the symbol table.
 *
 * @param st - Pointer to the symbol table
 */
void symbolTableDeleteBlock(SymbolTable *st);

/**
 * Insert a symbol into the symbol table.
 *
 * @param st  - Pointer to the symbol table
 * @param sym - Pointer to the symbol to be inserted
 */
void symbolTableInsert(SymbolTable *st, Symbol *sym);

/**
 * Find a symbol in the symbol table by its identifier.
 *
 * @param st  - Pointer to the symbol table
 * @param id  - Identifier of the symbol
 *
 * @return Pointer to the found symbol, or NULL if not found
 */
Symbol* symbolTableFind(SymbolTable *st, char *id);

/**
 * Find a symbol in the current block of the symbol table by its identifier.
 *
 * @param st  - Pointer to the symbol table
 * @param id  - Identifier of the symbol
 *
 * @return Pointer to the found symbol, or NULL if not found
 */
Symbol *symbolTableFindInBlock(SymbolTable *st, char *id);

/**
 * Delete the symbol table and free its memory.
 *
 * @param st - Pointer to the symbol table
 */
void symbolTableDelete(SymbolTable *st);

/**
 * Show the contents of the symbol table.
 *
 * @param st - Pointer to the symbol table
 * @param f  - File pointer to write the output
 */
void symbolTableShow(SymbolTable *st, FILE* f);

#endif