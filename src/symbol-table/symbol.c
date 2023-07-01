#include "symbol.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

Symbol *symbolVariableNew(char *id, char *type, int address, int size) {
    Symbol *new = (Symbol*) malloc(sizeof(Symbol));
    new->symbolType = SymbolTypeVariable;
    new->id = strdup(id);
    new->data.variable.type = strdup(type);
    new->data.variable.address = address;
    new->data.variable.size = size;
    return new;
}

Symbol *symbolTypeNew(char *id, int bytes) {
    Symbol *new = (Symbol*) malloc(sizeof(Symbol));
    new->symbolType = SymbolTypeType;
    new->id = strdup(id);
    new->data.type.bytes = bytes;
    return new;
}

Symbol *symbolFunctionNew(char *id, char *returnType /*, paramList*/) {
    Symbol *new = (Symbol*) malloc(sizeof(Symbol));
    new->symbolType = SymbolTypeFunction;
    new->id = strdup(id);
    new->data.function.returnType = strdup(returnType);
    return new;
}

void symbolDelete(Symbol *symbol){
    if(!symbol) return;
    free(symbol->id);
    switch (symbol->symbolType)
    {
    case SymbolTypeVariable:
        free(symbol->data.variable.type);
        break;

    case SymbolTypeType:
        break;

    case SymbolTypeFunction:
        free(symbol->data.function.returnType);
        break;
    
    default:
        break;
    }
    free(symbol);
}
