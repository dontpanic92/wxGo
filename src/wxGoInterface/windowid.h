WXGO_DECL_TYPECONV(IdManager)
typedef int wxWindowID;
class wxIdManager
{
public:
    static wxWindowID ReserveId(int count = 1);
    static void UnreserveId(wxWindowID id, int count = 1);
};