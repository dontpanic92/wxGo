//FIXME:Only wxGTK Fully Supported

#define wxNOT_FOUND       (-1)

typedef int wxCoord;
enum {  wxDefaultCoord = -1 };

enum wxGeometryCentre
{
    wxCENTRE                  = 0x0001,
    wxCENTER                  = wxCENTRE
};
#define wxCENTER_FRAME          0x0000
#define wxCENTRE_ON_SCREEN      0x0002
#define wxCENTER_ON_SCREEN      wxCENTRE_ON_SCREEN
enum wxOrientation
{
    wxHORIZONTAL              = 0x0004,
    wxVERTICAL                = 0x0008,
    wxBOTH                    = wxVERTICAL | wxHORIZONTAL,
    wxORIENTATION_MASK        = wxBOTH
};
enum wxDirection
{
    wxLEFT                    = 0x0010,
    wxRIGHT                   = 0x0020,
    wxUP                      = 0x0040,
    wxDOWN                    = 0x0080,
    wxTOP                     = wxUP,
    wxBOTTOM                  = wxDOWN,
    wxNORTH                   = wxUP,
    wxSOUTH                   = wxDOWN,
    wxWEST                    = wxLEFT,
    wxEAST                    = wxRIGHT,
    wxALL                     = (wxUP | wxDOWN | wxRIGHT | wxLEFT),
    wxDIRECTION_MASK           = wxALL
};
enum wxAlignment
{
    wxALIGN_INVALID           = -1,
    wxALIGN_NOT               = 0x0000,
    wxALIGN_CENTER_HORIZONTAL = 0x0100,
    wxALIGN_CENTRE_HORIZONTAL = wxALIGN_CENTER_HORIZONTAL,
    wxALIGN_LEFT              = wxALIGN_NOT,
    wxALIGN_TOP               = wxALIGN_NOT,
    wxALIGN_RIGHT             = 0x0200,
    wxALIGN_BOTTOM            = 0x0400,
    wxALIGN_CENTER_VERTICAL   = 0x0800,
    wxALIGN_CENTRE_VERTICAL   = wxALIGN_CENTER_VERTICAL,
    wxALIGN_CENTER            = (wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL),
    wxALIGN_CENTRE            = wxALIGN_CENTER,
    wxALIGN_MASK              = 0x0f00
};
enum wxSizerFlagBits
{
    wxFIXED_MINSIZE                = 0x8000,
    wxRESERVE_SPACE_EVEN_IF_HIDDEN = 0x0002,
    wxSIZER_FLAG_BITS_MASK         = 0x8002
};
enum wxStretch
{
    wxSTRETCH_NOT             = 0x0000,
    wxSHRINK                  = 0x1000,
    wxGROW                    = 0x2000,
    wxEXPAND                  = wxGROW,
    wxSHAPED                  = 0x4000,
    wxTILE                    = wxSHAPED | wxFIXED_MINSIZE,
    wxSTRETCH_MASK            = 0x7000 
};
enum wxBorder
{
    wxBORDER_DEFAULT = 0,
    wxBORDER_NONE   = 0x00200000,
    wxBORDER_STATIC = 0x01000000,
    wxBORDER_SIMPLE = 0x02000000,
    wxBORDER_RAISED = 0x04000000,
    wxBORDER_SUNKEN = 0x08000000,
    wxBORDER_DOUBLE = 0x10000000, 
    wxBORDER_THEME  = wxBORDER_DOUBLE,
    wxBORDER_MASK   = 0x1f200000
};

#define wxDEFAULT_CONTROL_BORDER    wxBORDER_SUNKEN
#define wxVSCROLL               0x80000000
#define wxHSCROLL               0x40000000
#define wxCAPTION               0x20000000
#define wxDOUBLE_BORDER         wxBORDER_DOUBLE
#define wxSUNKEN_BORDER         wxBORDER_SUNKEN
#define wxRAISED_BORDER         wxBORDER_RAISED
#define wxBORDER                wxBORDER_SIMPLE
#define wxSIMPLE_BORDER         wxBORDER_SIMPLE
#define wxSTATIC_BORDER         wxBORDER_STATIC
#define wxNO_BORDER             wxBORDER_NONE
#define wxALWAYS_SHOW_SB        0x00800000
#define wxCLIP_CHILDREN         0x00400000
#define wxCLIP_SIBLINGS         0x20000000
#define wxTRANSPARENT_WINDOW    0x00100000
#define wxTAB_TRAVERSAL         0x00080000
#define wxWANTS_CHARS           0x00040000

#define wxRETAINED              0x00000000

