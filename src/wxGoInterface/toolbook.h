#define wxTBK_BUTTONBAR            0x0100
#define wxTBK_HORZ_LAYOUT          0x8000
%constant wxEventType wxEVT_TOOLBOOK_PAGE_CHANGED;
%constant wxEventType wxEVT_TOOLBOOK_PAGE_CHANGING;
WXGO_DECL_TYPECONV(Toolbook)
class wxToolbook : public wxBookCtrlBase
{
public:
    wxToolbook();
    wxToolbook(wxWindow* parent, wxWindowID id,
                 const wxPoint& pos = wxDefaultPosition,
                 const wxSize& size = wxDefaultSize,
                 long style = 0,
                 const wxString& name = wxEmptyString);
    bool Create(wxWindow *parent,
                wxWindowID id,
                const wxPoint& pos = wxDefaultPosition,
                const wxSize& size = wxDefaultSize,
                long style = 0,
                const wxString& name = wxEmptyString);
    wxToolBarBase* GetToolBar() const;
};