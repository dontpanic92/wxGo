WXGO_DECL_TYPECONV(NativeFontInfo)
class wxNativeFontInfo
{
public:
    wxNativeFontInfo();
    wxNativeFontInfo(const wxNativeFontInfo& info);
    ~wxNativeFontInfo();
    wxNativeFontInfo& operator=(const wxNativeFontInfo& info);
    void Init();
    void InitFromFont(const wxFont& font);
    int GetPointSize() const;
    wxFontStyle GetStyle() const;
    wxFontWeight GetWeight() const;
    bool GetUnderlined() const;
    wxString GetFaceName() const;
    wxFontFamily GetFamily() const;
    wxFontEncoding GetEncoding() const;
    void SetPointSize(int pointsize);
    void SetStyle(wxFontStyle style);
    void SetWeight(wxFontWeight weight);
    void SetUnderlined(bool underlined);
    bool SetFaceName(const wxString& facename);
    void SetFamily(wxFontFamily family);
    void SetEncoding(wxFontEncoding encoding);
    void SetFaceName(const wxArrayString &facenames);
    bool FromString(const wxString& s);
    wxString ToString() const;
    bool FromUserString(const wxString& s);
    wxString ToUserString() const;
};