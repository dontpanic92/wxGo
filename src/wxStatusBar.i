%rename(StatusBar) wxStatusBar;
%rename(StatusBarPan) wxStatusBarPane;

%{
	#include "wx/wx.h"
	#include "wx/statusbr.h"
%}

%include "wxGoInterface/statusbr.h"

