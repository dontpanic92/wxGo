%{
	#include "wx/wx.h"
%}

%include "wxGoInterface/colour.h"

%inline {
	void ColourMakeDisabled(unsigned char* r, unsigned char* g, unsigned char* b, unsigned char brightness = 255){
		wxColour::MakeDisabled(r, g, b, brightness);
	}
	
	void ColourChangeLightness(unsigned char* r, unsigned char* g, unsigned char* b, int ialpha){
		wxColour::MakeDisabled(r, g, b, ialpha);
	}
	
	const wxColour* GetBLACK(){
		return wxBLACK;
	}
	const wxColour* GetBLUE(){
		return wxBLUE;
	}
	const wxColour* GetCYAN(){
		return wxCYAN;
	}
	const wxColour* GetGREEN(){
		return wxGREEN;
	}
	const wxColour* GetYELLOW(){
		return wxYELLOW;
	}
	const wxColour* GetLIGHT_GREY(){
		return wxLIGHT_GREY;
	}
	const wxColour* GetRED(){
		return wxRED;
	}
	const wxColour* GetWHITE(){
		return wxWHITE;
	}
}

%insert(go_wrapper) {
var BLACK Colour = GetBLACK()
var BLUE Colour = GetBLUE()
var CYAN Colour = GetCYAN()
var GREEN Colour = GetGREEN()
var YELLOW Colour = GetYELLOW()
var LIGHT_GREY Colour = GetLIGHT_GREY()
var RED Colour = GetRED()
var WHITE Colour = GetWHITE()
}
