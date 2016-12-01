enum {
    wxC2S_NAME             = 1,   
    wxC2S_CSS_SYNTAX       = 2,   
    wxC2S_HTML_SYNTAX      = 4    
};
%constant const unsigned char wxALPHA_TRANSPARENT = 0;
%constant const unsigned char wxALPHA_OPAQUE = 0xff;

typedef wxColour wxColor;

class wxColour : public wxObject
{
public:
    wxColour();
    wxColour(unsigned char red, unsigned char green, unsigned char blue,
             unsigned char alpha = wxALPHA_OPAQUE);
    wxColour(const wxString& colourName);
    wxColour(unsigned long colRGB);
    wxColour(const wxColour& colour);
    virtual unsigned char Alpha() const;
    virtual unsigned char Blue() const;
    virtual wxString GetAsString(long flags = wxC2S_NAME | wxC2S_CSS_SYNTAX) const;
    void SetRGB(wxUint32 colRGB);
    void SetRGBA(wxUint32 colRGBA);
    wxUint32 GetRGB() const;
    wxUint32 GetRGBA() const;
    // Not available in wxgtk3
    //wxIntPtr GetPixel() const;
    virtual unsigned char Green() const;
    virtual bool IsOk() const;
    virtual unsigned char Red() const;
    void Set(unsigned char red, unsigned char green,
             unsigned char blue,
             unsigned char alpha = wxALPHA_OPAQUE);
    void Set(unsigned long RGB);
    bool Set(const wxString& str);
    bool operator !=(const wxColour& colour) const;
    //wxColour& operator=(const wxColour& colour);
    bool operator ==(const wxColour& colour) const;
    static void MakeMono(unsigned char* r, unsigned char* g, unsigned char* b, bool on);
    //static void MakeDisabled(unsigned char* r, unsigned char* g, unsigned char* b, unsigned char brightness = 255);
    wxColour& MakeDisabled(unsigned char brightness = 255);
    static void MakeGrey(unsigned char* r, unsigned char* g, unsigned char* b);
    static void MakeGrey(unsigned char* r, unsigned char* g, unsigned char* b,
                         double weight_r, double weight_g, double weight_b);
    static unsigned char AlphaBlend(unsigned char fg, unsigned char bg, double alpha);
    //static void ChangeLightness(unsigned char* r, unsigned char* g, unsigned char* b, int ialpha);
    wxColour ChangeLightness(int ialpha) const;
};

%constant const wxColour wxNullColour;
%constant const wxColour wxTransparentColour;

wxColour* const wxBLACK;
wxColour* const wxBLUE;
wxColour* const wxCYAN;
wxColour* const wxGREEN;
wxColour* const wxYELLOW;
wxColour* const wxLIGHT_GREY;
wxColour* const wxRED;
wxColour* const wxWHITE;

bool wxFromString(const wxString& string, wxColour* colour);
wxString wxToString(const wxColour& colour);
