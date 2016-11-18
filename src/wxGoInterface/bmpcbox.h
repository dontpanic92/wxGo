WXGO_DECL_TYPECONV(BitmapComboBox)
class wxBitmapComboBox : public wxComboBox
{
public:
    wxBitmapComboBox();
    wxBitmapComboBox(wxWindow* parent, wxWindowID id = wxID_ANY,
                     const wxString& value = wxEmptyString,
                     const wxPoint& pos = wxDefaultPosition,
                     const wxSize& size = wxDefaultSize,
                     int n = 0,
                     const wxString choices[] = NULL,
                     long style = 0,
                     const wxValidator& validator = wxDefaultValidator,
                     const wxString& name = wxBitmapComboBoxNameStr);
    wxBitmapComboBox(wxWindow* parent, wxWindowID id,
                     const wxString& value,
                     const wxPoint& pos,
                     const wxSize& size,
                     const wxArrayString& choices,
                     long style,
                     const wxValidator& validator = wxDefaultValidator,
                     const wxString& name = wxBitmapComboBoxNameStr);
    virtual ~wxBitmapComboBox();
    int Append(const wxString& item,
               const wxBitmap& bitmap = wxNullBitmap);
    int Append(const wxString& item, const wxBitmap& bitmap,
               void* clientData);
    int Append(const wxString& item, const wxBitmap& bitmap,
               wxClientData* clientData);
    bool Create(wxWindow* parent, wxWindowID id,
                const wxString& value,
                const wxPoint& pos,
                const wxSize& size,
                int n, const wxString choices[],
                long style = 0,
                const wxValidator& validator = wxDefaultValidator,
                const wxString& name = wxBitmapComboBoxNameStr);
    bool Create(wxWindow* parent, wxWindowID id,
                const wxString& value,
                const wxPoint& pos,
                const wxSize& size,
                const wxArrayString& choices,
                long style = 0,
                const wxValidator& validator = wxDefaultValidator,
                const wxString& name = wxBitmapComboBoxNameStr);
    virtual wxSize GetBitmapSize() const;
    virtual wxBitmap GetItemBitmap(unsigned int n) const;
    int Insert(const wxString& item, const wxBitmap& bitmap,
               unsigned int pos);
    int Insert(const wxString& item, const wxBitmap& bitmap,
               unsigned int pos,
               void* clientData);
    int Insert(const wxString& item, const wxBitmap& bitmap,
               unsigned int pos,
               wxClientData* clientData);
    virtual void SetItemBitmap(unsigned int n, const wxBitmap& bitmap);
};