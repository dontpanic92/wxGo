
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

%rename(Assign) operator=;
%rename(Equals) operator==; 
%rename(NotEquals) operator!=; 