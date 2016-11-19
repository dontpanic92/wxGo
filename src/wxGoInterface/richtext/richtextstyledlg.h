#define wxRICHTEXT_ORGANISER_DELETE_STYLES  0x0001
#define wxRICHTEXT_ORGANISER_CREATE_STYLES  0x0002
#define wxRICHTEXT_ORGANISER_APPLY_STYLES   0x0004
#define wxRICHTEXT_ORGANISER_EDIT_STYLES    0x0008
#define wxRICHTEXT_ORGANISER_RENAME_STYLES  0x0010
#define wxRICHTEXT_ORGANISER_OK_CANCEL      0x0020
#define wxRICHTEXT_ORGANISER_RENUMBER       0x0040
#define wxRICHTEXT_ORGANISER_SHOW_CHARACTER 0x0100
#define wxRICHTEXT_ORGANISER_SHOW_PARAGRAPH 0x0200
#define wxRICHTEXT_ORGANISER_SHOW_LIST      0x0400
#define wxRICHTEXT_ORGANISER_SHOW_BOX       0x0800
#define wxRICHTEXT_ORGANISER_SHOW_ALL       0x1000
#define wxRICHTEXT_ORGANISER_ORGANISE (wxRICHTEXT_ORGANISER_SHOW_ALL|wxRICHTEXT_ORGANISER_DELETE_STYLES|wxRICHTEXT_ORGANISER_CREATE_STYLES|wxRICHTEXT_ORGANISER_APPLY_STYLES|wxRICHTEXT_ORGANISER_EDIT_STYLES|wxRICHTEXT_ORGANISER_RENAME_STYLES)
#define wxRICHTEXT_ORGANISER_BROWSE (wxRICHTEXT_ORGANISER_SHOW_ALL|wxRICHTEXT_ORGANISER_OK_CANCEL)
#define wxRICHTEXT_ORGANISER_BROWSE_NUMBERING (wxRICHTEXT_ORGANISER_SHOW_LIST|wxRICHTEXT_ORGANISER_OK_CANCEL|wxRICHTEXT_ORGANISER_RENUMBER)
WXGO_DECL_TYPECONV(RichTextStyleOrganiserDialog)
class wxRichTextStyleOrganiserDialog : public wxDialog
{
public:
    wxRichTextStyleOrganiserDialog();
    wxRichTextStyleOrganiserDialog(int flags,
                                   wxRichTextStyleSheet* sheet,
                                   wxRichTextCtrl* ctrl,
                                   wxWindow* parent,
                                   wxWindowID id = wxID_ANY,
                                   const wxString& caption = _("Style Organiser"),
                                   const wxPoint& pos = wxDefaultPosition,
                                   const wxSize& size = wxDefaultSize,
                                   long style = wxDEFAULT_DIALOG_STYLE|wxRESIZE_BORDER|wxSYSTEM_MENU|wxCLOSE_BOX);
    bool ApplyStyle(wxRichTextCtrl* ctrl = NULL);
    bool Create(int flags, wxRichTextStyleSheet* sheet, wxRichTextCtrl* ctrl,
                wxWindow* parent, wxWindowID id = wxID_ANY,
                const wxString& caption = wxGetTranslation("Style Organiser"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize(400, 300), long style = wxDEFAULT_DIALOG_STYLE|wxRESIZE_BORDER|wxSYSTEM_MENU|wxCLOSE_BOX);
    bool GetRestartNumbering() const;
    wxRichTextCtrl* GetRichTextCtrl() const;
    wxString GetSelectedStyle() const;
    wxRichTextStyleDefinition* GetSelectedStyleDefinition() const;
    wxRichTextStyleSheet* GetStyleSheet() const;
    void SetFlags(int flags);
    void SetRestartNumbering(bool restartNumbering);
    void SetRichTextCtrl(wxRichTextCtrl* ctrl);
    static void SetShowToolTips(bool show);
    void SetStyleSheet(wxRichTextStyleSheet* sheet);
    int GetFlags() const;
};