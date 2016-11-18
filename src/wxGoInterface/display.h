WXGO_DECL_TYPECONV(Display)
class wxDisplay
{
public:
    wxDisplay(unsigned int index = 0);
    ~wxDisplay();
    bool ChangeMode(const wxVideoMode& mode = wxDefaultVideoMode);
    wxRect GetClientArea() const;
    static unsigned int GetCount();
    wxVideoMode GetCurrentMode() const;
    static int GetFromPoint(const wxPoint& pt);
    static int GetFromWindow(const wxWindow* win);
    wxRect GetGeometry() const;
    wxArrayVideoModes GetModes(const wxVideoMode& mode = wxDefaultVideoMode) const;
    wxString GetName() const;
    bool IsPrimary() const;
};