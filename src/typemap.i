
//Typemaps for wxString

%typemap(gotype) wxString "string"
%typemap(gotype) const wxString& "string"


%typemap(in) wxString "$1 = wxString($input.p, wxConvUTF8, $input.n);"

%typemap(in) const wxString& %{
    $*1_ltype $1_str($input.p, wxConvUTF8, $input.n);
    $1 = &$1_str;
%}

%typemap(directorin,fragment="AllocateString") wxString
%{ 
    wxScopedCharBuffer $1_utf8_str = $1.utf8_str();
    $input = Swig_AllocateString($1_utf8_str, $1_utf8_str.length()); 
%}

%typemap(godirectorin,fragment="CopyString") wxString
%{ $result = swigCopyString($input) %}

%typemap(directorin,fragment="AllocateString") const wxString&
%{ 
    wxScopedCharBuffer $1_utf8_str = $1.utf8_str();
    $input = Swig_AllocateString($1_utf8_str, $1_utf8_str.length()); 
%}

%typemap(godirectorin,fragment="CopyString") const wxString&
%{ $result = swigCopyString($input) %}

%typemap(out,fragment="AllocateString") wxString
%{
    wxScopedCharBuffer $1_utf8_str = $1.utf8_str();
    $result = Swig_AllocateString($1_utf8_str, $1_utf8_str.length()); 
%}

%typemap(goout,fragment="CopyString") wxString
%{ $result = swigCopyString($1) %}

%typemap(out,fragment="AllocateString") const wxString&
%{ 
    wxScopedCharBuffer $1_utf8_str = $1->utf8_str();
    $result = Swig_AllocateString($1_utf8_str, $1_utf8_str.length()); 
%}

%typemap(goout,fragment="CopyString") const wxString &
%{ $result = swigCopyString($1) %}

%typemap(godirectorout) wxString
%{
  {
    p := Swig_malloc(len($input))
    s := (*[1<<30]byte)(unsafe.Pointer(p))[:len($input)]
    copy(s, $input)
    $result = *(*string)(unsafe.Pointer(&s))
  }
%}

%typemap(directorout,warning=SWIGWARN_TYPEMAP_THREAD_UNSAFE_MSG) wxString
%{
  $result = wxString::FromUTF8($input.p, $input.n);
  free($input.p);
%}

%typemap(godirectorout) const wxString&
%{
  {
    p := Swig_malloc(len($input))
    s := (*[1<<30]byte)(unsafe.Pointer(p))[:len($input)]
    copy(s, $input)
    $result = *(*string)(unsafe.Pointer(&s))
  }
%}

%typemap(directorout,warning=SWIGWARN_TYPEMAP_THREAD_UNSAFE_MSG) const wxString&
%{
  static $*1_ltype $1_str;
  $1_str = wxString::FromUTF8($input.p, $input.n);
  free($input.p);
  $result = &$1_str;
%}


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
        wxScopedCharBuffer utf8_str = arr[i].utf8_str();
        go_arr[i] = Swig_AllocateString(utf8_str, utf8_str.length());
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
    sliceWithPointer* $1_ptr = (sliceWithPointer*)$input;

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
struct sliceWithPointer {
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
    sliceWithPointer* $1_ptr = (sliceWithPointer*)$input;

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

%typemap(argout) (int n, const wxAcceleratorEntry entries[]) %{
    delete []$2;
%}

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

%typemap(argout) const wxVariantList&, wxVariantList& %{
    delete $1;
%}

%typemap(out)  const wxVariantList&, wxVariantList& %{
    _goslice_ *slice = new _goslice_;
    size_t count = $1->GetCount();
    long long *go_arr = (long long*)malloc(sizeof(long long[count]));
    slice->array = go_arr;
    slice->len = slice->cap = count;
    
    for (int i = 0; i < count; i++) {
        go_arr[i] = (long long)$1->operator[](i);
    }
    $result = (long long)slice;
%}

%typemap(goout) const wxVariantList&, wxVariantList& %{
    slice := (*[]uint64)(unsafe.Pointer(uintptr($1)))
    newSlice := make([]Variant, len(*slice))
    for i := range newSlice {
        newSlice[i] = SwigClassVariantSetSwigcptr(uintptr((*slice)[i]))
    }
    p := *(*swig_goslice)(unsafe.Pointer(uintptr($1)))
    Swig_free(p.arr)
    $result = newSlice
%}

// Typemaps for wxVectors

%define _APPLY_WXVECTOR(wxtype, ref, deref)
%{
wxVector< wx##wxtype ref > wxtype##SliceToVector (_goslice_ slice) {
    wxVector< wx##wxtype ref > vector;
    for (int i = 0; i < slice.len; i++) {
        wx##wxtype * a = (( wx##wxtype ** )slice.array)[i];
        vector.push_back( deref a);
    }
    return vector;
}

_goslice_ vectorTo##wxtype##Slice (const wxVector< wx##wxtype ref >& arr) {
    _goslice_ slice;
    size_t count = arr.size();
    wx##wxtype * ref go_arr = ( wx##wxtype * ref )malloc(sizeof( wx##wxtype ref) * count);
    slice.array = go_arr;
    slice.len = slice.cap = count;
    
