
all: preprocess linux-internal windows-internal osx-internal

linux-internal:
	swig -Wall -c++ -D__WXGTK__ -go -cgo -v -o wx_wrap_linux.cxx ../src/wx.i
	python2 postprocess.py wx.go
	mv wx.go ../wx/wx_linux.go
	mv wx_wrap_linux.cxx ../wx/wx_wrap_linux.cxx
	mv wx_wrap_linux.h ../wx/wx_wrap_linux.h 

linux: preprocess linux-internal


windows-internal:
	swig -Wall -c++ -D__WXMSW__ -go -cgo -v -o wx_wrap_windows.cxx ../src/wx.i
	python2 postprocess.py wx.go
	mv wx.go ../wx/wx_windows.go
	mv wx_wrap_windows.cxx ../wx/wx_wrap_windows.cxx
	mv wx_wrap_windows.h ../wx/wx_wrap_windows.h 

windows: preprocess windows-internal

osx-internal:
	swig -Wall -c++ -D__WXOSX_COCOA__ -D__WXOSX__ -D__WXMAC__ -go -cgo -v -o wx_wrap_osx.cxx ../src/wx.i
	python2 postprocess.py wx.go
	mv wx.go ../wx/wx_osx.go
	mv wx_wrap_osx.cxx ../wx/wx_wrap_osx.cxx
	mv wx_wrap_osx.h ../wx/wx_wrap_osx.h 

osx: preprocess osx-internal

preprocess:
	if [ -d "../src/wxGoInterface" ]; then rm -r ../src/wxGoInterface; fi
	python2 preprocess.py ../src/wxGoInterface_original ../src/wxGoInterface