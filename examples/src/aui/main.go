package main

import "github.com/dontpanic92/wxGo/wx"

type MyFrame struct {
	wx.Frame
	auiManager wx.AuiManager
	menuBar    wx.MenuBar
}

const (
	ID_Settings = iota + wx.ID_HIGHEST + 1
	ID_SampleItem
)

func NewMyFrame() *MyFrame {
	self := &MyFrame{}
	self.Frame = wx.NewFrame(wx.NullWindow, wx.ID_ANY, "AUI Example")

	// AUI Init

	self.auiManager = wx.NewAuiManager()
	self.auiManager.SetManagedWindow(self)

	// We should call auiManager.UnInit() in frame's destructor, but unfortunately
	// we can't get a callback when frame's destructor called. So we do this in the
	// EVT_CLOSE_WINDOW. And also because we listen the CloseEvent, we have to call
	// Destroy() manually.
	wx.Bind(self, wx.EVT_CLOSE_WINDOW, func(e wx.Event) {
		self.auiManager.UnInit()
		self.Destroy()
	}, self.GetId())

	// Menu

	self.menuBar = wx.NewMenuBar()
	fileMenu := wx.NewMenu()
	fileMenu.Append(wx.ID_EXIT)

	wx.Bind(self, wx.EVT_MENU, func(e wx.Event) {
		self.Close(true)
	}, wx.ID_EXIT)

	self.menuBar.Append(fileMenu, "&File")
	self.SetMenuBar(self.menuBar)

	// StatusBar

	self.CreateStatusBar()
	self.GetStatusBar().SetStatusText("Ready")

	// AuiToolBar

	toolBar1 := wx.NewAuiToolBar(self, wx.ID_ANY, wx.DefaultPosition, wx.DefaultSize, wx.AUI_TB_DEFAULT_STYLE|wx.AUI_TB_OVERFLOW)
	toolBar1.SetToolBitmapSize(wx.NewSizeT(48, 48))

	toolBar1.AddTool(ID_SampleItem+1, "Test", wx.ArtProviderGetBitmap(wx.ART_ERROR))
	toolBar1.AddSeparator()
	toolBar1.AddTool(ID_SampleItem+2, "Test", wx.ArtProviderGetBitmap(wx.ART_QUESTION))
	toolBar1.AddTool(ID_SampleItem+3, "Test", wx.ArtProviderGetBitmap(wx.ART_INFORMATION))
	toolBar1.AddTool(ID_SampleItem+4, "Test", wx.ArtProviderGetBitmap(wx.ART_WARNING))
	toolBar1.AddTool(ID_SampleItem+5, "Test", wx.ArtProviderGetBitmap(wx.ART_MISSING_IMAGE))

	separator := wx.NewAuiToolBarItemT()
	separator.SetKind(wx.ITEM_SEPARATOR)
	customButton := wx.NewAuiToolBarItemT()
	customButton.SetKind(wx.ITEM_NORMAL)
	customButton.SetLabel("Customize...")
	wx.Bind(self, wx.EVT_MENU, func(e wx.Event) {
		wx.MessageBox("Customize clicked!")
	}, customButton.GetId())

	toolBar1.SetCustomOverflowItems([]wx.AuiToolBarItem{}, []wx.AuiToolBarItem{separator, customButton})
	toolBar1.Realize()

	paneInfo := wx.NewAuiPaneInfoT().Name("tb1").Caption("Big Toolbar").ToolbarPane().Top()
	self.auiManager.AddPane(toolBar1, paneInfo)

	// Left pane - a tree control

	treeCtrl := wx.NewTreeCtrl(self, wx.ID_ANY, wx.DefaultPosition, wx.NewSizeT(160, 250), wx.TR_DEFAULT_STYLE|wx.NO_BORDER)

	treeRoot := treeCtrl.AddRoot("wxAUI Project", 0)

	firstItem := treeCtrl.AppendItem(treeRoot, "Item 1", 0)
	treeCtrl.AppendItem(treeRoot, "Item 2", 0)
	treeCtrl.AppendItem(treeRoot, "Item 3", 0)
	treeCtrl.AppendItem(treeRoot, "Item 4", 0)
	treeCtrl.AppendItem(treeRoot, "Item 5", 0)
	treeCtrl.AppendItem(firstItem, "Subitem 1", 1)
	treeCtrl.AppendItem(firstItem, "Subitem 2", 1)
	treeCtrl.AppendItem(firstItem, "Subitem 3", 1)
	treeCtrl.AppendItem(firstItem, "Subitem 4", 1)
	treeCtrl.AppendItem(firstItem, "Subitem 5", 1)
	treeCtrl.Expand(treeRoot)

	self.auiManager.AddPane(wx.ToWindow(treeCtrl), wx.LEFT, "Hello")
	// wxTreeCtrl has an overloaded `GetNextSibling` function, which as a different
	// signature with wxWindow. So we have to cast wxTreeCtrl to wxWindow manually.
	// Equivalent: treeCtrl.SwigGetWindow()

	// CenterPane - a text control

	paneInfo = wx.NewAuiPaneInfoT().Name("notebook").CenterPane().PaneBorder(false)
	notebook := wx.NewAuiNotebook(self, wx.ID_ANY, wx.DefaultPosition, wx.DefaultSize, wx.AUI_NB_DEFAULT_STYLE|wx.AUI_NB_CLOSE_BUTTON)
	notebook.AddPage(wx.NewTextCtrl(notebook, wx.ID_ANY, "", wx.DefaultPosition, wx.DefaultSize, wx.TE_MULTILINE), "Test", true)
	self.auiManager.AddPane(notebook, paneInfo)

	self.auiManager.Update()

	return self
}

func main() {
	wx1 := wx.NewApp()
	frame := NewMyFrame()
	frame.Show()
	wx1.MainLoop()
	return
}
