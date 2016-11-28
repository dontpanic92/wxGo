WXGO_DECL_TYPECONV(WebViewFSHandler)
class wxWebViewFSHandler : public wxWebViewHandler
{
public:
    wxWebViewFSHandler(const wxString& scheme);
    virtual wxFSFile* GetFile(const wxString &uri);
};