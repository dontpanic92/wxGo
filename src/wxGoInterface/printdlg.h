WXGO_DECL_TYPECONV(PrintDialog)
class wxPrintDialog : public wxObject
{
public:
    wxPrintDialog(wxWindow* parent, wxPrintDialogData* data = NULL);
    wxPrintDialog(wxWindow *parent, wxPrintData* data);
    virtual ~wxPrintDialog();
    virtual wxDC* GetPrintDC();
    virtual wxPrintDialogData& GetPrintDialogData();
    virtual wxPrintData& GetPrintData();
    virtual int ShowModal();
};
WXGO_DECL_TYPECONV(PageSetupDialog)
class wxPageSetupDialog : public wxObject
{
public:
    wxPageSetupDialog(wxWindow* parent, wxPageSetupDialogData* data = NULL);
    virtual ~wxPageSetupDialog();
    wxPageSetupDialogData& GetPageSetupData();
    int ShowModal();
};