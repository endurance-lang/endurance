#ifndef REGISTER_MANAGER_H
#define REGISTER_MANAGER_H

typedef struct register_manager RManager;

struct register_manager{
    int lastTempUsed;
    int lastAccessTime[12];
    char *registers[32];
    int timer;
};

RManager *rManagerCreate();
int rManagerGetRegVar(RManager *rm, char *varName);
int rManagerHasVar(RManager *rm, char *varName);
int rManagerAddVar(RManager *rm, char *varName);
int rManagerHasSpaceVar(RManager *rm);
void rManagerFreeRegVar(RManager *rm, int reg);
char *rManagerVarToFreeSpace(RManager *rm);
char *rManagerGetVar(RManager *rm, int regNumber);
int rManagerGetRegTemp(RManager *rm);
void rManagerFreeAllRegisters(RManager *rm);

#endif
