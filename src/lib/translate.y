%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../symbol-table/symbolTable.h"
#include "../utils/print-source-code.h"
#include "../risc-v/riscV-context.h"
#include "../pseudo/pseudo-context.h"
#include "types.h"
#include <stdarg.h>
#include <assert.h>

extern int yylex();
extern void yyerror(const char*);
extern FILE* yyin; // Declarar a variável global de entrada do analisador léxico
extern int line;

void onExit();
void onStart();
void executeProgram();

SymbolTable *st;
FILE *prod, *gen;

FILE *friscv;
RiscVContext *riscv;

FILE *fpseudo;
PseudoContext *pseudo;

FILE *dot;
int nextLabel = 1;

int nextAddress = 0;

void blockOpen();
void blockClose();

// void handleStruct();
void handleVarDeclaration(char *type, char *id, int size);
ExprData handleAttr(char *id);
void handleOperation(int opcode, ...);
ExprData handleBinaryExpr(int opcode, ExprData e1, ExprData e2);
ExprData handleUnaryExpr(int opcode, ExprData e);
ExprData handleAssignExpr(char *id, ExprData e);
void reportAndExit(const char *s, ...);

char *mergeStrPointers(char *a, char *b);

void handleIfAfterExpr(ExprData e);
void handleIfAfterStmt();
void handleIfAfterElse();

void handleRepEntry();
void handleRepAfterExpr(ExprData e);
void handleRepUpdate();
void handleRepStmt();
void handleRepExit();

void handleRepGotoEntry();
void handleRepGotoUpdate();

ExprData handleFunctionCall(char *id, FuncParamList *params);

ExprData handleInteger(int integer);

%}

%union {
    struct {
        union {
            char *string;
            int integer;
            double decimal;
            int boolean;
            ExprData exprData;
            FuncParamList *paramList;
        } data;
        int node_id;
    } data;
};

%token INCLUDE MAIN BREAK CASE CONST CONTINUE DEFAULT IF ELSE ENUM RETURN STRUCT DO PRINTF SCANF FOR GOTO SIZEOF SWITCH TYPEDEF UNION WHILE FREE POINTER SLICE SOME REDUCE FILTER MAP SORT CLOSE_BRACKET OPEN_BRACKET CLOSE_PAREN OPEN_PAREN BLOCK_CLOSE BLOCK_OPEN ADD SUB MUL DIV BITWISE_AND BITWISE_OR BITWISE_NOT MOD LEFT_SHIFT RIGHT_SHIFT LT GT LE GE EQ NE BITWISE_XOR LOGICAL_AND LOGICAL_OR LOGICAL_NOT COLON SEMI_COLON ASSIGN COMMA INVALID UMINUS DOT

%token <data> DECIMAL STRING

%token <data> IDENTIFIER
%token <data> INTEGER
%token <data> TRUE FALSE

%type <data> constvector boolean attr expr term const exprvector exprlist optexprlist program stmts stmt conditional condexpr repetition repexpr var func typelist opttypelist commands varlist idlist optexpr

%start program

%left COMMA
%right ASSIGN
%right COLON
%left LOGICAL_OR
%left LOGICAL_AND
%left BITWISE_OR
%left BITWISE_XOR
%left BITWISE_AND
%left EQ NE
%left LT LE GE GT
%left LEFT_SHIFT RIGHT_SHIFT
%left ADD SUB
%left MUL DIV MOD
%right LOGICAL_NOT SIZEOF BITWISE_NOT
%left OPEN_PAREN CLOSE_PAREN OPEN_BRACKET CLOSE_BRACKET POINTER

%nonassoc IFX
%nonassoc ELSE
%nonassoc UNARY

%%

program: stmts                      { 
                                        symbolTableShow(st, stdout);
                                        printf("Programa sintaticamente correto\n");
                                        $$.node_id = nextLabel++; 
                                        fprintf(dot, "n%d [label=\"program\"]\n", $$.node_id); 
                                        fprintf(dot, "n%d -- n%d\n", $$.node_id, $1.node_id); 
                                    }
    ;

stmts: stmts stmt                   { 
                                        $$.node_id = nextLabel++; 
                                        fprintf(dot, "n%d [label=\"stmts\"]\n", $$.node_id);
                                        fprintf(dot, "n%d -- {n%d n%d}\n", $$.node_id, $1.node_id, $2.node_id); 
                                    }
    | /* EPS */                     { 
                                        $$.node_id = nextLabel++; 
                                        int eps = nextLabel++; 
                                        fprintf(dot, "n%d [label=\"stmts\"]\n", $$.node_id);
                                        fprintf(dot, "n%d [label=\"&#x03B5;\"]\n",eps); 
                                        fprintf(dot, "n%d -- n%d\n", $$.node_id, eps); 
                                    }
    ;

stmt: conditional               { 
                                    $$.node_id = nextLabel++; 
                                    fprintf(dot, "n%d [label=\"stmt\"]\n", $$.node_id); 
                                    fprintf(dot, "n%d -- n%d\n", $$.node_id, $1.node_id);
                                }
    | repetition                { 
                                    $$.node_id = nextLabel++; 
                                    fprintf(dot, "n%d [label=\"stmt\"]\n", $$.node_id); 
                                    fprintf(dot, "n%d -- n%d\n", $$.node_id, $1.node_id);
                                }
    | func                      { 
                                    $$.node_id = nextLabel++; 
                                    fprintf(dot, "n%d [label=\"stmt\"]\n", $$.node_id); 
                                    fprintf(dot, "n%d -- n%d\n", $$.node_id, $1.node_id);
                                }
    | var SEMI_COLON            { 
                                    $$.node_id = nextLabel++; 
                                    int semicolon = nextLabel++; 
                                    fprintf(dot, "n%d [label=\"stmt\"]\n", $$.node_id);  
                                    fprintf(dot, "n%d [label=\";\"]\n", semicolon); 
                                    fprintf(dot, "n%d -- {n%d n%d}\n", $$.node_id, $1.node_id, semicolon); }
    | commands                  { 
                                    $$.node_id = nextLabel++; 
                                    fprintf(dot, "n%d [label=\"stmt\"]\n", $$.node_id); 
                                    fprintf(dot, "n%d -- n%d\n", $$.node_id, $1.node_id);
                                }
    | expr SEMI_COLON           { 
                                    $$.node_id = nextLabel++; 
                                    int semicolon = nextLabel++; 
                                    fprintf(dot, "n%d [label=\"stmt\"]\n", $$.node_id);  
                                    fprintf(dot, "n%d [label=\";\"]\n", semicolon); 
                                    fprintf(dot, "n%d -- {n%d n%d}\n", $$.node_id, $1.node_id, semicolon);
                                }
    | {blockOpen();} BLOCK_OPEN stmts BLOCK_CLOSE      { 
                                            blockClose();
                                            int block_open = nextLabel++;
                                            $$.node_id = nextLabel++;
                                            int block_close = nextLabel++;
                                               
                                            fprintf(dot, "n%d [label=\"&#9875;\"]\n", block_open);
                                            fprintf(dot, "n%d [label=\"stmt\"]\n", $$.node_id);
                                            fprintf(dot, "n%d [label=\"&#9875;;\"]\n", block_close);
                                            
                                            fprintf(dot, "{ rank=same; n%d n%d n%d; }\n", block_open, $3.node_id, block_close);
                                            
                                            fprintf(dot, "n%d -- n%d\n", $$.node_id, block_open);
                                            fprintf(dot, "n%d -- n%d\n", $$.node_id, $3.node_id);
                                            fprintf(dot, "n%d -- n%d\n", $$.node_id, block_close);

                                        }

