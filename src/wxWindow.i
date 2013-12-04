
%{
	#include "wx/wx.h"
%}

%include "wxGoInterface/window.h"


//From JeroenD
%insert(go_wrapper) %{
	func NullWindow() Window {
        return SwigcptrWindow(0)
	}
%}
