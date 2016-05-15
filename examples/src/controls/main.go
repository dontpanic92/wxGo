package main

import "wx"

type ControlDialog struct {
    wx.Dialog
}

func NewControlDialog() ControlDialog {
    var f ControlDialog
    f.Dialog = wx.NewDialog()
    f.Create(wx.NullWindow, -1, "Controls")
    
    
    f.SetSizeHints( wx.DefaultSize, wx.DefaultSize )
		
    bSizer2 := wx.NewBoxSizer( wx.HORIZONTAL )
    bSizer3 := wx.NewBoxSizer( wx.VERTICAL )
    

    m_radioBox2 := wx.NewRadioBox( f, wx.ID_ANY, "wxRadioBox", wx.DefaultPosition, wx.DefaultSize, []string{"aaa", "bbb"}, 1, wx.HORIZONTAL )
    m_radioBox2.SetSelection( 0 )
    bSizer3.Add( m_radioBox2, 0, wx.ALL|wx.EXPAND, 5 )
    
    m_checkBox2 := wx.NewCheckBox( f, wx.ID_ANY, "Check Me!", wx.DefaultPosition, wx.DefaultSize, 0)
    bSizer3.Add( m_checkBox2, 0, wx.ALL|wx.EXPAND, 5 )
    
    m_staticText2 := wx.NewStaticText( f, wx.ID_ANY, "MyLabel", wx.DefaultPosition, wx.DefaultSize, 0)
    m_staticText2.Wrap( -1 )
    bSizer3.Add( m_staticText2, 0, wx.ALL|wx.EXPAND, 5 )
    
    m_textCtrl2 := wx.NewTextCtrl( f, wx.ID_ANY, "", wx.DefaultPosition, wx.DefaultSize, 0)
    bSizer3.Add( m_textCtrl2, 0, wx.ALL|wx.EXPAND, 5 )
    
    m_slider1 := wx.NewSlider( f, wx.ID_ANY, 50, 0, 100, wx.DefaultPosition, wx.DefaultSize, wx.HORIZONTAL )
    bSizer3.Add( m_slider1, 0, wx.ALL|wx.EXPAND, 5 )
    
    
    bSizer2.Add( bSizer3, 1, wx.EXPAND, 5 )
    
    bSizer4 := wx.NewBoxSizer( wx.VERTICAL )
    
    
    m_listBox2 := wx.NewListBox( f, wx.ID_ANY, wx.DefaultPosition, wx.DefaultSize, []string{"aaa", "bbb"}, 0)
    m_listBox2.InsertItems([]string{"ccc"}, 1)
    bSizer4.Add( m_listBox2, 1, wx.ALL|wx.EXPAND, 5 )
    
    m_gauge1 := wx.NewGauge( f, wx.ID_ANY, 100, wx.DefaultPosition, wx.DefaultSize, wx.HORIZONTAL )
    m_gauge1.SetValue( 50 ) 
    bSizer4.Add( m_gauge1, 0, wx.ALL|wx.EXPAND, 5 )
    
    m_button5 := wx.NewButton( f, wx.ID_ANY, "MyButton", wx.DefaultPosition, wx.DefaultSize, 0)
    bSizer4.Add( m_button5, 0, wx.ALL|wx.EXPAND, 5 )
    
    m_button6 := wx.NewButton( f, wx.ID_ANY, "MyButton", wx.DefaultPosition, wx.DefaultSize, 0)
    bSizer4.Add( m_button6, 0, wx.ALL|wx.EXPAND, 5 )
    
    
    bSizer2.Add( bSizer4, 1, wx.EXPAND, 5 )
    
    
    f.SetSizer( bSizer2 )
    f.Layout()
    
    f.Centre( wx.BOTH )
    
    return f
}

func main() {
    wx.NewApp()
    f := NewControlDialog()
    f.ShowModal()
    return
}
