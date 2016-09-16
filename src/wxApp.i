%rename(App) wxGoApp;
%{
	#include "wx/display.h"
	
	class wxGoApp : public wxApp{
	public:
		wxGoApp(){
			wxApp::SetInstance(this);
    		SetExitOnFrameDelete(true);
			char progName[] = {"wxGo"};
			char* argv[] = {progName, NULL};
			int argc = 1;
    		wxEntryStart(argc, argv);
			CallOnInit();
		}
		
		~wxGoApp(){
			wxEntryCleanup();
		}
	};
%}

%include "wxGoInterface/app.h"
