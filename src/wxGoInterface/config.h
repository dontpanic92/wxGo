enum
{
    wxCONFIG_USE_LOCAL_FILE = 1,
    wxCONFIG_USE_GLOBAL_FILE = 2,
    wxCONFIG_USE_RELATIVE_PATH = 4,
    wxCONFIG_USE_NO_ESCAPE_CHARACTERS = 8,
    wxCONFIG_USE_SUBDIR = 16
};
WXGO_DECL_TYPECONV(ConfigBase)
class wxConfigBase : public wxObject
{
public:
    wxConfigBase(const wxString& appName = wxEmptyString,
                 const wxString& vendorName = wxEmptyString,
                 const wxString& localFilename = wxEmptyString,
                 const wxString& globalFilename = wxEmptyString,
                 long style = 0,
                 const wxMBConv& conv = wxConvAuto());
    virtual ~wxConfigBase();
    virtual const wxString& GetPath() const = 0;
    virtual void SetPath(const wxString& strPath) = 0;
    virtual bool GetFirstEntry(wxString& str, long& index) const = 0;
    virtual bool GetFirstGroup(wxString& str, long& index) const = 0;
    virtual bool GetNextEntry(wxString& str, long& index) const = 0;
    virtual bool GetNextGroup(wxString& str, long& index) const = 0;
    virtual size_t GetNumberOfEntries(bool bRecursive = false) const = 0;
    virtual size_t GetNumberOfGroups(bool bRecursive = false) const = 0;
    enum EntryType
    {
        Type_Unknown,
        Type_String,
        Type_Boolean,
        Type_Integer,
        Type_Float
    };
    bool Exists(const wxString& strName) const;
    virtual wxConfigBase::EntryType GetEntryType(const wxString& name) const;
    virtual bool HasEntry(const wxString& strName) const = 0;
    virtual bool HasGroup(const wxString& strName) const = 0;
    wxString GetAppName() const;
    wxString GetVendorName() const;
    virtual bool Flush(bool bCurrentOnly = false) = 0;
    bool Read(const wxString& key, wxString* str,
              const wxString& defaultVal) const;
    const wxString Read(const wxString& key,
                        const wxString& defaultVal) const;
    bool Read(const wxString& key, long* l) const;
    bool Read(const wxString& key, long* l,
              long defaultVal) const;
    bool Read(const wxString& key, double* d) const;
    bool Read(const wxString& key, double* d,
                     double defaultVal) const;
    bool Read(const wxString& key, float* f) const;
    bool Read(const wxString& key, float* f, float defaultVal) const;
    bool Read(const wxString& key, bool* b) const;
    bool Read(const wxString& key, bool* d,
              bool defaultVal) const;
    bool Read(const wxString& key, wxMemoryBuffer* buf) const;
    bool ReadBool(const wxString& key, bool defaultVal) const;
    double ReadDouble(const wxString& key, double defaultVal) const;
    long ReadLong(const wxString& key, long defaultVal) const;
    bool Write(const wxString& key, const wxString& value);
    bool Write(const wxString& key, long value);
    bool Write(const wxString& key, double value);
    bool Write(const wxString& key, bool value);
    bool Write(const wxString& key, const wxMemoryBuffer& buf);
    virtual bool RenameEntry(const wxString& oldName,
                             const wxString& newName) = 0;
    virtual bool RenameGroup(const wxString& oldName,
                             const wxString& newName) = 0;
    virtual bool DeleteAll() = 0;
    virtual bool DeleteEntry(const wxString& key,
                             bool bDeleteGroupIfEmpty = true) = 0;
    virtual bool DeleteGroup(const wxString& key) = 0;
    bool IsExpandingEnvVars() const;
    bool IsRecordingDefaults() const;
    void SetExpandEnvVars(bool bDoIt = true);
    void SetRecordDefaults(bool bDoIt = true);
    static wxConfigBase* Create();
    static void DontCreateOnDemand();
    static wxConfigBase* Get(bool CreateOnDemand = true);
    static wxConfigBase* Set(wxConfigBase* pConfig);
};
WXGO_DECL_TYPECONV(ConfigPathChanger)
class wxConfigPathChanger
{
public:
    wxConfigPathChanger(const wxConfigBase *pContainer, const wxString& strEntry);
    ~wxConfigPathChanger();
    const wxString& Name() const;
    void UpdateIfDeleted();
};