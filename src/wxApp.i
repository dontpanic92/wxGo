%rename(App) wxGoApp;
%{
	#include "wx/display.h"
	
	class wxGoApp : public wxApp{
	private:
		char * m_tempProgName;
	public:
		wxGoApp() : wxGoApp("wxGo") {
		}
		wxGoApp(const char * progName) : m_tempProgName(NULL){
			m_tempProgName = new char[strlen(progName) + 1];
			if (m_tempProgName) {
				strcpy(m_tempProgName, progName);
			}
			wxApp::SetInstance(this);
			SetExitOnFrameDelete(true);
			char* argv[] = {m_tempProgName, NULL};
			int argc = 1;
			wxEntryStart(argc, argv);
			CallOnInit();
		}
		
		~wxGoApp(){
			wxEntryCleanup();
			if (m_tempProgName) {
				delete[] m_tempProgName;
			}
		}
	};
%}

%include "wxGoInterface/app.h"
