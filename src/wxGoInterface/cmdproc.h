WXGO_DECL_TYPECONV(Command)
class wxCommand : public wxObject
{
public:
    wxCommand(bool canUndo = false, const wxString& name = wxEmptyString);
    virtual ~wxCommand();
    virtual bool CanUndo() const;
    virtual bool Do() = 0;
    virtual wxString GetName() const;
    virtual bool Undo() = 0;
};
WXGO_DECL_TYPECONV(CommandProcessor)
class wxCommandProcessor : public wxObject
{
public:
    wxCommandProcessor(int maxCommands = -1);
    virtual ~wxCommandProcessor();
    virtual bool CanUndo() const;
    virtual bool CanRedo() const;
    virtual void ClearCommands();
    wxList& GetCommands();
    wxCommand *GetCurrentCommand() const;
    wxMenu* GetEditMenu() const;
    int GetMaxCommands() const;
    const wxString& GetRedoAccelerator() const;
    wxString GetRedoMenuLabel() const;
    const wxString& GetUndoAccelerator() const;
    wxString GetUndoMenuLabel() const;
    virtual void Initialize();
    virtual bool IsDirty() const;
    void MarkAsSaved();
    virtual bool Redo();
    void SetEditMenu(wxMenu* menu);
    virtual void SetMenuStrings();
    void SetRedoAccelerator(const wxString& accel);
    void SetUndoAccelerator(const wxString& accel);
    virtual bool Submit(wxCommand* command, bool storeIt = true);
    virtual void Store(wxCommand *command);
    virtual bool Undo();
};