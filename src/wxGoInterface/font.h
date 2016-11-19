%typedef int wxFontFamily;
#define wxFONTFAMILY_DEFAULT  wxDEFAULT
#define wxFONTFAMILY_DECORATIVE  wxDECORATIVE
#define wxFONTFAMILY_ROMAN  wxROMAN
#define wxFONTFAMILY_SCRIPT  wxSCRIPT
#define wxFONTFAMILY_SWISS  wxSWISS
#define wxFONTFAMILY_MODERN  wxMODERN
#define wxFONTFAMILY_TELETYPE  wxTELETYPE
#define wxFONTFAMILY_MAX wxFONTFAMILY_TELETYPE  + 1
#define wxFONTFAMILY_UNKNOWN  wxFONTFAMILY_MAX
%typedef int wxFontStyle;
#define wxFONTSTYLE_NORMAL  wxNORMAL
#define wxFONTSTYLE_ITALIC  wxITALIC
#define wxFONTSTYLE_SLANT  wxSLANT
#define wxFONTSTYLE_MAX wxFONTSTYLE_SLANT  + 1
%typedef int wxFontWeight;
#define wxFONTWEIGHT_NORMAL  wxNORMAL
#define wxFONTWEIGHT_LIGHT  wxLIGHT
#define wxFONTWEIGHT_BOLD  wxBOLD
#define wxFONTWEIGHT_MAX wxFONTWEIGHT_BOLD  + 1
%typedef int wxFontSymbolicSize;
#define wxFONTSIZE_XX_SMALL  -3
#define wxFONTSIZE_X_SMALL wxFONTSIZE_XX_SMALL  + 1
#define wxFONTSIZE_SMALL wxFONTSIZE_X_SMALL + 1
#define wxFONTSIZE_MEDIUM wxFONTSIZE_SMALL + 1
#define wxFONTSIZE_LARGE wxFONTSIZE_MEDIUM + 1
#define wxFONTSIZE_X_LARGE wxFONTSIZE_LARGE + 1
#define wxFONTSIZE_XX_LARGE wxFONTSIZE_X_LARGE + 1
%typedef int wxFontFlag;
#define wxFONTFLAG_DEFAULT           0
#define wxFONTFLAG_ITALIC            1 << 0
#define wxFONTFLAG_SLANT             1 << 1
#define wxFONTFLAG_LIGHT             1 << 2
#define wxFONTFLAG_BOLD              1 << 3
#define wxFONTFLAG_ANTIALIASED       1 << 4
#define wxFONTFLAG_NOT_ANTIALIASED   1 << 5
#define wxFONTFLAG_UNDERLINED        1 << 6
#define wxFONTFLAG_STRIKETHROUGH     1 << 7
#define wxFONTFLAG_MASK  wxFONTFLAG_ITALIC             |                      wxFONTFLAG_SLANT              |                      wxFONTFLAG_LIGHT              |                      wxFONTFLAG_BOLD               |                      wxFONTFLAG_ANTIALIASED        |                      wxFONTFLAG_NOT_ANTIALIASED    |                      wxFONTFLAG_UNDERLINED         |                      wxFONTFLAG_STRIKETHROUGH
%typedef int wxFontEncoding;
#define wxFONTENCODING_SYSTEM  -1
#define wxFONTENCODING_DEFAULT wxFONTENCODING_SYSTEM  + 1
#define wxFONTENCODING_ISO8859_1 wxFONTENCODING_DEFAULT + 1
#define wxFONTENCODING_ISO8859_2 wxFONTENCODING_ISO8859_1 + 1
#define wxFONTENCODING_ISO8859_3 wxFONTENCODING_ISO8859_2 + 1
#define wxFONTENCODING_ISO8859_4 wxFONTENCODING_ISO8859_3 + 1
#define wxFONTENCODING_ISO8859_5 wxFONTENCODING_ISO8859_4 + 1
#define wxFONTENCODING_ISO8859_6 wxFONTENCODING_ISO8859_5 + 1
#define wxFONTENCODING_ISO8859_7 wxFONTENCODING_ISO8859_6 + 1
#define wxFONTENCODING_ISO8859_8 wxFONTENCODING_ISO8859_7 + 1
#define wxFONTENCODING_ISO8859_9 wxFONTENCODING_ISO8859_8 + 1
#define wxFONTENCODING_ISO8859_10 wxFONTENCODING_ISO8859_9 + 1
#define wxFONTENCODING_ISO8859_11 wxFONTENCODING_ISO8859_10 + 1
#define wxFONTENCODING_ISO8859_12 wxFONTENCODING_ISO8859_11 + 1
#define wxFONTENCODING_ISO8859_13 wxFONTENCODING_ISO8859_12 + 1
#define wxFONTENCODING_ISO8859_14 wxFONTENCODING_ISO8859_13 + 1
#define wxFONTENCODING_ISO8859_15 wxFONTENCODING_ISO8859_14 + 1
#define wxFONTENCODING_ISO8859_MAX wxFONTENCODING_ISO8859_15 + 1
#define wxFONTENCODING_KOI8 wxFONTENCODING_ISO8859_MAX + 1
#define wxFONTENCODING_KOI8_U wxFONTENCODING_KOI8 + 1
#define wxFONTENCODING_ALTERNATIVE wxFONTENCODING_KOI8_U + 1
#define wxFONTENCODING_BULGARIAN wxFONTENCODING_ALTERNATIVE + 1
#define wxFONTENCODING_CP437 wxFONTENCODING_BULGARIAN + 1
#define wxFONTENCODING_CP850 wxFONTENCODING_CP437 + 1
#define wxFONTENCODING_CP852 wxFONTENCODING_CP850 + 1
#define wxFONTENCODING_CP855 wxFONTENCODING_CP852 + 1
#define wxFONTENCODING_CP866 wxFONTENCODING_CP855 + 1
#define wxFONTENCODING_CP874 wxFONTENCODING_CP866 + 1
#define wxFONTENCODING_CP932 wxFONTENCODING_CP874 + 1
#define wxFONTENCODING_CP936 wxFONTENCODING_CP932 + 1
#define wxFONTENCODING_CP949 wxFONTENCODING_CP936 + 1
#define wxFONTENCODING_CP950 wxFONTENCODING_CP949 + 1
#define wxFONTENCODING_CP1250 wxFONTENCODING_CP950 + 1
#define wxFONTENCODING_CP1251 wxFONTENCODING_CP1250 + 1
#define wxFONTENCODING_CP1252 wxFONTENCODING_CP1251 + 1
#define wxFONTENCODING_CP1253 wxFONTENCODING_CP1252 + 1
#define wxFONTENCODING_CP1254 wxFONTENCODING_CP1253 + 1
#define wxFONTENCODING_CP1255 wxFONTENCODING_CP1254 + 1
#define wxFONTENCODING_CP1256 wxFONTENCODING_CP1255 + 1
#define wxFONTENCODING_CP1257 wxFONTENCODING_CP1256 + 1
#define wxFONTENCODING_CP1258 wxFONTENCODING_CP1257 + 1
#define wxFONTENCODING_CP1361 wxFONTENCODING_CP1258 + 1
#define wxFONTENCODING_CP12_MAX wxFONTENCODING_CP1361 + 1
#define wxFONTENCODING_UTF7 wxFONTENCODING_CP12_MAX + 1
#define wxFONTENCODING_UTF8 wxFONTENCODING_UTF7 + 1
#define wxFONTENCODING_EUC_JP wxFONTENCODING_UTF8 + 1
#define wxFONTENCODING_UTF16BE wxFONTENCODING_EUC_JP + 1
#define wxFONTENCODING_UTF16LE wxFONTENCODING_UTF16BE + 1
#define wxFONTENCODING_UTF32BE wxFONTENCODING_UTF16LE + 1
#define wxFONTENCODING_UTF32LE wxFONTENCODING_UTF32BE + 1
#define wxFONTENCODING_MACROMAN wxFONTENCODING_UTF32LE + 1
#define wxFONTENCODING_MACJAPANESE wxFONTENCODING_MACROMAN + 1
#define wxFONTENCODING_MACCHINESETRAD wxFONTENCODING_MACJAPANESE + 1
#define wxFONTENCODING_MACKOREAN wxFONTENCODING_MACCHINESETRAD + 1
#define wxFONTENCODING_MACARABIC wxFONTENCODING_MACKOREAN + 1
#define wxFONTENCODING_MACHEBREW wxFONTENCODING_MACARABIC + 1
#define wxFONTENCODING_MACGREEK wxFONTENCODING_MACHEBREW + 1
#define wxFONTENCODING_MACCYRILLIC wxFONTENCODING_MACGREEK + 1
#define wxFONTENCODING_MACDEVANAGARI wxFONTENCODING_MACCYRILLIC + 1
#define wxFONTENCODING_MACGURMUKHI wxFONTENCODING_MACDEVANAGARI + 1
#define wxFONTENCODING_MACGUJARATI wxFONTENCODING_MACGURMUKHI + 1
#define wxFONTENCODING_MACORIYA wxFONTENCODING_MACGUJARATI + 1
#define wxFONTENCODING_MACBENGALI wxFONTENCODING_MACORIYA + 1
#define wxFONTENCODING_MACTAMIL wxFONTENCODING_MACBENGALI + 1
#define wxFONTENCODING_MACTELUGU wxFONTENCODING_MACTAMIL + 1
#define wxFONTENCODING_MACKANNADA wxFONTENCODING_MACTELUGU + 1
#define wxFONTENCODING_MACMALAJALAM wxFONTENCODING_MACKANNADA + 1
#define wxFONTENCODING_MACSINHALESE wxFONTENCODING_MACMALAJALAM + 1
#define wxFONTENCODING_MACBURMESE wxFONTENCODING_MACSINHALESE + 1
#define wxFONTENCODING_MACKHMER wxFONTENCODING_MACBURMESE + 1
#define wxFONTENCODING_MACTHAI wxFONTENCODING_MACKHMER + 1
#define wxFONTENCODING_MACLAOTIAN wxFONTENCODING_MACTHAI + 1
#define wxFONTENCODING_MACGEORGIAN wxFONTENCODING_MACLAOTIAN + 1
#define wxFONTENCODING_MACARMENIAN wxFONTENCODING_MACGEORGIAN + 1
#define wxFONTENCODING_MACCHINESESIMP wxFONTENCODING_MACARMENIAN + 1
#define wxFONTENCODING_MACTIBETAN wxFONTENCODING_MACCHINESESIMP + 1
#define wxFONTENCODING_MACMONGOLIAN wxFONTENCODING_MACTIBETAN + 1
#define wxFONTENCODING_MACETHIOPIC wxFONTENCODING_MACMONGOLIAN + 1
#define wxFONTENCODING_MACCENTRALEUR wxFONTENCODING_MACETHIOPIC + 1
#define wxFONTENCODING_MACVIATNAMESE wxFONTENCODING_MACCENTRALEUR + 1
#define wxFONTENCODING_MACARABICEXT wxFONTENCODING_MACVIATNAMESE + 1
#define wxFONTENCODING_MACSYMBOL wxFONTENCODING_MACARABICEXT + 1
#define wxFONTENCODING_MACDINGBATS wxFONTENCODING_MACSYMBOL + 1
#define wxFONTENCODING_MACTURKISH wxFONTENCODING_MACDINGBATS + 1
#define wxFONTENCODING_MACCROATIAN wxFONTENCODING_MACTURKISH + 1
#define wxFONTENCODING_MACICELANDIC wxFONTENCODING_MACCROATIAN + 1
#define wxFONTENCODING_MACROMANIAN wxFONTENCODING_MACICELANDIC + 1
#define wxFONTENCODING_MACCELTIC wxFONTENCODING_MACROMANIAN + 1
#define wxFONTENCODING_MACGAELIC wxFONTENCODING_MACCELTIC + 1
#define wxFONTENCODING_MACKEYBOARD wxFONTENCODING_MACGAELIC + 1
#define wxFONTENCODING_ISO2022_JP wxFONTENCODING_MACKEYBOARD + 1
#define wxFONTENCODING_MAX wxFONTENCODING_ISO2022_JP + 1
#define wxFONTENCODING_MACMIN  wxFONTENCODING_MACROMAN
#define wxFONTENCODING_MACMAX  wxFONTENCODING_MACKEYBOARD
#define wxFONTENCODING_UTF16 wxFONTENCODING_MACMAX  + 1
#define wxFONTENCODING_UTF32 wxFONTENCODING_UTF16 + 1
#define wxFONTENCODING_UNICODE wxFONTENCODING_UTF32 + 1
#define wxFONTENCODING_GB2312  wxFONTENCODING_CP936
#define wxFONTENCODING_BIG5  wxFONTENCODING_CP950
#define wxFONTENCODING_SHIFT_JIS  wxFONTENCODING_CP932
#define wxFONTENCODING_EUC_KR  wxFONTENCODING_CP949
#define wxFONTENCODING_JOHAB  wxFONTENCODING_CP1361
#define wxFONTENCODING_VIETNAMESE  wxFONTENCODING_CP1258
WXGO_DECL_TYPECONV(FontInfo)
class wxFontInfo
{
public:
    wxFontInfo();
    explicit wxFontInfo(int pointSize);
    explicit wxFontInfo(const wxSize& pixelSize);
    wxFontInfo& Family(wxFontFamily family);
    wxFontInfo& FaceName(const wxString& faceName);
    wxFontInfo& Bold(bool bold = true);
    wxFontInfo& Light(bool light = true);
    wxFontInfo& Italic(bool italic = true);
    wxFontInfo& Slant(bool slant = true);
    wxFontInfo& AntiAliased(bool antiAliased = true);
    wxFontInfo& Underlined(bool underlined = true);
    wxFontInfo& Strikethrough(bool strikethrough = true);
    wxFontInfo& Encoding(wxFontEncoding encoding);
    wxFontInfo& AllFlags(int flags);
};
WXGO_DECL_TYPECONV(Font)
class wxFont : public wxGDIObject
{
public:
    wxFont();
    wxFont(const wxFont& font);
    wxFont(const wxFontInfo& font);
    wxFont(int pointSize, wxFontFamily family, wxFontStyle style,
           wxFontWeight weight,
           bool underline = false,
           const wxString& faceName = wxEmptyString,
           wxFontEncoding encoding = wxFONTENCODING_DEFAULT);
    wxFont(const wxSize& pixelSize, wxFontFamily family,
           wxFontStyle style, wxFontWeight weight,
           bool underline = false,
           const wxString& faceName = wxEmptyString,
           wxFontEncoding encoding = wxFONTENCODING_DEFAULT);
    wxFont(const wxString& nativeInfoString);
    wxFont(const wxNativeFontInfo& nativeInfo);
    virtual ~wxFont();
    virtual wxFontEncoding GetEncoding() const;
    virtual wxString GetFaceName() const;
    virtual wxFontFamily GetFamily() const;
    wxString GetNativeFontInfoDesc() const;
    wxString GetNativeFontInfoUserDesc() const;
    const wxNativeFontInfo *GetNativeFontInfo() const;
    virtual int GetPointSize() const;
    virtual wxSize GetPixelSize() const;
    virtual wxFontStyle GetStyle() const;
    virtual bool GetUnderlined() const;
    virtual bool GetStrikethrough() const;
    virtual wxFontWeight GetWeight() const;
    virtual bool IsFixedWidth() const;
    virtual bool IsOk() const;
    wxFont Bold() const;
    wxFont Italic() const;
    wxFont Larger() const;
    wxFont Smaller() const;
    wxFont Underlined() const;
    wxFont Strikethrough() const;
    wxFont& MakeBold();
    wxFont& MakeItalic();
    wxFont& MakeLarger();
    wxFont& MakeSmaller();
    wxFont& MakeUnderlined();
    wxFont& MakeStrikethrough();
    wxFont& Scale(float x);
    wxFont Scaled(float x) const;
    virtual void SetEncoding(wxFontEncoding encoding);
    virtual bool SetFaceName(const wxString& faceName);
    virtual void SetFamily(wxFontFamily family);
    bool SetNativeFontInfo(const wxString& info);
    bool SetNativeFontInfoUserDesc(const wxString& info);
    void SetNativeFontInfo(const wxNativeFontInfo& info);
    virtual void SetPointSize(int pointSize);
    virtual void SetPixelSize(const wxSize& pixelSize);
    virtual void SetStyle(wxFontStyle style);
    void SetSymbolicSize(wxFontSymbolicSize size);
    void SetSymbolicSizeRelativeTo(wxFontSymbolicSize size, int base);
    virtual void SetUnderlined(bool underlined);
    virtual void SetStrikethrough(bool strikethrough);
    virtual void SetWeight(wxFontWeight weight);
    static wxFontEncoding GetDefaultEncoding();
    static void SetDefaultEncoding(wxFontEncoding encoding);
    static wxFont* New(int pointSize, wxFontFamily family, wxFontStyle style,
                       wxFontWeight weight,
                       bool underline = false,
                       const wxString& faceName = wxEmptyString,
                       wxFontEncoding encoding = wxFONTENCODING_DEFAULT);
    static wxFont* New(int pointSize, wxFontFamily family,
                       int flags = wxFONTFLAG_DEFAULT,
                       const wxString& faceName = wxEmptyString,
                       wxFontEncoding encoding = wxFONTENCODING_DEFAULT);
    static wxFont* New(const wxSize& pixelSize,
                       wxFontFamily family,
                       wxFontStyle style,
                       wxFontWeight weight,
                       bool underline = false,
                       const wxString& faceName = wxEmptyString,
                       wxFontEncoding encoding = wxFONTENCODING_DEFAULT);
    static wxFont* New(const wxSize& pixelSize,
                       wxFontFamily family,
                       int flags = wxFONTFLAG_DEFAULT,
                       const wxString& faceName = wxEmptyString,
                       wxFontEncoding encoding = wxFONTENCODING_DEFAULT);
    static wxFont *New(const wxNativeFontInfo& nativeInfo);
    static wxFont *New(const wxString& nativeInfoString);
};
%constant wxFont wxNullFont;
WXGO_DECL_TYPECONV(FontList)
class wxFontList
{
public:
    wxFontList();
    wxFont* FindOrCreateFont(int point_size, wxFontFamily family, wxFontStyle style,
                             wxFontWeight weight, bool underline = false,
                             const wxString& facename = wxEmptyString,
                             wxFontEncoding encoding = wxFONTENCODING_DEFAULT);
};
%constant wxFontList* wxTheFontList;
bool wxFromString(const wxString& string, wxFont* font);
wxString wxToString(const wxFont& font);