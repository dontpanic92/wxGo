
enum wxTaskBarIconType
{
    wxTBI_DOCK,
    wxTBI_CUSTOM_STATUSITEM,
    wxTBI_DEFAULT_TYPE
};


class wxTaskBarIconEvent : public wxEvent
{
public:
    wxTaskBarIconEvent(wxEventType evtType, wxTaskBarIcon *tbIcon);
};

class wxTaskBarIcon : public wxEvtHandler
{
public:

    wxTaskBarIcon(wxTaskBarIconType iconType = wxTBI_DEFAULT_TYPE);

    virtual ~wxTaskBarIcon();

    void Destroy();

    bool IsIconInstalled() const;

    bool IsOk() const;

    virtual bool PopupMenu(wxMenu* menu);

    virtual bool RemoveIcon();

    virtual bool SetIcon(const wxIcon& icon,
                         const wxString& tooltip = wxEmptyString);
#ifdef __WXMSW__
    bool ShowBalloon(const wxString& title,
                        const wxString& text,
                        unsigned msec = 0,
                        int flags = 0,
                        const wxIcon& icon = wxNullIcon);
#endif
    static bool IsAvailable();

};


%constant wxEventType wxEVT_TASKBAR_MOVE;
%constant wxEventType wxEVT_TASKBAR_LEFT_DOWN;
%constant wxEventType wxEVT_TASKBAR_LEFT_UP;
%constant wxEventType wxEVT_TASKBAR_RIGHT_DOWN;
%constant wxEventType wxEVT_TASKBAR_RIGHT_UP;
%constant wxEventType wxEVT_TASKBAR_LEFT_DCLICK;
%constant wxEventType wxEVT_TASKBAR_RIGHT_DCLICK;
%constant wxEventType wxEVT_TASKBAR_CLICK;
%constant wxEventType wxEVT_TASKBAR_BALLOON_TIMEOUT;
%constant wxEventType wxEVT_TASKBAR_BALLOON_CLICK;
