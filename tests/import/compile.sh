#!/bin/bash

gcc preprocess.c -o preprocess

yacc -d -v example.y                                     # cria y.tab.h y.tab.c
lex example.l                                                       # cria lex.yy.c
gcc lex.yy.c y.tab.c ../../src/*.c -o main      # compile