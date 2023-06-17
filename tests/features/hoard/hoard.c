#include "hoard.h"

int hoard(void* array, int size, void* condition, int (*compareFunction)(void*, void*)) {
    for (int i = 0; i < size; i++) {
        void* element = (char*)array + i * sizeof(array);
        if (compareFunction(element, condition)) {
            return 1; // Found a matching element
        }
    }
    return 0; // No matching element found
}

int compareInt(void* a, void* b) {
    int* intA = (int*)a;
    int* intB = (int*)b;
    return (*intA == *intB);
}

int compareFloat(void* a, void* b) {
    float* floatA = (float*)a;
    float* floatB = (float*)b;
    return (*floatA == *floatB);
}

int compareDouble(void* a, void* b) {
    double* doubleA = (double*)a;
    double* doubleB = (double*)b;
    return (*doubleA == *doubleB);
}

int compareChar(void* a, void* b) {
    char* charA = (char*)a;
    char* charB = (char*)b;
    return (*charA == *charB);
}