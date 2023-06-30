#ifndef REGISTER_MANAGER_H
#define REGISTER_MANAGER_H

typedef struct register_manager RManager;

struct register_manager{
    int lastTempUsed;
    int lastAccessTime[12];
    char *registers[32];
};

RManager *rManagerCreate();
int rManagerGetRegVar(RManager *rm, char *varName);
char * rManagerGetVar(RManager *rm, int regNumber);
int rManagerGetRegTemp(RManager *rm);

#endif
