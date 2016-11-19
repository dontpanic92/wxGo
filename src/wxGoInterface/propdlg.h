%typedef int wxPropertySheetDialogFlags;
#define wxPROPSHEET_DEFAULT  0x0001
#define wxPROPSHEET_NOTEBOOK  0x0002
#define wxPROPSHEET_TOOLBOOK  0x0004
#define wxPROPSHEET_CHOICEBOOK  0x0008
#define wxPROPSHEET_LISTBOOK  0x0010
#define wxPROPSHEET_BUTTONTOOLBOOK  0x0020
#define wxPROPSHEET_TREEBOOK  0x0040
#define wxPROPSHEET_SHRINKTOFIT  0x0100
WXGO_DECL_TYPECONV(PropertySheetDialog)
class wxPropertySheetDialog : public wxDialog
{
public:
    wxPropertySheetDialog(wxWindow* parent, wxWindowID id,
                          const wxString& title,
                          const wxPoint& pos = wxDefaultPosition,
                          const wxSize& size = wxDefaultSize,
                          long style = wxDEFAULT_DIALOG_STYLE,
                          const wxString& name = wxDialogNameStr);
    virtual void AddBookCtrl(wxSizer* sizer);
    bool Create(wxWindow* parent, wxWindowID id, const wxString& title,
                const wxPoint& pos = wxDefaultPosition,
                const wxSize& size = wxDefaultSize,
                long style = wxDEFAULT_DIALOG_STYLE,
                const wxString& name = wxDialogNameStr);
    virtual wxBookCtrlBase* CreateBookCtrl();
    virtual void CreateButtons(int flags = wxOK|wxCANCEL);
    wxBookCtrlBase* GetBookCtrl() const;
    wxSizer* GetInnerSizer() const;
    long GetSheetStyle() const;
    virtual void LayoutDialog(int centreFlags = wxBOTH);
    void SetBookCtrl(wxBookCtrlBase* bookCtrl);
    void SetSheetStyle(long style);
};