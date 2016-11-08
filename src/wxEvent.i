%include wxTrackable.i

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
void Connect(wxEvtHandler* self, 
			 int id, 
			 int lastId, 
			 wxEventType eventType,
			 wxGoCallbackDispatcher* evtHandler, 
			 wxObject* obj){
	
	self->Connect(id,
				  lastId, 
				  eventType,
				  (wxObjectEventFunction)&wxGoCallbackDispatcher::CallbackFunc,
				  obj,
				  evtHandler);
	}
            
void Disconnect(wxEvtHandler* self, 
				int id, int lastId, 
				wxEventType eventType,
                wxGoCallbackDispatcher* evtHandler, 
                wxObject* obj){
                
	self->Disconnect(id, 
					 lastId, 
					 eventType,
                     (wxObjectEventFunction)&wxGoCallbackDispatcher::CallbackFunc,
                     obj,
                     evtHandler);
}

}


%insert(go_header) %{

type EventCallbackFunc func(Event)
        
var evtCallbackMap map[uintptr] EventCallbackFunc  
var dispatcherInit bool = false
var goCallbackDispatcher GoCallbackDispatcher
        
type goCallbackDispatcherClass struct { }
func (p *goCallbackDispatcherClass) Callback(evt Event) {
	obj := evt.GetEventUserData()
	value, ok := evtCallbackMap[obj.Swigcptr()]
	if ok {
		value(evt)
	}
}
        
func MakeDispatcher(){
	//MultiThread unsafe
	if !dispatcherInit {
		goCallbackDispatcher = NewDirectorGoCallbackDispatcher(&goCallbackDispatcherClass{})
		evtCallbackMap = make(map[uintptr] EventCallbackFunc)
		dispatcherInit = true
	}
}
%}


%insert(go_wrapper) %{

func Bind(evtHandler EvtHandler, event int, callback EventCallbackFunc, winid int) {
	if !dispatcherInit {
		MakeDispatcher()
	}
	obj := NewObject()
	evtCallbackMap[obj.Swigcptr()] = callback
	Connect(evtHandler, winid, -1, event, goCallbackDispatcher, obj)
}

func Unbind(evtHandler EvtHandler, event int, callback EventCallbackFunc, winid int) {
	if !dispatcherInit {
		return
	}
	for k := range evtCallbackMap {
		if func_pointers_are_equal(evtCallbackMap[k], callback) {
			obj := SwigcptrObject(k)
			Disconnect(evtHandler, winid, -1, event, goCallbackDispatcher, obj)
			DeleteObject(obj)
			delete(evtCallbackMap, k)
		}
	}
}

%}
