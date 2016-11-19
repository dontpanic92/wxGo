#define wxCHB_DEFAULT          wxBK_DEFAULT
#define wxCHB_TOP              wxBK_TOP
#define wxCHB_BOTTOM           wxBK_BOTTOM
#define wxCHB_LEFT             wxBK_LEFT
#define wxCHB_RIGHT            wxBK_RIGHT
#define wxCHB_ALIGN_MASK       wxBK_ALIGN_MASK
%constant wxEventType wxEVT_CHOICEBOOK_PAGE_CHANGED;
%constant wxEventType wxEVT_CHOICEBOOK_PAGE_CHANGING;
WXGO_DECL_TYPECONV(Choicebook)
class wxChoicebook : public wxBookCtrlBase
{
public:
    wxChoicebook();
    wxChoicebook(wxWindow* parent, wxWindowID id,
                 const wxPoint& pos = wxDefaultPosition,
                 const wxSize& size = wxDefaultSize,
                 long style = 0,
                 const wxString& name = wxEmptyString);
    bool Create(wxWindow *parent,
                wxWindowID id,
                const wxPoint& pos = wxDefaultPosition,
                const wxSize& size = wxDefaultSize,
                long style = 0,
                const wxString& name = wxEmptyString);
    wxChoice * GetChoiceCtrl() const;
};