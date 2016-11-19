WXGO_DECL_TYPECONV(GraphicsObject)
class wxGraphicsObject : public wxObject
{
public:
    wxGraphicsRenderer* GetRenderer() const;
    bool IsNull() const;
};
WXGO_DECL_TYPECONV(GraphicsPath)
class wxGraphicsPath : public wxGraphicsObject
{
public:
    virtual void AddArc(wxDouble x, wxDouble y, wxDouble r,
                        wxDouble startAngle, wxDouble endAngle,
                        bool clockwise);
    void AddArc(const wxPoint2DDouble& c, wxDouble r,
                wxDouble startAngle, wxDouble endAngle, bool clockwise);
    virtual void AddArcToPoint(wxDouble x1, wxDouble y1, wxDouble x2,
                               wxDouble y2, wxDouble r);
    virtual void AddCircle(wxDouble x, wxDouble y, wxDouble r);
    virtual void AddCurveToPoint(wxDouble cx1, wxDouble cy1,
                                 wxDouble cx2, wxDouble cy2,
                                 wxDouble x, wxDouble y);
    void AddCurveToPoint(const wxPoint2DDouble& c1,
                         const wxPoint2DDouble& c2,
                         const wxPoint2DDouble& e);
    virtual void AddEllipse(wxDouble x, wxDouble y, wxDouble w, wxDouble h);
    virtual void AddLineToPoint(wxDouble x, wxDouble y);
    void AddLineToPoint(const wxPoint2DDouble& p);
    virtual void AddPath(const wxGraphicsPath& path);
    virtual void AddQuadCurveToPoint(wxDouble cx, wxDouble cy,
                                     wxDouble x, wxDouble y);
    virtual void AddRectangle(wxDouble x, wxDouble y, wxDouble w, wxDouble h);
    virtual void AddRoundedRectangle(wxDouble x, wxDouble y, wxDouble w,
                                     wxDouble h, wxDouble radius);
    virtual void CloseSubpath();
    bool Contains(const wxPoint2DDouble& c,
                  wxPolygonFillMode fillStyle = wxODDEVEN_RULE) const;
    virtual bool Contains(wxDouble x, wxDouble y,
                          wxPolygonFillMode fillStyle = wxODDEVEN_RULE) const;
    wxRect2DDouble GetBox() const;
    virtual void GetBox(wxDouble* x, wxDouble* y,
                        wxDouble* w, wxDouble* h) const;
    virtual void GetCurrentPoint(wxDouble* x, wxDouble* y) const;
    wxPoint2DDouble GetCurrentPoint() const;
    virtual void* GetNativePath() const;
    virtual void MoveToPoint(wxDouble x, wxDouble y);
    void MoveToPoint(const wxPoint2DDouble& p);
    virtual void Transform(const wxGraphicsMatrix& matrix);
    virtual void UnGetNativePath(void* p) const;
};
%typedef int wxAntialiasMode;
#define wxANTIALIAS_NONE 0
#define wxANTIALIAS_DEFAULT wxANTIALIAS_NONE + 1
%typedef int wxInterpolationQuality;
#define wxINTERPOLATION_DEFAULT 0
#define wxINTERPOLATION_NONE wxINTERPOLATION_DEFAULT + 1
#define wxINTERPOLATION_FAST wxINTERPOLATION_NONE + 1
#define wxINTERPOLATION_GOOD wxINTERPOLATION_FAST + 1
#define wxINTERPOLATION_BEST wxINTERPOLATION_GOOD + 1
%typedef int wxCompositionMode;
#define wxCOMPOSITION_INVALID  -1
#define wxCOMPOSITION_CLEAR wxCOMPOSITION_INVALID  + 1
#define wxCOMPOSITION_SOURCE wxCOMPOSITION_CLEAR + 1
#define wxCOMPOSITION_OVER wxCOMPOSITION_SOURCE + 1
#define wxCOMPOSITION_IN wxCOMPOSITION_OVER + 1
#define wxCOMPOSITION_OUT wxCOMPOSITION_IN + 1
#define wxCOMPOSITION_ATOP wxCOMPOSITION_OUT + 1
#define wxCOMPOSITION_DEST wxCOMPOSITION_ATOP + 1
#define wxCOMPOSITION_DEST_OVER wxCOMPOSITION_DEST + 1
#define wxCOMPOSITION_DEST_IN wxCOMPOSITION_DEST_OVER + 1
#define wxCOMPOSITION_DEST_OUT wxCOMPOSITION_DEST_IN + 1
#define wxCOMPOSITION_DEST_ATOP wxCOMPOSITION_DEST_OUT + 1
#define wxCOMPOSITION_XOR wxCOMPOSITION_DEST_ATOP + 1
#define wxCOMPOSITION_ADD wxCOMPOSITION_XOR + 1
WXGO_DECL_TYPECONV(GraphicsBitmap)
class wxGraphicsBitmap : public wxGraphicsObject
{
public:
    wxGraphicsBitmap() {}
    wxImage ConvertToImage() const;
    void* GetNativeBitmap() const;
};
WXGO_DECL_TYPECONV(GraphicsContext)
class wxGraphicsContext : public wxGraphicsObject
{
public:
    static wxGraphicsContext* Create(wxWindow* window);
    static wxGraphicsContext* Create(const wxWindowDC& windowDC);
    static wxGraphicsContext* Create(const wxMemoryDC& memoryDC);
    static wxGraphicsContext* Create(const wxPrinterDC& printerDC);
#ifdef __WXMSW__
    static wxGraphicsContext* Create(const wxEnhMetaFileDC& metaFileDC);
#endif
    static wxGraphicsContext* Create(wxImage& image);
    static wxGraphicsContext* Create();
    virtual void Clip(const wxRegion& region) = 0;
    virtual void Clip(wxDouble x, wxDouble y, wxDouble w, wxDouble h) = 0;
    virtual void ConcatTransform(const wxGraphicsMatrix& matrix) = 0;
    virtual wxGraphicsBitmap CreateBitmap( const wxBitmap &bitmap ) = 0;
    virtual wxGraphicsBitmap CreateBitmapFromImage(const wxImage& image);
    virtual wxGraphicsBitmap CreateSubBitmap(const wxGraphicsBitmap& bitmap,
                                             wxDouble x, wxDouble y,
                                             wxDouble w, wxDouble h) = 0;
    virtual wxGraphicsBrush CreateBrush(const wxBrush& brush) const;
    virtual wxGraphicsFont CreateFont(const wxFont& font,
                                      const wxColour& col = *wxBLACK) const;
    virtual wxGraphicsFont CreateFont(double sizeInPixels,
                                      const wxString& facename,
                                      int flags = wxFONTFLAG_DEFAULT,
                                      const wxColour& col = *wxBLACK) const;
    static wxGraphicsContext* CreateFromNative(void* context);
    static wxGraphicsContext* CreateFromNativeWindow(void* window);
    wxGraphicsBrush
    CreateLinearGradientBrush(wxDouble x1, wxDouble y1,
                              wxDouble x2, wxDouble y2,
                              const wxColour& c1, const wxColour& c2) const;
    wxGraphicsBrush
    CreateLinearGradientBrush(wxDouble x1, wxDouble y1,
                              wxDouble x2, wxDouble y2,
                              const wxGraphicsGradientStops& stops) const;
    virtual wxGraphicsMatrix CreateMatrix(wxDouble a = 1.0, wxDouble b = 0.0,
                                          wxDouble c = 0.0, wxDouble d = 1.0,
                                          wxDouble tx = 0.0,
                                          wxDouble ty = 0.0) const;
    wxGraphicsMatrix CreateMatrix(const wxAffineMatrix2DBase& mat) const;
    wxGraphicsPath CreatePath() const;
    virtual wxGraphicsPen CreatePen(const wxPen& pen) const;
    virtual wxGraphicsBrush
    CreateRadialGradientBrush(wxDouble xo, wxDouble yo,
                              wxDouble xc, wxDouble yc,
                              wxDouble radius,
                              const wxColour& oColor,
                              const wxColour& cColor) const;
    virtual wxGraphicsBrush
    CreateRadialGradientBrush(wxDouble xo, wxDouble yo,
                              wxDouble xc, wxDouble yc,
                              wxDouble radius,
                              const wxGraphicsGradientStops& stops) = 0;
    virtual void DrawBitmap(const wxGraphicsBitmap& bmp,
                            wxDouble x, wxDouble y,
                            wxDouble w, wxDouble h ) = 0;
    virtual void DrawBitmap(const wxBitmap& bmp,
                            wxDouble x, wxDouble y,
                            wxDouble w, wxDouble h) = 0;
    virtual void DrawEllipse(wxDouble x, wxDouble y, wxDouble w, wxDouble h);
    virtual void DrawIcon(const wxIcon& icon, wxDouble x, wxDouble y,
                          wxDouble w, wxDouble h) = 0;
    virtual void DrawLines(size_t n, const wxPoint2DDouble* points,
                           wxPolygonFillMode fillStyle = wxODDEVEN_RULE);
    virtual void DrawPath(const wxGraphicsPath& path,
                          wxPolygonFillMode fillStyle = wxODDEVEN_RULE);
    virtual void DrawRectangle(wxDouble x, wxDouble y, wxDouble w, wxDouble h);
    virtual void DrawRoundedRectangle(wxDouble x, wxDouble y, wxDouble w,
                                      wxDouble h, wxDouble radius);
    void DrawText(const wxString& str, wxDouble x, wxDouble y);
    void DrawText(const wxString& str, wxDouble x, wxDouble y, wxDouble angle);
    void DrawText(const wxString& str, wxDouble x, wxDouble y,
                  const wxGraphicsBrush& backgroundBrush);
    void DrawText(const wxString& str, wxDouble x, wxDouble y,
                  wxDouble angle, const wxGraphicsBrush& backgroundBrush);
    virtual void FillPath(const wxGraphicsPath& path,
                          wxPolygonFillMode fillStyle = wxODDEVEN_RULE) = 0;
    virtual void* GetNativeContext() = 0;
    virtual void GetPartialTextExtents(const wxString& text,
                                       wxArrayDouble& widths) const = 0;
    virtual void GetTextExtent(const wxString& text, wxDouble* width,
                               wxDouble* height, wxDouble* descent,
                               wxDouble* externalLeading) const = 0;
    virtual wxGraphicsMatrix GetTransform() const = 0;
    virtual void ResetClip() = 0;
    virtual void Rotate(wxDouble angle) = 0;
    virtual void Scale(wxDouble xScale, wxDouble yScale) = 0;
    void SetBrush(const wxBrush& brush);
    virtual void SetBrush(const wxGraphicsBrush& brush);
    void SetFont(const wxFont& font, const wxColour& colour);
    virtual void SetFont(const wxGraphicsFont& font);
    void SetPen(const wxPen& pen);
    virtual void SetPen(const wxGraphicsPen& pen);
    virtual void SetTransform(const wxGraphicsMatrix& matrix) = 0;
    virtual void StrokeLine(wxDouble x1, wxDouble y1, wxDouble x2, wxDouble y2);
    virtual void StrokeLines(size_t n, const wxPoint2DDouble* beginPoints,
                             const wxPoint2DDouble* endPoints);
    virtual void StrokeLines(size_t n, const wxPoint2DDouble* points);
    virtual void StrokePath(const wxGraphicsPath& path) = 0;
    virtual void Translate(wxDouble dx, wxDouble dy) = 0;
    virtual void BeginLayer(wxDouble opacity) = 0;
    virtual void EndLayer() = 0;
    virtual bool SetAntialiasMode(wxAntialiasMode antialias) = 0;
    virtual wxAntialiasMode GetAntialiasMode() const ;
    virtual bool SetInterpolationQuality(wxInterpolationQuality interpolation) = 0;
    virtual wxInterpolationQuality GetInterpolationQuality() const;
    virtual bool SetCompositionMode(wxCompositionMode op) = 0;
    virtual wxCompositionMode GetCompositionMode() const;
    virtual void PushState() = 0;
    virtual void PopState() = 0;
    virtual bool ShouldOffset() const;
    virtual void EnableOffset(bool enable = true);
    void DisableOffset();
    bool OffsetEnabled();
    virtual bool StartDoc( const wxString& message );
    virtual void EndDoc();
    virtual void StartPage( wxDouble width = 0, wxDouble height = 0 );
    virtual void EndPage();
    virtual void Flush();
    void GetSize(wxDouble* width, wxDouble* height) const;
    virtual void GetDPI( wxDouble* dpiX, wxDouble* dpiY);
};
WXGO_DECL_TYPECONV(GraphicsGradientStop)
class wxGraphicsGradientStop
{
public:
    wxGraphicsGradientStop(wxColour col = wxTransparentColour, float pos = 0.);
    const wxColour& GetColour() const;
    void SetColour(const wxColour& col);
    float GetPosition() const;
    void SetPosition(float pos);
};
WXGO_DECL_TYPECONV(GraphicsGradientStops)
class wxGraphicsGradientStops
{
public:
    wxGraphicsGradientStops(wxColour startCol = wxTransparentColour,
                            wxColour endCol = wxTransparentColour);
    void Add(const wxGraphicsGradientStop& stop);
    void Add(wxColour col, float pos);
    wxGraphicsGradientStop Item(unsigned n) const;
    size_t GetCount() const;
    void SetStartColour(wxColour col);
    wxColour GetStartColour() const;
    void SetEndColour(wxColour col);
    wxColour GetEndColour() const;
};
WXGO_DECL_TYPECONV(GraphicsRenderer)
class wxGraphicsRenderer : public wxObject
{
public:
    virtual wxGraphicsBitmap CreateBitmap( const wxBitmap &bitmap ) = 0;
    virtual wxGraphicsBitmap CreateBitmapFromImage(const wxImage& image) = 0;
    virtual wxImage CreateImageFromBitmap(const wxGraphicsBitmap& bmp) = 0;
    virtual wxGraphicsBitmap CreateBitmapFromNativeBitmap( void* bitmap ) = 0;
    virtual wxGraphicsContext* CreateContext(wxWindow* window) = 0;
    virtual wxGraphicsContext* CreateContext(const wxWindowDC& windowDC) = 0 ;
    virtual wxGraphicsContext* CreateContext(const wxMemoryDC& memoryDC) = 0 ;
    virtual wxGraphicsContext* CreateContext(const wxPrinterDC& printerDC) = 0 ;
#ifdef __WXMSW__
    virtual wxGraphicsContext* CreateContext(const wxEnhMetaFileDC& metaFileDC) = 0;
#endif
    wxGraphicsContext* CreateContextFromImage(wxImage& image);
    virtual wxGraphicsBrush CreateBrush(const wxBrush& brush) = 0;
    virtual wxGraphicsContext* CreateContextFromNativeContext(void* context) = 0;
    virtual wxGraphicsContext* CreateContextFromNativeWindow(void* window) = 0;
    virtual wxGraphicsContext * CreateMeasuringContext() = 0;
    virtual wxGraphicsFont CreateFont(const wxFont& font,
                                      const wxColour& col = *wxBLACK) = 0;
    virtual wxGraphicsFont CreateFont(double sizeInPixels,
                                      const wxString& facename,
                                      int flags = wxFONTFLAG_DEFAULT,
                                      const wxColour& col = *wxBLACK) = 0;
    virtual wxGraphicsBrush CreateLinearGradientBrush(wxDouble x1,
                                                      wxDouble y1,
                                                      wxDouble x2,
                                                      wxDouble y2,
                                                      const wxGraphicsGradientStops& stops) = 0;
    virtual wxGraphicsMatrix CreateMatrix(wxDouble a = 1.0, wxDouble b = 0.0,
                                          wxDouble c = 0.0, wxDouble d = 1.0,
                                          wxDouble tx = 0.0,
                                          wxDouble ty = 0.0) = 0;
    virtual wxGraphicsPath CreatePath() = 0;
    virtual wxGraphicsPen CreatePen(const wxPen& pen) = 0;
    virtual wxGraphicsBrush CreateRadialGradientBrush(wxDouble xo, wxDouble yo,
                                                      wxDouble xc, wxDouble yc,
                                                      wxDouble radius,
                                                      const wxGraphicsGradientStops& stops) = 0;
    virtual wxGraphicsBitmap CreateSubBitmap(const wxGraphicsBitmap& bitmap,
                                             wxDouble x, wxDouble y,
                                             wxDouble w, wxDouble h) = 0;
    virtual wxString GetName() const = 0;
    virtual void GetVersion(int* major, int* minor = NULL, int* micro=NULL) const = 0;
    static wxGraphicsRenderer* GetDefaultRenderer();
    static wxGraphicsRenderer* GetCairoRenderer();
};
WXGO_DECL_TYPECONV(GraphicsBrush)
class wxGraphicsBrush : public wxGraphicsObject
{
public:
};
WXGO_DECL_TYPECONV(GraphicsFont)
class wxGraphicsFont : public wxGraphicsObject
{
public:
};
WXGO_DECL_TYPECONV(GraphicsPen)
class wxGraphicsPen : public wxGraphicsObject
{
public:
};
WXGO_DECL_TYPECONV(GraphicsMatrix)
class wxGraphicsMatrix : public wxGraphicsObject
{
public:
    virtual void Concat(const wxGraphicsMatrix* t);
    virtual void Get(wxDouble* a = NULL, wxDouble* b = NULL,
                     wxDouble* c = NULL, wxDouble* d = NULL,
                     wxDouble* tx = NULL, wxDouble* ty = NULL) const;
    virtual void* GetNativeMatrix() const;
    virtual void Invert();
    virtual bool IsEqual(const wxGraphicsMatrix* t) const;
    virtual bool IsIdentity() const;
    virtual void Rotate(wxDouble angle);
    virtual void Scale(wxDouble xScale, wxDouble yScale);
    virtual void Set(wxDouble a = 1.0, wxDouble b = 0.0, wxDouble c = 0.0,
                     wxDouble d = 1.0, wxDouble tx = 0.0, wxDouble ty = 0.0);
    virtual void TransformDistance(wxDouble* dx, wxDouble* dy) const;
    virtual void TransformPoint(wxDouble* x, wxDouble* y) const;
    virtual void Translate(wxDouble dx, wxDouble dy);
};
const wxGraphicsPen     wxNullGraphicsPen;
const wxGraphicsBrush   wxNullGraphicsBrush;
const wxGraphicsFont    wxNullGraphicsFont;
const wxGraphicsBitmap  wxNullGraphicsBitmap;
const wxGraphicsMatrix  wxNullGraphicsMatrix;
const wxGraphicsPath    wxNullGraphicsPath;