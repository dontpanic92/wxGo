
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
    _gostring_ *go_arr = (_gostring_*)malloc(sizeof(_gostring_[count]));
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


%typemap(gotype) wxArrayString, const wxArrayString& "[]string"
%typemap(imtype) wxArrayString, const wxArrayString& "uint64"

%typemap(goargout) wxArrayString, const wxArrayString & %{
%}

%typemap(argout) wxArrayString, const wxArrayString & %{
%}

%typemap(in) wxArrayString %{
    $1 = gostringSliceToArrayString(*(_goslice_*)$input);
%}

%typemap(in) const wxArrayString & %{
    $*1_ltype $1_arr;
    $1_arr = gostringSliceToArrayString(*(_goslice_*)$input);
    $1 = &$1_arr;
%}

//Any method to get the type of $result instead of hard-coded?
%typemap(out) wxArrayString %{
    $result = (long long)malloc(sizeof(_goslice_));
    *(_goslice_*)$result = arrayStringToGostringSlice($1);
%}

%typemap(out) const wxArrayString & %{
    $result = (long long)malloc(sizeof(_goslice_));
    *(_goslice_*)$result = arrayStringToGostringSlice(*$1);
%}

%typemap(goin) wxArrayString, const wxArrayString & %{
    $result = uint64((uintptr)(unsafe.Pointer(&$1)))
%}

%typemap(goout) wxArrayString, const wxArrayString & %{
    $result = swigCopyStringSlice((*[]string)(unsafe.Pointer(uintptr($1))))
    Swig_free(uintptr($1))
%}

%{
struct StringSliceWithPointer {
    _goslice_ slice;
    _goslice_* ptr;
};
%}

%insert(go_header) %{
type stringSliceWithPointer struct {
    slice []string
    ptr uintptr
}
%}

%typemap(gotype) wxArrayString & "*[]string"
%typemap(imtype) wxArrayString & "*stringSliceWithPointer"

%typemap(goin) wxArrayString & %{
    var $1_var stringSliceWithPointer
    $result = &$1_var
    $result.slice = *$1
%}

%typemap(goargout) wxArrayString & %{
    *$1 = swigCopyStringSlice((*[]string)(unsafe.Pointer($1_var.ptr)))
    Swig_free($1_var.ptr)
%}

%typemap(in) wxArrayString & %{
    StringSliceWithPointer* $1_ptr = (StringSliceWithPointer*)$input;

    $*1_ltype $1_arr;
    $1_arr = gostringSliceToArrayString($1_ptr->slice);
    $1 = &$1_arr; 
%}

%typemap(argout) wxArrayString & %{
    $1_ptr->ptr = (_goslice_*)malloc(sizeof(_goslice_));
    *$1_ptr->ptr = arrayStringToGostringSlice(*$1);
%}


// Typemaps for wxArrayInt

%{
wxArrayInt intgoSliceToArrayInt(_goslice_ slice) {
    wxArrayInt arrayInt;
    for (int i = 0; i < slice.len; i++) {
        intgo a = ((intgo*)slice.array)[i];
        arrayInt.Add(a);
    }
    return arrayInt;
}

_goslice_ arrayIntToIntgoSlice(const wxArrayInt& arr) {
    _goslice_ slice;
    size_t count = arr.GetCount();
    intgo *go_arr = (intgo*)malloc(sizeof(intgo[count]));
    slice.array = go_arr;
    slice.len = slice.cap = count;
    
    for (int i = 0; i < count; i++) {
        go_arr[i] = arr[i];
    }
    
    return slice;
}
%}

%insert(go_header) %{
func swigCopyIntSlice(intSlice *[]int) []int {
    newSlice := make([]int, len(*intSlice))
    for i := range newSlice {
        newSlice[i] = (*intSlice)[i]
    }
    p := *(*swig_goslice)(unsafe.Pointer(intSlice))
    Swig_free(p.arr)
    return newSlice
}
%}

%typemap(gotype) wxArrayInt "[]int"

%typemap(in) wxArrayInt %{
    $1 = intgoSliceToArrayInt($input);
%}

%typemap(out) wxArrayInt %{
    $result = arrayIntToIntgoSlice($1);
%}

%typemap(goout) wxArrayInt %{
    $result = swigCopyIntSlice(&$1)
%}


%typemap(gotype) const wxArrayInt& "[]int"
%typemap(imtype) const wxArrayInt& "[]int"

%typemap(goin) const wxArrayInt & %{
    $result = $1
%}

%typemap(goargout) const wxArrayInt & %{
%}

%typemap(argout) const wxArrayInt & %{
%}

%typemap(in) const wxArrayInt & %{
    $*1_ltype $1_arr;
    $1_arr = intgoSliceToArrayInt($input);
    $1 = &$1_arr;
%}

%typemap(out) const wxArrayInt & %{
    $result = arrayIntToIntgoSlice(*$1);
%}


