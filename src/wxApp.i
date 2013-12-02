%rename(App) wxGoApp;
%{
	#include "wx/wx.h"
	#include "wx/display.h"
	
	class wxGoApp : public wxApp{
		
	public:
		wxGoApp(){
			wxApp::SetInstance(this);
			wxChar* argv[10] = {wxT("wxGo"), NULL};
			int argc = 1;
    		wxEntryStart(argc, (wxChar**)argv);
		}
		
  		void OnWindowDestroy(wxWindowDestroyEvent &event) 
  		{
			wxExit();
  		}

		int MainLoop(){
			this->Connect(wxEVT_DESTROY,
					wxWindowDestroyEventHandler(wxGoApp::OnWindowDestroy));
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
