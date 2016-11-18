WXGO_DECL_TYPECONV(WithImages)
class wxWithImages
{
public:
    enum
    {
        NO_IMAGE = -1
    };
    wxWithImages();
    virtual ~wxWithImages();
    void AssignImageList(wxImageList* imageList);
    virtual void SetImageList(wxImageList* imageList);
    wxImageList* GetImageList() const;
protected:
    bool HasImageList() const;
    wxIcon GetImage(int iconIndex) const;
};