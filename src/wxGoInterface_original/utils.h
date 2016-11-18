/////////////////////////////////////////////////////////////////////////////
// Name:        utils.h
// Purpose:     interface of various utility classes and functions
// Author:      wxWidgets team
// Licence:     wxWindows licence
/////////////////////////////////////////////////////////////////////////////

/**
    Signal constants used by wxProcess.
*/
/*enum wxSignal
{
    wxSIGNONE = 0,  //!< verify if the process exists under Unix
    wxSIGHUP,
    wxSIGINT,
    wxSIGQUIT,
    wxSIGILL,
    wxSIGTRAP,
    wxSIGABRT,
    wxSIGEMT,
    wxSIGFPE,
    wxSIGKILL,      //!< forcefully kill, dangerous!
    wxSIGBUS,
    wxSIGSEGV,
    wxSIGSYS,
    wxSIGPIPE,
    wxSIGALRM,
    wxSIGTERM       //!< terminate the process gently
};

/**
    Return values for wxProcess::Kill.
*/
/*enum wxKillError
{
    wxKILL_OK,              //!< no error
    wxKILL_BAD_SIGNAL,      //!< no such signal
    wxKILL_ACCESS_DENIED,   //!< permission denied
    wxKILL_NO_PROCESS,      //!< no such process
    wxKILL_ERROR            //!< another, unspecified error
};

enum wxKillFlags
{
    wxKILL_NOCHILDREN = 0,  //!< don't kill children
    wxKILL_CHILDREN = 1     //!< kill children
};

enum wxShutdownFlags
{
    wxSHUTDOWN_FORCE    = 1, //!< can be combined with other flags (MSW-only)
    wxSHUTDOWN_POWEROFF = 2, //!< power off the computer
    wxSHUTDOWN_REBOOT   = 4, //!< shutdown and reboot
    wxSHUTDOWN_LOGOFF   = 8  //!< close session (currently MSW-only)
};*/


/**
    @class wxWindowDisabler

    This class disables all windows of the application (may be with the
    exception of one of them) in its constructor and enables them back in its
    destructor.

    This is useful when you want to indicate to the user that the application
    is currently busy and cannot respond to user input.

    @library{wxcore}
    @category{misc}

    @see wxBusyCursor
*/
class wxWindowDisabler
{
public:
    /**
        Disables all top level windows of the applications.

        If @a disable is @c false nothing is done. This can be convenient if
        the windows should be disabled depending on some condition.

        @since 2.9.0
    */
    wxWindowDisabler(bool disable = true);

    /**
        Disables all top level windows of the applications with the exception
        of @a winToSkip if it is not @NULL.

        Notice that under MSW if @a winToSkip appears in the taskbar, the user
        will be able to close the entire application (even though its main
        window is disabled) by right clicking on the taskbar icon and selecting
        the appropriate "Close" command from the context menu. To prevent this
        from happening you may want to use wxFRAME_TOOL_WINDOW, if applicable,
        or wxFRAME_NO_TASKBAR style when creating the window that will remain
        enabled.
    */
    wxWindowDisabler(wxWindow* winToSkip);

    /**
        Reenables the windows disabled by the constructor.
    */
    ~wxWindowDisabler();
};



/**
    @class wxBusyCursor

    This class makes it easy to tell your user that the program is temporarily
    busy. Just create a wxBusyCursor object on the stack, and within the
    current scope, the hourglass will be shown.

    For example:

    @code
    wxBusyCursor wait;

    for (int i = 0; i < 100000; i++)
        DoACalculation();
    @endcode

    It works by calling wxBeginBusyCursor() in the constructor, and
    wxEndBusyCursor() in the destructor.

    @library{wxcore}
    @category{misc}

    @see wxBeginBusyCursor(), wxEndBusyCursor(), wxWindowDisabler
*/
class wxBusyCursor
{
public:
    /**
        Constructs a busy cursor object, calling wxBeginBusyCursor().
    */
    wxBusyCursor(const wxCursor* cursor = wxHOURGLASS_CURSOR);

    /**
        Destroys the busy cursor object, calling wxEndBusyCursor().
    */
    ~wxBusyCursor();
};



// ============================================================================
// Global functions/macros
// ============================================================================


