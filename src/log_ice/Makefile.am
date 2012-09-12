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
##  src/log_ice/Makefile.am
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

lib_LTLIBRARIES = liblog_icec.la
liblog_icec_la_CXXFLAGS = $(AM_CXXFLAGS)
liblog_icec_la_LDFLAGS = $(EXTRA_LD_CONFIG) -lIce -lIceUtil \
	   ../logmod/liblogmodc.la \
	   ../dbg_log/libdbg_logc.la        

H_FILES =

INST_FILES = \
	ice/dbg_class_event.h \
	ice/event.h \
	ice/logger_event.h \
	ice/loggerctrl.h \
	ice/option_event.h \
	event_logger.h \
	event_logger_impl.h \
	log_ice_defs.h \
	log_ice_prec.h \
	version.h

CXX_FILES = \
	event_logger.cpp \
	event_logger_impl.cpp \
	log_ice.cpp \
	log_ice_prec.cpp
	
liblog_icec_la_SOURCES = $(H_FILES) $(CXX_FILES) 

liblog_icec_la_LIBADD= \
	./ice/liblog_ice_ice.la

SUBDIRS = \
	ice

INCLUDE_DIR = $(prefix)/include/log_ice

pkgconfigdir = ${libdir}/pkgconfig
pkgconfig_DATA = log_ice.pc

install-data-local:
	@$(NORMAL_INSTALL)
	$(mkinstalldirs) $(INCLUDE_DIR)
	for file in $(INST_FILES); do \
	  d=$(top_srcdir)/include/log_ice; \
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

## Taf!

