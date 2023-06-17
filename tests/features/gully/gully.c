#include "./gully.h"

void gully(void* array, int start, int end, int dataSize) {
    // Calculate the size of the sliced array
    int size = end - start + 1;

    // Calculate the total size in bytes
    int totalSize = size * dataSize;

    // Create a new array to store the sliced elements
    void* sliced = malloc(totalSize);

    // Copy the sliced elements to the new array
    char* source = (char*)array;
    char* destination = (char*)sliced;

    for (int i = 0; i < totalSize; i++) {
        destination[i] = source[start * dataSize + i];
    }

    // Print the sliced elements
    for (int i = 0; i < size; i++) {
        if (dataSize == sizeof(int)) {
            printf("%d ", *((int*)sliced + i));
        } else if (dataSize == sizeof(float)) {
            printf("%f ", *((float*)sliced + i));
        } else if (dataSize == sizeof(double)) {
            printf("%lf ", *((double*)sliced + i));
        } else if (dataSize == sizeof(char)) {
            printf("%c ", *((char*)sliced + i));
        } else {
            // Handle other types accordingly
        }
    }
    printf("\n");

    // Free the allocated memory
    free(sliced);
}