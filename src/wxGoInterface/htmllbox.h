WXGO_DECL_TYPECONV(HtmlListBox)
class wxHtmlListBox : public wxVListBox
{
public:
    wxHtmlListBox(wxWindow* parent, wxWindowID id = wxID_ANY,
                  const wxPoint& pos = wxDefaultPosition,
                  const wxSize& size = wxDefaultSize,
                  long style = 0,
                  const wxString& name = wxHtmlListBoxNameStr);
    wxHtmlListBox();
    virtual ~wxHtmlListBox();
    bool Create(wxWindow* parent, wxWindowID id = wxID_ANY,
                const wxPoint& pos = wxDefaultPosition,
                const wxSize& size = wxDefaultSize,
                long style = 0,
                const wxString& name = wxHtmlListBoxNameStr);
    wxFileSystem& GetFileSystem() const;
    const wxFileSystem& GetFileSystem() const;
protected:
    virtual void OnLinkClicked(size_t n, const wxHtmlLinkInfo& link);
    virtual wxColour GetSelectedTextBgColour(const wxColour& colBg) const;
    virtual wxColour GetSelectedTextColour(const wxColour& colFg) const;
    virtual wxString OnGetItemMarkup(size_t n) const;
    virtual wxString OnGetItem(size_t n) const = 0;
};
WXGO_DECL_TYPECONV(SimpleHtmlListBox)
class wxSimpleHtmlListBox : public wxHtmlListBox,
                            public wxItemContainer
{
public:
    wxSimpleHtmlListBox(wxWindow* parent, wxWindowID id,
                        const wxPoint& pos = wxDefaultPosition,
                        const wxSize& size = wxDefaultSize,
                        int n = 0,
                        const wxString choices[] = NULL,
                        long style = wxHLB_DEFAULT_STYLE,
                        const wxValidator& validator = wxDefaultValidator,
                        const wxString& name = wxSimpleHtmlListBoxNameStr);
    wxSimpleHtmlListBox(wxWindow* parent, wxWindowID id,
                        const wxPoint& pos,
                        const wxSize& size,
                        const wxArrayString& choices,
                        long style = wxHLB_DEFAULT_STYLE,
                        const wxValidator& validator = wxDefaultValidator,
                        const wxString& name = wxSimpleHtmlListBoxNameStr);
    wxSimpleHtmlListBox();
    virtual ~wxSimpleHtmlListBox();
    bool Create(wxWindow *parent, wxWindowID id,
                const wxPoint& pos = wxDefaultPosition,
                const wxSize& size = wxDefaultSize,
                int n = 0, const wxString choices[] = NULL,
                long style = wxHLB_DEFAULT_STYLE,
                const wxValidator& validator = wxDefaultValidator,
                const wxString& name = wxSimpleHtmlListBoxNameStr);
    bool Create(wxWindow *parent, wxWindowID id,
                const wxPoint& pos,
                const wxSize& size,
                const wxArrayString& choices,
                long style = wxHLB_DEFAULT_STYLE,
                const wxValidator& validator = wxDefaultValidator,
                const wxString& name = wxSimpleHtmlListBoxNameStr);
};