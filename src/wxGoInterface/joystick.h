WXGO_DECL_TYPECONV(Joystick)
class wxJoystick : public wxObject
{
public:
    wxJoystick(int joystick = wxJOYSTICK1);
    virtual ~wxJoystick();
    int GetButtonState() const;
    bool GetButtonState(unsigned int id) const;
    int GetManufacturerId() const;
    int GetMovementThreshold() const;
    int GetNumberAxes() const;
    int GetNumberButtons() const;
    static int GetNumberJoysticks();
    int GetPOVCTSPosition() const;
    int GetPOVPosition() const;
    int GetPollingMax() const;
    int GetPollingMin() const;
    wxPoint GetPosition() const;
    int GetPosition(unsigned int axis) const;
    int GetProductId() const;
    wxString GetProductName() const;
    int GetRudderMax() const;
    int GetRudderMin() const;
    int GetRudderPosition() const;
    int GetUMax() const;
    int GetUMin() const;
    int GetUPosition() const;
    int GetVMax() const;
    int GetVMin() const;
    int GetVPosition() const;
    int GetXMax() const;
    int GetXMin() const;
    int GetYMax() const;
    int GetYMin() const;
    int GetZMax() const;
    int GetZMin() const;
    int GetZPosition() const;
    bool HasPOV() const;
    bool HasPOV4Dir() const;
    bool HasPOVCTS() const;
    bool HasRudder() const;
    bool HasU() const;
    bool HasV() const;
    bool HasZ() const;
    bool IsOk() const;
    bool ReleaseCapture();
    bool SetCapture(wxWindow* win, int pollingFreq = 0);
    void SetMovementThreshold(int threshold);
};