#ifndef SYMBOL_H
#define SYMBOL_H

typedef struct symbol Symbol;
typedef enum types Enumtypes;

// Enumeration for different types
enum types {
    type_int,     // Integer type
    type_char,    // Character type
    type_double,  // Double type
    type_bool,    // Boolean type
    type_float,   // Float type
    type_struct,  // Struct type
    type_enum,    // Enum type
    type_types,   // Types type
    type_func     // Function type
};

struct symbol {
    char *id;       // Identifier
    Enumtypes type; // Type
    void *address;  // Address
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
Symbol *symbolNew(char *id, Enumtypes type, int size);

/**
 * Delete a symbol and free its memory.
 *
 * @param symbol - Pointer to the symbol to be deleted
 */
void symbolDelete(Symbol *symbol);

#endif