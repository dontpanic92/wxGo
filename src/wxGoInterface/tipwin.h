WXGO_DECL_TYPECONV(TipWindow)
class wxTipWindow : public wxWindow
{
public:
    wxTipWindow(wxWindow* parent, const wxString& text,
                wxCoord maxLength = 100,
                wxTipWindow** windowPtr = NULL,
                wxRect* rectBounds = NULL);
    void SetBoundingRect(const wxRect& rectBound);
    void SetTipWindowPtr(wxTipWindow** windowPtr);
};