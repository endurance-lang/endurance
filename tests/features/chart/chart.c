#include "chart.h"

void* chart(void* array, int size, size_t dataSize, void* (*function)(void*)) {
    void* mappedArray = malloc(size * dataSize);
    for (int i = 0; i < size; i++) {
        void* element = (char*)array + i * dataSize;
        void* mappedElement = function(element);
        char* destination = (char*)mappedArray + i * dataSize;
        memcpy(destination, mappedElement, dataSize);
        free(mappedElement);
    }
    return mappedArray;
}


void* square(void* num) {
    int* value = (int*)num;
    int* result = malloc(sizeof(int));
    *result = (*value) * (*value);
    return result;
}