WXGO_DECL_TYPECONV(Sizer)
class wxSizer : public wxObject
{
public:
    wxSizer();
    virtual ~wxSizer();
    wxSizerItem* Add(wxWindow* window, const wxSizerFlags& flags);
    wxSizerItem* Add(wxWindow* window,
                     int proportion = 0,
                     int flag = 0,
                     int border = 0,
                     wxObject* userData = NULL);
    wxSizerItem* Add(wxSizer* sizer, const wxSizerFlags& flags);
    wxSizerItem* Add(wxSizer* sizer,
                     int proportion = 0,
                     int flag = 0,
                     int border = 0,
                     wxObject* userData = NULL);
    wxSizerItem* Add(int width, int height,
                     int proportion = 0,
                     int flag = 0,
                     int border = 0,
                     wxObject* userData = NULL);
    wxSizerItem* Add( int width, int height, const wxSizerFlags& flags);
    wxSizerItem* Add(wxSizerItem* item);
    virtual wxSizerItem *AddSpacer(int size);
    wxSizerItem* AddStretchSpacer(int prop = 1);
    virtual wxSize CalcMin() = 0;
    virtual void Clear(bool delete_windows = false);
    wxSize ComputeFittingClientSize(wxWindow* window);
    wxSize ComputeFittingWindowSize(wxWindow* window);
    virtual bool Detach(wxWindow* window);
    virtual bool Detach(wxSizer* sizer);
    virtual bool Detach(int index);
    wxSize Fit(wxWindow* window);
    void FitInside(wxWindow* window);
    virtual bool InformFirstDirection(int direction, int size, int availableOtherDir);
    wxSizerItemList& GetChildren();
    wxWindow* GetContainingWindow() const;
    void SetContainingWindow(wxWindow *window);
    size_t GetItemCount() const;
    wxSizerItem* GetItem(wxWindow* window, bool recursive = false);
    wxSizerItem* GetItem(wxSizer* sizer, bool recursive = false);
    wxSizerItem* GetItem(size_t index);
    wxSizerItem* GetItemById(int id, bool recursive = false);
    wxSize GetMinSize();
    wxPoint GetPosition() const;
    wxSize GetSize() const;
    bool Hide(wxWindow* window, bool recursive = false);
    bool Hide(wxSizer* sizer, bool recursive = false);
    bool Hide(size_t index);
    wxSizerItem* Insert(size_t index, wxWindow* window,
                        const wxSizerFlags& flags);
    wxSizerItem* Insert(size_t index, wxWindow* window,
                        int proportion = 0,
                        int flag = 0,
                        int border = 0,
                        wxObject* userData = NULL);
    wxSizerItem* Insert(size_t index, wxSizer* sizer,
                        const wxSizerFlags& flags);
    wxSizerItem* Insert(size_t index, wxSizer* sizer,
                        int proportion = 0,
                        int flag = 0,
                        int border = 0,
                        wxObject* userData = NULL);
    wxSizerItem* Insert(size_t index, int width, int height,
                        int proportion = 0,
                        int flag = 0,
                        int border = 0,
                        wxObject* userData = NULL);
    wxSizerItem* Insert(size_t index,
                        int width,
                        int height,
                        const wxSizerFlags& flags);
    wxSizerItem* Insert(size_t index, wxSizerItem* item);
    wxSizerItem* InsertSpacer(size_t index, int size);
    wxSizerItem* InsertStretchSpacer(size_t index, int prop = 1);
    bool IsEmpty() const;
    bool IsShown(wxWindow* window) const;
    bool IsShown(wxSizer* sizer) const;
    bool IsShown(size_t index) const;
    virtual void Layout();
    wxSizerItem* Prepend(wxWindow* window, const wxSizerFlags& flags);
    wxSizerItem* Prepend(wxWindow* window, int proportion = 0,
                         int flag = 0,
                         int border = 0,
                         wxObject* userData = NULL);
    wxSizerItem* Prepend(wxSizer* sizer,
                         const wxSizerFlags& flags);
    wxSizerItem* Prepend(wxSizer* sizer, int proportion = 0,
                         int flag = 0,
                         int border = 0,
                         wxObject* userData = NULL);
    wxSizerItem* Prepend(int width, int height,
                         int proportion = 0,
                         int flag = 0,
                         int border = 0,
                         wxObject* userData = NULL);
    wxSizerItem* Prepend(int width, int height, const wxSizerFlags& flags);
    wxSizerItem* Prepend(wxSizerItem* item);
    wxSizerItem* PrependSpacer(int size);
    wxSizerItem* PrependStretchSpacer(int prop = 1);
    virtual void RecalcSizes() = 0;
    virtual bool Remove(wxSizer* sizer);
    virtual bool Remove(int index);
    virtual bool Replace(wxWindow* oldwin, wxWindow* newwin,
                         bool recursive = false);
    virtual bool Replace(wxSizer* oldsz, wxSizer* newsz,
                         bool recursive = false);
    virtual bool Replace(size_t index, wxSizerItem* newitem);
    void SetDimension(int x, int y, int width, int height);
    void SetDimension(const wxPoint& pos, const wxSize& size);
    bool SetItemMinSize(wxWindow* window, int width, int height);
    bool SetItemMinSize(wxWindow* window, const wxSize& size);
    bool SetItemMinSize(wxSizer* sizer, int width, int height);
    bool SetItemMinSize(wxSizer* sizer, const wxSize& size);
    bool SetItemMinSize(size_t index, int width, int height);
    bool SetItemMinSize(size_t index, const wxSize& size);
    void SetMinSize(const wxSize& size);
    void SetMinSize(int width, int height);
    void SetSizeHints(wxWindow* window);
    bool Show(wxWindow* window, bool show = true,
              bool recursive = false);
    bool Show(wxSizer* sizer, bool show = true,
              bool recursive = false);
    bool Show(size_t index, bool show = true);
    virtual void ShowItems(bool show);
};
WXGO_DECL_TYPECONV(BoxSizer)
class wxBoxSizer : public wxSizer
{
public:
    wxBoxSizer(int orient);
    virtual wxSizerItem *AddSpacer(int size);
    virtual wxSize CalcMin();
    int GetOrientation() const;
    void SetOrientation(int orient);
    virtual void RecalcSizes();
};
WXGO_DECL_TYPECONV(StdDialogButtonSizer)
class wxStdDialogButtonSizer : public wxBoxSizer
{
public:
    wxStdDialogButtonSizer();
    void AddButton(wxButton* button);
    void Realize();
    void SetAffirmativeButton(wxButton* button);
    void SetCancelButton(wxButton* button);
    void SetNegativeButton(wxButton* button);
    virtual void RecalcSizes();
    virtual wxSize CalcMin();
};
WXGO_DECL_TYPECONV(SizerItem)
class wxSizerItem : public wxObject
{
public:
    wxSizerItem(int width, int height, int proportion=0, int flag=0,
                int border=0, wxObject* userData=NULL);
    wxSizerItem(wxWindow* window, const wxSizerFlags& flags);
    wxSizerItem(wxWindow* window, int proportion=0, int flag=0,
                int border=0,
                wxObject* userData=NULL);
    wxSizerItem(wxSizer* sizer, const wxSizerFlags& flags);
    wxSizerItem(wxSizer* sizer, int proportion=0, int flag=0,
                int border=0,
                wxObject* userData=NULL);
    virtual ~wxSizerItem();
    void AssignWindow(wxWindow *window);
    void AssignSizer(wxSizer *sizer);
    void AssignSpacer(const wxSize& size);
    void AssignSpacer(int w, int h);
    virtual wxSize CalcMin();
    virtual void DeleteWindows();
    void DetachSizer();
    int GetBorder() const;
    int GetFlag() const;
    int GetId() const;
    wxSize GetMinSize() const;
    void SetMinSize(const wxSize& size);
    void SetMinSize(int x, int y);
    wxPoint GetPosition() const;
    int GetProportion() const;
    float GetRatio() const;
    virtual wxRect GetRect();
    virtual wxSize GetSize() const;
    wxSizer* GetSizer() const;
    wxSize GetSpacer() const;
    wxObject* GetUserData() const;
    wxWindow* GetWindow() const;
    bool IsShown() const;
    bool IsSizer() const;
    bool IsSpacer() const;
    bool IsWindow() const;
    void SetBorder(int border);
    virtual void SetDimension(const wxPoint& pos, const wxSize& size);
    void SetFlag(int flag);
    void SetId(int id);
    void SetInitSize(int x, int y);
    void SetProportion(int proportion);
    void SetRatio(int width, int height);
    void SetRatio(wxSize size);
    void SetRatio(float ratio);
    void SetUserData(wxObject* userData);
    void Show(bool show);
};
WXGO_DECL_TYPECONV(SizerFlags)
class wxSizerFlags
{
public:
    wxSizerFlags(int proportion = 0);
    wxSizerFlags& Align(int alignment);
    wxSizerFlags& Border(int direction, int borderinpixels);
    wxSizerFlags& Border(int direction = wxALL);
    wxSizerFlags& Bottom();
    wxSizerFlags& Center();
    wxSizerFlags& Centre();
    wxSizerFlags& DoubleBorder(int direction = wxALL);
    wxSizerFlags& DoubleHorzBorder();
    wxSizerFlags& Expand();
    wxSizerFlags& FixedMinSize();
    wxSizerFlags& ReserveSpaceEvenIfHidden();
    static int GetDefaultBorder();
    wxSizerFlags& Left();
    wxSizerFlags& Proportion(int proportion);
    wxSizerFlags& Right();
    wxSizerFlags& Shaped();
    wxSizerFlags& Top();
    wxSizerFlags& TripleBorder(int direction = wxALL);
};
%typedef int wxFlexSizerGrowMode;
#define wxFLEX_GROWMODE_NONE 0
#define wxFLEX_GROWMODE_SPECIFIED wxFLEX_GROWMODE_NONE + 1
#define wxFLEX_GROWMODE_ALL wxFLEX_GROWMODE_SPECIFIED + 1
WXGO_DECL_TYPECONV(GridSizer)
class wxGridSizer : public wxSizer
{
public:
    wxGridSizer( int cols, int vgap, int hgap );
    wxGridSizer( int cols, const wxSize& gap = wxSize(0, 0) );
    wxGridSizer( int rows, int cols, int vgap, int hgap );
    wxGridSizer( int rows, int cols, const wxSize& gap );
    int GetCols() const;
    int GetRows() const;
    int GetEffectiveColsCount() const;
    int GetEffectiveRowsCount() const;
    int GetHGap() const;
    int GetVGap() const;
    void SetCols(int cols);
    void SetHGap(int gap);
    void SetRows(int rows);
    void SetVGap(int gap);
    virtual wxSize CalcMin();
    virtual void RecalcSizes();
};
WXGO_DECL_TYPECONV(FlexGridSizer)
class wxFlexGridSizer : public wxGridSizer
{
public:
    wxFlexGridSizer( int cols, int vgap, int hgap );
    wxFlexGridSizer( int cols, const wxSize& gap = wxSize(0, 0) );
    wxFlexGridSizer( int rows, int cols, int vgap, int hgap );
    wxFlexGridSizer( int rows, int cols, const wxSize& gap );
    void AddGrowableCol(size_t idx, int proportion = 0);
    void AddGrowableRow(size_t idx, int proportion = 0);
    int GetFlexibleDirection() const;
    wxFlexSizerGrowMode GetNonFlexibleGrowMode() const;
    bool IsColGrowable(size_t idx);
    bool IsRowGrowable(size_t idx);
    void RemoveGrowableCol(size_t idx);
    void RemoveGrowableRow(size_t idx);
    void SetFlexibleDirection(int direction);
    void SetNonFlexibleGrowMode(wxFlexSizerGrowMode mode);
    virtual void RecalcSizes();
    virtual wxSize CalcMin();
};
WXGO_DECL_TYPECONV(StaticBoxSizer)
class wxStaticBoxSizer : public wxBoxSizer
{
public:
    wxStaticBoxSizer(wxStaticBox* box, int orient);
    wxStaticBoxSizer(int orient, wxWindow *parent,
                     const wxString& label = wxEmptyString);
    wxStaticBox* GetStaticBox() const;
    virtual wxSize CalcMin();
    virtual void RecalcSizes();
};