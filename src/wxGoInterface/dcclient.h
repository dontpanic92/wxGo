WXGO_DECL_TYPECONV(WindowDC)
WXGO_DECL_TYPECONV(ClientDC)
WXGO_DECL_TYPECONV(PaintDC)
class wxWindowDC : public wxDC
{
public:
    wxWindowDC(wxWindow* window);
};
class wxClientDC : public wxWindowDC
{
public:
    wxClientDC(wxWindow* window);
};
class wxPaintDC : public wxClientDC
{
public:
    wxPaintDC(wxWindow* window);
};