#define wxCHOICE_WIDTH 150
#define wxCHOICE_HEIGHT 200
#define wxCHOICEDLG_STYLE (wxDEFAULT_DIALOG_STYLE | wxOK | wxCANCEL | wxCENTRE | wxRESIZE_BORDER)
WXGO_DECL_TYPECONV(MultiChoiceDialog)
class wxMultiChoiceDialog : public wxDialog
{
public:
    wxMultiChoiceDialog(wxWindow* parent, const wxString& message,
                        const wxString& caption,
                        int n, const wxString* choices,
                        long style = wxCHOICEDLG_STYLE,
                        const wxPoint& pos = wxDefaultPosition);
    wxMultiChoiceDialog(wxWindow* parent,
                        const wxString& message,
                        const wxString& caption,
                        const wxArrayString& choices,
                        long style = wxCHOICEDLG_STYLE,
                        const wxPoint& pos = wxDefaultPosition);
    wxArrayInt GetSelections() const;
    void SetSelections(const wxArrayInt& selections);
    int ShowModal();
};
WXGO_DECL_TYPECONV(SingleChoiceDialog)
class wxSingleChoiceDialog : public wxDialog
{
public:
    wxSingleChoiceDialog(wxWindow* parent, const wxString& message,
                         const wxString& caption,
                         int n, const wxString* choices,
                         void** clientData = NULL,
                         long style = wxCHOICEDLG_STYLE,
                         const wxPoint& pos = wxDefaultPosition);
    wxSingleChoiceDialog(wxWindow* parent,
                         const wxString& message,
                         const wxString& caption,
                         const wxArrayString& choices,
                         void** clientData = NULL,
                         long style = wxCHOICEDLG_STYLE,
                         const wxPoint& pos = wxDefaultPosition);
    int GetSelection() const;
    void* GetSelectionData() const;
    wxString GetStringSelection() const;
    void SetSelection(int selection);
    int ShowModal();
};
int wxGetSingleChoiceIndex(const wxString& message,
                           const wxString& caption,
                           const wxArrayString& aChoices,
                           wxWindow* parent = NULL,
                           int x = wxDefaultCoord,
                           int y = wxDefaultCoord,
                           bool centre = true,
                           int width = wxCHOICE_WIDTH,
                           int height = wxCHOICE_HEIGHT,
                           int initialSelection = 0);
int wxGetSingleChoiceIndex(const wxString& message,
                           const wxString& caption,
                           const wxArrayString& choices,
                           int initialSelection,
                           wxWindow *parent = NULL);
wxString wxGetSingleChoice(const wxString& message,
                           const wxString& caption,
                           const wxArrayString& aChoices,
                           wxWindow* parent = NULL,
                           int x = wxDefaultCoord,
                           int y = wxDefaultCoord,
                           bool centre = true,
                           int width = wxCHOICE_WIDTH,
                           int height = wxCHOICE_HEIGHT,
                           int initialSelection = 0);
wxString wxGetSingleChoice(const wxString& message,
                           const wxString& caption,
                           const wxArrayString& choices,
                           int initialSelection,
                           wxWindow *parent = NULL);
int wxGetSelectedChoices(wxArrayInt& selections,
                            const wxString& message,
                            const wxString& caption,
                            const wxArrayString& aChoices,
                            wxWindow* parent = NULL,
                            int x = wxDefaultCoord,
                            int y = wxDefaultCoord,
                            bool centre = true,
                            int width = wxCHOICE_WIDTH,
                            int height = wxCHOICE_HEIGHT);