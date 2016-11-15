WXGO_DECL_TYPECONV(SizerXmlHandler)
class wxSizerXmlHandler : public wxXmlResourceHandler
{
public:
    wxSizerXmlHandler();
    virtual wxObject *DoCreateResource();
    virtual bool CanHandle(wxXmlNode *node);
protected:
    virtual wxSizer* DoCreateSizer(const wxString& name);
    virtual bool IsSizerNode(wxXmlNode *node) const;
};