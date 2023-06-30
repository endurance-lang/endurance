%{
#include <stdio.h>
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
oggin                       { yylval.string = strdup(yytext); return IDENTIFIER; }
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

jib                         { yylval.string = strdup(yytext); return IDENTIFIER; }
boat                        { yylval.string = strdup(yytext); return IDENTIFIER; }
ship                        { yylval.string = strdup(yytext); return IDENTIFIER; }
addled                      { yylval.string = strdup(yytext); return IDENTIFIER; }
aye                         { yylval.boolean = 1; return TRUE; }
arr                         { yylval.boolean = 0; return FALSE; }
sailor                      { yylval.string = strdup(yytext); return IDENTIFIER; }

weigh_anchor                { return DO; }
parrot                      { yylval.string = strdup(yytext); return IDENTIFIER; }
plunder                     { yylval.string = strdup(yytext); return IDENTIFIER; }
voyage                      { return FOR; }
compass                     { return GOTO; }
rummage                     { return SIZEOF; }
sweet                       { return SWITCH; }
charter                     { return TYPEDEF; }
treasure                    { return UNION; }
squall                      { return WHILE; }
swab                        { yylval.string = strdup(yytext); return IDENTIFIER; }
harpoon                     { return POINTER; }

gully                       { yylval.string = strdup(yytext); return IDENTIFIER; }
hoard                       { yylval.string = strdup(yytext); return IDENTIFIER; }
booty                       { yylval.string = strdup(yytext); return IDENTIFIER; }
net                         { yylval.string = strdup(yytext); return IDENTIFIER; }
chart                       { yylval.string = strdup(yytext); return IDENTIFIER; }
plunderhaul                 { yylval.string = strdup(yytext); return IDENTIFIER; }

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
{integer}                   { yylval.integer = atoi(yytext); return INTEGER; }
{decimal}                   { yylval.decimal = atof(yytext); return DECIMAL; }
{word}                      { yylval.string = strdup(yytext); return STRING; }
{identifier}                { yylval.string = strdup(yytext); return IDENTIFIER; }
.                           { printf("Token não reconhecido. LEXEMA: %s\n", yytext); return INVALID; }
%%