WXGO_DECL_TYPECONV(PreferencesEditor)
WXGO_DECL_TYPECONV(PreferencesPage)
WXGO_DECL_TYPECONV(StockPreferencesPage)
class wxPreferencesEditor
{
public:
    wxPreferencesEditor(const wxString& title = wxString());
    ~wxPreferencesEditor();
    void AddPage(wxPreferencesPage *page);
    virtual void Show(wxWindow* parent);
    void Dismiss();
    static bool ShouldApplyChangesImmediately();
    static bool ShownModally();
};
class wxPreferencesPage
{
public:
    wxPreferencesPage();
    virtual ~wxPreferencesPage();
    virtual wxString GetName() const = 0;
    virtual wxBitmap GetLargeIcon() const = 0;
    virtual wxWindow *CreateWindow(wxWindow *parent) = 0;
};
class wxStockPreferencesPage : public wxPreferencesPage
{
public:
    enum Kind
    {
        Kind_General,
        Kind_Advanced
    };
    wxStockPreferencesPage(Kind kind);
    Kind GetKind() const;
    virtual wxString GetName() const;
    virtual wxBitmap GetLargeIcon() const;
};