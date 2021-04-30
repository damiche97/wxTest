//
// Created by michael on 30.04.21.
//

#include "cEditorFrame.h"

wxBEGIN_EVENT_TABLE(cEditorFrame, wxMDIChildFrame)
    EVT_SLIDER(20001, cEditorFrame::OnZoomChange)
wxEND_EVENT_TABLE()

cEditorFrame::cEditorFrame(wxMDIParentFrame *parent, wxString sName) : wxMDIChildFrame(parent, wxID_ANY, sName){
    m_Canvas = new cCanvas(this);
    m_StatusBar = this->CreateStatusBar(2, wxSTB_DEFAULT_STYLE, wxID_ANY);      //two regions to status bar
    //m_ZoomSlider = new wxSlider(m_StatusBar, 20001, 8, 1, 32);
}

cEditorFrame::~cEditorFrame() {

}

void cEditorFrame::OnZoomChange(wxCommandEvent &evt) {
    m_StatusBar->SetStatusText(wxString("Zoom: ") << m_ZoomSlider->GetValue(), 1);
    m_Canvas->SetPixelSize(m_ZoomSlider->GetValue());
    evt.Skip();

}
