%typedef int wxEdge;
#define wxLeft 0
#define wxTop wxLeft + 1
#define wxRight wxTop + 1
#define wxBottom wxRight + 1
#define wxWidth wxBottom + 1
#define wxHeight wxWidth + 1
#define wxCentre wxHeight + 1
#define wxCenter  wxCentre
#define wxCentreX wxCenter  + 1
#define wxCentreY wxCentreX + 1
%typedef int wxRelationship;
#define wxUnconstrained 0
#define wxAsIs wxUnconstrained + 1
#define wxPercentOf wxAsIs + 1
#define wxAbove wxPercentOf + 1
#define wxBelow wxAbove + 1
#define wxLeftOf wxBelow + 1
#define wxRightOf wxLeftOf + 1
#define wxSameAs wxRightOf + 1
#define wxAbsolute wxSameAs + 1
const int wxLAYOUT_DEFAULT_MARGIN = 0;
WXGO_DECL_TYPECONV(IndividualLayoutConstraint)
class wxIndividualLayoutConstraint : public wxObject
{
public:
    wxIndividualLayoutConstraint();
    virtual ~wxIndividualLayoutConstraint();
    void Set(wxRelationship rel,
             wxWindow *otherW,
             wxEdge otherE,
             int val = 0,
             int margin = wxLAYOUT_DEFAULT_MARGIN);
    void LeftOf(wxWindow *sibling, int margin = wxLAYOUT_DEFAULT_MARGIN);
    void RightOf(wxWindow *sibling, int margin = wxLAYOUT_DEFAULT_MARGIN);
    void Above(wxWindow *sibling, int margin = wxLAYOUT_DEFAULT_MARGIN);
    void Below(wxWindow *sibling, int margin = wxLAYOUT_DEFAULT_MARGIN);
    void SameAs(wxWindow *otherW, wxEdge edge, int margin = wxLAYOUT_DEFAULT_MARGIN);
    void PercentOf(wxWindow *otherW, wxEdge wh, int per);
    void Absolute(int val);
    void Unconstrained();
    void AsIs();
    wxWindow *GetOtherWindow();
    wxEdge GetMyEdge() const;
    void SetEdge(wxEdge which);
    void SetValue(int v);
    int GetMargin();
    void SetMargin(int m);
    int GetValue() const;
    int GetPercent() const;
    int GetOtherEdge() const;
    bool GetDone() const;
    void SetDone(bool d);
    wxRelationship GetRelationship();
    void SetRelationship(wxRelationship r);
    bool ResetIfWin(wxWindow *otherW);
    bool SatisfyConstraint(wxLayoutConstraints *constraints, wxWindow *win);
    int GetEdge(wxEdge which, wxWindow *thisWin, wxWindow *other) const;
};
WXGO_DECL_TYPECONV(LayoutConstraints)
class wxLayoutConstraints : public wxObject
{
public:
    wxIndividualLayoutConstraint left;
    wxIndividualLayoutConstraint top;
    wxIndividualLayoutConstraint right;
    wxIndividualLayoutConstraint bottom;
    wxIndividualLayoutConstraint width;
    wxIndividualLayoutConstraint height;
    wxIndividualLayoutConstraint centreX;
    wxIndividualLayoutConstraint centreY;
    wxLayoutConstraints();
    virtual ~wxLayoutConstraints();
    bool SatisfyConstraints(wxWindow *win, int *noChanges);
    bool AreSatisfied() const;
};