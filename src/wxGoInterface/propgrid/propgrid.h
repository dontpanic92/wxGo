%typedef int wxPG_WINDOW_STYLES;
#define wxPG_AUTO_SORT                       0x00000010
#define wxPG_HIDE_CATEGORIES                 0x00000020
#define wxPG_ALPHABETIC_MODE                 (wxPG_HIDE_CATEGORIES|wxPG_AUTO_SORT)
#define wxPG_BOLD_MODIFIED                   0x00000040
#define wxPG_SPLITTER_AUTO_CENTER            0x00000080
#define wxPG_TOOLTIPS                        0x00000100
#define wxPG_HIDE_MARGIN                     0x00000200
#define wxPG_STATIC_SPLITTER                 0x00000400
#define wxPG_STATIC_LAYOUT                   (wxPG_HIDE_MARGIN|wxPG_STATIC_SPLITTER)
#define wxPG_LIMITED_EDITING                 0x00000800
#define wxPG_TOOLBAR                         0x00001000
#define wxPG_DESCRIPTION                     0x00002000
#define wxPG_NO_INTERNAL_BORDER              0x00004000
%typedef int wxPG_EX_WINDOW_STYLES;
#define wxPG_EX_INIT_NOCAT                   0x00001000
#define wxPG_EX_NO_FLAT_TOOLBAR              0x00002000
#define wxPG_EX_MODE_BUTTONS                 0x00008000
#define wxPG_EX_HELP_AS_TOOLTIPS             0x00010000
#define wxPG_EX_NATIVE_DOUBLE_BUFFERING          0x00080000
#define wxPG_EX_AUTO_UNSPECIFIED_VALUES          0x00200000
#define wxPG_EX_WRITEONLY_BUILTIN_ATTRIBUTES     0x00400000
#define wxPG_EX_HIDE_PAGE_BUTTONS                0x01000000
#define wxPG_EX_MULTIPLE_SELECTION               0x02000000
#define wxPG_EX_ENABLE_TLP_TRACKING              0x04000000
#define wxPG_EX_NO_TOOLBAR_DIVIDER               0x04000000
#define wxPG_EX_TOOLBAR_SEPARATOR                0x08000000
#define wxPG_DEFAULT_STYLE          (0)
#define wxPGMAN_DEFAULT_STYLE       (0)
%typedef int wxPG_VALIDATION_FAILURE_BEHAVIOR_FLAGS;
#define wxPG_VFB_STAY_IN_PROPERTY            0x01
#define wxPG_VFB_BEEP                        0x02
#define wxPG_VFB_MARK_CELL                   0x04
#define wxPG_VFB_SHOW_MESSAGE                0x08
#define wxPG_VFB_SHOW_MESSAGEBOX             0x10
#define wxPG_VFB_SHOW_MESSAGE_ON_STATUSBAR   0x20
#define wxPG_VFB_DEFAULT                     wxPG_VFB_MARK_CELL |                                      wxPG_VFB_SHOW_MESSAGEBOX
typedef wxByte wxPGVFBFlags;
WXGO_DECL_TYPECONV(PGValidationInfo)
class wxPGValidationInfo
{
public:
    wxPGVFBFlags GetFailureBehavior();
    const wxString& GetFailureMessage() const;
    wxVariant& GetValue();
    void SetFailureBehavior(wxPGVFBFlags failureBehavior);
    void SetFailureMessage(const wxString& message);
};
%typedef int wxPG_KEYBOARD_ACTIONS;
#define wxPG_ACTION_INVALID  0
#define wxPG_ACTION_NEXT_PROPERTY wxPG_ACTION_INVALID  + 1
#define wxPG_ACTION_PREV_PROPERTY wxPG_ACTION_NEXT_PROPERTY + 1
#define wxPG_ACTION_EXPAND_PROPERTY wxPG_ACTION_PREV_PROPERTY + 1
#define wxPG_ACTION_COLLAPSE_PROPERTY wxPG_ACTION_EXPAND_PROPERTY + 1
#define wxPG_ACTION_CANCEL_EDIT wxPG_ACTION_COLLAPSE_PROPERTY + 1
#define wxPG_ACTION_EDIT wxPG_ACTION_CANCEL_EDIT + 1
#define wxPG_ACTION_PRESS_BUTTON wxPG_ACTION_EDIT + 1
#define wxPG_ACTION_MAX wxPG_ACTION_PRESS_BUTTON + 1
typedef int (*wxPGSortCallback)(wxPropertyGrid* propGrid,
                                wxPGProperty* p1,
                                wxPGProperty* p2);
