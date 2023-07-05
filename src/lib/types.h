#ifndef TYPES_H
#define TYPES_H

/**
 * Expression Data => Estrutura que representa os dados de uma expressão.
 */
typedef struct {
    int reg;            // Número do registrador associado à expressão
    char *returnType;   // Tipo de retorno da expressão
    int temp;           // Variável temporária associada à expressão
} ExprData;

/**
 * Function Data => Estrutura que representa os dados de um parâmetro de função.
 */
typedef struct {
    int reg;        // Número do registrador associado ao parâmetro
    char *type;     // Tipo do parâmetro
} FuncParam;

/**
 * Estrutura que representa uma lista de parâmetros de função.
 */
typedef struct param_list FuncParamList;

/**
 * Estrutura que representa uma função e seus parâmetros associados.
 */
struct param_list {
    FuncParam param;        // Identificador da função
    FuncParamList *next;    // Ponteiro para o início da lista de parâmetros da função
};

typedef struct {
    char *id;
    FuncParamList *params;
} FuncData;

/**
 * Adds a parameter to the function parameter list.
 *
 * @param paramList - Ponteiro para o início da lista de parâmetros da função
 * @param reg - Número do registrador associado ao parâmetro
 * @param type - Tipo do parâmetro
 */
void functAddParam(FuncParamList **paramList, int reg, char *type);

/**
 * Retorna o tamanho da lista de parâmetros da função.
 *
 * @param paramList - Ponteiro para o início da lista de parâmetros da função
 * @return O tamanho da lista de parâmetros da função
*/
int functParamListSize(FuncParamList **paramList);

/**
 * Retorna o parâmetro no índice especificado da lista de parâmetros da função.
 *
 * @param paramList - Ponteiro para o início da lista de parâmetros da função
 * @param idx - Índice do parâmetro a ser obtido
 * @return O parâmetro no índice especificado
 */
FuncParam functGetParam(FuncParamList **paramList, int idx);

#endif