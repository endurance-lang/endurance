#include "plunderhaul.h"

void main() {
    int intArray[] = {4, 2, 8, 1, 5};
    int intSize = sizeof(intArray) / sizeof(intArray[0]);

    plunderhaul(intArray, intSize, sizeof(int), compareInts);

    printf("Sorted int array: ");
    for (int i = 0; i < intSize; i++) {
        printf("%d ", intArray[i]);
    }
    printf("\n");
}