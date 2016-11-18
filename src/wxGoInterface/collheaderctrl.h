WXGO_DECL_TYPECONV(CollapsibleHeaderCtrl)
class wxCollapsibleHeaderCtrl : public wxControl
{
public:
    wxCollapsibleHeaderCtrl() { }
    wxCollapsibleHeaderCtrl(wxWindow *parent,
        wxWindowID id,
        const wxString& label,
        const wxPoint& pos = wxDefaultPosition,
        const wxSize& size = wxDefaultSize,
        long style = wxBORDER_NONE,
        const wxValidator& validator = wxDefaultValidator,
        const wxString& name = wxCollapsibleHeaderCtrlNameStr);
    bool Create(wxWindow *parent,
        wxWindowID id,
        const wxString& label,
        const wxPoint& pos = wxDefaultPosition,
        const wxSize& size = wxDefaultSize,
        long style = wxBORDER_NONE,
        const wxValidator& validator = wxDefaultValidator,
        const wxString& name = wxCollapsibleHeaderCtrlNameStr);
    virtual void SetCollapsed(bool collapsed = true);
    virtual bool IsCollapsed() const;
};