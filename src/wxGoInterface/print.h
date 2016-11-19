%typedef int wxPrinterError;
#define wxPRINTER_NO_ERROR  0
#define wxPRINTER_CANCELLED wxPRINTER_NO_ERROR  + 1
#define wxPRINTER_ERROR wxPRINTER_CANCELLED + 1
#define wxPREVIEW_PRINT        1
#define wxPREVIEW_PREVIOUS     2
#define wxPREVIEW_NEXT         4
#define wxPREVIEW_ZOOM         8
#define wxPREVIEW_FIRST       16
#define wxPREVIEW_LAST        32
#define wxPREVIEW_GOTO        64
#define wxPREVIEW_DEFAULT  (wxPREVIEW_PREVIOUS|wxPREVIEW_NEXT|wxPREVIEW_ZOOM\
                            |wxPREVIEW_FIRST|wxPREVIEW_GOTO|wxPREVIEW_LAST)
#define wxID_PREVIEW_CLOSE      1
#define wxID_PREVIEW_NEXT       2
#define wxID_PREVIEW_PREVIOUS   3
#define wxID_PREVIEW_PRINT      4
#define wxID_PREVIEW_ZOOM       5
#define wxID_PREVIEW_FIRST      6
#define wxID_PREVIEW_LAST       7
#define wxID_PREVIEW_GOTO       8
#define wxID_PREVIEW_ZOOM_IN    9
#define wxID_PREVIEW_ZOOM_OUT   10
WXGO_DECL_TYPECONV(PreviewControlBar)
class wxPreviewControlBar : public wxPanel
{
public:
    wxPreviewControlBar(wxPrintPreview* preview,
                        long buttons,
                        wxWindow* parent,
                        const wxPoint& pos = wxDefaultPosition,
                        const wxSize& size = wxDefaultSize,
                        long style = 0,
                        const wxString& name = "panel");
    virtual ~wxPreviewControlBar();
    virtual void CreateButtons();
    virtual wxPrintPreviewBase* GetPrintPreview() const;
    virtual int GetZoomControl();
    virtual void SetZoomControl(int percent);
};
WXGO_DECL_TYPECONV(PreviewCanvas)
class wxPreviewCanvas : public wxScrolledWindow
{
public:
    wxPreviewCanvas(wxPrintPreview* preview, wxWindow* parent,
                    const wxPoint& pos = wxDefaultPosition,
                    const wxSize& size = wxDefaultSize,
                    long style = 0,
                    const wxString& name = "canvas");
    virtual ~wxPreviewCanvas();
    void OnPaint(wxPaintEvent& event);
};
%typedef int wxPreviewFrameModalityKind;
#define wxPreviewFrame_AppModal 0
#define wxPreviewFrame_WindowModal wxPreviewFrame_AppModal + 1
#define wxPreviewFrame_NonModal wxPreviewFrame_WindowModal + 1
WXGO_DECL_TYPECONV(PreviewFrame)
class wxPreviewFrame : public wxFrame
{
public:
    wxPreviewFrame(wxPrintPreviewBase* preview, wxWindow* parent,
                   const wxString& title = "Print Preview",
                   const wxPoint& pos = wxDefaultPosition,
                   const wxSize& size = wxDefaultSize,
                   long style = wxDEFAULT_FRAME_STYLE,
                   const wxString& name = wxFrameNameStr);
    virtual ~wxPreviewFrame();
    virtual void CreateCanvas();
    virtual void CreateControlBar();
    virtual void Initialize();
    virtual void InitializeWithModality(wxPreviewFrameModalityKind kind);
    void OnCloseWindow(wxCloseEvent& event);
};
WXGO_DECL_TYPECONV(PrintPreview)
class wxPrintPreview : public wxObject
{
public:
    wxPrintPreview(wxPrintout* printout,
                   wxPrintout* printoutForPrinting = NULL,
                   wxPrintDialogData* data = NULL);
    wxPrintPreview(wxPrintout* printout,
                   wxPrintout* printoutForPrinting,
                   wxPrintData* data);
    ~wxPrintPreview();
    virtual wxPreviewCanvas* GetCanvas() const;
    virtual int GetCurrentPage() const;
    virtual wxFrame* GetFrame() const;
    virtual int GetMaxPage() const;
    virtual int GetMinPage() const;
    virtual wxPrintout* GetPrintout() const;
    virtual wxPrintout* GetPrintoutForPrinting() const;
    virtual bool IsOk() const;
    virtual bool PaintPage(wxPreviewCanvas* canvas, wxDC& dc);
    virtual bool Print(bool prompt);
    virtual bool RenderPage(int pageNum);
    virtual void SetCanvas(wxPreviewCanvas* window);
    virtual bool SetCurrentPage(int pageNum);
    virtual void SetFrame(wxFrame* frame);
    virtual void SetPrintout(wxPrintout* printout);
    virtual void SetZoom(int percent);
};
WXGO_DECL_TYPECONV(Printer)
class wxPrinter : public wxObject
{
public:
    wxPrinter(wxPrintDialogData* data = NULL);
    virtual wxPrintAbortDialog* CreateAbortWindow(wxWindow* parent, wxPrintout* printout);
    bool GetAbort() const;
    static wxPrinterError GetLastError();
    virtual wxPrintDialogData& GetPrintDialogData() const;
    virtual bool Print(wxWindow* parent, wxPrintout* printout,
                       bool prompt = true);
    virtual wxDC* PrintDialog(wxWindow* parent);
    virtual void ReportError(wxWindow* parent, wxPrintout* printout,
                             const wxString& message);
    virtual bool Setup(wxWindow* parent);
};
WXGO_DECL_TYPECONV(Printout)
class wxPrintout : public wxObject
{
public:
    wxPrintout(const wxString& title = "Printout");
    virtual ~wxPrintout();
    void FitThisSizeToPage(const wxSize& imageSize);
    void FitThisSizeToPageMargins(const wxSize& imageSize,
                                  const wxPageSetupDialogData& pageSetupData);
    void FitThisSizeToPaper(const wxSize& imageSize);
    wxDC* GetDC() const;
    wxRect GetLogicalPageMarginsRect(const wxPageSetupDialogData& pageSetupData) const;
    wxRect GetLogicalPageRect() const;
    wxRect GetLogicalPaperRect() const;
    void GetPPIPrinter(int* w, int* h) const;
    void GetPPIScreen(int* w, int* h) const;
    virtual void GetPageInfo(int* minPage, int* maxPage, int* pageFrom,
                             int* pageTo);
    void GetPageSizeMM(int* w, int* h) const;
    void GetPageSizePixels(int* w, int* h) const;
    wxRect GetPaperRectPixels() const;
    virtual wxString GetTitle() const;
    virtual bool HasPage(int pageNum);
    virtual bool IsPreview() const;
    wxPrintPreview *GetPreview() const;
    void MapScreenSizeToDevice();
    void MapScreenSizeToPage();
    void MapScreenSizeToPageMargins(const wxPageSetupDialogData& pageSetupData);
    void MapScreenSizeToPaper();
    void OffsetLogicalOrigin(wxCoord xoff, wxCoord yoff);
    virtual bool OnBeginDocument(int startPage, int endPage);
    virtual void OnBeginPrinting();
    virtual void OnEndDocument();
    virtual void OnEndPrinting();
    virtual void OnPreparePrinting();
    virtual bool OnPrintPage(int pageNum) = 0;
    void SetLogicalOrigin(wxCoord x, wxCoord y);
};
WXGO_DECL_TYPECONV(PrintAbortDialog)
class wxPrintAbortDialog: public wxDialog
{
public:
    wxPrintAbortDialog(wxWindow *parent,
                       const wxString& documentTitle,
                       const wxPoint& pos = wxDefaultPosition,
                       const wxSize& size = wxDefaultSize,
                       long style = wxDEFAULT_DIALOG_STYLE,
                       const wxString& name = "dialog");
    void SetProgress(int currentPage, int totalPages,
                     int currentCopy, int totalCopies);
};