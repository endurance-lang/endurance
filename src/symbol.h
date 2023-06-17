#ifndef SYMBOL_H
#define SYMBOL_H

typedef struct symbol Symbol;
typedef enum types Enumtypes;

enum types {
    type_int,
    type_char,
    type_double,
    type_bool,
    type_float,
    type_struct,
    type_enum,
    type_types,
    type_func
};

struct symbol {
    char *id;
    Enumtypes type;
    void *address;
};

Symbol *symbolNew(char *id, Enumtypes type, int size);
void symbolDelete(Symbol *symbol);

#endif