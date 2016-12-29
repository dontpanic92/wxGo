
%go_import("reflect")
%go_import("runtime")

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
	return Swigcptr##WXTYPE##(a.(SwigcptrInterface).Swigcptr())
}
}
%enddef

%define WXGO_GETTER_TO_VAR(WXTYPE, WXVARNAME)
%insert(go_wrapper) {
var WXVARNAME WXTYPE = Get##WXVARNAME()
}
%enddef

%rename(Assign) operator=;
%rename(Equals) operator==; 
%rename(NotEquals) operator!=; 
%rename(Not) operator!;
%rename(At) operator[]; 
%rename(Add) operator+; 
%rename(Minus) operator-;
%rename(AddAssign) operator+=; 
%rename(MinusAssign) operator-=;


%feature("notabstract") wxGUIEventLoop;

%feature("notabstract") wxDataObjectComposite;
%feature("notabstract") wxDataObjectSimple;
%feature("notabstract") wxCustomDataObject;
%feature("notabstract") wxBitmapDataObject;
%feature("notabstract") wxTextDataObject;
%feature("notabstract") wxURLDataObject;
%feature("notabstract") wxFileDataObject;
%feature("notabstract") wxHTMLDataObject;

%feature("notabstract") wxDataViewTextRenderer;
%feature("notabstract") wxDataViewIconTextRenderer;
%feature("notabstract") wxDataViewSpinRenderer;
%feature("notabstract") wxDataViewToggleRenderer;
%feature("notabstract") wxDataViewChoiceRenderer;
%feature("notabstract") wxDataViewChoiceByIndexRenderer;
%feature("notabstract") wxDataViewDateRenderer;
%feature("notabstract") wxDataViewBitmapRenderer;
%feature("notabstract") wxDataViewListCtrl;
%feature("notabstract") wxDataViewListStore;
%feature("notabstract") wxDataViewTreeStore;

%feature("notabstract") wxGridCellStringRenderer;
%feature("notabstract") wxGridCellAutoWrapStringRenderer;
%feature("notabstract") wxGridCellBoolRenderer;
%feature("notabstract") wxGridCellDateTimeRenderer;
%feature("notabstract") wxGridCellEnumRenderer;
%feature("notabstract") wxGridCellFloatRenderer;
%feature("notabstract") wxGridCellNumberRenderer;
%feature("notabstract") wxGridCellTextEditor;
%feature("notabstract") wxGridCellAutoWrapStringEditor;
%feature("notabstract") wxGridCellBoolEditor;
%feature("notabstract") wxGridCellChoiceEditor;
%feature("notabstract") wxGridCellEnumEditor;
%feature("notabstract") wxGridCellFloatEditor;
%feature("notabstract") wxGridCellNumberEditor;

%feature("notabstract") wxFilePickerCtrl;
%feature("notabstract") wxDirPickerCtrl;
%feature("notabstract") wxFontPickerCtrl;
%feature("notabstract") wxColourPickerCtrl;

%feature("notabstract") wxHeaderCtrlSimple;
%feature("notabstract") wxHelpController;
%feature("notabstract") wxHtmlTagsModule;
%feature("notabstract") wxSimpleHtmlListBox;

%feature("notabstract") wxChoicebook;
%feature("notabstract") wxListbook;
%feature("notabstract") wxSimplebook;
%feature("notabstract") wxToolbook;
%feature("notabstract") wxTreebook;
%feature("notabstract") wxWizardPageSimple;
%feature("notabstract") wxAuiNotebook;

%feature("notabstract") wxRichTextBufferDataObject;
%feature("notabstract") wxRichTextHTMLHandler;
%feature("notabstract") wxRichTextStyleListBox;

%nodefaultctor wxTextEntry;

%nodefaultdtor wxVariantData;

%{
	#include "wx/defs.h"
%}

%include "wxGoInterface/defs.h"

