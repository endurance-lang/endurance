#include "booty.h"

void* booty(void* array, int size, void* initialValue, BinaryOperation binaryOperation) {
    void* result = initialValue;
    for (int i = 0; i < size; i++) {
        void* element = (char*)array + i * sizeof(*array);
        binaryOperation(result, element, result);
    }
    return result;
}

void sumInt(void* a, void* b, void* result) {
    *(int*)result = *(int*)a + *(int*)b;
}