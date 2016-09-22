%{
#ifdef __WXOSX__
    #include "wx/html/webkit.h"
#endif
    #include "wx/html/helpctrl.h"
    #include "wx/html/helpdata.h"
    #include "wx/html/helpdlg.h"
    #include "wx/html/helpfrm.h"
    #include "wx/html/helpwnd.h"
    #include "wx/html/htmlcell.h"
    #include "wx/html/htmldefs.h"
    #include "wx/html/htmlfilt.h"
    #include "wx/html/htmlpars.h"
    #include "wx/html/htmltag.h"
    #include "wx/html/htmlwin.h"
    #include "wx/html/htmprint.h"
    #include "wx/html/winpars.h"
%}

#ifdef __WXOSX__
%include "wxGoInterface/html/webkit.h"
#endif

%include "wxGoInterface/html/helpctrl.h"
%include "wxGoInterface/html/helpdata.h"
%include "wxGoInterface/html/helpdlg.h"
%include "wxGoInterface/html/helpfrm.h"
%include "wxGoInterface/html/helpwnd.h"
%include "wxGoInterface/html/htmlcell.h"
%include "wxGoInterface/html/htmldefs.h"
%include "wxGoInterface/html/htmlfilt.h"
%include "wxGoInterface/html/htmlpars.h"
%include "wxGoInterface/html/htmltag.h"
%include "wxGoInterface/html/htmlwin.h"
%include "wxGoInterface/html/htmprint.h"
%include "wxGoInterface/html/winpars.h"