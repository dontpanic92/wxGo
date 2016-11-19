extern const wxChar wxRichTextLineBreakChar;
typedef int wxDataObjectBase::Direction;
%typedef int wxRichTextFileType;
#define wxRICHTEXT_TYPE_ANY  0
#define wxRICHTEXT_TYPE_TEXT wxRICHTEXT_TYPE_ANY  + 1
#define wxRICHTEXT_TYPE_XML wxRICHTEXT_TYPE_TEXT + 1
#define wxRICHTEXT_TYPE_HTML wxRICHTEXT_TYPE_XML + 1
#define wxRICHTEXT_TYPE_RTF wxRICHTEXT_TYPE_HTML + 1
#define wxRICHTEXT_TYPE_PDF wxRICHTEXT_TYPE_RTF + 1
#define wxRICHTEXT_FIXED_WIDTH      0x01
#define wxRICHTEXT_FIXED_HEIGHT     0x02
#define wxRICHTEXT_VARIABLE_WIDTH   0x04
#define wxRICHTEXT_VARIABLE_HEIGHT  0x08
#define wxRICHTEXT_LAYOUT_SPECIFIED_RECT 0x10
#define wxRICHTEXT_DRAW_IGNORE_CACHE    0x01
#define wxRICHTEXT_DRAW_SELECTED        0x02
#define wxRICHTEXT_DRAW_PRINT           0x04
#define wxRICHTEXT_DRAW_GUIDELINES      0x08
%typedef int wxRichTextHitTestFlags;
#define wxRICHTEXT_HITTEST_NONE  0x01
#define wxRICHTEXT_HITTEST_BEFORE  0x02
#define wxRICHTEXT_HITTEST_AFTER  0x04
#define wxRICHTEXT_HITTEST_ON  0x08
#define wxRICHTEXT_HITTEST_OUTSIDE  0x10
#define wxRICHTEXT_HITTEST_NO_NESTED_OBJECTS  0x20
#define wxRICHTEXT_HITTEST_NO_FLOATING_OBJECTS  0x40
#define wxRICHTEXT_HITTEST_HONOUR_ATOMIC  0x80
#define wxRICHTEXT_FORMATTED        0x01
#define wxRICHTEXT_UNFORMATTED      0x02
#define wxRICHTEXT_CACHE_SIZE       0x04
#define wxRICHTEXT_HEIGHT_ONLY      0x08
#define wxRICHTEXT_SETSTYLE_NONE            0x00
#define wxRICHTEXT_SETSTYLE_WITH_UNDO       0x01
#define wxRICHTEXT_SETSTYLE_OPTIMIZE        0x02
#define wxRICHTEXT_SETSTYLE_PARAGRAPHS_ONLY 0x04
#define wxRICHTEXT_SETSTYLE_CHARACTERS_ONLY 0x08
#define wxRICHTEXT_SETSTYLE_RENUMBER        0x10
#define wxRICHTEXT_SETSTYLE_SPECIFY_LEVEL   0x20
#define wxRICHTEXT_SETSTYLE_RESET           0x40
#define wxRICHTEXT_SETSTYLE_REMOVE          0x80
#define wxRICHTEXT_SETPROPERTIES_NONE            0x00
#define wxRICHTEXT_SETPROPERTIES_WITH_UNDO       0x01
#define wxRICHTEXT_SETPROPERTIES_PARAGRAPHS_ONLY 0x02
#define wxRICHTEXT_SETPROPERTIES_CHARACTERS_ONLY 0x04
#define wxRICHTEXT_SETPROPERTIES_RESET           0x08
#define wxRICHTEXT_SETPROPERTIES_REMOVE          0x10
#define wxRICHTEXT_INSERT_NONE                              0x00
#define wxRICHTEXT_INSERT_WITH_PREVIOUS_PARAGRAPH_STYLE     0x01
#define wxRICHTEXT_INSERT_INTERACTIVE                       0x02
#define wxTEXT_ATTR_KEEP_FIRST_PARA_STYLE   0x10000000
#define wxSCRIPT_MUL_FACTOR             1.5
typedef unsigned short wxTextAttrDimensionFlags;
%typedef int wxTextBoxAttrFlags;
#define wxTEXT_BOX_ATTR_FLOAT                    0x00000001
#define wxTEXT_BOX_ATTR_CLEAR                    0x00000002
#define wxTEXT_BOX_ATTR_COLLAPSE_BORDERS         0x00000004
#define wxTEXT_BOX_ATTR_VERTICAL_ALIGNMENT       0x00000008
#define wxTEXT_BOX_ATTR_BOX_STYLE_NAME           0x00000010
#define wxTEXT_BOX_ATTR_WHITESPACE               0x00000020
#define wxTEXT_BOX_ATTR_CORNER_RADIUS            0x00000040
%typedef int wxTextAttrValueFlags;
#define wxTEXT_ATTR_VALUE_VALID                0x1000
#define wxTEXT_ATTR_VALUE_VALID_MASK           0x1000
%typedef int wxTextAttrUnits;
#define wxTEXT_ATTR_UNITS_TENTHS_MM              0x0001
#define wxTEXT_ATTR_UNITS_PIXELS                 0x0002
#define wxTEXT_ATTR_UNITS_PERCENTAGE             0x0004
#define wxTEXT_ATTR_UNITS_POINTS                 0x0008
#define wxTEXT_ATTR_UNITS_HUNDREDTHS_POINT       0x0100
#define wxTEXT_ATTR_UNITS_MASK                   0x010F
%typedef int wxTextBoxAttrPosition;
#define wxTEXT_BOX_ATTR_POSITION_STATIC          0x0000
#define wxTEXT_BOX_ATTR_POSITION_RELATIVE        0x0010
#define wxTEXT_BOX_ATTR_POSITION_ABSOLUTE        0x0020
#define wxTEXT_BOX_ATTR_POSITION_FIXED           0x0040
#define wxTEXT_BOX_ATTR_POSITION_MASK            0x00F0
WXGO_DECL_TYPECONV(TextAttrDimension)
class wxTextAttrDimension
{
public:
    wxTextAttrDimension() { Reset(); }
    wxTextAttrDimension(int value, wxTextAttrUnits units = wxTEXT_ATTR_UNITS_TENTHS_MM) { m_value = value; m_flags = units|wxTEXT_ATTR_VALUE_VALID; }
    void Reset() { m_value = 0; m_flags = 0; }
    bool EqPartial(const wxTextAttrDimension& dim, bool weakTest = true) const;
    bool Apply(const wxTextAttrDimension& dim, const wxTextAttrDimension* compareWith = NULL);
    void CollectCommonAttributes(const wxTextAttrDimension& attr, wxTextAttrDimension& clashingAttr, wxTextAttrDimension& absentAttr);
    bool operator==(const wxTextAttrDimension& dim) const { return m_value == dim.m_value && m_flags == dim.m_flags; }
    int GetValue() const { return m_value; }
    float GetValueMM() const { return float(m_value) / 10.0; }
    void SetValueMM(float value) { m_value = (int) ((value * 10.0) + 0.5); m_flags |= wxTEXT_ATTR_VALUE_VALID; }
    void SetValue(int value) { m_value = value; m_flags |= wxTEXT_ATTR_VALUE_VALID; }
    void SetValue(int value, wxTextAttrDimensionFlags flags) { SetValue(value); m_flags = flags; }
    void SetValue(int value, wxTextAttrUnits units) { m_value = value; m_flags = units | wxTEXT_ATTR_VALUE_VALID; }
    void SetValue(const wxTextAttrDimension& dim) { (*this) = dim; }
    wxTextAttrUnits GetUnits() const { return (wxTextAttrUnits) (m_flags & wxTEXT_ATTR_UNITS_MASK); }
    void SetUnits(wxTextAttrUnits units) { m_flags &= ~wxTEXT_ATTR_UNITS_MASK; m_flags |= units; }
    wxTextBoxAttrPosition GetPosition() const { return (wxTextBoxAttrPosition) (m_flags & wxTEXT_BOX_ATTR_POSITION_MASK); }
    void SetPosition(wxTextBoxAttrPosition pos) { m_flags &= ~wxTEXT_BOX_ATTR_POSITION_MASK; m_flags |= pos; }
    bool IsValid() const { return (m_flags & wxTEXT_ATTR_VALUE_VALID) != 0; }
    void SetValid(bool b) { m_flags &= ~wxTEXT_ATTR_VALUE_VALID_MASK; m_flags |= (b ? wxTEXT_ATTR_VALUE_VALID : 0); }
    wxTextAttrDimensionFlags GetFlags() const { return m_flags; }
    void SetFlags(wxTextAttrDimensionFlags flags) { m_flags = flags; }
    int                         m_value;
    wxTextAttrDimensionFlags    m_flags;
};
WXGO_DECL_TYPECONV(TextAttrDimensions)
class wxTextAttrDimensions
{
public:
    wxTextAttrDimensions() {}
    void Reset() { m_left.Reset(); m_top.Reset(); m_right.Reset(); m_bottom.Reset(); }
    bool operator==(const wxTextAttrDimensions& dims) const { return m_left == dims.m_left && m_top == dims.m_top && m_right == dims.m_right && m_bottom == dims.m_bottom; }
    bool EqPartial(const wxTextAttrDimensions& dims, bool weakTest = true) const;
    bool Apply(const wxTextAttrDimensions& dims, const wxTextAttrDimensions* compareWith = NULL);
    void CollectCommonAttributes(const wxTextAttrDimensions& attr, wxTextAttrDimensions& clashingAttr, wxTextAttrDimensions& absentAttr);
    bool RemoveStyle(const wxTextAttrDimensions& attr);
    wxTextAttrDimension& GetLeft() { return m_left; }
    wxTextAttrDimension& GetRight() { return m_right; }
    wxTextAttrDimension& GetTop() { return m_top; }
    wxTextAttrDimension& GetBottom() { return m_bottom; }
    bool IsValid() const { return m_left.IsValid() && m_top.IsValid() && m_right.IsValid() && m_bottom.IsValid(); }
    wxTextAttrDimension         m_left;
    wxTextAttrDimension         m_top;
    wxTextAttrDimension         m_right;
    wxTextAttrDimension         m_bottom;
};
WXGO_DECL_TYPECONV(TextAttrSize)
class wxTextAttrSize
{
public:
    wxTextAttrSize() {}
    void Reset() { m_width.Reset(); m_height.Reset(); }
    bool operator==(const wxTextAttrSize& size) const { return m_width == size.m_width && m_height == size.m_height ; }
    bool EqPartial(const wxTextAttrSize& size, bool weakTest = true) const;
    bool Apply(const wxTextAttrSize& dims, const wxTextAttrSize* compareWith = NULL);
    void CollectCommonAttributes(const wxTextAttrSize& attr, wxTextAttrSize& clashingAttr, wxTextAttrSize& absentAttr);
    bool RemoveStyle(const wxTextAttrSize& attr);
    wxTextAttrDimension& GetWidth() { return m_width; }
    void SetWidth(int value, wxTextAttrDimensionFlags flags) { m_width.SetValue(value, flags); }
    void SetWidth(int value, wxTextAttrUnits units) { m_width.SetValue(value, units); }
    void SetWidth(const wxTextAttrDimension& dim) { m_width.SetValue(dim); }
    wxTextAttrDimension& GetHeight() { return m_height; }
    void SetHeight(int value, wxTextAttrDimensionFlags flags) { m_height.SetValue(value, flags); }
    void SetHeight(int value, wxTextAttrUnits units) { m_height.SetValue(value, units); }
    void SetHeight(const wxTextAttrDimension& dim) { m_height.SetValue(dim); }
    bool IsValid() const { return m_width.IsValid() && m_height.IsValid(); }
    wxTextAttrDimension         m_width;
    wxTextAttrDimension         m_height;
};
WXGO_DECL_TYPECONV(TextAttrDimensionConverter)
class wxTextAttrDimensionConverter
{
public:
    wxTextAttrDimensionConverter(wxDC& dc, double scale = 1.0, const wxSize& parentSize = wxDefaultSize);
    wxTextAttrDimensionConverter(int ppi, double scale = 1.0, const wxSize& parentSize = wxDefaultSize);
    int GetPixels(const wxTextAttrDimension& dim, int direction = wxHORIZONTAL) const;
    int GetTenthsMM(const wxTextAttrDimension& dim) const;
    int ConvertTenthsMMToPixels(int units) const;
    int ConvertPixelsToTenthsMM(int pixels) const;
    int     m_ppi;
    double  m_scale;
    wxSize  m_parentSize;
};
%typedef int wxTextAttrBorderStyle;
#define wxTEXT_BOX_ATTR_BORDER_NONE              0
#define wxTEXT_BOX_ATTR_BORDER_SOLID             1
#define wxTEXT_BOX_ATTR_BORDER_DOTTED            2
#define wxTEXT_BOX_ATTR_BORDER_DASHED            3
#define wxTEXT_BOX_ATTR_BORDER_DOUBLE            4
#define wxTEXT_BOX_ATTR_BORDER_GROOVE            5
#define wxTEXT_BOX_ATTR_BORDER_RIDGE             6
#define wxTEXT_BOX_ATTR_BORDER_INSET             7
#define wxTEXT_BOX_ATTR_BORDER_OUTSET            8
%typedef int wxTextAttrBorderFlags;
#define wxTEXT_BOX_ATTR_BORDER_STYLE             0x0001
#define wxTEXT_BOX_ATTR_BORDER_COLOUR            0x0002
%typedef int wxTextAttrBorderWidth;
#define wxTEXT_BOX_ATTR_BORDER_THIN              -1
#define wxTEXT_BOX_ATTR_BORDER_MEDIUM            -2
#define wxTEXT_BOX_ATTR_BORDER_THICK             -3
%typedef int wxTextBoxAttrFloatStyle;
#define wxTEXT_BOX_ATTR_FLOAT_NONE               0
#define wxTEXT_BOX_ATTR_FLOAT_LEFT               1
#define wxTEXT_BOX_ATTR_FLOAT_RIGHT              2
%typedef int wxTextBoxAttrClearStyle;
#define wxTEXT_BOX_ATTR_CLEAR_NONE               0
#define wxTEXT_BOX_ATTR_CLEAR_LEFT               1
#define wxTEXT_BOX_ATTR_CLEAR_RIGHT              2
#define wxTEXT_BOX_ATTR_CLEAR_BOTH               3
%typedef int wxTextBoxAttrCollapseMode;
#define wxTEXT_BOX_ATTR_COLLAPSE_NONE            0
#define wxTEXT_BOX_ATTR_COLLAPSE_FULL            1
%typedef int wxTextBoxAttrVerticalAlignment;
#define wxTEXT_BOX_ATTR_VERTICAL_ALIGNMENT_NONE  0
#define wxTEXT_BOX_ATTR_VERTICAL_ALIGNMENT_TOP   1
#define wxTEXT_BOX_ATTR_VERTICAL_ALIGNMENT_CENTRE  2
#define wxTEXT_BOX_ATTR_VERTICAL_ALIGNMENT_BOTTOM   3
%typedef int wxTextBoxAttrWhitespaceMode;
#define wxTEXT_BOX_ATTR_WHITESPACE_NONE                  0
#define wxTEXT_BOX_ATTR_WHITESPACE_NORMAL                1
#define wxTEXT_BOX_ATTR_WHITESPACE_NO_WRAP               2
#define wxTEXT_BOX_ATTR_WHITESPACE_PREFORMATTED          3
#define wxTEXT_BOX_ATTR_WHITESPACE_PREFORMATTED_LINE     4
#define wxTEXT_BOX_ATTR_WHITESPACE_PREFORMATTED_WRAP     5
WXGO_DECL_TYPECONV(TextAttrBorder)
class wxTextAttrBorder
{
public:
    wxTextAttrBorder() { Reset(); }
    bool operator==(const wxTextAttrBorder& border) const
    {
        return m_flags == border.m_flags && m_borderStyle == border.m_borderStyle &&
               m_borderColour == border.m_borderColour && m_borderWidth == border.m_borderWidth;
    }
    void Reset() { m_borderStyle = 0; m_borderColour = 0; m_flags = 0; m_borderWidth.Reset(); }
    bool EqPartial(const wxTextAttrBorder& border, bool weakTest = true) const;
    bool Apply(const wxTextAttrBorder& border, const wxTextAttrBorder* compareWith = NULL);
    bool RemoveStyle(const wxTextAttrBorder& attr);
    void CollectCommonAttributes(const wxTextAttrBorder& attr, wxTextAttrBorder& clashingAttr, wxTextAttrBorder& absentAttr);
    void SetStyle(int style) { m_borderStyle = style; m_flags |= wxTEXT_BOX_ATTR_BORDER_STYLE; }
    int GetStyle() const { return m_borderStyle; }
    void SetColour(unsigned long colour) { m_borderColour = colour; m_flags |= wxTEXT_BOX_ATTR_BORDER_COLOUR; }
    void SetColour(const wxColour& colour) { m_borderColour = colour.GetRGB(); m_flags |= wxTEXT_BOX_ATTR_BORDER_COLOUR; }
    unsigned long GetColourLong() const { return m_borderColour; }
    wxColour GetColour() const { return wxColour(m_borderColour); }
    wxTextAttrDimension& GetWidth() { return m_borderWidth; }
    void SetWidth(const wxTextAttrDimension& width) { m_borderWidth = width; }
    void SetWidth(int value, wxTextAttrUnits units = wxTEXT_ATTR_UNITS_TENTHS_MM) { SetWidth(wxTextAttrDimension(value, units)); }
    bool HasStyle() const { return (m_flags & wxTEXT_BOX_ATTR_BORDER_STYLE) != 0; }
    bool HasColour() const { return (m_flags & wxTEXT_BOX_ATTR_BORDER_COLOUR) != 0; }
    bool HasWidth() const { return m_borderWidth.IsValid(); }
    bool IsValid() const { return HasWidth(); }
    bool IsDefault() const { return (m_flags == 0); }
    void MakeValid() { m_borderWidth.SetValid(true); }
    int GetFlags() const { return m_flags; }
    void SetFlags(int flags) { m_flags = flags; }
    void AddFlag(int flag) { m_flags |= flag; }
    void RemoveFlag(int flag) { m_flags &= ~flag; }
    int                         m_borderStyle;
    unsigned long               m_borderColour;
    wxTextAttrDimension         m_borderWidth;
    int                         m_flags;
};
WXGO_DECL_TYPECONV(TextAttrBorders)
class wxTextAttrBorders
{
public:
    wxTextAttrBorders() { }
    bool operator==(const wxTextAttrBorders& borders) const
    {
        return m_left == borders.m_left && m_right == borders.m_right &&
               m_top == borders.m_top && m_bottom == borders.m_bottom;
    }
    void SetStyle(int style);
    void SetColour(unsigned long colour);
    void SetColour(const wxColour& colour);
    void SetWidth(const wxTextAttrDimension& width);
    void SetWidth(int value, wxTextAttrUnits units = wxTEXT_ATTR_UNITS_TENTHS_MM) { SetWidth(wxTextAttrDimension(value, units)); }
    void Reset() { m_left.Reset(); m_right.Reset(); m_top.Reset(); m_bottom.Reset(); }
    bool EqPartial(const wxTextAttrBorders& borders, bool weakTest = true) const;
    bool Apply(const wxTextAttrBorders& borders, const wxTextAttrBorders* compareWith = NULL);
    bool RemoveStyle(const wxTextAttrBorders& attr);
    void CollectCommonAttributes(const wxTextAttrBorders& attr, wxTextAttrBorders& clashingAttr, wxTextAttrBorders& absentAttr);
    bool IsValid() const { return m_left.IsValid() || m_right.IsValid() || m_top.IsValid() || m_bottom.IsValid(); }
    wxTextAttrBorder& GetRight() { return m_right; }
    wxTextAttrBorder& GetTop() { return m_top; }
    wxTextAttrBorder& GetBottom() { return m_bottom; }
    wxTextAttrBorder m_left, m_right, m_top, m_bottom;
};
WXGO_DECL_TYPECONV(TextAttrShadow)
class wxTextAttrShadow
{
public:
    wxTextAttrShadow() { Reset(); }
    bool operator==(const wxTextAttrShadow& shadow) const;
    void Reset();
    bool EqPartial(const wxTextAttrShadow& shadow, bool weakTest = true) const;
    bool Apply(const wxTextAttrShadow& shadow, const wxTextAttrShadow* compareWith = NULL);
    bool RemoveStyle(const wxTextAttrShadow& attr);
    void CollectCommonAttributes(const wxTextAttrShadow& attr, wxTextAttrShadow& clashingAttr, wxTextAttrShadow& absentAttr);
    void SetColour(unsigned long colour) { m_shadowColour = colour; m_flags |= wxTEXT_BOX_ATTR_BORDER_COLOUR; }
    void SetColour(const wxColour& colour) { m_shadowColour = colour.GetRGB(); m_flags |= wxTEXT_BOX_ATTR_BORDER_COLOUR; }
    unsigned long GetColourLong() const { return m_shadowColour; }
    wxColour GetColour() const { return wxColour(m_shadowColour); }
    bool HasColour() const { return (m_flags & wxTEXT_BOX_ATTR_BORDER_COLOUR) != 0; }
    wxTextAttrDimension& GetOffsetX() { return m_offsetX; }
    void SetOffsetX(const wxTextAttrDimension& offset) { m_offsetX = offset; }
    wxTextAttrDimension& GetOffsetY() { return m_offsetY; }
    void SetOffsetY(const wxTextAttrDimension& offset) { m_offsetY = offset; }
    wxTextAttrDimension& GetSpread() { return m_spread; }
    void SetSpread(const wxTextAttrDimension& spread) { m_spread = spread; }
    wxTextAttrDimension& GetBlurDistance() { return m_blurDistance; }
    void SetBlurDistance(const wxTextAttrDimension& blur) { m_blurDistance = blur; }
    wxTextAttrDimension& GetOpacity() { return m_opacity; }
    bool IsValid() const { return (m_flags & wxTEXT_ATTR_VALUE_VALID) != 0; }
    void SetValid(bool b) { m_flags &= ~wxTEXT_ATTR_VALUE_VALID_MASK; m_flags |= (b ? wxTEXT_ATTR_VALUE_VALID : 0); }
    int GetFlags() const { return m_flags; }
    void SetFlags(int flags) { m_flags = flags; }
    void AddFlag(int flag) { m_flags |= flag; }
    void RemoveFlag(int flag) { m_flags &= ~flag; }
    void SetOpacity(const wxTextAttrDimension& opacity) { m_opacity = opacity; }
    bool IsDefault() const { return !HasColour() && !m_offsetX.IsValid() && !m_offsetY.IsValid() && !m_spread.IsValid() && !m_blurDistance.IsValid() && !m_opacity.IsValid(); }
    int                         m_flags;
    unsigned long               m_shadowColour;
    wxTextAttrDimension         m_offsetX;
    wxTextAttrDimension         m_offsetY;
    wxTextAttrDimension         m_spread;
    wxTextAttrDimension         m_blurDistance;
    wxTextAttrDimension         m_opacity;
};
WXGO_DECL_TYPECONV(TextBoxAttr)
class wxTextBoxAttr
{
public:
    wxTextBoxAttr() { Init(); }
    wxTextBoxAttr(const wxTextBoxAttr& attr) { Init(); (*this) = attr; }
    void Init() { Reset(); }
    void Reset();
    bool operator== (const wxTextBoxAttr& attr) const;
    bool EqPartial(const wxTextBoxAttr& attr, bool weakTest = true) const;
    bool Apply(const wxTextBoxAttr& style, const wxTextBoxAttr* compareWith = NULL);
    void CollectCommonAttributes(const wxTextBoxAttr& attr, wxTextBoxAttr& clashingAttr, wxTextBoxAttr& absentAttr);
    bool RemoveStyle(const wxTextBoxAttr& attr);
    void SetFlags(int flags) { m_flags = flags; }
    int GetFlags() const { return m_flags; }
    bool HasFlag(wxTextBoxAttrFlags flag) const { return (m_flags & flag) != 0; }
    void RemoveFlag(wxTextBoxAttrFlags flag) { m_flags &= ~flag; }
    void AddFlag(wxTextBoxAttrFlags flag) { m_flags |= flag; }
    bool IsDefault() const;
    wxTextBoxAttrFloatStyle GetFloatMode() const { return m_floatMode; }
    void SetFloatMode(wxTextBoxAttrFloatStyle mode) { m_floatMode = mode; m_flags |= wxTEXT_BOX_ATTR_FLOAT; }
    bool HasFloatMode() const { return HasFlag(wxTEXT_BOX_ATTR_FLOAT); }
    bool IsFloating() const { return HasFloatMode() && GetFloatMode() != wxTEXT_BOX_ATTR_FLOAT_NONE; }
    wxTextBoxAttrClearStyle GetClearMode() const { return m_clearMode; }
    void SetClearMode(wxTextBoxAttrClearStyle mode) { m_clearMode = mode; m_flags |= wxTEXT_BOX_ATTR_CLEAR; }
    bool HasClearMode() const { return HasFlag(wxTEXT_BOX_ATTR_CLEAR); }
    wxTextBoxAttrCollapseMode GetCollapseBorders() const { return m_collapseMode; }
    void SetCollapseBorders(wxTextBoxAttrCollapseMode collapse) { m_collapseMode = collapse; m_flags |= wxTEXT_BOX_ATTR_COLLAPSE_BORDERS; }
    bool HasCollapseBorders() const { return HasFlag(wxTEXT_BOX_ATTR_COLLAPSE_BORDERS); }
    wxTextBoxAttrWhitespaceMode GetWhitespaceMode() const { return m_whitespaceMode; }
    void SetWhitespaceMode(wxTextBoxAttrWhitespaceMode whitespace) { m_whitespaceMode = whitespace; m_flags |= wxTEXT_BOX_ATTR_WHITESPACE; }
    bool HasWhitespaceMode() const { return HasFlag(wxTEXT_BOX_ATTR_WHITESPACE); }
    bool HasCornerRadius() const { return HasFlag(wxTEXT_BOX_ATTR_CORNER_RADIUS); }
    wxTextAttrDimension& GetCornerRadius() { return m_cornerRadius; }
    void SetCornerRadius(const wxTextAttrDimension& dim) { m_cornerRadius = dim; m_flags |= wxTEXT_BOX_ATTR_CORNER_RADIUS; }
    wxTextBoxAttrVerticalAlignment GetVerticalAlignment() const { return m_verticalAlignment; }
    void SetVerticalAlignment(wxTextBoxAttrVerticalAlignment verticalAlignment) { m_verticalAlignment = verticalAlignment; m_flags |= wxTEXT_BOX_ATTR_VERTICAL_ALIGNMENT; }
    bool HasVerticalAlignment() const { return HasFlag(wxTEXT_BOX_ATTR_VERTICAL_ALIGNMENT); }
    wxTextAttrDimensions& GetMargins() { return m_margins; }
    wxTextAttrDimension& GetLeftMargin() { return m_margins.m_left; }
    wxTextAttrDimension& GetRightMargin() { return m_margins.m_right; }
    wxTextAttrDimension& GetTopMargin() { return m_margins.m_top; }
    wxTextAttrDimension& GetBottomMargin() { return m_margins.m_bottom; }
    wxTextAttrDimensions& GetPosition() { return m_position; }
    wxTextAttrDimension& GetLeft() { return m_position.m_left; }
    wxTextAttrDimension& GetRight() { return m_position.m_right; }
    wxTextAttrDimension& GetTop() { return m_position.m_top; }
    wxTextAttrDimension& GetBottom() { return m_position.m_bottom; }
    wxTextAttrDimensions& GetPadding() { return m_padding; }
    wxTextAttrDimension& GetLeftPadding() { return m_padding.m_left; }
    wxTextAttrDimension& GetRightPadding() { return m_padding.m_right; }
    wxTextAttrDimension& GetTopPadding() { return m_padding.m_top; }
    wxTextAttrDimension& GetBottomPadding() { return m_padding.m_bottom; }
    wxTextAttrBorders& GetBorder() { return m_border; }
    wxTextAttrBorder& GetLeftBorder() { return m_border.m_left; }
    wxTextAttrBorder& GetTopBorder() { return m_border.m_top; }
    wxTextAttrBorder& GetRightBorder() { return m_border.m_right; }
    wxTextAttrBorder& GetBottomBorder() { return m_border.m_bottom; }
    wxTextAttrBorders& GetOutline() { return m_outline; }
    wxTextAttrBorder& GetLeftOutline() { return m_outline.m_left; }
    wxTextAttrBorder& GetTopOutline() { return m_outline.m_top; }
    wxTextAttrBorder& GetRightOutline() { return m_outline.m_right; }
    wxTextAttrBorder& GetBottomOutline() { return m_outline.m_bottom; }
    wxTextAttrSize& GetSize() { return m_size; }
    wxTextAttrSize& GetMinSize() { return m_minSize; }
    wxTextAttrSize& GetMaxSize() { return m_maxSize; }
    void SetSize(const wxTextAttrSize& sz) { m_size = sz; }
    void SetMinSize(const wxTextAttrSize& sz) { m_minSize = sz; }
    void SetMaxSize(const wxTextAttrSize& sz) { m_maxSize = sz; }
    wxTextAttrDimension& GetWidth() { return m_size.m_width; }
    wxTextAttrDimension& GetHeight() { return m_size.m_height; }
    const wxString& GetBoxStyleName() const { return m_boxStyleName; }
    void SetBoxStyleName(const wxString& name) { m_boxStyleName = name; AddFlag(wxTEXT_BOX_ATTR_BOX_STYLE_NAME); }
    bool HasBoxStyleName() const { return HasFlag(wxTEXT_BOX_ATTR_BOX_STYLE_NAME); }
    wxTextAttrShadow& GetShadow() { return m_shadow; }
public:
    int                             m_flags;
    wxTextAttrDimensions            m_margins;
    wxTextAttrDimensions            m_padding;
    wxTextAttrDimensions            m_position;
    wxTextAttrSize                  m_size;
    wxTextAttrSize                  m_minSize;
    wxTextAttrSize                  m_maxSize;
    wxTextAttrBorders               m_border;
    wxTextAttrBorders               m_outline;
    wxTextBoxAttrFloatStyle         m_floatMode;
    wxTextBoxAttrClearStyle         m_clearMode;
    wxTextBoxAttrCollapseMode       m_collapseMode;
    wxTextBoxAttrVerticalAlignment  m_verticalAlignment;
    wxTextBoxAttrWhitespaceMode     m_whitespaceMode;
    wxTextAttrDimension             m_cornerRadius;
    wxString                        m_boxStyleName;
    wxTextAttrShadow                m_shadow;
};
WXGO_DECL_TYPECONV(RichTextAttr)
class wxRichTextAttr: public wxTextAttr
{
public:
    wxRichTextAttr(const wxTextAttr& attr) { wxTextAttr::Copy(attr); }
    wxRichTextAttr(const wxRichTextAttr& attr): wxTextAttr() { Copy(attr); }
    wxRichTextAttr() {}
    void Copy(const wxRichTextAttr& attr);
    void operator=(const wxRichTextAttr& attr) { Copy(attr); }
    void operator=(const wxTextAttr& attr) { wxTextAttr::Copy(attr); }
    bool operator==(const wxRichTextAttr& attr) const;
    bool EqPartial(const wxRichTextAttr& attr, bool weakTest = true) const;
    bool Apply(const wxRichTextAttr& style, const wxRichTextAttr* compareWith = NULL);
    void CollectCommonAttributes(const wxRichTextAttr& attr, wxRichTextAttr& clashingAttr, wxRichTextAttr& absentAttr);
    bool RemoveStyle(const wxRichTextAttr& attr);
    wxTextBoxAttr& GetTextBoxAttr() { return m_textBoxAttr; }
    void SetTextBoxAttr(const wxTextBoxAttr& attr) { m_textBoxAttr = attr; }
    bool IsDefault() const { return (GetFlags() == 0) && m_textBoxAttr.IsDefault(); }
    wxTextBoxAttr    m_textBoxAttr;
};
class wxRichTextAttrArray;
class wxRichTextVariantArray;
WXGO_DECL_TYPECONV(RichTextProperties)
class wxRichTextProperties: public wxObject
{
public:
    wxRichTextProperties() {}
    wxRichTextProperties(const wxRichTextProperties& props): wxObject() { Copy(props); }
    void operator=(const wxRichTextProperties& props) { Copy(props); }
    bool operator==(const wxRichTextProperties& props) const;
    void Copy(const wxRichTextProperties& props) { m_properties = props.m_properties; }
    wxVariant& operator[](size_t idx) { return m_properties[idx]; }
    void Clear() { m_properties.Clear(); }
    wxRichTextVariantArray& GetProperties() { return m_properties; }
    void SetProperties(const wxRichTextVariantArray& props) { m_properties = props; }
    wxArrayString GetPropertyNames() const;
    size_t GetCount() const { return m_properties.GetCount(); }
    bool HasProperty(const wxString& name) const { return Find(name) != -1; }
    int Find(const wxString& name) const;
    bool Remove(const wxString& name);
    const wxVariant& GetProperty(const wxString& name) const;
    wxVariant* FindOrCreateProperty(const wxString& name);
    wxString GetPropertyString(const wxString& name) const;
    long GetPropertyLong(const wxString& name) const;
    bool GetPropertyBool(const wxString& name) const;
    double GetPropertyDouble(const wxString& name) const;
    void SetProperty(const wxVariant& variant);
    void SetProperty(const wxString& name, const wxVariant& variant);
    void SetProperty(const wxString& name, const wxString& value);
    void SetProperty(const wxString& name, const wxChar* value);
    void SetProperty(const wxString& name, long value);
    void SetProperty(const wxString& name, double value);
    void SetProperty(const wxString& name, bool value);
    void RemoveProperties(const wxRichTextProperties& properties);
    void MergeProperties(const wxRichTextProperties& properties);
protected:
    wxRichTextVariantArray  m_properties;
};
WXGO_DECL_TYPECONV(RichTextFontTable)
class wxRichTextFontTable: public wxObject
{
public:
    wxRichTextFontTable();
    wxRichTextFontTable(const wxRichTextFontTable& table);
    virtual ~wxRichTextFontTable();
    bool IsOk() const { return m_refData != NULL; }
    wxFont FindFont(const wxRichTextAttr& fontSpec);
    void Clear();
    void operator= (const wxRichTextFontTable& table);
    bool operator == (const wxRichTextFontTable& table) const;
    bool operator != (const wxRichTextFontTable& table) const { return !(*this == table); }
    void SetFontScale(double fontScale);
protected:
    double m_fontScale;
};
WXGO_DECL_TYPECONV(RichTextRange)
class wxRichTextRange
{
public:
    wxRichTextRange() { m_start = 0; m_end = 0; }
    wxRichTextRange(long start, long end) { m_start = start; m_end = end; }
    wxRichTextRange(const wxRichTextRange& range) { m_start = range.m_start; m_end = range.m_end; }
    ~wxRichTextRange() {}
    void operator =(const wxRichTextRange& range) { m_start = range.m_start; m_end = range.m_end; }
    bool operator ==(const wxRichTextRange& range) const { return (m_start == range.m_start && m_end == range.m_end); }
    bool operator !=(const wxRichTextRange& range) const { return (m_start != range.m_start || m_end != range.m_end); }
    wxRichTextRange operator -(const wxRichTextRange& range) const { return wxRichTextRange(m_start - range.m_start, m_end - range.m_end); }
    wxRichTextRange operator +(const wxRichTextRange& range) const { return wxRichTextRange(m_start + range.m_start, m_end + range.m_end); }
    void SetRange(long start, long end) { m_start = start; m_end = end; }
    void SetStart(long start) { m_start = start; }
    long GetStart() const { return m_start; }
    void SetEnd(long end) { m_end = end; }
    long GetEnd() const { return m_end; }
    bool IsOutside(const wxRichTextRange& range) const { return range.m_start > m_end || range.m_end < m_start; }
    bool IsWithin(const wxRichTextRange& range) const { return m_start >= range.m_start && m_end <= range.m_end; }
    bool Contains(long pos) const { return pos >= m_start && pos <= m_end ; }
    bool LimitTo(const wxRichTextRange& range) ;
    long GetLength() const { return m_end - m_start + 1; }
    void Swap() { long tmp = m_start; m_start = m_end; m_end = tmp; }
    wxRichTextRange ToInternal() const { return wxRichTextRange(m_start, m_end-1); }
    wxRichTextRange FromInternal() const { return wxRichTextRange(m_start, m_end+1); }
protected:
    long m_start;
    long m_end;
};
class wxRichTextRangeArray;
#define wxRICHTEXT_ALL  wxRichTextRange(-2, -2)
#define wxRICHTEXT_NONE  wxRichTextRange(-1, -1)
#define wxRICHTEXT_NO_SELECTION wxRichTextRange(-2, -2)
WXGO_DECL_TYPECONV(RichTextSelection)
class wxRichTextSelection
{
public:
    wxRichTextSelection(const wxRichTextSelection& sel) { Copy(sel); }
    wxRichTextSelection(const wxRichTextRange& range, wxRichTextParagraphLayoutBox* container) { m_ranges.Add(range); m_container = container; }
    wxRichTextSelection() { Reset(); }
    void Reset() { m_ranges.Clear(); m_container = NULL; }
    void Set(const wxRichTextRange& range, wxRichTextParagraphLayoutBox* container)
    { m_ranges.Clear(); m_ranges.Add(range); m_container = container; }
    void Add(const wxRichTextRange& range)
    { m_ranges.Add(range); }
    void Set(const wxRichTextRangeArray& ranges, wxRichTextParagraphLayoutBox* container)
    { m_ranges = ranges; m_container = container; }
    void Copy(const wxRichTextSelection& sel)
    { m_ranges = sel.m_ranges; m_container = sel.m_container; }
    void operator=(const wxRichTextSelection& sel) { Copy(sel); }
    bool operator==(const wxRichTextSelection& sel) const;
    wxRichTextRange operator[](size_t i) const { return GetRange(i); }
    wxRichTextRangeArray& GetRanges() { return m_ranges; }
    void SetRanges(const wxRichTextRangeArray& ranges) { m_ranges = ranges; }
    size_t GetCount() const { return m_ranges.GetCount(); }
    wxRichTextRange GetRange(size_t i) const { return m_ranges[i]; }
    wxRichTextRange GetRange() const { return (m_ranges.GetCount() > 0) ? (m_ranges[0]) : wxRICHTEXT_NO_SELECTION; }
    void SetRange(const wxRichTextRange& range) { m_ranges.Clear(); m_ranges.Add(range); }
    wxRichTextParagraphLayoutBox* GetContainer() const { return m_container; }
    void SetContainer(wxRichTextParagraphLayoutBox* container) { m_container = container; }
    bool IsValid() const { return m_ranges.GetCount() > 0 && GetContainer(); }
    wxRichTextRangeArray GetSelectionForObject(wxRichTextObject* obj) const;
    bool WithinSelection(long pos, wxRichTextObject* obj) const;
    bool WithinSelection(long pos) const { return WithinSelection(pos, m_ranges); }
    static bool WithinSelection(long pos, const wxRichTextRangeArray& ranges);
    static bool WithinSelection(const wxRichTextRange& range, const wxRichTextRangeArray& ranges);
    wxRichTextRangeArray            m_ranges;
    wxRichTextParagraphLayoutBox*   m_container;
};
WXGO_DECL_TYPECONV(RichTextDrawingContext)
class wxRichTextDrawingContext: public wxObject
{
public:
    wxRichTextDrawingContext(wxRichTextBuffer* buffer);
    void Init();
    bool HasVirtualAttributes(wxRichTextObject* obj) const;
    wxRichTextAttr GetVirtualAttributes(wxRichTextObject* obj) const;
    bool ApplyVirtualAttributes(wxRichTextAttr& attr, wxRichTextObject* obj) const;
    int GetVirtualSubobjectAttributesCount(wxRichTextObject* obj) const;
    int GetVirtualSubobjectAttributes(wxRichTextObject* obj, wxArrayInt& positions,
                                      wxRichTextAttrArray& attributes) const;
    bool HasVirtualText(const wxRichTextPlainText* obj) const;
    bool GetVirtualText(const wxRichTextPlainText* obj, wxString& text) const;
    void EnableVirtualAttributes(bool b);
    bool GetVirtualAttributesEnabled() const;
    void EnableImages(bool b) { m_enableImages = b; }
    bool GetImagesEnabled() const { return m_enableImages; }
    void SetLayingOut(bool b) { m_layingOut = b; }
    bool GetLayingOut() const { return m_layingOut; }
    void EnableDelayedImageLoading(bool b) { m_enableDelayedImageLoading = b; }
    bool GetDelayedImageLoading() const { return m_enableDelayedImageLoading; }
    wxRichTextBuffer*   m_buffer;
    bool                m_enableVirtualAttributes;
    bool                m_enableImages;
    bool                m_enableDelayedImageLoading;
    bool                m_layingOut;
};
WXGO_DECL_TYPECONV(RichTextObject)
class wxRichTextObject: public wxObject
{
public:
    wxRichTextObject(wxRichTextObject* parent = NULL);
    virtual ~wxRichTextObject();
    virtual bool Draw(wxDC& dc, wxRichTextDrawingContext& context, const wxRichTextRange& range,
                      const wxRichTextSelection& selection, const wxRect& rect, int descent, int style) = 0;
    virtual bool Layout(wxDC& dc, wxRichTextDrawingContext& context, const wxRect& rect,
                        const wxRect& parentRect, int style) = 0;
    virtual int HitTest(wxDC& dc, wxRichTextDrawingContext& context, const wxPoint& pt,
                        long& textPosition, wxRichTextObject** obj, wxRichTextObject** contextObj,
                        int flags = 0);
    virtual bool FindPosition(wxDC& dc, wxRichTextDrawingContext& context, long index,
                              wxPoint& pt, int* height, bool forceLineStart);
    virtual wxSize GetBestSize() const;
    virtual bool GetRangeSize(const wxRichTextRange& range, wxSize& size, int& descent,
                              wxDC& dc, wxRichTextDrawingContext& context, int flags,
                              const wxPoint& position = wxPoint(0,0),
                              const wxSize& parentSize = wxDefaultSize,
                              wxArrayInt* partialExtents = NULL) const  = 0;
    virtual wxRichTextObject* DoSplit(long pos);
    virtual void CalculateRange(long start, long& end);
    virtual bool DeleteRange(const wxRichTextRange& range);
    virtual bool IsEmpty() const;
    virtual bool IsFloatable() const;
    virtual bool IsFloating() const;
    virtual int GetFloatDirection() const;
    virtual wxString GetTextForRange(const wxRichTextRange& range) const;
    virtual bool CanMerge(wxRichTextObject* object, wxRichTextDrawingContext& context) const;
    virtual bool Merge(wxRichTextObject* object, wxRichTextDrawingContext& context);
    virtual bool CanSplit(wxRichTextDrawingContext& context) const;
    virtual wxRichTextObject* Split(wxRichTextDrawingContext& context);
    virtual void Dump(wxTextOutputStream& stream);
    virtual bool CanEditProperties() const;
    virtual bool EditProperties(wxWindow* parent, wxRichTextBuffer* buffer);
    virtual wxString GetPropertiesMenuLabel() const;
    virtual bool AcceptsFocus() const;
    virtual bool ImportFromXML(wxRichTextBuffer* buffer, wxXmlNode* node, wxRichTextXMLHandler* handler, bool* recurse);
#if wxRICHTEXT_HAVE_DIRECT_OUTPUT
    virtual bool ExportXML(wxOutputStream& stream, int indent, wxRichTextXMLHandler* handler);
#endif
#if wxRICHTEXT_HAVE_XMLDOCUMENT_OUTPUT
    virtual bool ExportXML(wxXmlNode* parent, wxRichTextXMLHandler* handler);
#endif
    virtual bool UsesParagraphAttributes() const;
    virtual wxString GetXMLNodeName() const;
    virtual void Invalidate(const wxRichTextRange& invalidRange = wxRICHTEXT_ALL);
    virtual bool HandlesChildSelections() const;
    virtual wxRichTextSelection GetSelection(long start, long end) const;
    virtual wxSize GetCachedSize() const;
    virtual void SetCachedSize(const wxSize& sz);
    virtual wxSize GetMaxSize() const;
    virtual void SetMaxSize(const wxSize& sz);
    virtual wxSize GetMinSize() const;
    virtual void SetMinSize(const wxSize& sz);
    virtual wxTextAttrSize GetNaturalSize() const;
    virtual wxPoint GetPosition() const;
    virtual void SetPosition(const wxPoint& pos);
    virtual wxPoint GetAbsolutePosition() const;
    virtual wxRect GetRect() const;
    void SetRange(const wxRichTextRange& range);
    wxRichTextRange& GetRange();
    void SetOwnRange(const wxRichTextRange& range);
    wxRichTextRange& GetOwnRange();
    wxRichTextRange GetOwnRangeIfTopLevel() const;
    virtual bool IsComposite() const;
    virtual bool IsAtomic() const;
    virtual wxRichTextObject* GetParent() const;
    virtual void SetParent(wxRichTextObject* parent);
    virtual wxRichTextParagraphLayoutBox* GetContainer() const;
    virtual wxRichTextParagraphLayoutBox* GetParentContainer() const;
    virtual void SetMargins(int margin);
    virtual void SetMargins(int leftMargin, int rightMargin, int topMargin, int bottomMargin);
    virtual int GetLeftMargin() const;
    virtual int GetRightMargin() const;
    virtual int GetTopMargin() const;
    virtual int GetBottomMargin() const;
    virtual wxRect GetAvailableContentArea(wxDC& dc, wxRichTextDrawingContext& context, const wxRect& outerRect) const;
    virtual bool LayoutToBestSize(wxDC& dc, wxRichTextDrawingContext& context, wxRichTextBuffer* buffer,
                    const wxRichTextAttr& parentAttr, const wxRichTextAttr& attr,
                    const wxRect& availableParentSpace, const wxRect& availableContainerSpace, int style);
    virtual bool AdjustAttributes(wxRichTextAttr& attr, wxRichTextDrawingContext& context);
    void SetAttributes(const wxRichTextAttr& attr);
    wxRichTextAttr& GetAttributes();
    wxRichTextProperties& GetProperties();
    void SetProperties(const wxRichTextProperties& props);
    void SetDescent(int descent);
    int GetDescent() const;
    wxRichTextBuffer* GetBuffer() const;
    void SetName(const wxString& name);
    wxString GetName() const;
    virtual bool IsTopLevel() const;
    bool IsShown() const;
    virtual void Show(bool show);
    virtual wxRichTextObject* Clone() const;
    void Copy(const wxRichTextObject& obj);
    void Reference();
    void Dereference();
    virtual void Move(const wxPoint& pt);
    int ConvertTenthsMMToPixels(wxDC& dc, int units) const;
     int ConvertTenthsMMToPixels(int ppi, int units, double scale = 1.0);
    int ConvertPixelsToTenthsMM(wxDC& dc, int pixels) const;
      int ConvertPixelsToTenthsMM(int ppi, int pixels, double scale = 1.0);
    static bool DrawBoxAttributes(wxDC& dc, wxRichTextBuffer* buffer, const wxRichTextAttr& attr, const wxRect& boxRect, int flags = 0, wxRichTextObject* obj = NULL);
    static bool DrawBorder(wxDC& dc, wxRichTextBuffer* buffer, const wxRichTextAttr& attr, const wxTextAttrBorders& borders, const wxRect& rect, int flags = 0);
    static bool GetBoxRects(wxDC& dc, wxRichTextBuffer* buffer, const wxRichTextAttr& attr,
                            wxRect& marginRect, wxRect& borderRect, wxRect& contentRect,
                            wxRect& paddingRect, wxRect& outlineRect);
    static bool GetTotalMargin(wxDC& dc, wxRichTextBuffer* buffer, const wxRichTextAttr& attr,
                               int& leftMargin, int& rightMargin, int& topMargin, int& bottomMargin);
    static wxRect AdjustAvailableSpace(wxDC& dc, wxRichTextBuffer* buffer, const wxRichTextAttr& parentAttr,
                                       const wxRichTextAttr& childAttr, const wxRect& availableParentSpace,
                                       const wxRect& availableContainerSpace);
protected:
    wxSize                  m_size;
    wxSize                  m_maxSize;
    wxSize                  m_minSize;
    wxPoint                 m_pos;
    int                     m_descent; 
    int                     m_refCount;
    bool                    m_show;
    wxRichTextObject*       m_parent;
    wxRichTextRange         m_range;
    wxRichTextRange         m_ownRange;
    wxRichTextAttr          m_attributes;
    wxRichTextProperties    m_properties;
};
class wxRichTextObjectList;
WXGO_DECL_TYPECONV(RichTextCompositeObject)
class wxRichTextCompositeObject: public wxRichTextObject
{
public:
    wxRichTextCompositeObject(wxRichTextObject* parent = NULL);
    virtual ~wxRichTextCompositeObject();
    virtual int HitTest(wxDC& dc, wxRichTextDrawingContext& context, const wxPoint& pt,
                        long& textPosition, wxRichTextObject** obj,
                        wxRichTextObject** contextObj, int flags = 0);
    virtual bool FindPosition(wxDC& dc, wxRichTextDrawingContext& context, long index,
                              wxPoint& pt, int* height, bool forceLineStart);
    virtual void CalculateRange(long start, long& end);
    virtual bool DeleteRange(const wxRichTextRange& range);
    virtual wxString GetTextForRange(const wxRichTextRange& range) const;
    virtual bool GetRangeSize(const wxRichTextRange& range, wxSize& size, int& descent,
                              wxDC& dc, wxRichTextDrawingContext& context, int flags,
                              const wxPoint& position = wxPoint(0,0),
                              const wxSize& parentSize = wxDefaultSize,
                              wxArrayInt* partialExtents = NULL) const;
    virtual void Dump(wxTextOutputStream& stream);
    virtual void Invalidate(const wxRichTextRange& invalidRange = wxRICHTEXT_ALL);
    wxRichTextObjectList& GetChildren();
    size_t GetChildCount() const ;
    wxRichTextObject* GetChild(size_t n) const ;
    virtual bool IsComposite() const;
    virtual bool IsAtomic() const;
    virtual bool IsEmpty() const;
    virtual wxRichTextObject* GetChildAtPosition(long pos) const;
    void Copy(const wxRichTextCompositeObject& obj);
    void operator= (const wxRichTextCompositeObject& obj);
    size_t AppendChild(wxRichTextObject* child) ;
    bool InsertChild(wxRichTextObject* child, wxRichTextObject* inFrontOf) ;
    bool RemoveChild(wxRichTextObject* child, bool deleteChild = false) ;
    bool DeleteChildren() ;
    bool Defragment(wxRichTextDrawingContext& context, const wxRichTextRange& range = wxRICHTEXT_ALL);
    virtual void Move(const wxPoint& pt);
protected:
    wxRichTextObjectList    m_children;
};
WXGO_DECL_TYPECONV(RichTextParagraphLayoutBox)
class wxRichTextParagraphLayoutBox: public wxRichTextCompositeObject
{
public:
    wxRichTextParagraphLayoutBox(wxRichTextObject* parent = NULL);
    wxRichTextParagraphLayoutBox(const wxRichTextParagraphLayoutBox& obj): wxRichTextCompositeObject() { Init(); Copy(obj); }
    ~wxRichTextParagraphLayoutBox();
    virtual int HitTest(wxDC& dc, wxRichTextDrawingContext& context, const wxPoint& pt, long& textPosition, wxRichTextObject** obj, wxRichTextObject** contextObj, int flags = 0);
    virtual bool Draw(wxDC& dc, wxRichTextDrawingContext& context, const wxRichTextRange& range, const wxRichTextSelection& selection, const wxRect& rect, int descent, int style);
    virtual bool Layout(wxDC& dc, wxRichTextDrawingContext& context, const wxRect& rect, const wxRect& parentRect, int style);
    virtual bool GetRangeSize(const wxRichTextRange& range, wxSize& size, int& descent, wxDC& dc, wxRichTextDrawingContext& context, int flags, const wxPoint& position = wxPoint(0,0), const wxSize& parentSize = wxDefaultSize, wxArrayInt* partialExtents = NULL) const;
    virtual bool DeleteRange(const wxRichTextRange& range);
    virtual wxString GetTextForRange(const wxRichTextRange& range) const;
    virtual bool ImportFromXML(wxRichTextBuffer* buffer, wxXmlNode* node, wxRichTextXMLHandler* handler, bool* recurse);
#if wxRICHTEXT_HAVE_DIRECT_OUTPUT
    virtual bool ExportXML(wxOutputStream& stream, int indent, wxRichTextXMLHandler* handler);
#endif
#if wxRICHTEXT_HAVE_XMLDOCUMENT_OUTPUT
    virtual bool ExportXML(wxXmlNode* parent, wxRichTextXMLHandler* handler);
#endif
    virtual wxString GetXMLNodeName() const { return wxT("paragraphlayout"); }
    virtual bool AcceptsFocus() const { return true; }
    void SetRichTextCtrl(wxRichTextCtrl* ctrl) { m_ctrl = ctrl; }
    wxRichTextCtrl* GetRichTextCtrl() const { return m_ctrl; }
    void SetPartialParagraph(bool partialPara) { m_partialParagraph = partialPara; }
    bool GetPartialParagraph() const { return m_partialParagraph; }
    virtual wxRichTextStyleSheet* GetStyleSheet() const;
    virtual bool IsTopLevel() const { return true; }
    bool InsertParagraphsWithUndo(wxRichTextBuffer* buffer, long pos, const wxRichTextParagraphLayoutBox& paragraphs, wxRichTextCtrl* ctrl, int flags = 0);
    bool InsertTextWithUndo(wxRichTextBuffer* buffer, long pos, const wxString& text, wxRichTextCtrl* ctrl, int flags = 0);
    bool InsertNewlineWithUndo(wxRichTextBuffer* buffer, long pos, wxRichTextCtrl* ctrl, int flags = 0);
    bool InsertImageWithUndo(wxRichTextBuffer* buffer, long pos, const wxRichTextImageBlock& imageBlock,
                                                        wxRichTextCtrl* ctrl, int flags,
                                                        const wxRichTextAttr& textAttr);
    wxRichTextField* InsertFieldWithUndo(wxRichTextBuffer* buffer, long pos, const wxString& fieldType,
                                                        const wxRichTextProperties& properties,
                                                        wxRichTextCtrl* ctrl, int flags,
                                                        const wxRichTextAttr& textAttr);
    wxRichTextAttr GetStyleForNewParagraph(wxRichTextBuffer* buffer, long pos, bool caretPosition = false, bool lookUpNewParaStyle=false) const;
    wxRichTextObject* InsertObjectWithUndo(wxRichTextBuffer* buffer, long pos, wxRichTextObject *object, wxRichTextCtrl* ctrl, int flags = 0);
    bool DeleteRangeWithUndo(const wxRichTextRange& range, wxRichTextCtrl* ctrl, wxRichTextBuffer* buffer);
    void DrawFloats(wxDC& dc, wxRichTextDrawingContext& context, const wxRichTextRange& range, const wxRichTextSelection& selection, const wxRect& rect, int descent, int style);
    void MoveAnchoredObjectToParagraph(wxRichTextParagraph* from, wxRichTextParagraph* to, wxRichTextObject* obj);
    void Init();
    virtual void Clear();
    virtual void Reset();
    virtual wxRichTextRange AddParagraph(const wxString& text, wxRichTextAttr* paraStyle = NULL);
    virtual wxRichTextRange AddImage(const wxImage& image, wxRichTextAttr* paraStyle = NULL);
    virtual wxRichTextRange AddParagraphs(const wxString& text, wxRichTextAttr* paraStyle = NULL);
    virtual wxRichTextLine* GetLineAtPosition(long pos, bool caretPosition = false) const;
    virtual wxRichTextLine* GetLineAtYPosition(int y) const;
    virtual wxRichTextParagraph* GetParagraphAtPosition(long pos, bool caretPosition = false) const;
    virtual wxSize GetLineSizeAtPosition(long pos, bool caretPosition = false) const;
    virtual long GetVisibleLineNumber(long pos, bool caretPosition = false, bool startOfLine = false) const;
    virtual wxRichTextLine* GetLineForVisibleLineNumber(long lineNumber) const;
    virtual wxRichTextObject* GetLeafObjectAtPosition(long position) const;
    virtual wxRichTextParagraph* GetParagraphAtLine(long paragraphNumber) const;
    virtual wxRichTextParagraph* GetParagraphForLine(wxRichTextLine* line) const;
    virtual int GetParagraphLength(long paragraphNumber) const;
    virtual int GetParagraphCount() const { return static_cast<int>(GetChildCount()); }
    virtual int GetLineCount() const;
    virtual wxString GetParagraphText(long paragraphNumber) const;
    virtual long XYToPosition(long x, long y) const;
    virtual bool PositionToXY(long pos, long* x, long* y) const;
    virtual bool SetStyle(const wxRichTextRange& range, const wxRichTextAttr& style, int flags = wxRICHTEXT_SETSTYLE_WITH_UNDO);
    virtual void SetStyle(wxRichTextObject *obj, const wxRichTextAttr& textAttr, int flags = wxRICHTEXT_SETSTYLE_WITH_UNDO);
    virtual bool GetStyle(long position, wxRichTextAttr& style);
    virtual bool GetUncombinedStyle(long position, wxRichTextAttr& style);
    virtual bool DoGetStyle(long position, wxRichTextAttr& style, bool combineStyles = true);
    virtual bool GetStyleForRange(const wxRichTextRange& range, wxRichTextAttr& style);
    bool CollectStyle(wxRichTextAttr& currentStyle, const wxRichTextAttr& style, wxRichTextAttr& clashingAttr, wxRichTextAttr& absentAttr);
    virtual bool SetListStyle(const wxRichTextRange& range, wxRichTextListStyleDefinition* def, int flags = wxRICHTEXT_SETSTYLE_WITH_UNDO, int startFrom = 1, int specifiedLevel = -1);
    virtual bool SetListStyle(const wxRichTextRange& range, const wxString& defName, int flags = wxRICHTEXT_SETSTYLE_WITH_UNDO, int startFrom = 1, int specifiedLevel = -1);
    virtual bool ClearListStyle(const wxRichTextRange& range, int flags = wxRICHTEXT_SETSTYLE_WITH_UNDO);
    virtual bool NumberList(const wxRichTextRange& range, wxRichTextListStyleDefinition* def = NULL, int flags = wxRICHTEXT_SETSTYLE_WITH_UNDO, int startFrom = 1, int specifiedLevel = -1);
    virtual bool NumberList(const wxRichTextRange& range, const wxString& defName, int flags = wxRICHTEXT_SETSTYLE_WITH_UNDO, int startFrom = 1, int specifiedLevel = -1);
    virtual bool PromoteList(int promoteBy, const wxRichTextRange& range, wxRichTextListStyleDefinition* def = NULL, int flags = wxRICHTEXT_SETSTYLE_WITH_UNDO, int specifiedLevel = -1);
    virtual bool PromoteList(int promoteBy, const wxRichTextRange& range, const wxString& defName, int flags = wxRICHTEXT_SETSTYLE_WITH_UNDO, int specifiedLevel = -1);
    virtual bool DoNumberList(const wxRichTextRange& range, const wxRichTextRange& promotionRange, int promoteBy, wxRichTextListStyleDefinition* def, int flags = wxRICHTEXT_SETSTYLE_WITH_UNDO, int startFrom = 1, int specifiedLevel = -1);
    virtual bool FindNextParagraphNumber(wxRichTextParagraph* previousParagraph, wxRichTextAttr& attr) const;
    virtual bool SetProperties(const wxRichTextRange& range, const wxRichTextProperties& properties, int flags = wxRICHTEXT_SETPROPERTIES_WITH_UNDO);
    virtual bool SetObjectPropertiesWithUndo(wxRichTextObject& obj, const wxRichTextProperties& properties, wxRichTextObject* objToSet = NULL);
    virtual bool HasCharacterAttributes(const wxRichTextRange& range, const wxRichTextAttr& style) const;
    virtual bool HasParagraphAttributes(const wxRichTextRange& range, const wxRichTextAttr& style) const;
    virtual wxRichTextObject* Clone() const { return new wxRichTextParagraphLayoutBox(*this); }
    virtual void PrepareContent(wxRichTextParagraphLayoutBox& container);
    virtual bool InsertFragment(long position, wxRichTextParagraphLayoutBox& fragment);
    virtual bool CopyFragment(const wxRichTextRange& range, wxRichTextParagraphLayoutBox& fragment);
    virtual bool ApplyStyleSheet(wxRichTextStyleSheet* styleSheet);
    void Copy(const wxRichTextParagraphLayoutBox& obj);
    void operator= (const wxRichTextParagraphLayoutBox& obj) { Copy(obj); }
    virtual void UpdateRanges();
    virtual wxString GetText() const;
    virtual bool SetDefaultStyle(const wxRichTextAttr& style);
    virtual const wxRichTextAttr& GetDefaultStyle() const { return m_defaultAttributes; }
    virtual void SetBasicStyle(const wxRichTextAttr& style) { m_attributes = style; }
    virtual const wxRichTextAttr& GetBasicStyle() const { return m_attributes; }
    virtual void Invalidate(const wxRichTextRange& invalidRange = wxRICHTEXT_ALL);
    virtual void DoInvalidate(const wxRichTextRange& invalidRange);
    virtual void InvalidateHierarchy(const wxRichTextRange& invalidRange = wxRICHTEXT_ALL);
    virtual bool UpdateFloatingObjects(const wxRect& availableRect, wxRichTextObject* untilObj = NULL);
    wxRichTextRange GetInvalidRange(bool wholeParagraphs = false) const;
    bool IsDirty() const { return m_invalidRange != wxRICHTEXT_NONE; }
    wxRichTextFloatCollector* GetFloatCollector() { return m_floatCollector; }
    int GetFloatingObjectCount() const;
    bool GetFloatingObjects(wxRichTextObjectList& objects) const;
protected:
    wxRichTextCtrl* m_ctrl;
    wxRichTextAttr  m_defaultAttributes;
    wxRichTextRange m_invalidRange;
    bool            m_partialParagraph;
    wxRichTextFloatCollector* m_floatCollector;
};
WXGO_DECL_TYPECONV(RichTextBox)
class wxRichTextBox: public wxRichTextParagraphLayoutBox
{
public:
    wxRichTextBox(wxRichTextObject* parent = NULL);
    wxRichTextBox(const wxRichTextBox& obj): wxRichTextParagraphLayoutBox() { Copy(obj); }
    virtual bool Draw(wxDC& dc, wxRichTextDrawingContext& context, const wxRichTextRange& range, const wxRichTextSelection& selection, const wxRect& rect, int descent, int style);
    virtual wxString GetXMLNodeName() const { return wxT("textbox"); }
    virtual bool CanEditProperties() const { return true; }
    virtual bool EditProperties(wxWindow* parent, wxRichTextBuffer* buffer);
    virtual wxString GetPropertiesMenuLabel() const { return _("&Box"); }
    virtual wxRichTextObject* Clone() const { return new wxRichTextBox(*this); }
    void Copy(const wxRichTextBox& obj);
protected:
};
WXGO_DECL_TYPECONV(RichTextField)
class wxRichTextField: public wxRichTextParagraphLayoutBox
{
public:
    wxRichTextField(const wxString& fieldType = wxEmptyString, wxRichTextObject* parent = NULL);
    wxRichTextField(const wxRichTextField& obj): wxRichTextParagraphLayoutBox() { Copy(obj); }
    virtual bool Draw(wxDC& dc, wxRichTextDrawingContext& context, const wxRichTextRange& range, const wxRichTextSelection& selection, const wxRect& rect, int descent, int style);
    virtual bool Layout(wxDC& dc, wxRichTextDrawingContext& context, const wxRect& rect, const wxRect& parentRect, int style);
    virtual bool GetRangeSize(const wxRichTextRange& range, wxSize& size, int& descent, wxDC& dc, wxRichTextDrawingContext& context, int flags, const wxPoint& position = wxPoint(0,0), const wxSize& parentSize = wxDefaultSize, wxArrayInt* partialExtents = NULL) const;
    virtual wxString GetXMLNodeName() const { return wxT("field"); }
    virtual bool CanEditProperties() const;
    virtual bool EditProperties(wxWindow* parent, wxRichTextBuffer* buffer);
    virtual wxString GetPropertiesMenuLabel() const;
    virtual bool AcceptsFocus() const { return false; }
    virtual void CalculateRange(long start, long& end);
    virtual bool IsAtomic() const { return true; }
    virtual bool IsEmpty() const { return false; }
    virtual bool IsTopLevel() const;
    void SetFieldType(const wxString& fieldType) { GetProperties().SetProperty(wxT("FieldType"), fieldType); }
    wxString GetFieldType() const { return GetProperties().GetPropertyString(wxT("FieldType")); }
    virtual bool UpdateField(wxRichTextBuffer* buffer);
    virtual wxRichTextObject* Clone() const { return new wxRichTextField(*this); }
    void Copy(const wxRichTextField& obj);
protected:
};
WXGO_DECL_TYPECONV(RichTextFieldType)
class wxRichTextFieldType: public wxObject
{
public:
    wxRichTextFieldType(const wxString& name = wxEmptyString)
        : m_name(name)
        { }
    wxRichTextFieldType(const wxRichTextFieldType& fieldType) { Copy(fieldType); }
    void Copy(const wxRichTextFieldType& fieldType) { m_name = fieldType.m_name; }
    virtual bool Draw(wxRichTextField* obj, wxDC& dc, wxRichTextDrawingContext& context, const wxRichTextRange& range, const wxRichTextSelection& selection, const wxRect& rect, int descent, int style) = 0;
    virtual bool Layout(wxRichTextField* obj, wxDC& dc, wxRichTextDrawingContext& context, const wxRect& rect, const wxRect& parentRect, int style) = 0;
    virtual bool GetRangeSize(wxRichTextField* obj, const wxRichTextRange& range, wxSize& size, int& descent, wxDC& dc, wxRichTextDrawingContext& context, int flags, const wxPoint& position = wxPoint(0,0), const wxSize& parentSize = wxDefaultSize, wxArrayInt* partialExtents = NULL) const = 0;
    virtual bool CanEditProperties(wxRichTextField* obj) const { return false; }
    virtual bool EditProperties(wxRichTextField* obj, wxWindow* parent, wxRichTextBuffer* buffer) { return false; }
    virtual wxString GetPropertiesMenuLabel(wxRichTextField* obj) const { return wxEmptyString; }
    virtual bool UpdateField(wxRichTextBuffer* buffer, wxRichTextField* obj) { return false; }
    virtual bool IsTopLevel(wxRichTextField* obj) const { return true; }
    void SetName(const wxString& name) { m_name = name; }
    wxString GetName() const { return m_name; }
protected:
    wxString  m_name;
};
class wxRichTextFieldTypeHashMap;
WXGO_DECL_TYPECONV(RichTextFieldTypeStandard)
class wxRichTextFieldTypeStandard: public wxRichTextFieldType
{
public:
    enum { wxRICHTEXT_FIELD_STYLE_COMPOSITE = 0x01,
           wxRICHTEXT_FIELD_STYLE_RECTANGLE = 0x02,
           wxRICHTEXT_FIELD_STYLE_NO_BORDER = 0x04,
           wxRICHTEXT_FIELD_STYLE_START_TAG = 0x08,
           wxRICHTEXT_FIELD_STYLE_END_TAG = 0x10
         };
    wxRichTextFieldTypeStandard(const wxString& name, const wxString& label, int displayStyle = wxRICHTEXT_FIELD_STYLE_RECTANGLE);
    wxRichTextFieldTypeStandard(const wxString& name, const wxBitmap& bitmap, int displayStyle = wxRICHTEXT_FIELD_STYLE_NO_BORDER);
    wxRichTextFieldTypeStandard() { Init(); }
    wxRichTextFieldTypeStandard(const wxRichTextFieldTypeStandard& field) { Copy(field); }
    void Init();
    void Copy(const wxRichTextFieldTypeStandard& field);
    void operator=(const wxRichTextFieldTypeStandard& field) { Copy(field); }
    virtual bool Draw(wxRichTextField* obj, wxDC& dc, wxRichTextDrawingContext& context, const wxRichTextRange& range, const wxRichTextSelection& selection, const wxRect& rect, int descent, int style);
    virtual bool Layout(wxRichTextField* obj, wxDC& dc, wxRichTextDrawingContext& context, const wxRect& rect, const wxRect& parentRect, int style);
    virtual bool GetRangeSize(wxRichTextField* obj, const wxRichTextRange& range, wxSize& size, int& descent, wxDC& dc, wxRichTextDrawingContext& context, int flags, const wxPoint& position = wxPoint(0,0), const wxSize& parentSize = wxDefaultSize, wxArrayInt* partialExtents = NULL) const;
    wxSize GetSize(wxRichTextField* obj, wxDC& dc, wxRichTextDrawingContext& context, int style) const;
    virtual bool IsTopLevel(wxRichTextField* obj) const { return (GetDisplayStyle() & wxRICHTEXT_FIELD_STYLE_COMPOSITE) != 0; }
    void SetLabel(const wxString& label) { m_label = label; }
    const wxString& GetLabel() const { return m_label; }
    void SetBitmap(const wxBitmap& bitmap) { m_bitmap = bitmap; }
    const wxBitmap& GetBitmap() const { return m_bitmap; }
    int GetDisplayStyle() const { return m_displayStyle; }
    void SetDisplayStyle(int displayStyle) { m_displayStyle = displayStyle; }
    const wxFont& GetFont() const { return m_font; }
    void SetFont(const wxFont& font) { m_font = font; }
    const wxColour& GetTextColour() const { return m_textColour; }
    void SetTextColour(const wxColour& colour) { m_textColour = colour; }
    const wxColour& GetBorderColour() const { return m_borderColour; }
    void SetBorderColour(const wxColour& colour) { m_borderColour = colour; }
    const wxColour& GetBackgroundColour() const { return m_backgroundColour; }
    void SetBackgroundColour(const wxColour& colour) { m_backgroundColour = colour; }
    void SetVerticalPadding(int padding) { m_verticalPadding = padding; }
    int GetVerticalPadding() const { return m_verticalPadding; }
    void SetHorizontalPadding(int padding) { m_horizontalPadding = padding; }
    int GetHorizontalPadding() const { return m_horizontalPadding; }
    void SetHorizontalMargin(int margin) { m_horizontalMargin = margin; }
    int GetHorizontalMargin() const { return m_horizontalMargin; }
    void SetVerticalMargin(int margin) { m_verticalMargin = margin; }
    int GetVerticalMargin() const { return m_verticalMargin; }
protected:
    wxString    m_label;
    int         m_displayStyle;
    wxFont      m_font;
    wxColour    m_textColour;
    wxColour    m_borderColour;
    wxColour    m_backgroundColour;
    int         m_verticalPadding;
    int         m_horizontalPadding;
    int         m_horizontalMargin;
    int         m_verticalMargin;
    wxBitmap    m_bitmap;
};
WXGO_DECL_TYPECONV(RichTextLine)
class wxRichTextLine
{
public:
    wxRichTextLine(wxRichTextParagraph* parent);
    wxRichTextLine(const wxRichTextLine& obj) { Init( NULL); Copy(obj); }
    virtual ~wxRichTextLine() {}
    void SetRange(const wxRichTextRange& range) { m_range = range; }
    void SetRange(long from, long to) { m_range = wxRichTextRange(from, to); }
    wxRichTextParagraph* GetParent() { return m_parent; }
    wxRichTextRange& GetRange() { return m_range; }
    wxRichTextRange GetAbsoluteRange() const;
    virtual wxSize GetSize() const { return m_size; }
    virtual void SetSize(const wxSize& sz) { m_size = sz; }
    virtual wxPoint GetPosition() const { return m_pos; }
    virtual void SetPosition(const wxPoint& pos) { m_pos = pos; }
    virtual wxPoint GetAbsolutePosition() const;
    virtual wxRect GetRect() const { return wxRect(GetAbsolutePosition(), GetSize()); }
    void SetDescent(int descent) { m_descent = descent; }
    int GetDescent() const { return m_descent; }
#if wxRICHTEXT_USE_OPTIMIZED_LINE_DRAWING
    wxArrayInt& GetObjectSizes() { return m_objectSizes; }
#endif
    void Init(wxRichTextParagraph* parent);
    void Copy(const wxRichTextLine& obj);
    virtual wxRichTextLine* Clone() const { return new wxRichTextLine(*this); }
protected:
    wxRichTextRange     m_range;
    wxPoint             m_pos;
    wxSize              m_size;
    int                 m_descent;
    wxRichTextParagraph* m_parent;
#if wxRICHTEXT_USE_OPTIMIZED_LINE_DRAWING
    wxArrayInt          m_objectSizes;
#endif
};
class wxRichTextLineList;
WXGO_DECL_TYPECONV(RichTextParagraph)
class wxRichTextParagraph: public wxRichTextCompositeObject
{
public:
    wxRichTextParagraph(wxRichTextObject* parent = NULL, wxRichTextAttr* style = NULL);
    wxRichTextParagraph(const wxString& text, wxRichTextObject* parent = NULL, wxRichTextAttr* paraStyle = NULL, wxRichTextAttr* charStyle = NULL);
    virtual ~wxRichTextParagraph();
    wxRichTextParagraph(const wxRichTextParagraph& obj): wxRichTextCompositeObject() { Copy(obj); }
    void Init();
    virtual bool Draw(wxDC& dc, wxRichTextDrawingContext& context, const wxRichTextRange& range, const wxRichTextSelection& selection, const wxRect& rect, int descent, int style);
    virtual bool Layout(wxDC& dc, wxRichTextDrawingContext& context, const wxRect& rect, const wxRect& parentRect, int style);
    virtual bool GetRangeSize(const wxRichTextRange& range, wxSize& size, int& descent, wxDC& dc, wxRichTextDrawingContext& context, int flags, const wxPoint& position = wxPoint(0,0), const wxSize& parentSize = wxDefaultSize, wxArrayInt* partialExtents = NULL) const;
    virtual bool FindPosition(wxDC& dc, wxRichTextDrawingContext& context, long index, wxPoint& pt, int* height, bool forceLineStart);
    virtual int HitTest(wxDC& dc, wxRichTextDrawingContext& context, const wxPoint& pt, long& textPosition, wxRichTextObject** obj, wxRichTextObject** contextObj, int flags = 0);
    virtual void CalculateRange(long start, long& end);
    virtual wxString GetXMLNodeName() const { return wxT("paragraph"); }
    wxRichTextLineList& GetLines() { return m_cachedLines; }
    void Copy(const wxRichTextParagraph& obj);
    virtual wxRichTextObject* Clone() const { return new wxRichTextParagraph(*this); }
    void ClearLines();
    virtual void ApplyParagraphStyle(wxRichTextLine* line, const wxRichTextAttr& attr, const wxRect& rect, wxDC& dc);
    virtual bool InsertText(long pos, const wxString& text);
    virtual wxRichTextObject* SplitAt(long pos, wxRichTextObject** previousObject = NULL);
    virtual void MoveToList(wxRichTextObject* obj, wxList& list);
    virtual void MoveFromList(wxList& list);
    bool GetContiguousPlainText(wxString& text, const wxRichTextRange& range, bool fromStart = true);
    bool FindWrapPosition(const wxRichTextRange& range, wxDC& dc, wxRichTextDrawingContext& context, int availableSpace, long& wrapPosition, wxArrayInt* partialExtents);
    wxRichTextObject* FindObjectAtPosition(long position);
    wxString GetBulletText();
    wxRichTextLine* AllocateLine(int pos);
    bool ClearUnusedLines(int lineCount);
    wxRichTextAttr GetCombinedAttributes(const wxRichTextAttr& contentStyle, bool includingBoxAttr = false) const;
    wxRichTextAttr GetCombinedAttributes(bool includingBoxAttr = false) const;
    long GetFirstLineBreakPosition(long pos);
    static void InitDefaultTabs();
    static void ClearDefaultTabs();
    static const wxArrayInt& GetDefaultTabs() { return sm_defaultTabs; }
    void LayoutFloat(wxDC& dc, wxRichTextDrawingContext& context, const wxRect& rect, const wxRect& parentRect, int style, wxRichTextFloatCollector* floatCollector);
    int GetImpactedByFloatingObjects() const { return m_impactedByFloatingObjects; }
    void SetImpactedByFloatingObjects(int i) { m_impactedByFloatingObjects = i; }
protected:
    wxRichTextLineList  m_cachedLines;
    int                 m_impactedByFloatingObjects;
    static wxArrayInt  sm_defaultTabs;
friend class wxRichTextFloatCollector;
};
WXGO_DECL_TYPECONV(RichTextPlainText)
class wxRichTextPlainText: public wxRichTextObject
{
public:
    wxRichTextPlainText(const wxString& text = wxEmptyString, wxRichTextObject* parent = NULL, wxRichTextAttr* style = NULL);
    wxRichTextPlainText(const wxRichTextPlainText& obj): wxRichTextObject() { Copy(obj); }
    virtual bool Draw(wxDC& dc, wxRichTextDrawingContext& context, const wxRichTextRange& range, const wxRichTextSelection& selection, const wxRect& rect, int descent, int style);
    virtual bool Layout(wxDC& dc, wxRichTextDrawingContext& context, const wxRect& rect, const wxRect& parentRect, int style);
    virtual bool GetRangeSize(const wxRichTextRange& range, wxSize& size, int& descent, wxDC& dc, wxRichTextDrawingContext& context, int flags, const wxPoint& position = wxPoint(0,0), const wxSize& parentSize = wxDefaultSize, wxArrayInt* partialExtents = NULL) const;
    virtual wxString GetTextForRange(const wxRichTextRange& range) const;
    virtual wxRichTextObject* DoSplit(long pos);
    virtual void CalculateRange(long start, long& end);
    virtual bool DeleteRange(const wxRichTextRange& range);
    virtual bool IsEmpty() const { return m_text.empty(); }
    virtual bool CanMerge(wxRichTextObject* object, wxRichTextDrawingContext& context) const;
    virtual bool Merge(wxRichTextObject* object, wxRichTextDrawingContext& context);
    virtual bool CanSplit(wxRichTextDrawingContext& context) const;
    virtual wxRichTextObject* Split(wxRichTextDrawingContext& context);
    virtual void Dump(wxTextOutputStream& stream);
    long GetFirstLineBreakPosition(long pos);
    virtual bool UsesParagraphAttributes() const { return false; }
    virtual bool ImportFromXML(wxRichTextBuffer* buffer, wxXmlNode* node, wxRichTextXMLHandler* handler, bool* recurse);
#if wxRICHTEXT_HAVE_DIRECT_OUTPUT
    virtual bool ExportXML(wxOutputStream& stream, int indent, wxRichTextXMLHandler* handler);
#endif
#if wxRICHTEXT_HAVE_XMLDOCUMENT_OUTPUT
    virtual bool ExportXML(wxXmlNode* parent, wxRichTextXMLHandler* handler);
#endif
    virtual wxString GetXMLNodeName() const { return wxT("text"); }
    const wxString& GetText() const { return m_text; }
    void SetText(const wxString& text) { m_text = text; }
    void Copy(const wxRichTextPlainText& obj);
    virtual wxRichTextObject* Clone() const { return new wxRichTextPlainText(*this); }
private:
    bool DrawTabbedString(wxDC& dc, const wxRichTextAttr& attr, const wxRect& rect, wxString& str, wxCoord& x, wxCoord& y, bool selected);
protected:
    wxString    m_text;
};
WXGO_DECL_TYPECONV(RichTextImageBlock)
class wxRichTextImageBlock: public wxObject
{
public:
    wxRichTextImageBlock();
    wxRichTextImageBlock(const wxRichTextImageBlock& block);
    virtual ~wxRichTextImageBlock();
    void Init();
    void Clear();
    virtual bool MakeImageBlock(const wxString& filename, wxBitmapType imageType,
                                wxImage& image, bool convertToJPEG = true);
    virtual bool MakeImageBlock(wxImage& image, wxBitmapType imageType, int quality = 80);
    virtual bool MakeImageBlockDefaultQuality(const wxImage& image, wxBitmapType imageType);
    virtual bool DoMakeImageBlock(const wxImage& image, wxBitmapType imageType);
    bool Write(const wxString& filename);
    bool WriteHex(wxOutputStream& stream);
    bool ReadHex(wxInputStream& stream, int length, wxBitmapType imageType);
    void Copy(const wxRichTextImageBlock& block);
    bool Load(wxImage& image);
    void operator=(const wxRichTextImageBlock& block);
    unsigned char* GetData() const { return m_data; }
    size_t GetDataSize() const { return m_dataSize; }
    wxBitmapType GetImageType() const { return m_imageType; }
    void SetData(unsigned char* image) { m_data = image; }
    void SetDataSize(size_t size) { m_dataSize = size; }
    void SetImageType(wxBitmapType imageType) { m_imageType = imageType; }
    bool IsOk() const { return GetData() != NULL; }
    bool Ok() const { return IsOk(); }
    wxString GetExtension() const;
    static unsigned char* ReadBlock(wxInputStream& stream, size_t size);
    static unsigned char* ReadBlock(const wxString& filename, size_t size);
    static bool WriteBlock(wxOutputStream& stream, unsigned char* block, size_t size);
    static bool WriteBlock(const wxString& filename, unsigned char* block, size_t size);
protected:
    unsigned char*      m_data;
    size_t              m_dataSize;
    wxBitmapType        m_imageType;
};
WXGO_DECL_TYPECONV(RichTextImage)
class wxRichTextImage: public wxRichTextObject
{
public:
    wxRichTextImage(wxRichTextObject* parent = NULL): wxRichTextObject(parent) { }
    wxRichTextImage(const wxImage& image, wxRichTextObject* parent = NULL, wxRichTextAttr* charStyle = NULL);
    wxRichTextImage(const wxRichTextImageBlock& imageBlock, wxRichTextObject* parent = NULL, wxRichTextAttr* charStyle = NULL);
    wxRichTextImage(const wxRichTextImage& obj): wxRichTextObject(obj) { Copy(obj); }
    virtual bool Draw(wxDC& dc, wxRichTextDrawingContext& context, const wxRichTextRange& range, const wxRichTextSelection& selection, const wxRect& rect, int descent, int style);
    virtual bool Layout(wxDC& dc, wxRichTextDrawingContext& context, const wxRect& rect, const wxRect& parentRect, int style);
    virtual bool GetRangeSize(const wxRichTextRange& range, wxSize& size, int& descent, wxDC& dc, wxRichTextDrawingContext& context, int flags, const wxPoint& position = wxPoint(0,0), const wxSize& parentSize = wxDefaultSize, wxArrayInt* partialExtents = NULL) const;
    virtual wxTextAttrSize GetNaturalSize() const;
    virtual bool IsEmpty() const { return false;  }
    virtual bool CanEditProperties() const { return true; }
    virtual bool EditProperties(wxWindow* parent, wxRichTextBuffer* buffer);
    virtual wxString GetPropertiesMenuLabel() const { return _("&Picture"); }
    virtual bool UsesParagraphAttributes() const { return false; }
    virtual bool ImportFromXML(wxRichTextBuffer* buffer, wxXmlNode* node, wxRichTextXMLHandler* handler, bool* recurse);
#if wxRICHTEXT_HAVE_DIRECT_OUTPUT
    virtual bool ExportXML(wxOutputStream& stream, int indent, wxRichTextXMLHandler* handler);
#endif
#if wxRICHTEXT_HAVE_XMLDOCUMENT_OUTPUT
    virtual bool ExportXML(wxXmlNode* parent, wxRichTextXMLHandler* handler);
#endif
    virtual bool IsFloatable() const { return true; }
    virtual wxString GetXMLNodeName() const { return wxT("image"); }
    const wxBitmap& GetImageCache() const { return m_imageCache; }
    void SetImageCache(const wxBitmap& bitmap) { m_imageCache = bitmap; }
    void ResetImageCache() { m_imageCache = wxNullBitmap; }
    wxRichTextImageBlock& GetImageBlock() { return m_imageBlock; }
    wxSize GetOriginalImageSize() const;
    void SetOriginalImageSize(const wxSize& sz);
    void Copy(const wxRichTextImage& obj);
    virtual wxRichTextObject* Clone() const { return new wxRichTextImage(*this); }
    virtual bool LoadImageCache(wxDC& dc, wxRichTextDrawingContext& context, wxSize& retImageSize, bool resetCache = false, const wxSize& parentSize = wxDefaultSize);
    virtual bool LoadAndScaleImageCache(wxImage& image, const wxSize& sz, wxRichTextDrawingContext& context, bool& changed);
    int GetImageState() const { return m_imageState; }
    void SetImageState(int state) { m_imageState = state; }
protected:
    wxRichTextImageBlock    m_imageBlock;
    wxBitmap                m_imageCache;
    wxSize                  m_originalImageSize;
    int                     m_imageState;
};
class wxRichTextCommand;
class wxRichTextAction;
WXGO_DECL_TYPECONV(RichTextBuffer)
class wxRichTextBuffer: public wxRichTextParagraphLayoutBox
{
public:
    wxRichTextBuffer() { Init(); }
    wxRichTextBuffer(const wxRichTextBuffer& obj): wxRichTextParagraphLayoutBox() { Init(); Copy(obj); }
    virtual ~wxRichTextBuffer() ;
    wxCommandProcessor* GetCommandProcessor() const { return m_commandProcessor; }
    void SetStyleSheet(wxRichTextStyleSheet* styleSheet) { m_styleSheet = styleSheet; }
    virtual wxRichTextStyleSheet* GetStyleSheet() const { return m_styleSheet; }
    bool SetStyleSheetAndNotify(wxRichTextStyleSheet* sheet);
    bool PushStyleSheet(wxRichTextStyleSheet* styleSheet);
    wxRichTextStyleSheet* PopStyleSheet();
    wxRichTextFontTable& GetFontTable() { return m_fontTable; }
    void SetFontTable(const wxRichTextFontTable& table) { m_fontTable = table; }
    void SetFontScale(double fontScale);
    double GetFontScale() const { return m_fontScale; }
    void SetDimensionScale(double dimScale);
    double GetDimensionScale() const { return m_dimensionScale; }
    void Init();
    virtual void ResetAndClearCommands();
    virtual bool LoadFile(const wxString& filename, wxRichTextFileType type = wxRICHTEXT_TYPE_ANY);
    virtual bool LoadFile(wxInputStream& stream, wxRichTextFileType type = wxRICHTEXT_TYPE_ANY);
    virtual bool SaveFile(const wxString& filename, wxRichTextFileType type = wxRICHTEXT_TYPE_ANY);
    virtual bool SaveFile(wxOutputStream& stream, wxRichTextFileType type = wxRICHTEXT_TYPE_ANY);
    void SetHandlerFlags(int flags) { m_handlerFlags = flags; }
    int GetHandlerFlags() const { return m_handlerFlags; }
    virtual wxRichTextRange AddParagraph(const wxString& text, wxRichTextAttr* paraStyle = NULL) { Modify(); return wxRichTextParagraphLayoutBox::AddParagraph(text, paraStyle); }
    virtual bool BeginBatchUndo(const wxString& cmdName);
    virtual bool EndBatchUndo();
    virtual bool BatchingUndo() const { return m_batchedCommandDepth > 0; }
    virtual bool SubmitAction(wxRichTextAction* action);
    virtual wxRichTextCommand* GetBatchedCommand() const { return m_batchedCommand; }
    virtual bool BeginSuppressUndo();
    virtual bool EndSuppressUndo();
    virtual bool SuppressingUndo() const { return m_suppressUndo > 0; }
    virtual bool CopyToClipboard(const wxRichTextRange& range);
    virtual bool PasteFromClipboard(long position);
    virtual bool CanPasteFromClipboard() const;
    virtual bool BeginStyle(const wxRichTextAttr& style);
    virtual bool EndStyle();
    virtual bool EndAllStyles();
    virtual void ClearStyleStack();
    virtual size_t GetStyleStackSize() const { return m_attributeStack.GetCount(); }
    bool BeginBold();
    bool EndBold() { return EndStyle(); }
    bool BeginItalic();
    bool EndItalic() { return EndStyle(); }
    bool BeginUnderline();
    bool EndUnderline() { return EndStyle(); }
    bool BeginFontSize(int pointSize);
    bool EndFontSize() { return EndStyle(); }
    bool BeginFont(const wxFont& font);
    bool EndFont() { return EndStyle(); }
    bool BeginTextColour(const wxColour& colour);
    bool EndTextColour() { return EndStyle(); }
    bool BeginAlignment(wxTextAttrAlignment alignment);
    bool EndAlignment() { return EndStyle(); }
    bool BeginLeftIndent(int leftIndent, int leftSubIndent = 0);
    bool EndLeftIndent() { return EndStyle(); }
    bool BeginRightIndent(int rightIndent);
    bool EndRightIndent() { return EndStyle(); }
    bool BeginParagraphSpacing(int before, int after);
    bool EndParagraphSpacing() { return EndStyle(); }
    bool BeginLineSpacing(int lineSpacing);
    bool EndLineSpacing() { return EndStyle(); }
    bool BeginNumberedBullet(int bulletNumber, int leftIndent, int leftSubIndent, int bulletStyle = wxTEXT_ATTR_BULLET_STYLE_ARABIC|wxTEXT_ATTR_BULLET_STYLE_PERIOD);
    bool EndNumberedBullet() { return EndStyle(); }
    bool BeginSymbolBullet(const wxString& symbol, int leftIndent, int leftSubIndent, int bulletStyle = wxTEXT_ATTR_BULLET_STYLE_SYMBOL);
    bool EndSymbolBullet() { return EndStyle(); }
    bool BeginStandardBullet(const wxString& bulletName, int leftIndent, int leftSubIndent, int bulletStyle = wxTEXT_ATTR_BULLET_STYLE_STANDARD);
    bool EndStandardBullet() { return EndStyle(); }
    bool BeginCharacterStyle(const wxString& characterStyle);
    bool EndCharacterStyle() { return EndStyle(); }
    bool BeginParagraphStyle(const wxString& paragraphStyle);
    bool EndParagraphStyle() { return EndStyle(); }
    bool BeginListStyle(const wxString& listStyle, int level = 1, int number = 1);
    bool EndListStyle() { return EndStyle(); }
    bool BeginURL(const wxString& url, const wxString& characterStyle = wxEmptyString);
    bool EndURL() { return EndStyle(); }
    bool AddEventHandler(wxEvtHandler* handler);
    bool RemoveEventHandler(wxEvtHandler* handler, bool deleteHandler = false);
    void ClearEventHandlers();
    bool SendEvent(wxEvent& event, bool sendToAll = true);
    virtual int HitTest(wxDC& dc, wxRichTextDrawingContext& context, const wxPoint& pt, long& textPosition, wxRichTextObject** obj, wxRichTextObject** contextObj, int flags = 0);
    void Copy(const wxRichTextBuffer& obj);
    void operator= (const wxRichTextBuffer& obj) { Copy(obj); }
    virtual wxRichTextObject* Clone() const { return new wxRichTextBuffer(*this); }
    bool InsertParagraphsWithUndo(long pos, const wxRichTextParagraphLayoutBox& paragraphs, wxRichTextCtrl* ctrl, int flags = 0);
    bool InsertTextWithUndo(long pos, const wxString& text, wxRichTextCtrl* ctrl, int flags = 0);
    bool InsertNewlineWithUndo(long pos, wxRichTextCtrl* ctrl, int flags = 0);
    bool InsertImageWithUndo(long pos, const wxRichTextImageBlock& imageBlock, wxRichTextCtrl* ctrl, int flags = 0,
            const wxRichTextAttr& textAttr = wxRichTextAttr());
    wxRichTextObject* InsertObjectWithUndo(long pos, wxRichTextObject *object, wxRichTextCtrl* ctrl, int flags);
    bool DeleteRangeWithUndo(const wxRichTextRange& range, wxRichTextCtrl* ctrl);
    void Modify(bool modify = true) { m_modified = modify; }
    bool IsModified() const { return m_modified; }
    virtual void Dump();
    virtual void Dump(wxTextOutputStream& stream) { wxRichTextParagraphLayoutBox::Dump(stream); }
    static wxList& GetHandlers() { return sm_handlers; }
    static void AddHandler(wxRichTextFileHandler *handler);
    static void InsertHandler(wxRichTextFileHandler *handler);
    static bool RemoveHandler(const wxString& name);
    static wxRichTextFileHandler *FindHandler(const wxString& name);
    static wxRichTextFileHandler *FindHandler(const wxString& extension, wxRichTextFileType imageType);
    static wxRichTextFileHandler *FindHandlerFilenameOrType(const wxString& filename,
                                                            wxRichTextFileType imageType);
    static wxRichTextFileHandler *FindHandler(wxRichTextFileType imageType);
    static wxString GetExtWildcard(bool combine = false, bool save = false, wxArrayInt* types = NULL);
    static void CleanUpHandlers();
    static void InitStandardHandlers();
    static wxList& GetDrawingHandlers() { return sm_drawingHandlers; }
    static void AddDrawingHandler(wxRichTextDrawingHandler *handler);
    static void InsertDrawingHandler(wxRichTextDrawingHandler *handler);
    static bool RemoveDrawingHandler(const wxString& name);
    static wxRichTextDrawingHandler *FindDrawingHandler(const wxString& name);
    static void CleanUpDrawingHandlers();
    static wxRichTextFieldTypeHashMap& GetFieldTypes() { return sm_fieldTypes; }
    static void AddFieldType(wxRichTextFieldType *fieldType);
    static bool RemoveFieldType(const wxString& name);
    static wxRichTextFieldType *FindFieldType(const wxString& name);
    static void CleanUpFieldTypes();
    static wxRichTextRenderer* GetRenderer() { return sm_renderer; }
    static void SetRenderer(wxRichTextRenderer* renderer);
    static int GetBulletRightMargin() { return sm_bulletRightMargin; }
    static void SetBulletRightMargin(int margin) { sm_bulletRightMargin = margin; }
    static float GetBulletProportion() { return sm_bulletProportion; }
    static void SetBulletProportion(float prop) { sm_bulletProportion = prop; }
    double GetScale() const { return m_scale; }
    void SetScale(double scale) { m_scale = scale; }
    static bool GetFloatingLayoutMode();
    static void SetFloatingLayoutMode(bool mode);
protected:
    wxCommandProcessor*     m_commandProcessor;
    wxRichTextFontTable     m_fontTable;
    bool                    m_modified;
    int                     m_batchedCommandDepth;
    wxString                m_batchedCommandsName;
    wxRichTextCommand*      m_batchedCommand;
    int                     m_suppressUndo;
    wxRichTextStyleSheet*   m_styleSheet;
    wxList                  m_eventHandlers;
    wxList                  m_attributeStack;
    int                     m_handlerFlags;
    static wxList           sm_handlers;
    static wxList           sm_drawingHandlers;
    static wxRichTextFieldTypeHashMap sm_fieldTypes;
    static wxRichTextRenderer* sm_renderer;
    static int              sm_bulletRightMargin;
    static float            sm_bulletProportion;
    double                  m_scale;
};
WXGO_DECL_TYPECONV(RichTextCell)
class wxRichTextCell: public wxRichTextBox
{
public:
    wxRichTextCell(wxRichTextObject* parent = NULL);
    wxRichTextCell(const wxRichTextCell& obj): wxRichTextBox() { Copy(obj); }
    virtual bool Draw(wxDC& dc, wxRichTextDrawingContext& context, const wxRichTextRange& range, const wxRichTextSelection& selection, const wxRect& rect, int descent, int style);
    virtual int HitTest(wxDC& dc, wxRichTextDrawingContext& context, const wxPoint& pt, long& textPosition, wxRichTextObject** obj, wxRichTextObject** contextObj, int flags = 0);
    virtual wxString GetXMLNodeName() const { return wxT("cell"); }
    virtual bool CanEditProperties() const { return true; }
    virtual bool EditProperties(wxWindow* parent, wxRichTextBuffer* buffer);
    virtual wxString GetPropertiesMenuLabel() const { return _("&Cell"); }
    int GetColSpan() const;
    void SetColSpan(long span);
    int GetRowSpan() const;
    void SetRowSpan(long span);
    virtual wxRichTextObject* Clone() const { return new wxRichTextCell(*this); }
    void Copy(const wxRichTextCell& obj);
protected:
};
class wxRichTextObjectPtrArray;
class wxRichTextObjectPtrArrayArray;
WXGO_DECL_TYPECONV(RichTextTable)
class wxRichTextTable: public wxRichTextBox
{
public:
    wxRichTextTable(wxRichTextObject* parent = NULL);
    wxRichTextTable(const wxRichTextTable& obj): wxRichTextBox() { Copy(obj); }
    virtual bool Draw(wxDC& dc, wxRichTextDrawingContext& context, const wxRichTextRange& range, const wxRichTextSelection& selection, const wxRect& rect, int descent, int style);
    virtual int HitTest(wxDC& dc, wxRichTextDrawingContext& context, const wxPoint& pt, long& textPosition, wxRichTextObject** obj, wxRichTextObject** contextObj, int flags = 0);
    virtual wxString GetXMLNodeName() const { return wxT("table"); }
    virtual bool Layout(wxDC& dc, wxRichTextDrawingContext& context, const wxRect& rect, const wxRect& parentRect, int style);
    virtual bool GetRangeSize(const wxRichTextRange& range, wxSize& size, int& descent, wxDC& dc, wxRichTextDrawingContext& context, int flags, const wxPoint& position = wxPoint(0,0), const wxSize& parentSize = wxDefaultSize, wxArrayInt* partialExtents = NULL) const;
    virtual bool DeleteRange(const wxRichTextRange& range);
    virtual wxString GetTextForRange(const wxRichTextRange& range) const;
    virtual bool ImportFromXML(wxRichTextBuffer* buffer, wxXmlNode* node, wxRichTextXMLHandler* handler, bool* recurse);
#if wxRICHTEXT_HAVE_DIRECT_OUTPUT
    virtual bool ExportXML(wxOutputStream& stream, int indent, wxRichTextXMLHandler* handler);
#endif
#if wxRICHTEXT_HAVE_XMLDOCUMENT_OUTPUT
    virtual bool ExportXML(wxXmlNode* parent, wxRichTextXMLHandler* handler);
#endif
    virtual bool FindPosition(wxDC& dc, wxRichTextDrawingContext& context, long index, wxPoint& pt, int* height, bool forceLineStart);
    virtual void CalculateRange(long start, long& end);
    virtual bool HandlesChildSelections() const { return true; }
    virtual wxRichTextSelection GetSelection(long start, long end) const;
    virtual bool CanEditProperties() const { return true; }
    virtual bool EditProperties(wxWindow* parent, wxRichTextBuffer* buffer);
    virtual wxString GetPropertiesMenuLabel() const { return _("&Table"); }
    virtual bool AcceptsFocus() const { return false; }
    wxRichTextObjectPtrArrayArray& GetCells() { return m_cells; }
    int GetRowCount() const { return m_rowCount; }
    int GetColumnCount() const { return m_colCount; }
    virtual wxRichTextCell* GetCell(int row, int col) const;
    virtual wxRichTextCell* GetCell(long pos) const;
    virtual bool GetCellRowColumnPosition(long pos, int& row, int& col) const;
    virtual wxPosition GetFocusedCell() const;
    virtual void ClearTable();
    virtual bool CreateTable(int rows, int cols);
    virtual bool SetCellStyle(const wxRichTextSelection& selection, const wxRichTextAttr& style, int flags = wxRICHTEXT_SETSTYLE_WITH_UNDO);
    virtual bool DeleteRows(int startRow, int noRows = 1);
    virtual bool DeleteColumns(int startCol, int noCols = 1);
    virtual bool AddRows(int startRow, int noRows = 1, const wxRichTextAttr& attr = wxRichTextAttr());
    virtual bool AddColumns(int startCol, int noCols = 1, const wxRichTextAttr& attr = wxRichTextAttr());
    virtual wxRichTextObject* Clone() const { return new wxRichTextTable(*this); }
    void Copy(const wxRichTextTable& obj);
protected:
    int m_rowCount;
    int m_colCount;
    wxRichTextObjectPtrArrayArray   m_cells;
};
WXGO_DECL_TYPECONV(RichTextTableBlock)
class wxRichTextTableBlock
{
public:
    wxRichTextTableBlock() { Init(); }
    wxRichTextTableBlock(int colStart, int colEnd, int rowStart, int rowEnd)
    { Init(); m_colStart = colStart; m_colEnd = colEnd; m_rowStart = rowStart; m_rowEnd = rowEnd; }
    wxRichTextTableBlock(const wxRichTextTableBlock& block) { Copy(block); }
    void Init() { m_colStart = 0; m_colEnd = 0; m_rowStart = 0; m_rowEnd = 0; }
    void Copy(const wxRichTextTableBlock& block)
    {
        m_colStart = block.m_colStart; m_colEnd = block.m_colEnd; m_rowStart = block.m_rowStart; m_rowEnd = block.m_rowEnd;
    }
    void operator=(const wxRichTextTableBlock& block) { Copy(block); }
    bool operator==(const wxRichTextTableBlock& block)
    { return m_colStart == block.m_colStart && m_colEnd == block.m_colEnd && m_rowStart == block.m_rowStart && m_rowEnd == block.m_rowEnd; }
    bool ComputeBlockForSelection(wxRichTextTable* table, wxRichTextCtrl* ctrl, bool requireCellSelection = true);
    bool IsWholeTable(wxRichTextTable* table) const;
    static wxRichTextCell* GetFocusedCell(wxRichTextCtrl* ctrl);
    int ColStart() const { return m_colStart; }
    int ColEnd() const { return m_colEnd; }
    int RowStart() const { return m_rowStart; }
    int RowEnd() const { return m_rowEnd; }
    int m_colStart, m_colEnd, m_rowStart, m_rowEnd;
};
%typedef int wxRichTextCommandId;
#define wxRICHTEXT_INSERT 0
#define wxRICHTEXT_DELETE wxRICHTEXT_INSERT + 1
#define wxRICHTEXT_CHANGE_ATTRIBUTES wxRICHTEXT_DELETE + 1
#define wxRICHTEXT_CHANGE_STYLE wxRICHTEXT_CHANGE_ATTRIBUTES + 1
#define wxRICHTEXT_CHANGE_OBJECT wxRICHTEXT_CHANGE_STYLE + 1
WXGO_DECL_TYPECONV(RichTextObjectAddress)
class wxRichTextObjectAddress
{
public:
    wxRichTextObjectAddress(wxRichTextParagraphLayoutBox* topLevelContainer, wxRichTextObject* obj) { Create(topLevelContainer, obj); }
    wxRichTextObjectAddress() { Init(); }
    wxRichTextObjectAddress(const wxRichTextObjectAddress& address) { Copy(address); }
    void Init() {}
    void Copy(const wxRichTextObjectAddress& address) { m_address = address.m_address; }
    void operator=(const wxRichTextObjectAddress& address) { Copy(address); }
    wxRichTextObject* GetObject(wxRichTextParagraphLayoutBox* topLevelContainer) const;
    bool Create(wxRichTextParagraphLayoutBox* topLevelContainer, wxRichTextObject* obj);
    const wxArrayInt& GetAddress() const { return m_address; }
    void SetAddress(const wxArrayInt& address) { m_address = address; }
protected:
    wxArrayInt  m_address;
};
class wxRichTextAction;
WXGO_DECL_TYPECONV(RichTextCommand)
class wxRichTextCommand: public wxCommand
{
public:
    wxRichTextCommand(const wxString& name, wxRichTextCommandId id, wxRichTextBuffer* buffer,
        wxRichTextParagraphLayoutBox* container, wxRichTextCtrl* ctrl, bool ignoreFirstTime = false);
    wxRichTextCommand(const wxString& name);
    virtual ~wxRichTextCommand();
    bool Do();
    bool Undo();
    void AddAction(wxRichTextAction* action);
    void ClearActions();
    wxList& GetActions() { return m_actions; }
protected:
    wxList  m_actions;
};
WXGO_DECL_TYPECONV(RichTextAction)
class wxRichTextAction: public wxObject
{
public:
    wxRichTextAction(wxRichTextCommand* cmd, const wxString& name, wxRichTextCommandId id,
        wxRichTextBuffer* buffer, wxRichTextParagraphLayoutBox* container,
        wxRichTextCtrl* ctrl, bool ignoreFirstTime = false);
    virtual ~wxRichTextAction();
    bool Do();
    bool Undo();
    void UpdateAppearance(long caretPosition, bool sendUpdateEvent = false,
                          const wxRect& oldFloatRect = wxRect(),
                          wxArrayInt* optimizationLineCharPositions = NULL, wxArrayInt* optimizationLineYPositions = NULL,
                          bool isDoCmd = true);
    void ApplyParagraphs(const wxRichTextParagraphLayoutBox& fragment);
    wxRichTextParagraphLayoutBox& GetNewParagraphs() { return m_newParagraphs; }
    wxRichTextParagraphLayoutBox& GetOldParagraphs() { return m_oldParagraphs; }
    wxRichTextAttr& GetAttributes() { return m_attributes; }
    wxRichTextObject* GetObject() const { return m_object; }
    void StoreObject(wxRichTextObject* obj) { m_object = obj; }
    void SetObject(wxRichTextObject* obj) { m_object = obj; m_objectAddress.Create(m_buffer, m_object); }
    void MakeObject(wxRichTextObject* obj) { m_objectAddress.Create(m_buffer, obj); }
    void SetOldAndNewObjects(wxRichTextObject* oldObj, wxRichTextObject* newObj);
    void CalculateRefreshOptimizations(wxArrayInt& optimizationLineCharPositions, wxArrayInt& optimizationLineYPositions,
                                       wxRect& oldFloatRect);
    void SetPosition(long pos) { m_position = pos; }
    long GetPosition() const { return m_position; }
    void SetRange(const wxRichTextRange& range) { m_range = range; }
    const wxRichTextRange& GetRange() const { return m_range; }
    wxRichTextObjectAddress& GetContainerAddress() { return m_containerAddress; }
    void SetContainerAddress(const wxRichTextObjectAddress& address) { m_containerAddress = address; }
    void SetContainerAddress(wxRichTextParagraphLayoutBox* container, wxRichTextObject* obj) { m_containerAddress.Create(container, obj); }
    wxRichTextParagraphLayoutBox* GetContainer() const;
    const wxString& GetName() const { return m_name; }
    void SetIgnoreFirstTime(bool b);
    bool GetIgnoreFirstTime() const;
protected:
    wxString                        m_name;
    wxRichTextBuffer*               m_buffer;
    wxRichTextObjectAddress         m_containerAddress;
    wxRichTextCtrl*                 m_ctrl;
    wxRichTextParagraphLayoutBox    m_newParagraphs;
    wxRichTextParagraphLayoutBox    m_oldParagraphs;
    wxRichTextObject*               m_object;
    wxRichTextAttr                  m_attributes;
    wxRichTextObjectAddress         m_objectAddress;
    wxRichTextRange                 m_range;
    long                            m_position;
    bool                            m_ignoreThis;
    wxRichTextCommandId             m_cmdId;
};
#define wxRICHTEXT_HANDLER_INCLUDE_STYLESHEET       0x0001
#define wxRICHTEXT_HANDLER_SAVE_IMAGES_TO_MEMORY    0x0010
#define wxRICHTEXT_HANDLER_SAVE_IMAGES_TO_FILES     0x0020
#define wxRICHTEXT_HANDLER_SAVE_IMAGES_TO_BASE64    0x0040
#define wxRICHTEXT_HANDLER_NO_HEADER_FOOTER         0x0080
#define wxRICHTEXT_HANDLER_CONVERT_FACENAMES        0x0100
WXGO_DECL_TYPECONV(RichTextFileHandler)
class wxRichTextFileHandler: public wxObject
{
public:
    wxRichTextFileHandler(const wxString& name = wxEmptyString, const wxString& ext = wxEmptyString, int type = 0)
        : m_name(name), m_extension(ext), m_type(type), m_flags(0), m_visible(true)
        { }
    bool LoadFile(wxRichTextBuffer *buffer, wxInputStream& stream)
    { return DoLoadFile(buffer, stream); }
    bool SaveFile(wxRichTextBuffer *buffer, wxOutputStream& stream)
    { return DoSaveFile(buffer, stream); }
    virtual bool LoadFile(wxRichTextBuffer *buffer, const wxString& filename);
    virtual bool SaveFile(wxRichTextBuffer *buffer, const wxString& filename);
    virtual bool CanHandle(const wxString& filename) const;
    virtual bool CanSave() const { return false; }
    virtual bool CanLoad() const { return false; }
    virtual bool IsVisible() const { return m_visible; }
    virtual void SetVisible(bool visible) { m_visible = visible; }
    void SetName(const wxString& name) { m_name = name; }
    wxString GetName() const { return m_name; }
    void SetExtension(const wxString& ext) { m_extension = ext; }
    wxString GetExtension() const { return m_extension; }
    void SetType(int type) { m_type = type; }
    int GetType() const { return m_type; }
    void SetFlags(int flags) { m_flags = flags; }
    int GetFlags() const { return m_flags; }
    void SetEncoding(const wxString& encoding) { m_encoding = encoding; }
    const wxString& GetEncoding() const { return m_encoding; }
protected:
    virtual bool DoLoadFile(wxRichTextBuffer *buffer, wxInputStream& stream) = 0;
    virtual bool DoSaveFile(wxRichTextBuffer *buffer, wxOutputStream& stream) = 0;
    wxString  m_name;
    wxString  m_encoding;
    wxString  m_extension;
    int       m_type;
    int       m_flags;
    bool      m_visible;
};
WXGO_DECL_TYPECONV(RichTextPlainTextHandler)
class wxRichTextPlainTextHandler: public wxRichTextFileHandler
{
public:
    wxRichTextPlainTextHandler(const wxString& name = "Text",
                               const wxString& ext = "txt",
                               wxRichTextFileType type = wxRICHTEXT_TYPE_TEXT)
        : wxRichTextFileHandler(name, ext, type)
        { }
    virtual bool CanSave() const { return true; }
    virtual bool CanLoad() const { return true; }
protected:
    virtual bool DoLoadFile(wxRichTextBuffer *buffer, wxInputStream& stream);
    virtual bool DoSaveFile(wxRichTextBuffer *buffer, wxOutputStream& stream);
};
WXGO_DECL_TYPECONV(RichTextDrawingHandler)
class wxRichTextDrawingHandler: public wxObject
{
public:
    wxRichTextDrawingHandler(const wxString& name = wxEmptyString)
        : m_name(name)
        { }
    virtual bool HasVirtualAttributes(wxRichTextObject* obj) const = 0;
    virtual bool GetVirtualAttributes(wxRichTextAttr& attr, wxRichTextObject* obj) const = 0;
    virtual int GetVirtualSubobjectAttributesCount(wxRichTextObject* obj) const = 0;
    virtual int GetVirtualSubobjectAttributes(wxRichTextObject* obj, wxArrayInt& positions, wxRichTextAttrArray& attributes) const = 0;
    virtual bool HasVirtualText(const wxRichTextPlainText* obj) const = 0;
    virtual bool GetVirtualText(const wxRichTextPlainText* obj, wxString& text) const = 0;
    void SetName(const wxString& name) { m_name = name; }
    wxString GetName() const { return m_name; }
protected:
    wxString  m_name;
};
WXGO_DECL_TYPECONV(RichTextBufferDataObject)
class wxRichTextBufferDataObject: public wxDataObjectSimple
{
public:
    wxRichTextBufferDataObject(wxRichTextBuffer* richTextBuffer = NULL);
    virtual ~wxRichTextBufferDataObject();
    wxRichTextBuffer* GetRichTextBuffer();
    static const wxChar* GetRichTextBufferFormatId() { return ms_richTextBufferFormatId; }
    virtual wxDataFormat GetPreferredFormat(wxDataObjectBase::Direction dir) const;
    virtual size_t GetDataSize() const;
    virtual bool GetDataHere(void *pBuf) const;
    virtual bool SetData(size_t len, const void *buf);
    virtual size_t GetDataSize(const wxDataFormat&) const { return GetDataSize(); }
    virtual bool GetDataHere(const wxDataFormat&, void *buf) const { return GetDataHere(buf); }
    virtual bool SetData(const wxDataFormat&, size_t len, const void *buf) { return SetData(len, buf); }
private:
    wxDataFormat            m_formatRichTextBuffer;     
    wxRichTextBuffer*       m_richTextBuffer;           
    static const wxChar*    ms_richTextBufferFormatId;  
};
WXGO_DECL_TYPECONV(RichTextRenderer)
class wxRichTextRenderer: public wxObject
{
public:
    wxRichTextRenderer() {}
    virtual ~wxRichTextRenderer() {}
    virtual bool DrawStandardBullet(wxRichTextParagraph* paragraph, wxDC& dc, const wxRichTextAttr& attr, const wxRect& rect) = 0;
    virtual bool DrawTextBullet(wxRichTextParagraph* paragraph, wxDC& dc, const wxRichTextAttr& attr, const wxRect& rect, const wxString& text) = 0;
    virtual bool DrawBitmapBullet(wxRichTextParagraph* paragraph, wxDC& dc, const wxRichTextAttr& attr, const wxRect& rect) = 0;
    virtual bool EnumerateStandardBulletNames(wxArrayString& bulletNames) = 0;
    virtual bool MeasureBullet(wxRichTextParagraph* paragraph, wxDC& dc, const wxRichTextAttr& attr, wxSize& sz) = 0;
};
WXGO_DECL_TYPECONV(RichTextStdRenderer)
class wxRichTextStdRenderer: public wxRichTextRenderer
{
public:
    wxRichTextStdRenderer() {}
    virtual bool DrawStandardBullet(wxRichTextParagraph* paragraph, wxDC& dc, const wxRichTextAttr& attr, const wxRect& rect);
    virtual bool DrawTextBullet(wxRichTextParagraph* paragraph, wxDC& dc, const wxRichTextAttr& attr, const wxRect& rect, const wxString& text);
    virtual bool DrawBitmapBullet(wxRichTextParagraph* paragraph, wxDC& dc, const wxRichTextAttr& attr, const wxRect& rect);
    virtual bool EnumerateStandardBulletNames(wxArrayString& bulletNames);
    virtual bool MeasureBullet(wxRichTextParagraph* paragraph, wxDC& dc, const wxRichTextAttr& attr, wxSize& sz);
};
inline bool wxRichTextHasStyle(int flags, int style)
{
    return ((flags & style) == style);
}
bool wxTextAttrEq(const wxRichTextAttr& attr1, const wxRichTextAttr& attr2);
bool wxTextAttrEq(const wxRichTextAttr& attr1, const wxRichTextAttr& attr2);
bool wxRichTextApplyStyle(wxRichTextAttr& destStyle, const wxRichTextAttr& style, wxRichTextAttr* compareWith = NULL);
bool wxRichTextRemoveStyle(wxRichTextAttr& destStyle, const wxRichTextAttr& style);
bool wxRichTextCombineBitlists(int& valueA, int valueB, int& flagsA, int flagsB);
bool wxRichTextBitlistsEqPartial(int valueA, int valueB, int flags);
bool wxRichTextSplitParaCharStyles(const wxRichTextAttr& style, wxRichTextAttr& parStyle, wxRichTextAttr& charStyle);
bool wxRichTextTabsEq(const wxArrayInt& tabs1, const wxArrayInt& tabs2);
wxString wxRichTextDecimalToRoman(long n);
void wxTextAttrCollectCommonAttributes(wxTextAttr& currentStyle, const wxTextAttr& attr, wxTextAttr& clashingAttr, wxTextAttr& absentAttr);
void wxRichTextModuleInit();