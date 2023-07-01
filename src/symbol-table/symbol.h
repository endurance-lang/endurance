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
    Enumtypes symbolType;
    char *id;
    union {
        struct {
            char *type;
            int address;
            int size;
        } variable;
        struct {
            int bytes;
        } type;
        struct {
            char *returnType;
            /* parameter list */
        } function;
    } data;
};

/**
 * Create a new variable symbol.
 *
 * @param id        - variable name
 * @param type      - variable type
 * @param address   - first byte address
 * @param size      - size == 0 if this is a variable; size > 0 if this is an array with size items;
 *
 * @return Pointer to the created symbol variable
 */
Symbol *symbolVariableNew(char *id, char *type, int address, int size);

/**
 * Create a new type symbol.
 *
 * @param id        - type name
 * @param bytes     - the number of bytes this type uses in memory
 *
 * @return Pointer to the created symbol type
 */
Symbol *symbolTypeNew(char *id, int bytes);

/**
 * Create a new function symbol.
 *
 * @param id            - function name
 * @param returnType    - return type of funcition
 *
 * @return Pointer to the created symbol type
 */
Symbol *symbolFunctionNew(char *id, char *returnType /*, paramList*/);

/**
 * Delete a symbol and free its memory.
 *
 * @param symbol - Pointer to the symbol to be deleted
 */
void symbolDelete(Symbol *symbol);

#endif