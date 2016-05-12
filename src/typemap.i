
/*Still need testing

%typemap(gotype) string, wxString "string"
%typemap(gotype) string, const wxString& "string"
%typemap(gotype) string, const wxString* "string"

%typemap(in) wxString "$1 = wxString($input.p);"

%typemap(in) const wxString& "$1 = new wxString($input.p, wxConvUTF8);"
%typemap(in) const wxString* "$1 = new wxString($input.p, wxConvUTF8);"

%typemap(freearg) wxString& "delete $1;"
%typemap(freearg) wxString* "delete $1;"

%typemap(out) wxString "$result = _swig_makegostring($1.utf8_str(), $1.length());"
%typemap(out) const wxString& "$result = _swig_makegostring($1->utf8_str(), $1->length());"
%typemap(varout) wxString "$result = _swig_makegostring($1->utf8_str(), $1->length());"
*/

%apply int { long };
%apply unsigned int { unsigned long };

