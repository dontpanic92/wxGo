%module(directors="1") wx

%rename("%(strip:[wx])s") "";

%{
	//#incldue "wx/setup.h"
	#include "wx/wx.h"
%}

//%include wxString.i
%include typemap.i
%include define.i

%include wxObject.i
%include wxApp.i
%include wxEvent.i
%include wxWindow.i
%include wxGDI.i
%include wxDC.i
%include wxManagedWnd.i
%include wxControl.i
%include wxMiscWnd.i
%include wxDocView.i
%include wxSizer.i
%include wxBookCtrl.i
%include wxMenu.i
%include wxColour.i
%include wxDialogs.i
%include wxBitmap.i
%include wxStatic.i
%include wxSlider.i
%include wxSpin.i
%include wxClientData.i
%include wxTree.i
%include wxGrid.i
%include wxPickers.i
%include wxCalendar.i
%include wxValidator.i
%include wxArt.i
%include wxConfig.i
%include wxMisc.i
%include wxWebView.i

%include wxAui.i
%include wxSTC.i
%include wxRibbon.i
%include wxHTML.i
%include wxRichText.i
%include wxPropGrid.i
%include wxXml.i
%include wxXrc.i
