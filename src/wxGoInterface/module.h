WXGO_DECL_TYPECONV(Module)
class wxModule : public wxObject
{
public:
    wxModule();
    virtual ~wxModule();
    virtual void OnExit() = 0;
    virtual bool OnInit() = 0;
protected:
    void AddDependency(wxClassInfo* dep);
    void AddDependency(const char* classname);
};