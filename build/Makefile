
all: preprocess linux-internal windows-internal osx-internal

linux-internal:
	if [ -d "linux_build" ]; then rm -r linux_build; fi
	mkdir linux_build
	cd linux_build && \
	swig -Wall -c++ -D__WXGTK__ -go -cgo -trackobject 2 -v -o wx_wrap_linux.cxx ../../src/wx.i && \
	python ../postprocess.py wx.go && \
	mv wx.go ../../wx/wx_linux.go && \
	mv wx_wrap_linux.cxx ../../wx/wx_wrap_linux.cxx && \
	mv wx_wrap_linux.h ../../wx/wx_wrap_linux.h
	rm -r linux_build

linux: preprocess linux-internal


windows-internal:
	if [ -d "windows_build" ]; then rm -r windows_build; fi
	mkdir windows_build
	cd windows_build && \
	swig -Wall -c++ -D__WXMSW__ -go -cgo -trackobject 2 -v -o wx_wrap_windows.cxx ../../src/wx.i && \
	python ../postprocess.py wx.go && \
	mv wx.go ../../wx/wx_windows.go && \
	mv wx_wrap_windows.cxx ../../wx/wx_wrap_windows.cxx && \
	mv wx_wrap_windows.h ../../wx/wx_wrap_windows.h
	rm -r windows_build

windows: preprocess windows-internal

osx-internal:
	if [ -d "osx_build" ]; then rm -r osx_build; fi
	mkdir osx_build
	cd osx_build && \
	swig -Wall -c++ -D__WXOSX_COCOA__ -D__WXOSX__ -D__WXMAC__ -go -cgo -v -trackobject 2 -o wx_wrap_darwin.cxx ../../src/wx.i && \
	python ../postprocess.py wx.go && \
	mv wx.go ../../wx/wx_darwin.go && \
	mv wx_wrap_darwin.cxx ../../wx/wx_wrap_darwin.cxx && \
	mv wx_wrap_darwin.h ../../wx/wx_wrap_darwin.h 
	rm -r osx_build

osx: preprocess osx-internal

preprocess:
	if [ -d "../src/wxGoInterface" ]; then rm -r ../src/wxGoInterface; fi
	python preprocess.py ../src/wxGoInterface_original ../src/wxGoInterface
