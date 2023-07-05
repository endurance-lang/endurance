# Hoard
Hoard (tesouro acumulado, para realizar operações em uma coleção) é uma função `some`

```c
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
```

A função `hoard` é uma função genérica que percorre um array de elementos e verifica se algum elemento corresponde a uma condição especificada. Ela recebe como parâmetros:
- `array`: um ponteiro para o array de elementos.
- `size`: o tamanho do array.
- `condition`: um ponteiro para a condição que está sendo procurada.
- `compareFunction`: um ponteiro para uma função de comparação que compara um elemento do array com a condição.

A função percorre o array utilizando um loop `for` e em cada iteração, compara o elemento atual com a condição utilizando a função de comparação fornecida. Se a comparação for verdadeira, significa que o elemento corresponde à condição e a função retorna `1` indicando que um elemento correspondente foi encontrado. Caso nenhum elemento correspondente seja encontrado, a função retorna `0`.

Aqui estão as funções de comparação correspondentes para diferentes tipos de dados:

```c
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
```

Essas funções de comparação recebem dois ponteiros genéricos para elementos e realizam a comparação apropriada para cada tipo de dado. Elas retornam `1` se os elementos forem iguais e `0` caso contrário.

Essas funções podem ser utilizadas junto com a função `hoard` para buscar elementos em arrays de diferentes tipos de dados, como inteiros, floats, doubles e chars.