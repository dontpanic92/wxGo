WXGO_DECL_TYPECONV(PrinterDC)
class wxPrinterDC : public wxDC
{
public:
    wxPrinterDC(const wxPrintData& printData);
    wxRect GetPaperRect() const;
};