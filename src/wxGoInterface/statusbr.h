#define wxSTB_SIZEGRIP         0x0010
#define wxSTB_SHOW_TIPS        0x0020
#define wxSTB_ELLIPSIZE_START   0x0040
#define wxSTB_ELLIPSIZE_MIDDLE  0x0080
#define wxSTB_ELLIPSIZE_END     0x0100
%constant int wxSTB_DEFAULT_STYLE = (wxSTB_SIZEGRIP|wxSTB_ELLIPSIZE_END|wxSTB_SHOW_TIPS|wxFULL_REPAINT_ON_RESIZE);
#define wxSB_NORMAL    0x0000
#define wxSB_FLAT      0x0001
#define wxSB_RAISED    0x0002
#define wxSB_SUNKEN    0x0003
WXGO_DECL_TYPECONV(StatusBarPane)
class wxStatusBarPane
{
public:
    wxStatusBarPane(int style = wxSB_NORMAL, int width = 0);
    int GetWidth() const;
    int GetStyle() const;
    wxString GetText() const;
};
WXGO_DECL_TYPECONV(StatusBar)
class wxStatusBar : public wxControl
{
public:
    wxStatusBar();
    wxStatusBar(wxWindow* parent, wxWindowID id = wxID_ANY,
                long style = wxSTB_DEFAULT_STYLE,
                const wxString& name = wxStatusBarNameStr);
    virtual ~wxStatusBar();
    bool Create(wxWindow* parent, wxWindowID id = wxID_ANY,
                long style = wxSTB_DEFAULT_STYLE,
                const wxString& name = wxStatusBarNameStr);
    virtual bool GetFieldRect(int i, wxRect& rect) const;
    int GetFieldsCount() const;
    const wxStatusBarPane& GetField(int n) const;
    wxSize GetBorders() const;
    virtual wxString GetStatusText(int i = 0) const;
    int GetStatusWidth(int n) const;
    int GetStatusStyle(int n) const;
    void PopStatusText(int field = 0);
    void PushStatusText(const wxString& string, int field = 0);
    virtual void SetFieldsCount(int number = 1, const int* widths = NULL);
    virtual void SetMinHeight(int height);
    virtual void SetStatusStyles(int n, const int* styles);
    virtual void SetStatusText(const wxString& text, int i = 0);
    virtual void SetStatusWidths(int n, const int* widths_field);
};