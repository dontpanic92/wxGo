class wxApp : public wxAppConsole
{
public:
	
    wxApp();
    ~wxApp();

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

    bool IsActive() const { return m_isActive; }

    void SetTopWindow(wxWindow *win) { m_topWindow = win; }

    wxWindow *GetTopWindow() const;

    void SetExitOnFrameDelete(bool flag)
       { m_exitOnFrameDelete = flag ? Yes : No; }
    bool GetExitOnFrameDelete() const
       { return m_exitOnFrameDelete == Yes; }


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

    //int MainLoop();
    
    %extend {
    	void MyInit(){
    		wxApp::SetInstance(self);
    		
			int argc = 1;
			wxChar* argv[][10] = {wxT("wxGo"), '\0'};
    		self->Initialize(argc, (wxChar**)argv);
    	}
    
		int MainLoop(void* func) {
			int argc = 1;
			wxChar* argv[][10] = {wxT("wxGo"), '\0'};
			wxEntry(argc, (char**)argv);
			return 0;
		}
	}
    
    void ExitMainLoop();

	bool Yield(bool onlyIfNeeded = false);

    void WakeUpIdle();
    
    bool ProcessIdle();
};
