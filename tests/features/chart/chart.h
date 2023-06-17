#ifndef CHART_H
#define CHART_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

/*
implementa a funcionalidade de mapeamento (map) em um array genérico
*/
void* chart(void* array, int size, size_t dataSize, void* (*function)(void*));

/*
exemplo de função de mapeamento
*/
void* square(void* num);

#endif