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
##  samples/test01/src/test01/Makefile.am
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

bin_PROGRAMS = test01

H_FILES = 

noinst_HEADERS = $(H_FILES)

CXX_FILES = \
	dummya.cpp \
	main.cpp \
	test01_prec.cpp \
	.
	
NO_CXX_FILES =

test01_SOURCES = $(H_FILES) $(CXX_FILES)
test01_LDADD = \
	../../../../src/logmod/liblogmodc.la \
	../../../../src/dbg_log/libdbg_logc.la \
	../../../../src/log_ice/liblog_icec.la \
	../../../../src/log_sqlite/liblog_sqlitec.la

test01_LDFLAGS = $(EXTRA_LD_CONFIG) -lIce -lIceUtil `wx-config --libs core,base,adv` -lSlice

test01_CXXFLAGS = $(AM_CXXFLAGS) -I$(srcdir)/../../include `wx-config --cxxflags`

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

