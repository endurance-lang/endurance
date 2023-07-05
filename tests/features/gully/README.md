# Gully

A função gully é responsável por fatiar (slice) um array em um determinado intervalo e imprimir os elementos fatiados. Aqui está uma explicação passo a passo do que a função faz:

1. A função recebe quatro parâmetros:

    - `void* array`: um ponteiro genérico que aponta para o array a ser fatiado. Como é um ponteiro genérico, pode ser usado para qualquer tipo de array.
    - `int start`: o índice inicial do intervalo de fatia.
    - `int end`: o índice final do intervalo de fatia.
    - `int dataSize`: o tamanho em bytes do tipo de dado armazenado no array.

2. Calcula o tamanho do array fatiado:

    - `int size = end - start + 1;`

3. Calcula o tamanho total em bytes do array fatiado:

    - `int totalSize = size * dataSize;`

4. Aloca memória dinamicamente para um novo array que armazenará os elementos fatiados:

    - `void* sliced = malloc(totalSize);`

5. Copia os elementos fatiados do array original para o novo array:
    - Converte o ponteiro genérico `void*` para um ponteiro `char*` para permitir a cópia byte a byte.
    - `char* source = (char*)array;`
    - `char* destination = (char*)sliced;`
    - Usa um loop para copiar cada byte do intervalo fatiado:
        * `destination[i] = source[start * dataSize + i];`

6. Imprime os elementos fatiados:

- Usa um segundo loop para iterar pelos elementos fatiados.
- Verifica o tamanho do tipo de dado (`dataSize`) para determinar como interpretar e imprimir cada elemento.
- Se `dataSize` for igual ao tamanho de um `int`, imprime o elemento como inteiro:
    * `printf("%d ", *((int*)sliced + i));`
- Se `dataSize` for igual ao tamanho de um `float`, imprime o elemento como float:
    * `printf("%f ", *((float*)sliced + i));`
- Se `dataSize` for igual ao tamanho de um `double`, imprime o elemento como double:
    * `printf("%lf ", *((double*)sliced + i));`
- Se `dataSize` for igual ao tamanho de um `char`, imprime o elemento como caractere:
    * `printf("%c ", *((char*)sliced + i));`
- Caso contrário, é possível tratar outros tipos de dados adicionais de acordo com a necessidade.

7. Imprime uma nova linha para separar a saída.
    - `printf("\n");`

8. Libera a memória alocada para o novo array:
    - `free(sliced);`

Essa função permite fatiar arrays de qualquer tipo de dados, desde que o tamanho do tipo seja conhecido e fornecido durante a chamada da função.