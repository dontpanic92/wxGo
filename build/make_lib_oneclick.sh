#!/bin/bash

mkdir -p out
mkdir -p ../lib

echo "Compiling swig project..."
#swig -Wall -c++ -go -intgosize 64 -outdir ./out -o ./out/wx_wrap.cxx -soname wxgo.so ../src/wx.i 
#sed -i -e 's/\(#pragma dynimport _ _\)/\/\/\1/' \
#            -e 's/#pragma dynimport\(.*\)\(""\)/#pragma dynimport \1 "wxgo.so"/g' \
#            ./out/wx_gc.c
#python2 deal_with_go_1_4.py

swig -Wall -c++ -go -cgo -intgosize 64 -outdir ./out -o ./out/wx_wrap.cxx ../src/wx.i 

echo "Compiling wxGo..."
#g++ -c -std=c++11 -fPIC $(../wxWidgets/wxWidgets-3.0.2/wx-config --cxxflags) -o ./out/wx_wrap.o ./out/wx_wrap.cxx
#g++ -fpic -shared ./out/wx_wrap.o $(../wxWidgets/wxWidgets-3.0.2/wx-config --libs) -o ../lib/wxgo.so
rm -f ../lib/wx.a
cp ../src/go_helper.go ./out/
cd out
CGO_CXXFLAGS="$(../../wxWidgets/wxWidgets-3.1.0/wx-config --cxxflags) -O2" CGO_LDFLAGS="$(../../wxWidgets/wxWidgets-3.1.0/wx-config --libs)" go build -x -o ../../lib/wx.a

#echo "Compiling Go files..."
#go tool compile -o ./out/wx.6 ./out/wx.go ../src/go_helper.go
#go tool 6c -o ./out/wx_gc.6 -I /usr/lib/go/src/runtime/ ./out/wx_gc.c

#echo "Packing Go lib..."
#rm -f ../lib/wx.a
#go tool pack grc ../lib/wx.a ./out/wx.6 ./out/wx_gc.6

#grc
