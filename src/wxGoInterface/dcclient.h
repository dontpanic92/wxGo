WXGO_DECL_TYPECONV(WindowDC)
class wxWindowDC : public wxDC
{
public:
    wxWindowDC(wxWindow* window);
};
WXGO_DECL_TYPECONV(ClientDC)
class wxClientDC : public wxWindowDC
{
public:
    wxClientDC(wxWindow* window);
};
WXGO_DECL_TYPECONV(PaintDC)
class wxPaintDC : public wxClientDC
{
public:
    wxPaintDC(wxWindow* window);
};