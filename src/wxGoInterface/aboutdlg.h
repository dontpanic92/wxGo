WXGO_DECL_TYPECONV(AboutDialogInfo)
class wxAboutDialogInfo
{
public:
    wxAboutDialogInfo();
    void AddArtist(const wxString& artist);
    void AddDeveloper(const wxString& developer);
    void AddDocWriter(const wxString& docwriter);
    void AddTranslator(const wxString& translator);
    void SetArtists(const wxArrayString& artists);
    void SetCopyright(const wxString& copyright);
    void SetDescription(const wxString& desc);
    void SetDevelopers(const wxArrayString& developers);
    void SetDocWriters(const wxArrayString& docwriters);
    void SetIcon(const wxIcon& icon);
    void SetLicence(const wxString& licence);
    void SetName(const wxString& name);
    void SetTranslators(const wxArrayString& translators);
    void SetVersion(const wxString& version, const wxString& longVersion = wxString());
    void SetWebSite(const wxString& url,
                    const wxString& desc = wxEmptyString);
};
void wxAboutBox(const wxAboutDialogInfo& info, wxWindow* parent = NULL);