WXGO_DECL_TYPECONV(ColourData)
WXGO_DECL_TYPECONV(ColourDialog)
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
};
class wxColourDialog : public wxDialog
{
public:
    wxColourDialog(wxWindow* parent, wxColourData* data = NULL);
    virtual ~wxColourDialog();
    bool Create(wxWindow* parent, wxColourData* data = NULL);
    wxColourData& GetColourData();
    virtual int ShowModal();
};
wxColour wxGetColourFromUser(wxWindow* parent,
                             const wxColour& colInit,
                             const wxString& caption = wxEmptyString,
                             wxColourData* data = NULL);