conditional: IF OPEN_PAREN condexpr CLOSE_PAREN stmt %prec IFX {
                                                                    handleIfAfterStmt(); 
                                                                    handleIfAfterElse();

                                                                    $$.node_id = nextLabel++;
                                                                    int if_cond = nextLabel++; 
                                                                    int open_paren = nextLabel++;
                                                                    int close_paren = nextLabel++;
                                                                    
                                                                    fprintf(dot, "n%d [label=\"conditional\"]\n", $$.node_id);
                                                                    fprintf(dot, "n%d [label=\"IF\"]\n", if_cond);  
                                                                    fprintf(dot, "n%d [label=\"(\"]\n", open_paren);  
                                                                    fprintf(dot, "n%d [label=\")\"]\n", close_paren);   

                                                                    fprintf(dot, "{ rank=same; n%d n%d n%d n%d n%d; }\n", if_cond, open_paren, $3.node_id, close_paren, $5.node_id);
                                                                    
                                                                    fprintf(dot, "n%d -- n%d\n", $$.node_id, if_cond);
                                                                    fprintf(dot, "n%d -- n%d\n", $$.node_id, open_paren);
                                                                    fprintf(dot, "n%d -- n%d\n", $$.node_id, $3.node_id);
                                                                    fprintf(dot, "n%d -- n%d\n", $$.node_id, close_paren);
                                                                    fprintf(dot, "n%d -- n%d\n", $$.node_id, $5.node_id);
                                                                }
    | IF OPEN_PAREN condexpr CLOSE_PAREN stmt ELSE { 
                                                        handleIfAfterStmt();
                                                   } stmt { 
                                                        handleIfAfterElse(); 
                                                        $$.node_id = nextLabel++;
                                                        int if_cond = nextLabel++; 
                                                        int open_paren = nextLabel++;
                                                        int close_paren = nextLabel++;
                                                        int else_cond = nextLabel++;
                                                        
                                                        fprintf(dot, "n%d [label=\"conditional\"]\n", $$.node_id);
                                                        fprintf(dot, "n%d [label=\"IF\"]\n", if_cond);  
                                                        fprintf(dot, "n%d [label=\"(\"]\n", open_paren);  
                                                        fprintf(dot, "n%d [label=\")\"]\n", close_paren);   
                                                        fprintf(dot, "n%d [label=\"ELSE\"]\n", else_cond);   

                                                        fprintf(dot, "{ rank=same; n%d n%d n%d n%d n%d n%d n%d; }\n", if_cond, open_paren, $3.node_id, close_paren, $5.node_id, else_cond, $8.node_id);
                                                        
                                                        fprintf(dot, "n%d -- n%d\n", $$.node_id, if_cond);
                                                        fprintf(dot, "n%d -- n%d\n", $$.node_id, open_paren);
                                                        fprintf(dot, "n%d -- n%d\n", $$.node_id, $3.node_id);
                                                        fprintf(dot, "n%d -- n%d\n", $$.node_id, close_paren);
                                                        fprintf(dot, "n%d -- n%d\n", $$.node_id, $5.node_id);
                                                        fprintf(dot, "n%d -- n%d\n", $$.node_id, else_cond);
                                                        fprintf(dot, "n%d -- n%d\n", $$.node_id, $8.node_id);
                                                   }
    /* | SWITCH OPEN_PAREN expr CLOSE_PAREN BLOCK_OPEN caselist BLOCK_CLOSE {  } */
    ;

condexpr: expr                  { 
                                    handleIfAfterExpr($1.data.exprData); 

                                    $$.node_id = nextLabel++; 
                                    fprintf(dot, "n%d [label=\"condexpr\"]\n", $$.node_id); 
                                    fprintf(dot, "n%d -- n%d\n", $$.node_id, $1.node_id);

                                }
    ;

/* caselist: caselist CASE term COLON stmts    {  }
    | caselist DEFAULT COLON stmts          {  }
    |                                       {  }
    ; */

repetition: WHILE   {
                        handleRepEntry();
                    } 
                    OPEN_PAREN repexpr CLOSE_PAREN  {
                        handleRepStmt();
                    } stmt {
                        handleRepGotoEntry();
                        handleRepExit();

                        $$.node_id = nextLabel++;
                        int while_loop = nextLabel++;
                        int open_paren = nextLabel++;
                        int close_paren = nextLabel++;

                        fprintf(dot, "n%d [label=\"WHILE\"]\n", while_loop); 
                        fprintf(dot, "n%d [label=\"(\"]\n", open_paren);
                        fprintf(dot, "n%d [label=\"repetition\"]\n", $$.node_id); 
                        fprintf(dot, "n%d [label=\")\"]\n", close_paren);
                        
                        fprintf(dot, "{ rank=same; n%d n%d n%d n%d n%d; }\n", while_loop, open_paren, $4.node_id ,close_paren,$7.node_id);

                        fprintf(dot, "n%d -- n%d\n", $$.node_id, while_loop);
                        fprintf(dot, "n%d -- n%d\n", $$.node_id, open_paren);
                        fprintf(dot, "n%d -- n%d\n", $$.node_id, $4.node_id);
                        fprintf(dot, "n%d -- n%d\n", $$.node_id, close_paren);
                        fprintf(dot, "n%d -- n%d\n", $$.node_id, $7.node_id);
                    }

    | FOR OPEN_PAREN optexpr    {
                                    handleRepEntry();
                                } 
                                SEMI_COLON repexpr SEMI_COLON 
                                {
                                    handleRepUpdate();
                                } 
                                optexpr CLOSE_PAREN 
                                {
                                    handleRepGotoEntry();
                                    handleRepStmt();
                                } 
                                stmt {
                                    handleRepGotoUpdate();
                                    handleRepExit();

                                    $$.node_id = nextLabel++;
                                    int for_loop = nextLabel++;
                                    int open_paren = nextLabel++;
                                    int semicolon_1 = nextLabel++;
                                    int semicolon_2 = nextLabel++;
                                    int close_paren = nextLabel++;

                                    fprintf(dot, "n%d [label=\"repetition\"]\n", $$.node_id);
                                    fprintf(dot, "n%d [label=\"FOR\"]\n", for_loop);
                                    fprintf(dot, "n%d [label=\"(\"]\n", open_paren);
                                    fprintf(dot, "n%d [label=\";\"]\n", semicolon_1);
                                    fprintf(dot, "n%d [label=\";\"]\n", semicolon_2);
                                    fprintf(dot, "n%d [label=\")\"]\n", close_paren);

                                    fprintf(dot, "{ rank=same; n%d n%d n%d n%d n%d n%d n%d n%d n%d; }\n", for_loop, open_paren, $3.node_id, semicolon_1, $6.node_id, semicolon_2, $9.node_id, close_paren, $12.node_id);
                                    
                                    fprintf(dot, "n%d -- n%d\n", $$.node_id, for_loop);
                                    fprintf(dot, "n%d -- n%d\n", $$.node_id, open_paren);
                                    fprintf(dot, "n%d -- n%d\n", $$.node_id, $3.node_id);
                                    fprintf(dot, "n%d -- n%d\n", $$.node_id, semicolon_1);
                                    fprintf(dot, "n%d -- n%d\n", $$.node_id, $6.node_id);
                                    fprintf(dot, "n%d -- n%d\n", $$.node_id, semicolon_2);
                                    fprintf(dot, "n%d -- n%d\n", $$.node_id, $9.node_id);
                                    fprintf(dot, "n%d -- n%d\n", $$.node_id, close_paren);
                                    fprintf(dot, "n%d -- n%d\n", $$.node_id, $12.node_id);
                                }

    /* | DO {handleRepEntry();handleRepStmt();} stmt WHILE OPEN_PAREN repexpr CLOSE_PAREN SEMI_COLON {handleRepExit();} */
    ;

repexpr: expr   { 
                    handleRepAfterExpr($1.data.exprData);
                    $$.node_id = nextLabel++; 
                    fprintf(dot, "n%d [label=\"repexpr\"]\n", $$.node_id); 
                    fprintf(dot, "n%d -- n%d\n", $$.node_id, $1.node_id);
                }
    ;

var: IDENTIFIER IDENTIFIER constvector  { 
                                            handleVarDeclaration($1.data.string, $2.data.string, $3.data.integer);

                                            $$.node_id = nextLabel++;
                                            int identifier_1 = nextLabel++;
                                            int identifier_2 = nextLabel++;

                                            fprintf(dot, "n%d [label=\"var\"]\n", $$.node_id);
                                            fprintf(dot, "n%d [label=\"%s\"]\n", identifier_1, $1.data.string);
                                            fprintf(dot, "n%d [label=\"%s\"]\n", identifier_2, $2.data.string);

                                            fprintf(dot, "{ rank=same; n%d n%d n%d; }\n", identifier_1, identifier_2, $3.node_id);

                                            fprintf(dot, "n%d -- n%d\n", $$.node_id, identifier_1);
                                            fprintf(dot, "n%d -- n%d\n", $$.node_id, identifier_2);
                                            fprintf(dot, "n%d -- n%d\n", $$.node_id, $3.node_id);
                                        }
    ;

