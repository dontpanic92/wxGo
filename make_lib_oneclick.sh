#!/bin/bash

cd ./src
swigit.sh wx.i

cd ../swig_wrap_output
./gcccit.sh wx_wrap.cxx
./make_shared_lib.sh wx_wrap.o

cd ../swig_lib_output
./make_static_lib.sh wx
