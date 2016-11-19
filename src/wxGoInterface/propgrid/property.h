#define wxNullProperty  ((wxPGProperty*)NULL)
#define wxPG_ATTR_DEFAULT_VALUE           wxS("DefaultValue")
#define wxPG_ATTR_MIN                     wxS("Min")
#define wxPG_ATTR_MAX                     wxS("Max")
#define wxPG_ATTR_UNITS                     wxS("Units")
#define wxPG_ATTR_HINT                      wxS("Hint")
#define wxPG_ATTR_INLINE_HELP               wxS("InlineHelp")
#define wxPG_ATTR_AUTOCOMPLETE              wxS("AutoComplete")
#define wxPG_BOOL_USE_CHECKBOX              wxS("UseCheckbox")
#define wxPG_BOOL_USE_DOUBLE_CLICK_CYCLING  wxS("UseDClickCycling")
#define wxPG_FLOAT_PRECISION                wxS("Precision")
#define wxPG_STRING_PASSWORD                wxS("Password")
#define wxPG_UINT_BASE                      wxS("Base")
#define wxPG_UINT_PREFIX                    wxS("Prefix")
#define wxPG_FILE_WILDCARD                  wxS("Wildcard")
#define wxPG_FILE_SHOW_FULL_PATH            wxS("ShowFullPath")
#define wxPG_FILE_SHOW_RELATIVE_PATH        wxS("ShowRelativePath")
#define wxPG_FILE_INITIAL_PATH              wxS("InitialPath")
#define wxPG_FILE_DIALOG_TITLE              wxS("DialogTitle")
#define wxPG_FILE_DIALOG_STYLE              wxS("DialogStyle")
#define wxPG_DIR_DIALOG_MESSAGE             wxS("DialogMessage")
#define wxPG_ARRAY_DELIMITER                wxS("Delimiter")
#define wxPG_DATE_FORMAT                    wxS("DateFormat")
#define wxPG_DATE_PICKER_STYLE              wxS("PickerStyle")
#define wxPG_ATTR_SPINCTRL_STEP             wxS("Step")
#define wxPG_ATTR_SPINCTRL_WRAP             wxS("Wrap")
#define wxPG_ATTR_SPINCTRL_MOTIONSPIN       wxS("MotionSpin")
#define wxPG_ATTR_MULTICHOICE_USERSTRINGMODE    wxS("UserStringMode")
#define wxPG_COLOUR_ALLOW_CUSTOM            wxS("AllowCustom")
#define wxPG_COLOUR_HAS_ALPHA               wxS("HasAlpha")
%typedef int wxPGPropertyFlags;
#define wxPG_PROP_MODIFIED                   0x0001
#define wxPG_PROP_DISABLED                   0x0002
#define wxPG_PROP_HIDDEN                     0x0004
#define wxPG_PROP_CUSTOMIMAGE                0x0008
#define wxPG_PROP_NOEDITOR                   0x0010
#define wxPG_PROP_COLLAPSED                  0x0020
#define wxPG_PROP_INVALID_VALUE              0x0040
#define wxPG_PROP_WAS_MODIFIED               0x0200
#define wxPG_PROP_AGGREGATE                  0x0400
#define wxPG_PROP_CHILDREN_ARE_COPIES        0x0800
#define wxPG_PROP_PROPERTY                   0x1000
#define wxPG_PROP_CATEGORY                   0x2000
#define wxPG_PROP_MISC_PARENT                0x4000
#define wxPG_PROP_READONLY                   0x8000
#define wxPG_PROP_COMPOSED_VALUE             0x00010000
#define wxPG_PROP_USES_COMMON_VALUE          0x00020000
#define wxPG_PROP_AUTO_UNSPECIFIED           0x00040000
#define wxPG_PROP_CLASS_SPECIFIC_1           0x00080000
#define wxPG_PROP_CLASS_SPECIFIC_2           0x00100000
#define wxPG_PROP_BEING_DELETED              0x00200000
#define wxPG_PROP_MAX               wxPG_PROP_AUTO_UNSPECIFIED
#define wxPG_PROP_PARENTAL_FLAGS \
    ((wxPGPropertyFlags)(wxPG_PROP_AGGREGATE | \
                         wxPG_PROP_CATEGORY | \
                         wxPG_PROP_MISC_PARENT))
