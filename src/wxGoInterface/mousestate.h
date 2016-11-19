%typedef int wxMouseButton;
#define wxMOUSE_BTN_ANY      -1
#define wxMOUSE_BTN_NONE     0
#define wxMOUSE_BTN_LEFT     1
#define wxMOUSE_BTN_MIDDLE   2
#define wxMOUSE_BTN_RIGHT    3
#define wxMOUSE_BTN_AUX1     4
#define wxMOUSE_BTN_AUX2     5
#define wxMOUSE_BTN_MAX wxMOUSE_BTN_AUX2     + 1
WXGO_DECL_TYPECONV(MouseState)
class wxMouseState : public wxKeyboardState
{
public:
    wxMouseState();
    wxCoord GetX() const;
    wxCoord GetY() const;
    wxPoint GetPosition() const;
    void GetPosition(int *x, int *y) const;
    bool LeftIsDown() const;
    bool MiddleIsDown() const;
    bool RightIsDown() const;
    bool Aux1IsDown() const;
    bool Aux2IsDown() const;
    void SetX(wxCoord x);
    void SetY(wxCoord y);
    void SetPosition(wxPoint pos);
    void SetLeftDown(bool down);
    void SetMiddleDown(bool down);
    void SetRightDown(bool down);
    void SetAux1Down(bool down);
    void SetAux2Down(bool down);
    void SetState(const wxMouseState& state);
};