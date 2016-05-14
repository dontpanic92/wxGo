
%typemap(gotype) string, wxString "string"
%typemap(gotype) string, const wxString& "string"

%typemap(in) wxString "$1 = wxString($input.p, wxConvUTF8);"

%typemap(in) const wxString&
%{
  $*1_ltype $1_str($input.p, wxConvUTF8);
  $1 = &$1_str;
%}

%typemap(out,fragment="AllocateString") wxString
%{ $result = Swig_AllocateString($1.utf8_str(), $1.length()); %}

%typemap(out,fragment="AllocateString") const wxString&
%{ $result = Swig_AllocateString($1->utf8_str(), $1->length()); %}
