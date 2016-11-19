WXGO_DECL_TYPECONV(HtmlDCRenderer)
class wxHtmlDCRenderer : public wxObject
{
public:
    wxHtmlDCRenderer();
    int GetTotalWidth() const;
    int GetTotalHeight() const;
    int Render(int x, int y, wxArrayInt& known_pagebreaks, int from = 0,
               int dont_render = false, int to = INT_MAX);
    void SetDC(wxDC* dc, double pixel_scale = 1.0);
    void SetFonts(const wxString& normal_face, const wxString& fixed_face,
                  const int* sizes = NULL);
    void SetStandardFonts(int size = -1,
                          const wxString& normal_face = wxEmptyString,
                          const wxString& fixed_face = wxEmptyString);
    void SetHtmlText(const wxString& html,
                     const wxString& basepath = wxEmptyString,
                     bool isdir = true);
    void SetSize(int width, int height);
};
WXGO_DECL_TYPECONV(HtmlEasyPrinting)
class wxHtmlEasyPrinting : public wxObject
{
public:
    wxHtmlEasyPrinting(const wxString& name = "Printing",
                       wxWindow* parentWindow = NULL);
    const wxString& GetName() const;
    wxPageSetupDialogData* GetPageSetupData();
    wxWindow* GetParentWindow() const;
    wxPrintData* GetPrintData();
    void PageSetup();
    bool PreviewFile(const wxString& htmlfile);
    bool PreviewText(const wxString& htmltext,
                     const wxString& basepath = wxEmptyString);
    bool PrintFile(const wxString& htmlfile);
    bool PrintText(const wxString& htmltext,
                   const wxString& basepath = wxEmptyString);
    void SetFonts(const wxString& normal_face, const wxString& fixed_face,
                  const int* sizes = NULL);
    void SetName(const wxString& name);
    void SetStandardFonts(int size = -1,
                          const wxString& normal_face = wxEmptyString,
                          const wxString& fixed_face = wxEmptyString);
    void SetFooter(const wxString& footer, int pg = wxPAGE_ALL);
    void SetHeader(const wxString& header, int pg = wxPAGE_ALL);
    void SetParentWindow(wxWindow* window);
private:
    virtual bool CheckFit(const wxSize& pageArea, const wxSize& docArea) const;
};
enum {
    wxPAGE_ODD,
    wxPAGE_EVEN,
    wxPAGE_ALL
};
WXGO_DECL_TYPECONV(HtmlPrintout)
class wxHtmlPrintout : public wxPrintout
{
public:
    wxHtmlPrintout(const wxString& title = "Printout");
    static void AddFilter(wxHtmlFilter* filter);
    void SetFonts(const wxString& normal_face, const wxString& fixed_face,
                  const int* sizes = NULL);
    void SetFooter(const wxString& footer, int pg = wxPAGE_ALL);
    void SetHeader(const wxString& header, int pg = wxPAGE_ALL);
    void SetHtmlFile(const wxString& htmlfile);
    void SetHtmlText(const wxString& html,
                     const wxString& basepath = wxEmptyString,
                     bool isdir = true);
    void SetMargins(float top = 25.2, float bottom = 25.2,
                    float left = 25.2,
                    float right = 25.2,
                    float spaces = 5);
};