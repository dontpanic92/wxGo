enum
{
    wxCC_SPECIAL_DCLICK             = 0x0100,
    wxCC_STD_BUTTON                 = 0x0200
};
WXGO_DECL_TYPECONV(ComboPopup)
class wxComboPopup
{
public:
    wxComboPopup();
    virtual bool Create(wxWindow* parent) = 0;
    virtual void DestroyPopup();
    void Dismiss();
    virtual bool FindItem(const wxString& item, wxString* trueItem=NULL);
    virtual wxSize GetAdjustedSize(int minWidth, int prefHeight, int maxHeight);
    wxComboCtrl* GetComboCtrl() const;
    virtual wxWindow* GetControl() = 0;
    virtual wxString GetStringValue() const = 0;
    virtual void Init();
    bool IsCreated() const;
    virtual bool LazyCreate();
    virtual void OnComboDoubleClick();
    virtual void OnComboKeyEvent(wxKeyEvent& event);
    virtual void OnDismiss();
    virtual void OnPopup();
    virtual void PaintComboControl(wxDC& dc, const wxRect& rect);
    virtual void SetStringValue(const wxString& value);
protected:
    wxComboCtrl*    m_combo;
};
struct wxComboCtrlFeatures
{
    enum
    {
        MovableButton   = 0x0001, 
        BitmapButton    = 0x0002, 
        ButtonSpacing   = 0x0004, 
        TextIndent      = 0x0008, 
        PaintControl    = 0x0010, 
        PaintWritable   = 0x0020, 
        Borderless      = 0x0040, 
        All             = MovableButton | BitmapButton | ButtonSpacing |
                          TextIndent | PaintControl | PaintWritable |
                          Borderless 
    };
};
WXGO_DECL_TYPECONV(ComboCtrl)
class wxComboCtrl : public wxControl,
                    public wxTextEntry
{
public:
    wxComboCtrl();
    wxComboCtrl(wxWindow* parent, wxWindowID id = wxID_ANY,
                const wxString& value = wxEmptyString,
                const wxPoint& pos = wxDefaultPosition,
                const wxSize& size = wxDefaultSize,
                long style = 0,
                const wxValidator& validator = wxDefaultValidator,
                const wxString& name = wxComboBoxNameStr);
    virtual ~wxComboCtrl();
    virtual void Copy();
    bool Create(wxWindow* parent, wxWindowID id = wxID_ANY,
                const wxString& value = wxEmptyString,
                const wxPoint& pos = wxDefaultPosition,
                const wxSize& size = wxDefaultSize,
                long style = 0,
                const wxValidator& validator = wxDefaultValidator,
                const wxString& name = wxComboBoxNameStr);
    virtual void Cut();
    virtual void Dismiss();
    void EnablePopupAnimation(bool enable = true);
    virtual bool IsKeyPopupToggle(const wxKeyEvent& event) const;
    virtual void PrepareBackground( wxDC& dc, const wxRect& rect, int flags ) const;
    bool ShouldDrawFocus() const;
    const wxBitmap& GetBitmapDisabled() const;
    const wxBitmap& GetBitmapHover() const;
    const wxBitmap& GetBitmapNormal() const;
    const wxBitmap& GetBitmapPressed() const;
    wxSize GetButtonSize();
    int GetCustomPaintWidth() const;
    static int GetFeatures();
    virtual wxString GetHint() const;
    virtual long GetInsertionPoint() const;
    virtual long GetLastPosition() const;
    wxPoint GetMargins() const;
    wxComboPopup* GetPopupControl();
    wxWindow* GetPopupWindow() const;
    wxTextCtrl* GetTextCtrl() const;
    const wxRect& GetTextRect() const;
    virtual wxString GetValue() const;
    virtual void HidePopup(bool generateEvent=false);
    bool IsPopupShown() const;
    bool IsPopupWindowState(int state) const;
    virtual void OnButtonClick();
    virtual void Paste();
    virtual void Popup();
    virtual void Remove(long from, long to);
    virtual void Replace(long from, long to, const wxString& text);
    void SetButtonBitmaps(const wxBitmap& bmpNormal,
                          bool pushButtonBg = false,
                          const wxBitmap& bmpPressed = wxNullBitmap,
                          const wxBitmap& bmpHover = wxNullBitmap,
                          const wxBitmap& bmpDisabled = wxNullBitmap);
    void SetButtonPosition(int width = -1, int height = -1,
                           int side = wxRIGHT, int spacingX = 0);
    void SetCustomPaintWidth(int width);
    virtual bool SetHint(const wxString& hint);
    virtual void SetInsertionPoint(long pos);
    virtual void SetInsertionPointEnd();
    bool SetMargins(const wxPoint& pt);
    bool SetMargins(wxCoord left, wxCoord top = -1);
    void SetPopupAnchor(int anchorSide);
    void SetPopupControl(wxComboPopup* popup);
    void SetPopupExtents(int extLeft, int extRight);
    void SetPopupMaxHeight(int height);
    void SetPopupMinWidth(int width);
    virtual void SetSelection(long from, long to);
    void SetText(const wxString& value);
    void SetTextCtrlStyle( int style );
    virtual void SetValue(const wxString& value);
    void SetValueByUser(const wxString& value);
    virtual void ShowPopup();
    virtual void Undo();
    void UseAltPopupWindow(bool enable = true);
protected:
    virtual bool AnimateShow(const wxRect& rect, int flags);
    virtual void DoSetPopupControl(wxComboPopup* popup);
    enum
    {
        ShowBelow       = 0x0000, 
        ShowAbove       = 0x0001, 
        CanDeferShow    = 0x0002  
    };
    virtual void DoShowPopup(const wxRect& rect, int flags);
};