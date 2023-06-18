#!/bin/sh
printf "running... \n"

printf "\n\nfirst test \n\n"
make test-first

printf "\n\nsecond test \n\n"
make test-second

printf "\n\nthird test \n\n"
make test-third

printf "\n\nerror test \n\n"
make test-error

printf "\n"