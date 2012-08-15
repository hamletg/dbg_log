#include "log_ice_dbg/log_ice_dbg_prec.h"
#include "log_ice_dbg/printeri.h"

PrinterI::PrinterI(wxTextCtrl *text):Printer()
{
    m_text=text;
}

void 
PrinterI::
printString(const string & s, const Ice::Current &)
{
    if (m_text!=NULL)
    {
        m_text->AppendText(s.c_str());
        m_text->AppendText("\n");

    }
    //cout << s << endl;
}
