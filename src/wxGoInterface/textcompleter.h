WXGO_DECL_TYPECONV(TextCompleter)
class wxTextCompleter
{
public:
    virtual bool Start(const wxString& prefix) = 0;
    virtual wxString GetNext() = 0;
};
WXGO_DECL_TYPECONV(TextCompleterSimple)
class wxTextCompleterSimple : public wxTextCompleter
{
public:
    virtual void GetCompletions(const wxString& prefix, wxArrayString& res) = 0;
};