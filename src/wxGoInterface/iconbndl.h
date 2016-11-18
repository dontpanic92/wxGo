WXGO_DECL_TYPECONV(IconBundle)
class wxIconBundle : public wxGDIObject
{
public:
    enum
    {
        FALLBACK_NONE = 0,
        FALLBACK_SYSTEM = 1,
        FALLBACK_NEAREST_LARGER = 2
    };
    wxIconBundle();
    wxIconBundle(const wxString& file, wxBitmapType type = wxBITMAP_TYPE_ANY);
    wxIconBundle(wxInputStream& stream, wxBitmapType type = wxBITMAP_TYPE_ANY);
    wxIconBundle(const wxIcon& icon);
    wxIconBundle(const wxIconBundle& ic);
    virtual ~wxIconBundle();
    void AddIcon(const wxString& file, wxBitmapType type = wxBITMAP_TYPE_ANY);
    void AddIcon(wxInputStream& stream, wxBitmapType type = wxBITMAP_TYPE_ANY);
    void AddIcon(const wxIcon& icon);
    wxIcon GetIcon(const wxSize& size, int flags = FALLBACK_SYSTEM) const;
    wxIcon GetIcon(wxCoord size = wxDefaultCoord,
                   int flags = FALLBACK_SYSTEM) const;
    wxIcon GetIconOfExactSize(const wxSize& size) const;
    size_t GetIconCount() const;
    wxIcon GetIconByIndex(size_t n) const;
    bool IsEmpty() const;
    wxIconBundle& operator=(const wxIconBundle& ic);
};
wxIconBundle wxNullIconBundle;