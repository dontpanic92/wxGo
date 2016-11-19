#define wxLC_VRULES          0x0001
#define wxLC_HRULES          0x0002
#define wxLC_ICON            0x0004
#define wxLC_SMALL_ICON      0x0008
#define wxLC_LIST            0x0010
#define wxLC_REPORT          0x0020
#define wxLC_ALIGN_TOP       0x0040
#define wxLC_ALIGN_LEFT      0x0080
#define wxLC_AUTOARRANGE     0x0100
#define wxLC_VIRTUAL         0x0200
#define wxLC_EDIT_LABELS     0x0400
#define wxLC_NO_HEADER       0x0800
#define wxLC_NO_SORT_HEADER  0x1000
#define wxLC_SINGLE_SEL      0x2000
#define wxLC_SORT_ASCENDING  0x4000
#define wxLC_SORT_DESCENDING 0x8000
#define wxLC_MASK_TYPE       (wxLC_ICON | wxLC_SMALL_ICON | wxLC_LIST | wxLC_REPORT)
#define wxLC_MASK_ALIGN      (wxLC_ALIGN_TOP | wxLC_ALIGN_LEFT)
#define wxLC_MASK_SORT       (wxLC_SORT_ASCENDING | wxLC_SORT_DESCENDING)
#define wxLIST_MASK_STATE           0x0001
#define wxLIST_MASK_TEXT            0x0002
#define wxLIST_MASK_IMAGE           0x0004
#define wxLIST_MASK_DATA            0x0008
#define wxLIST_SET_ITEM             0x0010
#define wxLIST_MASK_WIDTH           0x0020
#define wxLIST_MASK_FORMAT          0x0040
#define wxLIST_STATE_DONTCARE       0x0000
#define wxLIST_STATE_DROPHILITED    0x0001      
#define wxLIST_STATE_FOCUSED        0x0002
#define wxLIST_STATE_SELECTED       0x0004
#define wxLIST_STATE_CUT            0x0008      
#define wxLIST_HITTEST_ABOVE            0x0001  
#define wxLIST_HITTEST_BELOW            0x0002  
#define wxLIST_HITTEST_NOWHERE          0x0004  
#define wxLIST_HITTEST_ONITEMICON       0x0020  
#define wxLIST_HITTEST_ONITEMLABEL      0x0080  
#define wxLIST_HITTEST_ONITEMRIGHT      0x0100  
#define wxLIST_HITTEST_ONITEMSTATEICON  0x0200  
#define wxLIST_HITTEST_TOLEFT           0x0400  
#define wxLIST_HITTEST_TORIGHT          0x0800  
#define wxLIST_HITTEST_ONITEM (wxLIST_HITTEST_ONITEMICON | wxLIST_HITTEST_ONITEMLABEL | wxLIST_HITTEST_ONITEMSTATEICON)
#define wxLIST_GETSUBITEMRECT_WHOLEITEM -1l
enum
{
    wxLIST_NEXT_ABOVE,          
    wxLIST_NEXT_ALL,            
    wxLIST_NEXT_BELOW,          
    wxLIST_NEXT_LEFT,           
    wxLIST_NEXT_RIGHT           
};
enum
{
    wxLIST_ALIGN_DEFAULT,
    wxLIST_ALIGN_LEFT,
    wxLIST_ALIGN_TOP,
    wxLIST_ALIGN_SNAP_TO_GRID
};
%typedef int wxListColumnFormat;
#define wxLIST_FORMAT_LEFT 0
#define wxLIST_FORMAT_RIGHT wxLIST_FORMAT_LEFT + 1
#define wxLIST_FORMAT_CENTRE wxLIST_FORMAT_RIGHT + 1
#define wxLIST_FORMAT_CENTER  wxLIST_FORMAT_CENTRE
enum
{
    wxLIST_AUTOSIZE = -1,
    wxLIST_AUTOSIZE_USEHEADER = -2      
};
enum
{
    wxLIST_RECT_BOUNDS,
    wxLIST_RECT_ICON,
    wxLIST_RECT_LABEL
};
enum
{
    wxLIST_FIND_UP,
    wxLIST_FIND_DOWN,
    wxLIST_FIND_LEFT,
    wxLIST_FIND_RIGHT
};
WXGO_DECL_TYPECONV(ListCtrl)
class wxListCtrl : public wxControl
{
public:
    wxListCtrl();
    wxListCtrl(wxWindow* parent, wxWindowID id,
               const wxPoint& pos = wxDefaultPosition,
               const wxSize& size = wxDefaultSize,
               long style = wxLC_ICON,
               const wxValidator& validator = wxDefaultValidator,
               const wxString& name = wxListCtrlNameStr);
    virtual ~wxListCtrl();
    long AppendColumn(const wxString& heading,
                      wxListColumnFormat format = wxLIST_FORMAT_LEFT,
                      int width = -1);
    bool Arrange(int flag = wxLIST_ALIGN_DEFAULT);
    void AssignImageList(wxImageList* imageList, int which);
    void ClearAll();
    bool Create(wxWindow* parent, wxWindowID id,
                const wxPoint& pos = wxDefaultPosition,
                const wxSize& size = wxDefaultSize,
                long style = wxLC_ICON,
                const wxValidator& validator = wxDefaultValidator,
                const wxString& name = wxListCtrlNameStr);
    bool DeleteAllItems();
    bool DeleteColumn(int col);
    bool DeleteItem(long item);
    wxTextCtrl* EditLabel(long item,
                          wxClassInfo* textControlClass = wxCLASSINFO(wxTextCtrl));
    void EnableAlternateRowColours(bool enable = true);
    void EnableBellOnNoMatch(bool on = true);
    bool EndEditLabel(bool cancel);
    bool EnsureVisible(long item);
    long FindItem(long start, const wxString& str,
                  bool partial = false);
    long FindItem(long start, wxUIntPtr data);
    long FindItem(long start, const wxPoint& pt, int direction);
    bool GetColumn(int col, wxListItem& item) const;
    int GetColumnCount() const;
#ifdef __WXMSW__
    int GetColumnIndexFromOrder(int pos) const;
#endif
#ifdef __WXMSW__
    int GetColumnOrder(int col) const;
#endif
    int GetColumnWidth(int col) const;
#ifdef __WXMSW__
    wxArrayInt GetColumnsOrder() const;
#endif
    int GetCountPerPage() const;
    wxTextCtrl* GetEditControl() const;
    wxImageList* GetImageList(int which) const;
    bool GetItem(wxListItem& info) const;
    wxColour GetItemBackgroundColour(long item) const;
    int GetItemCount() const;
    wxUIntPtr GetItemData(long item) const;
    wxFont GetItemFont(long item) const;
    bool GetItemPosition(long item, wxPoint& pos) const;
    bool GetItemRect(long item, wxRect& rect,
                     int code = wxLIST_RECT_BOUNDS) const;
    wxSize GetItemSpacing() const;
    int GetItemState(long item, long stateMask) const;
    wxString GetItemText(long item, int col = 0) const;
    wxColour GetItemTextColour(long item) const;
    long GetNextItem(long item, int geometry = wxLIST_NEXT_ALL,
                     int state = wxLIST_STATE_DONTCARE) const;
    int GetSelectedItemCount() const;
    bool GetSubItemRect(long item, long subItem, wxRect& rect,
                        int code = wxLIST_RECT_BOUNDS) const;
    wxColour GetTextColour() const;
    long GetTopItem() const;
    wxRect GetViewRect() const;
    void SetAlternateRowColour(const wxColour& colour);
    wxColour GetAlternateRowColour() const;
    long HitTest(const wxPoint& point, int& flags, long* ptrSubItem = NULL) const;
    bool InReportView() const;
    long InsertColumn(long col, const wxListItem& info);
    long InsertColumn(long col, const wxString& heading,
                      int format = wxLIST_FORMAT_LEFT,
                      int width = wxLIST_AUTOSIZE);
    long InsertItem(wxListItem& info);
    long InsertItem(long index, const wxString& label);
    long InsertItem(long index, int imageIndex);
    long InsertItem(long index, const wxString& label,
                    int imageIndex);
    bool IsVirtual() const;
    void RefreshItem(long item);
    void RefreshItems(long itemFrom, long itemTo);
    bool ScrollList(int dx, int dy);
    virtual bool SetBackgroundColour(const wxColour& col);
    bool SetColumn(int col, wxListItem& item);
    bool SetColumnWidth(int col, int width);
#ifdef __WXMSW__
    bool SetColumnsOrder(const wxArrayInt& orders);
#endif
    void SetImageList(wxImageList* imageList, int which);
    bool SetItem(wxListItem& info);
    long SetItem(long index, int column, const wxString& label, int imageId = -1);
    void SetItemBackgroundColour(long item, const wxColour& col);
    bool SetItemColumnImage(long item, long column, int image);
    void SetItemCount(long count);
    bool SetItemData(long item, long data);
    void SetItemFont(long item, const wxFont& font);
    bool SetItemImage(long item, int image, int selImage = -1);
    bool SetItemPosition(long item, const wxPoint& pos);
    bool SetItemPtrData(long item, wxUIntPtr data);
    bool SetItemState(long item, long state, long stateMask);
    void SetItemText(long item, const wxString& text);
    void SetItemTextColour(long item, const wxColour& col);
    void SetSingleStyle(long style, bool add = true);
    void SetTextColour(const wxColour& col);
    void SetWindowStyleFlag(long style);
    bool SortItems(wxListCtrlCompare fnSortCallBack, wxIntPtr data);
    bool HasCheckboxes() const;
    bool EnableCheckboxes(bool enable = true);
    bool IsItemChecked(long item) const;
    void CheckItem(long item, bool check);
protected:
    virtual wxListItemAttr* OnGetItemAttr(long item) const;
    virtual wxListItemAttr* OnGetItemColumnAttr(long item, long column) const;
    virtual int OnGetItemColumnImage(long item, long column) const;
    virtual int OnGetItemImage(long item) const;
    virtual wxString OnGetItemText(long item, long column) const;
};
WXGO_DECL_TYPECONV(ListEvent)
class wxListEvent : public wxNotifyEvent
{
public:
    wxListEvent(wxEventType commandType = wxEVT_NULL, int id = 0);
    long GetCacheFrom() const;
    long GetCacheTo() const;
    int GetColumn() const;
    wxUIntPtr GetData() const;
    int GetImage() const;
    long GetIndex() const;
    const wxListItem& GetItem() const;
    int GetKeyCode() const;
    const wxString& GetLabel() const;
    long GetMask() const;
    wxPoint GetPoint() const;
    const wxString& GetText() const;
    bool IsEditCancelled() const;
};
%constant wxEventType wxEVT_LIST_BEGIN_DRAG;
%constant wxEventType wxEVT_LIST_BEGIN_RDRAG;
%constant wxEventType wxEVT_LIST_BEGIN_LABEL_EDIT;
%constant wxEventType wxEVT_LIST_END_LABEL_EDIT;
%constant wxEventType wxEVT_LIST_DELETE_ITEM;
%constant wxEventType wxEVT_LIST_DELETE_ALL_ITEMS;
%constant wxEventType wxEVT_LIST_ITEM_SELECTED;
%constant wxEventType wxEVT_LIST_ITEM_DESELECTED;
%constant wxEventType wxEVT_LIST_KEY_DOWN;
%constant wxEventType wxEVT_LIST_INSERT_ITEM;
%constant wxEventType wxEVT_LIST_COL_CLICK;
%constant wxEventType wxEVT_LIST_ITEM_RIGHT_CLICK;
%constant wxEventType wxEVT_LIST_ITEM_MIDDLE_CLICK;
%constant wxEventType wxEVT_LIST_ITEM_ACTIVATED;
%constant wxEventType wxEVT_LIST_CACHE_HINT;
%constant wxEventType wxEVT_LIST_COL_RIGHT_CLICK;
%constant wxEventType wxEVT_LIST_COL_BEGIN_DRAG;
%constant wxEventType wxEVT_LIST_COL_DRAGGING;
%constant wxEventType wxEVT_LIST_COL_END_DRAG;
%constant wxEventType wxEVT_LIST_ITEM_FOCUSED;
%constant wxEventType wxEVT_LIST_ITEM_CHECKED;
%constant wxEventType wxEVT_LIST_ITEM_UNCHECKED;
WXGO_DECL_TYPECONV(ListItemAttr)
class wxListItemAttr
{
public:
    wxListItemAttr();
    wxListItemAttr(const wxColour& colText,
                   const wxColour& colBack,
                   const wxFont& font);
    const wxColour& GetBackgroundColour() const;
    const wxFont& GetFont() const;
    const wxColour& GetTextColour() const;
    bool HasBackgroundColour() const;
    bool HasFont() const;
    bool HasTextColour() const;
    void SetBackgroundColour(const wxColour& colour);
    void SetFont(const wxFont& font);
    void SetTextColour(const wxColour& colour);
};
WXGO_DECL_TYPECONV(ListView)
class wxListView : public wxListCtrl
{
public:
    wxListView();
    wxListView(wxWindow* parent, wxWindowID winid = wxID_ANY,
               const wxPoint& pos = wxDefaultPosition,
               const wxSize& size = wxDefaultSize,
               long style = wxLC_REPORT,
               const wxValidator& validator = wxDefaultValidator,
               const wxString& name = wxListCtrlNameStr);
    virtual ~wxListView();
    void ClearColumnImage(int col);
    void Focus(long index);
    long GetFirstSelected() const;
    long GetFocusedItem() const;
    long GetNextSelected(long item) const;
    bool IsSelected(long index) const;
    void Select(long n, bool on = true);
    void SetColumnImage(int col, int image);
};
WXGO_DECL_TYPECONV(ListItem)
class wxListItem : public wxObject
{
public:
    wxListItem();
    void Clear();
    wxListColumnFormat GetAlign() const;
    wxColour GetBackgroundColour() const;
    int GetColumn() const;
    wxUIntPtr GetData() const;
    wxFont GetFont() const;
    long GetId() const;
    int GetImage() const;
    long GetMask() const;
    long GetState() const;
    const wxString& GetText() const;
    wxColour GetTextColour() const;
    int GetWidth() const;
    void SetAlign(wxListColumnFormat align);
    void SetBackgroundColour(const wxColour& colBack);
    void SetColumn(int col);
    void SetData(long data);
    void SetData(void* data);
    void SetFont(const wxFont& font);
    void SetId(long id);
    void SetImage(int image);
    void SetMask(long mask);
    void SetState(long state);
    void SetStateMask(long stateMask);
    void SetText(const wxString& text);
    void SetTextColour(const wxColour& colText);
    void SetWidth(int width);
};