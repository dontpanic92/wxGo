%insert(go_header){
type SwigcptrInterface interface{
	Swigcptr() uintptr
}
}

%define WXGO_DECL_TYPECONV(WXTYPE)
%insert(go_wrapper) {
func To##WXTYPE##(a interface{}) WXTYPE{
	return Swigcptr##WXTYPE##(unsafe.Pointer(a.(SwigcptrInterface).Swigcptr()))
}
}
%enddef
