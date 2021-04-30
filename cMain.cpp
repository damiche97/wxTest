//
// Created by michael on 28.04.21.
//

#include "cMain.h"

wxBEGIN_EVENT_TABLE(cMain, wxMDIParentFrame)
    EVT_MENU(10001, cMain::OnMenuNew)
    EVT_MENU(10002, cMain::OnMenuOpen)
    EVT_MENU(10003, cMain::OnMenuSave)
    EVT_MENU(10004, cMain::OnMenuExit)
wxEND_EVENT_TABLE()

cMain::cMain() : wxMDIParentFrame(nullptr, wxID_ANY, "wxtest", wxPoint(30,30), wxSize(800,600))
{
    // Add the menu bar
    m_MenuBar = new wxMenuBar();
    this->SetMenuBar(m_MenuBar);

    // Add Menu for file operations
    // TODO: create proper constants for the IDs
    wxMenu *menuFile = new wxMenu();
    menuFile->Append(10001, "New");
    menuFile->Append(10002, "Open");
    menuFile->Append(10003, "Save");
    menuFile->Append(10004, "Exit");

    // Add File Menu to Menu Bar
    m_MenuBar->Append(menuFile, "FileTitle");

    // Add Toolbar
    m_ToolBar = this->CreateToolBar(wxTB_HORIZONTAL, wxID_ANY);
    wxColour palette[16];
    palette[0] = wxColour(0,0,0);
    palette[1] = wxColour(0,0,128);
    palette[2] = wxColour(0,128,0);
    palette[3] = wxColour(0,128,128);
    palette[4] = wxColour(128,0,0);
    palette[5] = wxColour(128,0,128);
    palette[6] = wxColour(128,128,0);
    palette[7] = wxColour(192,192,192);
    palette[8] = wxColour(128,128,128);
    palette[9] = wxColour(0,0,255);
    palette[10] = wxColour(0,255,0);
    palette[11] = wxColour(0,255,255);
    palette[12] = wxColour(255,0,0);
    palette[13] = wxColour(255,0,255);
    palette[14] = wxColour(255,255,0);
    palette[15] = wxColour(255,255,255);

    for (int i = 0; i< 16; i++){
        wxButton *b = new wxButton(m_ToolBar, 10100+i, "", wxDefaultPosition, wxSize(30,24), 0);
        b->SetBackgroundColour(palette[i]);
        b->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(cMain::OnSelectColour), nullptr, this);
        m_ToolBar->AddControl(b);
    }
    wxButton *b = new wxButton(m_ToolBar, 10100+16, "ALPHA", wxDefaultPosition, wxSize(30,24), 0);
    b->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(cMain::OnSelectColour), nullptr, this);
    m_ToolBar->AddControl(b);

    m_ToolBar->Realize();


}

cMain::~cMain() {

}

void cMain::OnMenuNew(wxCommandEvent &evt) {
    cEditorFrame *f = new cEditorFrame(this, "Test");
    f->Show();
    evt.Skip();
}

void cMain::OnMenuOpen(wxCommandEvent &evt) {

}

void cMain::OnMenuSave(wxCommandEvent &evt) {

}

void cMain::OnMenuExit(wxCommandEvent &evt) {
    Close();
    evt.Skip();
}

void cMain::OnSelectColour(wxCommandEvent &evt) {

}

/*
void cMain::OnButtonClicked(wxCommandEvent &evt)
{
    m_list1->AppendString(m_txt1->GetValue());
    evt.Skip();
}
 */