WXGO_DECL_TYPECONV(HtmlTagsModule)
class wxHtmlTagsModule : public wxModule
{
public:
    virtual void FillHandlersTable(wxHtmlWinParser* parser);
};
%nodefaultctor wxHtmlWinTagHandler;
WXGO_DECL_TYPECONV(HtmlWinTagHandler)
class wxHtmlWinTagHandler : public wxHtmlTagHandler
{
public:
    virtual void SetParser(wxHtmlWinParser* parser);
protected:
    wxHtmlWinParser* m_WParser;
};
%nodefaultctor wxHtmlWinParser;
WXGO_DECL_TYPECONV(HtmlWinParser)
class wxHtmlWinParser : public wxHtmlParser
{
public:
    wxHtmlWinParser(wxHtmlWindowInterface* wndIface = NULL);
    static void AddModule(wxHtmlTagsModule* module);
    wxHtmlContainerCell* CloseContainer();
    virtual wxFont* CreateCurrentFont();
    const wxColour& GetActualColor() const;
    int GetAlign() const;
    int GetCharHeight() const;
    int GetCharWidth() const;
    wxHtmlContainerCell* GetContainer() const;
    wxDC* GetDC();
    int GetFontBold() const;
    wxString GetFontFace() const;
    int GetFontFixed() const;
    int GetFontItalic() const;
    int GetFontSize() const;
    int GetFontUnderlined() const;
    const wxHtmlLinkInfo& GetLink() const;
    const wxColour& GetLinkColor() const;
    wxHtmlWindowInterface* GetWindowInterface();
    wxHtmlContainerCell* OpenContainer();
    void SetActualColor(const wxColour& clr);
    void SetAlign(int a);
    wxHtmlContainerCell* SetContainer(wxHtmlContainerCell* c);
    virtual void SetDC(wxDC* dc, double pixel_scale = 1.0e+0);
    void SetFontBold(int x);
    void SetFontFace(const wxString& face);
    void SetFontFixed(int x);
    void SetFontItalic(int x);
    void SetFontSize(int s);
    void SetFontUnderlined(int x);
    void SetFonts(const wxString& normal_face, const wxString& fixed_face,
                  const int* sizes = 0);
    void SetLink(const wxHtmlLinkInfo& link);
    void SetLinkColor(const wxColour& clr);
};