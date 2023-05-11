%{
#include <stdio.h>
%}

/* This tells flex to read only one input file */
%option noyywrap

/* definicoes regulares */

%%

%%

/*codigo em C. Foi criado o main, mas podem ser criadas outras funcoes aqui.*/
int main(void)
{
    /* Call the lexer, then quit. */
    yylex();
    return 0;
}