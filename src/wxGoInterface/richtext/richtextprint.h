%typedef int wxRichTextOddEvenPage;
#define wxRICHTEXT_PAGE_ODD 0
#define wxRICHTEXT_PAGE_EVEN wxRICHTEXT_PAGE_ODD + 1
#define wxRICHTEXT_PAGE_ALL wxRICHTEXT_PAGE_EVEN + 1
%typedef int wxRichTextPageLocation;
#define wxRICHTEXT_PAGE_LEFT 0
#define wxRICHTEXT_PAGE_CENTRE wxRICHTEXT_PAGE_LEFT + 1
#define wxRICHTEXT_PAGE_RIGHT wxRICHTEXT_PAGE_CENTRE + 1
WXGO_DECL_TYPECONV(RichTextHeaderFooterData)
class wxRichTextHeaderFooterData : public wxObject
{
public:
    wxRichTextHeaderFooterData();
    wxRichTextHeaderFooterData(const wxRichTextHeaderFooterData& data);
    void Clear();
    void Copy(const wxRichTextHeaderFooterData& data);
    const wxFont& GetFont() const;
    int GetFooterMargin() const;
    wxString GetFooterText(wxRichTextOddEvenPage page = wxRICHTEXT_PAGE_EVEN,
                           wxRichTextPageLocation location = wxRICHTEXT_PAGE_CENTRE) const;
    int GetHeaderMargin() const;
    wxString GetHeaderText(wxRichTextOddEvenPage page = wxRICHTEXT_PAGE_EVEN,
                           wxRichTextPageLocation location = wxRICHTEXT_PAGE_CENTRE) const;
    bool GetShowOnFirstPage() const;
    wxString GetText(int headerFooter, wxRichTextOddEvenPage page,
                     wxRichTextPageLocation location) const;
    const wxColour& GetTextColour() const;
    void Init();
    void SetFont(const wxFont& font);
    void SetFooterText(const wxString& text,
                       wxRichTextOddEvenPage page = wxRICHTEXT_PAGE_ALL,
                       wxRichTextPageLocation location = wxRICHTEXT_PAGE_CENTRE);
    void SetHeaderText(const wxString& text,
                       wxRichTextOddEvenPage page = wxRICHTEXT_PAGE_ALL,
                       wxRichTextPageLocation location = wxRICHTEXT_PAGE_CENTRE);
    void SetMargins(int headerMargin, int footerMargin);
    void SetShowOnFirstPage(bool showOnFirstPage);
    void SetText(const wxString& text, int headerFooter,
                 wxRichTextOddEvenPage page,
                 wxRichTextPageLocation location);
    void SetTextColour(const wxColour& col);
    void operator=(const wxRichTextHeaderFooterData& data);
};
WXGO_DECL_TYPECONV(RichTextPrintout)
class wxRichTextPrintout : public wxPrintout
{
public:
    wxRichTextPrintout(const wxString& title = "Printout");
    void CalculateScaling(wxDC* dc, wxRect& textRect,
                          wxRect& headerRect,
                          wxRect& footerRect);
    const wxRichTextHeaderFooterData& GetHeaderFooterData() const;
    virtual void GetPageInfo(int* minPage, int* maxPage, int* selPageFrom,
                             int* selPageTo);
    wxRichTextBuffer* GetRichTextBuffer() const;
    virtual bool HasPage(int page);
    virtual void OnPreparePrinting();
    virtual bool OnPrintPage(int page);
    void SetHeaderFooterData(const wxRichTextHeaderFooterData& data);
    void SetMargins(int top = 254, int bottom = 254, int left = 254,
                    int right = 254);
    void SetRichTextBuffer(wxRichTextBuffer* buffer);
};
WXGO_DECL_TYPECONV(RichTextPrinting)
class wxRichTextPrinting : public wxObject
{
public:
    wxRichTextPrinting(const wxString& name = "Printing",
                       wxWindow* parentWindow = NULL);
    wxString GetFooterText(wxRichTextOddEvenPage page = wxRICHTEXT_PAGE_EVEN,
                           wxRichTextPageLocation location = wxRICHTEXT_PAGE_CENTRE) const;
    const wxRichTextHeaderFooterData& GetHeaderFooterData() const;
    wxString GetHeaderText(wxRichTextOddEvenPage page = wxRICHTEXT_PAGE_EVEN,
                           wxRichTextPageLocation location = wxRICHTEXT_PAGE_CENTRE) const;
    wxPageSetupDialogData* GetPageSetupData();
    wxWindow* GetParentWindow() const;
    const wxRect& GetPreviewRect() const;
    wxPrintData* GetPrintData();
    const wxString& GetTitle() const;
    void PageSetup();
    bool PreviewBuffer(const wxRichTextBuffer& buffer);
    bool PreviewFile(const wxString& richTextFile);
    bool PrintBuffer(const wxRichTextBuffer& buffer, bool showPrintDialog = true);
    bool PrintFile(const wxString& richTextFile, bool showPrintDialog = true);
    void SetFooterText(const wxString& text,
                       wxRichTextOddEvenPage page = wxRICHTEXT_PAGE_ALL,
                       wxRichTextPageLocation location = wxRICHTEXT_PAGE_CENTRE);
    void SetHeaderFooterData(const wxRichTextHeaderFooterData& data);
    void SetHeaderFooterFont(const wxFont& font);
    void SetHeaderFooterTextColour(const wxColour& colour);
    void SetHeaderText(const wxString& text,
                       wxRichTextOddEvenPage page = wxRICHTEXT_PAGE_ALL,
                       wxRichTextPageLocation location = wxRICHTEXT_PAGE_CENTRE);
    void SetPageSetupData(const wxPageSetupDialogData& pageSetupData);
    void SetParentWindow(wxWindow* parent);
    void SetPreviewRect(const wxRect& rect);
    void SetPrintData(const wxPrintData& printData);
    void SetShowOnFirstPage(bool show);
    void SetTitle(const wxString& title);
};