WXGO_DECL_TYPECONV(Cursor)
class wxCursor : public wxGDIObject
{
public:
    wxCursor();
    wxCursor(const char bits[], int width, int height,
             int hotSpotX = -1, int hotSpotY = -1,
             const char maskBits[] = NULL);
    wxCursor(const wxString& cursorName,
             wxBitmapType type = wxCURSOR_DEFAULT_TYPE,
             int hotSpotX = 0, int hotSpotY = 0);
    wxCursor(wxStockCursor cursorId);
    wxCursor(const wxImage& image);
    wxCursor(const wxCursor& cursor);
    virtual ~wxCursor();
    virtual bool IsOk() const;
    wxPoint GetHotSpot() const;
    wxCursor& operator =(const wxCursor& cursor);
};
WXGO_GETTER_TO_VAR(Cursor, NullCursor);
WXGO_GETTER_TO_VAR(Cursor, STANDARD_CURSOR);
WXGO_GETTER_TO_VAR(Cursor, HOURGLASS_CURSOR);
WXGO_GETTER_TO_VAR(Cursor, CROSS_CURSOR);
const wxCursor wxNullCursor;
wxCursor* const wxSTANDARD_CURSOR;
wxCursor* const wxHOURGLASS_CURSOR;
wxCursor* const wxCROSS_CURSOR;