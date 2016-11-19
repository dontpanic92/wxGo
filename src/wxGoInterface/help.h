#define wxHELP_NETSCAPE     1
%typedef int wxHelpSearchMode;
#define wxHELP_SEARCH_INDEX 0
#define wxHELP_SEARCH_ALL wxHELP_SEARCH_INDEX + 1
WXGO_DECL_TYPECONV(HelpControllerBase)
class wxHelpControllerBase : public wxObject
{
public:
    wxHelpControllerBase(wxWindow* parentWindow = NULL);
    ~wxHelpControllerBase();
    virtual bool DisplayBlock(long blockNo) = 0;
    virtual bool DisplayContents() = 0;
    virtual bool DisplayContextPopup(int contextId);
    virtual bool DisplaySection(const wxString& section);
    virtual bool DisplaySection(int sectionNo) = 0;
    virtual bool DisplayTextPopup(const wxString& text,
                                  const wxPoint& pos);
    virtual wxFrame* GetFrameParameters(wxSize* size = NULL,
                                        wxPoint* pos = NULL,
                                        bool* newFrameEachTime = NULL);
    virtual wxWindow* GetParentWindow() const;
    virtual bool Initialize(const wxString& file);
    virtual bool Initialize(const wxString& file, int server);
    virtual bool KeywordSearch(const wxString& keyWord,
                               wxHelpSearchMode mode = wxHELP_SEARCH_ALL) = 0;
    virtual bool LoadFile(const wxString& file = wxEmptyString) = 0;
    virtual void OnQuit();
    virtual bool Quit() = 0;
    virtual void SetFrameParameters(const wxString& titleFormat,
                                    const wxSize& size,
                                    const wxPoint& pos = wxDefaultPosition,
                                    bool newFrameEachTime = false);
    virtual void SetParentWindow(wxWindow* parentWindow);
    virtual void SetViewer(const wxString& viewer, long flags=wxHELP_NETSCAPE);
};
WXGO_DECL_TYPECONV(HelpController)
class wxHelpController : public wxHelpControllerBase
{
public:
    wxHelpController(wxWindow* parentWindow = NULL);
};