WXGO_DECL_TYPECONV(KeyboardState)
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