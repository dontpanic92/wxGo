#define wxTE_NO_VSCROLL     0x0002
#define wxTE_READONLY       0x0010
#define wxTE_MULTILINE      0x0020
#define wxTE_PROCESS_TAB    0x0040
#define wxTE_LEFT           0x0000                    
#define wxTE_CENTER         wxALIGN_CENTER_HORIZONTAL 
#define wxTE_RIGHT          wxALIGN_RIGHT             
#define wxTE_CENTRE         wxTE_CENTER
#define wxTE_RICH           0x0080
#define wxTE_PROCESS_ENTER  0x0400
#define wxTE_PASSWORD       0x0800
#define wxTE_AUTO_URL       0x1000
#define wxTE_NOHIDESEL      0x2000
#define wxTE_DONTWRAP       wxHSCROLL
#define wxTE_CHARWRAP       0x4000  
#define wxTE_WORDWRAP       0x0001  
#define wxTE_BESTWRAP       0x0000  
#define wxTE_RICH2          0x8000
#define wxTEXT_TYPE_ANY     0
typedef long wxTextCoord;
%typedef int wxTextAttrAlignment;
#define wxTEXT_ALIGNMENT_DEFAULT 0
#define wxTEXT_ALIGNMENT_LEFT wxTEXT_ALIGNMENT_DEFAULT + 1
#define wxTEXT_ALIGNMENT_CENTRE wxTEXT_ALIGNMENT_LEFT + 1
#define wxTEXT_ALIGNMENT_CENTER  wxTEXT_ALIGNMENT_CENTRE
#define wxTEXT_ALIGNMENT_RIGHT wxTEXT_ALIGNMENT_CENTER  + 1
#define wxTEXT_ALIGNMENT_JUSTIFIED wxTEXT_ALIGNMENT_RIGHT + 1
%typedef int wxTextAttrFlags;
#define wxTEXT_ATTR_TEXT_COLOUR           0x00000001
#define wxTEXT_ATTR_BACKGROUND_COLOUR     0x00000002
#define wxTEXT_ATTR_FONT_FACE             0x00000004
#define wxTEXT_ATTR_FONT_POINT_SIZE       0x00000008
#define wxTEXT_ATTR_FONT_PIXEL_SIZE       0x10000000
#define wxTEXT_ATTR_FONT_WEIGHT           0x00000010
#define wxTEXT_ATTR_FONT_ITALIC           0x00000020
#define wxTEXT_ATTR_FONT_UNDERLINE        0x00000040
#define wxTEXT_ATTR_FONT_STRIKETHROUGH    0x08000000
#define wxTEXT_ATTR_FONT_ENCODING         0x02000000
#define wxTEXT_ATTR_FONT_FAMILY           0x04000000
#define wxTEXT_ATTR_FONT_SIZE  \        ( wxTEXT_ATTR_FONT_POINT_SIZE | wxTEXT_ATTR_FONT_PIXEL_SIZE )
#define wxTEXT_ATTR_FONT  \        ( wxTEXT_ATTR_FONT_FACE | wxTEXT_ATTR_FONT_SIZE | wxTEXT_ATTR_FONT_WEIGHT | \            wxTEXT_ATTR_FONT_ITALIC | wxTEXT_ATTR_FONT_UNDERLINE | wxTEXT_ATTR_FONT_STRIKETHROUGH | wxTEXT_ATTR_FONT_ENCODING | wxTEXT_ATTR_FONT_FAMILY )
#define wxTEXT_ATTR_ALIGNMENT             0x00000080
#define wxTEXT_ATTR_LEFT_INDENT           0x00000100
#define wxTEXT_ATTR_RIGHT_INDENT          0x00000200
#define wxTEXT_ATTR_TABS                  0x00000400
#define wxTEXT_ATTR_PARA_SPACING_AFTER    0x00000800
#define wxTEXT_ATTR_PARA_SPACING_BEFORE   0x00001000
#define wxTEXT_ATTR_LINE_SPACING          0x00002000
#define wxTEXT_ATTR_CHARACTER_STYLE_NAME  0x00004000
#define wxTEXT_ATTR_PARAGRAPH_STYLE_NAME  0x00008000
#define wxTEXT_ATTR_LIST_STYLE_NAME       0x00010000
#define wxTEXT_ATTR_BULLET_STYLE          0x00020000
#define wxTEXT_ATTR_BULLET_NUMBER         0x00040000
#define wxTEXT_ATTR_BULLET_TEXT           0x00080000
#define wxTEXT_ATTR_BULLET_NAME           0x00100000
#define wxTEXT_ATTR_BULLET  \        ( wxTEXT_ATTR_BULLET_STYLE | wxTEXT_ATTR_BULLET_NUMBER | wxTEXT_ATTR_BULLET_TEXT | \          wxTEXT_ATTR_BULLET_NAME )
#define wxTEXT_ATTR_URL                   0x00200000
#define wxTEXT_ATTR_PAGE_BREAK            0x00400000
#define wxTEXT_ATTR_EFFECTS               0x00800000
#define wxTEXT_ATTR_OUTLINE_LEVEL         0x01000000
#define wxTEXT_ATTR_AVOID_PAGE_BREAK_BEFORE  0x20000000
#define wxTEXT_ATTR_AVOID_PAGE_BREAK_AFTER  0x40000000
#define wxTEXT_ATTR_CHARACTER  \        (wxTEXT_ATTR_FONT|wxTEXT_ATTR_EFFECTS| \            wxTEXT_ATTR_BACKGROUND_COLOUR|wxTEXT_ATTR_TEXT_COLOUR|wxTEXT_ATTR_CHARACTER_STYLE_NAME|wxTEXT_ATTR_URL)
#define wxTEXT_ATTR_PARAGRAPH  \        (wxTEXT_ATTR_ALIGNMENT|wxTEXT_ATTR_LEFT_INDENT|wxTEXT_ATTR_RIGHT_INDENT|wxTEXT_ATTR_TABS|\            wxTEXT_ATTR_PARA_SPACING_BEFORE|wxTEXT_ATTR_PARA_SPACING_AFTER|wxTEXT_ATTR_LINE_SPACING|\            wxTEXT_ATTR_BULLET|wxTEXT_ATTR_PARAGRAPH_STYLE_NAME|wxTEXT_ATTR_LIST_STYLE_NAME|wxTEXT_ATTR_OUTLINE_LEVEL|\            wxTEXT_ATTR_PAGE_BREAK|wxTEXT_ATTR_AVOID_PAGE_BREAK_BEFORE|wxTEXT_ATTR_AVOID_PAGE_BREAK_AFTER)
#define wxTEXT_ATTR_ALL  (wxTEXT_ATTR_CHARACTER|wxTEXT_ATTR_PARAGRAPH)
%typedef int wxTextAttrBulletStyle;
#define wxTEXT_ATTR_BULLET_STYLE_NONE             0x00000000
#define wxTEXT_ATTR_BULLET_STYLE_ARABIC           0x00000001
#define wxTEXT_ATTR_BULLET_STYLE_LETTERS_UPPER    0x00000002
#define wxTEXT_ATTR_BULLET_STYLE_LETTERS_LOWER    0x00000004
#define wxTEXT_ATTR_BULLET_STYLE_ROMAN_UPPER      0x00000008
#define wxTEXT_ATTR_BULLET_STYLE_ROMAN_LOWER      0x00000010
#define wxTEXT_ATTR_BULLET_STYLE_SYMBOL           0x00000020
#define wxTEXT_ATTR_BULLET_STYLE_BITMAP           0x00000040
#define wxTEXT_ATTR_BULLET_STYLE_PARENTHESES      0x00000080
#define wxTEXT_ATTR_BULLET_STYLE_PERIOD           0x00000100
#define wxTEXT_ATTR_BULLET_STYLE_STANDARD         0x00000200
#define wxTEXT_ATTR_BULLET_STYLE_RIGHT_PARENTHESIS  0x00000400
#define wxTEXT_ATTR_BULLET_STYLE_OUTLINE          0x00000800
#define wxTEXT_ATTR_BULLET_STYLE_ALIGN_LEFT       0x00000000
#define wxTEXT_ATTR_BULLET_STYLE_ALIGN_RIGHT      0x00001000
#define wxTEXT_ATTR_BULLET_STYLE_ALIGN_CENTRE     0x00002000
#define wxTEXT_ATTR_BULLET_STYLE_CONTINUATION     0x00004000
%typedef int wxTextAttrEffects;
#define wxTEXT_ATTR_EFFECT_NONE                   0x00000000
#define wxTEXT_ATTR_EFFECT_CAPITALS               0x00000001
#define wxTEXT_ATTR_EFFECT_SMALL_CAPITALS         0x00000002
#define wxTEXT_ATTR_EFFECT_STRIKETHROUGH          0x00000004
#define wxTEXT_ATTR_EFFECT_DOUBLE_STRIKETHROUGH   0x00000008
#define wxTEXT_ATTR_EFFECT_SHADOW                 0x00000010
#define wxTEXT_ATTR_EFFECT_EMBOSS                 0x00000020
#define wxTEXT_ATTR_EFFECT_OUTLINE                0x00000040
#define wxTEXT_ATTR_EFFECT_ENGRAVE                0x00000080
#define wxTEXT_ATTR_EFFECT_SUPERSCRIPT            0x00000100
#define wxTEXT_ATTR_EFFECT_SUBSCRIPT              0x00000200
#define wxTEXT_ATTR_EFFECT_RTL                    0x00000400
#define wxTEXT_ATTR_EFFECT_SUPPRESS_HYPHENATION   0x00001000
%typedef int wxTextAttrLineSpacing;
#define wxTEXT_ATTR_LINE_SPACING_NORMAL          10
#define wxTEXT_ATTR_LINE_SPACING_HALF            15
#define wxTEXT_ATTR_LINE_SPACING_TWICE           20
%typedef int wxTextCtrlHitTestResult;
#define wxTE_HT_UNKNOWN  -2
#define wxTE_HT_BEFORE wxTE_HT_UNKNOWN  + 1
#define wxTE_HT_ON_TEXT wxTE_HT_BEFORE + 1
#define wxTE_HT_BELOW wxTE_HT_ON_TEXT + 1
#define wxTE_HT_BEYOND wxTE_HT_BELOW + 1
WXGO_DECL_TYPECONV(TextAttr)
class wxTextAttr
{
public:
    wxTextAttr();
    wxTextAttr(const wxColour& colText,
               const wxColour& colBack = wxNullColour,
               const wxFont& font = wxNullFont,
               wxTextAttrAlignment alignment = wxTEXT_ALIGNMENT_DEFAULT);
    wxTextAttr(const wxTextAttr& attr);
    bool Apply(const wxTextAttr& style,
               const wxTextAttr* compareWith = NULL);
    void Merge(const wxTextAttr& overlay);
    bool EqPartial(const wxTextAttr& attr, bool weakTest = true) const;
    wxTextAttrAlignment GetAlignment() const;
    const wxColour& GetBackgroundColour() const;
    const wxString& GetBulletFont() const;
    const wxString& GetBulletName() const;
    int GetBulletNumber() const;
    int GetBulletStyle() const;
    const wxString& GetBulletText() const;
    const wxString& GetCharacterStyleName() const;
    long GetFlags() const;
    wxFont GetFont() const;
    bool GetFontAttributes(const wxFont& font,
                           int flags = wxTEXT_ATTR_FONT);
    wxFontEncoding GetFontEncoding() const;
    const wxString& GetFontFaceName() const;
    wxFontFamily GetFontFamily() const;
    int GetFontSize() const;
    wxFontStyle GetFontStyle() const;
    bool GetFontUnderlined() const;
    wxFontWeight GetFontWeight() const;
    long GetLeftIndent() const;
    long GetLeftSubIndent() const;
    int GetLineSpacing() const;
    const wxString& GetListStyleName() const;
    int GetOutlineLevel() const;
    int GetParagraphSpacingAfter() const;
    int GetParagraphSpacingBefore() const;
    const wxString& GetParagraphStyleName() const;
    long GetRightIndent() const;
    const wxArrayInt& GetTabs() const;
    const wxColour& GetTextColour() const;
    int GetTextEffectFlags() const;
    int GetTextEffects() const;
    const wxString& GetURL() const;
    bool HasAlignment() const;
    bool HasBackgroundColour() const;
    bool HasBulletName() const;
    bool HasBulletNumber() const;
    bool HasBulletStyle() const;
    bool HasBulletText() const;
    bool HasCharacterStyleName() const;
    bool HasFlag(long flag) const;
    bool HasFont() const;
    bool HasFontEncoding() const;
    bool HasFontFaceName() const;
    bool HasFontFamily() const;
    bool HasFontItalic() const;
    bool HasFontSize() const;
    bool HasFontPointSize() const;
    bool HasFontPixelSize() const;
    bool HasFontUnderlined() const;
    bool HasFontWeight() const;
    bool HasLeftIndent() const;
    bool HasLineSpacing() const;
    bool HasListStyleName() const;
    bool HasOutlineLevel() const;
    bool HasPageBreak() const;
    bool HasParagraphSpacingAfter() const;
    bool HasParagraphSpacingBefore() const;
    bool HasParagraphStyleName() const;
    bool HasRightIndent() const;
    bool HasTabs() const;
    bool HasTextColour() const;
    bool HasTextEffects() const;
    bool HasURL() const;
    bool IsCharacterStyle() const;
    bool IsDefault() const;
    bool IsParagraphStyle() const;
    void SetAlignment(wxTextAttrAlignment alignment);
    void SetBackgroundColour(const wxColour& colBack);
    void SetBulletFont(const wxString& font);
    void SetBulletName(const wxString& name);
    void SetBulletNumber(int n);
    void SetBulletStyle(int style);
    void SetBulletText(const wxString& text);
    void SetCharacterStyleName(const wxString& name);
    void SetFlags(long flags);
    void SetFont(const wxFont& font, int flags = wxTEXT_ATTR_FONT & ~wxTEXT_ATTR_FONT_PIXEL_SIZE);
    void SetFontEncoding(wxFontEncoding encoding);
    void SetFontFaceName(const wxString& faceName);
    void SetFontFamily(wxFontFamily family);
    void SetFontSize(int pointSize);
    void SetFontPointSize(int pointSize);
    void SetFontPixelSize(int pixelSize);
    void SetFontStyle(wxFontStyle fontStyle);
    void SetFontUnderlined(bool underlined);
    void SetFontWeight(wxFontWeight fontWeight);
    void SetLeftIndent(int indent, int subIndent = 0);
    void SetLineSpacing(int spacing);
    void SetListStyleName(const wxString& name);
    void SetOutlineLevel(int level);
    void SetPageBreak(bool pageBreak = true);
    void SetParagraphSpacingAfter(int spacing);
    void SetParagraphSpacingBefore(int spacing);
    void SetParagraphStyleName(const wxString& name);
    void SetRightIndent(int indent);
    void SetTabs(const wxArrayInt& tabs);
    void SetTextColour(const wxColour& colText);
    void SetTextEffectFlags(int flags);
    void SetTextEffects(int effects);
    void SetURL(const wxString& url);
    void operator=(const wxTextAttr& attr);
};
WXGO_DECL_TYPECONV(TextCtrl)
class wxTextCtrl : public wxControl,
                   public wxTextEntry
{
public:
    wxTextCtrl();
    wxTextCtrl(wxWindow* parent, wxWindowID id,
               const wxString& value = wxEmptyString,
               const wxPoint& pos = wxDefaultPosition,
               const wxSize& size = wxDefaultSize,
               long style = 0,
               const wxValidator& validator = wxDefaultValidator,
               const wxString& name = wxTextCtrlNameStr);
    virtual ~wxTextCtrl();
    bool Create(wxWindow* parent, wxWindowID id,
                const wxString& value = wxEmptyString,
                const wxPoint& pos = wxDefaultPosition,
                const wxSize& size = wxDefaultSize, long style = 0,
                const wxValidator& validator = wxDefaultValidator,
                const wxString& name = wxTextCtrlNameStr);
    virtual void DiscardEdits();
    virtual bool EmulateKeyPress(const wxKeyEvent& event);
    virtual const wxTextAttr& GetDefaultStyle() const;
    virtual int GetLineLength(long lineNo) const;
    virtual wxString GetLineText(long lineNo) const;
    virtual int GetNumberOfLines() const;
    virtual bool GetStyle(long position, wxTextAttr& style);
    wxTextCtrlHitTestResult HitTest(const wxPoint& pt, long *pos) const;
    wxTextCtrlHitTestResult HitTest(const wxPoint& pt,
                                    wxTextCoord *col,
                                    wxTextCoord *row) const;
    virtual bool IsModified() const;
    bool IsMultiLine() const;
    bool IsSingleLine() const;
    bool LoadFile(const wxString& filename,
                  int fileType = wxTEXT_TYPE_ANY);
    virtual void MarkDirty();
    void OnDropFiles(wxDropFilesEvent& event);
    virtual bool PositionToXY(long pos, long* x, long* y) const;
    wxPoint PositionToCoords(long pos) const;
    bool SaveFile(const wxString& filename = wxEmptyString,
                  int fileType = wxTEXT_TYPE_ANY);
    virtual bool SetDefaultStyle(const wxTextAttr& style);
    void SetModified(bool modified);
    virtual bool SetStyle(long start, long end, const wxTextAttr& style);
    virtual void ShowPosition(long pos);
    virtual long XYToPosition(long x, long y) const;
};
%constant wxEventType wxEVT_TEXT;
%constant wxEventType wxEVT_TEXT_ENTER;
%constant wxEventType wxEVT_TEXT_URL;
%constant wxEventType wxEVT_TEXT_MAXLEN;
WXGO_DECL_TYPECONV(TextUrlEvent)
class wxTextUrlEvent : public wxCommandEvent
{
public:
    wxTextUrlEvent(int winid, const wxMouseEvent& evtMouse,
                   long start, long end);
    wxTextUrlEvent(const wxTextUrlEvent& event);
    const wxMouseEvent& GetMouseEvent() const;
    long GetURLStart() const;
    long GetURLEnd() const;
    virtual wxEvent *Clone() const;
};