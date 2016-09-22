WXGO_DECL_TYPECONV(ComboBox)
class wxComboBox : public wxControl,
                   public wxItemContainer,
                   public wxTextEntry
{
public:
    wxComboBox();
    wxComboBox(wxWindow* parent, wxWindowID id,
               const wxString& value = wxEmptyString,
               const wxPoint& pos = wxDefaultPosition,
               const wxSize& size = wxDefaultSize,
               int n = 0,
               const wxString choices[] = NULL,
               long style = 0,
               const wxValidator& validator = wxDefaultValidator,
               const wxString& name = wxComboBoxNameStr);
    wxComboBox(wxWindow* parent, wxWindowID id,
               const wxString& value,
               const wxPoint& pos,
               const wxSize& size,
               const wxArrayString& choices,
               long style = 0,
               const wxValidator& validator = wxDefaultValidator,
               const wxString& name = wxComboBoxNameStr);
    virtual ~wxComboBox();
    bool Create(wxWindow *parent, wxWindowID id,
                const wxString& value = wxEmptyString,
                const wxPoint& pos = wxDefaultPosition,
                const wxSize& size = wxDefaultSize,
                int n = 0, const wxString choices[] = (const wxString *) NULL,
                long style = 0,
                const wxValidator& validator = wxDefaultValidator,
                const wxString& name = wxComboBoxNameStr);
    bool Create(wxWindow *parent, wxWindowID id,
                const wxString& value,
                const wxPoint& pos,
                const wxSize& size,
                const wxArrayString& choices,
                long style = 0,
                const wxValidator& validator = wxDefaultValidator,
                const wxString& name = wxComboBoxNameStr);
    virtual int GetCurrentSelection() const;
    virtual long GetInsertionPoint() const;
    bool IsListEmpty() const;
    bool IsTextEmpty() const;
    virtual void SetSelection(long from, long to);
    virtual void SetValue(const wxString& text);
    virtual void Popup();
    virtual void Dismiss();
    virtual int GetSelection() const;
    virtual void GetSelection(long *from, long *to) const;
    virtual void SetSelection(int n);
    virtual int FindString(const wxString& s, bool bCase = false) const;
    virtual wxString GetString(unsigned int n) const;
    virtual wxString GetStringSelection() const;
    virtual void SetString(unsigned int n, const wxString& text);
    virtual unsigned int GetCount() const;
};