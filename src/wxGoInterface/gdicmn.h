class wxSize
{
public:
    int x, y;

    wxSize(int xx, int yy) : x(xx), y(yy) { }

    void IncTo(const wxSize& sz)
        { if ( sz.x > x ) x = sz.x; if ( sz.y > y ) y = sz.y; }
    void DecTo(const wxSize& sz)
        { if ( sz.x < x ) x = sz.x; if ( sz.y < y ) y = sz.y; }
    void DecToIfSpecified(const wxSize& sz)
    {
        if ( sz.x != wxDefaultCoord && sz.x < x )
            x = sz.x;
        if ( sz.y != wxDefaultCoord && sz.y < y )
            y = sz.y;
    }

    void IncBy(int dx, int dy) { x += dx; y += dy; }
    void IncBy(const wxPoint& pt);
    void IncBy(const wxSize& sz) { IncBy(sz.x, sz.y); }
    void IncBy(int d) { IncBy(d, d); }

    void DecBy(int dx, int dy) { IncBy(-dx, -dy); }
    void DecBy(const wxPoint& pt);
    void DecBy(const wxSize& sz) { DecBy(sz.x, sz.y); }
    void DecBy(int d) { DecBy(d, d); }


    wxSize& Scale(float xscale, float yscale)
        { x = (int)(x*xscale); y = (int)(y*yscale); return *this; }

    // accessors
    void Set(int xx, int yy) { x = xx; y = yy; }
    void SetWidth(int w) { x = w; }
    void SetHeight(int h) { y = h; }

    int GetWidth() const { return x; }
    int GetHeight() const { return y; }

    bool IsFullySpecified() const { return x != wxDefaultCoord && y != wxDefaultCoord; }

    // combine this size with the other one replacing the default (i.e. equal
    // to wxDefaultCoord) components of this object with those of the other
    void SetDefaults(const wxSize& size)
    {
        if ( x == wxDefaultCoord )
            x = size.x;
        if ( y == wxDefaultCoord )
            y = size.y;
    }
};

class wxRealPoint
{
public:
    double x;
    double y;

    wxRealPoint() : x(0.0), y(0.0) { }
    wxRealPoint(double xx, double yy) : x(xx), y(yy) { }
    wxRealPoint(const wxPoint& pt);

};

class wxPoint
{
public:
    int x, y;

    wxPoint() : x(0), y(0) { }
    wxPoint(int xx, int yy) : x(xx), y(yy) { }
    wxPoint(const wxRealPoint& pt) : x(int(pt.x)), y(int(pt.y)) { }

    bool IsFullySpecified() const { return x != wxDefaultCoord && y != wxDefaultCoord; }

    void SetDefaults(const wxPoint& pt)
    {
        if ( x == wxDefaultCoord )
            x = pt.x;
        if ( y == wxDefaultCoord )
            y = pt.y;
    }
};
class wxRect
{
public:
    wxRect()
        : x(0), y(0), width(0), height(0)
        { }
    wxRect(int xx, int yy, int ww, int hh)
        : x(xx), y(yy), width(ww), height(hh)
        { }
    wxRect(const wxPoint& topLeft, const wxPoint& bottomRight);
    wxRect(const wxPoint& pt, const wxSize& size)
        : x(pt.x), y(pt.y), width(size.x), height(size.y)
        { }
    wxRect(const wxSize& size)
        : x(0), y(0), width(size.x), height(size.y)
        { }

    wxPoint GetPosition() const { return wxPoint(x, y); }
    void SetPosition( const wxPoint &p ) { x = p.x; y = p.y; }

    wxSize GetSize() const { return wxSize(width, height); }
    void SetSize( const wxSize &s ) { width = s.GetWidth(); height = s.GetHeight(); }

    bool IsEmpty() const { return (width <= 0) || (height <= 0); }

    int GetLeft()   const { return x; }
    int GetTop()    const { return y; }
    int GetBottom() const { return y + height - 1; }
    int GetRight()  const { return x + width - 1; }

    void SetLeft(int left) { x = left; }
    void SetRight(int right) { width = right - x + 1; }
    void SetTop(int top) { y = top; }
    void SetBottom(int bottom) { height = bottom - y + 1; }

