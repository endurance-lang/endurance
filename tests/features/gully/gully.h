#ifndef GULLY_H
#define GULLY_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*
A função gully é responsável por fatiar (slice) um array 
em um determinado intervalo e imprimir os elementos fatiados.
*/
void gully(void* array, int start, int end, int dataSize);

#endif