%{
    #include <stdio.h>
    int yylex(void);
    void yyerror(char*);
%}

%token NUMBER INVALID

%%

program:
    program expr        { printf("%d\n", $2); }
    |
    ;

expr:
    | expr '+' term     {$$ = $1 + $3;}
    | expr '-' term     {$$ = $1 - $3;}
    | term              {$$ = $1;}
    ;

term:
    NUMBER              {$$ = $1;}
    | '(' expr ')'      {$$ = $2;}

%%

int main(void) {
    yyparse();
    return 0;
}