func: IDENTIFIER IDENTIFIER OPEN_PAREN opttypelist CLOSE_PAREN BLOCK_OPEN stmts BLOCK_CLOSE 
                                        {
                                            $$.node_id = nextLabel++;
                                            int identifier_1 = nextLabel++;
                                            int identifier_2 = nextLabel++;
                                            int open_paren = nextLabel++;
                                            int close_paren = nextLabel++;
                                            int block_open = nextLabel++;
                                            int block_close = nextLabel++;

                                            fprintf(dot, "n%d [label=\"func\"]\n", $$.node_id);
                                            fprintf(dot, "n%d [label=\"%s\"]\n", identifier_1, $1.data.string);
                                            fprintf(dot, "n%d [label=\"%s\"]\n", identifier_2, $2.data.string);
                                            fprintf(dot, "n%d [label=\"(\"]\n", open_paren);
                                            fprintf(dot, "n%d [label=\")\"]\n", close_paren);
                                            fprintf(dot, "n%d [label=\"&#9875;\"]\n", block_open);
                                            fprintf(dot, "n%d [label=\"&#9875;;\"]\n", block_close);

                                            fprintf(dot, "{ rank=same; n%d n%d n%d n%d n%d n%d n%d n%d ; }\n", identifier_1, identifier_2, open_paren, $4.node_id, close_paren, block_open, $7.node_id, block_close);

                                            fprintf(dot, "n%d -- n%d\n", $$.node_id, identifier_1);
                                            fprintf(dot, "n%d -- n%d\n", $$.node_id, identifier_2);
                                            fprintf(dot, "n%d -- n%d\n", $$.node_id, open_paren);
                                            fprintf(dot, "n%d -- n%d\n", $$.node_id, $4.node_id);
                                            fprintf(dot, "n%d -- n%d\n", $$.node_id, close_paren);
                                            fprintf(dot, "n%d -- n%d\n", $$.node_id, block_open);
                                            fprintf(dot, "n%d -- n%d\n", $$.node_id, $7.node_id);
                                            fprintf(dot, "n%d -- n%d\n", $$.node_id, block_close);

                                        }
    ;

typelist: typelist COMMA var {
                                $$.node_id = nextLabel++; 
                                int comma = nextLabel++;
                                fprintf(dot, "n%d [label=\"typelist\"]\n", $$.node_id);
                                fprintf(dot, "n%d [label=\",\"]\n", comma); 

                                fprintf(dot, "{ rank=same; n%d n%d n%d;}\n", $1.node_id, comma, $3.node_id);

                                fprintf(dot, "n%d -- n%d\n", $$.node_id, $1.node_id);
                                fprintf(dot, "n%d -- n%d\n", $$.node_id, comma);
                                fprintf(dot, "n%d -- n%d\n", $$.node_id, $3.node_id);
                             }
    | var {
            $$.node_id = nextLabel++; 
            fprintf(dot, "n%d [label=\"typelist\"]\n", $$.node_id); 
            fprintf(dot, "n%d -- n%d\n", $$.node_id, $1.node_id); 
          }
    ;

exprlist: exprlist COMMA expr   { 
                                    functAddParam(&$1.data.paramList, $3.data.exprData.reg, $3.data.exprData.returnType);
                                    
                                    $$.node_id = nextLabel++;
                                    int comma = nextLabel++;

                                    fprintf(dot, "n%d [label=\",\"]\n", comma);
                                    fprintf(dot, "n%d [label=\"exprlist\"]\n", $$.node_id);

                                    fprintf(dot, "{ rank=same; n%d n%d n%d; }\n", $1.node_id, comma, $3.node_id);

                                    fprintf(dot, "n%d -- n%d\n", $$.node_id, $1.node_id);
                                    fprintf(dot, "n%d -- n%d\n", $$.node_id, comma);
                                    fprintf(dot, "n%d -- n%d\n", $$.node_id, $3.node_id);
                                }
    | expr  { 
                $$.data.paramList = NULL; 
                functAddParam(&$$.data.paramList, $1.data.exprData.reg, $1.data.exprData.returnType); 

                $$.node_id = nextLabel++;
                fprintf(dot, "n%d [label=\"exprlist\"]\n", $$.node_id);
                fprintf(dot, "n%d -- n%d\n", $$.node_id, $1.node_id);
                
            }
    ;

opttypelist: typelist   { 
                            $$.node_id = nextLabel++;
                            fprintf(dot, "n%d [label=\"opttypelist\"]\n", $$.node_id);
                            fprintf(dot, "n%d -- n%d\n", $$.node_id, $1.node_id); 
                        }
    |                   {
                            $$.node_id = nextLabel++; 
                            int eps = nextLabel++; 
                            fprintf(dot, "n%d [label=\"opttypelist\"]\n", $$.node_id);
                            fprintf(dot, "n%d [label=\"&#x03B5;\"]\n",eps); 
                            fprintf(dot, "n%d -- n%d\n", $$.node_id, eps);
                        }
    ;

optexprlist: exprlist   { 
                            $$.data.paramList = $1.data.paramList; 
                            
                            $$.node_id = nextLabel++;
                            fprintf(dot, "n%d [label=\"optexprlist\"]\n", $$.node_id);
                            fprintf(dot, "n%d -- n%d\n", $$.node_id, $1.node_id);
                            
                        }
    |                   { 
                            $$.data.paramList = NULL; 
                            
                            $$.node_id = nextLabel++; 
                            int eps = nextLabel++; 
                            fprintf(dot, "n%d [label=\"optexprlist\"]\n", $$.node_id);
                            fprintf(dot, "n%d [label=\"&#x03B5;\"]\n",eps); 
                            fprintf(dot, "n%d -- n%d\n", $$.node_id, eps); 
                        }
    ;

