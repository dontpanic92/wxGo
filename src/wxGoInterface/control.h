%typedef int wxEllipsizeFlags;
#define wxELLIPSIZE_FLAGS_NONE  0
#define wxELLIPSIZE_FLAGS_PROCESS_MNEMONICS  1
#define wxELLIPSIZE_FLAGS_EXPAND_TABS  2
#define wxELLIPSIZE_FLAGS_DEFAULT  wxELLIPSIZE_FLAGS_PROCESS_MNEMONICS|                                wxELLIPSIZE_FLAGS_EXPAND_TABS
%typedef int wxEllipsizeMode;
#define wxELLIPSIZE_NONE 0
#define wxELLIPSIZE_START wxELLIPSIZE_NONE + 1
#define wxELLIPSIZE_MIDDLE wxELLIPSIZE_START + 1
#define wxELLIPSIZE_END wxELLIPSIZE_MIDDLE + 1
WXGO_DECL_TYPECONV(Control)
class wxControl : public wxWindow
{
public:
   wxControl(wxWindow *parent, wxWindowID id,
             const wxPoint& pos = wxDefaultPosition,
             const wxSize& size = wxDefaultSize, long style = 0,
             const wxValidator& validator = wxDefaultValidator,
             const wxString& name = wxControlNameStr);
    wxControl();
    bool Create(wxWindow *parent, wxWindowID id,
            const wxPoint& pos = wxDefaultPosition,
            const wxSize& size = wxDefaultSize, long style = 0,
            const wxValidator& validator = wxDefaultValidator,
            const wxString& name = wxControlNameStr);
    virtual void Command(wxCommandEvent& event);
    wxString GetLabel() const;
    wxString GetLabelText() const;
    wxSize GetSizeFromTextSize(int xlen, int ylen = -1) const;
    wxSize GetSizeFromTextSize(const wxSize& tsize) const;
    void SetLabel(const wxString& label);
    void SetLabelText(const wxString& text);
    bool SetLabelMarkup(const wxString& markup);
};