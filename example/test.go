package main

import "github.com/dontpanic92/wxGo/wx"

//Frame Struct def
type MyFrame struct {
    wx.Frame
    statusbar wx.StatusBar
    toolbar wx.ToolBar
    menubar wx.MenuBar
    notebook wx.Notebook
}


//Menu Event Functions def
func (f *MyFrame)evtColour(wx.Event) {
    colourdlg := wx.NewColourDialog(f)
    if colourdlg.ShowModal() == int(wx.ID_OK){
        colour := colourdlg.GetColourData().GetColour()
        f.notebook.GetCurrentPage().SetForegroundColour(colour)
    }
    colourdlg.Destroy()    
}


func (f *MyFrame)evtFont(wx.Event) {
    fontdlg := wx.NewFontDialog(f)
    if fontdlg.ShowModal() == int(wx.ID_OK){
        font := fontdlg.GetFontData().GetChosenFont()
        f.notebook.GetCurrentPage().SetFont(font)
    }
    fontdlg.Destroy()
}

func (f *MyFrame)evtOpenFile(wx.Event) {
    wx.ToTextCtrl(f.notebook.GetCurrentPage()).LoadFile(wx.LoadFileSelector("Text", "*"))
}

func (f *MyFrame)evtAbout(wx.Event) {        
    wx.MessageBox("Welcome to wxWidgets!\nString test|测试|測試|試験|테스트")
    aboutinfo := wx.NewAboutDialogInfo()
    aboutinfo.SetName("wxGo Example")
    aboutinfo.AddDeveloper("wxGo Developers")
    aboutinfo.SetWebSite("http://github.com/dontpanic92/wxGo")
    aboutinfo.SetVersion("0.1")
    wx.AboutBox(aboutinfo)
}

//Frame Init def
func NewMyFrame() MyFrame {
    var f MyFrame
    f.Frame = wx.NewFrame()
    f.Create(wx.NullWindow, -1, "GoLang wxWidgets Wrapper")
        
    f.statusbar = f.CreateStatusBar()
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
    f.SetMenuBar(f.menubar)


    f.toolbar = f.CreateToolBar( int64(wx.TB_HORIZONTAL), int(wx.ID_ANY) ) 
    //f.toolbar.AddTool( int(wx.ID_ANY), "tool", wx.GetNullBitmap()) 
    f.toolbar.AddSeparator()
    //f.toolbar.AddTool( int(wx.ID_ANY), "tool", wx.GetNullBitmap()) 
    f.toolbar.Realize()


    mainSizer := wx.NewBoxSizer(int(wx.HORIZONTAL) )
    f.SetSizer(mainSizer)
        
    f.notebook = wx.NewNotebook( f, int(wx.ID_ANY), wx.DefaultPosition, wx.DefaultSize, int64(0) )
        
    mainSizer.Add(f.notebook, 1, int(wx.EXPAND), 5)
        
    

    textCtrl := wx.NewTextCtrl(f.notebook, int(wx.ID_ANY), "", wx.DefaultPosition, wx.DefaultSize, int64(wx.TE_MULTILINE))
    textCtrl.SetMinSize(wx.NewSize(600, 400))
    //textCtrl.SetDefaultStyle(wx.NewTextAttr(wx.RED))

    f.notebook.AddPage(textCtrl, "This is a page", true)
    textCtrl.SetFocus()
        
    f.Layout()
    mainSizer.Fit(f)
    
    wx.Bind( f, wx.EVT_MENU, f.evtFont, menuItemFont.GetId() )
    wx.Bind( f, wx.EVT_MENU, f.evtColour, menuItemColour.GetId() )
    wx.Bind( f, wx.EVT_MENU, f.evtOpenFile, menuItemOpenFile.GetId() )
    wx.Bind( f, wx.EVT_MENU, f.evtAbout, menuItemAbout.GetId() )

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
