
%nodefaultctor wxTrackable;
%nodefaultdtor wxTrackable;
class wxTrackable{
public:
};


%{
    #include "wx/evtloop.h"
    #include "wx/kbdstate.h"
    #include "wx/mousestate.h"
%}

%include "wxGoInterface/evtloop.h"
%include "wxGoInterface/kbdstate.h"
%include "wxGoInterface/mousestate.h"

%{
class wxGoCallbackDispatcher : public wxEvtHandler{
public:
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
void Connect(wxEvtHandler* self, 
			 int id, 
			 int lastId, 
			 wxEventType eventType,
			 wxGoCallbackDispatcher* evtHandler) {
	
	self->Connect(id,
				  lastId, 
				  eventType,
				  (wxObjectEventFunction)&wxGoCallbackDispatcher::Callback,
				  NULL,
				  evtHandler);
	}
            
bool Disconnect(wxEvtHandler* self, 
				int id, int lastId, 
				wxEventType eventType,
                wxGoCallbackDispatcher* evtHandler){
                
	return self->Disconnect(id, 
					 lastId, 
					 eventType,
                     (wxObjectEventFunction)&wxGoCallbackDispatcher::Callback,
                     NULL,
                     evtHandler);
}

}


%insert(go_header) %{

type EventCallbackFunc func(Event)

type wxGoCallback struct {
	callbackFunc EventCallbackFunc
}

func (p *wxGoCallback) Callback(e Event) {
	p.callbackFunc(e)
}

type wxGoCallbackParameters struct {
	event int
	winid int
}

var evtCallbackMap = make(map[wxGoCallbackParameters] GoCallbackDispatcher)

%}


%insert(go_wrapper) %{

func Bind(evtHandler EvtHandler, event int, callback EventCallbackFunc, winid int) {
	newCallback := NewDirectorGoCallbackDispatcher(&wxGoCallback{callback})
	param := wxGoCallbackParameters{event, winid}
	evtCallbackMap[param] = newCallback
	Connect(evtHandler, winid, -1, event, newCallback)
}

func Unbind(evtHandler EvtHandler, event int, winid int) bool {
	param := wxGoCallbackParameters{event, winid}
	callbackDispatcher := evtCallbackMap[param]
	ret := Disconnect(evtHandler, param.winid, -1, param.event, callbackDispatcher)
	DeleteGoCallbackDispatcher(callbackDispatcher)
	delete(evtCallbackMap, param)
	return ret
}

%}
