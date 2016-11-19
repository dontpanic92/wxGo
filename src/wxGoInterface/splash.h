#define wxSPLASH_CENTRE_ON_PARENT   0x01
#define wxSPLASH_CENTRE_ON_SCREEN   0x02
#define wxSPLASH_NO_CENTRE          0x00
#define wxSPLASH_TIMEOUT            0x04
#define wxSPLASH_NO_TIMEOUT         0x00
WXGO_DECL_TYPECONV(SplashScreen)
class wxSplashScreen : public wxFrame
{
public:
    wxSplashScreen(const wxBitmap& bitmap, long splashStyle,
                   int milliseconds,
                   wxWindow* parent,
                   wxWindowID id,
                   const wxPoint& pos = wxDefaultPosition,
                   const wxSize& size = wxDefaultSize,
                   long style = wxBORDER_SIMPLE|wxFRAME_NO_TASKBAR|wxSTAY_ON_TOP);
    virtual ~wxSplashScreen();
    long GetSplashStyle() const;
    wxSplashScreenWindow* GetSplashWindow() const;
    int GetTimeout() const;
    void OnCloseWindow(wxCloseEvent& event);
};