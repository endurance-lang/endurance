#include <stdio.h>
#include "../../src/symbolTable.h"

int main() {
    FILE *output = stdout;

    Symbol* search;
    SymbolTable* st = symbolTableNew();
    symbolTableCreateBlock(st);
    symbolTableInsert(st, symbolNew("var", type_int, 1));
    symbolTableInsert(st, symbolNew("teste", type_int, 2));
    symbolTableInsert(st, symbolNew("test-2", type_int, 2));
    symbolTableShow(st,output);
    search = symbolTableFind(st, "variavi");
    
    search = symbolTableFind(st, "var");
   
    symbolTableCreateBlock(st);
    symbolTableInsert(st, symbolNew("var", type_char, 1));
    symbolTableShow(st,output);
    search = symbolTableFind(st, "var");
    
    symbolTableDeleteBlock(st);
    symbolTableShow(st,output);
    search = symbolTableFind(st, "var");
   
    symbolTableDeleteBlock(st);
    symbolTableShow(st,output);
    search = symbolTableFind(st, "var");

    symbolTableDelete(st);

    return 0;
}