#define wxBACKINGSTORE          wxRETAINED
#define wxPOPUP_WINDOW          0x00020000
#define wxFULL_REPAINT_ON_RESIZE 0x00010000
#define wxNO_FULL_REPAINT_ON_RESIZE 0
//#define wxWINDOW_STYLE_MASK     \
//    (wxVSCROLL|wxHSCROLL|wxBORDER_MASK|wxALWAYS_SHOW_SB|wxCLIP_CHILDREN| \
//     wxCLIP_SIBLINGS|wxTRANSPARENT_WINDOW|wxTAB_TRAVERSAL|wxWANTS_CHARS| \
//     wxRETAINED|wxPOPUP_WINDOW|wxFULL_REPAINT_ON_RESIZE)
%constant wxWINDOW_STYLE_MASK = (wxVSCROLL|wxHSCROLL|wxBORDER_MASK|wxALWAYS_SHOW_SB|wxCLIP_CHILDREN| \
     wxCLIP_SIBLINGS|wxTRANSPARENT_WINDOW|wxTAB_TRAVERSAL|wxWANTS_CHARS| \
     wxRETAINED|wxPOPUP_WINDOW|wxFULL_REPAINT_ON_RESIZE);
#define wxWS_EX_VALIDATE_RECURSIVELY    0x00000001
#define wxWS_EX_BLOCK_EVENTS            0x00000002
#define wxWS_EX_TRANSIENT               0x00000004
#define wxWS_EX_THEMED_BACKGROUND       0x00000008
#define wxWS_EX_PROCESS_IDLE            0x00000010
#define wxWS_EX_PROCESS_UI_UPDATES      0x00000020
#define wxFRAME_EX_METAL                0x00000040
#define wxDIALOG_EX_METAL               0x00000040
#define wxWS_EX_CONTEXTHELP             0x00000080
#define wxFRAME_EX_CONTEXTHELP          wxWS_EX_CONTEXTHELP
#define wxDIALOG_EX_CONTEXTHELP         wxWS_EX_CONTEXTHELP
#define wxFRAME_DRAWER          0x0020
#define wxFRAME_NO_WINDOW_MENU  0x0100
#define wxMB_DOCKABLE       0x0001
#define wxMENU_TEAROFF      0x0001
#define wxCOLOURED          0x0800
#define wxFIXED_LENGTH      0x0400
#define wxLB_SORT           0x0010
#define wxLB_SINGLE         0x0020
#define wxLB_MULTIPLE       0x0040
#define wxLB_EXTENDED       0x0080
#define wxLB_NEEDED_SB      0x0000
#define wxLB_OWNERDRAW      0x0100
#define wxLB_ALWAYS_SB      0x0200
#define wxLB_NO_SB          0x0400
#define wxLB_HSCROLL        wxHSCROLL
#define wxLB_INT_HEIGHT     0x0800
#define wxCB_SIMPLE         0x0004
#define wxCB_SORT           0x0008
#define wxCB_READONLY       0x0010
#define wxCB_DROPDOWN       0x0020
#define wxRA_LEFTTORIGHT    0x0001
#define wxRA_TOPTOBOTTOM    0x0002
#define wxRA_SPECIFY_COLS   wxHORIZONTAL
#define wxRA_SPECIFY_ROWS   wxVERTICAL
#define wxRA_HORIZONTAL     wxHORIZONTAL
#define wxRA_VERTICAL       wxVERTICAL
#define wxRB_GROUP          0x0004
#define wxRB_SINGLE         0x0008
#define wxSB_HORIZONTAL      wxHORIZONTAL
#define wxSB_VERTICAL        wxVERTICAL
#define wxSP_HORIZONTAL       wxHORIZONTAL 
#define wxSP_VERTICAL         wxVERTICAL   
#define wxSP_ARROW_KEYS       0x4000
#define wxSP_WRAP             0x8000
#define wxTC_RIGHTJUSTIFY     0x0010
#define wxTC_FIXEDWIDTH       0x0020
#define wxTC_TOP              0x0000    
#define wxTC_LEFT             0x0020
#define wxTC_RIGHT            0x0040
#define wxTC_BOTTOM           0x0080
#define wxTC_MULTILINE        0x0200    
#define wxTC_OWNERDRAW        0x0400
#define wxBI_EXPAND           wxEXPAND
#define wxLI_HORIZONTAL         wxHORIZONTAL
#define wxLI_VERTICAL           wxVERTICAL
#define wxYES                   0x00000002
#define wxOK                    0x00000004
#define wxNO                    0x00000008
#define wxYES_NO                (wxYES | wxNO)
#define wxCANCEL                0x00000010
#define wxAPPLY                 0x00000020
#define wxCLOSE                 0x00000040
#define wxOK_DEFAULT            0x00000000  
#define wxYES_DEFAULT           0x00000000  
#define wxNO_DEFAULT            0x00000080  
#define wxCANCEL_DEFAULT        0x80000000  
#define wxICON_EXCLAMATION      0x00000100
#define wxICON_HAND             0x00000200
#define wxICON_WARNING          wxICON_EXCLAMATION
#define wxICON_ERROR            wxICON_HAND
#define wxICON_QUESTION         0x00000400
#define wxICON_INFORMATION      0x00000800
#define wxICON_STOP             wxICON_HAND
#define wxICON_ASTERISK         wxICON_INFORMATION
#define wxHELP                  0x00001000
#define wxFORWARD               0x00002000
#define wxBACKWARD              0x00004000
#define wxRESET                 0x00008000
#define wxMORE                  0x00010000
#define wxSETUP                 0x00020000
#define wxICON_NONE             0x00040000
#define wxICON_AUTH_NEEDED      0x00080000
//#define wxICON_MASK \
//    (wxICON_EXCLAMATION|wxICON_HAND|wxICON_QUESTION|wxICON_INFORMATION|wxICON_NONE|wxICON_AUTH_NEEDED)
%constant wxICON_MASK = (wxICON_EXCLAMATION|wxICON_HAND|wxICON_QUESTION|wxICON_INFORMATION|wxICON_NONE|wxICON_AUTH_NEEDED);
enum wxBackgroundStyle
{
    wxBG_STYLE_ERASE,
    wxBG_STYLE_SYSTEM,
    wxBG_STYLE_PAINT,
    wxBG_STYLE_TRANSPARENT,
    wxBG_STYLE_COLOUR,
    wxBG_STYLE_CUSTOM = wxBG_STYLE_PAINT
};
enum wxKeyType
{
    wxKEY_NONE,
    wxKEY_INTEGER,
    wxKEY_STRING
};
enum wxStandardID
{
#if defined(__WXMSW__) || wxUSE_AUTOID_MANAGEMENT
    wxID_AUTO_LOWEST = -32000,
    wxID_AUTO_HIGHEST = -2000,
#else
    wxID_AUTO_LOWEST = -1000000,
    wxID_AUTO_HIGHEST = -2000,
#endif
    wxID_NONE = -3,
    wxID_SEPARATOR = -2,
    wxID_ANY = -1,
    wxID_LOWEST = 4999,
    wxID_OPEN,
    wxID_CLOSE,
    wxID_NEW,
    wxID_SAVE,
    wxID_SAVEAS,
    wxID_REVERT,
    wxID_EXIT,
    wxID_UNDO,
    wxID_REDO,
    wxID_HELP,
    wxID_PRINT,
    wxID_PRINT_SETUP,
    wxID_PAGE_SETUP,
    wxID_PREVIEW,
    wxID_ABOUT,
    wxID_HELP_CONTENTS,
    wxID_HELP_INDEX,
    wxID_HELP_SEARCH,
    wxID_HELP_COMMANDS,
    wxID_HELP_PROCEDURES,
    wxID_HELP_CONTEXT,
    wxID_CLOSE_ALL,
    wxID_PREFERENCES,
    wxID_EDIT = 5030,
    wxID_CUT,
    wxID_COPY,
    wxID_PASTE,
    wxID_CLEAR,
    wxID_FIND,
    wxID_DUPLICATE,
    wxID_SELECTALL,
    wxID_DELETE,
    wxID_REPLACE,
    wxID_REPLACE_ALL,
    wxID_PROPERTIES,
    wxID_VIEW_DETAILS,
    wxID_VIEW_LARGEICONS,
    wxID_VIEW_SMALLICONS,
    wxID_VIEW_LIST,
    wxID_VIEW_SORTDATE,
    wxID_VIEW_SORTNAME,
    wxID_VIEW_SORTSIZE,
    wxID_VIEW_SORTTYPE,
    wxID_FILE = 5050,
    wxID_FILE1,
    wxID_FILE2,
    wxID_FILE3,
    wxID_FILE4,
    wxID_FILE5,
    wxID_FILE6,
    wxID_FILE7,
    wxID_FILE8,
    wxID_FILE9,
    wxID_OK = 5100,
    wxID_CANCEL,
    wxID_APPLY,
    wxID_YES,
    wxID_NO,
    wxID_STATIC,
    wxID_FORWARD,
    wxID_BACKWARD,
    wxID_DEFAULT,
    wxID_MORE,
    wxID_SETUP,
    wxID_RESET,
    wxID_CONTEXT_HELP,
    wxID_YESTOALL,
    wxID_NOTOALL,
    wxID_ABORT,
    wxID_RETRY,
    wxID_IGNORE,
    wxID_ADD,
    wxID_REMOVE,
    wxID_UP,
    wxID_DOWN,
    wxID_HOME,
    wxID_REFRESH,
    wxID_STOP,
    wxID_INDEX,
    wxID_BOLD,
    wxID_ITALIC,
    wxID_JUSTIFY_CENTER,
    wxID_JUSTIFY_FILL,
    wxID_JUSTIFY_RIGHT,
    wxID_JUSTIFY_LEFT,
    wxID_UNDERLINE,
    wxID_INDENT,
    wxID_UNINDENT,
    wxID_ZOOM_100,
    wxID_ZOOM_FIT,
    wxID_ZOOM_IN,
    wxID_ZOOM_OUT,
    wxID_UNDELETE,
    wxID_REVERT_TO_SAVED,
    wxID_CDROM,
    wxID_CONVERT,
    wxID_EXECUTE,
    wxID_FLOPPY,
    wxID_HARDDISK,
    wxID_BOTTOM,
    wxID_FIRST,
    wxID_LAST,
    wxID_TOP,
    wxID_INFO,
    wxID_JUMP_TO,
    wxID_NETWORK,
    wxID_SELECT_COLOR,
    wxID_SELECT_FONT,
    wxID_SORT_ASCENDING,
    wxID_SORT_DESCENDING,
    wxID_SPELL_CHECK,
    wxID_STRIKETHROUGH,
    wxID_SYSTEM_MENU = 5200,
    wxID_CLOSE_FRAME,
    wxID_MOVE_FRAME,
    wxID_RESIZE_FRAME,
    wxID_MAXIMIZE_FRAME,
    wxID_ICONIZE_FRAME,
    wxID_RESTORE_FRAME,
    wxID_MDI_WINDOW_FIRST = 5230,
    wxID_MDI_WINDOW_CASCADE = wxID_MDI_WINDOW_FIRST,
    wxID_MDI_WINDOW_TILE_HORZ,
    wxID_MDI_WINDOW_TILE_VERT,
    wxID_MDI_WINDOW_ARRANGE_ICONS,
    wxID_MDI_WINDOW_PREV,
    wxID_MDI_WINDOW_NEXT,
    wxID_MDI_WINDOW_LAST = wxID_MDI_WINDOW_NEXT,
    wxID_OSX_MENU_FIRST = 5250,
    wxID_OSX_HIDE = wxID_OSX_MENU_FIRST,
    wxID_OSX_HIDEOTHERS,
    wxID_OSX_SHOWALL,
    wxID_OSX_MENU_LAST = wxID_OSX_SHOWALL,
    wxID_FILEDLGG = 5900,
    wxID_FILECTRL = 5950,
    wxID_HIGHEST = 5999
};
enum wxItemKind
{
    wxITEM_SEPARATOR = -1,
    wxITEM_NORMAL,
    wxITEM_CHECK,
    wxITEM_RADIO,
    wxITEM_DROPDOWN,
    wxITEM_MAX
};
enum wxCheckBoxState
{
    wxCHK_UNCHECKED,
    wxCHK_CHECKED,
    wxCHK_UNDETERMINED 
};
enum wxHitTest
{
    wxHT_NOWHERE,
    wxHT_SCROLLBAR_FIRST = wxHT_NOWHERE,
    wxHT_SCROLLBAR_ARROW_LINE_1,    
    wxHT_SCROLLBAR_ARROW_LINE_2,    
    wxHT_SCROLLBAR_ARROW_PAGE_1,    
    wxHT_SCROLLBAR_ARROW_PAGE_2,    
    wxHT_SCROLLBAR_THUMB,           
    wxHT_SCROLLBAR_BAR_1,           
    wxHT_SCROLLBAR_BAR_2,           
    wxHT_SCROLLBAR_LAST,
    wxHT_WINDOW_OUTSIDE,            
    wxHT_WINDOW_INSIDE,             
    wxHT_WINDOW_VERT_SCROLLBAR,     
    wxHT_WINDOW_HORZ_SCROLLBAR,     
    wxHT_WINDOW_CORNER,             
    wxHT_MAX
};
#define wxSIZE_AUTO_WIDTH       0x0001
#define wxSIZE_AUTO_HEIGHT      0x0002
#define wxSIZE_AUTO             (wxSIZE_AUTO_WIDTH|wxSIZE_AUTO_HEIGHT)
#define wxSIZE_USE_EXISTING     0x0000
#define wxSIZE_ALLOW_MINUS_ONE  0x0004
#define wxSIZE_NO_ADJUSTMENTS   0x0008
#define wxSIZE_FORCE            0x0010
#define wxSIZE_FORCE_EVENT      0x0020
enum wxHatchStyle
{
    wxHATCHSTYLE_INVALID = -1,
    wxHATCHSTYLE_FIRST = 111,
    wxHATCHSTYLE_BDIAGONAL = wxHATCHSTYLE_FIRST,
    wxHATCHSTYLE_CROSSDIAG,
    wxHATCHSTYLE_FDIAGONAL,
    wxHATCHSTYLE_CROSS,
    wxHATCHSTYLE_HORIZONTAL,
    wxHATCHSTYLE_VERTICAL,
    wxHATCHSTYLE_LAST = wxHATCHSTYLE_VERTICAL
};
#if FUTURE_WXWIN_COMPATIBILITY_3_0
enum wxDeprecatedGUIConstants
{
    wxDEFAULT    = 70,
    wxDECORATIVE,
    wxROMAN,
    wxSCRIPT,
    wxSWISS,
    wxMODERN,
    wxTELETYPE,  
    wxVARIABLE   = 80,
    wxFIXED,
    wxNORMAL     = 90,
    wxLIGHT,
    wxBOLD,
    wxITALIC,
    wxSLANT,
    wxSOLID      =   100,
    wxDOT,
    wxLONG_DASH,
    wxSHORT_DASH,
    wxDOT_DASH,
    wxUSER_DASH,
    wxTRANSPARENT,
    wxSTIPPLE_MASK_OPAQUE, 
    wxSTIPPLE_MASK,        
    wxSTIPPLE =          110,
    wxBDIAGONAL_HATCH = wxHATCHSTYLE_BDIAGONAL,
    wxCROSSDIAG_HATCH = wxHATCHSTYLE_CROSSDIAG,
    wxFDIAGONAL_HATCH = wxHATCHSTYLE_FDIAGONAL,
    wxCROSS_HATCH = wxHATCHSTYLE_CROSS,
    wxHORIZONTAL_HATCH = wxHATCHSTYLE_HORIZONTAL,
    wxVERTICAL_HATCH = wxHATCHSTYLE_VERTICAL,
    wxFIRST_HATCH = wxHATCHSTYLE_FIRST,
    wxLAST_HATCH = wxHATCHSTYLE_LAST
};
#endif
enum
{
    wxTOOL_TOP = 1,
    wxTOOL_BOTTOM,
    wxTOOL_LEFT,
    wxTOOL_RIGHT
};
enum wxDataFormatId
{
    wxDF_INVALID =          0,
    wxDF_TEXT =             1,  
    wxDF_BITMAP =           2,  
    wxDF_METAFILE =         3,  
    wxDF_SYLK =             4,
    wxDF_DIF =              5,
    wxDF_TIFF =             6,
    wxDF_OEMTEXT =          7,  
    wxDF_DIB =              8,  
    wxDF_PALETTE =          9,
    wxDF_PENDATA =          10,
    wxDF_RIFF =             11,
    wxDF_WAVE =             12,
    wxDF_UNICODETEXT =      13,
    wxDF_ENHMETAFILE =      14,
    wxDF_FILENAME =         15, 
    wxDF_LOCALE =           16,
    wxDF_PRIVATE =          20,
    wxDF_HTML =             30, 
    wxDF_MAX
};
enum wxKeyCode
{
    WXK_NONE    =    0,
    WXK_CONTROL_A = 1,
    WXK_CONTROL_B,
    WXK_CONTROL_C,
    WXK_CONTROL_D,
    WXK_CONTROL_E,
    WXK_CONTROL_F,
    WXK_CONTROL_G,
    WXK_CONTROL_H,
    WXK_CONTROL_I,
    WXK_CONTROL_J,
    WXK_CONTROL_K,
    WXK_CONTROL_L,
    WXK_CONTROL_M,
    WXK_CONTROL_N,
    WXK_CONTROL_O,
    WXK_CONTROL_P,
    WXK_CONTROL_Q,
    WXK_CONTROL_R,
    WXK_CONTROL_S,
    WXK_CONTROL_T,
    WXK_CONTROL_U,
    WXK_CONTROL_V,
    WXK_CONTROL_W,
    WXK_CONTROL_X,
    WXK_CONTROL_Y,
    WXK_CONTROL_Z,
    WXK_BACK    =    8, 
    WXK_TAB     =    9,
    WXK_RETURN  =    13,
    WXK_ESCAPE  =    27,
    WXK_SPACE   =    32,
    WXK_DELETE  =    127,
    WXK_START   = 300,
    WXK_LBUTTON,
    WXK_RBUTTON,
    WXK_CANCEL,
    WXK_MBUTTON,
    WXK_CLEAR,
    WXK_SHIFT,
    WXK_ALT,
    WXK_CONTROL,
    WXK_MENU,
    WXK_PAUSE,
    WXK_CAPITAL,
    WXK_END,
    WXK_HOME,
    WXK_LEFT,
    WXK_UP,
    WXK_RIGHT,
    WXK_DOWN,
    WXK_SELECT,
    WXK_PRINT,
    WXK_EXECUTE,
    WXK_SNAPSHOT,
    WXK_INSERT,
    WXK_HELP,
    WXK_NUMPAD0,
    WXK_NUMPAD1,
    WXK_NUMPAD2,
    WXK_NUMPAD3,
    WXK_NUMPAD4,
    WXK_NUMPAD5,
    WXK_NUMPAD6,
    WXK_NUMPAD7,
    WXK_NUMPAD8,
    WXK_NUMPAD9,
    WXK_MULTIPLY,
    WXK_ADD,
    WXK_SEPARATOR,
    WXK_SUBTRACT,
    WXK_DECIMAL,
    WXK_DIVIDE,
    WXK_F1,
    WXK_F2,
    WXK_F3,
    WXK_F4,
    WXK_F5,
    WXK_F6,
    WXK_F7,
    WXK_F8,
    WXK_F9,
    WXK_F10,
    WXK_F11,
    WXK_F12,
    WXK_F13,
    WXK_F14,
    WXK_F15,
    WXK_F16,
    WXK_F17,
    WXK_F18,
    WXK_F19,
    WXK_F20,
    WXK_F21,
    WXK_F22,
    WXK_F23,
    WXK_F24,
    WXK_NUMLOCK,
    WXK_SCROLL,
    WXK_PAGEUP,
    WXK_PAGEDOWN,
    WXK_NUMPAD_SPACE,
    WXK_NUMPAD_TAB,
    WXK_NUMPAD_ENTER,
    WXK_NUMPAD_F1,
    WXK_NUMPAD_F2,
    WXK_NUMPAD_F3,
    WXK_NUMPAD_F4,
    WXK_NUMPAD_HOME,
    WXK_NUMPAD_LEFT,
    WXK_NUMPAD_UP,
    WXK_NUMPAD_RIGHT,
    WXK_NUMPAD_DOWN,
    WXK_NUMPAD_PAGEUP,
    WXK_NUMPAD_PAGEDOWN,
    WXK_NUMPAD_END,
    WXK_NUMPAD_BEGIN,
    WXK_NUMPAD_INSERT,
    WXK_NUMPAD_DELETE,
    WXK_NUMPAD_EQUAL,
    WXK_NUMPAD_MULTIPLY,
    WXK_NUMPAD_ADD,
    WXK_NUMPAD_SEPARATOR,
    WXK_NUMPAD_SUBTRACT,
    WXK_NUMPAD_DECIMAL,
    WXK_NUMPAD_DIVIDE,
    WXK_WINDOWS_LEFT,
    WXK_WINDOWS_RIGHT,
    WXK_WINDOWS_MENU ,
#ifdef __WXOSX__
    WXK_RAW_CONTROL,
#else
    WXK_RAW_CONTROL = WXK_CONTROL,
#endif
    WXK_COMMAND = WXK_CONTROL,
    WXK_SPECIAL1 = 193,
    WXK_SPECIAL2,
    WXK_SPECIAL3,
    WXK_SPECIAL4,
    WXK_SPECIAL5,
    WXK_SPECIAL6,
    WXK_SPECIAL7,
    WXK_SPECIAL8,
    WXK_SPECIAL9,
    WXK_SPECIAL10,
    WXK_SPECIAL11,
    WXK_SPECIAL12,
    WXK_SPECIAL13,
    WXK_SPECIAL14,
    WXK_SPECIAL15,
    WXK_SPECIAL16,
    WXK_SPECIAL17,
    WXK_SPECIAL18,
    WXK_SPECIAL19,
    WXK_SPECIAL20
};
enum wxKeyModifier
{
    wxMOD_NONE      = 0x0000,
    wxMOD_ALT       = 0x0001,
    wxMOD_CONTROL   = 0x0002,
    wxMOD_ALTGR     = wxMOD_ALT | wxMOD_CONTROL,
    wxMOD_SHIFT     = 0x0004,
    wxMOD_META      = 0x0008,
    wxMOD_WIN       = wxMOD_META,
#if defined(__WXMAC__) || defined(__WXCOCOA__)
    wxMOD_RAW_CONTROL = 0x0010,
#else
    wxMOD_RAW_CONTROL = wxMOD_CONTROL,
#endif
    wxMOD_CMD       = wxMOD_CONTROL,
    wxMOD_ALL       = 0xffff
};
typedef enum
{
    wxPAPER_NONE,               
    wxPAPER_LETTER,             
    wxPAPER_LEGAL,              
    wxPAPER_A4,                 
    wxPAPER_CSHEET,             
    wxPAPER_DSHEET,             
    wxPAPER_ESHEET,             
    wxPAPER_LETTERSMALL,        
    wxPAPER_TABLOID,            
    wxPAPER_LEDGER,             
    wxPAPER_STATEMENT,          
    wxPAPER_EXECUTIVE,          
    wxPAPER_A3,                 
    wxPAPER_A4SMALL,            
    wxPAPER_A5,                 
    wxPAPER_B4,                 
    wxPAPER_B5,                 
    wxPAPER_FOLIO,              
    wxPAPER_QUARTO,             
    wxPAPER_10X14,              
    wxPAPER_11X17,              
    wxPAPER_NOTE,               
    wxPAPER_ENV_9,              
    wxPAPER_ENV_10,             
    wxPAPER_ENV_11,             
    wxPAPER_ENV_12,             
    wxPAPER_ENV_14,             
    wxPAPER_ENV_DL,             
    wxPAPER_ENV_C5,             
    wxPAPER_ENV_C3,             
    wxPAPER_ENV_C4,             
    wxPAPER_ENV_C6,             
    wxPAPER_ENV_C65,            
    wxPAPER_ENV_B4,             
    wxPAPER_ENV_B5,             
    wxPAPER_ENV_B6,             
    wxPAPER_ENV_ITALY,          
    wxPAPER_ENV_MONARCH,        
    wxPAPER_ENV_PERSONAL,       
    wxPAPER_FANFOLD_US,         
    wxPAPER_FANFOLD_STD_GERMAN, 
    wxPAPER_FANFOLD_LGL_GERMAN, 
    wxPAPER_ISO_B4,             
    wxPAPER_JAPANESE_POSTCARD,  
    wxPAPER_9X11,               
    wxPAPER_10X11,              
    wxPAPER_15X11,              
    wxPAPER_ENV_INVITE,         
    wxPAPER_LETTER_EXTRA,       
    wxPAPER_LEGAL_EXTRA,        
    wxPAPER_TABLOID_EXTRA,      
    wxPAPER_A4_EXTRA,           
    wxPAPER_LETTER_TRANSVERSE,  
    wxPAPER_A4_TRANSVERSE,      
    wxPAPER_LETTER_EXTRA_TRANSVERSE, 
    wxPAPER_A_PLUS,             
    wxPAPER_B_PLUS,             
    wxPAPER_LETTER_PLUS,        
    wxPAPER_A4_PLUS,            
    wxPAPER_A5_TRANSVERSE,      
    wxPAPER_B5_TRANSVERSE,      
    wxPAPER_A3_EXTRA,           
    wxPAPER_A5_EXTRA,           
    wxPAPER_B5_EXTRA,           
    wxPAPER_A2,                 
    wxPAPER_A3_TRANSVERSE,      
    wxPAPER_A3_EXTRA_TRANSVERSE, 
    wxPAPER_DBL_JAPANESE_POSTCARD,
    wxPAPER_A6,                 
    wxPAPER_JENV_KAKU2,         
    wxPAPER_JENV_KAKU3,         
    wxPAPER_JENV_CHOU3,         
    wxPAPER_JENV_CHOU4,         
    wxPAPER_LETTER_ROTATED,     
    wxPAPER_A3_ROTATED,         
    wxPAPER_A4_ROTATED,         
    wxPAPER_A5_ROTATED,         
    wxPAPER_B4_JIS_ROTATED,     
    wxPAPER_B5_JIS_ROTATED,     
    wxPAPER_JAPANESE_POSTCARD_ROTATED,
    wxPAPER_DBL_JAPANESE_POSTCARD_ROTATED,
    wxPAPER_A6_ROTATED,         
    wxPAPER_JENV_KAKU2_ROTATED, 
    wxPAPER_JENV_KAKU3_ROTATED, 
    wxPAPER_JENV_CHOU3_ROTATED, 
    wxPAPER_JENV_CHOU4_ROTATED, 
    wxPAPER_B6_JIS,             
    wxPAPER_B6_JIS_ROTATED,     
    wxPAPER_12X11,              
    wxPAPER_JENV_YOU4,          
    wxPAPER_JENV_YOU4_ROTATED,  
    wxPAPER_P16K,               
    wxPAPER_P32K,               
    wxPAPER_P32KBIG,            
    wxPAPER_PENV_1,             
    wxPAPER_PENV_2,             
    wxPAPER_PENV_3,             
    wxPAPER_PENV_4,             
    wxPAPER_PENV_5,             
    wxPAPER_PENV_6,             
    wxPAPER_PENV_7,             
    wxPAPER_PENV_8,             
    wxPAPER_PENV_9,             
    wxPAPER_PENV_10,            
    wxPAPER_P16K_ROTATED,       
    wxPAPER_P32K_ROTATED,       
    wxPAPER_P32KBIG_ROTATED,    
    wxPAPER_PENV_1_ROTATED,     
    wxPAPER_PENV_2_ROTATED,     
    wxPAPER_PENV_3_ROTATED,     
    wxPAPER_PENV_4_ROTATED,     
    wxPAPER_PENV_5_ROTATED,     
    wxPAPER_PENV_6_ROTATED,     
    wxPAPER_PENV_7_ROTATED,     
    wxPAPER_PENV_8_ROTATED,     
    wxPAPER_PENV_9_ROTATED,     
    wxPAPER_PENV_10_ROTATED,    
    wxPAPER_A0,                 
    wxPAPER_A1                  
} wxPaperSize;
enum wxPrintOrientation
{
   wxPORTRAIT = 1,
   wxLANDSCAPE
};
enum wxDuplexMode
{
    wxDUPLEX_SIMPLEX, 
    wxDUPLEX_HORIZONTAL,
    wxDUPLEX_VERTICAL
};
#define wxPRINT_QUALITY_HIGH    -1
#define wxPRINT_QUALITY_MEDIUM  -2
#define wxPRINT_QUALITY_LOW     -3
#define wxPRINT_QUALITY_DRAFT   -4
typedef int wxPrintQuality;
enum wxPrintMode
{
    wxPRINT_MODE_NONE =    0,
    wxPRINT_MODE_PREVIEW = 1,   
    wxPRINT_MODE_FILE =    2,   
    wxPRINT_MODE_PRINTER = 3,   
    wxPRINT_MODE_STREAM =  4    
};
enum wxUpdateUI
{
    wxUPDATE_UI_NONE          = 0x0000,
    wxUPDATE_UI_RECURSE       = 0x0001,
    wxUPDATE_UI_FROMIDLE      = 0x0002 
};

