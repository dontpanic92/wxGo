#define wxPB_USE_TEXTCTRL           0x0002
#define wxPB_SMALL                  0x8000
WXGO_DECL_TYPECONV(PickerBase)
class wxPickerBase : public wxControl
{
public:
    wxPickerBase();
    virtual ~wxPickerBase();
    bool CreateBase(wxWindow *parent,
                    wxWindowID id,
                    const wxString& text = wxEmptyString,
                    const wxPoint& pos = wxDefaultPosition,
                    const wxSize& size = wxDefaultSize,
                    long style = 0,
                    const wxValidator& validator = wxDefaultValidator,
                    const wxString& name = wxButtonNameStr);
    int GetInternalMargin() const;
    int GetPickerCtrlProportion() const;
    wxTextCtrl* GetTextCtrl();
    wxControl* GetPickerCtrl();
    int GetTextCtrlProportion() const;
    bool HasTextCtrl() const;
    bool IsPickerCtrlGrowable() const;
    bool IsTextCtrlGrowable() const;
    void SetInternalMargin(int margin);
    void SetPickerCtrlGrowable(bool grow = true);
    void SetPickerCtrlProportion(int prop);
    void SetTextCtrlGrowable(bool grow = true);
    void SetTextCtrlProportion(int prop);
    void SetTextCtrl(wxTextCtrl* text);
    void SetPickerCtrl(wxControl* picker);
    virtual void UpdatePickerFromTextCtrl() = 0;
    virtual void UpdateTextCtrlFromPicker() = 0;
protected:
    virtual long GetTextCtrlStyle(long style) const;
    virtual long GetPickerStyle(long style) const;
    void PostCreation();
};