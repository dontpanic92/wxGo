%constant wxEventType wxEVT_TREEBOOK_PAGE_CHANGED;
%constant wxEventType wxEVT_TREEBOOK_PAGE_CHANGING;
%constant wxEventType wxEVT_TREEBOOK_NODE_COLLAPSED;
%constant wxEventType wxEVT_TREEBOOK_NODE_EXPANDED;
WXGO_DECL_TYPECONV(Treebook)
class wxTreebook : public wxBookCtrlBase
{
public:
    wxTreebook();
    wxTreebook(wxWindow* parent, wxWindowID id,
               const wxPoint& pos = wxDefaultPosition,
               const wxSize& size = wxDefaultSize,
               long style = wxBK_DEFAULT,
               const wxString& name = wxEmptyString);
    virtual ~wxTreebook();
    virtual bool AddPage(wxWindow* page, const wxString& text,
                         bool bSelect = false, int imageId = wxNOT_FOUND);
    virtual bool AddSubPage(wxWindow* page, const wxString& text,
                            bool bSelect = false, int imageId = wxNOT_FOUND);
    bool CollapseNode(size_t pageId);
    bool Create(wxWindow* parent, wxWindowID id,
                const wxPoint& pos = wxDefaultPosition,
                const wxSize& size = wxDefaultSize,
                long style = wxBK_DEFAULT,
                const wxString& name = wxEmptyString);
    virtual bool DeletePage(size_t pagePos);
    virtual bool ExpandNode(size_t pageId, bool expand = true);
    int GetPageParent(size_t page) const;
    virtual int GetSelection() const;
    virtual bool InsertPage(size_t pagePos, wxWindow* page,
                            const wxString& text, bool bSelect = false,
                            int imageId = wxNOT_FOUND);
    virtual bool InsertSubPage(size_t pagePos, wxWindow* page,
                               const wxString& text, bool bSelect = false,
                               int imageId = wxNOT_FOUND);
    virtual bool IsNodeExpanded(size_t pageId) const;
};