commands: 
    RETURN optexpr SEMI_COLON {
                                int return_ = nextLabel++;
                                $$.node_id = nextLabel++;
                                int semicolon = nextLabel++;
                                
                                fprintf(dot, "n%d [label=\"commands\"]\n", $$.node_id);
                                fprintf(dot, "n%d [label=\"RETURN\"]\n", return_);
                                fprintf(dot, "n%d [label=\";\"]\n", semicolon);

                                fprintf(dot, "{ rank=same; n%d n%d n%d; }\n", return_, $2.node_id, semicolon);

                                fprintf(dot, "n%d -- n%d\n", $$.node_id, return_);
                                fprintf(dot, "n%d -- n%d\n", $$.node_id, $2.node_id);
                                fprintf(dot, "n%d -- n%d\n", $$.node_id, semicolon);
                                }
    | BREAK SEMI_COLON {
                                int break_ = nextLabel++;
                                int semicolon = nextLabel++;
                                $$.node_id = nextLabel++;

                                fprintf(dot, "n%d [label=\"commands\"]\n", $$.node_id);
                                fprintf(dot, "n%d [label=\"BREAK\"]\n", break_);
                                fprintf(dot, "n%d [label=\";\"]\n", semicolon);

                                fprintf(dot, "{ rank=same; n%d n%d n%d; }\n", break_, semicolon, $$.node_id);
                                
                                fprintf(dot, "n%d -- {n%d n%d}\n", $$.node_id, break_, semicolon);
                                
                        }
    | CONTINUE SEMI_COLON {
                                int continue_ = nextLabel++;
                                int semicolon = nextLabel++;
                                $$.node_id = nextLabel++;

                                fprintf(dot, "n%d [label=\"commands\"]\n", $$.node_id);
                                fprintf(dot, "n%d [label=\"CONTINUE\"]\n", continue_);
                                fprintf(dot, "n%d [label=\";\"]\n", semicolon);

                                fprintf(dot, "{ rank=same; n%d n%d n%d; }\n", continue_, semicolon, $$.node_id);
                                
                                fprintf(dot, "n%d -- {n%d n%d}\n", $$.node_id, continue_, semicolon);
                          }
    | TYPEDEF IDENTIFIER IDENTIFIER SEMI_COLON {
                                                    int typedef_ = nextLabel++;
                                                    int identifier_1 = nextLabel++;
                                                    int identifier_2 = nextLabel++;
                                                    int semicolon = nextLabel++;
                                                    $$.node_id = nextLabel++;

                                                    fprintf(dot, "n%d [label=\"commands\"]\n", $$.node_id);
                                                    fprintf(dot, "n%d [label=\"TYPEDEF\"]\n", typedef_);
                                                    fprintf(dot, "n%d [label=\"%s\"]\n", identifier_1, $2.data.string);
                                                    fprintf(dot, "n%d [label=\"%s\"]\n", identifier_2, $3.data.string);
                                                    fprintf(dot, "n%d [label=\";\"]\n", semicolon);

                                                    fprintf(dot, "n%d -- {n%d n%d n%d n%d}\n", $$.node_id, typedef_, identifier_1, identifier_2, semicolon);
                                               }
    | INCLUDE STRING SEMI_COLON {
                                    int include_ = nextLabel++;
                                    int string_ = nextLabel++;
                                    int semicolon = nextLabel++;
                                    $$.node_id = nextLabel++;

                                    fprintf(dot, "n%d [label=\"INCLUDE\"]\n", include_);
                                    fprintf(dot, "n%d [label=\"%s\"]\n", string_,$2.data.string);
                                    fprintf(dot, "n%d [label=\";\"]\n", semicolon);
                                    fprintf(dot, "n%d [label=\"commands\"]\n", $$.node_id);
                                    fprintf(dot, "n%d -- {n%d n%d n%d}\n", $$.node_id, include_, string_, semicolon);
                                }
    | STRUCT IDENTIFIER BLOCK_OPEN varlist BLOCK_CLOSE { 
                                                        $$.node_id = nextLabel++;
                                                        int struct_ = nextLabel++;
                                                        int identifier = nextLabel++;
                                                        int block_open = nextLabel++;
                                                        int block_close = nextLabel++;

                                                        fprintf(dot, "n%d [label=\"STRUCT\"]\n", struct_);
                                                        fprintf(dot, "n%d [label=\"%s\"]\n", identifier, $2.data.string);
                                                        fprintf(dot, "n%d [label=\"&#9875;\"]\n", block_open);
                                                        fprintf(dot, "n%d [label=\"commands\"]\n", $$.node_id);
                                                        fprintf(dot, "n%d [label=\"&#9875;;\"]\n", block_close);
                                                        
                                                        fprintf(dot, "{rank=same; n%d n%d n%d n%d n%d;}\n", struct_, identifier, block_open, $4.node_id, block_close);
                                                        
                                                        fprintf(dot, "n%d -- n%d\n", $$.node_id, struct_);
                                                        fprintf(dot, "n%d -- n%d\n", $$.node_id, identifier);
                                                        fprintf(dot, "n%d -- n%d\n", $$.node_id, block_open);
                                                        fprintf(dot, "n%d -- n%d\n", $$.node_id, $4.node_id);
                                                        fprintf(dot, "n%d -- n%d\n", $$.node_id, block_close);
                                                       }
    | ENUM IDENTIFIER BLOCK_OPEN idlist BLOCK_CLOSE { 
                                                        int enum_ = nextLabel++;
                                                        int identifier = nextLabel++;
                                                        int block_open = nextLabel++;
                                                        $$.node_id = nextLabel++;
                                                        int block_close = nextLabel++;

                                                        fprintf(dot, "n%d [label=\"commands\"]\n", $$.node_id);
                                                        fprintf(dot, "n%d [label=\"ENUM\"]\n", enum_);
                                                        fprintf(dot, "n%d [label=\"ID\"]\n", identifier);
                                                        fprintf(dot, "n%d [label=\"&#9875;\"]\n", block_open);
                                                        fprintf(dot, "n%d [label=\"&#9875;;\"]\n", block_close);

                                                        fprintf(dot, "{ rank=same; n%d n%d n%d n%d n%d; }\n", enum_, identifier, block_open, $4.node_id, block_close);
                                                            
                                                        fprintf(dot, "n%d -- n%d\n", $$.node_id, enum_);
                                                        fprintf(dot, "n%d -- n%d\n", $$.node_id, identifier);
                                                        fprintf(dot, "n%d -- n%d\n", $$.node_id, block_open);
                                                        fprintf(dot, "n%d -- n%d\n", $$.node_id, $4.node_id);
                                                        fprintf(dot, "n%d -- n%d\n", $$.node_id, block_close);
                                                    }
    ;

varlist: varlist var SEMI_COLON     { 
                                        $$.node_id = nextLabel++;
                                        int semicolon = nextLabel++;
                                        fprintf(dot, "n%d [label=\"varlist\"]\n", $$.node_id);
                                        fprintf(dot, "n%d [label=\";\"]\n", semicolon);
                                        fprintf(dot, "n%d -- {n%d n%d n%d}\n", $$.node_id, $1.node_id, $2.node_id, semicolon);
                                    }
    |                               {
                                        $$.node_id = nextLabel++; 
                                        int eps = nextLabel++; 
                                        fprintf(dot, "n%d [label=\"varlist\"]\n", $$.node_id);
                                        fprintf(dot, "n%d [label=\"&#x03B5;\"]\n",eps); 
                                        fprintf(dot, "n%d -- n%d\n", $$.node_id, eps); 
                                    }
    ;

idlist: idlist COMMA IDENTIFIER     { 
                                        $$.node_id = nextLabel++;
                                        int identifier = nextLabel++;
                                        int comma = nextLabel++;
                                        fprintf(dot, "n%d [label=\"idlist\"]\n", $$.node_id);
                                        fprintf(dot, "n%d [label=\"%s\"]\n", identifier, $3.data.string);
                                        fprintf(dot, "n%d [label=\",\"]\n", comma);

                                        fprintf(dot, "n%d -- {n%d n%d n%d}\n", $$.node_id, identifier, comma, $3.node_id);
                                    }
    | IDENTIFIER                    { 
                                        int identifier = nextLabel++;
                                        $$.node_id = nextLabel++;
                                        fprintf(dot, "n%d [label=\"idlist\"]\n", $$.node_id);
                                        fprintf(dot, "n%d [label=\"%s\"]\n", identifier, $1.data.string);
                                        fprintf(dot, "n%d -- n%d\n", $$.node_id, identifier);
                                    }
    ;

optexpr: expr                       { 
                                        $$.node_id = nextLabel++;
                                        fprintf(dot, "n%d [label=\"optexpr\"]\n", $$.node_id);
                                        fprintf(dot, "n%d -- n%d\n", $$.node_id, $1.node_id);
                                    }
    |                               { 
                                        $$.node_id = nextLabel++; 
                                        int eps = nextLabel++; 
                                        fprintf(dot, "n%d [label=\"optexpr\"]\n", $$.node_id);
                                        fprintf(dot, "n%d [label=\"&#x03B5;\"]\n",eps); 
                                        fprintf(dot, "n%d -- n%d\n", $$.node_id, eps);
                                    }
    ;                           

