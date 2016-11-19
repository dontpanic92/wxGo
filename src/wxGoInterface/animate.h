%typedef int wxAnimationType;
#define wxANIMATION_TYPE_INVALID 0
#define wxANIMATION_TYPE_GIF wxANIMATION_TYPE_INVALID + 1
#define wxANIMATION_TYPE_ANI wxANIMATION_TYPE_GIF + 1
#define wxANIMATION_TYPE_ANY wxANIMATION_TYPE_ANI + 1
#define wxAC_NO_AUTORESIZE       (0x0010)
#define wxAC_DEFAULT_STYLE       (wxBORDER_NONE)
WXGO_DECL_TYPECONV(AnimationCtrl)
class wxAnimationCtrl : public wxControl
{
public:
    wxAnimationCtrl(wxWindow* parent, wxWindowID id,
                    const wxAnimation& anim = wxNullAnimation,
                    const wxPoint& pos = wxDefaultPosition,
                    const wxSize& size = wxDefaultSize,
                    long style = wxAC_DEFAULT_STYLE,
                    const wxString& name = wxAnimationCtrlNameStr);
    bool Create(wxWindow* parent, wxWindowID id,
                const wxAnimation& anim = wxNullAnimation,
                const wxPoint& pos = wxDefaultPosition,
                const wxSize& size = wxDefaultSize,
                long style = wxAC_DEFAULT_STYLE,
                const wxString& name = wxAnimationCtrlNameStr);
    virtual wxAnimation GetAnimation() const;
    wxBitmap GetInactiveBitmap() const;
    virtual bool IsPlaying() const;
    virtual bool LoadFile(const wxString& file,
                          wxAnimationType animType = wxANIMATION_TYPE_ANY);
    virtual bool Load(wxInputStream& file,
                      wxAnimationType animType = wxANIMATION_TYPE_ANY);
    virtual bool Play();
    virtual void SetAnimation(const wxAnimation& anim);
    virtual void SetInactiveBitmap(const wxBitmap& bmp);
    virtual void Stop();
};
WXGO_DECL_TYPECONV(Animation)
class wxAnimation : public wxObject
{
public:
    wxAnimation();
    wxAnimation(const wxAnimation& anim);
    wxAnimation(const wxString& name,
                wxAnimationType type = wxANIMATION_TYPE_ANY);
    virtual ~wxAnimation();
    virtual int GetDelay(unsigned int i) const;
    virtual wxImage GetFrame(unsigned int i) const;
    virtual unsigned int GetFrameCount() const;
    virtual wxSize GetSize() const;
    virtual bool IsOk() const;
    virtual bool Load(wxInputStream& stream,
                      wxAnimationType type = wxANIMATION_TYPE_ANY);
    virtual bool LoadFile(const wxString& name,
                          wxAnimationType type = wxANIMATION_TYPE_ANY);
    wxAnimation& operator =(const wxAnimation& brush);
};
%constant wxAnimation wxNullAnimation;