WXGO_DECL_TYPECONV(PostScriptDC)
class wxPostScriptDC : public wxDC
{
public:
    wxPostScriptDC();
    wxPostScriptDC(const wxPrintData& printData);
};