expr: expr ADD expr { 
                        $$.data.exprData = handleBinaryExpr(ADD, $1.data.exprData, $3.data.exprData);

                        $$.node_id = nextLabel++;
                        int add = nextLabel++;

                        fprintf(dot, "n%d [label=\"expr\"]\n", $$.node_id);
                        fprintf(dot, "n%d [label=\"+\"]\n", add);
                        
                        fprintf(dot, "{rank=same; n%d n%d n%d;}\n", $1.node_id, add, $3.node_id);

                        fprintf(dot, "n%d -- n%d\n", $$.node_id, $1.node_id);
                        fprintf(dot, "n%d -- n%d\n", $$.node_id, add);
                        fprintf(dot, "n%d -- n%d\n", $$.node_id, $3.node_id);
                    }
    | expr SUB expr { 
                        $$.data.exprData = handleBinaryExpr(SUB, $1.data.exprData, $3.data.exprData); 

                        $$.node_id = nextLabel++;
                        int sub = nextLabel++;

                        fprintf(dot, "n%d [label=\"expr\"]\n", $$.node_id);
                        fprintf(dot, "n%d [label=\"-\"]\n", sub);

                        fprintf(dot, "{rank=same; n%d n%d n%d;}\n", $1.node_id, sub, $3.node_id);
                        
                        fprintf(dot, "n%d -- n%d\n", $$.node_id, $1.node_id);
                        fprintf(dot, "n%d -- n%d\n", $$.node_id, sub);
                        fprintf(dot, "n%d -- n%d\n", $$.node_id, $3.node_id);

                    }
    | expr MUL expr { 
                        $$.data.exprData = handleBinaryExpr(MUL, $1.data.exprData, $3.data.exprData); 

                        $$.node_id = nextLabel++;
                        int mul = nextLabel++;

                        fprintf(dot, "n%d [label=\"expr\"]\n", $$.node_id);
                        fprintf(dot, "n%d [label=\"*\"]\n", mul);

                        fprintf(dot, "{rank=same; n%d n%d n%d;}\n", $1.node_id, mul, $3.node_id);

                        fprintf(dot, "n%d -- n%d\n", $$.node_id, $1.node_id);
                        fprintf(dot, "n%d -- n%d\n", $$.node_id, mul);
                        fprintf(dot, "n%d -- n%d\n", $$.node_id, $3.node_id);

                    }
    | expr DIV expr { 
                        $$.data.exprData = handleBinaryExpr(DIV, $1.data.exprData, $3.data.exprData);
                        
                        $$.node_id = nextLabel++;
                        int div = nextLabel++;

                        fprintf(dot, "n%d [label=\"expr\"]\n", $$.node_id);
                        fprintf(dot, "n%d [label=\"/\"]\n", div);

                        fprintf(dot, "{rank=same; n%d n%d n%d;}\n", $1.node_id, div, $3.node_id);

                        fprintf(dot, "n%d -- n%d\n", $$.node_id, $1.node_id);
                        fprintf(dot, "n%d -- n%d\n", $$.node_id, div);
                        fprintf(dot, "n%d -- n%d\n", $$.node_id, $3.node_id);
                        
                    }
    | expr MOD expr { /* geraTemp1, geraTemp2, chama codeGen(t1, op, t2) */ 
                        $$.node_id = nextLabel++;
                        int mod = nextLabel++;

                        fprintf(dot, "n%d [label=\"expr\"]\n", $$.node_id);
                        fprintf(dot, "n%d [label=\"%%\"]\n", mod);

                        fprintf(dot, "{rank=same; n%d n%d n%d;}\n", $1.node_id, mod, $3.node_id);
                        
                        fprintf(dot, "n%d -- n%d\n", $$.node_id, $1.node_id);
                        fprintf(dot, "n%d -- n%d\n", $$.node_id, mod);
                        fprintf(dot, "n%d -- n%d\n", $$.node_id, $3.node_id);
                    }
    | expr BITWISE_AND expr     { 
                                    $$.data.exprData = handleBinaryExpr(BITWISE_AND, $1.data.exprData, $3.data.exprData); 

                                    $$.node_id = nextLabel++;
                                    int and_ = nextLabel++;

                                    fprintf(dot, "n%d [label=\"expr\"]\n", $$.node_id);
                                    fprintf(dot, "n%d [label=\"&\"]\n", and_);

                                    fprintf(dot, "{rank=same; n%d n%d n%d;}\n", $1.node_id, and_, $3.node_id);
                        
                                    fprintf(dot, "n%d -- n%d\n", $$.node_id, $1.node_id);
                                    fprintf(dot, "n%d -- n%d\n", $$.node_id, and_);
                                    fprintf(dot, "n%d -- n%d\n", $$.node_id, $3.node_id);

                                }
    | expr BITWISE_OR expr      { 
                                    $$.data.exprData = handleBinaryExpr(BITWISE_OR, $1.data.exprData, $3.data.exprData); 

                                    $$.node_id = nextLabel++;
                                    int or_ = nextLabel++;

                                    fprintf(dot, "n%d [label=\"expr\"]\n", $$.node_id);
                                    fprintf(dot, "n%d [label=\"|\"]\n", or_);

                                    fprintf(dot, "{rank=same; n%d n%d n%d;}\n", $1.node_id, or_, $3.node_id);

                                    fprintf(dot, "n%d -- n%d\n", $$.node_id, $1.node_id);
                                    fprintf(dot, "n%d -- n%d\n", $$.node_id, or_);
                                    fprintf(dot, "n%d -- n%d\n", $$.node_id, $3.node_id);

                                }
    | expr BITWISE_NOT expr     { 
                                    $$.data.exprData = handleBinaryExpr(BITWISE_NOT, $1.data.exprData, $3.data.exprData); 

                                    $$.node_id = nextLabel++;
                                    int not_ = nextLabel++;

                                    fprintf(dot, "n%d [label=\"expr\"]\n", $$.node_id);
                                    fprintf(dot, "n%d [label=\"~\"]\n", not_);

                                    fprintf(dot, "{rank=same; n%d n%d n%d;}\n", $1.node_id, not_, $3.node_id);

                                    fprintf(dot, "n%d -- n%d\n", $$.node_id, $1.node_id);
                                    fprintf(dot, "n%d -- n%d\n", $$.node_id, not_);
                                    fprintf(dot, "n%d -- n%d\n", $$.node_id, $3.node_id);
                                    
                                }
    | expr BITWISE_XOR expr     { 
                                    $$.data.exprData = handleBinaryExpr(BITWISE_XOR, $1.data.exprData, $3.data.exprData); 
                                    
                                    $$.node_id = nextLabel++;
                                    int xor_ = nextLabel++;

                                    fprintf(dot, "n%d [label=\"expr\"]\n", $$.node_id);
                                    fprintf(dot, "n%d [label=\"^\"]\n", xor_);

                                    fprintf(dot, "{rank=same; n%d n%d n%d;}\n", $1.node_id, xor_, $3.node_id);
                        
                                    fprintf(dot, "n%d -- n%d\n", $$.node_id, $1.node_id);
                                    fprintf(dot, "n%d -- n%d\n", $$.node_id, xor_);
                                    fprintf(dot, "n%d -- n%d\n", $$.node_id, $3.node_id);
                                }
    | expr LEFT_SHIFT expr      { 
                                    $$.data.exprData = handleBinaryExpr(LEFT_SHIFT, $1.data.exprData, $3.data.exprData); 

                                    $$.node_id = nextLabel++;
                                    int lshift = nextLabel++;

                                    fprintf(dot, "n%d [label=\"expr\"]\n", $$.node_id);
                                    fprintf(dot, "n%d [label=\"<<\"]\n", lshift);
                                    
                                    fprintf(dot, "{rank=same; n%d n%d n%d;}\n", $1.node_id, lshift, $3.node_id);

                                    fprintf(dot, "n%d -- n%d\n", $$.node_id, $1.node_id);
                                    fprintf(dot, "n%d -- n%d\n", $$.node_id, lshift);
                                    fprintf(dot, "n%d -- n%d\n", $$.node_id, $3.node_id);

                                }
    | expr RIGHT_SHIFT expr     { 
                                    $$.data.exprData = handleBinaryExpr(RIGHT_SHIFT, $1.data.exprData, $3.data.exprData); 

                                    $$.node_id = nextLabel++;
                                    int rshift = nextLabel++;

                                    fprintf(dot, "n%d [label=\"expr\"]\n", $$.node_id);
                                    fprintf(dot, "n%d [label=\">>\"]\n", rshift);

                                    fprintf(dot, "{rank=same; n%d n%d n%d;}\n", $1.node_id, rshift, $3.node_id);

                                    fprintf(dot, "n%d -- n%d\n", $$.node_id, $1.node_id);
                                    fprintf(dot, "n%d -- n%d\n", $$.node_id, rshift);
                                    fprintf(dot, "n%d -- n%d\n", $$.node_id, $3.node_id);

                                }
    | expr EQ expr  { 
                        $$.data.exprData = handleBinaryExpr(EQ, $1.data.exprData, $3.data.exprData); 

                        $$.node_id = nextLabel++;
                        int eq = nextLabel++;

                        fprintf(dot, "n%d [label=\"expr\"]\n", $$.node_id);
                        fprintf(dot, "n%d [label=\"==\"]\n", eq);

                        fprintf(dot, "{rank=same; n%d n%d n%d;}\n", $1.node_id, eq, $3.node_id);

                        fprintf(dot, "n%d -- n%d\n", $$.node_id, $1.node_id);
                        fprintf(dot, "n%d -- n%d\n", $$.node_id, eq);
                        fprintf(dot, "n%d -- n%d\n", $$.node_id, $3.node_id);

                    }
    | expr NE expr  { 
                        $$.data.exprData = handleBinaryExpr(NE, $1.data.exprData, $3.data.exprData); 

                        $$.node_id = nextLabel++;
                        int ne = nextLabel++;

                        fprintf(dot, "n%d [label=\"expr\"]\n", $$.node_id);
                        fprintf(dot, "n%d [label=\"!=\"]\n", ne);

                        fprintf(dot, "{rank=same; n%d n%d n%d;}\n", $1.node_id, ne, $3.node_id);
                        
                        fprintf(dot, "n%d -- n%d\n", $$.node_id, $1.node_id);
                        fprintf(dot, "n%d -- n%d\n", $$.node_id, ne);
                        fprintf(dot, "n%d -- n%d\n", $$.node_id, $3.node_id);
                        
                    }
    | expr LT expr  { 
                        $$.data.exprData = handleBinaryExpr(LT, $1.data.exprData, $3.data.exprData); 

                        $$.node_id = nextLabel++;
                        int lt = nextLabel++;

                        fprintf(dot, "n%d [label=\"expr\"]\n", $$.node_id);
                        fprintf(dot, "n%d [label=\"<\"]\n", lt);

                        fprintf(dot, "{rank=same; n%d n%d n%d;}\n", $1.node_id, lt, $3.node_id);

                        fprintf(dot, "n%d -- n%d\n", $$.node_id, $1.node_id);
                        fprintf(dot, "n%d -- n%d\n", $$.node_id, lt);
                        fprintf(dot, "n%d -- n%d\n", $$.node_id, $3.node_id);
        

                    }
    | expr GT expr  { 
                        $$.data.exprData = handleBinaryExpr(GT, $1.data.exprData, $3.data.exprData); 

                        $$.node_id = nextLabel++;
                        int gt = nextLabel++;
                        
                        fprintf(dot, "n%d [label=\"expr\"]\n", $$.node_id);
                        fprintf(dot, "n%d [label=\">\"]\n", gt);

                        fprintf(dot, "{rank=same; n%d n%d n%d;}\n", $1.node_id, gt, $3.node_id);

                        fprintf(dot, "n%d -- n%d\n", $$.node_id, $1.node_id);
                        fprintf(dot, "n%d -- n%d\n", $$.node_id, gt);
                        fprintf(dot, "n%d -- n%d\n", $$.node_id, $3.node_id);

                    }
    | expr LE expr  { 
                        $$.data.exprData = handleBinaryExpr(LE, $1.data.exprData, $3.data.exprData); 
                        
                        $$.node_id = nextLabel++;
                        int le = nextLabel++;
                        
                        fprintf(dot, "n%d [label=\"expr\"]\n", $$.node_id);
                        fprintf(dot, "n%d [label=\"<=\"]\n", le);

                        fprintf(dot, "{rank=same; n%d n%d n%d;}\n", $1.node_id, le, $3.node_id);

                        fprintf(dot, "n%d -- n%d\n", $$.node_id, $1.node_id);
                        fprintf(dot, "n%d -- n%d\n", $$.node_id, le);
                        fprintf(dot, "n%d -- n%d\n", $$.node_id, $3.node_id);
                        
                    }
    | expr GE expr  { 
                        $$.data.exprData = handleBinaryExpr(GE, $1.data.exprData, $3.data.exprData); 
                        
                        $$.node_id = nextLabel++;
                        int ge = nextLabel++;
                        
                        fprintf(dot, "n%d [label=\"expr\"]\n", $$.node_id);
                        fprintf(dot, "n%d [label=\">=\"]\n", ge);

                        fprintf(dot, "{rank=same; n%d n%d n%d;}\n", $1.node_id, ge, $3.node_id);
                        
                        fprintf(dot, "n%d -- n%d\n", $$.node_id, $1.node_id);
                        fprintf(dot, "n%d -- n%d\n", $$.node_id, ge);
                        fprintf(dot, "n%d -- n%d\n", $$.node_id, $3.node_id);

                    }
    | expr LOGICAL_AND expr         { 
                                        $$.data.exprData = handleBinaryExpr(LOGICAL_AND, $1.data.exprData, $3.data.exprData); 

                                        $$.node_id = nextLabel++;
                                        int and_ = nextLabel++;
                                        
                                        fprintf(dot, "n%d [label=\"expr\"]\n", $$.node_id);
                                        fprintf(dot, "n%d [label=\"&&\"]\n", and_);

                                        fprintf(dot, "{rank=same; n%d n%d n%d;}\n", $1.node_id, and_, $3.node_id);
                        
                                        fprintf(dot, "n%d -- n%d\n", $$.node_id, $1.node_id);
                                        fprintf(dot, "n%d -- n%d\n", $$.node_id, and_);
                                        fprintf(dot, "n%d -- n%d\n", $$.node_id, $3.node_id);
                                    }
    | expr LOGICAL_OR expr          { 
                                        $$.data.exprData = handleBinaryExpr(LOGICAL_OR, $1.data.exprData, $3.data.exprData); 

                                        $$.node_id = nextLabel++;
                                        int or_ = nextLabel++;

                                        fprintf(dot, "n%d [label=\"expr\"]\n", $$.node_id);
                                        fprintf(dot, "n%d [label=\"||\"]\n", or_);

                                        fprintf(dot, "{rank=same; n%d n%d n%d;}\n", $1.node_id, or_, $3.node_id);

                                        fprintf(dot, "n%d -- n%d\n", $$.node_id, $1.node_id);
                                        fprintf(dot, "n%d -- n%d\n", $$.node_id, or_);
                                        fprintf(dot, "n%d -- n%d\n", $$.node_id, $3.node_id);
                                        
                                    }
    | OPEN_PAREN expr CLOSE_PAREN   { 
                                        $$.data.exprData = $2.data.exprData; 

                                        $$.node_id = nextLabel++;
                                        int paren = nextLabel++;
                                        int close_paren = nextLabel++;

                                        fprintf(dot, "n%d [label=\"expr\"]\n", $$.node_id);
                                        fprintf(dot, "n%d [label=\"(\"]\n", paren);
                                        fprintf(dot, "n%d [label=\")\"]\n", close_paren);

                                        fprintf(dot, "{rank=same; n%d n%d n%d;}\n", paren, $2.node_id, close_paren);

                                        fprintf(dot, "n%d -- n%d\n", $$.node_id, paren);
                                        fprintf(dot, "n%d -- n%d\n", $$.node_id, $2.node_id);
                                        fprintf(dot, "n%d -- n%d\n", $$.node_id, close_paren);
                                    }
                                    
    | LOGICAL_NOT expr %prec UNARY  { 
                                        $$.data.exprData = handleUnaryExpr(LOGICAL_NOT, $2.data.exprData); 

                                        int not = nextLabel++;
                                        $$.node_id = nextLabel++;
                                        fprintf(dot, "n%d [label=\"!\"]\n", not);
                                        fprintf(dot, "n%d [label=\"expr\"]\n", $$.node_id);
    

                                        fprintf(dot, "{rank=same; n%d n%d;}\n", not, $2.node_id);
                        
                                        fprintf(dot, "n%d -- n%d\n", $$.node_id, not);
                                        fprintf(dot, "n%d -- n%d\n", $$.node_id, $2.node_id);
                                        
                                    }
    | SUB expr %prec UNARY          { 
                                        $$.data.exprData = handleUnaryExpr(SUB, $2.data.exprData); 
                                        
                                        $$.node_id = nextLabel++;
                                        int sub = nextLabel++;
                                        
                                        fprintf(dot, "n%d [label=\"-\"]\n", sub);
                                        fprintf(dot, "n%d [label=\"expr\"]\n", $$.node_id);

                                        fprintf(dot, "{rank=same; n%d n%d;}\n", sub, $2.node_id);
                        
                                        fprintf(dot, "n%d -- n%d\n", $$.node_id, sub);
                                        fprintf(dot, "n%d -- n%d\n", $$.node_id, $2.node_id);
                                        
                                    }
    | term                          { 
                                        $$.data.exprData = $1.data.exprData; 

                                        $$.node_id = nextLabel++;
                                        
                                        fprintf(dot, "n%d [label=\"expr\"]\n", $$.node_id);
                                        fprintf(dot, "n%d -- n%d\n", $$.node_id, $1.node_id);
                                        
                                    }
    | attr ASSIGN expr              { 
                                        $$.data.exprData = handleAssignExpr($1.data.string, $3.data.exprData); 

                                        $$.node_id = nextLabel++;
                                        int assign_ = nextLabel++;

                                        fprintf(dot, "n%d [label=\"=\"]\n", assign_);
                                        fprintf(dot, "n%d [label=\"attr\"]\n", $$.node_id);

                                        fprintf(dot, "{rank=same; n%d n%d n%d;}\n", $1.node_id, assign_, $3.node_id);

                                        fprintf(dot, "n%d -- n%d\n", $$.node_id, $1.node_id);
                                        fprintf(dot, "n%d -- n%d\n", $$.node_id, assign_);
                                        fprintf(dot, "n%d -- n%d\n", $$.node_id, $3.node_id);
                                    }
    | SIZEOF IDENTIFIER             { /* return symbol table size of identifier */ }
    ;


