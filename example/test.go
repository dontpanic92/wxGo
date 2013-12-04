package main

import "./wx"
import "fmt"


func InitFrame(){
	frame := wx.NewFrame()
	str := wx.NewString("GoLang wxWidgets Wrapper")
	frame.Create(wx.NullWindow(), -1, str)
	statusbar := frame.CreateStatusBar()
	statusbar.SetStatusText(wx.NewString("Welcome to wxWidgets"))
	
	statusbar.SetFieldsCount(2)
	statusbar.SetStatusText(wx.NewString("This is a statusbar!"), 1)
	
	menubar := wx.NewMenuBar()
	menuFile := wx.NewMenu()
	menuItemNew := wx.NewMenuItem(menuFile, 0, wx.NewString("File"), wx.NewString("Create New File"), 0)
	menuFile.Append(menuItemNew)
	menubar.Append(menuFile, wx.NewString("File"))
	frame.SetMenuBar(menubar)

	mainSizer := wx.NewBoxSizer( 0x0004 )
	frame.SetSizer(mainSizer)
	
	frame.Show()
	
	point := frame.GetClientAreaOrigin()
	fmt.Println(point.GetX())
}

func main(){
	wx1 := wx.NewApp()
	InitFrame();
	wx1.MainLoop()
	
}
