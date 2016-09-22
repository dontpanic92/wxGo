WXGO_DECL_TYPECONV(ToolTip)
class wxToolTip : public wxObject
{
public:
    wxToolTip(const wxString& tip);
    static void Enable(bool flag);
    wxString GetTip() const;
    wxWindow* GetWindow() const;
    static void SetAutoPop(long msecs);
    static void SetDelay(long msecs);
#ifdef __WXMSW__
    static void SetMaxWidth(int width);
#endif
    static void SetReshow(long msecs);
    void SetTip(const wxString& tip);
};