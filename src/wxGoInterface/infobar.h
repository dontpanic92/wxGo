WXGO_DECL_TYPECONV(InfoBar)
class wxInfoBar : public wxControl
{
public:
    wxInfoBar();
    wxInfoBar(wxWindow *parent, wxWindowID winid = wxID_ANY);
    bool Create(wxWindow *parent, wxWindowID winid = wxID_ANY);
    void AddButton(wxWindowID btnid, const wxString& label = wxString());
    virtual void Dismiss();
    void RemoveButton(wxWindowID btnid);
    void ShowMessage(const wxString& msg, int flags = wxICON_INFORMATION);
    virtual size_t GetButtonCount() const;
    virtual wxWindowID GetButtonId(size_t idx) const;
    virtual bool HasButtonId(wxWindowID btnid) const;
    void SetShowHideEffects(wxShowEffect showEffect, wxShowEffect hideEffect);
    wxShowEffect GetShowEffect() const;
    wxShowEffect GetHideEffect() const;
    void SetEffectDuration(int duration);
    int GetEffectDuration() const;
    virtual bool SetFont(const wxFont& font);
};