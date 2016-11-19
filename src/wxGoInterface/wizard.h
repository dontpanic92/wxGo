#define wxWIZARD_EX_HELPBUTTON   0x00000010
#define wxWIZARD_VALIGN_TOP       0x01
#define wxWIZARD_VALIGN_CENTRE    0x02
#define wxWIZARD_VALIGN_BOTTOM    0x04
#define wxWIZARD_HALIGN_LEFT      0x08
#define wxWIZARD_HALIGN_CENTRE    0x10
#define wxWIZARD_HALIGN_RIGHT     0x20
#define wxWIZARD_TILE             0x40
WXGO_DECL_TYPECONV(WizardPage)
class wxWizardPage : public wxPanel
{
public:
    wxWizardPage();
    wxWizardPage(wxWizard* parent,
                 const wxBitmap& bitmap = wxNullBitmap);
    bool Create(wxWizard *parent,
                const wxBitmap& bitmap = wxNullBitmap);
    virtual wxBitmap GetBitmap() const;
    virtual wxWizardPage* GetNext() const = 0;
    virtual wxWizardPage* GetPrev() const = 0;
};
WXGO_DECL_TYPECONV(WizardEvent)
class wxWizardEvent : public wxNotifyEvent
{
public:
    wxWizardEvent(wxEventType type = wxEVT_NULL, int id = wxID_ANY,
                  bool direction = true, wxWizardPage* page = 0);
    bool GetDirection() const;
    wxWizardPage* GetPage() const;
};
%constant wxEventType wxEVT_WIZARD_PAGE_CHANGED;
%constant wxEventType wxEVT_WIZARD_PAGE_CHANGING;
%constant wxEventType wxEVT_WIZARD_CANCEL;
%constant wxEventType wxEVT_WIZARD_HELP;
%constant wxEventType wxEVT_WIZARD_FINISHED;
%constant wxEventType wxEVT_WIZARD_PAGE_SHOWN;
%constant wxEventType wxEVT_WIZARD_BEFORE_PAGE_CHANGED;
WXGO_DECL_TYPECONV(WizardPageSimple)
class wxWizardPageSimple : public wxWizardPage
{
public:
    wxWizardPageSimple();
    wxWizardPageSimple(wxWizard* parent,
                       wxWizardPage* prev = NULL,
                       wxWizardPage* next = NULL,
                       const wxBitmap& bitmap = wxNullBitmap);
    bool Create(wxWizard *parent = NULL,
                wxWizardPage *prev = NULL,
                wxWizardPage *next = NULL,
                const wxBitmap& bitmap = wxNullBitmap);
    wxWizardPageSimple& Chain(wxWizardPageSimple* next);
    void SetNext(wxWizardPage* next);
    void SetPrev(wxWizardPage* prev);
};
WXGO_DECL_TYPECONV(Wizard)
class wxWizard : public wxDialog
{
public:
    wxWizard();
    wxWizard(wxWindow* parent, int id = wxID_ANY,
             const wxString& title = wxEmptyString,
             const wxBitmap& bitmap = wxNullBitmap,
             const wxPoint& pos = wxDefaultPosition,
             long style = wxDEFAULT_DIALOG_STYLE);
    bool Create(wxWindow* parent, int id = wxID_ANY,
                const wxString& title = wxEmptyString,
                const wxBitmap& bitmap = wxNullBitmap,
                const wxPoint& pos = wxDefaultPosition, long style = wxDEFAULT_DIALOG_STYLE);
    virtual void FitToPage(const wxWizardPage* firstPage);
    const wxBitmap& GetBitmap() const;
    const wxColour& GetBitmapBackgroundColour() const;
    int GetBitmapPlacement() const;
    virtual wxWizardPage* GetCurrentPage() const;
    int GetMinimumBitmapWidth() const;
    virtual wxSizer* GetPageAreaSizer() const;
    virtual wxSize GetPageSize() const;
    virtual bool HasNextPage(wxWizardPage* page);
    virtual bool HasPrevPage(wxWizardPage* page);
    virtual bool RunWizard(wxWizardPage* firstPage);
    void SetBitmap(const wxBitmap& bitmap);
    void SetBitmapBackgroundColour(const wxColour& colour);
    void SetBitmapPlacement(int placement);
    virtual void SetBorder(int border);
    void SetMinimumBitmapWidth(int width);
    virtual void SetPageSize(const wxSize& sizePage);
};