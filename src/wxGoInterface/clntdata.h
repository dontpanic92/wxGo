WXGO_DECL_TYPECONV(ClientDataContainer)
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
WXGO_DECL_TYPECONV(ClientData)
class wxClientData
{
public:
    wxClientData();
    virtual ~wxClientData();
};
WXGO_DECL_TYPECONV(StringClientData)
class wxStringClientData : public wxClientData
{
public:
    wxStringClientData();
    wxStringClientData(const wxString& data);
    const wxString& GetData() const;
    void SetData(const wxString& data);
};