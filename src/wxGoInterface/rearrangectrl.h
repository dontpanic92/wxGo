WXGO_DECL_TYPECONV(RearrangeList)
class wxRearrangeList : public wxCheckListBox
{
public:
    wxRearrangeList();
    wxRearrangeList(wxWindow *parent,
                    wxWindowID id,
                    const wxPoint& pos,
                    const wxSize& size,
                    const wxArrayInt& order,
                    const wxArrayString& items,
                    long style = 0,
                    const wxValidator& validator = wxDefaultValidator,
                    const wxString& name = wxRearrangeListNameStr);
    bool Create(wxWindow *parent,
                wxWindowID id,
                const wxPoint& pos,
                const wxSize& size,
                const wxArrayInt& order,
                const wxArrayString& items,
                long style = 0,
                const wxValidator& validator = wxDefaultValidator,
                const wxString& name = wxRearrangeListNameStr);
    const wxArrayInt& GetCurrentOrder() const;
    bool CanMoveCurrentUp() const;
    bool CanMoveCurrentDown() const;
    bool MoveCurrentUp();
    bool MoveCurrentDown();
};
WXGO_DECL_TYPECONV(RearrangeCtrl)
class wxRearrangeCtrl : public wxPanel
{
public:
    wxRearrangeCtrl();
    wxRearrangeCtrl(wxWindow *parent,
                    wxWindowID id,
                    const wxPoint& pos,
                    const wxSize& size,
                    const wxArrayInt& order,
                    const wxArrayString& items,
                    long style = 0,
                    const wxValidator& validator = wxDefaultValidator,
                    const wxString& name = wxRearrangeListNameStr);
    bool Create(wxWindow *parent,
                wxWindowID id,
                const wxPoint& pos,
                const wxSize& size,
                const wxArrayInt& order,
                const wxArrayString& items,
                long style = 0,
                const wxValidator& validator = wxDefaultValidator,
                const wxString& name = wxRearrangeListNameStr);
    wxRearrangeList *GetList() const;
};
WXGO_DECL_TYPECONV(RearrangeDialog)
class wxRearrangeDialog : public wxDialog
{
public:
    wxRearrangeDialog();
    wxRearrangeDialog(wxWindow *parent,
                      const wxString& message,
                      const wxString& title,
                      const wxArrayInt& order,
                      const wxArrayString& items,
                      const wxPoint& pos = wxDefaultPosition,
                      const wxString& name = wxRearrangeDialogNameStr);
    bool Create(wxWindow *parent,
                const wxString& message,
                const wxString& title,
                const wxArrayInt& order,
                const wxArrayString& items,
                const wxPoint& pos = wxDefaultPosition,
                const wxString& name = wxRearrangeDialogNameStr);
    void AddExtraControls(wxWindow *win);
    wxRearrangeList *GetList() const;
    wxArrayInt GetOrder() const;
};