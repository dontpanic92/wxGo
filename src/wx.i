%module(directors="1") wx

%rename("%(strip:[wx])s") "";

%{
	#include "wx/wx.h"
%}

%include wxString.i
%include typemap.i

%include typedef.i
%include define.i


%include wxObject.i
%include wxApp.i
%include wxEvent.i
%include wxWindow.i
%include wxCtrlSub.i
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
%include wxColourDlg.i
%include wxFont.i
%include wxFontDlg.i
%include wxFileDlg.i
%include wxAboutDlg.i
%include wxTextCtrl.i
%include wxPanel.i
%include wxNoteBook.i
%include wxAnyButton.i
%include wxButton.i
%include wxTaskBar.i
%include wxToolBar.i
%include wxBitmap.i
%include wxStatic.i
%include wxListBox.i
%include wxSlider.i
%include wxGauge.i
%include wxScrollbar.i
%include wxSpin.i

%include wxAui.i