/** @addtogroup group_funcmacro_dialog */
//@{

/**
    Changes the cursor to the given cursor for all windows in the application.
    Use wxEndBusyCursor() to revert the cursor back to its previous state.
    These two calls can be nested, and a counter ensures that only the outer
    calls take effect.

    @see wxIsBusy(), wxBusyCursor

    @header{wx/utils.h}
*/
void wxBeginBusyCursor(const wxCursor* cursor = wxHOURGLASS_CURSOR);

/**
    Changes the cursor back to the original cursor, for all windows in the
    application. Use with wxBeginBusyCursor().

    @see wxIsBusy(), wxBusyCursor

    @header{wx/utils.h}
*/
void wxEndBusyCursor();

/**
    Returns @true if between two wxBeginBusyCursor() and wxEndBusyCursor()
    calls.

    @see wxBusyCursor.

    @header{wx/utils.h}
*/
bool wxIsBusy();

/**
    Ring the system bell.

    @note This function is categorized as a GUI one and so is not thread-safe.

    @header{wx/utils.h}

    @library{wxcore}
*/
void wxBell();

/**
    Shows a message box with the information about the wxWidgets build used,
    including its version, most important build parameters and the version of
    the underlying GUI toolkit. This is mainly used for diagnostic purposes
    and can be invoked by Ctrl-Alt-middle clicking on any wxWindow which
    doesn't otherwise handle this event.

    @since 2.9.0

    @see wxGetLibraryVersionInfo()

    @header{wx/utils.h}
*/
void wxInfoMessageBox(wxWindow* parent);

//@}

/** @addtogroup group_funcmacro_version */
//@{

/**
    Get wxWidgets version information.

    @since 2.9.2

    @see wxVersionInfo

    @header{wx/utils.h}

    @library{wxcore}
*/
wxVersionInfo wxGetLibraryVersionInfo();

//@}


/** @addtogroup group_funcmacro_misc */
//@{

/**
    Returns battery state as one of @c wxBATTERY_NORMAL_STATE,
    @c wxBATTERY_LOW_STATE, @c wxBATTERY_CRITICAL_STATE,
    @c wxBATTERY_SHUTDOWN_STATE or @c wxBATTERY_UNKNOWN_STATE.
    @c wxBATTERY_UNKNOWN_STATE is also the default on platforms where this
    feature is not implemented (currently everywhere but MS Windows).

    @header{wx/utils.h}
*/
//wxBatteryState wxGetBatteryState();

/**
    Returns the type of power source as one of @c wxPOWER_SOCKET,
    @c wxPOWER_BATTERY or @c wxPOWER_UNKNOWN. @c wxPOWER_UNKNOWN is also the
    default on platforms where this feature is not implemented (currently
    everywhere but MS Windows).

    @header{wx/utils.h}
*/
//wxPowerType wxGetPowerType();

/**
    Under X only, returns the current display name.

    @see wxSetDisplayName()

    @header{wx/utils.h}
*/
//wxString wxGetDisplayName();

/**
    For normal keys, returns @true if the specified key is currently down.

    For togglable keys (Caps Lock, Num Lock and Scroll Lock), returns @true if
    the key is toggled such that its LED indicator is lit. There is currently
    no way to test whether togglable keys are up or down.

    Even though there are virtual key codes defined for mouse buttons, they
    cannot be used with this function currently.

    @header{wx/utils.h}
*/
bool wxGetKeyState(wxKeyCode key);

/**
    Returns the mouse position in screen coordinates.

    @header{wx/utils.h}
*/
wxPoint wxGetMousePosition();

/**
    Returns the current state of the mouse.  Returns a wxMouseState instance
    that contains the current position of the mouse pointer in screen
    coordinates, as well as boolean values indicating the up/down status of the
    mouse buttons and the modifier keys.

    @header{wx/utils.h}
*/
wxMouseState wxGetMouseState();

/**
    This function enables or disables all top level windows. It is used by
    wxSafeYield().

    @header{wx/utils.h}
*/
void wxEnableTopLevelWindows(bool enable = true);

