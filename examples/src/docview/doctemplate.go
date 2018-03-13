package main

import "github.com/dontpanic92/wxGo/wx"

// See view.go for inheritance usage

type MyTextDocTemplate struct {
	dt wx.DocTemplate
}

func (self *MyTextDocTemplate) DoCreateDocument() wx.Document {
	return NewTextEditDocument()
}

func (self *MyTextDocTemplate) DoCreateView() wx.View {
	return NewMyTextView()
}

func NewMyTextDocTemplate(docMan wx.DocManager, descr string, filter string, dir string, ext string,
	docTypeName string, viewTypeName string) wx.DocTemplate {
	tdt := &MyTextDocTemplate{}
	dt := wx.NewDirectorDocTemplate(tdt, docMan, descr, filter, dir, ext, docTypeName, viewTypeName)
	tdt.dt = dt
	return dt
}
