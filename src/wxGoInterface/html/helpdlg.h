WXGO_DECL_TYPECONV(HtmlHelpDialog)
class wxHtmlHelpDialog : public wxDialog
{
public:
    wxHtmlHelpDialog(wxHtmlHelpData* data = NULL);
    wxHtmlHelpDialog(wxWindow* parent, wxWindowID id,
                     const wxString& title = wxEmptyString,
                     int style = wxHF_DEFAULT_STYLE,
                     wxHtmlHelpData* data = NULL);
    virtual void AddToolbarButtons(wxToolBar* toolBar, int style);
    bool Create(wxWindow* parent, wxWindowID id,
                const wxString& title = wxEmptyString,
                int style = wxHF_DEFAULT_STYLE);
    wxHtmlHelpController* GetController() const;
    void SetController(wxHtmlHelpController* controller);
    void SetTitleFormat(const wxString& format);
};