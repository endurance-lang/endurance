#ifndef HOARD_H
#define HOARD_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*
*/
int hoard(void* array, int size, void* condition, int (*compareFunction)(void*, void*));

/*
Funções de comparação para diferentes tipos de dados
*/

/*
Função int
*/
int compareInt(void* a, void* b);

/*
Função float
*/
int compareFloat(void* a, void* b);

/*
Função double
*/
int compareDouble(void* a, void* b);

/*
Função char
*/
int compareChar(void* a, void* b);

#endif