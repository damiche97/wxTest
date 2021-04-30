//
// Created by michael on 30.04.21.
//

#ifndef WXTEST_CCANVAS_H
#define WXTEST_CCANVAS_H

#include "wx/wx.h"
#include "wx/vscroll.h"
//#pragma once

class cCanvas : public wxHVScrolledWindow {
public:
    cCanvas(wxWindow *parent);
    ~cCanvas();

private:
    int m_nPixelSize = 8;
public:
    void SetPixelSize( int n);

private:
    virtual wxCoord OnGetRowHeight(size_t row) const;
    virtual wxCoord OnGetColumnWidth(size_t col) const;

    void OnDraw(wxDC& dc);
    void OnPaint(wxPaintEvent &evt);

    wxDECLARE_EVENT_TABLE();

};


#endif //WXTEST_CCANVAS_H
