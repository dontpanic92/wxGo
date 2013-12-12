class wxObject
{
public:
    wxObject();
    virtual ~wxObject();
    bool IsSameAs(const wxObject& obj) const;
};

