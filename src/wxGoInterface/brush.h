WXGO_DECL_TYPECONV(Brush)
WXGO_DECL_TYPECONV(BrushList)
%ignore wxBrushStyle;
enum wxBrushStyle;
typedef int wxBrushStyle;
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
wxBrush wxNullBrush;
wxBrush* wxBLUE_BRUSH;
wxBrush* wxGREEN_BRUSH;
wxBrush* wxYELLOW_BRUSH;
wxBrush* wxWHITE_BRUSH;
wxBrush* wxBLACK_BRUSH;
wxBrush* wxGREY_BRUSH;
wxBrush* wxMEDIUM_GREY_BRUSH;
wxBrush* wxLIGHT_GREY_BRUSH;
wxBrush* wxTRANSPARENT_BRUSH;
wxBrush* wxCYAN_BRUSH;
wxBrush* wxRED_BRUSH;
class wxBrushList
{
public:
    wxBrush* FindOrCreateBrush(const wxColour& colour,
                               wxBrushStyle style = wxBRUSHSTYLE_SOLID);
};
wxBrushList* wxTheBrushList;