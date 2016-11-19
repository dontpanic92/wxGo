WXGO_DECL_TYPECONV(BookCtrlEvent)
class wxBookCtrlEvent : public wxNotifyEvent
{
public:
    wxBookCtrlEvent(wxEventType eventType = wxEVT_NULL, int id = 0,
                    int sel = wxNOT_FOUND, int oldSel = wxNOT_FOUND);
    int GetOldSelection() const;
    int GetSelection() const;
    void SetOldSelection(int page);
    void SetSelection(int page);
};
enum
{
    wxNB_HITTEST_NOWHERE = wxBK_HITTEST_NOWHERE,
    wxNB_HITTEST_ONICON  = wxBK_HITTEST_ONICON,
    wxNB_HITTEST_ONLABEL = wxBK_HITTEST_ONLABEL,
    wxNB_HITTEST_ONITEM  = wxBK_HITTEST_ONITEM,
    wxNB_HITTEST_ONPAGE  = wxBK_HITTEST_ONPAGE
};
#define wxNB_DEFAULT          wxBK_DEFAULT
#define wxNB_TOP              wxBK_TOP
#define wxNB_BOTTOM           wxBK_BOTTOM
#define wxNB_LEFT             wxBK_LEFT
#define wxNB_RIGHT            wxBK_RIGHT
#define wxNB_FIXEDWIDTH       0x0100
#define wxNB_MULTILINE        0x0200
#define wxNB_NOPAGETHEME      0x0400
#define wxNB_FLAT             0x0800
%constant wxEventType wxEVT_NOTEBOOK_PAGE_CHANGED;
%constant wxEventType wxEVT_NOTEBOOK_PAGE_CHANGING;
WXGO_DECL_TYPECONV(Notebook)
class wxNotebook : public wxBookCtrlBase
{
public:
    wxNotebook();
    wxNotebook(wxWindow* parent, wxWindowID id,
               const wxPoint& pos = wxDefaultPosition,
               const wxSize& size = wxDefaultSize,
               long style = 0,
               const wxString& name = wxNotebookNameStr);
    virtual ~wxNotebook();
    bool Create(wxWindow* parent, wxWindowID id,
                const wxPoint& pos = wxDefaultPosition,
                const wxSize& size = wxDefaultSize,
                long style = 0,
                const wxString& name = wxNotebookNameStr);
    virtual int GetRowCount() const;
    virtual wxColour GetThemeBackgroundColour() const;
    virtual void SetPadding(const wxSize& padding);
    virtual int GetPageImage(size_t nPage) const;
    virtual bool SetPageImage(size_t page, int image);
    virtual wxString GetPageText(size_t nPage) const;
    virtual bool SetPageText(size_t page, const wxString& text);
    virtual int GetSelection() const;
    virtual int SetSelection(size_t page);
    virtual int ChangeSelection(size_t page);
    virtual bool InsertPage(size_t index, wxWindow * page, const wxString & text,
                            bool select = false, int imageId = NO_IMAGE);
};