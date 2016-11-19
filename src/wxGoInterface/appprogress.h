WXGO_DECL_TYPECONV(AppProgressIndicator)
class wxAppProgressIndicator
{
public:
    wxAppProgressIndicator(wxWindow* parent = NULL, int maxValue = 100);
    virtual ~wxAppProgressIndicator();
    bool IsAvailable() const;
    void SetValue(int value);
    void SetRange(int range);
    void Pulse();
};