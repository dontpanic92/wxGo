WXGO_DECL_TYPECONV(SpinCtrl)
class wxSpinCtrl : public wxControl
{
public:
    wxSpinCtrl();
    wxSpinCtrl(wxWindow* parent, wxWindowID id = wxID_ANY,
               const wxString& value = wxEmptyString,
               const wxPoint& pos = wxDefaultPosition,
               const wxSize& size = wxDefaultSize,
               long style = wxSP_ARROW_KEYS,
               int min = 0, int max = 100,
               int initial = 0, const wxString& name = "wxSpinCtrl");
    bool Create(wxWindow* parent, wxWindowID id = wxID_ANY,
                const wxString& value = wxEmptyString,
                const wxPoint& pos = wxDefaultPosition,
                const wxSize& size = wxDefaultSize,
                long style = wxSP_ARROW_KEYS, int min = 0, int max = 100,
                int initial = 0, const wxString& name = "wxSpinCtrl");
    int GetBase() const;
    int GetMax() const;
    int GetMin() const;
    int GetValue() const;
    bool SetBase(int base);
    void SetRange(int minVal, int maxVal);
    virtual void SetSelection(long from, long to);
    virtual void SetValue(const wxString& text);
    void SetValue(int value);
};
WXGO_DECL_TYPECONV(SpinCtrlDouble)
class wxSpinCtrlDouble : public wxControl
{
public:
    wxSpinCtrlDouble();
    wxSpinCtrlDouble(wxWindow* parent, wxWindowID id = -1,
               const wxString& value = wxEmptyString,
               const wxPoint& pos = wxDefaultPosition,
               const wxSize& size = wxDefaultSize,
               long style = wxSP_ARROW_KEYS,
               double min = 0, double max = 100,
               double initial = 0, double inc = 1,
               const wxString& name = wxT("wxSpinCtrlDouble"));
    bool Create(wxWindow* parent, wxWindowID id = wxID_ANY,
                const wxString& value = wxEmptyString,
                const wxPoint& pos = wxDefaultPosition,
                const wxSize& size = wxDefaultSize,
                long style = wxSP_ARROW_KEYS, double min = 0, double max = 100,
                double initial = 0, double inc = 1,
                const wxString& name = "wxSpinCtrlDouble");
    unsigned int GetDigits() const;
    double GetIncrement() const;
    double GetMax() const;
    double GetMin() const;
    double GetValue() const;
    void SetDigits(unsigned int digits);
    void SetIncrement(double inc);
    void SetRange(double minVal, double maxVal);
    virtual void SetValue(const wxString& text);
    void SetValue(double value);
};
WXGO_DECL_TYPECONV(SpinDoubleEvent)
class wxSpinDoubleEvent : public wxNotifyEvent
{
public:
    wxSpinDoubleEvent(wxEventType commandType = wxEVT_NULL, int winid = 0,
                      double value = 0);
    wxSpinDoubleEvent(const wxSpinDoubleEvent& event);
    double GetValue() const;
    void SetValue(double value);
};
%constant wxEventType wxEVT_SPINCTRL;
%constant wxEventType wxEVT_SPINCTRLDOUBLE;