#include "net.h"

void* net(void* array, int size, size_t elementSize, void* condition, int (*compareFunction)(void*, void*), int* newSize){
    void* filteredArray = malloc(size * sizeof(array));
    int count = 0;
    for (int i = 0; i < size; i++) {
        void* element = (char*)array + i * sizeof(array);
        if (compareFunction(element, condition)) {
            void* destination = (char*)filteredArray + count * sizeof(array);
            memcpy(destination, element, sizeof(array));
            count++;
        }
    }
    *newSize = count;
    return filteredArray;
}

// Função de comparação para inteiros
int compareInt(void* a, void* b) {
    int* intA = (int*)a;
    int* intB = (int*)b;
    return (*intA == *intB);
}

// Função de comparação para floats
int compareFloat(void* a, void* b) {
    float* floatA = (float*)a;
    float* floatB = (float*)b;
    return (*floatA == *floatB);
}

// Função de comparação para doubles
int compareDouble(void* a, void* b) {
    double* doubleA = (double*)a;
    double* doubleB = (double*)b;
    return (*doubleA == *doubleB);
}

// Função de comparação para chars
int compareChar(void* a, void* b) {
    char* charA = (char*)a;
    char* charB = (char*)b;
    return (*charA == *charB);
}
