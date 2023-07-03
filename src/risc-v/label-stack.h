#ifndef LABELSTACK_H
#define LABELSTACK_H

typedef struct labelStack LabelStack;

struct labelStack {
    char *label;
    struct labelStack *next;
};

void labelStackPush(LabelStack **lst, char *label);
void labelStackPop(LabelStack **lst);

#endif