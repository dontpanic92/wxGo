package main
import "fmt"
import "github.com/dontpanic92/wxGo/wx"

type MyFrame struct {
	wx.Frame
	statusbar wx.StatusBar
	toolbar   wx.ToolBar
	menubar   wx.MenuBar
	browser   wx.WebView

	backBtn    wx.ToolBarToolBase
	forwardBtn wx.ToolBarToolBase
	stopBtn    wx.ToolBarToolBase
	refreshBtn wx.ToolBarToolBase
	goBtn      wx.ToolBarToolBase

	urlBox wx.TextCtrl
}

func (f *MyFrame) evtAbout(wx.Event) {
	aboutinfo := wx.NewAboutDialogInfo()
	aboutinfo.SetName("wxGo Web Explorer")
	aboutinfo.AddDeveloper("dontpanic")
	aboutinfo.SetDescription("A Web Explorer using wxGo.")
	aboutinfo.SetWebSite("http://github.com/dontpanic92/wxGo")
	aboutinfo.SetVersion("0.1")
	wx.AboutBox(aboutinfo)
	wx.DeleteAboutDialogInfo(aboutinfo)
}

func NewMyFrame() *MyFrame {
	self := &MyFrame{}
	self.Frame = wx.NewFrame(wx.NullWindow, -1, "wxGo Web Explorer", wx.DefaultPosition, wx.NewSizeT(800, 600))

	// Statusbar
	self.statusbar = self.CreateStatusBar()
	self.statusbar.SetStatusText("Ready")
	self.statusbar.SetFieldsCount(2)
	self.statusbar.SetStatusText("Welcome to wxWidgets", 1)

	// Menubar
	self.menubar = wx.NewMenuBar()
	menuHelp := wx.NewMenu()
	menuItemAbout := wx.NewMenuItem(menuHelp, wx.ID_ANY, "&About", "About", wx.ITEM_NORMAL)
	menuHelp.Append(menuItemAbout)
	self.menubar.Append(menuHelp, "&Help")
	self.SetMenuBar(self.menubar)

	// Toolbar
	self.toolbar = self.CreateToolBar(wx.TB_HORIZONTAL, wx.ID_ANY)
	self.backBtn = self.toolbar.AddTool(wx.ID_ANY, "Back", wx.ArtProviderGetBitmap(wx.ART_GO_BACK), wx.NullBitmap, wx.ITEM_NORMAL, "Back", "Go Back")
	self.forwardBtn = self.toolbar.AddTool(wx.ID_ANY, "Forward", wx.ArtProviderGetBitmap(wx.ART_GO_FORWARD), wx.NullBitmap, wx.ITEM_NORMAL, "Forward", "Go Forward")
	self.stopBtn = self.toolbar.AddTool(wx.ID_ANY, "Stop", wx.ArtProviderGetBitmap(wx.ART_CROSS_MARK), wx.NullBitmap, wx.ITEM_NORMAL, "Stop", "Stop")
	self.refreshBtn = self.toolbar.AddTool(wx.ID_ANY, "Refresh", wx.NewBitmap(refresh_xpm), wx.NullBitmap, wx.ITEM_NORMAL, "Reload", "Refresh current page")

	self.urlBox = wx.NewTextCtrl(self.toolbar, wx.ID_ANY, "", wx.DefaultPosition, wx.NewSizeT(400, -1), wx.TE_PROCESS_ENTER)
	self.toolbar.AddControl(self.urlBox)

	self.goBtn = self.toolbar.AddTool(wx.ID_ANY, "Go!", wx.ArtProviderGetBitmap(wx.ART_GOTO_LAST), wx.NullBitmap, wx.ITEM_NORMAL, "Go!", "Go!")

	self.toolbar.Realize()

	fmt.Println(len(cursor_png))
	// Cursor
	bitmap := wx.BitmapNewFromPNGData(cursor_png)
	fmt.Println(":::::", bitmap.IsOk())
	image := bitmap.ConvertToImage()
	cursor := wx.NewCursor(image)
	self.SetCursor(cursor)

	// Content Area
	mainSizer := wx.NewBoxSizer(wx.VERTICAL)
	self.SetSizer(mainSizer)

	self.browser = wx.WebViewNew(self, wx.ID_ANY)
	self.browser.LoadURL("http://www.wxwidgets.org")
	self.browser.SetMinSize(wx.NewSizeT(600, 400))
	mainSizer.Add(self.browser, 1, wx.EXPAND, 5)

	self.Layout()

	// Menu event bindings
	wx.Bind(self, wx.EVT_MENU, self.evtAbout, menuItemAbout.GetId())

	// Browser event bindings
	wx.Bind(self, wx.EVT_WEBVIEW_NAVIGATING, func(e wx.Event) {
		webViewEvent := wx.ToWebViewEvent(e)
		self.statusbar.SetStatusText("Navigating " + webViewEvent.GetURL() + " ...")
		self.UpdateState()
	}, self.browser.GetId())

	wx.Bind(self, wx.EVT_WEBVIEW_NAVIGATED, func(e wx.Event) {
		self.statusbar.SetStatusText("Ready")
		self.UpdateState()
	}, self.browser.GetId())

	// Toolbar tools event bindings
	wx.Bind(self, wx.EVT_TOOL, func(e wx.Event) {
		self.browser.GoBack()
	}, self.backBtn.GetId())

	wx.Bind(self, wx.EVT_TOOL, func(e wx.Event) {
		self.browser.GoForward()
	}, self.forwardBtn.GetId())

	wx.Bind(self, wx.EVT_TOOL, func(e wx.Event) {
		self.browser.Stop()
	}, self.stopBtn.GetId())

	wx.Bind(self, wx.EVT_TOOL, func(e wx.Event) {
		self.browser.Reload()
	}, self.refreshBtn.GetId())

	wx.Bind(self, wx.EVT_TOOL, func(e wx.Event) {
		self.browser.LoadURL(self.urlBox.GetValue())
		self.browser.SetFocus()
	}, self.goBtn.GetId())

	// URL box event bindings
	wx.Bind(self, wx.EVT_TEXT_ENTER, func(e wx.Event) {
		self.browser.LoadURL(self.urlBox.GetValue())
		self.browser.SetFocus()
	}, self.urlBox.GetId())

	// Frame event bindings
	wx.Bind(self, wx.EVT_IDLE, func(wx.Event) {
		if self.browser.IsBusy() {
			self.toolbar.EnableTool(self.stopBtn.GetId(), true)
		} else {
			self.toolbar.EnableTool(self.stopBtn.GetId(), false)
		}
	}, wx.ID_ANY)

	return self
}

func (self *MyFrame) UpdateState() {
	self.toolbar.EnableTool(self.backBtn.GetId(), self.browser.CanGoBack())
	self.toolbar.EnableTool(self.forwardBtn.GetId(), self.browser.CanGoForward())

	if self.browser.IsBusy() {
		self.toolbar.EnableTool(self.stopBtn.GetId(), true)
	} else {
		self.toolbar.EnableTool(self.stopBtn.GetId(), false)
	}

	self.SetTitle(self.browser.GetCurrentTitle())
	self.urlBox.SetValue(self.browser.GetCurrentURL())
}

//Main Function
func main() {
	wx1 := wx.NewApp()
	wx.InitAllImageHandlers()
	f := NewMyFrame()
	f.Show()
	wx1.MainLoop()
	return
}
