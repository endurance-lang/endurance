#include <stdlib.h>
#include "label-stack.h"

void labelStackPush(LabelStack **lst, char *label){
    LabelStack *new = (LabelStack *) malloc(sizeof(LabelStack));
    new->label = label;
    new->next = *lst;
    *lst = new;
}

void labelStackPop(LabelStack **lst){
    LabelStack *aux = *lst;
    *lst = (*lst)->next;
    free(aux);
}