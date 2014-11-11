#!/bin/bash

mkdir -p out
mkdir -p ../lib

echo "Compiling swig project..."
swig -Wall -c++ -go -intgosize 64 -outdir ./out -o ./out/wx_wrap.cxx -soname wxgo.so ../src/wx.i 

echo "Compiling wxWidgets Wrapper..."
g++ -c -std=c++11 -fPIC $(../wxWidgets/wxWidgets-3.0.0/wx-config --cxxflags) -o ./out/wx_wrap.o ./out/wx_wrap.cxx
g++ -fpic -shared ./out/wx_wrap.o $(../wxWidgets/wxWidgets-3.0.0/wx-config --libs) -o ../lib/wxgo.so

echo "Compiling Go files..."
go tool 6g -o ./out/wx.6 ./out/wx.go ../src/go_helper.go
go tool 6c -o ./out/wx_gc.6 -I /usr/lib/go/src/pkg/runtime/ ./out/wx_gc.c

echo "Packing Go lib..."
rm -f ../lib/wx.a
go tool pack c ../lib/wx.a ./out/wx.6 ./out/wx_gc.6

#grc
