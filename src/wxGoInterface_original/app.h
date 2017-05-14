class wxGoApp
{
public:

    wxGoApp();
    wxGoApp(const char *);
    ~wxGoApp();

    bool Initialize(int& argc, wxChar **argv);

    bool OnInitGui();

    bool OnInit();

    virtual void OnLaunched();
    
    virtual void OnEventLoopEnter(wxEventLoopBase* loop);

    int OnRun();

    int OnExit();

    void CleanUp();

    bool SafeYield(wxWindow *win, bool onlyIfNeeded);
    bool SafeYieldFor(wxWindow *win, long eventsToProcess);

    bool IsActive() const ;

    void SetTopWindow(wxWindow *win);

    wxWindow *GetTopWindow() const;

    void SetExitOnFrameDelete(bool flag);
    bool GetExitOnFrameDelete() const;


    void SetUseBestVisual( bool flag, bool forceTrueColour = false );
    bool GetUseBestVisual() const;

    void SetPrintMode(int mode) { }
    int GetPrintMode();

    wxLayoutDirection GetLayoutDirection() const;

    bool SetNativeTheme(const wxString& theme);

    void SetActive(bool isActive, wxWindow *lastFocus);
    
//Functions from wxAppConsole

	void ProcessPendingEvents();

    bool HasPendingEvents() const;

    void SuspendProcessingOfPendingEvents();

    void ResumeProcessingOfPendingEvents();

    void RemovePendingEventHandler(wxEvtHandler* toRemove);

    void AppendPendingEventHandler(wxEvtHandler* toAppend);

    void DelayPendingEventHandler(wxEvtHandler* toDelay);

    void DeletePendingEvents();

    bool Pending();
    
    bool Dispatch();

    int MainLoop();
    
    void ExitMainLoop();

	bool Yield(bool onlyIfNeeded = false);

    void WakeUpIdle();
    
    bool ProcessIdle();

    static wxGoApp *GetInstance();
};
