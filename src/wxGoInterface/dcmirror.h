WXGO_DECL_TYPECONV(MirrorDC)
class wxMirrorDC : public wxDC
{
public:
    wxMirrorDC(wxDC& dc, bool mirror);
};