WXGO_DECL_TYPECONV(RichTextXMLHandler)
class wxRichTextXMLHandler : public wxRichTextFileHandler
{
public:
    wxRichTextXMLHandler(const wxString& name = "XML",
                         const wxString& ext = "xml",
                         int type = wxRICHTEXT_TYPE_XML);
    virtual bool CanLoad() const;
    virtual bool CanSave() const;
    bool ExportXML(wxOutputStream& stream, wxRichTextObject& obj, int level);
    bool ImportXML(wxRichTextBuffer* buffer, wxRichTextObject* obj, wxXmlNode* node);
    static void RegisterNodeName(const wxString& nodeName, const wxString& className) { sm_nodeNameToClassMap[nodeName] = className; }
    static void ClearNodeToClassMap() { sm_nodeNameToClassMap.clear(); }
protected:
    virtual bool DoLoadFile(wxRichTextBuffer* buffer, wxInputStream& stream);
    virtual bool DoSaveFile(wxRichTextBuffer* buffer, wxOutputStream& stream);
};