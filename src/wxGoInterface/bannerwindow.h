WXGO_DECL_TYPECONV(BannerWindow)
class wxBannerWindow : public wxWindow
{
public:
    wxBannerWindow();
    wxBannerWindow(wxWindow* parent, wxDirection dir = wxLEFT);
    wxBannerWindow(wxWindow* parent,
                   wxWindowID winid,
                   wxDirection dir = wxLEFT,
                   const wxPoint& pos = wxDefaultPosition,
                   const wxSize& size = wxDefaultSize,
                   long style = 0,
                   const wxString& name = wxBannerWindowNameStr);
    bool Create(wxWindow* parent,
                wxWindowID winid,
                wxDirection dir = wxLEFT,
                const wxPoint& pos = wxDefaultPosition,
                const wxSize& size = wxDefaultSize,
                long style = 0,
                const wxString& name = wxBannerWindowNameStr);
    void SetBitmap(const wxBitmap& bmp);
    void SetText(const wxString& title, const wxString& message);
    void SetGradient(const wxColour& start, const wxColour& end);
};