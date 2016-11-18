WXGO_DECL_TYPECONV(MenuItem)
class wxMenuItem : public wxObject
{
public:
    wxMenuItem(wxMenu* parentMenu = NULL, int id = wxID_SEPARATOR,
               const wxString& text = wxEmptyString,
               const wxString& helpString = wxEmptyString,
               wxItemKind kind = wxITEM_NORMAL,
               wxMenu* subMenu = NULL);
    virtual ~wxMenuItem();
    virtual void Check(bool check = true);
    virtual void Enable(bool enable = true);
    static wxString GetLabelText(const wxString& text);
#ifdef __WXMSW__
    wxColour& GetBackgroundColour() const;
    virtual const wxBitmap& GetBitmap(bool checked = true) const;
    virtual const wxBitmap& GetDisabledBitmap() const;
    wxFont& GetFont() const;
#else
    const wxBitmap& GetBitmap() const;
#endif
    const wxString& GetHelp() const;
    int GetId() const;
    virtual wxString GetItemLabel() const;
    virtual wxString GetItemLabelText() const;
    wxItemKind GetKind() const;
#ifdef __WXMSW__
    int GetMarginWidth() const;
#endif
    wxMenu* GetMenu() const;
    wxMenu* GetSubMenu() const;
#ifdef __WXMSW__
    wxColour& GetTextColour() const;
#endif
    virtual wxAcceleratorEntry *GetAccel() const;
    bool IsCheck() const;
    bool IsCheckable() const;
    virtual bool IsChecked() const;
    virtual bool IsEnabled() const;
    bool IsRadio() const;
    bool IsSeparator() const;
    bool IsSubMenu() const;
#ifdef __WXMSW__
    void SetBackgroundColour(const wxColour& colour);
    virtual void SetBitmap(const wxBitmap& bmp, bool checked = true);
    void SetBitmaps(const wxBitmap& checked,
                    const wxBitmap& unchecked = wxNullBitmap);
    void SetDisabledBitmap(const wxBitmap& disabled);
    void SetFont(const wxFont& font);
#else
    virtual void SetBitmap(const wxBitmap& bmp);
#endif
    void SetHelp(const wxString& helpString);
    virtual void SetItemLabel(const wxString& label);
#ifdef __WXMSW__
    void SetMarginWidth(int width);
#endif
    void SetMenu(wxMenu* menu);
    void SetSubMenu(wxMenu* menu);
#ifdef __WXMSW__
    void SetTextColour(const wxColour& colour);
#endif
    virtual void SetAccel(wxAcceleratorEntry *accel);
};