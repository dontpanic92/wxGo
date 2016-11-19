%nodefaultctor wxEventLoopBase;
WXGO_DECL_TYPECONV(EventLoopBase)
class wxEventLoopBase
{
public:
    static wxEventLoopBase *GetActive();
    static void SetActive(wxEventLoopBase* loop);
    bool IsMain() const;
    virtual int Run();
    bool IsRunning() const;
    virtual bool IsOk() const;
    virtual void Exit(int rc = 0);
    virtual void ScheduleExit(int rc = 0) = 0;
    virtual bool Pending() const = 0;
    virtual bool Dispatch() = 0;
    virtual int DispatchTimeout(unsigned long timeout) = 0;
    virtual void WakeUp() = 0;
    virtual void WakeUpIdle();
    virtual bool ProcessIdle();
    virtual bool IsYielding() const;
    bool Yield(bool onlyIfNeeded = false);
    bool YieldFor(long eventsToProcess);
    virtual bool IsEventAllowedInsideYield(wxEventCategory cat) const;
protected:
    virtual void OnExit();
};
WXGO_DECL_TYPECONV(EventLoopActivator)
class wxEventLoopActivator
{
public:
    wxEventLoopActivator(wxEventLoopBase *loop);
    ~wxEventLoopActivator();
};
WXGO_DECL_TYPECONV(GUIEventLoop)
class wxGUIEventLoop : public wxEventLoopBase
{
public:
    wxGUIEventLoop();
    virtual ~wxGUIEventLoop();
};