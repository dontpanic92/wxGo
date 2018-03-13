package main

import "github.com/dontpanic92/wxGo/wx"

type MainFrame struct {
	wx.Frame
	docMan wx.DocManager
}

func NewMainFrame() *MainFrame {
	self := &MainFrame{}
	self.docMan = wx.NewDocManager()
	NewMyTextDocTemplate(self.docMan, "Text", "*.txt;*.text", "", "txt;text",
		"Text Doc", "Text View")

	self.Frame = wx.NewDocMDIParentFrame(self.docMan, wx.ToFrame(wx.NullWindow), wx.ID_ANY,
		"wxGo DocView Sample")

	menuFile := wx.NewMenu()
	menuFile.Append(wx.ID_NEW)
	menuFile.Append(wx.ID_OPEN)
	menuFile.AppendSeparator()
	menuFile.Append(wx.ID_EXIT)

	menuBar := wx.NewMenuBar()
	menuBar.Append(menuFile, "File")

	self.Frame.SetMenuBar(menuBar)
	self.Layout()

	self.docMan.CreateNewDocument()

	return self
}

func main() {
	wx1 := wx.NewApp()
	frame := NewMainFrame()
	frame.Show()
	wx1.MainLoop()
	return
}
