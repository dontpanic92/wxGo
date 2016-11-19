#ifndef _WX_WEBKIT_H
#define _WX_WEBKIT_H
WXGO_DECL_TYPECONV(WebKitCtrl)
class wxWebKitCtrl : public wxControl
{
public:
    wxWebKitCtrl();
    wxWebKitCtrl(wxWindow *parent,
                    wxWindowID winid,
                    const wxString& strURL,
                    const wxPoint& pos = wxDefaultPosition,
                    const wxSize& size = wxDefaultSize, long style = 0,
                    const wxValidator& validator = wxDefaultValidator,
                 const wxString& name = wxWebKitCtrlNameStr);
    bool Create(wxWindow *parent,
                wxWindowID winid,
                const wxString& strURL,
                const wxPoint& pos = wxDefaultPosition,
                const wxSize& size = wxDefaultSize, long style = 0,
                const wxValidator& validator = wxDefaultValidator,
                const wxString& name = wxWebKitCtrlNameStr);
    virtual ~wxWebKitCtrl();
    void LoadURL(const wxString &url);
    bool CanGoBack();
    bool CanGoForward();
    bool GoBack();
    bool GoForward();
    void Reload();
    void Stop();
    bool CanGetPageSource();
    wxString GetPageSource();
    void SetPageSource(const wxString& source, const wxString& baseUrl = wxEmptyString);
    wxString GetPageURL();
    void SetPageTitle(const wxString& title);
    wxString GetPageTitle();
    void SetTitle(const wxString& title);
    wxString GetTitle();
    wxString GetSelection();
    bool CanIncreaseTextSize();
    void IncreaseTextSize();
    bool CanDecreaseTextSize();
    void DecreaseTextSize();
    void Print(bool showPrompt = false);
    void MakeEditable(bool enable = true);
    bool IsEditable();
    wxString RunScript(const wxString& javascript);
    void SetScrollPos(int pos);
    int GetScrollPos();
};
enum {
    wxWEBKIT_STATE_START = 1,
    wxWEBKIT_STATE_NEGOTIATING = 2,
    wxWEBKIT_STATE_REDIRECTING = 4,
    wxWEBKIT_STATE_TRANSFERRING = 8,
    wxWEBKIT_STATE_STOP = 16,
    wxWEBKIT_STATE_FAILED = 32
};
enum {
    wxWEBKIT_NAV_LINK_CLICKED = 1,
    wxWEBKIT_NAV_BACK_NEXT = 2,
    wxWEBKIT_NAV_FORM_SUBMITTED = 4,
    wxWEBKIT_NAV_RELOAD = 8,
    wxWEBKIT_NAV_FORM_RESUBMITTED = 16,
    wxWEBKIT_NAV_OTHER = 32
};
WXGO_DECL_TYPECONV(WebKitBeforeLoadEvent)
class wxWebKitBeforeLoadEvent : public wxCommandEvent
{
public:
    bool IsCancelled();
    void Cancel(bool cancel = true);
    wxString GetURL();
    void SetURL(const wxString& url);
    void SetNavigationType(int navType);
    int GetNavigationType();
    wxWebKitBeforeLoadEvent( wxWindow* win = 0 );
};
WXGO_DECL_TYPECONV(WebKitStateChangedEvent)
class wxWebKitStateChangedEvent : public wxCommandEvent
{
public:
    int GetState();
    void SetState(int state);
    wxString GetURL();
    void SetURL(const wxString& url);
    wxWebKitStateChangedEvent( wxWindow* win = 0 );
};
WXGO_DECL_TYPECONV(WebKitNewWindowEvent)
class wxWebKitNewWindowEvent : public wxCommandEvent
{
public:
    wxString GetURL() const;
    void SetURL(const wxString& url);
    wxString GetTargetName() const;
    void SetTargetName(const wxString& name);
    wxWebKitNewWindowEvent( wxWindow* win = 0 );
};
%constant wxEventType wxEVT_WEBKIT_STATE_CHANGED;
%constant wxEventType wxEVT_WEBKIT_BEFORE_LOAD;
%constant wxEventType wxEVT_WEBKIT_NEW_WINDOW;
#endif