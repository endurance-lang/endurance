#ifndef BOOTY_H
#define BOOTY_H

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*
Função de operação binária genérica
*/
typedef void (*BinaryOperation)(void*, void*, void*);

/*
Reduz um array a um único valor usando uma operação binária
*/
void* booty(void* array, int size, void* initialValue, BinaryOperation binaryOperation);

/*
Função de exemplo de operação binária para inteiros
*/
void sumInt(void* a, void* b, void* result);


#endif