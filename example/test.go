package main

import "./wx"
import "fmt"

func evtMenu(wx.Event){
        fmt.Println("hi")
}

func InitFrame(){
        frame := wx.NewFrame()
        str := wx.NewString("GoLang wxWidgets Wrapper")
        frame.Create(wx.GetNullWindow(), -1, str)
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
        
        wx.Bind( frame, wx.GetEVT_MENU(), evtMenu, menuItemNew.GetId() )
        //wx.Unbind( frame, wx.GetEVT_MENU(), evtMenu, menuItemNew.GetId() )
        
        frame.Show()
}

func main(){
        wx1 := wx.NewApp()
        InitFrame();
        wx1.MainLoop()
        
}
