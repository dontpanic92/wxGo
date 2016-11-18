struct wxVideoMode
{
public:
    wxVideoMode(int width = 0, int height = 0, int depth = 0, int freq = 0);
    bool Matches(const wxVideoMode& other) const;
    int GetWidth() const;
    int GetHeight() const;
    int GetDepth() const;
    bool IsOk() const;
    bool operator==(const wxVideoMode& m) const;
    bool operator!=(const wxVideoMode& mode) const;
    int w;
    int h;
    int bpp;
    int refresh;
};
%constant const wxVideoMode wxDefaultVideoMode;