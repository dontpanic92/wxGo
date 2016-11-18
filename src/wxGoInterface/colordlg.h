WXGO_DECL_TYPECONV(ColourDialog)
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