#include "symbol.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

Symbol *symbolNew(char *id, Enumtypes type, int size) {
    Symbol *new = (Symbol *) malloc(sizeof(Symbol));
    new->type = type;
    new->id = strdup(id);
    switch (type) {
    case type_bool:
        new->address = (char *) malloc(size * sizeof(char));
        break;
    
    case type_char:
        new->address = (char *) malloc(size * sizeof(char));
        break;

    case type_double:
        new->address = (double *) malloc(size * sizeof(double));
        break;

    case type_float:
        new->address = (float *) malloc(size * sizeof(float));
        break;

    case type_int:
        new->address = (int *) malloc(size * sizeof(int));
        break;

    case type_struct:
        new->address = (int *) malloc(size * sizeof(int));
        break;

    case type_enum:
        new->address = (int *) malloc(size * sizeof(int));
        break;
    
    case type_types:
        new->address = (int *) malloc(size * sizeof(int));
        break;

    case type_func:
        new->address = (int *) malloc(size * sizeof(int));
        break;

    default:
        fprintf(stderr, "Invalid type\n");
        exit(0);
        break;
    }

    return new;
}

void symbolDelete(Symbol *symbol){
    free(symbol->id);
    free(symbol->address);
    free(symbol);
}
