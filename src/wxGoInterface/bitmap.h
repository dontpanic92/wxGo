#define wxBITMAP_SCREEN_DEPTH       (-1)
WXGO_DECL_TYPECONV(BitmapHandler)
class wxBitmapHandler : public wxObject
{
public:
    wxBitmapHandler();
    virtual ~wxBitmapHandler();
    virtual bool Create(wxBitmap* bitmap, const void* data, wxBitmapType type,
                        int width, int height, int depth = 1);
    const wxString& GetExtension() const;
    const wxString& GetName() const;
    wxBitmapType GetType() const;
    virtual bool LoadFile(wxBitmap* bitmap, const wxString& name, wxBitmapType type,
                          int desiredWidth, int desiredHeight);
    virtual bool SaveFile(const wxBitmap* bitmap, const wxString& name, wxBitmapType type,
                          const wxPalette* palette = NULL) const;
    void SetExtension(const wxString& extension);
    void SetName(const wxString& name);
    void SetType(wxBitmapType type);
};
WXGO_DECL_TYPECONV(Bitmap)
class wxBitmap : public wxGDIObject
{
public:
    wxBitmap();
    wxBitmap(const wxBitmap& bitmap);
    wxBitmap(const char bits[], int width, int height, int depth = 1);
    wxBitmap(int width, int height, int depth = wxBITMAP_SCREEN_DEPTH);
    wxBitmap(const wxSize& sz, int depth = wxBITMAP_SCREEN_DEPTH);
    wxBitmap(const char* const* bits);
    wxBitmap(const wxString& name, wxBitmapType type = wxBITMAP_DEFAULT_TYPE);
    wxBitmap(const wxImage& img, int depth = wxBITMAP_SCREEN_DEPTH);
    virtual ~wxBitmap();
    static void AddHandler(wxBitmapHandler* handler);
    static void CleanUpHandlers();
    virtual wxImage ConvertToImage() const;
    virtual bool CopyFromIcon(const wxIcon& icon);
    virtual bool Create(int width, int height, int depth = wxBITMAP_SCREEN_DEPTH);
    virtual bool Create(const wxSize& sz, int depth = wxBITMAP_SCREEN_DEPTH);
    static wxBitmapHandler* FindHandler(const wxString& name);
    static wxBitmapHandler* FindHandler(const wxString& extension,
                                        wxBitmapType bitmapType);
    static wxBitmapHandler* FindHandler(wxBitmapType bitmapType);
    virtual int GetDepth() const;
    static wxList& GetHandlers();
    virtual int GetHeight() const;
    virtual wxMask* GetMask() const;
    virtual wxPalette* GetPalette() const;
    virtual wxBitmap GetSubBitmap(const wxRect& rect) const;
    wxSize GetSize() const;
    wxBitmap ConvertToDisabled(unsigned char brightness = 255) const;
    virtual int GetWidth() const;
    static void InitStandardHandlers();
    static void InsertHandler(wxBitmapHandler* handler);
    virtual bool IsOk() const;
    virtual bool LoadFile(const wxString& name, wxBitmapType type = wxBITMAP_DEFAULT_TYPE);
    static wxBitmap NewFromPNGData(const void* data, size_t size);
    static bool RemoveHandler(const wxString& name);
    virtual bool SaveFile(const wxString& name, wxBitmapType type,
                          const wxPalette* palette = NULL) const;
    virtual void SetDepth(int depth);
    virtual void SetHeight(int height);
    virtual void SetMask(wxMask* mask);
    virtual void SetPalette(const wxPalette& palette);
    virtual void SetWidth(int width);
};
%constant wxBitmap wxNullBitmap;
WXGO_DECL_TYPECONV(Mask)
class wxMask : public wxObject
{
public:
    wxMask();
    wxMask(const wxBitmap& bitmap, int index);
    wxMask(const wxBitmap& bitmap);
    wxMask(const wxBitmap& bitmap, const wxColour& colour);
    virtual ~wxMask();
    bool Create(const wxBitmap& bitmap, int index);
    bool Create(const wxBitmap& bitmap);
    bool Create(const wxBitmap& bitmap, const wxColour& colour);
    wxBitmap GetBitmap() const;
};