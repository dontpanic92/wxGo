%typedef int wxXmlNodeType;
#define wxXML_ELEMENT_NODE        1
#define wxXML_ATTRIBUTE_NODE      2
#define wxXML_TEXT_NODE           3
#define wxXML_CDATA_SECTION_NODE  4
#define wxXML_ENTITY_REF_NODE     5
#define wxXML_ENTITY_NODE         6
#define wxXML_PI_NODE             7
#define wxXML_COMMENT_NODE        8
#define wxXML_DOCUMENT_NODE       9
#define wxXML_DOCUMENT_TYPE_NODE  10
#define wxXML_DOCUMENT_FRAG_NODE  11
#define wxXML_NOTATION_NODE       12
#define wxXML_HTML_DOCUMENT_NODE  13
WXGO_DECL_TYPECONV(XmlNode)
class wxXmlNode
{
public:
    wxXmlNode(wxXmlNode* parent, wxXmlNodeType type,
              const wxString& name,
              const wxString& content = wxEmptyString,
              wxXmlAttribute* attrs = NULL,
              wxXmlNode* next = NULL, int lineNo = -1);
    wxXmlNode(wxXmlNodeType type, const wxString& name,
              const wxString& content = wxEmptyString,
              int lineNo = -1);
    wxXmlNode(const wxXmlNode& node);
    virtual ~wxXmlNode();
    virtual void AddAttribute(const wxString& name, const wxString& value);
    virtual void AddAttribute(wxXmlAttribute* attr);
    virtual void AddChild(wxXmlNode* child);
    virtual bool DeleteAttribute(const wxString& name);
    wxString GetAttribute(const wxString& attrName,
                          const wxString& defaultVal = wxEmptyString) const;
    wxXmlAttribute* GetAttributes() const;
    wxXmlNode* GetChildren() const;
    const wxString& GetContent() const;
    int GetDepth(wxXmlNode* grandparent = NULL) const;
    bool GetNoConversion() const;
    int GetLineNumber() const;
    const wxString& GetName() const;
    wxXmlNode* GetNext() const;
    wxString GetNodeContent() const;
    wxXmlNode* GetParent() const;
    wxXmlNodeType GetType() const;
    bool HasAttribute(const wxString& attrName) const;
    virtual bool InsertChild(wxXmlNode* child, wxXmlNode* followingNode);
    virtual bool InsertChildAfter(wxXmlNode* child, wxXmlNode* precedingNode);
    bool IsWhitespaceOnly() const;
    virtual bool RemoveChild(wxXmlNode* child);
    void SetAttributes(wxXmlAttribute* attr);
    void SetChildren(wxXmlNode* child);
    void SetContent(const wxString& con);
    void SetName(const wxString& name);
    void SetNext(wxXmlNode* next);
    void SetNoConversion(bool noconversion);
    void SetParent(wxXmlNode* parent);
    void SetType(wxXmlNodeType type);
    wxXmlNode& operator=(const wxXmlNode& node);
};
WXGO_DECL_TYPECONV(XmlAttribute)
class wxXmlAttribute
{
public:
    wxXmlAttribute();
    wxXmlAttribute(const wxString& name, const wxString& value,
                   wxXmlAttribute* next = NULL);
    virtual ~wxXmlAttribute();
    wxString GetName() const;
    wxXmlAttribute* GetNext() const;
    wxString GetValue() const;
    void SetName(const wxString& name);
    void SetNext(wxXmlAttribute* next);
    void SetValue(const wxString& value);
};
WXGO_DECL_TYPECONV(XmlDoctype)
class wxXmlDoctype
{
public:
    wxXmlDoctype(const wxString& rootName = wxString(),
                 const wxString& systemId = wxString(),
                 const wxString& publicId = wxString());
    void Clear();
    const wxString& GetRootName() const;
    const wxString& GetSystemId() const;
    const wxString& GetPublicId() const;
    wxString GetFullString() const;
    bool IsValid() const;
};
#define wxXML_NO_INDENTATION           (-1)
%typedef int wxXmlDocumentLoadFlag;
#define wxXMLDOC_NONE 0
#define wxXMLDOC_KEEP_WHITESPACE_NODES wxXMLDOC_NONE + 1
WXGO_DECL_TYPECONV(XmlDocument)
class wxXmlDocument : public wxObject
{
public:
    wxXmlDocument();
    wxXmlDocument(const wxXmlDocument& doc);
    wxXmlDocument(const wxString& filename,
                  const wxString& encoding = "UTF-8");
    wxXmlDocument(wxInputStream& stream,
                  const wxString& encoding = "UTF-8");
    virtual ~wxXmlDocument();
    void AppendToProlog(wxXmlNode* node);
    wxXmlNode* DetachDocumentNode();
    wxXmlNode* DetachRoot();
    const wxString& GetFileEncoding() const;
    const wxXmlDoctype& GetDoctype() const;
    wxXmlNode* GetDocumentNode() const;
    wxXmlNode* GetRoot() const;
    const wxString& GetVersion() const;
    bool IsOk() const;
    virtual bool Load(const wxString& filename,
                      const wxString& encoding = "UTF-8", int flags = wxXMLDOC_NONE);
    virtual bool Load(wxInputStream& stream,
                      const wxString& encoding = "UTF-8", int flags = wxXMLDOC_NONE);
    virtual bool Save(const wxString& filename, int indentstep = 2) const;
    virtual bool Save(wxOutputStream& stream, int indentstep = 2) const;
    void SetDocumentNode(wxXmlNode* node);
    void SetFileEncoding(const wxString& encoding);
    void SetDoctype(const wxXmlDoctype& doctype);
    void SetRoot(wxXmlNode* node);
    void SetVersion(const wxString& version);
    wxXmlDocument& operator=(const wxXmlDocument& doc);
    static wxVersionInfo GetLibraryVersionInfo();
};