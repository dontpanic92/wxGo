enum
{
    wxTL_SINGLE         = 0x0000,       
    wxTL_MULTIPLE       = 0x0001,       
    wxTL_CHECKBOX       = 0x0002,       
    wxTL_3STATE         = 0x0004,       
    wxTL_USER_3STATE    = 0x0008,       
    wxTL_NO_HEADER      = 0x0010,
    wxTL_DEFAULT_STYLE  = wxTL_SINGLE,
    wxTL_STYLE_MASK     = wxTL_SINGLE |
                          wxTL_MULTIPLE |
                          wxTL_CHECKBOX |
                          wxTL_3STATE |
                          wxTL_USER_3STATE
};
WXGO_DECL_TYPECONV(TreeListItem)
class wxTreeListItem
{
public:
    wxTreeListItem();
    bool IsOk() const;
};
WXGO_DECL_TYPECONV(TreeListItemComparator)
class wxTreeListItemComparator
{
public:
    wxTreeListItemComparator();
    virtual int
    Compare(wxTreeListCtrl* treelist,
            unsigned column,
            wxTreeListItem first,
            wxTreeListItem second) = 0;
    virtual ~wxTreeListItemComparator();
};
typedef wxVector<wxTreeListItem> wxTreeListItems;
extern const wxTreeListItem wxTLI_FIRST;
extern const wxTreeListItem wxTLI_LAST;
WXGO_DECL_TYPECONV(TreeListCtrl)
class wxTreeListCtrl : public wxWindow
{
public:
    wxTreeListCtrl();
    wxTreeListCtrl(wxWindow* parent,
                   wxWindowID id,
                   const wxPoint& pos = wxDefaultPosition,
                   const wxSize& size = wxDefaultSize,
                   long style = wxTL_DEFAULT_STYLE,
                   const wxString& name = wxTreeListCtrlNameStr);
    bool Create(wxWindow* parent,
                wxWindowID id,
                const wxPoint& pos = wxDefaultPosition,
                const wxSize& size = wxDefaultSize,
                long style = wxTL_DEFAULT_STYLE,
                const wxString& name = wxTreeListCtrlNameStr);
    static const int NO_IMAGE = -1;
    void AssignImageList(wxImageList* imageList);
    void SetImageList(wxImageList* imageList);
    int AppendColumn(const wxString& title,
                     int width = wxCOL_WIDTH_AUTOSIZE,
                     wxAlignment align = wxALIGN_LEFT,
                     int flags = wxCOL_RESIZABLE);
    unsigned GetColumnCount() const;
    bool DeleteColumn(unsigned col);
    void ClearColumns();
    void SetColumnWidth(unsigned col, int width);
    int GetColumnWidth(unsigned col) const;
    int WidthFor(const wxString& text) const;
    wxTreeListItem AppendItem(wxTreeListItem parent,
                              const wxString& text,
                              int imageClosed = NO_IMAGE,
                              int imageOpened = NO_IMAGE,
                              wxClientData* data = NULL);
    wxTreeListItem InsertItem(wxTreeListItem parent,
                              wxTreeListItem previous,
                              const wxString& text,
                              int imageClosed = NO_IMAGE,
                              int imageOpened = NO_IMAGE,
                              wxClientData* data = NULL);
    wxTreeListItem PrependItem(wxTreeListItem parent,
                               const wxString& text,
                               int imageClosed = NO_IMAGE,
                               int imageOpened = NO_IMAGE,
                               wxClientData* data = NULL);
    void DeleteItem(wxTreeListItem item);
    void DeleteAllItems();
    wxTreeListItem GetRootItem() const;
    wxTreeListItem GetItemParent(wxTreeListItem item) const;
    wxTreeListItem GetFirstChild(wxTreeListItem item) const;
    wxTreeListItem GetNextSibling(wxTreeListItem item) const;
    wxTreeListItem GetFirstItem() const;
    wxTreeListItem GetNextItem(wxTreeListItem item) const;
    const wxString& GetItemText(wxTreeListItem item, unsigned col = 0) const;
    void SetItemText(wxTreeListItem item, unsigned col, const wxString& text);
    void SetItemText(wxTreeListItem item, const wxString& text);
    void SetItemImage(wxTreeListItem item, int closed, int opened = NO_IMAGE);
    wxClientData* GetItemData(wxTreeListItem item) const;
    void SetItemData(wxTreeListItem item, wxClientData* data);
    void Expand(wxTreeListItem item);
    void Collapse(wxTreeListItem item);
    bool IsExpanded(wxTreeListItem item) const;
    wxTreeListItem GetSelection() const;
    unsigned GetSelections(wxTreeListItems& selections) const;
    void Select(wxTreeListItem item);
    void Unselect(wxTreeListItem item);
    bool IsSelected(wxTreeListItem item) const;
    void SelectAll();
    void UnselectAll();
    void EnsureVisible(wxTreeListItem item);
    void CheckItem(wxTreeListItem item, wxCheckBoxState state = wxCHK_CHECKED);
    void CheckItemRecursively(wxTreeListItem item,
                              wxCheckBoxState state = wxCHK_CHECKED);
    void UncheckItem(wxTreeListItem item);
    void UpdateItemParentStateRecursively(wxTreeListItem item);
    wxCheckBoxState GetCheckedState(wxTreeListItem item) const;
    bool AreAllChildrenInState(wxTreeListItem item,
                               wxCheckBoxState state) const;
    void SetSortColumn(unsigned col, bool ascendingOrder = true);
    bool GetSortColumn(unsigned* col, bool* ascendingOrder = NULL);
    void SetItemComparator(wxTreeListItemComparator* comparator);
    wxWindow* GetView() const;
    wxDataViewCtrl* GetDataView() const;
};
WXGO_DECL_TYPECONV(TreeListEvent)
class wxTreeListEvent : public wxNotifyEvent
{
public:
    wxTreeListEvent();
    wxTreeListItem GetItem() const;
    wxCheckBoxState GetOldCheckedState() const;
    unsigned GetColumn() const;
};
#define wxTreeListEventHandler(func) \
    wxEVENT_HANDLER_CAST(wxTreeListEventFunction, func)
%constant wxEventType wxEVT_TREELIST_SELECTION_CHANGED;
%constant wxEventType wxEVT_TREELIST_ITEM_EXPANDING;
%constant wxEventType wxEVT_TREELIST_ITEM_EXPANDED;
%constant wxEventType wxEVT_TREELIST_ITEM_CHECKED;
%constant wxEventType wxEVT_TREELIST_ITEM_ACTIVATED;
%constant wxEventType wxEVT_TREELIST_ITEM_CONTEXT_MENU;
%constant wxEventType wxEVT_TREELIST_COLUMN_SORTED;