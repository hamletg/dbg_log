#include "test01/test01_prec.h"

#include "test01/mythread.h"
#include "test01/dummya.h"

#include "dbg_log/dbg_class.h"

MyThread::MyThread(wxThreadKind kind):wxThread(kind)
{
}

MyThread::~MyThread()
{
}

wxThread::ExitCode MyThread::Entry()
{
	DummyA dum;

	DBG_SET_THREAD_NAME("Slave");

	dum.Loop();

	return 0;
}

