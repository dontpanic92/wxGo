#define wxHTML_ALIGN_LEFT            0x0000
#define wxHTML_ALIGN_RIGHT           0x0002
#define wxHTML_ALIGN_JUSTIFY         0x0010
#define wxHTML_ALIGN_TOP             0x0004
#define wxHTML_ALIGN_BOTTOM          0x0008
#define wxHTML_ALIGN_CENTER          0x0001
#define wxHTML_CLR_FOREGROUND                0x0001
#define wxHTML_CLR_BACKGROUND                0x0002
#define wxHTML_CLR_TRANSPARENT_BACKGROUND    0x0004
#define wxHTML_UNITS_PIXELS          0x0001
#define wxHTML_UNITS_PERCENT         0x0002
#define wxHTML_INDENT_LEFT           0x0010
#define wxHTML_INDENT_RIGHT          0x0020
#define wxHTML_INDENT_TOP            0x0040
#define wxHTML_INDENT_BOTTOM         0x0080
#define wxHTML_INDENT_HORIZONTAL     (wxHTML_INDENT_LEFT | wxHTML_INDENT_RIGHT)
#define wxHTML_INDENT_VERTICAL       (wxHTML_INDENT_TOP | wxHTML_INDENT_BOTTOM)
#define wxHTML_INDENT_ALL            (wxHTML_INDENT_VERTICAL | wxHTML_INDENT_HORIZONTAL)
#define wxHTML_COND_ISANCHOR              1
#define wxHTML_COND_ISIMAGEMAP            2
#define wxHTML_COND_USER              10000