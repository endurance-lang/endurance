#include "chart.h"

void main() {
    int intArray[] = {1, 2, 3, 4, 5};
    int size = sizeof(intArray) / sizeof(int);

    // Aplica a função square ao array de inteiros
    int* mappedArray = (int*)chart(intArray, size, sizeof(int), square);

    // Imprime o array resultante
    for (int i = 0; i < size; i++) {
        printf("%d ", mappedArray[i]);
    }
    printf("\n");

    // Libera a memória alocada para o array resultante
    free(mappedArray);
}