#define wxID_HTML_HELPFRAME   (wxID_HIGHEST + 1)
#define wxHF_EMBEDDED                0x00008000
#define wxHF_DIALOG                  0x00010000
#define wxHF_FRAME                   0x00020000
#define wxHF_MODAL                   0x00040000
WXGO_DECL_TYPECONV(HtmlHelpController)
class wxHtmlHelpController : public wxHelpControllerBase
{
public:
    wxHtmlHelpController(int style = wxHF_DEFAULT_STYLE,
                         wxWindow* parentWindow = NULL);
    wxHtmlHelpController(wxWindow* parentWindow, int style = wxHF_DEFAULT_STYLE);
    bool AddBook(const wxFileName& bookFile, bool showWaitMsg = false);
    bool AddBook(const wxString& bookUrl, bool showWaitMsg = false);
    bool Display(const wxString& x);
    bool Display(int id);
    virtual bool DisplayContents();
    bool DisplayIndex();
    virtual bool KeywordSearch(const wxString& keyword,
                               wxHelpSearchMode mode = wxHELP_SEARCH_ALL);
    virtual void ReadCustomization(wxConfigBase* cfg,
                                   const wxString& path = wxEmptyString);
    void SetShouldPreventAppExit(bool enable);
    void SetTempDir(const wxString& path);
    void SetTitleFormat(const wxString& format);
    void UseConfig(wxConfigBase* config,
                   const wxString& rootpath = wxEmptyString);
    virtual void WriteCustomization(wxConfigBase* cfg,
                                    const wxString& path = wxEmptyString);
    wxHtmlHelpWindow* GetHelpWindow();
    void SetHelpWindow(wxHtmlHelpWindow* helpWindow);
    wxHtmlHelpFrame* GetFrame();
    wxHtmlHelpDialog* GetDialog();
protected:
    virtual wxHtmlHelpDialog* CreateHelpDialog(wxHtmlHelpData* data);
    virtual wxHtmlHelpFrame* CreateHelpFrame(wxHtmlHelpData* data);
};
WXGO_DECL_TYPECONV(HtmlModalHelp)
class wxHtmlModalHelp
{
public:
    wxHtmlModalHelp(wxWindow* parent, const wxString& helpFile,
                    const wxString& topic = wxEmptyString,
                    int style = wxHF_DEFAULT_STYLE | wxHF_DIALOG | wxHF_MODAL);
};