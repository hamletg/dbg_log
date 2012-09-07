#ifndef __PRINTERI_H__
#define __PRINTERI_H__

#ifdef WIN32
#define _WINSOCKAPI_ 
#endif

#include <Ice/Ice.h>
#include <wx/textctrl.h>
#include <string>
#include "log_ice_dbg/ice/printer.h"

using namespace std;
using namespace Demo;

class PrinterI : public Printer 
{
public:
    PrinterI(wxTextCtrl *text);
    virtual void printString(const string & s,const Ice::Current &);
    wxTextCtrl *m_text;
};

#endif
