%{
#include <stdio.h>
%}

/* This tells flex to read only one input file */
%option noyywrap




/* definicoes regulares */
ws [ \t\n]

digit [0-9]
positive [+]?{digit}+
negative [-]{digit}+
decimal [+]?[-]?{digit}+[.]{digit}+

low [a-z]
upper [A-Z]
word ["']*[a-zA-Z][a-zA-Z0-9_"']*

%%
\/ahoy.*belay\/           { printf("COMMENTS\n"); }

windward                   { printf("UNSIGNED\n"); }
leeward                    { printf("SIGNED\n"); }
cutlass                    { printf("SHORT\n"); }
musket                     { printf("LONG\n"); }
inport                     { printf("INCLUDE\n"); }
oggin                      { printf("MAIN\n"); }
anchor                     { printf("BREAK\n"); }
trade                      { printf("CASE\n"); }
rigging                    { printf("CONST\n"); }
mast                       { printf("CONTINUE\n"); }
pirate                     { printf("DEFAULT\n"); }
spyglass                   { printf("IF\n"); }
parley                     { printf("ELSE\n"); }
crew                       { printf("ENUM\n"); }
land_ho                    { printf("RETURN\n"); }
chest                      { printf("STRUCT\n"); }

jib                        { printf("INT\n"); }
boat                       { printf("FLOAT\n"); }
ship                       { printf("DOUBLE\n"); }
addled                     { printf("BOOL\n"); }
aye                        { printf("TRUE\n"); }
arr                        { printf("FALSE\n"); }
sailor                     { printf("CHAR\n"); }

weigh_anchor               { printf("DO\n"); }
parrot                     { printf("PRINTF\n"); }
plunder                    { printf("SCANF\n"); }
voyage                     { printf("FOR\n"); }
compass                    { printf("GOTO\n"); }
rummage                    { printf("SIZEOF\n"); }
sweet                      { printf("SWITCH\n"); }
charter                    { printf("TYPEDEF\n"); }
treasure                   { printf("UNION\n"); }
squall                     { printf("WHILE\n"); }
swab                       { printf("FREE\n"); }
harpoon                    { printf("POINTER\n"); }

gully                      { printf("SLICE\n"); }
hoard                      { printf("SOME\n"); }
booty                      { printf("REDUCE\n"); }
net                        { printf("FILTER\n"); }
chart                      { printf("MAP\n"); }
plunderhaul                { printf("SORT\n"); }

"="                        { printf("ASSIGN\n"); }
":"                        { printf("COLON\n"); }

"=="                       { printf("EQ\n"); }
"!="                       { printf("NE\n"); }
"<"                        { printf("LT\n"); }
">"                        { printf("GT\n"); }
"<="                       { printf("LE\n"); }
">="                       { printf("GE\n"); }

"rum"                      { printf("LOGICAL_AND\n"); }
"grog"                     { printf("LOGICAL_OR\n"); }
"sober"                    { printf("LOGICAL_NOT\n"); }

"++"                       { printf("INCREMENT\n"); }
"--"                       { printf("DECREMENT\n"); }

"&"                        { printf("BITWISE_AND\n"); }
"|"                        { printf("BITWISE_OR\n"); }
"^"                        { printf("BITWISE_XOR\n"); }
"~"                        { printf("BITWISE_NOT\n"); }
"<<"                       { printf("LEFT_SHIFT\n"); }
">>"                       { printf("RIGHT_SHIFT\n"); }
"&^"                       { printf("BITWISE_AND_NOT\n"); }

"⚓️"                        { printf("BLOCK_OPEN\n"); }
"\⚓️;"                      { printf("BLOCK_CLOSE\n"); }
";"                        { printf("SEMICOLON\n"); }
"("                        { printf("OPEN_PAREN\n"); }
")"                        { printf("CLOSE_PAREN\n"); }
"["                        { printf("OPEN_BRACKET\n"); }
"]"                        { printf("CLOSE_BRACKET\n"); }
"{"                        { printf("OPEN_BRACE\n"); }
"}"                        { printf("CLOSE_BRACE\n"); }

{ws}+ { /*Espaços em branco, tabulação e quebra de linha devem ser ignorados.*/ }
{positive}                 { printf("Foi encontrado um número inteiro positivo. LEXEMA: %s\n", yytext); }
{negative}                 { printf("Foi encontrado um número inteiro negativo. LEXEMA: %s\n", yytext); }
{decimal}                  { printf("Foi encontrado um número número com parte decimal. LEXEMA: %s\n", yytext); }
{word}                  { printf("Foi encontrado uma string. LEXEMA: %s\n", yytext); }
. { printf("Token não reconhecido. LEXEMA: %s\n", yytext); }
%%

/*codigo em C. Foi criado o main, mas podem ser criadas outras funcoes aqui.*/
int main(void)
{
    /* Call the lexer, then quit. */
    yylex();
    return 0;
}