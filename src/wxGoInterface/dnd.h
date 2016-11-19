enum
{
    wxDrag_CopyOnly    = 0, 
    wxDrag_AllowMove   = 1, 
    wxDrag_DefaultMove = 3  
};
enum wxDragResult
{
    wxDragError,    
    wxDragNone,     
    wxDragCopy,     
    wxDragMove,     
    wxDragLink,     
    wxDragCancel    
};
WXGO_DECL_TYPECONV(DropTarget)
class wxDropTarget
{
public:
    wxDropTarget(wxDataObject* data = NULL);
    virtual ~wxDropTarget();
    virtual bool GetData();
    virtual wxDragResult OnData(wxCoord x, wxCoord y, wxDragResult defResult) = 0;
    virtual wxDragResult OnDragOver(wxCoord x, wxCoord y, wxDragResult defResult);
    virtual bool OnDrop(wxCoord x, wxCoord y);
    virtual wxDragResult OnEnter(wxCoord x, wxCoord y, wxDragResult defResult);
    virtual void OnLeave();
    wxDataObject *GetDataObject() const;
    void SetDataObject(wxDataObject* data);
    void SetDefaultAction(wxDragResult action);
    wxDragResult GetDefaultAction();
};
WXGO_DECL_TYPECONV(DropSource)
class wxDropSource
{
public:
#if defined(__WXMSW__) || defined(__WXOSX__)
    wxDropSource(wxWindow* win = NULL,
                 const wxCursor& iconCopy = wxNullCursor,
                 const wxCursor& iconMove = wxNullCursor,
                 const wxCursor& iconNone = wxNullCursor);
#endif
#if defined(__WXMSW__) || defined(__WXOSX__) 
    wxDropSource(wxDataObject& data, wxWindow* win,
                 const wxCursor& iconCopy = wxNullCursor,
                 const wxCursor& iconMove = wxNullCursor,
                 const wxCursor& iconNone = wxNullCursor);
#endif
#ifdef __WXGTK__
    wxDropSource(wxWindow* win = NULL,
                 const wxIcon& iconCopy = wxNullIcon,
                 const wxIcon& iconMove = wxNullIcon,
                 const wxIcon& iconNone = wxNullIcon);
#endif
#ifdef __WXGTK__
    wxDropSource(wxDataObject& data, wxWindow* win,
                 const wxIcon& iconCopy = wxNullIcon,
                 const wxIcon& iconMove = wxNullIcon,
                 const wxIcon& iconNone = wxNullIcon);
#endif
    virtual wxDragResult DoDragDrop(int flags = wxDrag_CopyOnly);
    wxDataObject* GetDataObject();
    virtual bool GiveFeedback(wxDragResult effect);
#if defined(__WXMSW__) || defined(__WXOSX__)
    void SetCursor(wxDragResult res, const wxCursor& cursor);
#endif
#ifdef __WXGTK__
    void SetIcon(wxDragResult res, const wxIcon& icon);
#endif
    void SetData(wxDataObject& data);
};
WXGO_DECL_TYPECONV(TextDropTarget)
class wxTextDropTarget : public wxDropTarget
{
public:
    wxTextDropTarget();
    virtual bool OnDrop(wxCoord x, wxCoord y);
    virtual bool OnDropText(wxCoord x, wxCoord y, const wxString& data) = 0;
};
WXGO_DECL_TYPECONV(FileDropTarget)
class wxFileDropTarget : public wxDropTarget
{
public:
    wxFileDropTarget();
    virtual bool OnDrop(wxCoord x, wxCoord y);
    virtual bool OnDropFiles(wxCoord x, wxCoord y,
                             const wxArrayString& filenames) = 0;
};
#define wxDROP_ICON(name)
bool wxIsDragResultOk(wxDragResult res);