WXGO_DECL_TYPECONV(RichTextFormattingDialogFactory)
class wxRichTextFormattingDialogFactory : public wxObject
{
public:
    wxRichTextFormattingDialogFactory();
    virtual ~wxRichTextFormattingDialogFactory();
    virtual bool CreateButtons(wxRichTextFormattingDialog* dialog);
    virtual wxPanel* CreatePage(int page, wxString& title,
                                wxRichTextFormattingDialog* dialog);
    virtual bool CreatePages(long pages,
                             wxRichTextFormattingDialog* dialog);
    virtual int GetPageId(int i) const;
    virtual int GetPageIdCount() const;
    virtual int GetPageImage(int id) const;
    virtual bool SetSheetStyle(wxRichTextFormattingDialog* dialog);
    virtual bool ShowHelp(int page,
                          wxRichTextFormattingDialog* dialog);
};
#define wxRICHTEXT_FORMAT_STYLE_EDITOR      0x0001
#define wxRICHTEXT_FORMAT_FONT              0x0002
#define wxRICHTEXT_FORMAT_TABS              0x0004
#define wxRICHTEXT_FORMAT_BULLETS           0x0008
#define wxRICHTEXT_FORMAT_INDENTS_SPACING   0x0010
WXGO_DECL_TYPECONV(RichTextFormattingDialog)
class wxRichTextFormattingDialog : public wxPropertySheetDialog
{
public:
    enum { Option_AllowPixelFontSize = 0x0001 };
    wxRichTextFormattingDialog();
    wxRichTextFormattingDialog(long flags, wxWindow* parent, const wxString& title = "Formatting",
                               wxWindowID id = wxID_ANY, const wxPoint& pos = wxDefaultPosition,
                               const wxSize& sz = wxDefaultSize, long style = wxDEFAULT_DIALOG_STYLE);
    virtual ~wxRichTextFormattingDialog();
    virtual bool ApplyStyle(wxRichTextCtrl* ctrl, const wxRichTextRange& range,
                            int flags = wxRICHTEXT_SETSTYLE_WITH_UNDO|wxRICHTEXT_SETSTYLE_OPTIMIZE);
    bool Create(long flags, wxWindow* parent,
                const wxString& title = wxGetTranslation("Formatting"), wxWindowID id = wxID_ANY,
                const wxPoint& pos = wxDefaultPosition, const wxSize& sz = wxDefaultSize,
                long style = wxDEFAULT_DIALOG_STYLE);
    wxTextAttr& GetAttributes();
    static wxRichTextFormattingDialog* GetDialog(wxWindow* win);
    static wxTextAttr* GetDialogAttributes(wxWindow* win);
    static wxRichTextStyleDefinition* GetDialogStyleDefinition(wxWindow* win);
    static wxRichTextFormattingDialogFactory* GetFormattingDialogFactory();
    wxImageList* GetImageList() const;
    virtual bool GetStyle(wxRichTextCtrl* ctrl, const wxRichTextRange& range);
    virtual wxRichTextStyleDefinition* GetStyleDefinition() const;
    virtual wxRichTextStyleSheet* GetStyleSheet() const;
    void SetAttributes(const wxTextAttr& attr);
    void SetOptions(int options) { m_options = options; }
    int GetOptions() const { return m_options; }
    bool HasOption(int option) const { return (m_options & option) != 0; }
    static void SetFormattingDialogFactory(wxRichTextFormattingDialogFactory* factory);
    void SetImageList(wxImageList* imageList);
    virtual bool SetStyle(const wxTextAttr& style, bool update = true);
    virtual bool SetStyleDefinition(const wxRichTextStyleDefinition& styleDef,
                                    wxRichTextStyleSheet* sheet,
                                    bool update = true);
    virtual bool UpdateDisplay();
    static bool GetRestoreLastPage();
    static void SetRestoreLastPage(bool b);
    static int GetLastPage();
    static void SetLastPage(int lastPage);
    static void SetColourData(const wxColourData& colourData);
    static wxColourData GetColourData();
};