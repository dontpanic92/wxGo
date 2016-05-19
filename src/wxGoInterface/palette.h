WXGO_DECL_TYPECONV(Palette)
class wxPalette : public wxGDIObject
{
public:
    wxPalette();
    wxPalette(const wxPalette& palette);
    wxPalette(int n, const unsigned char* red,
              const unsigned char* green,
              const unsigned char* blue);
    virtual ~wxPalette();
    bool Create(int n, const unsigned char* red,
                const unsigned char* green,
                const unsigned char* blue);
    virtual int GetColoursCount() const;
    int GetPixel(unsigned char red, unsigned char green,
                 unsigned char blue) const;
    bool GetRGB(int pixel, unsigned char* red, unsigned char* green,
                unsigned char* blue) const;
    virtual bool IsOk() const;
    wxPalette& operator =(const wxPalette& palette);
};
%constant wxPalette wxNullPalette;