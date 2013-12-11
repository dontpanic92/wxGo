#define wxFRAME_SHAPED          0x0010 

class wxNonOwnedWindow : public wxWindow
{
public:
    bool SetShape(const wxRegion& region);
    bool SetShape(const wxGraphicsPath& path);
};
