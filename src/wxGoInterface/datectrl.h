enum
{
    wxDP_DEFAULT = 0,
    wxDP_SPIN = 1,
    wxDP_DROPDOWN = 2,
    wxDP_SHOWCENTURY = 4,
    wxDP_ALLOWNONE = 8
};
WXGO_DECL_TYPECONV(DatePickerCtrl)
class wxDatePickerCtrl : public wxControl
{
public:
    wxDatePickerCtrl();
    wxDatePickerCtrl(wxWindow* parent, wxWindowID id,
                     const wxDateTime& dt = wxDefaultDateTime,
                     const wxPoint& pos = wxDefaultPosition,
                     const wxSize& size = wxDefaultSize,
                     long style = wxDP_DEFAULT | wxDP_SHOWCENTURY,
                     const wxValidator& validator = wxDefaultValidator,
                     const wxString& name = "datectrl");
    bool Create(wxWindow* parent, wxWindowID id,
                const wxDateTime& dt = wxDefaultDateTime,
                const wxPoint& pos = wxDefaultPosition,
                const wxSize& size = wxDefaultSize,
                long style = wxDP_DEFAULT | wxDP_SHOWCENTURY,
                const wxValidator& validator = wxDefaultValidator,
                const wxString& name = "datectrl");
    virtual bool GetRange(wxDateTime* dt1, wxDateTime* dt2) const;
    virtual wxDateTime GetValue() const;
    virtual void SetRange(const wxDateTime& dt1, const wxDateTime& dt2);
    virtual void SetValue(const wxDateTime& dt);
};