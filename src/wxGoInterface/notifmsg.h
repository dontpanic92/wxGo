WXGO_DECL_TYPECONV(NotificationMessage)
class wxNotificationMessage : public wxEvtHandler
{
public:
    enum
    {
        Timeout_Auto = -1,  
        Timeout_Never = 0   
    };
    wxNotificationMessage();
    wxNotificationMessage(const wxString& title, const wxString& message = wxEmptyString,
                          wxWindow* parent = NULL, int flags = wxICON_INFORMATION);
    virtual ~wxNotificationMessage();
    bool AddAction(wxWindowID actionid, const wxString &label = wxString());
    virtual bool Close();
    void SetFlags(int flags);
    void SetIcon(const wxIcon& icon);
    void SetMessage(const wxString& message);
    void SetParent(wxWindow* parent);
    void SetTitle(const wxString& title);
    virtual bool Show(int timeout = Timeout_Auto);
#ifdef __WXMSW__
    static wxTaskBarIcon *UseTaskBarIcon(wxTaskBarIcon *icon);
#endif
#ifdef __WXMSW__
    static bool MSWUseToasts(
        const wxString& shortcutPath = wxString(),
        const wxString& appId = wxString());
#endif
};