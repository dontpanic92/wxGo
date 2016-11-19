WXGO_DECL_TYPECONV(SVGFileDC)
class wxSVGFileDC : public wxDC
{
public:
    wxSVGFileDC(const wxString& filename, int width = 320, int height = 240, double dpi = 72);
    virtual ~wxSVGFileDC();
    void EndDoc();
    void EndPage();
    void Clear();
    void SetBitmapHandler(wxSVGBitmapHandler* handler);
    void SetLogicalFunction(wxRasterOperationMode function);
    void SetClippingRegion(wxCoord x, wxCoord y, wxCoord width,
                           wxCoord height);
    void SetClippingRegion(const wxPoint& pt, const wxSize& sz);
    void SetClippingRegion(const wxRect& rect);
    void SetClippingRegion(const wxRegion& region);
    void DestroyClippingRegion();
    void CrossHair(wxCoord x, wxCoord y);
    bool FloodFill(wxCoord x, wxCoord y, const wxColour& colour,
                   wxFloodFillStyle style = wxFLOOD_SURFACE);
    void GetClippingBox(wxCoord *x, wxCoord *y, wxCoord *width, wxCoord *height) const;
    bool GetPixel(wxCoord x, wxCoord y, wxColour* colour) const;
    void SetPalette(const wxPalette& palette);
    bool StartDoc(const wxString& message);
};
WXGO_DECL_TYPECONV(SVGBitmapHandler)
class wxSVGBitmapHandler
{
public:
    virtual bool ProcessBitmap(const wxBitmap& bitmap,
                               wxCoord x, wxCoord y,
                               wxOutputStream& stream) const = 0;
};
WXGO_DECL_TYPECONV(SVGBitmapEmbedHandler)
class wxSVGBitmapEmbedHandler : public wxSVGBitmapHandler
{
public:
    virtual bool ProcessBitmap(const wxBitmap& bitmap,
                               wxCoord x, wxCoord y,
                               wxOutputStream& stream) const;
};
WXGO_DECL_TYPECONV(SVGBitmapFileHandler)
class wxSVGBitmapFileHandler : public wxSVGBitmapHandler
{
public:
    virtual bool ProcessBitmap(const wxBitmap& bitmap,
                               wxCoord x, wxCoord y,
                               wxOutputStream& stream) const;
};