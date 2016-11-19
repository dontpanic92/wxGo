%typedef int wxAuiPaneDockArtSetting;
#define wxAUI_DOCKART_SASH_SIZE  0
#define wxAUI_DOCKART_CAPTION_SIZE  1
#define wxAUI_DOCKART_GRIPPER_SIZE  2
#define wxAUI_DOCKART_PANE_BORDER_SIZE  3
#define wxAUI_DOCKART_PANE_BUTTON_SIZE  4
#define wxAUI_DOCKART_BACKGROUND_COLOUR  5
#define wxAUI_DOCKART_SASH_COLOUR  6
#define wxAUI_DOCKART_ACTIVE_CAPTION_COLOUR  7
#define wxAUI_DOCKART_ACTIVE_CAPTION_GRADIENT_COLOUR  8
#define wxAUI_DOCKART_INACTIVE_CAPTION_COLOUR  9
#define wxAUI_DOCKART_INACTIVE_CAPTION_GRADIENT_COLOUR  10
#define wxAUI_DOCKART_ACTIVE_CAPTION_TEXT_COLOUR  11
#define wxAUI_DOCKART_INACTIVE_CAPTION_TEXT_COLOUR  12
#define wxAUI_DOCKART_BORDER_COLOUR  13
#define wxAUI_DOCKART_GRIPPER_COLOUR  14
#define wxAUI_DOCKART_CAPTION_FONT  15
#define wxAUI_DOCKART_GRADIENT_TYPE  16
%typedef int wxAuiPaneDockArtGradients;
#define wxAUI_GRADIENT_NONE  0
#define wxAUI_GRADIENT_VERTICAL  1
#define wxAUI_GRADIENT_HORIZONTAL  2
%typedef int wxAuiPaneButtonState;
#define wxAUI_BUTTON_STATE_NORMAL  0
#define wxAUI_BUTTON_STATE_HOVER  1 << 1
#define wxAUI_BUTTON_STATE_PRESSED  1 << 2
#define wxAUI_BUTTON_STATE_DISABLED  1 << 3
#define wxAUI_BUTTON_STATE_HIDDEN    1 << 4
#define wxAUI_BUTTON_STATE_CHECKED   1 << 5
%typedef int wxAuiButtonId;
#define wxAUI_BUTTON_CLOSE  101
#define wxAUI_BUTTON_MAXIMIZE_RESTORE  102
#define wxAUI_BUTTON_MINIMIZE  103
#define wxAUI_BUTTON_PIN  104
#define wxAUI_BUTTON_OPTIONS  105
#define wxAUI_BUTTON_WINDOWLIST  106
#define wxAUI_BUTTON_LEFT  107
#define wxAUI_BUTTON_RIGHT  108
#define wxAUI_BUTTON_UP  109
#define wxAUI_BUTTON_DOWN  110
#define wxAUI_BUTTON_CUSTOM1  201
#define wxAUI_BUTTON_CUSTOM2  202
#define wxAUI_BUTTON_CUSTOM3  203
WXGO_DECL_TYPECONV(AuiDockArt)
class wxAuiDockArt
{
public:
    wxAuiDockArt();
    virtual ~wxAuiDockArt();
    virtual void DrawBackground(wxDC& dc, wxWindow* window, int orientation,
                                const wxRect& rect) = 0;
    virtual void DrawBorder(wxDC& dc, wxWindow* window, const wxRect& rect,
                            wxAuiPaneInfo& pane) = 0;
    virtual void DrawCaption(wxDC& dc, wxWindow* window, const wxString& text,
                             const wxRect& rect, wxAuiPaneInfo& pane) = 0;
    virtual void DrawGripper(wxDC& dc, wxWindow* window, const wxRect& rect,
                             wxAuiPaneInfo& pane) = 0;
    virtual void DrawPaneButton(wxDC& dc, wxWindow* window, int button,
                                int button_state, const wxRect& rect,
                                wxAuiPaneInfo& pane) = 0;
    virtual void DrawSash(wxDC& dc, wxWindow* window, int orientation,
                          const wxRect& rect) = 0;
    virtual wxColour GetColour(int id) = 0;
    virtual wxFont GetFont(int id) = 0;
    virtual int GetMetric(int id) = 0;
    virtual void SetColour(int id, const wxColour& colour) = 0;
    virtual void SetFont(int id, const wxFont& font) = 0;
    virtual void SetMetric(int id, int new_val) = 0;
};