typedef unsigned long COLORREF;
#define GetRValue(rgb) ((unsigned char)((rgb) >> 16))
#define GetGValue(rgb) ((unsigned char)(((unsigned short)(rgb)) >> 8))
#define GetBValue(rgb) ((unsigned char)(rgb))

#ifdef __WXGTK__
typedef struct _GSList GSList;
typedef struct _GdkColor        GdkColor;
typedef struct _GdkCursor       GdkCursor;
typedef struct _GdkDragContext  GdkDragContext;
#if defined(__WXGTK20__)
    typedef struct _GdkAtom* GdkAtom;
#else
    typedef unsigned long GdkAtom;
#endif
#if !defined(__WXGTK3__)
    typedef struct _GdkColormap GdkColormap;
    typedef struct _GdkFont GdkFont;
    typedef struct _GdkGC GdkGC;
    typedef struct _GdkRegion GdkRegion;
#endif
#if defined(__WXGTK3__)
    typedef struct _GdkWindow GdkWindow;
#elif defined(__WXGTK20__)
    typedef struct _GdkDrawable GdkWindow;
    typedef struct _GdkDrawable GdkPixmap;
#else
    typedef struct _GdkWindow GdkWindow;
    typedef struct _GdkWindow GdkBitmap;
    typedef struct _GdkWindow GdkPixmap;
#endif
typedef struct _GtkWidget         GtkWidget;
typedef struct _GtkRcStyle        GtkRcStyle;
typedef struct _GtkAdjustment     GtkAdjustment;
typedef struct _GtkToolbar        GtkToolbar;
typedef struct _GtkNotebook       GtkNotebook;
typedef struct _GtkNotebookPage   GtkNotebookPage;
typedef struct _GtkAccelGroup     GtkAccelGroup;
typedef struct _GtkSelectionData  GtkSelectionData;
typedef struct _GtkTextBuffer     GtkTextBuffer;
typedef struct _GtkRange          GtkRange;
typedef struct _GtkCellRenderer   GtkCellRenderer;
typedef GtkWidget *WXWidget;
#endif
typedef struct _PangoContext         PangoContext;
typedef struct _PangoLayout          PangoLayout;
typedef struct _PangoFontDescription PangoFontDescription;

enum
{
    wxPRIORITY_MIN     = 0u,   
    wxPRIORITY_DEFAULT = 50u,  
    wxPRIORITY_MAX     = 100u  
};

