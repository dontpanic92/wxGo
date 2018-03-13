// Issue #10. Original code by @andrewarrow.

package main

import "github.com/dontpanic92/wxGo/wx"
import "time"

const UPLOAD_WORKER_ID = wx.ID_HIGHEST + 1

type MyFrame struct {
	wx.Frame
}

func (self *MyFrame) startUpload() {
	i := 0
	for {
		i = i % 101

		threadEvent := wx.NewThreadEvent(wx.EVT_THREAD, UPLOAD_WORKER_ID)
		threadEvent.SetInt(i)
		self.QueueEvent(threadEvent)

		i += 1
		time.Sleep(time.Millisecond * 100)
	}
}

func NewMyFrame() *MyFrame {
	self := &MyFrame{}
	self.Frame = wx.NewFrame(wx.NullWindow, -1, "Thread Event Test")
	mainSizer := wx.NewBoxSizer(wx.HORIZONTAL)
	g := wx.NewGauge(self, wx.ID_ANY, 100, wx.DefaultPosition, wx.NewSizeT(600, 40), 0)
	self.SetSizer(mainSizer)
	mainSizer.Add(g, 100, wx.ALL|wx.EXPAND, 50)
	self.Layout()

	wx.Bind(self, wx.EVT_THREAD, func(e wx.Event) {
		threadEvent := wx.ToThreadEvent(e)
		g.SetValue(threadEvent.GetInt())
	}, UPLOAD_WORKER_ID)

	go self.startUpload()
	return self
}

func main() {
	wx1 := wx.NewApp()
	f := NewMyFrame()
	f.Show()
	wx1.MainLoop()
	return
}
