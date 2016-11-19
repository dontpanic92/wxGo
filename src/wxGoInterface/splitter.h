#define wxSP_NOBORDER         0x0000
#define wxSP_THIN_SASH        0x0000    
#define wxSP_NOSASH           0x0010
#define wxSP_PERMIT_UNSPLIT   0x0040
#define wxSP_LIVE_UPDATE      0x0080
#define wxSP_3DSASH           0x0100
#define wxSP_3DBORDER         0x0200
#define wxSP_NO_XP_THEME      0x0400
#define wxSP_BORDER           wxSP_3DBORDER
#define wxSP_3D               (wxSP_3DBORDER | wxSP_3DSASH)
%typedef int wxSplitMode;
#define wxSPLIT_HORIZONTAL  1
#define wxSPLIT_VERTICAL wxSPLIT_HORIZONTAL  + 1
enum
{
    wxSPLIT_DRAG_NONE,
    wxSPLIT_DRAG_DRAGGING,
    wxSPLIT_DRAG_LEFT_DOWN
};
WXGO_DECL_TYPECONV(SplitterWindow)
class wxSplitterWindow : public wxWindow
{
public:
    wxSplitterWindow();
    wxSplitterWindow(wxWindow* parent, wxWindowID id = wxID_ANY,
                     const wxPoint& pos = wxDefaultPosition,
                     const wxSize& size = wxDefaultSize,
                     long style = wxSP_3D,
                     const wxString& name = "splitterWindow");
    virtual ~wxSplitterWindow();
    bool Create(wxWindow* parent, wxWindowID id = wxID_ANY,
                const wxPoint& point = wxDefaultPosition,
                const wxSize& size = wxDefaultSize, long style = wxSP_3D,
                const wxString& name = "splitter");
    int GetMinimumPaneSize() const;
    double GetSashGravity() const;
    int GetSashPosition() const;
    int GetSashSize() const;
    int GetDefaultSashSize() const;
    wxSplitMode GetSplitMode() const;
    wxWindow* GetWindow1() const;
    wxWindow* GetWindow2() const;
    void Initialize(wxWindow* window);
    bool IsSashInvisible() const;
    bool IsSplit() const;
    virtual void OnDoubleClickSash(int x, int y);
    virtual bool OnSashPositionChange(int newSashPosition);
    virtual void OnUnsplit(wxWindow* removed);
    bool ReplaceWindow(wxWindow* winOld, wxWindow* winNew);
    void SetMinimumPaneSize(int paneSize);
    void SetSashGravity(double gravity);
    void SetSashPosition(int position, bool redraw = true);
    void SetSplitMode(int mode);
    void SetSashInvisible(bool invisible=true);
    virtual bool SplitHorizontally(wxWindow* window1, wxWindow* window2,
                                   int sashPosition = 0);
    virtual bool SplitVertically(wxWindow* window1, wxWindow* window2,
                                 int sashPosition = 0);
    bool Unsplit(wxWindow* toRemove = NULL);
    void UpdateSize();
};
WXGO_DECL_TYPECONV(SplitterEvent)
class wxSplitterEvent : public wxNotifyEvent
{
public:
    wxSplitterEvent(wxEventType eventType = wxEVT_NULL,
                    wxSplitterWindow* splitter = NULL);
    int GetSashPosition() const;
    wxWindow* GetWindowBeingRemoved() const;
    int GetX() const;
    int GetY() const;
    void SetSashPosition(int pos);
};
%constant wxEventType wxEVT_SPLITTER_SASH_POS_CHANGED;
%constant wxEventType wxEVT_SPLITTER_SASH_POS_CHANGING;
%constant wxEventType wxEVT_SPLITTER_DOUBLECLICKED;
%constant wxEventType wxEVT_SPLITTER_UNSPLIT;