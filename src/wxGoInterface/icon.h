#define wxICON_SCREEN_DEPTH       (-1)
WXGO_DECL_TYPECONV(Icon)
class wxIcon : public wxGDIObject
{
public:
    wxIcon();
    wxIcon(const wxIcon& icon);
#if defined(__WXMSW__) || defined(__WXOSX__)
    wxIcon(const char bits[], int width, int height);
#endif
    wxIcon(const char* const* bits);
    wxIcon(const wxString& name, wxBitmapType type = wxICON_DEFAULT_TYPE,
           int desiredWidth = -1, int desiredHeight = -1);
    wxIcon(const wxIconLocation& loc);
    virtual ~wxIcon();
#ifdef __WXMSW__
    bool CreateFromHICON(WXHICON icon);
#endif
#ifdef __WXMSW__
#endif
    void CopyFromBitmap(const wxBitmap& bmp);
    int GetDepth() const;
    int GetHeight() const;
    int GetWidth() const;
    virtual bool IsOk() const;
    bool LoadFile(const wxString& name, wxBitmapType type,
                  int desiredWidth, int desiredHeight);
    void SetDepth(int depth);
    void SetHeight(int height);
    void SetWidth(int width);
    wxIcon& operator=(const wxIcon& icon);
};
%constant wxIcon wxNullIcon;