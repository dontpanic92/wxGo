%typedef int wxPenStyle;
#define wxPENSTYLE_INVALID  -1
#define wxPENSTYLE_SOLID wxPENSTYLE_INVALID  + 1
#define wxPENSTYLE_DOT wxPENSTYLE_SOLID + 1
#define wxPENSTYLE_LONG_DASH wxPENSTYLE_DOT + 1
#define wxPENSTYLE_SHORT_DASH wxPENSTYLE_LONG_DASH + 1
#define wxPENSTYLE_DOT_DASH wxPENSTYLE_SHORT_DASH + 1
#define wxPENSTYLE_USER_DASH wxPENSTYLE_DOT_DASH + 1
#define wxPENSTYLE_TRANSPARENT wxPENSTYLE_USER_DASH + 1
#define wxPENSTYLE_STIPPLE_MASK_OPAQUE wxPENSTYLE_TRANSPARENT + 1
#define wxPENSTYLE_STIPPLE_MASK wxPENSTYLE_STIPPLE_MASK_OPAQUE + 1
#define wxPENSTYLE_STIPPLE wxPENSTYLE_STIPPLE_MASK + 1
#define wxPENSTYLE_BDIAGONAL_HATCH wxPENSTYLE_STIPPLE + 1
#define wxPENSTYLE_CROSSDIAG_HATCH wxPENSTYLE_BDIAGONAL_HATCH + 1
#define wxPENSTYLE_FDIAGONAL_HATCH wxPENSTYLE_CROSSDIAG_HATCH + 1
#define wxPENSTYLE_CROSS_HATCH wxPENSTYLE_FDIAGONAL_HATCH + 1
#define wxPENSTYLE_HORIZONTAL_HATCH wxPENSTYLE_CROSS_HATCH + 1
#define wxPENSTYLE_VERTICAL_HATCH wxPENSTYLE_HORIZONTAL_HATCH + 1
#define wxPENSTYLE_FIRST_HATCH wxPENSTYLE_VERTICAL_HATCH + 1
#define wxPENSTYLE_LAST_HATCH wxPENSTYLE_FIRST_HATCH + 1
%typedef int wxPenJoin;
#define wxJOIN_INVALID  -1
#define wxJOIN_BEVEL  120
#define wxJOIN_MITER wxJOIN_BEVEL  + 1
#define wxJOIN_ROUND wxJOIN_MITER + 1
%typedef int wxPenCap;
#define wxCAP_INVALID  -1
#define wxCAP_ROUND  130
#define wxCAP_PROJECTING wxCAP_ROUND  + 1
#define wxCAP_BUTT wxCAP_PROJECTING + 1
WXGO_DECL_TYPECONV(Pen)
class wxPen : public wxGDIObject
{
public:
    wxPen();
    wxPen(const wxColour& colour, int width = 1, wxPenStyle style = wxPENSTYLE_SOLID);
#if defined(__WXMSW__) && defined(__WXOSX__)
    wxPen(const wxBitmap& stipple, int width);
#endif
    wxPen(const wxPen& pen);
    virtual ~wxPen();
    virtual wxPenCap GetCap() const;
    virtual wxColour GetColour() const;
    virtual int GetDashes(wxDash** dashes) const;
    virtual wxPenJoin GetJoin() const;
    virtual wxBitmap* GetStipple() const;
    virtual wxPenStyle GetStyle() const;
    virtual int GetWidth() const;
    virtual bool IsOk() const;
    bool IsNonTransparent() const;
    bool IsTransparent() const;
    virtual void SetCap(wxPenCap capStyle);
    virtual void SetColour(wxColour& colour);
    virtual void SetColour(unsigned char red, unsigned char green, unsigned char blue);
    virtual void SetDashes(int n, const wxDash* dash);
    virtual void SetJoin(wxPenJoin join_style);
    virtual void SetStipple(const wxBitmap& stipple);
    virtual void SetStyle(wxPenStyle style);
    virtual void SetWidth(int width);
    bool operator!=(const wxPen& pen) const;
    wxPen& operator=(const wxPen& pen);
    bool operator==(const wxPen& pen) const;
};
%constant wxPen wxNullPen;
wxPen* const wxRED_PEN;
wxPen* const wxBLUE_PEN;
wxPen* const wxCYAN_PEN;
wxPen* const wxGREEN_PEN;
wxPen* const wxYELLOW_PEN;
wxPen* const wxBLACK_PEN;
wxPen* const wxWHITE_PEN;
wxPen* const wxTRANSPARENT_PEN;
wxPen* const wxBLACK_DASHED_PEN;
wxPen* const wxGREY_PEN;
wxPen* const wxMEDIUM_GREY_PEN;
wxPen* const wxLIGHT_GREY_PEN;
WXGO_DECL_TYPECONV(PenList)
class wxPenList
{
public:
    wxPenList();
    wxPen* FindOrCreatePen(const wxColour& colour,
                           int width = 1,
                           wxPenStyle style = wxPENSTYLE_SOLID);
};
%constant wxPenList* wxThePenList;