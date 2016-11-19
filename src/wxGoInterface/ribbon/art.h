%typedef int wxRibbonArtSetting;
#define wxRIBBON_ART_TAB_SEPARATION_SIZE 0
#define wxRIBBON_ART_PAGE_BORDER_LEFT_SIZE wxRIBBON_ART_TAB_SEPARATION_SIZE + 1
#define wxRIBBON_ART_PAGE_BORDER_TOP_SIZE wxRIBBON_ART_PAGE_BORDER_LEFT_SIZE + 1
#define wxRIBBON_ART_PAGE_BORDER_RIGHT_SIZE wxRIBBON_ART_PAGE_BORDER_TOP_SIZE + 1
#define wxRIBBON_ART_PAGE_BORDER_BOTTOM_SIZE wxRIBBON_ART_PAGE_BORDER_RIGHT_SIZE + 1
#define wxRIBBON_ART_PANEL_X_SEPARATION_SIZE wxRIBBON_ART_PAGE_BORDER_BOTTOM_SIZE + 1
#define wxRIBBON_ART_PANEL_Y_SEPARATION_SIZE wxRIBBON_ART_PANEL_X_SEPARATION_SIZE + 1
#define wxRIBBON_ART_TOOL_GROUP_SEPARATION_SIZE wxRIBBON_ART_PANEL_Y_SEPARATION_SIZE + 1
#define wxRIBBON_ART_GALLERY_BITMAP_PADDING_LEFT_SIZE wxRIBBON_ART_TOOL_GROUP_SEPARATION_SIZE + 1
#define wxRIBBON_ART_GALLERY_BITMAP_PADDING_RIGHT_SIZE wxRIBBON_ART_GALLERY_BITMAP_PADDING_LEFT_SIZE + 1
#define wxRIBBON_ART_GALLERY_BITMAP_PADDING_TOP_SIZE wxRIBBON_ART_GALLERY_BITMAP_PADDING_RIGHT_SIZE + 1
#define wxRIBBON_ART_GALLERY_BITMAP_PADDING_BOTTOM_SIZE wxRIBBON_ART_GALLERY_BITMAP_PADDING_TOP_SIZE + 1
#define wxRIBBON_ART_PANEL_LABEL_FONT wxRIBBON_ART_GALLERY_BITMAP_PADDING_BOTTOM_SIZE + 1
#define wxRIBBON_ART_BUTTON_BAR_LABEL_FONT wxRIBBON_ART_PANEL_LABEL_FONT + 1
#define wxRIBBON_ART_TAB_LABEL_FONT wxRIBBON_ART_BUTTON_BAR_LABEL_FONT + 1
#define wxRIBBON_ART_BUTTON_BAR_LABEL_COLOUR wxRIBBON_ART_TAB_LABEL_FONT + 1
#define wxRIBBON_ART_BUTTON_BAR_LABEL_DISABLED_COLOUR wxRIBBON_ART_BUTTON_BAR_LABEL_COLOUR + 1
#define wxRIBBON_ART_BUTTON_BAR_HOVER_BORDER_COLOUR wxRIBBON_ART_BUTTON_BAR_LABEL_DISABLED_COLOUR + 1
#define wxRIBBON_ART_BUTTON_BAR_HOVER_BACKGROUND_TOP_COLOUR wxRIBBON_ART_BUTTON_BAR_HOVER_BORDER_COLOUR + 1
#define wxRIBBON_ART_BUTTON_BAR_HOVER_BACKGROUND_TOP_GRADIENT_COLOUR wxRIBBON_ART_BUTTON_BAR_HOVER_BACKGROUND_TOP_COLOUR + 1
#define wxRIBBON_ART_BUTTON_BAR_HOVER_BACKGROUND_COLOUR wxRIBBON_ART_BUTTON_BAR_HOVER_BACKGROUND_TOP_GRADIENT_COLOUR + 1
#define wxRIBBON_ART_BUTTON_BAR_HOVER_BACKGROUND_GRADIENT_COLOUR wxRIBBON_ART_BUTTON_BAR_HOVER_BACKGROUND_COLOUR + 1
#define wxRIBBON_ART_BUTTON_BAR_ACTIVE_BORDER_COLOUR wxRIBBON_ART_BUTTON_BAR_HOVER_BACKGROUND_GRADIENT_COLOUR + 1
#define wxRIBBON_ART_BUTTON_BAR_ACTIVE_BACKGROUND_TOP_COLOUR wxRIBBON_ART_BUTTON_BAR_ACTIVE_BORDER_COLOUR + 1
#define wxRIBBON_ART_BUTTON_BAR_ACTIVE_BACKGROUND_TOP_GRADIENT_COLOUR wxRIBBON_ART_BUTTON_BAR_ACTIVE_BACKGROUND_TOP_COLOUR + 1
#define wxRIBBON_ART_BUTTON_BAR_ACTIVE_BACKGROUND_COLOUR wxRIBBON_ART_BUTTON_BAR_ACTIVE_BACKGROUND_TOP_GRADIENT_COLOUR + 1
#define wxRIBBON_ART_BUTTON_BAR_ACTIVE_BACKGROUND_GRADIENT_COLOUR wxRIBBON_ART_BUTTON_BAR_ACTIVE_BACKGROUND_COLOUR + 1
#define wxRIBBON_ART_GALLERY_BORDER_COLOUR wxRIBBON_ART_BUTTON_BAR_ACTIVE_BACKGROUND_GRADIENT_COLOUR + 1
#define wxRIBBON_ART_GALLERY_HOVER_BACKGROUND_COLOUR wxRIBBON_ART_GALLERY_BORDER_COLOUR + 1
#define wxRIBBON_ART_GALLERY_BUTTON_BACKGROUND_COLOUR wxRIBBON_ART_GALLERY_HOVER_BACKGROUND_COLOUR + 1
#define wxRIBBON_ART_GALLERY_BUTTON_BACKGROUND_GRADIENT_COLOUR wxRIBBON_ART_GALLERY_BUTTON_BACKGROUND_COLOUR + 1
#define wxRIBBON_ART_GALLERY_BUTTON_BACKGROUND_TOP_COLOUR wxRIBBON_ART_GALLERY_BUTTON_BACKGROUND_GRADIENT_COLOUR + 1
#define wxRIBBON_ART_GALLERY_BUTTON_FACE_COLOUR wxRIBBON_ART_GALLERY_BUTTON_BACKGROUND_TOP_COLOUR + 1
#define wxRIBBON_ART_GALLERY_BUTTON_HOVER_BACKGROUND_COLOUR wxRIBBON_ART_GALLERY_BUTTON_FACE_COLOUR + 1
#define wxRIBBON_ART_GALLERY_BUTTON_HOVER_BACKGROUND_GRADIENT_COLOUR wxRIBBON_ART_GALLERY_BUTTON_HOVER_BACKGROUND_COLOUR + 1
#define wxRIBBON_ART_GALLERY_BUTTON_HOVER_BACKGROUND_TOP_COLOUR wxRIBBON_ART_GALLERY_BUTTON_HOVER_BACKGROUND_GRADIENT_COLOUR + 1
#define wxRIBBON_ART_GALLERY_BUTTON_HOVER_FACE_COLOUR wxRIBBON_ART_GALLERY_BUTTON_HOVER_BACKGROUND_TOP_COLOUR + 1
#define wxRIBBON_ART_GALLERY_BUTTON_ACTIVE_BACKGROUND_COLOUR wxRIBBON_ART_GALLERY_BUTTON_HOVER_FACE_COLOUR + 1
#define wxRIBBON_ART_GALLERY_BUTTON_ACTIVE_BACKGROUND_GRADIENT_COLOUR wxRIBBON_ART_GALLERY_BUTTON_ACTIVE_BACKGROUND_COLOUR + 1
#define wxRIBBON_ART_GALLERY_BUTTON_ACTIVE_BACKGROUND_TOP_COLOUR wxRIBBON_ART_GALLERY_BUTTON_ACTIVE_BACKGROUND_GRADIENT_COLOUR + 1
#define wxRIBBON_ART_GALLERY_BUTTON_ACTIVE_FACE_COLOUR wxRIBBON_ART_GALLERY_BUTTON_ACTIVE_BACKGROUND_TOP_COLOUR + 1
#define wxRIBBON_ART_GALLERY_BUTTON_DISABLED_BACKGROUND_COLOUR wxRIBBON_ART_GALLERY_BUTTON_ACTIVE_FACE_COLOUR + 1
#define wxRIBBON_ART_GALLERY_BUTTON_DISABLED_BACKGROUND_GRADIENT_COLOUR wxRIBBON_ART_GALLERY_BUTTON_DISABLED_BACKGROUND_COLOUR + 1
#define wxRIBBON_ART_GALLERY_BUTTON_DISABLED_BACKGROUND_TOP_COLOUR wxRIBBON_ART_GALLERY_BUTTON_DISABLED_BACKGROUND_GRADIENT_COLOUR + 1
#define wxRIBBON_ART_GALLERY_BUTTON_DISABLED_FACE_COLOUR wxRIBBON_ART_GALLERY_BUTTON_DISABLED_BACKGROUND_TOP_COLOUR + 1
#define wxRIBBON_ART_GALLERY_ITEM_BORDER_COLOUR wxRIBBON_ART_GALLERY_BUTTON_DISABLED_FACE_COLOUR + 1
#define wxRIBBON_ART_TAB_LABEL_COLOUR wxRIBBON_ART_GALLERY_ITEM_BORDER_COLOUR + 1
#define wxRIBBON_ART_TAB_SEPARATOR_COLOUR wxRIBBON_ART_TAB_LABEL_COLOUR + 1
#define wxRIBBON_ART_TAB_SEPARATOR_GRADIENT_COLOUR wxRIBBON_ART_TAB_SEPARATOR_COLOUR + 1
#define wxRIBBON_ART_TAB_CTRL_BACKGROUND_COLOUR wxRIBBON_ART_TAB_SEPARATOR_GRADIENT_COLOUR + 1
#define wxRIBBON_ART_TAB_CTRL_BACKGROUND_GRADIENT_COLOUR wxRIBBON_ART_TAB_CTRL_BACKGROUND_COLOUR + 1
#define wxRIBBON_ART_TAB_HOVER_BACKGROUND_TOP_COLOUR wxRIBBON_ART_TAB_CTRL_BACKGROUND_GRADIENT_COLOUR + 1
#define wxRIBBON_ART_TAB_HOVER_BACKGROUND_TOP_GRADIENT_COLOUR wxRIBBON_ART_TAB_HOVER_BACKGROUND_TOP_COLOUR + 1
#define wxRIBBON_ART_TAB_HOVER_BACKGROUND_COLOUR wxRIBBON_ART_TAB_HOVER_BACKGROUND_TOP_GRADIENT_COLOUR + 1
#define wxRIBBON_ART_TAB_HOVER_BACKGROUND_GRADIENT_COLOUR wxRIBBON_ART_TAB_HOVER_BACKGROUND_COLOUR + 1
#define wxRIBBON_ART_TAB_ACTIVE_BACKGROUND_TOP_COLOUR wxRIBBON_ART_TAB_HOVER_BACKGROUND_GRADIENT_COLOUR + 1
#define wxRIBBON_ART_TAB_ACTIVE_BACKGROUND_TOP_GRADIENT_COLOUR wxRIBBON_ART_TAB_ACTIVE_BACKGROUND_TOP_COLOUR + 1
#define wxRIBBON_ART_TAB_ACTIVE_BACKGROUND_COLOUR wxRIBBON_ART_TAB_ACTIVE_BACKGROUND_TOP_GRADIENT_COLOUR + 1
#define wxRIBBON_ART_TAB_ACTIVE_BACKGROUND_GRADIENT_COLOUR wxRIBBON_ART_TAB_ACTIVE_BACKGROUND_COLOUR + 1
#define wxRIBBON_ART_TAB_BORDER_COLOUR wxRIBBON_ART_TAB_ACTIVE_BACKGROUND_GRADIENT_COLOUR + 1
#define wxRIBBON_ART_PANEL_BORDER_COLOUR wxRIBBON_ART_TAB_BORDER_COLOUR + 1
#define wxRIBBON_ART_PANEL_BORDER_GRADIENT_COLOUR wxRIBBON_ART_PANEL_BORDER_COLOUR + 1
#define wxRIBBON_ART_PANEL_MINIMISED_BORDER_COLOUR wxRIBBON_ART_PANEL_BORDER_GRADIENT_COLOUR + 1
#define wxRIBBON_ART_PANEL_MINIMISED_BORDER_GRADIENT_COLOUR wxRIBBON_ART_PANEL_MINIMISED_BORDER_COLOUR + 1
#define wxRIBBON_ART_PANEL_LABEL_BACKGROUND_COLOUR wxRIBBON_ART_PANEL_MINIMISED_BORDER_GRADIENT_COLOUR + 1
#define wxRIBBON_ART_PANEL_LABEL_BACKGROUND_GRADIENT_COLOUR wxRIBBON_ART_PANEL_LABEL_BACKGROUND_COLOUR + 1
#define wxRIBBON_ART_PANEL_LABEL_COLOUR wxRIBBON_ART_PANEL_LABEL_BACKGROUND_GRADIENT_COLOUR + 1
#define wxRIBBON_ART_PANEL_HOVER_LABEL_BACKGROUND_COLOUR wxRIBBON_ART_PANEL_LABEL_COLOUR + 1
#define wxRIBBON_ART_PANEL_HOVER_LABEL_BACKGROUND_GRADIENT_COLOUR wxRIBBON_ART_PANEL_HOVER_LABEL_BACKGROUND_COLOUR + 1
#define wxRIBBON_ART_PANEL_HOVER_LABEL_COLOUR wxRIBBON_ART_PANEL_HOVER_LABEL_BACKGROUND_GRADIENT_COLOUR + 1
#define wxRIBBON_ART_PANEL_MINIMISED_LABEL_COLOUR wxRIBBON_ART_PANEL_HOVER_LABEL_COLOUR + 1
#define wxRIBBON_ART_PANEL_ACTIVE_BACKGROUND_TOP_COLOUR wxRIBBON_ART_PANEL_MINIMISED_LABEL_COLOUR + 1
#define wxRIBBON_ART_PANEL_ACTIVE_BACKGROUND_TOP_GRADIENT_COLOUR wxRIBBON_ART_PANEL_ACTIVE_BACKGROUND_TOP_COLOUR + 1
#define wxRIBBON_ART_PANEL_ACTIVE_BACKGROUND_COLOUR wxRIBBON_ART_PANEL_ACTIVE_BACKGROUND_TOP_GRADIENT_COLOUR + 1
#define wxRIBBON_ART_PANEL_ACTIVE_BACKGROUND_GRADIENT_COLOUR wxRIBBON_ART_PANEL_ACTIVE_BACKGROUND_COLOUR + 1
#define wxRIBBON_ART_PAGE_BORDER_COLOUR wxRIBBON_ART_PANEL_ACTIVE_BACKGROUND_GRADIENT_COLOUR + 1
#define wxRIBBON_ART_PAGE_BACKGROUND_TOP_COLOUR wxRIBBON_ART_PAGE_BORDER_COLOUR + 1
#define wxRIBBON_ART_PAGE_BACKGROUND_TOP_GRADIENT_COLOUR wxRIBBON_ART_PAGE_BACKGROUND_TOP_COLOUR + 1
#define wxRIBBON_ART_PAGE_BACKGROUND_COLOUR wxRIBBON_ART_PAGE_BACKGROUND_TOP_GRADIENT_COLOUR + 1
#define wxRIBBON_ART_PAGE_BACKGROUND_GRADIENT_COLOUR wxRIBBON_ART_PAGE_BACKGROUND_COLOUR + 1
#define wxRIBBON_ART_PAGE_HOVER_BACKGROUND_TOP_COLOUR wxRIBBON_ART_PAGE_BACKGROUND_GRADIENT_COLOUR + 1
#define wxRIBBON_ART_PAGE_HOVER_BACKGROUND_TOP_GRADIENT_COLOUR wxRIBBON_ART_PAGE_HOVER_BACKGROUND_TOP_COLOUR + 1
#define wxRIBBON_ART_PAGE_HOVER_BACKGROUND_COLOUR wxRIBBON_ART_PAGE_HOVER_BACKGROUND_TOP_GRADIENT_COLOUR + 1
#define wxRIBBON_ART_PAGE_HOVER_BACKGROUND_GRADIENT_COLOUR wxRIBBON_ART_PAGE_HOVER_BACKGROUND_COLOUR + 1
#define wxRIBBON_ART_TOOLBAR_BORDER_COLOUR wxRIBBON_ART_PAGE_HOVER_BACKGROUND_GRADIENT_COLOUR + 1
#define wxRIBBON_ART_TOOLBAR_HOVER_BORDER_COLOUR wxRIBBON_ART_TOOLBAR_BORDER_COLOUR + 1
#define wxRIBBON_ART_TOOLBAR_FACE_COLOUR wxRIBBON_ART_TOOLBAR_HOVER_BORDER_COLOUR + 1
#define wxRIBBON_ART_TOOL_BACKGROUND_TOP_COLOUR wxRIBBON_ART_TOOLBAR_FACE_COLOUR + 1
#define wxRIBBON_ART_TOOL_BACKGROUND_TOP_GRADIENT_COLOUR wxRIBBON_ART_TOOL_BACKGROUND_TOP_COLOUR + 1
#define wxRIBBON_ART_TOOL_BACKGROUND_COLOUR wxRIBBON_ART_TOOL_BACKGROUND_TOP_GRADIENT_COLOUR + 1
#define wxRIBBON_ART_TOOL_BACKGROUND_GRADIENT_COLOUR wxRIBBON_ART_TOOL_BACKGROUND_COLOUR + 1
#define wxRIBBON_ART_TOOL_HOVER_BACKGROUND_TOP_COLOUR wxRIBBON_ART_TOOL_BACKGROUND_GRADIENT_COLOUR + 1
#define wxRIBBON_ART_TOOL_HOVER_BACKGROUND_TOP_GRADIENT_COLOUR wxRIBBON_ART_TOOL_HOVER_BACKGROUND_TOP_COLOUR + 1
#define wxRIBBON_ART_TOOL_HOVER_BACKGROUND_COLOUR wxRIBBON_ART_TOOL_HOVER_BACKGROUND_TOP_GRADIENT_COLOUR + 1
#define wxRIBBON_ART_TOOL_HOVER_BACKGROUND_GRADIENT_COLOUR wxRIBBON_ART_TOOL_HOVER_BACKGROUND_COLOUR + 1
#define wxRIBBON_ART_TOOL_ACTIVE_BACKGROUND_TOP_COLOUR wxRIBBON_ART_TOOL_HOVER_BACKGROUND_GRADIENT_COLOUR + 1
#define wxRIBBON_ART_TOOL_ACTIVE_BACKGROUND_TOP_GRADIENT_COLOUR wxRIBBON_ART_TOOL_ACTIVE_BACKGROUND_TOP_COLOUR + 1
#define wxRIBBON_ART_TOOL_ACTIVE_BACKGROUND_COLOUR wxRIBBON_ART_TOOL_ACTIVE_BACKGROUND_TOP_GRADIENT_COLOUR + 1
#define wxRIBBON_ART_TOOL_ACTIVE_BACKGROUND_GRADIENT_COLOUR wxRIBBON_ART_TOOL_ACTIVE_BACKGROUND_COLOUR + 1
#define wxRIBBON_ART_BUTTON_BAR_LABEL_HIGHLIGHT_COLOUR wxRIBBON_ART_TOOL_ACTIVE_BACKGROUND_GRADIENT_COLOUR + 1
#define wxRIBBON_ART_BUTTON_BAR_LABEL_HIGHLIGHT_GRADIENT_COLOUR wxRIBBON_ART_BUTTON_BAR_LABEL_HIGHLIGHT_COLOUR + 1
#define wxRIBBON_ART_BUTTON_BAR_LABEL_HIGHLIGHT_TOP_COLOUR wxRIBBON_ART_BUTTON_BAR_LABEL_HIGHLIGHT_GRADIENT_COLOUR + 1
#define wxRIBBON_ART_BUTTON_BAR_LABEL_HIGHLIGHT_GRADIENT_TOP_COLOUR wxRIBBON_ART_BUTTON_BAR_LABEL_HIGHLIGHT_TOP_COLOUR + 1
%typedef int wxRibbonScrollButtonStyle;
#define wxRIBBON_SCROLL_BTN_LEFT  0
#define wxRIBBON_SCROLL_BTN_RIGHT  1
#define wxRIBBON_SCROLL_BTN_UP  2
#define wxRIBBON_SCROLL_BTN_DOWN  3
#define wxRIBBON_SCROLL_BTN_DIRECTION_MASK  3
#define wxRIBBON_SCROLL_BTN_NORMAL  0
#define wxRIBBON_SCROLL_BTN_HOVERED  4
#define wxRIBBON_SCROLL_BTN_ACTIVE  8
#define wxRIBBON_SCROLL_BTN_STATE_MASK  12
#define wxRIBBON_SCROLL_BTN_FOR_OTHER  0
#define wxRIBBON_SCROLL_BTN_FOR_TABS  16
#define wxRIBBON_SCROLL_BTN_FOR_PAGE  32
#define wxRIBBON_SCROLL_BTN_FOR_MASK  48
%typedef int wxRibbonButtonKind;
#define wxRIBBON_BUTTON_NORMAL     1 << 0
#define wxRIBBON_BUTTON_DROPDOWN   1 << 1
#define wxRIBBON_BUTTON_HYBRID     wxRIBBON_BUTTON_NORMAL | wxRIBBON_BUTTON_DROPDOWN
#define wxRIBBON_BUTTON_TOGGLE     1 << 2
WXGO_DECL_TYPECONV(RibbonArtProvider)
class wxRibbonArtProvider
{
public:
    wxRibbonArtProvider();
    virtual ~wxRibbonArtProvider();
    virtual wxRibbonArtProvider* Clone() const = 0;
    virtual void SetFlags(long flags) = 0;
    virtual long GetFlags() const = 0;
    virtual int GetMetric(int id) const = 0;
    virtual void SetMetric(int id, int new_val) = 0;
    virtual void SetFont(int id, const wxFont& font) = 0;
    virtual wxFont GetFont(int id) const = 0;
    virtual wxColour GetColour(int id) const = 0;
    virtual void SetColour(int id, const wxColor& colour) = 0;
    wxColour GetColor(int id) const;
    void SetColor(int id, const wxColour& color);
    virtual void GetColourScheme(wxColour* primary,
                        wxColour* secondary,
                        wxColour* tertiary) const = 0;
    virtual void SetColourScheme(const wxColour& primary,
                        const wxColour& secondary,
                        const wxColour& tertiary) = 0;
    virtual void DrawTabCtrlBackground(
                        wxDC& dc,
                        wxWindow* wnd,
                        const wxRect& rect) = 0;
    virtual void DrawTab(wxDC& dc,
                        wxWindow* wnd,
                        const wxRibbonPageTabInfo& tab) = 0;
    virtual void DrawTabSeparator(wxDC& dc,
                        wxWindow* wnd,
                        const wxRect& rect,
                        double visibility) = 0;
    virtual void DrawPageBackground(
                        wxDC& dc,
                        wxWindow* wnd,
                        const wxRect& rect) = 0;
    virtual void DrawScrollButton(
                        wxDC& dc,
                        wxWindow* wnd,
                        const wxRect& rect,
                        long style) = 0;
    virtual void DrawPanelBackground(
                        wxDC& dc,
                        wxRibbonPanel* wnd,
                        const wxRect& rect) = 0;
    virtual void DrawGalleryBackground(
                        wxDC& dc,
                        wxRibbonGallery* wnd,
                        const wxRect& rect) = 0;
    virtual void DrawGalleryItemBackground(
                        wxDC& dc,
                        wxRibbonGallery* wnd,
                        const wxRect& rect,
                        wxRibbonGalleryItem* item) = 0;
    virtual void DrawMinimisedPanel(
                        wxDC& dc,
                        wxRibbonPanel* wnd,
                        const wxRect& rect,
                        wxBitmap& bitmap) = 0;
    virtual void DrawButtonBarBackground(
                        wxDC& dc,
                        wxWindow* wnd,
                        const wxRect& rect) = 0;
    virtual void DrawButtonBarButton(
                        wxDC& dc,
                        wxWindow* wnd,
                        const wxRect& rect,
                        wxRibbonButtonKind kind,
                        long state,
                        const wxString& label,
                        const wxBitmap& bitmap_large,
                        const wxBitmap& bitmap_small) = 0;
    virtual void DrawToolBarBackground(
                        wxDC& dc,
                        wxWindow* wnd,
                        const wxRect& rect) = 0;
    virtual void DrawToolGroupBackground(
                        wxDC& dc,
                        wxWindow* wnd,
                        const wxRect& rect) = 0;
    virtual void DrawTool(
                        wxDC& dc,
                        wxWindow* wnd,
                        const wxRect& rect,
                        const wxBitmap& bitmap,
                        wxRibbonButtonKind kind,
                        long state) = 0;
    virtual void DrawToggleButton(wxDC& dc,
                                  wxRibbonBar* wnd,
                                  const wxRect& rect,
                                  wxRibbonDisplayMode mode) = 0;
    virtual void DrawHelpButton(wxDC& dc,
                                wxRibbonBar* wnd,
                                const wxRect& rect) = 0;
    virtual void GetBarTabWidth(
                        wxDC& dc,
                        wxWindow* wnd,
                        const wxString& label,
                        const wxBitmap& bitmap,
                        int* ideal,
                        int* small_begin_need_separator,
                        int* small_must_have_separator,
                        int* minimum) = 0;
    virtual int GetTabCtrlHeight(
                        wxDC& dc,
                        wxWindow* wnd,
                        const wxRibbonPageTabInfoArray& pages) = 0;
    virtual wxSize GetScrollButtonMinimumSize(
                        wxDC& dc,
                        wxWindow* wnd,
                        long style) = 0;
    virtual wxSize GetPanelSize(
                        wxDC& dc,
                        const wxRibbonPanel* wnd,
                        wxSize client_size,
                        wxPoint* client_offset) = 0;
    virtual wxSize GetPanelClientSize(
                        wxDC& dc,
                        const wxRibbonPanel* wnd,
                        wxSize size,
                        wxPoint* client_offset) = 0;
    virtual wxRect GetPanelExtButtonArea(
                        wxDC& dc,
                        const wxRibbonPanel* wnd,
                        wxRect rect) = 0;
    virtual wxSize GetGallerySize(
                        wxDC& dc,
                        const wxRibbonGallery* wnd,
                        wxSize client_size) = 0;
    virtual wxSize GetGalleryClientSize(
                        wxDC& dc,
                        const wxRibbonGallery* wnd,
                        wxSize size,
                        wxPoint* client_offset,
                        wxRect* scroll_up_button,
                        wxRect* scroll_down_button,
                        wxRect* extension_button) = 0;
    virtual wxRect GetPageBackgroundRedrawArea(
                        wxDC& dc,
                        const wxRibbonPage* wnd,
                        wxSize page_old_size,
                        wxSize page_new_size) = 0;
    virtual bool GetButtonBarButtonSize(
                        wxDC& dc,
                        wxWindow* wnd,
                        wxRibbonButtonKind kind,
                        wxRibbonButtonBarButtonState size,
                        const wxString& label,
                        wxSize bitmap_size_large,
                        wxSize bitmap_size_small,
                        wxSize* button_size,
                        wxRect* normal_region,
                        wxRect* dropdown_region) = 0;
    virtual wxSize GetMinimisedPanelMinimumSize(
                        wxDC& dc,
                        const wxRibbonPanel* wnd,
                        wxSize* desired_bitmap_size,
                        wxDirection* expanded_panel_direction) = 0;
    virtual wxSize GetToolSize(
                        wxDC& dc,
                        wxWindow* wnd,
                        wxSize bitmap_size,
                        wxRibbonButtonKind kind,
                        bool is_first,
                        bool is_last,
                        wxRect* dropdown_region) = 0;
    virtual wxRect GetBarToggleButtonArea(const wxRect& rect) = 0;
    virtual wxRect GetRibbonHelpButtonArea(const wxRect& rect) = 0;
};