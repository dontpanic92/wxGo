%import "wxGdiobj.i"
%include "wxGoInterface/font.h"

WXGO_DECL_TYPECONV(Font)

%inline {
	const wxFont* GetNORMAL_FONT(){
		return wxNORMAL_FONT;
	}
	const wxFont* GetSMALL_FONT(){
		return wxSMALL_FONT;
	}
	const wxFont* GetITALIC_FONT(){
		return wxITALIC_FONT;
	}
	const wxFont* GetSWISS_FONT(){
		return wxSWISS_FONT;
	}
}

/*
 * Crash Here.
 * Perhaps the reason is that when we call 
 *            wxStockGDI::instance().GetFont(wxStockGDI::FONT_NORMAL) 
 * the wxStockGDI object isn't initialized yet.
 * However to get the other GDI Objects we use static member functions,
 * so we won't face this problem in other places.
 *
 
%insert(go_wrapper){
var NORMAL_FONT Font = GetNORMAL_FONT()
var SMALL_FONT Font = GetSMALL_FONT()
var ITALIC_FONT Font = GetITALIC_FONT()
var SWISS_FONT Font = GetSWISS_FONT()
}

*/
