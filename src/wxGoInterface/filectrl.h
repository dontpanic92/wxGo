enum
{
    wxFC_OPEN              = 0x0001,
    wxFC_SAVE              = 0x0002,
    wxFC_MULTIPLE          = 0x0004,
    wxFC_NOSHOWHIDDEN      = 0x0008
};
#define wxFC_DEFAULT_STYLE wxFC_OPEN
WXGO_DECL_TYPECONV(FileCtrl)
class wxFileCtrl : public wxControl
{
public:
    wxFileCtrl();
    wxFileCtrl(wxWindow* parent, wxWindowID id,
               const wxString& defaultDirectory = wxEmptyString,
               const wxString& defaultFilename = wxEmptyString,
               const wxString& wildCard = wxFileSelectorDefaultWildcardStr,
               long style = wxFC_DEFAULT_STYLE,
               const wxPoint& pos = wxDefaultPosition,
               const wxSize& size = wxDefaultSize,
               const wxString& name = wxFileCtrlNameStr);
    bool Create(wxWindow* parent, wxWindowID id,
                const wxString& defaultDirectory = wxEmptyString,
                const wxString& defaultFilename = wxEmptyString,
                const wxString& wildCard = wxFileSelectorDefaultWildcardStr,
                long style = wxFC_DEFAULT_STYLE, const wxPoint& pos = wxDefaultPosition,
                const wxSize& size = wxDefaultSize,
                const wxString& name = wxFileCtrlNameStr);
    virtual wxString GetDirectory() const;
    virtual wxString GetFilename() const;
    virtual void GetFilenames(wxArrayString& filenames) const;
    virtual int GetFilterIndex() const;
    virtual wxString GetPath() const;
    virtual void GetPaths(wxArrayString& paths) const;
    virtual wxString GetWildcard() const;
    virtual bool SetDirectory(const wxString& directory);
    virtual bool SetFilename(const wxString& filename);
    virtual bool SetPath(const wxString& path);
    virtual void SetFilterIndex(int filterIndex);
    virtual void SetWildcard(const wxString& wildCard);
    virtual void ShowHidden(bool show);
};
%constant wxEventType wxEVT_FILECTRL_SELECTIONCHANGED;
%constant wxEventType wxEVT_FILECTRL_FILEACTIVATED;
%constant wxEventType wxEVT_FILECTRL_FOLDERCHANGED;
%constant wxEventType wxEVT_FILECTRL_FILTERCHANGED;
WXGO_DECL_TYPECONV(FileCtrlEvent)
class wxFileCtrlEvent : public wxCommandEvent
{
public:
    wxFileCtrlEvent(wxEventType type, wxObject *evtObject, int id);
    wxString GetDirectory() const;
    wxString GetFile() const;
    wxArrayString GetFiles() const;
    int GetFilterIndex() const;
    void SetFiles(const wxArrayString& files);
    void SetDirectory( const wxString &directory );
    void SetFilterIndex(int index);
};