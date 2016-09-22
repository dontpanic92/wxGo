WXGO_DECL_TYPECONV(GCDC)
class wxGCDC: public wxDC
{
public:
    wxGCDC( const wxWindowDC& windowDC );
    wxGCDC( const wxMemoryDC& memoryDC );
    wxGCDC( const wxPrinterDC& printerDC );
    wxGCDC(wxGraphicsContext* context);
#ifdef __WXMSW__
    wxGCDC( const wxEnhMetaFileDC& emfDC );
#endif
    wxGCDC();
    virtual ~wxGCDC();
    wxGraphicsContext* GetGraphicsContext() const;
    void SetGraphicsContext( wxGraphicsContext* ctx );
};