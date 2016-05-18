WXGO_DECL_TYPECONV(RadioBox)
class wxRadioBox : public wxControl, public wxItemContainerImmutable
{
public:
    wxRadioBox();
    wxRadioBox(wxWindow* parent, wxWindowID id,
               const wxString& label,
               const wxPoint& pos,
               const wxSize& size,
               const wxArrayString& choices,
               int majorDimension = 0,
               long style = wxRA_SPECIFY_COLS,
               const wxValidator& validator = wxDefaultValidator,
               const wxString& name = wxRadioBoxNameStr);
    virtual ~wxRadioBox();
    bool Create(wxWindow* parent, wxWindowID id,
                const wxString& label,
                const wxPoint& pos,
                const wxSize& size,
                const wxArrayString& choices,
                int majorDimension = 0,
                long style = wxRA_SPECIFY_COLS,
                const wxValidator& validator = wxDefaultValidator,
                const wxString& name = wxRadioBoxNameStr);
    virtual bool Enable(unsigned int n, bool enable = true);
    virtual int FindString(const wxString& string, bool bCase = false) const;
    unsigned int GetColumnCount() const;
    virtual int GetItemFromPoint(const wxPoint& pt) const;
    wxString GetItemHelpText(unsigned int item) const;
    wxToolTip* GetItemToolTip(unsigned int item) const;
    unsigned int GetRowCount() const;
    virtual bool IsItemEnabled(unsigned int n) const;
    virtual bool IsItemShown(unsigned int n) const;
    void SetItemHelpText(unsigned int item, const wxString& helptext);
    void SetItemToolTip(unsigned int item, const wxString& text);
    virtual void SetSelection(int n);
    virtual bool Show(unsigned int item, bool show = true);
    virtual unsigned int GetCount() const;
    virtual wxString GetString(unsigned int n) const;
    virtual void SetString(unsigned int n, const wxString& string);
    virtual int GetSelection() const;
};