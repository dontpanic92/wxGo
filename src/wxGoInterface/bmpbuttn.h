WXGO_DECL_TYPECONV(BitmapButton)
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