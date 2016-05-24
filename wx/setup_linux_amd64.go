package wx

// #cgo CPPFLAGS: -I${SRCDIR}/linux_amd64/ -I${SRCDIR}/../wxWidgets/wxWidgets-3.1.0/include -D_FILE_OFFSET_BITS=64 -D__WXGTK__
// #cgo LDFLAGS: -L${SRCDIR}/linux_amd64/lib -pthread  -lwx_gtk2u_xrc-3.1 -lwx_gtk2u_webview-3.1 -lwx_gtk2u_stc-3.1 -lwx_gtk2u_richtext-3.1 -lwx_gtk2u_ribbon-3.1 -lwx_gtk2u_propgrid-3.1 -lwx_gtk2u_aui-3.1 -lwx_gtk2u_gl-3.1 -lwx_gtk2u_qa-3.1 -lwx_baseu_net-3.1 -lwx_gtk2u_html-3.1 -lwx_gtk2u_adv-3.1 -lwx_gtk2u_core-3.1 -lwx_baseu_xml-3.1 -lwx_baseu-3.1 -lwxscintilla-3.1 -lGL -lGLU -lgthread-2.0 -pthread -lX11 -lXxf86vm -lSM -lgtk-x11-2.0 -lgdk-x11-2.0 -lpangocairo-1.0 -latk-1.0 -lcairo -lpangoft2-1.0 -lpango-1.0 -lfontconfig -lfreetype -lnotify -lgdk_pixbuf-2.0 -lgio-2.0 -lgobject-2.0 -lglib-2.0 -lpng -ljpeg -ltiff -lexpat -lwxregexu-3.1 -lz -ldl -lm 
// #cgo LDFLAGS: -s -w
import "C"