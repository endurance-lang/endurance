#ifndef TYPES_H
#define TYPES_H

/* Expression Data */
typedef struct {
    int reg;
    char *returnType;
    int temp;
} ExprData;


/* Function Data */
typedef struct {
    int reg;
    char *type;
} FuncParam;


typedef struct param_list FuncParamList;
struct param_list {
    FuncParam param;
    FuncParamList *next;
};

typedef struct {
    char *id;
    FuncParamList *params;
} FuncData;

void functAddParam(FuncParamList **paramList, int reg, char *type);
int functParamListSize(FuncParamList **paramList);
FuncParam functGetParam(FuncParamList **paramList, int idx);



#endif