%typedef int wxLayoutOrientation;
#define wxLAYOUT_HORIZONTAL 0
#define wxLAYOUT_VERTICAL wxLAYOUT_HORIZONTAL + 1
%typedef int wxLayoutAlignment;
#define wxLAYOUT_NONE 0
#define wxLAYOUT_TOP wxLAYOUT_NONE + 1
#define wxLAYOUT_LEFT wxLAYOUT_TOP + 1
#define wxLAYOUT_RIGHT wxLAYOUT_LEFT + 1
#define wxLAYOUT_BOTTOM wxLAYOUT_RIGHT + 1
WXGO_DECL_TYPECONV(LayoutAlgorithm)
class wxLayoutAlgorithm : public wxObject
{
public:
    wxLayoutAlgorithm();
    virtual ~wxLayoutAlgorithm();
    bool LayoutFrame(wxFrame* frame, wxWindow* mainWindow = NULL);
    bool LayoutMDIFrame(wxMDIParentFrame* frame, wxRect* rect = NULL);
    bool LayoutWindow(wxWindow* parent, wxWindow* mainWindow = NULL);
};
WXGO_DECL_TYPECONV(SashLayoutWindow)
class wxSashLayoutWindow : public wxSashWindow
{
public:
    wxSashLayoutWindow();
    wxSashLayoutWindow(wxWindow* parent, wxWindowID id,
                       const wxPoint& pos = wxDefaultPosition,
                       const wxSize& size = wxDefaultSize,
                       long style = wxCLIP_CHILDREN | wxSW_3D,
                       const wxString& name = "layoutWindow");
    bool Create(wxWindow* parent, wxWindowID id = wxID_ANY,
                const wxPoint& pos = wxDefaultPosition,
                const wxSize& size = wxDefaultSize,
                long style = wxCLIP_CHILDREN | wxSW_3D,
                const wxString& name = "layoutWindow");
    wxLayoutAlignment GetAlignment() const;
    wxLayoutOrientation GetOrientation() const;
    void OnCalculateLayout(wxCalculateLayoutEvent& event);
    void OnQueryLayoutInfo(wxQueryLayoutInfoEvent& event);
    void SetAlignment(wxLayoutAlignment alignment);
    void SetDefaultSize(const wxSize& size);
    void SetOrientation(wxLayoutOrientation orientation);
};
WXGO_DECL_TYPECONV(QueryLayoutInfoEvent)
class wxQueryLayoutInfoEvent : public wxEvent
{
public:
    wxQueryLayoutInfoEvent(wxWindowID id = 0);
    wxLayoutAlignment GetAlignment() const;
    int GetFlags() const;
    wxLayoutOrientation GetOrientation() const;
    int GetRequestedLength() const;
    wxSize GetSize() const;
    void SetAlignment(wxLayoutAlignment alignment);
    void SetFlags(int flags);
    void SetOrientation(wxLayoutOrientation orientation);
    void SetRequestedLength(int length);
    void SetSize(const wxSize& size);
};
%constant wxEventType wxEVT_QUERY_LAYOUT_INFO;
WXGO_DECL_TYPECONV(CalculateLayoutEvent)
class wxCalculateLayoutEvent : public wxEvent
{
public:
    wxCalculateLayoutEvent(wxWindowID id = 0);
    int GetFlags() const;
    wxRect GetRect() const;
    void SetFlags(int flags);
    void SetRect(const wxRect& rect);
};
%constant wxEventType wxEVT_CALCULATE_LAYOUT;