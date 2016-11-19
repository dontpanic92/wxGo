WXGO_DECL_TYPECONV(MenuBar)
class wxMenuBar : public wxWindow
{
public:
    wxMenuBar(long style = 0);
    wxMenuBar(size_t n, wxMenu* menus[], const wxString titles[],
              long style = 0);
    virtual ~wxMenuBar();
    virtual bool Append(wxMenu* menu, const wxString& title);
    void Check(int id, bool check);
    void Enable(int id, bool enable);
    bool IsEnabledTop(size_t pos) const;
    virtual void EnableTop(size_t pos, bool enable);
    virtual wxMenuItem* FindItem(int id, wxMenu** menu = NULL) const;
    int FindMenu(const wxString& title) const;
    virtual int FindMenuItem(const wxString& menuString,
                             const wxString& itemString) const;
    wxString GetHelpString(int id) const;
    wxString GetLabel(int id) const;
    wxMenu* GetMenu(size_t menuIndex) const;
    size_t GetMenuCount() const;
    virtual wxString GetMenuLabel(size_t pos) const;
    virtual wxString GetMenuLabelText(size_t pos) const;
    virtual bool Insert(size_t pos, wxMenu* menu, const wxString& title);
    bool IsChecked(int id) const;
    bool IsEnabled(int id) const;
    virtual void Refresh(bool eraseBackground = true, const wxRect* rect = NULL);
    virtual wxMenu* Remove(size_t pos);
    virtual wxMenu* Replace(size_t pos, wxMenu* menu, const wxString& title);
    void SetHelpString(int id, const wxString& helpString);
    void SetLabel(int id, const wxString& label);
    virtual void SetMenuLabel(size_t pos, const wxString& label);
#ifdef __WXOSX__
    static void MacSetCommonMenuBar(wxMenuBar* menubar);
#endif
#ifdef __WXOSX__
    static wxMenuBar* MacGetCommonMenuBar();
#endif
#ifdef __WXOSX__
    wxMenu *OSXGetAppleMenu() const;
#endif
    wxFrame *GetFrame() const;
    bool IsAttached() const;
    virtual void Attach(wxFrame *frame);
    virtual void Detach();
};
WXGO_DECL_TYPECONV(Menu)
class wxMenu : public wxEvtHandler
{
public:
    wxMenu();
    wxMenu(long style);
    wxMenu(const wxString& title, long style = 0);
    virtual ~wxMenu();
    wxMenuItem* Append(int id, const wxString& item = wxEmptyString,
                       const wxString& helpString = wxEmptyString,
                       wxItemKind kind = wxITEM_NORMAL);
    wxMenuItem* Append(int id, const wxString& item, wxMenu* subMenu,
                       const wxString& helpString = wxEmptyString);
    wxMenuItem* Append(wxMenuItem* menuItem);
    wxMenuItem* AppendCheckItem(int id, const wxString& item,
                                const wxString& help = wxEmptyString);
    wxMenuItem* AppendRadioItem(int id, const wxString& item,
                                const wxString& help = wxEmptyString);
    wxMenuItem* AppendSeparator();
    wxMenuItem* AppendSubMenu(wxMenu* submenu, const wxString& text,
                              const wxString& help = wxEmptyString);
    virtual void Break();
    void Check(int id, bool check);
    bool Delete(int id);
    bool Delete(wxMenuItem* item);
    bool Destroy(int id);
    bool Destroy(wxMenuItem* item);
    void Enable(int id, bool enable);
    wxMenuItem *FindChildItem(int id, size_t *pos = NULL) const;
    virtual int FindItem(const wxString& itemString) const;
    wxMenuItem* FindItem(int id, wxMenu** menu = NULL) const;
    wxMenuItem* FindItemByPosition(size_t position) const;
    virtual wxString GetHelpString(int id) const;
    wxString GetLabel(int id) const;
    wxString GetLabelText(int id) const;
    size_t GetMenuItemCount() const;
    wxMenuItemList& GetMenuItems();
    wxString GetTitle() const;
    wxMenuItem* Insert(size_t pos, wxMenuItem* menuItem);
    wxMenuItem* Insert(size_t pos, int id,
                       const wxString& item = wxEmptyString,
                       const wxString& helpString = wxEmptyString,
                       wxItemKind kind = wxITEM_NORMAL);
    wxMenuItem* Insert(size_t pos, int id, const wxString& text,
                       wxMenu* submenu, const wxString& help = wxEmptyString);
    wxMenuItem* InsertCheckItem(size_t pos, int id, const wxString& item,
                                const wxString& helpString = wxEmptyString);
    wxMenuItem* InsertRadioItem(size_t pos, int id, const wxString& item,
                                const wxString& helpString = wxEmptyString);
    wxMenuItem* InsertSeparator(size_t pos);
    bool IsChecked(int id) const;
    bool IsEnabled(int id) const;
    wxMenuItem* Prepend(wxMenuItem* item);
    wxMenuItem* Prepend(int id, const wxString& item = wxEmptyString,
                        const wxString& helpString = wxEmptyString,
                        wxItemKind kind = wxITEM_NORMAL);
    wxMenuItem* Prepend(int id, const wxString& text, wxMenu* submenu,
                        const wxString& help = wxEmptyString);
    wxMenuItem* PrependCheckItem(int id, const wxString& item,
                                 const wxString& helpString = wxEmptyString);
    wxMenuItem* PrependRadioItem(int id, const wxString& item,
                                 const wxString& helpString = wxEmptyString);
    wxMenuItem* PrependSeparator();
    wxMenuItem* Remove(int id);
    wxMenuItem* Remove(wxMenuItem* item);
    virtual void SetHelpString(int id, const wxString& helpString);
    void SetLabel(int id, const wxString& label);
    virtual void SetTitle(const wxString& title);
    void UpdateUI(wxEvtHandler* source = NULL);
    void SetInvokingWindow(wxWindow *win);
    wxWindow *GetInvokingWindow() const;
    wxWindow *GetWindow() const;
    long GetStyle() const;
    void SetParent(wxMenu *parent);
    wxMenu *GetParent() const;
    virtual void Attach(wxMenuBar *menubar);
    virtual void Detach();
    bool IsAttached() const;
};