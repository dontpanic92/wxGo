%typedef int wxLayoutDirection;
#define wxLayout_Default 0
#define wxLayout_LeftToRight wxLayout_Default + 1
#define wxLayout_RightToLeft wxLayout_LeftToRight + 1
struct wxLanguageInfo
{
    int Language;
    wxString CanonicalName;
#ifdef __WXMSW__
    wxUint32 WinLang, WinSublang;
#endif
    wxString Description;
    wxLayoutDirection LayoutDirection;
#ifdef __WXMSW__
    wxUint32 GetLCID() const;
#endif
    wxString GetLocaleName() const;
};
%typedef int wxLocaleCategory;
#define wxLOCALE_CAT_NUMBER 0
#define wxLOCALE_CAT_DATE wxLOCALE_CAT_NUMBER + 1
#define wxLOCALE_CAT_MONEY wxLOCALE_CAT_DATE + 1
#define wxLOCALE_CAT_DEFAULT wxLOCALE_CAT_MONEY + 1
%typedef int wxLocaleInfo;
#define wxLOCALE_THOUSANDS_SEP 0
#define wxLOCALE_DECIMAL_POINT wxLOCALE_THOUSANDS_SEP + 1
#define wxLOCALE_SHORT_DATE_FMT wxLOCALE_DECIMAL_POINT + 1
#define wxLOCALE_LONG_DATE_FMT wxLOCALE_SHORT_DATE_FMT + 1
#define wxLOCALE_DATE_TIME_FMT wxLOCALE_LONG_DATE_FMT + 1
#define wxLOCALE_TIME_FMT wxLOCALE_DATE_TIME_FMT + 1
WXGO_DECL_TYPECONV(Locale)
class wxLocale
{
public:
    wxLocale();
    wxLocale(int language, int flags = wxLOCALE_LOAD_DEFAULT);
    wxLocale(const wxString& name,
             const wxString& shortName = wxEmptyString,
             const wxString& locale = wxEmptyString,
             bool bLoadDefault = true);
    virtual ~wxLocale();
    bool AddCatalog(const wxString& domain);
    bool AddCatalog(const wxString& domain, wxLanguage msgIdLanguage);
    bool AddCatalog(const wxString& domain, wxLanguage msgIdLanguage,
                    const wxString& msgIdCharset);
    static void AddCatalogLookupPathPrefix(const wxString& prefix);
    static void AddLanguage(const wxLanguageInfo& info);
    static const wxLanguageInfo* FindLanguageInfo(const wxString& locale);
    wxString GetCanonicalName() const;
    wxString GetHeaderValue(const wxString& header,
                            const wxString& domain = wxEmptyString) const;
    int GetLanguage() const;
    static const wxLanguageInfo* GetLanguageInfo(int lang);
    static wxString GetLanguageName(int lang);
    static wxString GetLanguageCanonicalName(int lang);
    const wxString& GetLocale() const;
    const wxString& GetName() const;
    virtual const wxString& GetString(const wxString& origString,
                                      const wxString& domain = wxEmptyString) const;
    virtual const wxString& GetString(const wxString& origString,
                                      const wxString& origString2, unsigned n,
                                      const wxString& domain = wxEmptyString) const;
    wxString GetSysName() const;
    static wxFontEncoding GetSystemEncoding();
    static wxString GetSystemEncodingName();
    static int GetSystemLanguage();
    static wxString GetInfo(wxLocaleInfo index,
                            wxLocaleCategory cat = wxLOCALE_CAT_DEFAULT);
    static wxString GetOSInfo(wxLocaleInfo index,
                              wxLocaleCategory cat = wxLOCALE_CAT_DEFAULT);
    bool Init(int language = wxLANGUAGE_DEFAULT,
              int flags = wxLOCALE_LOAD_DEFAULT);
    bool Init(const wxString& name, const wxString& shortName = wxEmptyString,
              const wxString& locale = wxEmptyString, bool bLoadDefault = true);
    static bool IsAvailable(int lang);
    bool IsLoaded(const wxString& domain) const;
    bool IsOk() const;
};