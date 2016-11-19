#define wxFRAME_NO_TASKBAR      0x0002  
#define wxFRAME_TOOL_WINDOW     0x0004  
#define wxFRAME_FLOAT_ON_PARENT 0x0008  
WXGO_DECL_TYPECONV(Frame)
class wxFrame : public wxTopLevelWindow
{
public:
    wxFrame();
    wxFrame(wxWindow* parent, wxWindowID id,
            const wxString& title,
            const wxPoint& pos = wxDefaultPosition,
            const wxSize& size = wxDefaultSize,
            long style = wxDEFAULT_FRAME_STYLE,
            const wxString& name = wxFrameNameStr);
    virtual ~wxFrame();
    void Centre(int direction = wxBOTH);
    bool Create(wxWindow* parent, wxWindowID id, const wxString& title,
                const wxPoint& pos = wxDefaultPosition,
                const wxSize& size = wxDefaultSize,
                long style = wxDEFAULT_FRAME_STYLE,
                const wxString& name = wxFrameNameStr);
    virtual wxStatusBar* CreateStatusBar(int number = 1, long style = wxSTB_DEFAULT_STYLE,
                                         wxWindowID id = 0,
                                         const wxString& name = wxStatusBarNameStr);
    virtual wxToolBar* CreateToolBar(long style = wxTB_DEFAULT_STYLE,
                                     wxWindowID id = wxID_ANY,
                                     const wxString& name = wxToolBarNameStr);
    virtual void DoGiveHelp(const wxString& text, bool show);
    virtual wxPoint GetClientAreaOrigin() const;
    virtual wxMenuBar* GetMenuBar() const;
    virtual wxStatusBar* GetStatusBar() const;
    int GetStatusBarPane() const;
    virtual wxToolBar* GetToolBar() const;
    virtual wxStatusBar* OnCreateStatusBar(int number, long style,
                                           wxWindowID id,
                                           const wxString& name);
    virtual wxToolBar* OnCreateToolBar(long style, wxWindowID id,
                                       const wxString& name);
    bool ProcessCommand(int id);
    virtual void SetMenuBar(wxMenuBar* menuBar);
    virtual void SetStatusBar(wxStatusBar* statusBar);
    void SetStatusBarPane(int n);
    virtual void SetStatusText(const wxString& text, int number = 0);
    virtual void SetStatusWidths(int n, const int* widths_field);
    virtual void SetToolBar(wxToolBar* toolBar);
#ifdef __WXMSW__
    wxTaskBarButton* MSWGetTaskBarButton();
#endif
    void PushStatusText(const wxString &text, int number = 0);
    void PopStatusText(int number = 0);
};