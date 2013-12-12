package main

import "../lib/wx"

func evtMenu(wx.Event){
		s := wx.NewString("Welcome to wxWidgets!\nString test|测试|測試|試験|테스트")
		str := s.Utf8_str()
		wx.MessageBox(str);
}

func InitFrame(){
        frame := wx.NewFrame()
        str := "GoLang wxWidgets Wrapper"
        frame.Create(wx.NullWindow, -1, str)
        
        statusbar := frame.CreateStatusBar()
        statusbar.SetStatusText("Welcome to wxWidgets")
        
        statusbar.SetFieldsCount(2)
        statusbar.SetStatusText("This is a statusbar!", 1)
        
        menubar := wx.NewMenuBar()
        menuFile := wx.NewMenu()
        menuItemNew := wx.NewMenuItem(menuFile, int(wx.ID_ANY), "Hello", "Create New File", wx.ITEM_NORMAL)
        menuFile.Append(menuItemNew)
        menubar.Append(menuFile, "File")
        frame.SetMenuBar(menubar)

        mainSizer := wx.NewBoxSizer(int(wx.HORIZONTAL) )
        frame.SetSizer(mainSizer)
        
        notebook := wx.NewNotebook( frame, int(wx.ID_ANY), wx.DefaultPosition, wx.DefaultSize, 0 )
        
        mainSizer.Add(notebook, 1, int(wx.EXPAND), 5)
        
        panel := wx.NewPanel(notebook, int(wx.ID_ANY), wx.DefaultPosition, wx.DefaultSize, wx.TAB_TRAVERSAL)

	textCtrl := wx.NewTextCtrl(panel, int(wx.ID_ANY), "", wx.DefaultPosition, wx.DefaultSize, wx.TE_MULTILINE)
        textCtrl.SetMinSize(wx.NewSize(600, 400))

		bSizer := wx.NewBoxSizer(int(wx.VERTICAL))
        bSizer.Add(textCtrl, 1, int(wx.EXPAND), 5)

		panel.SetSizer(bSizer)
		panel.Layout()
		bSizer.Fit(panel)
		notebook.AddPage(panel, "This is a page", true)
		textCtrl.SetFocus()
        
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
