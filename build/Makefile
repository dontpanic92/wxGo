
all: preprocess linux windows

linux:
	swig -Wall -c++ -D__WXGTK__ -go -cgo -v -o wx_wrap_linux.cxx ../src/wx.i

	mv wx.go ../wx/wx_linux.go
	mv wx_wrap_linux.cxx ../wx/wx_wrap_linux.cxx
	mv wx_wrap_linux.h ../wx/wx_wrap_linux.h 

windows:
	swig -Wall -c++ -D__WXMSW__ -go -cgo -v -o wx_wrap_windows.cxx ../src/wx.i

	mv wx.go ../wx/wx_windows.go
	mv wx_wrap_windows.cxx ../wx/wx_wrap_windows.cxx
	mv wx_wrap_windows.h ../wx/wx_wrap_windows.h 


preprocess:
	if [ -d "../src/wxGoInterface" ]; then rm -r ../src/wxGoInterface; fi
	python2 preprocess.py ../src/wxGoInterface_original ../src/wxGoInterface