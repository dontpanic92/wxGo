
%{
	#include "wx/wx.h"
	#include "wx/gtk/frame.h"
%}

%include "wxGoInterface/frame.h"

#define wxFRAME_NO_TASKBAR      0x0002
#define wxFRAME_TOOL_WINDOW     0x0004
#define wxFRAME_FLOAT_ON_PARENT 0x0008

