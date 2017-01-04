%typedef int wxAuiToolBarStyle;
#define wxAUI_TB_TEXT           1 << 0
#define wxAUI_TB_NO_TOOLTIPS    1 << 1
#define wxAUI_TB_NO_AUTORESIZE  1 << 2
#define wxAUI_TB_GRIPPER        1 << 3
#define wxAUI_TB_OVERFLOW       1 << 4
#define wxAUI_TB_VERTICAL       1 << 5
#define wxAUI_TB_HORZ_LAYOUT    1 << 6
#define wxAUI_TB_HORIZONTAL     1 << 7
#define wxAUI_TB_PLAIN_BACKGROUND  1 << 8
#define wxAUI_TB_HORZ_TEXT      (wxAUI_TB_HORZ_LAYOUT | wxAUI_TB_TEXT)
#define wxAUI_ORIENTATION_MASK  (wxAUI_TB_VERTICAL | wxAUI_TB_HORIZONTAL)
#define wxAUI_TB_DEFAULT_STYLE  0
%typedef int wxAuiToolBarArtSetting;
#define wxAUI_TBART_SEPARATOR_SIZE  0
#define wxAUI_TBART_GRIPPER_SIZE  1
#define wxAUI_TBART_OVERFLOW_SIZE  2
%typedef int wxAuiToolBarToolTextOrientation;
#define wxAUI_TBTOOL_TEXT_LEFT  0
#define wxAUI_TBTOOL_TEXT_RIGHT  1
#define wxAUI_TBTOOL_TEXT_TOP  2
#define wxAUI_TBTOOL_TEXT_BOTTOM  3
WXGO_DECL_TYPECONV(AuiToolBarEvent)
class wxAuiToolBarEvent : public wxNotifyEvent
{
public:
    bool IsDropDownClicked() const;
    wxPoint GetClickPoint() const;
    wxRect GetItemRect() const;
    int GetToolId() const;
};
WXGO_DECL_TYPECONV(AuiToolBarItem)
class wxAuiToolBarItem
{
public:
    wxAuiToolBarItem();
    wxAuiToolBarItem(const wxAuiToolBarItem& c);
    wxAuiToolBarItem& operator=(const wxAuiToolBarItem& c);
    void Assign(const wxAuiToolBarItem& c);
    void SetWindow(wxWindow* w);
    wxWindow* GetWindow();
    void SetId(int new_id);
    int GetId() const;
    void SetKind(int new_kind);
    int GetKind() const;
    void SetState(int new_state);
    int GetState() const;
    void SetSizerItem(wxSizerItem* s);
    wxSizerItem* GetSizerItem() const;
    void SetLabel(const wxString& s);
    const wxString& GetLabel() const;
    void SetBitmap(const wxBitmap& bmp);
    const wxBitmap& GetBitmap() const;
    void SetDisabledBitmap(const wxBitmap& bmp);
    const wxBitmap& GetDisabledBitmap() const;
    void SetHoverBitmap(const wxBitmap& bmp);
    const wxBitmap& GetHoverBitmap() const;
    void SetShortHelp(const wxString& s);
    const wxString& GetShortHelp() const;
    void SetLongHelp(const wxString& s);
    const wxString& GetLongHelp() const;
    void SetMinSize(const wxSize& s);
    const wxSize& GetMinSize() const;
    void SetSpacerPixels(int s);
    int GetSpacerPixels() const;
    void SetProportion(int p);
    int GetProportion() const;
    void SetActive(bool b);
    bool IsActive() const;
    void SetHasDropDown(bool b);
    bool HasDropDown() const;
    void SetSticky(bool b);
    bool IsSticky() const;
    void SetUserData(long l);
    long GetUserData() const;
    void SetAlignment(int l);
    int GetAlignment() const;
};
WXGO_DECL_TYPECONV(AuiToolBarArt)
class wxAuiToolBarArt
{
public:
    wxAuiToolBarArt();
    virtual wxAuiToolBarArt* Clone() = 0;
    virtual void SetFlags(unsigned int flags) = 0;
    virtual unsigned int GetFlags() = 0;
    virtual void SetFont(const wxFont& font) = 0;
    virtual wxFont GetFont() = 0;
    virtual void SetTextOrientation(int orientation) = 0;
    virtual int GetTextOrientation() = 0;
    virtual void DrawBackground(
                         wxDC& dc,
                         wxWindow* wnd,
                         const wxRect& rect) = 0;
    virtual void DrawPlainBackground(
                                  wxDC& dc,
                                  wxWindow* wnd,
                                  const wxRect& rect) = 0;
    virtual void DrawLabel(
                         wxDC& dc,
                         wxWindow* wnd,
                         const wxAuiToolBarItem& item,
                         const wxRect& rect) = 0;
    virtual void DrawButton(
                         wxDC& dc,
                         wxWindow* wnd,
                         const wxAuiToolBarItem& item,
                         const wxRect& rect) = 0;
    virtual void DrawDropDownButton(
                         wxDC& dc,
                         wxWindow* wnd,
                         const wxAuiToolBarItem& item,
                         const wxRect& rect) = 0;
    virtual void DrawControlLabel(
                         wxDC& dc,
                         wxWindow* wnd,
                         const wxAuiToolBarItem& item,
                         const wxRect& rect) = 0;
    virtual void DrawSeparator(
                         wxDC& dc,
                         wxWindow* wnd,
                         const wxRect& rect) = 0;
    virtual void DrawGripper(
                         wxDC& dc,
                         wxWindow* wnd,
                         const wxRect& rect) = 0;
    virtual void DrawOverflowButton(
                         wxDC& dc,
                         wxWindow* wnd,
                         const wxRect& rect,
                         int state) = 0;
    virtual wxSize GetLabelSize(
                         wxDC& dc,
                         wxWindow* wnd,
                         const wxAuiToolBarItem& item) = 0;
    virtual wxSize GetToolSize(
                         wxDC& dc,
                         wxWindow* wnd,
                         const wxAuiToolBarItem& item) = 0;
    virtual int GetElementSize(int element_id) = 0;
    virtual void SetElementSize(int element_id, int size) = 0;
    virtual int ShowDropDown(
                         wxWindow* wnd,
                         const wxAuiToolBarItemArray& items) = 0;
};
WXGO_DECL_TYPECONV(AuiDefaultToolBarArt)
class wxAuiDefaultToolBarArt : public wxAuiToolBarArt
{
public:
    wxAuiDefaultToolBarArt();
    virtual ~wxAuiDefaultToolBarArt();
    virtual wxAuiToolBarArt* Clone();
    virtual void SetFlags(unsigned int flags);
    virtual unsigned int GetFlags();
    virtual void SetFont(const wxFont& font);
    virtual wxFont GetFont();
    virtual void SetTextOrientation(int orientation);
    virtual int GetTextOrientation();
    virtual void DrawBackground(
                wxDC& dc,
                wxWindow* wnd,
                const wxRect& rect);
    virtual void DrawPlainBackground(wxDC& dc,
                                  wxWindow* wnd,
                                  const wxRect& rect);
    virtual void DrawLabel(
                wxDC& dc,
                wxWindow* wnd,
                const wxAuiToolBarItem& item,
                const wxRect& rect);
    virtual void DrawButton(
                wxDC& dc,
                wxWindow* wnd,
                const wxAuiToolBarItem& item,
                const wxRect& rect);
    virtual void DrawDropDownButton(
                wxDC& dc,
                wxWindow* wnd,
                const wxAuiToolBarItem& item,
                const wxRect& rect);
    virtual void DrawControlLabel(
                wxDC& dc,
                wxWindow* wnd,
                const wxAuiToolBarItem& item,
                const wxRect& rect);
    virtual void DrawSeparator(
                wxDC& dc,
                wxWindow* wnd,
                const wxRect& rect);
    virtual void DrawGripper(
                wxDC& dc,
                wxWindow* wnd,
                const wxRect& rect);
    virtual void DrawOverflowButton(
                wxDC& dc,
                wxWindow* wnd,
                const wxRect& rect,
                int state);
    virtual wxSize GetLabelSize(
                wxDC& dc,
                wxWindow* wnd,
                const wxAuiToolBarItem& item);
    virtual wxSize GetToolSize(
                wxDC& dc,
                wxWindow* wnd,
                const wxAuiToolBarItem& item);
    virtual int GetElementSize(int element);
    virtual void SetElementSize(int element_id, int size);
    virtual int ShowDropDown(wxWindow* wnd,
                             const wxAuiToolBarItemArray& items);
};
WXGO_DECL_TYPECONV(AuiToolBar)
class wxAuiToolBar : public wxControl
{
public:
    wxAuiToolBar();
    wxAuiToolBar(wxWindow* parent,
                 wxWindowID id = wxID_ANY,
                 const wxPoint& position = wxDefaultPosition,
                 const wxSize& size = wxDefaultSize,
                 long style = wxAUI_TB_DEFAULT_STYLE);
    bool Create(wxWindow* parent,
                wxWindowID id = wxID_ANY,
                const wxPoint& pos = wxDefaultPosition,
                const wxSize& size = wxDefaultSize,
                long style = wxAUI_TB_DEFAULT_STYLE);
    virtual ~wxAuiToolBar();
    void SetWindowStyleFlag(long style);
    long GetWindowStyleFlag() const;
    void SetArtProvider(wxAuiToolBarArt* art);
    wxAuiToolBarArt* GetArtProvider() const;
    bool SetFont(const wxFont& font);
    wxAuiToolBarItem* AddTool(int tool_id,
                 const wxString& label,
                 const wxBitmap& bitmap,
                 const wxString& short_help_string = wxEmptyString,
                 wxItemKind kind = wxITEM_NORMAL);
    wxAuiToolBarItem* AddTool(int tool_id,
                 const wxString& label,
                 const wxBitmap& bitmap,
                 const wxBitmap& disabled_bitmap,
                 wxItemKind kind,
                 const wxString& short_help_string,
                 const wxString& long_help_string,
                 wxObject* client_data);
    wxAuiToolBarItem* AddTool(int tool_id,
                 const wxBitmap& bitmap,
                 const wxBitmap& disabled_bitmap,
                 bool toggle = false,
                 wxObject* client_data = NULL,
                 const wxString& short_help_string = wxEmptyString,
                 const wxString& long_help_string = wxEmptyString);
    wxAuiToolBarItem* AddLabel(int tool_id,
                  const wxString& label = wxEmptyString,
                  const int width = -1);
    wxAuiToolBarItem* AddControl(wxControl* control,
                    const wxString& label = wxEmptyString);
    wxAuiToolBarItem* AddSeparator();
    wxAuiToolBarItem* AddSpacer(int pixels);
    wxAuiToolBarItem* AddStretchSpacer(int proportion = 1);
    bool Realize();
    wxControl* FindControl(int window_id);
    wxAuiToolBarItem* FindToolByPosition(wxCoord x, wxCoord y) const;
    wxAuiToolBarItem* FindToolByIndex(int idx) const;
    wxAuiToolBarItem* FindTool(int tool_id) const;
    void ClearTools();
    void Clear();
    bool DeleteTool(int tool_id);
    bool DeleteByIndex(int tool_id);
    size_t GetToolCount() const;
    int GetToolPos(int tool_id) const;
    int GetToolIndex(int tool_id) const;
    bool GetToolFits(int tool_id) const;
    wxRect GetToolRect(int tool_id) const;
    bool GetToolFitsByIndex(int tool_id) const;
    bool GetToolBarFits() const;
    void SetMargins(const wxSize& size);
    void SetMargins(int x, int y);
    void SetMargins(int left, int right, int top, int bottom);
    void SetToolBitmapSize(const wxSize& size);
    wxSize GetToolBitmapSize() const;
    bool GetOverflowVisible() const;
    void SetOverflowVisible(bool visible);
    bool GetGripperVisible() const;
    void SetGripperVisible(bool visible);
    void ToggleTool(int tool_id, bool state);
    bool GetToolToggled(int tool_id) const;
    void EnableTool(int tool_id, bool state);
    bool GetToolEnabled(int tool_id) const;
    void SetToolDropDown(int tool_id, bool dropdown);
    bool GetToolDropDown(int tool_id) const;
    void SetToolBorderPadding(int padding);
    int  GetToolBorderPadding() const;
    void SetToolTextOrientation(int orientation);
    int  GetToolTextOrientation() const;
    void SetToolPacking(int packing);
    int  GetToolPacking() const;
    void SetToolProportion(int tool_id, int proportion);
    int  GetToolProportion(int tool_id) const;
    void SetToolSeparation(int separation);
    int GetToolSeparation() const;
    void SetToolSticky(int tool_id, bool sticky);
    bool GetToolSticky(int tool_id) const;
    wxString GetToolLabel(int tool_id) const;
    void SetToolLabel(int tool_id, const wxString& label);
    wxBitmap GetToolBitmap(int tool_id) const;
    void SetToolBitmap(int tool_id, const wxBitmap& bitmap);
    wxString GetToolShortHelp(int tool_id) const;
    void SetToolShortHelp(int tool_id, const wxString& help_string);
    wxString GetToolLongHelp(int tool_id) const;
    void SetToolLongHelp(int tool_id, const wxString& help_string);
    void SetCustomOverflowItems(const wxAuiToolBarItemArray& prepend,
                                const wxAuiToolBarItemArray& append);
    wxSize GetHintSize(int dock_direction) const;
    bool IsPaneValid(const wxAuiPaneInfo& pane) const;
};
%constant wxEventType wxEVT_AUITOOLBAR_TOOL_DROPDOWN;
%constant wxEventType wxEVT_AUITOOLBAR_OVERFLOW_CLICK;
%constant wxEventType wxEVT_AUITOOLBAR_RIGHT_CLICK;
%constant wxEventType wxEVT_AUITOOLBAR_MIDDLE_CLICK;
%constant wxEventType wxEVT_AUITOOLBAR_BEGIN_DRAG;