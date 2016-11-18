WXGO_DECL_TYPECONV(BusyInfo)
WXGO_DECL_TYPECONV(BusyInfoFlags)
class wxBusyInfo
{
public:
    wxBusyInfo(const wxBusyInfoFlags& flags);
    wxBusyInfo(const wxString& msg, wxWindow* parent = NULL);
    virtual ~wxBusyInfo();
};
class wxBusyInfoFlags
{
public:
    wxBusyInfoFlags();
    wxBusyInfoFlags& Parent(wxWindow* parent);
    wxBusyInfoFlags& Icon(const wxIcon& icon);
    wxBusyInfoFlags& Title(const wxString& title);
    wxBusyInfoFlags& Text(const wxString& text);
    wxBusyInfoFlags& Label(const wxString& label);
    wxBusyInfoFlags& Foreground(const wxColour& foreground);
    wxBusyInfoFlags& Background(const wxColour& background);
    wxBusyInfoFlags& Transparency(wxByte alpha);
};