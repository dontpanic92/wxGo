
//Typemaps for wxString

%typemap(gotype) wxString "string"
%typemap(gotype) const wxString& "string"


%typemap(in) wxString "$1 = wxString($input.p, wxConvUTF8);"

%typemap(in) const wxString& %{
    $*1_ltype $1_str($input.p, wxConvUTF8);
    $1 = &$1_str;
%}

%typemap(out,fragment="AllocateString") wxString
%{ $result = Swig_AllocateString($1.utf8_str(), $1.length()); %}

%typemap(goout,fragment="CopyString") wxString
%{ $result = swigCopyString($1) %}

%typemap(out,fragment="AllocateString") const wxString&
%{ $result = Swig_AllocateString($1->utf8_str(), $1->length()); %}

%typemap(goout,fragment="CopyString") const wxString &
%{ $result = swigCopyString($1) %}


//Typemaps for wxArrayString

%typemap(gotype) wxArrayString "[]string"
%typemap(gotype) const wxArrayString& "[]string"

%{
wxArrayString gostringSliceToArrayString(_goslice_ slice) {
    wxArrayString arrayString;
    for (int i = 0; i < slice.len; i++) {
        wxString tmp_str(((_gostring_*)slice.array)[i].p, wxConvUTF8);
        arrayString.Add(tmp_str);
    }
    return arrayString;
}

_goslice_ arrayStringToGostringSlice(const wxArrayString& arr) {
    _goslice_ slice;
    size_t count = arr.GetCount();
    _gostring_ *go_arr = new _gostring_[count];
    slice.array = go_arr;
    slice.len = slice.cap = count;
    
    for (int i = 0; i < count; i++) {
        go_arr[i] = Swig_AllocateString(arr[i].utf8_str(), arr[i].length());
    }
    
    return slice;
}
%}

%typemap(in) wxArrayString %{
    $1 = gostringSliceToArrayString($input);
%}

%typemap(in) const wxArrayString& %{
    $*1_ltype $1_arr;
    $1_arr = gostringSliceToArrayString($input);
    $1 = &$1_arr;
%}

%typemap(out) wxArrayString %{
    $result = arrayStringToGostringSlice($1);
%}

%typemap(out) const wxArrayString& %{
    $result = arrayStringToGostringSlice(*$1);
%}


// Typemaps for wxChar & wxUniChar

%typemap(gotype) wxUniChar "rune"
%typemap(imtype) wxUniChar "int32"

%typemap(out) wxUniChar %{
    $result = $1.GetValue();
%}

%typemap(goout) wxUniChar %{
    $result = rune($1)
%}

%typedef wchar_t wxChar;

// Typemaps for named enums

%apply int { enum SWIGTYPE }

// Misc

%typemap(gotype) long "int"
%typemap(gotype) unsigned long "uint"
%typedef int wxInt32;
%typedef unsigned int wxUint32;

%typemap(gotype) wxLongLong "int64"
%typemap(imtype) wxLongLong "int64"
%typemap(out) wxLongLong %{
    $result = $1.GetValue();
%}

%typemap(in) wxLongLong %{
    $1 = $input;
%}

%typemap(gotype) wxULongLong "uint64"
%typemap(imtype) wxULongLong "uint64"
%typemap(out) wxULongLong %{
    $result = $1.GetValue();
%}

%typemap(in) wxULongLong %{
    $1 = $input;
%}

%typedef long wxIntPtr;
%typedef unsigned long wxUIntPtr;
%typedef long long time_t;
%typedef unsigned char wxByte;
