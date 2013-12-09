
%{
	#include "wx/wx.h"
%}

%include "wxGoInterface/window.h"

%insert(go_wrapper) %{
	var NullWindow Window = SwigcptrWindow(0)
%}

