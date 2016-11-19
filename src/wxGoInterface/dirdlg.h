#define wxDD_CHANGE_DIR         0x0100
#define wxDD_DIR_MUST_EXIST     0x0200
#define wxDD_NEW_DIR_BUTTON     0 
#define wxDD_DEFAULT_STYLE      (wxDEFAULT_DIALOG_STYLE|wxRESIZE_BORDER)
const char wxDirDialogDefaultFolderStr[] = "/";
const char wxDirSelectorPromptStr[] = "Select a directory";
const char wxDirDialogNameStr[] = "wxDirCtrl";
WXGO_DECL_TYPECONV(DirDialog)
class wxDirDialog : public wxDialog
{
public:
    wxDirDialog(wxWindow* parent,
                const wxString& message = wxDirSelectorPromptStr,
                const wxString& defaultPath = wxEmptyString,
                long style = wxDD_DEFAULT_STYLE,
                const wxPoint& pos = wxDefaultPosition,
                const wxSize& size = wxDefaultSize,
                const wxString& name = wxDirDialogNameStr);
    virtual ~wxDirDialog();
    virtual wxString GetMessage() const;
    virtual wxString GetPath() const;
    virtual void SetMessage(const wxString& message);
    virtual void SetPath(const wxString& path);
    int ShowModal();
};
wxString wxDirSelector(const wxString& message = wxDirSelectorPromptStr,
                       const wxString& default_path = wxEmptyString,
                       long style = 0,
                       const wxPoint& pos = wxDefaultPosition,
                       wxWindow* parent = NULL);