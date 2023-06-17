# Plunderhaul

O código fornecido é a implementação da função `plunderhaul`, que ordena um array em ordem crescente usando o algoritmo de ordenação bubble sort. Aqui está uma explicação passo a passo do código:

1. A função `plunderhaul` recebe vários parâmetros:
   - `array`: Um ponteiro para o array que precisa ser ordenado. Ele é do tipo `void*` para permitir a ordenação de arrays de tipos diferentes.
   - `size`: O número de elementos no array.
   - `elementSize`: O tamanho de cada elemento em bytes. Isso é necessário para realizar a aritmética de ponteiros ao acessar os elementos do array.
   - `compareFunction`: Um ponteiro para função de comparação usada para comparar dois elementos do array.

2. Dentro da função, um ponteiro `char*` chamado `charArray` é criado e inicializado com o ponteiro `array` fornecido convertido para `char*`. Isso é feito para permitir manipulações em nível de byte do array.

3. A função usa dois loops aninhados para executar o algoritmo bubble sort. O loop externo (`i`) itera `size - 1` vezes, representando o número de passagens necessárias para ordenar o array. O loop interno (`j`) itera `size - i - 1` vezes, representando o número de comparações necessárias em cada passagem.

4. Dentro do loop interno, dois ponteiros `void*` chamados `currentElement` e `nextElement` são criados. Esses ponteiros apontam para o elemento atual e o próximo elemento do array que estão sendo comparados.

5. A função `compareFunction` é chamada para comparar o `currentElement` com o `nextElement`. Se o resultado for maior que 0, indicando que o elemento atual é maior que o próximo elemento, os elementos são trocados.

6. Para trocar os elementos, um buffer temporário (`temp`) é criado usando `malloc` e seu tamanho é definido como `elementSize` para acomodar o tamanho de cada elemento. A função `memcpy` é então usada para copiar o conteúdo do `currentElement` para `temp`, o conteúdo do `nextElement` para `currentElement` e o conteúdo de `temp` para `nextElement`.

7. Após a conclusão do loop interno, a função retorna ao loop externo para a próxima passagem. Esse processo continua até que o array esteja completamente ordenado.

8. Por fim, a função termina sua execução e o array ordenado está disponível na localização de memória original apontada pelo parâmetro `array`.

Observação: Esta implementação do bubble sort usando ponteiros `void*` e uma função de comparação permite a ordenação de arrays de diferentes tipos. A função de comparação precisa ser fornecida pelo usuário para definir a lógica de comparação específica com base no tipo de elemento sendo ordenado.