WXGO_DECL_TYPECONV(RibbonToolBar)
class wxRibbonToolBar : public wxRibbonControl
{
public:
    wxRibbonToolBar();
    wxRibbonToolBar(wxWindow* parent,
                  wxWindowID id = wxID_ANY,
                  const wxPoint& pos = wxDefaultPosition,
                  const wxSize& size = wxDefaultSize,
                  long style = 0);
    virtual ~wxRibbonToolBar();
    bool Create(wxWindow* parent,
                wxWindowID id = wxID_ANY,
                const wxPoint& pos = wxDefaultPosition,
                const wxSize& size = wxDefaultSize,
                long style = 0);
    virtual wxRibbonToolBarToolBase* AddTool(
                int tool_id,
                const wxBitmap& bitmap,
                const wxString& help_string,
                wxRibbonButtonKind kind = wxRIBBON_BUTTON_NORMAL);
    virtual wxRibbonToolBarToolBase* AddDropdownTool(
                int tool_id,
                const wxBitmap& bitmap,
                const wxString& help_string = wxEmptyString);
    virtual wxRibbonToolBarToolBase* AddHybridTool(
                int tool_id,
                const wxBitmap& bitmap,
                const wxString& help_string = wxEmptyString);
    virtual wxRibbonToolBarToolBase* AddToggleTool(
        int tool_id,
        const wxBitmap& bitmap,
        const wxString& help_string);
    virtual wxRibbonToolBarToolBase* AddTool(
                int tool_id,
                const wxBitmap& bitmap,
                const wxBitmap& bitmap_disabled = wxNullBitmap,
                const wxString& help_string = wxEmptyString,
                wxRibbonButtonKind kind = wxRIBBON_BUTTON_NORMAL,
                wxObject* client_data = NULL);
    virtual wxRibbonToolBarToolBase* AddSeparator();
    virtual wxRibbonToolBarToolBase* InsertTool(
                size_t pos,
                int tool_id,
                const wxBitmap& bitmap,
                const wxString& help_string,
                wxRibbonButtonKind kind = wxRIBBON_BUTTON_NORMAL);
    virtual wxRibbonToolBarToolBase* InsertDropdownTool(
                size_t pos,
                int tool_id,
                const wxBitmap& bitmap,
                const wxString& help_string = wxEmptyString);
    virtual wxRibbonToolBarToolBase* InsertHybridTool(
                size_t pos,
                int tool_id,
                const wxBitmap& bitmap,
                const wxString& help_string = wxEmptyString);
    virtual wxRibbonToolBarToolBase* InsertToggleTool(
                size_t pos,
                int tool_id,
                const wxBitmap& bitmap,
                const wxString& help_string = wxEmptyString);
    virtual wxRibbonToolBarToolBase* InsertTool(
                size_t pos,
                int tool_id,
                const wxBitmap& bitmap,
                const wxBitmap& bitmap_disabled = wxNullBitmap,
                const wxString& help_string = wxEmptyString,
                wxRibbonButtonKind kind = wxRIBBON_BUTTON_NORMAL,
                wxObject* client_data = NULL);
    virtual wxRibbonToolBarToolBase* InsertSeparator(size_t pos);
    virtual void ClearTools();
    virtual bool DeleteTool(int tool_id);
    virtual bool DeleteToolByPos(size_t pos);
    virtual wxRibbonToolBarToolBase* FindById(int tool_id)const;
    wxRibbonToolBarToolBase* GetToolByPos(size_t pos) const;
    virtual size_t GetToolCount() const;
    virtual int GetToolId(const wxRibbonToolBarToolBase* tool)const;
    virtual wxObject* GetToolClientData(int tool_id)const;
    virtual bool GetToolEnabled(int tool_id)const;
    virtual wxString GetToolHelpString(int tool_id)const;
    virtual wxRibbonButtonKind GetToolKind(int tool_id)const;
    virtual int GetToolPos(int tool_id)const;
    virtual bool GetToolState(int tool_id)const;
    virtual bool Realize();
    virtual void SetRows(int nMin, int nMax = -1);
    virtual void SetToolClientData(int tool_id, wxObject* clientData);
    virtual void SetToolDisabledBitmap(int tool_id, const wxBitmap &bitmap);
    virtual void SetToolHelpString(int tool_id, const wxString& helpString);
    virtual void SetToolNormalBitmap(int tool_id, const wxBitmap &bitmap);
    virtual void EnableTool(int tool_id, bool enable = true);
    virtual void ToggleTool(int tool_id, bool checked);
};