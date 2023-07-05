#ifndef PSEUDOCONTEXT_H
#define PSEUDOCONTEXT_H

#include "../symbol-table/symbolTable.h"
#include "inst-stack.h"

/**
 * Estrutura que representa o contexto pseudocódigo.
 */
typedef struct pseudoContext PseudoContext;

struct pseudoContext
{
    SymbolTable *symbolTable;        // Tabela de símbolos
    FILE *fileName;                  // Nome do arquivo
    InstructionStack *ifs, *elses, *repentry, *repexit, *repstmt, *repupdate; // Pilhas de instruções
};

/**
 * Cria um novo contexto pseudocódigo.
 *
 * @param filename - Nome do arquivo
 * @param st - Ponteiro para a tabela de símbolos
 * @return Ponteiro para o novo contexto pseudocódigo
 */
PseudoContext *pseudo_ContextNew(FILE *filename, SymbolTable *st);

/**
 * Gera o código pseudocódigo para uma atribuição.
 *
 * @param context - Ponteiro para o contexto pseudocódigo
 * @param var - Variável de destino da atribuição
 * @param reg2 - Registrador com o valor a ser atribuído
 * @return Registrador resultante da atribuição
 */
int pseudoCodeGenAssign(PseudoContext *context, char *var, int reg2);

/**
 * Gera o código pseudocódigo para um valor inteiro.
 *
 * @param context - Ponteiro para o contexto pseudocódigo
 * @param num - Valor inteiro
 * @return Registrador com o valor inteiro
 */
int pseudoCodeGenInteger(PseudoContext *context, int num);

/**
 * Gera o código pseudocódigo para um operador binário.
 *
 * @param context - Ponteiro para o contexto pseudocódigo
 * @param op - Operador binário
 * @param reg1 - Registrador do operando 1
 * @param reg2 - Registrador do operando 2
 * @return Registrador resultante da operação
 */
int pseudoCodeGenBinaryOperator(PseudoContext *context, int op, int reg1, int reg2);

/**
 * Gera o código pseudocódigo para um operador unário.
 *
 * @param context - Ponteiro para o contexto pseudocódigo
 * @param op - Operador unário
 * @param reg1 - Registrador do operando
 * @return Registrador resultante da operação
 */
int pseudoCodeGenUnaryOperator(PseudoContext *context, int op, int reg1);

/**
 * Gera o código pseudocódigo para uma variável.
 *
 * @param context - Ponteiro para o contexto pseudocódigo
 * @param var - Nome da variável
 * @return Registrador contendo o valor da variável
 */
int pseudoCodeGenVariable(PseudoContext *context, char *var);

/**
 * Indica o ponto de geração de código pseudocódigo após uma expressão de um "if".
 *
 * @param context - Ponteiro para o contexto pseudocódigo
 * @param reg - Registrador resultante da expressão
 */
void pseudoCodeIfAfterExpr(PseudoContext *context, int reg);

/**
 * Indica o ponto de geração de código pseudocódigo após uma instrução de um "if".
 *
 * @param context - Ponteiro para o contexto pseudocódigo
 */
void pseudoCodeIfAfterStmt(PseudoContext *context);

/**
 * Indica o ponto de geração de código pseudocódigo após um "else".
 *
 * @param context - Ponteiro para o contexto pseudocódigo
 */
void pseudoCodeIfAfterElse(PseudoContext *context);

/**
 * Indica o ponto de geração de código pseudocódigo após a entrada de um "repetir".
 *
 * @param context - Ponteiro para o contexto pseudocódigo
 */
void pseudoCodeRepEntry(PseudoContext *context);

/**
 * Indica o ponto de geração de código pseudocódigo após uma expressão de um "repetir".
 *
 * @param context - Ponteiro para o contexto pseudocódigo
 * @param reg - Registrador resultante da expressão
 */
void pseudoCodeRepAfterExpr(PseudoContext *context, int reg);

/**
 * Indica o ponto de geração de código pseudocódigo após uma saída de um "repetir".
 *
 * @param context - Ponteiro para o contexto pseudocódigo
 */
void pseudoCodeRepExit(PseudoContext *context);

/**
 * Indica o ponto de geração de código pseudocódigo após uma atualização de um "repetir".
 *
 * @param context - Ponteiro para o contexto pseudocódigo
 */
void pseudoCodeRepUpdate(PseudoContext *context);

/**
 * Gera o código pseudocódigo para uma instrução dentro de um "repetir".
 *
 * @param context - Ponteiro para o contexto pseudocódigo
 */
void pseudoCodeRepStmt(PseudoContext *context);

/**
 * Gera o código pseudocódigo para o salto de entrada de um "repetir".
 *
 * @param context - Ponteiro para o contexto pseudocódigo
 */
void pseudoCodeRepGotoEntry(PseudoContext *context);

/**
 * Gera o código pseudocódigo para o salto de atualização de um "repetir".
 *
 * @param context - Ponteiro para o contexto pseudocódigo
 */
void pseudoCodeRepGotoUpdate(PseudoContext *context);

#endif