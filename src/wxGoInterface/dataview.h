WXGO_DECL_TYPECONV(DataViewModel)
class wxDataViewModel : public wxRefCounter
{
public:
    wxDataViewModel();
    void AddNotifier(wxDataViewModelNotifier* notifier);
    bool ChangeValue(const wxVariant& variant,
                     const wxDataViewItem& item,
                     unsigned int col);
    virtual bool Cleared();
    virtual int Compare(const wxDataViewItem& item1,
                        const wxDataViewItem& item2,
                        unsigned int column,
                        bool ascending) const;
    virtual bool GetAttr(const wxDataViewItem& item, unsigned int col,
                         wxDataViewItemAttr& attr) const;
    virtual bool IsEnabled(const wxDataViewItem &item,
                           unsigned int col) const;
    virtual unsigned int GetChildren(const wxDataViewItem& item,
                                     wxDataViewItemArray& children) const = 0;
    virtual unsigned int GetColumnCount() const = 0;
    virtual wxString GetColumnType(unsigned int col) const = 0;
    virtual wxDataViewItem GetParent(const wxDataViewItem& item) const = 0;
    virtual void GetValue(wxVariant& variant, const wxDataViewItem& item,
                          unsigned int col) const = 0;
    virtual bool HasContainerColumns(const wxDataViewItem& item) const;
    virtual bool HasDefaultCompare() const;
    bool HasValue(const wxDataViewItem& item, unsigned col) const;
    virtual bool IsContainer(const wxDataViewItem& item) const = 0;
    bool ItemAdded(const wxDataViewItem& parent,
                           const wxDataViewItem& item);
    bool ItemChanged(const wxDataViewItem& item);
    bool ItemDeleted(const wxDataViewItem& parent,
                             const wxDataViewItem& item);
    bool ItemsAdded(const wxDataViewItem& parent,
                            const wxDataViewItemArray& items);
    bool ItemsChanged(const wxDataViewItemArray& items);
    bool ItemsDeleted(const wxDataViewItem& parent,
                              const wxDataViewItemArray& items);
    void RemoveNotifier(wxDataViewModelNotifier* notifier);
    virtual void Resort();
    virtual bool SetValue(const wxVariant& variant,
                          const wxDataViewItem& item,
                          unsigned int col) = 0;
    virtual bool ValueChanged(const wxDataViewItem& item,
                              unsigned int col);
    virtual bool IsListModel() const;
    virtual bool IsVirtualListModel() const;
protected:
    virtual ~wxDataViewModel();
};
WXGO_DECL_TYPECONV(DataViewListModel)
class wxDataViewListModel : public wxDataViewModel
{
public:
    virtual ~wxDataViewListModel();
    int Compare(const wxDataViewItem& item1,
                const wxDataViewItem& item2,
                unsigned int column, bool ascending) const;
    virtual bool GetAttrByRow(unsigned int row, unsigned int col,
                         wxDataViewItemAttr& attr) const;
    virtual bool IsEnabledByRow(unsigned int row,
                                unsigned int col) const;
    unsigned int GetCount() const = 0;
    unsigned int GetRow(const wxDataViewItem& item) const = 0;
    virtual void GetValueByRow(wxVariant& variant, unsigned int row,
                               unsigned int col) const = 0;
    virtual bool SetValueByRow(const wxVariant& variant, unsigned int row,
                               unsigned int col) = 0;
};
WXGO_DECL_TYPECONV(DataViewIndexListModel)
class wxDataViewIndexListModel : public wxDataViewListModel
{
public:
    wxDataViewIndexListModel(unsigned int initial_size = 0);
    wxDataViewItem GetItem(unsigned int row) const;
    void Reset(unsigned int new_size);
    void RowAppended();
    void RowChanged(unsigned int row);
    void RowDeleted(unsigned int row);
    void RowInserted(unsigned int before);
    void RowPrepended();
    void RowValueChanged(unsigned int row, unsigned int col);
    void RowsDeleted(const wxArrayInt& rows);
};
WXGO_DECL_TYPECONV(DataViewVirtualListModel)
class wxDataViewVirtualListModel : public wxDataViewListModel
{
public:
    wxDataViewVirtualListModel(unsigned int initial_size = 0);
    wxDataViewItem GetItem(unsigned int row) const;
    void Reset(unsigned int new_size);
    void RowAppended();
    void RowChanged(unsigned int row);
    void RowDeleted(unsigned int row);
    void RowInserted(unsigned int before);
    void RowPrepended();
    void RowValueChanged(unsigned int row, unsigned int col);
    void RowsDeleted(const wxArrayInt& rows);
};
WXGO_DECL_TYPECONV(DataViewItemAttr)
class wxDataViewItemAttr
{
public:
    wxDataViewItemAttr();
    void SetBold(bool set);
    void SetColour(const wxColour& colour);
    void SetBackgroundColour(const wxColour& colour);
    void SetItalic(bool set);
    bool HasColour() const;
    const wxColour& GetColour() const;
    bool HasFont() const;
    bool GetBold() const;
    bool GetItalic() const;
    bool HasBackgroundColour() const;
    const wxColour& GetBackgroundColour() const;
    bool IsDefault() const;
    wxFont GetEffectiveFont(const wxFont& font) const;
};
WXGO_DECL_TYPECONV(DataViewItem)
class wxDataViewItem
{
public:
    wxDataViewItem();
    wxDataViewItem(const wxDataViewItem& item);
    explicit wxDataViewItem(void* id);
    void* GetID() const;
    bool IsOk() const;
};
#define wxDVC_DEFAULT_RENDERER_SIZE     20
#define wxDVC_DEFAULT_WIDTH             80
#define wxDVC_TOGGLE_DEFAULT_WIDTH      30
#define wxDVC_DEFAULT_MINWIDTH          30
#define wxDVR_DEFAULT_ALIGNMENT         -1
#define wxDV_SINGLE                  0x0000     
#define wxDV_MULTIPLE                0x0001     
#define wxDV_NO_HEADER               0x0002     
#define wxDV_HORIZ_RULES             0x0004     
#define wxDV_VERT_RULES              0x0008     
#define wxDV_ROW_LINES               0x0010     
#define wxDV_VARIABLE_LINE_HEIGHT    0x0020     
%constant wxEventType wxEVT_DATAVIEW_SELECTION_CHANGED;
%constant wxEventType wxEVT_DATAVIEW_ITEM_ACTIVATED;
%constant wxEventType wxEVT_DATAVIEW_ITEM_COLLAPSING;
%constant wxEventType wxEVT_DATAVIEW_ITEM_COLLAPSED;
%constant wxEventType wxEVT_DATAVIEW_ITEM_EXPANDING;
%constant wxEventType wxEVT_DATAVIEW_ITEM_EXPANDED;
%constant wxEventType wxEVT_DATAVIEW_ITEM_START_EDITING;
%constant wxEventType wxEVT_DATAVIEW_ITEM_EDITING_STARTED;
%constant wxEventType wxEVT_DATAVIEW_ITEM_EDITING_DONE;
%constant wxEventType wxEVT_DATAVIEW_ITEM_VALUE_CHANGED;
%constant wxEventType wxEVT_DATAVIEW_ITEM_CONTEXT_MENU;
%constant wxEventType wxEVT_DATAVIEW_COLUMN_HEADER_CLICK;
%constant wxEventType wxEVT_DATAVIEW_COLUMN_HEADER_RIGHT_CLICK;
%constant wxEventType wxEVT_DATAVIEW_COLUMN_SORTED;
%constant wxEventType wxEVT_DATAVIEW_COLUMN_REORDERED;
%constant wxEventType wxEVT_DATAVIEW_CACHE_HINT;
%constant wxEventType wxEVT_DATAVIEW_ITEM_BEGIN_DRAG;
%constant wxEventType wxEVT_DATAVIEW_ITEM_DROP_POSSIBLE;
%constant wxEventType wxEVT_DATAVIEW_ITEM_DROP;
WXGO_DECL_TYPECONV(DataViewCtrl)
class wxDataViewCtrl : public wxControl
{
public:
    wxDataViewCtrl();
    wxDataViewCtrl(wxWindow* parent, wxWindowID id,
                   const wxPoint& pos = wxDefaultPosition,
                   const wxSize& size = wxDefaultSize,
                   long style = 0,
                   const wxValidator& validator = wxDefaultValidator,
                   const wxString& name = wxDataViewCtrlNameStr);
    virtual ~wxDataViewCtrl();
    bool AllowMultiColumnSort(bool allow);
    bool Create(wxWindow* parent, wxWindowID id,
                const wxPoint& pos = wxDefaultPosition,
                const wxSize& size = wxDefaultSize,
                long style = 0,
                const wxValidator& validator = wxDefaultValidator,
                const wxString& name = wxDataViewCtrlNameStr);
    virtual bool AppendColumn(wxDataViewColumn* col);
    virtual bool PrependColumn(wxDataViewColumn* col);
    virtual bool InsertColumn(unsigned int pos, wxDataViewColumn* col);
    wxDataViewColumn* AppendBitmapColumn(const wxString& label,
                                         unsigned int model_column,
                                         wxDataViewCellMode mode = wxDATAVIEW_CELL_INERT,
                                         int width = -1,
                                         wxAlignment align = wxALIGN_CENTER,
                                         int flags = wxDATAVIEW_COL_RESIZABLE);
    wxDataViewColumn* AppendBitmapColumn(const wxBitmap& label,
                                         unsigned int model_column,
                                         wxDataViewCellMode mode = wxDATAVIEW_CELL_INERT,
                                         int width = -1,
                                         wxAlignment align = wxALIGN_CENTER,
                                         int flags = wxDATAVIEW_COL_RESIZABLE);
    wxDataViewColumn* PrependBitmapColumn(const wxString& label,
                                         unsigned int model_column,
                                         wxDataViewCellMode mode = wxDATAVIEW_CELL_INERT,
                                         int width = -1,
                                         wxAlignment align = wxALIGN_CENTER,
                                         int flags = wxDATAVIEW_COL_RESIZABLE);
    wxDataViewColumn* PrependBitmapColumn(const wxBitmap& label,
                                         unsigned int model_column,
                                         wxDataViewCellMode mode = wxDATAVIEW_CELL_INERT,
                                         int width = -1,
                                         wxAlignment align = wxALIGN_CENTER,
                                         int flags = wxDATAVIEW_COL_RESIZABLE);
    wxDataViewColumn* AppendDateColumn(const wxString& label,
                                       unsigned int model_column,
                                       wxDataViewCellMode mode = wxDATAVIEW_CELL_ACTIVATABLE,
                                       int width = -1,
                                       wxAlignment align = wxALIGN_NOT,
                                       int flags = wxDATAVIEW_COL_RESIZABLE);
    wxDataViewColumn* AppendDateColumn(const wxBitmap& label,
                                       unsigned int model_column,
                                       wxDataViewCellMode mode = wxDATAVIEW_CELL_ACTIVATABLE,
                                       int width = -1,
                                       wxAlignment align = wxALIGN_NOT,
                                       int flags = wxDATAVIEW_COL_RESIZABLE);
    wxDataViewColumn* PrependDateColumn(const wxString& label,
                                       unsigned int model_column,
                                       wxDataViewCellMode mode = wxDATAVIEW_CELL_ACTIVATABLE,
                                       int width = -1,
                                       wxAlignment align = wxALIGN_NOT,
                                       int flags = wxDATAVIEW_COL_RESIZABLE);
    wxDataViewColumn* PrependDateColumn(const wxBitmap& label,
                                       unsigned int model_column,
                                       wxDataViewCellMode mode = wxDATAVIEW_CELL_ACTIVATABLE,
                                       int width = -1,
                                       wxAlignment align = wxALIGN_NOT,
                                       int flags = wxDATAVIEW_COL_RESIZABLE);
    wxDataViewColumn* AppendIconTextColumn(const wxString& label,
                                           unsigned int model_column,
                                           wxDataViewCellMode mode = wxDATAVIEW_CELL_INERT,
                                           int width = -1,
                                           wxAlignment align = wxALIGN_NOT,
                                           int flags = wxDATAVIEW_COL_RESIZABLE);
    wxDataViewColumn* AppendIconTextColumn(const wxBitmap& label,
                                           unsigned int model_column,
                                           wxDataViewCellMode mode = wxDATAVIEW_CELL_INERT,
                                           int width = -1,
                                           wxAlignment align = wxALIGN_NOT,
                                           int flags = wxDATAVIEW_COL_RESIZABLE);
    wxDataViewColumn* PrependIconTextColumn(const wxString& label,
                                           unsigned int model_column,
                                           wxDataViewCellMode mode = wxDATAVIEW_CELL_INERT,
                                           int width = -1,
                                           wxAlignment align = wxALIGN_NOT,
                                           int flags = wxDATAVIEW_COL_RESIZABLE);
    wxDataViewColumn* PrependIconTextColumn(const wxBitmap& label,
                                           unsigned int model_column,
                                           wxDataViewCellMode mode = wxDATAVIEW_CELL_INERT,
                                           int width = -1,
                                           wxAlignment align = wxALIGN_NOT,
                                           int flags = wxDATAVIEW_COL_RESIZABLE);
    wxDataViewColumn* AppendProgressColumn(const wxString& label,
                                           unsigned int model_column,
                                           wxDataViewCellMode mode = wxDATAVIEW_CELL_INERT,
                                           int width = 80,
                                           wxAlignment align = wxALIGN_CENTER,
                                           int flags = wxDATAVIEW_COL_RESIZABLE);
    wxDataViewColumn* AppendProgressColumn(const wxBitmap& label,
                                           unsigned int model_column,
                                           wxDataViewCellMode mode = wxDATAVIEW_CELL_INERT,
                                           int width = 80,
                                           wxAlignment align = wxALIGN_CENTER,
                                           int flags = wxDATAVIEW_COL_RESIZABLE);
    wxDataViewColumn* PrependProgressColumn(const wxString& label,
                                           unsigned int model_column,
                                           wxDataViewCellMode mode = wxDATAVIEW_CELL_INERT,
                                           int width = 80,
                                           wxAlignment align = wxALIGN_CENTER,
                                           int flags = wxDATAVIEW_COL_RESIZABLE);
    wxDataViewColumn* PrependProgressColumn(const wxBitmap& label,
                                           unsigned int model_column,
                                           wxDataViewCellMode mode = wxDATAVIEW_CELL_INERT,
                                           int width = 80,
                                           wxAlignment align = wxALIGN_CENTER,
                                           int flags = wxDATAVIEW_COL_RESIZABLE);
    wxDataViewColumn* AppendTextColumn(const wxString& label,
                                       unsigned int model_column,
                                       wxDataViewCellMode mode = wxDATAVIEW_CELL_INERT,
                                       int width = -1,
                                       wxAlignment align = wxALIGN_NOT,
                                       int flags = wxDATAVIEW_COL_RESIZABLE);
    wxDataViewColumn* AppendTextColumn(const wxBitmap& label,
                                       unsigned int model_column,
                                       wxDataViewCellMode mode = wxDATAVIEW_CELL_INERT,
                                       int width = -1,
                                       wxAlignment align = wxALIGN_NOT,
                                       int flags = wxDATAVIEW_COL_RESIZABLE);
    wxDataViewColumn* PrependTextColumn(const wxString& label,
                                       unsigned int model_column,
                                       wxDataViewCellMode mode = wxDATAVIEW_CELL_INERT,
                                       int width = -1,
                                       wxAlignment align = wxALIGN_NOT,
                                       int flags = wxDATAVIEW_COL_RESIZABLE);
    wxDataViewColumn* PrependTextColumn(const wxBitmap& label,
                                       unsigned int model_column,
                                       wxDataViewCellMode mode = wxDATAVIEW_CELL_INERT,
                                       int width = -1,
                                       wxAlignment align = wxALIGN_NOT,
                                       int flags = wxDATAVIEW_COL_RESIZABLE);
    wxDataViewColumn* AppendToggleColumn(const wxString& label,
                                         unsigned int model_column,
                                         wxDataViewCellMode mode = wxDATAVIEW_CELL_INERT,
                                         int width = 30,
                                         wxAlignment align = wxALIGN_CENTER,
                                         int flags = wxDATAVIEW_COL_RESIZABLE);
    wxDataViewColumn* AppendToggleColumn(const wxBitmap& label,
                                         unsigned int model_column,
                                         wxDataViewCellMode mode = wxDATAVIEW_CELL_INERT,
                                         int width = 30,
                                         wxAlignment align = wxALIGN_CENTER,
                                         int flags = wxDATAVIEW_COL_RESIZABLE);
    wxDataViewColumn* PrependToggleColumn(const wxString& label,
                                         unsigned int model_column,
                                         wxDataViewCellMode mode = wxDATAVIEW_CELL_INERT,
                                         int width = 30,
                                         wxAlignment align = wxALIGN_CENTER,
                                         int flags = wxDATAVIEW_COL_RESIZABLE);
    wxDataViewColumn* PrependToggleColumn(const wxBitmap& label,
                                         unsigned int model_column,
                                         wxDataViewCellMode mode = wxDATAVIEW_CELL_INERT,
                                         int width = 30,
                                         wxAlignment align = wxALIGN_CENTER,
                                         int flags = wxDATAVIEW_COL_RESIZABLE);
    virtual bool AssociateModel(wxDataViewModel* model);
    virtual bool ClearColumns();
    virtual void Collapse(const wxDataViewItem& item);
    virtual bool DeleteColumn(wxDataViewColumn* column);
    virtual void EditItem(const wxDataViewItem& item, const wxDataViewColumn *column);
    virtual bool EnableDragSource( const wxDataFormat &format );
    virtual bool EnableDropTarget( const wxDataFormat &format );
    virtual void EnsureVisible(const wxDataViewItem& item,
                               const wxDataViewColumn* column = NULL);
    virtual void Expand(const wxDataViewItem& item);
    virtual void ExpandAncestors( const wxDataViewItem & item );
    virtual wxDataViewColumn* GetColumn(unsigned int pos) const;
    virtual unsigned int GetColumnCount() const;
    virtual int GetColumnPosition(const wxDataViewColumn* column) const;
    wxDataViewColumn* GetExpanderColumn() const;
    wxDataViewItem GetCurrentItem() const;
    wxDataViewColumn *GetCurrentColumn() const;
    int GetIndent() const;
    virtual wxRect GetItemRect(const wxDataViewItem& item,
                               const wxDataViewColumn* col = NULL) const;
    wxDataViewModel* GetModel();
    virtual int GetSelectedItemsCount() const;
    virtual wxDataViewItem GetSelection() const;
    virtual int GetSelections(wxDataViewItemArray& sel) const;
    virtual wxDataViewColumn* GetSortingColumn() const;
    virtual wxVector<wxDataViewColumn *> GetSortingColumns() const;
    bool HasSelection() const;
    virtual void HitTest(const wxPoint& point, wxDataViewItem& item,
                         wxDataViewColumn*& col) const;
    virtual bool IsExpanded(const wxDataViewItem& item) const;
    virtual bool IsSelected(const wxDataViewItem& item) const;
    virtual void Select(const wxDataViewItem& item);
    virtual void SelectAll();
    void SetExpanderColumn(wxDataViewColumn* col);
    void SetCurrentItem(const wxDataViewItem& item);
    void SetIndent(int indent);
    virtual void SetSelections(const wxDataViewItemArray& sel);
    virtual void Unselect(const wxDataViewItem& item);
    virtual void UnselectAll();
    virtual bool SetRowHeight(int rowHeight);
    virtual void ToggleSortByColumn(int column);
};
WXGO_DECL_TYPECONV(DataViewModelNotifier)
class wxDataViewModelNotifier
{
public:
    wxDataViewModelNotifier();
    virtual ~wxDataViewModelNotifier();
    virtual bool Cleared() = 0;
    wxDataViewModel* GetOwner() const;
    virtual bool ItemAdded(const wxDataViewItem& parent,
                           const wxDataViewItem& item) = 0;
    virtual bool ItemChanged(const wxDataViewItem& item) = 0;
    virtual bool ItemDeleted(const wxDataViewItem& parent,
                             const wxDataViewItem& item) = 0;
    virtual bool ItemsAdded(const wxDataViewItem& parent,
                            const wxDataViewItemArray& items);
    virtual bool ItemsChanged(const wxDataViewItemArray& items);
    virtual bool ItemsDeleted(const wxDataViewItem& parent,
                              const wxDataViewItemArray& items);
    virtual void Resort() = 0;
    void SetOwner(wxDataViewModel* owner);
    virtual bool ValueChanged(const wxDataViewItem& item, unsigned int col) = 0;
};
%typedef int wxDataViewCellMode;
#define wxDATAVIEW_CELL_INERT 0
#define wxDATAVIEW_CELL_ACTIVATABLE wxDATAVIEW_CELL_INERT + 1
#define wxDATAVIEW_CELL_EDITABLE wxDATAVIEW_CELL_ACTIVATABLE + 1
%typedef int wxDataViewCellRenderState;
#define wxDATAVIEW_CELL_SELECTED     1
#define wxDATAVIEW_CELL_PRELIT       2
#define wxDATAVIEW_CELL_INSENSITIVE  4
#define wxDATAVIEW_CELL_FOCUSED      8
WXGO_DECL_TYPECONV(DataViewRenderer)
class wxDataViewRenderer : public wxObject
{
public:
    wxDataViewRenderer(const wxString& varianttype,
                       wxDataViewCellMode mode = wxDATAVIEW_CELL_INERT,
                       int align = wxDVR_DEFAULT_ALIGNMENT );
    void EnableEllipsize(wxEllipsizeMode mode = wxELLIPSIZE_MIDDLE);
    void DisableEllipsize();
    virtual int GetAlignment() const;
    wxEllipsizeMode GetEllipsizeMode() const;
    virtual wxDataViewCellMode GetMode() const;
    wxDataViewColumn* GetOwner() const;
    virtual bool GetValue(wxVariant& value) const = 0;
    wxString GetVariantType() const;
    virtual void SetAlignment( int align );
    void SetOwner(wxDataViewColumn* owner);
    virtual bool SetValue(const wxVariant& value) = 0;
    virtual bool Validate(wxVariant& value);
    virtual bool HasEditorCtrl() const;
    virtual wxWindow* CreateEditorCtrl(wxWindow * parent,
                                       wxRect labelRect,
                                       const wxVariant& value);
    virtual bool GetValueFromEditorCtrl(wxWindow * editor,
                                        wxVariant& value);
    virtual bool StartEditing( const wxDataViewItem &item, wxRect labelRect );
    virtual void CancelEditing();
    virtual bool FinishEditing();
    wxWindow *GetEditorCtrl();
protected:
    wxDataViewCtrl* GetView() const;
};
WXGO_DECL_TYPECONV(DataViewTextRenderer)
class wxDataViewTextRenderer : public wxDataViewRenderer
{
public:
    static wxString GetDefaultType();
    wxDataViewTextRenderer(const wxString& varianttype = GetDefaultType(),
                           wxDataViewCellMode mode = wxDATAVIEW_CELL_INERT,
                           int align = wxDVR_DEFAULT_ALIGNMENT );
};
WXGO_DECL_TYPECONV(DataViewIconTextRenderer)
class wxDataViewIconTextRenderer : public wxDataViewRenderer
{
public:
    static wxString GetDefaultType();
    wxDataViewIconTextRenderer(const wxString& varianttype = GetDefaultType(),
                               wxDataViewCellMode mode = wxDATAVIEW_CELL_INERT,
                               int align = wxDVR_DEFAULT_ALIGNMENT );
};
%feature("") wxDataViewProgressRenderer;
WXGO_DECL_TYPECONV(DataViewProgressRenderer)
class wxDataViewProgressRenderer : public wxDataViewRenderer
{
public:
    static wxString GetDefaultType();
    wxDataViewProgressRenderer(const wxString& label = wxEmptyString,
                               const wxString& varianttype = GetDefaultType(),
                               wxDataViewCellMode mode = wxDATAVIEW_CELL_INERT,
                               int align = wxDVR_DEFAULT_ALIGNMENT );
};
WXGO_DECL_TYPECONV(DataViewCustomRenderer)
class wxDataViewCustomRenderer : public wxDataViewRenderer
{
public:
    static wxString GetDefaultType();
    wxDataViewCustomRenderer(const wxString& varianttype = GetDefaultType(),
                             wxDataViewCellMode mode = wxDATAVIEW_CELL_INERT,
                             int align = wxDVR_DEFAULT_ALIGNMENT);
    virtual ~wxDataViewCustomRenderer();
    virtual bool ActivateCell(const wxRect& cell,
                              wxDataViewModel* model,
                              const wxDataViewItem & item,
                              unsigned int col,
                              const wxMouseEvent *mouseEvent);
    virtual wxWindow* CreateEditorCtrl(wxWindow* parent,
                                       wxRect labelRect,
                                       const wxVariant& value);
    const wxDataViewItemAttr& GetAttr() const;
    virtual wxSize GetSize() const = 0;
    virtual bool GetValueFromEditorCtrl(wxWindow* editor,
                                        wxVariant& value);
    virtual bool HasEditorCtrl() const;
    virtual bool LeftClick( wxPoint cursor,
                            wxRect cell,
                            wxDataViewModel * model,
                            const wxDataViewItem & item,
                            unsigned int col );
    virtual bool Activate(wxRect cell,
                          wxDataViewModel * model,
                          const wxDataViewItem & item,
                          unsigned int col);
    virtual bool Render(wxRect cell, wxDC* dc, int state) = 0;
    void RenderText(const wxString& text, int xoffset, wxRect cell,
                    wxDC* dc, int state);
    virtual bool StartDrag(const wxPoint& cursor,
                           const wxRect& cell,
                           wxDataViewModel* model,
                           const wxDataViewItem & item,
                           unsigned int col);
protected:
    wxSize GetTextExtent(const wxString& str) const;
};
WXGO_DECL_TYPECONV(DataViewSpinRenderer)
class wxDataViewSpinRenderer : public wxDataViewCustomRenderer
{
public:
    wxDataViewSpinRenderer(int min, int max,
                           wxDataViewCellMode mode = wxDATAVIEW_CELL_EDITABLE,
                           int align = wxDVR_DEFAULT_ALIGNMENT);
};
WXGO_DECL_TYPECONV(DataViewToggleRenderer)
class wxDataViewToggleRenderer : public wxDataViewRenderer
{
public:
    static wxString GetDefaultType();
    wxDataViewToggleRenderer(const wxString& varianttype = GetDefaultType(),
                             wxDataViewCellMode mode = wxDATAVIEW_CELL_INERT,
                             int align = wxDVR_DEFAULT_ALIGNMENT);
};
WXGO_DECL_TYPECONV(DataViewChoiceRenderer)
class wxDataViewChoiceRenderer: public wxDataViewRenderer
{
public:
    wxDataViewChoiceRenderer( const wxArrayString &choices,
                              wxDataViewCellMode mode = wxDATAVIEW_CELL_EDITABLE,
                              int alignment = wxDVR_DEFAULT_ALIGNMENT );
    wxString GetChoice(size_t index) const;
    const wxArrayString& GetChoices() const;
};
#ifndef __WXOSX__
WXGO_DECL_TYPECONV(DataViewChoiceByIndexRenderer)
class wxDataViewChoiceByIndexRenderer : public wxDataViewChoiceRenderer
{
public:
    wxDataViewChoiceByIndexRenderer( const wxArrayString &choices,
                              wxDataViewCellMode mode = wxDATAVIEW_CELL_EDITABLE,
                              int alignment = wxDVR_DEFAULT_ALIGNMENT );
};
#endif
WXGO_DECL_TYPECONV(DataViewDateRenderer)
class wxDataViewDateRenderer : public wxDataViewRenderer
{
public:
    static wxString GetDefaultType();
    wxDataViewDateRenderer(const wxString& varianttype = GetDefaultType(),
                           wxDataViewCellMode mode = wxDATAVIEW_CELL_ACTIVATABLE,
                           int align = wxDVR_DEFAULT_ALIGNMENT);
};
WXGO_DECL_TYPECONV(DataViewBitmapRenderer)
class wxDataViewBitmapRenderer : public wxDataViewRenderer
{
public:
    static wxString GetDefaultType();
    wxDataViewBitmapRenderer(const wxString& varianttype = GetDefaultType(),
                             wxDataViewCellMode mode = wxDATAVIEW_CELL_INERT,
                             int align = wxDVR_DEFAULT_ALIGNMENT);
};
%typedef int wxDataViewColumnFlags;
#define wxDATAVIEW_COL_RESIZABLE      1
#define wxDATAVIEW_COL_SORTABLE       2
#define wxDATAVIEW_COL_REORDERABLE    4
#define wxDATAVIEW_COL_HIDDEN         8
WXGO_DECL_TYPECONV(DataViewColumn)
class wxDataViewColumn : public wxSettableHeaderColumn
{
public:
    wxDataViewColumn(const wxString& title,
                     wxDataViewRenderer* renderer,
                     unsigned int model_column,
                     int width = wxDVC_DEFAULT_WIDTH,
                     wxAlignment align = wxALIGN_CENTER,
                     int flags = wxDATAVIEW_COL_RESIZABLE);
    wxDataViewColumn(const wxBitmap& bitmap,
                     wxDataViewRenderer* renderer,
                     unsigned int model_column,
                     int width = wxDVC_DEFAULT_WIDTH,
                     wxAlignment align = wxALIGN_CENTER,
                     int flags = wxDATAVIEW_COL_RESIZABLE);
    unsigned int GetModelColumn() const;
    wxDataViewCtrl* GetOwner() const;
    wxDataViewRenderer* GetRenderer() const;
};
WXGO_DECL_TYPECONV(DataViewListCtrl)
class wxDataViewListCtrl: public wxDataViewCtrl
{
public:
    wxDataViewListCtrl();
    wxDataViewListCtrl( wxWindow *parent, wxWindowID id,
           const wxPoint& pos = wxDefaultPosition,
           const wxSize& size = wxDefaultSize, long style = wxDV_ROW_LINES,
           const wxValidator& validator = wxDefaultValidator );
    ~wxDataViewListCtrl();
    bool Create( wxWindow *parent, wxWindowID id,
           const wxPoint& pos = wxDefaultPosition,
           const wxSize& size = wxDefaultSize, long style = wxDV_ROW_LINES,
           const wxValidator& validator = wxDefaultValidator );
    wxDataViewListStore *GetStore();
    int ItemToRow(const wxDataViewItem &item) const;
    wxDataViewItem RowToItem(int row) const;
    int GetSelectedRow() const;
    void SelectRow(unsigned row);
    void UnselectRow(unsigned row);
    bool IsRowSelected(unsigned row) const;
    virtual bool AppendColumn( wxDataViewColumn *column );
    void AppendColumn( wxDataViewColumn *column, const wxString &varianttype );
    wxDataViewColumn *AppendTextColumn( const wxString &label,
          wxDataViewCellMode mode = wxDATAVIEW_CELL_INERT,
          int width = -1, wxAlignment align = wxALIGN_LEFT,
          int flags = wxDATAVIEW_COL_RESIZABLE );
    wxDataViewColumn *AppendToggleColumn( const wxString &label,
          wxDataViewCellMode mode = wxDATAVIEW_CELL_ACTIVATABLE,
          int width = -1, wxAlignment align = wxALIGN_LEFT,
          int flags = wxDATAVIEW_COL_RESIZABLE );
    wxDataViewColumn *AppendProgressColumn( const wxString &label,
          wxDataViewCellMode mode = wxDATAVIEW_CELL_INERT,
          int width = -1, wxAlignment align = wxALIGN_LEFT,
          int flags = wxDATAVIEW_COL_RESIZABLE );
    wxDataViewColumn *AppendIconTextColumn( const wxString &label,
          wxDataViewCellMode mode = wxDATAVIEW_CELL_INERT,
          int width = -1, wxAlignment align = wxALIGN_LEFT,
          int flags = wxDATAVIEW_COL_RESIZABLE );
    virtual bool InsertColumn( unsigned int pos, wxDataViewColumn *column );
    void InsertColumn( unsigned int pos, wxDataViewColumn *column,
                       const wxString &varianttype );
    virtual bool PrependColumn( wxDataViewColumn *column );
    void PrependColumn( wxDataViewColumn *column, const wxString &varianttype );
    void AppendItem( const wxVector<wxVariant> &values, wxUIntPtr data = NULL );
    void PrependItem( const wxVector<wxVariant> &values, wxUIntPtr data = NULL );
    void InsertItem( unsigned int row, const wxVector<wxVariant> &values, wxUIntPtr data = NULL );
    void DeleteItem( unsigned row );
    void DeleteAllItems();
    unsigned int GetItemCount() const;
    wxUIntPtr GetItemData(const wxDataViewItem& item) const;
    void SetValue( const wxVariant &value, unsigned int row, unsigned int col );
    void GetValue( wxVariant &value, unsigned int row, unsigned int col );
    void SetTextValue( const wxString &value, unsigned int row, unsigned int col );
    wxString GetTextValue( unsigned int row, unsigned int col ) const;
    void SetToggleValue( bool value, unsigned int row, unsigned int col );
    bool GetToggleValue( unsigned int row, unsigned int col ) const;
    void SetItemData(const wxDataViewItem& item, wxUIntPtr data);
};
WXGO_DECL_TYPECONV(DataViewTreeCtrl)
class wxDataViewTreeCtrl : public wxDataViewCtrl
{
public:
    wxDataViewTreeCtrl();
    wxDataViewTreeCtrl(wxWindow* parent, wxWindowID id,
                       const wxPoint& pos = wxDefaultPosition,
                       const wxSize& size = wxDefaultSize,
                       long style = wxDV_NO_HEADER | wxDV_ROW_LINES,
                       const wxValidator& validator = wxDefaultValidator);
    virtual ~wxDataViewTreeCtrl();
    wxDataViewItem AppendContainer(const wxDataViewItem& parent,
                                   const wxString& text,
                                   int icon = -1,
                                   int expanded = -1,
                                   wxClientData* data = NULL);
    wxDataViewItem AppendItem(const wxDataViewItem& parent,
                              const wxString& text,
                              int icon = -1,
                              wxClientData* data = NULL);
    bool Create(wxWindow* parent, wxWindowID id,
                const wxPoint& pos = wxDefaultPosition,
                const wxSize& size = wxDefaultSize,
                long style = wxDV_NO_HEADER | wxDV_ROW_LINES,
                const wxValidator& validator = wxDefaultValidator);
    void DeleteAllItems();
    void DeleteChildren(const wxDataViewItem& item);
    void DeleteItem(const wxDataViewItem& item);
    int GetChildCount(const wxDataViewItem& parent) const;
    wxImageList* GetImageList();
    wxClientData* GetItemData(const wxDataViewItem& item) const;
    const wxIcon& GetItemExpandedIcon(const wxDataViewItem& item) const;
    const wxIcon& GetItemIcon(const wxDataViewItem& item) const;
    wxString GetItemText(const wxDataViewItem& item) const;
    wxDataViewItem GetNthChild(const wxDataViewItem& parent,
                               unsigned int pos) const;
    wxDataViewTreeStore* GetStore();
    wxDataViewItem InsertContainer(const wxDataViewItem& parent,
                                   const wxDataViewItem& previous,
                                   const wxString& text,
                                   int icon = -1,
                                   int expanded = -1,
                                   wxClientData* data = NULL);
    wxDataViewItem InsertItem(const wxDataViewItem& parent,
                              const wxDataViewItem& previous,
                              const wxString& text,
                              int icon = -1,
                              wxClientData* data = NULL);
    bool IsContainer( const wxDataViewItem& item );
    wxDataViewItem PrependContainer(const wxDataViewItem& parent,
                                    const wxString& text,
                                    int icon = -1,
                                    int expanded = -1,
                                    wxClientData* data = NULL);
    wxDataViewItem PrependItem(const wxDataViewItem& parent,
                               const wxString& text,
                               int icon = -1,
                               wxClientData* data = NULL);
    void SetImageList(wxImageList* imagelist);
    void SetItemData(const wxDataViewItem& item, wxClientData* data);
    void SetItemExpandedIcon(const wxDataViewItem& item,
                             const wxIcon& icon);
    void SetItemIcon(const wxDataViewItem& item, const wxIcon& icon);
    void SetItemText(const wxDataViewItem& item,
                     const wxString& text);
};
WXGO_DECL_TYPECONV(DataViewListStore)
class wxDataViewListStore: public wxDataViewIndexListModel
{
public:
    wxDataViewListStore();
    ~wxDataViewListStore();
    void PrependColumn( const wxString &varianttype );
    void InsertColumn( unsigned int pos, const wxString &varianttype );
    void AppendColumn( const wxString &varianttype );
    void AppendItem( const wxVector<wxVariant> &values, wxUIntPtr data = NULL );
    void PrependItem( const wxVector<wxVariant> &values, wxUIntPtr data = NULL );
    void InsertItem(  unsigned int row, const wxVector<wxVariant> &values, wxUIntPtr data = NULL );
    void DeleteItem( unsigned pos );
    void DeleteAllItems();
    unsigned int GetItemCount() const;
    wxUIntPtr GetItemData(const wxDataViewItem& item) const;
    virtual unsigned int GetColumnCount() const;
    virtual wxString GetColumnType( unsigned int col ) const;
    void SetItemData(const wxDataViewItem& item, wxUIntPtr data);
    virtual void GetValueByRow( wxVariant &value,
                           unsigned int row, unsigned int col ) const;
    virtual bool SetValueByRow( const wxVariant &value,
                           unsigned int row, unsigned int col );
};
WXGO_DECL_TYPECONV(DataViewTreeStore)
class wxDataViewTreeStore : public wxDataViewModel
{
public:
    wxDataViewTreeStore();
    virtual ~wxDataViewTreeStore();
    wxDataViewItem AppendContainer(const wxDataViewItem& parent,
                                   const wxString& text,
                                   const wxIcon& icon = wxNullIcon,
                                   const wxIcon& expanded = wxNullIcon,
                                   wxClientData* data = NULL);
    wxDataViewItem AppendItem(const wxDataViewItem& parent,
                              const wxString& text,
                              const wxIcon& icon = wxNullIcon,
                              wxClientData* data = NULL);
    void DeleteAllItems();
    void DeleteChildren(const wxDataViewItem& item);
    void DeleteItem(const wxDataViewItem& item);
    int GetChildCount(const wxDataViewItem& parent) const;
    wxClientData* GetItemData(const wxDataViewItem& item) const;
    const wxIcon& GetItemExpandedIcon(const wxDataViewItem& item) const;
    const wxIcon& GetItemIcon(const wxDataViewItem& item) const;
    wxString GetItemText(const wxDataViewItem& item) const;
    wxDataViewItem GetNthChild(const wxDataViewItem& parent,
                               unsigned int pos) const;
    wxDataViewItem InsertContainer(const wxDataViewItem& parent,
                                   const wxDataViewItem& previous,
                                   const wxString& text,
                                   const wxIcon& icon = wxNullIcon,
                                   const wxIcon& expanded = wxNullIcon,
                                   wxClientData* data = NULL);
    wxDataViewItem InsertItem(const wxDataViewItem& parent,
                              const wxDataViewItem& previous,
                              const wxString& text,
                              const wxIcon& icon = wxNullIcon,
                              wxClientData* data = NULL);
    wxDataViewItem PrependContainer(const wxDataViewItem& parent,
                                    const wxString& text,
                                    const wxIcon& icon = wxNullIcon,
                                    const wxIcon& expanded = wxNullIcon,
                                    wxClientData* data = NULL);
    wxDataViewItem PrependItem(const wxDataViewItem& parent,
                               const wxString& text,
                               const wxIcon& icon = wxNullIcon,
                               wxClientData* data = NULL);
    void SetItemData(const wxDataViewItem& item, wxClientData* data);
    void SetItemExpandedIcon(const wxDataViewItem& item,
                             const wxIcon& icon);
    void SetItemIcon(const wxDataViewItem& item, const wxIcon& icon);
};
WXGO_DECL_TYPECONV(DataViewIconText)
class wxDataViewIconText : public wxObject
{
public:
    wxDataViewIconText(const wxString& text = wxEmptyString,
                       const wxIcon& icon = wxNullIcon);
    wxDataViewIconText(const wxDataViewIconText& other);
    const wxIcon& GetIcon() const;
    wxString GetText() const;
    void SetIcon(const wxIcon& icon);
    void SetText(const wxString& text);
};
WXGO_DECL_TYPECONV(DataViewEvent)
class wxDataViewEvent : public wxNotifyEvent
{
public:
    wxDataViewEvent(wxEventType commandType = wxEVT_NULL,
                    int winid = 0);
    int GetColumn() const;
    wxDataViewColumn* GetDataViewColumn() const;
    wxDataViewModel* GetModel() const;
    wxPoint GetPosition() const;
    const wxVariant& GetValue() const;
    bool IsEditCancelled() const;
    void SetColumn(int col);
    void SetDataViewColumn(wxDataViewColumn* col);
    void SetModel(wxDataViewModel* model);
    void SetValue(const wxVariant& value);
    void SetDataObject( wxDataObject *obj );
    wxDataFormat GetDataFormat() const;
    size_t GetDataSize() const;
    void *GetDataBuffer() const;
    void SetDragFlags(int flags);
    wxDragResult GetDropEffect() const;
    int GetCacheFrom() const;
    int GetCacheTo() const;
    wxDataViewItem GetItem() const;
    void SetItem( const wxDataViewItem &item );
    void SetEditCanceled(bool editCancelled);
    void SetPosition( int x, int y );
    void SetCache(int from, int to);
    wxDataObject *GetDataObject() const;
    void SetDataFormat( const wxDataFormat &format );
    void SetDataSize( size_t size );
    void SetDataBuffer( void* buf );
    int GetDragFlags() const;
    void SetDropEffect( wxDragResult effect );
};