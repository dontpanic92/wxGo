WXGO_DECL_TYPECONV(DocMDIParentFrame)
class wxDocMDIParentFrame : public wxMDIParentFrame
{
public:
    wxDocMDIParentFrame();
    wxDocMDIParentFrame(wxDocManager* manager, wxFrame* parent,
                        wxWindowID id,
                        const wxString& title,
                        const wxPoint& pos = wxDefaultPosition,
                        const wxSize& size = wxDefaultSize,
                        long style = wxDEFAULT_FRAME_STYLE,
                        const wxString& name = wxFrameNameStr);
    virtual ~wxDocMDIParentFrame();
    bool Create(wxDocManager* manager, wxFrame* parent,
                wxWindowID id, const wxString& title,
                const wxPoint& pos = wxDefaultPosition,
                const wxSize& size = wxDefaultSize,
                long style = wxDEFAULT_FRAME_STYLE,
                const wxString& name = wxFrameNameStr);
};
WXGO_DECL_TYPECONV(DocMDIChildFrame)
class wxDocMDIChildFrame : public wxMDIChildFrame
{
public:
    wxDocMDIChildFrame(wxDocument* doc, wxView* view,
                       wxMDIParentFrame* parent, wxWindowID id,
                       const wxString& title,
                       const wxPoint& pos = wxDefaultPosition,
                       const wxSize& size = wxDefaultSize,
                       long style = wxDEFAULT_FRAME_STYLE,
                       const wxString& name = wxFrameNameStr);
    virtual ~wxDocMDIChildFrame();
    wxDocument* GetDocument() const;
    wxView* GetView() const;
    void SetDocument(wxDocument* doc);
    void SetView(wxView* view);
};