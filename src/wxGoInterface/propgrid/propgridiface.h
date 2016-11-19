WXGO_DECL_TYPECONV(PGPropArgCls)
class wxPGPropArgCls
{
public:
    wxPGPropArgCls( const wxPGProperty* property )
    {
        m_ptr.property = (wxPGProperty*) property;
        m_flags = IsProperty;
    }
    wxPGPropArgCls( const wxString& str )
    {
        m_ptr.stringName = &str;
        m_flags = IsWxString;
    }
    wxPGPropArgCls( const wxPGPropArgCls& id )
    {
        m_ptr = id.m_ptr;
        m_flags = id.m_flags;
    }
    wxPGPropArgCls( wxString* str, bool deallocPtr)
    {
        m_ptr.stringName = str;
        m_flags = IsWxString | OwnsWxString;
    }
    ~wxPGPropArgCls()
    {
        if ( m_flags & OwnsWxString )
            delete m_ptr.stringName;
    }
    wxPGProperty* GetPtr() const
    {
        wxCHECK( m_flags == IsProperty, NULL );
        return m_ptr.property;
    }
    wxPGPropArgCls( const char* str )
    {
        m_ptr.charName = str;
        m_flags = IsCharPtr;
    }
    wxPGPropArgCls( const wchar_t* str )
    {
        m_ptr.wcharName = str;
        m_flags = IsWCharPtr;
    }
    wxPGPropArgCls( int )
    {
        m_ptr.property = NULL;
        m_flags = IsProperty;
    }
    wxPGProperty* GetPtr( wxPropertyGridInterface* iface ) const;
    wxPGProperty* GetPtr0() const { return m_ptr.property; }
    bool HasName() const { return (m_flags != IsProperty); }
    const wxString& GetName() const { return *m_ptr.stringName; }
};
typedef const wxPGPropArgCls& wxPGPropArg;
WXGO_DECL_TYPECONV(PropertyGridInterface)
class wxPropertyGridInterface
{
public:
    virtual ~wxPropertyGridInterface() { }
    wxPGProperty* Append( wxPGProperty* property );
    wxPGProperty* AppendIn( wxPGPropArg id, wxPGProperty* newProperty );
    void BeginAddChildren( wxPGPropArg id );
    virtual void Clear() = 0;
    bool ClearSelection( bool validation = false);
    void ClearModifiedStatus();
    bool Collapse( wxPGPropArg id );
    bool CollapseAll();
    bool ChangePropertyValue( wxPGPropArg id, wxVariant newValue );
    void DeleteProperty( wxPGPropArg id );
    bool DisableProperty( wxPGPropArg id );
    bool EditorValidate();
    bool EnableProperty( wxPGPropArg id, bool enable = true );
    void EndAddChildren( wxPGPropArg id );
    bool Expand( wxPGPropArg id );
    bool ExpandAll( bool expand = true );
    int GetColumnProportion( unsigned int column ) const;
    wxPGProperty* GetFirstChild( wxPGPropArg id );
    wxPropertyGridIterator GetIterator( int flags = wxPG_ITERATE_DEFAULT,
                                        wxPGProperty* firstProp = NULL );
    wxPropertyGridIterator GetIterator( int flags, int startPos );
    wxPGProperty* GetFirst( int flags = wxPG_ITERATE_ALL );
    wxPGProperty* GetProperty( const wxString& name ) const;
    void GetPropertiesWithFlag( wxArrayPGProperty* targetArr,
                                wxPGProperty::FlagType flags,
                                bool inverse = false,
                                int iterFlags = (wxPG_ITERATE_PROPERTIES|wxPG_ITERATE_HIDDEN|wxPG_ITERATE_CATEGORIES) ) const;
    wxVariant GetPropertyAttribute( wxPGPropArg id, const wxString& attrName ) const;
    wxColour GetPropertyBackgroundColour( wxPGPropArg id ) const;
    wxPropertyCategory* GetPropertyCategory( wxPGPropArg id ) const;
    void* GetPropertyClientData( wxPGPropArg id ) const;
    wxPGProperty* GetPropertyByLabel( const wxString& label ) const;
    wxPGProperty* GetPropertyByName( const wxString& name ) const;
    wxPGProperty* GetPropertyByName( const wxString& name,
                                     const wxString& subname ) const;
    const wxPGEditor* GetPropertyEditor( wxPGPropArg id ) const;
    wxString GetPropertyHelpString( wxPGPropArg id ) const;
    wxBitmap* GetPropertyImage( wxPGPropArg id ) const;
    const wxString& GetPropertyLabel( wxPGPropArg id );
    wxString GetPropertyName( wxPGProperty* property );
    wxColour GetPropertyTextColour( wxPGPropArg id ) const;
    wxValidator* GetPropertyValidator( wxPGPropArg id );
    wxVariant GetPropertyValue( wxPGPropArg id );
    wxArrayInt GetPropertyValueAsArrayInt( wxPGPropArg id ) const;
    wxArrayString GetPropertyValueAsArrayString( wxPGPropArg id ) const;
    bool GetPropertyValueAsBool( wxPGPropArg id ) const;
    wxDateTime GetPropertyValueAsDateTime( wxPGPropArg id ) const;
    double GetPropertyValueAsDouble( wxPGPropArg id ) const;
    int GetPropertyValueAsInt( wxPGPropArg id ) const;
    long GetPropertyValueAsLong( wxPGPropArg id ) const;
    wxLongLong_t GetPropertyValueAsLongLong( wxPGPropArg id ) const;
    wxString GetPropertyValueAsString( wxPGPropArg id ) const;
    unsigned long GetPropertyValueAsULong( wxPGPropArg id ) const;
    wxULongLong_t GetPropertyValueAsULongLong( wxPGPropArg id ) const;
    wxVariant GetPropertyValues( const wxString& listname = wxEmptyString,
                                 wxPGProperty* baseparent = NULL, long flags = 0 ) const;
    const wxArrayPGProperty& GetSelectedProperties() const;
    wxPGProperty* GetSelection() const;
    virtual wxPGVIterator GetVIterator( int flags ) const;
    bool HideProperty( wxPGPropArg id, bool hide = true, int flags = wxPG_RECURSE );
    static void InitAllTypeHandlers();
    wxPGProperty* Insert( wxPGPropArg priorThis, wxPGProperty* newProperty );
    wxPGProperty* Insert( wxPGPropArg parent, int index, wxPGProperty* newProperty );
    bool IsPropertyCategory( wxPGPropArg id ) const;
    bool IsPropertyEnabled( wxPGPropArg id ) const;
    bool IsPropertyExpanded( wxPGPropArg id ) const;
    bool IsPropertyModified( wxPGPropArg id ) const;
    virtual bool IsPropertySelected( wxPGPropArg id ) const;
    bool IsPropertyShown( wxPGPropArg id ) const;
    bool IsPropertyValueUnspecified( wxPGPropArg id ) const;
    void LimitPropertyEditing( wxPGPropArg id, bool limit = true );
    static void RegisterAdditionalEditors();
    wxPGProperty* RemoveProperty( wxPGPropArg id );
    wxPGProperty* ReplaceProperty( wxPGPropArg id, wxPGProperty* property );
    enum EditableStateFlags
    {
        SelectionState   = 0x01,
        ExpandedState    = 0x02,
        ScrollPosState   = 0x04,
        PageState        = 0x08,
        SplitterPosState = 0x10,
        DescBoxState     = 0x20,
        AllStates        = SelectionState |
                           ExpandedState |
                           ScrollPosState |
                           PageState |
                           SplitterPosState |
                           DescBoxState
    };
    bool RestoreEditableState( const wxString& src,
                               int restoreStates = AllStates );
    wxString SaveEditableState( int includedStates = AllStates ) const;
    static void SetBoolChoices( const wxString& trueChoice,
                                const wxString& falseChoice );
    bool SetColumnProportion( unsigned int column, int proportion );
    void SetPropertyAttribute( wxPGPropArg id, const wxString& attrName,
                               wxVariant value, long argFlags = 0 );
    void SetPropertyAttributeAll( const wxString& attrName, wxVariant value );
    void SetPropertyBackgroundColour( wxPGPropArg id,
                                      const wxColour& colour,
                                      int flags = wxPG_RECURSE );
    void SetPropertyCell( wxPGPropArg id,
                          int column,
                          const wxString& text = wxEmptyString,
                          const wxBitmap& bitmap = wxNullBitmap,
                          const wxColour& fgCol = wxNullColour,
                          const wxColour& bgCol = wxNullColour );
    void SetPropertyClientData( wxPGPropArg id, void* clientData );
    void SetPropertyColoursToDefault( wxPGPropArg id );
    void SetPropertyEditor( wxPGPropArg id, const wxPGEditor* editor );
    void SetPropertyEditor( wxPGPropArg id, const wxString& editorName );
    void SetPropertyLabel( wxPGPropArg id, const wxString& newproplabel );
    void SetPropertyName( wxPGPropArg id, const wxString& newName );
    void SetPropertyReadOnly( wxPGPropArg id, bool set = true,
                              int flags = wxPG_RECURSE );
    void SetPropertyValueUnspecified( wxPGPropArg id );
    void SetPropertyValues( const wxVariantList& list,
                            wxPGPropArg defaultCategory = wxNullProperty );
    void SetPropertyValues( const wxVariant& list,
                            wxPGPropArg defaultCategory = wxNullProperty );
    void SetPropertyHelpString( wxPGPropArg id, const wxString& helpString );
    void SetPropertyImage( wxPGPropArg id, wxBitmap& bmp );
    bool SetPropertyMaxLength( wxPGPropArg id, int maxLen );
    void SetPropertyTextColour( wxPGPropArg id,
                                const wxColour& colour,
                                int flags = wxPG_RECURSE );
    void SetPropertyValidator( wxPGPropArg id, const wxValidator& validator );
    void SetPropertyValue( wxPGPropArg id, long value );
    void SetPropertyValue( wxPGPropArg id, int value );
    void SetPropertyValue( wxPGPropArg id, double value );
    void SetPropertyValue( wxPGPropArg id, bool value );
    void SetPropertyValue( wxPGPropArg id, const wxString& value );
    void SetPropertyValue( wxPGPropArg id, const wxArrayString& value );
    void SetPropertyValue( wxPGPropArg id, const wxDateTime& value );
    void SetPropertyValue( wxPGPropArg id, wxObject* value );
    void SetPropertyValue( wxPGPropArg id, wxLongLong_t value );
    void SetPropertyValue( wxPGPropArg id, wxULongLong_t value );
    void SetPropertyValue( wxPGPropArg id, const wxArrayInt& value );
    void SetPropertyValueString( wxPGPropArg id, const wxString& value );
    void SetPropertyValue( wxPGPropArg id, wxVariant value );
    void SetValidationFailureBehavior( int vfbFlags );
    void Sort( int flags = 0 );
    void SortChildren( wxPGPropArg id, int flags = 0 );
    static wxPGEditor* GetEditorByName( const wxString& editorName );
};