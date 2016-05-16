enum wxFontFamily
{
    wxFONTFAMILY_DEFAULT = wxDEFAULT,           
    wxFONTFAMILY_DECORATIVE = wxDECORATIVE,     
    wxFONTFAMILY_ROMAN = wxROMAN,               
    wxFONTFAMILY_SCRIPT = wxSCRIPT,             
    wxFONTFAMILY_SWISS = wxSWISS,               
    wxFONTFAMILY_MODERN = wxMODERN,
    wxFONTFAMILY_TELETYPE = wxTELETYPE,
    wxFONTFAMILY_MAX,
    wxFONTFAMILY_UNKNOWN = wxFONTFAMILY_MAX
};
enum wxFontStyle
{
    wxFONTSTYLE_NORMAL = wxNORMAL,
    wxFONTSTYLE_ITALIC = wxITALIC,
    wxFONTSTYLE_SLANT = wxSLANT,
    wxFONTSTYLE_MAX
};
enum wxFontWeight
{
    wxFONTWEIGHT_NORMAL = wxNORMAL,  
    wxFONTWEIGHT_LIGHT = wxLIGHT,    
    wxFONTWEIGHT_BOLD = wxBOLD,      
    wxFONTWEIGHT_MAX
};
enum wxFontSymbolicSize
{
    wxFONTSIZE_XX_SMALL = -3,   
    wxFONTSIZE_X_SMALL,         
    wxFONTSIZE_SMALL,           
    wxFONTSIZE_MEDIUM,          
    wxFONTSIZE_LARGE,           
    wxFONTSIZE_X_LARGE,         
    wxFONTSIZE_XX_LARGE         
};
enum wxFontFlag
{
    wxFONTFLAG_DEFAULT          = 0,
    wxFONTFLAG_ITALIC           = 1 << 0,
    wxFONTFLAG_SLANT            = 1 << 1,
    wxFONTFLAG_LIGHT            = 1 << 2,
    wxFONTFLAG_BOLD             = 1 << 3,
    wxFONTFLAG_ANTIALIASED      = 1 << 4,
    wxFONTFLAG_NOT_ANTIALIASED  = 1 << 5,
    wxFONTFLAG_UNDERLINED       = 1 << 6,
    wxFONTFLAG_STRIKETHROUGH    = 1 << 7,
    wxFONTFLAG_MASK = wxFONTFLAG_ITALIC             |
                      wxFONTFLAG_SLANT              |
                      wxFONTFLAG_LIGHT              |
                      wxFONTFLAG_BOLD               |
                      wxFONTFLAG_ANTIALIASED        |
                      wxFONTFLAG_NOT_ANTIALIASED    |
                      wxFONTFLAG_UNDERLINED         |
                      wxFONTFLAG_STRIKETHROUGH
};
enum wxFontEncoding
{
    wxFONTENCODING_SYSTEM = -1,     
    wxFONTENCODING_DEFAULT,         
    wxFONTENCODING_ISO8859_1,       
    wxFONTENCODING_ISO8859_2,       
    wxFONTENCODING_ISO8859_3,       
    wxFONTENCODING_ISO8859_4,       
    wxFONTENCODING_ISO8859_5,       
    wxFONTENCODING_ISO8859_6,       
    wxFONTENCODING_ISO8859_7,       
    wxFONTENCODING_ISO8859_8,       
    wxFONTENCODING_ISO8859_9,       
    wxFONTENCODING_ISO8859_10,      
    wxFONTENCODING_ISO8859_11,      
    wxFONTENCODING_ISO8859_12,      
    wxFONTENCODING_ISO8859_13,      
    wxFONTENCODING_ISO8859_14,      
    wxFONTENCODING_ISO8859_15,      
    wxFONTENCODING_ISO8859_MAX,
    wxFONTENCODING_KOI8,            
    wxFONTENCODING_KOI8_U,          
    wxFONTENCODING_ALTERNATIVE,     
    wxFONTENCODING_BULGARIAN,       
    wxFONTENCODING_CP437,           
    wxFONTENCODING_CP850,           
    wxFONTENCODING_CP852,           
    wxFONTENCODING_CP855,           
    wxFONTENCODING_CP866,           
    wxFONTENCODING_CP874,           
    wxFONTENCODING_CP932,           
    wxFONTENCODING_CP936,           
    wxFONTENCODING_CP949,           
    wxFONTENCODING_CP950,           
    wxFONTENCODING_CP1250,          
    wxFONTENCODING_CP1251,          
    wxFONTENCODING_CP1252,          
    wxFONTENCODING_CP1253,          
    wxFONTENCODING_CP1254,          
    wxFONTENCODING_CP1255,          
    wxFONTENCODING_CP1256,          
    wxFONTENCODING_CP1257,          
    wxFONTENCODING_CP1258,          
    wxFONTENCODING_CP1361,          
    wxFONTENCODING_CP12_MAX,
    wxFONTENCODING_UTF7,            
    wxFONTENCODING_UTF8,            
    wxFONTENCODING_EUC_JP,          
    wxFONTENCODING_UTF16BE,         
    wxFONTENCODING_UTF16LE,         
    wxFONTENCODING_UTF32BE,         
    wxFONTENCODING_UTF32LE,         
    wxFONTENCODING_MACROMAN,        
    wxFONTENCODING_MACJAPANESE,
    wxFONTENCODING_MACCHINESETRAD,
    wxFONTENCODING_MACKOREAN,
    wxFONTENCODING_MACARABIC,
    wxFONTENCODING_MACHEBREW,
    wxFONTENCODING_MACGREEK,
    wxFONTENCODING_MACCYRILLIC,
    wxFONTENCODING_MACDEVANAGARI,
    wxFONTENCODING_MACGURMUKHI,
    wxFONTENCODING_MACGUJARATI,
    wxFONTENCODING_MACORIYA,
    wxFONTENCODING_MACBENGALI,
    wxFONTENCODING_MACTAMIL,
    wxFONTENCODING_MACTELUGU,
    wxFONTENCODING_MACKANNADA,
    wxFONTENCODING_MACMALAJALAM,
    wxFONTENCODING_MACSINHALESE,
    wxFONTENCODING_MACBURMESE,
    wxFONTENCODING_MACKHMER,
    wxFONTENCODING_MACTHAI,
    wxFONTENCODING_MACLAOTIAN,
    wxFONTENCODING_MACGEORGIAN,
    wxFONTENCODING_MACARMENIAN,
    wxFONTENCODING_MACCHINESESIMP,
    wxFONTENCODING_MACTIBETAN,
    wxFONTENCODING_MACMONGOLIAN,
    wxFONTENCODING_MACETHIOPIC,
    wxFONTENCODING_MACCENTRALEUR,
    wxFONTENCODING_MACVIATNAMESE,
    wxFONTENCODING_MACARABICEXT,
    wxFONTENCODING_MACSYMBOL,
    wxFONTENCODING_MACDINGBATS,
    wxFONTENCODING_MACTURKISH,
    wxFONTENCODING_MACCROATIAN,
    wxFONTENCODING_MACICELANDIC,
    wxFONTENCODING_MACROMANIAN,
    wxFONTENCODING_MACCELTIC,
    wxFONTENCODING_MACGAELIC,
    wxFONTENCODING_MACKEYBOARD,
    wxFONTENCODING_ISO2022_JP,      
    wxFONTENCODING_MAX,             
    wxFONTENCODING_MACMIN = wxFONTENCODING_MACROMAN ,
    wxFONTENCODING_MACMAX = wxFONTENCODING_MACKEYBOARD ,
    wxFONTENCODING_UTF16,  
    wxFONTENCODING_UTF32,  
    wxFONTENCODING_UNICODE,
    wxFONTENCODING_GB2312 = wxFONTENCODING_CP936, 
    wxFONTENCODING_BIG5 = wxFONTENCODING_CP950,   
    wxFONTENCODING_SHIFT_JIS = wxFONTENCODING_CP932, 
    wxFONTENCODING_EUC_KR = wxFONTENCODING_CP949, 
    wxFONTENCODING_JOHAB = wxFONTENCODING_CP1361, 
    wxFONTENCODING_VIETNAMESE = wxFONTENCODING_CP1258 
};
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
    //bool operator!=(const wxFont& font) const;
    //bool operator==(const wxFont& font) const;
    //wxFont& operator =(const wxFont& font);
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
wxFont wxNullFont;
/*
wxFont* wxNORMAL_FONT;
wxFont* wxSMALL_FONT;
wxFont* wxITALIC_FONT;
wxFont* wxSWISS_FONT;
*/
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
