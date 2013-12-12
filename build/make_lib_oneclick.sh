#!/bin/bash

mkdir -p out
mkdir -p ../lib

swig -Wall -c++ -go -intgosize 64 -outdir ./out -o ./out/wx_wrap.cxx -soname wxgo.so ../src/wx.i 

gcc -c -fPIC $(../wxWidgets/wxWidgets-3.0.0/wx-config --cxxflags) -o ./out/wx_wrap.o ./out/wx_wrap.cxx

gcc -fpic -shared ./out/wx_wrap.o $(../wxWidgets/wxWidgets-3.0.0/wx-config --libs) -o ../lib/wxgo.so

go tool 6g -o ./out/wx.6 ./out/wx.go ../src/go_helper.go
go tool 6c -o ./out/wx_gc.6 -I /usr/lib/go/src/pkg/runtime/ ./out/wx_gc.c
go tool pack grc ../lib/wx.a ./out/wx.6 ./out/wx_gc.6
