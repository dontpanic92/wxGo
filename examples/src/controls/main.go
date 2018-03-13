package main

import "github.com/dontpanic92/wxGo/wx"

type ControlDialog struct {
	wx.Dialog
}

func NewControlDialog() ControlDialog {
	f := ControlDialog{}
	f.Dialog = wx.NewDialog(wx.NullWindow, -1, "Controls", wx.DefaultPosition, wx.NewSizeT(600, 400))

	bSizer2 := wx.NewBoxSizer(wx.HORIZONTAL)
	bSizer3 := wx.NewBoxSizer(wx.VERTICAL)

	radioBox2 := wx.NewRadioBox(f, wx.ID_ANY, "wxRadioBox", wx.DefaultPosition, wx.DefaultSize, []string{"aaa", "bbb"}, 1, wx.HORIZONTAL)
	radioBox2.SetSelection(0)
	bSizer3.Add(radioBox2, 0, wx.ALL|wx.EXPAND, 5)

	checkBox2 := wx.NewCheckBox(f, wx.ID_ANY, "Check Me!", wx.DefaultPosition, wx.DefaultSize, 0)
	bSizer3.Add(checkBox2, 0, wx.ALL|wx.EXPAND, 5)

	staticText2 := wx.NewStaticText(f, wx.ID_ANY, "MyLabel", wx.DefaultPosition, wx.DefaultSize, 0)
	staticText2.Wrap(-1)
	bSizer3.Add(staticText2, 0, wx.ALL|wx.EXPAND, 5)

	textCtrl2 := wx.NewTextCtrl(f, wx.ID_ANY, "", wx.DefaultPosition, wx.DefaultSize, 0)
	bSizer3.Add(textCtrl2, 0, wx.ALL|wx.EXPAND, 5)

	slider1 := wx.NewSlider(f, wx.ID_ANY, 50, 0, 100, wx.DefaultPosition, wx.DefaultSize, wx.HORIZONTAL)
	bSizer3.Add(slider1, 0, wx.ALL|wx.EXPAND, 5)

	bSizer2.Add(bSizer3, 1, wx.EXPAND, 5)
	bSizer4 := wx.NewBoxSizer(wx.VERTICAL)

	listBox2 := wx.NewListBox(f, wx.ID_ANY, wx.DefaultPosition, wx.DefaultSize, []string{"aaa", "bbb"}, 0)
	listBox2.InsertItems([]string{"ccc"}, 1)
	bSizer4.Add(listBox2, 1, wx.ALL|wx.EXPAND, 5)

	gauge1 := wx.NewGauge(f, wx.ID_ANY, 100, wx.DefaultPosition, wx.DefaultSize, wx.HORIZONTAL)
	gauge1.SetValue(50)
	bSizer4.Add(gauge1, 0, wx.ALL|wx.EXPAND, 5)

	button5 := wx.NewButton(f, wx.ID_ANY, "MyButton", wx.DefaultPosition, wx.DefaultSize, 0)
	bSizer4.Add(button5, 0, wx.ALL|wx.EXPAND, 5)

	button6 := wx.NewButton(f, wx.ID_ANY, "MyButton", wx.DefaultPosition, wx.DefaultSize, 0)
	bSizer4.Add(button6, 0, wx.ALL|wx.EXPAND, 5)

	bSizer2.Add(bSizer4, 1, wx.EXPAND, 5)

	f.SetSizer(bSizer2)
	f.Layout()

	f.Centre(wx.BOTH)

	return f
}

func main() {
	wx.NewApp()
	f := NewControlDialog()
	f.ShowModal()
	f.Destroy()
	return
}
