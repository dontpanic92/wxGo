package wx

// #cgo CPPFLAGS: -I${SRCDIR}/linux_386/ -I${SRCDIR}/../wxWidgets/wxWidgets-3.1.0/include -D_FILE_OFFSET_BITS=64 -D__WXGTK__
// #cgo CXXFLAGS: -std=c++11 -D_GLIBCXX_USE_CXX11_ABI=0
// #cgo !wxgo_binary_package_build LDFLAGS: -L${SRCDIR}/linux_386/lib -lwx_gtk3u_xrc-3.1 -lwx_gtk3u_webview-3.1  -lwx_gtk3u_stc-3.1 -lwx_gtk3u_richtext-3.1 -lwx_gtk3u_ribbon-3.1 -lwx_gtk3u_propgrid-3.1 -lwx_gtk3u_aui-3.1 -lwx_gtk3u_media-3.1 -lwx_gtk3u_gl-3.1 -lwx_gtk3u_qa-3.1 -lwx_baseu_net-3.1 -lwx_gtk3u_html-3.1 -lwx_gtk3u_adv-3.1 -lwx_gtk3u_core-3.1 -lwx_baseu_xml-3.1 -lwx_baseu-3.1 -lwxscintilla-3.1 -lwxregexu-3.1
// #cgo LDFLAGS: -pthread -lstdc++ -lGL -lGLU -lgthread-2.0 -lX11 -lXxf86vm -lSM -lgtk-3 -lgdk-3 -lpangocairo-1.0 -lpango-1.0 -latk-1.0 -lcairo-gobject -lcairo -lnotify -lgdk_pixbuf-2.0 -lgio-2.0 -lgobject-2.0 -lglib-2.0 -lpng -ljpeg -ltiff -lexpat -lz -ldl -lm -lgstreamer-1.0 -lgstvideo-1.0 -lwebkitgtk-3.0
import "C"
