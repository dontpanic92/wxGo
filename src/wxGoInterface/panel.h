WXGO_DECL_TYPECONV(Panel)
class wxPanel : public wxWindow
{
public:
    wxPanel();
    wxPanel(wxWindow* parent, wxWindowID id = wxID_ANY,
            const wxPoint& pos = wxDefaultPosition,
            const wxSize& size = wxDefaultSize,
            long style = wxTAB_TRAVERSAL,
            const wxString& name = wxPanelNameStr);
    virtual ~wxPanel();
    bool AcceptsFocus() const;
    bool Create(wxWindow* parent, wxWindowID id = wxID_ANY,
                const wxPoint& pos = wxDefaultPosition,
                const wxSize& size = wxDefaultSize,
                long style = wxTAB_TRAVERSAL,
                const wxString& name = wxPanelNameStr);
    virtual void InitDialog();
    virtual bool Layout();
    void OnSysColourChanged(wxSysColourChangedEvent& event);
    virtual void SetFocus();
    void SetFocusIgnoringChildren();
};