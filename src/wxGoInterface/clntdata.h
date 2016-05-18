WXGO_DECL_TYPECONV(ClientDataContainer)
WXGO_DECL_TYPECONV(ClientData)
WXGO_DECL_TYPECONV(StringClientData)
class wxClientDataContainer
{
public:
    wxClientDataContainer();
    virtual ~wxClientDataContainer();
    void* GetClientData() const;
    wxClientData* GetClientObject() const;
    void SetClientData(void* data);
    void SetClientObject(wxClientData* data);
};
class wxClientData
{
public:
    wxClientData();
    virtual ~wxClientData();
};
class wxStringClientData : public wxClientData
{
public:
    wxStringClientData();
    wxStringClientData(const wxString& data);
    const wxString& GetData() const;
    void SetData(const wxString& data);
};