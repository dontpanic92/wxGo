%typedef int wxFindReplaceFlags;
#define wxFR_DOWN        1
#define wxFR_WHOLEWORD   2
#define wxFR_MATCHCASE   4
%typedef int wxFindReplaceDialogStyles;
#define wxFR_REPLACEDIALOG  1
#define wxFR_NOUPDOWN       2
#define wxFR_NOMATCHCASE    4
#define wxFR_NOWHOLEWORD    8
WXGO_DECL_TYPECONV(FindDialogEvent)
class wxFindDialogEvent : public wxCommandEvent
{
public:
    wxFindDialogEvent(wxEventType commandType = wxEVT_NULL,
                      int id = 0);
    wxFindReplaceDialog* GetDialog() const;
    wxString GetFindString() const;
    int GetFlags() const;
    const wxString& GetReplaceString() const;
};
%constant wxEventType wxEVT_FIND;
%constant wxEventType wxEVT_FIND_NEXT;
%constant wxEventType wxEVT_FIND_REPLACE;
%constant wxEventType wxEVT_FIND_REPLACE_ALL;
%constant wxEventType wxEVT_FIND_CLOSE;
WXGO_DECL_TYPECONV(FindReplaceData)
class wxFindReplaceData : public wxObject
{
public:
    wxFindReplaceData(wxUint32 flags = 0);
    const wxString& GetFindString() const;
    int GetFlags() const;
    const wxString& GetReplaceString() const;
    void SetFindString(const wxString& str);
    void SetFlags(wxUint32 flags);
    void SetReplaceString(const wxString& str);
};
WXGO_DECL_TYPECONV(FindReplaceDialog)
class wxFindReplaceDialog : public wxDialog
{
public:
    wxFindReplaceDialog();
    wxFindReplaceDialog(wxWindow* parent,
                        wxFindReplaceData* data,
                        const wxString& title,
                        int style = 0);
    virtual ~wxFindReplaceDialog();
    bool Create(wxWindow* parent, wxFindReplaceData* data,
                const wxString& title, int style = 0);
    const wxFindReplaceData* GetData() const;
};