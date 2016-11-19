WXGO_DECL_TYPECONV(PropertyGridPage)
class wxPropertyGridPage : public wxEvtHandler,
                                                public wxPropertyGridInterface
{
    friend class wxPropertyGridManager;
public:
    wxPropertyGridPage();
    virtual ~wxPropertyGridPage();
    virtual void Clear();
    wxSize FitColumns();
    inline int GetIndex() const;
    wxPGProperty* GetRoot() const;
    int GetSplitterPosition( int col = 0 ) const;
    int GetToolId() const;
    virtual void Init();
    virtual bool IsHandlingAllEvents() const;
    virtual void OnShow();
    virtual void RefreshProperty( wxPGProperty* p );
    void SetSplitterPosition( int splitterPos, int col = 0 );
};
WXGO_DECL_TYPECONV(PropertyGridManager)
class wxPropertyGridManager : public wxPanel, public wxPropertyGridInterface
{
public:
    wxPropertyGridPage* AddPage( const wxString& label = wxEmptyString,
                                 const wxBitmap& bmp = wxPG_NULL_BITMAP,
                                 wxPropertyGridPage* pageObj = NULL );
    virtual void Clear();
    void ClearPage( int page );
    bool CommitChangesFromEditor( wxUint32 flags = 0 );
    bool Create( wxWindow *parent, wxWindowID id = wxID_ANY,
                 const wxPoint& pos = wxDefaultPosition,
                 const wxSize& size = wxDefaultSize,
                 long style = wxPGMAN_DEFAULT_STYLE,
                 const wxString& name = wxPropertyGridManagerNameStr );
    bool EnableCategories( bool enable );
    bool EnsureVisible( wxPGPropArg id );
    int GetColumnCount( int page = -1 ) const;
    int GetDescBoxHeight() const;
    wxPropertyGrid* GetGrid();
    virtual wxPGVIterator GetVIterator( int flags ) const;
    wxPropertyGridPage* GetCurrentPage() const;
    wxPropertyGridPage* GetPage( unsigned int ind ) const;
    wxPropertyGridPage* GetPage( const wxString& name ) const;
    int GetPageByName( const wxString& name ) const;
    size_t GetPageCount() const;
    const wxString& GetPageName( int index ) const;
    wxPGProperty* GetPageRoot( int index ) const;
    int GetSelectedPage() const;
    wxPGProperty* GetSelectedProperty() const;
    wxPGProperty* GetSelection() const;
    wxToolBar* GetToolBar() const;
    virtual wxPropertyGridPage* InsertPage( int index, const wxString& label,
                                            const wxBitmap& bmp = wxNullBitmap,
                                            wxPropertyGridPage* pageObj = NULL );
    bool IsAnyModified() const;
    bool IsFrozen() const;
    bool IsPageModified( size_t index ) const;
    virtual bool IsPropertySelected( wxPGPropArg id ) const;
    virtual bool RemovePage( int page );
    void SelectPage( int index );
    void SelectPage( const wxString& label );
    void SelectPage( wxPropertyGridPage* page );
    bool SelectProperty( wxPGPropArg id, bool focus = false );
    void SetColumnCount( int colCount, int page = -1 );
    void SetColumnTitle( int idx, const wxString& title );
    void SetDescription( const wxString& label, const wxString& content );
    void SetDescBoxHeight( int ht, bool refresh = true );
    void SetSplitterLeft( bool subProps = false, bool allPages = true );
    void SetPageSplitterLeft(int page, bool subProps = false);
    void SetPageSplitterPosition( int page, int pos, int column = 0 );
    void SetSplitterPosition( int pos, int column = 0 );
    void ShowHeader(bool show = true);
protected:
    virtual wxPropertyGrid* CreatePropertyGrid() const;
};