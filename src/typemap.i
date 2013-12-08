
//%typedef string wxString;
/*
%typemap(in) wxString{
	$1 = wxString($input, wxConvUTF8, $input.n)
}

%typemap(out) wxString{ 
	$result = _swig_makegostring($1.data(), $1.length());
}

%typemap(in) wxString*, wxString&{
	$1 = new wxString($input, wxConvUTF8, $input->n);
}

%typemap(out) wxString*, wxString&{ 
	$result = _swig_makegostring($1.data(), $1.length());
}
*/

%rename("%(strip:[wx])s") "";

%typedef int wxWindowID;
%typedef int wxBitmapType;
%typedef int wxPolygonFillMode;
%typedef int wxStockCursor;
%typedef int8 wxInt8;
%typedef int wxStockGDI::Item;
%typedef int wxItemKind;

%insert(go_wrapper) %{
	func Get() Window {
        return SwigcptrWindow(0)
	}
%}
