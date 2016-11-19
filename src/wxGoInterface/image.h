%typedef int wxImageResolution;
#define wxIMAGE_RESOLUTION_NONE  0
#define wxIMAGE_RESOLUTION_INCHES  1
#define wxIMAGE_RESOLUTION_CM  2
%typedef int wxImageResizeQuality;
#define wxIMAGE_QUALITY_NEAREST 0
#define wxIMAGE_QUALITY_BILINEAR wxIMAGE_QUALITY_NEAREST + 1
#define wxIMAGE_QUALITY_BICUBIC wxIMAGE_QUALITY_BILINEAR + 1
#define wxIMAGE_QUALITY_BOX_AVERAGE wxIMAGE_QUALITY_BICUBIC + 1
#define wxIMAGE_QUALITY_NORMAL wxIMAGE_QUALITY_BOX_AVERAGE + 1
#define wxIMAGE_QUALITY_HIGH wxIMAGE_QUALITY_NORMAL + 1
%typedef int wxImagePNGType;
#define wxPNG_TYPE_COLOUR  0
#define wxPNG_TYPE_GREY  2
#define wxPNG_TYPE_GREY_RED  3
#define wxPNG_TYPE_PALETTE  4
#define wxIMAGE_OPTION_QUALITY                          wxString("quality")
#define wxIMAGE_OPTION_FILENAME                         wxString("FileName")
#define wxIMAGE_OPTION_RESOLUTION                       wxString("Resolution")
#define wxIMAGE_OPTION_RESOLUTIONX                      wxString("ResolutionX")
#define wxIMAGE_OPTION_RESOLUTIONY                      wxString("ResolutionY")
#define wxIMAGE_OPTION_RESOLUTIONUNIT                   wxString("ResolutionUnit")
#define wxIMAGE_OPTION_MAX_WIDTH                        wxString("MaxWidth")
#define wxIMAGE_OPTION_MAX_HEIGHT                       wxString("MaxHeight")
#define wxIMAGE_OPTION_ORIGINAL_WIDTH                   wxString("OriginalWidth")
#define wxIMAGE_OPTION_ORIGINAL_HEIGHT                  wxString("OriginalHeight")
#define wxIMAGE_OPTION_BMP_FORMAT                       wxString("wxBMP_FORMAT")
#define wxIMAGE_OPTION_CUR_HOTSPOT_X                    wxString("HotSpotX")
#define wxIMAGE_OPTION_CUR_HOTSPOT_Y                    wxString("HotSpotY")
#define wxIMAGE_OPTION_GIF_COMMENT                      wxString("GifComment")
#define wxIMAGE_OPTION_PNG_FORMAT                       wxString("PngFormat")
#define wxIMAGE_OPTION_PNG_BITDEPTH                     wxString("PngBitDepth")
#define wxIMAGE_OPTION_PNG_FILTER                       wxString("PngF")
#define wxIMAGE_OPTION_PNG_COMPRESSION_LEVEL            wxString("PngZL")
#define wxIMAGE_OPTION_PNG_COMPRESSION_MEM_LEVEL        wxString("PngZM")
#define wxIMAGE_OPTION_PNG_COMPRESSION_STRATEGY         wxString("PngZS")
#define wxIMAGE_OPTION_PNG_COMPRESSION_BUFFER_SIZE      wxString("PngZB")
#define wxIMAGE_OPTION_TIFF_BITSPERSAMPLE               wxString("BitsPerSample")
#define wxIMAGE_OPTION_TIFF_SAMPLESPERPIXEL             wxString("SamplesPerPixel")
#define wxIMAGE_OPTION_TIFF_COMPRESSION                 wxString("Compression")
#define wxIMAGE_OPTION_TIFF_PHOTOMETRIC                 wxString("Photometric")
#define wxIMAGE_OPTION_TIFF_IMAGEDESCRIPTOR             wxString("ImageDescriptor")
enum
{
    wxBMP_24BPP        = 24, 
    wxBMP_8BPP         =  8, 
    wxBMP_8BPP_GREY    =  9, 
    wxBMP_8BPP_GRAY    =  wxBMP_8BPP_GREY,
    wxBMP_8BPP_RED     = 10, 
    wxBMP_8BPP_PALETTE = 11, 
    wxBMP_4BPP         =  4, 
    wxBMP_1BPP         =  1, 
    wxBMP_1BPP_BW      =  2  
};
WXGO_DECL_TYPECONV(ImageHandler)
class wxImageHandler : public wxObject
{
public:
    wxImageHandler();
    virtual ~wxImageHandler();
    bool CanRead( wxInputStream& stream );
    bool CanRead( const wxString& filename );
    const wxString& GetExtension() const;
    const wxArrayString& GetAltExtensions() const;
    virtual int GetImageCount(wxInputStream& stream);
    const wxString& GetMimeType() const;
    const wxString& GetName() const;
    wxBitmapType GetType() const;
    virtual bool LoadFile(wxImage* image, wxInputStream& stream,
                          bool verbose = true, int index = -1);
    virtual bool SaveFile(wxImage* image, wxOutputStream& stream,
                          bool verbose = true);
    void SetExtension(const wxString& extension);
    void SetAltExtensions(const wxArrayString& extensions);
    void SetMimeType(const wxString& mimetype);
    void SetName(const wxString& name);
protected:
    virtual int DoGetImageCount( wxInputStream& stream );
    virtual bool DoCanRead( wxInputStream& stream ) = 0;
};
const unsigned char wxIMAGE_ALPHA_TRANSPARENT = 0;
const unsigned char wxIMAGE_ALPHA_OPAQUE = 0xff;
const unsigned char wxIMAGE_ALPHA_THRESHOLD = 0x80;
WXGO_DECL_TYPECONV(Image)
class wxImage : public wxObject
{
public:
    class RGBValue
    {
    public:
        RGBValue(unsigned char r=0, unsigned char g=0, unsigned char b=0);
        unsigned char red;
        unsigned char green;
        unsigned char blue;
    };
    class HSVValue
    {
    public:
        HSVValue(double h=0.0, double s=0.0, double v=0.0);
        double hue;
        double saturation;
        double value;        
    };
    wxImage();
    wxImage(int width, int height, bool clear = true);
    wxImage(const wxSize& sz, bool clear = true);
    wxImage(int width, int height, unsigned char* data, bool static_data = false);
    wxImage(const wxSize& sz, unsigned char* data, bool static_data = false);
    wxImage(int width, int height, unsigned char* data, unsigned char* alpha,
            bool static_data = false );
    wxImage(const wxSize& sz, unsigned char* data, unsigned char* alpha,
            bool static_data = false);
    wxImage(const char* const* xpmData);
    wxImage(const wxString& name, wxBitmapType type = wxBITMAP_TYPE_ANY, int index = -1);
    wxImage(const wxString& name, const wxString& mimetype, int index = -1);
    wxImage(wxInputStream& stream, wxBitmapType type = wxBITMAP_TYPE_ANY, int index = -1);
    wxImage(wxInputStream& stream, const wxString& mimetype, int index = -1);
    virtual ~wxImage();
    wxImage Copy() const;
    bool Create(int width, int height, bool clear = true);
    bool Create( const wxSize& sz, bool clear = true );
    bool Create( int width, int height, unsigned char* data, bool static_data = false );
    bool Create( const wxSize& sz, unsigned char* data, bool static_data = false );
    bool Create( int width, int height, unsigned char* data, unsigned char* alpha, bool static_data = false );
    bool Create( const wxSize& sz, unsigned char* data, unsigned char* alpha, bool static_data = false );
    void Clear(unsigned char value = 0);
    void Destroy();
    void InitAlpha();
    wxImage Blur(int blurRadius) const;
    wxImage BlurHorizontal(int blurRadius) const;
    wxImage BlurVertical(int blurRadius) const;
    wxImage Mirror(bool horizontally = true) const;
    void Paste(const wxImage& image, int x, int y);
    void Replace(unsigned char r1, unsigned char g1,
                 unsigned char b1, unsigned char r2,
                 unsigned char g2, unsigned char b2);
    wxImage& Rescale(int width, int height,
                     wxImageResizeQuality quality = wxIMAGE_QUALITY_NORMAL);
    wxImage& Resize(const wxSize& size, const wxPoint& pos, int red = -1,
                    int green = -1, int blue = -1);
    wxImage Rotate(double angle, const wxPoint& rotationCentre,
                   bool interpolating = true,
                   wxPoint* offsetAfterRotation = NULL) const;
    wxImage Rotate90(bool clockwise = true) const;
    wxImage Rotate180() const;
    void RotateHue(double angle);
    wxImage Scale(int width, int height,
                   wxImageResizeQuality quality = wxIMAGE_QUALITY_NORMAL) const;
    wxImage Size(const wxSize& size, const wxPoint& pos, int red = -1,
                 int green = -1, int blue = -1) const;
    bool ConvertAlphaToMask(unsigned char threshold = wxIMAGE_ALPHA_THRESHOLD);
    bool ConvertAlphaToMask(unsigned char mr, unsigned char mg, unsigned char mb,
                            unsigned char threshold = wxIMAGE_ALPHA_THRESHOLD);
    wxImage ConvertToGreyscale(double weight_r, double weight_g, double weight_b) const;
    wxImage ConvertToGreyscale() const;
    wxImage ConvertToMono(unsigned char r, unsigned char g, unsigned char b) const;
    wxImage ConvertToDisabled(unsigned char brightness = 255) const;
    unsigned long ComputeHistogram(wxImageHistogram& histogram) const;
    bool FindFirstUnusedColour(unsigned char* r, unsigned char* g,
                               unsigned char* b, unsigned char startR = 1,
                               unsigned char startG = 0,
                               unsigned char startB = 0) const;
    wxImage& operator=(const wxImage& image);
    unsigned char* GetAlpha() const;
    unsigned char* GetData() const;
    unsigned char GetAlpha(int x, int y) const;
    unsigned char GetRed(int x, int y) const;
    unsigned char GetGreen(int x, int y) const;
    unsigned char GetBlue(int x, int y) const;
    unsigned char GetMaskRed() const;
    unsigned char GetMaskGreen() const;
    unsigned char GetMaskBlue() const;
    int GetWidth() const;
    int GetHeight() const;
    wxSize GetSize() const;
    wxString GetOption(const wxString& name) const;
    int GetOptionInt(const wxString& name) const;
    bool GetOrFindMaskColour(unsigned char* r, unsigned char* g,
                             unsigned char* b) const;
    const wxPalette& GetPalette() const;
    wxImage GetSubImage(const wxRect& rect) const;
    wxBitmapType GetType() const;
    bool HasAlpha() const;
    bool HasMask() const;
    bool HasOption(const wxString& name) const;
    bool IsOk() const;
    bool IsTransparent(int x, int y,
                       unsigned char threshold = wxIMAGE_ALPHA_THRESHOLD) const;
    virtual bool LoadFile(wxInputStream& stream,
                          wxBitmapType type = wxBITMAP_TYPE_ANY,
                          int index = -1);
    virtual bool LoadFile(const wxString& name,
                          wxBitmapType type = wxBITMAP_TYPE_ANY,
                          int index = -1);
    virtual bool LoadFile(const wxString& name, const wxString& mimetype,
                          int index = -1);
    virtual bool LoadFile(wxInputStream& stream, const wxString& mimetype,
                          int index = -1);
    virtual bool SaveFile(wxOutputStream& stream,
                          const wxString& mimetype) const;
    virtual bool SaveFile(const wxString& name, wxBitmapType type) const;
    virtual bool SaveFile(const wxString& name, const wxString& mimetype) const;
    virtual bool SaveFile(const wxString& name) const;
    virtual bool SaveFile(wxOutputStream& stream, wxBitmapType type) const;
    void SetAlpha(unsigned char* alpha = NULL,
                  bool static_data = false);
    void SetAlpha(int x, int y, unsigned char alpha);
    void ClearAlpha();
    void SetData(unsigned char* data, bool static_data = false);
    void SetData(unsigned char* data, int new_width, int new_height,
                 bool static_data = false);
    static void SetDefaultLoadFlags(int flags);
    void SetLoadFlags(int flags);
    void SetMask(bool hasMask = true);
    void SetMaskColour(unsigned char red, unsigned char green,
                       unsigned char blue);
    bool SetMaskFromImage(const wxImage& mask, unsigned char mr,
                          unsigned char mg,
                          unsigned char mb);
    void SetOption(const wxString& name, const wxString& value);
    void SetOption(const wxString& name, int value);
    void SetPalette(const wxPalette& palette);
    void SetRGB( int x, int y, unsigned char r, unsigned char g, unsigned char b );
    void SetRGB(const wxRect& rect,
                unsigned char red,
                unsigned char green,
                unsigned char blue);
    void SetType(wxBitmapType type);
    static void AddHandler(wxImageHandler* handler);
    static void CleanUpHandlers();
    static wxImageHandler* FindHandler(const wxString& name);
    static wxImageHandler* FindHandler(const wxString& extension,
                                       wxBitmapType imageType);
    static wxImageHandler* FindHandler(wxBitmapType imageType);
    static wxImageHandler* FindHandlerMime(const wxString& mimetype);
    static wxList& GetHandlers();
    static void InitStandardHandlers();
    static void InsertHandler(wxImageHandler* handler);
    static bool RemoveHandler(const wxString& name);
    static bool CanRead(const wxString& filename);
    static bool CanRead(wxInputStream& stream);
    static int GetDefaultLoadFlags();
    static int GetImageCount(const wxString& filename,
                             wxBitmapType type = wxBITMAP_TYPE_ANY);
    static int GetImageCount(wxInputStream& stream,
                             wxBitmapType type = wxBITMAP_TYPE_ANY);
    static wxString GetImageExtWildcard();
    int GetLoadFlags() const;
    static wxImage::HSVValue RGBtoHSV(const wxImage::RGBValue& rgb);
    static wxImage::RGBValue HSVtoRGB(const wxImage::HSVValue& hsv);
};
WXGO_DECL_TYPECONV(ImageHistogram)
class wxImageHistogram : public wxImageHistogramBase
{
public:
    wxImageHistogram();
    static unsigned long MakeKey(unsigned char r,
                                 unsigned char g,
                                 unsigned char b);
    bool FindFirstUnusedColour(unsigned char *r,
                               unsigned char *g,
                               unsigned char *b,
                               unsigned char startR = 1,
                               unsigned char startG = 0,
                               unsigned char startB = 0 ) const;
};
%constant wxImage wxNullImage;
void wxInitAllImageHandlers();