WXGO_DECL_TYPECONV(PropertyGrid)
class wxPropertyGrid : public wxControl,
                       public wxScrollHelper,
                       public wxPropertyGridInterface
{
public:
    wxPropertyGrid();
    wxPropertyGrid( wxWindow *parent, wxWindowID id = wxID_ANY,
                    const wxPoint& pos = wxDefaultPosition,
                    const wxSize& size = wxDefaultSize,
                    long style = wxPG_DEFAULT_STYLE,
                    const wxString& name = wxPropertyGridNameStr );
    virtual ~wxPropertyGrid();
    void AddActionTrigger( int action, int keycode, int modifiers = 0 );
    bool AddToSelection( wxPGPropArg id );
    static void AutoGetTranslation( bool enable );
    void BeginLabelEdit( unsigned int colIndex = 0 );
    bool ChangePropertyValue( wxPGPropArg id, wxVariant newValue );
    void CenterSplitter( bool enableAutoResizing = false );
    virtual void Clear();
    void ClearActionTriggers( int action );
    virtual bool CommitChangesFromEditor( wxUint32 flags = 0 );
    bool Create( wxWindow *parent, wxWindowID id = wxID_ANY,
                const wxPoint& pos = wxDefaultPosition,
                const wxSize& size = wxDefaultSize,
                long style = wxPG_DEFAULT_STYLE,
                const wxString& name = wxPropertyGridNameStr );
    void DedicateKey( int keycode );
    bool EnableCategories( bool enable );
    void EndLabelEdit( bool commit = true );
    bool EnsureVisible( wxPGPropArg id );
    wxSize FitColumns();
    wxTextCtrl* GetLabelEditor() const;
    wxWindow* GetPanel();
    wxColour GetCaptionBackgroundColour() const;
    wxFont& GetCaptionFont();
    wxColour GetCaptionForegroundColour() const;
    wxColour GetCellBackgroundColour() const;
    wxColour GetCellDisabledTextColour() const;
    wxColour GetCellTextColour() const;
    unsigned int GetColumnCount() const;
    wxColour GetEmptySpaceColour() const;
    int GetFontHeight() const;
    wxPropertyGrid* GetGrid();
    wxRect GetImageRect( wxPGProperty* property, int item ) const;
    wxSize GetImageSize( wxPGProperty* property = NULL, int item = -1 ) const;
    wxPGProperty* GetLastItem( int flags = wxPG_ITERATE_DEFAULT );
    wxColour GetLineColour() const;
    wxColour GetMarginColour() const;
    wxPGProperty* GetRoot() const;
    int GetRowHeight() const;
    wxPGProperty* GetSelectedProperty() const;
    wxPGProperty* GetSelection() const;
    wxColour GetSelectionBackgroundColour() const;
    wxColour GetSelectionForegroundColour() const;
    wxPGSortCallback GetSortFunction() const;
    int GetSplitterPosition( unsigned int splitterIndex = 0 ) const;
    wxTextCtrl* GetEditorTextCtrl() const;
    const wxPGCell& GetUnspecifiedValueAppearance() const;
    wxString GetUnspecifiedValueText( int argFlags = 0 ) const;
    int GetVerticalSpacing() const;
    wxPropertyGridHitTestResult HitTest( const wxPoint& pt ) const;
    bool IsAnyModified() const;
    bool IsEditorFocused() const;
    bool IsFrozen() const;
    void MakeColumnEditable( unsigned int column, bool editable = true );
    void OnTLPChanging( wxWindow* newTLP );
    void RefreshEditor();
    virtual void RefreshProperty( wxPGProperty* p );
    static wxPGEditor* RegisterEditorClass( wxPGEditor* editor,
                                            bool noDefCheck = false );
    static wxPGEditor* DoRegisterEditorClass( wxPGEditor* editor,
                                            const wxString& name,
                                            bool noDefCheck = false );
    void ResetColours();
    void ResetColumnSizes( bool enableAutoResizing = false );
    bool RemoveFromSelection( wxPGPropArg id );
    bool SelectProperty( wxPGPropArg id, bool focus = false );
    void SetCaptionBackgroundColour(const wxColour& col);
    void SetCaptionTextColour(const wxColour& col);
    void SetCellBackgroundColour(const wxColour& col);
    void SetCellDisabledTextColour(const wxColour& col);
    void SetCellTextColour(const wxColour& col);
    void SetColumnCount( int colCount );
    void SetCurrentCategory( wxPGPropArg id );
    void SetEmptySpaceColour(const wxColour& col);
    void SetLineColour(const wxColour& col);
    void SetMarginColour(const wxColour& col);
    void SetSelection( const wxArrayPGProperty& newSelection );
    void SetSelectionBackgroundColour(const wxColour& col);
    void SetSelectionTextColour(const wxColour& col);
    void SetSortFunction( wxPGSortCallback sortFunction );
    void SetSplitterPosition( int newxpos, int col = 0 );
    void SetSplitterLeft( bool privateChildrenToo = false );
    void SetUnspecifiedValueAppearance( const wxPGCell& cell );
    void SetVerticalSpacing( int vspacing );
    virtual void DoShowPropertyError( wxPGProperty* property,
                                      const wxString& msg );
    virtual void DoHidePropertyError( wxPGProperty* property );
    virtual wxStatusBar* GetStatusBar();
    void EditorsValueWasModified();
    void EditorsValueWasNotModified();
    wxVariant GetUncommittedPropertyValue();
    bool IsEditorsValueModified() const;
    void ShowPropertyError( wxPGPropArg id, const wxString& msg );
    bool WasValueChangedInEvent() const;
};
WXGO_DECL_TYPECONV(PropertyGridEvent)
class wxPropertyGridEvent : public wxCommandEvent
{
public:
    wxPropertyGridEvent(wxEventType commandType=0, int id=0);
    wxPropertyGridEvent(const wxPropertyGridEvent& event);
    ~wxPropertyGridEvent();
    bool CanVeto() const;
    unsigned int GetColumn() const;
    wxPGProperty* GetMainParent() const;
    wxPGProperty* GetProperty() const;
    wxPGVFBFlags GetValidationFailureBehavior() const;
    wxString GetPropertyName() const;
    wxVariant GetPropertyValue() const;
    wxVariant GetValue() const;
    void SetCanVeto( bool canVeto );
    void SetProperty( wxPGProperty* p );
    void SetValidationFailureBehavior( wxPGVFBFlags flags );
    void SetValidationFailureMessage( const wxString& message );
    void Veto( bool veto = true );
    bool WasVetoed() const;
};