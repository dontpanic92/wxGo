WXGO_DECL_TYPECONV(PopupWindow)
WXGO_DECL_TYPECONV(PopupTransientWindow)
class wxPopupWindow: public wxNonOwnedWindow
{
public:
    wxPopupWindow();
    wxPopupWindow(wxWindow *parent, int flags = wxBORDER_NONE);
    bool Create(wxWindow *parent, int flags = wxBORDER_NONE);
    virtual void Position(const wxPoint& ptOrigin,
                          const wxSize& sizePopup);
};
class wxPopupTransientWindow : public wxPopupWindow
{
public:
    wxPopupTransientWindow();
    wxPopupTransientWindow(wxWindow *parent, int flags = wxBORDER_NONE);
    virtual void Popup(wxWindow *focus = NULL);
    virtual void Dismiss();
    virtual bool ProcessLeftDown(wxMouseEvent& event);
protected:
    virtual void OnDismiss();
};