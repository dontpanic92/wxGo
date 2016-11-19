WXGO_DECL_TYPECONV(PGEditor)
class wxPGEditor : public wxObject
{
public:
    wxPGEditor();
    virtual ~wxPGEditor();
    virtual wxString GetName() const;
    virtual wxPGWindowList CreateControls( wxPropertyGrid* propgrid,
                                           wxPGProperty* property,
                                           const wxPoint& pos,
                                           const wxSize& size ) const = 0;
    virtual void UpdateControl( wxPGProperty* property, wxWindow* ctrl ) const = 0;
    virtual void DrawValue( wxDC& dc, const wxRect& rect,
                            wxPGProperty* property, const wxString& text ) const;
    virtual bool OnEvent( wxPropertyGrid* propgrid, wxPGProperty* property,
        wxWindow* wnd_primary, wxEvent& event ) const = 0;
    virtual bool GetValueFromControl( wxVariant& variant, wxPGProperty* property,
                                      wxWindow* ctrl ) const;
    virtual void SetValueToUnspecified( wxPGProperty* property,
                                        wxWindow* ctrl ) const = 0;
    virtual void SetControlAppearance( wxPropertyGrid* pg,
                                       wxPGProperty* property,
                                       wxWindow* ctrl,
                                       const wxPGCell& appearance,
                                       const wxPGCell& oldAppearance,
                                       bool unspecified ) const;
    virtual void SetControlStringValue( wxPGProperty* property,
                                        wxWindow* ctrl, const wxString& txt ) const;
    virtual void SetControlIntValue( wxPGProperty* property,
                                     wxWindow* ctrl, int value ) const;
    virtual int InsertItem( wxWindow* ctrl, const wxString& label, int index ) const;
    virtual void DeleteItem( wxWindow* ctrl, int index ) const;
    virtual void OnFocus( wxPGProperty* property, wxWindow* wnd ) const;
    virtual bool CanContainCustomImage() const;
};
WXGO_DECL_TYPECONV(PGMultiButton)
class wxPGMultiButton : public wxWindow
{
public:
    wxPGMultiButton( wxPropertyGrid* pg, const wxSize& sz );
    virtual ~wxPGMultiButton() { }
    void Add( const wxString& label, int id = -2 );
    void Add( const wxBitmap& bitmap, int id = -2 );
    void Finalize( wxPropertyGrid* propGrid, const wxPoint& pos );
    wxWindow* GetButton( unsigned int i );
    int GetButtonId( unsigned int i ) const;
    unsigned int GetCount();
    wxSize GetPrimarySize() const;
};