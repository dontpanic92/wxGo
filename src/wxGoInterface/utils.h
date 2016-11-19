WXGO_DECL_TYPECONV(WindowDisabler)
class wxWindowDisabler
{
public:
    wxWindowDisabler(bool disable = true);
    wxWindowDisabler(wxWindow* winToSkip);
    ~wxWindowDisabler();
};
WXGO_DECL_TYPECONV(BusyCursor)
class wxBusyCursor
{
public:
    wxBusyCursor(const wxCursor* cursor = wxHOURGLASS_CURSOR);
    ~wxBusyCursor();
};
void wxBeginBusyCursor(const wxCursor* cursor = wxHOURGLASS_CURSOR);
void wxEndBusyCursor();
bool wxIsBusy();
void wxBell();
void wxInfoMessageBox(wxWindow* parent);
wxVersionInfo wxGetLibraryVersionInfo();
bool wxGetKeyState(wxKeyCode key);
wxPoint wxGetMousePosition();
wxMouseState wxGetMouseState();
void wxEnableTopLevelWindows(bool enable = true);
wxWindow* wxFindWindowAtPoint(const wxPoint& pt);
wxWindow* wxFindWindowByLabel(const wxString& label,
                              wxWindow* parent = NULL);
wxWindow* wxFindWindowByName(const wxString& name, wxWindow* parent = NULL);
int wxFindMenuItemId(wxFrame* frame, const wxString& menuString,
                     const wxString& itemString);
void wxRegisterId(int id);
bool wxLaunchDefaultApplication(const wxString& document, int flags = 0);
bool wxLaunchDefaultBrowser(const wxString& url, int flags = 0);
#define wxStrip_Mnemonics  1
#define wxStrip_Accel  2
#define wxStrip_All  wxStrip_Mnemonics | wxStrip_Accel
wxString wxStripMenuCodes(const wxString& str, int flags = wxStrip_All);