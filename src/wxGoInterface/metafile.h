WXGO_DECL_TYPECONV(MetafileDC)
class wxMetafileDC : public wxDC
{
public:
    wxMetafileDC(const wxString& filename = wxEmptyString);
    ~wxMetafileDC();
    wxMetafile* Close();
};
WXGO_DECL_TYPECONV(Metafile)
class wxMetafile : public wxObject
{
public:
    wxMetafile(const wxString& filename = wxEmptyString);
    ~wxMetafile();
    bool IsOk();
    bool Play(wxDC* dc);
    bool SetClipboard(int width = 0, int height = 0);
};