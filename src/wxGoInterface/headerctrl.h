enum
{
    wxHD_ALLOW_REORDER = 0x0001,
    wxHD_ALLOW_HIDE = 0x0002,
    wxHD_DEFAULT_STYLE = wxHD_ALLOW_REORDER
};
WXGO_DECL_TYPECONV(HeaderCtrl)
class wxHeaderCtrl : public wxControl
{
public:
    wxHeaderCtrl();
    wxHeaderCtrl(wxWindow *parent,
                 wxWindowID winid = wxID_ANY,
                 const wxPoint& pos = wxDefaultPosition,
                 const wxSize& size = wxDefaultSize,
                 long style = wxHD_DEFAULT_STYLE,
                 const wxString& name = wxHeaderCtrlNameStr);
    bool Create(wxWindow *parent,
                wxWindowID winid = wxID_ANY,
                const wxPoint& pos = wxDefaultPosition,
                const wxSize& size = wxDefaultSize,
                long style = wxHD_DEFAULT_STYLE,
                const wxString& name = wxHeaderCtrlNameStr);
    void SetColumnCount(unsigned int count);
    unsigned int GetColumnCount() const;
    bool IsEmpty() const;
    void UpdateColumn(unsigned int idx);
    void SetColumnsOrder(const wxArrayInt& order);
    wxArrayInt GetColumnsOrder() const;
    unsigned int GetColumnAt(unsigned int pos) const;
    unsigned int GetColumnPos(unsigned int idx) const;
    void ResetColumnsOrder();
    static void MoveColumnInOrderArray(wxArrayInt& order,
                                       unsigned int idx,
                                       unsigned int pos);
    bool ShowColumnsMenu(const wxPoint& pt, const wxString& title = wxString());
    void AddColumnsItems(wxMenu& menu, int idColumnsBase = 0);
    bool ShowCustomizeDialog();
    int GetColumnTitleWidth(const wxHeaderColumn& col);
protected:
    virtual const wxHeaderColumn& GetColumn(unsigned int idx) const = 0;
    virtual void UpdateColumnVisibility(unsigned int idx, bool show);
    virtual void UpdateColumnsOrder(const wxArrayInt& order);
    virtual bool UpdateColumnWidthToFit(unsigned int idx, int widthTitle);
    virtual void OnColumnCountChanging(unsigned int count);
};
WXGO_DECL_TYPECONV(HeaderCtrlSimple)
class wxHeaderCtrlSimple : public wxHeaderCtrl
{
public:
    wxHeaderCtrlSimple();
    wxHeaderCtrlSimple(wxWindow *parent,
                       wxWindowID winid = wxID_ANY,
                       const wxPoint& pos = wxDefaultPosition,
                       const wxSize& size = wxDefaultSize,
                       long style = wxHD_DEFAULT_STYLE,
                       const wxString& name = wxHeaderCtrlNameStr);
    void InsertColumn(const wxHeaderColumnSimple& col, unsigned int idx);
    void AppendColumn(const wxHeaderColumnSimple& col);
    void DeleteColumn(unsigned int idx);
    void ShowColumn(unsigned int idx, bool show = true);
    void HideColumn(unsigned int idx);
    void ShowSortIndicator(unsigned int idx, bool sortOrder = true);
    void RemoveSortIndicator();
protected:
    virtual int GetBestFittingWidth(unsigned int idx) const;
};
WXGO_DECL_TYPECONV(HeaderCtrlEvent)
class wxHeaderCtrlEvent : public wxNotifyEvent
{
public:
    wxHeaderCtrlEvent(wxEventType commandType = wxEVT_NULL, int winid = 0);
    wxHeaderCtrlEvent(const wxHeaderCtrlEvent& event);
    int GetColumn() const;
    void SetColumn(int col);
    int GetWidth() const;
    void SetWidth(int width);
    unsigned int GetNewOrder() const;
    void SetNewOrder(unsigned int order);
};
%constant wxEventType wxEVT_HEADER_CLICK;
%constant wxEventType wxEVT_HEADER_RIGHT_CLICK;
%constant wxEventType wxEVT_HEADER_MIDDLE_CLICK;
%constant wxEventType wxEVT_HEADER_DCLICK;
%constant wxEventType wxEVT_HEADER_RIGHT_DCLICK;
%constant wxEventType wxEVT_HEADER_MIDDLE_DCLICK;
%constant wxEventType wxEVT_HEADER_SEPARATOR_DCLICK;
%constant wxEventType wxEVT_HEADER_BEGIN_RESIZE;
%constant wxEventType wxEVT_HEADER_RESIZING;
%constant wxEventType wxEVT_HEADER_END_RESIZE;
%constant wxEventType wxEVT_HEADER_BEGIN_REORDER;
%constant wxEventType wxEVT_HEADER_END_REORDER;
%constant wxEventType wxEVT_HEADER_DRAGGING_CANCELLED;