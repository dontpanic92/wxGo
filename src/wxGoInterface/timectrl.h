enum
{
    wxTP_DEFAULT = 0
};
WXGO_DECL_TYPECONV(TimePickerCtrl)
class wxTimePickerCtrl : public wxControl
{
public:
    wxTimePickerCtrl();
    wxTimePickerCtrl(wxWindow* parent, wxWindowID id,
                     const wxDateTime& dt = wxDefaultDateTime,
                     const wxPoint& pos = wxDefaultPosition,
                     const wxSize& size = wxDefaultSize,
                     long style = wxTP_DEFAULT,
                     const wxValidator& validator = wxDefaultValidator,
                     const wxString& name = "timectrl");
    bool Create(wxWindow* parent, wxWindowID id,
                const wxDateTime& dt = wxDefaultDateTime,
                const wxPoint& pos = wxDefaultPosition,
                const wxSize& size = wxDefaultSize,
                long style = wxDP_DEFAULT | wxDP_SHOWCENTURY,
                const wxValidator& validator = wxDefaultValidator,
                const wxString& name = "timectrl");
    bool GetTime(int* hour, int* min, int* sec) const;
    virtual wxDateTime GetValue() const;
    bool SetTime(int hour, int min, int sec);
    virtual void SetValue(const wxDateTime& dt);
};