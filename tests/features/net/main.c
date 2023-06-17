#include "net.h"

void main() {
    // Array de inteiros
    int intArray[] = {1, 2, 3, 4, 5, 4, 3, 2, 1};
    int intSize = sizeof(intArray) / sizeof(int);
    int intCondition = 3;
    int intNewSize = 0;
    int* intFilteredArray = (int*)net(intArray, intSize, sizeof(int), &intCondition, compareInt, &intNewSize);

    printf("Filtered Int Array: ");
    for (int i = 0; i < intNewSize; i++) {
        printf("%d ", intFilteredArray[i]);
    }
    printf("\n");
    free(intFilteredArray);

    // Array de floats
    float floatArray[] = {1.1, 2.2, 3.3, 4.4, 5.5, 4.4, 3.3, 2.2, 1.1};
    int floatSize = sizeof(floatArray) / sizeof(float);
    float floatCondition = 4.4;
    int floatNewSize = 0;
    float* floatFilteredArray = (float*)net(floatArray, floatSize, sizeof(float), &floatCondition, compareFloat, &floatNewSize);

    printf("Filtered Float Array: ");
    for (int i = 0; i < floatNewSize; i++) {
        printf("%.1f ", floatFilteredArray[i]);
    }
    printf("\n");
    free(floatFilteredArray);

    // Array de doubles
    double doubleArray[] = {1.11, 2.22, 3.33, 4.44, 5.55, 4.44, 3.33, 2.22, 1.11};
    int doubleSize = sizeof(doubleArray) / sizeof(double);
    double doubleCondition = 3.33;
    int doubleNewSize = 0;
    double* doubleFilteredArray = (double*)net(doubleArray, doubleSize, sizeof(double), &doubleCondition, compareDouble, &doubleNewSize);

    printf("Filtered Double Array: ");
    for (int i = 0; i < doubleNewSize; i++) {
        printf("%.2f ", doubleFilteredArray[i]);
    }
    printf("\n");
    free(doubleFilteredArray);

    // Array de chars
    char charArray[] = {'a', 'b', 'c', 'd', 'e', 'd', 'c', 'b', 'a'};
    int charSize = sizeof(charArray) / sizeof(char);
    char charCondition = 'c';
    int charNewSize = 0;
    char* charFilteredArray = (char*)net(charArray, charSize, sizeof(char), &charCondition, compareChar, &charNewSize);

    printf("Filtered Char Array: ");
    for (int i = 0; i < charNewSize; i++) {
        printf("%c ", charFilteredArray[i]);
    }
    printf("\n");
    free(charFilteredArray);
}