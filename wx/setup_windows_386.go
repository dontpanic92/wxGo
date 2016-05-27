package wx

// #cgo CPPFLAGS: -I${SRCDIR}/windows_386/ -I${SRCDIR}/../wxWidgets/wxWidgets-3.1.0/include -D_FILE_OFFSET_BITS=64 -D__WXMSW__
// #cgo LDFLAGS: -L${SRCDIR}/windows_386/lib -Wl,--subsystem,windows -mwindows -lwxmsw31u -lwxmsw31u_gl -lwxscintilla -lopengl32 -lglu32 -lwxregexu -lwxexpat -lwxtiff -lwxjpeg -lwxpng -lwxzlib -lrpcrt4 -loleaut32 -lole32 -luuid -lwinspool -lwinmm -lshell32 -lshlwapi -lcomctl32 -lcomdlg32 -ladvapi32 -lversion -lwsock32 -lgdi32 -lntdll -lmsvcrt
// #cgo CXXFLAGS: -fpermissive
import "C"
