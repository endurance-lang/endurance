#include "register-manager.h"
#include <stdlib.h>
#include <string.h>

static int vars[] = {8, 9, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27};
static int temps[] = {5, 6, 7, 28, 29, 30, 31};
static int timer = 0;

RManager *rManagerCreate()
{
    RManager *rm = (RManager *) malloc(sizeof(RManager));
    rm->lastTempUsed = -1;
    for (int i = 0; i < 32; i++)
    {
        rm->registers[i] = NULL;
    }
    for (int i = 0; i < 12; i++)
    {
        rm->lastAccessTime[i] = 0;
    }
    return rm;
}
int rManagerAddVar(RManager *rm, char *varName){
    for (int i = 0; i < 12; i++)
    {
        int pos = vars[i];
        if (!rm->registers[pos])
        {
            rm->registers[pos] = strdup(varName);
            timer++;
            rm->lastAccessTime[i] = timer;
            return pos;
        }
    }
    return -2;
}
int rManagerGetRegVar(RManager *rm, char *varName)
{
    for (int i = 0; i < 12; i++)
    {
        int pos = vars[i];
        if (rm->registers[pos] && !strcmp(varName, rm->registers[pos]))
        {
            timer++;
            rm->lastAccessTime[i] = timer;
            return pos;
        }
    }
   
    return -1;
}

int rManagerHasSpaceVar(RManager *rm){
    for (int i = 0; i < 12; i++)
    {
        int pos = vars[i];
        if (!rm->registers[pos])
        {
            return 1;
        }
    }
    return 0;
}

void rManagerFreeRegVar(RManager *rm, int reg){
    free(rm->registers[reg]);
    rm->registers[reg] = NULL;
    for(int i = 0; i< 12;i++){
        if (vars[i] == reg){
            rm->lastAccessTime[i] = 0;
        }
    }
}

char *rManagerVarToFreeSpace(RManager *rm){
    int min = __INT_MAX__;
    int minpos = -1;
    for (int i = 0; i < 12; i++)
    {
        if (rm->lastAccessTime[i] < min)
        {
            min = rm->lastAccessTime[i];
            minpos = vars[i];
        }
    }
    
    return rm->registers[minpos];
}

int rManagerHasVar(RManager *rm, char *varName){
    for (int i = 0; i < 12; i++)
    {
        int pos = vars[i];
        if (rm->registers[pos] && !strcmp(varName, rm->registers[pos]))
        {
            return 1;
        }
    }
    return 0;
}
char *rManagerGetVar(RManager *rm, int regNumber)
{
    return rm->registers[regNumber];
}

int rManagerGetRegTemp(RManager *rm)
{
    rm->lastTempUsed = (rm->lastTempUsed + 1) % 7;
    return temps[rm->lastTempUsed];
}
