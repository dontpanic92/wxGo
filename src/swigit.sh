#!/bin/bash

filename=$(basename "$1")
filename="${filename%.*}"

swig -Wall -c++ -go -intgosize 64 -outdir "../swig_lib_output" -o "../swig_wrap_output/"$filename"_wrap.cxx" $1
