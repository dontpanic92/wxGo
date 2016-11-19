%constant wxEventType wxEVT_TOGGLEBUTTON;
WXGO_DECL_TYPECONV(ToggleButton)
class wxToggleButton : public wxAnyButton
{
public:
    wxToggleButton();
    wxToggleButton(wxWindow* parent, wxWindowID id,
                   const wxString& label,
                   const wxPoint& pos = wxDefaultPosition,
                   const wxSize& size = wxDefaultSize,
                   long style = 0,
                   const wxValidator& val = wxDefaultValidator,
                   const wxString& name = wxCheckBoxNameStr);
    virtual ~wxToggleButton();
    bool Create(wxWindow* parent, wxWindowID id,
                const wxString& label,
                const wxPoint& pos = wxDefaultPosition,
                const wxSize& size = wxDefaultSize,
                long style = 0,
                const wxValidator& val = wxDefaultValidator,
                const wxString& name = wxCheckBoxNameStr);
    virtual bool GetValue() const;
    virtual void SetValue(bool state);
};
WXGO_DECL_TYPECONV(BitmapToggleButton)
class wxBitmapToggleButton : public wxToggleButton
{
public:
    wxBitmapToggleButton();
    wxBitmapToggleButton(wxWindow* parent, wxWindowID id,
                         const wxBitmap& label,
                         const wxPoint& pos = wxDefaultPosition,
                         const wxSize& size = wxDefaultSize,
                         long style = 0,
                         const wxValidator& val = wxDefaultValidator,
                         const wxString& name = wxCheckBoxNameStr);
    bool Create(wxWindow* parent, wxWindowID id,
                const wxBitmap& label,
                const wxPoint& pos = wxDefaultPosition,
                const wxSize& size = wxDefaultSize,
                long style = 0,
                const wxValidator& val = wxDefaultValidator,
                const wxString& name = wxCheckBoxNameStr);
    virtual bool GetValue() const;
    virtual void SetValue(bool state);
};