%typemap(goout) const wxArrayInt & %{
    $result = swigCopyIntSlice(&$1)
%}

%{
struct IntSliceWithPointer {
    _goslice_ slice;
    _goslice_* ptr;
};
%}

%insert(go_header) %{
type intSliceWithPointer struct {
    slice []int
    ptr uintptr
}
%}

%typemap(gotype) wxArrayInt & "*[]int"
%typemap(imtype) wxArrayInt & "*intSliceWithPointer"

%typemap(goin) wxArrayInt & %{
    var $1_var intSliceWithPointer
    $result = &$1_var
    $result.slice = *$1
%}

%typemap(goargout) wxArrayInt & %{
    *$1 = swigCopyIntSlice((*[]int)(unsafe.Pointer($1_var.ptr)))
    Swig_free($1_var.ptr)
%}

%typemap(in) wxArrayInt & %{
    IntSliceWithPointer* $1_ptr = (IntSliceWithPointer*)$input;

    $*1_ltype $1_arr;
    $1_arr = intgoSliceToArrayInt($1_ptr->slice);
    $1 = &$1_arr; 
%}

%typemap(argout) wxArrayInt & %{
    $1_ptr->ptr = (_goslice_*)malloc(sizeof(_goslice_));
    *$1_ptr->ptr = arrayIntToIntgoSlice(*$1);
%}

// Typemaps for wxAcceleratorEntry[]

%typemap(gotype) (int n, const wxAcceleratorEntry entries[]) "[]AcceleratorEntry"
%typemap(imtype) (int n, const wxAcceleratorEntry entries[]) "uint64"

%typemap(goin) (int n, const wxAcceleratorEntry entries[]) %{
    $result_tmp := make([]uintptr, len($1))
    for i := 0; i < len($1); i++ {
        $result_tmp[i] = $1[i].Swigcptr()
    }
    $result = uint64(uintptr(unsafe.Pointer(&$result_tmp)))
%} 

%typemap(in) (int n, const wxAcceleratorEntry entries[]) %{
    _goslice_* $input_slice = (_goslice_*)($input);
    $1 = $input_slice->len;
    wxAcceleratorEntry** $2_arr = (wxAcceleratorEntry**)$input_slice->array;
    $2 = new wxAcceleratorEntry[$1];
    for (int i = 0; i < $1; i++) {
        $2[i] = *($2_arr[i]);
    }
%}

%typemap(argout) (int n, const wxAcceleratorEntry entries[]) {
    delete []$2;
}

// Typemaps for wxVariantList
// We treat wxVariantList& as const wxVariantList&
%typemap(gotype) const wxVariantList&, wxVariantList& "[]Variant"
%typemap(imtype) const wxVariantList&, wxVariantList& "uint64"

%typemap(goin) const wxVariantList&, wxVariantList& %{
    $result_tmp := make([]uintptr, len($1))
    for i := 0; i < len($1); i++ {
        $result_tmp[i] = $1[i].Swigcptr()
    }
    $result = uint64(uintptr(unsafe.Pointer(&$result_tmp)))
%} 

%typemap(in) const wxVariantList&, wxVariantList& %{
    _goslice_* $input_slice = (_goslice_*)($input);
    intgo $1_len = $input_slice->len;
    wxVariant** $1_arr = (wxVariant**)$input_slice->array;
    $1 = new wxVariantList;
    for (int i = 0; i < $1_len; i++) {
        $1->push_back($1_arr[i]);
    }
%}

%typemap(argout) const wxVariantList&, wxVariantList& {
    delete $1;
}

%typemap(out)  const wxVariantList&, wxVariantList& {
    _goslice_ *slice = new _goslice_;
    size_t count = $1->GetCount();
    long long *go_arr = (long long*)malloc(sizeof(long long[count]));
    slice->array = go_arr;
    slice->len = slice->cap = count;
    
    for (int i = 0; i < count; i++) {
        go_arr[i] = (long long)$1->operator[](i);
    }
    $result = (long long)slice;
}

%typemap(goout) const wxVariantList&, wxVariantList& {
    slice := (*[]uint64)(unsafe.Pointer(uintptr($1)))
    newSlice := make([]Variant, len(*slice))
    for i := range newSlice {
        newSlice[i] = SwigClassVariantSetSwigcptr(uintptr((*slice)[i]))
    }
    p := *(*swig_goslice)(unsafe.Pointer(uintptr($1)))
    Swig_free(p.arr)
    $result = newSlice
}


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
%typemap(gotype) wxDash "int8"

%typedef double wxDouble;
%typedef int wxInt32;
%typedef unsigned int wxUint32;

%typemap(gotype) wxFileOffset "int64"
%typemap(gotype) wxLongLong_t "int64"
%typemap(gotype) wxULongLong_t "uint64"

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
