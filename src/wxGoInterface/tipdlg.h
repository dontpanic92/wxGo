WXGO_DECL_TYPECONV(TipProvider)
class wxTipProvider
{
public:
    wxTipProvider(size_t currentTip);
    virtual ~wxTipProvider();
    size_t GetCurrentTip() const;
    virtual wxString GetTip() = 0;
};
wxTipProvider* wxCreateFileTipProvider(const wxString& filename,
                                       size_t currentTip);
bool wxShowTip(wxWindow *parent,
               wxTipProvider *tipProvider,
               bool showAtStartup = true);