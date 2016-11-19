WXGO_DECL_TYPECONV(RichTextStyleListCtrl)
class wxRichTextStyleListCtrl : public wxControl
{
public:
    wxRichTextStyleListCtrl(wxWindow* parent,
                            wxWindowID id = wxID_ANY,
                            const wxPoint& pos = wxDefaultPosition,
                            const wxSize& size = wxDefaultSize,
                            long style = 0);
    wxRichTextStyleListCtrl();
    bool Create(wxWindow* parent, wxWindowID id = wxID_ANY,
                const wxPoint& pos = wxDefaultPosition,
                const wxSize& size = wxDefaultSize,
                long style = 0);
    wxRichTextCtrl* GetRichTextCtrl() const;
    wxChoice* GetStyleChoice() const;
    wxRichTextStyleListBox* GetStyleListBox() const;
    wxRichTextStyleSheet* GetStyleSheet() const;
    wxRichTextStyleListBox::wxRichTextStyleType GetStyleType() const;
    void SetRichTextCtrl(wxRichTextCtrl* ctrl);
    void SetStyleSheet(wxRichTextStyleSheet* styleSheet);
    void SetStyleType(wxRichTextStyleListBox::wxRichTextStyleType styleType);
    void UpdateStyles();
};
%nodefaultctor wxRichTextStyleDefinition;
WXGO_DECL_TYPECONV(RichTextStyleDefinition)
class wxRichTextStyleDefinition : public wxObject
{
public:
    virtual ~wxRichTextStyleDefinition();
    const wxString& GetBaseStyle() const;
    const wxString& GetDescription() const;
    const wxString& GetName() const;
    wxRichTextAttr GetStyle() const;
    const wxRichTextAttr GetStyle() const;
    virtual wxRichTextAttr GetStyleMergedWithBase(const wxRichTextStyleSheet* sheet) const;
    void SetBaseStyle(const wxString& name);
    void SetDescription(const wxString& descr);
    void SetName(const wxString& name);
    void SetStyle(const wxRichTextAttr& style);
    wxRichTextProperties& GetProperties();
    void SetProperties(const wxRichTextProperties& props);
};
WXGO_DECL_TYPECONV(RichTextParagraphStyleDefinition)
class wxRichTextParagraphStyleDefinition : public wxRichTextStyleDefinition
{
public:
    wxRichTextParagraphStyleDefinition(const wxString& name = wxEmptyString);
    virtual ~wxRichTextParagraphStyleDefinition();
    const wxString& GetNextStyle() const;
    void SetNextStyle(const wxString& name);
};
WXGO_DECL_TYPECONV(RichTextStyleListBox)
class wxRichTextStyleListBox : public wxHtmlListBox
{
public:
    enum wxRichTextStyleType
    {
        wxRICHTEXT_STYLE_ALL,
        wxRICHTEXT_STYLE_PARAGRAPH,
        wxRICHTEXT_STYLE_CHARACTER,
        wxRICHTEXT_STYLE_LIST,
        wxRICHTEXT_STYLE_BOX
    };
    wxRichTextStyleListBox(wxWindow* parent,
                           wxWindowID id = wxID_ANY,
                           const wxPoint& pos = wxDefaultPosition,
                           const wxSize& size = wxDefaultSize,
                           long style = 0);
    wxRichTextStyleListBox();
    virtual ~wxRichTextStyleListBox();
    bool Create(wxWindow* parent,
                wxWindowID id = wxID_ANY,
                const wxPoint& pos = wxDefaultPosition,
                const wxSize& size = wxDefaultSize,
                long style = 0);
    void ApplyStyle(int i);
    int ConvertTenthsMMToPixels(wxDC& dc, int units) const;
    wxString CreateHTML(wxRichTextStyleDefinition* def) const;
    bool GetApplyOnSelection() const;
    wxRichTextCtrl* GetRichTextCtrl() const;
    wxRichTextStyleDefinition* GetStyle(size_t i) const;
    wxRichTextStyleSheet* GetStyleSheet() const;
    wxRichTextStyleListBox::wxRichTextStyleType GetStyleType() const;
    void OnLeftDown(wxMouseEvent& event);
    void SetApplyOnSelection(bool applyOnSelection);
    void SetRichTextCtrl(wxRichTextCtrl* ctrl);
    void SetStyleSheet(wxRichTextStyleSheet* styleSheet);
    void SetStyleType(wxRichTextStyleListBox::wxRichTextStyleType styleType);
    void UpdateStyles();
protected:
    virtual wxString OnGetItem(size_t n) const;
};
WXGO_DECL_TYPECONV(RichTextStyleComboCtrl)
class wxRichTextStyleComboCtrl : public wxComboCtrl
{
public:
    wxRichTextStyleComboCtrl(wxWindow* parent,
                             wxWindowID id = wxID_ANY,
                             const wxPoint& pos = wxDefaultPosition,
                             const wxSize& size = wxDefaultSize,
                             long style = 0);
    wxRichTextStyleComboCtrl();
    virtual ~wxRichTextStyleComboCtrl();
    bool Create(wxWindow* parent,
                wxWindowID id = wxID_ANY,
                const wxPoint& pos = wxDefaultPosition,
                const wxSize& size = wxDefaultSize,
                long style = 0);
    wxRichTextCtrl* GetRichTextCtrl() const;
    wxRichTextStyleSheet* GetStyleSheet() const;
    void SetRichTextCtrl(wxRichTextCtrl* ctrl);
    void SetStyleSheet(wxRichTextStyleSheet* styleSheet);
    void UpdateStyles();
};
WXGO_DECL_TYPECONV(RichTextCharacterStyleDefinition)
class wxRichTextCharacterStyleDefinition : public wxRichTextStyleDefinition
{
public:
    wxRichTextCharacterStyleDefinition(const wxString& name = wxEmptyString);
    virtual ~wxRichTextCharacterStyleDefinition();
};
WXGO_DECL_TYPECONV(RichTextListStyleDefinition)
class wxRichTextListStyleDefinition : public wxRichTextParagraphStyleDefinition
{
public:
    wxRichTextListStyleDefinition(const wxString& name = wxEmptyString);
    virtual ~wxRichTextListStyleDefinition();
    wxRichTextAttr CombineWithParagraphStyle(int indent,
                                         const wxRichTextAttr& paraStyle,
                                         wxRichTextStyleSheet* styleSheet = NULL);
    int FindLevelForIndent(int indent) const;
    wxRichTextAttr GetCombinedStyle(int indent,
                                wxRichTextStyleSheet* styleSheet = NULL);
    wxRichTextAttr GetCombinedStyleForLevel(int level,
                                     wxRichTextStyleSheet* styleSheet = NULL);
    const wxRichTextAttr* GetLevelAttributes(int level) const;
    int GetLevelCount() const;
    bool IsNumbered(int level) const;
    void SetLevelAttributes(int level, const wxRichTextAttr& attr);
};
WXGO_DECL_TYPECONV(RichTextStyleSheet)
class wxRichTextStyleSheet : public wxObject
{
public:
    wxRichTextStyleSheet();
    virtual ~wxRichTextStyleSheet();
    bool AddCharacterStyle(wxRichTextCharacterStyleDefinition* def);
    bool AddListStyle(wxRichTextListStyleDefinition* def);
    bool AddParagraphStyle(wxRichTextParagraphStyleDefinition* def);
    bool AddStyle(wxRichTextStyleDefinition* def);
    void DeleteStyles();
    wxRichTextCharacterStyleDefinition* FindCharacterStyle(const wxString& name,
                                                           bool recurse = true) const;
    wxRichTextListStyleDefinition* FindListStyle(const wxString& name,
                                                 bool recurse = true) const;
    wxRichTextParagraphStyleDefinition* FindParagraphStyle(const wxString& name,
                                                           bool recurse = true) const;
    wxRichTextStyleDefinition* FindStyle(const wxString& name) const;
    wxRichTextCharacterStyleDefinition* GetCharacterStyle(size_t n) const;
    size_t GetCharacterStyleCount() const;
    const wxString& GetDescription() const;
    wxRichTextListStyleDefinition* GetListStyle(size_t n) const;
    size_t GetListStyleCount() const;
    const wxString& GetName() const;
    wxRichTextParagraphStyleDefinition* GetParagraphStyle(size_t n) const;
    size_t GetParagraphStyleCount() const;
    bool RemoveCharacterStyle(wxRichTextStyleDefinition* def,
                              bool deleteStyle = false);
    bool RemoveListStyle(wxRichTextStyleDefinition* def,
                         bool deleteStyle = false);
    bool RemoveParagraphStyle(wxRichTextStyleDefinition* def,
                              bool deleteStyle = false);
    bool RemoveStyle(wxRichTextStyleDefinition* def,
                     bool deleteStyle = false);
    void SetDescription(const wxString& descr);
    void SetName(const wxString& name);
    wxRichTextProperties& GetProperties();
    void SetProperties(const wxRichTextProperties& props);
};