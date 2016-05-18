WXGO_DECL_TYPECONV(Object)
class wxObject
{
public:
    wxObject();
    virtual ~wxObject();
    bool IsSameAs(const wxObject& obj) const;
};