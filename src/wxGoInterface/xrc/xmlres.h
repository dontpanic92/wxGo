%typedef int wxXmlResourceFlags;
#define wxXRC_USE_LOCALE      1
#define wxXRC_NO_SUBCLASSING  2
#define wxXRC_NO_RELOADING    4
WXGO_DECL_TYPECONV(XmlResource)
class wxXmlResource : public wxObject
{
public:
    wxXmlResource(const wxString& filemask,
                  int flags = wxXRC_USE_LOCALE,
                  const wxString& domain = wxEmptyString);
    wxXmlResource(int flags = wxXRC_USE_LOCALE,
                  const wxString& domain = wxEmptyString);
    virtual ~wxXmlResource();
    void AddHandler(wxXmlResourceHandler* handler);
    void InsertHandler(wxXmlResourceHandler *handler);
    bool AttachUnknownControl(const wxString& name,
                              wxWindow* control,
                              wxWindow* parent = NULL);
    void ClearHandlers();
    static void AddSubclassFactory(wxXmlSubclassFactory *factory);
    int CompareVersion(int major, int minor, int release, int revision) const;
    static wxString FindXRCIDById(int numId);
    static wxXmlResource* Get();
    const wxString& GetDomain() const;
    int GetFlags() const;
    const wxXmlNode *GetResourceNode(const wxString& name) const;
    long GetVersion() const;
    static int GetXRCID(const wxString& str_id, int value_if_not_found = wxID_NONE);
    void InitAllHandlers();
    bool Load(const wxString& filemask);
    bool LoadFile(const wxFileName& file);
    bool LoadAllFiles(const wxString& dirname);
    wxBitmap LoadBitmap(const wxString& name);
    wxDialog* LoadDialog(wxWindow* parent, const wxString& name);
    bool LoadDialog(wxDialog* dlg, wxWindow* parent, const wxString& name);
    wxFrame *LoadFrame(wxWindow* parent, const wxString& name);
    bool LoadFrame(wxFrame* frame, wxWindow* parent,
                   const wxString& name);
    wxIcon LoadIcon(const wxString& name);
    wxMenu* LoadMenu(const wxString& name);
    wxMenuBar* LoadMenuBar(wxWindow* parent, const wxString& name);
    wxMenuBar* LoadMenuBar(const wxString& name);
    wxObject* LoadObject(wxWindow* parent, const wxString& name,
                         const wxString& classname);
    bool LoadObject(wxObject* instance, wxWindow* parent,
                    const wxString& name,
                    const wxString& classname);
    wxObject* LoadObjectRecursively(wxWindow* parent,
                                    const wxString& name,
                                    const wxString& classname);
    bool LoadObjectRecursively(wxObject* instance, wxWindow* parent,
                    const wxString& name,
                    const wxString& classname);
    wxPanel* LoadPanel(wxWindow* parent, const wxString& name);
    bool LoadPanel(wxPanel* panel, wxWindow* parent, const wxString& name);
    wxToolBar* LoadToolBar(wxWindow* parent, const wxString& name);
    static wxXmlResource* Set(wxXmlResource* res);
    void SetDomain(const wxString& domain);
    void SetFlags(int flags);
    bool Unload(const wxString& filename);
protected:
    void ReportError(const wxXmlNode *context, const wxString& message);
    virtual void DoReportError(const wxString& xrcFile, const wxXmlNode *position,
                               const wxString& message);
};
WXGO_DECL_TYPECONV(XmlResourceHandler)
class wxXmlResourceHandler : public wxObject
{
public:
    wxXmlResourceHandler();
    virtual ~wxXmlResourceHandler();
    wxObject* CreateResource(wxXmlNode* node, wxObject* parent,
                             wxObject* instance);
    virtual wxObject* DoCreateResource() = 0;
    virtual bool CanHandle(wxXmlNode* node) = 0;
    void SetParentResource(wxXmlResource* res);
protected:
    void AddStyle(const wxString& name, int value);
    void AddWindowStyles();
    void CreateChildren(wxObject* parent, bool this_hnd_only = false);
    void CreateChildrenPrivately(wxObject* parent,
                                 wxXmlNode* rootnode = NULL);
    wxObject* CreateResFromNode(wxXmlNode* node, wxObject* parent,
                                wxObject* instance = NULL);
    wxAnimation* GetAnimation(const wxString& param = "animation");
    wxBitmap GetBitmap(const wxString& param = "bitmap",
                       const wxArtClient& defaultArtClient = wxART_OTHER,
                       wxSize size = wxDefaultSize);
    wxBitmap GetBitmap(const wxXmlNode* node,
                       const wxArtClient& defaultArtClient = wxART_OTHER,
                       wxSize size = wxDefaultSize);
    bool GetBool(const wxString& param, bool defaultv = false);
    wxColour GetColour(const wxString& param,
                       const wxColour& defaultColour = wxNullColour);
    wxFileSystem& GetCurFileSystem();
    wxCoord GetDimension(const wxString& param, wxCoord defaultv = 0,
                         wxWindow* windowToUse = 0);
    wxDirection GetDirection(const wxString& param, wxDirection dirDefault = wxLEFT);
    wxFont GetFont(const wxString& param = "font");
    int GetID();
    wxIcon GetIcon(const wxString& param = "icon",
                   const wxArtClient& defaultArtClient = wxART_OTHER,
                   wxSize size = wxDefaultSize);
    wxIcon GetIcon(const wxXmlNode* node,
                   const wxArtClient& defaultArtClient = wxART_OTHER,
                   wxSize size = wxDefaultSize);
    wxIconBundle GetIconBundle(const wxString& param,
                               const wxArtClient& defaultArtClient = wxART_OTHER);
    wxImageList *GetImageList(const wxString& param = "imagelist");
    long GetLong(const wxString& param, long defaultv = 0);
    float GetFloat(const wxString& param, float defaultv = 0);
    wxString GetName();
    bool IsObjectNode(const wxXmlNode *node) const;
    wxString GetNodeContent(wxXmlNode* node);
    wxXmlNode *GetNodeParent(const wxXmlNode *node) const;
    wxXmlNode *GetNodeNext(const wxXmlNode *node) const;
    wxXmlNode *GetNodeChildren(const wxXmlNode *node) const;
    wxXmlNode* GetParamNode(const wxString& param);
    wxString GetParamValue(const wxString& param);
    wxString GetParamValue(const wxXmlNode* node);
    wxPoint GetPosition(const wxString& param = "pos");
    wxSize GetSize(const wxString& param = "size", wxWindow* windowToUse = 0);
    int GetStyle(const wxString& param = "style", int defaults = 0);
    wxString GetText(const wxString& param, bool translate = true);
    bool HasParam(const wxString& param);
    bool IsOfClass(wxXmlNode* node, const wxString& classname);
    void SetupWindow(wxWindow* wnd);
    void ReportError(wxXmlNode *context, const wxString& message);
    void ReportError(const wxString& message);
    void ReportParamError(const wxString& param, const wxString& message);
    wxXmlResource* GetResource() const;
    wxXmlNode* GetNode() const;
    wxString GetClass() const;
    wxObject* GetParent() const;
    wxObject* GetInstance() const;
    wxWindow* GetParentAsWindow() const;    
};