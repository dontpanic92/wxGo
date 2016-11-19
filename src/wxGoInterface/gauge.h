#define wxGA_HORIZONTAL      wxHORIZONTAL
#define wxGA_VERTICAL        wxVERTICAL
#define wxGA_PROGRESS        0x0010
#define wxGA_SMOOTH          0x0020
#define wxGA_TEXT            0x0040
WXGO_DECL_TYPECONV(Gauge)
class wxGauge : public wxControl
{
public:
    wxGauge();
    wxGauge(wxWindow* parent, wxWindowID id, int range,
            const wxPoint& pos = wxDefaultPosition,
            const wxSize& size = wxDefaultSize,
            long style = wxGA_HORIZONTAL,
            const wxValidator& validator = wxDefaultValidator,
            const wxString& name = wxGaugeNameStr);
    virtual ~wxGauge();
    bool Create(wxWindow* parent, wxWindowID id, int range,
                const wxPoint& pos = wxDefaultPosition,
                const wxSize& size = wxDefaultSize, long style = wxGA_HORIZONTAL,
                const wxValidator& validator = wxDefaultValidator,
                const wxString& name = wxGaugeNameStr);
    int GetRange() const;
    int GetValue() const;
    bool IsVertical() const;
    virtual void Pulse();
    void SetRange(int range);
    void SetValue(int pos);
};