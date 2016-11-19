enum
{
    wxCOL_WIDTH_DEFAULT = -1,
    wxCOL_WIDTH_AUTOSIZE = -2
};
enum
{
    wxCOL_RESIZABLE   = 1,
    wxCOL_SORTABLE    = 2,
    wxCOL_REORDERABLE = 4,
    wxCOL_HIDDEN      = 8,
    wxCOL_DEFAULT_FLAGS = wxCOL_RESIZABLE | wxCOL_REORDERABLE
};
WXGO_DECL_TYPECONV(HeaderColumn)
class wxHeaderColumn
{
public:
    virtual wxString GetTitle() const = 0;
    virtual wxBitmap GetBitmap() const = 0;
    virtual int GetWidth() const = 0;
    virtual int GetMinWidth() const = 0;
    virtual wxAlignment GetAlignment() const = 0;
    virtual int GetFlags() const = 0;
    bool HasFlag(int flag) const;
    virtual bool IsResizeable() const;
    virtual bool IsSortable() const;
    virtual bool IsReorderable() const;
    virtual bool IsHidden() const;
    bool IsShown() const;
    virtual bool IsSortKey() const = 0;
    virtual bool IsSortOrderAscending() const = 0;
};
WXGO_DECL_TYPECONV(SettableHeaderColumn)
class wxSettableHeaderColumn : public wxHeaderColumn
{
public:
    virtual void SetTitle(const wxString& title) = 0;
    virtual void SetBitmap(const wxBitmap& bitmap) = 0;
    virtual void SetWidth(int width) = 0;
    virtual void SetMinWidth(int minWidth) = 0;
    virtual void SetAlignment(wxAlignment align) = 0;
    virtual void SetFlags(int flags) = 0;
    void ChangeFlag(int flag, bool set);
    void SetFlag(int flag);
    void ClearFlag(int flag);
    void ToggleFlag(int flag);
    virtual void SetResizeable(bool resizable);
    virtual void SetSortable(bool sortable);
    virtual void SetReorderable(bool reorderable);
    virtual void SetHidden(bool hidden);
    void UnsetAsSortKey();
    virtual void SetSortOrder(bool ascending) = 0;
    void ToggleSortOrder();
};
WXGO_DECL_TYPECONV(HeaderColumnSimple)
class wxHeaderColumnSimple : public wxSettableHeaderColumn
{
public:
    wxHeaderColumnSimple(const wxString& title,
                         int width = wxCOL_WIDTH_DEFAULT,
                         wxAlignment align = wxALIGN_NOT,
                         int flags = wxCOL_DEFAULT_FLAGS);
    wxHeaderColumnSimple(const wxBitmap &bitmap,
                         int width = wxCOL_WIDTH_DEFAULT,
                         wxAlignment align = wxALIGN_CENTER,
                         int flags = wxCOL_DEFAULT_FLAGS);
    virtual void SetTitle(const wxString& title);
    virtual wxString GetTitle() const;
    virtual void SetBitmap(const wxBitmap& bitmap);
    virtual wxBitmap GetBitmap() const;
    virtual void SetWidth(int width);
    virtual int GetWidth() const;
    virtual void SetMinWidth(int minWidth);
    virtual int GetMinWidth() const;
    virtual void SetAlignment(wxAlignment align);
    virtual wxAlignment GetAlignment() const;
    virtual void SetFlags(int flags);
    virtual int GetFlags() const;
    virtual bool IsSortKey() const;
    virtual void SetSortOrder(bool ascending);
    virtual bool IsSortOrderAscending() const;
};