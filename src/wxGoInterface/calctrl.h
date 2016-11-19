enum
{
    wxCAL_SUNDAY_FIRST               = 0x0000,
    wxCAL_MONDAY_FIRST               = 0x0001,
    wxCAL_SHOW_HOLIDAYS              = 0x0002,
    wxCAL_NO_YEAR_CHANGE             = 0x0004,
    wxCAL_NO_MONTH_CHANGE            = 0x000c,
    wxCAL_SEQUENTIAL_MONTH_SELECTION = 0x0010,
    wxCAL_SHOW_SURROUNDING_WEEKS     = 0x0020,
    wxCAL_SHOW_WEEK_NUMBERS          = 0x0040
};
WXGO_DECL_TYPECONV(CalendarEvent)
class wxCalendarEvent : public wxDateEvent
{
public:
    wxCalendarEvent();
    wxCalendarEvent(wxWindow *win, const wxDateTime& dt, wxEventType type);
    wxDateTime::WeekDay GetWeekDay() const;
    void SetWeekDay(wxDateTime::WeekDay day);
};
%constant wxEventType wxEVT_CALENDAR_SEL_CHANGED;
%constant wxEventType wxEVT_CALENDAR_PAGE_CHANGED;
%constant wxEventType wxEVT_CALENDAR_DOUBLECLICKED;
%constant wxEventType wxEVT_CALENDAR_WEEKDAY_CLICKED;
%constant wxEventType wxEVT_CALENDAR_WEEK_CLICKED;
%typedef int wxCalendarDateBorder;
#define wxCAL_BORDER_NONE 0
#define wxCAL_BORDER_SQUARE wxCAL_BORDER_NONE + 1
#define wxCAL_BORDER_ROUND wxCAL_BORDER_SQUARE + 1
WXGO_DECL_TYPECONV(CalendarDateAttr)
class wxCalendarDateAttr
{
public:
    wxCalendarDateAttr(const wxColour& colText = wxNullColour,
                       const wxColour& colBack = wxNullColour,
                       const wxColour& colBorder = wxNullColour,
                       const wxFont& font = wxNullFont,
                       wxCalendarDateBorder border = wxCAL_BORDER_NONE);
    wxCalendarDateAttr(wxCalendarDateBorder border,
                       const wxColour& colBorder = wxNullColour);
    const wxColour& GetBackgroundColour() const;
    wxCalendarDateBorder GetBorder() const;
    const wxColour& GetBorderColour() const;
    const wxFont& GetFont() const;
    const wxColour& GetTextColour() const;
    bool HasBackgroundColour() const;
    bool HasBorder() const;
    bool HasBorderColour() const;
    bool HasFont() const;
    bool HasTextColour() const;
    bool IsHoliday() const;
    void SetBackgroundColour(const wxColour& colBack);
    void SetBorder(wxCalendarDateBorder border);
    void SetBorderColour(const wxColour& col);
    void SetFont(const wxFont& font);
    void SetHoliday(bool holiday);
    void SetTextColour(const wxColour& colText);
    static const wxCalendarDateAttr& GetMark();
    static void SetMark(const wxCalendarDateAttr& m);
};
%typedef int wxCalendarHitTestResult;
#define wxCAL_HITTEST_NOWHERE 0
#define wxCAL_HITTEST_HEADER wxCAL_HITTEST_NOWHERE + 1
#define wxCAL_HITTEST_DAY wxCAL_HITTEST_HEADER + 1
#define wxCAL_HITTEST_INCMONTH wxCAL_HITTEST_DAY + 1
#define wxCAL_HITTEST_DECMONTH wxCAL_HITTEST_INCMONTH + 1
#define wxCAL_HITTEST_SURROUNDING_WEEK wxCAL_HITTEST_DECMONTH + 1
#define wxCAL_HITTEST_WEEK wxCAL_HITTEST_SURROUNDING_WEEK + 1
WXGO_DECL_TYPECONV(CalendarCtrl)
class wxCalendarCtrl : public wxControl
{
public:
    wxCalendarCtrl();
    wxCalendarCtrl(wxWindow* parent, wxWindowID id,
                   const wxDateTime& date = wxDefaultDateTime,
                   const wxPoint& pos = wxDefaultPosition,
                   const wxSize& size = wxDefaultSize,
                   long style = wxCAL_SHOW_HOLIDAYS,
                   const wxString& name = wxCalendarNameStr);
    ~wxCalendarCtrl();
    bool Create(wxWindow* parent, wxWindowID id,
                const wxDateTime& date = wxDefaultDateTime,
                const wxPoint& pos = wxDefaultPosition,
                const wxSize& size = wxDefaultSize,
                long style = wxCAL_SHOW_HOLIDAYS,
                const wxString& name = wxCalendarNameStr);
    virtual void EnableHolidayDisplay(bool display = true);
    virtual bool EnableMonthChange(bool enable = true);
    virtual wxDateTime GetDate() const;
    virtual const wxColour& GetHeaderColourBg() const;
    virtual const wxColour& GetHeaderColourFg() const;
    virtual const wxColour& GetHighlightColourBg() const;
    virtual const wxColour& GetHighlightColourFg() const;
    virtual const wxColour& GetHolidayColourBg() const;
    virtual const wxColour& GetHolidayColourFg() const;
    virtual wxCalendarHitTestResult HitTest(const wxPoint& pos,
                                            wxDateTime* date = NULL,
                                            wxDateTime::WeekDay* wd = NULL);
    virtual void ResetAttr(size_t day);
    virtual void SetAttr(size_t day, wxCalendarDateAttr* attr);
    virtual bool SetDate(const wxDateTime& date);
    virtual void SetHeaderColours(const wxColour& colFg,
                                  const wxColour& colBg);
    virtual void SetHighlightColours(const wxColour& colFg,
                                     const wxColour& colBg);
    virtual void SetHoliday(size_t day);
    virtual void SetHolidayColours(const wxColour& colFg,
                                   const wxColour& colBg);
    virtual void Mark(size_t day, bool mark);
    virtual bool SetDateRange(const wxDateTime& lowerdate = wxDefaultDateTime,
                                const wxDateTime& upperdate = wxDefaultDateTime);
    virtual bool GetDateRange(wxDateTime *lowerdate,
                                wxDateTime *upperdate) const;
};