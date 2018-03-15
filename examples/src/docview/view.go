package main

import "github.com/dontpanic92/wxGo/wx"

/* This file demonstrates how to subclass a C++ class in Go.
 * It may be not intuitive because of the different design and mechanism
 * between C++ and go, but the following code works, thanks to SWIG.
 * Here we take the wxView class as an example to see how it works.
 *
 * We will deal with 3 things here:
 * 1. a director object
 * 2. overwrittenMethodsForView object that holds all overwritten
 *    virtual methods
 * 3. out myTextView struct that acts as a sub class of wxView
 *
 * 1. The overwrittenMethodsForView structure
 *    Let's see the overwrittenMethodsForView first. Actually it is NOT a wxView
 *    (Please note that it does NOT embed a wx.View and it shouldn't), but just
 *    holds all overwritten virtual methods, e.g. wxView::OnCreate, etc.
 * 2. The director object
 *    We use wx.NewDirectorView to create a director object of wxView. A director
 *    is an object that is responsible for "routing". It contains TWO parts:
 *    the C++ part, which is a sub class of the base class (here the base class
 *    is wxView), and it implements ALL virtual functions that the base class has,
 *    including pure virtual functions. The other part is the Go part, which contains
 *    a `overwrittenMethodsForView` struct.
 *    When a virtual function called, the director object will check whether the
 *    `overwrittenMethodsForView` object has an implementation of this virtual
 *    function. If Yes, then our go function will be called. If NO, the super
 *    function will be called when this function is NOT a pure virtual function,
 *    otherwise a panic will be raised - There is no implementation of a pure
 *    virtual function which is surely an error.
 * 3. myTextView
 *    This is the object that will be used in Go code. It is a wxView, as it embeds
 *    a wx.View. And it also solves another problem: Finalizers will not be called
 *    if there is a circular reference. The director and overwrittenMethodsForView
 *    refer each other, so we cannot apply finalizers on them. But myTextView is
 *    OK.
 *
 * Overview:
 *
 *   myTextView==============================
 *                                             circular ref
 *      wx.View (the director object)------  <---------------> overwrittenMethodsForView-----------------
 *        responsible for routing virtual calls                    virtual void OnCreate
 *      -----------------------------------                        virtual void OnDraw
 *                                                                 (Other virtual function implementations)
 *      (User-defined part of myTextView)                      ------------------------------------------
 *   ========================================
**/

// Our interface using in Go code
// It can be a superset of base class
type MyTextView interface {
	wx.View
	GetCtrl() wx.TextCtrl
}

// Our structure that implement the interface
type myTextView struct {
	wx.View
}

// We can get our MyTextView back using this hash.
// Mapping C++ pointer to Go object
// See overwrittenMethodsForTextEditDocument.GetTextCtrl function
var viewTrack map[uintptr]MyTextView = make(map[uintptr]MyTextView)

// This struct will hold all overwritten virtual methods.
type overwrittenMethodsForView struct {
	view     wx.View
	textCtrl wx.TextCtrl
}

func (self *overwrittenMethodsForView) OnCreate(doc wx.Document, flags int) bool {
	// Use wx.DirectorXYZABC to call super function XYZ::ABC
	// Do NOT call view.OnCreate in this function - that will cause recursion
	// because this function is exactly the view.OnCreate!
	if !wx.DirectorViewOnCreate(self.view, doc, flags) {
		return false
	}

	document := doc.SwigGetDocument()

	subFrame := wx.NewDocMDIChildFrame(document, self.view, wx.ToDocMDIParentFrame(wx.AppGetInstance().GetTopWindow()), wx.ID_ANY, "Child Frame", wx.DefaultPosition, wx.NewSizeT(300, 300))

	menuFile := wx.NewMenu()
	menuFile.Append(wx.ID_NEW)
	menuFile.Append(wx.ID_OPEN)
	menuFile.AppendSeparator()
	menuFile.Append(wx.ID_EXIT)

	menuEdit := wx.NewMenu()
	menuEdit.Append(wx.ID_COPY)
	menuEdit.Append(wx.ID_PASTE)
	menuEdit.Append(wx.ID_SELECTALL)

	menuBar := wx.NewMenuBar()
	menuBar.Append(menuFile, "File")
	menuBar.Append(menuEdit, "Edit")

	subFrame.SetMenuBar(menuBar)

	self.textCtrl = wx.NewTextCtrl(subFrame, wx.ID_ANY, "", wx.DefaultPosition, wx.DefaultSize, wx.TE_MULTILINE)

	subFrame.Show()
	return true
}

func (self *overwrittenMethodsForView) OnDraw(dc wx.DC) {
	// Do nothing.
	// The text ctrl will deal with all of the drawing things.
}

func (self *overwrittenMethodsForView) OnClose(deleteWindow bool) bool {
	if !wx.DirectorViewOnClose(self.view, deleteWindow) {
		return false
	}

	self.view.Activate(false)
	if deleteWindow {
		self.view.GetFrame().Destroy()
		self.view.SetFrame(wx.ToFrame(wx.NullWindow))
	}

	delete(viewTrack, self.view.Swigcptr())
	return true
}

func (self *overwrittenMethodsForView) OnCopy(e wx.Event) {
	self.textCtrl.Copy()
}

func (self *overwrittenMethodsForView) OnPaste(e wx.Event) {
	self.textCtrl.Paste()
}

func (self *overwrittenMethodsForView) OnSelectAll(e wx.Event) {
	self.textCtrl.SelectAll()
}

func (self myTextView) GetCtrl() wx.TextCtrl {
	return self.DirectorInterface().(*overwrittenMethodsForView).textCtrl
}

func NewMyTextView() MyTextView {
	om := &overwrittenMethodsForView{}
	dv := wx.NewDirectorView(om)
	om.view = dv
	// This makes circular reference but it's ok

	wx.Bind(dv, wx.EVT_MENU, om.OnCopy, wx.ID_COPY)
	wx.Bind(dv, wx.EVT_MENU, om.OnPaste, wx.ID_PASTE)
	wx.Bind(dv, wx.EVT_MENU, om.OnSelectAll, wx.ID_SELECTALL)

	mtv := &myTextView{View: dv}

	// Store our go object in the map
	viewTrack[mtv.Swigcptr()] = mtv
	return mtv
}

// In this case, wxWidgets will be responsible for
// release the view object. If the C++ code won't delete
// the object and you want Go to recycle the memory
// automatically, use the following function:
/* func NewMyTextViewT() MyTextView {
	myTextView := NewMyTextView()
	myTextView.SwigTrackObject()
	return myTextView
} */
