#ifndef __MYTHREAD_H__
#define __MYTHREAD_H__

#include <wx/thread.h>

class MyThread: public wxThread
{
public:
	MyThread(wxThreadKind kind = wxTHREAD_DETACHED);
	virtual ~MyThread();

	virtual ExitCode Entry();
};

#endif

