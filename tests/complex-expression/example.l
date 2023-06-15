%{
    #include <stdio.h>
    #include "y.tab.h"

    int cnt_lines = 1;
    int depth = 0;
    int sym[100][256];
%}

/* This tells flex to read only one input file */
%option noyywrap

/* definicoes regulares */
ws                          [ \t]
digit                       [0-9]
number                      {digit}+

identifier                  [a-zA-Z_]

%%
[\n]                        { cnt_lines++; }
[-+()*/=;]                  { return *yytext; }
"{"                         { depth++; return *yytext; }
"}"                         { depth--; return *yytext; }


{ws}                        { /* ignore */ }
{number}                    { 
                                yylval = atoi(yytext);
                                return NUMBER; 
                            }
{identifier}                { yylval = *yytext; return IDENTIFIER; }
.                           { return INVALID; }
%%


void yyerror(char *s) {
    fprintf(stderr, "Error on line %d: %s\n", cnt_lines, s);
}