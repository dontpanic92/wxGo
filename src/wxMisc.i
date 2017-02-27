
%{
    #include "wx/cmdproc.h"
    #include "wx/module.h"
	#include "wx/filename.h"
    #include "wx/textcompleter.h"
    #include "wx/tooltip.h"
    #include "wx/richtooltip.h"
    #include "wx/dataobj.h"
    #include "wx/caret.h"
    #include "wx/accel.h"
    #include "wx/dnd.h"
    #include "wx/appprogress.h"
    #include "wx/clipbrd.h"
    #include "wx/cmndata.h"
    #include "wx/help.h"
    #include "wx/cshelp.h"
	#include "wx/taskbar.h"
	#include "wx/joystick.h"
	#include "wx/notifmsg.h"
	#include "wx/position.h"
	#include "wx/preferences.h"
	#include "wx/tipdlg.h"
	#include "wx/uiaction.h"
	#include "wx/utils.h"
	#include "wx/variant.h"
	#include "wx/versioninfo.h"
	#include "wx/wupdlock.h"
%}

%include "wxGoInterface/cmdproc.h"
%include "wxGoInterface/module.h"
%include "wxGoInterface/filename.h"
%include "wxGoInterface/textcompleter.h"
%include "wxGoInterface/tooltip.h"
%include "wxGoInterface/richtooltip.h"
%include "wxGoInterface/dataobj.h"
%include "wxGoInterface/caret.h"
%include "wxGoInterface/accel.h"
%include "wxGoInterface/dnd.h"
#if defined(__WXMSW__) || defined (__WXOSX__)
%include "wxGoInterface/appprogress.h"
#endif
%include "wxGoInterface/clipbrd.h"
%include "wxGoInterface/cmndata.h"
%include "wxGoInterface/help.h"
%include "wxGoInterface/cshelp.h"
%include "wxGoInterface/taskbar.h"
%include "wxGoInterface/joystick.h"
%include "wxGoInterface/notifmsg.h"
%include "wxGoInterface/position.h"
%include "wxGoInterface/preferences.h"
%include "wxGoInterface/tipdlg.h"
%include "wxGoInterface/uiaction.h"
%include "wxGoInterface/utils.h"
%include "wxGoInterface/variant.h"
%include "wxGoInterface/versioninfo.h"
%include "wxGoInterface/wupdlock.h"

WXGO_DECL_TYPECONV(VariantClientData)
%inline {
    class wxVariantClientData : public wxClientData, public wxVariant {
    public:
        wxVariantClientData(const wxVariant& variant) : wxVariant(variant) {}

        wxVariantClientData(const wxString& value) : wxVariant(value) {}

        wxVariantClientData(wxChar value) : wxVariant(value) {}

        wxVariantClientData(long value) : wxVariant(value) {}

        wxVariantClientData(bool value) : wxVariant(value) {}

        wxVariantClientData(double value) : wxVariant(value) {}

        wxVariantClientData(wxLongLong value) : wxVariant(value) {}

        wxVariantClientData(wxULongLong value) : wxVariant(value) {}

        wxVariantClientData(const wxVariantList& value) : wxVariant(value) {}

        wxVariantClientData(void* value) : wxVariant(value) {}

        wxVariantClientData(wxObject* value) : wxVariant(value) {}

        wxVariantClientData(const wxDateTime& value) : wxVariant(value) {}

        wxVariantClientData(const wxArrayString& value) : wxVariant(value) {}
    };
}

WXGO_DECL_TYPECONV(VariantTreeItemData)
%inline {
    class wxVariantTreeItemData : public wxTreeItemData, public wxVariant {
    public:
        wxVariantTreeItemData(const wxVariant& variant) : wxVariant(variant) {}

        wxVariantTreeItemData(const wxString& value) : wxVariant(value) {}

        wxVariantTreeItemData(wxChar value) : wxVariant(value) {}

        wxVariantTreeItemData(long value) : wxVariant(value) {}

        wxVariantTreeItemData(bool value) : wxVariant(value) {}

        wxVariantTreeItemData(double value) : wxVariant(value) {}

        wxVariantTreeItemData(wxLongLong value) : wxVariant(value) {}

        wxVariantTreeItemData(wxULongLong value) : wxVariant(value) {}

        wxVariantTreeItemData(const wxVariantList& value) : wxVariant(value) {}

        wxVariantTreeItemData(void* value) : wxVariant(value) {}

        wxVariantTreeItemData(wxObject* value) : wxVariant(value) {}

        wxVariantTreeItemData(const wxDateTime& value) : wxVariant(value) {}

        wxVariantTreeItemData(const wxArrayString& value) : wxVariant(value) {}
    };
}
