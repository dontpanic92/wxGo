WXGO_DECL_TYPECONV(IconLocation)
class wxIconLocation
{
public:
    bool IsOk() const;
    void SetFileName(const wxString& filename);
    const wxString& GetFileName() const;
};