#include <stdlib.h>
#include "label-stack.h"

void pushLabel(LabelStack **lst, char *label){
    LabelStack *new = (LabelStack *) malloc(sizeof(LabelStack));
    new->label = label;
    new->next = *lst;
    *lst = new;
}

void popLabel(LabelStack **lst){
    LabelStack *aux = *lst;
    *lst = (*lst)->next;
    free(aux);
}