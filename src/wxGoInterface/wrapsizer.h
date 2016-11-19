enum
{
    wxEXTEND_LAST_ON_EACH_LINE,
    wxREMOVE_LEADING_SPACES,
    wxWRAPSIZER_DEFAULT_FLAGS
};
WXGO_DECL_TYPECONV(WrapSizer)
class wxWrapSizer : public wxBoxSizer
{
public:
    wxWrapSizer(int orient = wxHORIZONTAL,
                int flags = wxWRAPSIZER_DEFAULT_FLAGS);
    virtual bool InformFirstDirection(int direction, int size,
                                      int availableOtherDir);
    virtual void RecalcSizes();
    virtual wxSize CalcMin();
protected:
    virtual bool IsSpaceItem(wxSizerItem *item) const;
};