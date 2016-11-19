%typedef int wxRibbonDisplayMode;
#define wxRIBBON_BAR_PINNED 0
#define wxRIBBON_BAR_MINIMIZED wxRIBBON_BAR_PINNED + 1
#define wxRIBBON_BAR_EXPANDED wxRIBBON_BAR_MINIMIZED + 1
WXGO_DECL_TYPECONV(RibbonBarEvent)
class wxRibbonBarEvent : public wxNotifyEvent
{
public:
    wxRibbonBarEvent(wxEventType command_type = wxEVT_NULL,
                     int win_id = 0,
                     wxRibbonPage* page = NULL);
    wxRibbonPage* GetPage();
    void SetPage(wxRibbonPage* page);
};
WXGO_DECL_TYPECONV(RibbonBar)
class wxRibbonBar : public wxRibbonControl
{
public:
    wxRibbonBar();
    wxRibbonBar(wxWindow* parent,
                wxWindowID id = wxID_ANY,
                const wxPoint& pos = wxDefaultPosition,
                const wxSize& size = wxDefaultSize,
                long style = wxRIBBON_BAR_DEFAULT_STYLE);
    bool Create(wxWindow* parent,
                wxWindowID id = wxID_ANY,
                const wxPoint& pos = wxDefaultPosition,
                const wxSize& size = wxDefaultSize,
                long style = wxRIBBON_BAR_DEFAULT_STYLE);
    virtual ~wxRibbonBar();
    void SetTabCtrlMargins(int left, int right);
    void SetArtProvider(wxRibbonArtProvider* art);
    bool SetActivePage(size_t page);
    bool SetActivePage(wxRibbonPage* page);
    int GetActivePage() const;
    wxRibbonPage* GetPage(int n);
    size_t GetPageCount() const;
    bool DismissExpandedPanel();
    int GetPageNumber(wxRibbonPage* page) const;
    void DeletePage(size_t n);
    void ClearPages();
    bool IsPageShown(size_t page) const;
    void ShowPage(size_t page, bool show_tab=true);
    void HidePage(size_t page);
    bool IsPageHighlighted(size_t page) const;
    void AddPageHighlight(size_t page, bool highlight = true);
    void RemovePageHighlight(size_t page);
    void ShowPanels(wxRibbonDisplayMode mode);
    void ShowPanels(bool show = true);
    void HidePanels();
    bool ArePanelsShown() const;
    wxRibbonDisplayMode GetDisplayMode() const;
    virtual bool Realize();
};