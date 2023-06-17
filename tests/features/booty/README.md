# Booty

Função de redução genérica. Essa função é responsável por reduzir um array a um único valor usando uma operação binária fornecida.

A função `booty` recebe os seguintes parâmetros:

- `array`: Um ponteiro genérico para o array que será reduzido.
- `size`: O número de elementos no array.
- `initialValue`: Um ponteiro genérico para o valor inicial do resultado da redução.
- `binaryOperation`: Um ponteiro para uma função que representa a operação binária a ser aplicada para reduzir os elementos do array.


Dentro da função `booty`, temos um loop `for` que percorre cada elemento do array. Em cada iteração, o elemento atual é obtido usando a expressão `(char*)array + i * sizeof(*array)`. Essa expressão garante que o ponteiro `element` aponte corretamente para o elemento atual do array, independentemente do tipo de dado.

Em seguida, a função `binaryOperation` é chamada com os parâmetros `result`, element e `result`. Isso significa que a operação binária será aplicada ao resultado atual (`result`) e ao elemento atual (`element`), e o resultado será armazenado novamente em `result`. Essa é a etapa de redução do array.

No final do loop, o resultado final da redução é retornado pela função.

A função `sumInt` é um exemplo de uma operação binária específica para inteiros. Ela recebe dois ponteiros genéricos para inteiros (`a` e `b`) e um ponteiro genérico para o resultado (`result`). Essa função realiza a soma dos valores apontados por a e b e armazena o resultado em `result` usando a expressão `*(int*)result = *(int*)a + *(int*)b`. Note que os ponteiros genéricos são convertidos para ponteiros de int antes de acessar os valores apontados por eles.