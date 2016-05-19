WXGO_DECL_TYPECONV(GenericValidator)
class wxGenericValidator : public wxValidator
{
public:
    wxGenericValidator(const wxGenericValidator& validator);
    wxGenericValidator(bool* valPtr);
    wxGenericValidator(wxString* valPtr);
    wxGenericValidator(int* valPtr);
    wxGenericValidator(wxArrayInt* valPtr);
    wxGenericValidator(wxDateTime* valPtr);
    wxGenericValidator(wxFileName* valPtr);
    wxGenericValidator(float* valPtr);
    wxGenericValidator(double* valPtr);
    virtual ~wxGenericValidator();
    virtual wxObject* Clone() const;
    virtual bool TransferFromWindow();
    virtual bool TransferToWindow();
};