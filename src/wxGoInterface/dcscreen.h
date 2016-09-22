WXGO_DECL_TYPECONV(ScreenDC)
class wxScreenDC : public wxDC
{
public:
    wxScreenDC();
    static bool EndDrawingOnTop();
    static bool StartDrawingOnTop(wxWindow* window);
    static bool StartDrawingOnTop(wxRect* rect = NULL);
};