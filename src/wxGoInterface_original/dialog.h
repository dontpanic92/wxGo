enum wxDialogLayoutAdaptationMode
{
    wxDIALOG_ADAPTATION_MODE_DEFAULT = 0,   
    wxDIALOG_ADAPTATION_MODE_ENABLED = 1,   
    wxDIALOG_ADAPTATION_MODE_DISABLED = 2   
};
#define wxDIALOG_NO_PARENT      0x00000020  
#define wxDEFAULT_DIALOG_STYLE  (wxCAPTION | wxSYSTEM_MENU | wxCLOSE_BOX)
#define wxDIALOG_ADAPTATION_NONE             0  
#define wxDIALOG_ADAPTATION_STANDARD_SIZER   1  
#define wxDIALOG_ADAPTATION_ANY_SIZER        2  
#define wxDIALOG_ADAPTATION_LOOSE_BUTTONS    3  
class wxDialog : public wxTopLevelWindow
{
public:
    wxDialog();
    wxDialog(wxWindow* parent, wxWindowID id, const wxString& title,
             const wxPoint& pos = wxDefaultPosition,
             const wxSize& size = wxDefaultSize,
             long style = wxDEFAULT_DIALOG_STYLE,
             const wxString& name = wxDialogNameStr);
    virtual ~wxDialog();
    void AddMainButtonId(wxWindowID id);
    virtual bool CanDoLayoutAdaptation();
    void Centre(int direction = wxBOTH);
    bool Create(wxWindow* parent, wxWindowID id, const wxString& title,
                const wxPoint& pos = wxDefaultPosition,
                const wxSize& size = wxDefaultSize,
                long style = wxDEFAULT_DIALOG_STYLE,
                const wxString& name = wxDialogNameStr);
    wxSizer* CreateButtonSizer(long flags);
    wxSizer* CreateSeparatedButtonSizer(long flags);
    wxSizer *CreateSeparatedSizer(wxSizer *sizer);
    wxStdDialogButtonSizer* CreateStdDialogButtonSizer(long flags);
    wxSizer *CreateTextSizer( const wxString& message );
    virtual bool DoLayoutAdaptation();
    static void EnableLayoutAdaptation(bool enable);
    virtual void EndModal(int retCode);
    int GetAffirmativeId() const;
    virtual wxWindow* GetContentWindow() const;
    int GetEscapeId() const;
    bool GetLayoutAdaptationDone() const;
    int GetLayoutAdaptationLevel() const;
    wxDialogLayoutAdaptationMode GetLayoutAdaptationMode() const;
    static wxDialogLayoutAdapter* GetLayoutAdapter();
    const wxArrayInt& GetMainButtonIds();
    int GetReturnCode() const;
    virtual void Iconize(bool iconize = true);
    virtual bool IsIconized() const;
    static bool IsLayoutAdaptationEnabled();
    bool IsMainButtonId(wxWindowID id) const;
    virtual bool IsModal() const;
    void SetAffirmativeId(int id);
    void SetEscapeId(int id);
    void SetIcon(const wxIcon& icon);
    void SetIcons(const wxIconBundle& icons);
    void SetLayoutAdaptationDone(bool done);
    void SetLayoutAdaptationLevel(int level);
    void SetLayoutAdaptationMode(wxDialogLayoutAdaptationMode mode);
    static wxDialogLayoutAdapter* SetLayoutAdapter(wxDialogLayoutAdapter* adapter);
    void SetReturnCode(int retCode);
    virtual bool Show(bool show = 1);
    virtual int ShowModal();
    void ShowWindowModal();
};

class wxDialogLayoutAdapter
{
public:
    wxDialogLayoutAdapter();
    virtual bool CanDoLayoutAdaptation(wxDialog* dialog) = 0;
    virtual bool DoLayoutAdaptation(wxDialog* dialog) = 0;
};

class wxWindowModalDialogEvent  : public wxCommandEvent
{
public:
    wxWindowModalDialogEvent (wxEventType commandType = wxEVT_NULL, int id = 0);
    wxDialog *GetDialog() const;
    int GetReturnCode() const;
    virtual wxEvent *Clone() const;
};
