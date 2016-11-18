WXGO_DECL_TYPECONV(UIActionSimulator)
class wxUIActionSimulator
{
public:
    wxUIActionSimulator();
    bool MouseMove(long x, long y);
    bool MouseMove(const wxPoint& point);
    bool MouseDown(int button = wxMOUSE_BTN_LEFT);
    bool MouseUp(int button = wxMOUSE_BTN_LEFT);
    bool MouseClick(int button = wxMOUSE_BTN_LEFT);
    bool MouseDblClick(int button = wxMOUSE_BTN_LEFT);
    bool MouseDragDrop(long x1, long y1, long x2, long y2,
                       int button = wxMOUSE_BTN_LEFT);
    bool KeyDown(int keycode, int modifiers = wxMOD_NONE);
    bool KeyUp(int keycode, int modifiers = wxMOD_NONE);
    bool Char(int keycode, int modifiers = wxMOD_NONE);
    bool Select(const wxString& text);
    bool Text(const wxString& text);
};