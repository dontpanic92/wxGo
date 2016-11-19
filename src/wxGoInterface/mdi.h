WXGO_DECL_TYPECONV(MDIClientWindow)
class wxMDIClientWindow : public wxWindow
{
public:
    wxMDIClientWindow();
    virtual bool CreateClient(wxMDIParentFrame* parent, long style = 0);
};
WXGO_DECL_TYPECONV(MDIParentFrame)
class wxMDIParentFrame : public wxFrame
{
public:
    wxMDIParentFrame();
    wxMDIParentFrame(wxWindow* parent, wxWindowID id,
                     const wxString& title,
                     const wxPoint& pos = wxDefaultPosition,
                     const wxSize& size = wxDefaultSize,
                     long style = wxDEFAULT_FRAME_STYLE | wxVSCROLL | wxHSCROLL,
                     const wxString& name = wxFrameNameStr);
    virtual ~wxMDIParentFrame();
    virtual void ActivateNext();
    virtual void ActivatePrevious();
    virtual void ArrangeIcons();
    virtual void Cascade();
    bool Create(wxWindow* parent,
                wxWindowID id,
                const wxString& title,
                const wxPoint& pos = wxDefaultPosition,
                const wxSize& size = wxDefaultSize,
                long style = wxDEFAULT_FRAME_STYLE | wxVSCROLL | wxHSCROLL,
                const wxString& name = wxFrameNameStr);
    virtual wxMDIChildFrame* GetActiveChild() const;
    wxMDIClientWindowBase* GetClientWindow() const;
    wxMenu *GetWindowMenu() const;
    static bool IsTDI();
    virtual wxMDIClientWindow* OnCreateClient();
    virtual void SetWindowMenu(wxMenu* menu);
    virtual void Tile(wxOrientation orient = wxHORIZONTAL);
};
WXGO_DECL_TYPECONV(MDIChildFrame)
class wxMDIChildFrame : public wxFrame
{
public:
    wxMDIChildFrame();
    wxMDIChildFrame(wxMDIParentFrame* parent, wxWindowID id,
                    const wxString& title,
                    const wxPoint& pos = wxDefaultPosition,
                    const wxSize& size = wxDefaultSize,
                    long style = wxDEFAULT_FRAME_STYLE,
                    const wxString& name = wxFrameNameStr);
    virtual ~wxMDIChildFrame();
    virtual void Activate();
    bool Create(wxMDIParentFrame* parent, wxWindowID id, const wxString& title,
                const wxPoint& pos = wxDefaultPosition,
                const wxSize& size = wxDefaultSize,
                long style = wxDEFAULT_FRAME_STYLE,
                const wxString& name = wxFrameNameStr);
    wxMDIParentFrame *GetMDIParent() const;
    virtual bool IsAlwaysMaximized() const;
    virtual void Maximize(bool maximize = true);
    virtual void Restore();
};