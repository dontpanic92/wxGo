enum
{
    wxIMAGE_LIST_NORMAL, 
    wxIMAGE_LIST_SMALL,  
    wxIMAGE_LIST_STATE   
};
#define wxIMAGELIST_DRAW_NORMAL         0x0001
#define wxIMAGELIST_DRAW_TRANSPARENT    0x0002
#define wxIMAGELIST_DRAW_SELECTED       0x0004
#define wxIMAGELIST_DRAW_FOCUSED        0x0008
WXGO_DECL_TYPECONV(ImageList)
class wxImageList : public wxObject
{
public:
    wxImageList();
    wxImageList(int width, int height, bool mask = true,
                int initialCount = 1);
    int Add(const wxBitmap& bitmap,
            const wxBitmap& mask = wxNullBitmap);
    int Add(const wxBitmap& bitmap, const wxColour& maskColour);
#if defined(__WXMSW__) || defined(__WXOSX__)
    int Add(const wxIcon& icon);
#endif
    bool Create(int width, int height, bool mask = true,
                int initialCount = 1);
    virtual bool Draw(int index, wxDC& dc, int x, int y,
                      int flags = wxIMAGELIST_DRAW_NORMAL,
                      bool solidBackground = false);
    wxBitmap GetBitmap(int index) const;
    wxIcon GetIcon(int index) const;
    virtual int GetImageCount() const;
    virtual bool GetSize(int index, int& width, int& height) const;
    virtual wxSize GetSize() const;
    bool Remove(int index);
    bool RemoveAll();
    bool Replace(int index, const wxBitmap& bitmap,
                 const wxBitmap& mask = wxNullBitmap);
    bool Replace(int index, const wxIcon& icon);
};