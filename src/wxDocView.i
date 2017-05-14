%{
    #include "wx/docmdi.h"
    #include "wx/docview.h"
%}

%feature("director") wxView;
%feature("director") wxDocument;
%feature("director") wxDocTemplate;

%include "wxGoInterface/docmdi.h"
%include "wxGoInterface/docview.h"
