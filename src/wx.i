%module(directors="1") wx

%rename("%(strip:[wx])s") "";

%{
	#include "wx/wx.h"
%}

%include wxString.i
%import typemap.i

%include typedef.i

%include wxObject.i
%include wxApp.i
%include wxEvent.i
%include wxWindow.i
%include wxControl.i
%include wxTopLevelWindow.i
%include wxFrame.i
%include wxSizer.i
%include wxMenu.i
%include wxStatusBar.i
%include wxDialog.i
%include wxMsgDlg.i
%include gdicmn.i
%include wxColour.i
%include wxFont.i
%include wxTextCtrl.i
%include wxPanel.i
%include wxNoteBook.i
