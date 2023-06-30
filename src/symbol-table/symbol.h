#ifndef SYMBOL_H
#define SYMBOL_H

typedef struct symbol Symbol;
typedef enum types Enumtypes;

// Enumeration for different types
enum types {
    SymbolTypeVariable,
    SymbolTypeFunction,
    SymbolTypeType
};

struct symbol {
    char *id;       // Identifier
    Enumtypes symbolType; // Type
    char *type;
    int size;
    int address;  // Address
};

/**
 * Create a new symbol.
 *
 * @param id     - Identifier for the symbol
 * @param type   - Type of the symbol (Enumtypes)
 * @param size   - Size of the symbol
 *
 * @return Pointer to the created symbol
 */
Symbol *symbolNew(char *id, Enumtypes symbolType, char *type, int size);

/**
 * Delete a symbol and free its memory.
 *
 * @param symbol - Pointer to the symbol to be deleted
 */
void symbolDelete(Symbol *symbol);

#endif