#define wxTextEntryDialogStyle (wxOK | wxCANCEL | wxCENTRE)
const char wxGetTextFromUserPromptStr[] = "Input Text";
const char wxGetPasswordFromUserPromptStr[] = "Enter Password";
WXGO_DECL_TYPECONV(TextEntryDialog)
class wxTextEntryDialog : public wxDialog
{
public:
    wxTextEntryDialog();
    wxTextEntryDialog(wxWindow* parent, const wxString& message,
                      const wxString& caption = wxGetTextFromUserPromptStr,
                      const wxString& value = wxEmptyString,
                      long style = wxTextEntryDialogStyle,
                      const wxPoint& pos = wxDefaultPosition);
    bool Create(wxWindow* parent, const wxString& message,
                      const wxString& caption = wxGetTextFromUserPromptStr,
                      const wxString& value = wxEmptyString,
                      long style = wxTextEntryDialogStyle,
                      const wxPoint& pos = wxDefaultPosition);
    virtual ~wxTextEntryDialog();
    wxString GetValue() const;
    void SetTextValidator(const wxTextValidator& validator);
    void SetTextValidator(wxTextValidatorStyle style = wxFILTER_NONE);
    void SetMaxLength(unsigned long len);
    void SetValue(const wxString& value);
    void ForceUpper();
    int ShowModal();
};
WXGO_DECL_TYPECONV(PasswordEntryDialog)
class wxPasswordEntryDialog : public wxTextEntryDialog
{
public:
    wxPasswordEntryDialog(wxWindow* parent, const wxString& message,
                          const wxString& caption = wxGetPasswordFromUserPromptStr,
                          const wxString& defaultValue = wxEmptyString,
                          long style = wxTextEntryDialogStyle,
                          const wxPoint& pos = wxDefaultPosition);
};
wxString wxGetTextFromUser(const wxString& message,
                           const wxString& caption = wxGetTextFromUserPromptStr,
                           const wxString& default_value = wxEmptyString,
                           wxWindow* parent = NULL,
                           int x = wxDefaultCoord,
                           int y = wxDefaultCoord,
                           bool centre = true);
wxString wxGetPasswordFromUser(const wxString& message,
                               const wxString& caption = wxGetPasswordFromUserPromptStr,
                               const wxString& default_value = wxEmptyString,
                               wxWindow* parent = NULL,
                               int x = wxDefaultCoord,
                               int y = wxDefaultCoord,
                               bool centre = true);