term: const { 
                $$.data.exprData = $1.data.exprData; 

                $$.node_id = nextLabel++;
                
                fprintf(dot, "n%d [label=\"term\"]\n", $$.node_id);
                fprintf(dot, "n%d -- n%d\n", $$.node_id, $1.node_id);
                
            }
    | IDENTIFIER OPEN_PAREN optexprlist CLOSE_PAREN { 
                    $$.data.exprData = handleFunctionCall($1.data.string, $3.data.paramList); 

                    $$.node_id = nextLabel++;
                    int identifier = nextLabel++;
                    int open_paren = nextLabel++;
                    int close_paren = nextLabel++;

                    fprintf(dot, "n%d [label=\"%s\"]\n", identifier, $1.data.string);
                    fprintf(dot, "n%d [label=\"(\"]\n", open_paren);
                    fprintf(dot, "n%d [label=\"term\"]\n", $$.node_id);
                    fprintf(dot, "n%d [label=\")\"]\n", close_paren);

                    fprintf(dot, "{rank=same; n%d n%d n%d n%d;}\n", identifier, open_paren, $3.node_id, close_paren);

                    fprintf(dot, "n%d -- n%d\n", $$.node_id, identifier);
                    fprintf(dot, "n%d -- n%d\n", $$.node_id, open_paren);
                    fprintf(dot, "n%d -- n%d\n", $$.node_id, $3.node_id);
                    fprintf(dot, "n%d -- n%d\n", $$.node_id, close_paren);
                }
    | attr  { 
                $$.data.exprData = handleAttr($1.data.string); 
                
                $$.node_id = nextLabel++;

                fprintf(dot, "n%d [label=\"term\"]\n", $$.node_id);
                fprintf(dot, "n%d -- n%d\n", $$.node_id, $1.node_id);

            }
    ;

