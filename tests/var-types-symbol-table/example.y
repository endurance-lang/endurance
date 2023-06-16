%{
    #include <stdio.h>
    #include "../../src/symbolTable.h"
    int yylex(void);
    void yyerror(char*);

    void onExit();
    
    extern int cnt_lines;
    SymbolTable *st;
%}

%union {
    int intValue;
    double doubleValue;
    char *strValue;
    Enumtypes typeValue;
};

%token <intValue> INTEGER
%token <doubleValue> DECIMAL
%token <strValue> IDENTIFIER
%token INT
%token DOUBLE
%token INVALID

%left '+' '-'
%left '*' '/'

%type <typeValue> type

%%

program:
    program stmt                    {  }
    |
    ;

stmt:
    type IDENTIFIER                 
                                    { symbolTableInsert(st, symbolNew(yylval.strValue, $1, 1)); }
    ';'

    | IDENTIFIER '=' expr ';'       {  }
    
    |                               { symbolTableCreateBlock(st); } 
        '{' program '}' 
                                    { 
                                        symbolTableShow(st);
                                        symbolTableDeleteBlock(st);
                                    }
    ;

type:
    INT                             { $$ = type_int; }
    | DOUBLE                        { $$ = type_double; }
    ;

expr:
    | expr '+' expr         {  }
    | expr '-' expr         {  }
    | expr '*' expr         {  }
    | expr '/' expr         {  }
    | '(' expr ')'          {  }
    | INTEGER               {  }
    | DECIMAL               {  }
    | IDENTIFIER            {  }
    ;


%%

void onExit() {
    symbolTableDelete(st);
}

void yyerror(char *s) {
    fprintf(stderr, "Error on line %d: %s\n", cnt_lines, s);
    onExit();
}

int main(void) {
    st = symbolTableNew();
    symbolTableCreateBlock(st);
    yyparse();
    symbolTableShow(st);
    symbolTableDeleteBlock(st);
    onExit();
    return 0;
}