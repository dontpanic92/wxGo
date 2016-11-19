#define wxTheClipboard
WXGO_DECL_TYPECONV(Clipboard)
class wxClipboard : public wxObject
{
public:
    wxClipboard();
    virtual ~wxClipboard();
    virtual bool AddData(wxDataObject* data);
    virtual void Clear();
    virtual void Close();
    virtual bool Flush();
    virtual bool GetData(wxDataObject& data);
    virtual bool IsOpened() const;
    virtual bool IsSupported(const wxDataFormat& format);
    bool IsUsingPrimarySelection() const;
    virtual bool Open();
    virtual bool SetData(wxDataObject* data);
    virtual void UsePrimarySelection(bool primary = false);
    static wxClipboard *Get();
};