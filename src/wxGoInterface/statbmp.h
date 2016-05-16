class wxStaticBitmap : public wxControl
{
public:
    enum ScaleMode
    {
        Scale_None,
        Scale_Fill,
        Scale_AspectFit,
        Scale_AspectFill
    };
    wxStaticBitmap();
    wxStaticBitmap(wxWindow* parent, wxWindowID id,
                   const wxBitmap& label,
                   const wxPoint& pos = wxDefaultPosition,
                   const wxSize& size = wxDefaultSize,
                   long style = 0,
                   const wxString& name = wxStaticBitmapNameStr);
    bool Create(wxWindow* parent, wxWindowID id, const wxBitmap& label,
                const wxPoint& pos = wxDefaultPosition,
                const wxSize& size = wxDefaultSize, long style = 0,
                const wxString& name = wxStaticBitmapNameStr);
    virtual wxBitmap GetBitmap() const;
    virtual wxIcon GetIcon() const;
    virtual void SetBitmap(const wxBitmap& label);
    virtual void SetIcon(const wxIcon& label);
    virtual void SetScaleMode(ScaleMode scaleMode);
    virtual ScaleMode GetScaleMode() const;
};