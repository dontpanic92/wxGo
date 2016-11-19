WXGO_DECL_TYPECONV(GridCellRenderer)
class wxGridCellRenderer : public wxClientDataContainer, public wxRefCounter
{
public:
    wxGridCellRenderer();
    virtual wxGridCellRenderer* Clone() const = 0;
    virtual void Draw(wxGrid& grid, wxGridCellAttr& attr, wxDC& dc,
                      const wxRect& rect, int row, int col,
                      bool isSelected) = 0;
    virtual wxSize GetBestSize(wxGrid& grid, wxGridCellAttr& attr, wxDC& dc,
                               int row, int col) = 0;
    virtual int GetBestHeight(wxGrid& grid, wxGridCellAttr& attr, wxDC& dc,
                               int row, int col, int width);
    virtual int GetBestWidth(wxGrid& grid, wxGridCellAttr& attr, wxDC& dc,
                               int row, int col, int height);
protected:
    virtual ~wxGridCellRenderer();
};
WXGO_DECL_TYPECONV(GridCellStringRenderer)
class wxGridCellStringRenderer : public wxGridCellRenderer
{
public:
    wxGridCellStringRenderer();
};
WXGO_DECL_TYPECONV(GridCellAutoWrapStringRenderer)
class wxGridCellAutoWrapStringRenderer : public wxGridCellStringRenderer
{
public:
    wxGridCellAutoWrapStringRenderer();
};
WXGO_DECL_TYPECONV(GridCellBoolRenderer)
class wxGridCellBoolRenderer : public wxGridCellRenderer
{
public:
    wxGridCellBoolRenderer();
};
WXGO_DECL_TYPECONV(GridCellDateTimeRenderer)
class wxGridCellDateTimeRenderer : public wxGridCellStringRenderer
{
public:
    wxGridCellDateTimeRenderer(const wxString& outformat = wxDefaultDateTimeFormat,
                               const wxString& informat = wxDefaultDateTimeFormat);
    virtual void SetParameters(const wxString& params);
};
WXGO_DECL_TYPECONV(GridCellEnumRenderer)
class wxGridCellEnumRenderer : public wxGridCellStringRenderer
{
public:
    wxGridCellEnumRenderer( const wxString& choices = wxEmptyString );
    virtual void SetParameters(const wxString& params);
};
%typedef int wxGridCellFloatFormat;
#define wxGRID_FLOAT_FORMAT_FIXED        0x0010
#define wxGRID_FLOAT_FORMAT_SCIENTIFIC   0x0020
#define wxGRID_FLOAT_FORMAT_COMPACT      0x0040
#define wxGRID_FLOAT_FORMAT_UPPER        0x0080
#define wxGRID_FLOAT_FORMAT_DEFAULT      wxGRID_FLOAT_FORMAT_FIXED
WXGO_DECL_TYPECONV(GridCellFloatRenderer)
class wxGridCellFloatRenderer : public wxGridCellStringRenderer
{
public:
    wxGridCellFloatRenderer(int width = -1, int precision = -1,
                            int format = wxGRID_FLOAT_FORMAT_DEFAULT);
    int GetFormat() const;
    int GetPrecision() const;
    int GetWidth() const;
    void SetFormat(int format);
    virtual void SetParameters(const wxString& params);
    void SetPrecision(int precision);
    void SetWidth(int width);
};
WXGO_DECL_TYPECONV(GridCellNumberRenderer)
class wxGridCellNumberRenderer : public wxGridCellStringRenderer
{
public:
    wxGridCellNumberRenderer();
};
WXGO_DECL_TYPECONV(GridCellEditor)
class wxGridCellEditor : public wxClientDataContainer, public wxRefCounter
{
public:
    wxGridCellEditor();
    virtual void BeginEdit(int row, int col, wxGrid* grid) = 0;
    virtual wxGridCellEditor* Clone() const = 0;
    virtual void Create(wxWindow* parent, wxWindowID id,
                        wxEvtHandler* evtHandler) = 0;
    virtual void Destroy();
    virtual bool EndEdit(int row, int col, const wxGrid* grid,
                         const wxString& oldval, wxString* newval) = 0;
    virtual void ApplyEdit(int row, int col, wxGrid* grid) = 0;
    virtual void HandleReturn(wxKeyEvent& event);
    bool IsCreated();
    virtual void PaintBackground(wxDC& dc, const wxRect& rectCell, wxGridCellAttr& attr);
    virtual void Reset() = 0;
    virtual void SetSize(const wxRect& rect);
    virtual void Show(bool show, wxGridCellAttr* attr = NULL);
    virtual void StartingClick();
    virtual void StartingKey(wxKeyEvent& event);
    virtual wxString GetValue() const = 0;
    wxControl* GetControl() const;
    void SetControl(wxControl* control);
protected:
    virtual ~wxGridCellEditor();
};
WXGO_DECL_TYPECONV(GridCellTextEditor)
class wxGridCellTextEditor : public wxGridCellEditor
{
public:
    explicit wxGridCellTextEditor(size_t maxChars = 0);
    virtual void SetParameters(const wxString& params);
    virtual void SetValidator(const wxValidator& validator);
};
WXGO_DECL_TYPECONV(GridCellAutoWrapStringEditor)
class wxGridCellAutoWrapStringEditor : public wxGridCellTextEditor
{
public:
    wxGridCellAutoWrapStringEditor();
};
WXGO_DECL_TYPECONV(GridCellBoolEditor)
class wxGridCellBoolEditor : public wxGridCellEditor
{
public:
    wxGridCellBoolEditor();
    static bool IsTrueValue(const wxString& value);
    static void UseStringValues(const wxString& valueTrue = "1",
                                const wxString& valueFalse = wxEmptyString);
};
WXGO_DECL_TYPECONV(GridCellChoiceEditor)
class wxGridCellChoiceEditor : public wxGridCellEditor
{
public:
    wxGridCellChoiceEditor(size_t count = 0,
                           const wxString choices[] = NULL,
                           bool allowOthers = false);
    wxGridCellChoiceEditor(const wxArrayString& choices,
                           bool allowOthers = false);
    virtual void SetParameters(const wxString& params);
};
WXGO_DECL_TYPECONV(GridCellEnumEditor)
class wxGridCellEnumEditor : public wxGridCellChoiceEditor
{
public:
    wxGridCellEnumEditor( const wxString& choices = wxEmptyString );
};
WXGO_DECL_TYPECONV(GridCellFloatEditor)
class wxGridCellFloatEditor : public wxGridCellTextEditor
{
public:
    wxGridCellFloatEditor(int width = -1, int precision = -1,
                          int format = wxGRID_FLOAT_FORMAT_DEFAULT);
    virtual void SetParameters(const wxString& params);
};
WXGO_DECL_TYPECONV(GridCellNumberEditor)
class wxGridCellNumberEditor : public wxGridCellTextEditor
{
public:
    wxGridCellNumberEditor(int min = -1, int max = -1);
    virtual void SetParameters(const wxString& params);
protected:
    bool HasRange() const;
    wxString GetString() const;
};
WXGO_DECL_TYPECONV(GridCellAttr)
class wxGridCellAttr : public wxClientDataContainer, public wxRefCounter
{
public:
    enum wxAttrKind
    {
        Any,
        Cell,
        Row,
        Col
    };
    wxGridCellAttr(wxGridCellAttr* attrDefault = NULL);
    wxGridCellAttr(const wxColour& colText, const wxColour& colBack,
                   const wxFont& font, int hAlign, int vAlign);
    wxGridCellAttr* Clone() const;
    void DecRef();
    void GetAlignment(int* hAlign, int* vAlign) const;
    const wxColour& GetBackgroundColour() const;
    wxGridCellEditor* GetEditor(const wxGrid* grid, int row, int col) const;
    const wxFont& GetFont() const;
    void GetNonDefaultAlignment(int *hAlign, int *vAlign) const;
    wxGridCellRenderer* GetRenderer(const wxGrid* grid, int row, int col) const;
    const wxColour& GetTextColour() const;
    bool HasAlignment() const;
    bool HasBackgroundColour() const;
    bool HasEditor() const;
    bool HasFont() const;
    bool HasRenderer() const;
    bool HasTextColour() const;
    void IncRef();
    bool IsReadOnly() const;
    void SetAlignment(int hAlign, int vAlign);
    void SetBackgroundColour(const wxColour& colBack);
    void SetDefAttr(wxGridCellAttr* defAttr);
    void SetEditor(wxGridCellEditor* editor);
    void SetFont(const wxFont& font);
    void SetReadOnly(bool isReadOnly = true);
    void SetRenderer(wxGridCellRenderer* renderer);
    void SetTextColour(const wxColour& colText);
protected:
    virtual ~wxGridCellAttr();
};
WXGO_DECL_TYPECONV(GridCornerHeaderRenderer)
class wxGridCornerHeaderRenderer
{
public:
    virtual void DrawBorder(const wxGrid& grid,
                            wxDC& dc,
                            wxRect& rect) const = 0;
};
WXGO_DECL_TYPECONV(GridHeaderLabelsRenderer)
class wxGridHeaderLabelsRenderer : public wxGridCornerHeaderRenderer
{
public:
    virtual void DrawLabel(const wxGrid& grid,
                           wxDC& dc,
                           const wxString& value,
                           const wxRect& rect,
                           int horizAlign,
                           int vertAlign,
                           int textOrientation) const;
};
WXGO_DECL_TYPECONV(GridRowHeaderRenderer)
class wxGridRowHeaderRenderer : public wxGridHeaderLabelsRenderer
{
};
WXGO_DECL_TYPECONV(GridColumnHeaderRenderer)
class wxGridColumnHeaderRenderer : public wxGridHeaderLabelsRenderer
{
};
WXGO_DECL_TYPECONV(GridRowHeaderRendererDefault)
class wxGridRowHeaderRendererDefault : public wxGridRowHeaderRenderer
{
public:
    virtual void DrawBorder(const wxGrid& grid,
                            wxDC& dc,
                            wxRect& rect) const;
};
WXGO_DECL_TYPECONV(GridColumnHeaderRendererDefault)
class wxGridColumnHeaderRendererDefault : public wxGridColumnHeaderRenderer
{
public:
    virtual void DrawBorder(const wxGrid& grid,
                            wxDC& dc,
                            wxRect& rect) const;
};
WXGO_DECL_TYPECONV(GridCornerHeaderRendererDefault)
class wxGridCornerHeaderRendererDefault : public wxGridCornerHeaderRenderer
{
public:
    virtual void DrawBorder(const wxGrid& grid,
                            wxDC& dc,
                            wxRect& rect) const;
};
WXGO_DECL_TYPECONV(GridCellAttrProvider)
class wxGridCellAttrProvider : public wxClientDataContainer
{
public:
    wxGridCellAttrProvider();
    virtual ~wxGridCellAttrProvider();
    virtual wxGridCellAttr *GetAttr(int row, int col,
                                    wxGridCellAttr::wxAttrKind kind) const;
    virtual void SetAttr(wxGridCellAttr *attr, int row, int col);
    virtual void SetRowAttr(wxGridCellAttr *attr, int row);
    virtual void SetColAttr(wxGridCellAttr *attr, int col);
    virtual const wxGridColumnHeaderRenderer& GetColumnHeaderRenderer(int col);
    virtual const wxGridRowHeaderRenderer& GetRowHeaderRenderer(int row);
    virtual const wxGridCornerHeaderRenderer& GetCornerRenderer();
};
WXGO_DECL_TYPECONV(GridCellCoords)
class wxGridCellCoords
{
public:
    wxGridCellCoords();
    wxGridCellCoords(int row, int col);
    int GetRow() const;
    void SetRow(int n);
    int GetCol() const;
    void SetCol(int n);
    void Set(int row, int col);
    wxGridCellCoords& operator=(const wxGridCellCoords& other);
    bool operator==(const wxGridCellCoords& other) const;
     bool operator!=(const wxGridCellCoords& other) const;
    bool operator!() const;
};
WXGO_DECL_TYPECONV(GridTableBase)
class wxGridTableBase : public wxObject
{
public:
    wxGridTableBase();
    virtual ~wxGridTableBase();
    virtual int GetNumberRows() = 0;
    virtual int GetNumberCols() = 0;
    int GetRowsCount() const;
    int GetColsCount() const;
    virtual bool IsEmptyCell(int row, int col);
    bool IsEmpty(const wxGridCellCoords& coords);
    virtual wxString GetValue(int row, int col) = 0;
    virtual void SetValue(int row, int col, const wxString& value) = 0;
    virtual wxString GetTypeName(int row, int col);
    virtual bool CanGetValueAs(int row, int col, const wxString& typeName);
    virtual bool CanSetValueAs(int row, int col, const wxString& typeName);
    virtual long GetValueAsLong(int row, int col);
    virtual double GetValueAsDouble(int row, int col);
    virtual bool GetValueAsBool(int row, int col);
    virtual void *GetValueAsCustom(int row, int col, const wxString& typeName);
    virtual void SetValueAsLong(int row, int col, long value);
    virtual void SetValueAsDouble(int row, int col, double value);
    virtual void SetValueAsBool( int row, int col, bool value );
    virtual void SetValueAsCustom(int row, int col, const wxString& typeName,
                                  void *value);
    virtual void SetView(wxGrid *grid);
    virtual wxGrid *GetView() const;
    virtual void Clear();
    virtual bool InsertRows(size_t pos = 0, size_t numRows = 1);
    virtual bool AppendRows(size_t numRows = 1);
    virtual bool DeleteRows(size_t pos = 0, size_t numRows = 1);
    virtual bool InsertCols(size_t pos = 0, size_t numCols = 1);
    virtual bool AppendCols(size_t numCols = 1);
    virtual bool DeleteCols(size_t pos = 0, size_t numCols = 1);
    virtual wxString GetRowLabelValue(int row);
    virtual wxString GetColLabelValue(int col);
    virtual void SetRowLabelValue(int row, const wxString& label);
    virtual void SetColLabelValue(int col, const wxString& label);
    void SetAttrProvider(wxGridCellAttrProvider *attrProvider);
    wxGridCellAttrProvider *GetAttrProvider() const;
    virtual wxGridCellAttr *GetAttr(int row, int col,
                                    wxGridCellAttr::wxAttrKind kind);
    virtual void SetAttr(wxGridCellAttr* attr, int row, int col);
    virtual void SetRowAttr(wxGridCellAttr *attr, int row);
    virtual void SetColAttr(wxGridCellAttr *attr, int col);
    virtual bool CanHaveAttributes();
};
%typedef int wxGridTableRequest;
#define wxGRIDTABLE_REQUEST_VIEW_GET_VALUES  2000
#define wxGRIDTABLE_REQUEST_VIEW_SEND_VALUES wxGRIDTABLE_REQUEST_VIEW_GET_VALUES  + 1
#define wxGRIDTABLE_NOTIFY_ROWS_INSERTED wxGRIDTABLE_REQUEST_VIEW_SEND_VALUES + 1
#define wxGRIDTABLE_NOTIFY_ROWS_APPENDED wxGRIDTABLE_NOTIFY_ROWS_INSERTED + 1
#define wxGRIDTABLE_NOTIFY_ROWS_DELETED wxGRIDTABLE_NOTIFY_ROWS_APPENDED + 1
#define wxGRIDTABLE_NOTIFY_COLS_INSERTED wxGRIDTABLE_NOTIFY_ROWS_DELETED + 1
#define wxGRIDTABLE_NOTIFY_COLS_APPENDED wxGRIDTABLE_NOTIFY_COLS_INSERTED + 1
#define wxGRIDTABLE_NOTIFY_COLS_DELETED wxGRIDTABLE_NOTIFY_COLS_APPENDED + 1
WXGO_DECL_TYPECONV(GridTableMessage)
class wxGridTableMessage
{
public:
    wxGridTableMessage();
    wxGridTableMessage( wxGridTableBase *table, int id,
                        int comInt1 = -1,
                        int comInt2 = -1 );
    void SetTableObject( wxGridTableBase *table );
    wxGridTableBase * GetTableObject() const;
    void SetId( int id );
    int  GetId();
    void SetCommandInt( int comInt1 );
    int  GetCommandInt();
    void SetCommandInt2( int comInt2 );
    int  GetCommandInt2();
};
WXGO_DECL_TYPECONV(GridStringTable)
class wxGridStringTable : public wxGridTableBase
{
public:
    wxGridStringTable();
    wxGridStringTable( int numRows, int numCols );
    virtual int GetNumberRows();
    virtual int GetNumberCols();
    virtual wxString GetValue( int row, int col );
    virtual void SetValue( int row, int col, const wxString& value );
    void Clear();
    bool InsertRows( size_t pos = 0, size_t numRows = 1 );
    bool AppendRows( size_t numRows = 1 );
    bool DeleteRows( size_t pos = 0, size_t numRows = 1 );
    bool InsertCols( size_t pos = 0, size_t numCols = 1 );
    bool AppendCols( size_t numCols = 1 );
    bool DeleteCols( size_t pos = 0, size_t numCols = 1 );
    void SetRowLabelValue( int row, const wxString& );
    void SetColLabelValue( int col, const wxString& );
    wxString GetRowLabelValue( int row );
    wxString GetColLabelValue( int col );
};
struct wxGridSizesInfo
{
    wxGridSizesInfo();
    wxGridSizesInfo(int defSize, const wxArrayInt& allSizes);
    int GetSize(unsigned pos) const;
    int m_sizeDefault;
    wxUnsignedToIntHashMap m_customSizes;
};
%typedef int wxGridRenderStyle;
#define wxGRID_DRAW_ROWS_HEADER  0x001
#define wxGRID_DRAW_COLS_HEADER  0x002
#define wxGRID_DRAW_CELL_LINES  0x004
#define wxGRID_DRAW_BOX_RECT  0x008
#define wxGRID_DRAW_SELECTION  0x010
#define wxGRID_DRAW_DEFAULT  wxGRID_DRAW_ROWS_HEADER |                          wxGRID_DRAW_COLS_HEADER |                          wxGRID_DRAW_CELL_LINES |                          wxGRID_DRAW_BOX_RECT
WXGO_DECL_TYPECONV(Grid)
class wxGrid : public wxScrolledWindow
{
public:
    enum wxGridSelectionModes
    {
        wxGridSelectCells,
        wxGridSelectRows,
        wxGridSelectColumns,
        wxGridSelectRowsOrColumns
    };
    enum CellSpan
    {
        CellSpan_Inside = -1,
        CellSpan_None = 0,
        CellSpan_Main
    };
    enum TabBehaviour
    {
        Tab_Stop,
        Tab_Wrap,
        Tab_Leave
    };
    wxGrid();
    wxGrid(wxWindow* parent, wxWindowID id,
           const wxPoint& pos = wxDefaultPosition,
           const wxSize& size = wxDefaultSize,
           long style = wxWANTS_CHARS,
           const wxString& name = wxGridNameStr);
    virtual ~wxGrid();
    bool Create(wxWindow* parent, wxWindowID id,
                const wxPoint& pos = wxDefaultPosition,
                const wxSize& size = wxDefaultSize,
                long style = wxWANTS_CHARS,
                const wxString& name = wxGridNameStr);
    bool CreateGrid(int numRows, int numCols,
                    wxGridSelectionModes selmode = wxGridSelectCells);
    bool SetTable(wxGridTableBase* table, bool takeOwnership = false,
                  wxGridSelectionModes selmode = wxGridSelectCells);
    bool ProcessTableMessage(wxGridTableMessage& msg);
    void EnableGridLines(bool enable = true);
    virtual wxPen GetColGridLinePen(int col);
    virtual wxPen GetDefaultGridLinePen();
    wxColour GetGridLineColour() const;
    virtual wxPen GetRowGridLinePen(int row);
    bool GridLinesEnabled() const;
    void SetGridLineColour(const wxColour& colour);
    void GetColLabelAlignment(int* horiz, int* vert) const;
    int GetColLabelTextOrientation() const;
    wxString GetColLabelValue(int col) const;
    wxColour GetLabelBackgroundColour() const;
    wxFont GetLabelFont() const;
    wxColour GetLabelTextColour() const;
    void GetRowLabelAlignment(int* horiz, int* vert) const;
    wxString GetRowLabelValue(int row) const;
    void HideColLabels();
    void HideRowLabels();
    void SetColLabelAlignment(int horiz, int vert);
    void SetColLabelTextOrientation(int textOrientation);
    void SetColLabelValue(int col, const wxString& value);
    void SetLabelBackgroundColour(const wxColour& colour);
    void SetLabelFont(const wxFont& font);
    void SetLabelTextColour(const wxColour& colour);
    void SetRowLabelAlignment(int horiz, int vert);
    void SetRowLabelValue(int row, const wxString& value);
    void SetUseNativeColLabels(bool native = true);
    void UseNativeColHeader(bool native = true);
    void GetCellAlignment(int row, int col, int* horiz, int* vert) const;
    wxColour GetCellBackgroundColour(int row, int col) const;
    wxFont GetCellFont(int row, int col) const;
    wxColour GetCellTextColour(int row, int col) const;
    void GetDefaultCellAlignment(int* horiz, int* vert) const;
    wxColour GetDefaultCellBackgroundColour() const;
    wxFont GetDefaultCellFont() const;
    wxColour GetDefaultCellTextColour() const;
    void SetCellAlignment(int row, int col, int horiz, int vert);
    void SetCellBackgroundColour(int row, int col, const wxColour& colour);
    void SetCellFont(int row, int col, const wxFont& font);
    void SetCellTextColour(int row, int col, const wxColour& colour);
    void SetDefaultCellAlignment(int horiz, int vert);
    void SetDefaultCellBackgroundColour(const wxColour& colour);
    void SetDefaultCellFont(const wxFont& font);
    void SetDefaultCellTextColour(const wxColour& colour);
    bool CanEnableCellControl() const;
    void DisableCellEditControl();
    void EnableCellEditControl(bool enable = true);
    void EnableEditing(bool edit);
    wxGridCellEditor* GetCellEditor(int row, int col) const;
    wxGridCellRenderer* GetCellRenderer(int row, int col) const;
    wxString GetCellValue(int row, int col) const;
    wxString GetCellValue(const wxGridCellCoords& coords) const;
    wxGridCellEditor* GetDefaultEditor() const;
    virtual wxGridCellEditor* GetDefaultEditorForCell(int row, int col) const;
    wxGridCellEditor* GetDefaultEditorForCell(const wxGridCellCoords& c) const;
    virtual wxGridCellEditor* GetDefaultEditorForType(const wxString& typeName) const;
    wxGridCellRenderer* GetDefaultRenderer() const;
    virtual wxGridCellRenderer* GetDefaultRendererForCell(int row, int col) const;
    virtual wxGridCellRenderer* GetDefaultRendererForType(const wxString& typeName) const;
    void HideCellEditControl();
    bool IsCellEditControlEnabled() const;
    bool IsCurrentCellReadOnly() const;
    bool IsEditable() const;
    bool IsReadOnly(int row, int col) const;
    void RegisterDataType(const wxString& typeName,
                          wxGridCellRenderer* renderer,
                          wxGridCellEditor* editor);
    void SaveEditControlValue();
    void SetCellEditor(int row, int col, wxGridCellEditor* editor);
    void SetCellRenderer(int row, int col, wxGridCellRenderer* renderer);
    void SetCellValue(int row, int col, const wxString& s);
    void SetCellValue(const wxGridCellCoords& coords, const wxString& s);
    void SetColFormatBool(int col);
    void SetColFormatCustom(int col, const wxString& typeName);
    void SetColFormatFloat(int col, int width = -1, int precision = -1);
    void SetColFormatNumber(int col);
    void SetDefaultEditor(wxGridCellEditor* editor);
    void SetDefaultRenderer(wxGridCellRenderer* renderer);
    void SetReadOnly(int row, int col, bool isReadOnly = true);
    void ShowCellEditControl();
    void AutoSize();
    void AutoSizeColLabelSize(int col);
    void AutoSizeColumn(int col, bool setAsMin = true);
    void AutoSizeColumns(bool setAsMin = true);
    void AutoSizeRow(int row, bool setAsMin = true);
    void AutoSizeRowLabelSize(int col);
    void AutoSizeRows(bool setAsMin = true);
    bool GetCellOverflow(int row, int col) const;
    int GetColLabelSize() const;
    int GetColMinimalAcceptableWidth() const;
    int GetColSize(int col) const;
    bool IsColShown(int col) const;
    bool GetDefaultCellOverflow() const;
    int GetDefaultColLabelSize() const;
    int GetDefaultColSize() const;
    int GetDefaultRowLabelSize() const;
    int GetDefaultRowSize() const;
    int GetRowMinimalAcceptableHeight() const;
    int GetRowLabelSize() const;
    int GetRowSize(int row) const;
    bool IsRowShown(int row) const;
    void SetCellOverflow(int row, int col, bool allow);
    void SetColLabelSize(int height);
    void SetColMinimalAcceptableWidth(int width);
    void SetColMinimalWidth(int col, int width);
    void SetColSize(int col, int width);
    void HideCol(int col);
    void ShowCol(int col);
    void SetDefaultCellOverflow( bool allow );
    void SetDefaultColSize(int width, bool resizeExistingCols = false);
    void SetDefaultRowSize(int height, bool resizeExistingRows = false);
    void SetRowLabelSize(int width);
    void SetRowMinimalAcceptableHeight(int height);
    void SetRowMinimalHeight(int row, int height);
    void SetRowSize(int row, int height);
    void HideRow(int col);
    void ShowRow(int col);
    wxGridSizesInfo GetColSizes() const;
    wxGridSizesInfo GetRowSizes() const;
    void SetColSizes(const wxGridSizesInfo& sizeInfo);
    void SetRowSizes(const wxGridSizesInfo& sizeInfo);
    void SetCellSize(int row, int col, int num_rows, int num_cols);
    CellSpan GetCellSize( int row, int col, int *num_rows, int *num_cols ) const;
    wxSize GetCellSize(const wxGridCellCoords& coords);
    bool CanDragCell() const;
    bool CanDragColMove() const;
    bool CanDragColSize(int col) const;
    bool CanDragGridSize() const;
    bool CanDragRowSize(int row) const;
    void DisableColResize(int col);
    void DisableRowResize(int row);
    void DisableDragColMove();
    void DisableDragColSize();
    void DisableDragGridSize();
    void DisableDragRowSize();
    void EnableDragCell(bool enable = true);
    void EnableDragColMove(bool enable = true);
    void EnableDragColSize(bool enable = true);
    void EnableDragGridSize(bool enable = true);
    void EnableDragRowSize(bool enable = true);
    int GetColAt(int colPos) const;
    int GetColPos(int colID) const;
    void SetColPos(int colID, int newPos);
    void SetColumnsOrder(const wxArrayInt& order);
    void ResetColPos();
    int GetGridCursorCol() const;
    int GetGridCursorRow() const;
    void GoToCell(int row, int col);
    void GoToCell(const wxGridCellCoords& coords);
    bool MoveCursorDown(bool expandSelection);
    bool MoveCursorDownBlock(bool expandSelection);
    bool MoveCursorLeft(bool expandSelection);
    bool MoveCursorLeftBlock(bool expandSelection);
    bool MoveCursorRight(bool expandSelection);
    bool MoveCursorRightBlock(bool expandSelection);
    bool MoveCursorUp(bool expandSelection);
    bool MoveCursorUpBlock(bool expandSelection);
    bool MovePageDown();
    bool MovePageUp();
    void SetGridCursor(int row, int col);
    void SetGridCursor(const wxGridCellCoords& coords);
    void SetTabBehaviour(TabBehaviour behaviour);
    void ClearSelection();
    wxGridCellCoordsArray GetSelectedCells() const;
    wxArrayInt GetSelectedCols() const;
    wxArrayInt GetSelectedRows() const;
    wxColour GetSelectionBackground() const;
    wxGridCellCoordsArray GetSelectionBlockBottomRight() const;
    wxGridCellCoordsArray GetSelectionBlockTopLeft() const;
    wxColour GetSelectionForeground() const;
    wxGridSelectionModes GetSelectionMode() const;
    bool IsInSelection(int row, int col) const;
    bool IsInSelection(const wxGridCellCoords& coords) const;
    bool IsSelection() const;
    void SelectAll();
    void SelectBlock(int topRow, int leftCol, int bottomRow, int rightCol,
                     bool addToSelected = false);
    void SelectBlock(const wxGridCellCoords& topLeft,
                     const wxGridCellCoords& bottomRight,
                     bool addToSelected = false);
    void SelectCol(int col, bool addToSelected = false);
    void SelectRow(int row, bool addToSelected = false);
    void SetSelectionBackground(const wxColour& c);
    void SetSelectionForeground(const wxColour& c);
    void SetSelectionMode(wxGridSelectionModes selmode);
    int GetScrollLineX() const;
    int GetScrollLineY() const;
    bool IsVisible(int row, int col, bool wholeCellVisible = true) const;
    bool IsVisible(const wxGridCellCoords& coords,
                   bool wholeCellVisible = true) const;
    void MakeCellVisible(int row, int col);
    void MakeCellVisible(const wxGridCellCoords& coords);
    void SetScrollLineX(int x);
    void SetScrollLineY(int y);
    wxRect BlockToDeviceRect(const wxGridCellCoords& topLeft,
                             const wxGridCellCoords& bottomRight) const;
    wxRect CellToRect(int row, int col) const;
    wxRect CellToRect(const wxGridCellCoords& coords) const;
    int XToCol(int x, bool clipToMinMax = false) const;
    int XToEdgeOfCol(int x) const;
    wxGridCellCoords XYToCell(int x, int y) const;
    wxGridCellCoords XYToCell(const wxPoint& pos) const;
    int YToEdgeOfRow(int y) const;
    int YToRow(int y, bool clipToMinMax = false) const;
    bool AppendCols(int numCols = 1, bool updateLabels = true);
    bool AppendRows(int numRows = 1, bool updateLabels = true);
    bool AreHorzGridLinesClipped() const;
    bool AreVertGridLinesClipped() const;
    void BeginBatch();
    void ClearGrid();
    void ClipHorzGridLines(bool clip);
    void ClipVertGridLines(bool clip);
    bool DeleteCols(int pos = 0, int numCols = 1, bool updateLabels = true);
    bool DeleteRows(int pos = 0, int numRows = 1, bool updateLabels = true);
    void EndBatch();
    virtual void Fit();
    void ForceRefresh();
    int GetBatchCount();
    int GetNumberCols() const;
    int GetNumberRows() const;
    wxGridCellAttr *GetOrCreateCellAttr(int row, int col) const;
    wxGridTableBase *GetTable() const;
    bool InsertCols(int pos = 0, int numCols = 1, bool updateLabels = true);
    bool InsertRows(int pos = 0, int numRows = 1, bool updateLabels = true);
    void RefreshAttr(int row, int col);
    void Render( wxDC& dc,
                 const wxPoint& pos = wxDefaultPosition,
                 const wxSize& size = wxDefaultSize,
                 const wxGridCellCoords& topLeft = wxGridCellCoords( -1, -1 ),
                 const wxGridCellCoords& bottomRight = wxGridCellCoords( -1, -1 ),
                 int style = wxGRID_DRAW_DEFAULT );
    void SetColAttr(int col, wxGridCellAttr* attr);
    void SetMargins(int extraWidth, int extraHeight);
    void SetRowAttr(int row, wxGridCellAttr* attr);
    wxArrayInt CalcRowLabelsExposed( const wxRegion& reg );
    wxArrayInt CalcColLabelsExposed( const wxRegion& reg );
    wxGridCellCoordsArray CalcCellsExposed( const wxRegion& reg );
    int GetSortingColumn() const;
    bool IsSortingBy(int col) const;
    bool IsSortOrderAscending() const;
    void SetSortingColumn(int col, bool ascending = true);
    void UnsetSortingColumn();
    wxWindow *GetGridWindow() const;
    wxWindow *GetGridRowLabelWindow() const;
    wxWindow *GetGridColLabelWindow() const;
    wxWindow *GetGridCornerLabelWindow() const;
    wxHeaderCtrl *GetGridColHeader() const;
    virtual void DrawCellHighlight( wxDC& dc, const wxGridCellAttr *attr );
    virtual void DrawRowLabels( wxDC& dc, const wxArrayInt& rows );
    virtual void DrawRowLabel( wxDC& dc, int row );
    virtual void DrawColLabels( wxDC& dc, const wxArrayInt& cols );
    virtual void DrawColLabel( wxDC& dc, int col );
    virtual void DrawCornerLabel(wxDC& dc);
    void DrawTextRectangle( wxDC& dc, const wxString& text, const wxRect& rect,
                            int horizontalAlignment = wxALIGN_LEFT,
                            int verticalAlignment = wxALIGN_TOP,
                            int textOrientation = wxHORIZONTAL ) const;
    void DrawTextRectangle( wxDC& dc, const wxArrayString& lines, const wxRect& rect,
                            int horizontalAlignment = wxALIGN_LEFT,
                            int verticalAlignment = wxALIGN_TOP,
                            int textOrientation = wxHORIZONTAL ) const;
    wxColour GetCellHighlightColour() const;
    int      GetCellHighlightPenWidth() const;
    int      GetCellHighlightROPenWidth() const;
    void SetCellHighlightColour( const wxColour& );
    void SetCellHighlightPenWidth(int width);
    void SetCellHighlightROPenWidth(int width);   
protected:
    bool CanHaveAttributes() const;
    int GetColMinimalWidth(int col) const;
    int GetColRight(int col) const;
    int GetColLeft(int col) const;
    int GetRowMinimalHeight(int col) const;
};
WXGO_DECL_TYPECONV(GridUpdateLocker)
class wxGridUpdateLocker
{
public:
    wxGridUpdateLocker(wxGrid* grid = NULL);
    ~wxGridUpdateLocker();
    void Create(wxGrid* grid);
};
WXGO_DECL_TYPECONV(GridEvent)
class wxGridEvent : public wxNotifyEvent
{
public:
    wxGridEvent();
    wxGridEvent(int id, wxEventType type, wxObject* obj,
                int row = -1, int col = -1, int x = -1, int y = -1,
                bool sel = true, const wxKeyboardState& kbd = wxKeyboardState());
    bool AltDown() const;
    bool ControlDown() const;
    virtual int GetCol();
    wxPoint GetPosition();
    virtual int GetRow();
    bool MetaDown() const;
    bool Selecting();
    bool ShiftDown() const;
};
WXGO_DECL_TYPECONV(GridSizeEvent)
class wxGridSizeEvent : public wxNotifyEvent
{
public:
    wxGridSizeEvent();
    wxGridSizeEvent(int id, wxEventType type, wxObject* obj,
                    int rowOrCol = -1, int x = -1, int y = -1,
                    const wxKeyboardState& kbd = wxKeyboardState());
    bool AltDown() const;
    bool ControlDown() const;
    wxPoint GetPosition();
    int GetRowOrCol();
    bool MetaDown() const;
    bool ShiftDown() const;
};
WXGO_DECL_TYPECONV(GridRangeSelectEvent)
class wxGridRangeSelectEvent : public wxNotifyEvent
{
public:
    wxGridRangeSelectEvent();
    wxGridRangeSelectEvent(int id, wxEventType type,
                           wxObject* obj,
                           const wxGridCellCoords& topLeft,
                           const wxGridCellCoords& bottomRight,
                           bool sel = true, const wxKeyboardState& kbd = wxKeyboardState());
    bool AltDown() const;
    bool ControlDown() const;
    wxGridCellCoords GetBottomRightCoords();
    int GetBottomRow();
    int GetLeftCol();
    int GetRightCol();
    wxGridCellCoords GetTopLeftCoords();
    int GetTopRow();
    bool MetaDown() const;
    bool Selecting();
    bool ShiftDown() const;
};
WXGO_DECL_TYPECONV(GridEditorCreatedEvent)
class wxGridEditorCreatedEvent : public wxCommandEvent
{
public:
    wxGridEditorCreatedEvent();
    wxGridEditorCreatedEvent(int id, wxEventType type, wxObject* obj,
                             int row, int col, wxControl* ctrl);
    int GetCol();
    wxControl* GetControl();
    int GetRow();
    void SetCol(int col);
    void SetControl(wxControl* ctrl);
    void SetRow(int row);
};
%constant wxEventType wxEVT_GRID_CELL_LEFT_CLICK;
%constant wxEventType wxEVT_GRID_CELL_RIGHT_CLICK;
%constant wxEventType wxEVT_GRID_CELL_LEFT_DCLICK;
%constant wxEventType wxEVT_GRID_CELL_RIGHT_DCLICK;
%constant wxEventType wxEVT_GRID_LABEL_LEFT_CLICK;
%constant wxEventType wxEVT_GRID_LABEL_RIGHT_CLICK;
%constant wxEventType wxEVT_GRID_LABEL_LEFT_DCLICK;
%constant wxEventType wxEVT_GRID_LABEL_RIGHT_DCLICK;
%constant wxEventType wxEVT_GRID_ROW_SIZE;
%constant wxEventType wxEVT_GRID_COL_SIZE;
%constant wxEventType wxEVT_GRID_COL_AUTO_SIZE;
%constant wxEventType wxEVT_GRID_RANGE_SELECT;
%constant wxEventType wxEVT_GRID_CELL_CHANGING;
%constant wxEventType wxEVT_GRID_CELL_CHANGED;
%constant wxEventType wxEVT_GRID_SELECT_CELL;
%constant wxEventType wxEVT_GRID_EDITOR_SHOWN;
%constant wxEventType wxEVT_GRID_EDITOR_HIDDEN;
%constant wxEventType wxEVT_GRID_EDITOR_CREATED;
%constant wxEventType wxEVT_GRID_CELL_BEGIN_DRAG;
%constant wxEventType wxEVT_GRID_COL_MOVE;
%constant wxEventType wxEVT_GRID_COL_SORT;
%constant wxEventType wxEVT_GRID_TABBING;