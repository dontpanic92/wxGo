WXGO_DECL_TYPECONV(Validator)
class wxValidator : public wxEvtHandler
{
public:
    wxValidator();
    virtual ~wxValidator();
    virtual wxObject* Clone() const;
    wxWindow* GetWindow() const;
    static void SuppressBellOnError(bool suppress = true);
    static bool IsSilent();
    void SetWindow(wxWindow* window);
    virtual bool TransferFromWindow();
    virtual bool TransferToWindow();
    virtual bool Validate(wxWindow* parent);
};
WXGO_GETTER_TO_VAR(Validator, DefaultValidator);
const wxValidator wxDefaultValidator;