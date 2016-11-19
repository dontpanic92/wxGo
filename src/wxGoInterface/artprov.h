typedef wxString wxArtClient;
typedef wxString wxArtID;
%constant wxArtClient wxART_TOOLBAR;
%constant wxArtClient wxART_MENU;
%constant wxArtClient wxART_FRAME_ICON;
%constant wxArtClient wxART_CMN_DIALOG;
%constant wxArtClient wxART_HELP_BROWSER;
%constant wxArtClient wxART_MESSAGE_BOX;
%constant wxArtClient wxART_BUTTON;
%constant wxArtClient wxART_LIST;
%constant wxArtClient wxART_OTHER;
%constant wxArtID wxART_ADD_BOOKMARK;         
%constant wxArtID wxART_DEL_BOOKMARK;         
%constant wxArtID wxART_HELP_SIDE_PANEL;      
%constant wxArtID wxART_HELP_SETTINGS;        
%constant wxArtID wxART_HELP_BOOK;            
%constant wxArtID wxART_HELP_FOLDER;          
%constant wxArtID wxART_HELP_PAGE;            
%constant wxArtID wxART_GO_BACK;              
%constant wxArtID wxART_GO_FORWARD;           
%constant wxArtID wxART_GO_UP;                
%constant wxArtID wxART_GO_DOWN;              
%constant wxArtID wxART_GO_TO_PARENT;         
%constant wxArtID wxART_GO_HOME;              
%constant wxArtID wxART_GOTO_FIRST;           
%constant wxArtID wxART_GOTO_LAST;            
%constant wxArtID wxART_FILE_OPEN;            
%constant wxArtID wxART_FILE_SAVE;            
%constant wxArtID wxART_FILE_SAVE_AS;         
%constant wxArtID wxART_PRINT;                
%constant wxArtID wxART_HELP;                 
%constant wxArtID wxART_TIP;                  
%constant wxArtID wxART_REPORT_VIEW;          
%constant wxArtID wxART_LIST_VIEW;            
%constant wxArtID wxART_NEW_DIR;              
%constant wxArtID wxART_HARDDISK;             
%constant wxArtID wxART_FLOPPY;               
%constant wxArtID wxART_CDROM;                
%constant wxArtID wxART_REMOVABLE;            
%constant wxArtID wxART_FOLDER;               
%constant wxArtID wxART_FOLDER_OPEN;          
%constant wxArtID wxART_GO_DIR_UP;            
%constant wxArtID wxART_EXECUTABLE_FILE;      
%constant wxArtID wxART_NORMAL_FILE;          
%constant wxArtID wxART_TICK_MARK;            
%constant wxArtID wxART_CROSS_MARK;           
%constant wxArtID wxART_ERROR;                
%constant wxArtID wxART_QUESTION;             
%constant wxArtID wxART_WARNING;              
%constant wxArtID wxART_INFORMATION;          
%constant wxArtID wxART_MISSING_IMAGE;        
%constant wxArtID wxART_COPY;                 
%constant wxArtID wxART_CUT;                  
%constant wxArtID wxART_PASTE;                
%constant wxArtID wxART_DELETE;               
%constant wxArtID wxART_NEW;                  
%constant wxArtID wxART_UNDO;                 
%constant wxArtID wxART_REDO;                 
%constant wxArtID wxART_PLUS;                 
%constant wxArtID wxART_MINUS;                
%constant wxArtID wxART_CLOSE;                
%constant wxArtID wxART_QUIT;                 
%constant wxArtID wxART_FIND;                 
%constant wxArtID wxART_FIND_AND_REPLACE;     
%constant wxArtID wxART_FULL_SCREEN;
%constant wxArtID wxART_EDIT;
WXGO_DECL_TYPECONV(ArtProvider)
class wxArtProvider : public wxObject
{
public:
    virtual ~wxArtProvider();
    static bool Delete(wxArtProvider* provider);
    static wxBitmap GetBitmap(const wxArtID& id,
                              const wxArtClient& client = wxART_OTHER,
                              const wxSize& size = wxDefaultSize);
    static wxIcon GetIcon(const wxArtID& id,
                          const wxArtClient& client = wxART_OTHER,
                          const wxSize& size = wxDefaultSize);
    static wxSize GetNativeSizeHint(const wxArtClient& client);
    static wxSize GetSizeHint(const wxArtClient& client,
                              bool platform_default = false);
    static wxIconBundle GetIconBundle(const wxArtID& id,
                                      const wxArtClient& client = wxART_OTHER);
    static bool HasNativeProvider();
    static bool Pop();
    static void Push(wxArtProvider* provider);
    static void PushBack(wxArtProvider* provider);
    static bool Remove(wxArtProvider* provider);
    static wxArtID GetMessageBoxIconId(int flags);
    static wxIcon GetMessageBoxIcon(int flags);
protected:
    virtual wxBitmap CreateBitmap(const wxArtID& id,
                                  const wxArtClient& client,
                                  const wxSize& size);
    virtual wxIconBundle CreateIconBundle(const wxArtID& id,
                                          const wxArtClient& client);
};