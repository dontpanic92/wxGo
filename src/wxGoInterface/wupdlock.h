WXGO_DECL_TYPECONV(WindowUpdateLocker)
class wxWindowUpdateLocker
{
public:
    wxWindowUpdateLocker(wxWindow* win);
    ~wxWindowUpdateLocker();
};