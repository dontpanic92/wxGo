#define wxBU_LEFT            0x0040
#define wxBU_TOP             0x0080
#define wxBU_RIGHT           0x0100
#define wxBU_BOTTOM          0x0200
#define wxBU_ALIGN_MASK      ( wxBU_LEFT | wxBU_TOP | wxBU_RIGHT | wxBU_BOTTOM )
#define wxBU_EXACTFIT        0x0001
#define wxBU_NOTEXT          0x0002
#define wxBU_AUTODRAW        0x0004
WXGO_DECL_TYPECONV(AnyButton)
class wxAnyButton : public wxControl
{
public:
    wxAnyButton();
    ~wxAnyButton();
    wxBitmap GetBitmap() const;
    wxBitmap GetBitmapCurrent() const;
    wxBitmap GetBitmapDisabled() const;
    wxBitmap GetBitmapFocus() const;
    wxBitmap GetBitmapLabel() const;
    wxBitmap GetBitmapPressed() const;
    void SetBitmap(const wxBitmap& bitmap, wxDirection dir = wxLEFT);
    void SetBitmapCurrent(const wxBitmap& bitmap);
    void SetBitmapDisabled(const wxBitmap& bitmap);
    void SetBitmapFocus(const wxBitmap& bitmap);
    void SetBitmapLabel(const wxBitmap& bitmap);
    void SetBitmapPressed(const wxBitmap& bitmap);
    wxSize GetBitmapMargins();
    void SetBitmapMargins(wxCoord x, wxCoord y);
    void SetBitmapMargins(const wxSize& sz);
    void SetBitmapPosition(wxDirection dir);
};