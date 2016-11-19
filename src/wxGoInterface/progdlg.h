#define wxPD_CAN_ABORT          0x0001
#define wxPD_APP_MODAL          0x0002
#define wxPD_AUTO_HIDE          0x0004
#define wxPD_ELAPSED_TIME       0x0008
#define wxPD_ESTIMATED_TIME     0x0010
#define wxPD_SMOOTH             0x0020
#define wxPD_REMAINING_TIME     0x0040
#define wxPD_CAN_SKIP           0x0080
WXGO_DECL_TYPECONV(GenericProgressDialog)
class wxGenericProgressDialog : public wxDialog
{
public:
    wxGenericProgressDialog(const wxString& title, const wxString& message,
                            int maximum = 100,
                            wxWindow* parent = NULL,
                            int style = wxPD_AUTO_HIDE | wxPD_APP_MODAL);
    virtual ~wxGenericProgressDialog();
    int GetValue() const;
    int GetRange() const;
    wxString GetMessage() const;
    virtual bool Pulse(const wxString& newmsg = wxEmptyString, bool* skip = NULL);
    void Resume();
    void SetRange(int maximum);
    bool WasCancelled() const;
    bool WasSkipped() const;
    virtual bool Update(int value, const wxString& newmsg = wxEmptyString,
                        bool* skip = NULL);
};
WXGO_DECL_TYPECONV(ProgressDialog)
class wxProgressDialog : public wxGenericProgressDialog
{
public:
    wxProgressDialog( const wxString& title, const wxString& message,
                      int maximum = 100,
                      wxWindow *parent = NULL,
                      int style = wxPD_APP_MODAL | wxPD_AUTO_HIDE );
};