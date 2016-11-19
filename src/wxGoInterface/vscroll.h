WXGO_DECL_TYPECONV(VarScrollHelperBase)
class wxVarScrollHelperBase
{
public:
    wxVarScrollHelperBase(wxWindow* winToScroll);
    virtual ~wxVarScrollHelperBase();
    int CalcScrolledPosition(int coord) const;
    int CalcUnscrolledPosition(int coord) const;
    void EnablePhysicalScrolling(bool scrolling = true);
    virtual int GetNonOrientationTargetSize() const = 0;
    virtual wxOrientation GetOrientation() const = 0;
    virtual int GetOrientationTargetSize() const = 0;
    virtual wxWindow* GetTargetWindow() const;
    size_t GetVisibleBegin() const;
    size_t GetVisibleEnd() const;
    bool IsVisible(size_t unit) const;
    virtual void RefreshAll();
    virtual void SetTargetWindow(wxWindow* target);
    virtual void UpdateScrollbar();
    int VirtualHitTest(wxCoord coord) const;
protected:
    virtual void OnGetUnitsSizeHint(size_t unitMin, size_t unitMax) const;
    virtual wxCoord EstimateTotalSize() const;
    virtual wxCoord OnGetUnitSize(size_t unit) const = 0;
};
WXGO_DECL_TYPECONV(VarVScrollHelper)
class wxVarVScrollHelper : public wxVarScrollHelperBase
{
public:
    wxVarVScrollHelper(wxWindow* winToScroll);
    size_t GetRowCount() const;
    size_t GetVisibleRowsBegin() const;
    size_t GetVisibleRowsEnd() const;
    bool IsRowVisible(size_t row) const;
    virtual void RefreshRow(size_t row);
    virtual void RefreshRows(size_t from, size_t to);
    virtual bool ScrollRowPages(int pages);
    virtual bool ScrollRows(int rows);
    bool ScrollToRow(size_t row);
    void SetRowCount(size_t rowCount);
protected:
    virtual void OnGetRowsHeightHint(size_t rowMin, size_t rowMax) const;
    virtual wxCoord EstimateTotalHeight() const;
    virtual wxCoord OnGetRowHeight(size_t row) const = 0;
};
WXGO_DECL_TYPECONV(VarHScrollHelper)
class wxVarHScrollHelper : public wxVarScrollHelperBase
{
public:
    wxVarHScrollHelper(wxWindow* winToScroll);
    size_t GetColumnCount() const;
    size_t GetVisibleColumnsBegin() const;
    size_t GetVisibleColumnsEnd() const;
    bool IsColumnVisible(size_t column) const;
    virtual void RefreshColumn(size_t column);
    virtual void RefreshColumns(size_t from, size_t to);
    virtual bool ScrollColumnPages(int pages);
    virtual bool ScrollColumns(int columns);
    bool ScrollToColumn(size_t column);
    void SetColumnCount(size_t columnCount);
protected:
    virtual wxCoord EstimateTotalWidth() const;
    virtual void OnGetColumnsWidthHint(size_t columnMin,
                                       size_t columnMax) const;
    virtual wxCoord OnGetColumnWidth(size_t column) const = 0;
};
WXGO_DECL_TYPECONV(VarHVScrollHelper)
class wxVarHVScrollHelper : public wxVarVScrollHelper,
                             public wxVarHScrollHelper
{
public:
    wxVarHVScrollHelper(wxWindow* winToScroll);
    void EnablePhysicalScrolling(bool vscrolling = true,
                                 bool hscrolling = true);
    wxSize GetRowColumnCount() const;
    wxPosition GetVisibleBegin() const;
    wxPosition GetVisibleEnd() const;
    bool IsVisible(size_t row, size_t column) const;
    bool IsVisible(const wxPosition& pos) const;
    virtual void RefreshRowColumn(size_t row, size_t column);
    virtual void RefreshRowColumn(const wxPosition& pos);
    virtual void RefreshRowsColumns(size_t fromRow, size_t toRow,
                                    size_t fromColumn, size_t toColumn);
    virtual void RefreshRowsColumns(const wxPosition& from,
                                    const wxPosition& to);
    bool ScrollToRowColumn(size_t row, size_t column);
    bool ScrollToRowColumn(const wxPosition& pos);
    void SetRowColumnCount(size_t rowCount, size_t columnCount);
    wxPosition VirtualHitTest(wxCoord x, wxCoord y) const;
    wxPosition VirtualHitTest(const wxPoint& pos) const;
};
WXGO_DECL_TYPECONV(VScrolledWindow)
class wxVScrolledWindow : public wxPanel, public wxVarVScrollHelper
{
public:
    wxVScrolledWindow();
    wxVScrolledWindow(wxWindow* parent, wxWindowID id = wxID_ANY,
                      const wxPoint& pos = wxDefaultPosition,
                      const wxSize& size = wxDefaultSize, long style = 0,
                      const wxString& name = wxPanelNameStr);
    bool Create(wxWindow* parent, wxWindowID id = wxID_ANY,
                const wxPoint& pos = wxDefaultPosition,
                const wxSize& size = wxDefaultSize, long style = 0,
                const wxString& name = wxPanelNameStr);
};
WXGO_DECL_TYPECONV(HScrolledWindow)
class wxHScrolledWindow : public wxPanel, public wxVarHScrollHelper
{
public:
    wxHScrolledWindow();
    wxHScrolledWindow(wxWindow* parent, wxWindowID id = wxID_ANY,
                      const wxPoint& pos = wxDefaultPosition,
                      const wxSize& size = wxDefaultSize, long style = 0,
                      const wxString& name = wxPanelNameStr);
    bool Create(wxWindow* parent, wxWindowID id = wxID_ANY,
                const wxPoint& pos = wxDefaultPosition,
                const wxSize& size = wxDefaultSize, long style = 0,
                const wxString& name = wxPanelNameStr);
};
WXGO_DECL_TYPECONV(HVScrolledWindow)
class wxHVScrolledWindow : public wxPanel, public wxVarHVScrollHelper
{
public:
    wxHVScrolledWindow();
    wxHVScrolledWindow(wxWindow* parent, wxWindowID id = wxID_ANY,
                       const wxPoint& pos = wxDefaultPosition,
                       const wxSize& size = wxDefaultSize, long style = 0,
                       const wxString& name = wxPanelNameStr);
    bool Create(wxWindow* parent, wxWindowID id = wxID_ANY,
                const wxPoint& pos = wxDefaultPosition,
                const wxSize& size = wxDefaultSize, long style = 0,
                const wxString& name = wxPanelNameStr);
};