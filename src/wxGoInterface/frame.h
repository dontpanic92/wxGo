class wxFrame : public wxFrameBase
{
public:
	wxFrame() ;
    wxFrame(wxWindow *parent,
               wxWindowID id,
               const wxString& title,
               const wxPoint& pos = wxDefaultPosition,
               const wxSize& size = wxDefaultSize,
               long style = wxDEFAULT_FRAME_STYLE,
               const wxString& name = wxFrameNameStr);

    bool Create(wxWindow *parent,
                wxWindowID id,
                const wxString& title,
                const wxPoint& pos = wxDefaultPosition,
                const wxSize& size = wxDefaultSize,
                long style = wxDEFAULT_FRAME_STYLE,
                const wxString& name = wxFrameNameStr);

    ~wxFrame();

    wxPoint GetClientAreaOrigin() const;

    void SetMenuBar(wxMenuBar *menubar);
    wxMenuBar *GetMenuBar() const ;

    wxMenuItem *FindItemInMenuBar(int menuId) const;

    bool ProcessCommand(wxMenuItem *item);

    bool ProcessCommand(int winid);

    wxStatusBar* CreateStatusBar(int number = 1,
                                         long style = wxSTB_DEFAULT_STYLE,
                                         wxWindowID winid = 0,
                                         const wxString& name = wxStatusLineNameStr);
    // return a new status bar
    wxStatusBar *OnCreateStatusBar(int number,
                                           long style,
                                           wxWindowID winid,
                                           const wxString& name);
    // get the main status bar
    wxStatusBar *GetStatusBar() const;

    // sets the main status bar
    void SetStatusBar(wxStatusBar *statBar);

    // forward these to status bar
    void SetStatusText(const wxString &text, int number = 0);
    void SetStatusWidths(int n, const int widths_field[]);
    void PushStatusText(const wxString &text, int number = 0);
    void PopStatusText(int number = 0);

    // set the status bar pane the help will be shown in
    void SetStatusBarPane(int n) ;
    int GetStatusBarPane() const ;

    wxToolBar* CreateToolBar(long style = -1,
                                     wxWindowID winid = wxID_ANY,
                                     const wxString& name = wxToolBarNameStr);
    // return a new toolbar
    wxToolBar *OnCreateToolBar(long style,
                                       wxWindowID winid,
                                       const wxString& name );

    // get/set the main toolbar
    wxToolBar *GetToolBar() const;
    void SetToolBar(wxToolBar *toolbar);

    void OnMenuOpen(wxMenuEvent& event);
    void OnMenuClose(wxMenuEvent& event);
    void OnMenuHighlight(wxMenuEvent& event);

    void DoMenuUpdates(wxMenu* menu = NULL);

    void UpdateWindowUI(long flags = wxUPDATE_UI_NONE);

    void OnInternalIdle();

    void DoGiveHelp(const wxString& text, bool show);

    bool IsClientAreaChild(const wxWindow *child) const;
    
    void Maximize(bool maximize = true);

    // undo Maximize() or Iconize()
    void Restore();

    // iconize = true => iconize, otherwise - restore
    void Iconize(bool iconize = true);

    // return true if the frame is maximized
    bool IsMaximized() const;

    // return true if the frame is always maximized
    // due to native guidelines or current policy
    bool IsAlwaysMaximized() const;

    // return true if the frame is iconized
    bool IsIconized() const;

    // get the frame icon
    wxIcon GetIcon() const;

    // get the frame icons
    const wxIconBundle& GetIcons() const ;

    // set the frame icon: implemented in terms of SetIcons()
    void SetIcon(const wxIcon& icon);

    // set the frame icons
    void SetIcons(const wxIconBundle& icons) { m_icons = icons; }

	bool Show( bool show = true );
	
    bool ShowFullScreen(bool show, long style = wxFULLSCREEN_ALL);

    void ShowWithoutActivating();


    bool IsFullScreen() const;

    void SetTitle(const wxString& title);

    wxString GetTitle() const;
    
    bool EnableCloseButton(bool enable );


    void RequestUserAttention(int flags = wxUSER_ATTENTION_INFO);


    bool IsActive();


    bool ShouldPreventAppExit() const;

    void CentreOnScreen(int dir = wxBOTH);
    void CenterOnScreen(int dir = wxBOTH);


    wxWindow *GetDefaultItem() const;
    wxWindow *SetDefaultItem(wxWindow *win);
    wxWindow *GetTmpDefaultItem() const ;
    wxWindow *SetTmpDefaultItem(wxWindow *win);
    bool Destroy();
    bool IsTopLevel() const ;
    bool IsTopNavigationDomain() const ;
    bool IsVisible() const;

    // event handlers
    void OnCloseWindow(wxCloseEvent& event);
    void OnSize(wxSizeEvent& event);

    // Get rect to be used to center top-level children
    void GetRectForTopLevelChildren(int *x, int *y, int *w, int *h);

    // this should go away, but for now it's called from docview.cpp,
    // so should be there for all platforms
    void OnActivate(wxActivateEvent &event);

    // do the window-specific processing after processing the update event
    void DoUpdateWindowUI(wxUpdateUIEvent& event) ;

    // a different API for SetSizeHints
    void SetMinSize(const wxSize& minSize);
    void SetMaxSize(const wxSize& maxSize);



    void SetRepresentedFilename(const wxString& filename);

};
