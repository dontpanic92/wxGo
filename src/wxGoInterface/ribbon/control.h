WXGO_DECL_TYPECONV(RibbonControl)
class wxRibbonControl : public wxControl
{
public:
    wxRibbonControl();
    wxRibbonControl(wxWindow *parent, wxWindowID id,
                    const wxPoint& pos = wxDefaultPosition,
                    const wxSize& size = wxDefaultSize, long style = 0,
                    const wxValidator& validator = wxDefaultValidator,
                    const wxString& name = wxControlNameStr);
    virtual void SetArtProvider(wxRibbonArtProvider* art);
    wxRibbonArtProvider* GetArtProvider() const;
    virtual bool IsSizingContinuous() const;
    wxSize GetNextSmallerSize(wxOrientation direction) const;
    wxSize GetNextSmallerSize(wxOrientation direction, wxSize relative_to) const;
    wxSize GetNextLargerSize(wxOrientation direction) const;
    wxSize GetNextLargerSize(wxOrientation direction, wxSize relative_to) const;
    virtual bool Realize();
    bool Realise();
    virtual wxRibbonBar* GetAncestorRibbonBar()const;
    virtual wxSize GetBestSizeForParentSize(const wxSize& parentSize) const;
protected:
    virtual wxSize DoGetNextSmallerSize(wxOrientation direction,
                                        wxSize relative_to) const;
    virtual wxSize DoGetNextLargerSize(wxOrientation direction,
                                       wxSize relative_to) const;
};