%nodefaultctor wxMenuItemBase;
class wxMenuItemBase : public wxObject
{
public:
    static wxMenuItem *New(wxMenu *parentMenu = NULL,
                           int itemid = wxID_SEPARATOR,
                           const wxString& text = wxEmptyString,
                           const wxString& help = wxEmptyString,
                           wxItemKind kind = wxITEM_NORMAL,
                           wxMenu *subMenu = NULL);

    virtual ~wxMenuItemBase();

    wxMenu *GetMenu() const { return m_parentMenu; }
    void SetMenu(wxMenu* menu) { m_parentMenu = menu; }

    void SetId(int itemid) { m_id = itemid; }
    int  GetId() const { return m_id; }

    virtual void SetItemLabel(const wxString& str);	


    virtual wxString GetItemLabel() const;
    virtual wxString GetItemLabelText() const ;
    static wxString GetLabelText(const wxString& label);


    wxItemKind GetKind() const { return m_kind; }
    void SetKind(wxItemKind kind) { m_kind = kind; }
    bool IsSeparator() const { return m_kind == wxITEM_SEPARATOR; }

    bool IsCheck() const { return m_kind == wxITEM_CHECK; }
    bool IsRadio() const { return m_kind == wxITEM_RADIO; }

    virtual void SetCheckable(bool checkable);

    bool IsCheckable() const;
    bool IsSubMenu() const { return m_subMenu != NULL; }
    void SetSubMenu(wxMenu *menu) { m_subMenu = menu; }
    wxMenu *GetSubMenu() const { return m_subMenu; }


    virtual void Enable(bool enable = true) { m_isEnabled = enable; }
    virtual bool IsEnabled() const { return m_isEnabled; }

    virtual void Check(bool check = true) { m_isChecked = check; }
    virtual bool IsChecked() const { return m_isChecked; }
    void Toggle() { Check(!m_isChecked); }

    void SetHelp(const wxString& str);
    const wxString& GetHelp() const { return m_help; }

    static wxMenuItem *New(wxMenu *parentMenu,
                           int itemid,
                           const wxString& text,
                           const wxString& help,
                           bool isCheckable,
                           wxMenu *subMenu = NULL);
};


class wxMenuItem : public wxMenuItemBase
{
public:
    wxMenuItem(wxMenu *parentMenu = NULL,
               int id = wxID_SEPARATOR,
               const wxString& text = wxEmptyString,
               const wxString& help = wxEmptyString,
               wxItemKind kind = wxITEM_NORMAL,
               wxMenu *subMenu = NULL);
    virtual ~wxMenuItem();

    virtual void SetItemLabel( const wxString& str );
    virtual void Enable( bool enable = true );
    virtual void Check( bool check = true );
    virtual bool IsChecked() const;
    virtual void SetBitmap(const wxBitmap& bitmap);
    virtual const wxBitmap& GetBitmap() const { return m_bitmap; }

    void SetMenuItem(GtkWidget *menuItem);
    GtkWidget *GetMenuItem() const { return m_menuItem; }
    void SetGtkLabel();
};


class wxMenuBase : public wxEvtHandler
{
public:

    static wxMenu *New(const wxString& title = wxEmptyString, long style = 0);

    wxMenuBase(const wxString& title, long style = 0);
    wxMenuBase(long style = 0);

    virtual ~wxMenuBase();

    wxMenuItem* Append(int itemid,
                       const wxString& text = wxEmptyString,
                       const wxString& help = wxEmptyString,
                       wxItemKind kind = wxITEM_NORMAL);
                       
    wxMenuItem* AppendSeparator();

    wxMenuItem* AppendCheckItem(int itemid,
                                const wxString& text,
                                const wxString& help = wxEmptyString);

    wxMenuItem* AppendRadioItem(int itemid,
                                const wxString& text,
                                const wxString& help = wxEmptyString);
                                
    wxMenuItem* AppendSubMenu(wxMenu *submenu,
                              const wxString& text,
                              const wxString& help = wxEmptyString);


