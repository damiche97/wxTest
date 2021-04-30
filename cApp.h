//
// Created by michael on 28.04.21.
//

#ifndef TEST_CAPP_H
#define TEST_CAPP_H

#include "wx/wx.h"
#include "cMain.h"

class cApp : public wxApp{
public:
    cApp();
    ~cApp();
private:
    cMain* m_frame1 = nullptr;

public:
    virtual bool OnInit();
};



#endif //TEST_CAPP_H
