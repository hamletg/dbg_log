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
##  samples/log_ice_dbg/src/log_ice_dbg/ice/Makefile.am
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

noinst_LTLIBRARIES = liblog_ice_dbg_ice.la
liblog_ice_dbg_ice_la_CXXFLAGS = $(AM_CXXFLAGS) -I$(srcdir)/../../../include
liblog_ice_dbg_ice_la_LDFLAGS = $(EXTRA_LD_CONFIG)

H_FILES =

CXX_FILES = \
	logicedbgctrlif.cpp \
	printer.cpp
	
liblog_ice_dbg_ice_la_SOURCES = $(H_FILES) $(CXX_FILES) 

INCLUDE_DIR = $(prefix)/include/log_ice/ice

install-data-local:
	@$(NORMAL_INSTALL)
	$(mkinstalldirs) $(INCLUDE_DIR)
	for file in $(noinst_HEADERS); do \
	  $(INSTALL_DATA) $(srcdir)/$$file $(INCLUDE_DIR)/$$file; \
	done

uninstall-local:
	@$(NORMAL_UNINSTALL)
	for file in $(noinst_HEADERS); do \
	  rm -f $(INCLUDE_DIR)/$$file; \
	done
	-rmdir $(INCLUDE_DIR)

## Taf!

