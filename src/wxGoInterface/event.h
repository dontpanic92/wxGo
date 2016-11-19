%typedef int wxEventPropagation;
#define wxEVENT_PROPAGATE_NONE  0
#define wxEVENT_PROPAGATE_MAX  INT_MAX
%typedef int wxEventCategory;
#define wxEVT_CATEGORY_UI  1
#define wxEVT_CATEGORY_USER_INPUT  2
#define wxEVT_CATEGORY_SOCKET  4
#define wxEVT_CATEGORY_TIMER  8
#define wxEVT_CATEGORY_THREAD  16
#define wxEVT_CATEGORY_ALL  wxEVT_CATEGORY_UI|wxEVT_CATEGORY_USER_INPUT|wxEVT_CATEGORY_SOCKET| \        wxEVT_CATEGORY_TIMER|wxEVT_CATEGORY_THREAD
%nodefaultctor wxEvent;
WXGO_DECL_TYPECONV(Event)
class wxEvent : public wxObject
{
public:
    wxObject* GetEventObject() const;
    wxEventType GetEventType() const;
    virtual wxEventCategory GetEventCategory() const;
    int GetId() const;
    wxObject *GetEventUserData() const;
    bool GetSkipped() const;
    long GetTimestamp() const;
    bool IsCommandEvent() const;
    void ResumePropagation(int propagationLevel);
    void SetEventObject(wxObject* object);
    void SetEventType(wxEventType type);
    void SetId(int id);
    void SetTimestamp(long timeStamp = 0);
    bool ShouldPropagate() const;
    void Skip(bool skip = true);
    int StopPropagation();
};
WXGO_DECL_TYPECONV(CommandEvent)
class wxCommandEvent : public wxEvent
{
public:
    wxCommandEvent(wxEventType commandEventType = wxEVT_NULL, int id = 0);
    virtual wxEvent* Clone() const;
    void* GetClientData() const;
    wxClientData* GetClientObject() const;
    long GetExtraLong() const;
    int GetInt() const;
    int GetSelection() const;
    wxString GetString() const;
    bool IsChecked() const;
    bool IsSelection() const;
    void SetClientData(void* clientData);
    void SetClientObject(wxClientData* clientObject);
    void SetExtraLong(long extraLong);
    void SetInt(int intCommand);
    void SetString(const wxString& string);
};
typedef int wxEventType;
WXGO_DECL_TYPECONV(EvtHandler)
class wxEvtHandler : public wxObject, public wxTrackable
{
public:
    wxEvtHandler();
    virtual ~wxEvtHandler();
    virtual void QueueEvent(wxEvent *event);
    virtual void AddPendingEvent(const wxEvent& event);
    virtual bool ProcessEvent(wxEvent& event);
    bool ProcessEventLocally(wxEvent& event);
    bool SafelyProcessEvent(wxEvent& event);
    void ProcessPendingEvents();
    void DeletePendingEvents();
    virtual bool SearchEventTable(wxEventTable& table,
                                  wxEvent& event);
    void* GetClientData() const;
    wxClientData* GetClientObject() const;
    void SetClientData(void* data);
    void SetClientObject(wxClientData* data);
    bool GetEvtHandlerEnabled() const;
    wxEvtHandler* GetNextHandler() const;
    wxEvtHandler* GetPreviousHandler() const;
    void SetEvtHandlerEnabled(bool enabled);
    virtual void SetNextHandler(wxEvtHandler* handler);
    virtual void SetPreviousHandler(wxEvtHandler* handler);
    void Unlink();
    bool IsUnlinked() const;
    static void AddFilter(wxEventFilter* filter);
    static void RemoveFilter(wxEventFilter* filter);
};
WXGO_DECL_TYPECONV(EventBlocker)
class wxEventBlocker : public wxEvtHandler
{
public:
    wxEventBlocker(wxWindow* win, wxEventType type = -1);
    virtual ~wxEventBlocker();
    void Block(wxEventType eventType);
};
WXGO_DECL_TYPECONV(PropagationDisabler)
class wxPropagationDisabler
{
public:
    wxPropagationDisabler(wxEvent& event);
    ~wxPropagationDisabler();
};
WXGO_DECL_TYPECONV(PropagateOnce)
class wxPropagateOnce
{
public:
    wxPropagateOnce(wxEvent& event);
    ~wxPropagateOnce();
};
%typedef int wxKeyCategoryFlags;
#define WXK_CATEGORY_ARROW 0
#define WXK_CATEGORY_PAGING WXK_CATEGORY_ARROW + 1
#define WXK_CATEGORY_JUMP WXK_CATEGORY_PAGING + 1
#define WXK_CATEGORY_TAB WXK_CATEGORY_JUMP + 1
#define WXK_CATEGORY_CUT WXK_CATEGORY_TAB + 1
#define WXK_CATEGORY_NAVIGATION WXK_CATEGORY_CUT + 1
WXGO_DECL_TYPECONV(KeyEvent)
class wxKeyEvent : public wxEvent,
                   public wxKeyboardState
{
public:
    wxKeyEvent(wxEventType keyEventType = wxEVT_NULL);
    int GetKeyCode() const;
    bool IsKeyInCategory(int category) const;
    wxPoint GetPosition() const;
    void GetPosition(wxCoord* x, wxCoord* y) const;
    wxUint32 GetRawKeyCode() const;
    wxUint32 GetRawKeyFlags() const;
    wxChar GetUnicodeKey() const;
    wxCoord GetX() const;
    wxCoord GetY() const;
    void DoAllowNextEvent();
    bool IsNextEventAllowed() const;
};
enum
{
    wxJOYSTICK1,
    wxJOYSTICK2
};
enum
{
    wxJOY_BUTTON_ANY = -1,
    wxJOY_BUTTON1    = 1,
    wxJOY_BUTTON2    = 2,
    wxJOY_BUTTON3    = 4,
    wxJOY_BUTTON4    = 8
};
WXGO_DECL_TYPECONV(JoystickEvent)
class wxJoystickEvent : public wxEvent
{
public:
    wxJoystickEvent(wxEventType eventType = wxEVT_NULL, int state = 0,
                    int joystick = wxJOYSTICK1,
                    int change = 0);
    bool ButtonDown(int button = wxJOY_BUTTON_ANY) const;
    bool ButtonIsDown(int button = wxJOY_BUTTON_ANY) const;
    bool ButtonUp(int button = wxJOY_BUTTON_ANY) const;
    int GetButtonChange() const;
    int GetButtonState() const;
    int GetJoystick() const;
    wxPoint GetPosition() const;
    int GetZPosition() const;
    bool IsButton() const;
    bool IsMove() const;
    bool IsZMove() const;
};
WXGO_DECL_TYPECONV(ScrollWinEvent)
class wxScrollWinEvent : public wxEvent
{
public:
    wxScrollWinEvent(wxEventType commandType = wxEVT_NULL, int pos = 0,
                     int orientation = 0);
    int GetOrientation() const;
    int GetPosition() const;
    void SetOrientation(int orient);
    void SetPosition(int pos);    
};
WXGO_DECL_TYPECONV(SysColourChangedEvent)
class wxSysColourChangedEvent : public wxEvent
{
public:
    wxSysColourChangedEvent();
};
WXGO_DECL_TYPECONV(WindowCreateEvent)
class wxWindowCreateEvent : public wxCommandEvent
{
public:
    wxWindowCreateEvent(wxWindow* win = NULL);
    wxWindow *GetWindow() const;
};
WXGO_DECL_TYPECONV(PaintEvent)
class wxPaintEvent : public wxEvent
{
public:
    wxPaintEvent(int id = 0);
};
WXGO_DECL_TYPECONV(MaximizeEvent)
class wxMaximizeEvent : public wxEvent
{
public:
    wxMaximizeEvent(int id = 0);
};
%typedef int wxUpdateUIMode;
#define wxUPDATE_UI_PROCESS_ALL 0
#define wxUPDATE_UI_PROCESS_SPECIFIED wxUPDATE_UI_PROCESS_ALL + 1
WXGO_DECL_TYPECONV(UpdateUIEvent)
class wxUpdateUIEvent : public wxCommandEvent
{
public:
    wxUpdateUIEvent(wxWindowID commandId = 0);
    static bool CanUpdate(wxWindow* window);
    void Check(bool check);
    void Enable(bool enable);
    bool GetChecked() const;
    bool GetEnabled() const;
    static wxUpdateUIMode GetMode();
    bool GetSetChecked() const;
    bool GetSetEnabled() const;
    bool GetSetShown() const;
    bool GetSetText() const;
    bool GetShown() const;
    wxString GetText() const;
    static long GetUpdateInterval();
    static void ResetUpdateTime();
    static void SetMode(wxUpdateUIMode mode);
    void SetText(const wxString& text);
    static void SetUpdateInterval(long updateInterval);
    void Show(bool show);
};
WXGO_DECL_TYPECONV(ClipboardTextEvent)
class wxClipboardTextEvent : public wxCommandEvent
{
public:
    wxClipboardTextEvent(wxEventType commandType = wxEVT_NULL, int id = 0);
};
%typedef int wxMouseWheelAxis;
#define wxMOUSE_WHEEL_VERTICAL 0
#define wxMOUSE_WHEEL_HORIZONTAL wxMOUSE_WHEEL_VERTICAL + 1
WXGO_DECL_TYPECONV(MouseEvent)
class wxMouseEvent : public wxEvent,
                     public wxMouseState
{
public:
    wxMouseEvent(wxEventType mouseEventType = wxEVT_NULL);
    bool Aux1DClick() const;
    bool Aux1Down() const;
    bool Aux1Up() const;
    bool Aux2DClick() const;
    bool Aux2Down() const;
    bool Aux2Up() const;
    bool Button(wxMouseButton but) const;
    bool ButtonDClick(wxMouseButton but = wxMOUSE_BTN_ANY) const;
    bool ButtonDown(wxMouseButton but = wxMOUSE_BTN_ANY) const;
    bool ButtonUp(wxMouseButton but = wxMOUSE_BTN_ANY) const;
    bool Dragging() const;
    bool Entering() const;
    int GetButton() const;
    int GetClickCount() const;
    int GetLinesPerAction() const;
    int GetColumnsPerAction() const;
    wxPoint GetLogicalPosition(const wxDC& dc) const;
    int GetWheelDelta() const;
    int GetWheelRotation() const;
    wxMouseWheelAxis GetWheelAxis() const;
    bool IsButton() const;
    bool IsPageScroll() const;
    bool Leaving() const;
    bool LeftDClick() const;
    bool LeftDown() const;
    bool LeftUp() const;
    bool MetaDown() const;
    bool MiddleDClick() const;
    bool MiddleDown() const;
    bool MiddleUp() const;
    bool Moving() const;
    bool RightDClick() const;
    bool RightDown() const;
    bool RightUp() const;
};
WXGO_DECL_TYPECONV(DropFilesEvent)
class wxDropFilesEvent : public wxEvent
{
public:
    wxDropFilesEvent(wxEventType id = 0, int noFiles = 0,
                     wxString* files = NULL);
    wxString* GetFiles() const;
    int GetNumberOfFiles() const;
    wxPoint GetPosition() const;
};
WXGO_DECL_TYPECONV(ActivateEvent)
class wxActivateEvent : public wxEvent
{
public:
    enum Reason
    {
        Reason_Mouse,
        Reason_Unknown
    };
    wxActivateEvent(wxEventType eventType = wxEVT_NULL, bool active = true,
                    int id = 0, Reason ActivationReason = Reason_Unknown);
    bool GetActive() const;
    Reason GetActivationReason() const;
};
WXGO_DECL_TYPECONV(ContextMenuEvent)
class wxContextMenuEvent : public wxCommandEvent
{
public:
    wxContextMenuEvent(wxEventType type = wxEVT_NULL, int id = 0,
                       const wxPoint& pos = wxDefaultPosition);
    const wxPoint& GetPosition() const;
    void SetPosition(const wxPoint& point);
};
WXGO_DECL_TYPECONV(EraseEvent)
class wxEraseEvent : public wxEvent
{
public:
    wxEraseEvent(int id = 0, wxDC* dc = NULL);
    wxDC* GetDC() const;
};
WXGO_DECL_TYPECONV(FocusEvent)
class wxFocusEvent : public wxEvent
{
public:
    wxFocusEvent(wxEventType eventType = wxEVT_NULL, int id = 0);
    wxWindow *GetWindow() const;
    void SetWindow(wxWindow *win);
};
WXGO_DECL_TYPECONV(ChildFocusEvent)
class wxChildFocusEvent : public wxCommandEvent
{
public:
    wxChildFocusEvent(wxWindow* win = NULL);
    wxWindow *GetWindow() const;
};
WXGO_DECL_TYPECONV(MouseCaptureLostEvent)
class wxMouseCaptureLostEvent : public wxEvent
{
public:
    wxMouseCaptureLostEvent(wxWindowID windowId = 0);
};
WXGO_DECL_TYPECONV(DisplayChangedEvent)
class wxDisplayChangedEvent : public wxEvent
{
public:
    wxDisplayChangedEvent();
};
WXGO_DECL_TYPECONV(PaletteChangedEvent)
class wxPaletteChangedEvent : public wxEvent
{
public:
    wxPaletteChangedEvent(wxWindowID winid = 0);
    void SetChangedWindow(wxWindow* win);
    wxWindow* GetChangedWindow() const;
};
WXGO_DECL_TYPECONV(QueryNewPaletteEvent)
class wxQueryNewPaletteEvent : public wxEvent
{
public:
    wxQueryNewPaletteEvent(wxWindowID winid = 0);
    void SetPaletteRealized(bool realized);
    bool GetPaletteRealized();
};
WXGO_DECL_TYPECONV(NotifyEvent)
class wxNotifyEvent : public wxCommandEvent
{
public:
    wxNotifyEvent(wxEventType eventType = wxEVT_NULL, int id = 0);
    void Allow();
    bool IsAllowed() const;
    void Veto();
};
WXGO_DECL_TYPECONV(ThreadEvent)
class wxThreadEvent : public wxEvent
{
public:
    wxThreadEvent(wxEventType eventType = wxEVT_THREAD, int id = wxID_ANY);
    virtual wxEvent *Clone() const;
    virtual wxEventCategory GetEventCategory() const;
    template<typename T>
    void SetPayload(const T& payload);
    template<typename T>
    T GetPayload() const;
    long GetExtraLong() const;
    int GetInt() const;
    wxString GetString() const;
    void SetExtraLong(long extraLong);
    void SetInt(int intCommand);
    void SetString(const wxString& string);
};
WXGO_DECL_TYPECONV(HelpEvent)
class wxHelpEvent : public wxCommandEvent
{
public:
    enum Origin
    {
        Origin_Unknown,    
        Origin_Keyboard,   
        Origin_HelpButton
    };
    wxHelpEvent(wxEventType type = wxEVT_NULL,
                wxWindowID winid = 0,
                const wxPoint& pt = wxDefaultPosition,
                wxHelpEvent::Origin origin = Origin_Unknown);
    wxHelpEvent::Origin GetOrigin() const;
    const wxPoint& GetPosition() const;
    void SetOrigin(wxHelpEvent::Origin origin);
    void SetPosition(const wxPoint& pt);
};
WXGO_DECL_TYPECONV(ScrollEvent)
class wxScrollEvent : public wxCommandEvent
{
public:
    wxScrollEvent(wxEventType commandType = wxEVT_NULL, int id = 0, int pos = 0,
                  int orientation = 0);
    int GetOrientation() const;
    int GetPosition() const;
    void SetOrientation(int orient);
    void SetPosition(int pos);    
};
%typedef int wxIdleMode;
#define wxIDLE_PROCESS_ALL 0
#define wxIDLE_PROCESS_SPECIFIED wxIDLE_PROCESS_ALL + 1
WXGO_DECL_TYPECONV(IdleEvent)
class wxIdleEvent : public wxEvent
{
public:
    wxIdleEvent();
    static wxIdleMode GetMode();
    bool MoreRequested() const;
    void RequestMore(bool needMore = true);
    static void SetMode(wxIdleMode mode);
};
WXGO_DECL_TYPECONV(InitDialogEvent)
class wxInitDialogEvent : public wxEvent
{
public:
    wxInitDialogEvent(int id = 0);
};
WXGO_DECL_TYPECONV(WindowDestroyEvent)
class wxWindowDestroyEvent : public wxCommandEvent
{
public:
    wxWindowDestroyEvent(wxWindow* win = NULL);
    wxWindow *GetWindow() const;
};
WXGO_DECL_TYPECONV(NavigationKeyEvent)
class wxNavigationKeyEvent : public wxEvent
{
public:
    enum wxNavigationKeyEventFlags
    {
        IsBackward = 0x0000,
        IsForward = 0x0001,
        WinChange = 0x0002,
        FromTab = 0x0004
    };
    wxNavigationKeyEvent();
    wxNavigationKeyEvent(const wxNavigationKeyEvent& event);
    wxWindow* GetCurrentFocus() const;
    bool GetDirection() const;
    bool IsFromTab() const;
    bool IsWindowChange() const;
    void SetCurrentFocus(wxWindow* currentFocus);
    void SetDirection(bool direction);
    void SetFlags(long flags);
    void SetFromTab(bool fromTab);
    void SetWindowChange(bool windowChange);
};
WXGO_DECL_TYPECONV(MouseCaptureChangedEvent)
class wxMouseCaptureChangedEvent : public wxEvent
{
public:
    wxMouseCaptureChangedEvent(wxWindowID windowId = 0,
                               wxWindow* gainedCapture = NULL);
    wxWindow* GetCapturedWindow() const;
};
WXGO_DECL_TYPECONV(CloseEvent)
class wxCloseEvent : public wxEvent
{
public:
    wxCloseEvent(wxEventType commandEventType = wxEVT_NULL, int id = 0);
    bool CanVeto() const;
    bool GetLoggingOff() const;
    void SetCanVeto(bool canVeto);
    void SetLoggingOff(bool loggingOff);
    void Veto(bool veto = true);
};
WXGO_DECL_TYPECONV(MenuEvent)
class wxMenuEvent : public wxEvent
{
public:
    wxMenuEvent(wxEventType type = wxEVT_NULL, int id = 0, wxMenu* menu = NULL);
    wxMenu* GetMenu() const;
    int GetMenuId() const;
    bool IsPopup() const;
};
WXGO_DECL_TYPECONV(ShowEvent)
class wxShowEvent : public wxEvent
{
public:
    wxShowEvent(int winid = 0, bool show = false);
    void SetShow(bool show);
    bool IsShown() const;
};
WXGO_DECL_TYPECONV(IconizeEvent)
class wxIconizeEvent : public wxEvent
{
public:
    wxIconizeEvent(int id = 0, bool iconized = true);
    bool IsIconized() const;
};
WXGO_DECL_TYPECONV(MoveEvent)
class wxMoveEvent : public wxEvent
{
public:
    wxMoveEvent(const wxPoint& pt, int id = 0);
    wxPoint GetPosition() const;
    wxRect GetRect() const;
    void SetRect(const wxRect& rect);
    void SetPosition(const wxPoint& pos);    
};
WXGO_DECL_TYPECONV(SizeEvent)
class wxSizeEvent : public wxEvent
{
public:
    wxSizeEvent(const wxSize& sz, int id = 0);
    wxSize GetSize() const;
    void SetSize(wxSize size);
    wxRect GetRect() const;
    void SetRect(wxRect rect);
};
WXGO_DECL_TYPECONV(SetCursorEvent)
class wxSetCursorEvent : public wxEvent
{
public:
    wxSetCursorEvent(wxCoord x = 0, wxCoord y = 0);
    const wxCursor& GetCursor() const;
    wxCoord GetX() const;
    wxCoord GetY() const;
    bool HasCursor() const;
    void SetCursor(const wxCursor& cursor);
};
%constant wxEventType wxEVT_NULL;
%constant wxEventType wxEVT_ANY;
wxEventType wxNewEventType();
void wxPostEvent(wxEvtHandler* dest, const wxEvent& event);
void wxQueueEvent(wxEvtHandler* dest, wxEvent *event);
%constant wxEventType wxEVT_BUTTON;
%constant wxEventType wxEVT_CHECKBOX;
%constant wxEventType wxEVT_CHOICE;
%constant wxEventType wxEVT_LISTBOX;
%constant wxEventType wxEVT_LISTBOX_DCLICK;
%constant wxEventType wxEVT_CHECKLISTBOX;
%constant wxEventType wxEVT_MENU;
%constant wxEventType wxEVT_SLIDER;
%constant wxEventType wxEVT_RADIOBOX;
%constant wxEventType wxEVT_RADIOBUTTON;
%constant wxEventType wxEVT_SCROLLBAR;
%constant wxEventType wxEVT_VLBOX;
%constant wxEventType wxEVT_COMBOBOX;
%constant wxEventType wxEVT_TOOL_RCLICKED;
%constant wxEventType wxEVT_TOOL_DROPDOWN;
%constant wxEventType wxEVT_TOOL_ENTER;
%constant wxEventType wxEVT_COMBOBOX_DROPDOWN;
%constant wxEventType wxEVT_COMBOBOX_CLOSEUP;
%constant wxEventType wxEVT_THREAD;
%constant wxEventType wxEVT_LEFT_DOWN;
%constant wxEventType wxEVT_LEFT_UP;
%constant wxEventType wxEVT_MIDDLE_DOWN;
%constant wxEventType wxEVT_MIDDLE_UP; 
%constant wxEventType wxEVT_RIGHT_DOWN;
%constant wxEventType wxEVT_RIGHT_UP;
%constant wxEventType wxEVT_MOTION;
%constant wxEventType wxEVT_ENTER_WINDOW;
%constant wxEventType wxEVT_LEAVE_WINDOW;
%constant wxEventType wxEVT_LEFT_DCLICK;
%constant wxEventType wxEVT_MIDDLE_DCLICK;
%constant wxEventType wxEVT_RIGHT_DCLICK;
%constant wxEventType wxEVT_SET_FOCUS;
%constant wxEventType wxEVT_KILL_FOCUS;
%constant wxEventType wxEVT_CHILD_FOCUS;
%constant wxEventType wxEVT_MOUSEWHEEL;
%constant wxEventType wxEVT_AUX1_DOWN;
%constant wxEventType wxEVT_AUX1_UP;
%constant wxEventType wxEVT_AUX1_DCLICK;
%constant wxEventType wxEVT_AUX2_DOWN;
%constant wxEventType wxEVT_AUX2_UP;
%constant wxEventType wxEVT_AUX2_DCLICK;
%constant wxEventType wxEVT_CHAR;
%constant wxEventType wxEVT_CHAR_HOOK;
%constant wxEventType wxEVT_NAVIGATION_KEY;
%constant wxEventType wxEVT_KEY_DOWN;
%constant wxEventType wxEVT_KEY_UP;
%constant wxEventType wxEVT_SET_CURSOR;
%constant wxEventType wxEVT_SCROLL_TOP;
%constant wxEventType wxEVT_SCROLL_BOTTOM;
%constant wxEventType wxEVT_SCROLL_LINEUP;
%constant wxEventType wxEVT_SCROLL_LINEDOWN;
%constant wxEventType wxEVT_SCROLL_PAGEUP;
%constant wxEventType wxEVT_SCROLL_PAGEDOWN;
%constant wxEventType wxEVT_SCROLL_THUMBTRACK;
%constant wxEventType wxEVT_SCROLL_THUMBRELEASE;
%constant wxEventType wxEVT_SCROLL_CHANGED;
%constant wxEventType wxEVT_SPIN_UP;
%constant wxEventType wxEVT_SPIN_DOWN;
%constant wxEventType wxEVT_SPIN;
%constant wxEventType wxEVT_SCROLLWIN_TOP;
%constant wxEventType wxEVT_SCROLLWIN_BOTTOM;
%constant wxEventType wxEVT_SCROLLWIN_LINEUP;
%constant wxEventType wxEVT_SCROLLWIN_LINEDOWN;
%constant wxEventType wxEVT_SCROLLWIN_PAGEUP;
%constant wxEventType wxEVT_SCROLLWIN_PAGEDOWN;
%constant wxEventType wxEVT_SCROLLWIN_THUMBTRACK;
%constant wxEventType wxEVT_SCROLLWIN_THUMBRELEASE;
%constant wxEventType wxEVT_SIZE;
%constant wxEventType wxEVT_MOVE;
%constant wxEventType wxEVT_CLOSE_WINDOW;
%constant wxEventType wxEVT_END_SESSION;
%constant wxEventType wxEVT_QUERY_END_SESSION;
%constant wxEventType wxEVT_ACTIVATE_APP;
%constant wxEventType wxEVT_ACTIVATE;
%constant wxEventType wxEVT_CREATE;
%constant wxEventType wxEVT_DESTROY;
%constant wxEventType wxEVT_SHOW;
%constant wxEventType wxEVT_ICONIZE;
%constant wxEventType wxEVT_MAXIMIZE;
%constant wxEventType wxEVT_MOUSE_CAPTURE_CHANGED;
%constant wxEventType wxEVT_MOUSE_CAPTURE_LOST;
%constant wxEventType wxEVT_PAINT;
%constant wxEventType wxEVT_ERASE_BACKGROUND;
%constant wxEventType wxEVT_NC_PAINT;
%constant wxEventType wxEVT_MENU_OPEN;
%constant wxEventType wxEVT_MENU_CLOSE;
%constant wxEventType wxEVT_MENU_HIGHLIGHT;
%constant wxEventType wxEVT_CONTEXT_MENU;
%constant wxEventType wxEVT_SYS_COLOUR_CHANGED;
%constant wxEventType wxEVT_DISPLAY_CHANGED;
%constant wxEventType wxEVT_QUERY_NEW_PALETTE;
%constant wxEventType wxEVT_PALETTE_CHANGED;
%constant wxEventType wxEVT_JOY_BUTTON_DOWN;
%constant wxEventType wxEVT_JOY_BUTTON_UP;
%constant wxEventType wxEVT_JOY_MOVE;
%constant wxEventType wxEVT_JOY_ZMOVE;
%constant wxEventType wxEVT_DROP_FILES;
%constant wxEventType wxEVT_INIT_DIALOG;
%constant wxEventType wxEVT_IDLE;
%constant wxEventType wxEVT_UPDATE_UI;
%constant wxEventType wxEVT_SIZING;
%constant wxEventType wxEVT_MOVING;
%constant wxEventType wxEVT_MOVE_START;
%constant wxEventType wxEVT_MOVE_END;
%constant wxEventType wxEVT_HIBERNATE;
%constant wxEventType wxEVT_TEXT_COPY;
%constant wxEventType wxEVT_TEXT_CUT;
%constant wxEventType wxEVT_TEXT_PASTE;
%constant wxEventType wxEVT_COMMAND_LEFT_CLICK;
%constant wxEventType wxEVT_COMMAND_LEFT_DCLICK;
%constant wxEventType wxEVT_COMMAND_RIGHT_CLICK;
%constant wxEventType wxEVT_COMMAND_RIGHT_DCLICK;
%constant wxEventType wxEVT_COMMAND_SET_FOCUS;
%constant wxEventType wxEVT_COMMAND_KILL_FOCUS;
%constant wxEventType wxEVT_COMMAND_ENTER;
%constant wxEventType wxEVT_HELP;
%constant wxEventType wxEVT_DETAILED_HELP;
%constant wxEventType wxEVT_TOOL;
%constant wxEventType wxEVT_WINDOW_MODAL_DIALOG_CLOSED;