typedef wxVector<wxDocument*> wxDocVector;
typedef wxVector<wxView*> wxViewVector;
typedef wxVector<wxDocTemplate*> wxDocTemplateVector;
WXGO_DECL_TYPECONV(DocTemplate)
class wxDocTemplate : public wxObject
{
public:
    wxDocTemplate(wxDocManager* manager, const wxString& descr,
                  const wxString& filter, const wxString& dir,
                  const wxString& ext, const wxString& docTypeName,
                  const wxString& viewTypeName, wxClassInfo* docClassInfo = 0,
                  wxClassInfo* viewClassInfo = 0,
                  long flags = wxTEMPLATE_VISIBLE);
    virtual ~wxDocTemplate();
    virtual wxDocument* CreateDocument(const wxString& path, long flags = 0);
    virtual wxView* CreateView(wxDocument* doc, long flags = 0);
    virtual bool FileMatchesTemplate(const wxString& path);
    wxString GetDefaultExtension() const;
    wxString GetDescription() const;
    wxString GetDirectory() const;
    wxClassInfo* GetDocClassInfo() const;
    wxDocManager* GetDocumentManager() const;
    virtual wxString GetDocumentName() const;
    wxString GetFileFilter() const;
    long GetFlags() const;
    wxClassInfo* GetViewClassInfo() const;
    virtual wxString GetViewName() const;
    virtual bool InitDocument(wxDocument* doc,
                              const wxString& path,
                              long flags = 0);
    bool IsVisible() const;
    void SetDefaultExtension(const wxString& ext);
    void SetDescription(const wxString& descr);
    void SetDirectory(const wxString& dir);
    void SetDocumentManager(wxDocManager* manager);
    void SetFileFilter(const wxString& filter);
    void SetFlags(long flags);
protected:
    wxString m_defaultExt;
    wxString m_description;
    wxString m_directory;
    wxClassInfo* m_docClassInfo;
    wxString m_docTypeName;
    wxDocTemplate* m_documentManager;
    wxString m_fileFilter;
    long m_flags;
    wxClassInfo* m_viewClassInfo;
    wxString m_viewTypeName;
    virtual wxDocument *DoCreateDocument();
    virtual wxView *DoCreateView();
};
WXGO_DECL_TYPECONV(DocManager)
class wxDocManager : public wxEvtHandler
{
public:
    wxDocManager(long flags = 0, bool initialize = true);
    virtual ~wxDocManager();
    virtual void ActivateView(wxView* doc, bool activate = true);
    void AddDocument(wxDocument* doc);
    virtual void AddFileToHistory(const wxString& filename);
    void AssociateTemplate(wxDocTemplate* temp);
    wxDocTemplate* FindTemplate(const wxClassInfo* classinfo);
    wxDocument* FindDocumentByPath(const wxString& path) const;
    bool CloseDocument(wxDocument *doc, bool force = false);
    bool CloseDocuments(bool force = true);
    virtual wxDocument* CreateDocument(const wxString& path, long flags = 0);
    wxDocument *CreateNewDocument();
    virtual wxView* CreateView(wxDocument* doc, long flags = 0);
    void DisassociateTemplate(wxDocTemplate* temp);
    virtual void FileHistoryAddFilesToMenu();
    virtual void FileHistoryAddFilesToMenu(wxMenu* menu);
    virtual void FileHistoryLoad(const wxConfigBase& config);
    virtual void FileHistoryRemoveMenu(wxMenu* menu);
    virtual void FileHistorySave(wxConfigBase& resourceFile);
    virtual void FileHistoryUseMenu(wxMenu* menu);
    virtual wxDocTemplate* FindTemplateForPath(const wxString& path);
    wxView* GetAnyUsableView() const;
    wxDocument* GetCurrentDocument() const;
    virtual wxView* GetCurrentView() const;
    wxDocVector GetDocumentsVector() const;
    wxDocTemplateVector GetTemplatesVector() const;
    wxList& GetDocuments();
    virtual wxFileHistory* GetFileHistory() const;
    virtual size_t GetHistoryFilesCount() const;
    wxString GetLastDirectory() const;
    int GetMaxDocsOpen() const;
    wxList& GetTemplates();
    virtual bool Initialize();
    virtual wxString MakeNewDocumentName();
    virtual wxFileHistory* OnCreateFileHistory();
    void OnFileClose(wxCommandEvent& event);
    void OnFileCloseAll(wxCommandEvent& event);
    void OnFileNew(wxCommandEvent& event);
    void OnFileOpen(wxCommandEvent& event);
    void OnFileRevert(wxCommandEvent& event);
    void OnFileSave(wxCommandEvent& event);
    void OnFileSaveAs(wxCommandEvent& event);
    void RemoveDocument(wxDocument* doc);
    virtual wxDocTemplate* SelectDocumentPath(wxDocTemplate** templates,
                                              int noTemplates, wxString& path,
                                              long flags, bool save = false);
    virtual wxDocTemplate* SelectDocumentType(wxDocTemplate** templates,
                                              int noTemplates,
                                              bool sort = false);
    virtual wxDocTemplate* SelectViewType(wxDocTemplate** templates,
                                          int noTemplates, bool sort = false);
    void SetLastDirectory(const wxString& dir);
    void SetMaxDocsOpen(int n);
protected:
    virtual void OnMRUFileNotExist(unsigned n, const wxString& filename);
    virtual wxPreviewFrame* CreatePreviewFrame(wxPrintPreviewBase* preview,
                                               wxWindow* parent,
                                               const wxString& title);
    wxView* m_currentView;
    int m_defaultDocumentNameCounter;
    wxList m_docs;
    wxFileHistory* m_fileHistory;
    wxString m_lastDirectory;
    int m_maxDocsOpen;
};
WXGO_DECL_TYPECONV(View)
class wxView : public wxEvtHandler
{
public:
    wxView();
    virtual ~wxView();
    virtual void Activate(bool activate);
    virtual bool Close(bool deleteWindow = true);
    wxDocument* GetDocument() const;
    wxDocManager* GetDocumentManager() const;
    wxWindow* GetFrame() const;
    wxString GetViewName() const;
    virtual void OnActivateView(bool activate, wxView* activeView,
                                wxView* deactiveView);
    virtual void OnChangeFilename();
    virtual bool OnClose(bool deleteWindow);
    virtual void OnClosingDocument();
    virtual bool OnCreate(wxDocument* doc, long flags);
    virtual wxPrintout* OnCreatePrintout();
    virtual void OnDraw(wxDC* dc) = 0;
    virtual void OnUpdate(wxView* sender, wxObject* hint = 0);
    virtual void SetDocument(wxDocument* doc);
    void SetFrame(wxWindow* frame);
    void SetViewName(const wxString& name);
protected:
    wxDocument* m_viewDocument;
    wxFrame* m_viewFrame;
    wxString m_viewTypeName;
};
WXGO_DECL_TYPECONV(DocChildFrame)
class wxDocChildFrame : public wxFrame
{
public:
    wxDocChildFrame(wxDocument* doc, wxView* view, wxFrame* parent,
                    wxWindowID id, const wxString& title,
                    const wxPoint& pos = wxDefaultPosition,
                    const wxSize& size = wxDefaultSize,
                    long style = wxDEFAULT_FRAME_STYLE,
                    const wxString& name = wxFrameNameStr);
    virtual ~wxDocChildFrame();
    wxDocument* GetDocument() const;
    wxView* GetView() const;
    void SetDocument(wxDocument* doc);
    void SetView(wxView* view);
protected:
    wxDocument* m_childDocument;
    wxView* m_childView;
};
WXGO_DECL_TYPECONV(DocParentFrame)
class wxDocParentFrame : public wxFrame
{
public:
    wxDocParentFrame();
    wxDocParentFrame(wxDocManager* manager, wxFrame* parent,
                     wxWindowID id, const wxString& title,
                     const wxPoint& pos = wxDefaultPosition,
                     const wxSize& size = wxDefaultSize,
                     long style = wxDEFAULT_FRAME_STYLE,
                     const wxString& name = wxFrameNameStr);
    virtual ~wxDocParentFrame();
    bool Create(wxDocManager* manager, wxFrame* parent, wxWindowID id,
                const wxString& title, const wxPoint& pos = wxDefaultPosition,
                const wxSize& size = wxDefaultSize, long style = 541072960,
                const wxString& name = wxFrameNameStr);
    wxDocManager* GetDocumentManager() const;
};
WXGO_DECL_TYPECONV(Document)
class wxDocument : public wxEvtHandler
{
public:
    wxDocument(wxDocument* parent = NULL);
    virtual ~wxDocument();
    virtual bool AddView(wxView* view);
    bool AlreadySaved() const;
    void Activate();
    virtual bool Close();
    virtual bool DeleteAllViews();
    virtual bool DeleteContents();
    virtual wxCommandProcessor* GetCommandProcessor() const;
    virtual wxDocManager* GetDocumentManager() const;
    wxString GetDocumentName() const;
    bool GetDocumentSaved() const;
    virtual wxDocTemplate* GetDocumentTemplate() const;
    virtual wxWindow* GetDocumentWindow() const;
    wxString GetFilename() const;
    wxView* GetFirstView() const;
    wxString GetTitle() const;
    virtual wxString GetUserReadableName() const;
    wxViewVector GetViewsVector() const;
    wxList& GetViews();
    const wxList& GetViews() const;
    bool IsChildDocument() const;
    virtual bool IsModified() const;
    virtual void Modify(bool modify);
    virtual void OnChangedViewList();
    virtual bool OnCloseDocument();
    virtual bool OnCreate(const wxString& path, long flags);
    virtual wxCommandProcessor* OnCreateCommandProcessor();
    virtual bool OnNewDocument();
    virtual bool OnOpenDocument(const wxString& filename);
    virtual bool OnSaveDocument(const wxString& filename);
    virtual bool OnSaveModified();
    virtual bool RemoveView(wxView* view);
    virtual bool Save();
    virtual bool SaveAs();
    virtual bool Revert();
    virtual void SetCommandProcessor(wxCommandProcessor* processor);
    void SetDocumentName(const wxString& name);
    virtual void SetDocumentTemplate(wxDocTemplate* templ);
    void SetDocumentSaved(bool saved = true);
    void SetFilename(const wxString& filename, bool notifyViews = false);
    virtual void OnChangeFilename(bool notifyViews);
    void SetTitle(const wxString& title);
    virtual void UpdateAllViews(wxView* sender = NULL, wxObject* hint = NULL);
protected:
    virtual bool DoSaveDocument(const wxString& file);
    virtual bool DoOpenDocument(const wxString& file);
    wxCommandProcessor* m_commandProcessor;
    wxString m_documentFile;
    bool m_documentModified;
    wxDocTemplate* m_documentTemplate;
    wxString m_documentTitle;
    wxString m_documentTypeName;
    wxList m_documentViews;
};