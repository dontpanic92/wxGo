#define wxCLRP_USE_TEXTCTRL       (wxPB_USE_TEXTCTRL)
#define wxCLRP_DEFAULT_STYLE      0
#define wxCLRP_SHOW_LABEL         0x0008
%constant wxEventType wxEVT_COLOURPICKER_CHANGED;
WXGO_DECL_TYPECONV(ColourPickerCtrl)
class wxColourPickerCtrl : public wxPickerBase
{
public:
    wxColourPickerCtrl();
    wxColourPickerCtrl(wxWindow* parent, wxWindowID id,
                       const wxColour& colour = *wxBLACK,
                       const wxPoint& pos = wxDefaultPosition,
                       const wxSize& size = wxDefaultSize,
                       long style = wxCLRP_DEFAULT_STYLE,
                       const wxValidator& validator = wxDefaultValidator,
                       const wxString& name = wxColourPickerCtrlNameStr);
    bool Create(wxWindow* parent, wxWindowID id,
                const wxColour& colour = *wxBLACK,
                const wxPoint& pos = wxDefaultPosition,
                const wxSize& size = wxDefaultSize,
                long style = wxCLRP_DEFAULT_STYLE,
                const wxValidator& validator = wxDefaultValidator,
                const wxString& name = wxColourPickerCtrlNameStr);
    wxColour GetColour() const;
    void SetColour(const wxColour& col);
    void SetColour(const wxString& colname);
};
WXGO_DECL_TYPECONV(ColourPickerEvent)
class wxColourPickerEvent : public wxCommandEvent
{
public:
    wxColourPickerEvent();
    wxColourPickerEvent(wxObject* generator, int id,
                        const wxColour& colour);
    wxColour GetColour() const;
    void SetColour(const wxColour& pos);
};