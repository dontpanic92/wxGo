package main

import "github.com/dontpanic92/wxGo/wx"

//Frame Struct def
type MyFrame struct {
	wx.Frame
	statusbar wx.StatusBar
	toolbar   wx.ToolBar
	menubar   wx.MenuBar
	notebook  wx.AuiNotebook
}

//Menu Event Functions def
func (f *MyFrame) evtColour(wx.Event) {
	colourdlg := wx.NewColourDialog(f)
	if colourdlg.ShowModal() == wx.ID_OK {
		colour := colourdlg.GetColourData().GetColour()
		currentPage := f.notebook.GetCurrentPage()
		if currentPage != wx.NullWindow {
			currentPage.SetForegroundColour(colour)
		}
	}
	colourdlg.Destroy()
}

func (f *MyFrame) evtFont(wx.Event) {
	fontdlg := wx.NewFontDialog(f)
	if fontdlg.ShowModal() == wx.ID_OK {
		font := fontdlg.GetFontData().GetChosenFont()
		currentPage := f.notebook.GetCurrentPage()
		if currentPage != wx.NullWindow {
			currentPage.SetFont(font)
		}
	}
	fontdlg.Destroy()
}

func (f *MyFrame) evtOpenFile(wx.Event) {
	path := wx.LoadFileSelector("Text", "*")
	if path != "" {
		textCtrl := wx.NewTextCtrl(f.notebook, wx.ID_ANY, "", wx.DefaultPosition, wx.DefaultSize, wx.TE_MULTILINE)
		textCtrl.SetMinSize(wx.NewSizeT(600, 400))
		f.notebook.AddPage(textCtrl, path)
		textCtrl.LoadFile(path)
		textCtrl.SetFocus()
	}
}

func (f *MyFrame) evtAbout(wx.Event) {
	aboutinfo := wx.NewAboutDialogInfo()
	aboutinfo.SetName("Dapeton")
	aboutinfo.AddDeveloper("dontpanic")
	aboutinfo.SetDescription("Dapeton is a notepad using wxGo.")
	aboutinfo.SetWebSite("http://github.com/dontpanic92/wxGo")
	aboutinfo.SetVersion("0.1")
	wx.AboutBox(aboutinfo)
	wx.DeleteAboutDialogInfo(aboutinfo)
}

//Frame Init def
func NewMyFrame() *MyFrame {
	f := &MyFrame{}
	f.Frame = wx.NewFrame(wx.NullWindow, -1, "Dapeton")

	f.statusbar = f.CreateStatusBar()
	f.statusbar.SetStatusText("Welcome to wxWidgets")

	f.statusbar.SetFieldsCount(2)
	f.statusbar.SetStatusText("This is a statusbar!", 1)

	f.menubar = wx.NewMenuBar()
	menuFile := wx.NewMenu()
	menuEdit := wx.NewMenu()
	menuHelp := wx.NewMenu()

	menuItemOpenFile := wx.NewMenuItem(menuFile, wx.ID_ANY, "&Open...", "Open a File", wx.ITEM_NORMAL)
	menuFile.Append(menuItemOpenFile)
	menuItemExit := wx.NewMenuItem(menuFile, wx.ID_ANY, "&Exit", "Exit", wx.ITEM_NORMAL)
	menuFile.Append(menuItemExit)
	menuItemFont := wx.NewMenuItem(menuFile, wx.ID_ANY, "&Font...", "Select a Font", wx.ITEM_NORMAL)
	menuEdit.Append(menuItemFont)
	menuItemColour := wx.NewMenuItem(menuFile, wx.ID_ANY, "&Colour...", "Select a Colour", wx.ITEM_NORMAL)
	menuEdit.Append(menuItemColour)
	menuItemAbout := wx.NewMenuItem(menuFile, wx.ID_ANY, "&About", "About", wx.ITEM_NORMAL)
	menuHelp.Append(menuItemAbout)

	f.menubar.Append(menuFile, "&File")
	f.menubar.Append(menuEdit, "&Edit")
	f.menubar.Append(menuHelp, "&Help")
	f.SetMenuBar(f.menubar)

	f.toolbar = f.CreateToolBar(wx.TB_HORIZONTAL, wx.ID_ANY)
	//f.toolbar.AddTool( wx.ID_ANY, "tool", wx.GetNullBitmap())
	f.toolbar.AddSeparator()
	//f.toolbar.AddTool( wx.ID_ANY, "tool", wx.GetNullBitmap())
	f.toolbar.Realize()

	mainSizer := wx.NewBoxSizer(wx.HORIZONTAL)
	f.SetSizer(mainSizer)

	f.notebook = wx.NewAuiNotebook(f, wx.ID_ANY, wx.DefaultPosition, wx.DefaultSize, wx.AUI_NB_DEFAULT_STYLE|wx.AUI_NB_CLOSE_BUTTON)

	mainSizer.Add(f.notebook, 1, wx.EXPAND, 5)

	textCtrl := wx.NewTextCtrl(f.notebook, wx.ID_ANY, "", wx.DefaultPosition, wx.DefaultSize, wx.TE_MULTILINE)
	textCtrl.SetMinSize(wx.NewSizeT(600, 400))

	f.notebook.AddPage(textCtrl, "Untitled", true)
	textCtrl.SetFocus()

	f.Layout()

	wx.Bind(f, wx.EVT_MENU, f.evtFont, menuItemFont.GetId())
	wx.Bind(f, wx.EVT_MENU, f.evtColour, menuItemColour.GetId())
	wx.Bind(f, wx.EVT_MENU, f.evtOpenFile, menuItemOpenFile.GetId())
	wx.Bind(f, wx.EVT_MENU, f.evtAbout, menuItemAbout.GetId())

	//wx.Unbind( f, wx.EVT_MENU, f.evtAbout, menuItemAbout.GetId() )

	return f
}

//Main Function
func main() {
	wx1 := wx.NewApp()
	f := NewMyFrame()
	f.Show()
	wx1.MainLoop()
	return
}
