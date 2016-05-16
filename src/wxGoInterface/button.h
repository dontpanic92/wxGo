class wxButton : public wxAnyButton
{
public:
    wxButton();
    wxButton(wxWindow* parent, wxWindowID id,
             const wxString& label = wxEmptyString,
             const wxPoint& pos = wxDefaultPosition,
             const wxSize& size = wxDefaultSize,
             long style = 0,
             const wxValidator& validator = wxDefaultValidator,
             const wxString& name = wxButtonNameStr);
    bool Create(wxWindow* parent, wxWindowID id,
                const wxString& label = wxEmptyString,
                const wxPoint& pos = wxDefaultPosition,
                const wxSize& size = wxDefaultSize,
                long style = 0,
                const wxValidator& validator = wxDefaultValidator,
                const wxString& name = wxButtonNameStr);
    bool GetAuthNeeded() const;
    static wxSize GetDefaultSize();
    wxString GetLabel() const;
    void SetAuthNeeded(bool needed = true);
    virtual wxWindow* SetDefault();
    void SetLabel(const wxString& label);
};
class wxBitmapButton : public wxButton
{
public:
    wxBitmapButton();
    wxBitmapButton(wxWindow* parent, wxWindowID id,
                   const wxBitmap& bitmap,
                   const wxPoint& pos = wxDefaultPosition,
                   const wxSize& size = wxDefaultSize,
                   long style = wxBU_AUTODRAW,
                   const wxValidator& validator = wxDefaultValidator,
                   const wxString& name = wxButtonNameStr);
    bool Create(wxWindow* parent, wxWindowID id,
                const wxBitmap& bitmap,
                const wxPoint& pos = wxDefaultPosition,
                const wxSize& size = wxDefaultSize,
                long style = wxBU_AUTODRAW,
                const wxValidator& validator = wxDefaultValidator,
                const wxString& name = wxButtonNameStr);
    static wxBitmapButton* NewCloseButton(wxWindow* parent, wxWindowID winid);
};