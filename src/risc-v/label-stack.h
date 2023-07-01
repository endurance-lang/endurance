#ifndef LABELSTACK_H
#define LABELSTACK_H

typedef struct labelStack LabelStack;

struct labelStack {
    char *label;
    struct labelStack *next;
};

void pushLabel(LabelStack **lst, char *label);
void popLabel(LabelStack **lst);

#endif