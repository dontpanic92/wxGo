WXGO_DECL_TYPECONV(RichMessageDialog)
class wxRichMessageDialog : public wxRichMessageDialogBase
{
public:
    wxRichMessageDialog(wxWindow* parent,
                        const wxString& message,
                        const wxString& caption = wxMessageBoxCaptionStr,
                        long style = wxOK | wxCENTRE);
    void ShowCheckBox(const wxString& checkBoxText, bool checked = false);
    wxString GetCheckBoxText() const;
    void ShowDetailedText(const wxString& detailedText);
    wxString GetDetailedText() const;
    bool IsCheckBoxChecked() const;
    virtual int ShowModal();
};