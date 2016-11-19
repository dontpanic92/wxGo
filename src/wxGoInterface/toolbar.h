%typedef int wxToolBarToolStyle;
#define wxTOOL_STYLE_BUTTON     1
#define wxTOOL_STYLE_SEPARATOR  2
#define wxTOOL_STYLE_CONTROL wxTOOL_STYLE_SEPARATOR  + 1
enum
{
    wxTB_HORIZONTAL  = wxHORIZONTAL,
    wxTB_TOP         = wxTB_HORIZONTAL,
    wxTB_VERTICAL    = wxVERTICAL,
    wxTB_LEFT        = wxTB_VERTICAL,
    wxTB_3DBUTTONS,
    wxTB_FLAT,
    wxTB_DOCKABLE,
    wxTB_NOICONS,
    wxTB_TEXT,
    wxTB_NODIVIDER,
    wxTB_NOALIGN,
    wxTB_HORZ_LAYOUT,
    wxTB_HORZ_TEXT   = wxTB_HORZ_LAYOUT | wxTB_TEXT,
    wxTB_NO_TOOLTIPS,
    wxTB_BOTTOM,
    wxTB_RIGHT,
    wxTB_DEFAULT_STYLE = wxTB_HORIZONTAL | wxTB_FLAT
};
WXGO_DECL_TYPECONV(ToolBarToolBase)
class wxToolBarToolBase : public wxObject
{
public:
    wxToolBarToolBase(wxToolBar *tbar = NULL,
                      int toolid = wxID_SEPARATOR,
                      const wxString& label = wxEmptyString,
                      const wxBitmap& bmpNormal = wxNullBitmap,
                      const wxBitmap& bmpDisabled = wxNullBitmap,
                      wxItemKind kind = wxITEM_NORMAL,
                      wxObject *clientData = NULL,
                      const wxString& shortHelpString = wxEmptyString,
                      const wxString& longHelpString = wxEmptyString);
    wxToolBarToolBase(wxToolBar *tbar,
                      wxControl *control,
                      const wxString& label);
    virtual ~wxToolBarToolBase();
    int GetId() const;
    wxControl *GetControl() const;
    wxToolBar *GetToolBar() const;
    bool IsStretchable() const;
    bool IsButton() const;
    bool IsControl() const;
    bool IsSeparator() const;
    bool IsStretchableSpace() const;
    int GetStyle() const;
    wxItemKind GetKind() const;
    void MakeStretchable();
    bool IsEnabled() const;
    bool IsToggled() const;
    bool CanBeToggled() const;
    const wxBitmap& GetNormalBitmap() const;
    const wxBitmap& GetDisabledBitmap() const;
    const wxBitmap& GetBitmap() const;
    const wxString& GetLabel() const;
    const wxString& GetShortHelp() const;
    const wxString& GetLongHelp() const;
    wxObject *GetClientData() const;
    virtual bool Enable(bool enable);
    virtual bool Toggle(bool toggle);
    virtual bool SetToggle(bool toggle);
    virtual bool SetShortHelp(const wxString& help);
    virtual bool SetLongHelp(const wxString& help);
    void Toggle();
    virtual void SetNormalBitmap(const wxBitmap& bmp);
    virtual void SetDisabledBitmap(const wxBitmap& bmp);
    virtual void SetLabel(const wxString& label);
    void SetClientData(wxObject *clientData);
    virtual void Detach();
    virtual void Attach(wxToolBar *tbar);
    virtual void SetDropdownMenu(wxMenu *menu);
    wxMenu *GetDropdownMenu() const;
};
WXGO_DECL_TYPECONV(ToolBar)
class wxToolBar : public wxControl
{
public:
    wxToolBar();
    wxToolBar(wxWindow* parent, wxWindowID id,
              const wxPoint& pos = wxDefaultPosition,
              const wxSize& size = wxDefaultSize,
              long style = wxTB_HORIZONTAL,
              const wxString& name = wxToolBarNameStr);
    virtual ~wxToolBar();
    wxToolBarToolBase* AddCheckTool(int toolId, const wxString& label,
                                    const wxBitmap& bitmap1,
                                    const wxBitmap& bmpDisabled = wxNullBitmap,
                                    const wxString& shortHelp = wxEmptyString,
                                    const wxString& longHelp = wxEmptyString,
                                    wxObject* clientData = NULL);
    virtual wxToolBarToolBase* AddControl(wxControl* control,
                                          const wxString& label = wxEmptyString);
    wxToolBarToolBase* AddRadioTool(int toolId, const wxString& label,
                                    const wxBitmap& bitmap1,
                                    const wxBitmap& bmpDisabled = wxNullBitmap,
                                    const wxString& shortHelp = wxEmptyString,
                                    const wxString& longHelp = wxEmptyString,
                                    wxObject* clientData = NULL);
    virtual wxToolBarToolBase* AddSeparator();
    wxToolBarToolBase *AddStretchableSpace();
    virtual wxToolBarToolBase* AddTool(wxToolBarToolBase* tool);
    wxToolBarToolBase* AddTool(int toolId, const wxString& label,
                               const wxBitmap& bitmap,
                               const wxString& shortHelp = wxEmptyString,
                               wxItemKind kind = wxITEM_NORMAL);
    wxToolBarToolBase* AddTool(int toolId, const wxString& label,
                               const wxBitmap& bitmap,
                               const wxBitmap& bmpDisabled,
                               wxItemKind kind = wxITEM_NORMAL,
                               const wxString& shortHelpString = wxEmptyString,
                               const wxString& longHelpString = wxEmptyString,
                               wxObject* clientData = NULL);
    virtual void ClearTools();
    virtual bool DeleteTool(int toolId);
    virtual bool DeleteToolByPos(size_t pos);
    virtual void EnableTool(int toolId, bool enable);
    wxToolBarToolBase* FindById(int id) const;
    virtual wxControl* FindControl(int id);
    virtual wxToolBarToolBase* FindToolForPosition(wxCoord x, wxCoord y) const;
    wxSize GetMargins() const;
    virtual wxSize GetToolBitmapSize() const;
    const wxToolBarToolBase *GetToolByPos(int pos) const;
    virtual wxObject* GetToolClientData(int toolId) const;
    virtual bool GetToolEnabled(int toolId) const;
    virtual wxString GetToolLongHelp(int toolId) const;
    virtual int GetToolPacking() const;
    virtual int GetToolPos(int toolId) const;
    virtual int GetToolSeparation() const;
    virtual wxString GetToolShortHelp(int toolId) const;
    virtual wxSize GetToolSize() const;
    virtual bool GetToolState(int toolId) const;
    size_t GetToolsCount() const;
    virtual wxToolBarToolBase* InsertControl(size_t pos, wxControl* control,
                                             const wxString& label = wxEmptyString);
    virtual wxToolBarToolBase* InsertSeparator(size_t pos);
    wxToolBarToolBase *InsertStretchableSpace(size_t pos);
    wxToolBarToolBase* InsertTool(  size_t pos,
                                    int toolId,
                                    const wxString& label,
                                    const wxBitmap& bitmap,
                                    const wxBitmap& bmpDisabled = wxNullBitmap,
                                    wxItemKind kind = wxITEM_NORMAL,
                                    const wxString& shortHelp = wxEmptyString,
                                    const wxString& longHelp = wxEmptyString,
                                    wxObject *clientData = NULL);
    wxToolBarToolBase* InsertTool(size_t pos,
                                  wxToolBarToolBase* tool);
    virtual bool OnLeftClick(int toolId, bool toggleDown);
    virtual void OnMouseEnter(int toolId);
    virtual void OnRightClick(int toolId, long x, long y);
    virtual bool Realize();
    virtual wxToolBarToolBase* RemoveTool(int id);
    bool SetDropdownMenu(int id, wxMenu* menu);
    virtual void SetMargins(int x, int y);
    void SetMargins(const wxSize& size);
    virtual void SetToolBitmapSize(const wxSize& size);
    virtual void SetToolClientData(int id, wxObject* clientData);
    virtual void SetToolDisabledBitmap(int id, const wxBitmap& bitmap);
    virtual void SetToolLongHelp(int toolId, const wxString& helpString);
    virtual void SetToolNormalBitmap(int id, const wxBitmap& bitmap);
    virtual void SetToolPacking(int packing);
    virtual void SetToolSeparation(int separation);
    virtual void SetToolShortHelp(int toolId, const wxString& helpString);
    virtual void ToggleTool(int toolId, bool toggle);
    virtual wxToolBarToolBase *CreateTool(int toolId,
                                          const wxString& label,
                                          const wxBitmap& bmpNormal,
                                          const wxBitmap& bmpDisabled = wxNullBitmap,
                                          wxItemKind kind = wxITEM_NORMAL,
                                          wxObject *clientData = NULL,
                                          const wxString& shortHelp = wxEmptyString,
                                          const wxString& longHelp = wxEmptyString);
    virtual wxToolBarToolBase *CreateTool(wxControl *control,
                                          const wxString& label);
    wxToolBarToolBase *CreateSeparator();
};