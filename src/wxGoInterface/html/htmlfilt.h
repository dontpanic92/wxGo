WXGO_DECL_TYPECONV(HtmlFilter)
class wxHtmlFilter : public wxObject
{
public:
    wxHtmlFilter();
    virtual bool CanRead(const wxFSFile& file) const = 0;
    virtual wxString ReadFile(const wxFSFile& file) const = 0;
};