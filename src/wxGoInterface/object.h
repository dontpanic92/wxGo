WXGO_DECL_TYPECONV(RefCounter)
WXGO_DECL_TYPECONV(Object)
WXGO_DECL_TYPECONV(ClassInfo)
typedef wxRefCounter wxObjectRefData;
class wxRefCounter
{
protected:
    virtual ~wxRefCounter();
public:
    wxRefCounter();
    void DecRef();
    int GetRefCount() const;
    void IncRef();
};
class wxObject
{
public:
    wxObject();
    wxObject(const wxObject& other);
    virtual ~wxObject();
    virtual wxClassInfo* GetClassInfo() const;
    wxObjectRefData* GetRefData() const;
    bool IsKindOf(const wxClassInfo* info) const;
    bool IsSameAs(const wxObject& obj) const;
    void Ref(const wxObject& clone);
    void SetRefData(wxObjectRefData* data);
    void UnRef();
    void UnShare();
protected:
    void AllocExclusive();
    virtual wxObjectRefData *CreateRefData() const;
    virtual wxObjectRefData *CloneRefData(const wxObjectRefData *data) const;
    wxObjectRefData* m_refData;
};
class wxClassInfo
{
public:
    wxClassInfo(const wxChar* className,
                const wxClassInfo* baseClass1,
                const wxClassInfo* baseClass2,
                int size, wxObjectConstructorFn fn);
    wxObject* CreateObject() const;
    static wxClassInfo* FindClass(const wxString& className);
    const wxChar* GetBaseClassName1() const;
    const wxChar* GetBaseClassName2() const;
    const wxChar* GetClassName() const;
    int GetSize() const;
    bool IsDynamic() const;
    bool IsKindOf(const wxClassInfo* info) const;
};
wxObject *wxCreateDynamicObject(const wxString& className);