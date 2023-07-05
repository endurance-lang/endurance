#ifndef REGISTER_MANAGER_H
#define REGISTER_MANAGER_H

/**
 * Estrutura que representa o gerenciador de registradores.
 */
typedef struct register_manager RManager;

struct register_manager{
    int lastTempUsed;       // Último registrador temporário usado
    int lastAccessTime[12]; // Último tempo de acesso aos registradores
    char *registers[32];    // Registradores
    int timer;              // Tempo atual
};

/**
 * Cria um novo gerenciador de registradores.
 *
 * @return Ponteiro para o novo gerenciador de registradores
 */
RManager *rManagerCreate();

/**
 * Obtém o registrador associado a uma variável.
 *
 * @param rm - Ponteiro para o gerenciador de registradores
 * @param varName - Nome da variável
 * @return Número do registrador associado à variável
 */
int rManagerGetRegVar(RManager *rm, char *varName);

/**
 * Verifica se uma variável possui um registrador associado.
 *
 * @param rm - Ponteiro para o gerenciador de registradores
 * @param varName - Nome da variável
 * @return 1 se a variável possui um registrador associado, 0 caso contrário
 */
int rManagerHasVar(RManager *rm, char *varName);

/**
 * Adiciona uma variável ao gerenciador de registradores.
 *
 * @param rm - Ponteiro para o gerenciador de registradores
 * @param varName - Nome da variável
 * @return 1 se a variável foi adicionada com sucesso, 0 caso contrário
 */
int rManagerAddVar(RManager *rm, char *varName);


/**
 * Verifica se há espaço disponível para mais variáveis nos registradores.
 *
 * @param rm - Ponteiro para o gerenciador de registradores
 * @return 1 se há espaço disponível, 0 caso contrário
 */
int rManagerHasSpaceVar(RManager *rm);

/**
 * Libera o registrador associado a uma variável.
 *
 * @param rm - Ponteiro para o gerenciador de registradores
 * @param reg - Número do registrador a ser liberado
 */
void rManagerFreeRegVar(RManager *rm, int reg);

/**
 * Obtém a variável que está ocupando um espaço livre nos registradores.
 *
 * @param rm - Ponteiro para o gerenciador de registradores
 * @return Nome da variável que será liberada
 */
char *rManagerVarToFreeSpace(RManager *rm);

/**
 * Obtém o nome da variável associada a um registrador.
 *
 * @param rm - Ponteiro para o gerenciador de registradores
 * @param regNumber - Número do registrador
 * @return Nome da variável associada ao registrador
 */
char *rManagerGetVar(RManager *rm, int regNumber);

/**
 * Obtém um registrador temporário disponível.
 *
 * @param rm - Ponteiro para o gerenciador de registradores
 * @return Número do registrador temporário disponível
 */
int rManagerGetRegTemp(RManager *rm);

/**
 * Libera todos os registradores.
 *
 * @param rm - Ponteiro para o gerenciador de registradores
 */
void rManagerFreeAllRegisters(RManager *rm);

#endif