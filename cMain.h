//
// Created by michael on 28.04.21.
//

#ifndef TEST_CMAIN_H
#define TEST_CMAIN_H

#include "wx/wx.h"
#include "cEditorFrame.h"

class cMain : public wxMDIParentFrame {
public:
    cMain();
    ~cMain();

private:
    // Pointer to the toolbar
    wxToolBar *m_ToolBar = nullptr;
    // Pointer to the menu bar
    wxMenuBar *m_MenuBar = nullptr;

    // Event handlers for New,Open,Save and Exit
    void OnMenuNew(wxCommandEvent &evt);
    void OnMenuOpen(wxCommandEvent &evt);
    void OnMenuSave(wxCommandEvent &evt);
    void OnMenuExit(wxCommandEvent &evt);
    //wxButton *m_btn1 = nullptr;
    //wxTextCtrl *m_txt1 = nullptr;
    //wxListBox *m_list1 = nullptr;

    void OnSelectColour(wxCommandEvent &evt);

    wxDECLARE_EVENT_TABLE();
};


#endif //TEST_CMAIN_H
