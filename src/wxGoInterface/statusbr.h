class wxStatusBarPane
{
public:
    wxStatusBarPane(int style = wxSB_NORMAL, int width = 0)
        : m_nStyle(style), m_nWidth(width)
        { m_bEllipsized = false; }

    int GetWidth() const { return m_nWidth; }
    int GetStyle() const { return m_nStyle; }
    wxString GetText() const { return m_text; }

    bool IsEllipsized() const;
    void SetIsEllipsized(bool isEllipsized) { m_bEllipsized = isEllipsized; }

    void SetWidth(int width) { m_nWidth = width; }
    void SetStyle(int style) { m_nStyle = style; }

    bool SetText(const wxString& text);

    bool PushText(const wxString& text);

    bool PopText();
};

class wxStatusBar : public wxControl
{
public:
    ~wxStatusBar();

    wxStatusBar(wxWindow *parent,
                       wxWindowID winid = wxID_ANY,
                       long style = wxSTB_DEFAULT_STYLE,
                       const wxString& name = wxStatusBarNameStr);


    bool Create(wxWindow *parent, wxWindowID winid = wxID_ANY,
                long style = wxSTB_DEFAULT_STYLE,
                const wxString& name = wxStatusBarNameStr);

    void SetStatusWidths(int n, const int widths_field[]);
    bool GetFieldRect(int i, wxRect& rect) const;
    void SetMinHeight(int height);

    int GetFieldFromPoint(const wxPoint& point) const;
    void SetFieldsCount(int number = 1, const int *widths = NULL);
    int GetFieldsCount() const ;
    void SetStatusText(const wxString& text, int number = 0);
    wxString GetStatusText(int number = 0) const;

    void PushStatusText(const wxString& text, int number = 0);
    void PopStatusText(int number = 0);

    void SetStatusStyles(int n, const int styles[]);

    int GetStatusStyle(int n) const;
    int GetBorderX() const;
    int GetBorderY() const;

    wxSize GetBorders() const;

    const wxStatusBarPane& GetField(int n) const;
    bool AcceptsFocus() const;
    bool CanBeOutsideClientArea() const ;
};