/**
    Find the deepest window at the given mouse position in screen coordinates,
    returning the window if found, or @NULL if not.

    This function takes child windows at the given position into account even
    if they are disabled. The hidden children are however skipped by it.

    @header{wx/utils.h}
*/
wxWindow* wxFindWindowAtPoint(const wxPoint& pt);

/**
    @deprecated Replaced by wxWindow::FindWindowByLabel().

    Find a window by its label. Depending on the type of window, the label may
    be a window title or panel item label. If @a parent is @NULL, the search
    will start from all top-level frames and dialog boxes; if non-@NULL, the
    search will be limited to the given window hierarchy. The search is
    recursive in both cases.

    @header{wx/utils.h}
*/
wxWindow* wxFindWindowByLabel(const wxString& label,
                              wxWindow* parent = NULL);

/**
    @deprecated Replaced by wxWindow::FindWindowByName().

    Find a window by its name (as given in a window constructor or @e Create
    function call). If @a parent is @NULL, the search will start from all
    top-level frames and dialog boxes; if non-@NULL, the search will be limited
    to the given window hierarchy. The search is recursive in both cases.

    If no such named window is found, wxFindWindowByLabel() is called.

    @header{wx/utils.h}
*/
wxWindow* wxFindWindowByName(const wxString& name, wxWindow* parent = NULL);

/**
    Find a menu item identifier associated with the given frame's menu bar.

    @header{wx/utils.h}
*/
int wxFindMenuItemId(wxFrame* frame, const wxString& menuString,
                     const wxString& itemString);

/**
    @deprecated Ids generated by it can conflict with the Ids defined by the
                user code, use @c wxID_ANY to assign ids which are guaranteed
                to not conflict with the user-defined ids for the controls and
                menu items you create instead of using this function.

    Generates an integer identifier unique to this run of the program.

    @header{wx/utils.h}
*/
//int wxNewId();

/**
    Ensures that Ids subsequently generated by wxNewId() do not clash with the
    given @a id.

    @header{wx/utils.h}
*/
void wxRegisterId(int id);

/**
    Opens the @a document in the application associated with the files of this
    type.

    The @a flags parameter is currently not used

    Returns @true if the application was successfully launched.

    @see wxLaunchDefaultBrowser(), wxExecute()

    @header{wx/utils.h}
*/
bool wxLaunchDefaultApplication(const wxString& document, int flags = 0);

/**
    Opens the @a url in user's default browser.

    If the @a flags parameter contains @c wxBROWSER_NEW_WINDOW flag, a new
    window is opened for the URL (currently this is only supported under
    Windows).

    And unless the @a flags parameter contains @c wxBROWSER_NOBUSYCURSOR flag,
    a busy cursor is shown while the browser is being launched (using
    wxBusyCursor).

    The parameter @a url is interpreted as follows:
    - if it has a valid scheme (e.g. @c "file:", @c "http:" or @c "mailto:")
      it is passed to the appropriate browser configured in the user system.
    - if it has no valid scheme (e.g. it's a local file path without the @c "file:"
      prefix), then ::wxFileExists and ::wxDirExists are used to test if it's a
      local file/directory; if it is, then the browser is called with the
      @a url parameter eventually prefixed by @c "file:".
    - if it has no valid scheme and it's not a local file/directory, then @c "http:"
      is prepended and the browser is called.

    Returns @true if the application was successfully launched.

    @note For some configurations of the running user, the application which is
          launched to open the given URL may be URL-dependent (e.g. a browser
          may be used for local URLs while another one may be used for remote
          URLs).

    @see wxLaunchDefaultApplication(), wxExecute()

    @header{wx/utils.h}
*/
bool wxLaunchDefaultBrowser(const wxString& url, int flags = 0);

