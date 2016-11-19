WXGO_DECL_TYPECONV(TreeItemId)
class wxTreeItemId
{
public:
    wxTreeItemId();
    bool IsOk() const;
    void* GetID() const;
    void Unset();
};
bool operator==(const wxTreeItemId& left, const wxTreeItemId& right);
bool operator!=(const wxTreeItemId& left, const wxTreeItemId& right);
WXGO_DECL_TYPECONV(TreeItemData)
class wxTreeItemData : public wxClientData
{
public:
    wxTreeItemData();
    virtual ~wxTreeItemData();
    const wxTreeItemId& GetId() const;
    void SetId(const wxTreeItemId& id);
};
%typedef int wxTreeItemIcon;
#define wxTreeItemIcon_Normal 0
#define wxTreeItemIcon_Selected wxTreeItemIcon_Normal + 1
#define wxTreeItemIcon_Expanded wxTreeItemIcon_Selected + 1
#define wxTreeItemIcon_SelectedExpanded wxTreeItemIcon_Expanded + 1
#define wxTreeItemIcon_Max wxTreeItemIcon_SelectedExpanded + 1
static const int wxTREE_ITEMSTATE_NONE  = -1;   
static const int wxTREE_ITEMSTATE_NEXT  = -2;   
static const int wxTREE_ITEMSTATE_PREV  = -3;   
#define wxTR_NO_BUTTONS              0x0000     
#define wxTR_HAS_BUTTONS             0x0001     
#define wxTR_NO_LINES                0x0004     
#define wxTR_LINES_AT_ROOT           0x0008     
#define wxTR_TWIST_BUTTONS           0x0010     
#define wxTR_SINGLE                  0x0000     
#define wxTR_MULTIPLE                0x0020     
#define wxTR_HAS_VARIABLE_ROW_HEIGHT 0x0080     
#define wxTR_EDIT_LABELS             0x0200     
#define wxTR_ROW_LINES               0x0400     
#define wxTR_HIDE_ROOT               0x0800     
#define wxTR_FULL_ROW_HIGHLIGHT      0x2000     
#define wxTR_DEFAULT_STYLE       (wxTR_HAS_BUTTONS | wxTR_LINES_AT_ROOT)
static const int wxTREE_HITTEST_ABOVE            = 0x0001;
static const int wxTREE_HITTEST_BELOW            = 0x0002;
static const int wxTREE_HITTEST_NOWHERE          = 0x0004;
static const int wxTREE_HITTEST_ONITEMBUTTON     = 0x0008;
static const int wxTREE_HITTEST_ONITEMICON       = 0x0010;
static const int wxTREE_HITTEST_ONITEMINDENT     = 0x0020;
static const int wxTREE_HITTEST_ONITEMLABEL      = 0x0040;
static const int wxTREE_HITTEST_ONITEMRIGHT      = 0x0080;
static const int wxTREE_HITTEST_ONITEMSTATEICON  = 0x0100;
static const int wxTREE_HITTEST_TOLEFT           = 0x0200;
static const int wxTREE_HITTEST_TORIGHT          = 0x0400;
static const int wxTREE_HITTEST_ONITEMUPPERPART  = 0x0800;
static const int wxTREE_HITTEST_ONITEMLOWERPART  = 0x1000;
static const int wxTREE_HITTEST_ONITEM  = wxTREE_HITTEST_ONITEMICON |
                                          wxTREE_HITTEST_ONITEMLABEL;