package main

import "../lib/wx"

//Frame Struct def
type myframe struct {
	frame wx.Frame
	statusbar wx.StatusBar
	toolbar wx.ToolBar
	menubar wx.MenuBar
	notebook wx.Notebook
	
	
}


//Menu Event Functions def
func (f *myframe)evtColour(wx.Event){
	colourdlg := wx.NewColourDialog(f.frame)
	if colourdlg.ShowModal() == int(wx.ID_OK){
		colour := colourdlg.GetColourData().GetColour()
		f.notebook.GetCurrentPage().SetForegroundColour(colour)
	}
	colourdlg.Destroy()	
}


func (f *myframe)evtFont(wx.Event){
	fontdlg := wx.NewFontDialog(f.frame)
	if fontdlg.ShowModal() == int(wx.ID_OK){
		font := fontdlg.GetFontData().GetChosenFont()
		f.notebook.GetCurrentPage().SetFont(font)
	}
	fontdlg.Destroy()
}

func (f *myframe)evtOpenFile(wx.Event){
	wx.ToTextCtrl(f.notebook.GetCurrentPage()).LoadFile(wx.LoadFileSelector("Text", "*"))
}

func (f *myframe)evtAbout(wx.Event){		
	wx.MessageBox("Welcome to wxWidgets!\nString test|测试|測試|試験|테스트")
	aboutinfo := wx.NewAboutDialogInfo()
	aboutinfo.SetName("wxGo Example")
	aboutinfo.AddDeveloper("wxGo Developers")
	aboutinfo.SetWebSite("http://github.com/dontpanic92/wxGo")
	aboutinfo.SetVersion("0.1")
	wx.AboutBox(aboutinfo)
}


//Frame Init def
func (f *myframe)InitFrame(){
    f.frame = wx.NewFrame()
    f.frame.Create(wx.NullWindow, -1, "GoLang wxWidgets Wrapper")
        
    f.statusbar = f.frame.CreateStatusBar()
    f.statusbar.SetStatusText("Welcome to wxWidgets")
        
    f.statusbar.SetFieldsCount(2)
    f.statusbar.SetStatusText("This is a statusbar!", 1)
        
    f.menubar = wx.NewMenuBar()
    menuFile := wx.NewMenu()
    
    menuItemFont := wx.NewMenuItem(menuFile, int(wx.ID_ANY), "Font...", "Select a Font", wx.ITEM_NORMAL)
    menuFile.Append(menuItemFont)
    menuItemColour := wx.NewMenuItem(menuFile, int(wx.ID_ANY), "Colour...", "Select a Colour", wx.ITEM_NORMAL)
    menuFile.Append(menuItemColour)
    menuItemOpenFile := wx.NewMenuItem(menuFile, int(wx.ID_ANY), "Open...", "Open a File", wx.ITEM_NORMAL)
    menuFile.Append(menuItemOpenFile)
    menuItemAbout := wx.NewMenuItem(menuFile, int(wx.ID_ANY), "About", "About", wx.ITEM_NORMAL)
    menuFile.Append(menuItemAbout)
    
    f.menubar.Append(menuFile, "File")
    f.frame.SetMenuBar(f.menubar)


    f.toolbar = f.frame.CreateToolBar( wx.TB_HORIZONTAL, int(wx.ID_ANY) ) 
    f.toolbar.AddTool( int(wx.ID_ANY), "tool", wx.GetNullBitmap()) 
    f.toolbar.AddSeparator()
    f.toolbar.AddTool( int(wx.ID_ANY), "tool", wx.GetNullBitmap()) 
    f.toolbar.Realize()


    mainSizer := wx.NewBoxSizer(int(wx.HORIZONTAL) )
    f.frame.SetSizer(mainSizer)
        
    f.notebook = wx.NewNotebook( f.frame, int(wx.ID_ANY), wx.DefaultPosition, wx.DefaultSize, 0 )
        
    mainSizer.Add(f.notebook, 1, int(wx.EXPAND), 5)
        
    

	textCtrl := wx.NewTextCtrl(f.notebook, int(wx.ID_ANY), "", wx.DefaultPosition, wx.DefaultSize, wx.TE_MULTILINE)
    textCtrl.SetMinSize(wx.NewSize(600, 400))
	//textCtrl.SetDefaultStyle(wx.NewTextAttr(wx.RED))

	f.notebook.AddPage(textCtrl, "This is a page", true)
	textCtrl.SetFocus()
        
    f.frame.Layout()
	mainSizer.Fit(f.frame)
	
    wx.Bind( f.frame, wx.EVT_MENU, f.evtFont, menuItemFont.GetId() )
    wx.Bind( f.frame, wx.EVT_MENU, f.evtColour, menuItemColour.GetId() )
    wx.Bind( f.frame, wx.EVT_MENU, f.evtOpenFile, menuItemOpenFile.GetId() )
    wx.Bind( f.frame, wx.EVT_MENU, f.evtAbout, menuItemAbout.GetId() )

    //wx.Unbind( f.frame, wx.EVT_MENU, f.evtAbout, menuItemAbout.GetId() )
    
    
    f.frame.Show()
}


//Main Function
func main(){
    wx1 := wx.NewApp()
    var f myframe
    f.InitFrame()
    wx1.MainLoop()
}