    wxPoint GetTopLeft() const { return GetPosition(); }
    wxPoint GetLeftTop() const { return GetTopLeft(); }
    void SetTopLeft(const wxPoint &p) { SetPosition(p); }
    void SetLeftTop(const wxPoint &p) { SetTopLeft(p); }

    wxPoint GetBottomRight() const { return wxPoint(GetRight(), GetBottom()); }
    wxPoint GetRightBottom() const { return GetBottomRight(); }
    void SetBottomRight(const wxPoint &p) { SetRight(p.x); SetBottom(p.y); }
    void SetRightBottom(const wxPoint &p) { SetBottomRight(p); }

    wxPoint GetTopRight() const { return wxPoint(GetRight(), GetTop()); }
    wxPoint GetRightTop() const { return GetTopRight(); }
    void SetTopRight(const wxPoint &p) { SetRight(p.x); SetTop(p.y); }
    void SetRightTop(const wxPoint &p) { SetTopRight(p); }

    wxPoint GetBottomLeft() const { return wxPoint(GetLeft(), GetBottom()); }
    wxPoint GetLeftBottom() const { return GetBottomLeft(); }
    void SetBottomLeft(const wxPoint &p) { SetLeft(p.x); SetBottom(p.y); }
    void SetLeftBottom(const wxPoint &p) { SetBottomLeft(p); }

    // operations with rect
    wxRect& Inflate(wxCoord dx, wxCoord dy);
    wxRect& Inflate(const wxSize& d) { return Inflate(d.x, d.y); }
    wxRect& Inflate(wxCoord d) { return Inflate(d, d); }


    wxRect& Deflate(wxCoord dx, wxCoord dy) { return Inflate(-dx, -dy); }
    wxRect& Deflate(const wxSize& d) { return Inflate(-d.x, -d.y); }
    wxRect& Deflate(wxCoord d) { return Inflate(-d); }

    void Offset(wxCoord dx, wxCoord dy) { x += dx; y += dy; }
    void Offset(const wxPoint& pt) { Offset(pt.x, pt.y); }

    wxRect& Intersect(const wxRect& rect);

    wxRect& Union(const wxRect& rect);

    // return true if the point is (not strcitly) inside the rect
    bool Contains(int x, int y) const;
    bool Contains(const wxPoint& pt) const { return Contains(pt.x, pt.y); }
    // return true if the rectangle 'rect' is (not strictly) inside this rect
    bool Contains(const wxRect& rect) const;

    bool Intersects(const wxRect& rect) const;

    wxRect CentreIn(const wxRect& r, int dir = wxBOTH) const
    {
        return wxRect(dir & wxHORIZONTAL ? r.x + (r.width - width)/2 : x,
                      dir & wxVERTICAL ? r.y + (r.height - height)/2 : y,
                      width, height);
    }

    wxRect CenterIn(const wxRect& r, int dir = wxBOTH) const
    {
        return CentreIn(r, dir);
    }

public:
    int x, y, width, height;
};


inline void wxSize::IncBy(const wxPoint& pt) { IncBy(pt.x, pt.y); }
inline void wxSize::DecBy(const wxPoint& pt) { DecBy(pt.x, pt.y); }

typedef wxInt8 wxDash;

class wxStockGDI
{
public:
	class Item;
	
    wxStockGDI();
    ~wxStockGDI();
    static void DeleteAll();

    static wxStockGDI& instance() { return *ms_instance; }

    static const wxBrush* GetBrush(Item item);
    static const wxColour* GetColour(Item item);
    static const wxCursor* GetCursor(Item item);
    const wxFont* GetFont(Item item);
    static const wxPen* GetPen(Item item);
};

void wxInitializeStockLists();
void wxDeleteStockLists();

bool wxColourDisplay();

int wxDisplayDepth();

void wxDisplaySize(int *width, int *height);
wxSize wxGetDisplaySize();
void wxDisplaySizeMM(int *width, int *height);
wxSize wxGetDisplaySizeMM();
wxSize wxGetDisplayPPI();


void wxClientDisplayRect(int *x, int *y, int *width, int *height);
wxRect wxGetClientDisplayRect();

void wxSetCursor(const wxCursor& cursor);

