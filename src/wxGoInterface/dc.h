%typedef int wxRasterOperationMode;
#define wxCLEAR 0
#define wxXOR wxCLEAR + 1
#define wxINVERT wxXOR + 1
#define wxOR_REVERSE wxINVERT + 1
#define wxAND_REVERSE wxOR_REVERSE + 1
#define wxCOPY wxAND_REVERSE + 1
#define wxAND wxCOPY + 1
#define wxAND_INVERT wxAND + 1
#define wxNO_OP wxAND_INVERT + 1
#define wxNOR wxNO_OP + 1
#define wxEQUIV wxNOR + 1
#define wxSRC_INVERT wxEQUIV + 1
#define wxOR_INVERT wxSRC_INVERT + 1
#define wxNAND wxOR_INVERT + 1
#define wxOR wxNAND + 1
#define wxSET wxOR + 1
%typedef int wxFloodFillStyle;
#define wxFLOOD_SURFACE  1
#define wxFLOOD_BORDER wxFLOOD_SURFACE  + 1
%typedef int wxMappingMode;
#define wxMM_TEXT  1
#define wxMM_METRIC wxMM_TEXT  + 1
#define wxMM_LOMETRIC wxMM_METRIC + 1
#define wxMM_TWIPS wxMM_LOMETRIC + 1
#define wxMM_POINTS wxMM_TWIPS + 1
struct wxFontMetrics
{
    wxFontMetrics();
    int height,             
        ascent,             
        descent,            
        internalLeading,    
        externalLeading,    
        averageWidth;       
};
%nodefaultctor wxDC;
WXGO_DECL_TYPECONV(DC)
class wxDC : public wxObject
{
public:
    wxCoord DeviceToLogicalX(wxCoord x) const;
    wxCoord DeviceToLogicalXRel(wxCoord x) const;
    wxCoord DeviceToLogicalY(wxCoord y) const;
    wxCoord DeviceToLogicalYRel(wxCoord y) const;
    wxCoord LogicalToDeviceX(wxCoord x) const;
    wxCoord LogicalToDeviceXRel(wxCoord x) const;
    wxCoord LogicalToDeviceY(wxCoord y) const;
    wxCoord LogicalToDeviceYRel(wxCoord y) const;
    void Clear();
    void DrawArc(wxCoord xStart, wxCoord yStart, wxCoord xEnd, wxCoord yEnd,
                 wxCoord xc, wxCoord yc);
    void DrawArc(const wxPoint& ptStart, const wxPoint& ptEnd, const wxPoint& centre);
    void DrawBitmap(const wxBitmap& bitmap, wxCoord x, wxCoord y,
                    bool useMask = false);
    void DrawBitmap(const wxBitmap &bmp, const wxPoint& pt,
                    bool useMask = false);
    void DrawCheckMark(wxCoord x, wxCoord y, wxCoord width, wxCoord height);
    void DrawCheckMark(const wxRect& rect);
    void DrawCircle(wxCoord x, wxCoord y, wxCoord radius);
    void DrawCircle(const wxPoint& pt, wxCoord radius);
    void DrawEllipse(wxCoord x, wxCoord y, wxCoord width, wxCoord height);
    void DrawEllipse(const wxPoint& pt, const wxSize& size);
    void DrawEllipse(const wxRect& rect);
    void DrawEllipticArc(wxCoord x, wxCoord y, wxCoord width, wxCoord height,
                          double start, double end);
    void DrawEllipticArc(const wxPoint& pt, const wxSize& sz,
                         double sa, double ea);
    void DrawIcon(const wxIcon& icon, wxCoord x, wxCoord y);
    void DrawIcon(const wxIcon& icon, const wxPoint& pt);
    void DrawLabel(const wxString& text, const wxBitmap& bitmap,
                   const wxRect& rect,
                   int alignment = wxALIGN_LEFT | wxALIGN_TOP,
                   int indexAccel = -1, wxRect* rectBounding = NULL);
    void DrawLabel(const wxString& text, const wxRect& rect,
                   int alignment = wxALIGN_LEFT | wxALIGN_TOP,
                   int indexAccel = -1);
    void DrawLine(wxCoord x1, wxCoord y1, wxCoord x2, wxCoord y2);
    void DrawLine(const wxPoint& pt1, const wxPoint& pt2);
    void DrawLines(int n, const wxPoint points[], wxCoord xoffset = 0,
                   wxCoord yoffset = 0);
    void DrawLines(const wxPointList* points,
                   wxCoord xoffset = 0, wxCoord yoffset = 0);
    void DrawPoint(wxCoord x, wxCoord y);
    void DrawPoint(const wxPoint& pt);
    void DrawPolygon(int n, const wxPoint points[], wxCoord xoffset = 0,
                     wxCoord yoffset = 0,
                     wxPolygonFillMode fill_style = wxODDEVEN_RULE);
    void DrawPolygon(const wxPointList* points,
                     wxCoord xoffset = 0, wxCoord yoffset = 0,
                     wxPolygonFillMode fill_style = wxODDEVEN_RULE);
    void DrawPolyPolygon(int n, const int count[], const wxPoint points[],
                         wxCoord xoffset = 0, wxCoord yoffset = 0,
                         wxPolygonFillMode fill_style = wxODDEVEN_RULE);
    void DrawRectangle(wxCoord x, wxCoord y, wxCoord width, wxCoord height);
    void DrawRectangle(const wxPoint& pt, const wxSize& sz);
    void DrawRectangle(const wxRect& rect);
    void DrawRotatedText(const wxString& text, wxCoord x, wxCoord y,
                         double angle);
    void DrawRotatedText(const wxString& text, const wxPoint& point,
                         double angle);
    void DrawRoundedRectangle(wxCoord x, wxCoord y, wxCoord width,
                              wxCoord height, double radius);
    void DrawRoundedRectangle(const wxPoint& pt, const wxSize& sz,
                              double radius);
    void DrawRoundedRectangle(const wxRect& rect, double radius);
    void DrawSpline(int n, const wxPoint points[]);
    void DrawSpline(const wxPointList* points);
    void DrawSpline(wxCoord x1, wxCoord y1, wxCoord x2, wxCoord y2,
                    wxCoord x3, wxCoord y3);
    void DrawText(const wxString& text, wxCoord x, wxCoord y);
    void DrawText(const wxString& text, const wxPoint& pt);
    void GradientFillConcentric(const wxRect& rect,
                                const wxColour& initialColour,
                                const wxColour& destColour);
    void GradientFillConcentric(const wxRect& rect,
                                const wxColour& initialColour,
                                const wxColour& destColour,
                                const wxPoint& circleCenter);
    void GradientFillLinear(const wxRect& rect, const wxColour& initialColour,
                            const wxColour& destColour,
                            wxDirection nDirection = wxRIGHT);
    bool FloodFill(wxCoord x, wxCoord y, const wxColour& colour,
                   wxFloodFillStyle style = wxFLOOD_SURFACE);
    bool FloodFill(const wxPoint& pt, const wxColour& col,
                   wxFloodFillStyle style = wxFLOOD_SURFACE);
    void CrossHair(wxCoord x, wxCoord y);
    void CrossHair(const wxPoint& pt);
    void DestroyClippingRegion();
    void GetClippingBox(wxCoord *x, wxCoord *y, wxCoord *width, wxCoord *height) const;
    void SetClippingRegion(wxCoord x, wxCoord y, wxCoord width, wxCoord height);
    void SetClippingRegion(const wxPoint& pt, const wxSize& sz);
    void SetClippingRegion(const wxRect& rect);
    void SetDeviceClippingRegion(const wxRegion& region);
    wxCoord GetCharHeight() const;
    wxCoord GetCharWidth() const;
    wxFontMetrics GetFontMetrics() const;
    void GetMultiLineTextExtent(const wxString& string, wxCoord* w,
                                wxCoord* h,
                                wxCoord* heightLine = NULL,
                                const wxFont* font = NULL) const;
    wxSize GetMultiLineTextExtent(const wxString& string) const;
    bool GetPartialTextExtents(const wxString& text,
                               wxArrayInt& widths) const;
    void GetTextExtent(const wxString& string, wxCoord* w, wxCoord* h,
                       wxCoord* descent = NULL,
                       wxCoord* externalLeading = NULL,
                       const wxFont* font = NULL) const;
    wxSize GetTextExtent(const wxString& string) const;
    int GetBackgroundMode() const;
    const wxFont& GetFont() const;
    wxLayoutDirection GetLayoutDirection() const;
    const wxColour& GetTextBackground() const;
    const wxColour& GetTextForeground() const;
    void SetBackgroundMode(int mode);
    void SetFont(const wxFont& font);
    void SetTextBackground(const wxColour& colour);
    void SetTextForeground(const wxColour& colour);
    void SetLayoutDirection(wxLayoutDirection dir);
    void CalcBoundingBox(wxCoord x, wxCoord y);
    wxCoord MaxX() const;
    wxCoord MaxY() const;
    wxCoord MinX() const;
    wxCoord MinY() const;
    void ResetBoundingBox();
    bool StartDoc(const wxString& message);
    void StartPage();
    void EndDoc();
    void EndPage();
    bool Blit(wxCoord xdest, wxCoord ydest, wxCoord width,
              wxCoord height, wxDC* source, wxCoord xsrc, wxCoord ysrc,
              wxRasterOperationMode logicalFunc = wxCOPY, bool useMask = false,
              wxCoord xsrcMask = wxDefaultCoord, wxCoord ysrcMask = wxDefaultCoord);
    bool StretchBlit(wxCoord xdest, wxCoord ydest,
                     wxCoord dstWidth, wxCoord dstHeight,
                     wxDC* source, wxCoord xsrc, wxCoord ysrc,
                     wxCoord srcWidth, wxCoord srcHeight,
                     wxRasterOperationMode logicalFunc = wxCOPY,
                     bool useMask = false,
                     wxCoord xsrcMask = wxDefaultCoord,
                     wxCoord ysrcMask = wxDefaultCoord);
    const wxBrush& GetBackground() const;
    const wxBrush& GetBrush() const;
    const wxPen& GetPen() const;
    void SetBackground(const wxBrush& brush);
    void SetBrush(const wxBrush& brush);
    void SetPen(const wxPen& pen);
    void CopyAttributes(const wxDC& dc);
    int GetDepth() const;
    wxPoint GetDeviceOrigin() const;
    wxRasterOperationMode GetLogicalFunction() const;
    wxMappingMode GetMapMode() const;
    bool GetPixel(wxCoord x, wxCoord y, wxColour* colour) const;
    wxSize GetPPI() const;
    void GetSize(wxCoord* width, wxCoord* height) const;
    wxSize GetSize() const;
    void GetSizeMM(wxCoord* width, wxCoord* height) const;
    wxSize GetSizeMM() const;
    void GetUserScale(double* x, double* y) const;
    bool IsOk() const;
    void SetAxisOrientation(bool xLeftRight, bool yBottomUp);
    void SetDeviceOrigin(wxCoord x, wxCoord y);
    void SetLogicalFunction(wxRasterOperationMode function);
    void SetMapMode(wxMappingMode mode);
    void SetPalette(const wxPalette& palette);
    void SetUserScale(double xScale, double yScale);
    bool CanUseTransformMatrix() const;
    bool SetTransformMatrix(const wxAffineMatrix2D& matrix);
    wxAffineMatrix2D GetTransformMatrix() const;
    void ResetTransformMatrix();
    bool CanDrawBitmap() const;
    bool CanGetTextExtent() const;
    void* GetHandle() const;
    wxBitmap GetAsBitmap(const wxRect *subrect = NULL) const;
    void SetLogicalScale(double x, double y);
    void GetLogicalScale(double *x, double *y) const;
    void SetLogicalOrigin(wxCoord x, wxCoord y);
    void GetLogicalOrigin(wxCoord *x, wxCoord *y) const;
    wxPoint GetLogicalOrigin() const;
};
WXGO_DECL_TYPECONV(DCClipper)
class wxDCClipper
{
public:
    wxDCClipper(wxDC& dc, const wxRegion& region);
    wxDCClipper(wxDC& dc, const wxRect& rect);
    wxDCClipper(wxDC& dc, wxCoord x, wxCoord y, wxCoord w, wxCoord h);
    ~wxDCClipper();
};
WXGO_DECL_TYPECONV(DCBrushChanger)
class wxDCBrushChanger
{
public:
    wxDCBrushChanger(wxDC& dc, const wxBrush& brush);
    ~wxDCBrushChanger();
};
WXGO_DECL_TYPECONV(DCPenChanger)
class wxDCPenChanger
{
public:
    wxDCPenChanger(wxDC& dc, const wxPen& pen);
    ~wxDCPenChanger();
};
WXGO_DECL_TYPECONV(DCTextColourChanger)
class wxDCTextColourChanger
{
public:
    wxDCTextColourChanger(wxDC& dc);
    wxDCTextColourChanger(wxDC& dc, const wxColour& col);
    void Set(const wxColour& col);
    ~wxDCTextColourChanger();
};
WXGO_DECL_TYPECONV(DCFontChanger)
class wxDCFontChanger
{
public:
    wxDCFontChanger(wxDC& dc);
    wxDCFontChanger(wxDC& dc, const wxFont& font);
    void Set(const wxFont& font);
    ~wxDCFontChanger();
};