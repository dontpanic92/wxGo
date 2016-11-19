WXGO_DECL_TYPECONV(PageSetupDialogData)
class wxPageSetupDialogData : public wxObject
{
public:
    wxPageSetupDialogData();
    wxPageSetupDialogData(const wxPageSetupDialogData& data);
    wxPageSetupDialogData(const wxPrintData& printData);
    virtual ~wxPageSetupDialogData();
    void EnableHelp(bool flag);
    void EnableMargins(bool flag);
    void EnableOrientation(bool flag);
    void EnablePaper(bool flag);
    void EnablePrinter(bool flag);
    bool GetDefaultInfo() const;
    bool GetDefaultMinMargins() const;
    bool GetEnableHelp() const;
    bool GetEnableMargins() const;
    bool GetEnableOrientation() const;
    bool GetEnablePaper() const;
    bool GetEnablePrinter() const;
    wxPoint GetMarginBottomRight() const;
    wxPoint GetMarginTopLeft() const;
    wxPoint GetMinMarginBottomRight() const;
    wxPoint GetMinMarginTopLeft() const;
    wxPaperSize GetPaperId() const;
    wxSize GetPaperSize() const;
    wxPrintData& GetPrintData();
    bool IsOk() const;
    void SetDefaultInfo(bool flag);
    void SetDefaultMinMargins(bool flag);
    void SetMarginBottomRight(const wxPoint& pt);
    void SetMarginTopLeft(const wxPoint& pt);
    void SetMinMarginBottomRight(const wxPoint& pt);
    void SetMinMarginTopLeft(const wxPoint& pt);
    void SetPaperId(wxPaperSize id);
    void SetPaperSize(const wxSize& size);
    void SetPrintData(const wxPrintData& printData);
    wxPageSetupDialogData& operator =(const wxPrintData& data);
    wxPageSetupDialogData& operator =(const wxPageSetupDialogData& data);
};
%typedef int wxPrintBin;
#define wxPRINTBIN_DEFAULT 0
#define wxPRINTBIN_ONLYONE wxPRINTBIN_DEFAULT + 1
#define wxPRINTBIN_LOWER wxPRINTBIN_ONLYONE + 1
#define wxPRINTBIN_MIDDLE wxPRINTBIN_LOWER + 1
#define wxPRINTBIN_MANUAL wxPRINTBIN_MIDDLE + 1
#define wxPRINTBIN_ENVELOPE wxPRINTBIN_MANUAL + 1
#define wxPRINTBIN_ENVMANUAL wxPRINTBIN_ENVELOPE + 1
#define wxPRINTBIN_AUTO wxPRINTBIN_ENVMANUAL + 1
#define wxPRINTBIN_TRACTOR wxPRINTBIN_AUTO + 1
#define wxPRINTBIN_SMALLFMT wxPRINTBIN_TRACTOR + 1
#define wxPRINTBIN_LARGEFMT wxPRINTBIN_SMALLFMT + 1
#define wxPRINTBIN_LARGECAPACITY wxPRINTBIN_LARGEFMT + 1
#define wxPRINTBIN_CASSETTE wxPRINTBIN_LARGECAPACITY + 1
#define wxPRINTBIN_FORMSOURCE wxPRINTBIN_CASSETTE + 1
#define wxPRINTBIN_USER wxPRINTBIN_FORMSOURCE + 1
WXGO_DECL_TYPECONV(PrintData)
class wxPrintData : public wxObject
{
public:
    wxPrintData();
    wxPrintData(const wxPrintData& data);
    virtual ~wxPrintData();
    wxPrintBin GetBin() const;
    bool GetCollate() const;
    bool GetColour() const;
    wxDuplexMode GetDuplex() const;
    int GetNoCopies() const;
    wxPrintOrientation GetOrientation() const;
    wxPaperSize GetPaperId() const;
    const wxString& GetPrinterName() const;
    wxPrintQuality GetQuality() const;
    bool IsOk() const;
    void SetBin(wxPrintBin flag);
    void SetCollate(bool flag);
    void SetColour(bool flag);
    void SetDuplex(wxDuplexMode mode);
    void SetNoCopies(int n);
    void SetOrientation(wxPrintOrientation orientation);
    void SetPaperId(wxPaperSize paperId);
    void SetPaperSize(const wxSize& size);
    void SetPrinterName(const wxString& printerName);
    void SetQuality(wxPrintQuality quality);
    wxPrintData& operator =(const wxPrintData& data);
    wxString GetFilename() const;
    void SetFilename( const wxString &filename );
    wxPrintMode GetPrintMode() const ;
    void SetPrintMode(wxPrintMode printMode) ;
};
WXGO_DECL_TYPECONV(PrintDialogData)
class wxPrintDialogData : public wxObject
{
public:
    wxPrintDialogData();
    wxPrintDialogData(const wxPrintDialogData& dialogData);
    wxPrintDialogData(const wxPrintData& printData);
    virtual ~wxPrintDialogData();
    void EnableHelp(bool flag);
    void EnablePageNumbers(bool flag);
    void EnablePrintToFile(bool flag);
    void EnableSelection(bool flag);
    bool GetAllPages() const;
    bool GetCollate() const;
    int GetFromPage() const;
    int GetMaxPage() const;
    int GetMinPage() const;
    int GetNoCopies() const;
    wxPrintData& GetPrintData();
    bool GetPrintToFile() const;
    bool GetSelection() const;
    int GetToPage() const;
    bool IsOk() const;
    void SetCollate(bool flag);
    void SetFromPage(int page);
    void SetMaxPage(int page);
    void SetMinPage(int page);
    void SetNoCopies(int n);
    void SetPrintData(const wxPrintData& printData);
    void SetPrintToFile(bool flag);
    void SetSelection(bool flag);
    void SetToPage(int page);
    void operator =(const wxPrintData& data);
    void operator =(const wxPrintDialogData& data);
};