WXGO_DECL_TYPECONV(FileHistory)
class wxFileHistory : public wxObject
{
public:
    wxFileHistory(size_t maxFiles = 9, wxWindowID idBase = wxID_FILE1);
    virtual ~wxFileHistory();
    virtual void AddFileToHistory(const wxString& filename);
    virtual void AddFilesToMenu();
    virtual void AddFilesToMenu(wxMenu* menu);
    wxWindowID GetBaseId() const;
    virtual size_t GetCount() const;
    virtual wxString GetHistoryFile(size_t index) const;
    virtual int GetMaxFiles() const;
    const wxList& GetMenus() const;
    virtual void Load(const wxConfigBase& config);
    virtual void RemoveFileFromHistory(size_t i);
    virtual void RemoveMenu(wxMenu* menu);
    virtual void Save(wxConfigBase& config);
    void SetBaseId(wxWindowID baseId);
    virtual void UseMenu(wxMenu* menu);
};