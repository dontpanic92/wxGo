WXGO_DECL_TYPECONV(ActivityIndicator)
class wxActivityIndicator : public wxControl
{
public:
    wxActivityIndicator();
    explicit wxActivityIndicator(wxWindow* parent,
                                 wxWindowID winid = wxID_ANY,
                                 const wxPoint& pos = wxDefaultPosition,
                                 const wxSize& size = wxDefaultSize,
                                 long style = 0,
                                 const wxString& name = "activityindicator");
    bool Create(wxWindow* parent,
                wxWindowID winid = wxID_ANY,
                const wxPoint& pos = wxDefaultPosition,
                const wxSize& size = wxDefaultSize,
                long style = 0,
                const wxString& name = "activityindicator");
    void Start();
    void Stop();
    bool IsRunning() const;
};