attr: IDENTIFIER exprvector     { 
                                    $$.data.string = $1.data.string; 

                                    $$.node_id = nextLabel++;
                                    int id = nextLabel++;

                                    fprintf(dot, "n%d [label=\"attr\"]\n", $$.node_id);
                                    fprintf(dot, "n%d [label=\"%s\"]\n", id, $1.data.string);

                                    fprintf(dot, "{rank=same; n%d n%d;}\n", id, $2.node_id);

                                    fprintf(dot, "n%d -- n%d\n", $$.node_id, id);
                                    fprintf(dot, "n%d -- n%d\n", $$.node_id, $2.node_id);
                                }
    | attr POINTER attr         { 
                                    $$.data.string = mergeStrPointers($1.data.string, $3.data.string); 

                                    $$.node_id = nextLabel++;
                                    int pointer = nextLabel++;

                                    fprintf(dot, "n%d [label=\"attr\"]\n", $$.node_id);
                                    fprintf(dot, "n%d [label=\"->\"]\n", pointer);

                                    fprintf(dot, "{rank=same; n%d n%d n%d;}\n", $1.node_id, pointer, $3.node_id);

                                    fprintf(dot, "n%d -- n%d\n", $$.node_id, $1.node_id);
                                    fprintf(dot, "n%d -- n%d\n", $$.node_id, pointer);
                                    fprintf(dot, "n%d -- n%d\n", $$.node_id, $3.node_id);
                                }
    ;

const: INTEGER          { 
                            $$.data.exprData = handleInteger($1.data.integer); 

                            int integer = nextLabel++;
                            $$.node_id = nextLabel++;

                            fprintf(dot, "n%d [label=\"%d\"]\n", integer, $1.data.integer);
                            fprintf(dot, "n%d [label=\"const\"]\n", $$.node_id);
                            fprintf(dot, "n%d -- n%d\n", $$.node_id, integer);
                        }
    | DECIMAL           { 
                            $$.data.exprData.returnType = strdup("ship"); 
                            $$.data.exprData.reg = 0;  

                            int decimal = nextLabel++;
                            $$.node_id = nextLabel++;

                            fprintf(dot, "n%d [label=\"%lf\"]\n", decimal, $1.data.decimal);
                            fprintf(dot, "n%d [label=\"const\"]\n", $$.node_id);
                            fprintf(dot, "n%d -- n%d\n", $$.node_id, decimal);   
                        }
    | STRING            { 
                            /* chama codeGen() e retorna o Temporary */
                            int string = nextLabel++;
                            $$.node_id = nextLabel++;

                            fprintf(dot, "n%d [label=\"%s\"]\n", string, $1.data.string);
                            fprintf(dot, "n%d [label=\"const\"]\n", $$.node_id);
                            fprintf(dot, "n%d -- n%d\n", $$.node_id, string);
                        }
    | boolean           {
                            /* chama codeGen() e retorna o Temporary */
                            $$.node_id = nextLabel++;
                            
                            fprintf(dot, "n%d [label=\"const\"]\n", $$.node_id);
                            fprintf(dot, "n%d -- n%d\n", $$.node_id, $1.node_id);
                            
                        }

boolean: TRUE                   { 
                                    $$.data.boolean = $1.data.boolean; 

                                    $$.node_id = nextLabel++;
                                    int true = nextLabel++;

                                    fprintf(dot, "n%d [label=\"true\"]\n", true);
                                    fprintf(dot, "n%d [label=\"boolean\"]\n", $$.node_id);
                                    fprintf(dot, "n%d -- n%d\n", $$.node_id, true);

                                }
    | FALSE                     { 
                                    $$.data.boolean = $1.data.boolean; 

                                    $$.node_id = nextLabel++;
                                    int false = nextLabel++;

                                    fprintf(dot, "n%d [label=\"false\"]\n", false);
                                    fprintf(dot, "n%d [label=\"boolean\"]\n", $$.node_id);
                                    fprintf(dot, "n%d -- n%d\n", $$.node_id, false);

                                }
    ;

exprvector:
    OPEN_BRACKET expr CLOSE_BRACKET { 
                                        $$.data.exprData = $2.data.exprData;

                                        int open_bracket = nextLabel++;
                                        $$.node_id = nextLabel++;
                                        int close_bracket = nextLabel++;

                                        fprintf(dot, "n%d [label=\"{\"]\n", open_bracket);
                                        fprintf(dot, "n%d [label=\"exprvector\"]\n", $$.node_id);
                                        fprintf(dot, "n%d [label=\"}\"]\n", close_bracket);

                                        fprintf(dot, "{ rank=same; n%d n%d n%d;}\n", open_bracket, $$.node_id, close_bracket);
                                        
                                        fprintf(dot, "n%d -- n%d\n", $$.node_id, open_bracket);
                                        fprintf(dot, "n%d -- n%d\n", $$.node_id, $2.node_id);
                                        fprintf(dot, "n%d -- n%d\n", $$.node_id, close_bracket);
                                    }
    | /* EPS */                     {  

                                        $$.node_id = nextLabel++; 
                                        int eps = nextLabel++; 
                                        fprintf(dot, "n%d [label=\"exprvector\"]\n", $$.node_id);
                                        fprintf(dot, "n%d [label=\"&#x03B5;\"]\n",eps); 
                                        fprintf(dot, "n%d -- n%d\n", $$.node_id, eps); 
                                    }
    ;

constvector: 
    OPEN_BRACKET INTEGER CLOSE_BRACKET  { 
                                            $$.data.integer = $2.data.integer; 

                                            int open_bracket = nextLabel++;
                                            int integer = nextLabel++;
                                            $$.node_id = nextLabel++; 
                                            int close_bracket = nextLabel++;
                                            
                                            fprintf(dot, "n%d [label=\"[\"]\n", open_bracket);
                                            fprintf(dot, "n%d [label=\"constvector\"]\n", $$.node_id);
                                            fprintf(dot, "n%d [label=\"]\"]\n", close_bracket);
                                            fprintf(dot, "n%d -- {n%d n%d n%d}\n", $$.node_id, open_bracket, integer, close_bracket);
                                            
                                        }
    | /* EPS */                     { 
                                        $$.data.integer = 1;
                                        
                                        $$.node_id = nextLabel++; 
                                        int eps = nextLabel++; 
                                        fprintf(dot, "n%d [label=\"constvector\"]\n", $$.node_id);
                                        fprintf(dot, "n%d [label=\"&#x03B5;\"]\n",eps); 
                                        fprintf(dot, "n%d -- n%d\n", $$.node_id, eps); 
                                    }
    ; 

%%

/**
 * Handle variable creation.
 *
 * @param _type     - Node Type
 * @param _id       - Variable Id
 * @param _sz       - How many copys of the type this variable stores
 *
 * @return Nothing
 */
