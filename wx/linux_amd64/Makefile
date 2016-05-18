all: 
	swig -Wall -c++ -D__WXGTK__ -go -cgo -intgosize 64 -v -o wx_wrap_linux_amd64.cxx ../../src/wx.i

	mv wx.go ../wx_linux_amd64.go
	mv wx_wrap_linux_amd64.cxx ../wx_wrap_linux_amd64.cxx
	mv wx_wrap_linux_amd64.h ../wx_wrap_linux_amd64.h 
