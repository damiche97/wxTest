//
// Created by michael on 28.04.21.
//

#include "cApp.h"
// Generate main via wx
wxIMPLEMENT_APP(cApp);

cApp::cApp(){
}

cApp::~cApp(){
}

bool cApp::OnInit()
{
    m_frame1 = new cMain();
    m_frame1->Show();
    return true;
}