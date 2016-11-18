WXGO_DECL_TYPECONV(VersionInfo)
class wxVersionInfo
{
public:
    wxVersionInfo(const wxString& name = wxString(),
                  int major = 0,
                  int minor = 0,
                  int micro = 0,
                  const wxString& description = wxString(),
                  const wxString& copyright = wxString());
    const wxString& GetName() const;
    int GetMajor() const;
    int GetMinor() const;
    int GetMicro() const;
    wxString ToString() const;
    wxString GetVersionString() const;
    bool HasDescription() const;
    const wxString& GetDescription();
    bool HasCopyright() const;
    const wxString& GetCopyright() const;
};