    wxMenuItem* Append(wxMenuItem *item) ;

    virtual void Break();

    wxMenuItem* Insert(size_t pos, wxMenuItem *item);

    wxMenuItem* Insert(size_t pos,
                       int itemid,
                       const wxString& text = wxEmptyString,
                       const wxString& help = wxEmptyString,
                       wxItemKind kind = wxITEM_NORMAL);

    wxMenuItem* InsertSeparator(size_t pos);

    wxMenuItem* InsertCheckItem(size_t pos,
                                int itemid,
                                const wxString& text,
                                const wxString& help = wxEmptyString);

    wxMenuItem* InsertRadioItem(size_t pos,
                                 int itemid,
                                 const wxString& text,
                                 const wxString& help = wxEmptyString);

    wxMenuItem* Insert(size_t pos,
                       int itemid,
                       const wxString& text,
                       wxMenu *submenu,
                       const wxString& help = wxEmptyString);

    wxMenuItem* Prepend(wxMenuItem *item);

    wxMenuItem* Prepend(int itemid,
                        const wxString& text = wxEmptyString,
                        const wxString& help = wxEmptyString,
                        wxItemKind kind = wxITEM_NORMAL);


    wxMenuItem* PrependSeparator();


    wxMenuItem* PrependCheckItem(int itemid,
                                 const wxString& text,
                                 const wxString& help = wxEmptyString);


    wxMenuItem* PrependRadioItem(int itemid,
                                 const wxString& text,
                                 const wxString& help = wxEmptyString);


    wxMenuItem* Prepend(int itemid,
                        const wxString& text,
                        wxMenu *submenu,
                        const wxString& help = wxEmptyString);


    wxMenuItem *Remove(int itemid);
    wxMenuItem *Remove(wxMenuItem *item);


    bool Delete(int itemid);
    bool Delete(wxMenuItem *item);

    bool Destroy(int itemid);
    bool Destroy(wxMenuItem *item);


    size_t GetMenuItemCount() const;

    wxMenuItemList& GetMenuItems() ;

    virtual int FindItem(const wxString& item) const;
    wxMenuItem* FindItem(int itemid, wxMenu **menu = NULL) const;

    wxMenuItem* FindItemByPosition(size_t position) const;

    void Enable(int itemid, bool enable);
    bool IsEnabled(int itemid) const;

    void Check(int itemid, bool check);
    bool IsChecked(int itemid) const;

    void SetLabel(int itemid, const wxString& label);
    wxString GetLabel(int itemid) const;

    wxString GetLabelText(int itemid) const ;

    virtual void SetHelpString(int itemid, const wxString& helpString);
    virtual wxString GetHelpString(int itemid) const;


    virtual void SetTitle(const wxString& title) { m_title = title; }
    const wxString& GetTitle() const { return m_title; }


    void SetEventHandler(wxEvtHandler *handler) { m_eventHandler = handler; }
    wxEvtHandler *GetEventHandler() const { return m_eventHandler; }

    void SetInvokingWindow(wxWindow *win);
    wxWindow *GetInvokingWindow() const { return m_invokingWindow; }

    wxWindow *GetWindow() const;

    long GetStyle() const { return m_style; }

    void UpdateUI(wxEvtHandler* source = NULL);

    wxMenuBar *GetMenuBar() const;

    virtual void Attach(wxMenuBarBase *menubar);
    virtual void Detach();

    bool IsAttached() const;

    void SetParent(wxMenu *parent) ;
    wxMenu *GetParent() const ;

    wxMenuItem *FindChildItem(int itemid, size_t *pos = NULL) const;

    bool SendEvent(int itemid, int checked = -1);

    void Append(int itemid,
                const wxString& text,
                const wxString& help,
                bool isCheckable);

    wxMenuItem* Append(int itemid,
                       const wxString& text,
                       wxMenu *submenu,
                       const wxString& help = wxEmptyString);

    void Insert(size_t pos,
                int itemid,
                const wxString& text,
                const wxString& help,
                bool isCheckable);

