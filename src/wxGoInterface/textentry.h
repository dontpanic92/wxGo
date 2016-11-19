typedef long wxTextPos;
WXGO_DECL_TYPECONV(TextEntry)
class wxTextEntry
{
public:
    virtual void AppendText(const wxString& text);
    bool AutoComplete(const wxArrayString& choices);
    bool AutoComplete(wxTextCompleter *completer);
    bool AutoCompleteFileNames();
    bool AutoCompleteDirectories();
    virtual bool CanCopy() const;
    virtual bool CanCut() const;
    virtual bool CanPaste() const;
    virtual bool CanRedo() const;
    virtual bool CanUndo() const;
    virtual void ChangeValue(const wxString& value);
    virtual void Clear();
    virtual void Copy();
    virtual void Cut();
    void ForceUpper();
    virtual long GetInsertionPoint() const;
    virtual wxTextPos GetLastPosition() const;
    virtual wxString GetRange(long from, long to) const;
    virtual void GetSelection(long* from, long* to) const;
    virtual wxString GetStringSelection() const;
    virtual wxString GetValue() const;
    virtual bool IsEditable() const;
    virtual bool IsEmpty() const;
    virtual void Paste();
    virtual void Redo();
    virtual void Remove(long from, long to);
    virtual void Replace(long from, long to, const wxString& value);
    virtual void SetEditable(bool editable);
    virtual void SetInsertionPoint(long pos);
    virtual void SetInsertionPointEnd();
    virtual void SetMaxLength(unsigned long len);
    virtual void SetSelection(long from, long to);
    virtual void SelectAll();
    virtual void SelectNone();
    virtual bool SetHint(const wxString& hint);
    virtual wxString GetHint() const;
    bool SetMargins(const wxPoint& pt);
    bool SetMargins(wxCoord left, wxCoord top = -1);
    wxPoint GetMargins() const;
    virtual void SetValue(const wxString& value);
    virtual void Undo();
    virtual void WriteText(const wxString& text);
};