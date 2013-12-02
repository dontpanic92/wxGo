%rename(String) wxString;
%{
	#include "wx/wx.h"
	#include "wx/string.h"
%}

%include "wxGoInterface/string.h"
