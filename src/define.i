
#ifdef WXGO_LINUX
#	ifdef WXGO_AMD64

%insert(cgo_comment) %{
#cgo CPPFLAGS: -I${SRCDIR}/linux_amd64/ -I${SRCDIR}/../wxWidgets/wxWidgets-3.1.0/include -D_FILE_OFFSET_BITS=64 -D__WXGTK__
#cgo LDFLAGS: -L/${SRCDIR}/linux_amd64/lib -pthread ${SRCDIR}/linux_amd64/lib/libwx_gtk2u_xrc-3.1.a ${SRCDIR}/linux_amd64/lib/libwx_gtk2u_qa-3.1.a ${SRCDIR}/linux_amd64/lib/libwx_baseu_net-3.1.a ${SRCDIR}/linux_amd64/lib/libwx_gtk2u_html-3.1.a ${SRCDIR}/linux_amd64/lib/libwx_gtk2u_adv-3.1.a ${SRCDIR}/linux_amd64/lib/libwx_gtk2u_core-3.1.a ${SRCDIR}/linux_amd64/lib/libwx_baseu_xml-3.1.a ${SRCDIR}/linux_amd64/lib/libwx_baseu-3.1.a -lgthread-2.0 -pthread -lX11 -lXxf86vm -lSM -lgtk-x11-2.0 -lgdk-x11-2.0 -lpangocairo-1.0 -latk-1.0 -lcairo -lpangoft2-1.0 -lpango-1.0 -lfontconfig -lfreetype -lnotify -lgdk_pixbuf-2.0 -lgio-2.0 -lgobject-2.0 -lglib-2.0 -lpng -ljpeg -ltiff -lexpat -lwxregexu-3.1 -lz -ldl -lm
%}

#	endif
#endif

%go_import("reflect")

%insert(go_header) {
type SwigcptrInterface interface{
	Swigcptr() uintptr
}
}

%insert(go_header) {
func func_pointers_are_equal(f1 interface{}, f2 interface{}) bool{
	return (reflect.ValueOf(f1).Pointer() == reflect.ValueOf(f2).Pointer())
}
}

%define WXGO_DECL_TYPECONV(WXTYPE)
%insert(go_wrapper) {
func To##WXTYPE##(a interface{}) WXTYPE{
	return Swigcptr##WXTYPE##(unsafe.Pointer(a.(SwigcptrInterface).Swigcptr()))
}
}
%enddef
