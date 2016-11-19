WXGO_DECL_TYPECONV(HtmlBookRecord)
class wxHtmlBookRecord
{
public:
    wxHtmlBookRecord(const wxString& bookfile, const wxString& basepath,
                     const wxString& title, const wxString& start);
    wxString GetBookFile() const;
    wxString GetTitle() const;
    wxString GetStart() const;
    wxString GetBasePath() const;
    void SetContentsRange(int start, int end);
    int GetContentsStart() const;
    int GetContentsEnd() const;
    void SetTitle(const wxString& title);
    void SetBasePath(const wxString& path);
    void SetStart(const wxString& start);
    wxString GetFullPath(const wxString &page) const;
};
struct wxHtmlHelpDataItem
{
    wxHtmlHelpDataItem();
    int level;
    wxHtmlHelpDataItem *parent;
    int id;
    wxString name;
    wxString page;
    wxHtmlBookRecord *book;
    wxString GetFullPath() const;
    wxString GetIndentedName() const;
};
WXGO_DECL_TYPECONV(HtmlHelpData)
class wxHtmlHelpData : public wxObject
{
public:
    wxHtmlHelpData();
    bool AddBook(const wxString& book_url);
    wxString FindPageById(int id);
    wxString FindPageByName(const wxString& page);
    const wxHtmlBookRecArray& GetBookRecArray() const;
    const wxHtmlHelpDataItems& GetContentsArray() const;
    const wxHtmlHelpDataItems& GetIndexArray() const;
    void SetTempDir(const wxString& path);
};