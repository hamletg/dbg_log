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
##  samples/log_ice_dbg/src/log_ice_dbg/Makefile.am
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

bin_PROGRAMS = log_ice_dbg

H_FILES = 

noinst_HEADERS = $(H_FILES)

CXX_FILES = \
	ice/logicedbgctrlif.cpp \
	ice/printer.cpp \
	appdata.cpp \
	dbgclasseventifi.cpp \
	enable_sqlite_dlg.cpp \
	log_ice_dbg_prec.cpp \
	loggerctrli.cpp \
	loggereventifi.cpp \
	main.cpp \
	nbr_event_panel.cpp \
	optioneventifi.cpp \
	printeri.cpp  \
	registeredproc.cpp \
	server.cpp \
	sqlitectrli.cpp \
	.
NO_CXX_FILES =

log_ice_dbg_SOURCES = $(H_FILES) $(CXX_FILES)
log_ice_dbg_LDADD = \
	./ice/liblog_ice_dbg_ice.la \
	../../../../src/logmod/liblogmodc.la \
	../../../../src/dbg_log/libdbg_logc.la \
	../../../../src/log_ice/liblog_icec.la \
	../../../../src/log_ice/ice/liblog_ice_ice.la \
	../../../../src/log_sqlite/liblog_sqlitec.la
	
log_ice_dbg_LDFLAGS = $(EXTRA_LD_CONFIG) -lIce -lIceUtil `wx-config --libs core,base,adv` -lSlice
	

log_ice_dbg_CXXFLAGS = $(AM_CXXFLAGS) -I$(srcdir)/../../include `wx-config --cxxflags`

SUBDIRS = \
	ice \
	.
	
#INCLUDE_DIR = $(prefix)/include/unipro

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

