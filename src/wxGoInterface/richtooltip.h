%typedef int wxTipKind;
#define wxTipKind_None 0
#define wxTipKind_TopLeft wxTipKind_None + 1
#define wxTipKind_Top wxTipKind_TopLeft + 1
#define wxTipKind_TopRight wxTipKind_Top + 1
#define wxTipKind_BottomLeft wxTipKind_TopRight + 1
#define wxTipKind_Bottom wxTipKind_BottomLeft + 1
#define wxTipKind_BottomRight wxTipKind_Bottom + 1
#define wxTipKind_Auto wxTipKind_BottomRight + 1
WXGO_DECL_TYPECONV(RichToolTip)
class wxRichToolTip
{
public:
    wxRichToolTip(const wxString& title, const wxString& message);
    void SetBackgroundColour(const wxColour& col,
                             const wxColour& colEnd = wxColour());
    void SetIcon(int icon = wxICON_INFORMATION);
    void SetIcon(const wxIcon& icon);
    void SetTimeout(unsigned millisecondsTimeout, unsigned millisecondsDelay = 0);
    void SetTipKind(wxTipKind tipKind);
    void SetTitleFont(const wxFont& font);
    void ShowFor(wxWindow* win, const wxRect* rect = NULL);
    ~wxRichToolTip();
};