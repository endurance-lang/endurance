#!/bin/sh
printf "running... \n"

printf "\n\nfirst test \n\n"
make run FILE="resources/undefined1.end"

printf "\n\nsecond test \n\n"
make run FILE="resources/riscv.end"

printf "\n\nthird test \n\n"
make run FILE="resources/scan.end"

printf "\n\nerror test \n\n"
make test-error

printf "\n\test graphviz \n\n"
make test-graphviz

printf "\n\graphviz image\n\n"
make graphviz-image

printf "\n"