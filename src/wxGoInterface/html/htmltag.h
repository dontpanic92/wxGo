WXGO_DECL_TYPECONV(HtmlTag)
class wxHtmlTag
{
protected:
    wxHtmlTag(wxHtmlTag* parent, const wxString* source,
              const const_iterator& pos, const const_iterator& end_pos,
              wxHtmlTagsCache* cache, wxHtmlEntitiesParser* entParser);
public:
    wxString GetAllParams() const;
    wxString GetName() const;
    wxString GetParam(const wxString& par, bool with_quotes = false) const;
    bool GetParamAsColour(const wxString& par, wxColour* clr) const;
    bool GetParamAsInt(const wxString& par, int* value) const;
    bool GetParamAsString(const wxString& par, wxString* value) const;
    bool HasEnding() const;
    bool HasParam(const wxString& par) const;
    static bool ParseAsColour(const wxString& str, wxColour *clr);
    int ScanParam(const wxString& par, const wchar_t* format, void* value) const;
    int ScanParam(const wxString& par, const char* format, void* value) const;
};