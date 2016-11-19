#define wxFNTP_FONTDESC_AS_LABEL      0x0008
#define wxFNTP_USEFONT_FOR_LABEL      0x0010
#define wxFONTBTN_DEFAULT_STYLE       (wxFNTP_FONTDESC_AS_LABEL | wxFNTP_USEFONT_FOR_LABEL)
#define wxFNTP_USE_TEXTCTRL           (wxPB_USE_TEXTCTRL)
#define wxFNTP_DEFAULT_STYLE          (wxFNTP_FONTDESC_AS_LABEL|wxFNTP_USEFONT_FOR_LABEL)
%constant wxEventType wxEVT_FONTPICKER_CHANGED;
WXGO_DECL_TYPECONV(FontPickerCtrl)
class wxFontPickerCtrl : public wxPickerBase
{
public:
    wxFontPickerCtrl();
    wxFontPickerCtrl(wxWindow* parent, wxWindowID id,
                     const wxFont& font = wxNullFont,
                     const wxPoint& pos = wxDefaultPosition,
                     const wxSize& size = wxDefaultSize,
                     long style = wxFNTP_DEFAULT_STYLE,
                     const wxValidator& validator = wxDefaultValidator,
                     const wxString& name = wxFontPickerCtrlNameStr);
    bool Create(wxWindow* parent, wxWindowID id,
                const wxFont& font = wxNullFont,
                const wxPoint& pos = wxDefaultPosition,
                const wxSize& size = wxDefaultSize,
                long style = wxFNTP_DEFAULT_STYLE,
                const wxValidator& validator = wxDefaultValidator,
                const wxString& name = wxFontPickerCtrlNameStr);
    unsigned int GetMaxPointSize() const;
    wxColour GetSelectedColour() const;
    wxFont GetSelectedFont() const;
    void SetMaxPointSize(unsigned int max);
    void SetSelectedColour(const wxColour& colour);
    void SetSelectedFont(const wxFont& font);
};
WXGO_DECL_TYPECONV(FontPickerEvent)
class wxFontPickerEvent : public wxCommandEvent
{
public:
    wxFontPickerEvent(wxObject* generator, int id,
                      const wxFont& font);
    wxFont GetFont() const;
    void SetFont(const wxFont& f);
};