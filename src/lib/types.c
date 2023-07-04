#include "types.h"
#include <stdlib.h>
#include <string.h>

void functAddParam(FuncParamList **paramList, int reg, char *type) {
    FuncParamList *new = (FuncParamList *) malloc(sizeof(FuncParamList));
    new->param.reg = reg;
    new->param.type = strdup(type);
    new->next = NULL;

    if(!*paramList) {
        *paramList = new;
        return;
    }

    FuncParamList *it = *paramList;
    while(it->next) it = it->next;
    it->next = new;
}

int functParamListSize(FuncParamList **paramList) {
    int size = 0;
    FuncParamList *it = *paramList;
    for(; it; it = it->next, size++);
    return size;
}

FuncParam functGetParam(FuncParamList **paramList, int idx) {
    FuncParamList *it = *paramList;
    while(idx--) it = it->next;
    return it->param;
}
