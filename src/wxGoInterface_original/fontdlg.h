class wxFontData : public wxObject
{
public:
    wxFontData();
    void EnableEffects(bool enable);
    bool GetAllowSymbols() const;
    wxFont GetChosenFont() const;
    const wxColour& GetColour() const;
    bool GetEnableEffects() const;
    wxFont GetInitialFont() const;
    bool GetShowHelp() const;
    void SetAllowSymbols(bool allowSymbols);
    void SetChosenFont(const wxFont& font);
    void SetColour(const wxColour& colour);
    void SetInitialFont(const wxFont& font);
    void SetRange(int min, int max);
    void SetShowHelp(bool showHelp);
};
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
