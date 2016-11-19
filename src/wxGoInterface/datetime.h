WXGO_DECL_TYPECONV(DateTime)
class wxDateTime
{
public:
    typedef unsigned short wxDateTime_t;
    enum TZ
    {
        Local,
        GMT_12, GMT_11, GMT_10, GMT_9, GMT_8, GMT_7,
        GMT_6, GMT_5, GMT_4, GMT_3, GMT_2, GMT_1,
        GMT0,
        GMT1, GMT2, GMT3, GMT4, GMT5, GMT6,
        GMT7, GMT8, GMT9, GMT10, GMT11, GMT12, GMT13,
        WET = GMT0,         
        WEST = GMT1,        
        CET = GMT1,         
        CEST = GMT2,        
        EET = GMT2,         
        EEST = GMT3,        
        MSK = GMT3,         
        MSD = GMT4,         
        AST = GMT_4,        
        ADT = GMT_3,        
        EST = GMT_5,        
        EDT = GMT_4,        
        CST = GMT_6,        
        CDT = GMT_5,        
        MST = GMT_7,        
        MDT = GMT_6,        
        PST = GMT_8,        
        PDT = GMT_7,        
        HST = GMT_10,       
        AKST = GMT_9,       
        AKDT = GMT_8,       
        A_WST = GMT8,       
        A_CST = GMT13 + 1,  
        A_EST = GMT10,      
        A_ESST = GMT11,     
        NZST = GMT12,       
        NZDT = GMT13,       
        UTC = GMT0
    };
    enum Calendar
    {
        Gregorian,  
        Julian      
    };
    enum Country
    {
        Country_Unknown, 
        Country_Default, 
        Country_WesternEurope_Start,
        Country_EEC = Country_WesternEurope_Start,
        France,
        Germany,
        UK,
        Country_WesternEurope_End = UK,
        Russia,
        USA
    };
    enum Month
    {
        Jan, Feb, Mar, Apr, May, Jun, Jul, Aug, Sep, Oct, Nov, Dec,
        Inv_Month
    };
    enum WeekDay
    {
        Sun, Mon, Tue, Wed, Thu, Fri, Sat,
        Inv_WeekDay
    };
    enum Year
    {
        Inv_Year = SHRT_MIN    
    };
    enum NameFlags
    {
        Name_Full = 0x01,       
        Name_Abbr = 0x02        
    };
    enum WeekFlags
    {
        Default_First,   
        Monday_First,    
        Sunday_First     
    };
    class TimeZone
    {
    public:
        TimeZone(TZ tz);
        TimeZone(long offset = 0);
        static TimeZone Make(long offset);
        long GetOffset() const;
    };
    struct Tm
    {
        wxDateTime_t msec,  
                     sec,   
                     min,   
                     hour,  
                     mday,  
                     yday;  
        Month mon;          
        int year;           
        bool IsValid() const;
        WeekDay GetWeekDay();
    };
    wxDateTime();
    wxDateTime(const wxDateTime& date);
    wxDateTime(time_t timet);
    wxDateTime(const struct tm& tm);
    wxDateTime(double jdn);
    wxDateTime(wxDateTime_t hour, wxDateTime_t minute = 0,
               wxDateTime_t second = 0, wxDateTime_t millisec = 0);
    wxDateTime(wxDateTime_t day, Month month,
               int year = Inv_Year, wxDateTime_t hour = 0,
               wxDateTime_t minute = 0, wxDateTime_t second = 0,
               wxDateTime_t millisec = 0);
    wxDateTime& ResetTime();
    wxDateTime& Set(time_t timet);
    wxDateTime& Set(const struct tm& tm);
    wxDateTime& Set(const Tm& tm);
    wxDateTime& Set(double jdn);
    wxDateTime& Set(wxDateTime_t hour, wxDateTime_t minute = 0,
                    wxDateTime_t second = 0, wxDateTime_t millisec = 0);
    wxDateTime& Set(wxDateTime_t day, Month month,
                    int year = Inv_Year, wxDateTime_t hour = 0,
                    wxDateTime_t minute = 0, wxDateTime_t second = 0,
                    wxDateTime_t millisec = 0);
    wxDateTime& SetDay(unsigned short day);
    wxDateTime& SetFromDOS(unsigned long ddt);
    wxDateTime& SetHour(unsigned short hour);
    wxDateTime& SetMillisecond(unsigned short millisecond);
    wxDateTime& SetMinute(unsigned short minute);
    wxDateTime& SetMonth(Month month);
    wxDateTime& SetSecond(unsigned short second);
    wxDateTime& SetToCurrent();
    wxDateTime& SetYear(int year);
    wxDateTime& operator=(time_t timet);
    wxDateTime& operator=(const struct tm& tm);
    unsigned long GetAsDOS() const;
    int GetCentury(const TimeZone& tz = Local) const;
    wxDateTime GetDateOnly() const;
    unsigned short GetDay(const TimeZone& tz = Local) const;
    unsigned short GetDayOfYear(const TimeZone& tz = Local) const;
    unsigned short GetHour(const TimeZone& tz = Local) const;
    unsigned short GetMillisecond(const TimeZone& tz = Local) const;
    unsigned short GetMinute(const TimeZone& tz = Local) const;
    Month GetMonth(const TimeZone& tz = Local) const;
    unsigned short GetSecond(const TimeZone& tz = Local) const;
    time_t GetTicks() const;
    Tm GetTm(const TimeZone& tz = Local) const;
    WeekDay GetWeekDay(const TimeZone& tz = Local) const;
    int GetWeekBasedYear(const TimeZone& tz) const;
    wxDateTime_t GetWeekOfMonth(WeekFlags flags = Monday_First,
                                const TimeZone& tz = Local) const;
    wxDateTime_t GetWeekOfYear(WeekFlags flags = Monday_First,
                               const TimeZone& tz = Local) const;
    int GetYear(const TimeZone& tz = Local) const;
    bool IsValid() const;
    bool IsWorkDay(Country country = Country_Default) const;
    bool IsEarlierThan(const wxDateTime& datetime) const;
    bool IsEqualTo(const wxDateTime& datetime) const;
    bool IsEqualUpTo(const wxDateTime& dt, const wxTimeSpan& ts) const;
    bool IsLaterThan(const wxDateTime& datetime) const;
    bool IsSameDate(const wxDateTime& dt) const;
    bool IsSameTime(const wxDateTime& dt) const;
    bool IsStrictlyBetween(const wxDateTime& t1,
                            const wxDateTime& t2) const;
    bool IsBetween(const wxDateTime& t1, const wxDateTime& t2) const;
    wxDateTime Add(const wxDateSpan& diff) const;
    wxDateTime Add(const wxTimeSpan& diff) const;
    wxDateTime Subtract(const wxTimeSpan& diff) const;
    wxDateTime Subtract(const wxDateSpan& diff) const;
    wxTimeSpan Subtract(const wxDateTime& dt) const;
    wxDateSpan DiffAsDateSpan(const wxDateTime& dt) const;
    wxString Format(const wxString& format = wxDefaultDateTimeFormat,
                    const TimeZone& tz = Local) const;
    wxString FormatDate() const;
    wxString FormatISOCombined(char sep = 'T') const;
    wxString FormatISODate() const;
    wxString FormatISOTime() const;
    wxString FormatTime() const;
    bool ParseDate(const wxString& date, wxString::const_iterator *end);
    bool ParseDateTime(const wxString& datetime, wxString::const_iterator *end);
    bool ParseFormat(const wxString& date,
                     const wxString& format,
                     const wxDateTime& dateDef,
                     wxString::const_iterator *end);
    bool ParseFormat(const wxString& date,
                     const wxString& format,
                     wxString::const_iterator *end);
    bool ParseFormat(const wxString& date, wxString::const_iterator *end);
    bool ParseISOCombined(const wxString& date, char sep = 'T');
    bool ParseISODate(const wxString& date);
    bool ParseISOTime(const wxString& date);
    bool ParseRfc822Date(const wxString& date, wxString::const_iterator *end);
    bool ParseTime(const wxString& time, wxString::const_iterator *end);
    wxDateTime GetLastMonthDay(Month month = Inv_Month,
                               int year = Inv_Year) const;
    wxDateTime GetLastWeekDay(WeekDay weekday, Month month = Inv_Month,
                              int year = Inv_Year);
    wxDateTime GetNextWeekDay(WeekDay weekday) const;
    wxDateTime GetPrevWeekDay(WeekDay weekday) const;
    wxDateTime GetWeekDay(WeekDay weekday, int n = 1, Month month = Inv_Month,
                          int year = Inv_Year) const;
    wxDateTime GetWeekDayInSameWeek(WeekDay weekday,
                                    WeekFlags flags = Monday_First) const;
    wxDateTime GetYearDay(wxDateTime_t yday) const;
    wxDateTime& SetToLastMonthDay(Month month = Inv_Month, int year = Inv_Year);
    bool SetToLastWeekDay(WeekDay weekday, Month month = Inv_Month,
                          int year = Inv_Year);
    wxDateTime& SetToNextWeekDay(WeekDay weekday);
    wxDateTime& SetToPrevWeekDay(WeekDay weekday);
    bool SetToWeekDay(WeekDay weekday, int n = 1,
                       Month month = Inv_Month, int year = Inv_Year);
    wxDateTime& SetToWeekDayInSameWeek(WeekDay weekday,
                                      WeekFlags flags = Monday_First);
    wxDateTime& SetToYearDay(wxDateTime_t yday);
    double GetJDN() const;
    double GetJulianDayNumber() const;
    double GetMJD() const;
    double GetModifiedJulianDayNumber() const;
    double GetRataDie() const;
    wxDateTime FromTimezone(const TimeZone& tz, bool noDST = false) const;
    int IsDST(Country country = Country_Default) const;
    wxDateTime& MakeFromTimezone(const TimeZone& tz, bool noDST = false);
    wxDateTime& MakeTimezone(const TimeZone& tz, bool noDST = false);
    wxDateTime& MakeUTC(bool noDST = false);
    wxDateTime ToTimezone(const TimeZone& tz, bool noDST = false) const;
    wxDateTime ToUTC(bool noDST = false) const;
    static int ConvertYearToBC(int year);
    static void GetAmPmStrings(wxString* am, wxString* pm);
    static wxDateTime GetBeginDST(int year = Inv_Year,
                                   Country country = Country_Default);
    static wxDateTime GetEndDST(int year = Inv_Year,
                                 Country country = Country_Default);
    static int GetCentury(int year);
    static Country GetCountry();
    static Month GetCurrentMonth(Calendar cal = Gregorian);
    static int GetCurrentYear(Calendar cal = Gregorian);
    static wxString GetEnglishMonthName(Month month,
                                        NameFlags flags = Name_Full);
    static wxString GetEnglishWeekDayName(WeekDay weekday,
                                          NameFlags flags = Name_Full);
    static wxString GetMonthName(Month month, NameFlags flags = Name_Full);
    static wxDateTime_t GetNumberOfDays(int year, Calendar cal = Gregorian);
    static wxDateTime_t GetNumberOfDays(Month month, int year = Inv_Year,
                                        Calendar cal = Gregorian);
    static time_t GetTimeNow();
    static tm* GetTmNow(struct tm *tm);
    static tm* GetTmNow();
    static wxString GetWeekDayName(WeekDay weekday,
                                   NameFlags flags = Name_Full);
    static bool IsDSTApplicable(int year = Inv_Year,
                                  Country country = Country_Default);
    static bool IsLeapYear(int year = Inv_Year, Calendar cal = Gregorian);
    static bool IsWestEuropeanCountry(Country country = Country_Default);
    static wxDateTime Now();
    static void SetCountry(Country country);
    static wxDateTime SetToWeekOfYear(int year, wxDateTime_t numWeek,
                                       WeekDay weekday = Mon);
    static wxDateTime Today();
    static wxDateTime UNow();
};
WXGO_GETTER_TO_VAR(DateTime, DefaultDateTime);
const wxDateTime wxDefaultDateTime;
WXGO_GETTER_TO_VAR(DateTime, InvalidDateTime);
const wxDateTime wxInvalidDateTime;
WXGO_DECL_TYPECONV(DateTimeWorkDays)
class wxDateTimeWorkDays
{
public:
};
WXGO_DECL_TYPECONV(DateSpan)
class wxDateSpan
{
public:
    wxDateSpan(int years = 0, int months = 0, int weeks = 0, int days = 0);
    wxDateSpan& Add(const wxDateSpan& other);
    static wxDateSpan Day();
    static wxDateSpan Days(int days);
    int GetDays() const;
    int GetMonths() const;
    int GetTotalMonths() const;
    int GetTotalDays() const;
    int GetWeeks() const;
    int GetYears() const;
    static wxDateSpan Month();
    static wxDateSpan Months(int mon);
    wxDateSpan& Multiply(int factor);
    wxDateSpan& Neg();
    wxDateSpan Negate() const;
    wxDateSpan& SetDays(int n);
    wxDateSpan& SetMonths(int n);
    wxDateSpan& SetWeeks(int n);
    wxDateSpan& SetYears(int n);
    wxDateSpan& Subtract(const wxDateSpan& other);
    static wxDateSpan Week();
    static wxDateSpan Weeks(int weeks);
    static wxDateSpan Year();
    static wxDateSpan Years(int years);
    bool operator!=(const wxDateSpan& other) const;
    bool operator==(const wxDateSpan& other) const;
};
WXGO_DECL_TYPECONV(TimeSpan)
class wxTimeSpan
{
public:
    wxTimeSpan();
    wxTimeSpan(long hours, long min = 0, wxLongLong sec = 0, wxLongLong msec = 0);
    wxTimeSpan Abs() const;
    wxTimeSpan& Add(const wxTimeSpan& diff);
    static wxTimeSpan Day();
    static wxTimeSpan Days(long days);
    wxString Format(const wxString& format = wxDefaultTimeSpanFormat) const;
    int GetDays() const;
    int GetHours() const;
    wxLongLong GetMilliseconds() const;
    int GetMinutes() const;
    wxLongLong GetSeconds() const;
    wxLongLong GetValue() const;
    int GetWeeks() const;
    static wxTimeSpan Hour();
    static wxTimeSpan Hours(long hours);
    bool IsEqualTo(const wxTimeSpan& ts) const;
    bool IsLongerThan(const wxTimeSpan& ts) const;
    bool IsNegative() const;
    bool IsNull() const;
    bool IsPositive() const;
    bool IsShorterThan(const wxTimeSpan& ts) const;
    static wxTimeSpan Millisecond();
    static wxTimeSpan Milliseconds(wxLongLong ms);
    static wxTimeSpan Minute();
    static wxTimeSpan Minutes(long min);
    wxTimeSpan& Multiply(int n);
    wxTimeSpan& Neg();
    wxTimeSpan Negate() const;
    static wxTimeSpan Second();
    static wxTimeSpan Seconds(wxLongLong sec);
    wxTimeSpan& Subtract(const wxTimeSpan& diff);
    static wxTimeSpan Week();
    static wxTimeSpan Weeks(long weeks);
};
%nodefaultctor wxDateTimeHolidayAuthority;
WXGO_DECL_TYPECONV(DateTimeHolidayAuthority)
class wxDateTimeHolidayAuthority
{
public:
};