// Typemap for xpmData
%typemap(gotype) (const char* const* xpmData), (const char* const* bits) "[]string"
%typemap(imtype) (const char* const* xpmData), (const char* const* bits) "uint64"

%typemap(in) (const char* const* xpmData), (const char* const* bits) %{
	wxArrayString $1_arrstr = gostringSliceToArrayString(*(_goslice_*)$input);
	size_t count = $1_arrstr.GetCount();
	wxVector<wxCharBuffer> charBuffers(count);
	$1 = new char*[count];
	for (size_t i = 0; i < count; i++)
	{
		charBuffers[i] = $1_arrstr[i].mb_str();
		$1[i] = charBuffers[i].data();
	}
%}

%typemap(argout) (const char* const* xpmData), (const char* const* bits) %{
	delete[] $1;
%}

%typemap(goin) (const char* const* xpmData), (const char* const* bits)  %{
    $result = uint64((uintptr)(unsafe.Pointer(&$1)))
%}

// Typemap for []byte

%typemap(gotype) (const char bits[]), (const char maskBits[]) "[]byte"
%typemap(in) (const char bits[]), (const char maskBits[]) %{
	$1 = $input.p;
%}

%typemap(gotype) (const void* data, size_t size) "[]byte"
%typemap(in) (const void* data, size_t size) %{
	$1 = $input.array;
	$2 = $input.len;
%}



%{
	#include "wx/gdicmn.h"
	#include "wx/gdiobj.h"
	#include "wx/graphics.h"
	#include "wx/cursor.h"
	#include "wx/region.h"
	#include "wx/palette.h"
	#include "wx/pen.h"
	#include "wx/brush.h"
	#include "wx/image.h"
	#include "wx/imaglist.h"
	#include "wx/icon.h"
	#include "wx/iconloc.h"
	#include "wx/iconbndl.h"
	#include "wx/font.h"
	#include "wx/fontutil.h"
	#include "wx/fontenum.h"
	#include "wx/withimages.h"
%}

%include "wxGoInterface/gdicmn.h"
%include "wxGoInterface/gdiobj.h"
%include "wxGoInterface/graphics.h"
%include "wxGoInterface/cursor.h"
%include "wxGoInterface/region.h"
%include "wxGoInterface/palette.h"
%include "wxGoInterface/pen.h"
%include "wxGoInterface/brush.h"
%include "wxGoInterface/image.h"
%include "wxGoInterface/imaglist.h"
%include "wxGoInterface/icon.h"
%include "wxGoInterface/iconloc.h"
%include "wxGoInterface/iconbndl.h"
%include "wxGoInterface/font.h"
%include "wxGoInterface/fontutil.h"
%include "wxGoInterface/fontenum.h"
%include "wxGoInterface/withimages.h"


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
