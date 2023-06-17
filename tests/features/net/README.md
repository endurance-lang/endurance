# Net

A função `net` é responsável por filtrar um array com base em uma condição fornecida e retornar um novo array contendo os elementos filtrados.

Aqui está uma explicação linha por linha do código:

1. `void* net(void* array, int size, size_t elementSize, void* condition, int (*compareFunction)(void*, void*), int* newSize)`
   - Essa linha define a assinatura da função `net` com os parâmetros de entrada: 
     - `array` é um ponteiro genérico para o array que será filtrado.
     - `size` é o tamanho total do array em número de elementos.
     - `elementSize` é o tamanho de cada elemento do array em bytes.
     - `condition` é um ponteiro genérico para a condição de filtro.
     - `compareFunction` é um ponteiro para uma função de comparação que verifica se um elemento atende à condição.
     - `newSize` é um ponteiro para uma variável que será atualizada com o tamanho do novo array filtrado.

2. `void* filteredArray = malloc(size * sizeof(array));`
   - Essa linha aloca memória dinamicamente para o novo array filtrado com base no tamanho do array original.

3. `int count = 0;`
   - Essa linha inicializa uma variável de contagem para acompanhar o número de elementos que atendem à condição de filtro.

4. `for (int i = 0; i < size; i++) {`
   - Este loop percorre cada elemento do array original.

5. `void* element = (char*)array + i * sizeof(array);`
   - Esta linha obtém o endereço do elemento atual do array original, convertendo-o em um ponteiro genérico. A fórmula `i * sizeof(array)` é usada para calcular o deslocamento correto para cada elemento.

6. `if (compareFunction(element, condition)) {`
    - Esta linha chama a função de comparação (`compareFunction`) para verificar se o elemento atual atende à condição de filtro. Se a função retornar um valor verdadeiro, o elemento é considerado válido.

7. `void* destination = (char*)filteredArray + count * sizeof(array);`
    - Esta linha calcula o endereço de destino no novo array filtrado para armazenar o elemento atual, levando em consideração o deslocamento adequado com base na contagem atual.

8. `memcpy(destination, element, sizeof(array));`
    - Esta linha copia o elemento atual do array original para o novo array filtrado usando a função `memcpy`. `sizeof(array)` é usado para determinar o tamanho do elemento a ser copiado.

9. `count++;`
    - Esta linha incrementa a contagem de elementos filtrados.

10. `*newSize = count;`
    - Esta linha atualiza a variável `newSize` com o número de elementos filtrados.

11. `return filteredArray;`
    - Esta linha retorna o novo array filtrado.

No geral, a função `net` percorre o array original, aplica a função de comparação a cada elemento e, se o elemento atender à condição, ele é copiado para o novo array filtrado. No final, o tamanho do novo array é atualizado e o array filtrado é retornado.