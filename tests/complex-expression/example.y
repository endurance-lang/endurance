%{
    #include <stdio.h>
    int yylex(void);
    void yyerror(char*);
    
    extern int cnt_lines;
    extern int depth;
    extern int sym[100][256];
%}

%token NUMBER
%token IDENTIFIER
%token INVALID

%left '+' '-'
%left '*' '/'

%%

program:
    program stmt                    {  }
    |
    ;

stmt:
    expr ';'                        { printf("%d\n", $1); }
    | IDENTIFIER '=' expr ';'       { sym[depth][$1] = $3; }
    | '{' program '}'
    ;

expr:
    | expr '+' expr         { $$ = $1 + $3; }
    | expr '-' expr         { $$ = $1 - $3; }
    | expr '*' expr         { $$ = $1 * $3; }
    | expr '/' expr         { $$ = $1 / $3; }
    | '(' expr ')'          { $$ = $2; }
    | NUMBER                { $$ = $1; }
    | IDENTIFIER            { $$ = sym[depth][$1]; }
    ;


%%

int main(void) {
    yyparse();
    return 0;
}