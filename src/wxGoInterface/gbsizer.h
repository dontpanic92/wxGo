WXGO_DECL_TYPECONV(GBPosition)
class wxGBPosition
{
public:
    wxGBPosition();
    wxGBPosition(int row, int col);
    int GetCol() const;
    int GetRow() const;
    void SetCol(int col);
    void SetRow(int row);
    bool operator!=(const wxGBPosition& p) const;
    bool operator==(const wxGBPosition& p) const;
};
WXGO_DECL_TYPECONV(GridBagSizer)
class wxGridBagSizer : public wxFlexGridSizer
{
public:
    wxGridBagSizer(int vgap = 0, int hgap = 0);
    wxSizerItem* Add(wxWindow* window, const wxGBPosition& pos,
                     const wxGBSpan& span = wxDefaultSpan,
                     int flag = 0, int border = 0, wxObject* userData = NULL);
    wxSizerItem* Add(wxSizer* sizer, const wxGBPosition& pos,
                     const wxGBSpan& span = wxDefaultSpan,
                     int flag = 0, int border = 0, wxObject* userData = NULL);
    wxSizerItem* Add(wxGBSizerItem* item);
    wxSizerItem* Add(int width, int height, const wxGBPosition& pos,
                     const wxGBSpan& span = wxDefaultSpan,
                     int flag = 0, int border = 0, wxObject* userData = NULL);
    wxSize CalcMin();
    bool CheckForIntersection(wxGBSizerItem* item,
                              wxGBSizerItem* excludeItem = NULL);
    bool CheckForIntersection(const wxGBPosition& pos, const wxGBSpan& span,
                              wxGBSizerItem* excludeItem = NULL);
    wxGBSizerItem* FindItem(wxWindow* window);
    wxGBSizerItem* FindItem(wxSizer* sizer);
    wxGBSizerItem* FindItemAtPoint(const wxPoint& pt);
    wxGBSizerItem* FindItemAtPosition(const wxGBPosition& pos);
    wxGBSizerItem* FindItemWithData(const wxObject* userData);
    wxSize GetCellSize(int row, int col) const;
    wxSize GetEmptyCellSize() const;
    wxGBPosition GetItemPosition(wxWindow* window);
    wxGBPosition GetItemPosition(wxSizer* sizer);
    wxGBPosition GetItemPosition(size_t index);
    wxGBSpan GetItemSpan(wxWindow* window);
    wxGBSpan GetItemSpan(wxSizer* sizer);
    wxGBSpan GetItemSpan(size_t index);
    void RecalcSizes();
    void SetEmptyCellSize(const wxSize& sz);
    bool SetItemPosition(wxWindow* window, const wxGBPosition& pos);
    bool SetItemPosition(wxSizer* sizer, const wxGBPosition& pos);
    bool SetItemPosition(size_t index, const wxGBPosition& pos);
    bool SetItemSpan(wxWindow* window, const wxGBSpan& span);
    bool SetItemSpan(wxSizer* sizer, const wxGBSpan& span);
    bool SetItemSpan(size_t index, const wxGBSpan& span);
};
WXGO_DECL_TYPECONV(GBSizerItem)
class wxGBSizerItem : public wxSizerItem
{
public:
    wxGBSizerItem(int width, int height, const wxGBPosition& pos,
                  const wxGBSpan& span=wxDefaultSpan, int flag=0, int border=0,
                  wxObject* userData=NULL);
    wxGBSizerItem(wxWindow* window, const wxGBPosition& pos,
                  const wxGBSpan& span=wxDefaultSpan, int flag=0, int border=0,
                  wxObject* userData=NULL);
    wxGBSizerItem(wxSizer* sizer, const wxGBPosition& pos,
                  const wxGBSpan& span=wxDefaultSpan, int flag=0, int border=0,
                  wxObject* userData=NULL);
    void GetEndPos(int& row, int& col);
    wxGBPosition GetPos() const;
    void GetPos(int& row, int& col) const;
    wxGBSpan GetSpan() const;
    void GetSpan(int& rowspan, int& colspan) const;
    bool Intersects(const wxGBSizerItem& other);
    bool Intersects(const wxGBPosition& pos, const wxGBSpan& span);
    bool SetPos(const wxGBPosition& pos);
    bool SetSpan(const wxGBSpan& span);
    wxGridBagSizer* GetGBSizer() const;
    void SetGBSizer(wxGridBagSizer* sizer);
};
WXGO_DECL_TYPECONV(GBSpan)
class wxGBSpan
{
public:
    wxGBSpan();
    wxGBSpan(int rowspan, int colspan);
    int GetColspan() const;
    int GetRowspan() const;
    void SetColspan(int colspan);
    void SetRowspan(int rowspan);
    bool operator!=(const wxGBSpan& o) const;
    bool operator==(const wxGBSpan& o) const;
};
%constant wxGBSpan wxDefaultSpan;