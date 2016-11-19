%typedef int wxHtmlURLType;
#define wxHTML_URL_PAGE 0
#define wxHTML_URL_IMAGE wxHTML_URL_PAGE + 1
#define wxHTML_URL_OTHER wxHTML_URL_IMAGE + 1
WXGO_DECL_TYPECONV(HtmlTagHandler)
class wxHtmlTagHandler : public wxObject
{
public:
    wxHtmlTagHandler();
    virtual wxString GetSupportedTags() = 0;
    virtual bool HandleTag(const wxHtmlTag& tag) = 0;
    virtual void SetParser(wxHtmlParser* parser);
    wxHtmlParser* GetParser() const;
protected:
    void ParseInner(const wxHtmlTag& tag);
    void ParseInnerSource(const wxString& source);
    wxHtmlParser* m_Parser;
};
WXGO_DECL_TYPECONV(HtmlParser)
class wxHtmlParser
{
public:
    wxHtmlParser();
    virtual void AddTagHandler(wxHtmlTagHandler* handler);
    void DoParsing();
    virtual void DoneParser();
    wxFileSystem* GetFS() const;
    virtual wxObject* GetProduct() = 0;
    const wxString* GetSource();
    virtual void InitParser(const wxString& source);
    virtual wxFSFile* OpenURL(wxHtmlURLType type, const wxString& url) const;
    wxObject* Parse(const wxString& source);
    void PopTagHandler();
    void PushTagHandler(wxHtmlTagHandler* handler,
                        const wxString& tags);
    void SetFS(wxFileSystem* fs);
    virtual void StopParsing();
protected:
    virtual void AddTag(const wxHtmlTag& tag);
};