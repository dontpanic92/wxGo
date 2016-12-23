%inline %{
typedef wxMessageDialog::ButtonLabel wxMessageDialogButtonLabel;
%}
WXGO_DECL_TYPECONV(MessageDialog)
class wxMessageDialog : public wxDialog
{
public:
    class ButtonLabel
    {
    public:
        ButtonLabel(int stockId);
        ButtonLabel(const wxString& label);
        wxString GetAsString() const;
        int GetStockId() const;
    };
    wxMessageDialog(wxWindow* parent, const wxString& message,
                    const wxString& caption = wxMessageBoxCaptionStr,
                    long style = wxOK | wxCENTRE,
                    const wxPoint& pos = wxDefaultPosition);
    virtual void SetExtendedMessage(const wxString& extendedMessage);
    virtual bool SetHelpLabel(const ButtonLabel& help);
    virtual void SetMessage(const wxString& message);
    virtual bool SetOKCancelLabels(const ButtonLabel& ok,
                                   const ButtonLabel& cancel);
    virtual bool SetOKLabel(const ButtonLabel& ok);
    virtual bool SetYesNoCancelLabels(const ButtonLabel& yes,
                                      const ButtonLabel& no,
                                      const ButtonLabel& cancel);
    virtual bool SetYesNoLabels(const ButtonLabel& yes, const ButtonLabel& no);
    virtual int ShowModal();
    wxString GetCaption() const;
    wxString GetMessage() const;
    wxString GetExtendedMessage() const;
    long GetMessageDialogStyle() const;
    bool HasCustomLabels() const;
    wxString GetYesLabel() const;
    wxString GetNoLabel() const;
    wxString GetOKLabel() const;
    wxString GetCancelLabel() const;
    wxString GetHelpLabel() const;
    long GetEffectiveIcon() const;
};
int wxMessageBox(const wxString& message,
                 const wxString& caption = wxMessageBoxCaptionStr,
                 int style = wxOK | wxCENTRE,
                 wxWindow* parent = NULL,
                 int x = wxDefaultCoord,
                 int y = wxDefaultCoord);