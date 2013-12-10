package main

import "./wx"

func evtMenu(wx.Event){
		wx.MessageBox(wx.NewString("Welcome to wxWidgets!"));
}

func InitFrame(){
        frame := wx.NewFrame()
        str := wx.NewString("GoLang wxWidgets Wrapper")
        frame.Create(wx.NullWindow, -1, str)
        
        statusbar := frame.CreateStatusBar()
        statusbar.SetStatusText(wx.NewString("Welcome to wxWidgets"))
        
        statusbar.SetFieldsCount(2)
        statusbar.SetStatusText(wx.NewString("This is a statusbar!"), 1)
        
        menubar := wx.NewMenuBar()
        menuFile := wx.NewMenu()
        menuItemNew := wx.NewMenuItem(menuFile, int(wx.ID_ANY), wx.NewString("File"), wx.NewString("Create New File"), wx.ITEM_NORMAL)
        menuFile.Append(menuItemNew)
        menubar.Append(menuFile, wx.NewString("File"))
        frame.SetMenuBar(menubar)

        mainSizer := wx.NewBoxSizer(int(wx.HORIZONTAL) )
        frame.SetSizer(mainSizer)
        
        textCtrl := wx.NewTextCtrl(frame, int(wx.ID_ANY), wx.NewString(""), wx.DefaultPosition, wx.DefaultSize, wx.TE_MULTILINE)
        textCtrl.SetMinSize(wx.NewSize(600, 400))
        mainSizer.Add(textCtrl, 1, int(wx.EXPAND), 5)
        
        frame.Layout()
		mainSizer.Fit(frame)
        wx.Bind( frame, wx.EVT_MENU, evtMenu, menuItemNew.GetId() )
        //wx.Unbind( frame, wx.EVT_MENU, evtMenu, menuItemNew.GetId() )
        
        frame.Show()
}

func main(){
        wx1 := wx.NewApp()
        InitFrame();
        wx1.MainLoop()
        
}
