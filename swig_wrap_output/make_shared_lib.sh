#!/bin/bash

filename=$(basename "$1")
filename="${filename%_wrap.*}"

gcc -fpic -shared $1 -L../wxWidgets/wxWidgets-3.0.0/lib/ $(../wxWidgets/wxWidgets-3.0.0/wx-config --libs) -o ../swig_lib_output/$filename.so
