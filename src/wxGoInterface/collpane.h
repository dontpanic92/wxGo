#define wxCP_DEFAULT_STYLE          (wxTAB_TRAVERSAL | wxNO_BORDER)
#define wxCP_NO_TLW_RESIZE          (0x0002)
WXGO_DECL_TYPECONV(CollapsiblePaneEvent)
class wxCollapsiblePaneEvent : public wxCommandEvent
{
public:
    wxCollapsiblePaneEvent(wxObject* generator, int id, bool collapsed);
    bool GetCollapsed() const;
    void SetCollapsed(bool collapsed);
};
%constant wxEventType wxEVT_COLLAPSIBLEPANE_CHANGED;
WXGO_DECL_TYPECONV(CollapsiblePane)
class wxCollapsiblePane : public wxControl
{
public:
    wxCollapsiblePane();
    wxCollapsiblePane(wxWindow* parent, wxWindowID id,
                      const wxString& label,
                      const wxPoint& pos = wxDefaultPosition,
                      const wxSize& size = wxDefaultSize,
                      long style = wxCP_DEFAULT_STYLE,
                      const wxValidator& validator = wxDefaultValidator,
                      const wxString& name = wxCollapsiblePaneNameStr);
    bool Create(wxWindow* parent, wxWindowID id,
                const wxString& label,
                const wxPoint& pos = wxDefaultPosition,
                const wxSize& size = wxDefaultSize,
                long style = wxCP_DEFAULT_STYLE,
                const wxValidator& validator = wxDefaultValidator,
                const wxString& name = wxCollapsiblePaneNameStr);
    virtual void Collapse(bool collapse = true);
    void Expand();
    virtual wxWindow* GetPane() const;
    virtual bool IsCollapsed() const;
    bool IsExpanded() const;
};