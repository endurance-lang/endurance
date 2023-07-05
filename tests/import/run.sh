#!/bin/bash

./preprocess $1 "temp.output"
./main < "temp.output"