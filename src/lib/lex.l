%{
#include <stdio.h>
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
\/ahoy.*belay\/             { printf("COMMENTS; LEXEMA: %s\n", yytext); }

windward                    { printf("UNSIGNED; LEXEMA: %s\n", yytext); }
leeward                     { printf("SIGNED; LEXEMA: %s\n", yytext); }
cutlass                     { printf("SHORT; LEXEMA: %s\n", yytext); }
musket                      { printf("LONG; LEXEMA: %s\n", yytext); }
inport                      { printf("INCLUDE; LEXEMA: %s\n", yytext); }
oggin                       { printf("MAIN; LEXEMA: %s\n", yytext); }
anchor                      { printf("BREAK; LEXEMA: %s\n", yytext); }
trade                       { printf("CASE; LEXEMA: %s\n", yytext); }
rigging                     { printf("CONST; LEXEMA: %s\n", yytext); }
mast                        { printf("CONTINUE; LEXEMA: %s\n", yytext); }
pirate                      { printf("DEFAULT; LEXEMA: %s\n", yytext); }
spyglass                    { printf("IF; LEXEMA: %s\n", yytext); }
parley                      { printf("ELSE; LEXEMA: %s\n", yytext); }
crew                        { printf("ENUM; LEXEMA: %s\n", yytext); }
land_ho                     { printf("RETURN; LEXEMA: %s\n", yytext); }
chest                       { printf("STRUCT; LEXEMA: %s\n", yytext); }

jib                         { printf("INT; LEXEMA: %s\n", yytext); }
boat                        { printf("FLOAT; LEXEMA: %s\n", yytext); }
ship                        { printf("DOUBLE; LEXEMA: %s\n", yytext); }
addled                      { printf("BOOL; LEXEMA: %s\n", yytext); }
aye                         { printf("TRUE; LEXEMA: %s\n", yytext); }
arr                         { printf("FALSE; LEXEMA: %s\n", yytext); }
sailor                      { printf("CHAR; LEXEMA: %s\n", yytext); }

weigh_anchor                { printf("DO; LEXEMA: %s\n", yytext); }
parrot                      { printf("PRINTF; LEXEMA: %s\n", yytext); }
plunder                     { printf("SCANF; LEXEMA: %s\n", yytext); }
voyage                      { printf("FOR; LEXEMA: %s\n", yytext); }
compass                     { printf("GOTO; LEXEMA: %s\n", yytext); }
rummage                     { printf("SIZEOF; LEXEMA: %s\n", yytext); }
sweet                       { printf("SWITCH; LEXEMA: %s\n", yytext); }
charter                     { printf("TYPEDEF; LEXEMA: %s\n", yytext); }
treasure                    { printf("UNION; LEXEMA: %s\n", yytext); }
squall                      { printf("WHILE; LEXEMA: %s\n", yytext); }
swab                        { printf("FREE; LEXEMA: %s\n", yytext); }
harpoon                     { printf("POINTER; LEXEMA: %s\n", yytext); }

gully                       { printf("SLICE; LEXEMA: %s\n", yytext); }
hoard                       { printf("SOME; LEXEMA: %s\n", yytext); }
booty                       { printf("REDUCE; LEXEMA: %s\n", yytext); }
net                         { printf("FILTER; LEXEMA: %s\n", yytext); }
chart                       { printf("MAP; LEXEMA: %s\n", yytext); }
plunderhaul                 { printf("SORT; LEXEMA: %s\n", yytext); }

"]"                         { printf("CLOSE_BRACKET; LEXEMA: %s\n", yytext); }
"["                         { printf("OPEN_BRACKET; LEXEMA: %s\n", yytext); }
")"                         { printf("CLOSE_PAREN; LEXEMA: %s\n", yytext); }
"("                         { printf("OPEN_PAREN; LEXEMA: %s\n", yytext); }
"⚓️;"                       { printf("BLOCK_CLOSE; LEXEMA: %s\n", yytext); }
"⚓️"                        { printf("BLOCK_OPEN; LEXEMA: %s\n", yytext); }
"."                         { printf("DOT; LEXEMA: %s\n", yytext); }
"++"                        { printf("INCREMENT; LEXEMA: %s\n", yytext); }
"--"                        { printf("DECREMENT; LEXEMA: %s\n", yytext); }
"+"                         { printf("ADD; LEXEMA: %s\n", yytext); }
"-"                         { printf("SUB; LEXEMA: %s\n", yytext); }
"*"                         { printf("MUL; LEXEMA: %s\n", yytext); }
"/"                         { printf("DIV; LEXEMA: %s\n", yytext); }
"&"                         { printf("BITWISE_AND; LEXEMA: %s\n", yytext); }
"|"                         { printf("BITWISE_OR; LEXEMA: %s\n", yytext); }
"~"                         { printf("BITWISE_NOT; LEXEMA: %s\n", yytext); }
"%"                         { printf("MOD; LEXEMA: %s\n", yytext); }
"<<"                        { printf("LEFT_SHIFT; LEXEMA: %s\n", yytext); }
">>"                        { printf("RIGHT_SHIFT; LEXEMA: %s\n", yytext); }
"<"                         { printf("LT; LEXEMA: %s\n", yytext); }
">"                         { printf("GT; LEXEMA: %s\n", yytext); }
"<="                        { printf("LE; LEXEMA: %s\n", yytext); }
">="                        { printf("GE; LEXEMA: %s\n", yytext); }
"=="                        { printf("EQ; LEXEMA: %s\n", yytext); }
"!="                        { printf("NE; LEXEMA: %s\n", yytext); }
"^"                         { printf("BITWISE_XOR; LEXEMA: %s\n", yytext); }
"rum"                       { printf("LOGICAL_AND; LEXEMA: %s\n", yytext); }
"grog"                      { printf("LOGICAL_OR; LEXEMA: %s\n", yytext); }
"sober"                     { printf("LOGICAL_NOT; LEXEMA: %s\n", yytext); }
"?"                         { printf("QUEST; LEXEMA: %s\n", yytext); }
":"                         { printf("COLON; LEXEMA: %s\n", yytext); }
";"                         { printf("SEMI_COLON; LEXEMA: %s\n", yytext); }
"="                         { printf("ASSIGN; LEXEMA: %s\n", yytext); }
"+="                        { printf("ADD_ASSIGN; LEXEMA: %s\n", yytext); }
"-="                        { printf("SUB_ASSIGN; LEXEMA: %s\n", yytext); }
"*="                        { printf("MUL_ASSIGN; LEXEMA: %s\n", yytext); }
"/="                        { printf("DIV_ASSIGN; LEXEMA: %s\n", yytext); }
"%="                        { printf("MOD_ASSIGN; LEXEMA: %s\n", yytext); }
"<<="                       { printf("LEFT_SHIFT_ASSIGN; LEXEMA: %s\n", yytext); }
">>="                       { printf("RIGHT_SHIFT_ASSIGN; LEXEMA: %s\n", yytext); }
"&="                        { printf("BITWISE_AND_ASSIGN; LEXEMA: %s\n", yytext); }
"|="                        { printf("BITWISE_OR_ASSIGN; LEXEMA: %s\n", yytext); }
"^="                        { printf("BITWISE_XOR_ASSIGN; LEXEMA: %s\n", yytext); }
","                         { printf("COMMA; LEXEMA: %s\n", yytext); }

{ws}                        { /*Espaços em branco, tabulação e quebra de linha devem ser ignorados.*/ }
{positive}                  { printf("Foi encontrado um número inteiro positivo. LEXEMA: %s\n", yytext); }
{negative}                  { printf("Foi encontrado um número inteiro negativo. LEXEMA: %s\n", yytext); }
{decimal_pos}               { printf("Foi encontrado um número número com parte decimal positivo. LEXEMA: %s\n", yytext); }
{decimal_neg}               { printf("Foi encontrado um número número com parte decimal negativo. LEXEMA: %s\n", yytext); }
{word}                      { printf("Foi encontrado uma string. LEXEMA: %s\n", yytext); }
{identifier}                { printf("Foi encontrado um identificador. LEXEMA: %s\n", yytext); }
.                           { printf("Token não reconhecido. LEXEMA: %s\n", yytext); }
%%

/*codigo em C. Foi criado o main, mas podem ser criadas outras funcoes aqui.*/
int main(void)
{
    /* Call the lexer, then quit. */
    yylex();
    return 0;
}