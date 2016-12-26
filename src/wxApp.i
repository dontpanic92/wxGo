%rename(App) wxGoApp;
%{
	#include "wx/display.h"
	
	class wxGoApp : public wxApp{
	public:
		wxGoApp(wxString progName = "wxGo"){
			wxApp::SetInstance(this);
    		SetExitOnFrameDelete(true);
			const char* progUtf8 = progName.utf8_str();
			char* progNameBuf = new char[strlen(progUtf8) + 1];
			char* argv[] = {progNameBuf, NULL};
			int argc = 1;
    		wxEntryStart(argc, argv);
			CallOnInit();
			delete[] progNameBuf;
		}
		
		~wxGoApp(){
			wxEntryCleanup();
		}
	};
%}

%include "wxGoInterface/app.h"
