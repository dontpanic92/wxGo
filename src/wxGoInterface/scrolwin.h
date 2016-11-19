%typedef int wxScrollbarVisibility;
#define wxSHOW_SB_NEVER  -1
#define wxSHOW_SB_DEFAULT wxSHOW_SB_NEVER  + 1
#define wxSHOW_SB_ALWAYS wxSHOW_SB_DEFAULT + 1
template<class T>
class wxScrolled : public T
{
public:
    wxScrolled();
    wxScrolled(wxWindow* parent, wxWindowID id = -1,
               const wxPoint& pos = wxDefaultPosition,
               const wxSize& size = wxDefaultSize,
               long style = wxHSCROLL | wxVSCROLL,
               const wxString& name = "scrolledWindow");
    void CalcScrolledPosition(int x, int y, int* xx, int* yy) const;
    wxPoint CalcScrolledPosition(const wxPoint& pt) const;
    void CalcUnscrolledPosition(int x, int y, int* xx, int* yy) const;
    wxPoint CalcUnscrolledPosition(const wxPoint& pt) const;
    bool Create(wxWindow* parent, wxWindowID id = -1,
                const wxPoint& pos = wxDefaultPosition,
                const wxSize& size = wxDefaultSize,
                long style = wxHSCROLL | wxVSCROLL,
                const wxString& name = "scrolledWindow");
    void DisableKeyboardScrolling();
    void DoPrepareDC(wxDC& dc);
    void EnableScrolling(bool xScrolling, bool yScrolling);
    void ShowScrollbars(wxScrollbarVisibility horz, wxScrollbarVisibility vert);
    void GetScrollPixelsPerUnit(int* xUnit, int* yUnit) const;
    void GetViewStart(int* x, int* y) const;
    wxPoint GetViewStart() const;
    void GetVirtualSize(int* x, int* y) const;
    bool IsRetained() const;
    virtual void OnDraw(wxDC& dc);
    void PrepareDC(wxDC& dc);
    void Scroll(int x, int y);
    void Scroll(const wxPoint& pt);
    void SetScrollRate(int xstep, int ystep);
    void SetScrollbars(int pixelsPerUnitX, int pixelsPerUnitY,
                       int noUnitsX,
                       int noUnitsY,
                       int xPos = 0,
                       int yPos = 0,
                       bool noRefresh = false);
    void SetTargetWindow(wxWindow *window);
    wxWindow *GetTargetWindow() const;
    void SetTargetRect(const wxRect& rect);
    wxRect GetTargetRect() const;
    int GetScrollPageSize(int orient) const;
    void SetScrollPageSize(int orient, int pageSize);
    int GetScrollLines( int orient ) const;
    void SetScale(double xs, double ys);
    double GetScaleX() const;
    double GetScaleY() const;
    virtual void AdjustScrollbars();
    bool IsAutoScrolling() const;
    void StopAutoScrolling();
    virtual bool SendAutoScrollEvents(wxScrollWinEvent& event) const;
protected:
    virtual wxSize GetSizeAvailableForScrollTarget(const wxSize& size);
};
WXGO_DECL_TYPECONV(ScrolledWindow)
class wxScrolledWindow: public wxPanel
{
public:
    wxScrolledWindow();
    wxScrolledWindow(wxWindow* parent, wxWindowID id,
               const wxPoint& pos = wxDefaultPosition,
               const wxSize& size = wxDefaultSize,
               long style = wxHSCROLL | wxVSCROLL,
               const wxString& name = "scrolledWindow");
    void CalcScrolledPosition(int x, int y, int* xx, int* yy) const;
    wxPoint CalcScrolledPosition(const wxPoint& pt) const;
    void CalcUnscrolledPosition(int x, int y, int* xx, int* yy) const;
    wxPoint CalcUnscrolledPosition(const wxPoint& pt) const;
    bool Create(wxWindow* parent, wxWindowID id,
                const wxPoint& pos = wxDefaultPosition,
                const wxSize& size = wxDefaultSize,
                long style = wxHSCROLL | wxVSCROLL,
                const wxString& name = "scrolledWindow");
    void DisableKeyboardScrolling();
    void DoPrepareDC(wxDC& dc);
    void EnableScrolling(bool xScrolling, bool yScrolling);
    void ShowScrollbars(wxScrollbarVisibility horz, wxScrollbarVisibility vert);
    void GetScrollPixelsPerUnit(int* xUnit, int* yUnit) const;
    void GetViewStart(int* x, int* y) const;
    wxPoint GetViewStart() const;
    void GetVirtualSize(int* x, int* y) const;
    bool IsRetained() const;
    virtual void OnDraw(wxDC& dc);
    void PrepareDC(wxDC& dc);
    void Scroll(int x, int y);
    void Scroll(const wxPoint& pt);
    void SetScrollRate(int xstep, int ystep);
    void SetScrollbars(int pixelsPerUnitX, int pixelsPerUnitY,
                       int noUnitsX,
                       int noUnitsY,
                       int xPos = 0,
                       int yPos = 0,
                       bool noRefresh = false);
    void SetTargetWindow(wxWindow *window);
    wxWindow *GetTargetWindow() const;
    void SetTargetRect(const wxRect& rect);
    wxRect GetTargetRect() const;
    int GetScrollPageSize(int orient) const;
    void SetScrollPageSize(int orient, int pageSize);
    int GetScrollLines( int orient ) const;
    void SetScale(double xs, double ys);
    double GetScaleX() const;
    double GetScaleY() const;
    virtual void AdjustScrollbars();
    bool IsAutoScrolling() const;
    void StopAutoScrolling();
    virtual bool SendAutoScrollEvents(wxScrollWinEvent& event) const;
protected:
    virtual wxSize GetSizeAvailableForScrollTarget(const wxSize& size);
};
WXGO_DECL_TYPECONV(ScrolledCanvas)
class wxScrolledCanvas: public wxWindow
{
public:
    wxScrolledCanvas();
    wxScrolledCanvas(wxWindow* parent, wxWindowID id = -1,
               const wxPoint& pos = wxDefaultPosition,
               const wxSize& size = wxDefaultSize,
               long style = wxHSCROLL | wxVSCROLL,
               const wxString& name = "scrolledWindow");
    void CalcScrolledPosition(int x, int y, int* xx, int* yy) const;
    wxPoint CalcScrolledPosition(const wxPoint& pt) const;
    void CalcUnscrolledPosition(int x, int y, int* xx, int* yy) const;
    wxPoint CalcUnscrolledPosition(const wxPoint& pt) const;
    bool Create(wxWindow* parent, wxWindowID id,
                const wxPoint& pos = wxDefaultPosition,
                const wxSize& size = wxDefaultSize,
                long style = wxHSCROLL | wxVSCROLL,
                const wxString& name = "scrolledWindow");
    void DisableKeyboardScrolling();
    void DoPrepareDC(wxDC& dc);
    void EnableScrolling(bool xScrolling, bool yScrolling);
    void ShowScrollbars(wxScrollbarVisibility horz, wxScrollbarVisibility vert);
    void GetScrollPixelsPerUnit(int* xUnit, int* yUnit) const;
    void GetViewStart(int* x, int* y) const;
    wxPoint GetViewStart() const;
    void GetVirtualSize(int* x, int* y) const;
    bool IsRetained() const;
    virtual void OnDraw(wxDC& dc);
    void PrepareDC(wxDC& dc);
    void Scroll(int x, int y);
    void Scroll(const wxPoint& pt);
    void SetScrollRate(int xstep, int ystep);
    void SetScrollbars(int pixelsPerUnitX, int pixelsPerUnitY,
                       int noUnitsX,
                       int noUnitsY,
                       int xPos = 0,
                       int yPos = 0,
                       bool noRefresh = false);
    void SetTargetWindow(wxWindow *window);
    wxWindow *GetTargetWindow() const;
    void SetTargetRect(const wxRect& rect);
    wxRect GetTargetRect() const;
    int GetScrollPageSize(int orient) const;
    void SetScrollPageSize(int orient, int pageSize);
    int GetScrollLines( int orient ) const;
    void SetScale(double xs, double ys);
    double GetScaleX() const;
    double GetScaleY() const;
    virtual void AdjustScrollbars();
    bool IsAutoScrolling() const;
    void StopAutoScrolling();
    virtual bool SendAutoScrollEvents(wxScrollWinEvent& event) const;
protected:
    virtual wxSize GetSizeAvailableForScrollTarget(const wxSize& size);
};