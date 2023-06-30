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

int rManagerGetRegVar(RManager *rm, char *varName)
{
    for (int i = 0; i < 12; i++)
    {
        int pos = vars[i];
        if (rm->registers[pos] && !strcmp(varName, rm->registers[pos]))
        {
            timer++;
            rm->lastAccessTime[pos] = timer;
            return pos;
        }
    }
    for (int i = 0; i < 12; i++)
    {
        int pos = vars[i];
        if (!rm->registers[pos])
        {
            timer++;
            rm->lastAccessTime[pos] = timer;
            rm->registers[pos] = varName;
            return pos;
        }
    }
    int min = __INT_MAX__;
    int minpos = -1;
    for (int i = 0; i < 12; i++)
    {
        if (rm->lastAccessTime[i] < min)
        {
            min = rm->lastAccessTime[i];
            minpos = i;
        }
    }
    return -minpos;
}
char *rManagerGetVar(RManager *rm, int regNumber)
{
    char *ret = rm->registers[regNumber];
    rm->registers[regNumber] = NULL;
    return ret;
}
int rManagerGetRegTemp(RManager *rm)
{
    rm->lastTempUsed = (rm->lastTempUsed + 1) % 7;
    return temps[rm->lastTempUsed];
}
