enum
{
    wxDIRCTRL_DIR_ONLY       = 0x0010,
    wxDIRCTRL_SELECT_FIRST   = 0x0020,
    wxDIRCTRL_SHOW_FILTERS   = 0x0040,
    wxDIRCTRL_3D_INTERNAL    = 0x0080,
    wxDIRCTRL_EDIT_LABELS    = 0x0100,
    wxDIRCTRL_MULTIPLE       = 0x0200,
    wxDIRCTRL_DEFAULT_STYLE  = wxDIRCTRL_3D_INTERNAL
};
WXGO_DECL_TYPECONV(GenericDirCtrl)
class wxGenericDirCtrl : public wxControl
{
public:
    wxGenericDirCtrl();
    wxGenericDirCtrl(wxWindow* parent, wxWindowID id = wxID_ANY,
                     const wxString& dir = wxDirDialogDefaultFolderStr,
                     const wxPoint& pos = wxDefaultPosition,
                     const wxSize& size = wxDefaultSize,
                     long style = wxDIRCTRL_DEFAULT_STYLE,
                     const wxString& filter = wxEmptyString,
                     int defaultFilter = 0,
                     const wxString& name = wxTreeCtrlNameStr);
    virtual ~wxGenericDirCtrl();
    virtual bool CollapsePath(const wxString& path);
    virtual void CollapseTree();
    bool Create(wxWindow* parent, wxWindowID id = wxID_ANY,
                const wxString& dir = wxDirDialogDefaultFolderStr,
                const wxPoint& pos = wxDefaultPosition,
                const wxSize& size = wxDefaultSize,
                long style = wxDIRCTRL_DEFAULT_STYLE,
                const wxString& filter = wxEmptyString, int defaultFilter = 0,
                const wxString& name = wxTreeCtrlNameStr);
    virtual bool ExpandPath(const wxString& path);
    virtual wxString GetDefaultPath() const;
    virtual wxString GetFilePath() const;
    virtual void GetFilePaths(wxArrayString& paths) const;
    virtual wxString GetFilter() const;
    virtual int GetFilterIndex() const;
    virtual wxDirFilterListCtrl* GetFilterListCtrl() const;
    virtual wxString GetPath() const;
    wxString GetPath(wxTreeItemId itemId) const;
    virtual void GetPaths(wxArrayString& paths) const;
    virtual wxTreeItemId GetRootId();
    virtual wxTreeCtrl* GetTreeCtrl() const;
    virtual void Init();
    virtual void ReCreateTree();
    virtual void SetDefaultPath(const wxString& path);
    virtual void SetFilter(const wxString& filter);
    virtual void SetFilterIndex(int n);
    virtual void SetPath(const wxString& path);
    virtual void ShowHidden(bool show);
    virtual void SelectPath(const wxString& path, bool select = true);
    virtual void SelectPaths(const wxArrayString& paths);
    virtual void UnselectAll();
};
WXGO_DECL_TYPECONV(DirFilterListCtrl)
class wxDirFilterListCtrl: public wxChoice
{
public:
    wxDirFilterListCtrl();
    wxDirFilterListCtrl(wxGenericDirCtrl* parent, wxWindowID id = wxID_ANY,
                        const wxPoint& pos = wxDefaultPosition,
                        const wxSize& size = wxDefaultSize,
                        long style = 0);
    bool Create(wxGenericDirCtrl* parent, wxWindowID id = wxID_ANY,
                const wxPoint& pos = wxDefaultPosition,
                const wxSize& size = wxDefaultSize,
                long style = 0);
    virtual ~wxDirFilterListCtrl() {}
    void Init();
    void FillFilterList(const wxString& filter, int defaultFilter);
};
%constant wxEventType wxEVT_DIRCTRL_SELECTIONCHANGED;
%constant wxEventType wxEVT_DIRCTRL_FILEACTIVATED;