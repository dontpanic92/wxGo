WXGO_DECL_TYPECONV(FontDialog)
class wxFontDialog : public wxDialog
{
public:
    wxFontDialog();
    wxFontDialog(wxWindow* parent);
    wxFontDialog(wxWindow* parent, const wxFontData& data);
    bool Create(wxWindow* parent);
    bool Create(wxWindow* parent, const wxFontData& data);
    wxFontData& GetFontData();
    int ShowModal();
};
wxFont wxGetFontFromUser(wxWindow* parent,
                         const wxFont& fontInit,
                         const wxString& caption = wxEmptyString);