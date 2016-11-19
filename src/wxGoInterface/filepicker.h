#define wxFLP_OPEN                    0x0400
#define wxFLP_SAVE                    0x0800
#define wxFLP_OVERWRITE_PROMPT        0x1000
#define wxFLP_FILE_MUST_EXIST         0x2000
#define wxFLP_CHANGE_DIR              0x4000
#define wxFLP_SMALL                   wxPB_SMALL
#define wxFLP_USE_TEXTCTRL            (wxPB_USE_TEXTCTRL)
#define wxFLP_DEFAULT_STYLE           (wxFLP_OPEN|wxFLP_FILE_MUST_EXIST)
#define wxDIRP_DIR_MUST_EXIST         0x0008
#define wxDIRP_CHANGE_DIR             0x0010
#define wxDIRP_SMALL                  wxPB_SMALL
#define wxDIRP_USE_TEXTCTRL           (wxPB_USE_TEXTCTRL)
#define wxDIRP_DEFAULT_STYLE          (wxDIRP_DIR_MUST_EXIST)
%constant wxEventType wxEVT_FILEPICKER_CHANGED;
%constant wxEventType wxEVT_DIRPICKER_CHANGED;
WXGO_DECL_TYPECONV(FilePickerCtrl)
class wxFilePickerCtrl : public wxPickerBase
{
public:
    wxFilePickerCtrl();
    wxFilePickerCtrl(wxWindow* parent, wxWindowID id,
                     const wxString& path = wxEmptyString,
                     const wxString& message = wxFileSelectorPromptStr,
                     const wxString& wildcard = wxFileSelectorDefaultWildcardStr,
                     const wxPoint& pos = wxDefaultPosition,
                     const wxSize& size = wxDefaultSize,
                     long style = wxFLP_DEFAULT_STYLE,
                     const wxValidator& validator = wxDefaultValidator,
                     const wxString& name = wxFilePickerCtrlNameStr);
    bool Create(wxWindow* parent, wxWindowID id,
                const wxString& path = wxEmptyString,
                const wxString& message = wxFileSelectorPromptStr,
                const wxString& wildcard = wxFileSelectorDefaultWildcardStr,
                const wxPoint& pos = wxDefaultPosition,
                const wxSize& size = wxDefaultSize,
                long style = wxFLP_DEFAULT_STYLE,
                const wxValidator& validator = wxDefaultValidator,
                const wxString& name = wxFilePickerCtrlNameStr);
    wxFileName GetFileName() const;
    wxString GetPath() const;
    void SetFileName(const wxFileName& filename);
    void SetInitialDirectory(const wxString& dir);
    void SetPath(const wxString& filename);
};
WXGO_DECL_TYPECONV(DirPickerCtrl)
class wxDirPickerCtrl : public wxPickerBase
{
public:
    wxDirPickerCtrl();
    wxDirPickerCtrl(wxWindow* parent, wxWindowID id,
                    const wxString& path = wxEmptyString,
                    const wxString& message = wxDirSelectorPromptStr,
                    const wxPoint& pos = wxDefaultPosition,
                    const wxSize& size = wxDefaultSize,
                    long style = wxDIRP_DEFAULT_STYLE,
                    const wxValidator& validator = wxDefaultValidator,
                    const wxString& name = wxDirPickerCtrlNameStr);
    bool Create(wxWindow* parent, wxWindowID id,
                const wxString& path = wxEmptyString,
                const wxString& message = wxDirSelectorPromptStr,
                const wxPoint& pos = wxDefaultPosition,
                const wxSize& size = wxDefaultSize,
                long style = wxDIRP_DEFAULT_STYLE,
                const wxValidator& validator = wxDefaultValidator,
                const wxString& name = wxDirPickerCtrlNameStr);
    wxFileName GetDirName() const;
    wxString GetPath() const;
    void SetDirName(const wxFileName& dirname);
    void SetInitialDirectory(const wxString& dir);
    void SetPath(const wxString& dirname);
};
WXGO_DECL_TYPECONV(FileDirPickerEvent)
class wxFileDirPickerEvent : public wxCommandEvent
{
public:
    wxFileDirPickerEvent();
    wxFileDirPickerEvent(wxEventType type, wxObject* generator,
                         int id,
                         const wxString& path);
    wxString GetPath() const;
    void SetPath(const wxString& path);
};