#define wxLB_DEFAULT          wxBK_DEFAULT
#define wxLB_TOP              wxBK_TOP
#define wxLB_BOTTOM           wxBK_BOTTOM
#define wxLB_LEFT             wxBK_LEFT
#define wxLB_RIGHT            wxBK_RIGHT
#define wxLB_ALIGN_MASK       wxBK_ALIGN_MASK
%constant wxEventType wxEVT_LISTBOOK_PAGE_CHANGED;
%constant wxEventType wxEVT_LISTBOOK_PAGE_CHANGING;
WXGO_DECL_TYPECONV(Listbook)
class wxListbook : public wxBookCtrlBase
{
public:
    wxListbook();
    wxListbook(wxWindow* parent, wxWindowID id,
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
    wxListView* GetListView() const;
};