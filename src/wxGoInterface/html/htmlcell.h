WXGO_DECL_TYPECONV(HtmlSelection)
class wxHtmlSelection
{
public:
    wxHtmlSelection();
    void Set(const wxPoint& fromPos, const wxHtmlCell *fromCell,
             const wxPoint& toPos, const wxHtmlCell *toCell);
    void Set(const wxHtmlCell *fromCell, const wxHtmlCell *toCell);
    const wxHtmlCell *GetFromCell() const;
    const wxHtmlCell *GetToCell() const;
    const wxPoint& GetFromPos() const;
    const wxPoint& GetToPos() const;
    void ClearFromToCharacterPos();
    bool AreFromToCharacterPosSet() const;
    void SetFromCharacterPos (wxCoord pos);
    void SetToCharacterPos (wxCoord pos);
    wxCoord GetFromCharacterPos () const;
    wxCoord GetToCharacterPos () const;
    bool IsEmpty() const;
};
%typedef int wxHtmlSelectionState;
#define wxHTML_SEL_OUT 0
#define wxHTML_SEL_IN wxHTML_SEL_OUT + 1
#define wxHTML_SEL_CHANGING wxHTML_SEL_IN + 1
WXGO_DECL_TYPECONV(HtmlRenderingState)
class wxHtmlRenderingState
{
public:
    wxHtmlRenderingState();
    void SetSelectionState(wxHtmlSelectionState s);
    wxHtmlSelectionState GetSelectionState() const;
    void SetFgColour(const wxColour& c);
    const wxColour& GetFgColour() const;
    void SetBgColour(const wxColour& c);
    const wxColour& GetBgColour() const;
    void SetBgMode(int m);
    int GetBgMode() const;
};
WXGO_DECL_TYPECONV(HtmlRenderingStyle)
class wxHtmlRenderingStyle
{
public:
    virtual wxColour GetSelectedTextColour(const wxColour& clr) = 0;
    virtual wxColour GetSelectedTextBgColour(const wxColour& clr) = 0;
};
WXGO_DECL_TYPECONV(HtmlRenderingInfo)
class wxHtmlRenderingInfo
{
public:
    wxHtmlRenderingInfo();
    void SetSelection(wxHtmlSelection *s);
    wxHtmlSelection *GetSelection() const;
    void SetStyle(wxHtmlRenderingStyle *style);
    wxHtmlRenderingStyle& GetStyle();
    wxHtmlRenderingState& GetState();
};
enum
{
    wxHTML_FIND_EXACT             = 1,
    wxHTML_FIND_NEAREST_BEFORE    = 2,
    wxHTML_FIND_NEAREST_AFTER     = 4
};
enum wxHtmlScriptMode
{
    wxHTML_SCRIPT_NORMAL,
    wxHTML_SCRIPT_SUB,
    wxHTML_SCRIPT_SUP
};
WXGO_DECL_TYPECONV(HtmlCell)
class wxHtmlCell : public wxObject
{
public:
    wxHtmlCell();
    virtual bool AdjustPagebreak(int* pagebreak,
                                 const wxArrayInt& known_pagebreaks,
                                 int pageHeight) const;
    virtual void Draw(wxDC& dc, int x, int y, int view_y1, int view_y2, wxHtmlRenderingInfo& info);
    virtual void DrawInvisible(wxDC& dc, int x , int y, wxHtmlRenderingInfo& info);
    virtual const wxHtmlCell* Find(int condition, const void* param) const;
    int GetDescent() const;
    virtual wxHtmlCell* GetFirstChild() const;
    int GetHeight() const;
    const wxString& GetId() const;
    virtual wxHtmlLinkInfo* GetLink(int x = 0, int y = 0) const;
    virtual wxCursor GetMouseCursor(wxHtmlWindowInterface* window) const;
    virtual wxCursor GetMouseCursorAt(wxHtmlWindowInterface* window,
                                      const wxPoint& rePos) const;
    wxHtmlCell* GetNext() const;
    wxHtmlContainerCell* GetParent() const;
    int GetPosX() const;
    int GetPosY() const;
    int GetWidth() const;
    virtual void Layout(int w);
    virtual bool ProcessMouseClick(wxHtmlWindowInterface* window,
                                   const wxPoint& pos,
                                   const wxMouseEvent& event);
    void SetId(const wxString& id);
    void SetLink(const wxHtmlLinkInfo& link);
    void SetNext(wxHtmlCell* cell);
    void SetParent(wxHtmlContainerCell* p);
    virtual void SetPos(int x, int y);
};
WXGO_DECL_TYPECONV(HtmlContainerCell)
class wxHtmlContainerCell : public wxHtmlCell
{
public:
    wxHtmlContainerCell(wxHtmlContainerCell* parent);
    int GetAlignHor() const;
    int GetAlignVer() const;
    wxColour GetBackgroundColour();
    int GetIndent(int ind) const;
    int GetIndentUnits(int ind) const;
    void InsertCell(wxHtmlCell* cell);
    void SetAlign(const wxHtmlTag& tag);
    void SetAlignHor(int al);
    void SetAlignVer(int al);
    void SetBackgroundColour(const wxColour& clr);
    void SetBorder(const wxColour& clr1, const wxColour& clr2, int border = 1);
    void SetIndent(int i, int what, int units = wxHTML_UNITS_PIXELS);
    void SetMinHeight(int h, int align = wxHTML_ALIGN_TOP);
    void SetWidthFloat(int w, int units);
    void SetWidthFloat(const wxHtmlTag& tag,
                       double pixel_scale = 1.0);
};
WXGO_DECL_TYPECONV(HtmlLinkInfo)
class wxHtmlLinkInfo : public wxObject
{
public:
    wxHtmlLinkInfo();
    wxHtmlLinkInfo(const wxString& href,
                   const wxString& target = wxEmptyString);
    const wxMouseEvent* GetEvent() const;
    wxString GetHref() const;
    const wxHtmlCell* GetHtmlCell() const;
    wxString GetTarget() const;
};
WXGO_DECL_TYPECONV(HtmlColourCell)
class wxHtmlColourCell : public wxHtmlCell
{
public:
    wxHtmlColourCell(const wxColour& clr, int flags = wxHTML_CLR_FOREGROUND);
};
WXGO_DECL_TYPECONV(HtmlWidgetCell)
class wxHtmlWidgetCell : public wxHtmlCell
{
public:
    wxHtmlWidgetCell(wxWindow* wnd, int w = 0);
};
WXGO_DECL_TYPECONV(HtmlWordCell)
class wxHtmlWordCell : public wxHtmlCell
{
public:
    wxHtmlWordCell(const wxString& word, const wxDC& dc);
};
WXGO_DECL_TYPECONV(HtmlWordWithTabsCell)
class wxHtmlWordWithTabsCell : public wxHtmlWordCell
{
public:
    wxHtmlWordWithTabsCell(const wxString& word,
                           const wxString& wordOrig,
                           size_t linepos,
                           const wxDC& dc);
};
WXGO_DECL_TYPECONV(HtmlFontCell)
class wxHtmlFontCell : public wxHtmlCell
{
public:
    wxHtmlFontCell(wxFont *font);
};