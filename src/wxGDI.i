
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
	#include "wx/icon.h"
%}

%include "wxGoInterface/gdicmn.h"
%include "wxGoInterface/gdiobj.h"
#ifndef __WXMSW__ 
// In Windows wxWidgets doesn't support graphics context
// by default if we are not using MSVC. 
%include "wxGoInterface/graphics.h"
#endif
%include "wxGoInterface/cursor.h"
%include "wxGoInterface/region.h"
%include "wxGoInterface/palette.h"
%include "wxGoInterface/pen.h"
%include "wxGoInterface/brush.h"
%include "wxGoInterface/image.h"
%include "wxGoInterface/icon.h"
