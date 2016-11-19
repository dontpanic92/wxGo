#define wxHL_CONTEXTMENU        0x0001
#define wxHL_ALIGN_LEFT         0x0002
#define wxHL_ALIGN_RIGHT        0x0004
#define wxHL_ALIGN_CENTRE       0x0008
#define wxHL_DEFAULT_STYLE      (wxHL_CONTEXTMENU|wxNO_BORDER|wxHL_ALIGN_CENTRE)
WXGO_DECL_TYPECONV(HyperlinkEvent)
class wxHyperlinkEvent : public wxCommandEvent
{
public:
    wxHyperlinkEvent(wxObject* generator, int id, const wxString& url);
    wxString GetURL() const;
    void SetURL(const wxString& url);
};
%constant wxEventType wxEVT_HYPERLINK;
WXGO_DECL_TYPECONV(HyperlinkCtrl)
class wxHyperlinkCtrl : public wxControl
{
public:
    wxHyperlinkCtrl();
    wxHyperlinkCtrl(wxWindow* parent, wxWindowID id,
                    const wxString& label,
                    const wxString& url,
                    const wxPoint& pos = wxDefaultPosition,
                    const wxSize& size = wxDefaultSize,
                    long style = wxHL_DEFAULT_STYLE,
                    const wxString& name = wxHyperlinkCtrlNameStr);
    bool Create(wxWindow* parent, wxWindowID id, const wxString& label,
                const wxString& url, const wxPoint& pos = wxDefaultPosition,
                const wxSize& size = wxDefaultSize,
                long style = wxHL_DEFAULT_STYLE,
                const wxString& name = wxHyperlinkCtrlNameStr);
    virtual wxColour GetHoverColour() const;
    virtual wxColour GetNormalColour() const;
    virtual wxString GetURL() const;
    virtual bool GetVisited() const = 0;
    virtual wxColour GetVisitedColour() const;
    virtual void SetHoverColour(const wxColour& colour);
    virtual void SetNormalColour(const wxColour& colour);
    virtual void SetURL(const wxString& url);
    virtual void SetVisited(bool visited = true) = 0;
    virtual void SetVisitedColour(const wxColour& colour);
};