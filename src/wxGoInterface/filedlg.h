enum
{
    wxFD_OPEN              = 0x0001,
    wxFD_SAVE              = 0x0002,
    wxFD_OVERWRITE_PROMPT  = 0x0004,
    wxFD_FILE_MUST_EXIST   = 0x0010,
    wxFD_MULTIPLE          = 0x0020,
    wxFD_CHANGE_DIR        = 0x0080,
    wxFD_PREVIEW           = 0x0100
};
#define wxFD_DEFAULT_STYLE      wxFD_OPEN
const char wxFileSelectorDefaultWildcardStr[];
WXGO_DECL_TYPECONV(FileDialog)
class wxFileDialog : public wxDialog
{
public:
    wxFileDialog(wxWindow* parent,
                 const wxString& message = wxFileSelectorPromptStr,
                 const wxString& defaultDir = wxEmptyString,
                 const wxString& defaultFile = wxEmptyString,
                 const wxString& wildcard = wxFileSelectorDefaultWildcardStr,
                 long style = wxFD_DEFAULT_STYLE,
                 const wxPoint& pos = wxDefaultPosition,
                 const wxSize& size = wxDefaultSize,
                 const wxString& name = wxFileDialogNameStr);
    virtual ~wxFileDialog();
    virtual wxString GetCurrentlySelectedFilename() const;
    virtual wxString GetDirectory() const;
    wxWindow* GetExtraControl() const;
    virtual wxString GetFilename() const;
    virtual void GetFilenames(wxArrayString& filenames) const;
    virtual int GetFilterIndex() const;
    virtual wxString GetMessage() const;
    virtual wxString GetPath() const;
    virtual void GetPaths(wxArrayString& paths) const;
    virtual wxString GetWildcard() const;
    virtual void SetDirectory(const wxString& directory);
    typedef wxWindow *(*ExtraControlCreatorFunction)(wxWindow*);
    bool SetExtraControlCreator(ExtraControlCreatorFunction creator);
    virtual void SetFilename(const wxString& setfilename);
    virtual void SetFilterIndex(int filterIndex);
    virtual void SetMessage(const wxString& message);
    virtual void SetPath(const wxString& path);
    virtual void SetWildcard(const wxString& wildCard);
    virtual int ShowModal();
};
wxString wxFileSelector(const wxString& message,
                        const wxString& default_path = wxEmptyString,
                        const wxString& default_filename = wxEmptyString,
                        const wxString& default_extension = wxEmptyString,
                        const wxString& wildcard = wxFileSelectorDefaultWildcardStr,
                        int flags = 0,
                        wxWindow* parent = NULL,
                        int x = wxDefaultCoord,
                        int y = wxDefaultCoord);
wxString wxFileSelectorEx(const wxString& message = wxFileSelectorPromptStr,
                          const wxString& default_path = wxEmptyString,
                          const wxString& default_filename = wxEmptyString,
                          int *indexDefaultExtension = NULL,
                          const wxString& wildcard = wxFileSelectorDefaultWildcardStr,
                          int flags = 0,
                          wxWindow *parent = NULL,
                          int x = wxDefaultCoord,
                          int y = wxDefaultCoord);
wxString wxLoadFileSelector(const wxString& what,
                            const wxString& extension,
                            const wxString& default_name = wxEmptyString,
                            wxWindow *parent = NULL);
wxString wxSaveFileSelector(const wxString& what,
                            const wxString& extension,
                            const wxString& default_name = wxEmptyString,
                            wxWindow *parent = NULL);