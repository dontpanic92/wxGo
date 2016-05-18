WXGO_DECL_TYPECONV(ScrollBar)
class wxScrollBar : public wxControl
{
public:
    wxScrollBar();
    wxScrollBar(wxWindow* parent, wxWindowID id,
                const wxPoint& pos = wxDefaultPosition,
                const wxSize& size = wxDefaultSize,
                long style = wxSB_HORIZONTAL,
                const wxValidator& validator = wxDefaultValidator,
                const wxString& name = wxScrollBarNameStr);
    virtual ~wxScrollBar();
    bool Create(wxWindow* parent, wxWindowID id,
                const wxPoint& pos = wxDefaultPosition,
                const wxSize& size = wxDefaultSize, long style = wxSB_HORIZONTAL,
                const wxValidator& validator = wxDefaultValidator,
                const wxString& name = wxScrollBarNameStr);
    virtual int GetPageSize() const;
    virtual int GetRange() const;
    virtual int GetThumbPosition() const;
    virtual int GetThumbSize() const;
    virtual void SetScrollbar(int position, int thumbSize, int range,
                              int pageSize,
                              bool refresh = true);
    virtual void SetThumbPosition(int viewStart);
    bool IsVertical() const;
};