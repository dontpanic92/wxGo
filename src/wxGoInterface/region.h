%typedef int wxRegionContain;
#define wxOutRegion  0
#define wxPartRegion  1
#define wxInRegion  2
%rename(Next) wxRegionIterator::operator ++;
%rename(HasNext) wxRegionIterator::operator bool;
WXGO_DECL_TYPECONV(RegionIterator)
class wxRegionIterator : public wxObject
{
public:
    wxRegionIterator();
    wxRegionIterator(const wxRegion& region);
    wxCoord GetH() const;
    wxCoord GetHeight() const;
    wxRect GetRect() const;
    wxCoord GetW() const;
    wxCoord GetWidth() const;
    wxCoord GetX() const;
    wxCoord GetY() const;
    bool HaveRects() const;
    void Reset();
    void Reset(const wxRegion& region);
    wxRegionIterator& operator ++();
    operator bool() const;
};
WXGO_DECL_TYPECONV(Region)
class wxRegion : public wxGDIObject
{
public:
    wxRegion();
    wxRegion(wxCoord x, wxCoord y, wxCoord width, wxCoord height);
    wxRegion(const wxPoint& topLeft, const wxPoint& bottomRight);
    wxRegion(const wxRect& rect);
    wxRegion(const wxRegion& region);
    wxRegion(size_t n, const wxPoint* points, wxPolygonFillMode fillStyle = wxODDEVEN_RULE);
    wxRegion(const wxBitmap& bmp);
    wxRegion(const wxBitmap& bmp, const wxColour& transColour,
             int tolerance = 0);
    virtual ~wxRegion();
    virtual void Clear();
    wxRegionContain Contains(wxCoord x, wxCoord y) const;
    wxRegionContain Contains(const wxPoint& pt) const;
    wxRegionContain Contains(wxCoord x, wxCoord y, wxCoord width, wxCoord height) const;
    wxRegionContain Contains(const wxRect& rect) const;
    wxBitmap ConvertToBitmap() const;
    void GetBox(wxCoord& x, wxCoord& y, wxCoord& width,
                wxCoord& height) const;
    wxRect GetBox() const;
    bool Intersect(wxCoord x, wxCoord y, wxCoord width,
                   wxCoord height);
    bool Intersect(const wxRect& rect);
    bool Intersect(const wxRegion& region);
    virtual bool IsEmpty() const;
    bool IsEqual(const wxRegion& region) const;
    bool Offset(wxCoord x, wxCoord y);
    bool Offset(const wxPoint& pt);
    bool Subtract(const wxRect& rect);
    bool Subtract(const wxRegion& region);
    bool Union(wxCoord x, wxCoord y, wxCoord width, wxCoord height);
    bool Union(const wxRect& rect);
    bool Union(const wxRegion& region);
    bool Union(const wxBitmap& bmp);
    bool Union(const wxBitmap& bmp, const wxColour& transColour,
               int tolerance = 0);
    bool Xor(wxCoord x, wxCoord y, wxCoord width, wxCoord height);
    bool Xor(const wxRect& rect);
    bool Xor(const wxRegion& region);
    wxRegion& operator=(const wxRegion& region);
};