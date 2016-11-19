%typedef int wxRibbonGalleryButtonState;
#define wxRIBBON_GALLERY_BUTTON_NORMAL 0
#define wxRIBBON_GALLERY_BUTTON_HOVERED wxRIBBON_GALLERY_BUTTON_NORMAL + 1
#define wxRIBBON_GALLERY_BUTTON_ACTIVE wxRIBBON_GALLERY_BUTTON_HOVERED + 1
#define wxRIBBON_GALLERY_BUTTON_DISABLED wxRIBBON_GALLERY_BUTTON_ACTIVE + 1
WXGO_DECL_TYPECONV(RibbonGallery)
class wxRibbonGallery : public wxRibbonControl
{
public:
    wxRibbonGallery();
    wxRibbonGallery(wxWindow* parent,
                  wxWindowID id = wxID_ANY,
                  const wxPoint& pos = wxDefaultPosition,
                  const wxSize& size = wxDefaultSize,
                  long style = 0);
    virtual ~wxRibbonGallery();
    bool Create(wxWindow* parent,
                wxWindowID id = wxID_ANY,
                const wxPoint& pos = wxDefaultPosition,
                const wxSize& size = wxDefaultSize,
                long style = 0);
    void Clear();
    bool IsEmpty() const;
    unsigned int GetCount() const;
    wxRibbonGalleryItem* GetItem(unsigned int n);
    wxRibbonGalleryItem* Append(const wxBitmap& bitmap, int id);
    wxRibbonGalleryItem* Append(const wxBitmap& bitmap, int id, void* clientData);
    wxRibbonGalleryItem* Append(const wxBitmap& bitmap, int id, wxClientData* clientData);
    void SetItemClientObject(wxRibbonGalleryItem* item, wxClientData* data);
    wxClientData* GetItemClientObject(const wxRibbonGalleryItem* item) const;
    void SetItemClientData(wxRibbonGalleryItem* item, void* data);
    void* GetItemClientData(const wxRibbonGalleryItem* item) const;
    void SetSelection(wxRibbonGalleryItem* item);
    wxRibbonGalleryItem* GetSelection() const;
    wxRibbonGalleryItem* GetHoveredItem() const;
    wxRibbonGalleryItem* GetActiveItem() const;
    wxRibbonGalleryButtonState GetUpButtonState() const;
    wxRibbonGalleryButtonState GetDownButtonState() const;
    wxRibbonGalleryButtonState GetExtensionButtonState() const;
    bool IsHovered() const;
    virtual bool ScrollLines(int lines);
    bool ScrollPixels(int pixels);
    void EnsureVisible(const wxRibbonGalleryItem* item);
};
WXGO_DECL_TYPECONV(RibbonGalleryEvent)
class wxRibbonGalleryEvent : public wxCommandEvent
{
public:
    wxRibbonGalleryEvent(wxEventType command_type = wxEVT_NULL,
                         int win_id = 0,
                         wxRibbonGallery* gallery = NULL,
                         wxRibbonGalleryItem* item = NULL);
    wxRibbonGallery* GetGallery();
    wxRibbonGalleryItem* GetGalleryItem();
    void SetGallery(wxRibbonGallery* gallery);
    void SetGalleryItem(wxRibbonGalleryItem* item);
};