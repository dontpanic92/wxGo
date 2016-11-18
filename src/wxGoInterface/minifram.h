WXGO_DECL_TYPECONV(MiniFrame)
class wxMiniFrame : public wxFrame
{
public:
    wxMiniFrame();
    wxMiniFrame(wxWindow* parent, wxWindowID id,
                const wxString& title,
                const wxPoint& pos = wxDefaultPosition,
                const wxSize& size = wxDefaultSize,
                long style = wxCAPTION | wxRESIZE_BORDER,
                const wxString& name = wxFrameNameStr);
    virtual ~wxMiniFrame();
    bool Create(wxWindow* parent, wxWindowID id, const wxString& title,
                const wxPoint& pos = wxDefaultPosition,
                const wxSize& size = wxDefaultSize,
                long style = wxCAPTION | wxRESIZE_BORDER,
                const wxString& name = wxFrameNameStr);
};