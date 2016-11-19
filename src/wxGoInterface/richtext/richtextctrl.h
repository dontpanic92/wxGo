#define wxRE_READONLY          0x0010
#define wxRE_MULTILINE         0x0020
#define wxRE_CENTRE_CARET      0x8000
#define wxRE_CENTER_CARET      wxRE_CENTRE_CARET
#define wxRICHTEXT_SHIFT_DOWN  0x01
#define wxRICHTEXT_CTRL_DOWN   0x02
#define wxRICHTEXT_ALT_DOWN    0x04
#define wxRICHTEXT_EX_NO_GUIDELINES 0x00000100
#define wxRICHTEXT_DEFAULT_OVERALL_SIZE wxSize(-1, -1)
#define wxRICHTEXT_DEFAULT_IMAGE_SIZE wxSize(80, 80)
#define wxRICHTEXT_DEFAULT_SPACING 3
#define wxRICHTEXT_DEFAULT_MARGIN 3
#define wxRICHTEXT_DEFAULT_UNFOCUSSED_BACKGROUND wxColour(175, 175, 175)
#define wxRICHTEXT_DEFAULT_FOCUSSED_BACKGROUND wxColour(140, 140, 140)
#define wxRICHTEXT_DEFAULT_UNSELECTED_BACKGROUND wxSystemSettings::GetColour(wxSYS_COLOUR_3DFACE)
#define wxRICHTEXT_DEFAULT_TYPE_COLOUR wxColour(0, 0, 200)
#define wxRICHTEXT_DEFAULT_FOCUS_RECT_COLOUR wxColour(100, 80, 80)
#define wxRICHTEXT_DEFAULT_CARET_WIDTH 2
#define wxRICHTEXT_DEFAULT_DELAYED_LAYOUT_THRESHOLD 20000
#define wxRICHTEXT_DEFAULT_LAYOUT_INTERVAL 50
#define wxRICHTEXT_DEFAULT_DELAYED_IMAGE_PROCESSING_INTERVAL 200
#define wxID_RICHTEXT_PROPERTIES1   (wxID_HIGHEST + 1)
#define wxID_RICHTEXT_PROPERTIES2   (wxID_HIGHEST + 2)
#define wxID_RICHTEXT_PROPERTIES3   (wxID_HIGHEST + 3)
%typedef int wxRichTextCtrlSelectionState;
#define wxRichTextCtrlSelectionState_Normal 0
#define wxRichTextCtrlSelectionState_CommonAncestor wxRichTextCtrlSelectionState_Normal + 1
WXGO_DECL_TYPECONV(RichTextContextMenuPropertiesInfo)
class wxRichTextContextMenuPropertiesInfo
{
public:
    wxRichTextContextMenuPropertiesInfo();
    void Init();
    bool AddItem(const wxString& label, wxRichTextObject* obj);
    int AddMenuItems(wxMenu* menu, int startCmd = wxID_RICHTEXT_PROPERTIES1) const;
    int AddItems(wxRichTextCtrl* ctrl, wxRichTextObject* container, wxRichTextObject* obj);
    void Clear();
    wxString GetLabel(int n) const;
    wxRichTextObject* GetObject(int n) const;
    wxRichTextObjectPtrArray& GetObjects();
    const wxArrayString& GetLabels() const;
    %extend {
        void SetLabels(const wxArrayString& labels) { self->m_labels = labels; }
    }
    int GetCount() const;
    wxRichTextObjectPtrArray    m_objects;
    wxArrayString               m_labels;
};
WXGO_DECL_TYPECONV(RichTextCtrl)
class wxRichTextCtrl : public wxControl,
                       public wxTextCtrlIface,
                       public wxScrollHelper
{
public:
    wxRichTextCtrl( );
    wxRichTextCtrl( wxWindow* parent, wxWindowID id = -1, const wxString& value = wxEmptyString, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize,
        long style = wxRE_MULTILINE, const wxValidator& validator = wxDefaultValidator, const wxString& name = wxTextCtrlNameStr);
    virtual ~wxRichTextCtrl( );
    bool Create( wxWindow* parent, wxWindowID id = -1, const wxString& value = wxEmptyString, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize,
        long style = wxRE_MULTILINE, const wxValidator& validator = wxDefaultValidator, const wxString& name = wxTextCtrlNameStr );
    void Init();
    virtual wxString GetRange(long from, long to) const;
    virtual int GetLineLength(long lineNo) const ;
    virtual wxString GetLineText(long lineNo) const ;
    virtual int GetNumberOfLines() const ;
    virtual bool IsModified() const ;
    virtual bool IsEditable() const ;
    bool IsSingleLine() const;
    bool IsMultiLine() const;
    const wxRichTextSelection& GetSelection() const;
    virtual wxString GetStringSelection() const;
    wxString GetFilename() const;
    void SetFilename(const wxString& filename);
    void SetDelayedLayoutThreshold(long threshold);
    long GetDelayedLayoutThreshold() const;
    bool GetFullLayoutRequired() const;
    void SetFullLayoutRequired(bool b);
    wxLongLong GetFullLayoutTime() const;
    void SetFullLayoutTime(wxLongLong t);
    long GetFullLayoutSavedPosition() const;
    void SetFullLayoutSavedPosition(long p);
    void ForceDelayedLayout();
    void SetTextCursor(const wxCursor& cursor );
    wxCursor GetTextCursor() const;
    void SetURLCursor(const wxCursor& cursor );
    wxCursor GetURLCursor() const;
    bool GetCaretAtLineStart() const;
    void SetCaretAtLineStart(bool atStart);
    bool GetDragging() const;
    void SetDragging(bool dragging);
    bool GetPreDrag() const;
    void SetPreDrag(bool pd);
    const wxPoint GetDragStartPoint() const;
    void SetDragStartPoint(wxPoint sp);
    const wxDateTime GetDragStartTime() const;
    void SetDragStartTime(wxDateTime st);
#if wxRICHTEXT_BUFFERED_PAINTING
    const wxBitmap& GetBufferBitmap() const;
    wxBitmap& GetBufferBitmap();
#endif
    wxMenu* GetContextMenu() const;
    void SetContextMenu(wxMenu* menu);
    long GetSelectionAnchor() const;
    void SetSelectionAnchor(long anchor);
    wxRichTextObject* GetSelectionAnchorObject() const;
    void SetSelectionAnchorObject(wxRichTextObject* anchor);
    wxRichTextContextMenuPropertiesInfo& GetContextMenuPropertiesInfo();
    wxRichTextParagraphLayoutBox* GetFocusObject() const;
    void StoreFocusObject(wxRichTextParagraphLayoutBox* obj);
    bool SetFocusObject(wxRichTextParagraphLayoutBox* obj, bool setCaretPosition = true);
    void Invalidate();
    virtual void Clear();
    virtual void Replace(long from, long to, const wxString& value);
    virtual void Remove(long from, long to);
    bool LoadFile(const wxString& file,
                  int type = wxRICHTEXT_TYPE_ANY);
    virtual bool DoLoadFile(const wxString& file, int fileType);
    bool SaveFile(const wxString& file = wxEmptyString,
                  int type = wxRICHTEXT_TYPE_ANY);
    virtual bool DoSaveFile(const wxString& file = wxEmptyString,
                            int fileType = wxRICHTEXT_TYPE_ANY);
    void SetHandlerFlags(int flags);
    int GetHandlerFlags() const;
    virtual void MarkDirty();
    virtual void DiscardEdits();
    void SetModified(bool modified);
    virtual void SetMaxLength(unsigned long len);
    virtual void WriteText(const wxString& text);
    virtual void AppendText(const wxString& text);
    virtual bool GetStyle(long position, wxTextAttr& style);
    virtual bool GetStyle(long position, wxRichTextAttr& style);
    virtual bool GetStyle(long position, wxRichTextAttr& style, wxRichTextParagraphLayoutBox* container);
    virtual bool SetStyle(long start, long end, const wxTextAttr& style);
    virtual bool SetStyle(long start, long end, const wxRichTextAttr& style);
    virtual bool SetStyle(const wxRichTextRange& range, const wxTextAttr& style);
    virtual bool SetStyle(const wxRichTextRange& range, const wxRichTextAttr& style);
    virtual void SetStyle(wxRichTextObject *obj, const wxRichTextAttr& textAttr, int flags = wxRICHTEXT_SETSTYLE_WITH_UNDO);
    virtual bool GetStyleForRange(const wxRichTextRange& range, wxTextAttr& style);
    virtual bool GetStyleForRange(const wxRichTextRange& range, wxRichTextAttr& style);
    virtual bool GetStyleForRange(const wxRichTextRange& range, wxRichTextAttr& style, wxRichTextParagraphLayoutBox* container);
    virtual bool SetStyleEx(const wxRichTextRange& range, const wxRichTextAttr& style, int flags = wxRICHTEXT_SETSTYLE_WITH_UNDO);
    virtual bool GetUncombinedStyle(long position, wxRichTextAttr& style);
    virtual bool GetUncombinedStyle(long position, wxRichTextAttr& style, wxRichTextParagraphLayoutBox* container);
    virtual bool SetDefaultStyle(const wxTextAttr& style);
    virtual bool SetDefaultStyle(const wxRichTextAttr& style);
    virtual const wxRichTextAttr& GetDefaultStyleEx() const;
    virtual bool SetListStyle(const wxRichTextRange& range, wxRichTextListStyleDefinition* def, int flags = wxRICHTEXT_SETSTYLE_WITH_UNDO, int startFrom = 1, int specifiedLevel = -1);
    virtual bool SetListStyle(const wxRichTextRange& range, const wxString& defName, int flags = wxRICHTEXT_SETSTYLE_WITH_UNDO, int startFrom = 1, int specifiedLevel = -1);
    virtual bool ClearListStyle(const wxRichTextRange& range, int flags = wxRICHTEXT_SETSTYLE_WITH_UNDO);
    virtual bool NumberList(const wxRichTextRange& range, wxRichTextListStyleDefinition* def = NULL, int flags = wxRICHTEXT_SETSTYLE_WITH_UNDO, int startFrom = 1, int specifiedLevel = -1);
    virtual bool NumberList(const wxRichTextRange& range, const wxString& defName, int flags = wxRICHTEXT_SETSTYLE_WITH_UNDO, int startFrom = 1, int specifiedLevel = -1);
    virtual bool PromoteList(int promoteBy, const wxRichTextRange& range, wxRichTextListStyleDefinition* def = NULL, int flags = wxRICHTEXT_SETSTYLE_WITH_UNDO, int specifiedLevel = -1);
    virtual bool PromoteList(int promoteBy, const wxRichTextRange& range, const wxString& defName, int flags = wxRICHTEXT_SETSTYLE_WITH_UNDO, int specifiedLevel = -1);
    virtual bool SetProperties(const wxRichTextRange& range, const wxRichTextProperties& properties, int flags = wxRICHTEXT_SETPROPERTIES_WITH_UNDO);
    virtual bool Delete(const wxRichTextRange& range);
    virtual long XYToPosition(long x, long y) const;
    virtual bool PositionToXY(long pos, long *x, long *y) const;
    virtual void ShowPosition(long pos);
    virtual wxTextCtrlHitTestResult HitTest(const wxPoint& pt, long *pos) const;
    virtual wxTextCtrlHitTestResult HitTest(const wxPoint& pt,
                                            wxTextCoord *col,
                                            wxTextCoord *row) const;
    wxRichTextParagraphLayoutBox* FindContainerAtPoint(const wxPoint pt, long& position, int& hit, wxRichTextObject* hitObj, int flags = 0);
    virtual void Copy();
    virtual void Cut();
    virtual void Paste();
    virtual void DeleteSelection();
    virtual bool CanCopy() const;
    virtual bool CanCut() const;
    virtual bool CanPaste() const;
    virtual bool CanDeleteSelection() const;
    virtual void Undo();
    virtual void Redo();
    virtual bool CanUndo() const;
    virtual bool CanRedo() const;
    virtual void SetInsertionPoint(long pos);
    virtual void SetInsertionPointEnd();
    virtual long GetInsertionPoint() const;
    virtual wxTextPos GetLastPosition() const;
    virtual void SetSelection(long from, long to);
    void SetSelection(const wxRichTextSelection& sel);
    virtual void SelectAll();
    virtual void SetEditable(bool editable);
    virtual bool HasSelection() const;
    virtual bool HasUnfocusedSelection() const;
    virtual bool WriteImage(const wxImage& image, wxBitmapType bitmapType = wxBITMAP_TYPE_PNG,
                            const wxRichTextAttr& textAttr = wxRichTextAttr());
    virtual bool WriteImage(const wxBitmap& bitmap, wxBitmapType bitmapType = wxBITMAP_TYPE_PNG,
                            const wxRichTextAttr& textAttr = wxRichTextAttr());
    virtual bool WriteImage(const wxString& filename, wxBitmapType bitmapType,
                            const wxRichTextAttr& textAttr = wxRichTextAttr());
    virtual bool WriteImage(const wxRichTextImageBlock& imageBlock,
                            const wxRichTextAttr& textAttr = wxRichTextAttr());
    virtual wxRichTextBox* WriteTextBox(const wxRichTextAttr& textAttr = wxRichTextAttr());
    virtual wxRichTextField* WriteField(const wxString& fieldType, const wxRichTextProperties& properties,
                            const wxRichTextAttr& textAttr = wxRichTextAttr());
    virtual wxRichTextTable* WriteTable(int rows, int cols, const wxRichTextAttr& tableAttr = wxRichTextAttr(), const wxRichTextAttr& cellAttr = wxRichTextAttr());
    virtual bool Newline();
    virtual bool LineBreak();
    virtual void SetBasicStyle(const wxRichTextAttr& style);
    virtual const wxRichTextAttr& GetBasicStyle() const;
    virtual bool BeginStyle(const wxRichTextAttr& style);
    virtual bool EndStyle();
    virtual bool EndAllStyles();
    bool BeginBold();
    bool EndBold();
    bool BeginItalic();
    bool EndItalic();
    bool BeginUnderline();
    bool EndUnderline();
    bool BeginFontSize(int pointSize);
    bool EndFontSize();
    bool BeginFont(const wxFont& font);
    bool EndFont();
    bool BeginTextColour(const wxColour& colour);
    bool EndTextColour();
    bool BeginAlignment(wxTextAttrAlignment alignment);
    bool EndAlignment();
    bool BeginLeftIndent(int leftIndent, int leftSubIndent = 0);
    bool EndLeftIndent();
    bool BeginRightIndent(int rightIndent);
    bool EndRightIndent();
    bool BeginParagraphSpacing(int before, int after);
    bool EndParagraphSpacing();
    bool BeginLineSpacing(int lineSpacing);
    bool EndLineSpacing();
    bool BeginNumberedBullet(int bulletNumber, int leftIndent, int leftSubIndent, int bulletStyle = wxTEXT_ATTR_BULLET_STYLE_ARABIC|wxTEXT_ATTR_BULLET_STYLE_PERIOD);
    bool EndNumberedBullet();
    bool BeginSymbolBullet(const wxString& symbol, int leftIndent, int leftSubIndent, int bulletStyle = wxTEXT_ATTR_BULLET_STYLE_SYMBOL);
    bool EndSymbolBullet();
    bool BeginStandardBullet(const wxString& bulletName, int leftIndent, int leftSubIndent, int bulletStyle = wxTEXT_ATTR_BULLET_STYLE_STANDARD);
    bool EndStandardBullet();
    bool BeginCharacterStyle(const wxString& characterStyle);
    bool EndCharacterStyle();
    bool BeginParagraphStyle(const wxString& paragraphStyle);
    bool EndParagraphStyle();
    bool BeginListStyle(const wxString& listStyle, int level = 1, int number = 1);
    bool EndListStyle();
    bool BeginURL(const wxString& url, const wxString& characterStyle = wxEmptyString);
    bool EndURL();
    bool SetDefaultStyleToCursorStyle();
    virtual void SelectNone();
    virtual bool SelectWord(long position);
    wxRichTextRange GetSelectionRange() const;
    void SetSelectionRange(const wxRichTextRange& range);
    wxRichTextRange GetInternalSelectionRange() const;
    void SetInternalSelectionRange(const wxRichTextRange& range);
    virtual wxRichTextRange AddParagraph(const wxString& text);
    virtual wxRichTextRange AddImage(const wxImage& image);
    virtual bool LayoutContent(bool onlyVisibleRect = false);
    virtual void DoLayoutBuffer(wxRichTextBuffer& buffer, wxDC& dc, wxRichTextDrawingContext& context, const wxRect& rect, const wxRect& parentRect, int flags);
    virtual bool MoveCaret(long pos, bool showAtLineStart = false, wxRichTextParagraphLayoutBox* container = NULL);
    virtual bool MoveRight(int noPositions = 1, int flags = 0);
    virtual bool MoveLeft(int noPositions = 1, int flags = 0);
    virtual bool MoveUp(int noLines = 1, int flags = 0);
    virtual bool MoveDown(int noLines = 1, int flags = 0);
    virtual bool MoveToLineEnd(int flags = 0);
    virtual bool MoveToLineStart(int flags = 0);
    virtual bool MoveToParagraphEnd(int flags = 0);
    virtual bool MoveToParagraphStart(int flags = 0);
    virtual bool MoveHome(int flags = 0);
    virtual bool MoveEnd(int flags = 0);
    virtual bool PageUp(int noPages = 1, int flags = 0);
    virtual bool PageDown(int noPages = 1, int flags = 0);
    virtual bool WordLeft(int noPages = 1, int flags = 0);
    virtual bool WordRight(int noPages = 1, int flags = 0);
    wxRichTextBuffer& GetBuffer();
    virtual bool BeginBatchUndo(const wxString& cmdName);
    virtual bool EndBatchUndo();
    virtual bool BatchingUndo() const;
    virtual bool BeginSuppressUndo();
    virtual bool EndSuppressUndo();
    virtual bool SuppressingUndo() const;
    virtual bool HasCharacterAttributes(const wxRichTextRange& range, const wxRichTextAttr& style) const;
    virtual bool HasParagraphAttributes(const wxRichTextRange& range, const wxRichTextAttr& style) const;
    virtual bool IsSelectionBold();
    virtual bool IsSelectionItalics();
    virtual bool IsSelectionUnderlined();
    virtual bool DoesSelectionHaveTextEffectFlag(int flag);
    virtual bool IsSelectionAligned(wxTextAttrAlignment alignment);
    virtual bool ApplyBoldToSelection();
    virtual bool ApplyItalicToSelection();
    virtual bool ApplyUnderlineToSelection();
    virtual bool ApplyTextEffectToSelection(int flags);
    virtual bool ApplyAlignmentToSelection(wxTextAttrAlignment alignment);
    virtual bool ApplyStyle(wxRichTextStyleDefinition* def);
    void SetStyleSheet(wxRichTextStyleSheet* styleSheet);
    wxRichTextStyleSheet* GetStyleSheet() const;
    bool PushStyleSheet(wxRichTextStyleSheet* styleSheet);
    wxRichTextStyleSheet* PopStyleSheet();
    bool ApplyStyleSheet(wxRichTextStyleSheet* styleSheet = NULL);
    virtual bool ShowContextMenu(wxMenu* menu, const wxPoint& pt, bool addPropertyCommands);
    virtual int PrepareContextMenu(wxMenu* menu, const wxPoint& pt, bool addPropertyCommands);
    virtual bool CanEditProperties(wxRichTextObject* obj) const;
    virtual bool EditProperties(wxRichTextObject* obj, wxWindow* parent);
    virtual wxString GetPropertiesMenuLabel(wxRichTextObject* obj);
    virtual void PrepareContent(wxRichTextParagraphLayoutBox& container);
    virtual bool CanDeleteRange(wxRichTextParagraphLayoutBox& container, const wxRichTextRange& range) const;
    virtual bool CanInsertContent(wxRichTextParagraphLayoutBox& container, long pos) const;
    virtual void EnableVerticalScrollbar(bool enable);
    virtual bool GetVerticalScrollbarEnabled() const;
    void SetFontScale(double fontScale, bool refresh = false);
    double GetFontScale() const { return GetBuffer().GetFontScale(); }
    void SetDimensionScale(double dimScale, bool refresh = false);
    double GetDimensionScale() const { return GetBuffer().GetDimensionScale(); }
    void SetScale(double scale, bool refresh = false);
    double GetScale() const;
    wxPoint GetUnscaledPoint(const wxPoint& pt) const;
    wxPoint GetScaledPoint(const wxPoint& pt) const;
    wxSize GetUnscaledSize(const wxSize& sz) const;
    wxSize GetScaledSize(const wxSize& sz) const;
    wxRect GetUnscaledRect(const wxRect& rect) const;
    wxRect GetScaledRect(const wxRect& rect) const;
    bool GetVirtualAttributesEnabled() const;
    void EnableVirtualAttributes(bool b);
    void Command(wxCommandEvent& event);
    void OnDropFiles(wxDropFilesEvent& event);
    void OnCaptureLost(wxMouseCaptureLostEvent& event);
    void OnSysColourChanged(wxSysColourChangedEvent& event);
    void OnCut(wxCommandEvent& event);
    void OnCopy(wxCommandEvent& event);
    void OnPaste(wxCommandEvent& event);
    void OnUndo(wxCommandEvent& event);
    void OnRedo(wxCommandEvent& event);
    void OnSelectAll(wxCommandEvent& event);
    void OnProperties(wxCommandEvent& event);
    void OnClear(wxCommandEvent& event);
    void OnUpdateCut(wxUpdateUIEvent& event);
    void OnUpdateCopy(wxUpdateUIEvent& event);
    void OnUpdatePaste(wxUpdateUIEvent& event);
    void OnUpdateUndo(wxUpdateUIEvent& event);
    void OnUpdateRedo(wxUpdateUIEvent& event);
    void OnUpdateSelectAll(wxUpdateUIEvent& event);
    void OnUpdateProperties(wxUpdateUIEvent& event);
    void OnUpdateClear(wxUpdateUIEvent& event);
    void OnContextMenu(wxContextMenuEvent& event);
    void OnPaint(wxPaintEvent& event);
    void OnEraseBackground(wxEraseEvent& event);
    void OnLeftClick(wxMouseEvent& event);
    void OnLeftUp(wxMouseEvent& event);
    void OnMoveMouse(wxMouseEvent& event);
    void OnLeftDClick(wxMouseEvent& event);
    void OnMiddleClick(wxMouseEvent& event);
    void OnRightClick(wxMouseEvent& event);
    void OnChar(wxKeyEvent& event);
    void OnSize(wxSizeEvent& event);
    void OnSetFocus(wxFocusEvent& event);
    void OnKillFocus(wxFocusEvent& event);
    void OnIdle(wxIdleEvent& event);
    void OnScroll(wxScrollWinEvent& event);
    virtual bool SetFont(const wxFont& font);
    virtual void SetupScrollbars(bool atTop = false);
    virtual bool KeyboardNavigate(int keyCode, int flags);
    virtual void PaintBackground(wxDC& dc);
    virtual void PaintAboveContent(wxDC& dc) {}
#if wxRICHTEXT_BUFFERED_PAINTING
    virtual bool RecreateBuffer(const wxSize& size = wxDefaultSize);
#endif
    virtual void DoWriteText(const wxString& value, int flags = 0);
    virtual bool ShouldInheritColours() const;
    virtual void PositionCaret(wxRichTextParagraphLayoutBox* container = NULL);
    virtual bool ExtendSelection(long oldPosition, long newPosition, int flags);
    virtual bool ExtendCellSelection(wxRichTextTable* table, int noRowSteps, int noColSteps);
    virtual bool StartCellSelection(wxRichTextTable* table, wxRichTextParagraphLayoutBox* newCell);
    virtual bool ScrollIntoView(long position, int keyCode);
    bool RefreshForSelectionChange(const wxRichTextSelection& oldSelection, const wxRichTextSelection& newSelection);
    void SetCaretPosition(long position, bool showAtLineStart = false) ;
    long GetCaretPosition() const;
    long GetAdjustedCaretPosition(long caretPos) const;
    void MoveCaretForward(long oldPosition) ;
    void MoveCaretBack(long oldPosition) ;
    bool GetCaretPositionForIndex(long position, wxRect& rect, wxRichTextParagraphLayoutBox* container = NULL);
    wxRichTextLine* GetVisibleLineForCaretPosition(long caretPosition) const;
    wxCommandProcessor* GetCommandProcessor() const;
    virtual bool DeleteSelectedContent(long* newPos= NULL);
    wxPoint GetPhysicalPoint(const wxPoint& ptLogical) const;
    wxPoint GetLogicalPoint(const wxPoint& ptPhysical) const;
    virtual long FindNextWordPosition(int direction = 1) const;
    bool IsPositionVisible(long pos) const;
    long GetFirstVisiblePosition() const;
    void EnableImages(bool b);
    bool GetImagesEnabled() const;
    void EnableDelayedImageLoading(bool b) { m_enableDelayedImageLoading = b; }
    bool GetDelayedImageLoading() const { return m_enableDelayedImageLoading; }
    bool GetDelayedImageProcessingRequired() const { return m_delayedImageProcessingRequired; }
    void SetDelayedImageProcessingRequired(bool b) { m_delayedImageProcessingRequired = b; }
    wxLongLong GetDelayedImageProcessingTime() const { return m_delayedImageProcessingTime; }
    void SetDelayedImageProcessingTime(wxLongLong t) { m_delayedImageProcessingTime = t; }
    long GetCaretPositionForDefaultStyle() const;
    void SetCaretPositionForDefaultStyle(long pos);
    bool IsDefaultStyleShowing() const;
    void SetAndShowDefaultStyle(const wxRichTextAttr& attr);
    wxPoint GetFirstVisiblePoint() const;
    virtual wxString GetValue() const;
    virtual void SetValue(const wxString& value);
    virtual bool ProcessBackKey(wxKeyEvent& event, int flags);
    virtual wxRichTextRange FindRangeForList(long pos, bool& isNumberedList);
    bool SetCaretPositionAfterClick(wxRichTextParagraphLayoutBox* container, long position, int hitTestFlags, bool extendSelection = false);
    long FindCaretPositionForCharacterPosition(long position, int hitTestFlags, wxRichTextParagraphLayoutBox* container,
                                               bool& caretLineStart);
    virtual bool ProcessMouseMovement(wxRichTextParagraphLayoutBox* container, wxRichTextObject* obj, long position, const wxPoint& pos);
    static const wxArrayString& GetAvailableFontNames();
    static void ClearAvailableFontNames();
    virtual wxString DoGetValue() const;
    bool ProcessDelayedImageLoading(bool refresh);
    bool ProcessDelayedImageLoading(const wxRect& screenRect, wxRichTextParagraphLayoutBox* box, int& loadCount);
    void RequestDelayedImageProcessing();
    void OnTimer(wxTimerEvent& event);
protected:
    virtual wxWindow *GetEditableWindow();
    virtual bool DoSetMargins(const wxPoint& pt);
    virtual wxPoint DoGetMargins() const;
protected:
    virtual wxSize DoGetBestSize() const ;
    virtual void DoSetValue(const wxString& value, int flags = 0);
    virtual void DoThaw();
protected:
#if wxRICHTEXT_BUFFERED_PAINTING
    wxBitmap                m_bufferBitmap;
#endif
    wxRichTextBuffer        m_buffer;
    wxMenu*                 m_contextMenu;
    long                    m_caretPosition;
    long                    m_caretPositionForDefaultStyle;
    wxRichTextSelection     m_selection;
    wxRichTextCtrlSelectionState m_selectionState;
    long                    m_selectionAnchor;
    wxRichTextObject*       m_selectionAnchorObject;
    bool                    m_editable;
    bool                    m_caretAtLineStart;
    bool                    m_dragging;
    bool                    m_fullLayoutRequired;
    wxLongLong              m_fullLayoutTime;
    long                    m_fullLayoutSavedPosition;
    long                    m_delayedLayoutThreshold;
    wxCursor                m_textCursor;
    wxCursor                m_urlCursor;
    static wxArrayString    sm_availableFontNames;
    wxRichTextContextMenuPropertiesInfo m_contextMenuPropertiesInfo;
    wxRichTextParagraphLayoutBox* m_focusObject;
    double                  m_scale;
    wxSize                  m_lastWindowSize;
    int                     m_setupScrollbarsCount;
    int                     m_setupScrollbarsCountInOnSize;
    bool                    m_enableImages;
    bool                    m_enableDelayedImageLoading;
    bool                    m_delayedImageProcessingRequired;
    wxLongLong              m_delayedImageProcessingTime;
    wxTimer                 m_delayedImageProcessingTimer;
};
WXGO_DECL_TYPECONV(RichTextEvent)
class wxRichTextEvent : public wxNotifyEvent
{
public:
    wxRichTextEvent(wxEventType commandType = wxEVT_NULL, int winid = 0);
    wxRichTextEvent(const wxRichTextEvent& event);
    long GetPosition() const;
    void SetPosition(long pos);
    int GetFlags() const;
    void SetFlags(int flags);
    wxRichTextStyleSheet* GetOldStyleSheet() const;
    void SetOldStyleSheet(wxRichTextStyleSheet* sheet);
    wxRichTextStyleSheet* GetNewStyleSheet() const;
    void SetNewStyleSheet(wxRichTextStyleSheet* sheet);
    const wxRichTextRange& GetRange() const;
    void SetRange(const wxRichTextRange& range);
    wxChar GetCharacter() const;
    void SetCharacter(wxChar ch);
    wxRichTextParagraphLayoutBox* GetContainer() const;
    void SetContainer(wxRichTextParagraphLayoutBox* container);
    wxRichTextParagraphLayoutBox* GetOldContainer() const;
    void SetOldContainer(wxRichTextParagraphLayoutBox* container);
    virtual wxEvent *Clone() const;
protected:
    int                             m_flags;
    long                            m_position;
    wxRichTextStyleSheet*           m_oldStyleSheet;
    wxRichTextStyleSheet*           m_newStyleSheet;
    wxRichTextRange                 m_range;
    wxChar                          m_char;
    wxRichTextParagraphLayoutBox*   m_container;
    wxRichTextParagraphLayoutBox*   m_oldContainer;
};
%constant wxEventType wxEVT_RICHTEXT_LEFT_CLICK;
%constant wxEventType wxEVT_RICHTEXT_RIGHT_CLICK;
%constant wxEventType wxEVT_RICHTEXT_MIDDLE_CLICK;
%constant wxEventType wxEVT_RICHTEXT_LEFT_DCLICK;
%constant wxEventType wxEVT_RICHTEXT_RETURN;
%constant wxEventType wxEVT_RICHTEXT_CHARACTER;
%constant wxEventType wxEVT_RICHTEXT_CONSUMING_CHARACTER;
%constant wxEventType wxEVT_RICHTEXT_DELETE;
%constant wxEventType wxEVT_RICHTEXT_STYLESHEET_CHANGING;
%constant wxEventType wxEVT_RICHTEXT_STYLESHEET_CHANGED;
%constant wxEventType wxEVT_RICHTEXT_STYLESHEET_REPLACING;
%constant wxEventType wxEVT_RICHTEXT_STYLESHEET_REPLACED;
%constant wxEventType wxEVT_RICHTEXT_CONTENT_INSERTED;
%constant wxEventType wxEVT_RICHTEXT_CONTENT_DELETED;
%constant wxEventType wxEVT_RICHTEXT_STYLE_CHANGED;
%constant wxEventType wxEVT_RICHTEXT_PROPERTIES_CHANGED;
%constant wxEventType wxEVT_RICHTEXT_SELECTION_CHANGED;
%constant wxEventType wxEVT_RICHTEXT_BUFFER_RESET;
%constant wxEventType wxEVT_RICHTEXT_FOCUS_OBJECT_CHANGED;