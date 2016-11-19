%typedef int wxAcceleratorEntryFlags;
#define wxACCEL_NORMAL 0
#define wxACCEL_ALT wxACCEL_NORMAL + 1
#define wxACCEL_CTRL wxACCEL_ALT + 1
#define wxACCEL_SHIFT wxACCEL_CTRL + 1
#define wxACCEL_RAW_CTRL wxACCEL_SHIFT + 1
#define wxACCEL_CMD wxACCEL_RAW_CTRL + 1
WXGO_DECL_TYPECONV(AcceleratorEntry)
class wxAcceleratorEntry
{
public:
    wxAcceleratorEntry(int flags = 0, int keyCode = 0, int cmd = 0,
                       wxMenuItem *item = NULL);
    wxAcceleratorEntry(const wxAcceleratorEntry& entry);
    int GetCommand() const;
    int GetFlags() const;
    int GetKeyCode() const;
    wxMenuItem *GetMenuItem() const;
    void Set(int flags, int keyCode, int cmd, wxMenuItem *item = NULL);
    bool IsOk() const;
    wxString ToString() const;
    wxString ToRawString() const;
    bool FromString(const wxString& str);
    wxAcceleratorEntry& operator=(const wxAcceleratorEntry& entry);
    bool operator==(const wxAcceleratorEntry& entry) const;
    bool operator!=(const wxAcceleratorEntry& entry) const;
};
WXGO_DECL_TYPECONV(AcceleratorTable)
class wxAcceleratorTable : public wxObject
{
public:
    wxAcceleratorTable();
    wxAcceleratorTable(int n, const wxAcceleratorEntry entries[]);
#ifdef __WXMSW__
    wxAcceleratorTable(const wxString& resource);
#endif
    virtual ~wxAcceleratorTable();
    bool IsOk() const;
};
%constant wxAcceleratorTable wxNullAcceleratorTable;