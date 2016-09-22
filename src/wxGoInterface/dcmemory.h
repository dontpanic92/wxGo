WXGO_DECL_TYPECONV(MemoryDC)
class wxMemoryDC : public wxDC
{
public:
    wxMemoryDC();
    wxMemoryDC(wxDC *dc);
    wxMemoryDC(wxBitmap& bitmap);
    void SelectObject(wxBitmap& bitmap);
    void SelectObjectAsSource(const wxBitmap& bitmap);
};