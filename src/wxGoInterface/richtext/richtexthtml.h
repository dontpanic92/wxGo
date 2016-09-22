WXGO_DECL_TYPECONV(RichTextHTMLHandler)
class wxRichTextHTMLHandler : public wxRichTextFileHandler
{
public:
    wxRichTextHTMLHandler(const wxString& name = "HTML",
                          const wxString& ext = "html",
                          int type = wxRICHTEXT_TYPE_HTML);
    void ClearTemporaryImageLocations();
    bool DeleteTemporaryImages();
    static bool DeleteTemporaryImages(int flags,
                                      const wxArrayString& imageLocations);
    wxArrayInt GetFontSizeMapping() const;
    const wxString& GetTempDir() const;
    const wxArrayString& GetTemporaryImageLocations() const;
    static void SetFileCounter(int counter);
    void SetFontSizeMapping(const wxArrayInt& fontSizeMapping);
    void SetTempDir(const wxString& tempDir);
    void SetTemporaryImageLocations(const wxArrayString& locations);
protected:
    virtual bool DoSaveFile(wxRichTextBuffer* buffer, wxOutputStream& stream);
};