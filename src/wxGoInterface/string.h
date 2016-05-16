class wxString
{
public:
    wxString(const wxString& stringSrc);
    ~wxString();
    %extend{
    	wxString(const char* pzr){
    		return new wxString(pzr, wxConvUTF8);
    	}
    	const char* utf8_str(){
    		const char* str = self->utf8_str();
    		return str;
    	}
    }
};