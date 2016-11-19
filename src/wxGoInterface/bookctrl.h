enum
{
    wxBK_HITTEST_NOWHERE = 1,
    wxBK_HITTEST_ONICON  = 2,
    wxBK_HITTEST_ONLABEL = 4,
    wxBK_HITTEST_ONITEM  = wxBK_HITTEST_ONICON | wxBK_HITTEST_ONLABEL,
    wxBK_HITTEST_ONPAGE  = 8
};
#define wxBK_DEFAULT          0x0000
#define wxBK_TOP              0x0010
#define wxBK_BOTTOM           0x0020
#define wxBK_LEFT             0x0040
#define wxBK_RIGHT            0x0080
#define wxBK_ALIGN_MASK       (wxBK_TOP | wxBK_BOTTOM | wxBK_LEFT | wxBK_RIGHT)
WXGO_DECL_TYPECONV(BookCtrlBase)
class wxBookCtrlBase : public wxControl, public wxWithImages
{
public:
    enum
    {
        NO_IMAGE = -1
    };
    wxBookCtrlBase();
    wxBookCtrlBase(wxWindow *parent,
                   wxWindowID winid,
                   const wxPoint& pos = wxDefaultPosition,
                   const wxSize& size = wxDefaultSize,
                   long style = 0,
                   const wxString& name = wxEmptyString);
    bool Create(wxWindow *parent,
                wxWindowID winid,
                const wxPoint& pos = wxDefaultPosition,
                const wxSize& size = wxDefaultSize,
                long style = 0,
                const wxString& name = wxEmptyString);
    virtual int GetPageImage(size_t nPage) const = 0;
    virtual bool SetPageImage(size_t page, int image) = 0;
    virtual wxString GetPageText(size_t nPage) const = 0;
    virtual bool SetPageText(size_t page, const wxString& text) = 0;
    virtual int GetSelection() const = 0;
    wxWindow* GetCurrentPage() const;
    virtual int SetSelection(size_t page) = 0;
    void AdvanceSelection(bool forward = true);
    virtual int ChangeSelection(size_t page) = 0;
    int FindPage(const wxWindow* page) const;
    virtual void SetPageSize(const wxSize& size);
    virtual int HitTest(const wxPoint& pt, long* flags = NULL) const;
    virtual bool AddPage(wxWindow* page, const wxString& text,
                         bool select = false, int imageId = NO_IMAGE);
    virtual bool DeleteAllPages();
    virtual bool DeletePage(size_t page);
    virtual bool InsertPage(size_t index,
                            wxWindow* page,
                            const wxString& text,
                            bool select = false,
                            int imageId = NO_IMAGE) = 0;
    virtual bool RemovePage(size_t page);
    virtual size_t GetPageCount() const;
    wxWindow* GetPage(size_t page) const;
};