#ifndef NET_H
#define NET_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*
Filters the array based on a given condition and returns a new 
array with the filtered elements
*/
void* net(void* array, int size, size_t elementSize, void* condition, int (*compareFunction)(void*, void*), int* newSize);

/**/
int compareInt(void* a, void* b);

/**/
int compareFloat(void* a, void* b);

/**/
int compareDouble(void* a, void* b);

/**/
int compareChar(void* a, void* b);

#endif