
%{
	#include "wx/wx.h"
%}

%include "wxGoInterface/window.h"


//From JeroenD
%insert(go_wrapper) %{
	func GetNullWindow() Window {
        return SwigcptrWindow(0)
	}
%}
