%rename(Size) wxSize;
%rename(Point) wxPoint;
%rename(RealPoint) wxRealPoint;
%rename(Rect) wxRect;
%rename(StockGDI) wxStockGDI;

%{
	#include "wx/wx.h"
%}

%include "wxGoInterface/gdicmn.h"

