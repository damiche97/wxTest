//
// Created by michael on 30.04.21.
//
//#pragma once
#ifndef WXTEST_CEDITORFRAME_H
#define WXTEST_CEDITORFRAME_H

#include "wx/wx.h"
#include "cCanvas.h"


class cEditorFrame : public wxMDIChildFrame{
public:
    cEditorFrame(wxMDIParentFrame *parent, wxString sName);
    ~cEditorFrame();
private:
    cCanvas *m_Canvas = nullptr;
    wxStatusBar *m_StatusBar = nullptr;
    wxSlider *m_ZoomSlider = nullptr;

    void OnZoomChange(wxCommandEvent &evt);

    wxDECLARE_EVENT_TABLE();
};


#endif //WXTEST_CEDITORFRAME_H
