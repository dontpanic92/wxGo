%typedef int wxPathFormat;
#define wxPATH_NATIVE  0
#define wxPATH_UNIX wxPATH_NATIVE  + 1
#define wxPATH_BEOS  wxPATH_UNIX
#define wxPATH_MAC wxPATH_BEOS  + 1
#define wxPATH_DOS wxPATH_MAC + 1
#define wxPATH_WIN  wxPATH_DOS
#define wxPATH_OS2  wxPATH_DOS
#define wxPATH_VMS wxPATH_OS2  + 1
#define wxPATH_MAX wxPATH_VMS + 1
%typedef int wxSizeConvention;
#define wxSIZE_CONV_TRADITIONAL 0
#define wxSIZE_CONV_IEC wxSIZE_CONV_TRADITIONAL + 1
#define wxSIZE_CONV_SI wxSIZE_CONV_IEC + 1
%typedef int wxPathNormalize;
#define wxPATH_NORM_ENV_VARS  0x0001
#define wxPATH_NORM_DOTS      0x0002
#define wxPATH_NORM_TILDE     0x0004
#define wxPATH_NORM_CASE      0x0008
#define wxPATH_NORM_ABSOLUTE  0x0010
#define wxPATH_NORM_LONG  0x0020
#define wxPATH_NORM_SHORTCUT  0x0040
#define wxPATH_NORM_ALL       0x00ff & ~wxPATH_NORM_CASE
enum
{
    wxPATH_RMDIR_FULL = 1,
    wxPATH_RMDIR_RECURSIVE = 2
};
enum
{
    wxFILE_EXISTS_REGULAR   = 0x0001,  
    wxFILE_EXISTS_DIR       = 0x0002,  
    wxFILE_EXISTS_SYMLINK   = 0x1004,
    wxFILE_EXISTS_DEVICE    = 0x0008,  
    wxFILE_EXISTS_FIFO      = 0x0016,  
    wxFILE_EXISTS_SOCKET    = 0x0032,  
    wxFILE_EXISTS_NO_FOLLOW = 0x1000,   
    wxFILE_EXISTS_ANY       = 0x1FFF,  
};
%constant wxULongLong wxInvalidSize;
WXGO_DECL_TYPECONV(FileName)
class wxFileName
{
public:
    wxFileName();
    wxFileName(const wxFileName& filename);
    wxFileName(const wxString& fullpath,
               wxPathFormat format = wxPATH_NATIVE);
    wxFileName(const wxString& path, const wxString& name,
               wxPathFormat format = wxPATH_NATIVE);
    wxFileName(const wxString& path, const wxString& name,
               const wxString& ext,
               wxPathFormat format = wxPATH_NATIVE);
    wxFileName(const wxString& volume, const wxString& path,
               const wxString& name,
               const wxString& ext,
               wxPathFormat format = wxPATH_NATIVE);
    bool AppendDir(const wxString& dir);
    void Assign(const wxFileName& filepath);
    void Assign(const wxString& fullpath,
                wxPathFormat format = wxPATH_NATIVE);
    void Assign(const wxString& volume, const wxString& path,
                const wxString& name,
                const wxString& ext,
                bool hasExt,
                wxPathFormat format = wxPATH_NATIVE);
    void Assign(const wxString& volume, const wxString& path,
                const wxString& name,
                const wxString& ext,
                wxPathFormat format = wxPATH_NATIVE);
    void Assign(const wxString& path, const wxString& name,
                wxPathFormat format = wxPATH_NATIVE);
    void Assign(const wxString& path, const wxString& name,
                const wxString& ext,
                wxPathFormat format = wxPATH_NATIVE);
    void AssignCwd(const wxString& volume = wxEmptyString);
    void AssignDir(const wxString& dir,
                   wxPathFormat format = wxPATH_NATIVE);
    void AssignHomeDir();
    void AssignTempFileName(const wxString& prefix);
    void AssignTempFileName(const wxString& prefix, wxFile* fileTemp);
    void AssignTempFileName(const wxString& prefix, wxFFile* fileTemp);
    void Clear();
    void ClearExt();
    static wxString CreateTempFileName(const wxString& prefix,
                                       wxFile* fileTemp = NULL);
    static wxString CreateTempFileName(const wxString& prefix,
                                       wxFFile* fileTemp = NULL);
    bool DirExists() const;
    static bool DirExists(const wxString& dir);
    static wxFileName DirName(const wxString& dir,
                              wxPathFormat format = wxPATH_NATIVE);
    void DontFollowLink();
    bool Exists(int flags = wxFILE_EXISTS_ANY) const;
    static bool Exists(const wxString& path, int flags = wxFILE_EXISTS_ANY);
    bool FileExists() const;
    static bool FileExists(const wxString& file);
    static wxFileName FileName(const wxString& file,
                               wxPathFormat format = wxPATH_NATIVE);
    static wxString GetCwd(const wxString& volume = wxEmptyString);
    size_t GetDirCount() const;
    const wxArrayString& GetDirs() const;
    wxString GetExt() const;
    static wxString GetForbiddenChars(wxPathFormat format = wxPATH_NATIVE);
    static wxPathFormat GetFormat(wxPathFormat format = wxPATH_NATIVE);
    wxString GetFullName() const;
    wxString GetFullPath(wxPathFormat format = wxPATH_NATIVE) const;
    static wxString GetHomeDir();
    wxString
    GetHumanReadableSize(const wxString& failmsg = _("Not available"),
                         int precision = 1,
                         wxSizeConvention conv = wxSIZE_CONV_TRADITIONAL) const;
    static wxString
    GetHumanReadableSize(const wxULongLong& bytes,
                         const wxString& nullsize = _("Not available"),
                         int precision = 1,
                         wxSizeConvention conv = wxSIZE_CONV_TRADITIONAL);
    wxString GetLongPath() const;
    wxDateTime GetModificationTime() const;
    wxString GetName() const;
    wxString GetPath(int flags = wxPATH_GET_VOLUME,
                     wxPathFormat format = wxPATH_NATIVE) const;
    static wxUniChar GetPathSeparator(wxPathFormat format = wxPATH_NATIVE);
    static wxString GetPathSeparators(wxPathFormat format = wxPATH_NATIVE);
    static wxString GetPathTerminators(wxPathFormat format = wxPATH_NATIVE);
    wxString GetPathWithSep(wxPathFormat format = wxPATH_NATIVE) const;
    wxString GetShortPath() const;
    wxULongLong GetSize() const;
    static wxULongLong GetSize(const wxString& filename);
    static wxString GetTempDir();
    bool GetTimes(wxDateTime* dtAccess, wxDateTime* dtMod,
                  wxDateTime* dtCreate) const;
    wxString GetVolume() const;
    static wxString GetVolumeSeparator(wxPathFormat format = wxPATH_NATIVE);
#ifdef __WXMSW__
    static wxString GetVolumeString(char drive, int flags = wxPATH_GET_SEPARATOR);
#endif
    bool HasExt() const;
    bool HasName() const;
    bool HasVolume() const;
    bool InsertDir(size_t before, const wxString& dir);
    bool IsAbsolute(wxPathFormat format = wxPATH_NATIVE) const;
    static bool IsCaseSensitive(wxPathFormat format = wxPATH_NATIVE);
    bool IsDir() const;
    bool IsDirReadable() const;
    static bool IsDirReadable(const wxString& dir);
    bool IsDirWritable() const;
    static bool IsDirWritable(const wxString& dir);
    bool IsFileExecutable() const;
    static bool IsFileExecutable(const wxString& file);
    bool IsFileReadable() const;
    static bool IsFileReadable(const wxString& file);
    bool IsFileWritable() const;
    static bool IsFileWritable(const wxString& file);
    bool IsOk() const;
    static bool IsPathSeparator(wxChar ch,
                                wxPathFormat format = wxPATH_NATIVE);
    static bool IsMSWUniqueVolumeNamePath(const wxString& path,
                                          wxPathFormat format = wxPATH_NATIVE);
    bool IsRelative(wxPathFormat format = wxPATH_NATIVE) const;
    bool MakeAbsolute(const wxString& cwd = wxEmptyString,
                      wxPathFormat format = wxPATH_NATIVE);
    bool MakeRelativeTo(const wxString& pathBase = wxEmptyString,
                        wxPathFormat format = wxPATH_NATIVE);
    bool Mkdir(int perm = wxS_DIR_DEFAULT, int flags = 0) const;
    static bool Mkdir(const wxString& dir, int perm = wxS_DIR_DEFAULT,
                      int flags = 0);
    bool Normalize(int flags = wxPATH_NORM_ALL,
                   const wxString& cwd = wxEmptyString,
                   wxPathFormat format = wxPATH_NATIVE);
    void PrependDir(const wxString& dir);
    void RemoveDir(size_t pos);
    void RemoveLastDir();
    bool ReplaceEnvVariable(const wxString& envname,
                            const wxString& replacementFmtString = "$%s",
                            wxPathFormat format = wxPATH_NATIVE);
    bool ReplaceHomeDir(wxPathFormat format = wxPATH_NATIVE);
    bool Rmdir(int flags = 0) const;
    static bool Rmdir(const wxString& dir, int flags = 0);
    bool SameAs(const wxFileName& filepath,
                wxPathFormat format = wxPATH_NATIVE) const;
    bool SetCwd() const;
    static bool SetCwd(const wxString& cwd);
    void SetEmptyExt();
    void SetExt(const wxString& ext);
    void SetFullName(const wxString& fullname);
    void SetName(const wxString& name);
    void SetPath(const wxString& path, wxPathFormat format = wxPATH_NATIVE);
    bool SetPermissions(int permissions);
    bool SetTimes(const wxDateTime* dtAccess,
                  const wxDateTime* dtMod,
                  const wxDateTime* dtCreate) const;
    void SetVolume(const wxString& volume);
    bool ShouldFollowLink() const;
    static void SplitPath(const wxString& fullpath,
                          wxString* volume,
                          wxString* path,
                          wxString* name,
                          wxString* ext,
                          bool* hasExt = NULL,
                          wxPathFormat format = wxPATH_NATIVE);
    static void SplitPath(const wxString& fullpath,
                          wxString* volume,
                          wxString* path,
                          wxString* name,
                          wxString* ext,
                          wxPathFormat format);
    static void SplitPath(const wxString& fullpath,
                          wxString* path,
                          wxString* name,
                          wxString* ext,
                          wxPathFormat format = wxPATH_NATIVE);
    static void SplitVolume(const wxString& fullpath,
                            wxString* volume,
                            wxString* path,
                            wxPathFormat format = wxPATH_NATIVE);
    static wxString StripExtension(const wxString& fullname);
    bool Touch() const;
    bool operator!=(const wxFileName& filename) const;
    bool operator!=(const wxString& filename) const;
    bool operator==(const wxFileName& filename) const;
    bool operator==(const wxString& filename) const;
    wxFileName& operator=(const wxFileName& filename);
    wxFileName& operator=(const wxString& filename);
};