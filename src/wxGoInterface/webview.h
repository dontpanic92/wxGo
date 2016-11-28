%typedef int wxWebViewZoom;
#define wxWEBVIEW_ZOOM_TINY 0
#define wxWEBVIEW_ZOOM_SMALL wxWEBVIEW_ZOOM_TINY + 1
#define wxWEBVIEW_ZOOM_MEDIUM wxWEBVIEW_ZOOM_SMALL + 1
#define wxWEBVIEW_ZOOM_LARGE wxWEBVIEW_ZOOM_MEDIUM + 1
#define wxWEBVIEW_ZOOM_LARGEST wxWEBVIEW_ZOOM_LARGE + 1
%typedef int wxWebViewZoomType;
#define wxWEBVIEW_ZOOM_TYPE_LAYOUT 0
#define wxWEBVIEW_ZOOM_TYPE_TEXT wxWEBVIEW_ZOOM_TYPE_LAYOUT + 1
%typedef int wxWebViewNavigationError;
#define wxWEBVIEW_NAV_ERR_CONNECTION 0
#define wxWEBVIEW_NAV_ERR_CERTIFICATE wxWEBVIEW_NAV_ERR_CONNECTION + 1
#define wxWEBVIEW_NAV_ERR_AUTH wxWEBVIEW_NAV_ERR_CERTIFICATE + 1
#define wxWEBVIEW_NAV_ERR_SECURITY wxWEBVIEW_NAV_ERR_AUTH + 1
#define wxWEBVIEW_NAV_ERR_NOT_FOUND wxWEBVIEW_NAV_ERR_SECURITY + 1
#define wxWEBVIEW_NAV_ERR_REQUEST wxWEBVIEW_NAV_ERR_NOT_FOUND + 1
#define wxWEBVIEW_NAV_ERR_USER_CANCELLED wxWEBVIEW_NAV_ERR_REQUEST + 1
#define wxWEBVIEW_NAV_ERR_OTHER wxWEBVIEW_NAV_ERR_USER_CANCELLED + 1
%typedef int wxWebViewReloadFlags;
#define wxWEBVIEW_RELOAD_DEFAULT 0
#define wxWEBVIEW_RELOAD_NO_CACHE wxWEBVIEW_RELOAD_DEFAULT + 1
%typedef int wxWebViewFindFlags;
#define wxWEBVIEW_FIND_WRAP  0x0001
#define wxWEBVIEW_FIND_ENTIRE_WORD  0x0002
#define wxWEBVIEW_FIND_MATCH_CASE  0x0004
#define wxWEBVIEW_FIND_HIGHLIGHT_RESULT  0x0008
#define wxWEBVIEW_FIND_BACKWARDS  0x0010
#define wxWEBVIEW_FIND_DEFAULT  0
WXGO_DECL_TYPECONV(WebViewHistoryItem)
class wxWebViewHistoryItem
{
public:
    wxWebViewHistoryItem(const wxString& url, const wxString& title);
    wxString GetUrl();
    wxString GetTitle();
};
WXGO_DECL_TYPECONV(WebViewFactory)
class wxWebViewFactory : public wxObject
{
public:
    virtual wxWebView* Create() = 0;
    virtual wxWebView* Create(wxWindow* parent,
                              wxWindowID id,
                              const wxString& url = wxWebViewDefaultURLStr,
                              const wxPoint& pos = wxDefaultPosition,
                              const wxSize& size = wxDefaultSize,
                              long style = 0,
                              const wxString& name = wxWebViewNameStr) = 0;
};
WXGO_DECL_TYPECONV(WebViewHandler)
class wxWebViewHandler
{
public:
    wxWebViewHandler(const wxString& scheme);
    virtual wxFSFile* GetFile(const wxString &uri) = 0;
    virtual wxString GetName() const;
};
WXGO_DECL_TYPECONV(WebView)
class wxWebView : public wxControl
{
public:
    virtual bool Create(wxWindow* parent,
                        wxWindowID id,
                        const wxString& url = wxWebViewDefaultURLStr,
                        const wxPoint& pos = wxDefaultPosition,
                        const wxSize& size = wxDefaultSize,
                        long style = 0,
                        const wxString& name = wxWebViewNameStr) = 0;
    static wxWebView* New(const wxString& backend = wxWebViewBackendDefault);
    static wxWebView* New(wxWindow* parent,
                          wxWindowID id,
                          const wxString& url = wxWebViewDefaultURLStr,
                          const wxPoint& pos = wxDefaultPosition,
                          const wxSize& size = wxDefaultSize,
                          const wxString& backend = wxWebViewBackendDefault,
                          long style = 0,
                          const wxString& name = wxWebViewNameStr);
    static void RegisterFactory(const wxString& backend, 
                                wxSharedPtr<wxWebViewFactory> factory);
    virtual wxString GetCurrentTitle() const = 0;
    virtual wxString GetCurrentURL() const = 0;
    virtual void* GetNativeBackend() const = 0;
    virtual wxString GetPageSource() const = 0;
    virtual wxString GetPageText() const = 0;
    virtual bool IsBusy() const = 0;
    virtual bool IsEditable() const = 0;
    virtual void LoadURL(const wxString& url) = 0;
    virtual void Print() = 0;
    virtual void RegisterHandler(wxSharedPtr<wxWebViewHandler> handler) = 0;
    virtual void Reload(wxWebViewReloadFlags flags = wxWEBVIEW_RELOAD_DEFAULT) = 0;
    virtual void RunScript(const wxString& javascript) = 0;
    virtual void SetEditable(bool enable = true) = 0;
    virtual void SetPage(const wxString& html, const wxString& baseUrl) = 0;
    virtual void SetPage(wxInputStream& html, wxString baseUrl);
    virtual void Stop() = 0;
    virtual bool CanCopy() const = 0;
    virtual bool CanCut() const = 0;
    virtual bool CanPaste() const = 0;
    virtual void Copy() = 0;
    virtual void Cut() = 0;
    virtual void Paste() = 0;
    virtual void EnableContextMenu(bool enable = true);
    virtual bool IsContextMenuEnabled() const;
    virtual bool CanGoBack() const = 0;
    virtual bool CanGoForward() const = 0;
    virtual void ClearHistory() = 0;
    virtual void EnableHistory(bool enable = true) = 0;
    virtual wxVector<wxSharedPtr<wxWebViewHistoryItem> > GetBackwardHistory() = 0;
    virtual wxVector<wxSharedPtr<wxWebViewHistoryItem> > GetForwardHistory() = 0;
    virtual void GoBack() = 0;
    virtual void GoForward() = 0;
    virtual void LoadHistoryItem(wxSharedPtr<wxWebViewHistoryItem> item) = 0;
    virtual void ClearSelection() = 0;
    virtual void DeleteSelection() = 0;
    virtual wxString GetSelectedSource() const = 0;
    virtual wxString GetSelectedText() const = 0;
    virtual bool HasSelection() const = 0;
    virtual void SelectAll() = 0;
    virtual bool CanRedo() const = 0;
    virtual bool CanUndo() const = 0;
    virtual void Redo() = 0;
    virtual void Undo() = 0;
    virtual long Find(const wxString& text, wxWebViewFindFlags flags = wxWEBVIEW_FIND_DEFAULT) = 0;
    virtual bool CanSetZoomType(wxWebViewZoomType type) const = 0;
    virtual wxWebViewZoom GetZoom() const = 0;
    virtual wxWebViewZoomType GetZoomType() const = 0;
    virtual void SetZoom(wxWebViewZoom zoom) = 0;
    virtual void SetZoomType(wxWebViewZoomType zoomType) = 0;
};
WXGO_DECL_TYPECONV(WebViewEvent)
class wxWebViewEvent : public wxNotifyEvent
{
public:
    wxWebViewEvent();
    wxWebViewEvent(wxEventType type, int id, const wxString href,
                   const wxString target);
    const wxString& GetTarget() const;
    const wxString& GetURL() const;
};
%constant wxEventType wxEVT_WEBVIEW_NAVIGATING;
%constant wxEventType wxEVT_WEBVIEW_NAVIGATED;
%constant wxEventType wxEVT_WEBVIEW_LOADED;
%constant wxEventType wxEVT_WEBVIEW_ERROR;
%constant wxEventType wxEVT_WEBVIEW_NEWWINDOW;
%constant wxEventType wxEVT_WEBVIEW_TITLE_CHANGED;