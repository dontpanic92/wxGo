WXGO_DECL_TYPECONV(FontMapper)
class wxFontMapper
{
public:
    wxFontMapper();
    virtual ~wxFontMapper();
    virtual wxFontEncoding CharsetToEncoding(const wxString& charset,
                                             bool interactive = true);
    static wxFontMapper* Get();
    static const wxChar** GetAllEncodingNames(wxFontEncoding encoding);
    bool GetAltForEncoding(wxFontEncoding encoding,
                           wxNativeEncodingInfo* info,
                           const wxString& facename = wxEmptyString,
                           bool interactive = true);
    bool GetAltForEncoding(wxFontEncoding encoding,
                           wxFontEncoding* alt_encoding,
                           const wxString& facename = wxEmptyString,
                           bool interactive = true);
    static wxFontEncoding GetEncoding(size_t n);
    static wxString GetEncodingDescription(wxFontEncoding encoding);
    static wxFontEncoding GetEncodingFromName(const wxString& encoding);
    static wxString GetEncodingName(wxFontEncoding encoding);
    static size_t GetSupportedEncodingsCount();
    virtual bool IsEncodingAvailable(wxFontEncoding encoding,
                                     const wxString& facename = wxEmptyString);
    static wxFontMapper* Set(wxFontMapper* mapper);
    void SetConfigPath(const wxString& prefix);
    void SetDialogParent(wxWindow* parent);
    void SetDialogTitle(const wxString& title);
};