//
// Created by michael on 30.04.21.
//

#include "cCanvas.h"

#include "wx/dcclient.h"
#include "wx/dcmemory.h"
#include "wx/dcbuffer.h"

wxBEGIN_EVENT_TABLE(cCanvas, wxHVScrolledWindow)
                EVT_PAINT(cCanvas::OnPaint)
wxEND_EVENT_TABLE()

cCanvas::cCanvas(wxWindow *parent) : wxHVScrolledWindow(parent, wxID_ANY) {
    SetRowColumnCount(40, 40);
    SetBackgroundColour(wxBG_STYLE_PAINT);
}

cCanvas::~cCanvas() {

}

void cCanvas::SetPixelSize(int n) {
    m_nPixelSize = n;
    wxVarHScrollHelper::RefreshAll();
    wxVarVScrollHelper::RefreshAll();
    Refresh();
}

wxCoord cCanvas::OnGetRowHeight(size_t row) const {
    return wxCoord(m_nPixelSize);
}

wxCoord cCanvas::OnGetColumnWidth(size_t col) const {
    return wxCoord(m_nPixelSize);
}

void cCanvas::OnDraw(wxDC &dc) {
    dc.Clear();

    wxBrush brush = dc.GetBrush();
    wxPen pen = dc.GetPen();

    pen.SetStyle(wxPENSTYLE_LONG_DASH);
    pen.SetColour(wxColour(200, 200, 200));
    dc.SetPen(pen);

    dc.SetBrush(brush);
    dc.DrawRectangle(20,20,200,200);
}

void cCanvas::OnPaint(wxPaintEvent &evt) {
    wxBufferedPaintDC dc(this);
    this->PrepareDC(dc);
    this->OnDraw(dc);
}

