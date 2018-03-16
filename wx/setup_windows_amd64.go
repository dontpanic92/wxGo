package wx

// #cgo CPPFLAGS: -I${SRCDIR}/windows_amd64/ -I${SRCDIR}/../wxWidgets/wxWidgets-3.1.0/include -D_FILE_OFFSET_BITS=64 -D__WXMSW__
// #cgo !wxgo_binary_package_build LDFLAGS: -L${SRCDIR}/windows_amd64/lib -lwxmsw31u -lwxmsw31u_gl -lwxscintilla -lwxregexu -lwxexpat -lwxtiff -lwxjpeg -lwxpng -lwxzlib
// #cgo mingw_workaround LDFLAGS: -Wl,--subsystem,windows,--allow-multiple-definition
// #cgo !mingw_workaround LDFLAGS: -Wl,--subsystem,windows
// #cgo LDFLAGS: -l:libstdc++.a -mwindows -lopengl32 -lglu32 -lrpcrt4 -loleaut32 -lole32 -luuid -lwinspool -lwinmm -lshell32 -lshlwapi -lcomctl32 -lcomdlg32 -ladvapi32 -lversion -lwsock32 -lgdi32
// #cgo !go1.8 LDFLAGS: -lntdll -lmsvcrt
// #cgo CXXFLAGS: -fpermissive
import "C"
