struct wxPropertyGridHitTestResult
{
public:
    wxPGProperty* GetProperty() const { return property; }
    int GetColumn() const;
    int GetSplitter() const;
    int GetSplitterHitOffset() const;
private:
    wxPGProperty*   property;
};
#define wxPG_IT_CHILDREN(A)         (A<<16)
%typedef int wxPG_ITERATOR_FLAGS;
#define wxPG_ITERATE_PROPERTIES              (wxPG_PROP_PROPERTY|wxPG_PROP_MISC_PARENT|wxPG_PROP_AGGREGATE| \                                       wxPG_PROP_COLLAPSED|((wxPG_PROP_MISC_PARENT|wxPG_PROP_CATEGORY)<<16))
#define wxPG_ITERATE_HIDDEN                  (wxPG_PROP_HIDDEN|wxPG_IT_CHILDREN(wxPG_PROP_COLLAPSED))
#define wxPG_ITERATE_FIXED_CHILDREN          (wxPG_IT_CHILDREN(wxPG_PROP_AGGREGATE)|wxPG_ITERATE_PROPERTIES)
#define wxPG_ITERATE_CATEGORIES              (wxPG_PROP_CATEGORY|wxPG_IT_CHILDREN(wxPG_PROP_CATEGORY)|wxPG_PROP_COLLAPSED)
#define wxPG_ITERATE_ALL_PARENTS             (wxPG_PROP_MISC_PARENT|wxPG_PROP_AGGREGATE|wxPG_PROP_CATEGORY)
#define wxPG_ITERATE_ALL_PARENTS_RECURSIVELY         (wxPG_ITERATE_ALL_PARENTS|wxPG_IT_CHILDREN(wxPG_ITERATE_ALL_PARENTS))
#define wxPG_ITERATOR_FLAGS_ALL              (wxPG_PROP_PROPERTY|wxPG_PROP_MISC_PARENT|wxPG_PROP_AGGREGATE| \                                      wxPG_PROP_HIDDEN|wxPG_PROP_CATEGORY|wxPG_PROP_COLLAPSED)
#define wxPG_ITERATOR_MASK_OP_ITEM           wxPG_ITERATOR_FLAGS_ALL
#define wxPG_ITERATOR_MASK_OP_PARENT         wxPG_ITERATOR_FLAGS_ALL
#define wxPG_ITERATE_VISIBLE                 (wxPG_ITERATE_PROPERTIES|wxPG_PROP_CATEGORY|wxPG_IT_CHILDREN(wxPG_PROP_AGGREGATE))
#define wxPG_ITERATE_ALL                     (wxPG_ITERATE_VISIBLE|wxPG_ITERATE_HIDDEN)
#define wxPG_ITERATE_NORMAL                  (wxPG_ITERATE_PROPERTIES|wxPG_ITERATE_HIDDEN)
#define wxPG_ITERATE_DEFAULT                 wxPG_ITERATE_NORMAL
WXGO_DECL_TYPECONV(PropertyGridIteratorBase)
class wxPropertyGridIteratorBase
{
public:
    wxPropertyGridIteratorBase()
    {
    }
    void Assign( const wxPropertyGridIteratorBase& it );
    bool AtEnd() const { return m_property == NULL; }
    wxPGProperty* GetProperty() const { return m_property; }
    void Init( wxPropertyGridPageState* state,
               int flags,
               wxPGProperty* property,
               int dir = 1 );
    void Init( wxPropertyGridPageState* state,
               int flags,
               int startPos = wxTOP,
               int dir = 0 );
    void Next( bool iterateChildren = true );
    void Prev();
    void SetBaseParent( wxPGProperty* baseParent )
        { m_baseParent = baseParent; }
protected:
};
WXGO_DECL_TYPECONV(PropertyGridIterator)
class wxPropertyGridIterator : public wxPropertyGridIteratorBase
{
public:
    void Assign( const wxPropertyGridIteratorBase& it );
    bool AtEnd() const { return m_property == NULL; }
    wxPGProperty* GetProperty() const { return m_property; }
    void Next( bool iterateChildren = true );
    void Prev();
protected:
};
WXGO_DECL_TYPECONV(PGVIterator)
class wxPGVIterator
{
public:
    wxPGVIterator() { m_pIt = NULL; }
    wxPGVIterator( wxPGVIteratorBase* obj ) { m_pIt = obj; }
    ~wxPGVIterator() { UnRef(); }
    void UnRef() { if (m_pIt) m_pIt->DecRef(); }
    wxPGVIterator( const wxPGVIterator& it )
    {
        m_pIt = it.m_pIt;
        m_pIt->IncRef();
    }
    const wxPGVIterator& operator=( const wxPGVIterator& it )
    {
        UnRef();
        m_pIt = it.m_pIt;
        m_pIt->IncRef();
        return *this;
    }
    void Next() { m_pIt->Next(); }
    bool AtEnd() const { return m_pIt->m_it.AtEnd(); }
    wxPGProperty* GetProperty() const { return m_pIt->m_it.GetProperty(); }
protected:
    wxPGVIteratorBase*  m_pIt;
};