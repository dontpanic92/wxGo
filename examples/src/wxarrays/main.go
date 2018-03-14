package main

import "github.com/dontpanic92/wxGo/wx"
import "strconv"

type ListDialog struct {
	wx.Dialog
	listBox wx.ListBox
}

func NewListDialog() *ListDialog {
	self := &ListDialog{}
	self.Dialog = wx.NewDialog(wx.NullWindow, -1, "wxArrays Test")

	self.SetSizeHints(wx.DefaultSize, wx.DefaultSize)

	bSizer := wx.NewBoxSizer(wx.VERTICAL)

	self.listBox = wx.NewListBox(self, wx.ID_ANY, wx.DefaultPosition, wx.DefaultSize, []string{"aaa", "bbb"}, wx.LB_EXTENDED)
	self.listBox.InsertItems([]string{"ccc"}, 1)
	self.listBox.Set([]string{"ccc", "ddd"})
	bSizer.Add(self.listBox, 1, wx.ALL|wx.EXPAND, 5)

	strs := self.listBox.GetStrings()
	self.listBox.Set(strs)

	button := wx.NewButton(self, wx.ID_ANY, "Select Other Files", wx.DefaultPosition, wx.DefaultSize, 0)
	bSizer.Add(button, 0, wx.ALL|wx.EXPAND, 5)

	updateTitle := func() {
		selections := make([]int, 0)
		self.listBox.GetSelections(&selections)
		self.SetTitle("wxArrays Test - " + strconv.Itoa(len(selections)) + " item(s) selected")
	}

	wx.Bind(self, wx.EVT_LISTBOX, func(e wx.Event) {
		updateTitle()
	}, self.listBox.GetId())

	wx.Bind(self, wx.EVT_BUTTON, func(e wx.Event) {
		fd := wx.NewFileDialogT(wx.NullWindow, "Select Files", "", "", "*", wx.FD_MULTIPLE, wx.DefaultPosition, wx.DefaultSize, "Open")
		if fd.ShowModal() != wx.ID_CANCEL {
			list := make([]string, 0)
			fd.GetFilenames(&list)
			self.listBox.Set(list)
			updateTitle()
		}
	}, button.GetId())

	self.SetSizer(bSizer)
	self.Layout()
	self.Centre(wx.BOTH)

	return self
}

func main() {
	wx.NewApp()
	dlg := NewListDialog()
	dlg.ShowModal()
	dlg.Destroy()
}
