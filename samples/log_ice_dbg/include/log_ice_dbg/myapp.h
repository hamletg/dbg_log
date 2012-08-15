#ifndef __MYAPP_H__
#define __MYAPP_H__

#include <wx/app.h>
#include <wx/cmdline.h>

class MyApp : public wxApp
{
public:
	MyApp();
    // override base class virtuals
    // ----------------------------

    // this one is called on application startup and is a good place for the app
    // initialization (doing it here and not in the ctor allows to have an error
    // return: if OnInit() returns false, the application terminates)
    virtual bool OnInit();
	virtual void OnInitCmdLine(wxCmdLineParser & parser);
	virtual bool OnCmdLineParsed(wxCmdLineParser& parser);

	unsigned short m_port;
};

wxDECLARE_APP(MyApp);

#endif
