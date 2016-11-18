WXGO_DECL_TYPECONV(FileConfig)
class wxFileConfig : public wxConfigBase
{
public:
    wxFileConfig(const wxString& appName = wxEmptyString,
               const wxString& vendorName = wxEmptyString,
               const wxString& localFilename = wxEmptyString,
               const wxString& globalFilename = wxEmptyString,
               long style = wxCONFIG_USE_LOCAL_FILE | wxCONFIG_USE_GLOBAL_FILE,
               const wxMBConv& conv = wxConvAuto());
    wxFileConfig(wxInputStream& is, const wxMBConv& conv = wxConvAuto());
    static wxFileName GetGlobalFile(const wxString& basename);
    static wxFileName GetLocalFile(const wxString& basename, int style = 0);
    static wxString GetGlobalFileName(const wxString& szFile);
    static wxString GetLocalFileName(const wxString& szFile, int style = 0);
    virtual bool Save(wxOutputStream& os, const wxMBConv& conv = wxConvAuto());
    void SetUmask(int mode);
  virtual void SetPath(const wxString& strPath);
  virtual const wxString& GetPath() const;
  virtual bool GetFirstGroup(wxString& str, long& lIndex) const;
  virtual bool GetNextGroup (wxString& str, long& lIndex) const;
  virtual bool GetFirstEntry(wxString& str, long& lIndex) const;
  virtual bool GetNextEntry (wxString& str, long& lIndex) const;
  virtual size_t GetNumberOfEntries(bool bRecursive = false) const;
  virtual size_t GetNumberOfGroups(bool bRecursive = false) const;
  virtual bool HasGroup(const wxString& strName) const;
  virtual bool HasEntry(const wxString& strName) const;
  virtual bool Flush(bool bCurrentOnly = false);
  virtual bool RenameEntry(const wxString& oldName, const wxString& newName);
  virtual bool RenameGroup(const wxString& oldName, const wxString& newName);
  virtual bool DeleteEntry(const wxString& key, bool bGroupIfEmptyAlso = true);
  virtual bool DeleteGroup(const wxString& szKey);
  virtual bool DeleteAll();
};