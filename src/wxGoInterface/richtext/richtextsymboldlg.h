WXGO_DECL_TYPECONV(SymbolPickerDialog)
class wxSymbolPickerDialog : public wxDialog
{
public:
    wxSymbolPickerDialog();
    wxSymbolPickerDialog(const wxString& symbol,
                         const wxString& initialFont,
                         const wxString& normalTextFont,
                         wxWindow* parent,
                         wxWindowID id = wxID_ANY,
                         const wxString& title = _("Symbols"),
                         const wxPoint& pos = wxDefaultPosition,
                         const wxSize& size = wxDefaultSize,
                         long style = wxDEFAULT_DIALOG_STYLE|wxRESIZE_BORDER|wxCLOSE_BOX);
    bool Create(const wxString& symbol, const wxString& initialFont,
                const wxString& normalTextFont, wxWindow* parent,
                wxWindowID id = wxID_ANY,
                const wxString& caption = wxGetTranslation("Symbols"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize(400, 300), long style = wxDEFAULT_DIALOG_STYLE|wxRESIZE_BORDER|wxCLOSE_BOX);
    wxString GetFontName() const;
    bool GetFromUnicode() const;
    wxString GetNormalTextFontName() const;
    wxString GetSymbol() const;
    int GetSymbolChar() const;
    bool HasSelection() const;
    void SetFontName(wxString value);
    void SetFromUnicode(bool value);
    void SetNormalTextFontName(wxString value);
    void SetSymbol(wxString value);
    void SetUnicodeMode(bool unicodeMode);
    bool UseNormalFont() const;
};