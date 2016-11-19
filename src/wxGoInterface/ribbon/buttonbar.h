%typedef int wxRibbonButtonBarButtonState;
#define wxRIBBON_BUTTONBAR_BUTTON_SMALL      0 << 0
#define wxRIBBON_BUTTONBAR_BUTTON_MEDIUM     1 << 0
#define wxRIBBON_BUTTONBAR_BUTTON_LARGE      2 << 0
#define wxRIBBON_BUTTONBAR_BUTTON_SIZE_MASK  3 << 0
#define wxRIBBON_BUTTONBAR_BUTTON_NORMAL_HOVERED     1 << 3
#define wxRIBBON_BUTTONBAR_BUTTON_DROPDOWN_HOVERED   1 << 4
#define wxRIBBON_BUTTONBAR_BUTTON_HOVER_MASK         wxRIBBON_BUTTONBAR_BUTTON_NORMAL_HOVERED | wxRIBBON_BUTTONBAR_BUTTON_DROPDOWN_HOVERED
#define wxRIBBON_BUTTONBAR_BUTTON_NORMAL_ACTIVE      1 << 5
#define wxRIBBON_BUTTONBAR_BUTTON_DROPDOWN_ACTIVE    1 << 6
#define wxRIBBON_BUTTONBAR_BUTTON_DISABLED           1 << 7
#define wxRIBBON_BUTTONBAR_BUTTON_TOGGLED            1 << 8
#define wxRIBBON_BUTTONBAR_BUTTON_STATE_MASK         0x1F8
WXGO_DECL_TYPECONV(RibbonButtonBar)
class wxRibbonButtonBar : public wxRibbonControl
{
public:
    wxRibbonButtonBar();
    wxRibbonButtonBar(wxWindow* parent,
                  wxWindowID id = wxID_ANY,
                  const wxPoint& pos = wxDefaultPosition,
                  const wxSize& size = wxDefaultSize,
                  long style = 0);
    virtual ~wxRibbonButtonBar();
    bool Create(wxWindow* parent,
                wxWindowID id = wxID_ANY,
                const wxPoint& pos = wxDefaultPosition,
                const wxSize& size = wxDefaultSize,
                long style = 0);
    virtual wxRibbonButtonBarButtonBase* AddButton(
                int button_id,
                const wxString& label,
                const wxBitmap& bitmap,
                const wxString& help_string,
                wxRibbonButtonKind kind = wxRIBBON_BUTTON_NORMAL);
    virtual wxRibbonButtonBarButtonBase* AddDropdownButton(
                int button_id,
                const wxString& label,
                const wxBitmap& bitmap,
                const wxString& help_string = wxEmptyString);
    virtual wxRibbonButtonBarButtonBase* AddHybridButton(
                int button_id,
                const wxString& label,
                const wxBitmap& bitmap,
                const wxString& help_string = wxEmptyString);
    virtual wxRibbonButtonBarButtonBase* AddToggleButton(
                int button_id,
                const wxString& label,
                const wxBitmap& bitmap,
                const wxString& help_string = wxEmptyString);
    virtual wxRibbonButtonBarButtonBase* AddButton(
                int button_id,
                const wxString& label,
                const wxBitmap& bitmap,
                const wxBitmap& bitmap_small = wxNullBitmap,
                const wxBitmap& bitmap_disabled = wxNullBitmap,
                const wxBitmap& bitmap_small_disabled = wxNullBitmap,
                wxRibbonButtonKind kind = wxRIBBON_BUTTON_NORMAL,
                const wxString& help_string = wxEmptyString);
    virtual wxRibbonButtonBarButtonBase* InsertButton(
                size_t pos,
                int button_id,
                const wxString& label,
                const wxBitmap& bitmap,
                const wxString& help_string,
                wxRibbonButtonKind kind = wxRIBBON_BUTTON_NORMAL);
    virtual wxRibbonButtonBarButtonBase* InsertDropdownButton(
                size_t pos,
                int button_id,
                const wxString& label,
                const wxBitmap& bitmap,
                const wxString& help_string = wxEmptyString);
    virtual wxRibbonButtonBarButtonBase* InsertHybridButton(
                size_t pos,
                int button_id,
                const wxString& label,
                const wxBitmap& bitmap,
                const wxString& help_string = wxEmptyString);
    virtual wxRibbonButtonBarButtonBase* InsertToggleButton(
                size_t pos,
                int button_id,
                const wxString& label,
                const wxBitmap& bitmap,
                const wxString& help_string = wxEmptyString);
    virtual wxRibbonButtonBarButtonBase* InsertButton(
                size_t pos,
                int button_id,
                const wxString& label,
                const wxBitmap& bitmap,
                const wxBitmap& bitmap_small = wxNullBitmap,
                const wxBitmap& bitmap_disabled = wxNullBitmap,
                const wxBitmap& bitmap_small_disabled = wxNullBitmap,
                wxRibbonButtonKind kind = wxRIBBON_BUTTON_NORMAL,
                const wxString& help_string = wxEmptyString);
    virtual size_t GetButtonCount() const;
    void SetItemClientObject(wxRibbonButtonBarButtonBase* item, wxClientData* data);
    wxClientData* GetItemClientObject(const wxRibbonButtonBarButtonBase* item) const;
    void SetItemClientData(wxRibbonButtonBarButtonBase* item, void* data);
    void* GetItemClientData(const wxRibbonButtonBarButtonBase* item) const;
    virtual wxRibbonButtonBarButtonBase *GetItem(size_t n) const;
    virtual wxRibbonButtonBarButtonBase *GetItemById(int id) const;
    virtual int GetItemId(wxRibbonButtonBarButtonBase *) const;
    virtual bool Realize();
    virtual void ClearButtons();
    virtual bool DeleteButton(int button_id);
    virtual void EnableButton(int button_id, bool enable = true);
    virtual void ToggleButton(int button_id, bool checked);
    virtual wxRibbonButtonBarButtonBase *GetActiveItem() const;
    virtual wxRibbonButtonBarButtonBase *GetHoveredItem() const;
    void SetShowToolTipsForDisabled(bool show);
    bool GetShowToolTipsForDisabled() const;
};
WXGO_DECL_TYPECONV(RibbonButtonBarEvent)
class wxRibbonButtonBarEvent : public wxCommandEvent
{
public:
    wxRibbonButtonBarEvent(wxEventType command_type = wxEVT_NULL,
                       int win_id = 0,
                       wxRibbonButtonBar* bar = NULL,
                       wxRibbonButtonBarButtonBase* button = NULL);
    wxRibbonButtonBar* GetBar();
    void SetBar(wxRibbonButtonBar* bar);
    wxRibbonButtonBarButtonBase* GetButton();
    void SetButton(wxRibbonButtonBarButtonBase* bar);
    bool PopupMenu(wxMenu* menu);
};