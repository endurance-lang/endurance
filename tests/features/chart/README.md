# Chart

A função `chart` implementa a funcionalidade de mapeamento (map) em um array genérico. Ela recebe como entrada um array (`void* array`), seu tamanho (`size`), o tamanho em bytes de cada elemento do array (`dataSize`), e um ponteiro para uma função que será aplicada a cada elemento do array (`void* (*function)(void*)`).

A função `chart` aloca memória para um novo array (`mappedArray`) que terá o mesmo tamanho do array original, multiplicado pelo tamanho de cada elemento (`size * dataSize`). Em seguida, percorre cada elemento do array original através de um loop `for` e aplica a função de mapeamento a cada elemento.

Dentro do loop, a função `chart` obtém o ponteiro para o elemento atual do array original, calculando seu endereço com base no tamanho do elemento (`(char*)array + i * dataSize`). Esse ponteiro é passado como argumento para a função de mapeamento (`function(element)`), que retorna um ponteiro para o elemento mapeado (`mappedElement`).

Em seguida, o ponteiro de destino (`destination`) é calculado com base no endereço do array mapeado e na posição atual do loop. Utiliza-se `char*` para permitir a manipulação de bytes. A função `memcpy` é utilizada para copiar o conteúdo do ponteiro `mappedElement` para o ponteiro de destino `destination`, utilizando o tamanho de cada elemento (`dataSize`).

Após a cópia, a memória alocada para o elemento mapeado (`mappedElement`) é liberada usando `free`, uma vez que o array mapeado (`mappedArray`) já contém uma cópia do valor.

Por fim, o array mapeado (`mappedArray`) é retornado.

No exemplo fornecido, a função `square` é utilizada como exemplo de função de mapeamento. Ela recebe um ponteiro genérico `num`, converte-o para um ponteiro de `int`, calcula o quadrado do valor e retorna um novo ponteiro de `int` contendo o resultado. Essa função é passada como argumento para a função `chart`, que a aplica a cada elemento do array original, retornando um novo array contendo os quadrados dos elementos.

É importante destacar que a função `chart` é genérica e pode ser utilizada com diferentes tipos de dados e funções de mapeamento, desde que a função de mapeamento siga a assinatura adequada (`void* (*function)(void*)`). Isso permite a flexibilidade de aplicar diferentes operações a elementos de um array, sem a necessidade de repetir o código de iteração e alocação de memória.