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