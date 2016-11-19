WXGO_DECL_TYPECONV(HelpProvider)
class wxHelpProvider
{
public:
    virtual ~wxHelpProvider();
    virtual void AddHelp(wxWindowBase* window, const wxString& text);
    virtual void AddHelp(wxWindowID id, const wxString& text);
    static wxHelpProvider* Get();
    virtual wxString GetHelp(const wxWindowBase* window) = 0;
    virtual void RemoveHelp(wxWindowBase* window);
    static wxHelpProvider* Set(wxHelpProvider* helpProvider);
    virtual bool ShowHelp(wxWindowBase* window);
    virtual bool ShowHelpAtPoint(wxWindowBase* window, const wxPoint& point,
                                 wxHelpEvent::Origin origin);
};
WXGO_DECL_TYPECONV(ContextHelp)
class wxContextHelp : public wxObject
{
public:
    wxContextHelp(wxWindow* window = NULL, bool doNow = true);
    virtual ~wxContextHelp();
    bool BeginContextHelp(wxWindow* window);
    bool EndContextHelp();
};
WXGO_DECL_TYPECONV(ContextHelpButton)
class wxContextHelpButton : public wxBitmapButton
{
public:
    wxContextHelpButton(wxWindow* parent,
                        wxWindowID id = wxID_CONTEXT_HELP,
                        const wxPoint& pos = wxDefaultPosition,
                        const wxSize& size = wxDefaultSize,
                        long style = wxBU_AUTODRAW);
};
WXGO_DECL_TYPECONV(SimpleHelpProvider)
class wxSimpleHelpProvider : public wxHelpProvider
{
public:
};
WXGO_DECL_TYPECONV(HelpControllerHelpProvider)
class wxHelpControllerHelpProvider : public wxSimpleHelpProvider
{
public:
    wxHelpControllerHelpProvider(wxHelpControllerBase* hc = NULL);
    wxHelpControllerBase* GetHelpController() const;
    void SetHelpController(wxHelpControllerBase* hc);
};