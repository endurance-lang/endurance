%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Definição dos tokens gerados pelo Flex
#include "translate.tab.h"

// Protótipos das funções geradas pelo Flex
extern int yylex();
extern int yylex_destroy();
extern char* yytext;
extern FILE* yyin;

// Função de erro
void yyerror(const char* s) {
    printf("Erro de análise sintática: %s\n", s);
}

// Estrutura para armazenar informações dos símbolos
typedef struct {
    int type;
    char* value;
} Symbol;

Symbol symbol_table[100];
int symbol_count = 0;

void add_symbol(int type, char* value) {
    symbol_table[symbol_count].type = type;
    symbol_table[symbol_count].value = strdup(value);
    symbol_count++;
}

void print_symbol_table() {
    printf("Tabela de símbolos:\n");
    for (int i = 0; i < symbol_count; i++) {
        printf("Tipo: %d, Valor: %s\n", symbol_table[i].type, symbol_table[i].value);
    }
}

%}

%union {
    int number;
    double decimal;
    char* string;
}

%token <number> INTEGER
%token <decimal> DECIMAL
%token <string> STRING
%token <string> IDENTIFIER
%token SEMI_COLON
%token ASSIGN

%token NUMBER
%token IDENTIFIER
%token INVALID

%left '+' '-'
%left '*' '/'

%%

program:
    program stmt                    {  }
    |
    ;

stmt:
    expr ';'                        {  }
    | IDENTIFIER '=' expr ';'       {  }
    | '{' program '}'               {  }
    ;

expr:
    | expr '+' expr         {  }
    | expr '-' expr         {  }
    | expr '*' expr         {  }
    | expr '/' expr         {  }
    | '(' expr ')'          {  }
    | NUMBER                {  }
    | IDENTIFIER            {  }
    ;


%%

int main(int argc, char** argv) {
    // Verificar se o nome do arquivo de entrada foi fornecido
    if (argc != 2) {
        printf("Uso: %s <arquivo_de_entrada>\n", argv[0]);
        return 1;
    }

    // Abrir o arquivo de entrada
    FILE* input_file = fopen(argv[1], "r");
    if (!input_file) {
        printf("Erro ao abrir o arquivo de entrada.\n");
        return 1;
    }

    // Definir o arquivo de entrada para o Flex
    yyin = input_file;

    // Chamar o parser
    yyparse();

    // Imprimir a tabela de símbolos
    print_symbol_table();

    // Fechar o arquivo de entrada
    fclose(input_file);

    return 0;
}