## ****************************************************************************
##
##  The following code is derived, directly or indirectly, from the Mipi UniPro
##  source code Copyright (c) 2004-2005 by all Contributors.
##  All Rights reserved.
##
##	License stuff here ????????
##
## ****************************************************************************
##
##  src/dbg_log/Makefile.am
##  Process this file with automake to produce a Makefile.in file.
##
##  Original Author: Michel Gillet, Nokia, 2005-09-05
##
## ****************************************************************************
##
##  MODIFICATION LOG - modifiers, enter your name, affiliation, date and
##  changes you are making here.
##
##      Name, Affiliation, Date:
##  Description of Modification:
##
## ****************************************************************************


include $(top_srcdir)/config/Make-rules

lib_LTLIBRARIES = libdbg_logc.la
libdbg_logc_la_CXXFLAGS = $(AM_CXXFLAGS) `wx-config --cxxflags`
libdbg_logc_la_LDFLAGS = $(EXTRA_LD_CONFIG) `wx-config --libs core,base` 

H_FILES = 

INST_FILES = \
	dbg_class.h \
	dbg_class_api.h \
	dbg_class_class_info.h \
	dbg_class_event.h \
	dbg_class_function_info.h \
	dbg_class_param.h \
	dbg_class_param_base.h \
	dbg_class_prof.h \
	dbg_class_prof_bug.h \
	dbg_log_defs.h \
	dbg_log_prec.h \
	inttypes.h \
	version.h
	
CXX_FILES = \
	dbg_class.cpp \
	dbg_class_class_info.cpp \
	dbg_class_event.cpp \
	dbg_class_function_info.cpp \
	dbg_class_param_base.cpp \
	dbg_class_prof.cpp \
	dbg_class_prof_bug.cpp \
	dbg_class_thread.cpp \
	dbg_log.cpp \
	dbg_log_prec.cpp

libdbg_logc_la_SOURCES = $(H_FILES) $(CXX_FILES) 

libdbg_logc_la_LIBADD = \
	../logmod/liblogmodc.la \
	.

INCLUDE_DIR = $(prefix)/include/dbg_log

pkgconfigdir = ${libdir}/pkgconfig
pkgconfig_DATA = dbg_log.pc

install-data-local:
	@$(NORMAL_INSTALL)
	$(mkinstalldirs) $(INCLUDE_DIR)
	for file in $(INST_FILES); do \
	  d=$(top_srcdir)/include/dbg_log; \
	  if test -d $$d/$$file; then \
	    test -d $(INCLUDE_DIR)/$$file \
	    || cp -pr $$d/$$file $(INCLUDE_DIR) || :; \
	  else \
	    test -f $(INCLUDE_DIR)/$$file \
	    || cp -p $$d/$$file $(INCLUDE_DIR)/$$file || :; \
	  fi; \
	done

uninstall-local:
	@$(NORMAL_UNINSTALL)
	for file in $(INST_FILES); do \
	  rm -f $(INCLUDE_DIR)/$$file; \
	done
	-rmdir $(INCLUDE_DIR)



