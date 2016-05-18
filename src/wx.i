%module(directors="1") wx

%rename("%(strip:[wx])s") "";

%{
	#include "wx/wx.h"
%}

//%include wxString.i
%include typemap.i
%include define.i

%include defs.i
%include wxObject.i
%include wxApp.i
%include wxEvent.i
%include wxWindow.i
%include wxCtrlSub.i
%include wxControl.i
%include wxTopLevelWindow.i
%include wxFrame.i
%include wxSizer.i
%include wxBookCtrl.i
%include wxMenu.i
%include wxStatusBar.i
%include wxDialog.i
%include gdicmn.i
%include wxColour.i
%include wxFont.i
%include wxDialogs.i
%include wxTextCtrl.i
%include wxPanel.i
%include wxNoteBook.i
%include wxAnyButton.i
%include wxButton.i
%include wxTaskBar.i
%include wxToolBar.i
%include wxBitmap.i
%include wxStatic.i
%include wxList.i
%include wxSlider.i
%include wxGauge.i
%include wxScroll.i
%include wxSpin.i
%include wxClientData.i
%include wxTree.i
%include wxSplitter.i
%include wxPickers.i

%include wxAui.i