%{
    #include <stdio.h>
    #include "../../src/symbolTable.h"
    int yylex(void);
    void yyerror(char*);

    void onExit();
    
    extern int cnt_lines;
    extern SymbolTable *st;
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
    expr ';'                        {  }
    | IDENTIFIER '=' expr ';'       {  }
    | '{' program '}'               {  }
    ;

expr:
    | expr '+' expr         {  }
    | expr '-' expr         {  }
    | expr '*' expr         {  }
    | expr '/' expr         {  }
    | '(' expr ')'          {  }
    | NUMBER                {  }
    | IDENTIFIER            {  }
    ;


%%

void onExit() {
    symbolTableDelete(st);
}

int main(void) {
    st = symbolTableNew();
    symbolTableCreateBlock(st);
    yyparse();
    symbolTableShow(st);
    symbolTableDeleteBlock(st);
    return 0;
}