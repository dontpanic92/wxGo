WXGO_DECL_TYPECONV(RibbonPanelEvent)
class wxRibbonPanelEvent : public wxCommandEvent
{
public:
    wxRibbonPanelEvent(wxEventType command_type = wxEVT_NULL,
                       int win_id = 0,
                       wxRibbonPanel* panel = NULL);
    wxRibbonPanel* GetPanel();
    void SetPanel(wxRibbonPanel* page);
};
WXGO_DECL_TYPECONV(RibbonPanel)
class wxRibbonPanel : public wxRibbonControl
{
public:
    wxRibbonPanel();
    wxRibbonPanel(wxWindow* parent,
                  wxWindowID id = wxID_ANY,
                  const wxString& label = wxEmptyString,
                  const wxBitmap& minimised_icon = wxNullBitmap,
                  const wxPoint& pos = wxDefaultPosition,
                  const wxSize& size = wxDefaultSize,
                  long style = wxRIBBON_PANEL_DEFAULT_STYLE);
    bool Create(wxWindow* parent,
                wxWindowID id = wxID_ANY,
                const wxString& label = wxEmptyString,
                const wxBitmap& icon = wxNullBitmap,
                const wxPoint& pos = wxDefaultPosition,
                const wxSize& size = wxDefaultSize,
                long style = wxRIBBON_PANEL_DEFAULT_STYLE);
    virtual ~wxRibbonPanel();
    wxBitmap& GetMinimisedIcon();
    virtual bool HasExtButton() const;
    bool IsMinimised() const;
    bool IsMinimised(wxSize at_size) const;
    bool IsHovered() const;
    bool IsExtButtonHovered() const;
    bool CanAutoMinimise() const;
    bool ShowExpanded();
    bool HideExpanded();
    void SetArtProvider(wxRibbonArtProvider* art);
    bool Realize();
    wxRibbonPanel* GetExpandedDummy();
    wxRibbonPanel* GetExpandedPanel();
};