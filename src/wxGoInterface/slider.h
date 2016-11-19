#define wxSL_HORIZONTAL      wxHORIZONTAL 
#define wxSL_VERTICAL        wxVERTICAL   
#define wxSL_TICKS           0x0010
#define wxSL_AUTOTICKS       wxSL_TICKS 
#define wxSL_LEFT            0x0040
#define wxSL_TOP             0x0080
#define wxSL_RIGHT           0x0100
#define wxSL_BOTTOM          0x0200
#define wxSL_BOTH            0x0400
#define wxSL_SELRANGE        0x0800
#define wxSL_INVERSE         0x1000
#define wxSL_MIN_MAX_LABELS  0x2000
#define wxSL_VALUE_LABEL     0x4000
#define wxSL_LABELS          (wxSL_MIN_MAX_LABELS|wxSL_VALUE_LABEL)
WXGO_DECL_TYPECONV(Slider)
class wxSlider : public wxControl
{
public:
    wxSlider();
    wxSlider(wxWindow* parent, wxWindowID id, int value,
             int minValue, int maxValue,
             const wxPoint& pos = wxDefaultPosition,
             const wxSize& size = wxDefaultSize,
             long style = wxSL_HORIZONTAL,
             const wxValidator& validator = wxDefaultValidator,
             const wxString& name = wxSliderNameStr);
    virtual ~wxSlider();
    virtual void ClearSel();
    virtual void ClearTicks();
    bool Create(wxWindow* parent, wxWindowID id, int value, int minValue,
                int maxValue, const wxPoint& point = wxDefaultPosition,
                const wxSize& size = wxDefaultSize, long style = wxSL_HORIZONTAL,
                const wxValidator& validator = wxDefaultValidator,
                const wxString& name = wxSliderNameStr);
    virtual int GetLineSize() const;
    virtual int GetMax() const;
    virtual int GetMin() const;
    virtual int GetPageSize() const;
    virtual int GetSelEnd() const;
    virtual int GetSelStart() const;
    virtual int GetThumbLength() const;
    virtual int GetTickFreq() const;
    virtual int GetValue() const;
    virtual void SetLineSize(int lineSize);
    void SetMin( int minValue );
    void SetMax( int maxValue );
    virtual void SetPageSize(int pageSize);
    virtual void SetRange(int minValue, int maxValue);
    virtual void SetSelection(int startPos, int endPos);
    virtual void SetThumbLength(int len);
    virtual void SetTick(int tickPos);
    virtual void SetTickFreq(int n);
    virtual void SetValue(int value);
};