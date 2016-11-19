typedef int wxWindowID;
WXGO_DECL_TYPECONV(IdManager)
class wxIdManager
{
public:
    static wxWindowID ReserveId(int count = 1);
    static void UnreserveId(wxWindowID id, int count = 1);
};