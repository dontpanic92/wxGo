enum
{
    wxID_HTML_PANEL = wxID_HIGHEST + 10,
    wxID_HTML_BACK,
    wxID_HTML_FORWARD,
    wxID_HTML_UPNODE,
    wxID_HTML_UP,
    wxID_HTML_DOWN,
    wxID_HTML_PRINT,
    wxID_HTML_OPENFILE,
    wxID_HTML_OPTIONS,
    wxID_HTML_BOOKMARKSLIST,
    wxID_HTML_BOOKMARKSADD,
    wxID_HTML_BOOKMARKSREMOVE,
    wxID_HTML_TREECTRL,
    wxID_HTML_INDEXPAGE,
    wxID_HTML_INDEXLIST,
    wxID_HTML_INDEXTEXT,
    wxID_HTML_INDEXBUTTON,
    wxID_HTML_INDEXBUTTONALL,
    wxID_HTML_NOTEBOOK,
    wxID_HTML_SEARCHPAGE,
    wxID_HTML_SEARCHTEXT,
    wxID_HTML_SEARCHLIST,
    wxID_HTML_SEARCHBUTTON,
    wxID_HTML_SEARCHCHOICE,
    wxID_HTML_COUNTINFO
};
WXGO_DECL_TYPECONV(HtmlHelpWindow)
class wxHtmlHelpWindow : public wxWindow
{
public:
    wxHtmlHelpWindow(wxHtmlHelpData* data = NULL);
    wxHtmlHelpWindow(wxWindow* parent, int wxWindowID,
                     const wxPoint& pos = wxDefaultPosition,
                     const wxSize& size = wxDefaultSize,
                     int style = wxTAB_TRAVERSAL|wxBORDER_NONE,
                     int helpStyle = wxHF_DEFAULT_STYLE,
                     wxHtmlHelpData* data = NULL);
    bool Create(wxWindow* parent, wxWindowID id,
                const wxPoint& pos = wxDefaultPosition,
                const wxSize& size = wxDefaultSize, int style = wxTAB_TRAVERSAL|wxBORDER_NONE,
                int helpStyle = wxHF_DEFAULT_STYLE);
    bool Display(const wxString& x);
    bool Display(int id);
    bool DisplayContents();
    bool DisplayIndex();
    wxHtmlHelpData* GetData();
    bool KeywordSearch(const wxString& keyword,
                       wxHelpSearchMode mode = wxHELP_SEARCH_ALL);
    void ReadCustomization(wxConfigBase* cfg,
                           const wxString& path = wxEmptyString);
    void UseConfig(wxConfigBase* config,
                   const wxString& rootpath = wxEmptyString);
    void WriteCustomization(wxConfigBase* cfg,
                            const wxString& path = wxEmptyString);
    void RefreshLists();
    wxHtmlHelpController* GetController() const;
    void SetController(wxHtmlHelpController* controller);
protected:
    void CreateSearch();
    virtual void AddToolbarButtons(wxToolBar* toolBar, int style);
    void CreateContents();
    void CreateIndex();
};