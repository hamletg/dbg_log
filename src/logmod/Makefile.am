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
##  src/logmod/Makefile.am
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

lib_LTLIBRARIES = liblogmodc.la
liblogmodc_la_CXXFLAGS = $(AM_CXXFLAGS) `wx-config --cxxflags`
liblogmodc_la_LDFLAGS = $(EXTRA_LD_CONFIG) `wx-config --libs core,base`   

H_FILES =

INST_FILES = \
	blob_event.h \
	event.h \
	event_logger.h \
	event_type.h \
	event_types.h \
	event_utils.h \
	inttypes.h \
	logger.h \
	logger_event.h \
	logmod_defs.h \
	logmod_prec.h \
	option_event.h \
	version.h \
	wxtextctrlts.h

CXX_FILES = \
	blob_event.cpp \
	event.cpp \
	event_logger.cpp \
	event_type.cpp \
	event_types.cpp \
	event_utils.cpp \
	logger.cpp \
	logger_event.cpp \
	logmod_dll.cpp \
	logmod_prec.cpp \
	option_event.cpp \
	wxtextctrlts.cpp
	
liblogmodc_la_SOURCES = $(H_FILES) $(CXX_FILES) 

INCLUDE_DIR = $(prefix)/include/logmod

pkgconfigdir = ${libdir}/pkgconfig
pkgconfig_DATA = logmod.pc

install-data-local:
	@$(NORMAL_INSTALL)
	$(mkinstalldirs) $(INCLUDE_DIR)
	for file in $(INST_FILES); do \
	  d=$(top_srcdir)/include/logmod; \
	  if test -d $$d/$$file; then \
	    test -d $(INCLUDE_DIR)/$$file \
	    || cp -pr $$d/$$file $(INCLUDE_DIR) || :; \
	  else \
	    test -f $(INCLUDE_DIR)/$$file \
	    || cp -p $$d/$$file $(INCLUDE_DIR)/$$file || :; \
	  fi; \
	done
	$(mkinstalldirs) $(INCLUDE_DIR)/unix
	cp -p $(top_builddir)/include/logmod/unix/setup.h $(INCLUDE_DIR)/unix/
	
uninstall-local:
	@$(NORMAL_UNINSTALL)
	for file in $(INST_FILES); do \
	  rm -f $(INCLUDE_DIR)/$$file; \
	done
	rm -f $(INCLUDE_DIR)/unix/setup.h
	-rmdir $(INCLUDE_DIR)/unix
	-rmdir $(INCLUDE_DIR)



