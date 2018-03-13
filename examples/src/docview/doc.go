package main

import "github.com/dontpanic92/wxGo/wx"

// See view.go for inheritance usage

type TextEditDocument struct {
	wx.Document
}

type overwrittenMethodsForTextEditDocument struct {
	doc wx.Document
}

func (self *overwrittenMethodsForTextEditDocument) OnCreate(path string, flags int) bool {

	if !wx.DirectorDocumentOnCreate(self.doc, path, flags) {
		return false
	}

	wx.Bind(self.GetTextCtrl(), wx.EVT_TEXT, self.OnTextChange, self.GetTextCtrl().GetId())

	return true
}

func (self *overwrittenMethodsForTextEditDocument) IsModified() bool {
	textCtrl := self.GetTextCtrl()
	return wx.DirectorDocumentIsModified(self.doc) || (textCtrl.Swigcptr() != 0 && textCtrl.IsModified())
}

func (self *overwrittenMethodsForTextEditDocument) Modify(mod bool) {
	wx.DirectorDocumentModify(self.doc, mod)
	textCtrl := self.GetTextCtrl()
	if textCtrl.Swigcptr() != 0 && !mod {
		textCtrl.DiscardEdits()
	}
}

func (self *overwrittenMethodsForTextEditDocument) DoSaveDocument(path string) bool {
	return self.GetTextCtrl().SaveFile(path)
}

func (self *overwrittenMethodsForTextEditDocument) DoOpenDocument(path string) bool {
	if !self.GetTextCtrl().LoadFile(path) {
		return false
	}

	wx.DirectorDocumentModify(self.doc, false)

	return true
}

func (self *overwrittenMethodsForTextEditDocument) OnTextChange(e wx.Event) {
	self.Modify(true)
	e.Skip()
}

func (self *overwrittenMethodsForTextEditDocument) GetTextCtrl() wx.TextCtrl {
	// Get our go object back
	view := viewTrack[self.doc.GetFirstView().Swigcptr()]
	if view == nil {
		return wx.ToTextCtrl(wx.NullWindow)
	}

	return view.GetCtrl()
}

func NewTextEditDocument() wx.Document {
	om := &overwrittenMethodsForTextEditDocument{}
	dd := wx.NewDirectorDocument(om)
	om.doc = dd

	return dd
}
