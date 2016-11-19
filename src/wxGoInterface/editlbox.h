#define wxEL_ALLOW_NEW          0x0100
#define wxEL_ALLOW_EDIT         0x0200
#define wxEL_ALLOW_DELETE       0x0400
#define wxEL_NO_REORDER         0x0800
#define wxEL_DEFAULT_STYLE      (wxEL_ALLOW_NEW | wxEL_ALLOW_EDIT | wxEL_ALLOW_DELETE)
WXGO_DECL_TYPECONV(EditableListBox)
class wxEditableListBox : public wxPanel
{
public:
    wxEditableListBox();
    wxEditableListBox(wxWindow* parent, wxWindowID id,
                      const wxString& label,
                      const wxPoint& pos = wxDefaultPosition,
                      const wxSize& size = wxDefaultSize,
                      long style = wxEL_DEFAULT_STYLE,
                      const wxString& name = wxEditableListBoxNameStr);
    virtual ~wxEditableListBox();
    bool Create(wxWindow* parent, wxWindowID id, const wxString& label,
                const wxPoint& pos = wxDefaultPosition,
                const wxSize& size = wxDefaultSize,
                long style = wxEL_DEFAULT_STYLE,
                const wxString& name = wxEditableListBoxNameStr);
    void SetStrings(const wxArrayString& strings);
    void GetStrings(wxArrayString& strings) const;
};