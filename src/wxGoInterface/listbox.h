class wxListBox : public wxControl,
                  public wxItemContainer
{
public:
    wxListBox();
    /*wxListBox(wxWindow* parent, wxWindowID id,
              const wxPoint& pos = wxDefaultPosition,
              const wxSize& size = wxDefaultSize,
              int n = 0,
              const wxString choices[] = NULL,
              long style = 0,
              const wxValidator& validator = wxDefaultValidator,
              const wxString& name = wxListBoxNameStr);*/
    wxListBox(wxWindow* parent, wxWindowID id,
              const wxPoint& pos,
              const wxSize& size,
              const wxArrayString& choices,
              long style = 0,
              const wxValidator& validator = wxDefaultValidator,
              const wxString& name = wxListBoxNameStr);
    virtual ~wxListBox();
    /*bool Create(wxWindow *parent, wxWindowID id,
                const wxPoint& pos = wxDefaultPosition,
                const wxSize& size = wxDefaultSize,
                int n = 0, const wxString choices[] = NULL,
                long style = 0,
                const wxValidator& validator = wxDefaultValidator,
                const wxString& name = wxListBoxNameStr);*/
    bool Create(wxWindow *parent, wxWindowID id,
                const wxPoint& pos,
                const wxSize& size,
                const wxArrayString& choices,
                long style = 0,
                const wxValidator& validator = wxDefaultValidator,
                const wxString& name = wxListBoxNameStr);
    void Deselect(int n);
    virtual void SetSelection(int n);
    virtual int GetSelection() const;
    virtual bool SetStringSelection(const wxString& s, bool select);
    virtual bool SetStringSelection(const wxString& s);
    virtual int GetSelections(wxArrayInt& selections) const;
    int HitTest(const wxPoint& point) const;
    int HitTest(int x, int y) const;
    /*void InsertItems(unsigned int nItems, const wxString *items,
                     unsigned int pos);*/
    void InsertItems(const wxArrayString& items,
                     unsigned int pos);
    virtual bool IsSelected(int n) const;
    void SetFirstItem(int n);
    void SetFirstItem(const wxString& string);
    virtual void EnsureVisible(int n);
    virtual bool IsSorted() const;
    virtual unsigned int GetCount() const; 
    virtual wxString GetString(unsigned int n) const; 
    virtual void SetString(unsigned int n, const wxString& s); 
    virtual int FindString(const wxString& s, bool bCase = false) const;     
};