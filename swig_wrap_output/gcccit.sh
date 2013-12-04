#!/bin/bash

gcc -c -fPIC -I../src -I../wxWidgets/wxWidgets-3.0.0/include -I../wxWidgets/wxWidgets-3.0.0/lib/wx/include/gtk2-unicode-static-3.0 $(../wxWidgets/wxWidgets-3.0.0/wx-config --cxxflags) $1
