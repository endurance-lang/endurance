#include "plunderhaul.h"

// Sorts the array in ascending order using the bubble sort algorithm
void plunderhaul(void* array, int size, size_t elementSize, int (*compareFunction)(const void*, const void*)) {
    char* charArray = (char*)array;
    
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            void* currentElement = charArray + j * elementSize;
            void* nextElement = charArray + (j + 1) * elementSize;

            if (compareFunction(currentElement, nextElement) > 0) {
                // Swap elements
                char* temp = malloc(elementSize);
                memcpy(temp, currentElement, elementSize);
                memcpy(currentElement, nextElement, elementSize);
                memcpy(nextElement, temp, elementSize);
                free(temp);
            }
        }
    }
}

int compareInts(const void* a, const void* b) {
    const int* intA = (const int*)a;
    const int* intB = (const int*)b;
    
    if (*intA < *intB)
        return -1;
    else if (*intA > *intB)
        return 1;
    else
        return 0;
}
