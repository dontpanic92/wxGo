WXGO_DECL_TYPECONV(FontEnumerator)
class wxFontEnumerator
{
public:
    wxFontEnumerator();
    virtual ~wxFontEnumerator();
    virtual bool EnumerateEncodings(const wxString& font = wxEmptyString);
    virtual bool EnumerateFacenames(wxFontEncoding encoding = wxFONTENCODING_SYSTEM,
                                    bool fixedWidthOnly = false);
    static wxArrayString GetEncodings(const wxString& facename = wxEmptyString);
    static wxArrayString GetFacenames(wxFontEncoding encoding = wxFONTENCODING_SYSTEM,
                                      bool fixedWidthOnly = false);
    static bool IsValidFacename(const wxString& facename);
    virtual bool OnFacename(const wxString& font);
    virtual bool OnFontEncoding(const wxString& font,
                                const wxString& encoding);
};