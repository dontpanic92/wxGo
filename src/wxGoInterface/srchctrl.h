WXGO_DECL_TYPECONV(SearchCtrl)
class wxSearchCtrl : public wxTextCtrl
{
public:
    wxSearchCtrl();
    wxSearchCtrl(wxWindow* parent, wxWindowID id,
                 const wxString& value = wxEmptyString,
                 const wxPoint& pos = wxDefaultPosition,
                 const wxSize& size = wxDefaultSize,
                 long style = 0,
                 const wxValidator& validator = wxDefaultValidator,
                 const wxString& name = wxSearchCtrlNameStr);
    virtual ~wxSearchCtrl();
    bool Create(wxWindow* parent, wxWindowID id,
                 const wxString& value = wxEmptyString,
                 const wxPoint& pos = wxDefaultPosition,
                 const wxSize& size = wxDefaultSize,
                 long style = 0,
                 const wxValidator& validator = wxDefaultValidator,
                 const wxString& name = wxSearchCtrlNameStr);
    virtual wxMenu* GetMenu();
    virtual bool IsSearchButtonVisible() const;
    virtual bool IsCancelButtonVisible() const;
    virtual void SetMenu(wxMenu* menu);
    virtual void ShowCancelButton(bool show);
    virtual void ShowSearchButton(bool show);
    void        SetDescriptiveText(const wxString& text);
    wxString    GetDescriptiveText() const;
};
%constant wxEventType  wxEVT_SEARCHCTRL_CANCEL_BTN;
%constant wxEventType  wxEVT_SEARCHCTRL_SEARCH_BTN;