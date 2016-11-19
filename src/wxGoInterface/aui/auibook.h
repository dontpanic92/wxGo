%typedef int wxAuiNotebookOption;
#define wxAUI_NB_TOP                  1 << 0
#define wxAUI_NB_LEFT                 1 << 1
#define wxAUI_NB_RIGHT                1 << 2
#define wxAUI_NB_BOTTOM               1 << 3
#define wxAUI_NB_TAB_SPLIT            1 << 4
#define wxAUI_NB_TAB_MOVE             1 << 5
#define wxAUI_NB_TAB_EXTERNAL_MOVE    1 << 6
#define wxAUI_NB_TAB_FIXED_WIDTH      1 << 7
#define wxAUI_NB_SCROLL_BUTTONS       1 << 8
#define wxAUI_NB_WINDOWLIST_BUTTON    1 << 9
#define wxAUI_NB_CLOSE_BUTTON         1 << 10
#define wxAUI_NB_CLOSE_ON_ACTIVE_TAB  1 << 11
#define wxAUI_NB_CLOSE_ON_ALL_TABS    1 << 12
#define wxAUI_NB_MIDDLE_CLICK_CLOSE   1 << 13
#define wxAUI_NB_DEFAULT_STYLE  wxAUI_NB_TOP |                             wxAUI_NB_TAB_SPLIT |                             wxAUI_NB_TAB_MOVE |                             wxAUI_NB_SCROLL_BUTTONS |                             wxAUI_NB_CLOSE_ON_ACTIVE_TAB |                             wxAUI_NB_MIDDLE_CLICK_CLOSE
WXGO_DECL_TYPECONV(AuiNotebook)
class wxAuiNotebook : public wxBookCtrlBase
{
public:
    wxAuiNotebook();
    wxAuiNotebook(wxWindow* parent, wxWindowID id = wxID_ANY,
                  const wxPoint& pos = wxDefaultPosition,
                  const wxSize& size = wxDefaultSize,
                  long style = wxAUI_NB_DEFAULT_STYLE);
    bool AddPage(wxWindow* page, const wxString& caption,
                 bool select = false,
                 const wxBitmap& bitmap = wxNullBitmap);
    virtual bool AddPage(wxWindow *page, const wxString &text, bool select, int imageId);
    void AdvanceSelection(bool forward = true);
    virtual int ChangeSelection(size_t n);
    bool Create(wxWindow* parent, wxWindowID id = wxID_ANY,
                const wxPoint& pos = wxDefaultPosition,
                const wxSize& size = wxDefaultSize,
                long style = 0);
    virtual bool DeleteAllPages();
    bool DeletePage(size_t page);
    wxAuiTabArt* GetArtProvider() const;
    wxWindow* GetCurrentPage () const;
    int GetHeightForPageHeight(int pageHeight);
    wxWindow* GetPage(size_t page_idx) const;
    wxBitmap GetPageBitmap(size_t page) const;
    size_t GetPageCount() const;
    int GetPageIndex(wxWindow* page_wnd) const;
    wxString GetPageText(size_t page) const;
    wxString GetPageToolTip(size_t pageIdx) const;
    int GetSelection() const;
    int GetTabCtrlHeight() const;
    bool InsertPage(size_t page_idx, wxWindow* page,
                    const wxString& caption,
                    bool select = false,
                    const wxBitmap& bitmap = wxNullBitmap);
    virtual bool InsertPage(size_t index, wxWindow *page, const wxString &text,
                            bool select=false, int imageId=NO_IMAGE);
    bool RemovePage(size_t page);
    void SetArtProvider(wxAuiTabArt* art);
    virtual bool SetFont(const wxFont& font);
    void SetMeasuringFont(const wxFont& font);
    void SetNormalFont(const wxFont& font);
    bool SetPageBitmap(size_t page, const wxBitmap& bitmap);
    virtual bool SetPageImage(size_t n, int imageId);
    bool SetPageText(size_t page, const wxString& text);
    bool SetPageToolTip(size_t page, const wxString& text);
    void SetSelectedFont(const wxFont& font);
    size_t SetSelection(size_t new_page);
    virtual void SetTabCtrlHeight(int height);
    virtual void SetUniformBitmapSize(const wxSize& size);
    virtual void Split(size_t page, int direction);
    bool ShowWindowMenu();
};
WXGO_DECL_TYPECONV(AuiNotebookPage)
class wxAuiNotebookPage
{
public:
    wxWindow* window;     
    wxString caption;     
    wxString tooltip;     
    wxBitmap bitmap;      
    wxRect rect;          
    bool active;          
    bool hover;           
};
WXGO_DECL_TYPECONV(AuiTabContainerButton)
class wxAuiTabContainerButton
{
public:
    int id;
    int curState;
    int location;
    wxBitmap bitmap;
    wxBitmap disBitmap;
    wxRect rect;
};
WXGO_DECL_TYPECONV(AuiTabContainer)
class wxAuiTabContainer
{
public:
    wxAuiTabContainer();
    virtual ~wxAuiTabContainer();
    void SetArtProvider(wxAuiTabArt* art);
    wxAuiTabArt* GetArtProvider() const;
    void SetFlags(unsigned int flags);
    unsigned int GetFlags() const;
    bool AddPage(wxWindow* page, const wxAuiNotebookPage& info);
    bool InsertPage(wxWindow* page, const wxAuiNotebookPage& info, size_t idx);
    bool MovePage(wxWindow* page, size_t newIdx);
    bool RemovePage(wxWindow* page);
    bool SetActivePage(wxWindow* page);
    bool SetActivePage(size_t page);
    void SetNoneActive();
    int GetActivePage() const;
    bool TabHitTest(int x, int y, wxWindow** hit) const;
    bool ButtonHitTest(int x, int y, wxAuiTabContainerButton** hit) const;
    wxWindow* GetWindowFromIdx(size_t idx) const;
    int GetIdxFromWindow(wxWindow* page) const;
    size_t GetPageCount() const;
    wxAuiNotebookPage& GetPage(size_t idx);
    wxAuiNotebookPageArray& GetPages();
    void SetNormalFont(const wxFont& normalFont);
    void SetSelectedFont(const wxFont& selectedFont);
    void SetMeasuringFont(const wxFont& measuringFont);
    void SetColour(const wxColour& colour);
    void SetActiveColour(const wxColour& colour);
    void DoShowHide();
    void SetRect(const wxRect& rect);
    void RemoveButton(int id);
    void AddButton(int id,
                   int location,
                   const wxBitmap& normalBitmap = wxNullBitmap,
                   const wxBitmap& disabledBitmap = wxNullBitmap);
    size_t GetTabOffset() const;
    void SetTabOffset(size_t offset);
    bool IsTabVisible(int tabPage, int tabOffset, wxDC* dc, wxWindow* wnd);
    void MakeTabVisible(int tabPage, wxWindow* win);
protected:
    virtual void Render(wxDC* dc, wxWindow* wnd);
protected:
    wxAuiTabArt* m_art;
    wxAuiNotebookPageArray m_pages;
    wxAuiTabContainerButtonArray m_buttons;
    wxAuiTabContainerButtonArray m_tabCloseButtons;
    wxRect m_rect;
    size_t m_tabOffset;
    unsigned int m_flags;
};
WXGO_DECL_TYPECONV(AuiTabArt)
class wxAuiTabArt
{
public:
    wxAuiTabArt();
    virtual wxAuiTabArt* Clone() = 0;
    virtual void DrawBackground(wxDC& dc, wxWindow* wnd, const wxRect& rect) = 0;
    virtual void DrawButton(wxDC& dc, wxWindow* wnd, const wxRect& in_rect,
                            int bitmap_id, int button_state, int orientation,
                            wxRect* out_rect) = 0;
    virtual void DrawTab(wxDC& dc, wxWindow* wnd, const wxAuiNotebookPage& page,
                         const wxRect& rect, int close_button_state,
                         wxRect* out_tab_rect, wxRect* out_button_rect, int* x_extent) = 0;
    virtual int GetBestTabCtrlSize(wxWindow*, const wxAuiNotebookPageArray&, const wxSize&) = 0;
    virtual int GetIndentSize() = 0;
    virtual wxSize GetTabSize(wxDC& dc, wxWindow* wnd, const wxString& caption,
                              const wxBitmap& bitmap, bool active,
                              int close_button_state, int* x_extent) = 0;
    virtual void SetFlags(unsigned int flags) = 0;
    virtual void SetMeasuringFont(const wxFont& font) = 0;
    virtual void SetNormalFont(const wxFont& font) = 0;
    virtual void SetSelectedFont(const wxFont& font) = 0;
    virtual void SetColour(const wxColour& colour) = 0;
    virtual void SetActiveColour(const wxColour& colour) = 0;
    virtual void SetSizingInfo(const wxSize& tab_ctrl_size, size_t tab_count) = 0;
};
WXGO_DECL_TYPECONV(AuiNotebookEvent)
class wxAuiNotebookEvent : public wxBookCtrlEvent
{
public:
    wxAuiNotebookEvent(wxEventType command_type = wxEVT_NULL, int win_id = 0);
    wxEvent *Clone();
};
%constant wxEventType wxEVT_AUINOTEBOOK_PAGE_CLOSE;
%constant wxEventType wxEVT_AUINOTEBOOK_PAGE_CLOSED;
%constant wxEventType wxEVT_AUINOTEBOOK_PAGE_CHANGED;
%constant wxEventType wxEVT_AUINOTEBOOK_PAGE_CHANGING;
%constant wxEventType wxEVT_AUINOTEBOOK_BUTTON;
%constant wxEventType wxEVT_AUINOTEBOOK_BEGIN_DRAG;
%constant wxEventType wxEVT_AUINOTEBOOK_END_DRAG;
%constant wxEventType wxEVT_AUINOTEBOOK_DRAG_MOTION;
%constant wxEventType wxEVT_AUINOTEBOOK_ALLOW_DND;
%constant wxEventType wxEVT_AUINOTEBOOK_DRAG_DONE;
%constant wxEventType wxEVT_AUINOTEBOOK_TAB_MIDDLE_DOWN;
%constant wxEventType wxEVT_AUINOTEBOOK_TAB_MIDDLE_UP;
%constant wxEventType wxEVT_AUINOTEBOOK_TAB_RIGHT_DOWN;
%constant wxEventType wxEVT_AUINOTEBOOK_TAB_RIGHT_UP;
%constant wxEventType wxEVT_AUINOTEBOOK_BG_DCLICK;
WXGO_DECL_TYPECONV(AuiDefaultTabArt)
class wxAuiDefaultTabArt : public wxAuiTabArt
{
public:
    wxAuiDefaultTabArt();
    virtual ~wxAuiDefaultTabArt();
    wxAuiTabArt* Clone();
    void SetFlags(unsigned int flags);
    void SetSizingInfo(const wxSize& tabCtrlSize,
                       size_t tabCount);
    void SetNormalFont(const wxFont& font);
    void SetSelectedFont(const wxFont& font);
    void SetMeasuringFont(const wxFont& font);
    void SetColour(const wxColour& colour);
    void SetActiveColour(const wxColour& colour);
    void DrawBackground(
                 wxDC& dc,
                 wxWindow* wnd,
                 const wxRect& rect);
    void DrawTab(wxDC& dc,
                 wxWindow* wnd,
                 const wxAuiNotebookPage& pane,
                 const wxRect& inRect,
                 int closeButtonState,
                 wxRect* outTabRect,
                 wxRect* outButtonRect,
                 int* xExtent);
    void DrawButton(
                 wxDC& dc,
                 wxWindow* wnd,
                 const wxRect& inRect,
                 int bitmapId,
                 int buttonState,
                 int orientation,
                 wxRect* outRect);
    int GetIndentSize();
    wxSize GetTabSize(
                 wxDC& dc,
                 wxWindow* wnd,
                 const wxString& caption,
                 const wxBitmap& bitmap,
                 bool active,
                 int closeButtonState,
                 int* xExtent);
    int ShowDropDown(
                 wxWindow* wnd,
                 const wxAuiNotebookPageArray& items,
                 int activeIdx);
    int GetBestTabCtrlSize(wxWindow* wnd,
                 const wxAuiNotebookPageArray& pages,
                 const wxSize& requiredBmpSize);
protected:
    wxFont m_normalFont;
    wxFont m_selectedFont; 
    wxFont m_measuringFont;
    wxColour m_baseColour;
    wxPen m_baseColourPen;
    wxPen m_borderPen;
    wxBrush m_baseColourBrush;
    wxColour m_activeColour;
    wxBitmap m_activeCloseBmp;
    wxBitmap m_disabledCloseBmp;
    wxBitmap m_activeLeftBmp;
    wxBitmap m_disabledLeftBmp;
    wxBitmap m_activeRightBmp;
    wxBitmap m_disabledRightBmp;
    wxBitmap m_activeWindowListBmp;
    wxBitmap m_disabledWindowListBmp;
    int m_fixedTabWidth;
    int m_tabCtrlHeight;
    unsigned int m_flags;
};
WXGO_DECL_TYPECONV(AuiSimpleTabArt)
class wxAuiSimpleTabArt : public wxAuiTabArt
{
public:
    wxAuiSimpleTabArt();
    virtual ~wxAuiSimpleTabArt();
    wxAuiTabArt* Clone();
    void SetFlags(unsigned int flags);
    void SetSizingInfo(const wxSize& tabCtrlSize,
                       size_t tabCount);
    void SetNormalFont(const wxFont& font);
    void SetSelectedFont(const wxFont& font);
    void SetMeasuringFont(const wxFont& font);
    void SetColour(const wxColour& colour);
    void SetActiveColour(const wxColour& colour);
    void DrawBackground(
                 wxDC& dc,
                 wxWindow* wnd,
                 const wxRect& rect);
    void DrawTab(wxDC& dc,
                 wxWindow* wnd,
                 const wxAuiNotebookPage& pane,
                 const wxRect& inRect,
                 int closeButtonState,
                 wxRect* outTabRect,
                 wxRect* outButtonRect,
                 int* xExtent);
    void DrawButton(
                 wxDC& dc,
                 wxWindow* wnd,
                 const wxRect& inRect,
                 int bitmapId,
                 int buttonState,
                 int orientation,
                 wxRect* outRect);
    int GetIndentSize();
    wxSize GetTabSize(
                 wxDC& dc,
                 wxWindow* wnd,
                 const wxString& caption,
                 const wxBitmap& bitmap,
                 bool active,
                 int closeButtonState,
                 int* xExtent);
    int ShowDropDown(
                 wxWindow* wnd,
                 const wxAuiNotebookPageArray& items,
                 int activeIdx);
    int GetBestTabCtrlSize(wxWindow* wnd,
                 const wxAuiNotebookPageArray& pages,
                 const wxSize& requiredBmpSize);
protected:
    wxFont m_normalFont;
    wxFont m_selectedFont;
    wxFont m_measuringFont;
    wxPen m_normalBkPen;
    wxPen m_selectedBkPen;
    wxBrush m_normalBkBrush;
    wxBrush m_selectedBkBrush;
    wxBrush m_bkBrush;
    wxBitmap m_activeCloseBmp;
    wxBitmap m_disabledCloseBmp;
    wxBitmap m_activeLeftBmp;
    wxBitmap m_disabledLeftBmp;
    wxBitmap m_activeRightBmp;
    wxBitmap m_disabledRightBmp;
    wxBitmap m_activeWindowListBmp;
    wxBitmap m_disabledWindowListBmp;
    int m_fixedTabWidth;
    unsigned int m_flags;
};