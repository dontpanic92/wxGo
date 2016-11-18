WXGO_DECL_TYPECONV(Position)
class wxPosition
{
public:
    wxPosition();
    wxPosition(int row, int col);
    int GetCol() const;
    int GetColumn() const;
    int GetRow() const;
    void SetCol(int column);
    void SetColumn(int column);
    void SetRow(int row);
    bool operator ==(const wxPosition& pos) const;
    bool operator !=(const wxPosition& pos) const;
    wxPosition& operator +=(const wxPosition& pos);
    wxPosition& operator -=(const wxPosition& pos);
    wxPosition& operator +=(const wxSize& size);
    wxPosition& operator -=(const wxSize& size);
    wxPosition operator +(const wxPosition& pos) const;
    wxPosition operator -(const wxPosition& pos) const;
    wxPosition operator +(const wxSize& size) const;
    wxPosition operator -(const wxSize& size) const;
};