    void Prepend(int itemid,
                 const wxString& text,
                 const wxString& help,
                 bool isCheckable);

    static void LockAccels(bool locked);
};


class wxMenuBarBase : public wxWindow
{
public:
    wxMenuBarBase();

    virtual ~wxMenuBarBase();

    virtual bool Append(wxMenu *menu, const wxString& title);

    virtual bool Insert(size_t pos, wxMenu *menu, const wxString& title);


    size_t GetMenuCount() const ;
    wxMenu *GetMenu(size_t pos) const;

    virtual wxMenu *Replace(size_t pos, wxMenu *menu, const wxString& title);

    virtual wxMenu *Remove(size_t pos);

    virtual void EnableTop(size_t pos, bool enable) = 0;

    virtual bool IsEnabledTop(size_t pos) const ;
    virtual void SetMenuLabel(size_t pos, const wxString& label);
    virtual wxString GetMenuLabel(size_t pos) const;

    virtual wxString GetMenuLabelText(size_t pos) const;
    
    virtual int FindMenuItem(const wxString& menu, const wxString& item) const;

    virtual wxMenuItem* FindItem(int itemid, wxMenu **menu = NULL) const;

    int FindMenu(const wxString& title) const;

    void Enable(int itemid, bool enable);
    void Check(int itemid, bool check);
    bool IsChecked(int itemid) const;
    bool IsEnabled(int itemid) const;
    virtual bool IsEnabled() const ;
    
    void SetLabel(int itemid, const wxString &label);
    wxString GetLabel(int itemid) const;

    void SetHelpString(int itemid, const wxString& helpString);
    wxString GetHelpString(int itemid) const;


    wxFrame *GetFrame() const;

    bool IsAttached() const ;

    virtual void Attach(wxFrame *frame);

    virtual void Detach();

    virtual bool Enable(bool enable = true);
    virtual void SetLabel(const wxString& s);
    virtual wxString GetLabel() const;

    virtual bool AcceptsFocusFromKeyboard() const;

    virtual void UpdateMenus();

    virtual bool CanBeOutsideClientArea() const { return true; }
};


class wxMenuBar : public wxMenuBarBase
{
public:
    wxMenuBar();
    wxMenuBar(long style);
    wxMenuBar(size_t n, wxMenu *menus[], const wxString titles[], long style = 0);
    ~wxMenuBar();

    virtual bool Append( wxMenu *menu, const wxString &title );
    virtual bool Insert(size_t pos, wxMenu *menu, const wxString& title);
    virtual wxMenu *Replace(size_t pos, wxMenu *menu, const wxString& title);
    virtual wxMenu *Remove(size_t pos);

    virtual int FindMenuItem(const wxString& menuString,
                             const wxString& itemString) const;
    virtual wxMenuItem* FindItem( int id, wxMenu **menu = NULL ) const;

    virtual void EnableTop( size_t pos, bool flag );
    virtual bool IsEnabledTop(size_t pos) const;
    virtual void SetMenuLabel( size_t pos, const wxString& label );
    virtual wxString GetMenuLabel( size_t pos ) const;

    void SetLayoutDirection(wxLayoutDirection dir);
    wxLayoutDirection GetLayoutDirection() const;

    virtual void Attach(wxFrame *frame);
    virtual void Detach();

};

class wxMenu : public wxMenuBase
{
public:
    wxMenu(const wxString& title, long style = 0)
        : wxMenuBase(title, style) { Init(); }

    wxMenu(long style = 0) : wxMenuBase(style);

    virtual ~wxMenu();

    void Attach(wxMenuBarBase *menubar);

    void SetLayoutDirection(const wxLayoutDirection dir);
    wxLayoutDirection GetLayoutDirection() const;

    wxString GetTitle() const;

    virtual void SetTitle(const wxString& title);


    GtkWidget       *m_menu;
    GtkWidget       *m_owner;
    GtkAccelGroup   *m_accel;
    bool m_popupShown;
};

