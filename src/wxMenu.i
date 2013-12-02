%rename(MenuItem) wxMenuItem;
%rename(MenuBar) wxMenuBar;
%rename(Menu) wxMenu;

%{
	#include "wx/wx.h"
	#include "wx/menu.h"
%}

%include "wxGoInterface/menu.h"