WXGO_DECL_TYPECONV(PGProperty)
class wxPGProperty : public wxObject
{
public:
    typedef wxUint32 FlagType;
    wxPGProperty();
    wxPGProperty( const wxString& label, const wxString& name );
    virtual ~wxPGProperty();
    virtual void OnSetValue();
    virtual wxVariant DoGetValue() const;
    virtual bool ValidateValue( wxVariant& value, wxPGValidationInfo& validationInfo ) const;
    virtual bool StringToValue( wxVariant& variant, const wxString& text, int argFlags = 0 ) const;
    virtual bool IntToValue( wxVariant& variant, int number, int argFlags = 0 ) const;
    virtual wxString ValueToString( wxVariant& value, int argFlags = 0 ) const;
    bool SetValueFromString( const wxString& text, int flags = 0 );
    bool SetValueFromInt( long value, int flags = 0 );
    virtual wxSize OnMeasureImage( int item = -1 ) const;
    virtual bool OnEvent( wxPropertyGrid* propgrid, wxWindow* wnd_primary, wxEvent& event );
    virtual wxVariant ChildChanged( wxVariant& thisValue,
                                    int childIndex,
                                    wxVariant& childValue ) const;
    virtual const wxPGEditor* DoGetEditorClass() const;
    virtual wxValidator* DoGetValidator () const;
    virtual void OnCustomPaint( wxDC& dc, const wxRect& rect, wxPGPaintData& paintdata );
    virtual wxPGCellRenderer* GetCellRenderer( int column ) const;
    virtual int GetChoiceSelection() const;
    virtual void RefreshChildren();
    virtual bool DoSetAttribute( const wxString& name, wxVariant& value );
    virtual wxVariant DoGetAttribute( const wxString& name ) const;
    virtual wxPGEditorDialogAdapter* GetEditorDialog() const;
    virtual void OnValidationFailure( wxVariant& pendingValue );
    int AddChoice( const wxString& label, int value = wxPG_INVALID_VALUE );
    void AddPrivateChild( wxPGProperty* prop );
    void AdaptListToValue( wxVariant& list, wxVariant* value ) const;
    wxPGProperty* AppendChild( wxPGProperty* childProperty );
    bool AreAllChildrenSpecified( wxVariant* pendingList = NULL ) const;
    bool AreChildrenComponents() const;
    void ChangeFlag( wxPGPropertyFlags flag, bool set );
    void DeleteChildren();
    void DeleteChoice( int index );
    void Enable( bool enable = true );
    wxString GenerateComposedValue() const;
    wxVariant GetAttribute( const wxString& name ) const;
    wxString GetAttribute( const wxString& name, const wxString& defVal ) const;
    long GetAttributeAsLong( const wxString& name, long defVal ) const;
    double GetAttributeAsDouble( const wxString& name, double defVal ) const;
    wxVariant GetAttributesAsList() const;
    const wxPGEditor* GetColumnEditor( int column ) const;
    const wxString& GetBaseName() const;
    wxPGCell& GetCell( unsigned int column );
    wxPGCell& GetOrCreateCell( unsigned int column );
    unsigned int GetChildCount() const;
    int GetChildrenHeight( int lh, int iMax = -1 ) const;
    const wxPGChoices& GetChoices() const;
    void* GetClientData() const;
    wxClientData *GetClientObject() const;
    wxVariant GetDefaultValue() const;
    wxString GetDisplayedString() const;
    const wxPGEditor* GetEditorClass() const;
    FlagType GetFlags() const;
    wxPropertyGrid* GetGrid() const;
    wxPropertyGrid* GetGridIfDisplayed() const;
    const wxString& GetHelpString() const;
    unsigned int GetIndexInParent() const;
    const wxString& GetLabel() const;
    const wxPGProperty* GetLastVisibleSubItem() const;
    wxPGProperty* GetMainParent() const;
    int GetMaxLength() const;
    wxString GetName() const;
    wxPGProperty* GetParent() const;
    wxPGProperty* GetPropertyByName( const wxString& name ) const;
    wxValidator* GetValidator() const;
    wxVariant GetValue() const;
    wxBitmap* GetValueImage() const;
    virtual wxString GetValueAsString( int argFlags = 0 ) const;
    wxString GetValueType() const;
    int GetY() const;
    FlagType HasFlag( wxPGPropertyFlags flag ) const;
    bool HasVisibleChildren() const;
    bool Hide( bool hide, int flags = wxPG_RECURSE );
    int Index( const wxPGProperty* p ) const;
    wxPGProperty* InsertChild( int index, wxPGProperty* childProperty );
    int InsertChoice( const wxString& label, int index, int value = wxPG_INVALID_VALUE );
    bool IsCategory() const;
    bool IsEnabled() const;
    bool IsExpanded() const;
    bool IsRoot() const;
    bool IsSomeParent( wxPGProperty* candidateParent ) const;
    bool IsTextEditable() const;
    bool IsValueUnspecified() const;
    bool IsVisible() const;
    wxPGProperty* Item( unsigned int i ) const;
    void RefreshEditor();
    void SetAttribute( const wxString& name, wxVariant value );
    void SetAutoUnspecified( bool enable = true );
    void SetBackgroundColour( const wxColour& colour,
                              int flags = wxPG_RECURSE );
    void SetEditor( const wxPGEditor* editor );
    void SetEditor( const wxString& editorName );
    void SetCell( int column, const wxPGCell& cell );
    bool SetChoices( wxPGChoices& choices );
    void SetClientData( void* clientData );
    void SetClientObject(wxClientData* clientObject);
    void SetChoiceSelection( int newValue );
    void SetDefaultValue( wxVariant& value );
    void SetFlagRecursively( wxPGPropertyFlags flag, bool set );
    void SetHelpString( const wxString& helpString );
    void SetLabel( const wxString& label );
    bool SetMaxLength( int maxLen );
    void SetModifiedStatus( bool modified );
    void SetName( const wxString& newName );
    void SetParentalType( int flag );
    void SetTextColour( const wxColour& colour,
                        int flags = wxPG_RECURSE );
    void SetValidator( const wxValidator& validator );
    void SetValue( wxVariant value, wxVariant* pList = NULL,
                   int flags = wxPG_SETVAL_REFRESH_EDITOR );
    void SetValueImage( wxBitmap& bmp );
    void SetValueInEvent( wxVariant value ) const;
    void SetValueToUnspecified();
    void SetWasModified( bool set = true );
    wxPGProperty* UpdateParentValues();
    bool UsesAutoUnspecified() const;
protected:
    void Empty();
};
WXGO_DECL_TYPECONV(PGCell)
class wxPGCell : public wxObject
{
public:
    wxPGCell();
    wxPGCell(const wxPGCell& other);
    wxPGCell( const wxString& text,
              const wxBitmap& bitmap = wxNullBitmap,
              const wxColour& fgCol = wxNullColour,
              const wxColour& bgCol = wxNullColour );
    virtual ~wxPGCell();
    const wxPGCellData* GetData() const;
    bool HasText() const;
    void MergeFrom( const wxPGCell& srcCell );
    void SetText( const wxString& text );
    void SetBitmap( const wxBitmap& bitmap );
    void SetFgCol( const wxColour& col );
    void SetFont( const wxFont& font );
    void SetBgCol( const wxColour& col );
    const wxString& GetText() const;
    const wxBitmap& GetBitmap() const;
    const wxColour& GetFgCol() const;
    const wxFont& GetFont() const;
    const wxColour& GetBgCol() const;
    wxPGCell& operator=( const wxPGCell& other );
};
WXGO_DECL_TYPECONV(PGChoices)
class wxPGChoices
{
public:
    typedef long ValArrItem;
    wxPGChoices();
    wxPGChoices( const wxPGChoices& a );
    wxPGChoices( const wxChar** labels, const long* values = NULL );
    wxPGChoices( const wxArrayString& labels, const wxArrayInt& values = wxArrayInt() );
    wxPGChoices( wxPGChoicesData* data );
    ~wxPGChoices();
    void Add( const wxChar** labels, const ValArrItem* values = NULL );
    void Add( const wxArrayString& arr, const wxArrayInt& arrint );
    wxPGChoiceEntry& Add( const wxString& label, int value = wxPG_INVALID_VALUE );
    wxPGChoiceEntry& Add( const wxString& label, const wxBitmap& bitmap,
                          int value = wxPG_INVALID_VALUE );
    wxPGChoiceEntry& Add( const wxPGChoiceEntry& entry );
    wxPGChoiceEntry& AddAsSorted( const wxString& label, int value = wxPG_INVALID_VALUE );
    void Assign( const wxPGChoices& a );
    void AssignData( wxPGChoicesData* data );
    void Clear();
    wxPGChoices Copy() const;
    const wxString& GetLabel( unsigned int ind ) const;
    unsigned int GetCount() const;
    int GetValue( unsigned int ind ) const;
    wxArrayInt GetValuesForStrings( const wxArrayString& strings ) const;
    wxArrayInt GetIndicesForStrings( const wxArrayString& strings,
                                     wxArrayString* unmatched = NULL ) const;
    int Index( const wxString& label ) const;
    int Index( int val ) const;
    wxPGChoiceEntry& Insert( const wxString& label, int index, int value = wxPG_INVALID_VALUE );
    wxPGChoiceEntry& Insert( const wxPGChoiceEntry& entry, int index );
    bool IsOk() const;
    wxPGChoiceEntry& Item( unsigned int i );
    void RemoveAt(size_t nIndex, size_t count = 1);
    void Set( const wxChar** labels, const long* values = NULL );
    void Set( const wxArrayString& labels, const wxArrayInt& values = wxArrayInt() );
    void AllocExclusive();
    wxArrayString GetLabels() const;
    void operator= (const wxPGChoices& a);
    wxPGChoiceEntry& operator[](unsigned int i);
};