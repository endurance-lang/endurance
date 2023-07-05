%{
    #include <stdio.h>
    #include <string.h>
    #include "../../src/symbolTable.h"
    #include "y.tab.h"

    int cnt_lines = 1;
%}

/* This tells flex to read only one input file */
%option noyywrap

/* definicoes regulares */
ws                          [ \t]
digit                       [0-9]
integer                     [+-]?{digit}+
double                      [+-]?{digit}+[.]{digit}+

identifier                  [a-zA-Z_][a-zA-Z0-9_]*

%%
[\n]                        { cnt_lines++; }
[-+()*/=;{}]                { return *yytext; }
"int"                       { return INT; }
"double"                    { return DOUBLE; }


{ws}                        { /* ignore */ }
{integer}                   { 
                                yylval.intValue = atoi(yytext);
                                return INTEGER;
                            }
{double}                    {
                                yylval.doubleValue = strtod(yytext, NULL);
                                return DECIMAL;
                            }
{identifier}                { 
                                yylval.strValue = yytext;
                                return IDENTIFIER; 
                            }
.                           { return INVALID; }
%%

