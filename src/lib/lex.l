%{
#include <stdio.h>
#include "types.h"
#include "translate.tab.h" // Inclua o arquivo .tab.h gerado pelo Bison

int line = 1;
%}

/* This tells flex to read only one input file */
%option noyywrap

/* definicoes regulares */
ws                          [ \t\n]

digit                       [0-9]
integer                     {digit}+
decimal                     {digit}+[.]{digit}+

word1q                      [']([^'\n]|"\\\'")*[']
word2q                      ["]([^"\n]|"\\\"")*["]
word                        {word1q}|{word2q}

identifier                  [A-Za-z_][A-Za-z0-9_]*

%%
\/ahoy.*belay\/             {  }

inport                      { return INCLUDE; }
oggin                       { yylval.data.data.string = strdup(yytext); return IDENTIFIER; }
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

jib                         { yylval.data.data.string = strdup(yytext); return IDENTIFIER; }
boat                        { yylval.data.data.string = strdup(yytext); return IDENTIFIER; }
ship                        { yylval.data.data.string = strdup(yytext); return IDENTIFIER; }
addled                      { yylval.data.data.string = strdup(yytext); return IDENTIFIER; }
aye                         { yylval.data.data.boolean = 1; return TRUE; }
arr                         { yylval.data.data.boolean = 0; return FALSE; }
sailor                      { yylval.data.data.string = strdup(yytext); return IDENTIFIER; }

weigh_anchor                { return DO; }
parrot                      { yylval.data.data.string = strdup(yytext); return IDENTIFIER; }
plunder                     { yylval.data.data.string = strdup(yytext); return IDENTIFIER; }
voyage                      { return FOR; }
compass                     { return GOTO; }
rummage                     { return SIZEOF; }
sweet                       { return SWITCH; }
charter                     { return TYPEDEF; }
treasure                    { return UNION; }
squall                      { return WHILE; }
swab                        { yylval.data.data.string = strdup(yytext); return IDENTIFIER; }
harpoon                     { return POINTER; }

gully                       { yylval.data.data.string = strdup(yytext); return IDENTIFIER; }
hoard                       { yylval.data.data.string = strdup(yytext); return IDENTIFIER; }
booty                       { yylval.data.data.string = strdup(yytext); return IDENTIFIER; }
net                         { yylval.data.data.string = strdup(yytext); return IDENTIFIER; }
chart                       { yylval.data.data.string = strdup(yytext); return IDENTIFIER; }
plunderhaul                 { yylval.data.data.string = strdup(yytext); return IDENTIFIER; }

"]"                         { return CLOSE_BRACKET; }
"["                         { return OPEN_BRACKET; }
")"                         { return CLOSE_PAREN; }
"("                         { return OPEN_PAREN; }
"⚓️;"                       { return BLOCK_CLOSE; }
"⚓️"                        { return BLOCK_OPEN; }
"."                         { return DOT; }
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
":"                         { return COLON; }
";"                         { return SEMI_COLON; }
"="                         { return ASSIGN; }
","                         { return COMMA; }

{ws}                        { line += (*yytext == '\n'); }
{integer}                   { yylval.data.data.integer = atoi(yytext); return INTEGER; }
{decimal}                   { yylval.data.data.decimal = atof(yytext); return DECIMAL; }
{word}                      { yylval.data.data.string = strdup(yytext); return STRING; }
{identifier}                { yylval.data.data.string = strdup(yytext); return IDENTIFIER; }
.                           { printf("Token não reconhecido. LEXEMA: %s\n", yytext); return INVALID; }
%%