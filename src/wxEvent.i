
%{
	#include "wx/wx.h"
%}

%import wxTrackable.i

enum wxMouseButton
{
    wxMOUSE_BTN_ANY     = -1,
    wxMOUSE_BTN_NONE    = 0,
    wxMOUSE_BTN_LEFT    = 1,
    wxMOUSE_BTN_MIDDLE  = 2,
    wxMOUSE_BTN_RIGHT   = 3,
    wxMOUSE_BTN_AUX1    = 4,
    wxMOUSE_BTN_AUX2    = 5,
    wxMOUSE_BTN_MAX
};
class wxKeyboardState
{
public:
    wxKeyboardState(bool controlDown = false,
                    bool shiftDown = false,
                    bool altDown = false,
                    bool metaDown = false);

    int GetModifiers() const;
    bool HasAnyModifiers() const;
    bool HasModifiers() const;
    bool ControlDown() const;
    bool RawControlDown() const;
    bool ShiftDown() const;
    bool MetaDown() const;
    bool AltDown() const;
    bool CmdDown() const;
    
    void SetControlDown(bool down);
    void SetRawControlDown(bool down);
    void SetShiftDown(bool down);
    void SetAltDown(bool down);
    void SetMetaDown(bool down);
};

class wxMouseState : public wxKeyboardState
{
public:
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

%include "wxGoInterface/event.h"

