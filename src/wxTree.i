%typedef void *wxTreeItemIdValue;
%{
    #include "wx/treebase.h"
    #include "wx/treebook.h"
    #include "wx/treectrl.h"
    #include "wx/treelist.h"
%}

%include "wxGoInterface/treebase.h"
%include "wxGoInterface/treebook.h"
%include "wxGoInterface/treectrl.h"
%include "wxGoInterface/treelist.h"

WXGO_DECL_TYPECONV(VariantTreeItemData)
%inline {
    class wxVariantTreeItemData : public wxTreeItemData {
    public:
        wxVariantTreeItemData(const wxVariant& data) {
            m_variantData = data;
        }

        wxVariant& GetData() {
            return m_variantData;
        }
    protected:
        wxVariant m_variantData;
    };
}