/**
    Loads an object from Windows resource file.

    This function loads the resource with the given name and type from the
    resources embedded into a Windows application.

    The typical use for it is to load some data from the data files embedded
    into the program itself. For example, you could have the following fragment
    in your @c .rc file
    @code
        mydata  MYDATA  "myfile.dat"
    @endcode
    and then use it in the following way:
    @code
        const void* data = NULL;
        size_t size = 0;
        if ( !wxLoadUserResource(&data, &size, "mydata", "MYDATA") ) {
            ... handle error ...
        }
        else {
            // Use the data in any way, for example:
            wxMemoryInputStream is(data, size);
            ... read the data from stream ...
        }
    @endcode

    @param outData Filled with the pointer to the data on successful return.
        Notice that this pointer does @em not need to be freed by the caller.
    @param outLen Filled with the length of the data in bytes.
    @param resourceName The name of the resource to load.
    @param resourceType The type of the resource in usual Windows format, i.e.
        either a real string like "MYDATA" or an integer created by the
        standard Windows @c MAKEINTRESOURCE() macro, including any constants
        for the standard resources types like @c RT_RCDATA.
    @param module The @c HINSTANCE of the module to load the resources from.
        The current module is used by default.
    @return true if the data was loaded from resource or false if it couldn't
        be found (in which case no error is logged) or was found but couldn't
        be loaded (which is unexpected and does result in an error message).

    This function is available under Windows only.

    @library{wxbase}

    @header{wx/utils.h}

    @since 2.9.1
 */
/*bool
wxLoadUserResource(const void **outData,
                   size_t *outLen,
                   const wxString& resourceName,
                   const wxChar* resourceType = "TEXT",
                   WXHINSTANCE module = 0);
*/
/**
    Loads a user-defined Windows resource as a string.

    This is a wrapper for the general purpose overload wxLoadUserResource(const
    void**, size_t*, const wxString&, const wxChar*, WXHINSTANCE) and can be
    more convenient for the string data, but does an extra copy compared to the
    general version.

    @param resourceName The name of the resource to load.
    @param resourceType The type of the resource in usual Windows format, i.e.
        either a real string like "MYDATA" or an integer created by the
        standard Windows @c MAKEINTRESOURCE() macro, including any constants
        for the standard resources types like @c RT_RCDATA.
    @param pLen Filled with the length of the returned buffer if it is
        non-@NULL. This parameter should be used if NUL characters can occur in
        the resource data. It is new since wxWidgets 2.9.1
    @param module The @c HINSTANCE of the module to load the resources from.
        The current module is used by default. This parameter is new since
        wxWidgets 2.9.1.
    @return A pointer to the data to be <tt>delete[]</tt>d by caller on success
        or @NULL on error.

    This function is available under Windows only.

    @library{wxbase}

    @header{wx/utils.h}
*/
/*char* wxLoadUserResource(const wxString& resourceName,
                         const wxChar* resourceType = "TEXT",
                         int* pLen = NULL,
                         WXHINSTANCE module = 0);
*/
/**
    @deprecated Replaced by wxWindow::Close(). See the
                @ref overview_windowdeletion "window deletion overview".

    Tells the system to delete the specified object when all other events have
    been processed. In some environments, it is necessary to use this instead
    of deleting a frame directly with the delete operator, because some GUIs
    will still send events to a deleted window.

    @header{wx/utils.h}
*/
//void wxPostDelete(wxObject* object);


/**
    Under X only, sets the current display name. This is the X host and display
    name such as "colonsay:0.0", and the function indicates which display
    should be used for creating windows from this point on. Setting the display
    within an application allows multiple displays to be used.

    @see wxGetDisplayName()

    @header{wx/utils.h}
*/
//void wxSetDisplayName(const wxString& displayName);

/**
   flags for wxStripMenuCodes
*/
enum
{
    // strip '&' characters
    wxStrip_Mnemonics = 1,

    // strip everything after '\t'
    wxStrip_Accel = 2,

    // strip everything (this is the default)
    wxStrip_All = wxStrip_Mnemonics | wxStrip_Accel
};

/**
    Strips any menu codes from @a str and returns the result.

    By default, the functions strips both the mnemonics character (@c '&')
    which is used to indicate a keyboard shortkey, and the accelerators, which
    are used only in the menu items and are separated from the main text by the
    @c \\t (TAB) character. By using @a flags of @c wxStrip_Mnemonics or
    @c wxStrip_Accel to strip only the former or the latter part, respectively.

    Notice that in most cases wxMenuItem::GetLabelFromText() or
    wxControl::GetLabelText() can be used instead.

    @header{wx/utils.h}
*/
wxString wxStripMenuCodes(const wxString& str, int flags = wxStrip_All);

//@}
