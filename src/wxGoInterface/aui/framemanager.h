%typedef int wxAuiManagerDock;
#define wxAUI_DOCK_NONE  0
#define wxAUI_DOCK_TOP  1
#define wxAUI_DOCK_RIGHT  2
#define wxAUI_DOCK_BOTTOM  3
#define wxAUI_DOCK_LEFT  4
#define wxAUI_DOCK_CENTER  5
#define wxAUI_DOCK_CENTRE  wxAUI_DOCK_CENTER
%typedef int wxAuiManagerOption;
#define wxAUI_MGR_ALLOW_FLOATING            1 << 0
#define wxAUI_MGR_ALLOW_ACTIVE_PANE         1 << 1
#define wxAUI_MGR_TRANSPARENT_DRAG          1 << 2
#define wxAUI_MGR_TRANSPARENT_HINT          1 << 3
#define wxAUI_MGR_VENETIAN_BLINDS_HINT      1 << 4
#define wxAUI_MGR_RECTANGLE_HINT            1 << 5
#define wxAUI_MGR_HINT_FADE                 1 << 6
#define wxAUI_MGR_NO_VENETIAN_BLINDS_FADE   1 << 7
#define wxAUI_MGR_LIVE_RESIZE               1 << 8
#define wxAUI_MGR_DEFAULT  wxAUI_MGR_ALLOW_FLOATING |                        wxAUI_MGR_TRANSPARENT_HINT |                        wxAUI_MGR_HINT_FADE |                        wxAUI_MGR_NO_VENETIAN_BLINDS_FADE
WXGO_DECL_TYPECONV(AuiManager)
class wxAuiManager : public wxEvtHandler
{
public:
    wxAuiManager(wxWindow* managed_wnd = NULL,
                 unsigned int flags = wxAUI_MGR_DEFAULT);
    virtual ~wxAuiManager();
    bool AddPane(wxWindow* window, const wxAuiPaneInfo& pane_info);
    bool AddPane(wxWindow* window, int direction = wxLEFT,
                 const wxString& caption = wxEmptyString);
    bool AddPane(wxWindow* window,
                 const wxAuiPaneInfo& pane_info,
                 const wxPoint& drop_pos);
    bool DetachPane(wxWindow* window);
    wxAuiPaneInfoArray& GetAllPanes();
    wxAuiDockArt* GetArtProvider() const;
    void GetDockSizeConstraint(double* widthpct, double* heightpct) const;
    unsigned int GetFlags() const;
    wxWindow* GetManagedWindow() const;
    static wxAuiManager* GetManager(wxWindow* window);
    wxAuiPaneInfo& GetPane(wxWindow* window);
    wxAuiPaneInfo& GetPane(const wxString& name);
    virtual void HideHint();
    bool InsertPane(wxWindow* window,
                    const wxAuiPaneInfo& insert_location,
                    int insert_level = wxAUI_INSERT_PANE);
    void LoadPaneInfo(wxString pane_part, wxAuiPaneInfo& pane);
    bool LoadPerspective(const wxString& perspective,
                         bool update = true);
    wxString SavePaneInfo(wxAuiPaneInfo& pane);
    wxString SavePerspective();
    void SetArtProvider(wxAuiDockArt* art_provider);
    void SetDockSizeConstraint(double widthpct, double heightpct);
    void SetFlags(unsigned int flags);
    void SetManagedWindow(wxWindow* managed_wnd);
    virtual void ShowHint(const wxRect& rect);
    void UnInit();
    void Update();
protected:
    virtual bool ProcessDockResult(wxAuiPaneInfo& target,
                                   const wxAuiPaneInfo& new_pos);
};
WXGO_DECL_TYPECONV(AuiPaneInfo)
class wxAuiPaneInfo
{
public:
    wxAuiPaneInfo();
    wxAuiPaneInfo(const wxAuiPaneInfo& c);
    wxAuiPaneInfo& BestSize(const wxSize& size);
    wxAuiPaneInfo& BestSize(int x, int y);
    wxAuiPaneInfo& Bottom();
    wxAuiPaneInfo& BottomDockable(bool b = true);
    wxAuiPaneInfo& Caption(const wxString& c);
    wxAuiPaneInfo& CaptionVisible(bool visible = true);
    wxAuiPaneInfo& Centre();
    wxAuiPaneInfo& Center();
    wxAuiPaneInfo& CentrePane();
    wxAuiPaneInfo& CenterPane();
    wxAuiPaneInfo& CloseButton(bool visible = true);
    wxAuiPaneInfo& DefaultPane();
    wxAuiPaneInfo& DestroyOnClose(bool b = true);
    wxAuiPaneInfo& Direction(int direction);
    wxAuiPaneInfo& Dock();
    wxAuiPaneInfo& DockFixed(bool b = true);
    wxAuiPaneInfo& Dockable(bool b = true);
    wxAuiPaneInfo& Fixed();
    wxAuiPaneInfo& Float();
    wxAuiPaneInfo& Floatable(bool b = true);
    wxAuiPaneInfo& FloatingPosition(const wxPoint& pos);
    wxAuiPaneInfo& FloatingPosition(int x, int y);
    wxAuiPaneInfo& FloatingSize(const wxSize& size);
    wxAuiPaneInfo& FloatingSize(int x, int y);
    wxAuiPaneInfo& Gripper(bool visible = true);
    wxAuiPaneInfo& GripperTop(bool attop = true);
    bool HasBorder() const;
    bool HasCaption() const;
    bool HasCloseButton() const;
    bool HasFlag(int flag) const;
    bool HasGripper() const;
    bool HasGripperTop() const;
    bool HasMaximizeButton() const;
    bool HasMinimizeButton() const;
    bool HasPinButton() const;
    wxAuiPaneInfo& Hide();
    wxAuiPaneInfo& Icon(const wxBitmap& b);
    bool IsBottomDockable() const;
    bool IsDockable() const;
    bool IsDocked() const;
    bool IsFixed() const;
    bool IsFloatable() const;
    bool IsFloating() const;
    bool IsLeftDockable() const;
    bool IsMovable() const;
    bool IsOk() const;
    bool IsResizable() const;
    bool IsRightDockable() const;
    bool IsShown() const;
    bool IsToolbar() const;
    bool IsTopDockable() const;
    wxAuiPaneInfo& Layer(int layer);
    wxAuiPaneInfo& Left();
    wxAuiPaneInfo& LeftDockable(bool b = true);
    wxAuiPaneInfo& MaxSize(const wxSize& size);
    wxAuiPaneInfo& MaxSize(int x, int y);
    wxAuiPaneInfo& MaximizeButton(bool visible = true);
    wxAuiPaneInfo& MinSize(const wxSize& size);
    wxAuiPaneInfo& MinSize(int x, int y);
    wxAuiPaneInfo& MinimizeButton(bool visible = true);
    wxAuiPaneInfo& Movable(bool b = true);
    wxAuiPaneInfo& Name(const wxString& n);
    wxAuiPaneInfo& PaneBorder(bool visible = true);
    wxAuiPaneInfo& PinButton(bool visible = true);
    wxAuiPaneInfo& Position(int pos);
    wxAuiPaneInfo& Resizable(bool resizable = true);
    wxAuiPaneInfo& Right();
    wxAuiPaneInfo& RightDockable(bool b = true);
    wxAuiPaneInfo& Row(int row);
    void SafeSet(wxAuiPaneInfo source);
    wxAuiPaneInfo& SetFlag(int flag, bool option_state);
    wxAuiPaneInfo& Show(bool show = true);
    wxAuiPaneInfo& ToolbarPane();
    wxAuiPaneInfo& Top();
    wxAuiPaneInfo& TopDockable(bool b = true);
    wxAuiPaneInfo& Window(wxWindow* w);
    wxAuiPaneInfo& operator=(const wxAuiPaneInfo& c);
};
WXGO_DECL_TYPECONV(AuiManagerEvent)
class wxAuiManagerEvent : public wxEvent
{
public:
    wxAuiManagerEvent(wxEventType type = wxEVT_NULL);
    bool CanVeto();
    int GetButton();
    wxDC* GetDC();
    bool GetVeto();
    wxAuiManager* GetManager();
    wxAuiPaneInfo* GetPane();
    void SetButton(int button);
    void SetCanVeto(bool can_veto);
    void SetDC(wxDC* pdc);
    void SetManager(wxAuiManager* manager);
    void SetPane(wxAuiPaneInfo* pane);
    void Veto(bool veto = true);
};
%constant wxEventType wxEVT_AUI_PANE_BUTTON;
%constant wxEventType wxEVT_AUI_PANE_CLOSE;
%constant wxEventType wxEVT_AUI_PANE_MAXIMIZE;
%constant wxEventType wxEVT_AUI_PANE_RESTORE;
%constant wxEventType wxEVT_AUI_PANE_ACTIVATED;
%constant wxEventType wxEVT_AUI_RENDER;
%constant wxEventType wxEVT_AUI_FIND_MANAGER;