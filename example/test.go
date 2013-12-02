package main

import "./wx"
import "fmt"

type mynullwindow struct{
}

func (window mynullwindow)Swigcptr()(uintptr){
	return 0
}

func InitFrame(){
	frame := wx.NewFrame()
	m := new(mynullwindow)
	str := wx.NewString("GoLang wxWidgets Wrapper")
	frame.Create(m, -1, str)
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

	frame.Show()
	
	point := frame.GetClientAreaOrigin()
	fmt.Println(point.GetX())
}

func main(){
	wx1 := wx.NewApp()
	InitFrame();
	wx1.MainLoop()
	
}
