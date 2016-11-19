#define wxHF_TOOLBAR                0x0001
#define wxHF_CONTENTS               0x0002
#define wxHF_INDEX                  0x0004
#define wxHF_SEARCH                 0x0008
#define wxHF_BOOKMARKS              0x0010
#define wxHF_OPEN_FILES             0x0020
#define wxHF_PRINT                  0x0040
#define wxHF_FLAT_TOOLBAR           0x0080
#define wxHF_MERGE_BOOKS            0x0100
#define wxHF_ICONS_BOOK             0x0200
#define wxHF_ICONS_BOOK_CHAPTER     0x0400
#define wxHF_ICONS_FOLDER           0x0000 
#define wxHF_DEFAULT_STYLE          (wxHF_TOOLBAR | wxHF_CONTENTS | \
                                     wxHF_INDEX | wxHF_SEARCH | \
                                     wxHF_BOOKMARKS | wxHF_PRINT)
WXGO_DECL_TYPECONV(HtmlHelpFrame)
class wxHtmlHelpFrame : public wxFrame
{
public:
    wxHtmlHelpFrame(wxHtmlHelpData* data = NULL);
    wxHtmlHelpFrame(wxWindow* parent, wxWindowID id,
                    const wxString& title = wxEmptyString,
                    int style = wxHF_DEFAULT_STYLE,
                    wxHtmlHelpData* data = NULL,
                    wxConfigBase* config = NULL,
                    const wxString& rootpath = wxEmptyString);
    virtual void AddToolbarButtons(wxToolBar* toolBar, int style);
    bool Create(wxWindow* parent, wxWindowID id,
                const wxString& title = wxEmptyString, int style = wxHF_DEFAULT_STYLE,
                wxConfigBase* config = NULL,
                const wxString& rootpath = wxEmptyString);
    wxHtmlHelpController* GetController() const;
    void SetController(wxHtmlHelpController* controller);
    void SetTitleFormat(const wxString& format);
};