WXGO_DECL_TYPECONV(TreeCtrl)
class wxTreeCtrl : public wxControl
{
public:
    wxTreeCtrl();
    wxTreeCtrl(wxWindow* parent, wxWindowID id = wxID_ANY,
               const wxPoint& pos = wxDefaultPosition,
               const wxSize& size = wxDefaultSize,
               long style = wxTR_DEFAULT_STYLE,
               const wxValidator& validator = wxDefaultValidator,
               const wxString& name = wxTreeCtrlNameStr);
    virtual ~wxTreeCtrl();
    virtual wxTreeItemId AddRoot(const wxString& text, int image = -1,
                                 int selImage = -1,
                                 wxTreeItemData* data = NULL);
    wxTreeItemId AppendItem(const wxTreeItemId& parent,
                            const wxString& text,
                            int image = -1,
                            int selImage = -1,
                            wxTreeItemData* data = NULL);
#ifndef __WXMSW__
    void AssignButtonsImageList(wxImageList* imageList);
#endif
    void AssignImageList(wxImageList* imageList);
    void AssignStateImageList(wxImageList* imageList);
    virtual void Collapse(const wxTreeItemId& item);
    void CollapseAll();
    void CollapseAllChildren(const wxTreeItemId& item);
    virtual void CollapseAndReset(const wxTreeItemId& item);
    bool Create(wxWindow* parent, wxWindowID id = wxID_ANY,
                const wxPoint& pos = wxDefaultPosition,
                const wxSize& size = wxDefaultSize,
                long style = wxTR_DEFAULT_STYLE,
                const wxValidator& validator = wxDefaultValidator,
                const wxString& name = wxTreeCtrlNameStr);
    virtual void Delete(const wxTreeItemId& item);
    virtual void DeleteAllItems();
    virtual void DeleteChildren(const wxTreeItemId& item);
    virtual wxTextCtrl *EditLabel(const wxTreeItemId& item,
                                  wxClassInfo* textCtrlClass = wxCLASSINFO(wxTextCtrl));
    void EnableBellOnNoMatch(bool on = true);
    virtual void EndEditLabel(const wxTreeItemId& item, bool discardChanges = false);
    virtual void EnsureVisible(const wxTreeItemId& item);
    virtual void Expand(const wxTreeItemId& item);
    void ExpandAll();
    void ExpandAllChildren(const wxTreeItemId& item);
    virtual bool GetBoundingRect(const wxTreeItemId& item, wxRect& rect,
                                 bool textOnly = false) const;
#ifndef __WXMSW__
    wxImageList* GetButtonsImageList() const;
#endif
    virtual size_t GetChildrenCount(const wxTreeItemId& item,
                                    bool recursively = true) const;
    virtual unsigned int GetCount() const;
    virtual wxTextCtrl* GetEditControl() const;
    virtual wxTreeItemId GetFirstChild(const wxTreeItemId& item,
                                       wxTreeItemIdValue& cookie) const;
    virtual wxTreeItemId GetFirstVisibleItem() const;
    virtual wxTreeItemId GetFocusedItem() const;
    virtual void ClearFocusedItem();
    virtual void SetFocusedItem(const wxTreeItemId& item);
    wxImageList* GetImageList() const;
    virtual unsigned int GetIndent() const;
    virtual wxColour GetItemBackgroundColour(const wxTreeItemId& item) const;
    virtual wxTreeItemData* GetItemData(const wxTreeItemId& item) const;
    virtual wxFont GetItemFont(const wxTreeItemId& item) const;
    virtual int GetItemImage(const wxTreeItemId& item,
                             wxTreeItemIcon which = wxTreeItemIcon_Normal) const;
    virtual wxTreeItemId GetItemParent(const wxTreeItemId& item) const;
    int GetItemState(const wxTreeItemId& item) const;
    virtual wxString GetItemText(const wxTreeItemId& item) const;
    virtual wxColour GetItemTextColour(const wxTreeItemId& item) const;
    virtual wxTreeItemId GetLastChild(const wxTreeItemId& item) const;
    virtual wxTreeItemId GetNextChild(const wxTreeItemId& item,
                                      wxTreeItemIdValue& cookie) const;
    virtual wxTreeItemId GetNextSibling(const wxTreeItemId& item) const;
    virtual wxTreeItemId GetNextVisible(const wxTreeItemId& item) const;
    virtual wxTreeItemId GetPrevSibling(const wxTreeItemId& item) const;
    virtual wxTreeItemId GetPrevVisible(const wxTreeItemId& item) const;
    bool GetQuickBestSize() const;
    virtual wxTreeItemId GetRootItem() const;
    virtual wxTreeItemId GetSelection() const;
    virtual size_t GetSelections(wxArrayTreeItemIds& selection) const;
    wxImageList* GetStateImageList() const;
    wxTreeItemId HitTest(const wxPoint& point, int& flags) const;
    wxTreeItemId InsertItem(const wxTreeItemId& parent,
                            const wxTreeItemId& previous,
                            const wxString& text,
                            int image = -1,
                            int selImage = -1,
                            wxTreeItemData* data = NULL);
    wxTreeItemId InsertItem(const wxTreeItemId& parent,
                            size_t pos,
                            const wxString& text,
                            int image = -1,
                            int selImage = -1,
                            wxTreeItemData* data = NULL);
    virtual bool IsBold(const wxTreeItemId& item) const;
    bool IsEmpty() const;
    virtual bool IsExpanded(const wxTreeItemId& item) const;
    virtual bool IsSelected(const wxTreeItemId& item) const;
    virtual bool IsVisible(const wxTreeItemId& item) const;
    virtual bool ItemHasChildren(const wxTreeItemId& item) const;
    virtual int OnCompareItems(const wxTreeItemId& item1,
                               const wxTreeItemId& item2);
    wxTreeItemId PrependItem(const wxTreeItemId& parent,
                             const wxString& text,
                             int image = -1,
                             int selImage = -1,
                             wxTreeItemData* data = NULL);
    virtual void ScrollTo(const wxTreeItemId& item);
    virtual void SelectItem(const wxTreeItemId& item, bool select = true);
#ifndef __WXMSW__
    void SetButtonsImageList(wxImageList* imageList);
#endif
    virtual void SetImageList(wxImageList* imageList);
    virtual void SetIndent(unsigned int indent);
    virtual void SetItemBackgroundColour(const wxTreeItemId& item,
                                         const wxColour& col);
    virtual void SetItemBold(const wxTreeItemId& item, bool bold = true);
    virtual void SetItemData(const wxTreeItemId& item, wxTreeItemData* data);
    virtual void SetItemDropHighlight(const wxTreeItemId& item,
                                      bool highlight = true);
    virtual void SetItemFont(const wxTreeItemId& item, const wxFont& font);
    virtual void SetItemHasChildren(const wxTreeItemId& item,
                                    bool hasChildren = true);
    virtual void SetItemImage(const wxTreeItemId& item, int image,
                              wxTreeItemIcon which = wxTreeItemIcon_Normal);
    void SetItemState(const wxTreeItemId& item, int state);
    virtual void SetItemText(const wxTreeItemId& item, const wxString& text);
    virtual void SetItemTextColour(const wxTreeItemId& item,
                                   const wxColour& col);
    void SetQuickBestSize(bool quickBestSize);
    virtual void SetStateImageList(wxImageList* imageList);
    void SetWindowStyle(long styles);
    virtual void SortChildren(const wxTreeItemId& item);
    virtual void Toggle(const wxTreeItemId& item);
    void ToggleItemSelection(const wxTreeItemId& item);
    virtual void Unselect();
    virtual void UnselectAll();
    void UnselectItem(const wxTreeItemId& item);
    virtual void SelectChildren(const wxTreeItemId& parent);
};
WXGO_DECL_TYPECONV(TreeEvent)
class wxTreeEvent : public wxNotifyEvent
{
public:
    wxTreeEvent(wxEventType commandType, wxTreeCtrl* tree,
                const wxTreeItemId& item = wxTreeItemId());
    wxTreeItemId GetItem() const;
    int GetKeyCode() const;
    const wxKeyEvent& GetKeyEvent() const;
    const wxString& GetLabel() const;
    wxTreeItemId GetOldItem() const;
    wxPoint GetPoint() const;
    bool IsEditCancelled() const;
    void SetToolTip(const wxString& tooltip);
};
%constant wxEventType wxEVT_TREE_BEGIN_DRAG;
%constant wxEventType wxEVT_TREE_BEGIN_RDRAG;
%constant wxEventType wxEVT_TREE_BEGIN_LABEL_EDIT;
%constant wxEventType wxEVT_TREE_END_LABEL_EDIT;
%constant wxEventType wxEVT_TREE_DELETE_ITEM;
%constant wxEventType wxEVT_TREE_GET_INFO;
%constant wxEventType wxEVT_TREE_SET_INFO;
%constant wxEventType wxEVT_TREE_ITEM_EXPANDED;
%constant wxEventType wxEVT_TREE_ITEM_EXPANDING;
%constant wxEventType wxEVT_TREE_ITEM_COLLAPSED;
%constant wxEventType wxEVT_TREE_ITEM_COLLAPSING;
%constant wxEventType wxEVT_TREE_SEL_CHANGED;
%constant wxEventType wxEVT_TREE_SEL_CHANGING;
%constant wxEventType wxEVT_TREE_KEY_DOWN;
%constant wxEventType wxEVT_TREE_ITEM_ACTIVATED;
%constant wxEventType wxEVT_TREE_ITEM_RIGHT_CLICK;
%constant wxEventType wxEVT_TREE_ITEM_MIDDLE_CLICK;
%constant wxEventType wxEVT_TREE_END_DRAG;
%constant wxEventType wxEVT_TREE_STATE_IMAGE_CLICK;
%constant wxEventType wxEVT_TREE_ITEM_GETTOOLTIP;
%constant wxEventType wxEVT_TREE_ITEM_MENU;