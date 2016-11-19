%typedef int wxBrushStyle;
#define wxBRUSHSTYLE_INVALID  -1
#define wxBRUSHSTYLE_SOLID  wxSOLID
#define wxBRUSHSTYLE_TRANSPARENT  wxTRANSPARENT
#define wxBRUSHSTYLE_STIPPLE_MASK_OPAQUE  wxSTIPPLE_MASK_OPAQUE
#define wxBRUSHSTYLE_STIPPLE_MASK  wxSTIPPLE_MASK
#define wxBRUSHSTYLE_STIPPLE  wxSTIPPLE
#define wxBRUSHSTYLE_BDIAGONAL_HATCH wxBRUSHSTYLE_STIPPLE  + 1
#define wxBRUSHSTYLE_CROSSDIAG_HATCH wxBRUSHSTYLE_BDIAGONAL_HATCH + 1
#define wxBRUSHSTYLE_FDIAGONAL_HATCH wxBRUSHSTYLE_CROSSDIAG_HATCH + 1
#define wxBRUSHSTYLE_CROSS_HATCH wxBRUSHSTYLE_FDIAGONAL_HATCH + 1
#define wxBRUSHSTYLE_HORIZONTAL_HATCH wxBRUSHSTYLE_CROSS_HATCH + 1
#define wxBRUSHSTYLE_VERTICAL_HATCH wxBRUSHSTYLE_HORIZONTAL_HATCH + 1
#define wxBRUSHSTYLE_FIRST_HATCH wxBRUSHSTYLE_VERTICAL_HATCH + 1
#define wxBRUSHSTYLE_LAST_HATCH wxBRUSHSTYLE_FIRST_HATCH + 1
WXGO_DECL_TYPECONV(Brush)
class wxBrush : public wxGDIObject
{
public:
    wxBrush();
    wxBrush(const wxColour& colour, wxBrushStyle style = wxBRUSHSTYLE_SOLID);
    wxBrush(const wxBitmap& stippleBitmap);
    wxBrush(const wxBrush& brush);
    virtual ~wxBrush();
    virtual wxColour GetColour() const;
    virtual wxBitmap* GetStipple() const;
    virtual wxBrushStyle GetStyle() const;
    virtual bool IsHatch() const;
    virtual bool IsOk() const;
    bool IsNonTransparent() const;
    bool IsTransparent() const;
    virtual void SetColour(const wxColour& colour);
    virtual void SetColour(unsigned char red, unsigned char green, unsigned char blue);
    virtual void SetStipple(const wxBitmap& bitmap);
    virtual void SetStyle(wxBrushStyle style);
    bool operator !=(const wxBrush& brush) const;
    bool operator ==(const wxBrush& brush) const;
};
%constant wxBrush wxNullBrush;
wxBrush* const wxBLUE_BRUSH;
wxBrush* const wxGREEN_BRUSH;
wxBrush* const wxYELLOW_BRUSH;
wxBrush* const wxWHITE_BRUSH;
wxBrush* const wxBLACK_BRUSH;
wxBrush* const wxGREY_BRUSH;
wxBrush* const wxMEDIUM_GREY_BRUSH;
wxBrush* const wxLIGHT_GREY_BRUSH;
wxBrush* const wxTRANSPARENT_BRUSH;
wxBrush* const wxCYAN_BRUSH;
wxBrush* const wxRED_BRUSH;
WXGO_DECL_TYPECONV(BrushList)
class wxBrushList
{
public:
    wxBrush* FindOrCreateBrush(const wxColour& colour,
                               wxBrushStyle style = wxBRUSHSTYLE_SOLID);
};
%constant wxBrushList* wxTheBrushList;