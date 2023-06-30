#include "symbol.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

static int nextAddress = 0;

Symbol *symbolNew(char *id, Enumtypes symboType, char *type, int size) {
    Symbol *new = (Symbol *) malloc(sizeof(Symbol));
    new->type = type;
    new->id = strdup(id);
    new->type = strdup(type);
    new->size = size;
    new->symbolType = symboType;
    int correctSize = ((size+3)/4)*4; // primeiro numero > size que eh mult de 4
    new->address = nextAddress;
    nextAddress += correctSize;
    return new;
}

void symbolDelete(Symbol *symbol){
    free(symbol->id);
    free(symbol->type);
    free(symbol);
}
