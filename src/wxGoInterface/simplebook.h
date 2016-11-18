WXGO_DECL_TYPECONV(Simplebook)
class wxSimplebook : public wxBookCtrlBase
{
public:
    wxSimplebook();
    wxSimplebook(wxWindow* parent,
                 wxWindowID id = wxID_ANY,
                 const wxPoint& pos = wxDefaultPosition,
                 const wxSize& size = wxDefaultSize,
                 long style = 0,
                 const wxString& name = wxEmptyString);
    bool Create(wxWindow* parent,
                wxWindowID id = wxID_ANY,
                const wxPoint& pos = wxDefaultPosition,
                const wxSize& size = wxDefaultSize,
                long style = 0,
                const wxString& name = wxEmptyString);
    void SetEffects(wxShowEffect showEffect, wxShowEffect hideEffect);
    void SetEffect(wxShowEffect effect);
    void SetEffectsTimeouts(unsigned showTimeout, unsigned hideTimeout);
    void SetEffectTimeout(unsigned timeout);
    bool ShowNewPage(wxWindow* page);
};