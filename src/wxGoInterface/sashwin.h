#define wxSW_NOBORDER         0x0000
#define wxSW_BORDER           0x0020
#define wxSW_3DSASH           0x0040
#define wxSW_3DBORDER         0x0080
#define wxSW_3D (wxSW_3DSASH | wxSW_3DBORDER)
%typedef int wxSashEdgePosition;
#define wxSASH_TOP  0
#define wxSASH_RIGHT wxSASH_TOP  + 1
#define wxSASH_BOTTOM wxSASH_RIGHT + 1
#define wxSASH_LEFT wxSASH_BOTTOM + 1
#define wxSASH_NONE  100
%typedef int wxSashDragStatus;
#define wxSASH_STATUS_OK 0
#define wxSASH_STATUS_OUT_OF_RANGE wxSASH_STATUS_OK + 1
WXGO_DECL_TYPECONV(SashWindow)
class wxSashWindow : public wxWindow
{
public:
    wxSashWindow();
    wxSashWindow(wxWindow* parent, wxWindowID id,
                 const wxPoint& pos = wxDefaultPosition,
                 const wxSize& size = wxDefaultSize,
                 long style = wxCLIP_CHILDREN | wxSW_3D,
                 const wxString& name = "sashWindow");
    virtual ~wxSashWindow();
    virtual int GetMaximumSizeX() const;
    virtual int GetMaximumSizeY() const;
    virtual int GetMinimumSizeX() const;
    virtual int GetMinimumSizeY() const;
    bool GetSashVisible(wxSashEdgePosition edge) const;
    virtual void SetMaximumSizeX(int min);
    virtual void SetMaximumSizeY(int min);
    virtual void SetMinimumSizeX(int min);
    virtual void SetMinimumSizeY(int min);
    void SetSashVisible(wxSashEdgePosition edge, bool visible);
    int GetEdgeMargin(wxSashEdgePosition edge) const;
    void SetDefaultBorderSize(int width);
    int GetDefaultBorderSize() const;
    void SetExtraBorderSize(int width);
    int GetExtraBorderSize() const;
    wxSashEdgePosition SashHitTest(int x, int y, int tolerance = 2);
    void SizeWindows();
};
WXGO_DECL_TYPECONV(SashEvent)
class wxSashEvent : public wxCommandEvent
{
public:
    wxSashEvent(int id = 0, wxSashEdgePosition edge = wxSASH_NONE);
    wxRect GetDragRect() const;
    wxSashDragStatus GetDragStatus() const;
    wxSashEdgePosition GetEdge() const;
    void SetEdge(wxSashEdgePosition edge);
    void SetDragRect(const wxRect& rect);
    void SetDragStatus(wxSashDragStatus status);
};
%constant wxEventType wxEVT_SASH_DRAGGED;