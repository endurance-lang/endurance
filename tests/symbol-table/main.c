#include <stdio.h>
#include "../../src/symbolTable.h"

int main() {
    Symbol *search;
    SymbolTable *st = symbolTableNew();
    symbolTableCreateBlock(st);
    symbolTableInsert(st, symbolNew("var", type_int, 1));
    search = symbolTableFind(st, "variavi");
    printf("%lld - expected 0\n", search);
    search = symbolTableFind(st, "var");
    printf("%lld - expected number x\n", search);
    symbolTableCreateBlock(st);
    symbolTableInsert(st, symbolNew("var", type_char, 1));
    search = symbolTableFind(st, "var");
    printf("%lld - expected number y\n", search);
    symbolTableDeleteBlock(st);
    search = symbolTableFind(st, "var");
    printf("%lld - expected number x\n", search);
    symbolTableDeleteBlock(st);
    search = symbolTableFind(st, "var");
    printf("%lld - expected 0\n", search);

    a = 10;

    return 0;
}