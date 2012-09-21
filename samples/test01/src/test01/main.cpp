#include "test01/test01_prec.h"

#include <wx/app.h>

#include "test01/dummya.h"
#include "test01/mythread.h"

#include "logmod/logger.h"
#include "dbg_log/dbg_class.h"
#include "log_ice/event_logger.h"
#include <iostream>
#include <fstream>

int main(int argc, char *argv[])
{
	DummyA dum;
	std::ofstream ofs("text.txt");	
	logmod::logger my_log;
	log_ice::event_logger event_log;
	
	wxInitializer initializer;
 	if ( !initializer )
 	{
		std::cerr << "Failed to initialize the wxWidgets library, aborting." << std::endl;
 		return -1;
 	}

	MyThread myt(wxTHREAD_JOINABLE);
	
	event_log.SetName("test01");
	event_log.LogThreadId(true);
	
	event_log.Enable();
	event_log.Connect();

	my_log.SetOfstream(&ofs);
	dbg_log::dbg_class::SetDefaultLogger(&my_log);
	dbg_log::dbg_class::SetDefaultEventLogger(&event_log);

	DBG_SET_THREAD_NAME("Main");
	dbg_log::dbg_class::SetDifferentiateThread(true);

	std::cout << "Hello World!" << std::endl;

	myt.Create();
	myt.Run();

	dum.Loop();

	myt.Wait();
	return 0;
}