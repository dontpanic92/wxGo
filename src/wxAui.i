%{
	#include "wx/aui/auibar.h"
    #include "wx/aui/auibook.h"
    #include "wx/aui/dockart.h"
    #include "wx/aui/framemanager.h"
%}


// Typemap for wxAuiToolBarItemArray

%{
wxAuiToolBarItemArray auiToolBarItemsliceToArray(_goslice_ slice) {
    wxAuiToolBarItemArray arrayItem;
    for (int i = 0; i < slice.len; i++) {
        wxAuiToolBarItem* a = ((wxAuiToolBarItem**)slice.array)[i];
        arrayItem.Add(*a);
    }
    return arrayItem;
}
%}

%typemap(gotype) const wxAuiToolBarItemArray& "[]AuiToolBarItem"
%typemap(imtype) const wxAuiToolBarItemArray& "uint64"

%typemap(in) const wxAuiToolBarItemArray & %{
    $*1_ltype $1_arr;
    $1_arr = auiToolBarItemsliceToArray(*(_goslice_*)$input);
    $1 = &$1_arr;
%}

%typemap(goin) const wxAuiToolBarItemArray & %{
    $1_swigcptrarr := make([]uintptr, len($1))
	for i := range $1 {
		$1_swigcptrarr[i] = $1[i].Swigcptr()
	}

    $result = uint64((uintptr)(unsafe.Pointer(&$1_swigcptrarr)))
%}

%include "wxGoInterface/aui/auibar.h"
%include "wxGoInterface/aui/auibook.h"
%include "wxGoInterface/aui/dockart.h"
%include "wxGoInterface/aui/framemanager.h"