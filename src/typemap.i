
//Typemaps for wxString

%typemap(gotype) wxString "string"
%typemap(gotype) const wxString& "string"


%typemap(in) wxString "$1 = wxString($input.p, wxConvUTF8, $input.n);"

%typemap(in) const wxString& %{
    $*1_ltype $1_str($input.p, wxConvUTF8, $input.n);
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

%{
wxArrayString gostringSliceToArrayString(_goslice_ slice) {
    wxArrayString arrayString;
    for (int i = 0; i < slice.len; i++) {
        const _gostring_& gostr = ((_gostring_*)slice.array)[i];
        wxString tmp_str(gostr.p, wxConvUTF8, gostr.n);
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

%insert(go_header) %{
type swig_goslice struct { arr uintptr; n int; c int }
func swigCopyStringSlice(strSlice *[]string) []string {
    newSlice := make([]string, len(*strSlice))
    for i := range newSlice {
        newSlice[i] = swigCopyString((*strSlice)[i])
    }
    p := *(*swig_goslice)(unsafe.Pointer(strSlice))
    Swig_free(p.arr)
    return newSlice
}
%}

%typemap(gotype) wxArrayString "[]string"

%typemap(in) wxArrayString %{
    $1 = gostringSliceToArrayString($input);
%}

%typemap(out) wxArrayString %{
    $result = arrayStringToGostringSlice($1);
%}

%typemap(goout) wxArrayString %{
    $result = swigCopyStringSlice(&$1)
%}


%typemap(gotype) const wxArrayString& "[]string"
%typemap(imtype) const wxArrayString& "[]string"

%typemap(goin) const wxArrayString & %{
    $result = $1
%}

%typemap(goargout) const wxArrayString & %{
%}

%typemap(argout) const wxArrayString & %{
%}

%typemap(in) const wxArrayString & %{
    $*1_ltype $1_arr;
    $1_arr = gostringSliceToArrayString($input);
    $1 = &$1_arr;
%}

%typemap(out) const wxArrayString & %{
    $result = arrayStringToGostringSlice(*$1);
%}


%typemap(goout) const wxArrayString & %{
    $result = swigCopyStringSlice(&$1)
%}

%{
struct SliceWithPointer {
    _goslice_ slice;
    _goslice_* ptr;
};
%}

%insert(go_header) %{
type sliceWithPointer struct {
    slice []string
    ptr uintptr
}
%}

%typemap(gotype) wxArrayString & "*[]string"
%typemap(imtype) wxArrayString & "*sliceWithPointer"

%typemap(goin) wxArrayString & %{
    var $1_var sliceWithPointer
    $result = &$1_var
    $result.slice = *$1
%}

%typemap(goargout) wxArrayString & %{
    *$1 = swigCopyStringSlice((*[]string)(unsafe.Pointer($1_var.ptr)))
    Swig_free(uintptr(unsafe.Pointer($1_var.ptr)))
%}

%typemap(in) wxArrayString & %{
    SliceWithPointer* $1_ptr = (SliceWithPointer*)$input;

    $*1_ltype $1_arr;
    $1_arr = gostringSliceToArrayString($1_ptr->slice);
    $1 = &$1_arr; 
%}

%typemap(argout) wxArrayString & %{
    $1_ptr->ptr = new _goslice_;
    *$1_ptr->ptr = arrayStringToGostringSlice(*$1);
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

%typemap(in) wxUniChar %{
    $1 = wxUniChar($input);
%}

%typemap(gotype) wxChar "rune"
%typemap(imtype) wxChar "int32"

%typemap(in) wxChar %{
    $1 = wxChar($input);
%}

%typemap(out) wxChar %{
    $result = $1;
%}

%typemap(goout) wxChar %{
    $result = rune($1)
%}

%typemap(gotype) const wxChar* "string"

%typemap(in) const wxChar* %{
    wxString $1_str($input.p, wxConvUTF8);
    $1 = (wxChar*)$1_str.t_str();
%}


%typemap(out,fragment="AllocateString") const wxChar*
%{ 
    wxString $1_str($1);
    $result = Swig_AllocateString($1_str.utf8_str(), $1_str.length()); 
%}

%typemap(goout,fragment="CopyString") const wxChar*
%{ $result = swigCopyString($1) %}

// Typemaps for named enums

%apply int { enum SWIGTYPE }

// Misc

%typemap(gotype) long "int"
%typemap(gotype) unsigned long "uint"
%typedef double wxDouble;
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
