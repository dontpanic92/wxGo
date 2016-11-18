WXGO_DECL_TYPECONV(ColourData)
class wxColourData : public wxObject
{
public:
    enum
    {
        NUM_CUSTOM = 16
    };
    wxColourData();
    virtual ~wxColourData();
    bool GetChooseFull() const;
    wxColour& GetColour();
    wxColour GetCustomColour(int i) const;
    void SetChooseFull(bool flag);
    void SetColour(const wxColour& colour);
    void SetCustomColour(int i, const wxColour& colour);
    wxString ToString() const;
    bool FromString(const wxString& str);
    wxColourData& operator =(const wxColourData& data);
};