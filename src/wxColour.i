%include "wxGoInterface/colour.h"

%inline {
	void ColourMakeDisabled(unsigned char* r, unsigned char* g, unsigned char* b, unsigned char brightness = 255){
		wxColour::MakeDisabled(r, g, b, brightness);
	}
	
	void ColourChangeLightness(unsigned char* r, unsigned char* g, unsigned char* b, int ialpha){
		wxColour::MakeDisabled(r, g, b, ialpha);
	}
}
