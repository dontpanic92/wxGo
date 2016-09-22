WXGO_DECL_TYPECONV(RibbonPage)
class wxRibbonPage : public wxRibbonControl
{
public:
    wxRibbonPage();
    wxRibbonPage(wxRibbonBar* parent,
                wxWindowID id = wxID_ANY,
                const wxString& label = wxEmptyString,
                const wxBitmap& icon = wxNullBitmap,
                long style = 0);
    virtual ~wxRibbonPage();
    bool Create(wxRibbonBar* parent,
                wxWindowID id = wxID_ANY,
                const wxString& label = wxEmptyString,
                const wxBitmap& icon = wxNullBitmap,
                long style = 0);
    void SetArtProvider(wxRibbonArtProvider* art);
    wxBitmap& GetIcon();
    void SetSizeWithScrollButtonAdjustment(int x, int y, int width, int height);
    void AdjustRectToIncludeScrollButtons(wxRect* rect) const;
    bool DismissExpandedPanel();
    virtual bool Realize();
    virtual bool ScrollLines(int lines);
    bool ScrollPixels(int pixels);
    bool ScrollSections(int sections);
    wxOrientation GetMajorAxis() const;
};