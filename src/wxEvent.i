%{
        #include "wx/wx.h"
%}

%import wxTrackable.i

enum wxMouseButton
{
    wxMOUSE_BTN_ANY     = -1,
    wxMOUSE_BTN_NONE    = 0,
    wxMOUSE_BTN_LEFT    = 1,
    wxMOUSE_BTN_MIDDLE  = 2,
    wxMOUSE_BTN_RIGHT   = 3,
    wxMOUSE_BTN_AUX1    = 4,
    wxMOUSE_BTN_AUX2    = 5,
    wxMOUSE_BTN_MAX
};
class wxKeyboardState
{
public:
    wxKeyboardState(bool controlDown = false,
                    bool shiftDown = false,
                    bool altDown = false,
                    bool metaDown = false);

    int GetModifiers() const;
    bool HasAnyModifiers() const;
    bool HasModifiers() const;
    bool ControlDown() const;
    bool RawControlDown() const;
    bool ShiftDown() const;
    bool MetaDown() const;
    bool AltDown() const;
    bool CmdDown() const;
    
    void SetControlDown(bool down);
    void SetRawControlDown(bool down);
    void SetShiftDown(bool down);
    void SetAltDown(bool down);
    void SetMetaDown(bool down);
};

class wxMouseState : public wxKeyboardState
{
public:
    bool LeftIsDown() const;
    bool MiddleIsDown() const;
    bool RightIsDown() const;
    bool Aux1IsDown() const;
    bool Aux2IsDown() const;

    void SetX(wxCoord x);
    void SetY(wxCoord y);
    void SetPosition(wxPoint pos);
    
    void SetLeftDown(bool down);
    void SetMiddleDown(bool down);
    void SetRightDown(bool down);
    void SetAux1Down(bool down);
    void SetAux2Down(bool down);

    void SetState(const wxMouseState& state);  
};

%{
class wxGoCallbackDispatcher : public wxEvtHandler{
public:
        void CallbackFunc(wxEvent& event){
                this->Callback(event);
        }
        virtual void Callback(wxEvent& event) = 0;
        virtual ~wxGoCallbackDispatcher(){}
};
%}

%include "wxGoInterface/event.h"

%feature("director") wxGoCallbackDispatcher;

class wxGoCallbackDispatcher : public wxEvtHandler{
public:
        virtual void Callback(wxEvent& event) = 0;
        virtual ~wxGoCallbackDispatcher(){}
};



%inline {
        void Connect(wxEvtHandler* self, int id, int lastId, wxEventType eventType,
                 wxGoCallbackDispatcher* evtHandler, wxObject* obj){
                self->Connect(id, lastId, eventType,
                                 (wxObjectEventFunction)&wxGoCallbackDispatcher::CallbackFunc,
                                 obj,
                                 evtHandler);
            }
            
    void Disconnect(wxEvtHandler* self, int id, int lastId, wxEventType eventType,
                 wxGoCallbackDispatcher* evtHandler, wxObject* obj){
                self->Disconnect(id, lastId, eventType,
                                 (wxObjectEventFunction)&wxGoCallbackDispatcher::CallbackFunc,
                                 obj,
                                 evtHandler);
            }
}


%insert(go_header) %{

        type EventCallbackFunc func(Event)
        
        var evtCallbackMap map[Object] EventCallbackFunc  
        var dispatcherInit bool = false
        var goCallbackDispatcher GoCallbackDispatcher
        
        type goCallbackDispatcherClass struct { }
        func (p *goCallbackDispatcherClass) Callback(evt Event) {
                obj := evt.GetEventUserData()
                value, ok := evtCallbackMap[obj]
                if ok {
                        value(evt)
                }
        }
        
        func MakeDispatcher(){
                //MultiThread unsafe
                if !dispatcherInit {
                        goCallbackDispatcher = NewDirectorGoCallbackDispatcher(&goCallbackDispatcherClass{})
                        evtCallbackMap = make(map[Object] EventCallbackFunc)
                        dispatcherInit = true
                }
        }
%}


%insert(go_wrapper) %{

func Bind(evtHandler EvtHandler, event int,
              callback EventCallbackFunc,
              winid int) {
        if !dispatcherInit {
                MakeDispatcher()
        }
        obj := NewObject()
        evtCallbackMap[obj] = callback
        Connect(evtHandler, winid, -1, event, goCallbackDispatcher, obj)
}

func Unbind(evtHandler EvtHandler, event int,
              callback EventCallbackFunc,
              winid int) {
        if !dispatcherInit {
                return
        }
        for k := range evtCallbackMap {
                if func_pointer_is_equal(evtCallbackMap[k], callback) {
                        Disconnect(evtHandler, winid, -1, event, goCallbackDispatcher, k)
                        delete(evtCallbackMap, k)
                }
        }
}
%}
