#define wxCHK_2STATE           0x4000
#define wxCHK_3STATE           0x1000
#define wxCHK_ALLOW_3RD_STATE_FOR_USER 0x2000
%typedef int wxCheckBoxState;
#define wxCHK_UNCHECKED 0
#define wxCHK_CHECKED wxCHK_UNCHECKED + 1
#define wxCHK_UNDETERMINED wxCHK_CHECKED + 1
WXGO_DECL_TYPECONV(CheckBox)
class wxCheckBox : public wxControl
{
public:
    wxCheckBox();
    wxCheckBox(wxWindow* parent, wxWindowID id,
               const wxString& label,
               const wxPoint& pos = wxDefaultPosition,
               const wxSize& size = wxDefaultSize,
               long style = 0,
               const wxValidator& validator = wxDefaultValidator,
               const wxString& name = wxCheckBoxNameStr);
    virtual ~wxCheckBox();
    bool Create(wxWindow* parent, wxWindowID id, const wxString& label,
                const wxPoint& pos = wxDefaultPosition,
                const wxSize& size = wxDefaultSize, long style = 0,
                const wxValidator& validator = wxDefaultValidator,
                const wxString& name = wxCheckBoxNameStr);
    virtual bool GetValue() const;
    wxCheckBoxState Get3StateValue() const;
    bool Is3State() const;
    bool Is3rdStateAllowedForUser() const;
    bool IsChecked() const;
    virtual void SetValue(bool state);
    void Set3StateValue(wxCheckBoxState state);
};