package main

import "./wx"

type mynullwindow struct{
}

func (window mynullwindow)Swigcptr()(uintptr){
	return 0
}

func InitFrame(){
	frame := wx.NewWxFrame()
	m := new(mynullwindow)
	str := wx.NewWxString("GoLang wxWidgets Wapper")
	frame.Create(m, -1, str)
	frame.Show()
}

func main(){
	wx1 := wx.NewWxApp()
	wx1.MyInit();
	
	InitFrame();
	wx1.MainLoop(0)
	
}
