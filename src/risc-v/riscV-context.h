#ifndef RISCVCONTEXT_H
#define RISCVCONTEXT_H

#include <stdlib.h>
#include "../symbol-table/symbolTable.h"
#include "register-manager.h"
#include "label-stack.h"

/**
 * Estrutura que representa o contexto do RISC-V.
 */
typedef struct riscVcontext RiscVContext;

struct riscVcontext
{
    SymbolTable* symbolTable; // Tabela de símbolos
    FILE* fileName;           // Nome do arquivo
    RManager* rm;             // Gerenciador de registradores
    LabelStack *if_else, *if_exit;
    LabelStack *rep_entry, *rep_exit, *rep_stmt, *rep_update;
};

/**
 * Cria um novo contexto do RISC-V.
 *
 * @param filename - Nome do arquivo
 * @param st - Tabela de símbolos
 * @return Ponteiro para o novo contexto do RISC-V
 */
RiscVContext *riscV_ContextNew(FILE* filename,SymbolTable* st);

// void getReg();

char* getLabel();

/**
 * Gera o código do RISC-V para uma atribuição.
 *
 * @param context - Ponteiro para o contexto do RISC-V
 * @param var - Nome da variável de destino
 * @param reg2 - Registrador contendo o valor a ser atribuído
 * @return 1 se a geração do código foi bem-sucedida, 0 caso contrário
 */
int riscVCodeGenAssign(RiscVContext *context, char* var, int reg2);

/**
 * Gera o código do RISC-V para um número inteiro.
 *
 * @param context - Ponteiro para o contexto do RISC-V
 * @param num - Número inteiro
 * @return 1 se a geração do código foi bem-sucedida, 0 caso contrário
 */
int riscVCodeGenInteger(RiscVContext *context, int num);

/**
 * Gera o código do RISC-V para um operador binário.
 *
 * @param context - Ponteiro para o contexto do RISC-V
 * @param op - Operador binário
 * @param reg1 - Registrador contendo o primeiro operando
 * @param reg2 - Registrador contendo o segundo operando
 * @return 1 se a geração do código foi bem-sucedida, 0 caso contrário
 */
int riscVCodeGenBinaryOperator(RiscVContext *context, int op, int reg1, int reg2);

/**
 * Gera o código do RISC-V para um operador unário.
 *
 * @param context - Ponteiro para o contexto do RISC-V
 * @param op - Operador unário
 * @param reg1 - Registrador contendo o operando
 * @return 1 se a geração do código foi bem-sucedida, 0 caso contrário
 */
int riscVCodeGenUnaryOperator(RiscVContext *context, int op, int reg1);

/**
 * Gera o código do RISC-V para uma variável.
 *
 * @param context - Ponteiro para o contexto do RISC-V
 * @param var - Nome da variável
 * @return 1 se a geração do código foi bem-sucedida, 0 caso contrário
 */
int riscVCodeGenVariable(RiscVContext *context,char* var);

/**
 * Salva os registradores do RISC-V.
 *
 * @param context - Ponteiro para o contexto do RISC-V
 */
void riscVSaveRegisters(RiscVContext *context);

/**
 * Gera o código do RISC-V após a expressão do comando if.
 *
 * @param context - Ponteiro para o contexto do RISC-V
 * @param reg - Registrador contendo o valor da expressão do comando if
 */
void riscVCodeIfAfterExpr(RiscVContext *context, int reg);

/**
 * Gera o código do RISC-V após o comando if.
 *
 * @param context - Ponteiro para o contexto do RISC-V
 */
void riscVCodeIfAfterStmt(RiscVContext *context);

/**
 * Gera o código do RISC-V após o comando else.
 *
 * @param context - Ponteiro para o contexto do RISC-V
 */
void riscVCodeIfAfterElse(RiscVContext *context);

/**
 * Gera o código do RISC-V para a entrada do comando repetir.
 *
 * @param context - Ponteiro para o contexto do RISC-V
 */
void riscVCodeRepEntry(RiscVContext *context);

/**
 * Gera o código do RISC-V após a expressão do comando repetir.
 *
 * @param context - Ponteiro para o contexto do RISC-V
 * @param reg - Registrador contendo o valor da expressão do comando repetir
 */
void riscVCodeRepAfterExpr(RiscVContext *context, int reg);

/**
 * Gera o código do RISC-V para a saída do comando repetir.
 *
 * @param context - Ponteiro para o contexto do RISC-V
 */
void riscVCodeRepExit(RiscVContext *context);

/**
 * Gera o código do RISC-V para a atualização do comando repetir.
 *
 * @param context - Ponteiro para o contexto do RISC-V
 */
void riscVCodeRepUpdate(RiscVContext *context);

/**
 * Gera o código do RISC-V para as instruções do comando repetir.
 *
 * @param context - Ponteiro para o contexto do RISC-V
 */
void riscVCodeRepStmt(RiscVContext *context);

/**
 * Gera o código do RISC-V para o salto para a entrada do comando repetir.
 *
 * @param context - Ponteiro para o contexto do RISC-V
 */
void riscVCodeRepGotoEntry(RiscVContext *context);

/**
 * Gera o código do RISC-V para o salto para a atualização do comando repetir.
 *
 * @param context - Ponteiro para o contexto do RISC-V
 */
void riscVCodeRepGotoUpdate(RiscVContext *context);


/**
 * Gera o código do RISC-V para encerrar o programa.
 *
 * @param context - Ponteiro para o contexto do RISC-V
 */
void riscVCodeExitProgram(RiscVContext *context);

#endif