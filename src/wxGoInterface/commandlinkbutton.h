WXGO_DECL_TYPECONV(CommandLinkButton)
class wxCommandLinkButton : public wxButton
{
public:
    wxCommandLinkButton();
    wxCommandLinkButton(wxWindow* parent, wxWindowID id,
                        const wxString& mainLabel = wxEmptyString,
                        const wxString& note = wxEmptyString,
                        const wxPoint& pos = wxDefaultPosition,
                        const wxSize& size = wxDefaultSize,
                        long style = 0,
                        const wxValidator& validator = wxDefaultValidator,
                        const wxString& name = wxButtonNameStr);
    bool Create(wxWindow* parent, wxWindowID id,
                const wxString& mainLabel = wxEmptyString,
                const wxString& note = wxEmptyString,
                const wxPoint& pos = wxDefaultPosition,
                const wxSize& size = wxDefaultSize,
                long style = 0,
                const wxValidator& validator = wxDefaultValidator,
                const wxString& name = wxButtonNameStr);
    void SetMainLabelAndNote(const wxString& mainLabel, const wxString& note);
    virtual void SetLabel(const wxString& label);
    wxString GetLabel() const;
    void SetMainLabel(const wxString& mainLabel);
    void SetNote(const wxString& note);
    wxString GetMainLabel() const;
    wxString GetNote() const;
};