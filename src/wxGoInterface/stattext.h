#define wxST_NO_AUTORESIZE         0x0001
#define wxST_ELLIPSIZE_START       0x0004
#define wxST_ELLIPSIZE_MIDDLE      0x0008
#define wxST_ELLIPSIZE_END         0x0010
WXGO_DECL_TYPECONV(StaticText)
class wxStaticText : public wxControl
{
public:
    wxStaticText();
    wxStaticText(wxWindow* parent, wxWindowID id,
                 const wxString& label,
                 const wxPoint& pos = wxDefaultPosition,
                 const wxSize& size = wxDefaultSize,
                 long style = 0,
                 const wxString& name = wxStaticTextNameStr);
    bool Create(wxWindow* parent, wxWindowID id, const wxString& label,
                const wxPoint& pos = wxDefaultPosition,
                const wxSize& size = wxDefaultSize, long style = 0,
                const wxString& name = wxStaticTextNameStr);
    bool IsEllipsized() const;
    void Wrap(int width);
};