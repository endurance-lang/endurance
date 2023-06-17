%{
#include <stdio.h>
#include "../symbolTable.h"
#include "translate.tab.h" // Inclua o arquivo .tab.h gerado pelo Bison

int line = 1;
%}

/* This tells flex to read only one input file */
%option noyywrap

/* definicoes regulares */
ws                          [ \t\n]

digit                       [0-9]
positive                    [+]?{digit}+
negative                    [-]{digit}+
decimal_pos                 [+]?{digit}+[.]{digit}+
decimal_neg                 [-]{digit}+[.]{digit}+ 

low                         [a-z]
upper                       [A-Z]
word1q                      [']([^'\n]|"\\\'")*[']
word2q                      ["]([^"\n]|"\\\"")*["]
word                        {word1q}|{word2q}

identifier                  [A-Za-z_][A-Za-z0-9_]*

%%
\/ahoy.*belay\/             {  }

windward                    { return UNSIGNED; }
leeward                     { return SIGNED; }
cutlass                     { return SHORT; }
musket                      { return LONG; }
inport                      { return INCLUDE; }
oggin                       { return MAIN; }
anchor                      { return BREAK; }
trade                       { return CASE; }
rigging                     { return CONST; }
mast                        { return CONTINUE; }
pirate                      { return DEFAULT; }
spyglass                    { return IF; }
parley                      { return ELSE; }
crew                        { return ENUM; }
land_ho                     { return RETURN; }
chest                       { return STRUCT; }

jib                         { return INT; }
boat                        { return FLOAT; }
ship                        { return DOUBLE; }
addled                      { return BOOL; }
aye                         { return TRUE; }
arr                         { return FALSE; }
sailor                      { return CHAR; }

weigh_anchor                { return DO; }
parrot                      { return PRINTF; }
plunder                     { return SCANF; }
voyage                      { return FOR; }
compass                     { return GOTO; }
rummage                     { return SIZEOF; }
sweet                       { return SWITCH; }
charter                     { return TYPEDEF; }
treasure                    { return UNION; }
squall                      { return WHILE; }
swab                        { return FREE; }
harpoon                     { return POINTER; }

gully                       { return SLICE; }
hoard                       { return SOME; }
booty                       { return REDUCE; }
net                         { return FILTER; }
chart                       { return MAP; }
plunderhaul                 { return SORT; }

"]"                         { return CLOSE_BRACKET; }
"["                         { return OPEN_BRACKET; }
")"                         { return CLOSE_PAREN; }
"("                         { return OPEN_PAREN; }
"⚓️;"                       { return BLOCK_CLOSE; }
"⚓️"                        { return BLOCK_OPEN; }
"."                         { return DOT; }
"++"                        { return INCREMENT; }
"--"                        { return DECREMENT; }
"+"                         { return ADD; }
"-"                         { return SUB; }
"*"                         { return MUL; }
"/"                         { return DIV; }
"&"                         { return BITWISE_AND; }
"|"                         { return BITWISE_OR; }
"~"                         { return BITWISE_NOT; }
"%"                         { return MOD; }
"<<"                        { return LEFT_SHIFT; }
">>"                        { return RIGHT_SHIFT; }
"<"                         { return LT; }
">"                         { return GT; }
"<="                        { return LE; }
">="                        { return GE; }
"=="                        { return EQ; }
"!="                        { return NE; }
"^"                         { return BITWISE_XOR; }
"rum"                       { return LOGICAL_AND; }
"grog"                      { return LOGICAL_OR; }
"sober"                     { return LOGICAL_NOT; }
"?"                         { return QUEST; }
":"                         { return COLON; }
";"                         { return SEMI_COLON; }
"="                         { return ASSIGN; }
"+="                        { return ADD_ASSIGN; }
"-="                        { return SUB_ASSIGN; }
"*="                        { return MUL_ASSIGN; }
"/="                        { return DIV_ASSIGN; }
"%="                        { return MOD_ASSIGN; }
"<<="                       { return LEFT_SHIFT_ASSIGN; }
">>="                       { return RIGHT_SHIFT_ASSIGN; }
"&="                        { return BITWISE_AND_ASSIGN; }
"|="                        { return BITWISE_OR_ASSIGN; }
"^="                        { return BITWISE_XOR_ASSIGN; }
","                         { return COMMA; }

{ws}                        { line += (*yytext == '\n'); }
{positive}                  { yylval.number = atoi(yytext); return INTEGER; }
{negative}                  { yylval.number = atoi(yytext); return INTEGER; }
{decimal_pos}               { yylval.decimal = atof(yytext); return DECIMAL; }
{decimal_neg}               { yylval.decimal = atof(yytext); return DECIMAL; }
{word}                      { yylval.string = strdup(yytext); return STRING; }
{identifier}                { yylval.string = strdup(yytext); return IDENTIFIER; }
.                           { printf("Token não reconhecido. LEXEMA: %s\n", yytext); }
%%