    for (int i = 0; i < count; i++) {
        go_arr[i] = arr[i];
    }
    
    return slice;
}
%}

%insert(go_header) %{
func swigCopy##wxtype##Slice (s *[] wxtype ) [] wxtype {
    newSlice := make([] wxtype, len(*s))
    for i := range newSlice {
        newSlice[i] = (*s)[i]
    }
    p := *(*swig_goslice)(unsafe.Pointer(s))
    Swig_free(p.arr)
    return newSlice
}
%}

%typemap(gotype) wxVector< wx##wxtype ref > "[] wxtype"

%typemap(in) wxVector< wx##wxtype ref > %{
    $1 = wxtype##SliceToVector($input);
%}

%typemap(out) wxVector< wx##wxtype ref > %{
    $result = vectorTo##wxtype##Slice ($1);
%}

%typemap(goout) wxVector< wx##wxtype ref > %{
    $result = swigCopy##wxtype##Slice(&$1)
%}


%typemap(gotype) const wxVector< wx##wxtype ref >& "[] wxtype"
%typemap(imtype) const wxVector< wx##wxtype ref >& "[] wxtype"

%typemap(goin) const wxVector< wx##wxtype ref > & %{
    $result = $1
%}

%typemap(goargout) const wxVector< wx##wxtype ref > & %{
%}

%typemap(argout) const wxVector< wx##wxtype ref > & %{
%}

%typemap(in) const wxVector< wx##wxtype ref > & %{
    $*1_ltype $1_arr;
    $1_arr = wxtype##SliceToVector ($input);
    $1 = &$1_arr;
%}

%typemap(out) const wxVector< wx##wxtype ref > & %{
    $result = vectorTo##wxtype##Slice (*$1);
%}

%typemap(goout) const wxVector< wx##wxtype ref > & %{
    $result = swigCopy##wxtype##Slice(&$1)
%}

%insert(go_header) %{
type wxtype##SliceWithPointer struct {
    slice [] wxtype
    ptr uintptr
}
%}

%typemap(gotype) wxVector< wx##wxtype ref > * "*[] wxtype"
%typemap(imtype) wxVector< wx##wxtype ref > * "* wxtype##SliceWithPointer"

%typemap(goin) wxVector< wx##wxtype ref > * %{
    var $1_var wxtype##SliceWithPointer
    $result = &$1_var
    $result.slice = *$1
%}

%typemap(goargout) wxVector< wx##wxtype ref > * %{
    *$1 = swigCopyIntSlice((*[]int)(unsafe.Pointer($1_var.ptr)))
    Swig_free($1_var.ptr)
%}

%typemap(in) wxVector< wx##wxtype ref > * %{
    sliceWithPointer* $1_ptr = (sliceWithPointer*)$input;

    $*1_ltype $1_arr;
    $1_arr = type##SliceToVector($1_ptr->slice);
    $1 = &$1_arr; 
%}

%typemap(argout) wxVector< wx##wxtype ref > * %{
    $1_ptr->ptr = (_goslice_*)malloc(sizeof(_goslice_));
    *$1_ptr->ptr = arrayIntToIntgoSlice(*$1);
%}

%enddef
#define APPLY_WXVECTOR(type) _APPLY_WXVECTOR(type, ,*)
#define APPLY_POINTER_WXVECTOR(type) _APPLY_WXVECTOR(type, *, )

%{
    #include <wx/variant.h>
    #include <wx/docview.h>
    #include <wx/treelist.h>
    #include <wx/dataview.h>
%}

APPLY_WXVECTOR(Variant)
APPLY_WXVECTOR(TreeListItem)
APPLY_POINTER_WXVECTOR(View)
APPLY_POINTER_WXVECTOR(Document)
APPLY_POINTER_WXVECTOR(DocTemplate)
APPLY_POINTER_WXVECTOR(DataViewColumn)

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
    wxScopedCharBuffer $1_utf8_str = $1_str.utf8_str();
    $result = Swig_AllocateString($1_utf8_str, $1_utf8_str.length()); 
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
