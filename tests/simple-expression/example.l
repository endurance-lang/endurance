%{
    #include <stdio.h>
    #include "y.tab.h"

    int cnt_lines = 1;
%}

/* This tells flex to read only one input file */
%option noyywrap

/* definicoes regulares */
ws                          [ \t\n]
digit                       [0-9]
number                      {digit}+

%%
[-+()]                      { return *yytext; }

{ws}                        { 
                                cnt_lines += (*yytext == '\n');
                            }
{number}                    { 
                                yylval = atoi(yytext);
                                return NUMBER; 
                            }
.                           { return INVALID; }
%%


void yyerror(char *s) {
    fprintf(stderr, "Error on line %d: %s\n", cnt_lines, s);
}