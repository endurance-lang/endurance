#ifndef SYMBOL_H
#define SYMBOL_H

typedef struct symbol Symbol;
typedef enum types Enumtypes;

enum types {
    type_int,
    type_char,
    type_double,
    type_bool,
    type_float
};

struct symbol {
    char *id;
    Enumtypes type;
    void *address;
};

Symbol *symbolNew(char *id, Enumtypes type, int size);
void symbolDelete(Symbol *symbol);

#endif