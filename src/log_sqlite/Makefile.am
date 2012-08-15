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
##  src/log_sqlite/Makefile.am
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

lib_LTLIBRARIES = liblog_sqlitec.la
liblog_sqlitec_la_CXXFLAGS = $(AM_CXXFLAGS) `wx-config --cxxflags`
liblog_sqlitec_la_LDFLAGS = $(EXTRA_LD_CONFIG) `wx-config --libs core,base` \
	../logmod/liblogmodc.la \
	-lwxcode_gtk2_wxsqlite3-2.9 -lsqlite3       

H_FILES = 

INST_FILES = \
	db_file.h \
	event_logger.h \
	log_sqlite_defs.h \
	log_sqlite_prec.h \
	version.h

CXX_FILES = \
	db_file.cpp \
	event_logger.cpp \
	log_sqlite.cpp \
	log_sqlite_prec.cpp

liblog_sqlitec_la_SOURCES = $(H_FILES) $(CXX_FILES) 

INCLUDE_DIR = $(prefix)/include/log_sqlite

pkgconfigdir = ${libdir}/pkgconfig
pkgconfig_DATA = log_sqlite.pc

install-data-local:
	@$(NORMAL_INSTALL)
	$(mkinstalldirs) $(INCLUDE_DIR)
	for file in $(INST_FILES); do \
	  d=$(top_srcdir)/include/log_sqlite; \
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
	for file in $(noinst_HEADERS); do \
	  rm -f $(INCLUDE_DIR)/$$file; \
	done
	-rmdir $(INCLUDE_DIR)


