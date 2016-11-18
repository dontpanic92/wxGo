WXGO_DECL_TYPECONV(MetafileDC)
WXGO_DECL_TYPECONV(Metafile)
class wxMetafileDC : public wxDC
{
public:
    wxMetafileDC(const wxString& filename = wxEmptyString);
    ~wxMetafileDC();
    wxMetafile* Close();
};
class wxMetafile : public wxObject
{
public:
    wxMetafile(const wxString& filename = wxEmptyString);
    ~wxMetafile();
    bool IsOk();
    bool Play(wxDC* dc);
    bool SetClipboard(int width = 0, int height = 0);
};
bool wxMakeMetafilePlaceable(const wxString& filename,
                              int minX, int minY,
                              int maxX, int maxY,
                              float scale = 1.0);