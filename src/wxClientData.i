%{
	#include "wx/clntdata.h"
%}
%include "wxGoInterface/clntdata.h"

WXGO_DECL_TYPECONV(VariantClientData)
%inline {
    class wxVariantClientData : public wxClientData {
    public:
        wxVariantClientData(const wxVariant& data) {
            m_variantData = data;
        }

        wxVariant& GetData() {
            return m_variantData;
        }
    protected:
        wxVariant m_variantData;
    };
}
