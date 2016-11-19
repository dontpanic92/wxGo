#define wxHW_SCROLLBAR_NEVER    0x0002
#define wxHW_SCROLLBAR_AUTO     0x0004
#define wxHW_NO_SELECTION       0x0008
#define wxHW_DEFAULT_STYLE      wxHW_SCROLLBAR_AUTO
%typedef int wxHtmlOpeningStatus;
#define wxHTML_OPEN 0
#define wxHTML_BLOCK wxHTML_OPEN + 1
#define wxHTML_REDIRECT wxHTML_BLOCK + 1
WXGO_DECL_TYPECONV(HtmlWindowInterface)
class wxHtmlWindowInterface
{
public:
    wxHtmlWindowInterface();
    virtual ~wxHtmlWindowInterface();
    virtual void SetHTMLWindowTitle(const wxString& title) = 0;
    virtual void OnHTMLLinkClicked(const wxHtmlLinkInfo& link) = 0;
    virtual wxHtmlOpeningStatus OnHTMLOpeningURL(wxHtmlURLType type,
                                                 const wxString& url,
                                                 wxString *redirect) const = 0;
    virtual wxPoint HTMLCoordsToWindow(wxHtmlCell *cell,
                                       const wxPoint& pos) const = 0;
    virtual wxWindow* GetHTMLWindow() = 0;
    virtual wxColour GetHTMLBackgroundColour() const = 0;
    virtual void SetHTMLBackgroundColour(const wxColour& clr) = 0;
    virtual void SetHTMLBackgroundImage(const wxBitmap& bmpBg) = 0;
    virtual void SetHTMLStatusText(const wxString& text) = 0;
    enum HTMLCursor
    {
        HTMLCursor_Default,
        HTMLCursor_Link,
        HTMLCursor_Text
    };
    virtual wxCursor GetHTMLCursor(wxHtmlWindowInterface::HTMLCursor type) const = 0;
};
WXGO_DECL_TYPECONV(HtmlWindow)
class wxHtmlWindow : public wxScrolledWindow, public wxHtmlWindowInterface
{
public:
    wxHtmlWindow();
    wxHtmlWindow(wxWindow *parent, wxWindowID id = wxID_ANY,
                 const wxPoint& pos = wxDefaultPosition,
                 const wxSize& size = wxDefaultSize,
                 long style = wxHW_DEFAULT_STYLE,
                 const wxString& name = "htmlWindow");
    virtual void SetHTMLWindowTitle(const wxString& title);
    virtual void OnHTMLLinkClicked(const wxHtmlLinkInfo& link);
    virtual wxHtmlOpeningStatus OnHTMLOpeningURL(wxHtmlURLType type,
                                                 const wxString& url,
                                                 wxString *redirect) const;
    virtual wxPoint HTMLCoordsToWindow(wxHtmlCell *cell,
                                       const wxPoint& pos) const;
    virtual wxWindow* GetHTMLWindow();
    virtual wxColour GetHTMLBackgroundColour() const;
    virtual void SetHTMLBackgroundColour(const wxColour& clr);
    virtual void SetHTMLBackgroundImage(const wxBitmap& bmpBg);
    virtual void SetHTMLStatusText(const wxString& text);
    virtual wxCursor GetHTMLCursor(HTMLCursor type) const;
    static void AddFilter(wxHtmlFilter* filter);
    bool AppendToPage(const wxString& source);
    wxHtmlContainerCell* GetInternalRepresentation() const;
    wxString GetOpenedAnchor() const;
    wxString GetOpenedPage() const;
    wxString GetOpenedPageTitle() const;
    wxFrame* GetRelatedFrame() const;
    bool HistoryBack();
    bool HistoryCanBack();
    bool HistoryCanForward();
    void HistoryClear();
    bool HistoryForward();
    bool LoadFile(const wxFileName& filename);
    virtual bool LoadPage(const wxString& location);
    virtual void OnLinkClicked(const wxHtmlLinkInfo& link);
    virtual wxHtmlOpeningStatus OnOpeningURL(wxHtmlURLType type,
                                             const wxString& url,
                                             wxString* redirect) const;
    virtual void OnSetTitle(const wxString& title);
    virtual void ReadCustomization(wxConfigBase* cfg,
                                   wxString path = wxEmptyString);
    void SelectAll();
    void SelectLine(const wxPoint& pos);
    void SelectWord(const wxPoint& pos);
    wxString SelectionToText();
    void SetBorders(int b);
    void SetFonts(const wxString& normal_face, const wxString& fixed_face,
                  const int* sizes = NULL);
    void SetStandardFonts(int size = -1,
                          const wxString& normal_face = wxEmptyString,
                          const wxString& fixed_face = wxEmptyString);
    virtual bool SetPage(const wxString& source);
    void SetRelatedFrame(wxFrame* frame, const wxString& format);
    void SetRelatedStatusBar(int index);
    void SetRelatedStatusBar(wxStatusBar* statusbar, int index = 0);
    wxString ToText();
    virtual void WriteCustomization(wxConfigBase* cfg,
                                    wxString path = wxEmptyString);
    static wxCursor GetDefaultHTMLCursor(HTMLCursor type);
    static void SetDefaultHTMLCursor(HTMLCursor type, const wxCursor& cursor);
protected:
    virtual bool OnCellClicked(wxHtmlCell* cell, wxCoord x, wxCoord y,
                               const wxMouseEvent& event);
    virtual void OnCellMouseHover(wxHtmlCell* cell, wxCoord x, wxCoord y);
};
%constant wxEventType wxEVT_HTML_CELL_CLICKED;
%constant wxEventType wxEVT_HTML_CELL_HOVER;
%constant wxEventType wxEVT_HTML_LINK_CLICKED;
WXGO_DECL_TYPECONV(HtmlLinkEvent)
class wxHtmlLinkEvent : public wxCommandEvent
{
public:
    wxHtmlLinkEvent(int id, const wxHtmlLinkInfo& linkinfo);
    const wxHtmlLinkInfo& GetLinkInfo() const;
};
WXGO_DECL_TYPECONV(HtmlCellEvent)
class wxHtmlCellEvent : public wxCommandEvent
{
public:
    wxHtmlCellEvent(wxEventType commandType, int id,
                    wxHtmlCell* cell,
                    const wxPoint& point,
                    const wxMouseEvent& ev);
    wxHtmlCell* GetCell() const;
    bool GetLinkClicked() const;
    wxPoint GetPoint() const;
    void SetLinkClicked(bool linkclicked);
};