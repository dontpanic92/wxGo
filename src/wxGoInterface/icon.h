WXGO_DECL_TYPECONV(Icon)
#define wxICON_SCREEN_DEPTH       (-1)
class wxIcon : public wxGDIObject
{
public:
    wxIcon();
    wxIcon(const wxIcon& icon);
    wxIcon(const char bits[], int width, int height);
    wxIcon(const char* const* bits);
    wxIcon(const wxString& name, wxBitmapType type = wxICON_DEFAULT_TYPE,
           int desiredWidth = -1, int desiredHeight = -1);
    wxIcon(const wxIconLocation& loc);
    virtual ~wxIcon();
    bool CreateFromHICON(WXHICON icon);
    wxIcon ConvertToDisabled(unsigned char brightness = 255) const;
    void CopyFromBitmap(const wxBitmap& bmp);
    int GetDepth() const;
    int GetHeight() const;
    int GetWidth() const;
    virtual bool IsOk() const;
    bool LoadFile(const wxString& name, wxBitmapType type = wxICON_DEFAULT_TYPE,
                  int desiredWidth = -1, int desiredHeight = -1);
    void SetDepth(int depth);
    void SetHeight(int height);
    void SetWidth(int width);
    wxIcon& operator=(const wxIcon& icon);
};
%constant wxIcon wxNullIcon;