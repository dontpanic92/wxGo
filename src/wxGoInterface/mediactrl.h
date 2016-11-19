%typedef int wxMediaState;
#define wxMEDIASTATE_STOPPED 0
#define wxMEDIASTATE_PAUSED wxMEDIASTATE_STOPPED + 1
#define wxMEDIASTATE_PLAYING wxMEDIASTATE_PAUSED + 1
%typedef int wxMediaCtrlPlayerControls;
#define wxMEDIACTRLPLAYERCONTROLS_NONE            0
#define wxMEDIACTRLPLAYERCONTROLS_STEP            1 << 0
#define wxMEDIACTRLPLAYERCONTROLS_VOLUME          1 << 1
#define wxMEDIACTRLPLAYERCONTROLS_DEFAULT         wxMEDIACTRLPLAYERCONTROLS_STEP |                    wxMEDIACTRLPLAYERCONTROLS_VOLUME
WXGO_DECL_TYPECONV(MediaEvent)
class wxMediaEvent : public wxNotifyEvent
{
public:
    wxMediaEvent(wxEventType commandType = wxEVT_NULL, int winid = 0);
};
WXGO_DECL_TYPECONV(MediaCtrl)
class wxMediaCtrl : public wxControl
{
public:
    wxMediaCtrl();
    wxMediaCtrl(wxWindow* parent, wxWindowID id, const wxString& fileName = wxEmptyString,
                const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize,
                long style = 0, const wxString& szBackend = wxEmptyString,
                const wxValidator& validator = wxDefaultValidator,
                const wxString& name = "mediaCtrl");
    bool Create(wxWindow* parent, wxWindowID id, const wxString& fileName = wxEmptyString,
                const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize,
                long style = 0, const wxString& szBackend = wxEmptyString,
                const wxValidator& validator = wxDefaultValidator,
                const wxString& name = "mediaCtrl");
    wxSize GetBestSize() const;
    double GetPlaybackRate();
    wxMediaState GetState();
    double GetVolume();
    wxFileOffset Length();
    bool Load(const wxString& fileName);
    bool LoadURI(const wxString& fileName);
    bool LoadURIWithProxy(const wxString& fileName, const wxString& proxy);
    bool Pause();
    bool Play();
    wxFileOffset Seek(wxFileOffset where, wxSeekMode mode = wxFromStart);
    bool SetPlaybackRate(double dRate);
    bool SetVolume(double dVolume);
    bool ShowPlayerControls(wxMediaCtrlPlayerControls flags = wxMEDIACTRLPLAYERCONTROLS_DEFAULT);
    bool Stop();
    wxFileOffset Tell();
};
%constant wxEventType wxEVT_MEDIA_LOADED;
%constant wxEventType wxEVT_MEDIA_STOP;
%constant wxEventType wxEVT_MEDIA_FINISHED;
%constant wxEventType wxEVT_MEDIA_STATECHANGED;
%constant wxEventType wxEVT_MEDIA_PLAY;
%constant wxEventType wxEVT_MEDIA_PAUSE;