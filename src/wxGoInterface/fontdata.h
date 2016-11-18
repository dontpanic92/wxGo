WXGO_DECL_TYPECONV(FontData)
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
    wxFontData& operator =(const wxFontData& data);
};