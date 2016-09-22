WXGO_DECL_TYPECONV(Caret)
class wxCaret
{
public:
    wxCaret();
    wxCaret(wxWindow* window, int width, int height);
    wxCaret(wxWindow* window, const wxSize& size);
    bool Create(wxWindow* window, int width, int height);
    bool Create(wxWindow* window, const wxSize& size);
    static int GetBlinkTime();
    void GetPosition(int* x, int* y) const;
    wxPoint GetPosition() const;
    void GetSize(int* width, int* height) const;
    wxSize GetSize() const;
    wxWindow* GetWindow() const;
    virtual void Hide();
    bool IsOk() const;
    bool IsVisible() const;
    void Move(int x, int y);
    void Move(const wxPoint& pt);
    static void SetBlinkTime(int milliseconds);
    void SetSize(int width, int height);
    void SetSize(const wxSize& size);
    virtual void Show(bool show = true);
};