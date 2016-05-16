class wxStaticLine : public wxControl
{
public:
    wxStaticLine();
    wxStaticLine(wxWindow* parent, wxWindowID id = wxID_ANY,
                 const wxPoint& pos = wxDefaultPosition,
                 const wxSize& size = wxDefaultSize,
                 long style = wxLI_HORIZONTAL,
                 const wxString& name = wxStaticLineNameStr);
    bool Create(wxWindow* parent, wxWindowID id = wxID_ANY,
                const wxPoint& pos = wxDefaultPosition,
                const wxSize& size = wxDefaultSize, long style = wxLI_HORIZONTAL,
                const wxString& name = wxStaticLineNameStr);
    static int GetDefaultSize();
    bool IsVertical() const;
};