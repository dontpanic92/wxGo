enum
{
    wxUSER_ATTENTION_INFO = 1,  
    wxUSER_ATTENTION_ERROR = 2  
};
enum
{
    wxFULLSCREEN_NOMENUBAR   = 0x0001,  
    wxFULLSCREEN_NOTOOLBAR   = 0x0002,  
    wxFULLSCREEN_NOSTATUSBAR = 0x0004,  
    wxFULLSCREEN_NOBORDER    = 0x0008,  
    wxFULLSCREEN_NOCAPTION   = 0x0010,  
    wxFULLSCREEN_ALL    = wxFULLSCREEN_NOMENUBAR | wxFULLSCREEN_NOTOOLBAR |
                          wxFULLSCREEN_NOSTATUSBAR | wxFULLSCREEN_NOBORDER |
                          wxFULLSCREEN_NOCAPTION
};
#define wxDEFAULT_FRAME_STYLE (wxSYSTEM_MENU |          \
                               wxRESIZE_BORDER |        \
                               wxMINIMIZE_BOX |         \
                               wxMAXIMIZE_BOX |         \
                               wxCLOSE_BOX |            \
                               wxCAPTION |              \
                               wxCLIP_CHILDREN)
WXGO_DECL_TYPECONV(TopLevelWindow)
class wxTopLevelWindow : public wxNonOwnedWindow
{
public:
    wxTopLevelWindow();
    wxTopLevelWindow(wxWindow *parent,
                    wxWindowID id,
                    const wxString& title,
                    const wxPoint& pos = wxDefaultPosition,
                    const wxSize& size = wxDefaultSize,
                    long style = wxDEFAULT_FRAME_STYLE,
                    const wxString& name = wxFrameNameStr);
    virtual ~wxTopLevelWindow();
    bool Create(wxWindow *parent,
                wxWindowID id,
                const wxString& title,
                const wxPoint& pos = wxDefaultPosition,
                const wxSize& size = wxDefaultSize,
                long style = wxDEFAULT_FRAME_STYLE,
                const wxString& name = wxFrameNameStr);
    virtual bool CanSetTransparent();
    void CenterOnScreen(int direction = wxBOTH);
    void CentreOnScreen(int direction = wxBOTH);
    virtual bool EnableCloseButton(bool enable = true);
    virtual bool EnableMaximizeButton(bool enable = true);
    virtual bool EnableMinimizeButton(bool enable = true);
    wxWindow* GetDefaultItem() const;
    static wxSize GetDefaultSize();
    wxIcon GetIcon() const;
    const wxIconBundle& GetIcons() const;
    virtual wxString GetTitle() const;
    virtual void Iconize(bool iconize = true);
    virtual bool IsActive();
    virtual bool IsAlwaysMaximized() const;
    virtual bool IsFullScreen() const;
    virtual bool IsIconized() const;
    virtual bool IsMaximized() const;
    virtual bool Layout();
    virtual void Maximize(bool maximize = true);
#ifdef __WXMSW__
    wxMenu *MSWGetSystemMenu() const;
#endif
    virtual void RequestUserAttention(int flags = wxUSER_ATTENTION_INFO);
    void Restore();
    wxWindow* SetDefaultItem(wxWindow* win);
    wxWindow*  SetTmpDefaultItem(wxWindow * win);
    wxWindow* GetTmpDefaultItem() const;
    void SetIcon(const wxIcon& icon);
    virtual void SetIcons(const wxIconBundle& icons);
    virtual void SetMaxSize(const wxSize& size);
    virtual void SetMinSize(const wxSize& size);
    virtual void SetSizeHints(int minW, int minH,
                              int maxW = -1, int maxH = -1,
                              int incW = -1, int incH = -1);
    void SetSizeHints(const wxSize& minSize,
                      const wxSize& maxSize = wxDefaultSize,
                      const wxSize& incSize = wxDefaultSize);
    virtual void SetTitle(const wxString& title);
    virtual bool SetTransparent(wxByte alpha);
    virtual bool ShouldPreventAppExit() const;
    virtual void OSXSetModified(bool modified);
    virtual bool OSXIsModified() const;
    virtual void SetRepresentedFilename(const wxString& filename);
    virtual void ShowWithoutActivating();
    virtual bool EnableFullScreenView(bool enable = true);
    virtual bool ShowFullScreen(bool show, long style = wxFULLSCREEN_ALL);
};