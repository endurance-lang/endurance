%{
    #include <stdio.h>
    #include "../../src/symbolTable.h"
    #include "y.tab.h"

    int cnt_lines = 1;
    SymbolTable *st;
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
"{"                         { 
                                symbolTableCreateBlock(st);
                                return *yytext; 
                            }
"}"                         { 
                                symbolTableShow(st);
                                symbolTableDeleteBlock(st);
                                return *yytext; 
                            }


{ws}                        { /* ignore */ }
{number}                    { 
                                yylval = atoi(yytext);
                                return NUMBER;
                            }
{identifier}                { 
                                symbolTableInsert(st, symbolNew(yytext, type_int, 1));
                                return IDENTIFIER;
                            }
.                           { return INVALID; }
%%


void yyerror(char *s) {
    fprintf(stderr, "Error on line %d: %s\n", cnt_lines, s);
}