void handleVarDeclaration(char *type, char *id, int size) {
    Symbol *sym_type = symbolTableFind(st, type);
    if(!sym_type || sym_type->symbolType != SymbolTypeType) {
        reportAndExit("\"%s\" nao e um tipo de dados.", type);
    }

    Symbol *sym_id = symbolTableFindInBlock(st, id);
    if(sym_id) {
        reportAndExit("Redeclaracao do identificador \"%s\"", id);
    }

    int allocSize = sym_type->data.type.bytes * size;

    symbolTableInsert(st, symbolVariableNew(id, type, nextAddress, allocSize));
    nextAddress += allocSize;

    /* printf("variable %s of type %s with %d bytes added.\n", id, type, allocSize); */
}

ExprData handleAttr(char *id) {
    Symbol *sym_id = symbolTableFind(st, id);
    if(!sym_id) {
        reportAndExit("\"%s\" nao eh uma variavel declarada.", id);
    }
    if(sym_id->symbolType != SymbolTypeVariable) {
        reportAndExit("\"%s\" nao eh um valor modificavel.", id);
    }
    
    ExprData ret;
    ret.returnType = sym_id->data.variable.type;
    ret.reg = riscVCodeGenVariable(riscv, id);
    ret.temp = pseudoCodeGenVariable(pseudo, id);
    return ret;
}

char *mergeStrPointers(char *a, char *b) {
    if(!a || !b) return NULL;
    int la = strlen(a);
    int lb = strlen(b);
    char *cat = (char*) malloc((la + lb + 2) * sizeof(char)); // size(a) + '.' + size(b) + '\0'
    cat[0] = '\0'; // make sure that this is a empty string
    strcat(cat, a);
    strcat(cat, ".");
    strcat(cat, b);
    return cat;
}

ExprData handleBinaryExpr(int opcode, ExprData e1, ExprData e2) {
    if(strcmp(e1.returnType, e2.returnType))
        reportAndExit("Impossivel fazer a operação entre tipos \"%s\" e \"%s\".", e1.returnType, e2.returnType);
    
    ExprData ret;
    ret.returnType = e1.returnType;

    ret.reg = riscVCodeGenBinaryOperator(riscv, opcode, e1.reg, e2.reg);
    ret.temp = pseudoCodeGenBinaryOperator(pseudo,opcode,e1.temp, e2.temp);

    return ret;
}

ExprData handleUnaryExpr(int opcode, ExprData e) {
    ExprData ret;
    ret.returnType = e.returnType;
    ret.reg = riscVCodeGenUnaryOperator(riscv, opcode, e.reg);
    ret.temp = pseudoCodeGenUnaryOperator(pseudo, opcode, e.temp);
    return ret;
}

ExprData handleAssignExpr(char *id, ExprData e) {
    Symbol *sym = symbolTableFind(st, id);

    if(!sym) reportAndExit("Identificador \"%s\" nao declarado.", id);

    if(strcmp(sym->data.variable.type, e.returnType)) reportAndExit("Impossivel atribuir um valor do tipo \"%s\" para uma variavel do tipo \"%s\".", e.returnType, sym->data.variable.type);

    ExprData ret;
    ret.returnType = e.returnType;
    ret.reg = riscVCodeGenAssign(riscv, id, e.reg);
    ret.temp = pseudoCodeGenAssign(pseudo,id,e.temp);
    return ret;
}

/* IF - ELSE */
void handleIfAfterExpr(ExprData e) {
    riscVCodeIfAfterExpr(riscv,e.reg);
    pseudoCodeIfAfterExpr(pseudo,e.temp);
}

void handleIfAfterStmt() {
    riscVCodeIfAfterStmt(riscv);
    pseudoCodeIfAfterStmt(pseudo);
}

void handleIfAfterElse() {
    riscVCodeIfAfterElse(riscv);
    pseudoCodeIfAfterElse(pseudo);
}

/* WHILE - FOR - DO WHILE */
void handleRepEntry() {
    riscVCodeRepEntry(riscv);
    pseudoCodeRepEntry(pseudo);
}

void handleRepAfterExpr(ExprData e) {
    riscVCodeRepAfterExpr(riscv, e.reg);
    pseudoCodeRepAfterExpr(pseudo, e.temp);
}

void handleRepExit() {
    riscVCodeRepExit(riscv);
    pseudoCodeRepExit(pseudo);
}

void handleRepUpdate() {
    riscVCodeRepUpdate(riscv);
    pseudoCodeRepUpdate(pseudo);
}

void handleRepStmt() {
    riscVCodeRepStmt(riscv);
    pseudoCodeRepStmt(pseudo);
}

void handleRepGotoEntry() {
    riscVCodeRepGotoEntry(riscv);
    pseudoCodeRepGotoEntry(pseudo);
}

void handleRepGotoUpdate() {
    riscVCodeRepGotoUpdate(riscv);
    pseudoCodeRepGotoUpdate(pseudo);
}

ExprData handleFunctionCall(char *id, FuncParamList *params) {
    ExprData ret;
    ret.reg = 0;
    ret.temp = 0;

    if(!strcmp(id, "parrot")) {
        if(functParamListSize(&params) != 1) {
            reportAndExit("parrot requer 1 parametro.");
        }

        FuncParam p = functGetParam(&params, 0);

        fprintf(friscv, "mv a1, x%d\n", p.reg);
        fprintf(friscv, "jal x1, printf\n");
        ret.returnType = strdup("void");
        return ret;
    }

    if(!strcmp(id, "plunder")) {
        if(functParamListSize(&params) != 0) {
            reportAndExit("plunder nao aceita parametros.");
        }

        fprintf(friscv, "jal x1, scanf\n");
        ret.reg = 11;
        ret.returnType = strdup("jib");
        return ret;
    }

    return ret;
}
ExprData handleInteger(int integer){
    ExprData ret;
    ret.returnType = strdup("jib"); 
    ret.reg = riscVCodeGenInteger(riscv, integer);
    ret.temp = pseudoCodeGenInteger(pseudo, integer);
    return ret;
}

void blockOpen() {
    symbolTableCreateBlock(st);
}

void blockClose() {
    symbolTableShow(st, stdout);
    symbolTableDeleteBlock(st);
}

void reportAndExit(const char *s, ...) {
    char msg[100];
    va_list args;
    va_start(args, s);
    vsnprintf(msg, sizeof(msg), s, args);
    va_end(args);
    yyerror(msg);
    onExit();
    exit(0);
}

void onExit() {
    riscVSaveRegisters(riscv);
    riscVCodeExitProgram(riscv);

    fprintf(dot,"}\n");

    fclose(gen);
    fclose(prod);
    fclose(friscv);
    fclose(dot);

    symbolTableDelete(st);
}

void onStart() {
    st = symbolTableNew();
    char sourceCode[1000000];
    size_t bytesRead = fread(sourceCode, sizeof(char), sizeof(sourceCode) - 1, stdin);
    sourceCode[bytesRead] = '\0';

    printSourceCodeWithLineNumbers(sourceCode);

    yyin = fmemopen(sourceCode, bytesRead, "r");
    
    prod = fopen("./build/producoes.output", "w");
    gen = fopen("./build/code.output", "w");


    friscv = fopen("./output/riscv.s", "w");
    riscv = riscV_ContextNew(friscv, st);

    fpseudo = fopen("./output/temp.txt","w");
    pseudo = pseudo_ContextNew(fpseudo,st);


    dot = fopen("./output/tree.dot", "w");
    fprintf(dot, "strict graph {\n");
    fprintf(dot, "node [ordering=out]\n");


    blockOpen();
    
    symbolTableInsert(st, symbolTypeNew("jib", 4));
    symbolTableInsert(st, symbolTypeNew("void", 4));
    symbolTableInsert(st, symbolTypeNew("boat", 4));
    symbolTableInsert(st, symbolTypeNew("ship", 4));
    symbolTableInsert(st, symbolTypeNew("addled", 4));
    symbolTableInsert(st, symbolTypeNew("sailor", 4));

    symbolTableInsert(st, symbolFunctionNew("parrot", "void"));
    /* symbolTableInsert(st, symbolFunctionNew("plunder", "void")); */
}

void yyerror(const char *s) {
    printf("Erro proximo a linha %d. %s\n", line, s);
}

int main(void) {
    onStart();
    yyparse();
    onExit();
    return 0;
}