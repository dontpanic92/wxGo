enum wxBitmapType
{
    wxBITMAP_TYPE_INVALID,
    wxBITMAP_TYPE_BMP,
    wxBITMAP_TYPE_BMP_RESOURCE,
    wxBITMAP_TYPE_RESOURCE = wxBITMAP_TYPE_BMP_RESOURCE,
    wxBITMAP_TYPE_ICO,
    wxBITMAP_TYPE_ICO_RESOURCE,
    wxBITMAP_TYPE_CUR,
    wxBITMAP_TYPE_CUR_RESOURCE,
    wxBITMAP_TYPE_XBM,
    wxBITMAP_TYPE_XBM_DATA,
    wxBITMAP_TYPE_XPM,
    wxBITMAP_TYPE_XPM_DATA,
    wxBITMAP_TYPE_TIFF,
    wxBITMAP_TYPE_TIF = wxBITMAP_TYPE_TIFF,
    wxBITMAP_TYPE_TIFF_RESOURCE,
    wxBITMAP_TYPE_TIF_RESOURCE = wxBITMAP_TYPE_TIFF_RESOURCE,
    wxBITMAP_TYPE_GIF,
    wxBITMAP_TYPE_GIF_RESOURCE,
    wxBITMAP_TYPE_PNG,
    wxBITMAP_TYPE_PNG_RESOURCE,
    wxBITMAP_TYPE_JPEG,
    wxBITMAP_TYPE_JPEG_RESOURCE,
    wxBITMAP_TYPE_PNM,
    wxBITMAP_TYPE_PNM_RESOURCE,
    wxBITMAP_TYPE_PCX,
    wxBITMAP_TYPE_PCX_RESOURCE,
    wxBITMAP_TYPE_PICT,
    wxBITMAP_TYPE_PICT_RESOURCE,
    wxBITMAP_TYPE_ICON,
    wxBITMAP_TYPE_ICON_RESOURCE,
    wxBITMAP_TYPE_ANI,
    wxBITMAP_TYPE_IFF,
    wxBITMAP_TYPE_TGA,
    wxBITMAP_TYPE_MACCURSOR,
    wxBITMAP_TYPE_MACCURSOR_RESOURCE,
    wxBITMAP_TYPE_ANY = 50
};
enum wxPolygonFillMode
{
    wxODDEVEN_RULE = 1,
    wxWINDING_RULE
};
enum wxStockCursor
{
    wxCURSOR_NONE,
    wxCURSOR_ARROW,             
    wxCURSOR_RIGHT_ARROW,       
    wxCURSOR_BULLSEYE,          
    wxCURSOR_CHAR,              
    wxCURSOR_CROSS,             
    wxCURSOR_HAND,              
    wxCURSOR_IBEAM,             
    wxCURSOR_LEFT_BUTTON,       
    wxCURSOR_MAGNIFIER,         
    wxCURSOR_MIDDLE_BUTTON,     
    wxCURSOR_NO_ENTRY,          
    wxCURSOR_PAINT_BRUSH,       
    wxCURSOR_PENCIL,            
    wxCURSOR_POINT_LEFT,        
    wxCURSOR_POINT_RIGHT,       
    wxCURSOR_QUESTION_ARROW,    
    wxCURSOR_RIGHT_BUTTON,      
    wxCURSOR_SIZENESW,          
    wxCURSOR_SIZENS,            
    wxCURSOR_SIZENWSE,          
    wxCURSOR_SIZEWE,            
    wxCURSOR_SIZING,            
    wxCURSOR_SPRAYCAN,          
    wxCURSOR_WAIT,              
    wxCURSOR_WATCH,             
    wxCURSOR_BLANK,             
    wxCURSOR_DEFAULT,           
    //wxCURSOR_COPY_ARROW ,       
    //wxCURSOR_CROSS_REVERSE,     
    //wxCURSOR_DOUBLE_ARROW,      
    //wxCURSOR_BASED_ARROW_UP,    
    //wxCURSOR_BASED_ARROW_DOWN,  
    wxCURSOR_ARROWWAIT,         
    wxCURSOR_MAX
};
class wxRealPoint
{
public:
    wxRealPoint();
    wxRealPoint(double x, double y);
    wxRealPoint(const wxPoint& pt);
    double x;
    double y;
};
class wxRect
{
public:
    wxRect();
    wxRect(int x, int y, int width, int height);
    wxRect(const wxPoint& topLeft, const wxPoint& bottomRight);
    wxRect(const wxPoint& pos, const wxSize& size);
    wxRect(const wxSize& size);
    wxRect CentreIn(const wxRect& r, int dir = wxBOTH) const;
    wxRect CenterIn(const wxRect& r, int dir = wxBOTH) const;
    bool Contains(int x, int y) const;
    bool Contains(const wxPoint& pt) const;
    bool Contains(const wxRect& rect) const;
    wxRect& Deflate(wxCoord dx, wxCoord dy);
    wxRect& Deflate(const wxSize& diff);
    wxRect& Deflate(wxCoord diff);
    //wxRect  Deflate(wxCoord dx, wxCoord dy) const;
    int GetBottom() const;
    wxPoint GetBottomLeft() const;
    wxPoint GetBottomRight() const;
    int GetHeight() const;
    int GetLeft() const;
    wxPoint GetPosition() const;
    int GetRight() const;
    wxSize GetSize() const;
    int GetTop() const;
    wxPoint GetTopLeft() const;
    wxPoint GetTopRight() const;
    int GetWidth() const;
    int GetX() const;
    int GetY() const;
    wxRect& Inflate(wxCoord dx, wxCoord dy);
    wxRect& Inflate(const wxSize& diff);
    wxRect& Inflate(wxCoord diff);
    //wxRect Inflate(wxCoord dx, wxCoord dy) const;
    wxRect& Intersect(const wxRect& rect);
    //wxRect Intersect(const wxRect& rect) const;
    bool Intersects(const wxRect& rect) const;
    bool IsEmpty() const;
    void Offset(wxCoord dx, wxCoord dy);
    void Offset(const wxPoint& pt);
    void SetHeight(int height);
    void SetPosition(const wxPoint& pos);
    void SetSize(const wxSize& s);
    void SetWidth(int width);
    void SetX(int x);
    void SetY(int y);
    void SetLeft(int left);
    void SetRight(int right);
    void SetTop(int top);
    void SetBottom(int bottom);
    void SetTopLeft(const wxPoint &p);
    void SetBottomRight(const wxPoint &p);
    void SetTopRight(const wxPoint &p);
    void SetBottomLeft(const wxPoint &p);
    //wxRect Union(const wxRect& rect) const;
    wxRect& Union(const wxRect& rect);
    /*int height;
    int width;
    int x;
    int y;*/
};
class wxPoint
{
public:
    wxPoint();
    wxPoint(int x, int y);
    wxPoint(const wxRealPoint& pt);
    bool IsFullySpecified() const;
    void SetDefaults(const wxPoint& pt);
    int x;
    int  y;
};
%constant wxPoint wxDefaultPosition;
class wxColourDatabase
{
public:
    wxColourDatabase();
    void AddColour(const wxString& colourName, const wxColour& colour);
    wxColour Find(const wxString& colourName) const;
    wxString FindName(const wxColour& colour) const;
};
%constant wxColourDatabase* wxTheColourDatabase;
class wxSize
{
public:
    wxSize();
    wxSize(int width, int height);
    void DecBy(const wxPoint& pt);
    void DecBy(const wxSize& size);
    void DecBy(int dx, int dy);
    void DecBy(int d);
    void DecTo(const wxSize& size);
    void DecToIfSpecified(const wxSize& size);
    int GetHeight() const;
    int GetWidth() const;
    void IncBy(const wxPoint& pt);
    void IncBy(const wxSize& size);
    void IncBy(int dx, int dy);
    void IncBy(int d);
    void IncTo(const wxSize& size);
    bool IsFullySpecified() const;
    wxSize& Scale(float xscale, float yscale);
    void Set(int width, int height);
    void SetDefaults(const wxSize& sizeDefault);
    void SetHeight(int height);
    void SetWidth(int width);
};
%constant wxSize wxDefaultSize;
#define wxBITMAP(bitmapName)
#define wxBITMAP_PNG(bitmapName)
#define wxBITMAP_PNG_FROM_DATA(bitmapName)
#define wxICON(iconName)
bool wxColourDisplay();
int wxDisplayDepth();
void wxSetCursor(const wxCursor& cursor);
void wxClientDisplayRect(int* x, int* y, int* width, int* height);
wxRect wxGetClientDisplayRect();
wxSize wxGetDisplayPPI();
void wxDisplaySize(int* width, int* height);
wxSize wxGetDisplaySize();
void wxDisplaySizeMM(int* width, int* height);
wxSize wxGetDisplaySizeMM();
