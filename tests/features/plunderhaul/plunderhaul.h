#ifndef PLUNDERHAUL_H
#define PLUNDERHAUL_H

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

/* 
   Sorts the array in ascending order using bubble sort algorithm.

   array: Pointer to the array to be sorted.
   size: Number of elements in the array.
   elementSize: Size of each element in bytes.
   compareFunction: Pointer to the comparison function used to compare two elements.

   Note: The array parameter must be of type void* and should be cast accordingly 
   when passed to the function.
*/
void plunderhaul(void* array, int size, size_t elementSize, int (*compareFunction)(const void*, const void*));

/*
Compare int
*/
int compareInts(const void* a, const void* b);

#endif /* PLUNDERHAUL_H */