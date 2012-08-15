#include "test01/test01_prec.h"
#include "test01/dummya.h"

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
	
	event_log.SetName("test01");
	event_log.Enable();
	event_log.Connect();

	my_log.SetOfstream(&ofs);
	dbg_log::dbg_class::SetDefaultLogger(&my_log);
	dbg_log::dbg_class::SetDefaultEventLogger(&event_log);

	std::cout << "Hello World!" << std::endl;
	
	dum.Loop();

	return 0;
}