WXGO_DECL_TYPECONV(DateEvent)
class wxDateEvent : public wxCommandEvent
{
public:
    wxDateEvent();
    wxDateEvent(wxWindow *win, const wxDateTime& dt, wxEventType type);
    const wxDateTime& GetDate() const;
    void SetDate(const wxDateTime& date);
};
%constant wxEventType wxEVT_DATE_CHANGED;
%constant wxEventType wxEVT_TIME_CHANGED;