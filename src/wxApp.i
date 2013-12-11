%rename(App) wxGoApp;
%{
	#include "wx/display.h"
	
	class wxGoApp : public wxApp{
	public:
		wxGoApp(){
			wxApp::SetInstance(this);
			char progName[] = {"wxGo"};
			char* argv[] = {progName, NULL};
			int argc = 1;
    		wxEntryStart(argc, argv);
    		SetExitOnFrameDelete(true);
		}

		int MainLoop(){
			return wxApp::MainLoop();
		}
		
		~wxGoApp(){
			wxEntryCleanup();
		}
	};
	
	wxIMPLEMENT_APP_NO_MAIN(wxGoApp);
%}

%include "wxGoInterface/app.h"

wxGoApp& wxGetApp();                                       
